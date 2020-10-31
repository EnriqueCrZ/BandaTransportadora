#include <LiquidCrystal_I2C.h>
const int Trigger = 2;
const int Echo = 3;
int Sensor = A0;
int pinLedR = 10;  // pin Rojo del led RGB
int pinLedV = 11;  // pin Verde del led RGB
int pinLedA = 12;   // pin Azul del led RGB
int pausa = 1000;
const int relepin=9;

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  pinMode(pinLedR, OUTPUT);    // pone el pinLedR como output
  pinMode(pinLedV, OUTPUT);    // pone el pinLedV como output
  pinMode(pinLedA, OUTPUT);   // pone el pinLedA como output
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  pinMode(relepin, OUTPUT);
}
void color (int rojo, int verde, int azul) {
  analogWrite(pinLedR, rojo);
  analogWrite(pinLedV, verde);
  analogWrite(pinLedA, azul);
}
void loop() {
  

  delay(pausa);       // delay por pausa
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);*/

  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  if(d<=5){
 color(0, 255, 0);   // rojo
    int lectura = analogRead(Sensor);
    float voltaje = 5.0 /1024 * lectura ; 
    float temp = voltaje * 100 -50 ; 
    lcd.init();
  lcd.backlight();
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tempuratura: ");
    lcd.setCursor (0,1);
    lcd.print(temp);
    digitalWrite(relepin, LOW);
    delay(100);
    if(temp >=25)
     digitalWrite(relepin, LOW);
     
    }
    else {
      color(255, 0, 0);
      digitalWrite(relepin, HIGH);
    }
  
}
  
