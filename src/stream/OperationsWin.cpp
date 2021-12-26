// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "OperationsWin.h"

#include "GraphModel.h"
#include "OperationsView.h"

OperationsWin::OperationsWin(QWidget *parent)
    : SavedWindow("OperationsGraph", tr("Graph of Operations"), true, parent) {
  OperationsView *operationsView =
      new OperationsView(GraphModel::globalGraphModel);
  setCentralWidget(operationsView);
}
