#include "mqtt_config.h"
#include <LittleFS.h>
#include <ArduinoJson.h>

Config config;

bool configExists() {
  return LittleFS.exists("/config.json");
}

bool loadConfig() {
  File file = LittleFS.open("/config.json", "r");
  if (!file) return false;

  StaticJsonDocument<512> doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();
  if (error) return false;

  config.mqttServer = doc["mqtt_server"].as<String>();
  config.mqttPort = doc["mqtt_port"] | 1883;
  config.mqttUsername = doc["mqtt_user"].as<String>();
  config.mqttPassword = doc["mqtt_pass"].as<String>();
  config.accessCode = doc["access_code"].as<String>();
  config.partition = doc["partition"] | 1;
  config.debug = doc["debug"] | 1;
  config.expander1 = doc["expander1"] | 0;
  config.expander2 = doc["expander2"] | 0;
  config.zones = doc["zones"] | 16;
  config.relays = doc["relays"] | 4;

  return true;
}

bool saveConfig() {
  StaticJsonDocument<512> doc;
  doc["mqtt_server"] = config.mqttServer;
  doc["mqtt_port"] = config.mqttPort;
  doc["mqtt_user"] = config.mqttUsername;
  doc["mqtt_pass"] = config.mqttPassword;
  doc["access_code"] = config.accessCode;
  doc["partition"] = config.partition;
  doc["debug"] = config.debug;
  doc["expander1"] = config.expander1;
  doc["expander2"] = config.expander2;
  doc["zones"] = config.zones;
  doc["relays"] = config.relays;

  File file = LittleFS.open("/config.json", "w");
  if (!file) return false;

  serializeJsonPretty(doc, file);
  file.close();
  return true;
}
