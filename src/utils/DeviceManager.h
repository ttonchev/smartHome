#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <devices/Chuwi.h>
#include <devices/RFLightSwitch.h>
#include<devices/LGTV.h>
#include<devices/MitsubishiAC.h>
#include<devices/RFBathAirSwitch.h>
#include<devices/RFWCAirSwitch.h>
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
  RFBathAirSwitch *bathAir;
  RFWCAirSwitch *wcAir;
  //IRMitsubishiAC *mitsubir;
  void controlChuwi(char         *command,
                    String       mqttTopicGet,
                    PubSubClient mqttClient);
  void controlLight(char         *command,
                    String       mqttTopicGet,
                    PubSubClient mqttClient);
  void controlTV(String        setting,
                 char         *command,
                 String       mqttTopicGet,
                 PubSubClient mqttClient);
  void controlAC(String        setting,
                 char         *command,
                String       mqttTopicGet,
                PubSubClient mqttClient);
  void controlBathAir(char         *command,
                 String       mqttTopicGet,
                 PubSubClient mqttClient);
  void controlWCAir(char         *command,
                 String       mqttTopicGet,
                 PubSubClient mqttClient);
  void processResponse(const char  *messageId,
                       const char  *result,
                       String       mqttTopicGet,
                       PubSubClient mqttClient);
};

#endif // ifndef DEVICE_MANAGER_H
