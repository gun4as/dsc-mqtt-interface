//for project documenation visit https://github.com/Dilbert66/esphome-dsckeybus
#ifndef dscAlarm_h
#define dscAlarm_h
#pragma once

#include "dscKeybus.h"
#include "Arduino.h"
#include <string>
#include "config.h"


extern dscKeybusInterface dsc;
extern bool forceDisconnect;

void disconnectKeybus();

const char mm0[] PROGMEM = "Nospiediet #: lai izietu";
const char mm1[] PROGMEM = "Zonu apiešana";
const char mm2[] PROGMEM = "Sistēmas problēmas";
const char mm3[] PROGMEM = "Signalizācijas atmiņa";
const char mm4[] PROGMEM = "Durvju zvaniņš";
const char mm5[] PROGMEM = "Piekļuves kodi";
const char mm6[] PROGMEM = "Lietotāja funkcijas";
const char mm7[] PROGMEM = "Izvades kontakts";
const char mm8[] PROGMEM = " ";
const char mm9[] PROGMEM = "Bez ieejas aizsardzība";
const char mm10[] PROGMEM = "Ātrā aizsardzība";

const char om0[] PROGMEM = "Nospiediet #: lai izietu";
const char om1[] PROGMEM = "Izvade 1";
const char om2[] PROGMEM = "Izvade 2";

const char tm0[] PROGMEM = "Nospiediet #: lai izietu";
const char tm1[] PROGMEM = "Nepieciešams serviss *";
const char tm2[] PROGMEM = "AC barošanas traucējumi";
const char tm3[] PROGMEM = "Tālruņa līnijas problēma";
const char tm4[] PROGMEM = "Saziņas kļūda";
const char tm5[] PROGMEM = "Zonas kļūda *";
const char tm6[] PROGMEM = "Zonas sabojāšana *";
const char tm7[] PROGMEM = "Zema baterija *";
const char tm8[] PROGMEM = "Sistēmas laiks";

const char sm0[] PROGMEM = "Nospiediet #: lai izietu";
const char sm1[] PROGMEM = "Zema baterija";
const char sm2[] PROGMEM = "Zvanu ķēdes kļūda";
const char sm3[] PROGMEM = "Sistēmas problēma";
const char sm4[] PROGMEM = "Sistēmas sabojāšana";
const char sm5[] PROGMEM = "Moduļa uzraudzība";
const char sm6[] PROGMEM = "RF traucējumi atklāti";
const char sm7[] PROGMEM = "PC5204 zema baterija";
const char sm8[] PROGMEM = "PC5204 AC kļūme";

const char um0[] PROGMEM = "Nospiediet #: lai izietu";
const char um1[] PROGMEM = "Laiks un datums";
const char um2[] PROGMEM = "Auto aizsardzība/atbruņošana";
const char um3[] PROGMEM = "Auto aizsardzības laiks";
const char um4[] PROGMEM = "Sistēmas tests";
const char um5[] PROGMEM = "Serviss/DLS režīms";
const char um6[] PROGMEM = "Notikumu žurnāls";

const char am0[] PROGMEM = " ";
const char am1[] PROGMEM = " ";
const char am2[] PROGMEM = "Sistēmas kļūme:(*2) skatīt";
const char am3[] PROGMEM = "Apiešana aktīva:(*1) skatīt";
const char am4[] PROGMEM = "Signalizācijas atmiņa:(*3) skatīt";
const char am5[] PROGMEM = "Atvērtas zonas: Ritiniet, lai skatītu <>";

const char ml0[] PROGMEM = "Sistēma ir gatava: Gatava aizsardzībai <>";
const char ml1[] PROGMEM = "Drošiniet sistēmu: Pirms aizsardzības <>";

const char STATUS_PENDING[] PROGMEM = "pending";
const char STATUS_ARM[] PROGMEM = "armed_away";
const char STATUS_STAY[] PROGMEM = "armed_home";
const char STATUS_NIGHT[] PROGMEM = "armed_night";
const char STATUS_OFF[] PROGMEM = "disarmed";
const char STATUS_ONLINE[] PROGMEM = "online";
const char STATUS_OFFLINE[] PROGMEM = "offline";
const char STATUS_TRIGGERED[] PROGMEM = "triggered";
const char STATUS_READY[] PROGMEM = "ready";
const char STATUS_NOT_READY[] PROGMEM = "not_ready"; //ha alarm panel likes to see "unavailable" instead of not_ready when the system can't be armed

const char *
  const mainMenu[] PROGMEM = {
    mm0,
    mm1,
    mm2,
    mm3,
    mm4,
    mm5,
    mm6,
    mm7,
    mm8,
    mm9,
    mm10
  };
const char *
  const outputMenu[] PROGMEM = {
    om0,
    om1,
    om2
  };
const char *
  const troubleMenu[] PROGMEM = {
    tm0,
    tm1,
    tm2,
    tm3,
    tm4,
    tm5,
    tm6,
    tm7,
    tm8
  };
const char *
  const serviceMenu[] PROGMEM = {
    sm0,
    sm1,
    sm2,
    sm3,
    sm4,
    sm5,
    sm6,
    sm7,
    sm8
  };
const char *
  const userMenu[] PROGMEM = {
    um0,
    um1,
    um2,
    um3,
    um4,
    um5,
    um6
  };
const char *
  const statusMenu[] PROGMEM = {
    am0,
    am1,
    am2,
    am3,
    am4,
    am5
  };
const char *
  const statusMenuLabels[] PROGMEM = {
    ml0,
    ml1
  };
enum panelStatus {
  acStatus,
  batStatus,
  trStatus,
  fireStatus,
  panicStatus,
  rdyStatus,
  armStatus,
  chimeStatus
};

class DSCkeybushome { 
  public: DSCkeybushome(byte dscClockPin = 0, byte dscReadPin = 0, byte dscWritePin = 0): dscClockPin(dscClockPin),
  dscReadPin(dscReadPin),
  dscWritePin(dscWritePin) {  
  }
  std:: function < void(uint8_t, bool) > zoneStatusChangeCallback;
  std:: function < void(std::string ) > systemStatusChangeCallback;
  std:: function < void(panelStatus, bool, int) > panelStatusChangeCallback;
  std:: function < void(bool, int) > fireStatusChangeCallback;
  std::function  <void (std::string,int)> partitionStatusChangeCallback;   
  std:: function < void(std::string, int) > partitionMsgChangeCallback;
  std:: function < void(std::string) > zoneMsgStatusCallback;
  std:: function < void(std::string) > troubleMsgStatusCallback;
  std:: function < void(uint8_t, bool) > relayChannelChangeCallback;
  std:: function < void(std::string, int) > line1DisplayCallback;
  std:: function < void(std::string, int) > line2DisplayCallback;
  std:: function < void(std::string) > eventInfoCallback;
  std:: function < void(std::string, int) > lightsCallback;
  std:: function < void(std::string, int) > beepsCallback;

  void onZoneStatusChange(std:: function < void(uint8_t zone, bool isOpen) > callback) {
    zoneStatusChangeCallback = callback;
  }
  void onSystemStatusChange(std:: function < void(std::string  status) > callback) {
    systemStatusChangeCallback = callback;
  }
  void onFireStatusChange(std:: function < void(bool isOpen,int partition) > callback) {
    fireStatusChangeCallback = callback;
  }
  void onPanelStatusChange(std:: function < void(panelStatus ts, bool isOpen, int partition) > callback) {
    panelStatusChangeCallback = callback;
  }
  void onPartitionStatusChange(std:: function < void(std::string status, int partition) > callback) {
    partitionStatusChangeCallback = callback;
  }
  void onPartitionMsgChange(std::function<void (std::string msg,uint8_t partition)> callback) {
    partitionMsgChangeCallback = callback; 
  }  
  void onZoneMsgStatus(std:: function < void(std::string msg) > callback) {
    zoneMsgStatusCallback = callback;
  }
  void onTroubleMsgStatus(std:: function < void(std::string msg) > callback) {
    troubleMsgStatusCallback = callback;
  }
  void onRelayChannelChange(std:: function < void(uint8_t channel, bool state) > callback) {
    relayChannelChangeCallback = callback;
  }

  void onLine1Display(std:: function < void(std::string msg, int partition) > callback) {
    line1DisplayCallback = callback;
  }
  void onLine2Display(std:: function < void(std::string msg, int partition) > callback) {
    line2DisplayCallback = callback;
  }
  void onEventInfo(std:: function < void(std::string msg) > callback) {
    eventInfoCallback = callback;
  }
  void onLights(std:: function < void(std::string msg, int partition) > callback) {
    lightsCallback = callback;
  }
  void onBeeps(std:: function < void(std::string beep, int partition) > callback) {
    beepsCallback = callback;
  }
  
  void set_accessCode(const char * ac) { accessCode=ac; }
  void set_maxZones(int mz) {maxZones=mz;}
  void set_userCodes(const char * uc) { userCodes=uc;}
  void set_defaultPartition(uint8_t dp) {defaultPartition=dp;}  
  void set_debug(uint8_t db) {debug=db;}  
  void set_expanderAddr(uint8_t idx,uint8_t addr) { if (idx==1) expanderAddr1=addr; else if (idx==2) expanderAddr2=addr;}

  int activePartition = 1;
  unsigned long cmdWaitTime;
  bool extendedBufferFlag=false;
  bool troubleFetch=false;

  private: 
  
  byte debug;
  const char * accessCode;
  const char * userCodes;
  byte maxZones = maxZonesDefault; 
  int defaultPartition = 1;
  
  uint8_t expanderAddr1=0;
  uint8_t expanderAddr2=0;
  uint8_t zone;
  byte dscClockPin,
  dscReadPin,
  dscWritePin;
  bool firstrun;
  bool options;
  unsigned long beepTime,
  eventTime;

  struct partitionType {
    unsigned long keyPressTime;
    byte lastStatus;
    byte status;
    byte digits;
    byte editIdx;
    byte currentSelection;
    byte selectedZone;
    byte locked:1;    
    byte inprogram:1;    
    byte decimalInput:1;
    byte hex:1;
    byte eventViewer:1;
    byte submitted:1;  
    byte newData:1;
    byte hexMode:1;
    byte chime:1;
    byte armedAway:1;
    byte armedStay:1;
    byte armedNight:1;
    byte armed:1;
    byte disabled:1;
    byte ready:1;
    byte exitdelay:1;
    byte fire:1;
    byte alarm:1;
  };

  struct zoneType {
    byte partition;
    byte tamper:1;
    byte batteryLow:1;
    byte open:1;
    byte alarm:1;
    byte enabled:1;
    byte bypassed:1;
  };

  public:
  zoneType * zoneStatus;
  partitionType partitionStatus[dscPartitions];
  bool forceRefresh;
  std::string previousZoneStatusMsg,eventStatusMsg; 
  
  private:
  byte  lastStatus[dscPartitions];  
  bool relayStatus[16],
  previousRelayStatus[16];
  bool sendCmd,system0Changed,system1Changed;
  byte system0,
  system1,previousSystem0,previousSystem1;
  byte programZones[dscZones];
  char decimalInputBuffer[6];
  byte line2Digit,
  line2Status;
  byte beeps,
  previousBeeps;
  bool refresh;
 
public:
void begin() {
    
    eventStatusMsg.reserve(64);
    zoneStatus = new zoneType[maxZones];
    
    if (debug > 2)
      Serial.begin(115200);
    firstrun = true;
    systemStatusChangeCallback(String(FPSTR(STATUS_OFFLINE)).c_str());
    forceDisconnect = false;
    #ifdef MODULESUPERVISION
    #endif
#if not defined(DISABLE_EXPANDER)      
    dsc.addModule(expanderAddr1);
    dsc.addModule(expanderAddr2);
#endif    
    dsc.maxZones = maxZones;
    dsc.resetStatus();
    dsc.processModuleData = true;
    if (dscClockPin && dscReadPin && dscWritePin)
      dsc.begin(Serial, dscClockPin, dscReadPin, dscWritePin);
    else
      dsc.begin(Serial);
    for (int x = 0; x < maxZones; x++) {
      zoneStatus[x].tamper = false;
      zoneStatus[x].batteryLow = false;
      zoneStatus[x].open = false;
      zoneStatus[x].alarm = false;
      zoneStatus[x].enabled = false;
      zoneStatus[x].partition = 0;
      zoneStatus[x].bypassed = false;
    } 
    for (int p = 0; p<dscPartitions;p++) {
        partitionStatus[p].editIdx=0;
        partitionStatus[p].digits=0;
        beepsCallback("0", p+1);    
        partitionMsgChangeCallback("",p+1);
        line1DisplayCallback("ESP Modulis Startējas", p+1);    
        line2DisplayCallback("", p+1);
    }
    for (int x=0;x<dscZones;x++)
        programZones[x]=0;

    system1 = 0;
    system0 = 0;
    troubleMsgStatusCallback("");
    eventInfoCallback("ESP modulis startējas");  
    zoneMsgStatusCallback("");
  }
 private: 

std::string getZoneName(int zone) {
  std::string name;
  // ... (oriģinālā koda loģika, kas aizpilda 'name')
  return name;
}

  std::string getUserName(char * code) {
  std::string name = code;  
  if (userCodes  && *userCodes) {
    std::string s=userCodes;
    std::string token1, token2, token3;
    size_t pos, pos1;
    s.append(",");
    while ((pos = s.find(',')) != std::string::npos) {
      token1 = s.substr(0, pos); // store the substring   
      pos1 = token1.find(':');
      token2 = token1.substr(0, pos1);
      token3 = token1.substr(pos1 + 1);
      if (token2 == code) {
        name = token3;
        break;
      }
      s.erase(0, pos + 1); /* erase() function store the current positon and move to next token. */
    }
  }
  return name;
}
public:
  void set_default_partition(int partition) {
    if (partition > 0 && partition < dscPartitions) {
      defaultPartition = partition;
      dsc.currentDefaultPartition = partition;
    }
  }

void set_zone_fault(int zone, bool fault) {
#if not defined(DISABLE_EXPANDER) 
    Serial.printf("Setting Zone Fault: %d,%d\n", zone, fault);
    dsc.setZoneFault(zone, fault);    
#endif
  }

  void alarm_disarm(std::string code) {   
    set_alarm_state("D", code, defaultPartition);
  }

  void alarm_arm_home() {
    set_alarm_state("S", "", defaultPartition);
  }

  void alarm_arm_night(std::string code) {
    set_alarm_state("N", code, defaultPartition);
  }

  void alarm_arm_away() {
    set_alarm_state("A", "", defaultPartition);
  }

  void alarm_trigger_fire() {
    set_alarm_state("F", "", defaultPartition);
  }

  void alarm_trigger_panic() {
    set_alarm_state("P", "", defaultPartition);
  }

private:
  void processMenu(byte key, byte partition = -1) {
    if (partition < 1) partition = defaultPartition;
    byte * currentSelection = & partitionStatus[partition - 1].currentSelection;
    if (partitionStatus[partition - 1].locked) {
      line1DisplayCallback(String(F("Sistēma")).c_str(), partition);
      line2DisplayCallback(String(F("nav piejama")).c_str(), partition);
      return;
    }

    if (partitionStatus[partition - 1].digits > 0) { //program mode data input 
      String tpl=F("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
      if (dsc.status[partition - 1] == 0xAA) { //time entry
        tpl = F("XXXX    XXXXXX  XXXXXXXXXXXXXXXX");
      }
      if (dsc.status[partition - 1] == 0xAB) { //time entry
        tpl = F("XXXX                            ");
      }      
      if (key == '#') {
        partitionStatus[partition - 1].newData = false;
        if (key == '#' && partitionStatus[partition - 1].hex) {
          dsc.setLCDSend(partition, (partitionStatus[partition - 1].digits > 8));
        } else {
          dsc.write(key, partition);
        }
        return;

      } else if (key == '>') {
        getNextIdx(tpl.c_str(), partition);
        if (!partitionStatus[partition - 1].hex && partitionStatus[partition - 1].editIdx == 0) {
          dsc.setLCDSend(partition);
          partitionStatus[partition - 1].newData = false;
          return;
        }
      } else if (key == '<') {
        getPrevIdx(tpl.c_str(), partition);
      } else if (key != '*') {
        if (partitionStatus[partition - 1].decimalInput) {
          int num;
          decimalInputBuffer[partitionStatus[partition - 1].editIdx] = key;
          sscanf(decimalInputBuffer, "%d", & num);
          dsc.pgmBuffer.data[0] = num;
          //convert data to int and store it to data[0];
        } else {
            //skip every 5th byte since it's a checksum
          byte y = (partitionStatus[partition - 1].editIdx / 2) + (partitionStatus[partition - 1].editIdx/8);
          char k = key - 48;
          if (partitionStatus[partition - 1].hexMode) {
            if (k < 6)
              k += 10;
            else
              return;
          }
          if (partitionStatus[partition - 1].editIdx % 2)
            dsc.pgmBuffer.data[y] = (dsc.pgmBuffer.data[y] & 0xF0) | k;
          else
            dsc.pgmBuffer.data[y] = (dsc.pgmBuffer.data[y] & 0x0F) | (k << 4);
        }
        getNextIdx(tpl.c_str(), partition);
        if (!partitionStatus[partition - 1].hex && partitionStatus[partition - 1].editIdx == 0) {
          dsc.setLCDSend(partition);
          partitionStatus[partition - 1].newData = false;
          return;
        }

      } else if (key == '*') {
        if (partitionStatus[partition - 1].hex) {
          partitionStatus[partition - 1].hexMode = partitionStatus[partition - 1].hexMode ? false : true;
        } else {
          dsc.write(key, partition);
          return;
        }
      }
      dsc.write("$", partition); //place holder character . 
      setStatus(partition - 1, true);
      return;
    }
    if (key == '#') {
      * currentSelection = 0xFF;
      partitionStatus[partition - 1].selectedZone = 0;
      dsc.write(key, partition);
      partitionStatus[partition - 1].eventViewer = false;
      activePartition = 1;
      setStatus(partition - 1, true);
      return;
    }
    if (dsc.status[partition - 1] < 0x04) {
      if (dsc.keybusVersion1) { //older versions don't support top level navigation 
        if (key == '<' || key == '>') return;
      } else {
        if (key == '<') {
          getPreviousMainOption(partition);
        } else
        if (key == '>') {
          getNextMainOption(partition);
        };
      }
      dsc.write(key, partition);
      setStatus(partition - 1, true);
    } else if (dsc.status[partition - 1] == 0x9E) { // * mainmenu
      if (key == '<') {
        * currentSelection = * currentSelection >= 11 ? 10 : ( * currentSelection > 0 ? * currentSelection - 1 : 10);
        if (*currentSelection == 8) *currentSelection-=1; //skip empty item
        if ( * currentSelection < 11)
          line2DisplayCallback(String(FPSTR(mainMenu[ * currentSelection])).c_str(), partition);
      } else if (key == '>') {
        * currentSelection = * currentSelection >= 10 ? 0 : * currentSelection + 1;
        if (*currentSelection == 8) *currentSelection+=1;
        if ( * currentSelection < 11)
          line2DisplayCallback(String(FPSTR(mainMenu[ * currentSelection])).c_str(), partition);
      } else if (key == '*' && * currentSelection > 0) {
        dsc.write(key, partition);
        char s[5];
        sprintf(s, "%d", * currentSelection % 10);
        //const char * out = strcpy(new char[3], s);
        * currentSelection = 0xFF;
        dsc.write(s, partition);
      } else {
        dsc.write(key, partition);
        * currentSelection = 0xFF;
      }
    } else if (dsc.status[partition - 1] == 0xA1) { //trouble
      if (key == '*' && * currentSelection > 0) {
        char s[5];
        sprintf(s, "%d", * currentSelection);
       // const char * out = strcpy(new char[3], s);
        * currentSelection = 0xFF;
        dsc.write(s, partition);
      } else if (key == '>') {
        * currentSelection = getNextOption( * currentSelection);
        if ( * currentSelection < 9)
          line2DisplayCallback(String(FPSTR(troubleMenu[ * currentSelection])).c_str(), partition);
      } else if (key == '<') {
        * currentSelection = getPreviousOption( * currentSelection);
        if ( * currentSelection < 9)
          line2DisplayCallback(String(FPSTR(troubleMenu[ * currentSelection])).c_str(), partition);
      } else {
        * currentSelection = 0xFF;
        dsc.write(key, partition);
      }
    } else if (dsc.status[partition - 1] == 0xC8) { //service
      if (key == '*' && * currentSelection > 0) {
        char s[5];
        sprintf(s, "%d", * currentSelection);
        //const char * out = strcpy(new char[3], s);
        * currentSelection = 0xFF;
        dsc.write(s, partition);
      } else if (key == '>') {
        * currentSelection = getNextOption( * currentSelection);
        if ( * currentSelection < 9)
          line2DisplayCallback(String(FPSTR(serviceMenu[ * currentSelection])).c_str(), partition);
      } else if (key == '<') {
        * currentSelection = getPreviousOption( * currentSelection);
        if ( * currentSelection < 9)
          line2DisplayCallback(String(FPSTR(serviceMenu[ * currentSelection])).c_str(), partition);
      } else {
        * currentSelection = 0xFF;
        dsc.write(key, partition);
      }
    } else if (dsc.status[partition - 1] == 0xA9 && !partitionStatus[partition - 1].eventViewer) { // * user functions
      if (key == '<') {
        * currentSelection = * currentSelection >= 7 ? 6 : ( * currentSelection > 0 ? * currentSelection - 1 : 6);
        if ( * currentSelection < 7)
          line2DisplayCallback(String(FPSTR(userMenu[ * currentSelection])).c_str(), partition);
      } else if (key == '>') {
        * currentSelection = * currentSelection >= 6 ? 0 : * currentSelection + 1;
        if ( * currentSelection < 7)
          line2DisplayCallback(String(FPSTR(userMenu[ * currentSelection])).c_str(), partition);
      } else if (key == '*' && * currentSelection > 0) {
        char s[5];
        if ( * currentSelection == 6) { //event viewer. 
          partitionStatus[partition - 1].eventViewer = true;
          activePartition = partition;
          dsc.write('b', partition);
        } else {
          sprintf(s, "%d", * currentSelection % 6);
          //const char * out = strcpy(new char[3], s);
          * currentSelection = 0xFF;
          dsc.write(s, partition);
        }
      } else {
        dsc.write(key, partition);
        * currentSelection = 0xFF;
      }
    } else if (dsc.status[partition - 1] == 0xA2) { //alarm memory
      if (key == '>') {
        * currentSelection = getNextOption( * currentSelection);
        dsc.write(key, partition);
      } else if (key == '<') {
        * currentSelection = getPreviousOption( * currentSelection);
        dsc.write(key, partition);
      } else {
        * currentSelection = 0xFF;
        dsc.write(key, partition);
      }
    } else if (dsc.status[partition - 1] == 0xA6) { //user codes
      if (key == '*') {
        char s[5];
        sprintf(s, "%02d", * currentSelection);
        //const char * out = strcpy(new char[3], s);
        dsc.write(s, partition);
      } else if (key == '>') {
        * currentSelection = getNextUserCode( * currentSelection);
        dsc.write(key, partition);
      } else if (key == '<') {
        * currentSelection = getPreviousUserCode( * currentSelection);
        dsc.write(key, partition);
      } else {
        * currentSelection = 0xFF;
        dsc.write(key, partition);
      }
      setStatus(partition - 1, true);
    } else if (dsc.status[partition - 1] == 0x11) { //alarms
      if (key == '>') {
        * currentSelection = getNextAlarmedZone( * currentSelection, partition);
        dsc.write(key, partition);
      } else if (key == '<') {
        * currentSelection = getPreviousAlarmedZone( * currentSelection, partition);
        dsc.write(key, partition);
      } else {
        * currentSelection = 0xFF;
        dsc.write(key, partition);
      }
      setStatus(partition - 1, true);
    } else if (dsc.status[partition - 1] == 0xA0) { //bypass
      if (key == '*') {
        char s[5];
        sprintf(s, "%02d", * currentSelection);
        //const char * out = strcpy(new char[3], s);
        dsc.write(s, partition);
      } else if (key == '>') {
        * currentSelection = getNextEnabledZone( * currentSelection, partition);
        dsc.write(key, partition);
      } else if (key == '<') {
        * currentSelection = getPreviousEnabledZone( * currentSelection, partition);
        dsc.write(key, partition);
      } else {
        * currentSelection = 0xFF;
        dsc.write(key, partition);
      }
      setStatus(partition - 1, true);
    } else if (dsc.status[partition - 1] == 0xB2) { //output control
      if (key == '<') {
        * currentSelection = * currentSelection >= 3 ? 2 : ( * currentSelection > 0 ? * currentSelection - 1 : 2);
        if ( * currentSelection < 3)
          line2DisplayCallback(String(FPSTR(outputMenu[ * currentSelection])).c_str(), partition);
        dsc.write(key, partition);
      } else if (key == '>') {
        * currentSelection = * currentSelection >= 2 ? 0 : * currentSelection + 1;
        if ( * currentSelection < 3)
          line2DisplayCallback(String(FPSTR(outputMenu[ * currentSelection])).c_str(), partition);
        dsc.write(key, partition);
      } else if (key == '*' && * currentSelection > 0) {
        char s[5];
        sprintf(s, "%d", * currentSelection);
       // const char * out = strcpy(new char[3], s);
        * currentSelection = 0xFF;
        dsc.write(s, partition);
      } else {
        * currentSelection = 0xFF;
        dsc.write(key, partition);
      }
      setStatus(partition - 1, true);
    }  else  {
      dsc.write(key, partition);
      setStatus(partition - 1, false);
    }
  }

  void getPrevIdx(const char * tpl, byte partition) {
    int count = 0;
    do {
      partitionStatus[partition - 1].editIdx = partitionStatus[partition - 1].editIdx > 0 ? partitionStatus[partition - 1].editIdx - 1 : partitionStatus[partition - 1].digits - 1;
      count++;
     //  byte b = (partitionStatus[partition - 1].editIdx / 2) + (partitionStatus[partition - 1].editIdx % 2);  
    } while (tpl[partitionStatus[partition - 1].editIdx] != 'X' && count <= partitionStatus[partition - 1].digits);
  }

  void getNextIdx(const char * tpl, byte partition) {
    int count = 0;
    do {
      partitionStatus[partition - 1].editIdx = partitionStatus[partition - 1].editIdx + 1 < partitionStatus[partition - 1].digits ? partitionStatus[partition - 1].editIdx + 1 : 0;
      count++;
       //byte b = (partitionStatus[partition - 1].editIdx / 2) + (partitionStatus[partition - 1].editIdx % 2);  
    } while (tpl[partitionStatus[partition - 1].editIdx] != 'X' && count <= partitionStatus[partition - 1].digits);
  }

public:
  void alarm_keypress(std::string keystring) {
    alarm_keypress_partition(keystring, defaultPartition);
  }

  void alarm_keypress_partition(std::string keystring, int partition) {
    if (!partition) partition = defaultPartition;
    if (debug > 0) Serial.printf("Writing keys: %s to partition %d, partition disabled: %d , partition locked: %d\n", keystring.c_str(), partition,dsc.disabled[partition - 1],partitionStatus[partition-1].locked);  
    if (dsc.disabled[partition - 1]) return;
    const char * keys = strcpy(new char[keystring.length() + 1], keystring.c_str()); 
    partitionStatus[partition - 1].keyPressTime = millis();
    if (keystring.length() == 1) {
      processMenu(keys[0], partition);
    } else {
        if (!partitionStatus[partition-1].locked) dsc.write(keys, partition);
    }
  }
private:

  bool isInt(std::string s, int base) {
    if (s.empty() || std::isspace(s[0])) return false;
    char * p;
    strtol(s.c_str(), & p, base);
    return ( * p == 0);
  }
public:
  void set_alarm_state(std::string state, std::string code = "", int partition = 0) {
    if (code.length() != 4 || !isInt(code, 10)) code = ""; // ensure we get a numeric 4 digit code
    const char * alarmCode = strcpy(new char[code.length() + 1], code.c_str());
    if (!partition) partition = defaultPartition;
    Serial.printf("Setting Alarm state: %s to partition %d\n",state.c_str(),partition);    
    if (partitionStatus[partition - 1].locked) return;    
    // Arm stay
    if (state.compare("S") == 0 && !dsc.armed[partition - 1] && !dsc.exitDelay[partition - 1]) {      
      dsc.write('s', partition); // Virtual keypad arm stay
    }
    // Arm away
    else if ((state.compare("A") == 0 || state.compare("W") == 0) && !dsc.armed[partition - 1] && !dsc.exitDelay[partition - 1]) {    
      dsc.write('w', partition); // Virtual keypad arm away
    }
    // Arm night  ** this depends on the accessCode setup in the yaml
    else if (state.compare("N") == 0 && !dsc.armed[partition - 1] && !dsc.exitDelay[partition - 1]) {
      //ensure you have the accessCode setup correctly in the yaml for this to work
      dsc.write('n', partition); // Virtual keypad arm away
      if (code.length() == 4 && !isInt(accessCode, 10)) { // if the code is sent and the yaml code is not active use this.
        dsc.write(alarmCode, partition);
      }
    }
    // Fire command
    else if (state.compare("F") == 0) {
      dsc.write('f', partition); // Virtual keypad arm away
    }
    // Panic command
    else if (state.compare("P") == 0) {
      dsc.write('p', partition); // Virtual keypad arm away
    }
    // Disarm
    else if (state.compare("D") == 0 && (dsc.armed[partition-1] || dsc.exitDelay[partition-1])) {
      if (code.length() == 4) { // ensure we get 4 digit code    
        dsc.write(alarmCode, partition);
      }
    }
    partitionStatus[partition-1].keyPressTime = millis();    
  }

private:
  void printPacket(const char * label, char cmd, volatile byte cbuf[], int len) {
    char s1[4];
    char s[70];
    int x=0;
    for (int c = 0; c < len; c++) {
      sprintf(s1, PSTR("%02X "), cbuf[c]);
      memcpy(&s[x],s1,3);
      x+=3;
    }
    s[x]=0;
    if (debug > 0)
        Serial.printf("%s %02X: %s\n",label, cmd, s); 
  }

  byte getPanelBitNumber(byte panelByte, byte startNumber) {
    byte bitCount = 0;
    byte p=defaultPartition;
    for (byte bit = 0; bit <= 7; bit++) {
      if (bitRead(dsc.panelData[panelByte], bit)) {
        p = startNumber + bitCount;
        break;
      }
      bitCount++;
    }
    return p;
  }

  bool getEnabledZonesB1(byte inputByte, byte startZone, byte partition) {
    bool zonesEnabled = false;
    byte zone;
    for (byte panelByte = inputByte; panelByte <= inputByte + 3; panelByte++) {
      if (dsc.panelData[panelByte] != 0) {
        zonesEnabled = true;
        for (byte zoneBit = 0; zoneBit < 8; zoneBit++) {
          zone = (zoneBit + startZone) + ((panelByte - inputByte) * 8) - 1;
          if (zone >= maxZones) continue;
          if (bitRead(dsc.panelData[panelByte], zoneBit)) {
            zoneStatus[zone].partition = partition;               
            zoneStatus[zone].enabled = true;
          } else if (zoneStatus[zone].partition==partition) {
                zoneStatus[zone].enabled = false;
          }
         
        }
      }
    }
    return zonesEnabled;
  }

  bool getEnabledZonesE6(byte inputByte, byte startZone, byte partitionByte) {
    bool zonesEnabled = false;
    byte zone;
    byte partition = getPanelBitNumber(partitionByte, 1) + 1;
    for (byte panelByte = inputByte; panelByte <= inputByte + 3; panelByte++) {
      if (dsc.panelData[panelByte] != 0) {
        zonesEnabled = true;
        for (byte zoneBit = 0; zoneBit < 8; zoneBit++) {
          zone = (zoneBit + startZone) + ((panelByte - inputByte) * 8) - 1;
          if (zone >= maxZones) continue;
          if (bitRead(dsc.panelData[panelByte], zoneBit)) {
            zoneStatus[zone].partition = partition;               
            zoneStatus[zone].enabled = true;
          } else if (zoneStatus[zone].partition==partition) {
                zoneStatus[zone].enabled = false;
          }
        }
      }
    }
    return zonesEnabled;
  }

  String getOptionsString() {

    char s1[4];
    std::string options;
    options = " ";
    byte option;
    for (byte optionGroup = 0; optionGroup < dscZones; optionGroup++) {
      for (byte optionBit = 0; optionBit < 8; optionBit++) {
        option = optionBit + 1 + (optionGroup * 8);
        if (bitRead(programZones[optionGroup], optionBit)) {
          sprintf(s1, "%d", option);
          options.append(s1);
        }
      }
    }
    return options.c_str();
  }

  bool checkUserCode(byte code) {
    byte option, optionGroup;
    bool r=false;
    for (optionGroup = 0; optionGroup < dscZones; optionGroup++) {
      for (byte optionBit = 0; optionBit < 8; optionBit++) {
        option = optionBit + 1 + (optionGroup * 8);
        if (bitRead(programZones[optionGroup], optionBit) && option == code) {
          r=true;
          break;
        }
      }
    }
    return r;
  }

  byte getNextOption(byte start) {
    byte option, optionGroup, s;
    s = start >= maxZones ? 0 : start;
    byte r=0;
    for (optionGroup = 0; optionGroup < dscZones; optionGroup++) {
      for (byte optionBit = 0; optionBit < 8; optionBit++) {
        option = optionBit + 1 + (optionGroup * 8);
        if (bitRead(programZones[optionGroup], optionBit) && option > s) {
            r= option;
            break;
      }
      }
    }
    return r;
  }

  byte getPreviousOption(byte start) {
    byte s;
    s = start >= maxZones || start == 0 ? maxZones : start;
    byte r=0;
    for (int optionGroup = dscZones - 1; optionGroup >= 0 && optionGroup < dscZones; optionGroup--) {
      for (int optionBit = 7; optionBit >= 0 && optionBit < 8; optionBit--) {
        byte option = optionBit + 1 + (optionGroup * 8);
        if (bitRead(programZones[optionGroup], optionBit)) {
          if (option < s){
              r=option;
              break;
          }
        }
      }
    }
    return r;
  }

  byte getNextUserCode(byte start) {
    if (start < 95)
      return start + 1;
    else
      return 1;
  }

  byte getPreviousUserCode(byte start) {
    if (start > 1)
      return start - 1;
    else
      return 95;
  }

  void getPreviousMainOption(byte partition) {

    byte menu = 0;
    byte zone = 0;

    if (partitionStatus[partition - 1].currentSelection > 5) {
      partitionStatus[partition - 1].currentSelection = 0;
      partitionStatus[partition - 1].selectedZone = 0;
      return;
    } else if (partitionStatus[partition - 1].currentSelection == 5) { //open zones
      partitionStatus[partition - 1].selectedZone = getPreviousOpenZone(partitionStatus[partition - 1].selectedZone, partition);
      if (partitionStatus[partition - 1].selectedZone) return;
    } else if (partitionStatus[partition - 1].currentSelection < 2)
      partitionStatus[partition - 1].currentSelection = 6;
    for (int x = partitionStatus[partition - 1].currentSelection; x >= 0; x--) {
      if ((x == 6) && !dsc.armed[partition - 1] && !dsc.armed[partition - 1]) { //openzones
        menu = 5;
        zone = 0;
        break;
      } else if (x == 3 && dsc.lights[partition - 1] & 0x10) { //trouble
        menu = 2;
        zone = 0;
        break;
      } else if (x == 4 && dsc.lights[partition - 1] & 0x08) { //bypass
        menu = 3;
        zone = 0;
        break;
      } else if (x == 5 && getNextAlarmedZone(0, partition)) { //alarms
        menu = 4;
        zone = 0;
        break;
      }
    }
    partitionStatus[partition - 1].currentSelection = menu;
    partitionStatus[partition - 1].selectedZone = zone;
  }

  void clearZoneAlarms(byte partition) {
    for (int zone = 0; zone < maxZones; zone++) {
      if (zoneStatus[zone].partition == partition)
        zoneStatus[zone].alarm = false;
    }
  }

  void clearZoneBypass(byte partition) {
    for (int zone = 0; zone < maxZones; zone++) {
      if (zoneStatus[zone].partition == partition)
        zoneStatus[zone].bypassed = false;
    }
  }

  byte getNextOpenZone(byte start, byte partition) {
    if (start >= maxZones) start = 0;
    byte z=0;
    for (int zone = start; zone < maxZones; zone++) {
      if (zoneStatus[zone].enabled && zoneStatus[zone].partition == partition && zoneStatus[zone].open) {
          z= zone + 1;
          break;
    }
    }
    return z;
  }

  byte getPreviousOpenZone(byte start, byte partition) {
    if (start == 1) return 0;
    byte z=0;
    if (start == 0 || start > maxZones) start = maxZones;
    for (int zone = start - 2; zone >= 0; zone--) {
      if (zoneStatus[zone].enabled && zoneStatus[zone].partition == partition && zoneStatus[zone].open) {
          z= zone + 1;
          break;
      }
    }
    return z;
  }

  void getNextMainOption(byte partition) {

    byte menu = 0;
    byte zone = 0;

    if (partitionStatus[partition - 1].currentSelection > 5) {
      partitionStatus[partition - 1].currentSelection = 0;
      return;
    } else if (partitionStatus[partition - 1].currentSelection == 5) { //open zones
      partitionStatus[partition - 1].selectedZone = getNextOpenZone(partitionStatus[partition - 1].selectedZone, partition);
      if (partitionStatus[partition - 1].selectedZone) return;
    }
    for (int x = partitionStatus[partition - 1].currentSelection; x < 6; x++) {
      if ((x == 0 || x == 1) && dsc.lights[partition - 1] & 0x10) { //trouble
        menu = 2;
        zone = 0;
        break;
      } else if (x == 2 && dsc.lights[partition - 1] & 0x08) { //bypass
        menu = 3;
        zone = 0;
        break;
      } else if (x == 3 && getNextAlarmedZone(0, partition)) { //alarm
        menu = 4;
        zone = 0;
        break;
      } else if (x == 4 && !dsc.armed[partition - 1] && !dsc.armed[partition - 1]) { //open
        menu = 5;
        zone = 0;
        break;
      }
    }
    partitionStatus[partition - 1].currentSelection = menu;
    partitionStatus[partition - 1].selectedZone = zone;
  }

  byte getNextEnabledZone(byte start, byte partition) {
    if (start >= maxZones) start = 0;
    byte z=0;
    for (int zone = start; zone < maxZones; zone++) {
      if (zoneStatus[zone].partition == partition && zoneStatus[zone].enabled) {
         z=zone + 1;
         break;
      }
    }
    return z;
  }

  byte getPreviousEnabledZone(byte start, byte partition) {

    if (start < 2 || start > maxZones) start = maxZones;
    byte z=0;
    for (int zone = start - 2; zone >= 0 && zone < maxZones; zone--) {
      if (zoneStatus[zone].partition == partition && zoneStatus[zone].enabled) {
         z=zone + 1;
         break;
      }
    }
    return z;
  }

  byte getNextAlarmedZone(byte start, byte partition) {
    if (start >= maxZones) start = 0;
    byte z=0;
    for (int zone = start; zone < maxZones; zone++) {
      if (zoneStatus[zone].partition == partition && zoneStatus[zone].alarm) {
         z=zone + 1;
         break;
      }
    }
    return z;
  }

  byte getPreviousAlarmedZone(byte start, byte partition) {
    if (start < 2 || start > maxZones) start = maxZones;
    byte z=0;
    for (int zone = start - 2; zone >= 0 && zone < maxZones; zone--) {
      if (zoneStatus[zone].partition == partition && zoneStatus[zone].alarm) {
         z=zone + 1;
         break;
      }
    }
    return z;
  }

  void getBypassZones(byte partition) {
    for (byte zoneGroup = 0; zoneGroup < dscZones; zoneGroup++) {
      for (byte zoneBit = 0; zoneBit < 8; zoneBit++) {
        zone = zoneBit + (zoneGroup * 8);
        if (!(zoneStatus[zone].partition == partition + 1 && zoneStatus[zone].enabled) || zone >= maxZones) continue;
        if (bitRead(programZones[zoneGroup], zoneBit)) {
          zoneStatus[zone].bypassed = true;
        } else {
          zoneStatus[zone].bypassed = false;
        }
      }
    }
  }

  public:
  void loop()  {

    if (forceDisconnect) return;
    if ((millis() - beepTime > 2000 && beeps > 0)) {
      beeps = 0;
      for (byte partition = 1; partition <= dscPartitions; partition++) {
        if (dsc.disabled[partition - 1]) continue;
        beepsCallback("0", partition);
      }
      beepTime = millis();
    }

    static unsigned long refreshTime;
    if (!firstrun && millis() - refreshTime > 60000 ) {
              refreshTime=millis();
              forceRefresh=true;         
    }
    if ( (dsc.loop() || forceRefresh) && dsc.panelData[0] ) { //Processes data only when a valid Keybus command has been read
 
      static bool delayedStart = true;
      static unsigned long startWait = millis();
      if (millis() - startWait > 60000 && delayedStart) {
        delayedStart = false;
        if (!dsc.disabled[defaultPartition-1] && !partitionStatus[defaultPartition-1].locked && !partitionStatus[defaultPartition-1].armed) {
          partitionStatus[defaultPartition-1].keyPressTime = millis();
          dsc.write("*21#7##", defaultPartition); //fetch panel troubles /zone module low battery
        }
      }

      if (debug > 1) {
        printPacket("Paneldata: ", dsc.panelData[0], dsc.panelData, 16);
        processStatus();
      }
      for (byte partition = 0; partition < dscPartitions; partition++) {
        if (dsc.disabled[partition] || dsc.status[partition] != 0xA0) continue;
        getBypassZones(partition);
        setStatus(partition, true);
      }
    }
    if (!forceDisconnect && ( dsc.statusChanged || forceRefresh) && dsc.panelData[0]) { // Processes data only when a valid Keybus command has been read and statuses were changed
      dsc.statusChanged = false; // Reset the status tracking flag
      if (debug  > 0)
        printPacket("Paneldata: ", dsc.panelData[0], dsc.panelData, 16);
      for (byte partition = 0; partition < dscPartitions; partition++) {
        if (firstrun) {
          beepsCallback("0", partition + 1);
          partitionStatus[partition].chime=0;
          for (int x=1;x<=maxRelays;x++) 
               relayChannelChangeCallback(x, false);
        }
        if (dsc.disabled[partition]) continue;
        setStatus(partition, forceRefresh || dsc.status[partition]==0xEE || dsc.status[partition]==0xA0);
      }
      if (dsc.bufferOverflow) Serial.printf( "Keybus buffer overflow\n");
      dsc.bufferOverflow = false;
      // Checks if the interface is connected to the Keybus
      if (dsc.keybusChanged || forceRefresh ) {
        dsc.keybusChanged = false; // Resets the Keybus data status flag
        if (dsc.keybusConnected) {
          systemStatusChangeCallback( String(FPSTR(STATUS_ONLINE)).c_str());
        } else systemStatusChangeCallback( String(FPSTR(STATUS_OFFLINE)).c_str());
      }
      if (dsc.powerChanged || forceRefresh ) {
        dsc.powerChanged = false;
        if (dsc.powerTrouble) {
          panelStatusChangeCallback(acStatus, false, 0); //no ac
        } else {
            panelStatusChangeCallback(acStatus, true, 0);
        }
      }
      if (dsc.batteryChanged || forceRefresh ) {
        dsc.batteryChanged = false;
        if (dsc.batteryTrouble) {
          panelStatusChangeCallback(batStatus, true, 0);
        } else {
            panelStatusChangeCallback(batStatus, false, 0);
        }
      }
    if (dsc.keypadFireAlarm  ) {
        dsc.keypadFireAlarm = false;
      }

      if (dsc.keypadPanicAlarm  ) {
        dsc.keypadPanicAlarm = false;
      }   
      // Publishes trouble status
      if (dsc.troubleChanged || forceRefresh ) {
        dsc.troubleChanged = false; // Resets the trouble status flag
        if (dsc.trouble) {
            panelStatusChangeCallback(trStatus, true, 0); // Trouble alarm tripped
            if ( troubleFetch && !dsc.disabled[defaultPartition-1] && !partitionStatus[defaultPartition-1].locked) {
            }          
        } else {
            panelStatusChangeCallback(trStatus, false, 0); // Trouble alarm restored
            if (!dsc.disabled[defaultPartition-1] && !partitionStatus[defaultPartition-1].locked && troubleFetch) { 
            }             
        }
      }
      for (byte partition = 0; partition < dscPartitions; partition++) {
        if (dsc.disabled[partition])
            partitionStatus[partition].disabled=true;
         else
             partitionStatus[partition].disabled=false; 
        if (dsc.disabled[partition] || partitionStatus[partition].locked) continue;
         if (lastStatus[partition] != dsc.status[partition]  ) {
				lastStatus[partition]=dsc.status[partition];
				char msg[50];
				sprintf(msg,PSTR("%02X: %s"), dsc.status[partition], String(statusText(dsc.status[partition])).c_str());
				partitionMsgChangeCallback(msg,partition+1);
        } 
        // Publishes alarm status
        if (dsc.alarmChanged[partition] || forceRefresh) {
          dsc.alarmChanged[partition] = false; // Resets the partition alarm status flag
          if (dsc.alarm[partition]) {
            dsc.readyChanged[partition] = false; //if we are triggered no need to trigger a ready state change
            dsc.armedChanged[partition] = false; // no need to display armed changed
            partitionStatusChangeCallback( String(FPSTR(STATUS_TRIGGERED)).c_str(), partition + 1);
            partitionStatus[partition].alarm=true;
          } else
              partitionStatus[partition].alarm=false;
        }
        // Publishes armed/disarmed status
        if (dsc.armedChanged[partition] || forceRefresh ) {
          dsc.armedChanged[partition] = false; // Resets the partition armed status flag
          if (dsc.armed[partition] && !dsc.alarm[partition]) {
            clearZoneAlarms(partition + 1);
            panelStatusChangeCallback(armStatus, true, partition + 1);
            partitionStatus[partition].armed=true;
            if ((dsc.armedAway[partition] || dsc.armedStay[partition]) && dsc.noEntryDelay[partition]) { 
              partitionStatusChangeCallback( String(FPSTR(STATUS_NIGHT)).c_str(), partition + 1);
              partitionStatus[partition].armedStay=false;   
              partitionStatus[partition].armedNight=true;
              partitionStatus[partition].armedAway=false;
              partitionStatus[partition].exitdelay=false;  
            }
            else if (dsc.armedStay[partition] ) {
              partitionStatusChangeCallback( String(FPSTR(STATUS_STAY)).c_str(), partition + 1);
              partitionStatus[partition].armedStay=true;   
              partitionStatus[partition].armedNight=false;
              partitionStatus[partition].armedAway=false;
              partitionStatus[partition].exitdelay=false;              
            } else {
               partitionStatusChangeCallback( String(FPSTR(STATUS_ARM)).c_str(), partition + 1);
              partitionStatus[partition].armedStay=false;   
              partitionStatus[partition].armedNight=false;
              partitionStatus[partition].armedAway=true;
              partitionStatus[partition].exitdelay=false;
            }
          } else if (!dsc.exitDelay[partition] && !dsc.alarm[partition]) {
            if (!forceRefresh) {
                clearZoneBypass(partition + 1);
            } 
              panelStatusChangeCallback(armStatus, false, partition + 1);
              partitionStatus[partition].armed=false;               
              partitionStatus[partition].armedStay=false;   
              partitionStatus[partition].armedNight=false;
              partitionStatus[partition].armedAway=false;  
              partitionStatus[partition].exitdelay=false;   
              partitionStatus[partition].alarm=false;      
          }
        }
        // Publishes exit delay status
        if (dsc.exitDelayChanged[partition] || forceRefresh) {
          dsc.exitDelayChanged[partition] = false; // Resets the exit delay status flag
          if (dsc.exitDelay[partition]) {
              partitionStatus[partition].armed=false;              
              partitionStatusChangeCallback( String(FPSTR(STATUS_PENDING)).c_str(), partition + 1);
              partitionStatus[partition].exitdelay=true;   
              partitionStatus[partition].armedStay=false;   
              partitionStatus[partition].armedNight=false;
              partitionStatus[partition].armedAway=false;  
          } else
              partitionStatus[partition].exitdelay=false;
        } 
    if (dsc.readyChanged[partition]  || forceRefresh) {
          dsc.readyChanged[partition] = false; // Resets the partition alarm status flag
          if (dsc.ready[partition]  && !dsc.exitDelay[partition]) {
            partitionStatusChangeCallback( String(FPSTR(STATUS_OFF)).c_str(), partition + 1);
            panelStatusChangeCallback(rdyStatus, true, partition + 1);
              partitionStatus[partition].ready=true;  
          } else if (!dsc.exitDelay[partition]) {
            if (!dsc.armed[partition] ) {
                partitionStatusChangeCallback( String(FPSTR(STATUS_NOT_READY)).c_str(), partition + 1);
                panelStatusChangeCallback(armStatus, false, partition + 1);
               partitionStatus[partition].exitdelay=false;   
              partitionStatus[partition].armedStay=false;   
              partitionStatus[partition].armedNight=false;
              partitionStatus[partition].armedAway=false;
              partitionStatus[partition].armed=false;    
              partitionStatus[partition].alarm=false;  
            }
            panelStatusChangeCallback(rdyStatus, false, partition + 1);
            partitionStatus[partition].ready=false;                
          }
        }
        // Publishes fire alarm status
        if (dsc.fireChanged[partition] || forceRefresh) {
          dsc.fireChanged[partition] = false; // Resets the fire status flag
          if (dsc.fire[partition]) {
              fireStatusChangeCallback(true, partition + 1); // Fire alarm tripped
               partitionStatus[partition].fire=true;
          } else {
              fireStatusChangeCallback(false,partition + 1); // Fire alarm restored
              partitionStatus[partition].fire=false;             
          }
        }
        if (forceRefresh) {
          panelStatusChangeCallback(chimeStatus, partitionStatus[partition].chime,partition+1);  
        }
      }
      if (dsc.openZonesStatusChanged || forceRefresh) {
        for (byte zoneGroup = 0; zoneGroup < dscZones; zoneGroup++) {
          for (byte zoneBit = 0; zoneBit < 8; zoneBit++) {
            if (bitRead(dsc.openZonesChanged[zoneGroup], zoneBit) || forceRefresh) { // Checks an individual open zone status flag
              bitWrite(dsc.openZonesChanged[zoneGroup], zoneBit, 0); // Resets the individual open zone status flag
              zone = zoneBit + (zoneGroup * 8);
              if (zone >= maxZones) continue;
              if (bitRead(dsc.openZones[zoneGroup], zoneBit)) {
                zoneStatusChangeCallback(zone+1,true);                  
                zoneStatus[zone].open = true;
              } else {
                zoneStatus[zone].open = false;
                zoneStatusChangeCallback(zone+1,false);                 
              }
            }
          }
        }
       }

      std::string zoneStatusMsg;
      zoneStatusMsg = "";
      char s1[7];
      for (int x = 0; x < maxZones; x++) {          
        if (zoneStatus[x].open) {
          sprintf(s1, PSTR("OP:%d"), x + 1);
          if (zoneStatusMsg != "") zoneStatusMsg.append(",");
          zoneStatusMsg.append(s1);
        }
        if (zoneStatus[x].alarm) {
          sprintf(s1, PSTR("AL:%d"), x + 1);
          if (zoneStatusMsg != "") zoneStatusMsg.append(",");
          zoneStatusMsg.append(s1);
        }
        if (zoneStatus[x].bypassed) {
          sprintf(s1, PSTR("BY:%d"), x + 1);
          if (zoneStatusMsg != "") zoneStatusMsg.append(",");
          zoneStatusMsg.append(s1);
        }
        if (zoneStatus[x].tamper) {
          sprintf(s1, PSTR("TA:%d"), x + 1);
          if (zoneStatusMsg != "") zoneStatusMsg.append(",");
          zoneStatusMsg.append(s1);
        }
        if (zoneStatus[x].batteryLow) {
          sprintf(s1, PSTR("BL:%d"), x + 1);
          if (zoneStatusMsg != "") zoneStatusMsg.append(",");
          zoneStatusMsg.append(s1);
        }
      }
      if (zoneStatusMsg != previousZoneStatusMsg || forceRefresh){
        zoneMsgStatusCallback(zoneStatusMsg);
    }
        previousZoneStatusMsg = zoneStatusMsg;
        
        std::string system0Msg="";
        std::string system1Msg="";  
        
     if (system0Changed || system1Changed || forceRefresh) {    
       if (system1Changed) 
           previousSystem1=system1;   
       else
           system1=previousSystem1;
      if (bitRead(system1, 0)) {
        system1Msg.append(String(PSTR("BAT ")).c_str());
        if (system1Changed) {
            dsc.batteryTrouble=true;          
            panelStatusChangeCallback(batStatus, true, 0);
        }
      } else {
          if (system1Changed) {
            dsc.batteryTrouble=false;    
            panelStatusChangeCallback(batStatus, false, 0);
          }
      }  
      if (bitRead(system1, 1)) {
        system1Msg.append(String(PSTR("BELL ")).c_str());
      }
      if (bitRead(system1, 2)) {
        system1Msg.append(String(PSTR("SYS ")).c_str());
      }
      if (bitRead(system1, 3)) {
        system1Msg.append(String(PSTR("TAMP ")).c_str());
      }
      if (bitRead(system1, 4)) {
        system1Msg.append(String(PSTR("SUP ")).c_str());
      }
      if (bitRead(system1, 5)) {
        system1Msg.append(String(PSTR("RF ")).c_str());
      }  
      if (system0Changed) 
          previousSystem0=system0;
        else
          system0=previousSystem0;
      if (bitRead(system0, 1)) {
        system0Msg.append(String(PSTR("AC ")).c_str());
      }
      if (bitRead(system0, 2)) {
        system0Msg.append(String(PSTR("TEL ")).c_str());
      }
      if (bitRead(system0, 3)) {
        system0Msg.append(String(PSTR("COM ")).c_str());
      }
      if (bitRead(system0, 4)) {
        system0Msg.append(String(PSTR("ZF ")).c_str());
      }
      if (bitRead(system0, 5)) {
        system0Msg.append(String(PSTR("ZT ")).c_str());
      }
      if (bitRead(system0, 6)) {
        system0Msg.append(String(PSTR("DBAT ")).c_str());
      }
      if (bitRead(system0, 7)) {
        system0Msg.append(String(PSTR("TIME ")).c_str());
      }
         troubleMsgStatusCallback(system0Msg.append(system1Msg));
     }
     system0Changed=false;
     system1Changed=false;
    }
    if (!forceDisconnect && dsc.handleModule() && dsc.moduleCmd) {
      if (dsc.panelData[0] == 0x41) {
        for (byte zoneByte = 0; zoneByte < 4; zoneByte++) {
          byte zoneBit = 0;
          for (int x = 7; x >= 0; x--) {
            zone = zoneBit + (zoneByte * 8);
            if (zone >= maxZones) continue;
            if (!bitRead(dsc.moduleData[zoneByte + 2], x)) { // Checks an individual zone battery status flag for low
              zoneStatus[zone].batteryLow = true;
            } else if (!bitRead(dsc.moduleData[zoneByte + 6], x)) { // Checks an individual zone battery status flag for restore
              zoneStatus[zone].batteryLow = false;
            }
            zoneBit++;
          }
        }
      }
      if (debug > 1)
        printPacket("Moduledata:", dsc.moduleCmd, dsc.moduleData, 16);
    }
    forceRefresh=false;
    firstrun = false;
  }
  
  void setStatus(byte partition, bool force = false, bool skip = false) {

    if (dsc.status[partition] == partitionStatus[partition].lastStatus && beeps == 0 && !force) return;
    byte * currentSelection = & partitionStatus[partition].currentSelection;
 
    String lcdLine1;
    String lcdLine2;
    options = false;
    partitionStatus[partition].digits = 0;
    partitionStatus[partition].hex = false;
    partitionStatus[partition].decimalInput = false;

    if (debug > 1)     
    Serial.printf("status %02X, last status %02X,line2status %02X,selection %02X,partition=%d,skip=%d,force=%d\n", dsc.status[partition], partitionStatus[partition].lastStatus, line2Status, * currentSelection, partition + 1, skip,force);  
  
    switch (dsc.status[partition]) {
    case 0x01:
      lcdLine1 = F("Partition gatava");
      lcdLine2 = F(" ");
      break;
    case 0x02:
      lcdLine1 = F("Mājās         ");
      lcdLine2 = F("zona atvērta      ");
      break;
    case 0x03:
      lcdLine1 = F("Zonas atvērtas  <>");
      lcdLine2 = F(" ");
      break;
    case 0x04:
      lcdLine1 = F("Ieslēgts:       ");
      lcdLine2 = F("Mājās            ");
      break;
    case 0x05:
      lcdLine1 = F("Ieslēgts:       ");
      lcdLine2 = F("Prom           ");
      break;
    case 0x06:
      lcdLine1 = F("Ieslēgts: Mājas  ");
      lcdLine2 = F("Nav ieejas kavēšanās  ");
      break;
    case 0x07:
      lcdLine1 = F("Failed       ");
      lcdLine2 = F("to arm          ");
      break;
    case 0x08:
      lcdLine1 = F("Izejas aizkave   ");
      lcdLine2 = F("procesā     ");
      break;
    case 0x09:
      lcdLine1 = F("Ieslēdzos:      ");
      lcdLine2 = F("Nav ieejas kavēšanās  ");
      break;
    case 0x0B:
      lcdLine1 = F("Ātra izeja   ");
      lcdLine2 = F("procesā     ");
      break;
    case 0x0C:
      lcdLine1 = F("Ieejas kavēšanās  ");
      lcdLine2 = F("procesā     ");
      break;
    case 0x0D:
      lcdLine1 = F("Ieejas kavēšanās  ");
      lcdLine2 = F("pēc trauksmes     ");
      break;
    case 0x0E:
      lcdLine1 = F("Nav         ");
      lcdLine2 = F("pieejams      ");
      break;
    case 0x10:
      lcdLine1 = F("Keypad       ");
      lcdLine2 = F("lockout         ");
      break;
    case 0x11:
      lcdLine1 = F("Partition in alarm");
      lcdLine2 = F("  ");
      break;
    case 0x12:
      lcdLine1 = F("Battery check");
      lcdLine2 = F("in progress     ");
      break;
    case 0x14:
      lcdLine1 = F("Auto-arm     ");
      lcdLine2 = F("in progress     ");
      break;
    case 0x15:
      lcdLine1 = F("Arming with  ");
      lcdLine2 = F("bypass zones    ");
      break;
    case 0x16:
      lcdLine1 = F("Ieslēgts Away  ");
      lcdLine2 = F("No entry delay  ");
      break;
    case 0x17:
      lcdLine1 = F("Power saving ");
      lcdLine2 = F("Keypad blanked  ");
      break;
    case 0x19:
      lcdLine1 = F("Trauksme       ");
      lcdLine2 = F("occurred        ");
      break;
    case 0x22:
      lcdLine1 = F("Alarms occurred");
      lcdLine2 = F("Press # to exit");
      break;
    case 0x2F:
      lcdLine1 = F("Keypad LCD   ");
      lcdLine2 = F("test            ");
      break;
    case 0x33:
      lcdLine1 = F("Command      ");
      lcdLine2 = F("output active   ");
      break;
    case 0x3D:
      lcdLine1 = F("Trauksme       ");
      lcdLine2 = F("occurred        ");
      break;
    case 0x3E:
      lcdLine1 = F("Izslegts     ");
      lcdLine2 = F(" ");
      
      break;
    case 0x40:
      lcdLine1 = F("Keypad       ");
      lcdLine2 = F("blanked         ");
      break;
    case 0x80:
      lcdLine1 = F("Invalid entry   ");
      lcdLine2 = F("         ");
      break;      
    case 0x8A:
      lcdLine1 = F("Aktīvs     ");
      lcdLine2 = F("stay/away zones ");
      break;
    case 0x8B:
      lcdLine1 = F("Atrā izeja   ");
      lcdLine2 = F(" ");
      break;
    case 0x8E:
      lcdLine1 = F("Invalid      ");
      lcdLine2 = F("option          ");
      break;
    case 0x8F:
      lcdLine1 = F("Invalid      ");
      lcdLine2 = F("access code     ");
      break;
    case 0x9E:
      lcdLine1 = F("Press (*) for <>");
      lcdLine2 = F(" ");
      break;
    case 0x9F:
      lcdLine1 = F("Enter  ");
      lcdLine2 = F("access code   ");
      break;
    case 0xA0:
      lcdLine1 = F("Zone bypass   <>");
      lcdLine2 = F(" ");
      break;
    case 0xA1:
      lcdLine1 = F("Trouble menu     <>    ");
      lcdLine2 = F(" ");
      break;
    case 0xA2:
      lcdLine1 = F("Alarm memory     <> ");
      lcdLine2 = F(" ");
      break;
    case 0xA3:
      lcdLine1 = F("Durvju        ");
      lcdLine2 = F("zvaniņs ieslēgts   ");
      partitionStatus[partition].chime=true;      
      panelStatusChangeCallback(chimeStatus, true, partition+1);       
      break;
    case 0xA4:
      lcdLine1 = F("Durvju        ");
      lcdLine2 = F("zvaniņs   izslēgts");
      partitionStatus[partition].chime=false;        
      panelStatusChangeCallback(chimeStatus, false, partition+1);        
      break;
    case 0xA5:
      lcdLine1 = F("Enter        ");
      lcdLine2 = F("master code     ");
      break;
    case 0xA6:
      lcdLine1 = F("*5:  Access Code");
      lcdLine2 = F("code? (2 digits)");
      break;
    case 0xA7:
      lcdLine1 = F("*5 Enter new ");
      lcdLine2 = F("4-digit code    ");
      partitionStatus[partition].digits = 4;
      break;
    case 0xA9:
      lcdLine1 = F("*6: User functions");
      lcdLine2 = F("function?  ");
      break;
    case 0xAA:
      lcdLine1 = F(" HHMM    MMDDYY   ");
      lcdLine2 = F("");
      partitionStatus[partition].digits = 16;
      break;
    case 0xAB:
      lcdLine1 = F(" HHMM");
      lcdLine2 = F("");
      partitionStatus[partition].digits = 4;
      break;
    case 0xAC:
      lcdLine1 = F("*6:          ");
      lcdLine2 = F("Auto-arm on     ");
      break;
    case 0xAD:
      lcdLine1 = F("*6:          ");
      lcdLine2 = F("Auto-arm off    ");
      break;
    case 0xAF:
      lcdLine1 = F("*6:          ");
      lcdLine2 = F("System test     ");
      break;
    case 0xB0:
      lcdLine1 = F("*6:          ");
      lcdLine2 = F("Enable DLS      ");
      break;
    case 0xB1:
        lcdLine1 = F("*6    ");
        lcdLine2=F("b1 command");
        break;      
    case 0xB2:
    case 0xB3:
      lcdLine1 = F("*7:          ");
      lcdLine2 = F("Command output  ");
      break;      
    case 0xB7:
      lcdLine1 = F("Enter        ");
      lcdLine2 = F("installer code  ");
      break;
    case 0xB8:
      lcdLine1 = F("Enter *      ");
      lcdLine2 = F("function code   ");
      break;
    case 0xB9:
      lcdLine1 = F("Zone Tamper <>");
      lcdLine2 = F(" ");
      break;
    case 0xBA:
      lcdLine1 = F("Zones low battery <>");
      lcdLine2 = F(" ");
      break;
    case 0xBC:
      lcdLine1 = F("*5 Enter new ");
      lcdLine2 = F("6-digit code    ");
      partitionStatus[partition].digits = 6;
      break;
    case 0xBF:
      lcdLine1 = F("Select day:");
      lcdLine2 = F("Sun=1,Tue=2,Sat=7");
      break;
    case 0xC6:
      lcdLine1 = F(" Zone faults  <>");
      lcdLine2 = F(" ");
      break;
    case 0xC7:
      lcdLine1 = F("Partition    ");
      lcdLine2 = F("disabled        ");
      break;
    case 0xC8:
      lcdLine1 = F("Service req.  <>");
      lcdLine2 = F(" ");
      break;
    case 0xCD:
       lcdLine1 = F("Downloading in progress");
       lcdLine2=F(" ");
       break;
    case 0xCE:
      lcdLine1 = F("Active camera");
      lcdLine2 = F("monitor select. ");
      break;
    case 0xD0:
      lcdLine1 = F("*2: Keypads  ");
      lcdLine2 = F("low battery     ");
      break;
    case 0xD1:
      lcdLine1 = F("*2: Keyfobs  ");
      lcdLine2 = F("low battery     ");
      break;
    case 0xD4:
      lcdLine1 = F("*2: Sensors  ");
      lcdLine2 = F("RF Delinquency  ");
      break;
    case 0xE4:
      lcdLine1 = F("*8: Installer menu");
      lcdLine2 = F("Section? ");
      partitionStatus[partition].decimalInput = false;
      break;
    case 0xE5:
      lcdLine1 = F("Keypad       ");
      lcdLine2 = F("slot assignment ");
      break;
    case 0xE6:
      lcdLine1 = F("Input (2 digits)");
      lcdLine2 = F(" ");
      partitionStatus[partition].digits = 2;
      break;
    case 0xE7:
      lcdLine1 = F("Input:       ");
      partitionStatus[partition].digits = 3;
      lcdLine2 = F("3 digits    ");
      partitionStatus[partition].decimalInput = true;
      break;
    case 0xE8:
      lcdLine1 = F("Input:       ");
      partitionStatus[partition].digits = 4;
      lcdLine2 = F("4 digits        ");
      break;
    case 0xE9:
      lcdLine1 = F("Input:       ");
      partitionStatus[partition].digits = 5;
      lcdLine2 = F("5 digits    ");
      break;
    case 0xEA:
      lcdLine1 = F("Input HEX:   ");
      partitionStatus[partition].digits = 2;
      partitionStatus[partition].hex = true;
      lcdLine2 = F("2 digits    ");
      break;
    case 0xEB:
      lcdLine1 = F("Input hex(4dig)");
      partitionStatus[partition].digits = 4;
      partitionStatus[partition].hex = true;
      lcdLine2 = F(" ");
      break;
    case 0xEC:
      lcdLine1 = F("Input hex(6dig)");
      partitionStatus[partition].digits = 6;
      partitionStatus[partition].hex = true;
      lcdLine2 = F(" ");
      break;
    case 0xED:
      lcdLine1 = F("Input HEX:   ");
      partitionStatus[partition].digits = 32;
      partitionStatus[partition].hex = true;
      lcdLine2 = F("32 digits  ");
      break;
    case 0xEE:
      lcdLine1 = F("Input: options     ");
      options = true;
      lcdLine2 = F("option per zone ");
      break;
    case 0xEF:
      lcdLine1 = F("Module       ");
      lcdLine2 = F("supervision   ");
      break;
    case 0xF0:
      lcdLine1 = F("Function     ");
      lcdLine2 = F("key 1      ");
      break;
    case 0xF1:
      lcdLine1 = F("Function     ");
      lcdLine2 = F("key 2        ");
      break;
    case 0xF2:
      lcdLine1 = F("Function     ");
      lcdLine2 = F("key 3       ");
      break;
    case 0xF3:
      lcdLine1 = F("Function     ");
      lcdLine2 = F("key 4      ");
      break;
    case 0xF4:
      lcdLine1 = F("Function     ");
      lcdLine2 = F("key 5           ");
      break;
    case 0xF5:
      lcdLine1 = F("Wireless mod.");
      lcdLine2 = F("placement test  ");
      break;
    case 0xF6:
      lcdLine1 = F("Activate     ");
      lcdLine2 = F("device for test ");
      break;
    case 0xF7:
      lcdLine1 = F("*8: Installer");
      partitionStatus[partition].decimalInput = false;
      partitionStatus[partition].digits = 0;
      lcdLine2 = F("menu, 2 digits  ");
      break;
    case 0xF8:
      lcdLine1 = F("Keypad    ");
      lcdLine2 = F("programming");
      break;
    case 0xFA:
      lcdLine1 = F("Input:   ");
      partitionStatus[partition].digits = 6;
      lcdLine2 = F("6 digits ");
      break;
    default:
      lcdLine2 = dsc.status[partition];
      partitionStatus[partition].digits = 0;
    }
    if (dsc.status[partition] != 0xA9) 
        partitionStatus[partition].eventViewer = false;
    if (partitionStatus[partition].digits == 0)
        partitionStatus[partition].newData = false;
    if (millis() - partitionStatus[partition].keyPressTime > 3000 && dsc.status[partition] > 0x8B) {
      if (!partitionStatus[partition].inprogram) {
        partitionStatus[partition].locked = true;
        partitionStatus[partition].lastStatus = dsc.status[partition];
        return;
      } else
        partitionStatus[partition].locked = false;
    } else if (dsc.status[partition] > 0x8B && !partitionStatus[partition].locked) {
      partitionStatus[partition].inprogram = true;
    }
    if (dsc.status[partition] < 0x8B) {
      partitionStatus[partition].locked = false;
      partitionStatus[partition].inprogram = false;
      activePartition = 1;
    } 
    if (!skip) {
      if (dsc.status[partition] != partitionStatus[partition].lastStatus && !partitionStatus[partition].locked && partitionStatus[partition].digits && !partitionStatus[partition].newData) {
        dsc.setLCDReceive(partitionStatus[partition].digits, partition + 1);
        partitionStatus[partition].editIdx = 0;
        partitionStatus[partition].hexMode = false;
        partitionStatus[partition].newData = true;
        lcdLine1 = F("");
        lcdLine2 = F("");
      } else if (partitionStatus[partition].digits && partitionStatus[partition].newData && dsc.pgmBuffer.dataPending) {
        char s[8];
        if (partitionStatus[partition].digits > 16)
        lcdLine1 =" ";
        lcdLine2 = " ";
        int y;
        char c;
        if (partitionStatus[partition].hexMode) lcdLine1 = F("*");
        if (partitionStatus[partition].decimalInput) {
          if (partitionStatus[partition].digits == 2)
            sprintf(decimalInputBuffer, PSTR("%2d"), dsc.pgmBuffer.data[0]);
          else
            sprintf(decimalInputBuffer, PSTR("%03d"), dsc.pgmBuffer.data[0]);
        }
        for (int x = 0; x < partitionStatus[partition].digits ; x++) { 
          y = (x / 2)  + (x/8); //skip every 5th byte since it's a checksum
          if (partitionStatus[partition].decimalInput)
            c = decimalInputBuffer[x] - 48;
          else
            c = x % 2 ? dsc.pgmBuffer.data[y] & 0x0F : (dsc.pgmBuffer.data[y] & 0xF0) >> 4;
          String tpl = F("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
          if (dsc.status[partition] == 0xAA) {
            tpl = F("XXXX    XXXXXX  XXXXXXXXXXXXXXXX");
          }
          if (dsc.status[partition] == 0xAB) {
            tpl = F("XXXX");
          }          
          if (tpl[x] == 'X') {
            if (x == partitionStatus[partition].editIdx)
              sprintf(s, PSTR("[%1X]"), c);
            else
              sprintf(s, PSTR("%1X"), c);
          } else
            sprintf(s, " "); 
          if (partitionStatus[partition].digits < 17)
             lcdLine2+=s;
          else {
            if (x < 16)
              lcdLine1+=s;
            else
               lcdLine2+=s;
          }
        }
      } else if (partitionStatus[partition].digits) {
        lcdLine1 = "";
        lcdLine2 = "";
      }
      if (dsc.status[partition] < 0x04) {
        if ( * currentSelection > 1 && * currentSelection < 6) {
          std::string s = String(FPSTR(statusMenu[ * currentSelection])).c_str();
          int pos = s.find(":");
          lcdLine1 = (s.substr(0, pos)).c_str();
          lcdLine2 = (s.substr(pos + 1)).c_str();
        } else {
          byte c = dsc.ready[partition] ? 0 : 1;
          std::string s = String(FPSTR(statusMenuLabels[c])).c_str();
          int pos = s.find(":");
          lcdLine1 = (s.substr(0, pos)).c_str();
          lcdLine2 = (s.substr(pos + 1)).c_str();
          * currentSelection = 1;
        }
        if (partitionStatus[partition].selectedZone && partitionStatus[partition].selectedZone < maxZones) {
          char s[50];
          std::string name=getZoneName(partitionStatus[partition].selectedZone);
          if (name !="")
            snprintf(s, 50,PSTR("%s <>"),name.c_str());
          else
            snprintf(s,50, PSTR("zona %02d  <>"), partitionStatus[partition].selectedZone);
          lcdLine2 = s;
        }
      } else if (dsc.status[partition] == 0xA0) { //bypass
        if ( * currentSelection == 0xFF || * currentSelection == 0 || dsc.status[partition] != partitionStatus[partition].lastStatus)
          *
          currentSelection = getNextEnabledZone(0xFF, partition + 1);
        if ( * currentSelection < maxZones && * currentSelection > 0) {
          char s[50];
          char bypassStatus = ' ';
          if (zoneStatus[ * currentSelection - 1].bypassed)
            bypassStatus = 'B';
          else if (zoneStatus[ * currentSelection - 1].open)
            bypassStatus = 'O';
          std::string name=getZoneName(* currentSelection);
          if (name !="")
            snprintf(s,50, PSTR("%s  %c"), name.c_str(), bypassStatus);
          else
            snprintf(s,50, PSTR("%02d  %c"), * currentSelection, bypassStatus);  
          lcdLine2 = s;
        }
      } else if (dsc.status[partition] == 0x11) { //alarms
        if ( * currentSelection == 0xFF || * currentSelection == 0 || dsc.status[partition] != partitionStatus[partition].lastStatus)
          *
          currentSelection = getNextAlarmedZone(0xFF, partition + 1);
        if ( * currentSelection < maxZones && * currentSelection > 0) {
           char s[50];
          std::string name=getZoneName(* currentSelection);
          if (name !="")
            snprintf(s, 50,PSTR("%s <>"),name.c_str());
          else
          snprintf(s,50, PSTR("zona %02d"), * currentSelection);          
          lcdLine2 = s;
        } else lcdLine2 = " ";
      } else if (dsc.status[partition] == 0xA2) { //alarm memory
        if ( * currentSelection == 0xFF || dsc.status[partition] != partitionStatus[partition].lastStatus)
          *
          currentSelection = getNextOption(0xFF);
        if ( * currentSelection < maxZones && * currentSelection > 0) {
          char s[16];
          lcdLine2 = "";
          sprintf(s, PSTR("zona %02d"), * currentSelection);
          lcdLine2 = s;
        } else {
          lcdLine1 = F("Nav trauksmes signālu");
          lcdLine2 = F("atmiņā");
        }
      } else if (dsc.status[partition] == 0x9E) { // main menu
        if ( * currentSelection == 0xFF || dsc.status[partition] != partitionStatus[partition].lastStatus) {
          * currentSelection = 1;
        }
        lcdLine2 = String(FPSTR(mainMenu[ * currentSelection]));
      } else if (dsc.status[partition] == 0xB2) { // output menu
        if ( * currentSelection == 0xFF || dsc.status[partition] != partitionStatus[partition].lastStatus) {
          * currentSelection = 1;
        }
        lcdLine2 = String(FPSTR(outputMenu[ * currentSelection]));
      } else if (dsc.status[partition] == 0xA9 && !partitionStatus[partition].eventViewer) { // user menu
        if ( * currentSelection == 0xFF || dsc.status[partition] != partitionStatus[partition].lastStatus) {
          * currentSelection = 1;
        }
        lcdLine2 = String(FPSTR(userMenu[ * currentSelection]));
      } else if (dsc.status[partition] == 0xA1) { //trouble
        if ( * currentSelection == 0xFF) {
          * currentSelection = getNextOption(0xFF);
        }
        if ( * currentSelection < 9) {
          lcdLine2 = String(FPSTR(troubleMenu[ * currentSelection]));
        }
      } else if (dsc.status[partition] == 0xC8) { //service
        if ( * currentSelection == 0xFF)
          * currentSelection = getNextOption(0xFF);
        if ( * currentSelection < 9) {
          lcdLine2 = String(FPSTR(serviceMenu[ * currentSelection]));
        }
      } else if (dsc.status[partition] == 0xA6) { //user code
        if ( * currentSelection == 0xFF)
          * currentSelection = getNextUserCode(0xFF);
        if ( * currentSelection < 96) {
          char s[16];
          char programmed = ' ';
          if (checkUserCode( * currentSelection))
            programmed = 'P';
          sprintf(s, PSTR("%02d   %c"), * currentSelection, programmed);
          lcdLine2 = s;
        }
      } else                 // Sends the access code when needed by the panel for arming
        if (dsc.status[partition] == 0x9F && dsc.accessCodePrompt && isInt(accessCode, 10)) {
        dsc.accessCodePrompt = false;
        dsc.write(accessCode, partition + 1);
      }  
      if (options) {
        lcdLine2 = getOptionsString();
      }
     }

    if (lcdLine1 != "") line1DisplayCallback(lcdLine1.c_str(), partition + 1);
    if (lcdLine2 != "") line2DisplayCallback(lcdLine2.c_str(), partition + 1);
    partitionStatus[partition].lastStatus = dsc.status[partition];  
  }

  // Processes status data not natively handled within the library
  void processStatus() {
    switch (dsc.panelData[0]) {
    case 0x0F:
    case 0x0A:
      processProgramZones(4,0);
      if (dsc.panelData[3] == 0xBA)
        processLowBatteryZones();
      if (dsc.panelData[3] == 0xA1) { //system status
        system0 = dsc.panelData[4];
        system0Changed=true;
      }
      if (dsc.panelData[3] == 0xC8) { //service required menu
        system1 = dsc.panelData[4];
        system1Changed=true;
      }

      break;
    case 0x5D:
    case 0x63:
      if ((dsc.panelData[2] & 0x04) == 0x04) { // Alarm memory zones 1-32
        processProgramZones(3,0);
      }
      break;
    case 0xA5:
      processEventBufferAA(true);
      break;
    case 0xAA:
      processEventBufferAA();
      break;
    case 0x6E:
      printPanel_0x6E();
      break;
    case 0x69:
    case 0x64:
      printBeeps(2);
      break;
    case 0x75: //tones 1
    case 0x7D:
      break; //tones 2
    case 0x87: //relay cmd
      processRelayCmd();
      break;
    case 0xB1:
      getEnabledZonesB1(2, 1, 1);
      getEnabledZonesB1(6, 1, 2);
      break;
    case 0xE6:
      switch (dsc.panelData[2]) {
      case 0x01:
        if (!(dsc.panelData[9] & 0x80))
           processProgramZones(5,0);
        else
          processProgramZones(5,4); 
           break;
      case 0x02:
      case 0x03:
      case 0x04:
      case 0x05:
      case 0x06:
      case 0x1D: //ESP_LOGI("info", "Sent tones cmd %02X,%02X", dsc.panelData[0], dsc.panelData[4]);
        break; //tones 3-8
      case 0x19:
        printBeeps(4);
        break;
      case 0x1A:
        break;
      case 0x20:
      case 0x21:
        processProgramZones(5,4);
        break; // Programming zone lights 33-64 //bypass?
      case 0x18:
        if ((dsc.panelData[4] & 0x04) == 0x04)
          processProgramZones(5,4);
        break; // Alarm memory zones 33-64
      case 0x2B:
        getEnabledZonesE6(4, 1, dsc.panelData[3]);
        break;
      case 0x2C:
        getEnabledZonesE6(4, 33, dsc.panelData[3]);
        break;
      };
      break;
    case 0xEB:
      if (dsc.panelData[7] == 1)
        switch (dsc.panelData[8]) {
        case 0xAE:
          line2DisplayCallback(String(F("Walk test end")).c_str(), activePartition);
          break;
        case 0xAF:
          line2DisplayCallback(String(F("Walk test beging")).c_str(), activePartition);
          break;
        };
      processEventBufferEC(true);
      break;
    case 0xEC:
      processEventBufferEC();
      break;
    }
   }

  void printPanelTone(byte panelByte) {
    if (dsc.panelData[panelByte] == 0) {
      return;
    }
    if ((dsc.panelData[panelByte] & 0x80) == 0x80) {
    }
    if ((dsc.panelData[panelByte] & 0x70) != 0) {
    }
    if ((dsc.panelData[panelByte] & 0x0F) != 0) {
    }
  }

  void printBeeps(byte panelByte) {
    dsc.statusChanged = true;
    beeps = dsc.panelData[panelByte] / 2;
    char s[4];
    sprintf(s, "%d", beeps);
    for (byte partition = 0; partition < dscPartitions; partition++) {
      if (dsc.disabled[partition] || partitionStatus[partition].locked) continue;
      beepsCallback(s, partition + 1);
      if (beeps == 2 && partitionStatus[partition].digits) {
        dsc.setLCDReceive(partitionStatus[partition].digits, partition);
        partitionStatus[partition].editIdx = 0;
        partitionStatus[partition].hexMode = false;
        partitionStatus[partition].newData = true;
      }
    }
    beepTime = millis();
  }

  void printPanel_0x6E() {
    if (dsc.pgmBuffer.partition) {
      if (dsc.pgmBuffer.idx == dsc.pgmBuffer.len) 
          setStatus(dsc.pgmBuffer.partition - 1, true);
    }
  }

  void processLowBatteryZones() {
    for (byte panelByte = 4; panelByte < 8; panelByte++) {
      for (byte zoneBit = 0; zoneBit < 8; zoneBit++) {
        zone = zoneBit + ((panelByte - 4) * 8);
        if (zone >= maxZones) continue;
        if (bitRead(dsc.panelData[panelByte], zoneBit)) {
          zoneStatus[zone].batteryLow = true;
        } else
          zoneStatus[zone].batteryLow = false;
      }
    }
  }

  void processRelayCmd() {
    byte rchan;
    byte pgm = 2;
    for (byte relayByte = 2; relayByte < 4; relayByte++) {
      for (byte x = 0; x < 8; x++) {
        if (relayByte == 3) {
          if (x < 2)
            pgm = 0;
          else if (x == 2 || x == 3)
            continue;
          else if (x > 3)
            pgm = 6;
        }
        rchan = pgm + x;
        if (bitRead(dsc.panelData[relayByte], x)) {
          relayStatus[rchan] = true;
        } else {
          relayStatus[rchan] = false;
        }
        if (previousRelayStatus[rchan] != relayStatus[rchan])
          relayChannelChangeCallback(rchan + 1, relayStatus[rchan]);
        previousRelayStatus[rchan] = relayStatus[rchan];
      }
    }
  }

  void processProgramZones(byte startByte,byte zoneStart) {
    byte byteCount = 0;
    for (byte zoneGroup = zoneStart; zoneGroup < zoneStart + 4; zoneGroup++) {
      programZones[zoneGroup] = dsc.panelData[startByte + byteCount];
      byteCount++;
    }
    if (zoneStart==0) {
        //clear upper group
        for (int x=4;x<dscZones;x++) {
            programZones[x] = 0;
        }  
    }    
    if (options)
      dsc.statusChanged = true;
  }

  void processEventBufferAA(bool showEvent = false) {
    #ifndef dscClassicSeries
    if (extendedBufferFlag) return; // Skips 0xAA data when 0xEC extended event buffer data is available
    eventStatusMsg="";
    char eventInfo[45] = "";
    char charBuffer[4];
    if (!showEvent) {
      strcat_P(eventInfo, PSTR("E:"));
      itoa(dsc.panelData[7], charBuffer, 10);
      if (dsc.panelData[7] < 10) strcat_P(eventInfo, PSTR("00"));
      else if (dsc.panelData[7] < 100) strcat(eventInfo, "0");
      strcat(eventInfo, charBuffer);
      strcat(eventInfo, " ");
    }
    byte dscYear3 = dsc.panelData[2] >> 4;
    byte dscYear4 = dsc.panelData[2] & 0x0F;
    byte dscMonth = dsc.panelData[2 + 1] << 2;
    dscMonth >>= 4;
    byte dscDay1 = dsc.panelData[2 + 1] << 6;
    dscDay1 >>= 3;
    byte dscDay2 = dsc.panelData[2 + 2] >> 5;
    byte dscDay = dscDay1 | dscDay2;
    byte dscHour = dsc.panelData[2 + 2] & 0x1F;
    byte dscMinute = dsc.panelData[2 + 3] >> 2;
    if (dscYear3 >= 7) strcat_P(eventInfo, PSTR("19"));
    else strcat_P(eventInfo, PSTR("20"));
    itoa(dscYear3, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    itoa(dscYear4, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, ".");
    if (dscMonth < 10) strcat(eventInfo, "0");
    itoa(dscMonth, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, ".");
    if (dscDay < 10) strcat(eventInfo, "0");
    itoa(dscDay, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, " ");
    if (dscHour < 10) strcat(eventInfo, "0");
    itoa(dscHour, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, ":");
    if (dscMinute < 10) strcat(eventInfo, "0");
    itoa(dscMinute, charBuffer, 10);
    strcat(eventInfo, charBuffer);
     if (dsc.panelData[6] == 0 && dsc.panelData[7] == 0) {
      return;
    }   

    byte partition = dsc.panelData[3] >> 6;
    strcat_P(eventInfo, PSTR(" P:"));
    itoa(partition, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, " ");

    if (showEvent)
      eventStatusMsg = eventInfo;
    else
      line1DisplayCallback(eventInfo, activePartition);
    switch (dsc.panelData[5] & 0x03) {
    case 0x00:
      printPanelStatus0(6, activePartition, showEvent);
      break;
    case 0x01:
      printPanelStatus1(6, activePartition, showEvent);
      break;
    case 0x02:
      printPanelStatus2(6, activePartition, showEvent);
      break;
    case 0x03:
      printPanelStatus3(6, activePartition, showEvent);
      break;
    }
    if (showEvent && eventStatusMsg != "") {
      eventInfoCallback(eventStatusMsg);
      eventTime = millis();
    }
    #endif
  }

  void processEventBufferEC(bool showEvent = false) {
    #ifndef dscClassicSeries
    if (!extendedBufferFlag) extendedBufferFlag = true;
    eventStatusMsg="";
    char eventInfo[45] = "";
    char charBuffer[4];
    if (!showEvent) {
      strcat(eventInfo, "E:");
      int eventNumber = dsc.panelData[9] + ((dsc.panelData[4] >> 6) * 256);
      itoa(eventNumber, charBuffer, 10);
      if (eventNumber < 10) strcat_P(eventInfo, PSTR("00"));
      else if (eventNumber < 100) strcat(eventInfo, "0");
      strcat(eventInfo, charBuffer);
      strcat(eventInfo, " ");
    }
    
    byte dscYear3 = dsc.panelData[3] >> 4;
    byte dscYear4 = dsc.panelData[3] & 0x0F;
    byte dscMonth = dsc.panelData[4] << 2;
    dscMonth >>= 4;
    byte dscDay1 = dsc.panelData[4] << 6;
    dscDay1 >>= 3;
    byte dscDay2 = dsc.panelData[5] >> 5;
    byte dscDay = dscDay1 | dscDay2;
    byte dscHour = dsc.panelData[5] & 0x1F;
    byte dscMinute = dsc.panelData[6] >> 2;

    if (dscYear3 >= 7) strcat_P(eventInfo, PSTR("19"));
    else strcat_P(eventInfo, PSTR("20"));
    itoa(dscYear3, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    itoa(dscYear4, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, ".");
    if (dscMonth < 10) strcat(eventInfo, "0");
    itoa(dscMonth, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, ".");
    if (dscDay < 10) strcat(eventInfo, "0");
    itoa(dscDay, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, " ");
    if (dscHour < 10) strcat(eventInfo, "0");
    itoa(dscHour, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    strcat(eventInfo, ":");
    if (dscMinute < 10) strcat(eventInfo, "0");
    itoa(dscMinute, charBuffer, 10);
    strcat(eventInfo, charBuffer);
    if (dsc.panelData[2] != 0) {
      strcat_P(eventInfo, PSTR(" P:"));
      byte bitCount = 0;
      for (byte bit = 0; bit <= 7; bit++) {
        if (bitRead(dsc.panelData[2], bit)) {
          itoa((bitCount + 1), charBuffer, 10);
        }
        bitCount++;
      }
      strcat(eventInfo, charBuffer);
    }
    strcat_P(eventInfo, PSTR(" "));
    if (showEvent)
      eventStatusMsg = eventInfo;
    else
      line1DisplayCallback(eventInfo, activePartition);
    switch (dsc.panelData[7]) {
    case 0x00:
      printPanelStatus0(8, activePartition, showEvent);
      break;
    case 0x01:
      printPanelStatus1(8, activePartition, showEvent);
      break;
    case 0x02:
      printPanelStatus2(8, activePartition, showEvent);
      break;
    case 0x03:
      printPanelStatus3(8, activePartition, showEvent);
      break;
    case 0x04:
      printPanelStatus4(8, activePartition, showEvent);
      break;
    case 0x05:
      printPanelStatus5(8, activePartition, showEvent);
      break;
    case 0x14:
      printPanelStatus14(8, activePartition, showEvent);
      break;
    case 0x16:
      printPanelStatus16(8, activePartition, showEvent);
      break;
    case 0x17:
      printPanelStatus17(8, activePartition, showEvent);
      break;
    case 0x18:
      printPanelStatus18(8, activePartition, showEvent);
      break;
    case 0x1B:
      printPanelStatus1B(8, activePartition, showEvent);
      break;
    }
    if (showEvent && eventStatusMsg != "") {
      eventInfoCallback(eventStatusMsg);
      eventTime = millis();
    }
    #endif
  }

  void printPanelStatus0(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;
    switch (dsc.panelData[panelByte]) {
    case 0x49:
      lcdLine1 = F("Duress alarm");
      lcdLine2 = F(" ");
      break;
    case 0x4A:
      lcdLine1 = F("Disarmed:");
      lcdLine2 = F("Alarm mem");
      break;
    case 0x4B:
      lcdLine1 = F("Recent");
      lcdLine2 = F("closing alarm");
      break;
    case 0x4C:
      lcdLine1 = F("Zone exp");
      lcdLine2 = F("suprvis. alarm");
      break;
    case 0x4D:
      lcdLine1 = F("Zone exp");
      lcdLine2 = F("suprvis. rest");
      break;
    case 0x4E:
      lcdLine1 = F("Keypad Fire");
      lcdLine2 = F("alarm");
      break;
    case 0x4F:
      lcdLine1 = F("Keypad Aux");
      lcdLine2 = F("alarm");
      break;
    case 0x50:
      lcdLine1 = F("Keypad Panic");
      lcdLine2 = F("alarm");
      break;
    case 0x51:
      lcdLine1 = F("Aux input");
      lcdLine2 = F("alarm");
      break;
    case 0x52:
      lcdLine1 = F("Keypad Fire");
      lcdLine2 = F("alarm rest");
      break;
    case 0x53:
      lcdLine1 = F("Keypad Aux");
      lcdLine2 = F("alarm rest");
      break;
    case 0x54:
      lcdLine1 = F("Keypad Panic");
      lcdLine2 = F("alarm rest");
      break;
    case 0x55:
      lcdLine1 = F("Aux input");
      lcdLine2 = F("alarm rest");
      break;      
    case 0x98:
      lcdLine1 = F("Keypad");
      lcdLine2 = F("lockout");
      break;     
    case 0xBE:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Partial");
      break;
    case 0xBF:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Special");
      break;   
    case 0xE5:
      lcdLine1 = F("Auto-arm");
      lcdLine2 = F("canc");
      break;
    case 0xE6:
      lcdLine1 = F("Disarmed:");
      lcdLine2 = F("Special");
      break;
    case 0xE7:
      lcdLine1 = F("Panel bat");
      lcdLine2 = F("trble");
      break;
    case 0xE8:
      lcdLine1 = F("Panel AC");
      lcdLine2 = F("trble");
      break;
    case 0xE9:
      lcdLine1 = F("Bell trble");
      lcdLine2 = F(" ");
      break;
    case 0xEA:
      lcdLine1 = F("Fire zone");
      lcdLine2 = F("trble");
      break;
    case 0xEB:
      lcdLine1 = F("Panel aux sup");
      lcdLine2 = F("trble");
      break;
    case 0xEC:
      lcdLine1 = F("Tel line");
      lcdLine2 = F("trble");
      break;
    case 0xEF:
      lcdLine1 = F("Panel bat");
      lcdLine2 = F("rest");
      break;
    case 0xF0:
      lcdLine1 = F("Panel AC");
      lcdLine2 = F("rest");
      break;
    case 0xF1:
      lcdLine1 = F("Bell rest");
      lcdLine2 = F(" ");
      break;
    case 0xF2:
      lcdLine1 = F("Fire zone");
      lcdLine2 = F("trble rest");
      break;
    case 0xF3:
      lcdLine1 = F("Panel aux sup");
      lcdLine2 = F("rest");
      break;
    case 0xF4:
      lcdLine1 = F("Tel line");
      lcdLine2 = F("rest");
      break;
    case 0xF7:
      lcdLine1 = F("Phone 1 FTC");
      lcdLine2 = F(" ");
      break;
    case 0xF8:
      lcdLine1 = F("Phone 2 FTC");
      lcdLine2 = F(" ");
      break;
    case 0xF9:
      lcdLine1 = F("Event buffer");
      lcdLine2 = F("threshold");
      break;
    case 0xFA:
      lcdLine1 = F("DLS lead-in");
      lcdLine2 = F(" ");
      break;
    case 0xFB:
      lcdLine1 = F("DLS lead-out");
      lcdLine2 = F(" ");
      break;
    case 0xFE:
      lcdLine1 = F("Periodic test");
      lcdLine2 = F("trans");
      break;
    case 0xFF:
      lcdLine1 = F("System test");
      lcdLine2 = F(" ");
      break;
    default:
      decoded = false;
    }
    char lcdMessage[20];
    char charBuffer[4];
    if (dsc.panelData[panelByte] >= 0x09 && dsc.panelData[panelByte] <= 0x28) {
      strcpy_P(lcdMessage,PSTR("Zonas trauksme:"));
      byte zone = dsc.panelData[panelByte] - 8;
      if (zone > 0 && zone < maxZones)
        zoneStatus[zone - 1].alarm = true;
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = " ";
      decoded = true;
    }

    if (dsc.panelData[panelByte] >= 0x29 && dsc.panelData[panelByte] <= 0x48) {
      lcdLine1 = F("Zonas trauksme");
      strcpy_P(lcdMessage, PSTR(" atjaunota:"));
      byte zone = dsc.panelData[panelByte] - 40; 
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
    }

    if (dsc.panelData[panelByte] >= 0x56 && dsc.panelData[panelByte] <= 0x75) {
      strcpy_P(lcdMessage, PSTR("Zone tamper:"));
      byte zone = dsc.panelData[panelByte] - 0x55;
      if (zone > 0 && zone < maxZones)
      zoneStatus[zone - 1].tamper = true;
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = " ";
      decoded = true;
    }

    if (dsc.panelData[panelByte] >= 0x76 && dsc.panelData[panelByte] <= 0x95) {
      lcdLine1 = F("Zone tamper");
      strcpy_P(lcdMessage, PSTR(" atjaunota: "));
      byte zone = dsc.panelData[panelByte] - 0x75;
      if (zone > 0 && zone < maxZones)
        zoneStatus[zone - 1].tamper = false;
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
    }

    if (dsc.panelData[panelByte] >= 0x99 && dsc.panelData[panelByte] <= 0xBD) {
      lcdLine1 = F("Armed:");
      byte dscCode = dsc.panelData[panelByte] - 0x98;
      if (dscCode >= 35) dscCode += 5;
      if (dscCode == 40) strcpy_P(lcdMessage, PSTR("Master code:"));
      else strcpy_P(lcdMessage, PSTR("Access code:"));
      itoa(dscCode, charBuffer, 10);
      std::string  c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }

    if (dsc.panelData[panelByte] >= 0xC0 && dsc.panelData[panelByte] <= 0xE4) {
      lcdLine1 = F("Disarmed:");
      byte dscCode = dsc.panelData[panelByte] - 0xBF;
      if (dscCode >= 35) dscCode += 5;
      if (dscCode == 40) strcpy_P(lcdMessage, PSTR("Master code:"));
      else strcpy_P(lcdMessage, PSTR("Access code:"));
      itoa(dscCode, charBuffer, 10);
      std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data0");
      lcdLine2 = " ";
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1 + " " + lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus1(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;
    switch (dsc.panelData[panelByte]) {
    case 0x03:
      lcdLine1 = F("Cross zone");
      lcdLine2 = F("alarm");
      break;
    case 0x04:
      lcdLine1 = F("Delinquency");
      lcdLine2 = F("alarm");
      break;
    case 0x05:
      lcdLine1 = F("Late to close");
      lcdLine2 = F(" ");
      break;  
    case 0x29:
      lcdLine1 = F("Download");
      lcdLine2 = F("forced ans");
      break;
    case 0x2B:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Auto-arm");
      break;
    case 0xAC:
      lcdLine1 = F("Exit inst");
      lcdLine2 = F("prog");
      break;
    case 0xAD:
      lcdLine1 = F("Enter inst");
      lcdLine2 = F("prog");
      break;
    case 0xAE:
      lcdLine1 = F("Walk test");
      lcdLine2 = F("end");
      break;
    case 0xAF:
      lcdLine1 = F("Walk test");
      lcdLine2 = F("begin");
      break; 
    case 0xD0:
      lcdLine1 = F("Command");
      lcdLine2 = F("output 4");
      break;
    case 0xD1:
      lcdLine1 = F("Exit fault");
      lcdLine2 = F("pre-alert");
      break;
    case 0xD2:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Entry delay");
      break;
    case 0xD3:
      lcdLine1 = F("Downlook rem");
      lcdLine2 = F("trig");
      break;
    default:
      decoded = false;
    }

    char lcdMessage[20];
    char charBuffer[4];
    if (dsc.panelData[panelByte] >= 0x24 && dsc.panelData[panelByte] <= 0x28) {
      byte dscCode = dsc.panelData[panelByte] - 0x03;
      if (dscCode >= 35) dscCode += 5;
      if (dscCode == 40) strcpy_P(lcdMessage, PSTR("Master kods:"));
      else strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" ");
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x2C && dsc.panelData[panelByte] <= 0x4B) {
      lcdLine1 = F("Zone bat");
      strcpy_P(lcdMessage, PSTR("rest:"));
      zoneStatus[dsc.panelData[panelByte] - 42].batteryLow = false;
      itoa(dsc.panelData[panelByte] - 43, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
      dsc.statusChanged = true;
    }

    if (dsc.panelData[panelByte] >= 0x4C && dsc.panelData[panelByte] <= 0x6B) {
      lcdLine1 = F("Zone bat");
      strcpy_P(lcdMessage, PSTR("low:"));
      zoneStatus[dsc.panelData[panelByte] - 74].batteryLow = true;
      itoa(dsc.panelData[panelByte] - 75, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
      dsc.statusChanged = true;
    }
    if (dsc.panelData[panelByte] >= 0x6C && dsc.panelData[panelByte] <= 0x8B) {
      lcdLine1 = F("Zonas kļuda");
      strcpy_P(lcdMessage, PSTR("rest:"));
      // zoneStatus[dsc.panelData[panelByte] - 106].open=false;
      itoa(dsc.panelData[panelByte] - 107, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
      dsc.statusChanged = true;
    }
    if (dsc.panelData[panelByte] >= 0x8C && dsc.panelData[panelByte] <= 0xAB) {
      strcpy_P(lcdMessage, PSTR("Zonas kļuda:"));
      itoa(dsc.panelData[panelByte] - 139, charBuffer, 10);
      //zoneStatus[dsc.panelData[panelByte] - 138].open=true;
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" ");
      decoded = true;
      dsc.statusChanged = true;
    }
    if (dsc.panelData[panelByte] >= 0xB0 && dsc.panelData[panelByte] <= 0xCF) {
      strcpy_P(lcdMessage, PSTR("Zone bypass:"));
      itoa(dsc.panelData[panelByte] - 175, charBuffer, 10);
      // zoneStatus[dsc.panelData[panelByte] - 174].bypassed=true;
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" ");
      decoded = true;
      dsc.statusChanged = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data1");
      lcdLine2 = F(" ");
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1 + " " + lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1+ " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus2(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
    String lcdLine1;
    String lcdLine2; 
    switch (dsc.panelData[panelByte]) {
    case 0x2A:
      lcdLine1 = F("Ātra izeja");
      lcdLine2 = F(" ");
      break;
    case 0x63:
      lcdLine1 = F("Keybus fault");
      lcdLine2 = F("rest");
      break;
    case 0x64:
      lcdLine1 = F("Keybus fault");
      lcdLine2 = F(" ");
      break;
    case 0x66:
      lcdLine1 = F("Zone bypass");
      lcdLine2 = F("program");
      break;
    case 0x67:
      lcdLine1 = F("Command");
      lcdLine2 = F("output 1");
      break;
    case 0x68:
      lcdLine1 = F("Command");
      lcdLine2 = F("output 2");
      break;
    case 0x69:
      lcdLine1 = F("Command");
      lcdLine2 = F("output 3");
      break;
    case 0x8C:
      lcdLine1 = F("Cold start");
      lcdLine2 = F(" ");
      break;
    case 0x8D:
      lcdLine1 = F("Warm start");
      lcdLine2 = F(" ");
      break;
    case 0x8E:
      lcdLine1 = F("Panel factory");
      lcdLine2 = F("default");
      break;
    case 0x91:
      lcdLine1 = F("Swinger shutdown");
      lcdLine2 = F(" ");
      break;
    case 0x93:
      lcdLine1 = F("Disarmed:");
      lcdLine2 = F("Keyswitch");
      break;
    case 0x96:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Keyswitch");
      break;
    case 0x97:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Keypad away");
      break;
    case 0x98:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Quick-arm");
      break;
    case 0x99:
      lcdLine1 = F("Activate");
      lcdLine2 = F("stay/away zones");
      break;
    case 0x9A:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Mājas");
      break;
    case 0x9B:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("Prom");
      break;
    case 0x9C:
      lcdLine1 = F("Armed:");
      lcdLine2 = F("No ent del");
      break; 
    case 0xFF:
      lcdLine1 = F("Zone exp");
      lcdLine2 = F("trble:1");
      break;
    default:
      decoded = false;
    }

    char lcdMessage[20];
    char charBuffer[4];
    if (dsc.panelData[panelByte] >= 0x67 && dsc.panelData[panelByte] <= 0x69) {
      strcpy_P(lcdMessage,  PSTR("Cmd O/P:"));
      itoa(dsc.panelData[panelByte] - 0x66, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" ");
      decoded = true;
    }

    if (dsc.panelData[panelByte] >= 0x9E && dsc.panelData[panelByte] <= 0xC2) {
      byte dscCode = dsc.panelData[panelByte] - 0x9D;
      lcdLine1 = F("*1: ");
      if (dscCode >= 35) dscCode += 5;
      if (dscCode == 40) strcpy_P(lcdMessage, PSTR("Master kods:"));
      else strcpy_P(lcdMessage,  PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0xC3 && dsc.panelData[panelByte] <= 0xC5) {
      byte dscCode = dsc.panelData[panelByte] - 0xA0;
      lcdLine1 = F("*5: ");
      if (dscCode >= 35) dscCode += 5;
      if (dscCode == 40) strcpy_P(lcdMessage,  PSTR("Master kods:"));
      else strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0xC6 && dsc.panelData[panelByte] <= 0xE5) {
      byte dscCode = dsc.panelData[panelByte] - 0xC5;
      if (dscCode >= 35) dscCode += 5;
      if (dscCode == 40) strcpy_P(lcdMessage, PSTR("Master kods:"));
      else strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
      std::string  c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" ");
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0xE6 && dsc.panelData[panelByte] <= 0xE8) {
      byte dscCode = dsc.panelData[panelByte] - 0xC3;
      lcdLine1 = F("");
      if (dscCode >= 35) dscCode += 5;
      if (dscCode == 40) strcpy_P(lcdMessage, PSTR("Master kods:"));
      else strcpy_P(lcdMessage,  PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0xE9 && dsc.panelData[panelByte] <= 0xF0) {
      lcdLine1 = F("Keypad rest");
      strcpy_P(lcdMessage,  PSTR(" slot:"));
      itoa(dsc.panelData[panelByte] - 232, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0xF1 && dsc.panelData[panelByte] <= 0xF8) {
      lcdLine1 = F("Keypad trble ");
      strcpy_P(lcdMessage, PSTR("slot: "));
      itoa(dsc.panelData[panelByte] - 240, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0xF9 && dsc.panelData[panelByte] <= 0xFE) {
      strcpy_P(lcdMessage,PSTR("Zone exp:"));
      itoa(dsc.panelData[panelByte] - 248, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" rest");
      decoded = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data2");
      lcdLine2 = " ";
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1+" " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus3(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
    String lcdLine1;
    String lcdLine2;
    switch (dsc.panelData[panelByte]) {
    case 0x05:
      lcdLine1 = F("PC/RF5132:");
      lcdLine2 = F("Suprvis. rest");
      break;
    case 0x06:
      lcdLine1 = F("PC/RF5132:");
      lcdLine2 = F("Suprvis. trble");
      break;
    case 0x09:
      lcdLine1 = F("PC5204:");
      lcdLine2 = F("Suprvis. rest");
      break;
    case 0x0A:
      lcdLine1 = F("PC5204:");
      lcdLine2 = F("Suprvis. trble");
      break;
    case 0x17:
      lcdLine1 = F("Zone exp 7");
      lcdLine2 = F("rest");
      break;
    case 0x18:
      lcdLine1 = F("Zone exp 7");
      lcdLine2 = F("trble");
      break;
    case 0x41:
      lcdLine1 = F("PC/RF5132:");
      lcdLine2 = F("Tamper rest");
      break;
    case 0x42:
      lcdLine1 = F("PC/RF5132: Tamper");
      lcdLine2 = F(" ");
      break;
    case 0x43:
      lcdLine1 = F("PC5208: Tamper");
      lcdLine2 = F("rest");
      break;
    case 0x44:
      lcdLine1 = F("PC5208: Tamper");
      lcdLine2 = F(" ");
      break;
    case 0x45:
      lcdLine1 = F("PC5204: Tamper");
      lcdLine2 = F("rest");
      break;
    case 0x46:
      lcdLine1 = F("PC5204: Tamper");
      lcdLine2 = F(" ");
      break;
    case 0x51:
      lcdLine1 = F("Zone exp 7");
      lcdLine2 = F("tamper rest");
      break;
    case 0x52:
      lcdLine1 = F("Zone exp 7");
      lcdLine2 = F("tamper");
      break;
    case 0xB3:
      lcdLine1 = F("PC5204:");
      lcdLine2 = F("Bat rest");
      break;
    case 0xB4:
      lcdLine1 = F("PC5204:");
      lcdLine2 = F("Bat trble");
      break;
    case 0xB5:
      lcdLine1 = F("PC5204: Aux");
      lcdLine2 = F("sup rest");
      break;
    case 0xB6:
      lcdLine1 = F("PC5204: Aux");
      lcdLine2 = F("sup trble");
      break;
    case 0xB7:
      lcdLine1 = F("PC5204: Out 1");
      lcdLine2 = F("rest");
      break;
    case 0xB8:
      lcdLine1 = F("PC5204: Out 1");
      lcdLine2 = F("trble");
      break;
    case 0xFF:
      lcdLine1 = F("Ext status");
      lcdLine2 = F(" ");
      break;
    default:
      decoded = false;
    }

    char lcdMessage[20];
    char charBuffer[4];

    if (dsc.panelData[panelByte] <= 0x04) {
      strcpy_P(lcdMessage, PSTR("Zone exp. "));
      itoa(dsc.panelData[panelByte] + 2, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F("trouble");
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x25 && dsc.panelData[panelByte] <= 0x2C) {
      strcpy_P(lcdMessage, PSTR("keypad "));
      itoa(dsc.panelData[panelByte] - 0x24, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F("tamper rest");
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x2D && dsc.panelData[panelByte] <= 0x34) {
      strcpy_P(lcdMessage, PSTR("klaviatūra"));
      itoa(dsc.panelData[panelByte] - 0x2c, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F("tamper");
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x35 && dsc.panelData[panelByte] <= 0x3A) {
      strcpy_P(lcdMessage, PSTR("Zone expander "));
      itoa(dsc.panelData[panelByte] - 52, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F("tamper rest");
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x3B && dsc.panelData[panelByte] <= 0x40) {
      strcpy_P(lcdMessage, PSTR("Zone expander "));
      itoa(dsc.panelData[panelByte] - 58, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F("tamper");
      decoded = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data3");
      lcdLine2 = F(" ");
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus4(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;
    switch (dsc.panelData[panelByte]) {
    case 0x86:
      lcdLine1 = F("Period test");
      lcdLine2 = F("trble");
      break;
    case 0x87:
      lcdLine1 = F("Exit fault");
      lcdLine2 = F(" ");
      break;
    case 0x89:
      lcdLine1 = F("Alarm canc");
      lcdLine2 = F(" ");
      break;
    default:
      decoded = false;
    }

    char lcdMessage[20];
    char charBuffer[4];

    if (dsc.panelData[panelByte] <= 0x1F) {
      strcpy_P(lcdMessage, PSTR("Zonas trauksme: "));
      byte zone = dsc.panelData[panelByte] + 33;
      if (zone > 0 && zone < maxZones)
        zoneStatus[zone - 1].alarm = true;
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" ");
      decoded = true;
    } else if (dsc.panelData[panelByte] >= 0x20 && dsc.panelData[panelByte] <= 0x3F) {
      lcdLine1 = F("Zonas trauksme");
      strcpy_P(lcdMessage, PSTR(" rest: "));
      byte zone = dsc.panelData[panelByte] + 1; 
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
    } else if (dsc.panelData[panelByte] >= 0x40 && dsc.panelData[panelByte] <= 0x5F) {
      strcpy_P(lcdMessage, PSTR("Zone tamper:"));
      byte zone = dsc.panelData[panelByte] - 31;
      if (zone > 0 && zone < maxZones)
      zoneStatus[zone - 1].tamper = true;
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine1 = lcdMessage;
      lcdLine2 = F(" ");
      decoded = true;
    } else if (dsc.panelData[panelByte] >= 0x60 && dsc.panelData[panelByte] <= 0x7F) {
      lcdLine1 = F("Zone tamper");
      strcpy_P(lcdMessage, PSTR(" rest:"));
      byte zone = dsc.panelData[panelByte] - 63;
      if (zone > 0 && zone < maxZones)
        zoneStatus[zone - 1].tamper = false;
      itoa(zone, charBuffer, 10);
      strcat(lcdMessage, charBuffer);
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data4");
      lcdLine2 = F(" ");
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus5(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;
    char lcdMessage[20];
    char charBuffer[4];

    if (dsc.panelData[panelByte] <= 0x39) {
      byte dscCode = dsc.panelData[panelByte] + 0x23;
      lcdLine1 = F("Armed:");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x3A && dsc.panelData[panelByte] <= 0x73) {
      byte dscCode = dsc.panelData[panelByte] - 0x17;
      lcdLine1 = F("Atbruņots:");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data5");
      lcdLine2 = F(" ");
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus14(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;
    switch (dsc.panelData[panelByte]) {
    case 0xC0:
      lcdLine1 = F("TLink");
      lcdLine2 = F("com fault");
      break;
    case 0xC2:
      lcdLine1 = F("Tlink");
      lcdLine2 = F("net fault");
      break;
    case 0xC4:
      lcdLine1 = F("TLink rec");
      lcdLine2 = F("trouble");
      break;
    case 0xC5:
      lcdLine1 = F("TLink receiver");
      lcdLine2 = F("restored");
      break;
    default:
      decoded = false;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data14");
      lcdLine2 = F(" ");
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus16(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;    

    switch (dsc.panelData[panelByte]) {
    case 0x80:
      lcdLine1 = F("Problēma");
      lcdLine2 = F("ack");
      break;
    case 0x81:
      lcdLine1 = F("RF delin");
      lcdLine2 = F("trouble");
      break;
    case 0x82:
      lcdLine1 = F("RF delin");
      lcdLine2 = F("rest");
      break;
    default:
      decoded = false;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data16");
      lcdLine2 = F("");
    }
if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus17(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;
    char lcdMessage[20];
    char charBuffer[4];

    if (dsc.panelData[panelByte] >= 0x4A && dsc.panelData[panelByte] <= 0x83) {
      byte dscCode = dsc.panelData[panelByte] - 0x27;
      lcdLine1 = F("*1: ");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }

    if (dsc.panelData[panelByte] <= 0x24) {
      byte dscCode = dsc.panelData[panelByte] + 1;
      lcdLine1 = F("*2: ");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x84 && dsc.panelData[panelByte] <= 0xBD) {
      byte dscCode = dsc.panelData[panelByte] - 0x61;
      lcdLine1 = F("*2: ");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x25 && dsc.panelData[panelByte] <= 0x49) {
      byte dscCode = dsc.panelData[panelByte] - 0x24;
      lcdLine1 = F("*3: ");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
      std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0xBE && dsc.panelData[panelByte] <= 0xF7) {
      byte dscCode = dsc.panelData[panelByte] - 0x9B;
      lcdLine1 = F("*3: ");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data17");
      lcdLine2 = F("");
    }
if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus18(byte panelByte, byte partition, bool showEvent = false) {

    bool decoded = true;
    char lcdMessage[20];
    char charBuffer[4];
     String lcdLine1;
     String lcdLine2;

    if (dsc.panelData[panelByte] <= 0x39) {
      byte dscCode = dsc.panelData[panelByte] + 0x23;
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
     std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine1 = lcdMessage;
      lcdLine2 = " ";
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x3A && dsc.panelData[panelByte] <= 0x95) {
      byte dscCode = dsc.panelData[panelByte] - 0x39;
      lcdLine1 = F("*5: ");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
      std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (dsc.panelData[panelByte] >= 0x96 && dsc.panelData[panelByte] <= 0xF1) {
      byte dscCode = dsc.panelData[panelByte] - 0x95;
      lcdLine1 = F("*6: ");
      if (dscCode >= 40) dscCode += 3;
      strcpy_P(lcdMessage, PSTR("Piekļuves kods:"));
      itoa(dscCode, charBuffer, 10);
      std::string c=getUserName(charBuffer);
      strcat(lcdMessage, c.c_str());
      lcdLine2 = lcdMessage;
      decoded = true;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data18");
      lcdLine2 = F("");
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }

  void printPanelStatus1B(byte panelByte, byte partition, bool showEvent = false) {
    bool decoded = true;
     String lcdLine1;
     String lcdLine2;
    switch (dsc.panelData[panelByte]) {
    case 0xF1:
      lcdLine1 = F("Sistēmas restarts ");
      lcdLine2 = F("trans");
      break;
    default:
      decoded = false;
    }
    if (!decoded) {
      lcdLine1 = F("Unknown data1b");
      lcdLine2 = F("");
    }
    if (showEvent)
      eventStatusMsg.append((lcdLine1+ " " +lcdLine2).c_str());
    else
      line2DisplayCallback((lcdLine1 + " " +lcdLine2).c_str(), partition);
  }
  
  const __FlashStringHelper *statusText(uint8_t statusCode)
  {
    switch (statusCode) {
        case 0x01: return F("Gatavs");
        case 0x02: return F("Zonas atvērtas");
        case 0x03: return F("Atvērta zona");
        case 0x04: return F("Armed mājas");
        case 0x05: return F("Armed prom");
        case 0x06: return F("Nav ieejas kavēšanās");
        case 0x07: return F("Neizdevās arm");
        case 0x08: return F("Izejas aizkave");
        case 0x09: return F("Nav ieejas kavēšanās");
        case 0x0B: return F("Atrā izeja");
        case 0x0C: return F("Ieejas kavēšanās");
        case 0x0D: return F("Trauksmes atmiņa");
        case 0x10: return F("Tastatūras bloķēšana");
        case 0x11: return F("Trauksme");
        case 0x14: return F("Automātiskā aktivizēšana");
        case 0x15: return F("Arm ar apvedceļu");
        case 0x16: return F("Nav ieejas kavēšanās");
        case 0x17: return F("Strāvas pārtraukums");//??? not sure
        case 0x22: return F("Trauksmes atmiņa");
        case 0x33: return F("Aizņemts");
        case 0x3D: return F("Atbruņots");
        case 0x3E: return F("Atbruņots");
        case 0x40: return F("Tastatūra ir notīrīta");
        case 0x8A: return F("Aktivizēt zonas");
        case 0x8B: return F("Ātra izeja");
        case 0x8E: return F("Nederīga opcija");
        case 0x8F: return F("Nederīgs kods");
        case 0x9E: return F("Ievadiet * kodu");
        case 0x9F: return F("Piekļuves kods");
        case 0xA0: return F("Zonu apvedceļš");
        case 0xA1: return F("Problēmu izvēlne");
        case 0xA2: return F("Trauksmes atmiņa");
        case 0xA3: return F("Durvju zvans ieslēgts");
        case 0xA4: return F("Atslēgts durvju zvans");
        case 0xA5: return F("Master kods");
        case 0xA6: return F("Piekkļuves kods");
        case 0xA7: return F("Ievadi jaunu kodu");
        case 0xA9: return F("Lietotāja funkcija");
        case 0xAA: return F("Datums un laiks");
        case 0xAB: return F("Automātiskās aktivizēšanas laiks");
        case 0xAC: return F("Automātiskā aktivizēšana ieslēgta");
        case 0xAD: return F("Automātiskā aktivizēšana izslēgta");
        case 0xAF: return F("Sistēmas tests");
        case 0xB0: return F("Iespējot DLS");
        case 0xB2: return F("Komandu izvade");
        case 0xB7: return F("Instalētāja kods");
        case 0xB8: return F("Ievadi * kodu");
        case 0xB9: return F("Zone tamper");
        case 0xBA: return F("Zones low batt.");
        case 0xC6: return F("Zonas kļūdu izvēlne");
        case 0xC8: return F("Nepieciešams serviss");
        case 0xD0: return F("Keypads low batt");
        case 0xD1: return F("Wireless low bat");
        case 0xE4: return F("Instalēšanas izvēlne");
        case 0xE5: return F("Tastatūras slots");
        case 0xE6: return F("Ievade: 2 cipari");
        case 0xE7: return F("Ievade: 3 cipari");
        case 0xE8: return F("Ievade: 4 cipari");
        case 0xEA: return F("Kods: 2 cipari");
        case 0xEB: return F("Kods: 4 cipari");
        case 0xEC: return F("Ievade: 6 cipari");
        case 0xED: return F("Ievade: 32 cipari");
        case 0xEE: return F("Ievade: opcija");
        case 0xF0: return F("Funkcijas taustiņš 1");
        case 0xF1: return F("Funkcijas taustiņš 2");
        case 0xF2: return F("Funkcijas taustiņš 3");
        case 0xF3: return F("Funkcijas taustiņš 4");
        case 0xF4: return F("Funkcijas taustiņš 5");
        case 0xF8: return F("Tastatūras programma");
        case 0xFF: return F("Izslēgts");
        default: return F("Nezināms");
    }
  }  
};
#endif 