
#include<LiquidCrystal.h>
int echo=6;
int trig=7;
LiquidCrystal lcd(13,12,11,10,9,8);
int buzzer=5;
long duration,distance;

void setup() {
  pinMode(echo,OUTPUT);
  pinMode(trig,INPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=((duration*0.034)/2);
  lcd.clear();
  lcd.print("Distance(cm):");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.setCursor(1,1);
  if(distance<50){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  delay(100);
  
}
