// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeOutput.h"

OmniTreeOutput::OmniTreeOutput(QString name, OmniTreeItem *parent)
    : OmniTreeItem(name, parent) {}

int OmniTreeOutput::columnCount() const { return isLeaf() ? 2 : 1; }

QVariant OmniTreeOutput::data(int role) const {
  (void)role;
  return QVariant();  // TODO
}
