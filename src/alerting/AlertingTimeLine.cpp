// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingTimeLine.h"

#include <QDebug>
#include <QFormLayout>
#include <cstdlib>

#include "KVStore.h"
#include "TimeRange.h"
#include "alerting/NotifTimeLine.h"
#include "alerting/tools.h"
#include "desssergen/alerting_log.h"
#include "desssergen/alerting_notification.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "timeline/TimeLine.h"
#include "timeline/TimeLineGroup.h"

static constexpr bool verbose{false};

AlertingTimeLine::AlertingTimeLine(QWidget *parent) : QWidget(parent) {
  formLayout = new QFormLayout;
  formLayout->setSpacing(0);
  formLayout->setLabelAlignment(Qt::AlignLeft);
  // counter weird MacOS default:
  formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
  timeLineGroup = new TimeLineGroup(this);

  qreal const endOfTime{getTime()};
  qreal const beginOfTime{endOfTime - 24 * 3600};
  TimeLine *timeLineTop{
      new TimeLine(beginOfTime, endOfTime, TimeLine::TicksBottom)};
  TimeLine *timeLineBottom{
      new TimeLine(beginOfTime, endOfTime, TimeLine::TicksTop)};
  /* Note: Order of insertion in the group has no influence over order of
   * representation in the QFormLayout: */
  timeLineGroup->add(timeLineTop);
  timeLineGroup->add(timeLineBottom);

  /* *Last* line will always be this timeLine. Lines will be added/removed
   * above to maintain a list of known archiving functions: */
  formLayout->addRow(QString(), timeLineTop);
  formLayout->addRow(QString(), timeLineBottom);

  /* TODO: Add time selector. */
  /* TODO: Add a search filter. */

  setLayout(formLayout);

  iterIncidents([this](std::string const &incidentId) {
    iterLogs(incidentId,
             [this, &incidentId](
                 double time,
                 std::shared_ptr<dessser::gen::alerting_log::t const> log) {
               addLog(incidentId, time, log);
             });
  });

  connect(kvs.get(), &KVStore::keyChanged, this,
          &AlertingTimeLine::onKeyChange);
}

void AlertingTimeLine::updateVisibility() {}

/* Just record it and update the visibility flag of existing time lines */
void AlertingTimeLine::setTimeRange(TimeRange const &range) {
  timeRange = range;
  updateVisibility();
}

void AlertingTimeLine::addLog(
    std::string const &incidentId, double const &time,
    std::shared_ptr<dessser::gen::alerting_log::t const>) {
  (void)time;
  NotifTimeLine *timeLine{timeLines.value(incidentId)};
  if (!timeLine) {
    std::shared_ptr<dessser::gen::alerting_notification::t const> const
        firstStart{getIncidentNotif(
            incidentId,
            std::make_shared<dessser::gen::sync_key::incident_key>(
                std::in_place_index<dessser::gen::sync_key::FirstStartNotif>,
                dessser::Void()))};
    if (!firstStart) {
      if (verbose)
        qDebug() << "Cannot find first_start notif for incident"
                 << QString::fromStdString(incidentId);
      return;
    }

    std::shared_ptr<std::string const> const assignedTeam{
        getAssignedTeam(incidentId)};
    if (!assignedTeam) {
      qWarning() << "Cannot find IncidentId"
                 << QString::fromStdString(incidentId)
                 << "(assigned team (absent or invalid type)";
      return;
    }

    QString const incident_name{QString::fromStdString(*assignedTeam) +
                                QString(": ") +
                                QString::fromStdString(firstStart->name)};

    timeLine = new NotifTimeLine(incidentId, 0., 0., true, true, this);
    timeLineGroup->add(timeLine);
    int const row{1};  // TODO: order notif names alphabetically?
    formLayout->insertRow(row, incident_name, timeLine);
    timeLines.insert(incidentId, timeLine);
  }
}

void AlertingTimeLine::addLogKey(dessser::gen::sync_key::t const &key,
                                 KValue const &kv) {
  std::string incidentId;
  double time;
  if (!parseLogKey(key, &incidentId, &time)) {
  not_log:
    return;
  }
  // Not all keys are log events:
  if (kv.val->index() != dessser::gen::sync_value::IncidentLog) goto not_log;

  std::shared_ptr<dessser::gen::alerting_log::t const> log{
      kv.val, &std::get<dessser::gen::sync_value::IncidentLog>(*kv.val)};

  addLog(incidentId, time, log);
}

void AlertingTimeLine::onKeyChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    if (change.op != KeyCreated) continue;
    addLogKey(*change.key, change.kv);
  }
}
