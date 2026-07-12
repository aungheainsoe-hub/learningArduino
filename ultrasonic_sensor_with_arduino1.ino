// C++ code
//

int trigPin = 10;
int echoPin = 9;
long time; 
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{

 // digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);// Wait for 1000 millisecond(s)


  time=pulseIn(echoPin, HIGH);
  distance = time*0.034/2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
}