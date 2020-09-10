// PROGRAMA: SENSOR DE DISTANCIA
// TIMIBOT

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  

long distancia;
long tiempo;

void setup() {  
lcd.init();             // Inicia el display
lcd.backlight();        // Prende su luz
   
pinMode(8, OUTPUT);    //Ultrasonico TRIG
pinMode(9, INPUT);     //Ultrasonico ECHO
}

void loop() {
       
  digitalWrite(8,LOW);      // Recibe pulso
  delayMicroseconds(5);
  digitalWrite(8, HIGH);    // Envia pulso
  delayMicroseconds(10);
  
  tiempo = pulseIn(9, HIGH);         // formula para calcular el tiempo
  distancia = long(0.017*tiempo);    // Formula para calcular la distancia
  lcd.setCursor(0,0);                // Localizacion
  lcd.print("DISTANCIA EN CM: ");    // Imprime en el display
  lcd.setCursor(8,1);                // Localizacion
  lcd.print(distancia);              // Imprime en el display
  delay(1000);
}
