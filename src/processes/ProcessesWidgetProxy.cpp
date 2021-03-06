// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "processes/ProcessesWidgetProxy.h"

#include <QDebug>
#include <QModelIndex>
#include <QtGlobal>
#include <optional>

#include "FunctionItem.h"
#include "GraphItem.h"
#include "ProgramItem.h"
#include "ProgramPartItem.h"
#include "SiteItem.h"

static constexpr bool verbose{false};

ProcessesWidgetProxy::ProcessesWidgetProxy(QObject *parent)
    : QSortFilterProxyModel(parent),
      /* Will be set by ProcessesWin ctor, but avoids manipulation of
       * uninitialized data: */
      includeFinished(false),
      includeUnused(false),
      includeDisabled(false),
      includeNonRunning(false),
      includeTopHalves(false) {
  setDynamicSortFilter(false);  // Or segfaults may happen when removing workers
}

bool ProcessesWidgetProxy::filterAcceptsFunction(
    FunctionItem const &function) const {
  /* We can also list non-running processes:
   * - Unused:
   *     processes that do not run because they are lazy and unused;
   * - Disabled:
   *     processes that do not run because they are disabled;
   * - Finished:
   *     processes that used to run but exited with status 0 (typically
   *     removed from the RC); We have runtime stats but no worker;
   * - Not-running:
   *     processes that do not run (aka have a pid) but should (as there is
   *     a worker), for whatever *other* reason, such as being unused or
   *     because of the running condition or a crash.
   *
   * There can be several reasons why a process is not running; For instance
   * it could be prevented by the running condition and be unused and
   * disabled. */

  // Filter out unused functions, optionally:
  if (!includeUnused && !function.isUsed()) {
    if (verbose)
      qDebug() << "Filter out lazy function" << function.shared->name;
    return false;
  }

  // Filter out the top-halves, optionally:
  if (!includeTopHalves && function.isTopHalf()) {
    if (verbose)
      qDebug() << "Filter out top-half function" << function.shared->name;
    return false;
  }

  // ...and non-working functions
  if (!includeFinished && !function.isWorking()) {
    if (verbose)
      qDebug() << "Filter out non-working function" << function.shared->name;
    return false;
  }

  /* Optionally exclude functions with no pid, unless the function is unused
   * or not working, in which case obviously the function cannot have a pid: */
  if (function.isWorking() && !function.isRunning() && !includeNonRunning) {
    if (verbose)
      qDebug() << "Filter out non-running function" << function.shared->name;
    return false;
  }

  return true;
}

bool ProcessesWidgetProxy::filterAcceptsRow(
    int sourceRow, QModelIndex const &sourceParent) const {
  if (!sourceParent.isValid()) return true;

  /* For now keep it simple: Accept all sites and programs, filter only
   * function names. */
  GraphItem const *parentPtr{
      static_cast<GraphItem const *>(sourceParent.internalPointer())};

  SiteItem const *parentSite{dynamic_cast<SiteItem const *>(parentPtr)};
  if (parentSite) {
    /* The row denotes a programPart.
     * For now always accept intermediary programPart objects, and start
     * to filter only actual programs: */
    Q_ASSERT((size_t)sourceRow < parentSite->programParts.size());
    ProgramPartItem const *programPart{parentSite->programParts[sourceRow]};
    ProgramItem const *program{programPart->actualProgram};
    if (!program) return true;
    /* If that program is running only top-halves or non-working functions,
     * then also filter it. There is a vicious consequence though: if it's
     * just empty, and we later add a function that should not be filtered,
     * then the filters won't be updated and the program and functions
     * would stay hidden.
     * Note that setRecursiveFilteringEnabled(false) is of no help here,
     * as it seems to operate the other way around (and false is the default
     * value anyway).
     * One safe way out of this issue is to invalidate the filter each
     * time we add a function (see ProcessesWidget constructor when we connect
     * to rowsInserted).
     * One would think that the addition of rows in the program, and/or the
     * signalling of dataChanged from the program  whenever a function is
     * added/removed, would also provide the required information to the
     * proxy that it should reassess its filter, but that's actually not
     * the case.
     * Sites cause no such trouble because we always display even empty
     * sites. */
    if (verbose)
      qDebug() << "Filtering program" << program->shared->name << "?";

    // Filter entire programs if all their functions are filtered:
    if (0 == program->functions.size()) {
      if (verbose)
        qDebug() << "Filter out empty program" << program->shared->name;
      return false;
    }
    bool accepted{false};
    for (FunctionItem const *function : program->functions) {
      if (filterAcceptsFunction(*function)) {
        accepted = true;
        break;
      }
    }
    if (!accepted) {
      if (verbose)
        qDebug() << "Filter out entire program" << program->shared->name;
      return false;
    }
    return true;
  }

  ProgramPartItem const *parentProgramPart{
      dynamic_cast<ProgramPartItem const *>(parentPtr)};
  if (!parentProgramPart) {
    qCritical() << "Filtering the rows of a function?!";
    return false;
  }

  ProgramItem const *parentProgram{parentProgramPart->actualProgram};
  if (!parentProgram) {
    /* If not an actual program, displays it (for now. TODO: only when some of
     * its functions are not filtered? */
    return true;
  }

  /* When the parent is an actual program, build the FQ name of the function
   * and match that: */
  Q_ASSERT((size_t)sourceRow < parentProgram->functions.size());
  FunctionItem const *function{parentProgram->functions[sourceRow]};

  if (!filterAcceptsFunction(*function)) return false;

  /* So far so good. Now build the FQ name of the function and match that: */
  SiteItem const *site{
      static_cast<SiteItem const *>(parentProgram->treeParent)};

  QString const fq{site->shared->name + ":" + parentProgram->shared->name +
                   "/" + function->shared->name};
  return fq.contains(filterRegularExpression());
}

void ProcessesWidgetProxy::viewFinished(bool checked) {
  if (includeFinished == checked) return;
  includeFinished = checked;
  invalidateFilter();
}

void ProcessesWidgetProxy::viewUnused(bool checked) {
  if (includeUnused == checked) return;
  includeUnused = checked;
  invalidateFilter();
}

void ProcessesWidgetProxy::viewDisabled(bool checked) {
  if (includeDisabled == checked) return;
  includeDisabled = checked;
  invalidateFilter();
}

void ProcessesWidgetProxy::viewNonRunning(bool checked) {
  if (includeNonRunning == checked) return;
  includeNonRunning = checked;
  invalidateFilter();
}

void ProcessesWidgetProxy::viewTopHalves(bool checked) {
  if (includeTopHalves == checked) return;
  includeTopHalves = checked;
  invalidateFilter();
}
