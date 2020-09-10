
// PROGRAMA: IMPRESION EN EL MONITOR SERIAL
// TIMIBOT
 
void setup() {
  Serial.begin(9600); // Se inicializa la comunicacion Serial
}
 
void loop(){

  Serial.println("Hola_Mundo!"); // Imprime en el monitor Serial
}
