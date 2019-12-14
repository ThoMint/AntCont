#ifndef WEBNETSERVER_H
#define WEBNETSERVER_H

#include "Arduino.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SFFIPS.h"

void initWebServer();
void onIndexRequest(AsyncWebServerRequest *request);
void onCSSRequest(AsyncWebServerRequest *request);
void onPageNotFound(AsyncWebServerRequest *request);

#endif
