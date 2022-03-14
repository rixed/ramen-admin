// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeFunction.h"

OmniTreeFunction::OmniTreeFunction(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreeFunction::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreeFunction::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
