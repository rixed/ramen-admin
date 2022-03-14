// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeStats.h"

OmniTreeStats::OmniTreeStats(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreeStats::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreeStats::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
