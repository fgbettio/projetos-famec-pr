

int sensorPin = A0;    // select the input pin for the potentiometer
int micPin = A1;    // select the input pin for the potentiometer
int bipPin = 2;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int micValue = 0;  // variable to store the value coming from the sensor


void setup() {
  Serial.begin(9600); 
  pinMode(bipPin, OUTPUT);  
}

void loop() {

  sensorValue = analogRead(sensorPin);    
  micValue = analogRead(micPin);    

  Serial.print("Sensor Valor: ");  
  Serial.print(sensorValue, DEC);  
  
  Serial.print("\t Mic Valor: ");  
  Serial.println(micValue, DEC);  

  bip(500,bipPin);
}

// ========= Funções ======================================================
// Descrição: Função aciona um buzzer com oscilador, HIGH o buzzer toca, LOW o buzzer silencia
// Parametros, int valor: tempo em milisegundos que o bip fica desligado, int pino: pino oonde está ligado o buzzer.
// ========================================================================
void bip(int valor,int pino)
{
  digitalWrite(pino, HIGH);  
  delay(100);          
  digitalWrite(pino, LOW);   
  delay(valor);                  

}
