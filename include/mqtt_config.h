#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

#include <Arduino.h>

struct Config {
  String mqttServer;
  uint16_t mqttPort;
  String mqttUsername;
  String mqttPassword;
  String accessCode;
  uint8_t partition;
  uint8_t debug;
  uint8_t expander1;
  uint8_t expander2;
  uint8_t zones;
  uint8_t relays;
};

extern Config config;

bool loadConfig();
bool saveConfig();
bool configExists();

#endif
