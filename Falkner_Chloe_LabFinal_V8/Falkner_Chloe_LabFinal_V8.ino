/*
   Name: Chloe Falkner
   Class: NMD 211 Lab 1001
   Assignment: Lab Final Project
   Date: 10 December 2021

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
   5. Program buttons to play notes of an octave and cycle through octaves on command
   6. Display octave and note information on LCD (not working)
   6.a. Tutorial: https://create.arduino.cc/projecthub/najad/interfacing-lcd1602-with-arduino-764ec4
   7. Troubleshoot
   7.a. The LCD and speaker are working properly, but not the Ir Receiver.
   8. The LCD and IrReceiver are working properly, but not the speaker.
*/

// include relevant libraries
#include <IRremote.hpp>                             // for the IR Receiver
#include "pitches.h"                                // contains the note frequencies
#include <LiquidCrystal.h>                          // for the LCD

// create global variables
int speaker = 8;                                    // pin to control active speaker
int RECV_PIN = 10;                                  // IR Receiver pin
int octave = 3;                                     // keep track of the current octave
int note = 0;                                       // keep track of the current note

// set up LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// button codes (you will need to update these)
//#define power       0xFFA25D
#define volumeUp    0xB946FF00
//#define funcStop    0xFFE21D
//#define backRewind  0xFF22DD
//#define playPause   0xFF02FD
//#define fastForward 0xFFC23D
//#define downArrow   0xFFE01F
#define volumeDown  0xEA15FF00
//#define upArrow     0xFF906F
//#define zero        0xFF6897
//#define eq          0xFF9867
//#define stRept      0xFFB04F
#define one         0xF30CFF00
#define two         0xE718FF00
#define three       0xA15EFF00
#define four        0xF708FF00
#define five        0xE31CFF00
#define six         0xA55AFF00
#define seven       0xBD42FF00
#define eight       0xAD52FF00
//#define nine        0xFF52AD

// array to hold octaves
// while the LCD displays the octaves as 1-7, the array stores them as 0-6
int octaves[7][8] = {{NOTE_B0, NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_A1, NOTE_B1},  // octave 0
  {NOTE_B1, NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_B2},                     // octave 1
  {NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3},                     // octave 2
  {NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4},                     // octave 3
  {NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5},                     // octave 4
  {NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6},                     // octave 5
  {NOTE_B6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7}                      // octave 6
};

void setup() {
  Serial.begin(9600);

  //start the lcd screen
  lcd.begin(16, 2);
  displayText();                                     // print inital text
  displayOctave();                                   // display the current octave number

  pinMode(speaker, OUTPUT);                          // set speaker pin as an output

  // start the remote receiver
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {

  if (IrReceiver.decode())                       // return 0 if no data ready, 1 if data ready
  {
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    //IrReceiver.printIRResultShort(&Serial);
    switch (IrReceiver.decodedIRData.decodedRawData) {  // which button is pressed
      case one:
        noTone(speaker);
        note = 0;                                      // low B
        Serial.println("B");                           // print B to Serial Monitor
        displayNote("B");                              // print B to LCD
        delay(10);                                     // delay implemented during troubleshooting. Not sure if it helped
        break;
      case two:
        noTone(speaker);
        note = 1;                                      // C
        displayNote("C");                              // print C to Serial Monitior
        Serial.println("C");                           // print C to LCD
        delay(10);                                     // delay implemented during troubleshooting. Not sure if it helped
        break;
      case three:
        note = 2;                                      // D
        displayNote("D");                              // print D to Serial Monitior
        Serial.println("D");                           // print D to LCD
        delay(10);                                     // delay implemented during troubleshooting. Not sure if it helped
        break;
      case four:
        note = 3;                                      // E
        displayNote("E");                              // print E to Serial Monitior
        Serial.println("E");                           // print E to LCD
        delay(10);                                     // delay implemented during troubleshooting. Not sure if it helped
        break;
      case five:
        note = 4;                                      // F
        displayNote("F");                              // print F to Serial Monitior
        Serial.println("F");                           // print F to LCD
        break;
      case six:
        note = 5;                                      // G
        displayNote("G");                              // print G to Serial Monitior
        Serial.println("G");                           // print G to LCD
        break;
      case seven:
        note = 6;                                      // A
        displayNote("A");                              // print A to Serial Monitior
        Serial.println("A");                           // print A to LCD
        break;
      case eight:
        note = 7;                                      // high B
        displayNote("B");                              // print B to LCD
        Serial.println("B");                           // print B to Serial Monitor
        break;
      case volumeUp:
        octave++;                                      // increase octave
        if (octave > 6) {                              // loop octaves from high to low
          octave = 0;
        }
        displayOctave();                               // print octave number to LCD
        break;
      case volumeDown: 
        octave--;                                      // decrease octave
        if (octave < 0) {                              // loop octaves from low to high
          octave = 6;
        }
        displayOctave();                               // print octave number to LCD
        break;
      default:
        //noTone(speaker);                              // program doesn't like this line
        break;
    }

    // play note
    tone(speaker, octaves[octave, note]);

    // restart sensor
    IrReceiver.stop();
    IrReceiver.start();

  }

  //tone(speaker, octaves[octave, note]);

}

// display basic text
void displayText() {
  lcd.print("Octave: ");
  lcd.setCursor(0, 1);
  lcd.print("Note: ");
}

// update the octave displayed
void displayOctave() {
  lcd.setCursor(8, 0);
  lcd.print(octave + 1);
}

// update the note displayed
void displayNote(String note_) {
  lcd.setCursor(8, 1);
  lcd.print(note_);
}
