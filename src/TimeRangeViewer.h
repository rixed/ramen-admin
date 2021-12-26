// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMERANGEVIEWER_H_190801
#define TIMERANGEVIEWER_H_190801
#include "AtomicWidget.h"

/* Although time-ranges are read-only, all "editors" must be AtomicWidgets.
 */

class QTableWidget;

class TimeRangeViewer : public AtomicWidget {
  Q_OBJECT

  QTableWidget *table;

 public:
  TimeRangeViewer(QWidget *parent = nullptr);
  void setEnabled(bool) {}

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
