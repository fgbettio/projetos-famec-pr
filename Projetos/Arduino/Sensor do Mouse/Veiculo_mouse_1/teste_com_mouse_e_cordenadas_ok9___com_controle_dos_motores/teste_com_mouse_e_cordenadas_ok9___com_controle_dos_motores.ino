

#include "Arduino.h"


#define MDATA 7 // branco
#define MCLK 6  // verde
// preto é o vermelho
// o laranja é o positivo
// verde é o preto
// branco é o marrom

#define M1A 2
#define M1B 3
#define M2A 4
#define M2B 5

int xr=0;
int yr=0;

 /*funções disponiveis*/
 /* void parar(); void frente(); void reverse();oid esquerda_fraco_M1();void direita_fraco_M2();void esquerda_forte_M1(); void direita_forte_M2(); void Parar_M1();
 void Parar_M2(); void reverse_M1(); void reverse_M2();*/
 
 void parar()
{
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);
}

void frente()
{
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}

void reverse()
{
   digitalWrite(M1A, LOW);
   digitalWrite(M1B, HIGH);
   digitalWrite(M2A, HIGH);
   digitalWrite(M2B, LOW);
}


void esquerda_fraco_M1()
{
   digitalWrite(M1A, LOW);
   digitalWrite(M1B, HIGH);
}
void direita_fraco_M2()
{
   digitalWrite(M2A, LOW);
   digitalWrite(M2B, HIGH);
}
void esquerda_forte_M1()
{
   digitalWrite(M1A, LOW);
   digitalWrite(M1B, HIGH);
   digitalWrite(M2B, LOW);
   digitalWrite(M2A, HIGH);
}
void direita_forte_M2()
{
   digitalWrite(M2A, LOW);
   digitalWrite(M2B, HIGH);
   digitalWrite(M1B, LOW);
   digitalWrite(M1A, HIGH);
}
void Parar_M1()
{
   digitalWrite(M1A, HIGH);
   digitalWrite(M1B, HIGH);
}
void Parar_M2()
{
   digitalWrite(M2A, HIGH);
   digitalWrite(M2B, HIGH);
}

void reverse_M1()
{
   digitalWrite(M1B, LOW);
   digitalWrite(M1A, HIGH);
}

void reverse_M2()
{
   digitalWrite(M2B, LOW);
   digitalWrite(M2A, HIGH);
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

//since for the device side we are going to be in charge of the clock,
//the two defines below are how long each _phase_ of the clock cycle is
#define CLKFULL 40
// we make changes in the middle of a phase, this how long from the
// start of phase to the when we drive the data line
#define CLKHALF 20

void mouse_write(char data)
{
  char i;
  char parity = 1;

  Serial.print("Sending ");
  Serial.print(data, HEX);
  Serial.print(" to mouse\n");
  Serial.print("RTS");
  /* put pins in output mode */
  gohi(MDATA);
  gohi(MCLK);
  Serial.print(" 1\n");
  delayMicroseconds(300);
  golo(MCLK);
  delayMicroseconds(300);
  Serial.print(" 2\n");
  golo(MDATA);
  delayMicroseconds(10);
  /* start bit */
  gohi(MCLK);
  Serial.print(" 3\n");
  /* aguardar o mouse pegar o controle do clock); */
  while (digitalRead(MCLK) == HIGH)
    ;
    Serial.print(" 4\n");
    
  /* clock baixo, e limpando o data enviado do mouse */
  for (i=0; i < 8; i++) {
    if (data & 0x01) {
      gohi(MDATA);
    } 
    else {
      golo(MDATA);
    }
    
     Serial.print("Dado:");
      Serial.println(data,HEX);
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
  Serial.print("enviando reset para  mouse\n");
  mouse_write(0xff);
  mouse_read();  /* ack byte */
  Serial.print("Read ack byte1 aaaaa\n");
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

  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT); 
  pinMode(M2B, OUTPUT);
 
  
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
  //Serial.println();
  
  xr=xr+mx; 
  yr=yr+my;
  
  

  Serial.print("\tXR=");
  Serial.print(xr, DEC);
  Serial.print("\tYR=");
  Serial.print(yr, DEC);
  Serial.println();
  
  delay(20);  /* twiddle */

  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
  delay(1000);


   
}


