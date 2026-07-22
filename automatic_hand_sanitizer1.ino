// C++ code
//

#include <Servo.h>

Servo myServo;

const int trig = 3;
const int echo = 4;
const int servo = 6;

float distance;
long duration;
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myServo.attach(servo);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(50);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(50);
  
  digitalWrite(trig,LOW);
  duration = pulseIn(echo, HIGH);
  
  distance = (duration * 0.0343) / 2;
  
  if (distance >= 10)
  {
    myServo.write(0);

  }
  else {
    myServo.write(90);
    delay(500);
    
       while (distance < 10)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);

    distance = (duration * 0.0343) / 2;
    myServo.write(0);
    
}
     
  }
}