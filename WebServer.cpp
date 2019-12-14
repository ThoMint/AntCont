#include "WebServer.h"

const int dns_port = 53;
const int http_port = 80;
AsyncWebServer server(http_port);

void initWebServer()
{
  server.on("/", HTTP_GET, onIndexRequest);
  server.on("/style.css", HTTP_GET, onCSSRequest);
  server.onNotFound(onPageNotFound);
  server.begin();
}

void onIndexRequest(AsyncWebServerRequest *request) {
  IPAddress remote_ip = request->client()->remoteIP();
  Serial.println("[" + remote_ip.toString() +
                  "] HTTP GET request of " + request->url());
  request->send(SPIFFS, "/index.html", "text/html");
}

void onCSSRequest(AsyncWebServerRequest *request) {
  IPAddress remote_ip = request->client()->remoteIP();
  Serial.println("[" + remote_ip.toString() +
                  "] HTTP GET request of " + request->url());
  request->send(SPIFFS, "/style.css", "text/css");
}

void onPageNotFound(AsyncWebServerRequest *request) {
  IPAddress remote_ip = request->client()->remoteIP();
  Serial.println("[" + remote_ip.toString() +
                  "] HTTP GET request of " + request->url());
  request->send(404, "text/plain", "Not found");
}
