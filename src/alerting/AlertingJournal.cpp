// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingJournal.h"

#include <QHeaderView>
#include <QTableView>
#include <QTimer>
#include <QVBoxLayout>

#include "alerting/AlertingLogsModel.h"

AlertingJournal::AlertingJournal(AlertingLogsModel *model, QWidget *parent)
    : QWidget(parent), wantResize(false) {
  tableView = new QTableView;
  tableView->setSelectionMode(QAbstractItemView::NoSelection);
  tableView->setShowGrid(false);
  tableView->horizontalHeader()->setStretchLastSection(true);
  tableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::ResizeToContents);
  tableView->verticalHeader()->hide();
  tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
  tableView->setModel(model);

  QVBoxLayout *layout{new QVBoxLayout};
  layout->setContentsMargins(QMargins());
  layout->addWidget(tableView);

  setLayout(layout);

  QTimer *resizeTimer{new QTimer(this)};
  connect(resizeTimer, &QTimer::timeout, this, &AlertingJournal::resizeColumns);
  resizeTimer->start(300);  // msec

  connect(model, &AlertingLogsModel::rowsInserted, this,
          &AlertingJournal::wantResizeColumns);
}

void AlertingJournal::wantResizeColumns() { wantResize = true; }

void AlertingJournal::resizeColumns() {
  if (!wantResize) return;
  wantResize = false;
  tableView->resizeColumnToContents(0);
}
