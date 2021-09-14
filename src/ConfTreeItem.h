#ifndef CONFTREEITEM_H_190715
#define CONFTREEITEM_H_190715
#include <optional>
#include <QPixmap>
#include <QString>

#include <QTreeWidgetItem>

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
  }
}

class ConfTreeItem : public QTreeWidgetItem
{
  friend class ConfTreeWidget;  // for calling emitDataChanged

public:
  /* While we already have a map of keys to values in conf::kvs, it is
   * organized as a prefix-tree (still TODO BTW) which is the best structure
   * for matching arbitrary globs, whereas For the ConfTreeview we need a
   * tree that's split at the slash borders (either from between key names or
   * path components names in program or source names).
   * Therefore we build yet another representation of the tree of keys as a
   * simple tree of strings. */
  QString const name;
  std::optional<dessser::gen::sync_key::t const> key;

  ConfTreeItem(
    std::optional<dessser::gen::sync_key::t const>,
    QString const,
    ConfTreeItem *parent = nullptr,
    ConfTreeItem *preceding = nullptr);

  QVariant data(int column, int role) const;
};

#endif