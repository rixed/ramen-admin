#ifndef DASHBOARD_H_200304
#define DASHBOARD_H_200304
#include <list>
#include <string>
#include <QString>
#include <QWidget>

struct ConfChange;
class DashboardWidgetForm;
class FunctionSelector;
struct KValue;
class QLabel;
class QSplitter;
class TimeLineGroup;
class TimeRangeEdit;

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
    namespace sync_value { struct t; }
  }
}


class Dashboard : public QWidget
{
  Q_OBJECT

  std::string const name;

  struct WidgetRef {
    uint32_t idx;
    DashboardWidgetForm *widget;

    WidgetRef(uint32_t idx_, DashboardWidgetForm *widget_)
      : idx(idx_), widget(widget_) {}
  };
  std::list<WidgetRef> widgets; // ordered according to idx

  QSplitter *splitter;

  // The placeholder message when a dashboard is empty:
  QLabel *placeHolder;

  bool isMyKey(dessser::gen::sync_key::t const &);
  void resetArrows();

  void addValue(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &);
  void delValue(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &);

public:
  TimeLineGroup *timeLineGroup;
  FunctionSelector *functionSelector;
  TimeRangeEdit *timeRangeEdit;

  Dashboard(std::string const &dash_name, QWidget *parent = nullptr);

protected:
  /* Add a widget, in the right order according to the key. */
  void addWidget(std::shared_ptr<dessser::gen::sync_key::t const>);

  void delWidget(uint32_t);

public slots:
  void setTailTime(double);

protected slots:
  void onChange(QList<ConfChange> const &);

  void addCurrentFunction();
};
#endif
