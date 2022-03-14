// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeWorker.h"

OmniTreeWorker::OmniTreeWorker(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreeWorker::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreeWorker::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
