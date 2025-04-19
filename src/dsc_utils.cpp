#include "dsc_utils.h"
#include "dscAlarm.h"
#include "globals.h"
#include "config.h"
#include "mqtt_utils.h"
#include "mqtt_config.h"

void setupDSC() {

DSCkeybus = new DSCkeybushome(dscClockPinDefault, dscReadPinDefault, dscWritePinDefault);
DSCkeybus->set_accessCode(config.accessCode.c_str());
DSCkeybus->set_maxZones(config.maxZonesDefault);
DSCkeybus->set_defaultPartition(config.defaultPartition);
DSCkeybus->set_debug(config.Ddebug);
DSCkeybus->set_expanderAddr(config.expanderAddr1, 0); // ja nepieciešams
DSCkeybus->set_expanderAddr(config.expanderAddr2, 0); // ja nepieciešams


DSCkeybus -> onSystemStatusChange([ & ](std::string statusCode) {
    mqttPublish(mqttPanelTopic, mqttStatusSuffix, statusCode.c_str());
  });

  DSCkeybus -> onPartitionStatusChange([ & ](std::string statusCode, int partition) {
    mqttPublish(mqttPartitionTopic, mqttStatusSuffix, partition, statusCode.c_str());
  });

  DSCkeybus -> onPartitionMsgChange([ & ](std::string msg, uint8_t partition) {
    mqttPublish(mqttPartitionTopic, mqttPartitionMsgSuffix, partition, msg.c_str());
  });

  DSCkeybus -> onPanelStatusChange([ & ](panelStatus ps, bool open, int partition) {

    String psvalue;

    switch (ps) {
    case trStatus:
      psvalue=F("/Trouble");
      break;
    case batStatus:
      psvalue=F("/Battery");
      break;
    case acStatus:
     psvalue=F("/AC");
      break;
    case panicStatus:
     psvalue=F("/Panic");
      break;
    case rdyStatus:
      psvalue=F("/Ready");
      break;
    case armStatus:
     psvalue=F("/Armed");
      break;
    case fireStatus:
      break;
    case chimeStatus:
      break;
    default:
      break;
    }
    
    if (!partition)
      mqttPublish(mqttPanelTopic, psvalue.c_str(), open);
    else
      mqttPublish(mqttPartitionTopic, psvalue.c_str(), partition, open);
  });
  DSCkeybus -> onZoneMsgStatus([ & ](std::string msg) {
    mqttPublish(mqttZoneMsgTopic, msg.c_str());
  });
  DSCkeybus -> onLine1Display([ & ](std::string msg, int partition) {
    mqttPublish(mqttPartitionTopic, mqttLine1Suffix, partition, msg.c_str());
  });
  DSCkeybus -> onLine2Display([ & ](std::string msg, int partition) {
    mqttPublish(mqttPartitionTopic, mqttLine2Suffix, partition, msg.c_str());
  });
  DSCkeybus -> onEventInfo([ & ](std::string msg) {
    mqttPublish(mqttEventTopic, msg.c_str());
  });

  DSCkeybus -> onBeeps([ & ](std::string beep, int partition) {
    mqttPublish(mqttPartitionTopic, mqttBeepSuffix, partition, beep.c_str());
  });
  DSCkeybus -> onFireStatusChange([ & ](bool open, int partition) {
    if (!partition)
      mqttPublish(mqttPanelTopic, mqttFireSuffix, open);
    else
      mqttPublish(mqttPartitionTopic, mqttFireSuffix, partition, open);
  });
  DSCkeybus -> onTroubleMsgStatus([ & ](std::string msg) {
    mqttPublish(mqttTroubleMsgTopic, msg.c_str());
  });
  DSCkeybus -> onZoneStatusChange([ & ](uint8_t zone, bool open) {
    mqttPublish(mqttZoneStatusTopic, zone, open);

  });
  DSCkeybus -> onRelayChannelChange([ & ](uint8_t channel, bool state) {
    mqttPublish(mqttRelayStatusTopic, channel, state);
  });

  DSCkeybus -> begin();
}