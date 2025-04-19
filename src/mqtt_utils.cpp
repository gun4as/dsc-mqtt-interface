#include "mqtt_utils.h"
#include <ArduinoJson.h>
#include "dscAlarm.h"
#include "mqtt_config.h"
#include "globals.h"
#include <WiFiClient.h>
#include "led_utils.h"

bool setupMqtt() {
  mqtt.setCallback(mqttCallback);
  if (mqttConnect()) {
    mqttPreviousTime = millis();
    return true;
  }
  mqttPreviousTime = 0;
  return false;
}

void mqttCallback(char * topic, byte * payload, unsigned int length) {
  StaticJsonDocument<256> doc;
  deserializeJson(doc, payload);
  int p = config.defaultPartition;
  const char * s = "";
  const char * c = config.accessCode.c_str();
  if (strcmp(topic, mqttCmdSubscribeTopic) == 0) {
    if (doc.containsKey("partition"))
      p = doc["partition"];
    if (doc.containsKey("code"))
      c = doc["code"];
    if (doc.containsKey("state")) {
      s = doc["state"];
      DSCkeybus->set_alarm_state(s, c, p);
    } else if (doc.containsKey("keys")) {
      s = doc["keys"];
      DSCkeybus->alarm_keypress_partition(s, p);
    } else if (doc.containsKey("fault") && doc.containsKey("zone")) {
      int z = doc["zone"];
      bool f = doc["fault"] > 0 ? 1 : 0;
      DSCkeybus->set_zone_fault(z, f);
    } else if (doc.containsKey("stop")) {
      disconnectKeybus();
    } else if (doc.containsKey("start") || doc.containsKey("restart")) {
      ESP.restart();
    }
  }
}

void mqttHandle() {
  static unsigned long mqttPreviousTime = 0;

  if (!eth_connected) {
    setLedStatus(LED_NETWORK_DISCONNECTED);
    return;
  }

  if (!mqtt.connected()) {
    setLedStatus(LED_MQTT_DISCONNECTED);
    unsigned long now = millis();
    if (now - mqttPreviousTime > 5000 || mqttPreviousTime == 0) {
      mqttPreviousTime = now;

      Serial.print(F("Attempting MQTT connection... "));
      if (mqttConnect()) {
        Serial.println(F("Success!"));
        mqttPreviousTime = 0;
      } else {
        Serial.println(F("Failed."));
        Serial.print(F("Status code = "));
        Serial.println(mqtt.state());
      }
    }
  } else {
    mqtt.loop();
    setLedStatus(LED_OK);
  }
}

bool mqttConnect() {
  Serial.print(F("MQTT...."));
  mqtt.setKeepAlive(60);
  mqtt.setSocketTimeout(60);

  if (mqtt.connect(mqttClientName, config.mqttUsername.c_str(), config.mqttPassword.c_str())) {
    Serial.print(F("connected: "));
    Serial.println(config.mqttServer);
    mqtt.subscribe(mqttCmdSubscribeTopic);
  } else {
    Serial.print(F("connection error: "));
    Serial.println(config.mqttServer);
  }
  return mqtt.connected();
}

void mqttPublish(const char * publishTopic,const char * value) {
  mqtt.publish(publishTopic, value);
}

void mqttPublish(const char * topic,const char * suffix,const char * value) {
  char publishTopic[strlen(topic) + 3 + strlen(suffix)];
  strcpy(publishTopic, topic);
  strcat(publishTopic, suffix);
  mqtt.publish(publishTopic, value);
}

void mqttPublish(const char * topic,const char * suffix, bool bvalue) {
  const char * value = bvalue ? "ON" : "OFF";
  mqttPublish(topic, suffix, value);
}

void mqttPublish(const char * topic,const char * suffix, byte srcNumber,const char * value) {
  char publishTopic[strlen(topic) + 10 + strlen(suffix)];
  char dstNumber[3];
  strcpy(publishTopic, topic);
  itoa(srcNumber, dstNumber, 10);
  strcat(publishTopic, dstNumber);
  strcat(publishTopic, suffix);
  mqtt.publish(publishTopic, value);
}

void mqttPublish(const char * topic,const char * suffix, byte srcNumber, bool bvalue) {
  const char * value = bvalue ? "ON" : "OFF";
  mqttPublish(topic, suffix, srcNumber, value);
}

void mqttPublish(const char * topic, byte srcNumber, bool bvalue) {
  const char * value = bvalue ? "ON" : "OFF";
  char publishTopic[strlen(topic) + 10];
  char dstNumber[3];
  strcpy(publishTopic, topic);
  itoa(srcNumber, dstNumber, 10);
  strcat(publishTopic, dstNumber);
  mqtt.publish(publishTopic, value);
}
