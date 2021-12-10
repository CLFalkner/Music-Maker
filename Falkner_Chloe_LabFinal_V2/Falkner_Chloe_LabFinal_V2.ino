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
   2. Control frequency using a potentiometer (not working yet
*/

// create global variables
int speaker = 12;                                    // pin to control active speaker
int potentiometer = 1;
int adc = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);                          // set speaker pin as an output
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;

  while (1) {
    // output a frequency
    adc = analogRead(potentiometer);
  //  Serial.println(adc);
    for (i = 0; i < 100; i++) {
      digitalWrite(speaker, HIGH);
      delay(1);
      digitalWrite(speaker, LOW);
      delay(1);
    }
  }

}
