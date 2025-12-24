#pragma once
#include <Arduino.h>
#include <WebServer.h>
#include <functional>

class SmaRiWebServer {
public:
  explicit SmaRiWebServer(uint16_t port = 1987);

  void begin();        // start server + register routes
  void end();          // stop server
  void loop();         // handleClient()
  bool isRunning() const;

void setStatusProvider(std::function<String()> provider);

private:
  void registerRoutes();

  WebServer _server;
  bool _running = false;

  std::function<String()> _statusProvider;
};
