// C++ code
//
const int pir = 7;
const int red = 9;
const int green = 10;
const int blue = 11;
const int buzzer = 3;

int motion;

void RGB_color(int red_value, int green_value, int blue_value);

void setup()
{
  pinMode(pir, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);
}

void loop()
{
 motion = digitalRead(pir);
  if (motion == HIGH)
  {
    RGB_color(0, 0, 255);
    digitalWrite(buzzer, HIGH);
    Serial.println("Motion detected!!");
  }
  else {
    RGB_color(255, 0, 255);
    digitalWrite(buzzer, LOW);
    Serial.println("Motion not detected!!");
  }
  
  delay(100);
}
void RGB_color(int red_value, int green_value, int blue_value) {
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}