#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "alerting/AlertingJournal.h"
#include "alerting/AlertingLogsModel.h"
#include "alerting/AlertingStats.h"
#include "alerting/AlertingTimeLine.h"

#include "alerting/AlertingWin.h"

AlertingWin::AlertingWin(QWidget *parent)
  : SavedWindow("Alerting", tr("Alerting"), true, parent)
{
  QWidget *widget = new QWidget;

  QVBoxLayout *layout = new QVBoxLayout;

  stats = new AlertingStats;
  layout->addWidget(stats);

  /* Copied from StorageTimeLine which alludes to some issue if not wrapping into another
   * widget: */
  QScrollArea *scrollArea { new QScrollArea };
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  scrollArea->setWidgetResizable(true);
  QWidget *w { new QWidget };
  QVBoxLayout *l1 { new QVBoxLayout };
  w->setLayout(l1);
  timeLine = new AlertingTimeLine;
  l1->addWidget(timeLine);
  l1->setSizeConstraint(QLayout::SetMinimumSize);
  scrollArea->setWidget(w);
  layout->addWidget(scrollArea);

  journal = new AlertingJournal(AlertingLogsModel::globalLogsModel);
  layout->addWidget(journal);

  widget->setLayout(layout);

  setCentralWidget(widget);
}
