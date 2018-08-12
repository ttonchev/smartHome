#include <Settings.h>
#include <devices/Chuwi.h>


Chuwi::Chuwi() : irSender(CHUWI_IR_PIN_SENDER) {
  irSender.begin();
}

void Chuwi::on() {
  PRINTLN("Power ON the Chuwi");
  sendSignal(CHUWI__CODE_POWER_ON);
}

void Chuwi::off() {
  PRINTLN("Power OFF the Chuwi");
  sendSignal(CHUWI__CODE_POWER_OFF);
}
void Chuwi::sendSignal(unsigned long signal_code) {
  irSender.sendNEC(signal_code, 32);
}
