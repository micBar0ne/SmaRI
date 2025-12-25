#pragma once
#include <Arduino.h>

enum class RelayId : uint8_t {
  RELAY_1 = 1,
  RELAY_2 = 2
};

class SmaRiRelayController {
public:
  void begin();
  void loop(unsigned long now);

  bool trigger(RelayId id, uint32_t durationMs);

  bool triggerDoubleTap(RelayId id, uint32_t onMs, uint32_t gapMs);

  bool isBusy() const { return _busy; }
  RelayId activeRelay() const { return _activeRelay; }
  uint32_t remainingMs(unsigned long now) const;

  const char* lastError() const { return _lastError; }
  RelayId lastRelay() const { return _lastRelay; }
  unsigned long lastActionAtMs() const { return _lastActionAtMs; }

private:
  void setRelayPin(RelayId id, bool on);
  int pinFor(RelayId id) const;

  bool _busy = false;
  RelayId _activeRelay = RelayId::RELAY_1;
  unsigned long _pulseEndAtMs = 0;

  RelayId _lastRelay = RelayId::RELAY_1;
  unsigned long _lastActionAtMs = 0;
  const char* _lastError = nullptr;

  enum class SeqState : uint8_t { IDLE, PULSE1_ON, GAP_OFF, PULSE2_ON };
  SeqState _seq = SeqState::IDLE;
  unsigned long _stepEndAtMs = 0;
  uint32_t _tapOnMs = 0;
  uint32_t _tapGapMs = 0;
};
