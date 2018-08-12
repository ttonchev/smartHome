#ifndef RF_LIGHT_SWITH_H
#define RF_LIGHT_SWITH_H

#include <RCSwitch.h> // RF control lib, https://github.com/sui77/rc-switch

// Sesoo: protocol: 1, bits: 24, length: 284
#define SESOO__CODE_A 2881300
#define SESOO__CODE_B 2881304
#define SESOO__CODE_C 2881297
#define SESOO__CODE_D 2881298

class RFLightSwitch {
public:

  RFLightSwitch();
  void on();
  void off();

private:

  RCSwitch mySwitch;
};

#endif // ifndef RF_LIGHT_SWITH_H
