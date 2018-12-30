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

void LGTV::channelUp() {
  PRINTLN("Channel up");
  sendSignal(MTEL_TV__CODE_CHANNEL_UP);
}

void LGTV::channelDown() {
  PRINTLN("Channel down");
  sendSignal(MTEL_TV__CODE_CHANNEL_DOWN);
}

void LGTV::up() {
  PRINTLN("up");
  sendSignal(LG_TV__CODE_UP);
}

void LGTV::down() {
  PRINTLN("down");
  sendSignal(LG_TV__CODE_DOWN);
}

void LGTV::left() {
  PRINTLN("left");
  sendSignal(LG_TV__CODE_LEFT);
}

void LGTV::right() {
  PRINTLN("right");
  sendSignal(LG_TV__CODE_RIGHT);
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
  sendSignal(LG_TV__CODE_OUTPUT_SELECT);
  delay(TIMEOUT*3);
  sendSignal(LG_TV__CODE_DOWN);
  delay(TIMEOUT);
  sendSignal(LG_TV__CODE_DOWN);
  delay(TIMEOUT);
  sendSignal(LG_TV__CODE_OK);
}
void LGTV::netflix(char *command) {
  if (strcasecmp(command, "1") == 0) {
    sendSignal(LG_TV__CODE_HOME);
    delay(TIMEOUT*3);
    sendSignal(LG_TV__CODE_RIGHT);
    delay(TIMEOUT);
    sendSignal(LG_TV__CODE_OK);
    delay(TIMEOUT*2);
    sendSignal(LG_TV__CODE_OK);
} else if(strcasecmp(command, "0") == 0) {
    sendSignal(LG_TV__CODE_EXIT);
  }
}
