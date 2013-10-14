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

