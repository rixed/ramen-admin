#include <QDebug>
#include <QHBoxLayout>
#include <QSizePolicy>

#include "chart/TimeChartEditor.h"
#include "chart/TimeChartEditWidget.h"
#include "dashboard/Dashboard.h"
#include "dashboard/DashboardWidgetForm.h"

#include "dashboard/DashboardWidgetChart.h"

static bool const verbose(false);

DashboardWidgetChart::DashboardWidgetChart(
  DashboardWidgetForm *widgetForm,
  QWidget *parent)
  : AtomicWidget(parent)
{
  chart =
    new TimeChartEditor(
      widgetForm ? widgetForm->submitButton : nullptr,
      widgetForm ? widgetForm->cancelButton : nullptr,
      widgetForm ? widgetForm->deleteButton : nullptr,
      widgetForm ? widgetForm->dashboard->timeLineGroup : nullptr);

  connect(this, &DashboardWidgetChart::timeRangeChanged,
          chart, &TimeChartEditor::timeRangeChanged);
  connect(chart, &TimeChartEditor::newTailTime,
          this, &DashboardWidgetChart::newTailTime);

  /* Open/close the editor when the AtomicForm is enabled/disabled: */
  if (widgetForm) {
    if (verbose)
      qDebug() << "DashboardWidgetChart: set TimechartEditWidget visibility to"
               << widgetForm->isEnabled();
    widgetForm->setExpand(true);
    chart->editWidget->setVisible(widgetForm->isEnabled());
    connect(widgetForm, &DashboardWidgetForm::changeEnabled,
            chart->editWidget, &TimeChartEditWidget::setVisible);
  }

  QSizePolicy p { sizePolicy() };
  p.setVerticalPolicy(QSizePolicy::MinimumExpanding);
  p.setVerticalStretch(1);
  setSizePolicy(p);

  relayoutWidget(chart);
}

void DashboardWidgetChart::setTimeRange(TimeRange const &range)
{
  emit timeRangeChanged(range);
}

void DashboardWidgetChart::setEnabled(bool enabled)
{
  chart->editWidget->setEnabled(enabled);
}

std::shared_ptr<dessser::gen::sync_value::t const> DashboardWidgetChart::getValue() const
{
  return chart->editWidget->getValue();
}

bool DashboardWidgetChart::setValue(
  std::shared_ptr<dessser::gen::sync_value::t const> val)
{
  return chart->editWidget->setValue(val);
}
