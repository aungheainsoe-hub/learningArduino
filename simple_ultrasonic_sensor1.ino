// C++ code
//

int trig = 9;
int echo = 10;
long duration;
float distance;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //prepare the sensor , turn the trigger off, wait 2 msec
  digitalWrite(trig,LOW);
  delayMicroseconds(20);
  
  //send the ultrasonic pulse
  //turn the trigger on
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  //Listen for the echo
  //Measure how long echo stays HIGH
  duration = pulseIn(echo, HIGH);
  //save the time
  Serial.println(duration);
  
  
  //Convert time into distance
  //Multiply time by speed of sound
  //Divide by 2 because sound travels to the object and back
  distance = (duration * 0.0343) / 2;

  //Display result
  //Print "Distance:"
  Serial.print("Distance: ");
  //Print distance
  Serial.println(distance);
  //Print "cm"
  Serial.print("cm");

  //Wait a short time
  delay(1000);

   //REPEAT
}