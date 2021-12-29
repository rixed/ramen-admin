// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef SITEITEM_H_190509
#define SITEITEM_H_190509
#include <QString>
#include <optional>
#include <vector>

#include "GraphItem.h"

struct GraphViewSettings;
class ProgramItem;

struct Site : public GraphData {
  std::optional<bool> isMaster;

  Site(QString const &name_) : GraphData(name_) {}
};

class SiteItem : public GraphItem {
 protected:
  std::vector<std::pair<QString const, QString const> > labels() const;

 public:
  std::vector<ProgramItem *> programs;

  SiteItem(GraphItem *treeParent, std::unique_ptr<Site>,
           GraphViewSettings const &);

  void reorder(GraphModel *) override;

  QRectF operationRect() const override;

  bool isTopHalf() const override { return false; }

  bool isUsed() const override { Q_ASSERT(false); }

  bool isRunning() const override { Q_ASSERT(false); }

  bool isWorking() const override { Q_ASSERT(false); }


  operator QString() const;
};

#endif
