
// PROGRAMA: CONTROL DE LA INTENSIDAD DE UN LED
// TIMIBOT

int valor_pot = 0;
int brillo = 0;

void setup() {
    
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  
  valor_pot = analogRead(A0);
  Serial.print("Valor_pot = ");
  Serial.println(valor_pot);
  brillo = map(valor_pot,0,1023,0,255);
  Serial.print("Brillo = ");
  Serial.println(brillo);

  analogWrite(13,brillo); // analogWrite(nombre o numero de pin "," valor PWM de 0 a 255)
}
