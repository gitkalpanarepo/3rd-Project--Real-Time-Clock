#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
DS1307 RTC;

void setup () {
Serial.begin(9600);
Wire.begin();
RTC.begin();
lcd.begin(16,2);

//pinMode(8,OUTPUT);

if (! RTC.isrunning()) {
Serial.println("RTC is NOT running!");
// following line sets the RTC to the date & time this sketch was compiled
RTC.adjust(DateTime(__DATE__, __TIME__));
}
}

void loop () {
DateTime now = RTC.now();
lcd.setCursor(0, 0);
lcd.print("DATE:");
lcd.print(now.day());
lcd.print('/');
lcd.print(now.month());
lcd.print('/');
lcd.print(now.year());
lcd.print(' ');
lcd.setCursor(0, 1);
lcd.print("TIME:");
if (now.hour()<10)
lcd.print('0');
lcd.print(now.hour());
lcd.print(':');
if (now.minute()<10)
lcd.print('0');
lcd.print(now.minute());
lcd.print(':');
if (now.second()<10)
lcd.print('0');
lcd.print(now.second());
delay(1000);
}
