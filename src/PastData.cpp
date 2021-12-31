// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "PastData.h"

#include <QDebug>
#include <algorithm>
#include <functional>

#include "ReplayRequest.h"
#include "desssergen/event_time.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "misc.h"
#include "misc_dessser.h"

static bool const verbose{false};

static int const maxInFlight{3};

/* Max number of seconds between two time ranges for them being merged in a
 * single ReplayRequest. A bit arbitrary, should depend on the tuple density:
 */
static double const minGapBetweenReplays{10.};

PastData::PastData(std::string const &site_, std::string const &program_,
                   std::string const &function_,
                   std::shared_ptr<dessser::gen::raql_type::t const> type_,
                   std::shared_ptr<EventTime const> eventTime_, double maxTime_,
                   QObject *parent)
    : QObject(parent),
      site(site_),
      program(program_),
      function(function_),
      numInFlight(0),
      type(type_),
      eventTime(eventTime_),
      maxTime(maxTime_) {}

void PastData::check() const {
  ReplayRequest const *last{nullptr};
  int numInFlight_{0};

  for (ReplayRequest const &r : replayRequests) {
    Q_ASSERT(r.since < r.until);
    if (last) Q_ASSERT(last->until <= r.since);
    last = &r;

    if (r.status != ReplayRequest::Completed) numInFlight_++;
  }

  Q_ASSERT(numInFlight == numInFlight_);
}

/* Try to merge this new request with that previous one.
 * If merge occurred (return true) then we could continue inserting
 * the new request starting from c.until. */
bool PastData::merge(ReplayRequest &r, ReplayRequest *next, double since,
                     double until, std::lock_guard<std::mutex> const &guard) {
  if (!r.isWaiting(guard) || since > r.until + minGapBetweenReplays ||
      until < r.since - minGapBetweenReplays)
    return false;

  /* Extending on the left is always possible since there can be no
   * other requests in between since and r.since: */
  if (since < r.since) r.since = since;
  /* Extending on the right is more sophisticated, as there could be
   * another request on the way: */
  if (until > r.until) {
    if (next) {
      r.until = std::min(until, next->since);
    } else {
      r.until = until;
    }
  }

  if (verbose)
    qDebug() << "PastData: Enlarging ReplayRequest" << *r.respKey << "to"
             << stringOfDate(r.since) << stringOfDate(r.until);

  check();
  return true;
}

/* Either create a new ReplayRequest or queue that request for later if
 * allowed. Returns true if the request have been dealt with in any of those
 * ways. */
bool PastData::insert(std::list<ReplayRequest>::iterator it, double since,
                      double until, bool canPostpone) {
  /* TODO: if the duration is tiny (TBD), ignores the request and returns true
   */

  if (numInFlight >= maxInFlight) {
    if (canPostpone) {
      if (verbose)
        qDebug() << "PastData: too many replay requests in flight, postponing.";
      postponedRequests.emplace_back(since, until);
      return true;
    } else {
      if (verbose) qDebug() << "PastData: too many replay requests in flight";
      return false;
    }
  } else {
    if (verbose)
      qDebug() << "PastData: Enqueuing a new ReplayRequest (since="
               << stringOfDate(since) << ", until=" << stringOfDate(until)
               << ")";

    std::list<ReplayRequest>::iterator const &emplaced{replayRequests.emplace(
        it, site, program, function, since, until, type, eventTime)};
    numInFlight++;
    connect(&*emplaced, &ReplayRequest::tupleBatchReceived, this,
            &PastData::tupleReceived);
    connect(&*emplaced, &ReplayRequest::endReceived, this,
            &PastData::replayEnded);

    check();
    return true;
  }
}

bool PastData::request(double since, double until, bool canPostpone) {
  if (!std::isnan(maxTime)) until = std::min(until, maxTime);

  if (since >= until) return true;

  check();

  for (std::list<ReplayRequest>::iterator it = replayRequests.begin();
       it != replayRequests.end(); it++) {
    if (since >= until) return true;

    ReplayRequest &c{*it};
    ReplayRequest *next{
        std::next(it) != replayRequests.end() ? &*(std::next(it)) : nullptr};

    std::lock_guard<std::mutex> guard(c.lock);

    if (c.until < since) continue;

    // As the list is ordered by time:
    if (c.since >= until) {
      if (merge(c, next, since, until, guard)) return true;
      return insert(it, since, until, canPostpone);
    }

    if (c.until > since && c.since <= since) since = c.until;
    if (c.since < until && c.until >= until) until = c.since;

    if (since >= until - 1. /* Helps with epsilons */) {
      // New request falls within c
      return true;
    } else if (until == c.since) {
      // New request falls right before c
      if (merge(c, next, since, until, guard)) return true;
      return insert(it, since, until, canPostpone);
    } else if (since == c.until) {
      // New request falls right after c
      if (merge(c, next, since, until, guard)) {
        since = c.until;
      }
      // Else have a look at the following requests
    } else {
      /* New request covers c entirely and must be split.
       * Attempt to merge the beginning into c.
       * Note that even if we cannot postpone this is still beneficial
       * to merge what we can now, even if eventually we return false and
       * the same query stays postponed. */
      if (!merge(c, next, since, c.until, guard)) {
        // If impossible, add a new query for that first part:
        if (!insert(it, since, c.since, canPostpone)) return false;
      }
      // And reiterate for the remaining part:
      since = c.until;
    }
  }

  if (since >= until) return true;

  // New request falls after all previous requests
  return insert(replayRequests.end(), since, until, canPostpone);
}

void PastData::iterTuples(
    double since, double until, bool onePast,
    std::function<void(double,
                       std::shared_ptr<dessser::gen::raql_value::t const>)>
        cb) {
  double lastTime;
  std::shared_ptr<dessser::gen::raql_value::t const> last;

  check();

  for (ReplayRequest &c : replayRequests) {
    std::lock_guard<std::mutex> guard{c.lock};

    if (c.since >= until) break;
    if (c.until <= since) continue;

    for (std::pair<double const,
                   std::shared_ptr<dessser::gen::raql_value::t const> > const
             &tuple : c.tuples) {
      if (tuple.first < since) {
        if (onePast) {
          lastTime = tuple.first;
          last = tuple.second;
        }
      } else if (tuple.first < until) {
        if (last) {
          Q_ASSERT(lastTime <= tuple.first);
          cb(lastTime, last);
          last = nullptr;
        }
        cb(tuple.first, tuple.second);
      } else {
        if (onePast) cb(tuple.first, tuple.second);
        return;
      }
    }
  }
}

void PastData::replayEnded() {
  Q_ASSERT(numInFlight > 0);
  numInFlight--;

  if (verbose)
    qDebug() << "PastData: a replay ended (still" << numInFlight
             << "in flight)";

  if (!postponedRequests.empty()) {
    if (verbose) qDebug() << "PastData: retrying postponed queries";
    auto it{postponedRequests.begin()};
    while (it != postponedRequests.end()) {
      if (request(it->first, it->second, false)) {
        postponedRequests.erase(it++);
      } else {
        it++;
      }
    }
  }
}
