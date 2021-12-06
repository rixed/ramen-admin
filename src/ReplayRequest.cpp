#include <algorithm>
#include <cstdlib>
#include <mutex>
#include <unistd.h>
#include <QtGlobal>
#include <QTimer>
#include <QDebug>

#include "ConfClient.h"
#include "desssergen/event_time.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/replay_request.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "EventTime.h"
#include "Menu.h"
#include "misc.h"
#include "misc_dessser.h"

#include "ReplayRequest.h"

static bool const verbose { false };

static std::chrono::milliseconds const batchReplaysForMs { 2000 };

std::string const respKeyPrefix(
  std::to_string(getpid()) + "_" + std::to_string(std::rand()) + "_");

static unsigned respKeySeq;
static std::mutex respKeySeqLock;

static std::shared_ptr<dessser::gen::sync_key::t const> nextRespKey()
{
  std::lock_guard<std::mutex> guard(respKeySeqLock);

  std::shared_ptr<dessser::gen::sync_key::per_client> resp {
    std::make_shared<dessser::gen::sync_key::per_client>(
      std::in_place_index<dessser::gen::sync_key::Response>,
      respKeyPrefix + std::to_string(respKeySeq++)) };

  return std::make_shared<dessser::gen::sync_key::t const>(
    std::in_place_index<dessser::gen::sync_key::PerClient>,
    std::const_pointer_cast<dessser::gen::sync_socket::t>(Menu::getClient()->syncSocket),
    resp);
}

ReplayRequest::ReplayRequest(
  std::string const &site_,
  std::string const &program_,
  std::string const &function_,
  double since_, double until_,
  std::shared_ptr<dessser::gen::raql_type::t const> type_,
  std::shared_ptr<EventTime const> eventTime_,
  QObject *parent)
  : QObject(parent),
    site(site_),
    program(program_),
    function(function_),
    started(std::time(nullptr)),
    respKey(nextRespKey()),
    type(type_),
    eventTime(eventTime_),
    status(Waiting),
    since(since_),
    until(until_)
{
  // Prepare to receive the values:
  connect(kvs.get(), &KVStore::keyChanged,
          this, &ReplayRequest::onChange);

  timer = new QTimer(this);
  timer->setSingleShot(true);
  connect(timer, &QTimer::timeout,
          this, &ReplayRequest::sendRequest);
  timer->start(batchReplaysForMs);
}

void ReplayRequest::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyChanged:
        receiveValue(*change.key, change.kv);
        break;
      case KeyDeleted:
        endReplay(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

bool ReplayRequest::isCompleted(std::lock_guard<std::mutex> const &) const
{
  return status == Completed;
}

bool ReplayRequest::isWaiting(std::lock_guard<std::mutex> const &) const
{
  return status == Waiting;
}

void ReplayRequest::sendRequest()
{
  std::lock_guard<std::mutex> guard(lock);

  assert(status == ReplayRequest::Waiting);
  status = Sent;

  // Create the response key:
  Menu::getClient()->sendNew(respKey);

  // Then the replay request:
  std::shared_ptr<dessser::gen::fq_function_name::t const> fq_target {
    std::make_shared<dessser::gen::fq_function_name::t const>(
      function, program, site) };

  std::shared_ptr<dessser::gen::replay_request::t const> req {
    std::make_shared<dessser::gen::replay_request::t const>(
      false, // explain
      std::const_pointer_cast<dessser::gen::sync_key::t>(respKey),
      since,
      std::const_pointer_cast<dessser::gen::fq_function_name::t>(fq_target),
      until) };

  std::shared_ptr<dessser::gen::sync_value::t const> val {
    std::make_shared<dessser::gen::sync_value::t const>(
      std::in_place_index<dessser::gen::sync_value::ReplayRequest>,
      std::const_pointer_cast<dessser::gen::replay_request::t>(req)) };

  if (verbose)
    qDebug() << "ReplayRequest::sendRequest:"
              << QString::fromStdString(program) << "/"
              << QString::fromStdString(function)
              << qSetRealNumberPrecision(13)
              << "from" << since << "to" << until
              << "respKey" << *respKey;

  std::shared_ptr<dessser::gen::sync_key::t const> key {
    std::make_shared<dessser::gen::sync_key::t const>(
      std::in_place_index<dessser::gen::sync_key::ReplayRequests>,
      dessser::VOID) };

  Menu::getClient()->sendSet(key, val);
}

void ReplayRequest::receiveValue(dessser::gen::sync_key::t const &key, KValue const &kv)
{
  if (key != *respKey) return;

  // Values are received in batches (Tuples)
  if (kv.val->index() != dessser::gen::sync_value::Tuples) {
    // Probably the VNull placeholder:
    if (kv.val->index() != dessser::gen::sync_value::RamenValue ||
        std::get<dessser::gen::sync_value::RamenValue>(*kv.val)->index() !=
          dessser::gen::raql_value::VNull)
      qCritical() << "ReplayRequest::receiveValue: invalid type:" << *kv.val;
    return;
  }

  auto const &batch { std::get<dessser::gen::sync_value::Tuples>(*kv.val) };

  bool hadTuple { false };

  {
    std::lock_guard<std::mutex> guard(lock);

    if (status != ReplayRequest::Sent) {
      qCritical() << "Replay" << *respKey
                  << "received a tuple while " << qstringOfStatus(status);
      // Will not be ordered properly, but better than nothing
    }

    if (verbose)
      qDebug() << "Received a batch of" << batch.size() << "tuples";

    for (std::shared_ptr<dessser::gen::sync_value::tuple> const tuple : batch) {
      std::optional<double> start { eventTime->startOfTuple(*tuple->values) };
      if (! start) {
        qCritical() << "Dropping tuple missing event time";
        continue;
      }

      if (*start >= since && *start <= until) {
        if (verbose)
          qDebug() << "ReplayRequest: received" << *tuple->values;

        tuples.insert(std::make_pair(*start, tuple->values));
        hadTuple = true;
      } else {
        std::optional<double> stop { eventTime->stopOfTuple(*tuple->values) };
        if (! stop || !overlap(*start, *stop, since, until)) {
          qCritical() << qSetRealNumberPrecision(13)
                      << "Ignoring a tuple which time" << int64_t(*start)
                      << "is not within" << since << "..." << until;
        }
      }
    }
  } // destroy guard

  if (hadTuple) emit tupleBatchReceived();
}

void ReplayRequest::endReplay(dessser::gen::sync_key::t const &key, KValue const &)
{
  if (key != *respKey) return;

  if (verbose)
    qDebug() << "ReplayRequest::endReplay" << key;

  {
    std::lock_guard<std::mutex> guard(lock);
    status = ReplayRequest::Completed;
  }
  emit endReceived();
}

QString const ReplayRequest::qstringOfStatus(ReplayRequest::Status const status)
{
  switch (status) {
    case ReplayRequest::Waiting:
      return QString(tr("Waiting"));
    case ReplayRequest::Sent:
      return QString(tr("Sent"));
    case ReplayRequest::Completed:
      return QString(tr("Completed"));
    default:
      assert(!"Invalid status!");
  }
}
