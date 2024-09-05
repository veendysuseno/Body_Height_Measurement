// Code Body_Height_Measurement
#define ECHOPIN 10                            
#define TRIGPIN 11                            
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int H2,HT,H1;

void setup(){
  lcd.begin(16, 2);
  lcd.print("Tinggi Badan");
  lcd.setCursor(0, 1);
  lcd.print("TB=");

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  delay(1000);
  HT=200;
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  int distance = pulseIn(ECHOPIN, HIGH);        
  distance= distance/58;                        
  H2=HT-distance;                    
  lcd.setCursor(3, 1);
  lcd.print(H2); 
  lcd.print(" cm ");
  delay(1000);    
}

