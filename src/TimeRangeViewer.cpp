#include <QtGlobal>
#include <QDebug>
#include <QTableWidget>
#include <QHeaderView>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"

#include "TimeRangeViewer.h"

TimeRangeViewer::TimeRangeViewer(QWidget *parent) :
  AtomicWidget(parent)
{
  table = new QTableWidget(1, 2);
  table->setHorizontalHeaderLabels({ tr("Since"), tr("Until") });
  table->setMinimumWidth(400);
  table->setCornerButtonEnabled(false);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->verticalHeader()->setVisible(false);
  relayoutWidget(table);
}

bool TimeRangeViewer::setValue(
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  /* Empty the previous table */
  table->setRowCount(0); // Keep the header

  if (v->index() == dessser::gen::sync_value::TimeRange) {
    dessser::gen::time_range::t const &timeRange {
      std::get<dessser::gen::sync_value::TimeRange>(*v) };
    size_t const sz { timeRange.size() };
    table->setRowCount(sz);
    for (unsigned i = 0; i < sz; i ++) {
      auto const &r { timeRange[i] };
      QTableWidgetItem *since {
        new QTableWidgetItem(stringOfDate(r.since)) };
      QTableWidgetItem *until {
        new QTableWidgetItem(stringOfDate(r.until) + (
          r.growing ? QString("…") : QString())) };
      table->setItem(i, 0, since);
      table->setItem(i, 1, until);
    }
    table->resizeColumnsToContents();
    // TODO: emit valueChanged?
    return true;
  } else {
    qCritical() << "Not a TimeRange value?!";
    return false;
  }
}
