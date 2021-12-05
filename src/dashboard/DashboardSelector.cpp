#include "ConfSubTree.h"
#include "dashboard/DashboardTreeModel.h"
#include "dashboard/tools.h"
#include "UserIdentity.h"

#include "dashboard/DashboardSelector.h"

DashboardSelector::DashboardSelector(
  DashboardTreeModel *model, QWidget *parent)
  : TreeComboBox(parent)
{
  Q_ASSERT(model);
  setModel(model);
  setAllowNonLeafSelection(false);

  setSizeAdjustPolicy(QComboBox::AdjustToContents);
}

std::string DashboardSelector::getCurrent() const
{
  QModelIndex const index { TreeComboBox::getCurrent() };
  ConfSubTree const *selected { static_cast<ConfSubTree *>(index.internalPointer()) };
  QString const dash_name { selected->nameFromRoot("/") };

  if (dash_name == "scratchpad") {
    return std::string(SCRATCHPAD);
  } else {
    return dash_name.toStdString();
  }
}
