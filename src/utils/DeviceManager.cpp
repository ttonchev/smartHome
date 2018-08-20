#include <Settings.h>
#include <utils/DeviceManager.h>
#include <utils/JsonUtils.h>

DeviceManager::DeviceManager() :
  chuwiCtl(new Chuwi()),
  lgCtl(new LGTV()),
  ac(new MitsubishiAC()) ,
  lightSwitch(new RFLightSwitch),
  air(new RFBathAirSwitch) {}

void DeviceManager::processRequest(char *topic, char *command, PubSubClient   mqttClient) {
  int slashIndex  = String(topic).lastIndexOf("Room");
  String deviceAndCommand   = String(topic).substring(slashIndex + 5);
  String mqttTopicGet = "get" + String(topic).substring(3);
  String deviceName;
  String setting;
  if (deviceAndCommand.indexOf("/") != -1) {
    deviceName = deviceAndCommand.substring(0, deviceAndCommand.indexOf("/"));
    setting = deviceAndCommand.substring(deviceAndCommand.indexOf("/") + 1);
    PRINTLN(setting);
    PRINTLN(deviceName);
  } else {
    deviceName = deviceAndCommand;
    PRINTLN(deviceName);
  }
  // TODO: use TRY/CATCH here
  if (strcasecmp("CHUWI", deviceName.c_str()) == 0) {
    controlChuwi(command, mqttTopicGet, mqttClient);
  } else if (strcasecmp("LIGHT", deviceName.c_str()) == 0) {
    controlLight(command, mqttTopicGet, mqttClient);
  } else if (strcasecmp("TV", deviceName.c_str()) == 0) {
    controlTV(setting, command, mqttTopicGet, mqttClient);
  } else if (strcasecmp("AC", deviceName.c_str()) == 0) {
    controlAC(setting, command, mqttTopicGet, mqttClient);
  } else if (strcasecmp("AIR", deviceName.c_str()) == 0) {
    controlAir(setting, command, mqttTopicGet, mqttClient);
  }
}

void DeviceManager::controlLight(char *command, String mqttTopicGet, PubSubClient   mqttClient) {
  if (strcasecmp(command, "1") == 0) {
    lightSwitch->on();
  } else if (strcasecmp(command, "0") == 0) {
    lightSwitch->off();
  } else {
    PRINTLN_E("illegal argumenrs");
    return;
  }
}

void DeviceManager::controlChuwi(char *command, String mqttTopicGet, PubSubClient   mqttClient) {
  if (strcasecmp(command, "on") == 0) {
      chuwiCtl->on();
  } else if (strcasecmp(command, "off") == 0){
    chuwiCtl->off();
  } else {
    PRINTLN_E("illegal argumenrs");
    return;
  }
}

void DeviceManager::controlTV(String setting, char *command, String mqttTopicGet, PubSubClient   mqttClient) {
  if (strcasecmp(command, "on") == 0) {
    lgCtl->on();
  } else if (strcasecmp(command, "off") == 0) {
    lgCtl->off();
  } else if (strcasecmp(command, "up") == 0) {
    lgCtl->up();
  } else if (strcasecmp(command, "down") == 0) {
    lgCtl->down();
  } else if (setting == "play") {
    lgCtl->play();
  } else if (setting == "rewind") {
    lgCtl->rewind();
  } else if (setting == "forward") {
    lgCtl->forward();
  } else if (setting == "begining") {
    lgCtl->begining();
  } else if (strcasecmp(setting.c_str(), "changeChannel") == 0) {
    lgCtl->channel(command);
  }
}

void DeviceManager::controlAC(String setting, char *command, String mqttTopicGet, PubSubClient   mqttClient) {
  PRINTLN("setting" + setting);
  if (setting == "") {
    if (strcasecmp(command, "on") == 0) {
      ac->on();
    } else if (strcasecmp(command, "off") == 0) {
      ac->off();
    }
  } else if (strcasecmp("mode", setting.c_str()) == 0) {
    ac->mode(command);
  } else if (strcasecmp("temp", setting.c_str()) == 0) {
    ac->setTemp(String(command).toInt());
  } else if (strcasecmp("fan", setting.c_str()) == 0) {
    ac->setFan(String(command).toInt());
  }
}

void DeviceManager::controlAir(String setting, char *command, String mqttTopicGet, PubSubClient   mqttClient) {
  if(strcasecmp("bath", setting.c_str()) == 0) {
    if(strcasecmp(command, "on") == 0) {
      air->bathOn();
    } else {
      air->bathOff();
    }
  } else if(strcasecmp("wc", setting.c_str()) == 0) {
    if(strcasecmp(command, "on") == 0) {
      air->wcOn();
    } else {
      air->wcOff();
    }
  }
}

void DeviceManager::processResponse(const char  *messageId,
                                    const char  *result,
                                    String       mqttTopicGet,
                                    PubSubClient mqttClient) {
  const size_t bufferSize = JSON_OBJECT_SIZE(1) + 2;
  DynamicJsonBuffer responseJsonBuffer(bufferSize);
  JsonObject& responseRoot = responseJsonBuffer.createObject();

  responseRoot["messageId"] = messageId;
  responseRoot["result"]    = result;

  // Convert response to String
  String responseString;
  responseRoot.printTo(responseString);

  // Publish the response message with QoS 0
  mqttClient.publish(mqttTopicGet.c_str(), responseString.c_str(), 0, false);
}
