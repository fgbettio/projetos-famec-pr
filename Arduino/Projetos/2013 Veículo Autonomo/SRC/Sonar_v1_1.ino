

int sensorPin = A0;    // select the input pin for the potentiometer
int micPin = A1;    // select the input pin for the potentiometer
int bipPin = 2;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int micValue = 0;  // variable to store the value coming from the sensor
int cont=0;


void setup() {
  Serial.begin(9600); 
  pinMode(bipPin, OUTPUT);  
}

void loop() {
  cont=0;
  //sensorValue = analogRead(sensorPin);    
  //micValue = analogRead(micPin);    

  bip(bipPin);
  while(analogRead(micPin)>500);// espera acabar o bit de inicio
  micValue=analogRead(micPin);
  while(micValue<70)
  {
    micValue=analogRead(micPin);
    cont++;
    if(cont>10000)
      break;
  }
  Serial.print("Mic: ");  
  Serial.print(micValue, DEC);  
  Serial.print("\t cont: ");  
  Serial.println(cont, DEC);  
  delay(1000);
  
  //Serial.print("\t Mic Valor: ");  
  //Serial.println(micValue, DEC);  
}

// ========= Funções ======================================================
// Descrição: Função aciona um buzzer com oscilador, HIGH o buzzer toca, LOW o buzzer silencia
// Parametros, int valor: tempo em milisegundos que o bip fica desligado, int pino: pino oonde está ligado o buzzer.
// ========================================================================
void bip(int pino)
{
  digitalWrite(pino, HIGH);  
  delay(10);          
  digitalWrite(pino, LOW);   
  //delay(valor);                  

}
