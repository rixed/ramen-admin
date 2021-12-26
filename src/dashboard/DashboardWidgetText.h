// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef DASHBOARDWIDGETTEXT_H_200304
#define DASHBOARDWIDGETTEXT_H_200304
#include <string>

#include "AtomicWidget.h"

class DashboardWidgetForm;
class GrowingTextEdit;

class DashboardWidgetText : public AtomicWidget {
  Q_OBJECT

  GrowingTextEdit *text;

 public:
  DashboardWidgetText(DashboardWidgetForm *, QWidget *parent = nullptr);

  void setEnabled(bool) override;

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const override;

  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>) override;
};

#endif
