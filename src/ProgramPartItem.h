// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef PROGRAMPARTITEM_H_190509
#define PROGRAMPARTITEM_H_190509
#include <QString>
#include <vector>

#include "GraphItem.h"

class FunctionItem;
class GraphModel;
struct GraphViewSettings;
class ProgramItem;

struct ProgramPart : public GraphData {
  ProgramPart(QString const &name_) : GraphData(name_) {}
};

class ProgramPartItem : public GraphItem {
 protected:
  std::vector<std::pair<QString const, QString const> > labels()
      const override {
    return {};
  }

 public:
  std::vector<ProgramPartItem *> subParts;

  /* If this part is also the final part of an actual program, its functions
   * are also children of this GraphItem.
   * Important note: there can still be subParts leading to other programs. */
  ProgramItem *actualProgram;

  ProgramPartItem(GraphItem *treeParent, std::unique_ptr<ProgramPart>,
                  ProgramItem *actualProgram, GraphViewSettings const &);

  bool isTopHalf() const override;

  bool isWorking() const override;

  bool isUsed() const override;

  /* Some of the functions are running, which will be none of them if the
   * program is conditionally disabled: */
  bool isRunning() const override;

  bool isViewable() const override { return false; }

  void reorder(GraphModel *);

  QRectF operationRect() const override { return QRectF{}; }

  operator QString() const;
};

#endif
