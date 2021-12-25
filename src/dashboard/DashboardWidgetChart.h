#ifndef DASHBOARDWIDGETCHART_H_200304
#define DASHBOARDWIDGETCHART_H_200304
#include <string>

#include "AtomicWidget.h"

class DashboardWidgetForm;
class QWidget;
class TimeChartEditor;
class TimeLineGroup;
struct TimeRange;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class DashboardWidgetChart : public AtomicWidget {
  Q_OBJECT

  TimeChartEditor *chart;

 public:
  DashboardWidgetChart(
      // Passed to steal its form buttons:
      DashboardWidgetForm *, QWidget *parent = nullptr);

  void setEnabled(bool) override;

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const override;

  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>) override;

 public slots:
  void setTimeRange(TimeRange const &);

 signals:
  // Re-emitted from the controlling TimeRangeEditor:
  void timeRangeChanged(TimeRange const &);
  void newTailTime(double);
};

#endif
