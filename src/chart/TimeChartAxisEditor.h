// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMECHARTAXISEDITOR_H_200309
#define TIMECHARTAXISEDITOR_H_200309
#include <QWidget>

class QCheckBox;
class QRadioButton;

namespace dessser {
namespace gen {
namespace dashboard_widget {
struct axis;
}
}  // namespace gen
}  // namespace dessser

class TimeChartAxisEditor : public QWidget {
  Q_OBJECT

 public:
  QRadioButton *left, *right;
  QCheckBox *forceZero;
  QRadioButton *linear, *logarithmic;

  TimeChartAxisEditor(QWidget *parent = nullptr);

  bool setValue(dessser::gen::dashboard_widget::axis const &);
  std::shared_ptr<dessser::gen::dashboard_widget::axis> getValue() const;

 signals:
  void valueChanged();
};

#endif
