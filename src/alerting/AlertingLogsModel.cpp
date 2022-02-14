// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingLogsModel.h"

#include <QCoreApplication>
#include <QDebug>
#include <QModelIndex>
#include <QVariant>

#include "KVStore.h"
#include "alerting/tools.h"
#include "desssergen/alerting_log.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static constexpr bool verbose{false};

AlertingLogsModel *AlertingLogsModel::globalLogsModel;

AlertingLogsModel::AlertingLogsModel(QObject *parent)
    : QAbstractTableModel(parent) {
  journal.reserve(20);

  iterIncidents([this](std::string const &incidentId) {
    iterLogs(incidentId,
             [this, &incidentId](
                 double time,
                 std::shared_ptr<dessser::gen::alerting_log::t const> log) {
               addLog(incidentId, time, log);
             });
  });

  connect(kvs.get(), &KVStore::keyChanged, this, &AlertingLogsModel::onChange);
}

AlertingLogsModel::~AlertingLogsModel() {
  for (Log const *l : journal) delete l;
}

void AlertingLogsModel::addLog(
    std::string const &incidentId, double time,
    std::shared_ptr<dessser::gen::alerting_log::t const> log) {
  /* Insert it into the journal (most of the time, will be merely appended,
   * so start looking from the end): */
  size_t i{journal.size()};
  while (i--) {
    if (journal[i]->time < time) break;
  }
  i++;
  // Insert at position i:
  beginInsertRows(QModelIndex(), i, i);
  std::vector<AlertingLogsModel::Log const *>::const_iterator it{
      journal.cbegin() + i};
  journal.insert(it, new Log{incidentId, time, log});
  endInsertRows();

  if (verbose)
    qDebug() << "AlertingLogsModel: has now" << journal.size() << "entries";
}

void AlertingLogsModel::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    if (change.op != KeyCreated) continue;

    std::string incidentId;
    double time;
    if (!parseLogKey(*change.key, &incidentId, &time)) continue;

    if (change.kv.val->index() != dessser::gen::sync_value::IncidentLog) {
      qCritical() << "Log entry not IncidentLog:" << *change.key;
      continue;
    }

    std::shared_ptr<dessser::gen::alerting_log::t const> log{
        change.kv.val,
        &std::get<dessser::gen::sync_value::IncidentLog>(*change.kv.val)};

    addLog(incidentId, time, log);
  }
}

int AlertingLogsModel::rowCount(QModelIndex const &parent) const {
  if (parent.isValid()) return 0;
  return journal.size();
}

int AlertingLogsModel::columnCount(QModelIndex const &parent) const {
  if (parent.isValid()) return 0;
  return AlertingLogsModel::NUM_COLUMNS;
}

QString alertingLogToQString(dessser::gen::alerting_log::t const &log) {
#define TR(x) QCoreApplication::translate("QMainWindow", x)
  switch (log.index()) {
    case dessser::gen::alerting_log::NewNotification: {
      QString ret{TR("New notification received, %1")};
      switch (std::get<dessser::gen::alerting_log::NewNotification>(log)) {
        case dessser::gen::alerting_log::Duplicate:
          return ret.arg(TR("duplicate"));
        case dessser::gen::alerting_log::Inhibited:
          return ret.arg(TR("inhibited"));
        case dessser::gen::alerting_log::STFU:
          return ret.arg(TR("silenced"));
        case dessser::gen::alerting_log::StartEscalation:
          return ret.arg(TR("started escalation"));
        default:
          qFatal("alertingLogToQString: invalid NewNotification");
      }
    } break;
    case dessser::gen::alerting_log::Outcry:
      return QString(TR("Sent message via %1"))
          .arg(QString::fromStdString(
              std::get<0>(std::get<dessser::gen::alerting_log::Outcry>(log))));
    case dessser::gen::alerting_log::Ack:
      return QString(TR("Received ack for %1"))
          .arg(QString::fromStdString(
              std::get<dessser::gen::alerting_log::Ack>(log)));
    case dessser::gen::alerting_log::Stop: {
      QString ret{TR("Stopped incident (%1)")};
      switch (std::get<dessser::gen::alerting_log::Stop>(log).index()) {
        case dessser::gen::alerting_log::Notification:
          return ret.arg(TR("notification"));
        case dessser::gen::alerting_log::Manual:
          return ret.arg(
              TR("manually stopped by %1")
                  .arg(QString::fromStdString(
                      std::get<dessser::gen::alerting_log::Manual>(
                          std::get<dessser::gen::alerting_log::Stop>(log)))));
        case dessser::gen::alerting_log::Timeout:
          return ret.arg(
              TR("timeout for %1")
                  .arg(QString::fromStdString(
                      std::get<dessser::gen::alerting_log::Timeout>(
                          std::get<dessser::gen::alerting_log::Stop>(log)))));
        default:
          qFatal("alertingLogToQString: invalid alerting_log::Stop index");
      }
    }
    case dessser::gen::alerting_log::Cancel:
      return QString(TR("Cancelled message for %1"))
          .arg(QString::fromStdString(
              std::get<dessser::gen::alerting_log::Cancel>(log)));
    default:
      qFatal("alertingLogToQString: invalid log index");
  }
#undef TR
}

QVariant AlertingLogsModel::data(QModelIndex const &index, int role) const {
  if (role != Qt::DisplayRole) return QVariant();

  size_t const row{size_t(index.row())};
  if (row >= journal.size()) return QVariant();

  switch (static_cast<AlertingLogsModel::Columns>(index.column())) {
    case AlertingLogsModel::Time:
      return journal[row]->timeStr;
    case AlertingLogsModel::Text:
      return alertingLogToQString(*journal[row]->log);
    default:
      return QVariant();
  }
}

QVariant AlertingLogsModel::headerData(int section, Qt::Orientation orientation,
                                       int role) const {
  if (role != Qt::DisplayRole) return QVariant();
  if (orientation != Qt::Horizontal) return QVariant();

  switch (section) {
    case 0:
      return QString(tr("Time"));
    case 1:
      return QString(tr("Text"));
    default:
      return QVariant();
  }
}
