#include <cmath>
#include <sstream>
#include <QtGlobal>
#include <QDateTime>
#include <QDebug>

#include "desssergen/event_time.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_value.h"
#include "desssergen/worker.h"
#include "EventTime.h"
#include "KVStore.h"
#include "misc.h"
#include "misc_dessser.h"
#include "ProgramItem.h"
#include "Resources.h"
#include "SiteItem.h"
#include "stream/GraphView.h"
#include "stream/GraphViewSettings.h"
#include "TailModel.h"

#include "FunctionItem.h"

static bool const verbose { false };

Function::Function(std::string const &siteName_, std::string const &programName_,
                   std::string const &functionName_, std::string const &srcPath_) :
  GraphData(QString::fromStdString(functionName_)),
  siteName(siteName_),
  programName(programName_),
  fqName(programName_ + "/" + functionName_),
  srcPath(srcPath_) {}

std::shared_ptr<TailModel> Function::getOrCreateTail()
{
  // Hopefully, this is destroyed as soon as the worker changes:
  if (tailModel) return tailModel;

  if (! worker) {
    if (verbose)
      qDebug() << "Cannot get the tail without the worker";
    return nullptr;
  }

  /* FIXME: there is a race condition here. We should pass the worker
   * src_path md5 and check that it's the same info file we have read
   * that type info from: */
  std::shared_ptr<dessser::gen::raql_type::t const> type { outType() };
  if (! type) {
    if (verbose)
      qDebug() << "Cannot get the tail without type info";
    return nullptr;
  }

  /* Also pass the factors: */
  std::shared_ptr<dessser::gen::source_info::compiled_func const> func { compiledInfo() };

  tailModel =
    std::make_shared<TailModel>(
      siteName, fqName, worker->worker_signature, outType(), getTime(), this);

  connect(tailModel.get(), &TailModel::receivedTuple,
          this, &Function::setMinTail);

  return tailModel;
}

void Function::setMinTail(double time)
{
  if (! pastData) return;
  if (time >= pastData->maxTime) return;

  if (verbose)
    qDebug() << "Function: update pastData max time with" << time;

  pastData->maxTime = time;

  // Keep the connection because the first tail tuple may not be the min time
}

/* Called when the function worker changes.
 * Release the tailModel and pastData if it does not match the worker any
 * longer */
void Function::checkTail()
{
  if (! tailModel) return;

  if (worker && worker->worker_signature == tailModel->workerSign) return;

  qInfo() << "Function" << QString::fromStdString(fqName) << "model changed";

  tailModel.reset();
  pastData.reset();
}

/* Look for it in the kvs at every call rather than caching a value that
 * could change at any time. */
std::shared_ptr<dessser::gen::source_info::compiled_func const> Function::compiledInfo() const
{
  dessser::gen::sync_key::t const k {
    std::in_place_index<dessser::gen::sync_key::Sources>,
    srcPath,
    "info" };
  KValue const *kv = nullptr;
  kvs->lock.lock_shared();
  auto it =
    kvs->map.find(std::shared_ptr<dessser::gen::sync_key::t const>(
      &k, /* No del */[](dessser::gen::sync_key::t const *){}));
  if (it != kvs->map.end()) kv = &it->second;
  kvs->lock.unlock_shared();

  if (! kv) {
    if (verbose) qDebug() << k << "not yet set";
    return nullptr;
  }

  if (kv->val->index() != dessser::gen::sync_value::SourceInfo) {
    qCritical() << k << "is not a SourceInfo but:" << *kv->val;
    return nullptr;
  }

  std::shared_ptr<dessser::gen::source_info::t const> info {
    std::get<dessser::gen::sync_value::SourceInfo>(*kv->val) };

  if (info->detail.index() != dessser::gen::source_info::Compiled) {
    qWarning() << k << "is not compiled";
    return nullptr;
  }

  std::shared_ptr<dessser::gen::source_info::compiled_program const> compiled {
    std::get<dessser::gen::source_info::Compiled>(info->detail) };
  for (std::shared_ptr<dessser::gen::source_info::compiled_func const> f :
       std::const_pointer_cast<dessser::gen::source_info::compiled_program>(compiled)->funcs) {
    if (QString::fromStdString(f->name) == name) return f;
  }

  qCritical() << k << "has no function" << name;
  return nullptr;
}

std::shared_ptr<dessser::gen::raql_type::t const> Function::outType() const
{
  std::shared_ptr<dessser::gen::source_info::compiled_func const> func { compiledInfo() };
  if (! func) return nullptr;
  return func->out_record;
}

std::shared_ptr<EventTime const> Function::getTime() const
{
  std::shared_ptr<dessser::gen::source_info::compiled_func const> func { compiledInfo() };
  if (! func) {
    qWarning() << "Function" << name << "has no compiledInfo";
    return nullptr;
  }

  return std::make_shared<EventTime>(*func->out_record);
}

std::shared_ptr<dessser::gen::event_time::t const> Function::get_event_time() const
{
  std::shared_ptr<dessser::gen::source_info::compiled_func const> func { compiledInfo() };
  if (! func) {
    qWarning() << "Function" << name << "has no compiledInfo";
    return nullptr;
  }

  switch (func->operation->index()) {
    case dessser::gen::raql_operation::Aggregate:
      {
        auto const op {
          std::get<dessser::gen::raql_operation::Aggregate>(*func->operation) };
        return op.Aggregate_event_time ? *op.Aggregate_event_time : nullptr;
      }
    case dessser::gen::raql_operation::ReadExternal:
      {
        auto const op {
          std::get<dessser::gen::raql_operation::ReadExternal>(*func->operation) };
        return op.event_time ? *op.event_time : nullptr;
      }
    case dessser::gen::raql_operation::ListenFor:
      return nullptr;
    default:
      return nullptr;
  }
}

std::shared_ptr<PastData> Function::getPast()
{
  if (pastData) return pastData;

  std::shared_ptr<EventTime const> eventTime = getTime();
  if (! eventTime) {
    qWarning() << "Function" << name << "has no eventTime";
    return nullptr;
  }

  std::shared_ptr<dessser::gen::raql_type::t const> type = outType();
  if (! type) {
    qWarning() << "Function" << name << "has no output type";
    return nullptr;
  }

  // Never allow to query past the tail start if we have a tail:
  double const maxDate {
    tailModel ?  tailModel->minEventTime() : NAN };

  pastData = std::make_shared<PastData>(
    siteName, programName, name.toStdString(), type, eventTime, maxDate);

  return pastData;
}

void Function::iterValues(
  double since, double until, bool onePast, std::vector<int> const &columns,
  std::function<void (double, std::vector<std::shared_ptr<dessser::gen::raql_value::t const>> const)> cb)
{
  /* It's not mandatory to tail that function, but we cannot iterValues
   * without pastData: */
  if (! getPast()) {
    qWarning() << "Cannot iterate over function values without past data.";
    return;
  }

  double reqSince = since, reqUntil = until;
  /* FIXME: lock tailModel->tuples here and release after having read the
   * first tuples */
  if (tailModel && !std::isnan(tailModel->minEventTime())) {
    reqUntil = std::min(reqUntil, tailModel->minEventTime());
  }
  if (reqSince < reqUntil) {
    pastData->request(reqSince, reqUntil);
  }

  if (verbose)
    qDebug() << qSetRealNumberPrecision(13)
             << "Function::iterValues since" << since << "until" << until;

  // We need the last tuple from PastData when we start drawing the tail:
  double lastTime;
  std::shared_ptr<dessser::gen::raql_value::t const> last;
  pastData->iterTuples(since, until, onePast,
    [&cb, &columns, &last, &lastTime](
      double time, std::shared_ptr<dessser::gen::raql_value::t const> tuple) {
    Q_ASSERT(!last || lastTime <= time);
    lastTime = time;
    last = tuple;
    std::vector<std::shared_ptr<dessser::gen::raql_value::t const>> v;
    v.reserve(columns.size());
    for (unsigned column : columns) {
      v.push_back(columnValue(*tuple, column));
    }
    cb(time, v);
  });

  /* Then for tail data: */

  std::function<void(double, std::shared_ptr<dessser::gen::raql_value::t const>)>
    sendTuple([&cb, &columns]
      (double time, std::shared_ptr<dessser::gen::raql_value::t const> tuple) {
    std::vector<std::shared_ptr<dessser::gen::raql_value::t const>> v;
    v.reserve(columns.size());
    for (unsigned column : columns)
      v.push_back(columnValue(*tuple, column));
    cb(time, v);
  });

  // FIXME: lock the tailModel to prevent points being added while we iterate
  for (std::pair<double const, size_t> const &ordered : tailModel->order) {
    std::pair<double, std::shared_ptr<dessser::gen::raql_value::t const>> const &tuple(
      tailModel->tuples[ordered.second]);
    Q_ASSERT(ordered.first == tuple.first);

    /* Despite we never request past data after the oldest tail, it can happen
     * that past data overlap with the tail, because tail is just cached or
     * because past data is requested even before we received the first tail
     * tuple. In this case we favor past data and skip the tail tuples: */
    if (last && lastTime > tuple.first) continue;

    if (tuple.first < since) {
      if (onePast) {
        lastTime = tuple.first;
        last = tuple.second;
      }
    } else if (tuple.first < until) {
      if (last) {
        sendTuple(lastTime, last);
        last = nullptr;
      }
      sendTuple(tuple.first, tuple.second);
    } else {
      if (onePast)
        sendTuple(tuple.first, tuple.second);
      break;
    }
  }
}

void Function::resetInstanceData()
{
  pid.reset();
  lastKilled.reset();
  lastExit.reset();
  lastExitStatus.reset();
  successiveFailures.reset();
  quarantineUntil.reset();
}

std::shared_ptr<Function> Function::find(
  QString const &site, QString const &program, QString const &name)
{
  for (auto &siteItem : GraphModel::globalGraphModel->sites) {
    if (siteItem->shared->name != site) continue;
    for (auto &programItem : siteItem->programs) {
      if (programItem->shared->name != program) continue;
      for (auto &functionItem : programItem->functions) {
        std::shared_ptr<Function> function =
          std::static_pointer_cast<Function>(functionItem->shared);
        if (function->name == name) return function;
      }
    }
  }
  return nullptr;
}

FunctionItem::FunctionItem(
  GraphItem *treeParent, std::unique_ptr<Function> function,
  GraphViewSettings const &settings) :
  GraphItem(treeParent, std::move(function), settings)
{
  // TODO: updateArrows should reallocate the channels:
  channel = std::rand() % settings.numArrowChannels;
  setZValue(3);
}

/* columnCount is called to know the number of columns of the sub elements.
 * Functions have no sub-elements and Qt should know this. */
int FunctionItem::columnCount() const
{
  qFatal("FunctionItem::columnCount called!");
}

QVariant FunctionItem::data(int column, int role) const
{
  std::shared_ptr<Function> shr =
    std::static_pointer_cast<Function>(shared);

  if (role == Qt::DisplayRole && !isTopHalf()) {
    if (column == GraphModel::ActionButton1)
      return Resources::get()->tablePixmap;
    if (column == GraphModel::ActionButton2)
      return Resources::get()->chartPixmap;
  }

  static QString na(tr("n.a"));

  if (role == Qt::TextAlignmentRole) {
    switch (column) {
      case GraphModel::Name:
        return Qt::AlignLeft;
      case GraphModel::WorkerTopHalf:
      case GraphModel::WorkerEnabled:
      case GraphModel::WorkerDebug:
      case GraphModel::WorkerUsed:
      case GraphModel::WorkerParams:
        return Qt::AlignHCenter;
    }
    return Qt::AlignRight;
  }

  if (role == Qt::FontRole) {
    if (column > GraphModel::Name) return QFont("Courier New");
  }

  if (role != Qt::DisplayRole &&
      role != GraphModel::SortRole) return QVariant();

  switch ((GraphModel::Columns)column) {
    case GraphModel::Name:
      return shr->name;

    case GraphModel::ActionButton1:
    case GraphModel::ActionButton2:
      if (role == GraphModel::SortRole)
        return shr->name;
      else
        return QVariant();

    case GraphModel::WorkerTopHalf:
      return QString(
        shr->worker ?
          (shr->worker->role.index() == dessser::gen::worker::TopHalf ? "✓" : "") : "?");

    case GraphModel::WorkerEnabled:
      return QString(
        shr->worker ? (shr->worker->enabled ? "✓" : "") : "?");

    case GraphModel::WorkerDebug:
      return QString(
        shr->worker ? (shr->worker->debug ? "✓" : "") : "?");

    case GraphModel::WorkerUsed:
      return QString(
        shr->worker ? (shr->worker->is_used ? "✓" : "") : "?");

    case GraphModel::StatsTime:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ? shr->runtimeStats->stats_time : 0.;
      else return shr->runtimeStats ?
          stringOfDate(shr->runtimeStats->stats_time) : na;

    case GraphModel::StatsNumInputs:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_in_tuples : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->tot_in_tuples) : na;

    case GraphModel::StatsNumSelected:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_sel_tuples : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->tot_sel_tuples) : na;

    case GraphModel::StatsNumFiltered:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_out_filtered : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->tot_out_filtered) : na;

    case GraphModel::StatsTotWaitIn:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ? shr->runtimeStats->tot_wait_in : 0.;
      else return shr->runtimeStats ?
        stringOfDuration(shr->runtimeStats->tot_wait_in) : na;

    case GraphModel::StatsTotInputBytes:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_in_bytes : (qulonglong)0;
      else return shr->runtimeStats ?
        stringOfBytes(shr->runtimeStats->tot_in_bytes) : na;

    case GraphModel::StatsFirstInput:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats &&
               shr->runtimeStats->first_input.has_value() ?
          *shr->runtimeStats->first_input : 0.;
      else return shr->runtimeStats &&
                  shr->runtimeStats->first_input.has_value() ?
        stringOfDate(*shr->runtimeStats->first_input) : na;

    case GraphModel::StatsLastInput:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats &&
               shr->runtimeStats->last_input.has_value() ?
          *shr->runtimeStats->last_input : 0.;
      else return shr->runtimeStats &&
                  shr->runtimeStats->last_input.has_value() ?
        stringOfDate(*shr->runtimeStats->last_input) : na;

    case GraphModel::StatsNumGroups:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->cur_groups : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->cur_groups) : na;

    case GraphModel::StatsMaxGroups:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->max_groups : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->max_groups) : na;

    case GraphModel::StatsNumOutputs:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_out_tuples : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->tot_out_tuples) : na;

    case GraphModel::StatsTotWaitOut:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_wait_out : 0.;
      else return shr->runtimeStats ?
        stringOfDuration(shr->runtimeStats->tot_wait_out) : na;

    case GraphModel::StatsFirstOutput:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats &&
               shr->runtimeStats->first_output.has_value() ?
          *shr->runtimeStats->first_output : 0.;
      else return shr->runtimeStats &&
                  shr->runtimeStats->first_output.has_value() ?
        stringOfDate(*shr->runtimeStats->first_output) : na;

    case GraphModel::StatsLastOutput:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats &&
               shr->runtimeStats->last_output.has_value() ?
          *shr->runtimeStats->last_output : 0.;
      else return shr->runtimeStats &&
                  shr->runtimeStats->last_output.has_value() ?
        stringOfDate(*shr->runtimeStats->last_output) : na;

    case GraphModel::StatsTotOutputBytes:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_out_bytes : (qulonglong)0;
      else return shr->runtimeStats ?
        stringOfBytes(shr->runtimeStats->tot_out_bytes) : na;

    case GraphModel::StatsNumFiringNotifs:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_firing_notifs : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->tot_firing_notifs) : na;

    case GraphModel::StatsNumExtinguishedNotifs:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_extinguished_notifs : 0.;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->tot_extinguished_notifs) : na;

    case GraphModel::NumArcFiles:
      if (role == GraphModel::SortRole)
        return shr->numArcFiles.has_value() ?
          *shr->numArcFiles : (qulonglong)0;
      else return shr->numArcFiles.has_value() ?
        QString::number(*shr->numArcFiles) : na;

    case GraphModel::NumArcBytes:
      if (role == GraphModel::SortRole)
        return shr->numArcBytes.has_value() ?
          *shr->numArcBytes : (qulonglong)0;
      else return shr->numArcBytes.has_value() ?
        stringOfBytes(*shr->numArcBytes) : na;

    case GraphModel::AllocedArcBytes:
      if (role == GraphModel::SortRole)
        return shr->allocArcBytes.has_value() ?
          *shr->allocArcBytes : (qulonglong)0;
      else return shr->allocArcBytes.has_value() ?
        stringOfBytes(*shr->allocArcBytes) : na;

    case GraphModel::StatsMinEventTime:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats &&
               shr->runtimeStats->min_etime.has_value() ?
          *shr->runtimeStats->min_etime : 0.;
      else return shr->runtimeStats &&
                  shr->runtimeStats->min_etime.has_value() ?
        stringOfDate(*shr->runtimeStats->min_etime) : na;

    case GraphModel::StatsMaxEventTime:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats &&
               shr->runtimeStats->max_etime.has_value() ?
          *shr->runtimeStats->max_etime : 0.;
      else return shr->runtimeStats &&
                  shr->runtimeStats->max_etime.has_value() ?
        stringOfDate(*shr->runtimeStats->max_etime) : na;

    case GraphModel::StatsTotCpu:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ? shr->runtimeStats->tot_cpu : 0.;
      else return shr->runtimeStats ?
        stringOfDuration(shr->runtimeStats->tot_cpu) : na;

    case GraphModel::StatsCurrentRam:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->cur_ram : (qulonglong)0;
      else return shr->runtimeStats ?
        stringOfBytes(shr->runtimeStats->cur_ram) : na;

    case GraphModel::StatsMaxRam:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->max_ram : (qulonglong)0;
      else return shr->runtimeStats ?
        stringOfBytes(shr->runtimeStats->max_ram) : na;

    case GraphModel::StatsFirstStartup:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ? shr->runtimeStats->first_startup : 0.;
      else return shr->runtimeStats ?
        stringOfDate(shr->runtimeStats->first_startup) : na;

    case GraphModel::StatsLastStartup:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ? shr->runtimeStats->last_startup : 0.;
      else return shr->runtimeStats ?
        stringOfDate(shr->runtimeStats->last_startup) : na;

    case GraphModel::StatsAverageTupleSize:
      if (shr->runtimeStats &&
          shr->runtimeStats->tot_full_bytes_samples > 0)
      {
        double const avg =
          (double)shr->runtimeStats->tot_full_bytes /
          shr->runtimeStats->tot_full_bytes_samples;
        if (role == GraphModel::SortRole) return avg;
        else return stringOfBytes(avg);
      } else {
        if (role == GraphModel::SortRole) return 0.;
        else return na;
      }

    case GraphModel::StatsNumAverageTupleSizeSamples:
      if (role == GraphModel::SortRole)
        return shr->runtimeStats ?
          shr->runtimeStats->tot_full_bytes_samples : (qulonglong)0;
      else return shr->runtimeStats ?
        QString::number(shr->runtimeStats->tot_full_bytes_samples) : na;

    case GraphModel::ArchivedTimes:
      if (role == GraphModel::SortRole)
        return shr->archivedTimes ?
          (qulonglong)shr->archivedTimes->size() : (qulonglong)0;
      else return shr->archivedTimes ?
        stringOfDuration(shr->archivedTimes->size()) : na;

    case GraphModel::WorkerReportPeriod:
      if (role == GraphModel::SortRole)
        return shr->worker ? shr->worker->report_period : 0.;
      else return shr->worker ?
        stringOfDuration(shr->worker->report_period) : na;

    case GraphModel::WorkerCWD:
      if (role == GraphModel::SortRole)
        return shr->worker ? QString::fromStdString(shr->worker->cwd) : QString();
      else return shr->worker ?
        QString::fromStdString(shr->worker->cwd) : na;

    case GraphModel::WorkerSrcPath:
      return QString::fromStdString(shr->srcPath);

    case GraphModel::WorkerParams:
      if (shr->worker) {
        std::ostringstream s;
        bool first { true };
        for (auto &p : shr->worker->params) {
          if (first) [[unlikely]] { s << ", "; first = false; }
          s << std::get<0>(p) << '=' << *std::get<1>(p);
        }
        return QString::fromStdString(s.str());
      } else return na;

    case GraphModel::NumParents:
      if (role == GraphModel::SortRole)
        return (qulonglong)(shr->worker && shr->worker->parents ?
          shr->worker->parents->size() : 0);
      else return shr->worker && shr->worker->parents ?
        QString::number(shr->worker->parents->size()) : na;

    case GraphModel::NumChildren:
      return na;  // TODO

    case GraphModel::InstancePid:
      if (role == GraphModel::SortRole)
        return shr->pid.has_value() ? *shr->pid : (qulonglong)0;
      else
        return shr->pid.has_value() ? QString::number(*shr->pid) : na;

    case GraphModel::InstanceLastKilled:
      if (role == GraphModel::SortRole)
        return shr->lastKilled.has_value() ? *shr->lastKilled : 0.;
      else return shr->lastKilled.has_value() ?
        stringOfDate(*shr->lastKilled) : na;

    case GraphModel::InstanceLastExit:
      if (role == GraphModel::SortRole)
        return shr->lastExit.has_value() ? *shr->lastExit : 0.;
      else return shr->lastExit.has_value() ?
        stringOfDate(*shr->lastExit) : na;

    case GraphModel::InstanceLastExitStatus:
      if (role == GraphModel::SortRole)
        return shr->lastExitStatus.has_value() ? *shr->lastExitStatus : 0;
      else
        return shr->lastExitStatus.has_value() ? *shr->lastExitStatus : na;

    case GraphModel::InstanceSuccessiveFailures:
      if (role == GraphModel::SortRole)
        return shr->successiveFailures.has_value() ?
          *shr->successiveFailures : (qulonglong)0;
      else
        return shr->successiveFailures.has_value() ?
          QString::number(*shr->successiveFailures) : na;

    case GraphModel::InstanceQuarantineUntil:
      if (role == GraphModel::SortRole)
        return shr->quarantineUntil.has_value() ? *shr->quarantineUntil : 0.;
      else return shr->quarantineUntil.has_value() ?
        stringOfDate(*shr->quarantineUntil) : na;

    case GraphModel::InstanceSignature:
      if (role == GraphModel::SortRole)
        return shr->instanceSignature.has_value() ?
          *shr->instanceSignature : na;
      else
        return shr->instanceSignature.has_value() ?
          *shr->instanceSignature : na;

    case GraphModel::WorkerSignature:
      return shr->worker ? QString::fromStdString(shr->worker->worker_signature) : na;

    case GraphModel::WorkerBinSignature:
      return shr->worker ? QString::fromStdString(shr->worker->info_signature) : na;

    case GraphModel::NumTailTuples:
      {
        std::shared_ptr<TailModel> tailModel = shr->getTail();
        if (role == GraphModel::SortRole)
          return tailModel ?
            tailModel->rowCount() : (qulonglong)0;
        else
          return
            QString::number(tailModel ? tailModel->rowCount() : 0);
      }

    case GraphModel::NumColumns:
      break;
  }

  qFatal("Bad columnCount for FunctionItem");
}

std::vector<std::pair<QString const, QString const>> FunctionItem::labels() const
{
  std::shared_ptr<Function> shr =
    std::static_pointer_cast<Function>(shared);

  std::vector<std::pair<QString const, QString const>> labels;
  labels.reserve(8);

  if (shr->worker && ! shr->worker->is_used)
    labels.emplace_back("", "UNUSED");
  // TODO: display some stats
  if (shr->numArcFiles)
    labels.emplace_back("#arc.files", QString::number(*shr->numArcFiles));
  if (shr->numArcBytes)
    labels.emplace_back("arc.size", QString::number(*shr->numArcBytes));
  if (shr->allocArcBytes)
    labels.emplace_back("arc.allocated", QString::number(*shr->allocArcBytes));

  return labels;
}

QRectF FunctionItem::operationRect() const
{
  return
    QRect(0, 0,
          settings.gridWidth - 2 * (
            settings.functionMarginHoriz +
            settings.programMarginHoriz +
            settings.siteMarginHoriz),
          settings.gridHeight - (
            settings.functionMarginBottom + settings.programMarginBottom +
            settings.siteMarginBottom + settings.functionMarginTop +
            settings.programMarginTop + settings.siteMarginTop));
}

bool FunctionItem::isTopHalf() const
{
  std::shared_ptr<Function> shr =
    std::static_pointer_cast<Function>(shared);

  return shr->worker &&
         shr->worker->role.index() == dessser::gen::worker::TopHalf;
}

bool FunctionItem::isWorking() const
{
  std::shared_ptr<Function> shr =
    std::static_pointer_cast<Function>(shared);

  return (bool)shr->worker;
}

bool FunctionItem::isRunning() const
{
  std::shared_ptr<Function> shr =
    std::static_pointer_cast<Function>(shared);

  return shr->pid.has_value();
}

bool FunctionItem::isUsed() const
{
  std::shared_ptr<Function> shr =
    std::static_pointer_cast<Function>(shared);

  if (! shr->worker) return false;
  return shr->worker->is_used;
}

FunctionItem::operator QString() const
{
  QString s("   Function[");
  s += row;
  s += "]:";
  s += shared->name;
  return s;
}
