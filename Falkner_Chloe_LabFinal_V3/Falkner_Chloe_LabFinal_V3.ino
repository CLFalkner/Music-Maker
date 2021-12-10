/*
   Name: Chloe Falkner
   Class: NMD 211 Lab 1001
   Assignment: Lab Final Project
   Date: 3 December 2021

   Goal: Play music notes through a speaker.
         Use membrane switch module to chose notes to play.
         Display the note on an LCD.

   Steps:
   1. Set up speaker using buzzer tutorial
   1.a. Tutorial: https://www.instructables.com/ACTIVE-speaker-WITH-ARDUINO-UNO-R3/
   2. Control frequency using a potentiometer (not working yet
   3. Changed goals. Program speaker to play musical notes.
   3.a. Reference tutorial: https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

// create global variables
int speaker = 12;                                    // pin to control active speaker

// notes in whatever song this is
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
// how long each note lasts
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);                          // set speaker pin as an output
}

void loop() {

tone(speaker, NOTE_C4);
delay(500);
noTone(speaker);
tone(speaker, NOTE_G3);
delay(500);
noTone(speaker);
  
  // cycle through the notes
//  for (int thisNote = 0; thisNote < sizeof(melody); thisNote++) {
//    // for note duration, divide 1 second by note type
//    // ex. quarter note = 1000/4, eighth note = 1000/8, etc.
//    int noteDuration = 1000 / noteDurations[thisNote];
//    tone(speaker, melody[thisNote], noteDuration);
//    
//    // put a little pause between each note
//    int pauseBetweenNotes = noteDuration * 1.3;
//    delay(pauseBetweenNotes);
//
//    // stop playing the note
//    noTone(speaker);
//  }

}
