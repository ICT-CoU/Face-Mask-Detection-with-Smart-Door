#include<Servo.h>
#include<SoftwareSerial.h>

Servo s;

void setup()
{
  Serial.begin(9600);
  s.attach(9);
  s.write(0);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);
}

void loop()
{
  delay(10);
  if (Serial.available() > 0)
  {
     String msg = Serial.readStringUntil('\n');
     Serial.println(msg);

    if (msg == "openDoor")
    {
       digitalWrite(A0,HIGH);
       digitalWrite(13,LOW);
       doorOn();
       delay(3000);
       doorOff();
    }
    if (msg == "closeDoor")
    {
       digitalWrite(13,HIGH);
       digitalWrite(A0,LOW);
    }
  }

}


void doorOff()
{
  for (int i = 100; i > 0; i--)
  {
    s.write(i);
    delay(20);
  }
}

void doorOn()
{
  for (int i = 1; i <= 100; i++)
  {
    s.write(i);
    delay(20);
  }
}
