#include <Arduino.h>
#include <LittleFS.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include "config.h"
#include "globals.h"
#include "ethernet.h"
#include "web_server.h"
#include "mqtt_config.h"
#include "led_utils.h"
#include "mqtt_utils.h"
#include "dsc_utils.h"
#include "dscAlarm.h"

#if defined(useTIME)
  #include <time.h>
#endif

AsyncWebServer server(80);
bool eth_connected = false;

WiFiClient ethClient;
PubSubClient mqtt(ethClient); 
unsigned long mqttPreviousTime;
DSCkeybushome *DSCkeybus = nullptr;




void setup() {
  Serial.begin(115200);
  Serial.println("\n[BOOT] ESP32 starting...");
  initLed();
  //palaižam failsistēmu
  if (!LittleFS.begin()) {
    Serial.println("LittleFS mount failed");
    return;
  }
  loadConfig(); //ielasām konfigurācijas failu
  setupEthernet(); //startējam ethernet  
  setupDSC(); 
  Serial.println(F("DSC Interface is online."));
}

void loop() {
  static bool serverStarted = false;
  static bool mqttWasConnected = false;

  if (eth_connected && !serverStarted) {
    setupWebServer();
    mqtt.setServer(config.mqttServer.c_str(), config.mqttPort);
    setupMqtt();
  
    serverStarted = true;
  }

  // Ja tīkls ir atgriezies, bet MQTT nav, mēģina atkārtot
  if (eth_connected && !mqtt.connected()) {
    setupMqtt();   
  }

  mqttHandle();
  DSCkeybus->loop();
  updateLed();

}