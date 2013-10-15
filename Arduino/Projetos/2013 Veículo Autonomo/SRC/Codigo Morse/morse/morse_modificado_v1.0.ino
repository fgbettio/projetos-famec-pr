int pin = 8;
int codigo=12;
int vetbin[8];
int cont;
void setup()
{
 Serial.begin(9600);
  pinMode(pin, OUTPUT);
}



void loop()
{
  dot(); dot(); dot();
  dash(); dash(); dash();
  dot(); dot(); dot();
  dec2bin(codigo);
  delay(3000);
  
}

void dot()
{
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
  delay(250);
}

void dash()
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(250);
}


void dec2bin(int valor)
  {
    int resto;
      for (cont=7; cont<=0;cont--)
      {
        if (valor >=1)
        {
            resto = valor %2;
            vetbin[cont]=resto;
            Serial.print(resto);
            valor = (valor /2)
              if (valor == 1)
              {
                vetbin[cont]=valor;
              }
                           
          }
          
        else 
         {   
           
           /// parei aqui, falta preencher o resto do vetor com 000000
            Serial.print(valor);
            vetbin[cont]=valor;
          }
      }     
  
        vetbin[3]=0;
        vetbin[2]=0;
        vetbin[1]=0;
        vetbin[0]=0;
        Serial.println();
        
    for (int i=0;i<=7;i++)
    {
      Serial.print (vetbin[i]);
      
    }
    Serial.println();
  }
