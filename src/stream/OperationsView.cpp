// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "stream/OperationsView.h"

#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QItemSelectionModel>
#include <QRadioButton>
#include <QTreeView>
#include <QVBoxLayout>

#include "FunctionItem.h"
#include "GraphModel.h"
#include "GraphView.h"
#include "Menu.h"
#include "ProgramItem.h"
#include "ProgramPartItem.h"
#include "TailModel.h"
#include "TailTable.h"
#include "misc.h"
#include "source/SourcesWin.h"

static bool const verbose{false};

/* For some unfathomable reason the QTreeView sizeHint always return a width
 * of 256, and this is read only. So to change the actual default size of a
 * QTreeView, it seems the only way is to subclass it: */
class NarrowTreeView : public QTreeView {
 public:
  NarrowTreeView(QWidget *parent = nullptr) : QTreeView(parent) {}
  QSize sizeHint() const { return QSize(100, 42); }
};

OperationsView::OperationsView(GraphModel *graphModel, QWidget *parent)
    : QSplitter(parent), allowReset(true) {
  // On the top side, we have another splitter to separate the treeview
  // from the graphview:
  QWidget *leftPannel{new QWidget};
  QVBoxLayout *leftPannelLayout{new QVBoxLayout};
  leftPannelLayout->setContentsMargins(1, 1, 1, 1);
  leftPannelLayout->setSpacing(3);

  QWidget *LODBar{new QWidget};
  QHBoxLayout *LODBarLayout{new QHBoxLayout};
  LODBarLayout->setContentsMargins(1, 1, 1, 1);
  LODBarLayout->setSpacing(3);
  toSites = new QRadioButton("&sites", LODBar);
  toPrograms = new QRadioButton("&programs", LODBar);
  toFunctions = new QRadioButton("&functions", LODBar);
  LODBarLayout->addWidget(toSites);
  LODBarLayout->addWidget(toPrograms);
  LODBarLayout->addWidget(toFunctions);
  LODBar->setLayout(LODBarLayout);
  leftPannelLayout->addWidget(LODBar);

  treeView = new NarrowTreeView();
  treeView->setModel(graphModel);
  treeView->setHeaderHidden(true);
  treeView->setUniformRowHeights(true);
  /* Hide all columns but the name: */
  for (int c = 0; c < GraphModel::Columns::NumColumns; c++) {
    if (c != GraphModel::Columns::Name) treeView->hideColumn(c);
  }

  leftPannelLayout->addWidget(treeView);

  leftPannel->setLayout(leftPannelLayout);

  addWidget(leftPannel);
  setStretchFactor(0, 0);

  GraphView *graphView{new GraphView(graphModel->settings)};
  graphView->setModel(graphModel);
  addWidget(graphView);
  setStretchFactor(1, 1);

  // Control the GraphView from the TreeView:
  connect(treeView, &NarrowTreeView::collapsed, graphView,
          &GraphView::collapse);
  connect(treeView, &NarrowTreeView::expanded, graphView, &GraphView::expand);
  connect(treeView, &NarrowTreeView::clicked, graphView, &GraphView::select);
  // And the other way around:
  connect(graphView, &GraphView::selected, treeView,
          &NarrowTreeView::setCurrentIndex);

  // Control the TreeView from the LOD buttons:
  connect(toSites, &QRadioButton::clicked, this, &OperationsView::setLOD);
  connect(toPrograms, &QRadioButton::clicked, this, &OperationsView::setLOD);
  connect(toFunctions, &QRadioButton::clicked, this, &OperationsView::setLOD);

  // Reset the LOD buttons when manually changing the TreeView:
  connect(treeView, &NarrowTreeView::collapsed, this,
          &OperationsView::resetLOD);
  connect(treeView, &NarrowTreeView::expanded, this, &OperationsView::resetLOD);

  // Also display in the sources window the selected programs:
  connect(graphView, &GraphView::selected, this, &OperationsView::selectItem);
  connect(this, &OperationsView::programSelected, this,
          &OperationsView::showSource);
  connect(this, &OperationsView::functionSelected, this,
          &OperationsView::showFuncInfo);
}

// slot to reset the LOD radio buttons
void OperationsView::resetLOD() {
  if (!allowReset) return;

  toSites->setAutoExclusive(false);
  toPrograms->setAutoExclusive(false);
  toFunctions->setAutoExclusive(false);
  toSites->setChecked(false);
  toPrograms->setChecked(false);
  toFunctions->setChecked(false);
  toSites->setAutoExclusive(true);
  toPrograms->setAutoExclusive(true);
  toFunctions->setAutoExclusive(true);
}

void OperationsView::setLOD(bool) {
  /* collapseAll and friends will unfortunately emit the collapsed signal,
   * which in turn will reset the Radio. So disable this temporarily: */
  allowReset = false;
  if (toSites->isChecked()) {
    treeView->collapseAll();
  } else if (toPrograms->isChecked()) {
    // Must expand everything down to, but excluding, function:
    int const num_rows{treeView->model()->rowCount()};
    if (num_rows > 0)
      expandAllFromParent(treeView, QModelIndex(), 0, num_rows - 1, true);
  } else if (toFunctions->isChecked()) {
    treeView->expandAll();
  }
  allowReset = true;
}

void OperationsView::selectItem(QModelIndex const &index) {
  if (!index.isValid()) return;

  GraphItem *gi{static_cast<GraphItem *>(index.internalPointer())};
  ProgramPartItem *p{dynamic_cast<ProgramPartItem *>(gi)};
  if (p) {
    // Ignore the user selecting a non-leaf program part:
    if (!p->actualProgram) return;
    emit programSelected(p->actualProgram);
    return;
  }

  FunctionItem *f{dynamic_cast<FunctionItem *>(gi)};
  if (f) {
    emit functionSelected(f);
    return;
  }
}

void OperationsView::showSource(ProgramItem const *p) {
  if (!Menu::sourcesWin) return;

  std::string const src_path{
      srcPathFromProgramName(p->shared->name.toStdString())};
  if (verbose)
    qDebug() << "Show source of program" << QString::fromStdString(src_path);
  Menu::sourcesWin->showFile(src_path);
}

// Same as above but also scroll down to that function:
void OperationsView::showFuncInfo(FunctionItem const *f) {
  if (!Menu::sourcesWin) return;

  ProgramItem const *programItem{
      dynamic_cast<ProgramItem const *>(f->graphicsParent())};
  Q_ASSERT(programItem);

  std::string const src_path{
      srcPathFromProgramName(programItem->shared->name.toStdString())};
  if (verbose)
    qDebug() << "Show source of function" << QString::fromStdString(src_path);
  Menu::sourcesWin->showFile(src_path);
}
