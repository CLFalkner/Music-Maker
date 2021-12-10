/*
   Name: Chloe Falkner
   Class: NMD 211 Lab 1001
   Assignment: Lab Final Project
   Date: 3 December 2021

   Goal: Play music notes through a speaker.
         Use remote to chose notes to play.
         Display the note on an LCD.

   Steps:
   1. Set up speaker using buzzer tutorial
   1.a. Tutorial: https://www.instructables.com/ACTIVE-speaker-WITH-ARDUINO-UNO-R3/
   2. Control frequency using a potentiometer (not working yet
   3. Changed goals. Program speaker to play musical notes.
   3.a. Reference tutorial: https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
   4. Set up remote. Identify codes for each button and sort notes into octaves
   4.a. Tutorial: https://create.arduino.cc/projecthub/electropeak/use-an-ir-remote-transmitter-and-receiver-with-arduino-1e6bc8

*/

#include <IRremote.h>
#include "pitches.h"

// create global variables
int speaker = 12;                                    // pin to control active speaker
int RECV_PIN = 10;

// button codes
#define power       0xFFA25D
#define volumeUp    0xFF629D
#define funcStop    0xFFE21D
#define backRewind  0xFF22DD
#define playPause   0xFF02FD
#define fastForward 0xFFC23D
#define downArrow   0xFFE01F
#define volumeDown  0xFFA857
#define upArrow     0xFF906F
#define zero        0xFF6897
#define eq          0xFF9867
#define stRept      0xFFB04F
#define one         0xFF30CF
#define two         0xFF18E7
#define three       0xFF7A85
#define four        0xFF10EF
#define five        0xFF38C7
#define six         0xFF5AA5
#define seven       0xFF42BD
#define eight       0xFF4AB5
#define nine        0xFF52AD

// array to hold octaves
int octaves[7][8] = {{NOTE_B0, NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_A1, NOTE_B1},
                     {NOTE_B1, NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_B2},
                     {NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3}, 
                     {NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4},
                     {NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5},
                     {NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6},
                     {NOTE_B6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7}};

IRrecv irrecv(RECV_PIN);
decode_results results;

//// notes in whatever song this is
//int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
//// how long each note lasts
//int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);                          // set speaker pin as an output
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
  if (irrecv.decode(&results))                       // return 0 if no data ready, 1 if data ready
  {
    Serial.print("Code: ");
    Serial.println(results.value, HEX);                   // print button value
    irrecv.resume();                                 // restart sensor and receive next value
  }

  //tone(speaker, NOTE_C4);
  //delay(500);
  //noTone(speaker);
  //tone(speaker, NOTE_G3);
  //delay(500);
  //noTone(speaker);

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
