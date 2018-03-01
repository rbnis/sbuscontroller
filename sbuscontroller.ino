// Program used to map an SBUS transmitter as
// wireless controller
//
// Robin Tripp
// 2018-02-27 - Original Version
//------------------------------------------------------------

#include "Joystick.h"
#include <FUTABA_SBUS.h>

Joystick_ Joystick;
FUTABA_SBUS sBus;

const unsigned long gcAnalogDelta = 25;
unsigned long gNextTime = 0;

uint16_t t;
uint16_t a;
uint16_t e;
uint16_t r;
uint16_t c5;
uint16_t c6;
uint16_t c7;

void setup() {
  // Set Range Values
  Joystick.setXAxisRange(172, 1811);
  Joystick.setYAxisRange(172, 1811);
  Joystick.setRxAxisRange(172, 1811);
  Joystick.setRyAxisRange(172, 1811);
  Joystick.setZAxisRange(172, 1811);
  Joystick.setRzAxisRange(172, 1811);

  sBus.begin();

  Joystick.begin(true);
}

void loop() {
  // Read SBUS channels
  sBus.FeedLine();
  if (sBus.toChannels == 1) {
    sBus.UpdateServos();
    sBus.UpdateChannels();
    sBus.toChannels = 0;

    t = sBus.channels[0];
    a = sBus.channels[1];
    e = sBus.channels[2];
    r = sBus.channels[3];
    c5 = sBus.channels[4];
    c6 = sBus.channels[5];
    c7 = sBus.channels[6];
  }

  // Write priority SBUS channels (TAER) to controller
  Joystick.setXAxis(t);
  Joystick.setYAxis(a);
  Joystick.setRxAxis(e);
  Joystick.setRyAxis(r);

  // Write remaining SBUS channels to controller
  if (millis() >= gNextTime) {
    gNextTime = millis() + gcAnalogDelta;

    Joystick.setZAxis(c5);
    Joystick.setRzAxis(c6);
    Joystick.setButton(0, map(c7, 172, 1811, 0, 1));
  }
}
