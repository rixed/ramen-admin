// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingJournal.h"

#include <QHeaderView>
#include <QTableView>
#include <QVBoxLayout>

#include "alerting/AlertingLogsModel.h"

AlertingJournal::AlertingJournal(AlertingLogsModel *model, QWidget *parent)
    : QWidget(parent) {
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

  connect(model, &AlertingLogsModel::rowsInserted, this,
          &AlertingJournal::resizeColumns);
}

void AlertingJournal::resizeColumns() {
  int const rows{tableView->model()->rowCount()};
  if (rows < 16 || (rows & 15) == 0) tableView->resizeColumnToContents(0);
}
