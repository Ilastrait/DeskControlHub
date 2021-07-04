// DeskControlHub
// Code By Ilastrait
// Feel Free To Edit According To Usecase

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// Change according to the ld you are using

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensor pin info, chasnge according to the pins you have connected your equipment to 
/*   
 *    ts1 - Touch Switch 1
 *    ts2 - Touch Switch 2
 *    relay1 - Relay 1 signal pin
 *    relay2 - Relayu 2 signal pin
 *    switch1 - Arbitary variable to store switch 1 pin value
 *    switch2 - Arbitary variable to store switch 2 pin value
 */
 
int ts1 = 11;
int ts2 = 9;

int relay1 = 2;
int relay2 = 4;

int switch1=0;
int switch2=0;

void setup()
{
  Serial.begin(9600);
	lcd.begin();
  lcd.backlight();
	  pinMode(ts1, INPUT);
    pinMode(ts2, INPUT);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    lcd.setCursor(0,0);
    lcd.print("HEAD Light : ");
    lcd.setCursor(0,1);
    lcd.print("FOOT Light : ");
    
}

void loop()
{
  
  switch1 = digitalRead(ts1);
  switch2 = digitalRead(ts2);
	if(switch1==1)
  {
    if(switch2==1)
    {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      lcd.setCursor(13,0);
      lcd.print("LIT");
      lcd.setCursor(13,1);
      lcd.print("LIT");
      }
    else
     {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH); 
      lcd.setCursor(13,0);
      lcd.print("LIT");
      lcd.setCursor(13,1);
      lcd.print("OFF"); 
    }
      }
   else
    {
      if(switch2==1)
      {
        digitalWrite(relay1, HIGH);
        digitalWrite(relay2, LOW);
        lcd.setCursor(13,0);
      lcd.print("OFF");
      lcd.setCursor(13,1);
      lcd.print("LIT");
        }
        else 
        {
          digitalWrite(relay1, HIGH);
          digitalWrite(relay2, HIGH);
          lcd.setCursor(13,0);
      lcd.print("OFF");
      lcd.setCursor(13,1);
      lcd.print("OFF");
          }
      }
  }

  // Code By Ilastrait
