
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <string>
#include <PubSubClient.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include "dscAlarm.h"
#include "mqtt_utils.h"
#include "config.h"
#include "globals.h"
#include "wifi_utils.h"
#include "dsc_utils.h"
#include "mqtt_config.h"
#include <LittleFS.h>
#include "web_server.h"

WiFiClient wifiClient;
PubSubClient mqtt(mqttServer, mqttPort, wifiClient);
unsigned long mqttPreviousTime;
DSCkeybushome *DSCkeybus = nullptr;


void setup() {
  Serial.setDebugOutput(true);
  Serial.begin(115200);
  Serial.println(); 
  LittleFS.begin();
  connectToWiFi();
  setupMqtt();
  setupDSC();
  Serial.println(F("DSC Interface is online."));
  setupWebServer();
}

void loop() {
  static int loopCount = 0;
  static unsigned long delayedStartupTime = millis();
  static bool delayedStartup = true;

  if (delayedStartup && (millis() - delayedStartupTime) > 30000) {
    delayedStartup = false;
  }

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin();
    if (loopCount == 0)
      Serial.println(F("\nWifi disconnected. Reconnecting..."));
    WiFi.disconnect();
    WiFi.reconnect();
    delay(1000);
    loopCount++;
    if (loopCount > 100)
      ESP.restart();
  } else
    loopCount = 0;

  if (WiFi.status() == WL_CONNECTED) {
      mqttHandle();
  }
  DSCkeybus -> loop();

} //loop
