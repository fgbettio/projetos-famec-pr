/*
 * ps2dev.cpp - an interface library for ps2 host.  
 * limitations:
 *      we do not handle parity errors.
 *      The timing constants are hard coded from the spec. Data rate is
 *         not impressive.
 *      probably lots of room for optimization.
 */

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "ps2dev.h"

#define MDATA 5
#define MCLK 6
int T=2;


int xr=0;
int yr=0;
/*
 * according to some code I saw, these functions will
 * correctly set the mouse clock and data pins for
 * various conditions.
 */
void gohi(int pin)
{
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH);
}

void golo(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

//since for the device side we are going to be in charge of the clock,
//the two defines below are how long each _phase_ of the clock cycle is
#define CLKFULL 20
// we make changes in the middle of a phase, this how long from the
// start of phase to the when we drive the data line
#define CLKHALF 10

void mouse_write(char data)
{
  char i;
  char parity = 1;

  //  Serial.print("Sending ");
  //  Serial.print(data, HEX);
  //  Serial.print(" to mouse\n");
  //  Serial.print("RTS");
  /* put pins in output mode */
  gohi(MDATA);
  gohi(MCLK);
  delayMicroseconds(300*T);
  golo(MCLK);
  delayMicroseconds(300*T);
  golo(MDATA);
  delayMicroseconds(10*T);
  /* start bit */
  gohi(MCLK);
  /* wait for mouse to take control of clock); */
  while (digitalRead(MCLK) == HIGH)
    ;
  /* clock is low, and we are clear to send data */
  for (i=0; i < 8; i++) {
    if (data & 0x01) {
      gohi(MDATA);
    } 
    else {
      golo(MDATA);
    }
    /* wait for clock cycle */
    while (digitalRead(MCLK) == LOW)
      ;
    while (digitalRead(MCLK) == HIGH)
      ;
    parity = parity ^ (data & 0x01);
    data = data >> 1;
  }  
  /* parity */
  if (parity) {
    gohi(MDATA);
  } 
  else {
    golo(MDATA);
  }
  while (digitalRead(MCLK) == LOW)
    ;
  while (digitalRead(MCLK) == HIGH)
    ;
  /* stop bit */
  gohi(MDATA);
  delayMicroseconds(50*T);
  while (digitalRead(MCLK) == HIGH)
    ;
  /* wait for mouse to switch modes */
  while ((digitalRead(MCLK) == LOW) || (digitalRead(MDATA) == LOW))
    ;
  /* put a hold on the incoming data. */
  golo(MCLK);
  //  Serial.print("done.\n");
}

/*
 * Get a byte of data from the mouse
 */
char mouse_read(void)
{
  char data = 0x00;
  int i;
  char bit = 0x01;

  //  Serial.print("reading byte from mouse\n");
  /* start the clock */
  gohi(MCLK);
  gohi(MDATA);
  delayMicroseconds(50*T);
  while (digitalRead(MCLK) == HIGH)
    ;
  delayMicroseconds(5*T);  /* not sure why */
  while (digitalRead(MCLK) == LOW) /* eat start bit */
    ;
  for (i=0; i < 8; i++) {
    while (digitalRead(MCLK) == HIGH)
      ;
    if (digitalRead(MDATA) == HIGH) {
      data = data | bit;
    }
    while (digitalRead(MCLK) == LOW)
      ;
    bit = bit << 1;
  }
  /* eat parity bit, which we ignore */
  while (digitalRead(MCLK) == HIGH)
    ;
  while (digitalRead(MCLK) == LOW)
    ;
  /* eat stop bit */
  while (digitalRead(MCLK) == HIGH)
    ;
  while (digitalRead(MCLK) == LOW)
    ;

  /* put a hold on the incoming data. */
  golo(MCLK);
  //  Serial.print("Recvd data ");
  //  Serial.print(data, HEX);
  //  Serial.print(" from mouse\n");
  return data;
}


void mouse_init()
{
  gohi(MCLK);
  gohi(MDATA);
  //  Serial.print("Sending reset to mouse\n");
  mouse_write(0xff);
  mouse_read();  /* ack byte */
  //  Serial.print("Read ack byte1\n");
  mouse_read();  /* blank */
  mouse_read();  /* blank */
  //  Serial.print("Sending remote mode code\n");
  mouse_write(0xf0);  /* remote mode */
  mouse_read();  /* ack */
  //  Serial.print("Read ack byte2\n");
  delayMicroseconds(100/T);
}
/*
 * the clock and data pins can be wired directly to the clk and data pins
 * of the PS2 connector.  No external parts are needed.
 */
PS2dev::PS2dev(int clk, int data)
{
  _ps2clk = clk;
  _ps2data = data;
  gohi(_ps2clk);
  gohi(_ps2data);
}

/*
 * according to some code I saw, these functions will
 * correctly set the clock and data pins for
 * various conditions.  It's done this way so you don't need
 * pullup resistors.
 */
void
PS2dev::gohi(int pin)
{
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH);
}

void
PS2dev::golo(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

int PS2dev::write(unsigned char data)
{
  unsigned char i;
  unsigned char parity = 1;

  //	Serial.print("sending ");
  //Serial.println(data,HEX);

	
  if (digitalRead(_ps2clk) == LOW) {
    return -1;
  }

  if (digitalRead(_ps2data) == LOW) {
    return -2;
  }


  golo(_ps2data);
  delayMicroseconds(CLKHALF);
  // device sends on falling clock
  golo(_ps2clk);	// start bit
  delayMicroseconds(CLKFULL);
  gohi(_ps2clk);
  delayMicroseconds(CLKHALF);

  for (i=0; i < 8; i++)
    {
      if (data & 0x01)
	{
	  gohi(_ps2data);
	} else {
	golo(_ps2data);
      }
      delayMicroseconds(CLKHALF);
      golo(_ps2clk);	
      delayMicroseconds(CLKFULL);
      gohi(_ps2clk);
      delayMicroseconds(CLKHALF);

      parity = parity ^ (data & 0x01);
      data = data >> 1;
    }
  // parity bit
  if (parity)
    {
      gohi(_ps2data);
    } else {
    golo(_ps2data);
  }
  delayMicroseconds(CLKHALF);
  golo(_ps2clk);	
  delayMicroseconds(CLKFULL);
  gohi(_ps2clk);
  delayMicroseconds(CLKHALF);

  // stop bit
  gohi(_ps2data);
  delayMicroseconds(CLKHALF);
  golo(_ps2clk);	
  delayMicroseconds(CLKFULL);
  gohi(_ps2clk);
  delayMicroseconds(CLKHALF);

  delayMicroseconds(50/T);
  return 0;
}


int PS2dev::read(unsigned char * value)
{
  unsigned char data = 0x00;
  unsigned char i;
  unsigned char bit = 0x01;
  
  unsigned char parity = 1;
  
  //wait for data line to go low
  while (digitalRead(_ps2data) == HIGH) {

  } 
  //wait for clock line to go high
  while (digitalRead(_ps2clk) == LOW) {

  } 

  
  delayMicroseconds(CLKHALF);
  golo(_ps2clk);
  delayMicroseconds(CLKFULL);
  gohi(_ps2clk);
  delayMicroseconds(CLKHALF);

  for (i=0; i < 8; i++)
    {
      if (digitalRead(_ps2data) == HIGH)
	{
	  data = data | bit;
	} else {
      }


      bit = bit << 1;
      
      delayMicroseconds(CLKHALF);
      golo(_ps2clk);	
      delayMicroseconds(CLKFULL);
      gohi(_ps2clk);
      delayMicroseconds(CLKHALF);
      
      parity = parity ^ (data & 0x01);
    }
  // we do the delay at the end of the loop, so at this point we have
  // already done the delay for the parity bit

  // stop bit
  delayMicroseconds(CLKHALF);
  golo(_ps2clk);	
  delayMicroseconds(CLKFULL);
  gohi(_ps2clk);
  delayMicroseconds(CLKHALF);
  

  delayMicroseconds(CLKHALF);
  golo(_ps2data);
  golo(_ps2clk);	
  delayMicroseconds(CLKFULL);
  gohi(_ps2clk);
  delayMicroseconds(CLKHALF);
  gohi(_ps2data);


  *value = data;
  
  return 0;
}
void setup()
{
  Serial.begin(9600);
  mouse_init();
}

/*
 * get a reading from the mouse and report it back to the
 * host via the serial line.
 */
void loop()
{
  char mstat;
  char mx;
  char my;

  /* get a reading from the mouse */
  mouse_write(0xeb);  /* give me data! */
  mouse_read();      /* ignore ack */
  mstat = mouse_read();
  mx = mouse_read();
  my = mouse_read();

  /* send the data back up */
  Serial.print(mstat, BIN);
  Serial.print("\tX=");
  Serial.print(mx, DEC);
  Serial.print("\tY=");
  Serial.print(my, DEC);
  //Serial.println();
  
  xr=xr+mx;
  yr=yr+my;
  Serial.print("\tXR=");
  Serial.print(xr, DEC);
  Serial.print("\tYR=");
  Serial.print(yr, DEC);
  Serial.println();
  

  delay(20/T);  /* twiddle */
}
