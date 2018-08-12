#include <Settings.h>
#include <PubSubClient.h>
#include <SmartHomeWiFiManager.h>
#include <utils/FotaClient.h>
#include <utils/DeviceManager.h>

SmartHomeWiFiManager smartHomeWiFiManager;
WiFiClientSecure     espClient;
FotaClient *fotaClient       = new FotaClient(DEVICE_NAME);
DeviceManager *deviceManager = new DeviceManager();
PubSubClient   mqttClient(espClient);
unsigned long  lastMqttConnectedMillis = 0;
unsigned long  lastPushMillis          = 0;

void callback(char *topic, byte *payload, unsigned int length) {
  PRINT("Message arrived [");
  PRINT(topic);
  PRINT("]: ");

  for (int i = 0; i < length; i++) {
    PRINT((char)payload[i]);
  }
  PRINTLN();

  char spayload[length + 1];
  memcpy(spayload, payload, length);
  spayload[length] = '\0';

  deviceManager->processRequest(topic, spayload, mqttClient);
}

void mqttReconnectIfNeeded() {
  while (!mqttClient.connected()) {
    PRINT("Attempting MQTT connection... ");

    // Don't clean the session if MQTT connection is lost for more than 10 sec
    bool cleanSession = lastMqttConnectedMillis == 0 || (millis() - lastMqttConnectedMillis) > 10 * 1000;

    if (cleanSession) {
      PRINT("Use clean session. ");
    } else {
      PRINT("Preseve the session. ");
    }

    if (mqttClient.connect("xnabysnk", MQTT_USER, MQTT_PASS, cleanSession)) {
      // mqttClient.publish(MQTT_SUBSCRIBE_TOPIC, "", 1, true); // clear the retain message for specific topic
      mqttClient.subscribe(MQTT_SUBSCRIBE_TOPIC, 1);
      PRINTLN("Connected");
    } else {
      PRINT("failed, rc=");
      PRINT(mqttClient.state());
      PRINTLN(" try again in 5 seconds");
      delay(5000);
    }
  }
  lastMqttConnectedMillis = millis();
}

void setup() {
  delay(2000);
  smartHomeWiFiManager.init(WIFI_AP_SSID, WIFI_AP_PASSWORD);
  smartHomeWiFiManager.connect();

  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
  mqttClient.setCallback(callback);

  fotaClient->init();
    // put your setup code here, to run once:
}

void loop() {
  smartHomeWiFiManager.reconnectIfNeeded();
//

  mqttReconnectIfNeeded();
//PRINTLN("kor");
mqttClient.loop();
  fotaClient->loop();
    // put your main code here, to run repeatedly:

    if (millis() - lastPushMillis > 5 * 1000) {
     PRINT("5 seconds passed! My IP is ");
     PRINTLN(WiFi.localIP().toString());
     lastPushMillis = millis();
     }

    //chuwi->on();
  REMOTE_PRINT_HANDLER;
}
