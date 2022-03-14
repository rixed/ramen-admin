// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "omni/OmniTreeModel.h"

#include "omni/OmniTreeItem.h"

OmniTreeModel::OmniTreeModel(QObject *parent)
    : QAbstractItemModel(parent), root(nullptr) {
  // TODO: connect to the KVStore to add items
}

OmniTreeItem *OmniTreeModel::getItem(QModelIndex const &index) const {
  return index.isValid() ? static_cast<OmniTreeItem *>(index.internalPointer())
                         : root;
}

QModelIndex OmniTreeModel::index(int row, int column,
                                 QModelIndex const &parent_index) const {
  if (!root) {
    Q_ASSERT(!parent_index.isValid());
    return QModelIndex();
  }

  OmniTreeItem *parent{getItem(parent_index)};
  if (row < 0 || row >= parent->rowCount() || column < 0 ||
      column >= parent->columnCount())
    return QModelIndex();
  return createIndex(row, column, parent);
}

QModelIndex OmniTreeModel::parent(QModelIndex const &index) const {
  Q_ASSERT(index.isValid());
  Q_ASSERT(root);  // because the index is valid

  OmniTreeItem *item{static_cast<OmniTreeItem *>(index.internalPointer())};
  if (item->parent) {
    for (int row = 0; row < (int)item->parent->children.size(); row++) {
      if (item->parent->children[row] != item) continue;
      return createIndex(row, 0, item->parent);
    }
    Q_ASSERT(false);
  } else {
    Q_ASSERT(item == root);
    return QModelIndex();
  }
}

int OmniTreeModel::rowCount(QModelIndex const &parent_index) const {
  OmniTreeItem *parent{getItem(parent_index)};
  Q_ASSERT(parent);

  return parent->rowCount();
}

int OmniTreeModel::columnCount(QModelIndex const &parent_index) const {
  OmniTreeItem *parent{getItem(parent_index)};
  Q_ASSERT(parent);

  return parent->columnCount();
}

QVariant OmniTreeModel::data(QModelIndex const &index, int role) const {
  OmniTreeItem *item{getItem(index)};
  return item->data(role);
}
