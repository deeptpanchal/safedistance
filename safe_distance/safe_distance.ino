#include "function.h"
#include <Servo.h>.

Servo myServo;

void setup()
{
	Serial.begin(9600);
  	lcd.begin(16, 2);
  	pinmode();
  	myServo.attach(Servo_pin);
  	digitalWrite(Stopping_relay,HIGH);
}

void loop()
{
	for (int i = 0; i <= 180; i += 1)
  	{
    		myServo.write(i);
    		distance = calculateDistance();
    		delay(50);
	    	Serial.print(i);
    		Serial.print(",");
    		Serial.print(distance);
    		Serial.print(".");
    		calculateSafeDistance();
    		if (distance < Safe_distance)
    		{
      			if (distance < (Safe_distance / 2))
      			{
        			//Motor_Stop();
        			digitalWrite(Stopping_relay,LOW);
      			}
      			else
        			Warning();
    		}
    		else
    		{
      			Normal();
      			if (distance <= 400)
        			Lcd1();
      			else
        			Lcd2();
    		}
  	}

  	for (int i = 180; i >= 0; i -= 1)
  	{
    		myServo.write(i);
    		distance = calculateDistance();
    delay(50);
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    calculateSafeDistance();
    if (distance < Safe_distance)
    {
      if (distance < (Safe_distance / 2))
      {
        //Motor_Stop();
        digitalWrite(Stopping_relay,LOW);
      }
      else
        Warning();
    }
    else
    {
      Normal();
      if (distance <= 400)
        Lcd1();
      else
        Lcd2();
    }
  }
}
