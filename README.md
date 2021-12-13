# Music-Maker
Using Arduino hardware to make music.

This project attempts to program a remote to play musical notes through a speaker when the appropriate buttons are pressed. 
A separate LCD display tells users the corresponding octave and letter for the playing note.

Please note that this project does NOT work properly.

MOTIVATION:
Who doesn't like music?

WIRING AND HARDWARE:

Starter Arduino kit: https://smile.amazon.com/gp/product/B01EWNUUUA/ref=ppx_yo_dt_b_search_asin_image?ie=UTF8&th=1

-Elegoo Mega2560 R3
-Basic speaker with separate power and ground wires
-LCD1602 Module
-IR Receiver Module

To set up the speaker:
1. Connect the power (red wire) to digital pin 8.
2. Connect the ground (black wire) to the GND.
3. If the speaker is to loud, use a resistor to reduce the signal power to the speaker.

To set up the IR Receiver:
1. Connect the Y pin to digital pin 10.
2. Connect the R pin to power (5V).
3. Connect the G pin to GND.

To set up the LCD:
1. Connect the VSS pin to GND.
2. Connect VDD to 5V.
3. Connect V0 to GND.
4. Connect RS to digital pin 12.
5. Connect RW to GND.
6. Connect E to digital pin 11.
7. Connect D4 to digital pin 5.
8. Connect D5 to digital pin 4.
9. Connect D6 to digital pin 3.
10. Connect D7 to digital pin 2.
11. Connect A to 5V using a 220 ohm resistor.
12. Connect K to GND.

Wiring Schematics:
![MusicMaker_Schematics](https://user-images.githubusercontent.com/47128769/145889778-24cbebcd-3444-4975-9348-0806b915cb0e.png)

You can also download the schematics file (MusicMaker_Schematics.ckt) from this repository and open it in Cirkit Designer.

This is how my setup looks:
![PXL_20211210_213545296](https://user-images.githubusercontent.com/47128769/145646316-bb03a7a0-7719-4a37-a8e4-f88894c86b58.jpg)


SOFTWARE:

To set up the LCD:
1. Run the LCDTestCode to make sure everything works: https://github.com/CLFalkner/Music-Maker/tree/main/LCDTestCode

To set up the IR Receiver:
1. Do the same with the IR Receiver: https://github.com/CLFalkner/Music-Maker/tree/main/RemoteTestCode_2
2. Please note that the RemoteTestCode file does not work, you must use RemoteTestCode_2
3. Use RemoteTestCode_2 to record the individual codes for each button.
4. You will need to replace my button codes with yours in order for the program to know what to do when a button is pressed.

To set up the speaker:
1. The speaker needs no special setup.

Bringing everything together:
1. Follow the code of versions 7 or 8, but be mindful that neither version works correctly.
2. If you choose version 7, the LCD and speaker will work properly, but communication with the IR Receiver will be nonexistent,
    meaning that the program will not respond to button pushes.
3. If you choose version 8, the LCD and IR Receiver will work properly, but the speaker will only emit static.
4. For now, until I figure out the problem, you will have figure out how to make these three function properly together.

VIDEO DEMONSTRATIONS:

Version 7: https://photos.app.goo.gl/avaCfWhVJYGwQ4167
Version 8: https://photos.app.goo.gl/rCHJ8WERUf3sUtJn7

THE ORDER IN WHICH I BUILT THE MUSIC-MAKER:

3. Changed goals. Program speaker to play musical notes.
3.a. Reference tutorial: https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
4. Set up remote. Identify codes for each button and sort notes into octaves
4.a. Tutorial: https://create.arduino.cc/projecthub/electropeak/use-an-ir-remote-transmitter-and-receiver-with-arduino-1e6bc8
5. Program buttons to play notes of an octave and cycle through octaves on command
6. Display octave and note information on LCD (not working)
6.a. Tutorial: https://create.arduino.cc/projecthub/najad/interfacing-lcd1602-with-arduino-764ec4
7. Troubleshoot
7.a. The LCD and speaker are working properly, but not the IR Receiver.
8. The LCD and IrReceiver are working properly, but not the speaker.

You will notice how steps 1 and 2 are missing in these steps. This is because I started this project working
towards another goal, but early on missed my chance to obtain the materials I needed for it and chose to change gears.
The corresponding project versions for 1 and 2, however, are still included in this repository.
