#ifndef DASHBOARDSELECTOR_H_200320
#define DASHBOARDSELECTOR_H_200320
/* A widget to pick a dashboard */
#include <string>

#include "TreeComboBox.h"

class DashboardTreeModel;

class DashboardSelector : public TreeComboBox
{
  Q_OBJECT

public:
  DashboardSelector(DashboardTreeModel *model, QWidget *parent = nullptr);

  // Returns the dashboard name:
  std::string getCurrent() const;
};

#endif
