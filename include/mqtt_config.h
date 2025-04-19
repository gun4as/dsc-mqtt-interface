#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

#include <Arduino.h>

struct Config {
  String mqttServer;
  int mqttPort;
  String mqttUsername;
  String mqttPassword;
  String accessCode;
  int partition;
  int defaultPartition;
  int maxZonesDefault;
  int maxRelays;
  int Ddebug;
  int expanderAddr1;
  int expanderAddr2;
  bool useDHCP;
  String staticIP;
  String gateway;
  String subnet;
  String dns;
  String webUsername;
  String webPassword;
};

extern Config config;

bool loadConfig();
bool saveConfig();
void applyDefaultConfig();
#endif
