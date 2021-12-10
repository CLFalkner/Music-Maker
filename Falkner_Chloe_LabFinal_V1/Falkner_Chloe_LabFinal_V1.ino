/*
   Name: Chloe Falkner
   Class: NMD 211 Lab 10001
   Assignment: Lab Final Project
   Date: 19 November 2021

   Goal: Vibrate a plate using a speaker with sand on top. 
         Control frequencies with a potentiometer to create different patterns with the sand.
         Display the frequency on an LCD.

   Steps:
   1. Set up speaker using buzzer tutorial
   1.a. Tutorial: https://www.instructables.com/ACTIVE-speaker-WITH-ARDUINO-UNO-R3/
*/

// create global variables
int speaker = 12;                                    // pin to control active speaker

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);                          // set speaker pin as an output
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;
  while (1) {
//    // output a frequency
//    for (i = 0; i < 80; i++) {
//      digitalWrite(speaker, HIGH);
//      delay(1);
//      digitalWrite(speaker, LOW);
//      delay(1);
//    }

    // different frequency
    for (i = 0; i < 100; i++) {
      digitalWrite(speaker, HIGH);
      delay(2);
      digitalWrite(speaker, LOW);
      delay(2);
    }
  }

}
