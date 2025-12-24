#ifndef SMARI_APP_H
#define SMARI_APP_H

#include <Arduino.h>
#include "Config.h"
#include "SmaRIWifi.h"
#include "SmaRIDisplay.h"
#include "SmaRILed.h"
#include "SmaRIWebServer.h"
#include "SmaRiRelayController.h"
#include "SmaRIAuditLog.h"

class SmaRiApp {
public:
  SmaRiApp();
  
  String buildStatusJson() const;

  void setup();
  void loop();

private:
  StatusLed    _statusLed;
  SmaRiWifi    _wifi;
  SmaRiDisplay _display;
  SmaRiWebServer _web;
  SmaRiRelayController _relay;
  SmaRiAuditLog _audit;

  unsigned long _initStart = 0;
};

#endif
