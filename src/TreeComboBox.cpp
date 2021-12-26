// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "TreeComboBox.h"

#include <QHeaderView>
#include <QTreeView>

TreeComboBox::TreeComboBox(QWidget *parent)
    : QComboBox(parent), m_allowNonLeafSelection(true) {
  treeView = new QTreeView;
  treeView->setFrameShape(QFrame::NoFrame);
  treeView->setSelectionBehavior(QTreeView::SelectRows);
  treeView->setRootIsDecorated(false);
  treeView->setWordWrap(true);
  treeView->setAllColumnsShowFocus(true);
  treeView->setItemsExpandable(false);
  treeView->header()->setVisible(false);
  setView(treeView);
}

void TreeComboBox::showPopup() {
  treeView->expandAll();
  QComboBox::showPopup();
}

QModelIndex TreeComboBox::getCurrent() const {
  QModelIndex index{treeView->currentIndex()};

  if (!m_allowNonLeafSelection && treeView->model()->rowCount(index) != 0)
    return QModelIndex();

  return index;
}
