#include "WebSocketServer.h"

const int ws_port = 1337;
char msg_buf[10];
WebSocketsServer webSocket = WebSocketsServer(ws_port);
StaticJsonDocument<256> doc;

void initWebSocketServer()
{
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
}

void onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t* payload, size_t length)
{
  switch(type)
  {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", client_num);
      break;
      
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(client_num);
        Serial.printf("[%u] Connection from ", client_num);
        Serial.println(ip.toString());
      }
      break;
      
    case WStype_TEXT:
      Serial.printf("[%u] Received text: %s\n", client_num, payload);
      deserializeJson(doc, payload);
      
      if(doc["type"].as<String>() == "stepperCMD")
      {
        cmdStepper(doc["dir"].as<String>(),doc["speed"].as<int>(),doc["amount"].as<int>());
      }
      if(doc["type"].as<String>() == "")
      {
        
      }
  }
}

void loopWebSocketServer()
{
  webSocket.loop();
}
