#include <Settings.h>
#include <devices/RFWCAirSwitch.h>

RFWCAirSwitch::RFWCAirSwitch() : mySwitch() {
  mySwitch.enableTransmit(RF_TRANSMITTER_PIN);
  mySwitch.setPulseLength(284);
  mySwitch.setProtocol(1);
}

void RFWCAirSwitch::on() {
  PRINTLN("Power ON the WC Switch");
  mySwitch.send(SESOO__CODE_WC_ON, 24);
}

void RFWCAirSwitch::off() {
  PRINTLN("Power OFF the WC Switch");
  mySwitch.send(SESOO__CODE_WC_OFF, 24);
}
