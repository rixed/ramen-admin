// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreePath.h"

OmniTreePath::OmniTreePath(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreePath::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreePath::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
