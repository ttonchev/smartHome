#ifndef CHUWI_H
#define CHUWI_H

#define CHUWI__CODE_POWER_ON 0x2AA22DD
#define CHUWI__CODE_POWER_OFF 0x2AA8877

#include <IRsend.h>

class Chuwi {

public:

  Chuwi();
  void on();
  void off();
  void sendSignal(unsigned long signal_code);

private:

  IRsend irSender;

};

#endif // ifndef CHUWI_H
