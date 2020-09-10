// PROGRAMA : PRENDIENDO MI PRIMER LED
// TIMIBOT

void setup(){ 
  pinMode(13, OUTPUT);   //LED  AZUL
}
 
void loop(){   
  digitalWrite(13, HIGH);   // Enciende LED ROJO
  delay(1000);              // Espera por un segundo
  digitalWrite(13, LOW);    // Apaga LED ROJO
  delay(1000);              // Espera por un segundo
}
