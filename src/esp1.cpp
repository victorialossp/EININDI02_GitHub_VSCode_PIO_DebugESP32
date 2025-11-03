#include "iikit.h"
#include "util/asyncDelay.h"

void blinkLEDFunc(uint8_t pin) {
  digitalWrite(pin, !digitalRead(pin));
}

void managerInputFunc(void) {
  IIKit.disp.setText(2, "P1:");
  IIKit.disp.setText(3, "T1:");
}

void setup()
{
  IIKit.setup();
  pinMode(def_pin_D1, OUTPUT);
}

AsyncDelay_c blinkLED(500); // time mili second
AsyncDelay_c delayPOT(50); // time mili second
void loop()
{
  IIKit.loop();
  if (blinkLED.isExpired()) blinkLEDFunc(def_pin_D1);
  if (delayPOT.isExpired()) managerInputFunc();
}