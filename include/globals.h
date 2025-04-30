#ifndef GLOBALS_H
#define GLOBALS_H

#include <ETH.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "dscAlarm.h"  // vai kur definēta DSCkeybushome klase
#include <PubSubClient.h>
#include <WiFiClient.h>



//ethernet  LAN8720 pini
#define ETH_PARAM_PHY_ADDR 1
#define ETH_PARAM_PHY_TYPE ETH_PHY_LAN8720
#define ETH_PARAM_PHY_POWER 16
#define ETH_PARAM_PHY_MDC 23
#define ETH_PARAM_PHY_MDIO 18
#define ETH_PARAM_CLK_MODE ETH_CLOCK_GPIO0_OUT

//DSC pini
#define DSC_CLOCK_PIN 14
#define DSC_READ_PIN  33
#define DSC_WRITE_PIN 32

extern AsyncWebServer server;
extern bool eth_connected;


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

extern int dscClockPinDefault;
extern int dscReadPinDefault;
extern int dscWritePinDefault;

extern DSCkeybushome *DSCkeybus;  // ← tikai deklarācija!
extern PubSubClient mqtt; // ← tikai deklarācija!
extern WiFiClient ethClient;  // ✅ Šis!
#endif // GLOBALS_H