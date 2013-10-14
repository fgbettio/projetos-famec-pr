void setup()
{
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
}

void loop()
{
  frente_M1();
  delay(1000);
  frente_M2();
  delay(1000);
  Parar_M1();
  delay(1000);
  Parar_M2();
  delay(1000);
  
}




void frente_M1()
{
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
}
void frente_M2()
{
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);
}
void Parar_M1()
{
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
}
void Parar_M2()
{
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
}

