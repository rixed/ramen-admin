// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGJOURNAL_H_200615
#define ALERTINGJOURNAL_H_200615
#include <QWidget>

class AlertingLogsModel;
class QTableView;

class AlertingJournal : public QWidget {
  Q_OBJECT

  QTableView *tableView;

  bool wantResize;

 public:
  AlertingJournal(AlertingLogsModel *model, QWidget *parent = nullptr);

 private slots:
  /* Initial synchronization can be slowed down significantly by the
   * constant addition and resizing of the AlertingJournal therefore a timer
   * limits the rate of calls to resizeColumns: */
  void wantResizeColumns();
  void resizeColumns();
};
#endif
