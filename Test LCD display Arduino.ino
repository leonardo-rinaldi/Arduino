//Test you LCD display 

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);


void setup()
{

  lcd.init();
  lcd.backlight();
  lcd.print("Test Display I2C");
  lcd.setCursor(0,1);
  lcd.print("versione 1.0");

}

void loop() {
  
}
