#include <Settings.h>
#include <devices/RFLightSwitch.h>

RFLightSwitch::RFLightSwitch() : mySwitch() {
  mySwitch.enableTransmit(RF_TRANSMITTER_PIN);
  mySwitch.setPulseLength(284);
  mySwitch.setProtocol(1);
}

void RFLightSwitch::on() {
  PRINTLN("Power ON the Light Switch");
  mySwitch.send(SESOO__CODE_A, 24);
}

void RFLightSwitch::off() {
  PRINTLN("Power OFF the Light Switch");
  mySwitch.send(SESOO__CODE_B, 24);
}
