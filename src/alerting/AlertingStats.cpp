#include <limits>
#include <memory>
#include <QDebug>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>

#include "alerting/tools.h"
#include "desssergen/alerting_delivery_status.h"
#include "desssergen/alerting_notification.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "KVStore.h"
#include "misc.h"

#include "alerting/AlertingStats.h"

static bool const verbose { false };

AlertingStats::AlertingStats(QWidget *parent)
  : QWidget(parent)
{
  lastNotificationWidget = new QLabel;
  oldestNotificationWidget = new QLabel;
  lastDeliveryAttemptWidget = new QLabel;
  nextScheduleWidget = new QLabel;
  nextSendWidget = new QLabel;
  numTeamsWidget = new QLabel;
  numIncidentsWidget = new QLabel;
  numFiringIncidentsWidget = new QLabel;
  numDialogsWidget = new QLabel;

  QHBoxLayout *layout { new QHBoxLayout };
  QFormLayout *leftCol { new QFormLayout };
  QFormLayout *rightCol { new QFormLayout };
  leftCol->addRow(tr("Number of Firing Incidents:"), numFiringIncidentsWidget);
  leftCol->addRow(tr("Number of Incidents:"), numIncidentsWidget);
  leftCol->addRow(tr("Number of Teams:"), numTeamsWidget);
  leftCol->addRow(tr("Number of Messaging contexts:"), numDialogsWidget);
  rightCol->addRow(tr("Last Notification:"), lastNotificationWidget);
  rightCol->addRow(tr("Oldest Notification:"), oldestNotificationWidget);
  rightCol->addRow(tr("Last Delivery Attemps:"), lastDeliveryAttemptWidget);
  rightCol->addRow(tr("Next Scheduled Run:"), nextScheduleWidget);
  rightCol->addRow(tr("Next Scheduled Delivery:"), nextSendWidget);
  layout->addLayout(leftCol);
  layout->addLayout(rightCol);
  setLayout(layout);

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout,
          this, QOverload<>::of(&AlertingStats::updateStats));

  connect(kvs.get(), &KVStore::keyChanged,
          this, &AlertingStats::onChange);

  timer->start(2000);
}

void AlertingStats::updateStats()
{
  if (verbose)
    qDebug() << "AlertingStats::updateStats: dirty=" << dirty;

  if (! dirty) return;

  int numFiringIncidents { 0 };
  int numIncidents { 0 };
  int numDialogs[dessser::gen::alerting_delivery_status::t::size] { 0 };
  double lastNotification { 0. };
  double oldestNotification { std::numeric_limits<double>::max() };
  double lastDeliveryAttempt { 0. };
  double nextSchedule { std::numeric_limits<double>::max() };
  double nextSend { std::numeric_limits<double>::max() };

  std::function<void(std::shared_ptr<dessser::gen::alerting_notification::t const> const)> updateNotifDates {
    [&lastNotification, &oldestNotification]
    (std::shared_ptr<dessser::gen::alerting_notification::t const> const notif)
    {
      lastNotification = std::max<double>(lastNotification, notif->sent_time);
      oldestNotification = std::min<double>(oldestNotification, notif->sent_time);
    }
  };

  /* Update all stats in one go: */
  int numTeams { 0 };
  iterTeams([&numTeams](std::string const &) { numTeams ++; });

  iterIncidents([&numFiringIncidents, &numIncidents, &numDialogs,
                 &lastDeliveryAttempt, &nextSchedule, &nextSend,
                 &updateNotifDates](std::string const &incidentId)
    {
      numIncidents ++;

      std::shared_ptr<dessser::gen::alerting_notification::t const> const firstStartNotif {
        getIncidentNotif(incidentId,
                         std::make_shared<dessser::gen::sync_key::incident_key>(
                           std::in_place_index<dessser::gen::sync_key::FirstStartNotif>,
                           dessser::VOID)) };
      if (firstStartNotif) {
        updateNotifDates(firstStartNotif);
      }

      std::shared_ptr<dessser::gen::alerting_notification::t const> const lastChangeNotif {
        getIncidentNotif(incidentId,
                         std::make_shared<dessser::gen::sync_key::incident_key>(
                           std::in_place_index<dessser::gen::sync_key::LastStateChangeNotif>,
                           dessser::VOID)) };
      if (lastChangeNotif) {
        if (lastChangeNotif->firing) numFiringIncidents ++;
        updateNotifDates(lastChangeNotif);
      }

      iterDialogs(incidentId,
                  [&numDialogs, &lastDeliveryAttempt, &nextSchedule, &nextSend,
                   &incidentId](std::string const &dialogId) {
        std::shared_ptr<dessser::gen::sync_value::t const> deliveryStatus_v {
          getDialog(incidentId, dialogId,
                    std::make_shared<dessser::gen::sync_key::dialog_key>(
                      std::in_place_index<dessser::gen::sync_key::DeliveryStatus>,
                      dessser::VOID)) };
        if (deliveryStatus_v &&
            deliveryStatus_v->index() == dessser::gen::sync_value::DeliveryStatus) {
          std::shared_ptr<dessser::gen::alerting_delivery_status::t const> const deliveryStatus {
            std::get<dessser::gen::sync_value::DeliveryStatus>(*deliveryStatus_v) };
          Q_ASSERT(deliveryStatus->index() < SIZEOF_ARRAY(numDialogs));
          numDialogs[deliveryStatus->index()] ++;
        }

        std::optional<double> const lastDelivAttempt {
          getDialogDate(incidentId, dialogId,
                        std::make_shared<dessser::gen::sync_key::dialog_key>(
                          std::in_place_index<dessser::gen::sync_key::LastDeliveryAttempt>,
                          dessser::VOID)) };
        if (lastDelivAttempt)
          lastDeliveryAttempt =
            std::max<double>(lastDeliveryAttempt, *lastDelivAttempt);

        std::optional<double> const nextSched {
          getDialogDate(incidentId, dialogId,
                        std::make_shared<dessser::gen::sync_key::dialog_key>(
                          std::in_place_index<dessser::gen::sync_key::NextScheduled>,
                          dessser::VOID)) };
        if (nextSched)
          nextSchedule =
            std::min<double>(nextSchedule, *lastDelivAttempt);

        std::optional<double> const nextSnd {
          getDialogDate(incidentId, dialogId,
                        std::make_shared<dessser::gen::sync_key::dialog_key>(
                          std::in_place_index<dessser::gen::sync_key::NextSend>,
                          dessser::VOID)) };
        if (nextSnd)
          nextSend =
            std::min<double>(nextSend, *nextSnd);
      });
    });

  numTeamsWidget->setText(QString::number(numTeams));

  numFiringIncidentsWidget->setText(QString::number(numFiringIncidents));
  numIncidentsWidget->setText(QString::number(numIncidents));
  QStringList numDialogsStr;
  if (numDialogs[dessser::gen::alerting_delivery_status::StartToBeSent] > 0)
    numDialogsStr.append(
      QString::number(numDialogs[dessser::gen::alerting_delivery_status::StartToBeSent]) +
      " alerts to be sent");
  if (numDialogs[dessser::gen::alerting_delivery_status::StartToBeSentThenStopped] > 0)
    numDialogsStr.append(
      QString::number(numDialogs[dessser::gen::alerting_delivery_status::StartToBeSentThenStopped]) +
      " stopped before alert delivery attempted");
  if (numDialogs[dessser::gen::alerting_delivery_status::StartSent] > 0)
    numDialogsStr.append(
      QString::number(numDialogs[dessser::gen::alerting_delivery_status::StartSent]) +
      " alerts sent");
  if (numDialogs[dessser::gen::alerting_delivery_status::StartAcked] > 0)
    numDialogsStr.append(
      QString::number(numDialogs[dessser::gen::alerting_delivery_status::StartAcked]) +
      " alerts acked");
  if (numDialogs[dessser::gen::alerting_delivery_status::StopToBeSent] > 0)
    numDialogsStr.append(
      QString::number(numDialogs[dessser::gen::alerting_delivery_status::StopToBeSent]) +
      " recovery to be sent");
  if (numDialogs[dessser::gen::alerting_delivery_status::StopSent] > 0)
    numDialogsStr.append(
      QString::number(numDialogs[dessser::gen::alerting_delivery_status::StopSent]) +
      " recovery sent");
  numDialogsWidget->setText(numDialogsStr.join(",\n"));
  lastNotificationWidget->setText(stringOfDate(lastNotification));
  oldestNotificationWidget->setText(stringOfDate(oldestNotification));
  lastDeliveryAttemptWidget->setText(stringOfDate(lastDeliveryAttempt));
  nextScheduleWidget->setText(stringOfDate(nextSchedule));
  nextSendWidget->setText(stringOfDate(nextSend));
}

bool AlertingStats::isMyKey(dessser::gen::sync_key::t const &k) const
{
  return
    k.index() == dessser::gen::sync_key::Teams ||
    k.index() == dessser::gen::sync_key::Incidents;
}

void AlertingStats::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyLocked:
      case KeyUnlocked:
        break;
      case KeyCreated:
      case KeyChanged:
      case KeyDeleted:
        if (! isMyKey(*change.key)) return;
        dirty = true;
        break;
    }
  }
}
