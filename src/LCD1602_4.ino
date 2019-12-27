// Four-bit connection code:
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(2,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Hello, 1602!");
}

void loop() {

}
