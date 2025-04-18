
#include "Arduino.h"
#include "config.h"

#ifdef ESP32
  #ifdef ETHERNET
    #include <SPI.h>
    #include <Ethernet.h>
    #include <AsyncTCP.h> 

  #else
    #include <WiFi.h>
    #include <mDNS.h>
    #include "wifi_utils.h"
  #endif
#else
  // ESP8266 vienmēr izmanto WiFi
  #include <ESP8266WiFi.h>
  #include <ESP8266mDNS.h>
  #include "wifi_utils.h"
#endif

#include <string>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "dscAlarm.h"
#include "mqtt_utils.h"
#include "globals.h"
#include "dsc_utils.h"
#include "mqtt_config.h"
#include <LittleFS.h>
#include "web_server.h"
#include "led_utils.h"


unsigned long lastReconnectAttempt = 0;
const unsigned long reconnectInterval = 10000;
int wifiReconnectAttempts = 0;
const int maxReconnectAttempts = 10;


unsigned long mqttPreviousTime;
DSCkeybushome *DSCkeybus = nullptr;

void setup() {
  Serial.setDebugOutput(true);
  Serial.begin(115200);
  Serial.println(); 

  LittleFS.begin();

#ifdef ETHERNET 
  Serial.println(F("Disabling WiFi (ESP32)..."));
  
  // 1. Standarta WiFi atslēgšana
  WiFi.disconnect(true, true);
  WiFi.mode(WIFI_OFF);
  delay(500);

  Serial.println(F("Initializing Ethernet (W5500)..."));
  Ethernet.init(5);
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  if (Ethernet.begin(mac) == 0) {
    Serial.println(F("Failed to configure Ethernet using DHCP"));
    // TODO: fallback uz static IP
  } else {
    Serial.print(F("Ethernet IP address: "));
    Serial.println(Ethernet.localIP());
   
  };
#else
  connectToWiFi();
#endif

  setupMqtt();

  setupDSC();
  Serial.println(F("DSC Interface is online."));

  //setupWebServer();
 // setLedStatus(LED_OK);
}


void loop() {
 // updateLed();
  DSCkeybus->loop();

  static bool delayedStartup = true;
  static unsigned long delayedStartupTime = millis();

  if (delayedStartup && millis() - delayedStartupTime > 30000) {
    delayedStartup = false;
  }

#ifdef ETHERNET
  // Ethernet savienojuma pārbaude
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println(F("Ethernet link is down."));
    return;
  }
#else
  // WiFi reconnect loģika
  wl_status_t wifiStatus = WiFi.status();
  if (wifiStatus != WL_CONNECTED && wifiStatus != WL_IDLE_STATUS) {
    if (millis() - lastReconnectAttempt > reconnectInterval) {
      Serial.println(F("WiFi disconnected. Reconnecting..."));

      WiFi.disconnect(true);
      delay(100);
      WiFi.begin();

      lastReconnectAttempt = millis();
      wifiReconnectAttempts++;

      if (wifiReconnectAttempts > maxReconnectAttempts) {
        Serial.println(F("WiFi failed too many times, restarting..."));
        ESP.restart();
      }
    }
    return;
  } else {
    wifiReconnectAttempts = 0;
  }
#endif

  mqttHandle();  // darbojas gan ar WiFi, gan Ethernet
 
}
