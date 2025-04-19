#ifndef CONFIG_H
#define CONFIG_H

// Noklusējuma konfigurācijas vērtības, kas tiek izmantotas, ja config.json nav pieejams vai ir bojāts
#define DEFAULT_MQTT_SERVER "192.168.4.2"
#define DEFAULT_MQTT_PORT 1883
#define DEFAULT_MQTT_USERNAME "mqtt"
#define DEFAULT_MQTT_PASSWORD ""
#define DEFAULT_ACCESS_CODE "1234"
#define DEFAULT_PARTITION 8
#define DEFAULT_PRIMARY_PARTITION 1
#define DEFAULT_ZONES 64
#define DEFAULT_RELAYS 4
#define DEFAULT_DEBUG 1
#define DEFAULT_EXPANDER1 0
#define DEFAULT_EXPANDER2 0
#define DEFAULT_USE_DHCP true
#define DEFAULT_STATIC_IP "192.168.4.1"
#define DEFAULT_GATEWAY "192.168.4.1"
#define DEFAULT_SUBNET "255.255.255.0"
#define DEFAULT_DNS "8.8.8.8"
#define DEFAULT_WEB_USERNAME "admin"
#define DEFAULT_WEB_PASSWORD "admin"

#define ARDUINO_MQTT
#define DEBUG 1


#endif // CONFIG_H