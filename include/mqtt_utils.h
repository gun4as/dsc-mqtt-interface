// mqtt_utils.h
#ifndef MQTT_UTILS_H
#define MQTT_UTILS_H

#include <Arduino.h>

void mqttCallback(char * topic, byte * payload, unsigned int length);
void mqttHandle();
bool mqttConnect();
void mqttPublish(const char * publishTopic,const char * value);
void mqttPublish(const char * topic,const char * suffix,const char * value);
void mqttPublish(const char * topic,const char * suffix, bool bvalue);
void mqttPublish(const char * topic,const char * suffix, byte srcNumber,const char * value);
void mqttPublish(const char * topic,const char * suffix, byte srcNumber, bool bvalue);
void mqttPublish(const char * topic, byte srcNumber, bool bvalue);

bool setupMqtt();

#endif