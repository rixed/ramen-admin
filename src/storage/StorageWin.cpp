// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "storage/StorageWin.h"

#include <QLabel>

#include "GraphModel.h"
#include "storage/StorageView.h"

StorageWin::StorageWin(QWidget *parent)
    : SavedWindow("Storage", tr("Storage"), true, parent) {
  if (GraphModel::globalGraphModel) {
    // TODO: a globalGraphModelWithoutTopHalves
    StorageView *storageView{new StorageView(GraphModel::globalGraphModel)};
    setCentralWidget(storageView);
  } else {
    QString errMsg{tr("No graph model yet!?")};
    setCentralWidget(new QLabel(errMsg));
    // Better luck next time?
    setAttribute(Qt::WA_DeleteOnClose);
  }
}
