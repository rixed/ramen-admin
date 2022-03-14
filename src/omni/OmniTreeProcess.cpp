// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeProcess.h"

OmniTreeProcess::OmniTreeProcess(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreeProcess::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreeProcess::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
