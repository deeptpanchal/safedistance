#include "pin_config.h"

void pinmode()
{
  pinMode(Stopping_relay, OUTPUT);
  //  pinMode(Mot_in_1, OUTPUT);
  //  pinMode(Mot_in_2, OUTPUT);
  //  //pinMode(Mot_en, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(alarm, OUTPUT);
}

//*************************************************** Motor function ****************************************************//

//void Motor_Clock()
//{
//  digitalWrite(Mot_in_1, HIGH);
//  digitalWrite(Mot_in_2, LOW);
//}
//
//void Motor_Anticlock()
//{
//  digitalWrite(Mot_in_1, LOW);
//  digitalWrite(Mot_in_2, HIGH);
//}
//
//void Motor_Stop()
//{
//  digitalWrite(Mot_in_1, HIGH);
//  digitalWrite(Mot_in_2, HIGH);
//}

//***************************************************** Warning ********************************************************//

void Warning()
{
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Warning.......!!");
  lcd.setCursor(0, 1);
  lcd.print("Apply brake..");
  lcd.setCursor(1, 0);
  digitalWrite(alarm, HIGH);
  digitalWrite(LED, HIGH);
}

//************************************************* normal condition ***************************************//

void Normal()
{
  //Motor_Clock();
  digitalWrite(Stopping_relay, HIGH);
  lcd.display();
  digitalWrite(alarm, LOW);
  digitalWrite(LED, LOW);
}

//************************************************** ultrasonic *******************************************//

int calculateDistance()
{
  int d;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //delayMicroseconds(10);
  duration = pulseIn(echo, HIGH);
  d = (340 * duration * 0.0001) / 2;
  return d;
}

//************************************************* LCD DISPLAY ***********************************************//

void Lcd1()
{
  lcd.setCursor(1, 0);                       //top cursor
  lcd.print("D(cm): S(cm): V:");
  lcd.setCursor(0, 1);                        //bottom cursor
  lcd.print(distance);
  lcd.print("  ");
  lcd.leftToRight();
  lcd.print(Safe_distance);
  lcd.print("  ");
  lcd.leftToRight();
  lcd.print(Speed);
  lcd.print("km/h  ");
  lcd.setCursor(1, 0);
}

void Lcd2()
{
  lcd.setCursor(1, 0);
  lcd.print("OUT OF RANGE:   ");
  lcd.setCursor(0, 1);
  lcd.print("Speed : ");
  lcd.print(Speed);
  //lcd.leftToRight();
  lcd.print(" km/h");
  lcd.setCursor(1, 0);
}

//******************************************** Safe Distance ******************************//

void calculateSafeDistance()
{
  //  Read = analogRead(Analog_speed);
  Speed = 54;//map(Read, 0, 1023, 0, 90);
  S = (Speed * 5) / 18;
  Safe_distance = (S / 2) * ((S / 4) + 1);
}
