// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "storage/StorageTreeModel.h"

#include <QDebug>

#include "FunctionItem.h"
#include "GraphModel.h"

static constexpr bool verbose{false};

StorageTreeModel::StorageTreeModel(QObject *parent)
    : QSortFilterProxyModel(parent) {
  setDynamicSortFilter(true);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  setRecursiveFilteringEnabled(true);
#endif
}

bool StorageTreeModel::filterAcceptsRow(int sourceRow,
                                        const QModelIndex &sourceParent) const {
  GraphModel *graphModel{static_cast<GraphModel *>(sourceModel())};
  QModelIndex const index{graphModel->index(sourceRow, 0, sourceParent)};
  GraphItem const *graphItem{graphModel->itemOfIndex(index)};
  FunctionItem const *functionItem{
      dynamic_cast<FunctionItem const *>(graphItem)};
  if (!functionItem) {
    if (verbose)
      qDebug() << "StorageTreeModel: Item" << graphItem->shared->name
               << "is not a function";
    return false;
  }
  std::shared_ptr<Function const> shr{
      std::static_pointer_cast<Function const>(functionItem->shared)};
  if (!shr) {
    if (verbose) qDebug() << "StorageTreeModel: Function has no shared data!?";
    return false;
  }
  if (!shr->archivedTimes || shr->archivedTimes->empty()) {
    if (verbose)
      qDebug() << "StorageTreeModel: Function" << shr->name
               << "has no archives";
    return false;
  }

  if (verbose)
    qDebug() << "StorageTreeModel: Function" << shr->name << "has archives!";
  return true;
}
