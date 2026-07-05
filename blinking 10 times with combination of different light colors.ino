int Led_y = 6;
int Led_g = 7;
int Led_r = 5;

void setup()
{
  pinMode(Led_y, OUTPUT);
  pinMode(Led_g, OUTPUT);
  pinMode(Led_r, OUTPUT);
}

void loop()
{
  for (int x = 0; x < 30; x++)
  {
    if (x < 10)
    {
      // Green + Yellow
      digitalWrite(Led_g, HIGH);
      digitalWrite(Led_y, HIGH);

      delay(100);

      digitalWrite(Led_g, LOW);
      digitalWrite(Led_y, LOW);
    }
    else if (x < 20)
    {
      // Green + Red
      digitalWrite(Led_g, HIGH);
      digitalWrite(Led_r, HIGH);

      delay(100);

      digitalWrite(Led_g, LOW);
      digitalWrite(Led_r, LOW);
    }
    else
    {
      // Green + Yellow + Red
      digitalWrite(Led_g, HIGH);
      digitalWrite(Led_y, HIGH);
      digitalWrite(Led_r, HIGH);

      delay(100);

      digitalWrite(Led_g, LOW);
      digitalWrite(Led_y, LOW);
      digitalWrite(Led_r, LOW);
    }

    delay(100);
  }
}