#include <Settings.h>
#include <devices/MitsubishiAC.h>

MitsubishiAC::MitsubishiAC() : mitsubir(AC_IR_PIN_SENDER) {
  mitsubir.begin();
}
void MitsubishiAC::on() {
  PRINTLN("Power ON the AC");
  mitsubir.on();
  mitsubir.setFan(3);
  mitsubir.setMode(MITSUBISHI_AC_VANE_AUTO);
  mitsubir.setTemp(24);
  mitsubir.setVane(MITSUBISHI_AC_VANE_AUTO);
  mitsubir.send();
}

void MitsubishiAC::off() {
  PRINTLN("Power OFF the AC");
  mitsubir.off();
  mitsubir.send();
}

void MitsubishiAC::mode(String mode) {
  if (mode == "HEAT") {
    mitsubir.setMode(MITSUBISHI_AC_HEAT);
  } else if (mode == "COOL") {
    mitsubir.setMode(MITSUBISHI_AC_COOL);
  } else if (mode == "AUTO") {
    mitsubir.setMode(MITSUBISHI_AC_AUTO);
  } else if (mode == "DRY") {
    mitsubir.setMode(MITSUBISHI_AC_DRY);
  }
  mitsubir.send();
}
/*
void MitsubishiAC::vaneMode(String mode) {
  if (mode == "AUTO") {
    mitsubir.setVane(MITSUBISHI_AC_VANE_AUTO);
  } else if (mode == "AUTO_MOVE") {
    mitsubir.setVane(MITSUBISHI_AC_VANE_AUTO_MOVE);
  } else if (mode == "UP") {
    PRINTLN(mitsubir.getVane());
    mitsubir.setVane(mitsubir.getVane() + 1);
    PRINTLN(mitsubir.getVane());
  } else if (mode == "DOWN") {
    mitsubir.setVane(mitsubir.getVane() - 1);
  }
  mitsubir.send();
}
*/
void MitsubishiAC::setTemp(int temp) {
  mitsubir.setTemp(temp);
  mitsubir.send();
}

void MitsubishiAC::setFan(int power) {
  //0 is auto, 1-5 power, 6 - silent
  mitsubir.setFan(power);
  mitsubir.send();
}
