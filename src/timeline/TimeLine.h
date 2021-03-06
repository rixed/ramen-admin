// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TIMELINE_H_191204
#define TIMELINE_H_191204
/* A Timeline is an AbstractTimeLine that displays an axis with tick
 * marks and labels.
 */
#include "timeline/AbstractTimeLine.h"

class QPainter;

class TimeLine : public AbstractTimeLine {
  Q_OBJECT

 public:
  enum TicksPosition {
    TicksTop = 0x1,
    TicksBottom = 0x2,
  };

  TimeLine(qreal beginOftime, qreal endOfTime, TicksPosition = TicksTop,
           bool withCursor = true, QWidget *parent = nullptr);

  QSize sizeHint() const override { return QSize(250, 40); }

 protected:
  void paintTick(QPainter &, qreal const, int const ticksHeight) const;

  void paintEvent(QPaintEvent *) override;

  void paintLabel(QPainter &, QFont const &, QFont const &, qreal const,
                  QDateTime *lastTime, int const ticksHeight,
                  int const labelsHeight) const;

 private:
  TicksPosition ticksPosition;
};

#endif
