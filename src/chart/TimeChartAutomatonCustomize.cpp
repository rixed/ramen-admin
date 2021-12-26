// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "chart/TimeChartAutomatonCustomize.h"

#include <QDebug>

#include "FunctionItem.h"
#include "GraphModel.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_key.h"
#include "misc.h"

static std::shared_ptr<dessser::gen::sync_key::t const> targetConfigKey{
    std::make_shared<dessser::gen::sync_key::t>(
        std::in_place_index<dessser::gen::sync_key::TargetConfig>,
        dessser::VOID)};

TimeChartAutomatonCustomize::TimeChartAutomatonCustomize(
    std::string const &site_, std::string const &program_,
    std::string const &function_, QObject *parent)
    : Automaton("Customize function", NumStates, parent),
      site(site_),
      program(program_),
      function(function_) {
  customProgram = "tmp/" + srcPathFromProgramName(program) + "/" +
                  std::to_string(int64_t(getTime())) + "_" +
                  std::to_string(rand());

  customFunction = "custom_" + function;

  sourceKey = std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::Sources>, customProgram,
      "ramen");

  infoKey = std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::Sources>, customProgram,
      "info");

  /* FIXME: do not wait for the worker but for the addition in the global
   * graphModel, so that the function editors can find it as well! */
  workerKey = std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::PerSite>,
      std::make_shared<dessser::gen::sync_key::per_site>(
          site,
          std::make_shared<dessser::gen::sync_key::per_site_data>(
              std::in_place_index<dessser::gen::sync_key::PerWorker>,
              std::make_shared<dessser::gen::sync_key::per_worker>(
                  (customProgram + '/' + customFunction),
                  std::make_shared<dessser::gen::sync_key::per_worker_data>(
                      std::in_place_index<dessser::gen::sync_key::Worker>,
                      dessser::VOID)))));

  addTransition(WaitSource, WaitInfo, OnSet, sourceKey);
  addTransition(WaitInfo, WaitLockRC, OnSet, infoKey);
  addTransition(WaitLockRC, WaitWorkerOrGraph, OnLock, targetConfigKey);
  addTransition(WaitWorkerOrGraph, WaitGraph, OnSet, workerKey);
  addTransition(WaitWorkerOrGraph, WaitWorker);
  addTransition(WaitWorker, Done, OnSet, workerKey);

  /* Transitions from WaitWorkerOrGraph to WaitWorker and from
   * WaitGraph to Done are manual, triggered by this signal: */
  connect(GraphModel::globalGraphModel, &GraphModel::functionAdded, this,
          &TimeChartAutomatonCustomize::graphChanged);

  start();
}

void TimeChartAutomatonCustomize::graphChanged(
    FunctionItem const *functionItem) {
  std::shared_ptr<Function const> function{
      std::static_pointer_cast<Function const>(functionItem->shared)};
  if (function->name.toStdString() != customFunction ||
      function->programName != customProgram || function->siteName != site)
    return;

  if (currentState == WaitWorkerOrGraph)
    moveTo(WaitWorker);
  else if (currentState == WaitGraph)
    moveTo(Done);
  else
    qCritical() << "TimeChartAutomatonCustomize::graphChanged signaled while"
                   "currently in state"
                << currentState;
}
