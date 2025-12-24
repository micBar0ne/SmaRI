#include "SmaRiWebServer.h"

SmaRiWebServer::SmaRiWebServer(uint16_t port)
: _server(port) {}

void SmaRiWebServer::registerRoutes() {
  _server.on("/health", HTTP_GET, [this]() {
    _server.send(200, "text/plain", "OK");
  });

  _server.on("/api/status", HTTP_GET, [this]() {
    if (_statusProvider) {
      const String json = _statusProvider();
      _server.send(200, "application/json", json);
    } else {
      _server.send(503, "application/json", "{\"error\":\"status provider not set\"}");
    }
  });

  _server.onNotFound([this]() {
    _server.send(404, "text/plain", "Not Found");
  });
}

void SmaRiWebServer::begin() {
  if (_running) return;

  registerRoutes();
  _server.begin();
  _running = true;
}

void SmaRiWebServer::end() {
  if (!_running) return;

  _server.stop();           // available on ESP32 WebServer
  _running = false;
}

void SmaRiWebServer::loop() {
  if (!_running) return;
  _server.handleClient();
}

bool SmaRiWebServer::isRunning() const {
  return _running;
}

void SmaRiWebServer::setStatusProvider(std::function<String()> provider) {
  _statusProvider = provider;
}
