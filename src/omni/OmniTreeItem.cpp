// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeItem.h"

OmniTreeItem::OmniTreeItem(QString name_, OmniTreeItem *parent_)
    : name(name_), parent(parent_) {
  children.reserve(20);
}

bool OmniTreeItem::isRoot() const { return parent == nullptr; }

bool OmniTreeItem::isLeaf() const { return children.empty(); }

void OmniTreeItem::addItem(OmniTreeItem *item) {
  auto child{children.cbegin()};
  while (child != children.cend() && item->name < (*child)->name) {
    child++;
  }
  children.insert(child, item);
}

int OmniTreeItem::rowCount() const { return children.size(); }
