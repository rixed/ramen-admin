// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ConfTreeItem.h"

#include <QDateTime>
#include <optional>

#include "ConfTreeWidget.h"  // for CONFTREE_WIDGET_NUM_COLUMNS
#include "KVStore.h"
#include "Resources.h"
#include "desssergen/sync_key.h"
#include "misc.h"

ConfTreeItem::ConfTreeItem(
    std::shared_ptr<dessser::gen::sync_key::t const> key_, QString const name_,
    ConfTreeItem *parent, ConfTreeItem *preceding)
    : QTreeWidgetItem(parent, preceding, UserType), name(name_), key(key_) {}

QVariant ConfTreeItem::data(int column, int role) const {
  Q_ASSERT(column < CONFTREE_WIDGET_NUM_COLUMNS);

  if (role == Qt::DecorationRole && column == 2 && key) {
    Resources *r = Resources::get();
    bool isLocked = false;
    kvs->lock.lock_shared();
    auto it = kvs->map.find(key);
    if (it != kvs->map.end()) isLocked = it->second.isLocked();
    kvs->lock.unlock_shared();
    return isLocked ? QIcon(r->lockedPixmap) : QVariant();
  }

  if (role != Qt::DisplayRole) return QVariant();

  if (0 == column) return QVariant(name);

  if (!key) return QVariant();

  switch (column) {
    case 2:  // lock status
      // k for the lock, and then maybe "locked by ... until ..."
      {
        bool isLocked = false;
        std::optional<QString> owner;
        double expiry;
        kvs->lock.lock_shared();
        auto it = kvs->map.find(key);
        if (it != kvs->map.end()) {
          isLocked = it->second.isLocked();
          owner = it->second.owner;
          expiry = it->second.expiry;
        }
        kvs->lock.unlock_shared();
        if (isLocked) {
          return QString(QString("locked by ") + *owner + QString(" until ") +
                         stringOfDate(expiry));
        } else {
          return QString("");
        }
      }
    // Column 1 is the view/edit widget that's set once and for all at creation
    // time
    default:
      return QVariant();
  }
}
