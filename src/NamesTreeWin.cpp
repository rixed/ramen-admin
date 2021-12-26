// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "NamesTreeWin.h"

#include <QLabel>
#include <QLineEdit>
#include <QTreeView>
#include <QVBoxLayout>

#include "NamesTree.h"
#include "SavedWindow.h"

NamesTreeWin::NamesTreeWin(QWidget *parent)
    : SavedWindow("Completable Names", tr("Completable Names"), true, parent) {
  if (NamesTree::globalNamesTree) {
    QLineEdit *lineEdit = new QLineEdit;
    // Or use the completer on a NamesSubtree:
    QCompleter *completer = new NamesCompleter(NamesTree::globalNamesTree);
    lineEdit->setCompleter(completer);

    QTreeView *treeWidget = new QTreeView;
    Q_ASSERT(NamesTree::globalNamesTree);
    treeWidget->setModel(NamesTree::globalNamesTree);
    treeWidget->setHeaderHidden(true);
    treeWidget->setUniformRowHeights(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(treeWidget);
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
  } else {
    QString errMsg(tr("No names tree yet!?"));
    setCentralWidget(new QLabel(errMsg));
    // Better luck next time?
    setAttribute(Qt::WA_DeleteOnClose);
  }
}
