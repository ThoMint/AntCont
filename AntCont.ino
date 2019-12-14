#include "AntCont.h"
#include "SFFIPS.h"
#include "Wlan.h"
#include "WebServer.h"
#include "StepMotor.h"
#include "WebSocketServer.h"

void setup()
{
  Serial.begin(115200);
  initSpiffs(true);
  initWiFi();
  initWebServer();
  initWebSocketServer();
  initStepper();
}

void loop()
{
  loopWebSocketServer();
}
