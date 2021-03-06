// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef PASTDATA_H_191007
#define PASTDATA_H_191007

/* This stores past values of a given function.
 * Each request to access past data will lead the server to replay the
 * data for that time range, which is an expensive operation. Also, many times
 * we are interested in a few fields out of many, but we nonetheless request
 * and cache the full tuple for the sake of simplicity.
 *
 * When a time range is requested, only the missing data is requested; boundary
 * timestamp equality will then be used to merge the result into preexisting
 * PastDataChunks as much as possible.
 *
 * Replays must be limited in size as to avoid the backend to read very large
 * amount of data. In theory, this is related to the storage configuration, and
 * if everything is configured properly then no replay should have to process
 * huge amount of data.  In reality, a process to limit the size of the
 * response is needed; ideally controlled solely from the client side. This is
 * still TODO.
 */
#include <QObject>
#include <cmath>
#include <functional>
#include <list>
#include <memory>
#include <mutex>
#include <utility>

#include "ReplayRequest.h"

namespace dessser {
namespace gen {
namespace raql_type {
struct t;
}
namespace raql_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

struct EventTime;

class PastData : public QObject {
  Q_OBJECT

  std::string const site, program, function;

  /* Request for past data that have to wait, in no particular order.
   * Maybe ordering these according to start would provide more merging
   * opportunities? */
  std::list<std::pair<double, double> > postponedRequests;

  // For debugging:
  void check() const;

  bool merge(ReplayRequest &, ReplayRequest *, double, double,
             std::lock_guard<std::mutex> const &);

  bool insert(std::list<ReplayRequest>::iterator, double, double, bool);

 public:
  // Used to detect function model changes:
  std::string const workerSign;

  /* List of queries (pending or past!) for this worker, ordered by time.
   * This is where the data is eventually stored. */
  std::list<ReplayRequest> replayRequests;

  std::shared_ptr<dessser::gen::raql_type::t const> type;

  std::shared_ptr<EventTime const> eventTime;

  /* If set, this is where the tail starts. No replay queries must go beyond
   * this point. */
  double maxTime = NAN;

  PastData(std::string const &site, std::string const &program,
           std::string const &function, std::string const &workerSign,
           std::shared_ptr<dessser::gen::raql_type::t const>,
           std::shared_ptr<EventTime const>, double maxTime_ = NAN,
           QObject *parent = nullptr);

  /* Returns true if the query can either be sent or postponed: */
  bool request(double since, double until, bool canPostpone = true);

  void iterTuples(
      double since, double until,
      std::function<void(double,
                         std::shared_ptr<dessser::gen::raql_value::t const>)>);

  /* Returns the time range covered by all received values.
   * Returns a range of 0 width if there are no values yet. */
  // FIXME: ask for a lock on replayRequests
  std::pair<double, double> range() const;

 protected slots:
  void replayEnded();

 signals:
  void tupleReceived();
};

#endif
