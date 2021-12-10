# Music-Maker
Using Arduino hardware to make music.

This project attempts to program a remote to play musical notes through a speaker when the appropriate buttons are pressed. 
A separate LCD display tells users the corresponding octave and letter for the playing note.

Please note that this project does NOT work properly.

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

To set up the IrReceiver:
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

This is how my setup looks:
![PXL_20211210_213545296](https://user-images.githubusercontent.com/47128769/145646316-bb03a7a0-7719-4a37-a8e4-f88894c86b58.jpg)


