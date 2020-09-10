// PROGRAMA: LECTURA DE VOLTAJE ANALOGICO CON POTENCIOMETRO Y EL MONITOR SERIAL
// TIMIBOT

int valor = 0;
float voltaje = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  valor = analogRead(A0);   // lee puerto analogico donde se encuentra potenciometro
  Serial.println(valor);    // imprime el valor de la lectura analogica en el monitor Serial

  voltaje = valor*5/1024;   // convierte el valor analogico a un valor de voltaje
  Serial.println(voltaje);  // imprime el valor de la lectura analogica en el monitor Serial

  delay(1000);  // espera 1 segundo
}
