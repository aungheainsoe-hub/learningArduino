#include <Keypad.h>

const byte row = 4;
const byte col = 4;

const int redLED = 13;
const int greenLED = 12;
const int piezo = 11;

char numPad[row][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPin[row] = {9,8,7,6};
byte colPin[col] = {5,4,3,2};

String password = "";
String firstPass = "";
String vstup = "";

bool passwordCreated = false;
bool setupMode = false;
bool waitingConfirm = false;
bool firstStar = false;

Keypad cKeypad = Keypad(makeKeymap(numPad), rowPin, colPin, row, col);

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(piezo, OUTPUT);

  digitalWrite(redLED, HIGH);

  Serial.begin(9600);
  Serial.println("Press ** to create password");
  
}

void loop()
{
  char cKey = cKeypad.getKey();

  if (!cKey)
    return;

  //-------------------------------------------------
  // PASSWORD SETUP
  //-------------------------------------------------

  if (!passwordCreated)
  {
    // Wait for **
    if (!setupMode)
    {
      if (cKey == '*')
      {
        if (firstStar)
        {
          setupMode = true;
          firstStar = false;

          Serial.println("\nCreate 4-digit password:");
        }
        else
        {
          firstStar = true;
        }
      }
      else
      {
        firstStar = false;
      }

      return;
    }

    // First password
    if (!waitingConfirm)
    {
      if (cKey >= '0' && cKey <= '9')
      {
        if (vstup.length() < 4)
        {
          vstup += cKey;
          Serial.print("*");
        }

        if (vstup.length() == 4)
        {
          firstPass = vstup;
          vstup = "";

          waitingConfirm = true;

          Serial.println("\nRe-enter password then press #");
        }
      }

      return;
    }

    // Confirmation password
    if (waitingConfirm)
    {
      if (cKey >= '0' && cKey <= '9')
      {
        if (vstup.length() < 4)
        {
          vstup += cKey;
          Serial.print("*");
        }
      }

      if (cKey == '#')
      {
        if (vstup == firstPass)
        {
          password = firstPass;
          passwordCreated = true;

          Serial.println("\nPassword Successful!");

          digitalWrite(redLED, LOW);
          digitalWrite(greenLED, HIGH);

          tone(piezo,500);
          delay(200);
          noTone(piezo);

          delay(1000);

          digitalWrite(redLED,HIGH);
          digitalWrite(greenLED,LOW);

          vstup = "";

          Serial.println("ENTER PASSWORD:");
        }
        else
        {
          Serial.println("\nPasswords do not match.");
          Serial.println("Press ** to create password again.");

          tone(piezo,1000);
          delay(800);
          noTone(piezo);

          firstPass = "";
          vstup = "";
          setupMode = false;
          waitingConfirm = false;
        }
      }

      return;
    }
  }

  //-------------------------------------------------
  // LOGIN (YOUR ORIGINAL CODE)
  //-------------------------------------------------

  if (cKey)
  {
    if (vstup.length() < 4)
    {
      Serial.print("*");
      vstup += cKey;
    }
  }

  if (vstup.length() == 4)
  {
    delay(1500);

    if (password == vstup)
    {
      Serial.println("\nEnter");

      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);

      tone(piezo,500);
      delay(100);
      noTone(piezo);
    }
    else
    {
      Serial.println("\nWrong Passcode");

      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);

      delay(800);

      tone(piezo,1000);
      delay(800);
      noTone(piezo);
    }

    delay(1500);

    vstup = "";

    Serial.println("ENTER PASSWORD:");

    digitalWrite(redLED,HIGH);
    digitalWrite(greenLED,LOW);
  }
}