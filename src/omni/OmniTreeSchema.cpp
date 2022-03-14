// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeSchema.h"

OmniTreeSchema::OmniTreeSchema(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreeSchema::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreeSchema::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
