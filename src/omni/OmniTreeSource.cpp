// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeSource.h"

OmniTreeSource::OmniTreeSource(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreeSource::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreeSource::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
