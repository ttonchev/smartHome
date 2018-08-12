#include <Settings.h>
#include <utils/FotaClient.h>
#include <ArduinoOTA.h>
#include <RemotePrint.h>

FotaClient::FotaClient(const char *deviceName) {
  this->deviceName = deviceName;
}

void FotaClient::init() {
  ArduinoOTA.setPort(ARDUINO_OTA_PORT);
  ArduinoOTA.setHostname(deviceName);
  ArduinoOTA.setPasswordHash(ARDUINO_OTA_PASS_HASH);

  ArduinoOTA.onStart([]() {
    String type;

    if (ArduinoOTA.getCommand() == U_FLASH) type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using
    // SPIFFS.end()
    PRINTLN("FOTA: Start updating " + type);
  });

  ArduinoOTA.onEnd([]() {
    PRINTLN("\nEnd");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    PRINT("FOTA: Progress: ");
    PRINTLN(progress / (total / 100));
  });

  ArduinoOTA.onError([](ota_error_t error) {
    PRINT_E("FOTA: Error: ");
    PRINT_E(error);

    if (error == OTA_AUTH_ERROR) PRINTLN_E("Auth Failed");

    if (error == OTA_BEGIN_ERROR) PRINTLN_E("Begin Failed");

    if (error == OTA_CONNECT_ERROR) PRINTLN_E("Connect Failed");

    if (error == OTA_RECEIVE_ERROR) PRINTLN_E("Receive Failed");

    if (error == OTA_END_ERROR) PRINTLN_E("End Failed");
  });

  ArduinoOTA.begin();
}

void FotaClient::loop() {
  ArduinoOTA.handle();
}
