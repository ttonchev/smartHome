#ifndef LG_TV_H
#define LG_TV_H

#define CAPTURE_BUFFER_SIZE 1024
#define TIMEOUT 15U
#define LG_TV__CODE_1 0x10
#define LG_TV__CODE_2 0x810
#define LG_TV__CODE_3 0x410
#define LG_TV__CODE_4 0xc10
#define LG_TV__CODE_5 0x210
#define LG_TV__CODE_6 0xa10
#define LG_TV__CODE_7 0x610
#define LG_TV__CODE_8 0xe10
#define LG_TV__CODE_9 0x110
#define LG_TV__CODE_0 0x910
#define LG_TV__CODE_LAST 0xdd0
#define LG_TV__CODE_CHANNEL_GUIDE 0x710
#define LG_TV__CODE_CHANNEL_UP 0x90
#define LG_TV__CODE_CHANNEL_DOWN 0x890
#define LG_TV__CODE_VOLUME_UP 0x490
#define LG_TV__CODE_VOLUME_DOWN 0xc90
#define LG_TV__CODE_MUTE 0x290
#define LG_TV__CODE_POWER 0xa90
#define LG_TV__CODE_POWER_ON 0x20DF40BF//0x20DF10EF
#define LG_TV__CODE_MTEL_POWER_ON 0xFF02FD
#define LG_TV__CODE_POWER_OFF 0xf50
#define LG_TV__CODE_UP 0x8d0
#define LG_TV__CODE_DOWN 0x4d0
#define LG_TV__CODE_RIGHT 0xcd0
#define LG_TV__CODE_LEFT 0x2d0
#define LG_TV__CODE_EXIT 0xc70
#define LG_TV__CODE_ENTER_RETURN_SELECT 0xa70
#define LG_TV__CODE_OUTPUT_SELECT 0x670
#define LG_TV__CODE_TV_SYSTEM 0x170

#include <string>
#include <IRsend.h> // https://github.com/markszabo/IRremoteESP8266
#include <IRrecv.h>

class LGTV {
public:

  LGTV();
  void on();
  void channel(std::string ch);
  void sendSignal(unsigned long signal_code);
  void hdmi1();
  void off();

private:

  IRsend irSender;
};

#endif // ifndef LG_TV_H
