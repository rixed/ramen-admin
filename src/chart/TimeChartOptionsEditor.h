// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMECHARTOPTIONSEDITOR_H_200306
#define TIMECHARTOPTIONSEDITOR_H_200306
#include <QWidget>
#include <memory>

class QLineEdit;
class QTabWidget;
class TimeChartEditWidget;

namespace dessser {
namespace gen {
namespace dashboard_widget {
struct chart;
}
}  // namespace gen
}  // namespace dessser

class TimeChartOptionsEditor : public QWidget {
  Q_OBJECT

  TimeChartEditWidget *editWidget;

 public:
  QLineEdit *title;

  /* Each tab is a TimeChartAxisEditor */
  QTabWidget *axes;

  TimeChartOptionsEditor(TimeChartEditWidget *, QWidget *parent = nullptr);

  void setEnabled(bool);
  bool setValue(std::shared_ptr<dessser::gen::dashboard_widget::chart const>);

 public slots:
  void updateAfterFieldChange(std::string const &site,
                              std::string const &program,
                              std::string const &function,
                              std::string const &field);

 signals:
  void axisChanged(int);
};

#endif
