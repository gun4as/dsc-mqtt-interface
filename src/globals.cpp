#include "globals.h"
#include "mqtt_config.h"
#include <PubSubClient.h>
#include <WiFiClient.h>
#include "dscAlarm.h"

//izdzēs divniekus ja liec produkcijā viekārši ir pamainiti topiki lai neparklājas ar īsto

const char * mqttClientName = "DSC2Interface";
const char * mqttZoneStatusTopic = "DSC2/Get/Zone";
const char * mqttRelayStatusTopic = "DSC2/Get/Relay";
const char * mqttTroubleMsgTopic = "DSC2/Get/Trouble";
const char * mqttPanelTopic = "DSC2/Get";
const char * mqttPartitionTopic = "DSC2/Get/Partition";
const char * mqttStatusSuffix = "/Status";
const char * mqttFireSuffix = "/Fire";
const char * mqttZoneMsgTopic = "DSC2/Get/ZoneExtStatus";
const char * mqttPartitionMsgSuffix = "/Message";
const char * mqttBeepSuffix = "/Beep";
const char * mqttLine1Suffix = "/DisplayLine1";
const char * mqttLine2Suffix = "/DisplayLine2";
const char * mqttEventTopic = "DSC2/Get/Event";
const char * mqttBirthMessage = "online";
const char * mqttLwtMessage = "offline";
const char * mqttCmdSubscribeTopic = "DSC2/Set";

int dscClockPinDefault = DSC_CLOCK_PIN;
int dscReadPinDefault = DSC_READ_PIN;
int dscWritePinDefault = DSC_WRITE_PIN;

