#include "web_server.h"
#include "mqtt_config.h"
#include "globals.h"
#include <LittleFS.h>
#include <ArduinoJson.h>

void setupWebServer() {
  Serial.println(F("[WEB] Starting web server..."));

  const char* www_username = config.webUsername.c_str();
  const char* www_password = config.webPassword.c_str();

  // Aizsargājam visus statiskos failus
  server.serveStatic("/", LittleFS, "/")
        .setDefaultFile("index.html")
        .setAuthentication(www_username, www_password);

  server.on("/config", HTTP_GET, [www_username, www_password](AsyncWebServerRequest *request){
    if (!request->authenticate(www_username, www_password)) return request->requestAuthentication();

    StaticJsonDocument<1024> doc;
    doc["mqttServer"]       = config.mqttServer;
    doc["mqttPort"]         = config.mqttPort;
    doc["mqttUsername"]     = config.mqttUsername;
    doc["mqttPassword"]     = config.mqttPassword;
    doc["accessCode"]       = config.accessCode;
    doc["partition"]        = config.partition;
    doc["defaultPartition"] = config.defaultPartition;
    doc["maxZonesDefault"]  = config.maxZonesDefault;
    doc["maxRelays"]        = config.maxRelays;
    doc["Ddebug"]           = config.Ddebug;
    doc["expanderAddr1"]    = config.expanderAddr1;
    doc["expanderAddr2"]    = config.expanderAddr2;
    doc["useDHCP"]          = config.useDHCP;
    doc["staticIP"]         = config.staticIP;
    doc["gateway"]          = config.gateway;
    doc["subnet"]           = config.subnet;
    doc["dns"]              = config.dns;
    doc["webUsername"]      = config.webUsername;
    doc["webPassword"]      = config.webPassword;

    String json;
    serializeJson(doc, json);
    request->send(200, "application/json", json);
  });

  server.on("/save", HTTP_POST, [](AsyncWebServerRequest *request) {}, nullptr,
    [www_username, www_password](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {
      if (!request->authenticate(www_username, www_password)) {
        request->requestAuthentication();
        return;
      }

      StaticJsonDocument<1024> doc;
      if (deserializeJson(doc, data, len)) {
        request->send(400, "application/json", "{\"error\":\"Invalid JSON\"}");
        return;
      }

      config.mqttServer       = doc["mqttServer"] | "";
      config.mqttPort         = doc["mqttPort"].as<int>();
      config.mqttUsername     = doc["mqttUsername"] | "";
      config.mqttPassword     = doc["mqttPassword"] | "";
      config.accessCode       = doc["accessCode"] | "";
      config.partition        = doc["partition"].as<int>();
      config.defaultPartition = doc["defaultPartition"].as<int>();
      config.maxZonesDefault  = doc["maxZonesDefault"].as<int>();
      config.maxRelays        = doc["maxRelays"].as<int>();
      config.Ddebug           = doc["Ddebug"].as<int>();
      config.expanderAddr1    = doc["expanderAddr1"].as<int>();
      config.expanderAddr2    = doc["expanderAddr2"].as<int>();
      config.useDHCP          = doc["useDHCP"] | true;
      config.staticIP         = doc["staticIP"] | "";
      config.gateway          = doc["gateway"] | "";
      config.subnet           = doc["subnet"] | "";
      config.dns              = doc["dns"] | "";
      config.webUsername      = doc["webUsername"] | "admin";
      config.webPassword      = doc["webPassword"] | "admin";

      if (saveConfig()) {
        request->send(200, "application/json", "{\"success\":true}");
        delay(1000);
        ESP.restart();
      } else {
        request->send(500, "application/json", "{\"error\":\"Failed to save\"}");
      }
  });

  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(LittleFS, "/index.html", "text/html");
  });

  server.begin();
}
