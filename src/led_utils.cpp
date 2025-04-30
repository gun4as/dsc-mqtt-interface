#include <Arduino.h>
#include "led_utils.h"

const int ledPin = 15;
LedStatus currentStatus = LED_OK;
unsigned long previousMillis = 0;
bool ledState = LOW;
int blinkInterval = 0;

void initLed() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW); // Iespējams, HIGH = izslēgts uz ESP8266
}

void setLedStatus(LedStatus status) {
    currentStatus = status;
    previousMillis = 0;
}

void updateLed() {
    unsigned long currentMillis = millis();

    switch (currentStatus) {
        case LED_NETWORK_DISCONNECTED: blinkInterval = 100; break;
        case LED_MQTT_DISCONNECTED: blinkInterval = 500; break;
        case LED_CONFIG_MODE:       blinkInterval = 1000; break;
        case LED_OK:
            digitalWrite(ledPin, LOW); // Izslēgts
            return;
    }

    if (currentMillis - previousMillis >= blinkInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(ledPin, ledState ? HIGH : LOW);  // Uz ESP8266 LOW = ieslēgts
    }
}
