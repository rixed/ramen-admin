// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMECHARTFUNCTIONSEDITOR_H_200306
#define TIMECHARTFUNCTIONSEDITOR_H_200306
#include <QWidget>
#include <list>

class Function;
class FunctionSelector;
class QToolBox;
class TimeChartFunctionEditor;
class FixedWidthToolBox;

namespace dessser {
namespace gen {
namespace dashboard_widget {
struct chart;
}
}  // namespace gen
}  // namespace dessser

class TimeChartFunctionsEditor : public QWidget {
  Q_OBJECT

  void allFieldsChanged(int);
  TimeChartFunctionEditor *addFunctionByName(std::string const &site,
                                             std::string const &program,
                                             std::string const &function,
                                             bool customizable);
  void addOrFocus(std::string const &site, std::string const &program,
                  std::string const &function, bool customizable);

 public:
  FixedWidthToolBox *functions;
  FunctionSelector *functionSelector;

  TimeChartFunctionsEditor(QWidget *parent = nullptr);
  bool setValue(dessser::gen::dashboard_widget::chart const &);
  void setEnabled(bool);

 protected slots:
  void addCurrentFunction();
  void addCustomizedFunction(std::string const &site,
                             std::string const &program,
                             std::string const &function);

 signals:
  void fieldChanged(std::string const &site, std::string const &program,
                    std::string const &function, std::string const &name);
};

#endif
