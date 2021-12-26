// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef CONFCHANGE_H_210908
#define CONFCHANGE_H_210908
#include <memory>

#include "KValue.h"
#include "desssergen/sync_key.h"

enum ConfChangeOp {
  KeyCreated,
  KeyChanged,
  KeyLocked,
  KeyUnlocked,
  KeyDeleted
};

/* In order to increase UI reactivity, several configuration changes
 * notifications are batched into a single signal, as a QList of ConfChange
 * items. */

struct ConfChange {
  ConfChangeOp op;
  std::shared_ptr<dessser::gen::sync_key::t const> key;
  KValue kv;
};

#endif
