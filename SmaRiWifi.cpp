#include "SmaRIWifi.h"
#include "Config.h"

#include <esp_bt.h>
#include <esp_wifi.h>

SmaRiWifi::SmaRiWifi(const char* ssid,
                     const char* pass,
                     bool useStaticIp,
                     IPAddress local,
                     IPAddress gateway,
                     IPAddress subnet,
                     IPAddress dns1,
                     IPAddress dns2)
: _ssid(ssid),
  _pass(pass),
  _useStaticIp(useStaticIp),
  _local(local),
  _gateway(gateway),
  _subnet(subnet),
  _dns1(dns1),
  _dns2(dns2)
{}

void SmaRiWifi::setTimeouts(uint32_t connectTimeoutMs, uint32_t retryIntervalMs) {
  _connectTimeoutMs = connectTimeoutMs;
  _retryIntervalMs  = retryIntervalMs;
}

void SmaRiWifi::begin() {
  if (RADIO_DISABLE_BLUETOOTH) {
    // SmaRI does not use Bluetooth.
    // This releases Bluetooth memory for the current boot.
    // After this, Bluetooth cannot be used until reboot.
    esp_bt_controller_mem_release(ESP_BT_MODE_BTDM);
  }

  WiFi.mode(WIFI_STA);

  if (WIFI_LIMIT_TX_POWER) {
    esp_wifi_set_max_tx_power(WIFI_TX_POWER_QDBM);
  }

  WiFi.setAutoReconnect(true);
  WiFi.persistent(false);

  if (_useStaticIp) {
    WiFi.config(_local, _gateway, _subnet, _dns1, _dns2);
  }

  WiFi.disconnect(false, false);
  startAttempt();
}

void SmaRiWifi::startAttempt() {
  _connectAttemptStart = millis();
  _state = WifiConnState::CONNECTING;
  WiFi.begin(_ssid, _pass);
}

bool SmaRiWifi::isConnected() const {
  return (_state == WifiConnState::CONNECTED) && (WiFi.status() == WL_CONNECTED);
}

String SmaRiWifi::ip() const {
  if (!isConnected()) return String();
  return WiFi.localIP().toString();
}

int SmaRiWifi::rssi() const {
  if (!isConnected()) return 0;
  return WiFi.RSSI();
}

void SmaRiWifi::loop() {
  wl_status_t s = WiFi.status();
  unsigned long now = millis();

  switch (_state) {
    case WifiConnState::IDLE:
      break;

    case WifiConnState::CONNECTING:
      if (s == WL_CONNECTED) {
        _state = WifiConnState::CONNECTED;
        _connectedAt = now;
      } else if (now - _connectAttemptStart > _connectTimeoutMs) {
        _state = WifiConnState::FAILED;
        _lastRetry = now;
      }
      break;

    case WifiConnState::CONNECTED:
      if (s != WL_CONNECTED) {
        startAttempt();
      }
      break;

    case WifiConnState::FAILED:
      if (now - _lastRetry > _retryIntervalMs) {
        startAttempt();
      }
      break;
  }
}
