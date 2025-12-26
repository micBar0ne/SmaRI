#include "SmaRiAuditLog.h"

void SmaRiAuditLog::add(AuditEventType type, uint8_t relayId, uint32_t durationMs, bool ok) {
  AuditEntry &e = _buf[_head];
  e.atMs = millis();
  e.type = type;
  e.relayId = relayId;
  e.durationMs = durationMs;
  e.ok = ok;

  _head = (_head + 1) % CAPACITY;
  if (_count < CAPACITY) _count++;
}

AuditEntry SmaRiAuditLog::getNewest(size_t idx) const {
  // idx=0 newest
  if (_count == 0) return AuditEntry{0, AuditEventType::RELAY_TRIGGER_FAIL, 0, 0, false};
  if (idx >= _count) idx = _count - 1;

  // head points to next write -> newest is head-1
  size_t newest = (_head + CAPACITY - 1) % CAPACITY;
  size_t pos = (newest + CAPACITY - idx) % CAPACITY;
  return _buf[pos];
}

String SmaRiAuditLog::toJson() const {
  String out = "[";
  for (size_t i = 0; i < _count; i++) {
    AuditEntry e = getNewest(i);
    out += "{";
    out += "\"at_ms\":" + String(e.atMs) + ",";
    out += "\"relay\":" + String(e.relayId) + ",";
    out += "\"duration_ms\":" + String(e.durationMs) + ",";
    out += "\"ok\":" + String(e.ok ? "true" : "false");
    out += "}";
    if (i + 1 < _count) out += ",";
  }
  out += "]";
  return out;
}
