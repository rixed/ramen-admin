#ifndef DASHBOARDWIDGET_H_200304
#define DASHBOARDWIDGET_H_200304
#include <memory>

#include "AtomicWidget.h"

class Dashboard;
class DashboardCopyDialog;
class DashboardWidgetChart;
class DashboardWidgetForm;
class DashboardWidgetText;
class QAction;
class QStackedLayout;
class QWidget;

/* This is an AtomicWidget that can switch representation between a chart
 * or a text box, thus surviving setKey that change the widget type.
 * It is the AtomicWidget that is added in the DashboardWidgetForm; The
 * underlying DashboardWidgetText/Chart is not. */
class DashboardWidget : public AtomicWidget {
  Q_OBJECT

  Dashboard *dashboard;
  DashboardWidgetForm *widgetForm;

  // Either none, one or the other is ever instantiated.
  DashboardWidgetText *widgetText;
  DashboardWidgetChart *widgetChart;
  AtomicWidget *current;

  QString title;

 public:
  /* If this is part of a dashboard (tu reuse its time setting) then
   * pass it, else nullptr: */
  DashboardWidget(Dashboard *, DashboardWidgetForm *,
                  QWidget *parent = nullptr);

  void setEnabled(bool) override;

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const override;

  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>) override;

  void setKey(std::shared_ptr<dessser::gen::sync_key::t const>) override;

 signals:
  void titleChanged(QString const &);
};

#endif
