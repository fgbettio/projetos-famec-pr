

#include "Arduino.h"
#include <TimerOne.h>

#define MDATA 5
#define MCLK 6

int xr=0;
int yr=0;

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
//#define CLKFULL 40
// we make changes in the middle of a phase, this how long from the
// start of phase to the when we drive the data line
//#define CLKHALF 20

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
  delayMicroseconds(300);
  golo(MCLK);
  delayMicroseconds(300);
  golo(MDATA);
  delayMicroseconds(10);
  /* start bit */
  gohi(MCLK);
  /* aguardar o mouse pegar o controle do clock); */
  while (digitalRead(MCLK) == HIGH)
    ;
  /* clock baixo, e limpando o data enviado do mouse */
  for (i=0; i < 8; i++) {
    if (data & 0x01) {
      gohi(MDATA);
    } 
    else {
      golo(MDATA);
    }
    /* espera por um ciclo de clock */
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
  delayMicroseconds(50);
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
 * pegando um byte do data do mouse
 */
char mouse_read(void)
{
  char data = 0x00;
  int i;
  char bit = 0x01;

  //  Serial.print("lendo o byte do mouse\n");
  /* start the clock */
  gohi(MCLK);
  gohi(MDATA);
  delayMicroseconds(50);
  while (digitalRead(MCLK) == HIGH)
    ;
  delayMicroseconds(5);  /* nao tem certeza porque */
  while (digitalRead(MCLK) == LOW) /* iniciando o bit */
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
  /* paridade do bit, iremos ignorar*/
  while (digitalRead(MCLK) == HIGH)
    ;
  while (digitalRead(MCLK) == LOW)
    ;
  /* parando o bit */
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
  //  Serial.print("enviando reset para  mouse\n");
  mouse_write(0xff);
  mouse_read();  /* ack byte */
  //  Serial.print("Read ack byte1\n");
  mouse_read();  /* blank */
  mouse_read();  /* blank */
  //  Serial.print("Sending remote mode code\n");
  mouse_write(0xf0);  /* remote mode */
  mouse_read();  /* ack */
  //  Serial.print("Read ack byte2\n");
  delayMicroseconds(100);
}

/* ver no proximo tempo oportuno 
int Timer1;
void setup()
{
  Serial.begin(9600);
  mouse_init();
   Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( leMouse ); // attach the service routine here
}
int leMouse()
{ 
  
}
*/  
/*
 * get a reading from the mouse and report it back to the
 * host via the serial line.
 */
void loop()
{
  char mstat;
  char mx;
  char my;
  int tempo;

  /* PEGANDO A LEITURA DO MOUSE*/
  mouse_write(0xeb);  /* ME DE O DATA */
  mouse_read();      /* IGNORE ACK */
  mstat = mouse_read();
  mx = mouse_read();
  my = mouse_read();// converter polegada para mm

  /* send the data back up */
  Serial.print(mstat, BIN);
  Serial.print("\tX=");
  Serial.print(mx, DEC);
  Serial.print("\tY=");
  Serial.print(my, DEC);
  //Serial.println();
  
  xr=(xr+mx);// Xin(m)i+Vel(m/s)//0 + 30 // 30 + 40
  yr=(yr+my);
  
  
  Serial.print("\tXR=");
  Serial.print(xr, DEC);
  Serial.print("\tYR=");
  Serial.print(yr, DEC);
  Serial.println();
  
  delay(1000);  /* twiddle */
}
