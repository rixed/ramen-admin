// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef CONFTREEMODEL_H_200320
#define CONFTREEMODEL_H_200320
/* Abstract class to help build global tree-models from the configuration */
#include <QAbstractItemModel>
#include <QStringList>

#include "ConfChange.h"

class ConfSubTree;
struct KValue;

class ConfTreeModel : public QAbstractItemModel {
  Q_OBJECT

 public:
  ConfSubTree *root;

  ConfSubTree *findOrCreate(
      // The root where to search for the item:
      ConfSubTree *,
      // This QStringList will be emptied:
      QStringList &,
      /* Therefore this "const" QString must not belong to the above
       * list. To ensure this, it is purposefully passed as copy: */
      QString const termValue);

  ConfTreeModel(QObject *parent = nullptr);

  virtual ~ConfTreeModel();

  // on configuration changes:
  virtual void onChange(QList<ConfChange> const &) = 0;

  void dump() const;

  // The QAbstractModel:
  QModelIndex index(int, int, QModelIndex const &) const;

  QModelIndex parent(QModelIndex const &) const;

  int rowCount(QModelIndex const &) const;

  int columnCount(QModelIndex const &) const;

  QVariant data(QModelIndex const &, int = Qt::DisplayRole) const;

  QModelIndex find(std::string const &) const;

  bool isTerm(QModelIndex const &) const;
};

#endif
