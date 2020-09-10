// PROGRAMA: CONTROL CON SENSOR DE LUZ, ON/OFF LED
// TIMIBOT

const int led = 13;
const int ldr = A2;
const int lim = 500;
int valor_ldr = 0;

void setup() {
    
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  
  valor_ldr = analogRead(ldr);  // lee el valor analogico de la fotorresistencia
  Serial.println(valor_ldr);

  if(valor_ldr >= lim) {
    digitalWrite(led,HIGH); // enciende led
  }
  else { 
    digitalWrite(led,LOW);  // apaga led
  }
}
