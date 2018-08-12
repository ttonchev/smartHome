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
//  sendSignal(LG_TV__CODE_MTEL_POWER_ON);
 sendSignal(LG_TV__CODE_POWER_ON);

 //if (irrecv.decode(&results)) {
   // Display a crude timestamp.
//    uint32_t now = millis();
//    Serial.printf("Timestamp : %06u.%03u\n", now / 1000, now % 1000);

 //}
}

void LGTV::channel(std::string ch) {
  PRINTLN("Switch to channel " + String(ch.c_str()) + " on the LG TV");

  for (int i = 0; i < ch.length(); i++) {
    switch (ch[i]) {
      case '1': sendSignal(LG_TV__CODE_1); break;
      case '2': sendSignal(LG_TV__CODE_2); break;
      case '3': sendSignal(LG_TV__CODE_3); break;
      case '4': sendSignal(LG_TV__CODE_4); break;
      case '5': sendSignal(LG_TV__CODE_5); break;
      case '6': sendSignal(LG_TV__CODE_6); break;
      case '7': sendSignal(LG_TV__CODE_7); break;
      case '8': sendSignal(LG_TV__CODE_8); break;
      case '9': sendSignal(LG_TV__CODE_9); break;
      case '0': sendSignal(LG_TV__CODE_0); break;
    }
  }
}

void LGTV::off() {
  PRINTLN("Power Off the LG TV");
  sendSignal(LG_TV__CODE_POWER_OFF);
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
