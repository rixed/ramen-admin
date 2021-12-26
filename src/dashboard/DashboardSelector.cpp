// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "dashboard/DashboardSelector.h"

#include "ConfSubTree.h"
#include "UserIdentity.h"
#include "dashboard/DashboardTreeModel.h"
#include "dashboard/tools.h"

DashboardSelector::DashboardSelector(DashboardTreeModel *model, QWidget *parent)
    : TreeComboBox(parent) {
  Q_ASSERT(model);
  setModel(model);
  setAllowNonLeafSelection(false);

  setSizeAdjustPolicy(QComboBox::AdjustToContents);
}

std::optional<std::string> DashboardSelector::getCurrent() const {
  QModelIndex const index{TreeComboBox::getCurrent()};
  // Non leaf selected?
  if (!index.isValid()) return std::nullopt;

  ConfSubTree const *selected{
      static_cast<ConfSubTree *>(index.internalPointer())};
  Q_ASSERT(selected);  // Since one is not allowed to select non-leaf
  QString const dash_name{selected->nameFromRoot("/")};

  if (dash_name == "scratchpad") {
    return std::string(SCRATCHPAD);
  } else {
    return dash_name.toStdString();
  }
}
