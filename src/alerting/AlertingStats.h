// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGSTATS_H_200525
#define ALERTINGSTATS_H_200525
#include <QWidget>

#include "ConfChange.h"

class QLabel;
class QTimer;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
}  // namespace gen
}  // namespace dessser

class AlertingStats : public QWidget {
  Q_OBJECT

  QLabel *numFiringIncidentsWidget;
  QLabel *numIncidentsWidget;
  QLabel *numTeamsWidget;
  QLabel *numDialogsWidget;
  QLabel *lastNotificationWidget;
  QLabel *oldestNotificationWidget;
  QLabel *lastDeliveryAttemptWidget;
  QLabel *nextScheduleWidget;
  QLabel *nextSendWidget;

  // Start dirty because of the missed sync:
  bool dirty = true;
  QTimer *timer;

  bool isMyKey(dessser::gen::sync_key::t const &) const;

  void updateStats();

 public:
  AlertingStats(QWidget *parent = nullptr);

 protected slots:
  void onChange(QList<ConfChange> const &);
};

#endif
