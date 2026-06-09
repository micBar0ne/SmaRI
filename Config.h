#pragma once

#ifndef SMARI_CONFIG_H
#define SMARI_CONFIG_H

#include "Secrets.h"

#ifndef SMARI_WIFI_SSID
  #error "Missing Secrets.h. Copy Secrets.h.example to Secrets.h and fill credentials."
#endif

#include <Arduino.h>
#include <WiFi.h>

#ifndef LED_BUILTIN
  #define LED_BUILTIN 2
#endif

static const int STATUS_LED_PIN = LED_BUILTIN;

// ---------- WIFI SETTINGS ----------
inline constexpr char WIFI_SSID[] = SMARI_WIFI_SSID;
inline constexpr char WIFI_PASS[] = SMARI_WIFI_PASS;

// ---------- RADIO SETTINGS ----------
// Bluetooth is not used by SmaRI.
// Releasing BT memory saves RAM and ensures BT is not available in this boot.
inline constexpr bool RADIO_DISABLE_BLUETOOTH = true;

// Reduce ESP32 Wi-Fi TX power.
// Unit is 0.25 dBm when using esp_wifi_set_max_tx_power().
// 80 = 20 dBm
// 60 = 15 dBm
// 52 = 13 dBm
// 44 = 11 dBm
// 34 = 8.5 dBm
inline constexpr bool WIFI_LIMIT_TX_POWER = true;
inline constexpr int8_t WIFI_TX_POWER_QDBM = 34;  // 11 dBm, safe first test

// ---------- WEB AUTH ----------
inline constexpr char WEB_USER[] = SMARI_WEB_USER;
inline constexpr char WEB_PASS[] = SMARI_WEB_PASS;
inline constexpr bool WEB_AUTH_ENABLED = true;

// Auth protection settings
inline constexpr uint8_t WEB_AUTH_MAX_FAILURES = 7;

// How long the device stays locked after too many failed logins
inline constexpr uint32_t WEB_AUTH_LOCKOUT_MS = 5UL * 60UL * 1000UL;   // 5 minutes

// Failed attempts older than this are forgotten
inline constexpr uint32_t WEB_AUTH_FAILURE_WINDOW_MS = 10UL * 60UL * 1000UL; // 10 minutes

// After this number of wrong attempts we could apply a penalty.
// Keep penalty disabled for now to avoid blocking delays.
inline constexpr uint8_t WEB_AUTH_PENALTY_AFTER = 4;
inline constexpr uint32_t WEB_AUTH_PENALTY_MS = 0;

inline constexpr const uint32_t WIFI_CONNECT_TIMEOUT_MS = 15000;
inline constexpr const uint32_t WIFI_RETRY_INTERVAL_MS  = 5000;

// ---- Static IP settings ----
inline const bool WIFI_USE_STATIC_IP = true;
inline const IPAddress WIFI_LOCAL_IP(192, 168, 1, 87);
inline const IPAddress WIFI_GATEWAY(192, 168, 1, 1);
inline const IPAddress WIFI_SUBNET (255, 255, 255, 0);
inline const IPAddress WIFI_DNS1   (1, 1, 1, 1);
inline const IPAddress WIFI_DNS2   (8, 8, 8, 8);

// ---------- UI SETTINGS ----------
inline const uint32_t INIT_SCREEN_DURATION_MS = 2000;
inline const uint32_t WIFI_SHOW_INFO_TIMEOUT  = 5000;

// ---------- RELAY SETTINGS ----------
inline constexpr int RELAY1_PIN = 26;
inline constexpr int RELAY2_PIN = 27;

inline constexpr bool RELAY_ACTIVE_LOW = true;

inline constexpr uint32_t RELAY_DEFAULT_PULSE_MS = 200;
inline constexpr uint32_t RELAY_MAX_PULSE_MS     = 300;
inline constexpr bool RELAY_ALLOW_CUSTOM_MS      = false;

#endif
