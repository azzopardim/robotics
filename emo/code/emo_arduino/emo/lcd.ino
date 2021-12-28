// EMO LCD
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * 
 *
 **/

// Declare Liquid Crystal Display module
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initializing LCD
void lcdInit() {
  lcd.clear();
  lcd.begin(16, 2);
}


