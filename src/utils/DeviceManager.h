#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <devices/Chuwi.h>
#include <devices/RFLightSwitch.h>
#include<devices/LGTV.h>
#include<devices/MitsubishiAC.h>
#include <utils/JsonUtils.h>
#include <PubSubClient.h>


class DeviceManager {
public:

  DeviceManager();
  void processRequest(char        *topic,
                      char        *command,
                      PubSubClient mqttClient);

private:

  Chuwi *chuwiCtl;
  RFLightSwitch *lightSwitch;
  LGTV *lgCtl;
  MitsubishiAC *ac;
  //IRMitsubishiAC *mitsubir;
  void controlChuwi(char         *command,
                    String       mqttTopicGet,
                    PubSubClient mqttClient);
  void controlLight(char         *command,
                    String       mqttTopicGet,
                    PubSubClient mqttClient);
  void controlTV(char         *command,
                 String       mqttTopicGet,
                 PubSubClient mqttClient);
  void controlAC(String        setting,
                 char         *command,
                String       mqttTopicGet,
                PubSubClient mqttClient);
  void processResponse(const char  *messageId,
                       const char  *result,
                       String       mqttTopicGet,
                       PubSubClient mqttClient);
};

#endif // ifndef DEVICE_MANAGER_H