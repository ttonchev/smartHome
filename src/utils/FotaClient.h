#ifndef FOTA_CLIENT_H
#define FOTA_CLIENT_H

#include <Arduino.h>

class FotaClient {
public:

  FotaClient(const char *deviceName);
  void init();
  void loop();

private:

  const char *deviceName;
};

#endif // ifndef FOTA_CLIENT_H
