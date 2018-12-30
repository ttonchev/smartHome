#include <Settings.h>
#include <devices/RFBathAirSwitch.h>

RFBathAirSwitch::RFBathAirSwitch() : mySwitch() {
  mySwitch.enableTransmit(RF_TRANSMITTER_PIN);
  mySwitch.setPulseLength(284);
  mySwitch.setProtocol(1);
}

void RFBathAirSwitch::on() {
  PRINTLN("Power ON the Bath Switch");
  mySwitch.send(SESOO__CODE_BATH_ON, 24);
}

void RFBathAirSwitch::off() {
  PRINTLN("Power OFF the Bath Switch");
  mySwitch.send(SESOO__CODE_BATH_OFF, 24);
}
