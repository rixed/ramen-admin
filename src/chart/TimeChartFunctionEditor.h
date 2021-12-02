#ifndef TIMECHARTFUNCTIONEDITOR_H_200306
#define TIMECHARTFUNCTIONEDITOR_H_200306
#include <memory>
#include <string>
#include <QSize>
#include <QWidget>

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
    namespace dashboard_widget { struct source; }
    namespace sync_value { struct t; }
  }
}

class TimeChartFunctionEditor : public QWidget
{
  Q_OBJECT

  FactorsDelegate *factorsDelegate;

public:
  QCheckBox *visible;   // To disable the whole source temporarily
  QPushButton *customize;
  QPushButton *openSource;
  QPushButton *deleteButton;

  FixedTableView *fields;

  TimeChartFunctionFieldsModel *model;

  TimeChartFunctionEditor(
    std::string const &site,
    std::string const &program,
    std::string const &function,
    bool customizable = true,  // TODO: disable this for the raw config editor
    QWidget *parent = nullptr);

protected slots:
  void wantSource();
  void wantCustomize();
  void automatonTransition(
    Automaton *, size_t, std::shared_ptr<dessser::gen::sync_value::t const>);

public slots:
  void setEnabled(bool);
  bool setValue(dessser::gen::dashboard_widget::source const &);
  std::shared_ptr<dessser::gen::dashboard_widget::source> getValue() const;

signals:
  void fieldChanged(std::string const &site, std::string const &program,
                    std::string const &function, std::string const &name);
  void customizedFunction(std::string const &site, std::string const &program,
                          std::string const &function);
};

#endif
