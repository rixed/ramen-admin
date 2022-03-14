// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREEITEM_H_220313
#define OMNITREEITEM_H_220313
/* Base class for all types of OmniTreeModel items */
#include <QString>
#include <QVariant>
#include <vector>

class QAbstractItemModel;

class OmniTreeItem {
 public:
  QString name;

  OmniTreeItem *parent;  // nullptr for root

  std::vector<OmniTreeItem *> children;

  enum Columns {
    Name = 0,
    Action1,
    Action2,
    Action3,
    NumColumns,
  };

  OmniTreeItem(QString name, OmniTreeItem *parent);
  virtual ~OmniTreeItem() {}

  bool isRoot() const;

  bool isLeaf() const;

  // Use alphabetical order:
  void addItem(OmniTreeItem *item);

  /* Implementation of the QAbstractItemModel: */

  int rowCount() const;

  virtual int columnCount() const = 0;

  virtual QVariant data(int role) const = 0;
};

#endif
