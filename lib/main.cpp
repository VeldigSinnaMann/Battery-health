#include <Arduino.h>
#include <EEPROM.h>
#include <Zumo32U4.h>

Zumo32U4OLED display;
Zumo32U4Buzzer buzzer;
void setup()
{
  Serial.begin(9600);
}

void ProductionFualt()
{
  int BatHelseRand;
  int RandomHealthOne = random(0, 1000);
  int RandomHealthTwo = random (0, 1000);
  int RandomHealthThree = random(0, 1000);
  if (RandomHealthOne == RandomHealthTwo && RandomHealthOne == RandomHealthThree)
  {
    int BatHelseRand = EEPROM.read(1);
    int BatHelseNow = BatHelseRand / 2;
    EEPROM.write(1, BatHelseNow);
    display.clear();
    display.print(BatHelseNow);
  }
}

void batteryCheck()
{
  uint8_t BatteryLevel_1 = 20;
  uint8_t BatteryLevel_0 = 10;
  uint8_t BatteryHealth = EEPROM.read(1);
  if (BatteryHealth <= BatteryLevel_1)
  {
    display.clear();
    display.print(F("Service!"));
  }
  else if (BatteryHealth <= BatteryLevel_0)
  {
    display.clear();
    display.print(F("Bytte!"));
  }
  
}



void levels()
{
  unsigned long TimNow;
  display.print(F("Lev"));
  display.println(EEPROM.read(0));
  TimNow = millis() + 1000;
  while(TimNow < millis())
  {
    ;
  }
  display.clear();
  display.print(F("Hels"));
  display.println(EEPROM.read(1));
  TimNow = millis() + 1000;
  while(TimNow < millis())
  {
    ;
  }
  display.clear();
}

void loop()
{
  ProductionFualt();
  
}