// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef FUNCTIONITEM_H_190509
#define FUNCTIONITEM_H_190509
#include <QObject>
#include <QString>
#include <functional>
#include <memory>
#include <optional>
#include <vector>

#include "GraphItem.h"
#include "PastData.h"
#include "desssergen/time_range.h"  // no "struct t;" that could be declared

struct GraphViewSettings;
class TailModel;

namespace dessser {
namespace gen {
namespace worker {
struct t;
}
namespace runtime_stats {
struct t;
}
namespace source_info {
struct t;
struct compiled_func;
}  // namespace source_info
}  // namespace gen
}  // namespace dessser

// FIXME: move me in Function.h
class Function : public QObject, public GraphData {
  Q_OBJECT

  /* Created on demand, deleted after a while when the function is the only
   * reference holder and when the worker changes: */
  std::shared_ptr<TailModel> tailModel;

  /* All past data that will ever be asked for this function.
   * Shared pointer anyway, since some callee might want to keep it longer
   * than the lifetime of this FunctionItem.
   * Null until we get the event-time. */
  std::shared_ptr<PastData> pastData;

 public:
  std::string const siteName, programName;
  /* In addition to the name we want the fqName to be available
   * when all we have is a shared_ptr<Function>: */
  std::string const fqName;
  /* And the srcPath: */
  std::string const srcPath;

  std::shared_ptr<dessser::gen::worker::t const> worker;
  std::shared_ptr<dessser::gen::runtime_stats::t const> runtimeStats;
  std::shared_ptr<dessser::gen::time_range::t const> archivedTimes;
  std::optional<int64_t> numArcFiles;
  std::optional<int64_t> numArcBytes;
  std::optional<int64_t> allocArcBytes;
  std::optional<uint32_t> pid;
  std::optional<double> lastKilled;
  std::optional<double> lastExit;
  std::optional<QString> lastExitStatus;
  std::optional<int64_t> successiveFailures;
  std::optional<double> quarantineUntil;
  /* instanceSignature is the signature used by supervisor to store a worker
   * state. It's taken from the Worker it's trying to run, and should be equal
   * to worker->workerSign, when we have the worker.
   * In case those disagree we reset either the worker or the instance info,
   * whichever is older. (Warning loudly when a new instance is received before
   * the worker, as it's supposed to happen the other way around.) */
  std::optional<QString> instanceSignature;

  Function(std::string const &site, std::string const &program,
           std::string const &function, std::string const &srcPath);

  std::shared_ptr<TailModel> getTail() const { return tailModel; };
  std::shared_ptr<TailModel> getOrCreateTail();

  // Returns nullptr if the info is not available yet
  std::shared_ptr<dessser::gen::source_info::compiled_func const> compiledInfo()
      const;
  // Returns nullptr is the type is still unknown:
  std::shared_ptr<dessser::gen::raql_type::t const> outType() const;
  // Returns nullptr if the info is not available yet
  std::shared_ptr<EventTime const> getTime() const;
  std::shared_ptr<dessser::gen::event_time::t const> get_event_time() const;
  // Returns the pastData if possible:
  std::shared_ptr<PastData> getPast();

  /* Iterate over all tuples over the time range, be them in pastData or the
   * tailModel. Also request for missing past data.
   * if onePast is true, include one point before/after the range given
   * (useful to draw line plots) */
  void iterValues(
      double since, double until, bool onePast, std::vector<int> const &columns,
      /* TODO: document the lifespan on those pointers to raql_value. Is
       * it safe to store? If not, shouldn't they be shared_ptr? */
      std::function<void(double,
                         std::vector<std::shared_ptr<
                             dessser::gen::raql_value::t const> > const)>);

  void resetInstanceData();
  void checkTail();
  static std::shared_ptr<Function> find(QString const &site,
                                        QString const &program,
                                        QString const &name);

 protected slots:
  void setMinTail(double);
};

class FunctionItem : public GraphItem {
  Q_OBJECT

 protected:
  std::vector<std::pair<QString const, QString const> > labels() const override;

 public:
  // FIXME: Function destructor must clean those:
  // Not the parent in the GraphModel but the parents of the operation:
  std::vector<FunctionItem *> parents;

  unsigned channel;  // could also be used to select a color?

  FunctionItem(GraphItem *treeParent, std::unique_ptr<Function>,
               GraphViewSettings const *);

  QVariant data(int, int) const override;

  QRectF operationRect() const override;

  bool isTopHalf() const override;

  bool isWorking() const override;  // has a worker

  bool isRunning() const override;  // has a pid

  bool isUsed()
      const override;  // either not lazy, or have no deps (is_used flag)

  operator QString() const;

  QString const typeName() const { return QString("FunctionItem"); }
};

#endif
