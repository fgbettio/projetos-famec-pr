//===================================================================================
// Descrição: Versao OK para todo mouse PS2, com acionamento de motores
// Data: 19/09/2013
// Author: Fabio, Robson
//===================================================================================
// ## adaptador PS2 ##
// vermelho = GND
// laranja = 5V
// preto = CLK
// marrom = DATA
//===================================================================================
#include "Arduino.h"

#define MDATA 7 
#define MCLK 6 

#define M1A 2
#define M1B 3
#define M2A 4
#define M2B 5
// =============================== Configuração ======================================
int giro=520;// mudar de acordo com o piso
//600 > vel min MESA
//820 > CHAO FAMEC SALA 12

// =============================== Declarações ======================================

int xr=0;
int yr=0;
int estado=0;
int temp_x=0;
int temp_y=0;
int ativo=0;
struct COORD_MOUSE
{
    char vel_x;// verificar o uso do INT
    char vel_y;
    int coord_x;
    int coord_y;
}data;

//=============SETUP=====================
// CONFIGURAÇÃO DOS PINOS
//===========================================================================
void setup()
{
 Serial.begin(9600);
  //mouse_init();

  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT); 
  pinMode(M2B, OUTPUT);  
}
//=================================================================================
// ===========================/*funções disponiveis*/==============================
 /* void parar();
 void frente(); 
 void reverse();
 void esquerda_fraco_M1();
 void direita_fraco_M2();
 void esquerda_forte_M1();
 void direita_forte_M2();
 void Parar_M1();
 void Parar_M2();
 void reverse_M1();
 void reverse_M2();*/
//==================================================================================
//==========================/* Trajetos disponiveis*/===============================
/* void trajeto_1*/ // circuito inicial com 7 comandos, retorna para incio
/* void trajeto_2*/ // circuito ida e volta, 10000 de coordenadas
/* void trajeto_3*/ // Gira Gira
/* void trajeto_4*/ // Usa Esquerda Fraco e Direita Fraco
//==================================================================================
void loop()
{
   frente();
   delay(500);

   parar();
   delay(500);
 
   reverse();
   delay(500);

   parar();
   delay(500);
   

}
//============== Declaração de Funções ==============
//===================================================================================
// Descrição: Função de lei.....
// Parametros: char acao,int valor_x,int valor_y,int proximo_estado
// Retornos: void
// Indiretos: nada
// Data: 24/09/2013
// Author: Fabio, Robson
//===================================================================================
int controle(char acao,int valor) // void controle(char acao,int valor)
{
      int atraso=1;//ms
      if(ativo==0)
      {
        temp_y=data.coord_y;
        temp_x=data.coord_x;
      }
      switch(acao)
      {
        case 'f':
            if (modulo(data.coord_y-temp_y)<=valor)// 11-10 < 100 
            {
              if(acao=='f')
                frente();
              ativo=1;
             /*if (data.vel_y==0)
              {
                controle('r',500);
              }*/ // tentativa de reverção ao detectar obstaculo
            }  
            else 
            {
              parar();
              //estado=proximo_estado;
              ativo=0;
              delay(atraso);
              return 1;
             
            }   
        break;
         case 'r':
            if (modulo(data.coord_y-temp_y)<=valor)// 11-10 < 100
            {
              reverse();
              ativo=1;
            }  
            else 
            {
              parar();
              //estado=proximo_estado;
              ativo=0;
              delay(atraso);
              return 1;
            }  
           break;
           case 'd':
            if (modulo(data.coord_x-temp_x)<=valor)// 11-10 < 100
            {
              direita_forte();
              ativo=1;
            }  
            else 
            {
              parar();
              //estado=proximo_estado;
              ativo=0;
              delay(atraso);
              return 1;
            }    
        break;
         case 'e':
            if (modulo(data.coord_x-temp_x)<=valor)// 11-10 < 100
            {
              esquerda_forte();
              ativo=1;
            }  
            else 
            {
              parar();
              //estado=proximo_estado;
              ativo=0;
              delay(atraso);
              return 1;
            }    
        break;
          case 'a':
            if (modulo(data.coord_x-temp_x)<=valor)// 11-10 < 100
            {
              esquerda_fraco();
              ativo=1;
            }  
            else 
            {
              parar();
              //estado=proximo_estado;
              ativo=0;
              delay(atraso);
              return 1;
            }    
        break;
        case 'b':
            if (modulo(data.coord_x-temp_x)<=valor)// 11-10 < 100
            {
              direita_fraco();
              ativo=1;
            }  
            else 
            {
              parar();
              //estado=proximo_estado;
              ativo=0;
              delay(atraso);
              return 1;
            }    
        break;
      }   
      return 0;
}
//===================================================================================
// Descrição: Modulo
// Parametros: int
// Retornos: int 
// Indiretos: nada
// Data: 24/09/2013
// Author: Fabio, Robson
//===================================================================================
float modulo(float valor)
{
    return sqrt(valor*valor);
}
//===================================================================================
// Descrição: Trajeto_1
// Parametros: int
// Retornos: int 
// Indiretos: nada
// Data: 24/09/2013
// Author: Fabio, Robson
//===================================================================================
void trajeto_1()
{
 
  le_mouse();
   //controle('r',500,2);
   //controle('e',650,0);
     
   switch(estado)
   {
    
     case 0:
         controle('f',100);
         if(data.vel_y<=0&&data.coord_y>50)//
         {
           estado=1;
         }
         else
         {
           estado=0;
         }
     break;
     case 1:
         if(controle('r',500)==1)
           estado=2;
     break;
     case 2:
         if(controle('d',giro)==1)
           estado=3;
     break;
     case 3:
         if(controle('f',800)==1)
           estado=4;
     break;
     case 4:
         if(controle('e',giro)==1)
           estado=0;
     break;
          
     default:
         estado=0;
         delay(5000);
     break;
  }
}
//===================================================================================
// Descrição: Trajeto_2 - percorre 5000 e gira e retorna 5000
// Parametros: int
// Retornos: int 
// Indiretos: nada
// Data: 25/09/2013
// Author: Robson
//===================================================================================
void trajeto_2()//MESA
{

  le_mouse();
   //controle('r',500,2);
   //controle('e',650,0);
      
   switch(estado)
   {
     case 0:
         controle('f',10000);
     break;
     case 1:
         controle('d',giro);
     break;
     case 2:
         controle('f',800);
     break;
     case 3:
         controle('d',giro);
     break;
     case 4:
         controle('f',10000);
     break;
     case 5:
         controle('d',giro);
     break;
     case 6:
         controle('f',800);
     break;
     case 7:
         controle('d',giro);
     break;
     
     default:
         estado=0;
         delay(5000);
     break;
  }
}
//===================================================================================
// Descrição: Trajeto_3 - Gira Gira
// Parametros: int
// Retornos: int 
// Indiretos: nada
// Data: 25/09/2013
// Author: Robson
//===================================================================================
void trajeto_3()
{
 int giro=600;// mudar de acordo com o piso
  le_mouse();
   //controle('r',500,2);
   //controle('e',650,0);
 
   switch(estado)
   {
     case 0:
         controle('d',giro);
     break;
     case 1:
         controle('e',giro);
     break;
     case 2:
         controle('f',500);
     break;
     case 3:
         controle('r',500);
     break;
     case 4:
         controle('e',500);
     break;
     
     default:
         estado=0;
         delay(5000);
     break;
  }
}
//===================================================================================
// Descrição: Trajeto_4 - usa esquerda fraco e direita fraco
// Parametros: int
// Retornos: int 
// Indiretos: nada
// Data: 26/09/2013
// Author: Robson
//===================================================================================
void trajeto_4()
{
 
  le_mouse();
   //controle('r',500,2);
   //controle('e',650,0);
       
   switch(estado)
   {
     case 0:
         controle('f',5000);
     break;
     case 1:
         controle('a',giro);
     break;
     case 2:
         controle('f',2000);
     break;
     case 3:
         controle('f',2000);
     break;
     case 4:
         controle('b',giro);
     break;
     case 5:
         controle('f',2000);
     break;
     case 6:
         controle('d',giro);
     break;
     case 7:
         controle('d',giro);
     break;
     case 8:
         controle('r',10000);
     break;
     
     default:
         estado=0;
         delay(5000);
     break;
  }
}

//===================================================================================
// Descrição: Função de lei.....
// Parametros: void
// Retornos: void
// Indiretos: struct COOD_MOUSE
// Data: 24/09/2013
// Author: Fabio, Robson
//===================================================================================
void le_mouse()
{
  //COORD_MOUSE interno;
  char mstat;
     /* PEGANDO A LEITURA DO MOUSE*/
   mouse_write(0xeb);  /* ME DE O DATA */
   mouse_read();      /* IGNORE ACK */
   mstat = mouse_read();// LE BOTOES
   data.vel_x = mouse_read();
   data.vel_y = mouse_read();
   
   data.coord_x=data.coord_x+data.vel_x;
   data.coord_y=data.coord_y+data.vel_y;
   
   delay(1);//nao remover
}

void parar()
{
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);
}

void reverse()
{
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);
}

void frente()
{
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}
void esquerda_fraco()
{
   digitalWrite(M1A, LOW);
   digitalWrite(M1B, HIGH);
}
void direita_fraco()
{
   digitalWrite(M2A, LOW);
   digitalWrite(M2B, HIGH);
}
void esquerda_forte()
{
   digitalWrite(M1A, HIGH);
   digitalWrite(M1B, LOW);
   digitalWrite(M2A, LOW);
   digitalWrite(M2B, HIGH);
}
void direita_forte()
{
   digitalWrite(M1A, LOW);
   digitalWrite(M1B, HIGH);
   digitalWrite(M2A, HIGH);
   digitalWrite(M2B, LOW);
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

void mouse_write(char data)
{
  char i;
  char parity = 1;
 
  gohi(MDATA);
  gohi(MCLK);
  delayMicroseconds(300);
  golo(MCLK);
  delayMicroseconds(300);

  /* colocando os pinos em output */  
  golo(MDATA);
  delayMicroseconds(10);
  /* start bit */
  gohi(MCLK);
  
  /* aguardar o mouse pegar o controle do clock); */
  while (digitalRead(MCLK) == HIGH);
  
    
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
  /* parando o  bit */
  gohi(MDATA);
  delayMicroseconds(50);
  while (digitalRead(MCLK) == HIGH)
    ;
  /* aguardando o switch modes do mouse*/
  while ((digitalRead(MCLK) == LOW) || (digitalRead(MDATA) == LOW))
    ;
  /* put a hold on the incoming data. */
  golo(MCLK);
}
//  pegando um byte do data do mouse
char mouse_read(void)
{
  char data = 0x00;
  int i;
  char bit = 0x01;

  // ("lendo o byte do mouse\n");
  /* iniciando o  clock */
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

  golo(MCLK);
  return data;
}

// iniciando o mouse
void mouse_init()
{
  gohi(MCLK);
  gohi(MDATA);
//  ("enviando reset para  mouse\n");
  mouse_write(0xff);
  mouse_read();  /* ack byte */
//  ("lendo ack byte1\n");
  mouse_read();  /* branco */
  mouse_read();  /* branco */
// ("Enviando remote mode code\n");
  mouse_write(0xf0);  /* modo remoto */
  mouse_read();  /* ack */
// ("Lendo ack byte2\n");
  delayMicroseconds(1000);
}


