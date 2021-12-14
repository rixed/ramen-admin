#ifndef ALERTINGLOGSMODEL_H_200615
#define ALERTINGLOGSMODEL_H_200615
#include <memory>
#include <vector>
#include <QList>
#include <QAbstractTableModel>

#include "misc.h"

struct ConfChange;
class QModelIndex;
class QVariant;

namespace dessser {
  namespace gen {
    namespace alerting_log { struct t; }
  }
}

class AlertingLogsModel : public QAbstractTableModel {
  Q_OBJECT

  struct Log {
    std::string incidentId;
    double time;
    std::shared_ptr<dessser::gen::alerting_log::t const> log;

    QString timeStr;

    Log(std::string incidentId_, double time_,
        std::shared_ptr<dessser::gen::alerting_log::t const> log_)
      : incidentId(incidentId_), time(time_), log(log_),
        timeStr(stringOfDate(time_)) {}
  };

  std::vector<Log> journal;

  void addLog(
    std::string const &, double, std::shared_ptr<dessser::gen::alerting_log::t const>);

public:
  enum Columns { Time, Text, NUM_COLUMNS };

  AlertingLogsModel(QObject *parent = nullptr);

  int rowCount(QModelIndex const &) const override;

  int columnCount(QModelIndex const &) const override;

  QVariant data(QModelIndex const &, int role) const override;

  QVariant headerData(int, Qt::Orientation, int role) const override;

  static AlertingLogsModel *globalLogsModel;

private slots:
  void onChange(QList<ConfChange> const &);
};

#endif
