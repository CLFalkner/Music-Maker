// Code to get individual codes for each button on the remote
// Source: https://github.com/Arduino-IRremote/Arduino-IRremote#sendandreceive--unittest

#include <IRremote.hpp>

const int RECV_PIN = 10;

void setup() {
  //Start the serial Monitor
  Serial.begin(9600);

  // start the remote receiver
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {                      // return 0 if no data ready, 1 if data ready
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    // restart sensor
    IrReceiver.stop();
    IrReceiver.start();
  }
}
