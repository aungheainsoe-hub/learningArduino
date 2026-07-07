int Led_r = 5;
int Led_y = 4;
int Led_g = 3;

void setup()
{
  pinMode(Led_r, OUTPUT);
  pinMode(Led_y, OUTPUT);
  pinMode(Led_g, OUTPUT);
}

void redLight()
{
  digitalWrite(Led_r, HIGH);
  digitalWrite(Led_y, LOW);
  digitalWrite(Led_g, LOW);
}

void redYellowLight()
{
  digitalWrite(Led_r, HIGH);
  digitalWrite(Led_y, HIGH);
  digitalWrite(Led_g, LOW);
}

void greenLight()
{
  digitalWrite(Led_r, LOW);
  digitalWrite(Led_y, LOW);
  digitalWrite(Led_g, HIGH);
}

void yellowLight()
{
  digitalWrite(Led_r, LOW);
  digitalWrite(Led_y, HIGH);
  digitalWrite(Led_g, LOW);
}

void loop()
{
  redLight();
  delay(10000);

  redYellowLight();
  delay(2000);

  greenLight();
  delay(10000);

  yellowLight();
  delay(2000);
}