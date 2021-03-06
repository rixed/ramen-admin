// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMECHARTFUNCTIONEDITOR_H_200306
#define TIMECHARTFUNCTIONEDITOR_H_200306
#include <QSize>
#include <QWidget>
#include <memory>
#include <string>

class Automaton;
class FactorsDelegate;
class FixedTableView;
struct KValue;
class QCheckBox;
class QLineEdit;
class QPushButton;
class TimeChartFunctionFieldsModel;

namespace dessser {
namespace gen {
namespace dashboard_widget {
struct source;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class TimeChartFunctionEditor : public QWidget {
  Q_OBJECT

  FactorsDelegate *factorsDelegate;

  QPushButton *customize;
  QPushButton *openSource;
  QPushButton *deleteButton;

  FixedTableView *fields;

 public:
  QCheckBox *visible;  // To disable the whole source temporarily
  TimeChartFunctionFieldsModel *model;

  TimeChartFunctionEditor(
      std::string const &site, std::string const &program,
      std::string const &function,
      bool customizable = true,  // TODO: disable this for the raw config editor
      QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::dashboard_widget::source> getValue() const;

 protected slots:
  void wantSource();
  void wantCustomize();
  void automatonTransition(Automaton *, size_t,
                           std::shared_ptr<dessser::gen::sync_value::t const>);

 public slots:
  void setEnabled(bool);
  bool setValue(dessser::gen::dashboard_widget::source const &);

 signals:
  void fieldChanged(std::string const &site, std::string const &program,
                    std::string const &function, std::string const &name);
  void customizedFunction(std::string const &site, std::string const &program,
                          std::string const &function);
};

#endif
