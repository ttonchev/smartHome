#include <Settings.h>
#include <devices/LGTV.h>

//IRrecv irrecv(TV_IR_PIN_SENDER, CAPTURE_BUFFER_SIZE, TIMEOUT, true);
//decode_results results; // Somewhere to store the results

LGTV::LGTV() : irSender(TV_IR_PIN_SENDER) {
  irSender.begin();
  //irrecv.enableIRIn();  // Start the receiver
}

void LGTV::on() {
 PRINTLN("Power ON the LG TV");
 sendSignal(LG_TV__CODE_MTEL_POWER_ON_OFF);
 delay(TIMEOUT);
 sendSignal(LG_TV__CODE_POWER_ON_OFF);
 //sendSignal(LG_TV__CODE_POWER_ON_OFF);
}

void LGTV::off() {
  PRINTLN("Power Off the LG TV");
  sendSignal(LG_TV__CODE_MTEL_POWER_ON_OFF);
  delay(TIMEOUT);
  sendSignal(LG_TV__CODE_POWER_ON_OFF);
//  sendSignal(LG_TV__CODE_POWER_ON_OFF);
}

void LGTV::up() {
  PRINTLN("Channel up");
  sendSignal(MTEL_TV__CODE_CHANNEL_UP);
}

void LGTV::down() {
  PRINTLN("Channel down");
  sendSignal(MTEL_TV__CODE_CHANNEL_DOWN);
}

void LGTV::play() {
  PRINTLN("PLAY/PAUSE");
  sendSignal(MTEL_TV__CODE_PAUSE_PLAY);
}

void LGTV::rewind() {
  sendSignal(MTEL_TV__CODE_REWIND);
}

void LGTV::forward() {
  sendSignal(MTEL_TV__CODE_FORWARD);
}

void LGTV::begining() {
  sendSignal(MTEL_TV__CODE_BEGINING);
}

void LGTV::channel(std::string ch) {
  PRINTLN("Switch to channel " + String(ch.c_str()) + " on the LG TV");

  for (int i = 0; i < ch.length(); i++) {
    switch (ch[i]) {
      case '1': sendSignal(MTEL_TV__CODE_1); delay(TIMEOUT); break;
      case '2': sendSignal(MTEL_TV__CODE_2); delay(TIMEOUT); break;
      case '3': sendSignal(MTEL_TV__CODE_3); delay(TIMEOUT); break;
      case '4': sendSignal(MTEL_TV__CODE_4); delay(TIMEOUT); break;
      case '5': sendSignal(MTEL_TV__CODE_5); delay(TIMEOUT); break;
      case '6': sendSignal(MTEL_TV__CODE_6); delay(TIMEOUT); break;
      case '7': sendSignal(MTEL_TV__CODE_7); delay(TIMEOUT); break;
      case '8': sendSignal(MTEL_TV__CODE_8); delay(TIMEOUT); break;
      case '9': sendSignal(MTEL_TV__CODE_9); delay(TIMEOUT); break;
      case '0': sendSignal(MTEL_TV__CODE_0); delay(TIMEOUT); break;
    }
  }
}

void LGTV::sendSignal(unsigned long signal_code) {
  irSender.sendNEC(signal_code, 32);
}

void LGTV::hdmi1() {
  /*uint16_t rawbuf[36] = {
     0x0000, 0x0067, 0x0000, 0x0010, 0x0060, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018,
     0x0030, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018,
     0x0030, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0338
     };*/

  uint16_t rawbuf[30] =
  { 0x0000, 0x0067, 0x0000, 0x000d, 0x0060, 0x0019, 0x0030, 0x0018, 0x0030, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018,
    0x0018, 0x0019, 0x0018, 0x0018, 0x0030, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0018, 0x0019, 0x0018, 0x0018,
    0x0018, 0x03f4 };

  irSender.sendRaw(rawbuf, 30, 38 /* kHz */);
}
