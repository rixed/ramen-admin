// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMELINEGROUP_H_191205
#define TIMELINEGROUP_H_191205
/* This object is used to group together a set of AbstractTimeLine objects.
 * The grouping is logical not graphical: it merely connects all the widgets
 * together so that they share a single cursor, time range and viewport.
 * But it displays nothing (and is not a QWidget).
 * Consequently, it does not take ownership of the objects. */
#include <QObject>
#include <QPair>
#include <QVector>
#include <optional>

class AbstractTimeLine;
struct TimeRange;
class QTimer;

class TimeLineGroup : public QObject {
  Q_OBJECT

  QVector<AbstractTimeLine *> items;
  qreal minBeginOfTime, maxEndOfTime;
  QPair<qreal, qreal> largestViewPort;

  /* The TimeLineGroup will track current time whenever the time range is set to
   * a relative time, signaling all its items (using their `offset` slot) every
   * seconds: */
  std::optional<double> relativeRangeEnd;
  QTimer *relativeRangeTimer;

 public:
  TimeLineGroup(QObject *parent = nullptr);

  /* Does not take ownership of the passed timeline. */
  void add(AbstractTimeLine *);
  /* Won't complain if that timeline is not in the group: */
  void remove(QObject *);

 protected slots:
  void setCurrentTimes(qreal) const;
  void setBeginOfTimes(qreal) const;
  void setEndOfTimes(qreal) const;
  void mayOffsetItems();

 public slots:
  // Typically connected to a TimeRangeEditor:
  void setTimeRange(TimeRange const &);

 signals:
  void offsetItems(double dt);
};

#endif
