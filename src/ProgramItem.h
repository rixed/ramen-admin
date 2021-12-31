// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef PROGRAMITEM_H_190509
#define PROGRAMITEM_H_190509
#include <QModelIndex>
#include <QString>
#include <vector>

#include "GraphItem.h"

class FunctionItem;
struct GraphViewSettings;
class ProgramPartItem;

struct Program : public GraphData {
  Program(QString const &name_) : GraphData(name_) {}
};

class ProgramItem : public GraphItem {
 protected:
  std::vector<std::pair<QString const, QString const> > labels() const override;

 public:
  /* As we are going to point to item from their children we do not want them
   * to move in memory, so we can use a vector of pointers: */
  std::vector<FunctionItem *> functions;

  /* The last ProgramPartItem corresponding to this ProgramItem: */
  ProgramPartItem *lastProgramPartItem;

  ProgramItem(GraphItem *treeParent, std::unique_ptr<Program>,
              GraphViewSettings const *);

  /* As the ProgramItem is not really part of the QAbstractItemModel any more,
   * it should never be indexed: */
  QModelIndex index(GraphModel const *, int) const override {
    Q_ASSERT(false);
    return QModelIndex();
  }

  QVariant data(int column, int role) const;

  void reorder(GraphModel *);

  QRectF operationRect() const override;

  bool isTopHalf() const override;

  bool isWorking() const override;

  bool isUsed() const override;

  /* Some of the functions are running, which will be none of them if the
   * program is conditionally disabled: */
  bool isRunning() const override;

  operator QString() const;

  QString const typeName() const { return QString("ProgramItem"); }
};

#endif
