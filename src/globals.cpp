#include "globals.h"

const char * mqttClientName = "DSCInterface";
const char * mqttZoneStatusTopic = "DSC/Get/Zone";
const char * mqttRelayStatusTopic = "DSC/Get/Relay";
const char * mqttTroubleMsgTopic = "DSC/Get/Trouble";
const char * mqttPanelTopic = "DSC/Get";
const char * mqttPartitionTopic = "DSC/Get/Partition";
const char * mqttStatusSuffix = "/Status";
const char * mqttFireSuffix = "/Fire";
const char * mqttZoneMsgTopic = "DSC/Get/ZoneExtStatus";
const char * mqttPartitionMsgSuffix = "/Message";
const char * mqttBeepSuffix = "/Beep";
const char * mqttLine1Suffix = "/DisplayLine1";
const char * mqttLine2Suffix = "/DisplayLine2";
const char * mqttEventTopic = "DSC/Get/Event";
const char * mqttBirthMessage = "online";
const char * mqttLwtMessage = "offline";
const char * mqttCmdSubscribeTopic = "DSC/Set";