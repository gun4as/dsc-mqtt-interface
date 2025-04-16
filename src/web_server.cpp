#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <mDNS.h>
#include <AsyncTCP.h>
#else
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif

#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include "mqtt_config.h"

AsyncWebServer server(80);
const char* adminPassword = "1234";

bool isConfigPortal = false;
bool isConfigPortalRequested() {
  return isConfigPortal;
}

void setupWebServer() {

    Serial.println(F("[WEB] Starting web server..."));
    Serial.print(F("[WEB] configExists = "));
    Serial.println(configExists());
    Serial.print(F("[WEB] isConfigPortal = "));
    Serial.println(isConfigPortal);


  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

  server.on("/save", HTTP_POST, [](AsyncWebServerRequest *request){
    if (!request->hasParam("plain", true)) {
      request->send(400, "application/json", "{\"error\":\"No data\"}");
      return;
    }

    String body = request->getParam("plain", true)->value();
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, body);

    if (error) {
      request->send(400, "application/json", "{\"error\":\"Invalid JSON\"}");
      return;
    }

    // ✅ Update global config values from JSON
    config.mqttServer  = doc["mqttServer"] | "";
    config.mqttPort    = doc["mqttPort"] | 1883;
    config.mqttUsername = doc["mqttUsername"] | "";
    config.mqttPassword = doc["mqttPassword"] | "";
    config.accessCode   = doc["accessCode"] | "";
    config.partition    = doc["partition"] | 1;
    config.debug        = doc["debug"] | 0;
    config.expander1    = doc["expander1"] | 0;
    config.expander2    = doc["expander2"] | 0;
    config.zones        = doc["zones"] | 24;
    config.relays       = doc["relays"] | 4;

    if (saveConfig()) {
      isConfigPortal = false;
      request->send(200, "application/json", "{\"success\":true}");
    } else {
      request->send(500, "application/json", "{\"error\":\"Failed to save\"}");
    }
  });

  /*
  server.onNotFound([](AsyncWebServerRequest *request) {
    if (request->url().indexOf("?password=") >= 0 &&
        request->arg("password") == adminPassword) {
      isConfigPortal = true;
    }
    

    if (!isConfigPortal && configExists()) {
      request->send(403, "text/plain", "Access denied");
      return;
    }



    request->send(LittleFS, "/index.html", String(), false);
  });
  */
  server.onNotFound([](AsyncWebServerRequest *request) {
    Serial.println("[WEB] OnNotFound called: " + request->url());
    request->send(LittleFS, "/index.html", "text/html");
  });
  
  server.begin();
}
