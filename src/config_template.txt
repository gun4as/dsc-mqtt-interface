#include "config.h"

// ==============================
// WiFi Settings
// ==============================

// WiFi SSID (tīkla nosaukums)
const char * wifiSSID = "YOUR_WIFI";

// WiFi parole
const char * wifiPassword = "YOUR_WIFI_PASSWORD";

// ==============================
// DSC Access Codes
// ==============================

// DSC signalizācijas piekļuves kods — tiek izmantots, lai ieslēgtu/atslēgtu signalizāciju
const char * accessCode = "YOUR_accessCode";

// ==============================
// MQTT Settings
// ==============================

// MQTT brokera IP vai domēns
const char * mqttServer = "YOUR_mqttServer IP";

// MQTT lietotājvārds (ja nepieciešams)
const char * mqttUsername = "YOUR_mqtt_username";

// MQTT parole (ja nepieciešams)
const char * mqttPassword = "YOUR_mqtt_Password";

// MQTT porta numurs (noklusēti 1883)
const int mqttPort = 1883;  // <-- NEDRĪKST izmantot pēdiņas! Skat. zemāk.

// ==============================
// Panel Settings
// ==============================

// Noklusētais partitions (parasti 1)
const int defaultPartition = 1;

// Adreses paplašinātājiem (ja lieto)
const int expanderAddr1 = 0;
const int expanderAddr2 = 0;

// Debug līmenis (0 = off, 1 = pamata, 2 = detalizēti)
const int Ddebug = 2;

// ==============================
// Hardware Pins (ESP8266 GPIO)
// ==============================

// DSC Clock signāla GPIO (parasti D1 → GPIO5)
const int dscClockPinDefault = 5;

// DSC Read datu GPIO (parasti D2 → GPIO4)
const int dscReadPinDefault = 4;

// DSC Write datu GPIO (parasti D8 → GPIO15)
const int dscWritePinDefault = 15;

// ==============================
// System Limits
// ==============================

// Maksimālais zonu skaits (16 vai līdz 64, atkarībā no paneļa)
const int maxZonesDefault = 16;

// Maksimālais releju (PGM) skaits
const int maxRelays = 4;
