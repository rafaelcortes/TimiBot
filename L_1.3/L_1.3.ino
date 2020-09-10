// PROGRAMA: SEMAFORO
// TIMIBOT

void setup(){
  
  pinMode(11, OUTPUT);   //LED VERDE
  pinMode(12, OUTPUT);   //LED AMARILLO
  pinMode(13, OUTPUT);   //LED ROJO
}
 
void loop(){
   
  digitalWrite(11, HIGH);   // Enciende LED VERDE
  delay(25000);             // Espera por veinticinco segundos
  digitalWrite(11, LOW);    // Apaga LED VERDE
  delay(500);               // Espera por medio segundo
  
  digitalWrite(12, HIGH);   // Enciende LED AMARILLO
  delay(5000);              // Espera por cinco segundos
  digitalWrite(12, LOW);    // Apaga LED AMARILLO
  delay(500);               // Espera por medio segundo
  
  digitalWrite(13, HIGH);   // Enciende LED ROJO
  delay(20000);             // Espera por veinte segundos
  digitalWrite(13, LOW);    // Apaga LED ROJO
  delay(500);               // Espera por medio segundo
}
