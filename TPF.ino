/*  Controlador de temperatura
    Esta máquina permite tener un control constante de la temperatura de aquello que estemos buscando medir, especificamente en este caso,
    este aparato se utilia para la medición de la temperatura de la plancha y de la carne que se este asando.
*/
//Librerias
  #include <max6675.h>
  #include <LiquidCrystal.h>
  #include <Wire.h>
  #include "RTClib.h"
  #include <SoftwareSerial.h>
  #include <LiquidCrystal.h>
  
//Variables
  int DO1 = 7;
  int CS1 = 6;
  int CLK1 = 5;
  int DO2 = 4;
  int CS2 = 3;
  int CLK2 = 2;
  int hora = 9999;
  int buzzer = 14;
  int ledR = 8;
  int ledG = 9;
  int ledB = 10;
  int BAN = 0;
  int BAN2 = 0;
  int alarma = 0;
  const int rs = 33, en = 35, d4 = 45, d5 = 47, d6 = 51, d7 = 53;
  float temperatura1;
  float temperatura2;
  char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  MAX6675 thermocouple1(CLK1, CS1, DO1);
  MAX6675 thermocouple2(CLK2, CS2, DO2);
  uint8_t degree[8]  = {140,146,146,140,128,128,128,128};
  RTC_DS1307 RTC;
  SoftwareSerial BT(1,0);
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
//Funciones
  void bluetooth();
  void thermocouple();
  void rtc();
  void LCD();
  void led();
  void buzz();
  
void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, degree);
  lcd.setCursor(1, 0);
  lcd.print(" Bienvenido a");
  lcd.setCursor(1, 1);
  lcd.print("Electro  Chori");
  analogWrite(ledR,255);
  analogWrite(ledG,255);
  analogWrite(ledB,255);
  pinMode(buzzer, OUTPUT);
  BT.begin(9600);
  Wire.begin();
  RTC.begin();
  while (!Serial);
  Serial.begin(9600);
  if (! RTC.begin()) {
    Serial.println("No se pudo encontrar RTC");
    while (1);
  }
}

void loop() {
  if(BAN == 0){
    RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
  }
  bluetooth();
  if(BAN == 0){
    RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
  }
  thermocouple();
  if(BAN == 0){
    RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
  }
  rtc();
  if(BAN == 0){
    RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
  }
  LCD();
  if(BAN == 0){
    RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
  }
  buzz();
  if(BAN == 0){
    RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
  }
  led();
  if(BAN == 0){
    RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
  }
  delay(1000);
}

void bluetooth(){
  char valor;
  if(Serial.available())
  {
    valor = Serial.read();
    if(valor == 'A'){
      hora = 15;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'B'){
      hora = 20;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'C'){
      hora = 23;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'D'){
      hora = 40;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'E'){
      hora = 45;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'F'){
      hora = 55;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'G'){
      hora = 50;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'H'){
      hora = 60;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'I'){
      hora = 70;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'J'){
      hora = 15;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'K'){
      hora = 25;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'L'){
      hora = 35;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'M'){
      hora = 35;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'N'){
      hora = 40;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'Ñ'){
      hora = 45;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'O'){
      hora = 18;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'P'){
      hora = 23;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'Q'){
      hora = 27;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'R'){
      hora = 30;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'S'){
      hora = 40;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'T'){
      hora = 50;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'U'){
      hora = 30;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'V'){
      hora = 40;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'W'){
      hora = 50;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'X'){
      hora = 40;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'Y'){
      hora = 50;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'Z'){
      hora = 60;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'a'){
      hora = 5;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'b'){
      hora = 10;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'c'){
      hora = 15;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'd'){
      hora = 20;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'e'){
      hora = 25;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'f'){
      hora = 30;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'g'){
      hora = 35;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'h'){
      hora = 40;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'i'){
      hora = 45;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'j'){
      hora = 50;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'k'){
      hora = 55;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'l'){
      hora = 60;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 1;
    }
    if(valor == 'z'){
      alarma = 1;
      RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      BAN = 0;
      
    }
  }
}

void buzz(){
  DateTime now = RTC.now();
  if(hora <= now.minute() && alarma == 0){
    while(alarma != 1){
      analogWrite(buzzer,128);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
      if(BAN == 0){
        RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      }
      rtc();
      if(BAN == 0){
        RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      }
      thermocouple();
      if(BAN == 0){
        RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      }
      led();
      if(BAN == 0){
        RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      }
      bluetooth();
      if(BAN == 0){
        RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      }
      LCD();
      if(BAN == 0){
        RTC.adjust(DateTime(2020, 0, 0, 0, 0, 0));
      }
      if (temperatura1 > 50.00){
       analogWrite(buzzer,128);
      delay(10000);
      digitalWrite(buzzer, LOW);
      delay(500);
      }
       if (temperatura2 > 50.00){
       analogWrite(buzzer,128);
      delay(10000);
      digitalWrite(buzzer, LOW);
      delay(500);
      }
    }
  }
}

void thermocouple(){
  temperatura1 = thermocouple1.readCelsius();
  temperatura2 = thermocouple2.readCelsius();
  Serial.print(temperatura1);
  Serial.print(",");
  Serial.print(temperatura2);
  Serial.print(",");
}

void rtc(){
  DateTime now = RTC.now();
  Serial.print(now.minute(), DEC);
  Serial.print(",");
  Serial.print(now.second(), DEC);
  if(now.minute() == hora){
    analogWrite(buzzer,128); /3/emite sonido
    delay(500); //espera medio segundo
    digitalWrite(buzzer, LOW); //deja de emitir
    delay(500);//espera medio segundo
    hora = 9999;
  }
}

void led(){
  if(BAN == 0 && BAN2 == 1){
    analogWrite(ledR,255);
    analogWrite(ledG,255);
    analogWrite(ledB,255);
  }
  if(BAN == 1){
    if(temperatura1 < 40.00){
      analogWrite(ledR,255);
      analogWrite(ledG,0);
      analogWrite(ledB,0);
    }
    if(temperatura1 > 40.00 && temperatura1 < 50.00){
      analogWrite(ledR,0);
      analogWrite(ledG,255);
      analogWrite(ledB,0);
    }
    if(temperatura1 > 50.00){
      analogWrite(ledR,0);
      analogWrite(ledG,0);
      analogWrite(ledB,255);
    }
  }
}

void LCD(){
  DateTime now = RTC.now();
  if(BAN == 1){
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Tiempo:");
    lcd.setCursor(1, 1);
    lcd.print(now.minute(), DEC);
    lcd.print(":");
    lcd.print(now.second(), DEC);
    lcd.print(" de ");
    lcd.print(hora);
    lcd.print(" min");
    BAN2 = 1;
  }
  if(BAN2 == 1 && BAN == 0){
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print(" Electro  Chori");
    lcd.setCursor(1, 1);
    lcd.print("  °v° :D ovo :3");
  }
}
