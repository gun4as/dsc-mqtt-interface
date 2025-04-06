#ifndef config_h
#define config_h

extern const char * wifiSSID;
extern const char * wifiPassword;
extern const char * accessCode;
extern const char * otaAccessCode;
extern const char * mqttServer;
extern const char * mqttUsername;
extern const char * mqttPassword;
extern const int mqttPort;

extern const int defaultPartition ;
extern const int expanderAddr1 ;
extern const int expanderAddr2 ;
extern const int Ddebug ;

// Hardware Pins
extern const int dscClockPinDefault;
extern const int dscReadPinDefault;
extern const int dscWritePinDefault;

// System Limits
extern const int maxZonesDefault;
extern const int maxRelays;

#endif