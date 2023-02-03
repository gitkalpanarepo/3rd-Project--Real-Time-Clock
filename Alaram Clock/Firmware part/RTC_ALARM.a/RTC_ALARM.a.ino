#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
int buzzer=13;

// LCD D4 to Arduino 5
// LCD D5 to Arduino 4
// LCD D6 to Arduino 3
// LCD D7 to Arduino 2
// RS 4 to Arduino 7
// EN 6 to Arduino 6
LiquidCrystal lcd(7,6,5,4,3,2);

// SDA pin to Arduino A4
// SCL pin to Arduino A5
DS1307 RTC;

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(57600);
  Wire.begin();
  RTC.begin();

  lcd.begin(16,2); // 16x2 LCD
  if (! RTC.isrunning()) {
Serial.println("RTC is NOT running!");
// following line sets the RTC to the date & time this sketch was compiled
RTC.adjust(DateTime(__DATE__, __TIME__));  
}
}

void loop() {
  DateTime now = RTC.now();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DATE:");
  lcd.setCursor(6,0);

  lcd.print(now.day());
  lcd.print('/');
    if (now.month() < 10) {
    lcd.print("0");
  }
   lcd.print(now.month());
  lcd.print("/");

  lcd.print(now.year());
   lcd.setCursor(0,1);
  lcd.print("TIME:");
  lcd.setCursor(7,1);
  if (now.hour() < 10) {
    lcd.print("0");
  }
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) {
    lcd.print("0");
  }

  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) {
    lcd.print("0");
  }

  lcd.print(now.second());
  delay(1000);
  //Morning alaram at 8:15am
   if (now.hour()==8 && now.minute()==14&& now.second()<=34 )
    {
      digitalWrite(buzzer,HIGH);
    }
    //Afternoon Break at 1:00pm
    else if (now.hour()==12 && now.minute()==11 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }
    //Afternoon Break reminder at 1:55pm 
    else if (now.hour()==13 && now.minute()==54 && now.second()<=59 )
    {
      digitalWrite(buzzer,HIGH);
    }    
    //Afternoon Break over at 2:00pm 
    else if (now.hour()==14 && now.minute()==00 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }    
    //Evening off and over time on at 5:00pm 
    else if (now.hour()==18 && now.minute()==57 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }
    //Overtime off time at 8:00pm 
    else if (now.hour()==00 && now.minute()==53 && now.second()<=19 )
    {
      digitalWrite(buzzer,HIGH);
    }
    
    
      else 
   {
     digitalWrite(buzzer,LOW);
   }   
    }
    
