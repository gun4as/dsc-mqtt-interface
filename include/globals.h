#ifndef globals_h
#define globals_h
#include "dscAlarm.h"  // vai kur definēta DSCkeybushome klase
#include <PubSubClient.h>
#include <ESP8266WiFi.h>


// MQTT Topics (Constants)
extern const char * mqttClientName;
extern const char * mqttZoneStatusTopic;
extern const char * mqttRelayStatusTopic;
extern const char * mqttTroubleMsgTopic;
extern const char * mqttPanelTopic;
extern const char * mqttPartitionTopic;
extern const char * mqttStatusSuffix;
extern const char * mqttFireSuffix;
extern const char * mqttZoneMsgTopic;
extern const char * mqttPartitionMsgSuffix;
extern const char * mqttBeepSuffix;
extern const char * mqttLine1Suffix;
extern const char * mqttLine2Suffix;
extern const char * mqttEventTopic;
extern const char * mqttBirthMessage;
extern const char * mqttLwtMessage;
extern const char * mqttCmdSubscribeTopic;

extern unsigned long mqttPreviousTime;

extern DSCkeybushome *DSCkeybus;  // ← tikai deklarācija!
extern PubSubClient mqtt; // ← tikai deklarācija!
extern WiFiClient wifiClient;

#endif