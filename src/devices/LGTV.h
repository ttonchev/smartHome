#ifndef LG_TV_H
#define LG_TV_H

#define CAPTURE_BUFFER_SIZE 1024
#define TIMEOUT 400
#define MTEL_TV__CODE_1 0xFF807F
#define MTEL_TV__CODE_2 0xFF40BF
#define MTEL_TV__CODE_3 0xFFC03F
#define MTEL_TV__CODE_4 0xFF20DF
#define MTEL_TV__CODE_5 0xFFA05F
#define MTEL_TV__CODE_6 0xFF609F
#define MTEL_TV__CODE_7 0xFFE01F
#define MTEL_TV__CODE_8 0xFF10EF
#define MTEL_TV__CODE_9 0xFF906F
#define MTEL_TV__CODE_0 0xFF00FF
#define MTEL_TV__CODE_CHANNEL_UP 0xFFD02F
#define MTEL_TV__CODE_CHANNEL_DOWN 0xFFA857
#define MTEL_TV__CODE_VOLUME_UP 0xFF30CF
#define MTEL_TV__CODE_VOLUME_DOWN 0xFF18E7
#define MTEL_TV__CODE_REWIND 0xFFC23D
#define MTEL_TV__CODE_FORWARD 0xFF629D
#define MTEL_TV__CODE_PAUSE_PLAY 0xFF22DD
#define MTEL_TV__CODE_STOP 0xFFA25D
#define MTEL_TV__CODE_BEGINING 0xFFB04F
#define LG_TV__CODE_MUTE 0x20DF906F
#define LG_TV__CODE_POWER_ON_OFF 0x20DF10EF
#define LG_TV__CODE_MTEL_POWER_ON_OFF 0xFF02FD
#define LG_TV__CODE_UP 0x20DF02FD
#define LG_TV__CODE_DOWN 0x20DF827D
#define LG_TV__CODE_RIGHT 0x20DF609F
#define LG_TV__CODE_LEFT 0x20DFE01F
#define LG_TV__CODE_EXIT 0x20DFDA25
#define LG_TV__CODE_OUTPUT_SELECT 0x20DFD02F
#define LG_TV__CODE_OK 0x20DF22DD
#define LG_TV__CODE_HOME 0x20DF3EC1
#define LG_TV__CODE_BACK 0x20DF14EB

#include <string>
#include <IRsend.h> // https://github.com/markszabo/IRremoteESP8266
#include <IRrecv.h>

class LGTV {
public:

  LGTV();
  void on();
  void channel(std::string ch);
  void channelUp();
  void channelDown();
  void up();
  void down();
  void left();
  void right();
  void play();
  void rewind();
  void forward();
  void begining();
  void sendSignal(unsigned long signal_code);
  void hdmi1();
  void off();
  void netflix(char *command);

private:

  IRsend irSender;
};

#endif // ifndef LG_TV_H
