// PROGRAMA : ROBOT SEGUIDOR DE LUZ
// TIMIBOT

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

int valorA2;                  //variable sensor luz izquierdo, controla motor derecho
int valorA3;                  //variable sensor luz derecho, controla motor izquierdo
//int M1 = D10;
//int M2 = D6; 

void setup () {
lcd.init();
lcd.backlight(); 
lcd.setCursor(1,0);
lcd.print("SEGUIDOR DE LUZ");
lcd.setCursor(4,1);
lcd.print("TIMIBOT");
pinMode(10, OUTPUT);            //MOTOR DERECHO
pinMode(6, OUTPUT);             //MOTOR IZQUIERDO
}

void loop() {
valorA2=analogRead(A2);       //Valor señal de entrada sensor izquierdo
valorA3=analogRead(A3);       // Valor señal de entrada sensor derecho

if (valorA2<=960) {
digitalWrite(6,LOW);
}
else {
digitalWrite(6,HIGH);
}

if (valorA3<=960) {
digitalWrite(10,LOW);
}
else {
digitalWrite(10,HIGH);
}

}
