// PROGRAMA: LUZ NOCTURNA, ON/OFF RELEVADOR Y FOCO
// TIMIBOT

const int ldr = 2;
const int foco = 7;
const int lim = 800;
int valor_ldr = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(foco,OUTPUT);  // pin de relevador
}

void loop() {

  valor_ldr = analogRead(ldr);  //lee el valor analogico de la fotorresistencia
  Serial.println(valor_ldr);

  if(valor_ldr >= lim) {
    digitalWrite(foco,HIGH); // enciende foco
  }
  else { 
    digitalWrite(foco,LOW);  // apaga foco
  }
}
