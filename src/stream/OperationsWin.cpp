#include "OperationsWin.h"

#include "GraphModel.h"
#include "OperationsView.h"

OperationsWin::OperationsWin(QWidget *parent)
    : SavedWindow("OperationsGraph", tr("Graph of Operations"), true, parent) {
  OperationsView *operationsView =
      new OperationsView(GraphModel::globalGraphModel);
  setCentralWidget(operationsView);
}
