
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int M1 = 10;
const int M2 = 6; 

const int LM35 = A1;
const int ldr1 = A2;
const int ldr2 = A3;

int pulsador1 = 0, pulsador2 = 0, pulsador3 = 0, pulsador4 = 0;

int valor = 0;
float voltaje = 0;

int valor_ldr1 = 0;
int valor_ldr2 = 0;

float tmp_C = 0;
int sensor = 0;

float distancia;
long tiempo;

int prueba = 1;

void setup() {

  lcd.init();

  lcd.backlight();

  if(prueba == 1) {

    // LEDS

    pinMode(11, OUTPUT);   //LED  VERDE
    pinMode(12, OUTPUT);   //LED  AMARILLO
    pinMode(13, OUTPUT);   //LED  ROJO

    lcd.setCursor(0,0);
    lcd.print("Prueba 1: 10 seg");
    lcd.setCursor(0,1);
    lcd.print("Led's");

    digitalWrite(11, HIGH);   // Enciende LED VERDE
    digitalWrite(12, HIGH);   // Enciende LED AMARILLO
    digitalWrite(13, HIGH);   // Enciende LED ROJO
  
    delay(10000);              // Espera por medio segundos
  
    digitalWrite(11, LOW);    // Apaga LED VERDE
    digitalWrite(12, LOW);    // Apaga LED AMARILLO
    digitalWrite(13, LOW);    // Apaga LED ROJO
  
    delay(500);              // Espera por medio segundo

    // SWITCHES
  
    pinMode(3, INPUT);     // Botón 1
    pinMode(4, INPUT);     // Botón 2
    pinMode(5, INPUT);     // Botón 3

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Prueba 2");
    lcd.setCursor(0,1);
    lcd.print("Pulsador1: 5 seg");

    for (unsigned long start = millis(); millis() - start < 5000;) {
    
      pulsador1 = digitalRead(3);  // lee el estado del boton y almacena
  
      if(pulsador1 == HIGH) {       // si el boton es pulsado
        digitalWrite(13, HIGH);    // Enciende Led Azul
      }
      else {                       // si el estado del boton es no pulsado
        digitalWrite(13, LOW);     // Apaga Led Azul
      }     
    }

    digitalWrite(13, LOW);

    lcd.setCursor(0,1);
    lcd.print("Pulsador2: 5 seg");

    for (unsigned long start = millis(); millis() - start < 5000;) {
    
      pulsador1 = digitalRead(4);  // lee el estado del boton y almacena
  
      if(pulsador1 == HIGH) {       // si el boton es pulsado
        digitalWrite(12, HIGH);    // Enciende Led Azul
      }
      else {                       // si el estado del boton es no pulsado
        digitalWrite(12, LOW);     // Apaga Led Azul
      }     
    }
  
    digitalWrite(12, LOW);

    lcd.setCursor(0,1);
    lcd.print("Pulsador3: 5 seg");

    for (unsigned long start = millis(); millis() - start < 5000;) {
    
      pulsador1 = digitalRead(5);  // lee el estado del boton y almacena
  
      if(pulsador1 == HIGH) {       // si el boton es pulsado
        digitalWrite(11, HIGH);    // Enciende Led Azul
      }
      else {                       // si el estado del boton es no pulsado
        digitalWrite(11, LOW);     // Apaga Led Azul
      }     
    }
  
    digitalWrite(11, LOW);

    // POTENCIOMETRO

    for (unsigned long start = millis(); millis() - start < 10000;) {

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Prueba 3: 10 seg");
      lcd.setCursor(0,1);
      lcd.print("Pot:");
    
      valor = analogRead(A0);   // lee puerto analogico donde se encuentra potenciometro
    
      lcd.setCursor(5,1);
      lcd.print(valor);
    
      delay(1000);
    }

    // FOTORRESISTENCIAS

    for (unsigned long start = millis(); millis() - start < 10000;) {

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Prueba 4: 10 seg");
      lcd.setCursor(0,1);
      lcd.print("FR1:    FR2:");
    
      valor_ldr1 = analogRead(ldr1);
      valor_ldr2 = analogRead(ldr2);  
    
      lcd.setCursor(4,1);
      lcd.print(valor_ldr1);
      lcd.setCursor(12,1);
      lcd.print(valor_ldr2);
    
      delay(1000);
    }

    // SENSOR DE TEMPERATURA
  
    for (unsigned long start = millis(); millis() - start < 10000;) {

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Prueba 5: 10 seg");
      lcd.setCursor(0,1);
      lcd.print("Tmp:");
    
      sensor = analogRead(LM35);  // Lee el valor desde el sensor

      tmp_C = (5 * sensor * 100.0)/1024.0;  // Convierte el valor a temperatura

      lcd.setCursor(5,1);
      lcd.print(tmp_C);
      lcd.setCursor(10,1);
      lcd.print(" C");
    
      delay(1000);
    }

    // ULTRASONICO

    pinMode(8, OUTPUT);    //Ultrasonico TRIG
    pinMode(9, INPUT);     //Ultrasonico ECHO

    for (unsigned long start = millis(); millis() - start < 10000;) {

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Prueba 6: 10 seg");
      lcd.setCursor(0,1);
      lcd.print("Dist:");

      digitalWrite(8,LOW);      // Recive pulso
      delayMicroseconds(5);
      digitalWrite(8, HIGH);    // Envia pulso
      delayMicroseconds(10);
    
      tiempo = pulseIn(9, HIGH);       // formula para calcular el tiempo
      distancia = float(0.017*tiempo);    // Formula para calcular la distancia

      lcd.setCursor(6,1);
      lcd.print(distancia);
      lcd.setCursor(13,1);
      lcd.print("cm");
    
      delay(1000);
    }

    // RELAY

    pinMode(7, OUTPUT);

    for(int x = 0 ; x < 5 ; x++) {

      digitalWrite(7, HIGH);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Prueba 7: 10 seg");
      lcd.setCursor(0,1);
      lcd.print("Relay: Encendido");

      delay(1000);

      digitalWrite(7, LOW);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Prueba 7: 10 seg");
      lcd.setCursor(0,1);
      lcd.print("Relay: Apagado");

      delay(1000);
    }
  }
  else if(prueba == 2) {

    // MOTORES
  
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);
  
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW); 
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Prueba 7");
    lcd.setCursor(0,1);
    lcd.print("Motor 1: 5 seg");
  
    digitalWrite(M1,HIGH);    // encender motor 1  
    delay(5000);
    digitalWrite(M1,LOW);
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Prueba 7");
    lcd.setCursor(0,1);
    lcd.print("Motor 2: 5 seg");
  
    digitalWrite(M2,HIGH);    // encender motor 2
    delay(5000);
    digitalWrite(M2,LOW);
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Prueba 7");
    lcd.setCursor(0,1);
    lcd.print("Motores: 5 seg");
  
    digitalWrite(M1,HIGH);    // encender motor 1  
    digitalWrite(M2,HIGH);    // encender motor 2
    delay(5000);
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW); 
  } 
}

void loop() {

  //digitalWrite(M1,HIGH);    // encender motor 1  
  //digitalWrite(M2,HIGH);    // encender motor 2
}
