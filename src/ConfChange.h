#ifndef CONFCHANGE_H_210908
#define CONFCHANGE_H_210908
#include <memory>

#include "desssergen/sync_key.h"
#include "KValue.h"

enum ConfChangeOp { KeyCreated, KeyChanged, KeyLocked, KeyUnlocked, KeyDeleted };

/* In order to increase UI reactivity, several configuration changes notifications are
 * batched into a single signal, as a QList of ConfChange items. */

struct ConfChange {
  ConfChangeOp op;
  std::shared_ptr<dessser::gen::sync_key::t const> key;
  KValue kv;
};

#endif
