

#include "Arduino.h"
#define MDATA 7 // branco
#define MCLK 6  // verde
int xr=0;
int yr=0;
#define CLKFULL 40
#define CLKHALF 20

void mouse_write(char data)
{
  char i;
  char parity = 1;

  Serial.print("Sending ");
  Serial.print(data, HEX);
  Serial.print(" to mouse\n");
  Serial.print("RTS\n");
  /* put pins in output mode */
  gohi(MDATA);
  Serial.print("Set Dada to High\n");
  gohi(MCLK);
  Serial.print("Set Clock to High\n");
  delayMicroseconds(300);
  golo(MCLK);
  Serial.print("Set Clock to Low\n");
  delayMicroseconds(300);
  golo(MDATA);
  Serial.print("Set Data to Low\n");
  delayMicroseconds(10);//10ms
  /* start bit */
  gohi(MCLK);
  Serial.print("Aguarda mouse pegar o controle\n");
  /* aguardar o mouse pegar o controle do clock); */
  while (digitalRead(MCLK) == HIGH);
  Serial.print("Recebendo dados...\n");
    
  /* clock baixo, e limpando o data enviado do mouse */
  for (i=0; i < 8; i++) {
    if (data & 0x01) {
      gohi(MDATA);
    } 
    else {
      golo(MDATA);
    }
    Serial.print("Dado:");
    Serial.print(data,HEX);
    Serial.print("\n");
    Serial.print("Dados recebidos\n");
    /* espera por um ciclo de clock */
    while (digitalRead(MCLK) == LOW);
    Serial.print("Recebido Clock do mouse Low\n");
    while (digitalRead(MCLK) == HIGH);
    Serial.print("Recebido Clock do mouse High\n");

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
  Serial.print("done.\n");
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
  while (digitalRead(MCLK) == HIGH);
  delayMicroseconds(5);  /* nao tem certeza porque */
  while (digitalRead(MCLK) == LOW) /* iniciando o bit */ ;
  for (i=0; i < 8; i++) 
  {
    while (digitalRead(MCLK) == HIGH);
    if (digitalRead(MDATA) == HIGH) 
    {
      data = data | bit;
    }
    while (digitalRead(MCLK) == LOW);
    bit = bit << 1;
  }
  /* paridade do bit, iremos ignorar*/
  while (digitalRead(MCLK) == HIGH);
  while (digitalRead(MCLK) == LOW);
  /* parando o bit */
  while (digitalRead(MCLK) == HIGH);
  while (digitalRead(MCLK) == LOW);

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
  Serial.print("enviando reset para  mouse\n");
  mouse_write(0xff);
  mouse_read();  /* ack byte */
  Serial.print("Read ack byte1\n");
  mouse_read();  /* blank */
  mouse_read();  /* blank */
  Serial.print("Sending remote mode code\n");
  mouse_write(0xf0);  /* remote mode */
  mouse_read();  /* ack */
  Serial.print("Read ack byte2\n");
  delayMicroseconds(1000);
}


void setup()
{
 Serial.begin(9600);
 mouse_init();

  
  
}

////

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
  my = mouse_read();

  /* send the data back up */
  Serial.print(mstat, BIN);
  Serial.print("\tX=");
  Serial.print(mx, DEC);
  Serial.print("\tY=");
  Serial.print(my, DEC);
  Serial.println();
  
  xr=xr+mx; 
  yr=yr+my;
   

  Serial.print("\tXR=");
  Serial.print(xr, DEC);
  Serial.print("\tYR=");
  Serial.print(yr, DEC);
  Serial.println();
  
  delay(20);  /* twiddle */

  

   
}

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



