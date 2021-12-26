// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "dashboard/DashboardWidget.h"

#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>

#include "AtomicWidget.h"
#include "Resources.h"
#include "TimeRangeEdit.h"
#include "dashboard/Dashboard.h"
#include "dashboard/DashboardCopyDialog.h"
#include "dashboard/DashboardSelector.h"
#include "dashboard/DashboardWidgetChart.h"
#include "dashboard/DashboardWidgetText.h"
#include "dashboard/tools.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static bool const verbose{false};

DashboardWidget::DashboardWidget(Dashboard *dashboard_,
                                 DashboardWidgetForm *widgetForm_,
                                 QWidget *parent)
    : AtomicWidget(parent),
      dashboard(dashboard_),
      widgetForm(widgetForm_),
      widgetText(nullptr),
      widgetChart(nullptr),
      current(nullptr) {}

void DashboardWidget::setEnabled(bool enabled) {
  if (current) current->setEnabled(enabled);
}

std::shared_ptr<dessser::gen::sync_value::t const> DashboardWidget::getValue()
    const {
  if (current) return current->getValue();
  return nullptr;
}

bool DashboardWidget::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> val) {
  if (val->index() != dessser::gen::sync_value::DashboardWidget) {
    qCritical() << *val << "is not a DashboardWidget";
    return false;
  }

  std::shared_ptr<dessser::gen::dashboard_widget::t const> w{
      std::get<dessser::gen::sync_value::DashboardWidget>(*val)};

  AtomicWidget *newCurrent;
  QString newTitle;

  switch (w->index()) {
    case dessser::gen::dashboard_widget::Text:
      if (!widgetText) {
        if (verbose) qDebug() << "DashboardWidget: create a new text widget";

        widgetText = new DashboardWidgetText(widgetForm, this);

        if (widgetChart) {
          widgetText->setKey(widgetChart->key());
          widgetChart->deleteLater();
          widgetChart = nullptr;
        }
      }
      newCurrent = widgetText;
      break;
    case dessser::gen::dashboard_widget::Chart: {
      std::shared_ptr<dessser::gen::dashboard_widget::chart const> confChart{
          std::get<dessser::gen::dashboard_widget::Chart>(*w)};

      if (!widgetChart) {
        if (verbose) qDebug() << "DashboardWidget: create a new chart widget";

        widgetChart = new DashboardWidgetChart(widgetForm, this);

        if (widgetText) {
          widgetChart->setKey(widgetText->key());
          widgetText->deleteLater();
          widgetText = nullptr;
        }

        if (dashboard) {
          connect(dashboard->timeRangeEdit, &TimeRangeEdit::valueChanged,
                  widgetChart, &DashboardWidgetChart::timeRangeChanged);
          widgetChart->setTimeRange(dashboard->timeRangeEdit->range);
          connect(widgetChart, &DashboardWidgetChart::newTailTime, dashboard,
                  &Dashboard::setTailTime);
        }
      }
      newCurrent = widgetChart;
      newTitle = QString::fromStdString(confChart->title);
    } break;

    default:
      qFatal("DashboardWidget::setValue: invalid index");
  }

  if (newCurrent != current) {
    current = newCurrent;
    relayoutWidget(current);
  }

  if (newTitle != title) {
    title = newTitle;
    emit titleChanged(title);
  }

  return current->setValue(val);
}

void DashboardWidget::setKey(
    std::shared_ptr<dessser::gen::sync_key::t const> newKey) {
  /* What if the new key has a value of the wrong type?
   * There is no support for this. Actually, we do not allo to set the key more
   * than once! */
  std::shared_ptr<dessser::gen::sync_key::t const> curKey{key()};
  Q_ASSERT(!curKey || !newKey || *curKey != *newKey);
  saveKey(newKey);
  // Propagates:
  if (widgetText) widgetText->setKey(newKey);
  if (widgetChart) widgetChart->setKey(newKey);
}
