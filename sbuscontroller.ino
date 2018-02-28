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

const unsigned long gcAnalogDelta = 20;
unsigned long gNextTime = 0;

uint16_t t;
uint16_t a;
uint16_t e;
uint16_t r;

void setup() {
  // Set Range Values
  Joystick.setXAxisRange(172, 1811);
  Joystick.setYAxisRange(172, 1811);
  Joystick.setRxAxisRange(172, 1811);
  Joystick.setRyAxisRange(172, 1811);

  sBus.begin();

  Joystick.begin(true);
}

void loop() {
  // Read SBUS channels
  sBus.FeedLine();
  if (sBus.toChannels == 1){
    sBus.UpdateServos();
    sBus.UpdateChannels();
    sBus.toChannels = 0;

    t = sBus.channels[0];
    a = sBus.channels[1];
    e = sBus.channels[2];
    r = sBus.channels[3];
  }

  // Write SBUS channels to controller
  if (millis() >= gNextTime) {
    gNextTime = millis() + gcAnalogDelta;
    
    Joystick.setXAxis(t);
    Joystick.setYAxis(a);
    Joystick.setRxAxis(e);
    Joystick.setRyAxis(r);
  }
}
