#ifndef LED_UTILS_H
#define LED_UTILS_H

enum LedStatus {
    LED_NETWORK_DISCONNECTED,
    LED_MQTT_DISCONNECTED,
    LED_CONFIG_MODE,
    LED_OK
};

void initLed();
void setLedStatus(LedStatus status);
void updateLed();

#endif
