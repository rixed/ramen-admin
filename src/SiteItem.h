// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef SITEITEM_H_190509
#define SITEITEM_H_190509
#include <QString>
#include <optional>
#include <vector>

#include "GraphItem.h"

struct GraphViewSettings;
class ProgramItem;
class ProgramPartItem;

struct Site : public GraphData {
  std::optional<bool> isMaster;

  Site(QString const &name_) : GraphData(name_) {}
};

class SiteItem : public GraphItem {
 protected:
  std::vector<std::pair<QString const, QString const> > labels() const override;

 public:
  /* Whenever we need a 3 layers tree (site/progra/function), use this
   * set of programs: */
  std::vector<ProgramItem *> programs;

  /* But when the full tree of path components is needed, for instance for
   * the GraphModel to fold the program components, use this.
   * Eventually the same FunctionItems are reached by programs and programParts.
   */
  std::vector<ProgramPartItem *> programParts;

  SiteItem(std::unique_ptr<Site>, GraphViewSettings const &);

  void reorder(GraphModel *);

  // The box representing the operation, regardless of its border (unlike
  // boundingRect):
  QRectF operationRect() const override;

  bool isTopHalf() const override { return false; }

  bool isUsed() const override { Q_ASSERT(false); }

  bool isRunning() const override { Q_ASSERT(false); }

  bool isWorking() const override { Q_ASSERT(false); }

  bool isViewable() const override { return true; }

  operator QString() const;
};

#endif
