//www.diyusthad.com
#include <LiquidCrystal.h>

// declare the pins for the LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    // initialize the LCD with the declared pins

void setup() {
  lcd.begin(16, 2);                     // tell the LCD the dimensions of the display (count the white boxes)
  lcd.print("hello, world");            // display "Hello World" on the screen
  
}

void loop() {
  // run timer
  lcd.setCursor(0,1);                   // choose the line and slot to display the timer in
  lcd.print(millis() / 1000);           // display the timer
}
