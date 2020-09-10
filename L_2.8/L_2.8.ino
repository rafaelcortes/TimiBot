// PROGRAMA : PRENDIENDO Y APAGANDO MOTORES
// TIMIBOT

int M1 = 0;
int M2 = 1; 

void setup(){
  
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}
 
void loop(){
 
  digitalWrite(M1,LOW);     // apagar motor 1
  //digitalWrite(M2,LOW);
  delay(2000);
 
  digitalWrite(M1,HIGH);    // encender motor 1
  //digitalWrite(M2,HIGH); 
  delay(2000);
}
