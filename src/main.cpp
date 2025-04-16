
#include "Arduino.h"
#ifdef ESP32
#include <WiFi.h>
#include <mDNS.h>
#else
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#endif
#include <string>
#include <PubSubClient.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include "dscAlarm.h"
#include "mqtt_utils.h"
#include "config.h"
#include "globals.h"
#include "wifi_utils.h"
#include "dsc_utils.h"
#include "mqtt_config.h"
#include <LittleFS.h>
#include "web_server.h"
#include "led_utils.h"

#if defined(useTIME)
#include <time.h>
#endif

unsigned long lastReconnectAttempt = 0;
const unsigned long reconnectInterval = 10000;
int wifiReconnectAttempts = 0;
const int maxReconnectAttempts = 10;

WiFiClient wifiClient;
PubSubClient mqtt(mqttServer, mqttPort, wifiClient);
unsigned long mqttPreviousTime;
DSCkeybushome *DSCkeybus = nullptr;

#if defined(useTIME)
const long  timeZoneOffset = -5 * 3600;  // Offset from UTC in seconds (example: US Eastern is UTC - 5)
const int   daylightOffset = 1 * 3600;   // Daylight savings time offset in seconds
const char* ntpServer = "pool.ntp.org";  // Set the NTP server
#endif

#if defined(useTIME)
tm timeClient;
#endif

void setup() {
  Serial.setDebugOutput(true);
  Serial.begin(115200);
  Serial.println(); 

 
  LittleFS.begin();
  connectToWiFi();
  setupMqtt();
  #if defined(useTIME)
  configTime(timeZoneOffset, daylightOffset, ntpServer);
  while (!getLocalTime( & timeClient)) {
    Serial.print(".");
    delay(2000);
  }
  #endif
  setupDSC();
  Serial.println(F("DSC Interface is online."));
  setupWebServer();
  setLedStatus(LED_OK);
}

void loop() {
  updateLed();
  DSCkeybus->loop();

  static bool delayedStartup = true;
  static unsigned long delayedStartupTime = millis();

  if (delayedStartup && millis() - delayedStartupTime > 30000) {
    delayedStartup = false;
  }

  // Reconnect tikai, ja nav already connecting!
  wl_status_t wifiStatus = WiFi.status();

  if (wifiStatus != WL_CONNECTED && wifiStatus != WL_IDLE_STATUS) {
    if (millis() - lastReconnectAttempt > reconnectInterval) {
      Serial.println(F("WiFi disconnected. Reconnecting..."));

      WiFi.disconnect(true);  // ar "true" notīra statusu
      delay(100);             // dod nedaudz laika
      WiFi.begin();           // mēģina no jauna

      lastReconnectAttempt = millis();
      wifiReconnectAttempts++;

      if (wifiReconnectAttempts > maxReconnectAttempts) {
        Serial.println(F("WiFi failed too many times, restarting..."));
        ESP.restart();
      }
    }
    return;
  } else {
    wifiReconnectAttempts = 0;  // savienots veiksmīgi
  }

  mqttHandle();  // izsauc tikai ja WiFi OK
}