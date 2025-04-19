#include "mqtt_config.h"
#include <ArduinoJson.h>
#include <LittleFS.h>
#include "config.h"

Config config;


bool loadConfig() {
  if (!LittleFS.exists("/config.json")) {
    Serial.println("[CONFIG] config.json nav atrasts, izmantojam noklusējuma iestatījumus");
    applyDefaultConfig();
    saveConfig();
    delay(1000);
    ESP.restart();  // 🔁 Restartē ESP
    return false;
  }

  File file = LittleFS.open("/config.json", "r");
  if (!file) {
    Serial.println("[CONFIG] Nevar atvērt config.json");
    applyDefaultConfig();
    saveConfig();
    delay(1000);
    ESP.restart();  // 🔁 Restartē ESP
    return false;
  }

  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error) {
    Serial.println("[CONFIG] JSON kļūda, izmantojam noklusējuma iestatījumus");
    applyDefaultConfig();
    saveConfig();
    delay(1000);
    ESP.restart();  // 🔁 Restartē ESP
    return false;
  }

  // Ielasa no faila vai uzstāda no def. vērtībām
  config.mqttServer      = doc["mqttServer"] | DEFAULT_MQTT_SERVER;
  config.mqttPort        = doc["mqttPort"] | DEFAULT_MQTT_PORT;
  config.mqttUsername    = doc["mqttUsername"] | DEFAULT_MQTT_USERNAME;
  config.mqttPassword    = doc["mqttPassword"] | DEFAULT_MQTT_PASSWORD;
  config.accessCode      = doc["accessCode"] | DEFAULT_ACCESS_CODE;
  config.partition       = doc["partition"] | DEFAULT_PARTITION;
  config.defaultPartition = doc["primaryPartition"] | DEFAULT_PRIMARY_PARTITION;
  config.maxZonesDefault = doc["zones"] | DEFAULT_ZONES;
  config.maxRelays         = doc["relays"] | DEFAULT_RELAYS;
  config.Ddebug          = doc["debug"] | DEFAULT_DEBUG;
  config.expanderAddr1       = doc["expander1"] | DEFAULT_EXPANDER1;
  config.expanderAddr2       = doc["expander2"] | DEFAULT_EXPANDER2;
  config.useDHCP         = doc["useDHCP"] | DEFAULT_USE_DHCP;
  config.staticIP        = doc["staticIP"] | DEFAULT_STATIC_IP;
  config.gateway         = doc["gateway"] | DEFAULT_GATEWAY;
  config.subnet          = doc["subnet"] | DEFAULT_SUBNET;
  config.dns             = doc["dns"] | DEFAULT_DNS;
  config.webUsername     = doc["webUsername"] | DEFAULT_WEB_USERNAME;
  config.webPassword     = doc["webPassword"] | DEFAULT_WEB_PASSWORD;

  return true;
}

bool saveConfig() {
  File file = LittleFS.open("/config.json", "w");
  if (!file) return false;

  StaticJsonDocument<1024> doc;
  doc["mqttServer"]       = config.mqttServer;
  doc["mqttPort"]         = config.mqttPort;
  doc["mqttUsername"]     = config.mqttUsername;
  doc["mqttPassword"]     = config.mqttPassword;
  doc["accessCode"]       = config.accessCode;
  doc["partition"]        = config.partition;
  doc["primaryPartition"] = config.defaultPartition;
  doc["zones"]            = config.maxZonesDefault;
  doc["relays"]           = config.maxRelays;
  doc["debug"]            = config.Ddebug;
  doc["expander1"]        = config.expanderAddr1;
  doc["expander2"]        = config.expanderAddr2;
  doc["useDHCP"]          = config.useDHCP;
  doc["staticIP"]         = config.staticIP;
  doc["gateway"]          = config.gateway;
  doc["subnet"]           = config.subnet;
  doc["dns"]              = config.dns;
  doc["webUsername"]      = config.webUsername;
  doc["webPassword"]      = config.webPassword;
  serializeJsonPretty(doc, file);
  file.close();
  return true;
}

void applyDefaultConfig() {
  config.mqttServer       = DEFAULT_MQTT_SERVER;
  config.mqttPort         = DEFAULT_MQTT_PORT;
  config.mqttUsername     = DEFAULT_MQTT_USERNAME;
  config.mqttPassword     = DEFAULT_MQTT_PASSWORD;
  config.accessCode       = DEFAULT_ACCESS_CODE;
  config.partition        = DEFAULT_PARTITION;
  config.defaultPartition = DEFAULT_PRIMARY_PARTITION;
  config.maxZonesDefault  = DEFAULT_ZONES;
  config.maxRelays        = DEFAULT_RELAYS;
  config.Ddebug            = DEFAULT_DEBUG;
  config.expanderAddr1        = DEFAULT_EXPANDER1;
  config.expanderAddr2        = DEFAULT_EXPANDER2;
  config.useDHCP          = DEFAULT_USE_DHCP;
  config.staticIP         = DEFAULT_STATIC_IP;
  config.gateway          = DEFAULT_GATEWAY;
  config.subnet           = DEFAULT_SUBNET;
  config.dns              = DEFAULT_DNS;
  config.webUsername      = DEFAULT_WEB_USERNAME;
  config.webPassword      = DEFAULT_WEB_PASSWORD;
}
