
// PROGRAMA : SERIE DE LEDS
// TIMIBOT

void setup(){
  
  pinMode(11, OUTPUT);   //LED  VERDE
  pinMode(12, OUTPUT);   //LED  AMARILLO
  pinMode(13, OUTPUT);   //LED  ROJO
}
 
void loop(){
  
  digitalWrite(11, HIGH);   // Enciende LED VERDE
  digitalWrite(12, HIGH);   // Enciende LED AMARILLO
  digitalWrite(13, HIGH);   // Enciende LED ROJO
  
  delay(500);               // Espera por medio segundos
  
  digitalWrite(11, LOW);    // Apaga LED VERDE
  digitalWrite(12, LOW);    // Apaga LED AMARILLO
  digitalWrite(13, LOW);    // Apaga LED ROJO
  
  delay(500);               // Espera por medio segundo
}
