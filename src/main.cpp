
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


// MQTT topics
const char * mqttClientName = "DSCInterface";
const char * mqttZoneStatusTopic = "DSC/Get/Zone"; // Sends zone status per zone: DSC/Get/Zone1 ... DSC/Get/Zone64
const char * mqttRelayStatusTopic = "DSC/Get/Relay"; //relay status (relay1... relay2)
const char * mqttTroubleMsgTopic = "DSC/Get/Trouble"; // Sends trouble status
const char * mqttPanelTopic = "DSC/Get";
const char * mqttPartitionTopic = "DSC/Get/Partition"; // Partition1 ... Partition2
const char * mqttStatusSuffix = "/Status"; // alarm/triggered ready/etc Partition1 ... Partition
const char * mqttFireSuffix = "/Fire"; // Sends fire status per partition: DSC/Get/Fire1/(on:off) ... DSC/Get/Fire8/(on:off)
const char * mqttZoneMsgTopic = "DSC/Get/ZoneExtStatus"; //zone extended statuses op/by/al
const char * mqttPartitionMsgSuffix = "/Message"; // Status messages for the partition
const char * mqttBeepSuffix = "/Beep"; // send beep counts for partition
const char * mqttLine1Suffix = "/DisplayLine1"; // send display line 1 for partition
const char * mqttLine2Suffix = "/DisplayLine2"; // send display line 1
const char * mqttEventTopic = "DSC/Get/Event"; // send event data for partition
const char * mqttBirthMessage = "online";
const char * mqttLwtMessage = "offline";
const char * mqttCmdSubscribeTopic = "DSC/Set"; // Receives messages to write to the panel


WiFiClient wifiClient;
PubSubClient mqtt(mqttServer, mqttPort, wifiClient);
unsigned long mqttPreviousTime;

DSCkeybushome *DSCkeybus = nullptr;


void setup() {
  Serial.setDebugOutput(true);
  Serial.begin(115200);
  Serial.println(); 
  connectToWiFi();
  setupMqtt();
  setupDSC();
  Serial.println(F("DSC Interface is online."));
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
