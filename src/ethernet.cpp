#include "ethernet.h"
#include "globals.h"
#include "mqtt_config.h"
#include "led_utils.h" 

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case ARDUINO_EVENT_ETH_START:
      Serial.println("ETH Started");
      ETH.setHostname("esp32-eth-device");
      setLedStatus(LED_NETWORK_DISCONNECTED);
      break;
    case ARDUINO_EVENT_ETH_CONNECTED:
      Serial.println("ETH Connected");
      break;
    case ARDUINO_EVENT_ETH_GOT_IP:
      Serial.print("ETH MAC: ");
      Serial.print(ETH.macAddress());
      Serial.print(", IPv4: ");
      Serial.print(ETH.localIP());
      if (ETH.fullDuplex()) Serial.print(", FULL_DUPLEX");
      Serial.print(", ");
      Serial.print(ETH.linkSpeed());
      Serial.println("Mbps");
      eth_connected = true;
      setLedStatus(LED_OK);
      break;
    case ARDUINO_EVENT_ETH_DISCONNECTED:
      Serial.println("ETH Disconnected");
      eth_connected = false;
      setLedStatus(LED_NETWORK_DISCONNECTED);
      break;
    case ARDUINO_EVENT_ETH_STOP:
      Serial.println("ETH Stopped");
      eth_connected = false;
      setLedStatus(LED_NETWORK_DISCONNECTED);
      break;
    default:
      break;
  }
}

void setupEthernet() {
  WiFi.onEvent(WiFiEvent);
  Serial.println("[ETH] Initializing...");

  if (config.useDHCP) {
    Serial.println("[ETH] Trying DHCP...");

    ETH.begin(
      ETH_PARAM_PHY_ADDR,
      ETH_PARAM_PHY_POWER,
      ETH_PARAM_PHY_MDC,
      ETH_PARAM_PHY_MDIO,
      ETH_PARAM_PHY_TYPE,
      ETH_PARAM_CLK_MODE
    );

    unsigned long start = millis();
    bool gotIP = false;

    // Gaidām līdz 5 sek uz IP no DHCP
    while (millis() - start < 5000) {
      if (ETH.linkUp() && ETH.localIP()[0] != 0) {
        gotIP = true;
        break;
      }
      delay(100);
    }

    if (!gotIP) {
      Serial.println("[ETH] DHCP failed, switching to static fallback");

      IPAddress localIP, gateway, subnet, dns;
      localIP.fromString(config.staticIP);
      gateway.fromString(config.gateway);
      subnet.fromString(config.subnet);
      dns.fromString(config.dns);

      bool ok = ETH.config(localIP, gateway, subnet, dns);
      if (!ok) {
        Serial.println("[ETH] ⚠️ ETH.config() failed for fallback!");
      }
    }
  } else {
    Serial.println("[ETH] Using static IP");

    ETH.begin(
      ETH_PARAM_PHY_ADDR,
      ETH_PARAM_PHY_POWER,
      ETH_PARAM_PHY_MDC,
      ETH_PARAM_PHY_MDIO,
      ETH_PARAM_PHY_TYPE,
      ETH_PARAM_CLK_MODE
    );

    delay(100);

    IPAddress localIP, gateway, subnet, dns;
    localIP.fromString(config.staticIP);
    gateway.fromString(config.gateway);
    subnet.fromString(config.subnet);
    dns.fromString(config.dns);

    bool ok = ETH.config(localIP, gateway, subnet, dns);
    if (!ok) {
      Serial.println("[ETH] ⚠️ ETH.config() failed!");
    }
  }
}
