#ifndef RF_WC_AIR_SWITH_H
#define RF_WC_AIR_SWITH_H

#include <RCSwitch.h> // RF control lib, https://github.com/sui77/rc-switch

// Sesoo: protocol: 1, bits: 24, length: 284
#define SESOO__CODE_WC_ON 2881295
#define SESOO__CODE_WC_OFF 2881296

class RFWCAirSwitch {
public:

  RFWCAirSwitch();
  void on();
  void off();

private:

  RCSwitch mySwitch;
};

#endif // ifndef RF_LIGHT_SWITH_H
