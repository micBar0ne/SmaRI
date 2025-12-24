#pragma once
#include <Arduino.h>

enum class AuditEventType : uint8_t {
  RELAY_TRIGGER_OK,
  RELAY_TRIGGER_FAIL
};

struct AuditEntry {
  unsigned long atMs;
  AuditEventType type;
  uint8_t relayId;      // 1,2...
  uint32_t durationMs;  // requested
  bool ok;
};

class SmaRiAuditLog {
public:
  static constexpr size_t CAPACITY = 20;

  void add(AuditEventType type, uint8_t relayId, uint32_t durationMs, bool ok);
  size_t size() const { return _count; }
  AuditEntry getNewest(size_t indexFromNewest) const; // 0=newest
  String toJson() const; // JSON array

private:
  AuditEntry _buf[CAPACITY]{};
  size_t _head = 0;   // next write index
  size_t _count = 0;  // <= CAPACITY
};
