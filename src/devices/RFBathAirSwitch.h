#ifndef RF_BATH_AIR_SWITH_H
#define RF_BATH_AIR_SWITH_H

#include <RCSwitch.h> // RF control lib, https://github.com/sui77/rc-switch

// Sesoo: protocol: 1, bits: 24, length: 284
#define SESOO__CODE_BATH_ON 2881298
#define SESOO__CODE_BATH_OFF 2881297

class RFBathAirSwitch {
public:

  RFBathAirSwitch();
  void on();
  void off();

private:

  RCSwitch mySwitch;
};

#endif // ifndef RF_LIGHT_SWITH_H
