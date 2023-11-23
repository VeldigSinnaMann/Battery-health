#include <Arduino.h>
#include <EEPROM.h>
#include <Zumo32U4.h>

Zumo32U4OLED display;


void setup()
{
  EEPROM.write(0, 100);
  EEPROM.write(1,100);
  display.clear();
}

void levels()
{
  display.print(F("Lev"));
  display.println(EEPROM.read(0));
  delay(1000);
  display.clear();
  display.print(F("Hels"));
  display.println(EEPROM.read(1));
  delay(1000);
  display.clear();
}

void loop()
{
  levels();
}
