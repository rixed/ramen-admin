#ifndef TIMECHARTEDITWIDGET_H_200306
#define TIMECHARTEDITWIDGET_H_200306
#include <functional>
#include <memory>
#include <optional>
#include <string>

#include "AtomicWidget.h"

class QPushButton;
class TimeChartFunctionsEditor;
class TimeChartOptionsEditor;

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
    namespace sync_value { struct t; }
    namespace dashboard_widget {
      struct axis;
      struct field;
    }
  }
}

/* FIXME: the actual AtomicWidget tracking the key is already the DashboardWidgetChart,
 * which is one of the personalities of the polymorphic DashboardWidget. Maybe this
 * TimechartWidget should then not be an AtomicWidget? */
class TimeChartEditWidget : public AtomicWidget
{
  Q_OBJECT

  TimeChartOptionsEditor *optionsEditor;
  TimeChartFunctionsEditor *functionsEditor;
  QPushButton *cancelButton, *deleteButton;

public:
  TimeChartEditWidget(
    QPushButton *submitButton,
    QPushButton *cancelButton,
    QPushButton *deleteButton,
    QWidget *parent = nullptr);

  void setEnabled(bool) override;

  bool setValue(
    std::shared_ptr<dessser::gen::sync_value::t const>) override;

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const override;

  int axisCountOnSide(bool left) const;

  // Returns the axis number, that can then later given to axis()
  std::optional<int> firstAxisOnSide(bool left) const;

  int axisCount() const;

  // or nullptr if this axis does not exist
  std::shared_ptr<dessser::gen::dashboard_widget::axis const> axis(int) const;

  void iterFields(std::function<void(
    std::string const &site, std::string const &program,
    std::string const &function, dessser::gen::dashboard_widget::field const &)>) const;

  void closeEvent(QCloseEvent *) override;

signals:
  void axisChanged(int);
  void fieldChanged(std::string const &site, std::string const &program,
                    std::string const &function, std::string const &name);
  // TODO: valueChanged, inputChanged?
};

#endif
