#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <ArduinoJson.h>
#include <Settings.h>

class JsonUtils {
public:

  static JsonObject* parseJsonString(char *json) {
    StaticJsonBuffer<500> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(json);

    if (!root.success()) {
      PRINTLN("parseObject() failed");
      return nullptr;
    }
    return &root;
  }
};

#endif // ifndef JSON_UTILS_H
