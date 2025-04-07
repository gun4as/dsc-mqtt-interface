#include "wifi_utils.h"
#include <ESP8266WiFi.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "config.h"

void connectToWiFi() {
    WiFiManager wm;
    // Ja gribi testēt un piespiedu kārtā vienmēr palaist hotspotu:
  // wm.resetSettings();
    
    wm.setConfigPortalTimeout(apTimeoutSeconds);

    // Parāda AP IP adresi kad startē hotspotu
    wm.setAPCallback([](WiFiManager* wm) {
        Serial.println(F("Starting config portal..."));
        Serial.print(F("AP IP address: "));
        Serial.println(WiFi.softAPIP());
        Serial.print(F("Connect to WiFi SSID: "));
        Serial.println(wm->getConfigPortalSSID());
    });

    // autoConnect mēģina pieslēgties esošam WiFi. Ja neizdodas, atver hotspotu
    if (!wm.autoConnect(apSSID, apPassword)) {
        Serial.println(F("Failed to connect. Restarting..."));
        delay(3000);
        ESP.restart();
    }

    Serial.println(F("Connected to WiFi"));
    Serial.print(F("IP address: "));
    Serial.println(WiFi.localIP());
}
