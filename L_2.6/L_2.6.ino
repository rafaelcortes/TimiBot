// PROGRAMA: SENSOR DE TEMPERATURA
// TIMIBOT

float tempC = 0;
int sensor = 0;
const int LM35 = 1;

void setup() {
  
  Serial.begin(9600);
}
void loop() {
     
  sensor = analogRead(LM35);  // Lee el valor desde el sensor

  tempC = (5 * sensor * 100.0)/1024.0;  // Convierte el valor a temperatura

  Serial.print(tempC);  // Imprime en el monitor Serial la Temperatura
  Serial.println(" C");
  
  delay(5000);
}
