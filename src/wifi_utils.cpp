#include "wifi_utils.h"
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include "config.h"

void connectToWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifiSSID, wifiPassword);
    uint8_t checkCount = 20;
    while (WiFi.status() != WL_CONNECTED) {
      Serial.printf("Connecting to Wifi..%d\n", checkCount);
      delay(1000);
      if (checkCount--) continue;
      checkCount = 50;
      WiFi.disconnect();
      WiFi.reconnect();
    }
  
    Serial.println(F("Ready"));
    Serial.print(F("IP address: "));
    Serial.println(WiFi.localIP());
  }
  