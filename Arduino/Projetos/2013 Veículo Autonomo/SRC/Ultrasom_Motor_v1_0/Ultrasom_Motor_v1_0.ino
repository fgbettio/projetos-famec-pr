#define M1A 2// 
#define M1B 3
#define M2A 4
#define M2B 5

#define SensorM1 7
#define SensorM1 8

#define LED 10

#define echoPin 9 //Pino 13 recebe o pulso do echo  
#define trigPin 8 //Pino 12 envia o pulso para gerar o echo  
#define tempo 500

//========================
int controle;
void setup() 
{
  Serial.begin(9600); //inicia a porta serial  
  pinMode(M1A, OUTPUT);//2
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT); 
  pinMode(M2B, OUTPUT);
  pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)  
  pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)   
  randomSeed(analogRead(0));
  delay(1000);
}

void loop() {
  
  if(verif_distancia()<40)
  {
    recua();
    delay(800);
    para();
    delay(1500);
    //random()
    if(random(0,2)==1)
      direita_suave();
    else
      esquerda_suave();
    delay(500);
    
  }
  else
  {
    frente();
    delay(15);
  }
  para();
  delay(1);
}
//=========================================================================
// ------------------------------------------------------
// Funcoes Auxiliares
// Desenvolvido por: Thiago
// Data: 14/setembro/2012
void frente() 
{
  frente_M1();
  frente_M2();
}
void recua() 
{
  re_M1();
  re_M2();
}
void para()
{
  parar_M1();
  parar_M2();
}

void direita_suave() 
{
  frente_M1();
  parar_M2();
}

void direita_forte()
{
  frente_M1();
  re_M2();
}
void esquerda_suave()
{
  frente_M2();
  parar_M1();
}
void esquerda_forte()
{
  frente_M2();
  re_M1();
}
/*-------------------------------------------------------
 Nome:  verif_distancia()
 Descricao: retorna a distancia do antepara em centimetros
 Parametros: nada
 Retornos: distancia em centimetros
 Indiretos: nada
 Data: 30/10/2013
 Autor: Fabio Bettio
 --------------------------------------------------------*/
long verif_distancia()
{
    //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0  
    digitalWrite(trigPin, LOW);  
  // delay de 2 microssegundos  
    delayMicroseconds(2);  
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1  
    digitalWrite(trigPin, HIGH);  
  //delay de 10 microssegundos  
    delayMicroseconds(10);  
  //seta o pino 12 com pulso baixo novamente  
    digitalWrite(trigPin, LOW);  
  //pulseInt lê o tempo entre a chamada e o pino entrar em high  
    long duration = pulseIn(echoPin,HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
    long distancia = duration /29 / 2 ;  
    return distancia;
}
//=========================================================================

//FUNÃ‡OES DE BAIXO NIVEL === ACESSO AO HARDWARE
void ativa_led()
{
  digitalWrite(LED, HIGH);
}
void desativa_led()
{
  digitalWrite(LED, LOW);
}
void frente_M1()
{
   digitalWrite(M1A, LOW);
   digitalWrite(M1B, HIGH);
}
void re_M1()
{
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
}
void frente_M2()
{
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}
void re_M2()
{
  digitalWrite(M2A, HIGH);   // set the LED on
  digitalWrite(M2B, LOW);   // set the LED off
}
void parar_M1()
{
 digitalWrite(M1A, LOW);   // set the LED on
 digitalWrite(M1B, LOW);   // set the LED off 
}
void parar_M2()
{
  digitalWrite(M2A, LOW);   // set the LED on
  digitalWrite(M2B, LOW);   // set the LED off
}
// TABELA DE CONTROLE DO MOTOR 1/2
// P0 P1   SENTIDO          P2 P3  SENTIDO
// 0  0    PARADO           0  0   PARADO
// 0  1    FRENTE           0  1   FRENTE
// 1  0    RE               1  0   RE
// 1  1    PARADO           1  1   PARADO

