
// PROGRAMA : BOTON ON/OFF CON LED
// TIMIBOT

int pulsador = 0;     

void setup(){
  
  pinMode(3, INPUT);     // Botón 
  pinMode(13, OUTPUT);   // Led Rojo
}
 
void loop(){

  pulsador = digitalRead(3);  // lee el estado del boton y almacena
  
  if(pulsador == HIGH) {       // si el boton es pulsado
    digitalWrite(13, HIGH);    // Enciende Led Rojo
  }
  else {                       // si el estado del boton es no pulsado
    digitalWrite(13, LOW);     // Apaga Led Rojo
  } 
}
