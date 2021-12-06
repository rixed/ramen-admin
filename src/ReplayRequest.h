#ifndef REPLAYREQUEST_H_191007
#define REPLAYREQUEST_H_191007
/* A ReplayRequest is a set of tuples obtained from the server and stored to
 * feed the charts and tail tables. */
#include <ctime>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <QObject>

#include "ConfChange.h"

class QTimer;
struct EventTime;
struct KValue;

namespace dessser {
  namespace gen {
    namespace raql_type { struct t; }
    namespace raql_value { struct t; }
    namespace event_time { struct t; }
    namespace sync_key { struct t; }
  }
}

extern std::string const respKeyPrefix;

class ReplayRequest : public QObject
{
  Q_OBJECT

  QTimer *timer;

  std::string const site, program, function;

  void receiveValue(dessser::gen::sync_key::t const &, KValue const &);
  void endReplay(dessser::gen::sync_key::t const &, KValue const &);

public:
  // Protects status, since, until and tuples:
  std::mutex lock;

  std::time_t started; // When the query was sent (for timeout)

  // Used to identify a single request:
  std::shared_ptr<dessser::gen::sync_key::t const> respKey;

  std::shared_ptr<dessser::gen::raql_type::t const> type;
  std::shared_ptr<EventTime const> eventTime;

  enum Status { Waiting, Sent, Completed } status;

  static QString const qstringOfStatus(ReplayRequest::Status const);

  double since, until;

  /* Where the results are stored (in event time order. */
  std::multimap<double, std::shared_ptr<dessser::gen::raql_value::t const>> tuples;

  /* Also start the actual request: */
  ReplayRequest(
    std::string const &site,
    std::string const &program,
    std::string const &function,
    double since_, double until_,
    std::shared_ptr<dessser::gen::raql_type::t const> type_,
    std::shared_ptr<EventTime const>,
    QObject *parent = nullptr);

  bool isCompleted(std::lock_guard<std::mutex> const &) const;

  bool isWaiting(std::lock_guard<std::mutex> const &) const;

protected slots:
  void sendRequest();

  void onChange(QList<ConfChange> const &);

signals:
  void tupleBatchReceived();

  void endReceived();
};

#endif
