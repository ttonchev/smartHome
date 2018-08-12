#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <RemotePrint.h>

#define WIFI_AP_SSID "xxxxxx"
#define WIFI_AP_PASSWORD "xxxxxx"
#define MQTT_SERVER "xxxx" // m20.cloudmqtt.com
#define MQTT_PORT 00000
#define MQTT_USER "xxxxx"
#define MQTT_PASS "xxxxx"
#define MQTT_SUBSCRIBE_TOPIC "set/apartment/livingRoom/#"

#define AC_IR_PIN_SENDER 4   // AC IR LED PIN
#define TV_IR_PIN_SENDER 4     // TV IR LED PIN
#define CHUWI_IR_PIN_SENDER 4 // YAMAHA IR LED PIN
#define RF_TRANSMITTER_PIN 5   // GPIO pin 5 (NodeMCU Pin D1)

#define DEVICE_NAME HOSTNAME
#define ARDUINO_OTA_PORT 8266
#define ARDUINO_OTA_PASS_HASH "d41e98d1eafa6d6011d3a70f1a5b92f0"

#endif // ifndef COMMON_H
