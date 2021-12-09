#ifndef DASHBOARDTREEMODEL_H_200320
#define DASHBOARDTREEMODEL_H_200320
#include <memory>

#include "ConfTreeModel.h"
#include "ConfChange.h"

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
    namespace sync_value { struct t; }
  }
}

class DashboardTreeModel : public ConfTreeModel
{
  Q_OBJECT

  void updateNames(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &);
  void deleteNames(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &);

public:
  static DashboardTreeModel *globalDashboardTree;

  DashboardTreeModel(QObject *parent = nullptr);

  // Make sure non-leaf nodes are not selectable:
  Qt::ItemFlags flags(QModelIndex const &) const override;

protected slots:
  void onChange(QList<ConfChange> const &);
};

#endif
