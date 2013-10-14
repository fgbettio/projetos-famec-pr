//verÃ§Ã£o OK, porem lenta
 void setup()
{
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  
  
  digitalWrite(7, LOW);
}
int val_lido_e;
int val_lido_d;
int entrada_e=0;
int entrada_d=1;
int direita_media,esquerda_media,f;
void loop()
{
  //val_lido_e = analogRead(entrada_e); //lÃª o sensor da esquerda
  //val_lido_d = analogRead(entrada_d); //lÃª o sensor da direita
  ativa_led();
  delay(200);
  desativa_led();
  
  frente_M1();
  frente_M2();
  delay(1000);
  parar_M1();
  parar_M2();
  
  
}

// ------------------------------------------------------
// FunÃ§Ãµes Auxiliares
// Desenvolvido por: Thiago
// Data: 14/setembro/2012
void esquerda_fraco(int dist) //movimenta para esquerda usando um dos motores
{
  float tempo;
  tempo=dist*10.5;
  esquerda_suave();
  delay(tempo);
  para();
}
void direita_fraco(int dist) //movimenta para direita usando um dos motores
{
  float tempo;
  tempo=dist*9;
  direita_suave();
  delay(tempo);
  para();
}
//
void direita_pesado(int dist) ////movimenta para direita usando um dos motores de modo inverso
{
  float tempo;
  tempo=dist*5.75;
  frente_M1();
  re_M2();
  delay(tempo);
  para();
}
void frente() //piso famec
{
//  float tempo;
//  tempo=dist*3508.77;
  frente_M1();
  frente_M2();
//  delay(tempo);
//  para();
}
//
//void frente(int dist) //piso casa
//{
//  float tempo;
//  tempo=dist*3400;
//  frente_M1();
//  frente_M2();
//  delay(tempo);
//  para();
//  delay(3000);
//}

//FUNÃ‡OES DE MEDIO NIVEL
//void pisca_farol(int i)
//{
//  int x;
//  for(x=0; x<i; x++)
//  {
//    ativa_led();
//    delay(500);
//    desativa_led();
//    delay(500);
//  }
//  desativa_led();
//}
//void ligar_farol()
//{
//  ativa_led();
//}
//void desliga_farol()
//{
//  desativa_led();
//}
void direita_suave() 
{
  frente_M1();
  parar_M2();
}
void direita_suave_vel(int vel_lig, int vel_des) 
{
  frente_M1();
  parar_M2();
  delay(vel_lig);
  parar_M1();
  delay(vel_des);
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
void esquerda_suave_vel(int vel_lig, int vel_des)
{
  frente_M2();
  parar_M1();
  delay(vel_lig);
  parar_M2();
  delay(vel_des);
}
void esquerda_forte()
{
  frente_M2();
  re_M1();
}
void para()
{
  parar_M1();
  parar_M2();
}

//FUNÃ‡OES DE BAIXO NIVEL === ACESSO AO HARDWARE
void ativa_led()
{
  digitalWrite(7, HIGH);
}
void desativa_led()
{
  digitalWrite(7, LOW);
}
void frente_M1()
{
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
}
void re_M1()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}
void frente_M2()
{
  digitalWrite(4, LOW);//0
  digitalWrite(5, HIGH);//1
  //00-para
  //01-anda
  //10-anda
  //11-para
}
void re_M2()
{
  digitalWrite(4, HIGH);   // set the LED on
  digitalWrite(5, LOW);   // set the LED off
}
void parar_M1()
{
 digitalWrite(2, LOW);   // set the LED on
 digitalWrite(3, LOW);   // set the LED off 
}
void parar_M2()
{
  digitalWrite(4, LOW);   // set the LED on
  digitalWrite(5, LOW);   // set the LED off
}
// TABELA DE CONTROLE DO MOTOR 1/2
// P0 P1   SENTIDO          P2 P3  SENTIDO
// 0  0    PARADO           0  0   PARADO
// 0  1    FRENTE           0  1   FRENTE
// 1  0    RE               1  0   RE
// 1  1    PARADO           1  1   PARADO

