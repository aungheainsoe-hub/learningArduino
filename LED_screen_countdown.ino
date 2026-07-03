#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(16, 2);
}

void loop()
{
  for (int count = 12; count >= 1; count--)
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Blink Left:");

    lcd.setCursor(0, 1);
    lcd.print(count);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);

    digitalWrite(LED_BUILTIN, LOW);
    delay(300);
  }

  lcd.clear();
  lcd.print("Done!");
  delay(2000);
}