// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMECHARTEDITOR_H_200306
#define TIMECHARTEDITOR_H_200306
#include <QWidget>

class QPushButton;
class QWidget;
class TimeChart;
class TimeChartEditWidget;
class TimeLine;
class TimeLineGroup;
struct TimeRange;

class TimeChartEditor : public QWidget {
  Q_OBJECT

  TimeLine *timeLine;

 public:
  TimeChartEditWidget *editWidget;
  TimeChart *chart;
  QWidget *timeLines;

  TimeChartEditor(QPushButton *submitButton, QPushButton *cancelButton,
                  QPushButton *deleteButton, TimeLineGroup *timeLineGroup,
                  QWidget *parent = nullptr);

  ~TimeChartEditor();

 protected:
  void resizeEvent(QResizeEvent *);

 signals:
  // Re-emitted (after a few bounces) from the controlling TimeRangeEditor
  void timeRangeChanged(TimeRange const &);
};

#endif
