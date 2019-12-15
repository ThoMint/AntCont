#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include "Arduino.h"
#include "SFFIPS.h"
#include "StepMotor.h"
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

void initWebSocketServer();
void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t * payload, size_t length);
void loopWebSocketServer();

#endif
