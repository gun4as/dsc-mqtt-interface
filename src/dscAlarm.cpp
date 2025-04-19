#include "dscAlarm.h"
#include "globals.h"

dscKeybusInterface dsc(dscClockPinDefault, dscReadPinDefault, dscWritePinDefault);
bool forceDisconnect = false;

void disconnectKeybus() {
  dsc.stop();
  dsc.keybusConnected = false;
  dsc.statusChanged = false;
  forceDisconnect = true;
}