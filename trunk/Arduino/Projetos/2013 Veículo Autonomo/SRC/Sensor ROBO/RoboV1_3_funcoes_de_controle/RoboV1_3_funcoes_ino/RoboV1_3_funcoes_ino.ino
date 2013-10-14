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
reverse();
delay (1000);
parar();
delay(1000);
frente();
delay(1000);
 
}

void parar()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void frente()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void reverse()
{
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH);
   digitalWrite(5, LOW);
   digitalWrite(4, HIGH);
}


void esquerda_fraco_M1()
{
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
}
void direita_fraco_M2()
{
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);
}
void esquerda_forte_M1()
{
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(5, LOW);
   digitalWrite(4, HIGH);
}
void direita_forte_M2()
{
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH);
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

void reverse_M1()
{
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH);
}

void reverse_M2()
{
   digitalWrite(5, LOW);
   digitalWrite(4, HIGH);
}
