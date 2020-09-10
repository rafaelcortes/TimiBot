// PROGRAMA : IMPRESION EN LA PANTALLA LCD 16X2, EL MENSAJE “HOLA_MUNDO!”
// TIMIBOT

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

void setup() {
  
  lcd.init();
  lcd.backlight(); 
}

void loop(){

  lcd.setCursor(0,0);
  lcd.print("   HOLA MUNDO   ");
  lcd.setCursor(0,1);  
  lcd.print("   TIMIBOT    ");  
  delay(2000); 
}
