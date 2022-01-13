// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "timeline/TimeLine.h"

#include <QApplication>
#include <QColor>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <cmath>

#include "misc.h"

static constexpr bool verbose{false};

TimeLine::TimeLine(qreal beginOftime, qreal endOfTime,
                   TicksPosition ticksPosition_, bool withCursor,
                   QWidget *parent)
    : AbstractTimeLine(beginOftime, endOfTime, withCursor, true, parent),
      ticksPosition(ticksPosition_) {}

static qreal roundTo(qreal step, qreal x) {
  return step * (std::floor((x + step / 2.) / step));
}

static int const offsetFromUtc{QDateTime::currentDateTime().offsetFromUtc()};

/* Date a begin and end timestamps, and an approximative number of desired
 * steps, and return a list of that many steps, within the given range, and
 * evenly spaced. */
static QVector<qreal> getTicks(int numSteps, QPair<qreal, qreal> const &range) {
  qreal const width{range.second - range.first};
  qreal const target{width /
                     numSteps};  // returned length must be close to this

  qreal const sec{1.};
  qreal const min{60 * sec};
  qreal const quarter{15 * min};
  qreal const hour{4 * quarter};
  qreal const halfDay{12 * hour};
  qreal const day{2 * halfDay};
  qreal const week{7 * day};

  qreal step;
  if (target > week / 2) {
    step = roundTo(week, target);
  } else if (target > day / 2) {
    step = roundTo(day, target);
  } else if (target > halfDay / 2) {
    step = roundTo(halfDay, target);
  } else if (target > hour / 2) {
    step = roundTo(hour, target);
  } else if (target > quarter / 2) {
    step = roundTo(quarter, target);
  } else if (target > min / 2) {
    step = roundTo(min, target);
  } else {  // nearest power of 10
    // Get the closest power of 10 below target:
    qreal f{std::pow(10, std::floor(std::log10(target)))};
    // if >=1, how much f is smaller than target:
    qreal i{std::floor(target / f)};
    if (i < 2.5 || 5 * f >= width) {
      // if it's less than 2.5 times smaller, use it
      step = f;
    } else if (i < 7.5 || 10 * f >= width) {
      // if it's around 5 times smaller, use 5 * f:
      step = 5 * f;
    } else {
      step = 10 * f;
    }
  }

  /* Before truncating, move to local time zone: */
  if (verbose) qDebug() << "Offset from UTC:" << offsetFromUtc;
  qreal start{roundTo(step, range.first + offsetFromUtc) - offsetFromUtc};

  if (verbose)
    qDebug() << "To get" << numSteps << "steps in between"
             << stringOfDate(range.first) << "and" << stringOfDate(range.second)
             << "starting at" << stringOfDate(start) << "with a step of"
             << stringOfDuration(step);

  QVector<qreal> res;
  res.reserve(numSteps + 2);
  // TODO: go further away to also display clipped labels
  while (start < range.second) {
    if (start >= range.first) {
      res.append(start);
      Q_ASSERT(res.length() < numSteps + 100);
    }
    start += step;
  }

  return res;
}

void TimeLine::paintTick(QPainter &painter, qreal const t,
                         int const ticksHeight) const {
  qreal const x{toPixel(t)};
  if (ticksPosition & TicksBottom) {
    qreal const y1{qreal(height())};
    qreal const y0{qreal(y1 - ticksHeight)};
    painter.drawLine(QLineF{x, y0, x, y1});
  }
  if (ticksPosition & TicksTop) {
    qreal const y0{0.};
    qreal const y1{qreal(y0 + ticksHeight)};
    painter.drawLine(QLineF{x, y0, x, y1});
  }
}

void TimeLine::paintLabel(QPainter &painter, QFont const &smallTimeFont,
                          QFont const &largeTimeFont, qreal const t,
                          QDateTime *lastTime, int const ticksHeight,
                          int const labelsHeight) const {
  qreal const x0{toPixel(t)};
  QDateTime time{QDateTime::fromSecsSinceEpoch(t)};
  bool const printDate{!lastTime || !lastTime->isValid() ||
                       lastTime->date() != time.date()};
  bool const printTime{time.time() != QTime(0, 0)};
  if (lastTime) *lastTime = time;

  qreal const h{printDate && printTime ? qreal(labelsHeight) / 2.
                                       : qreal(labelsHeight)};
  qreal y0{qreal(ticksHeight + 1)};

  auto print{[&](bool small, int x, int y, int h, QString const &str) {
    painter.setFont(small ? smallTimeFont : largeTimeFont);
    painter.drawText(QRect(x, y, 1, h),
                     Qt::AlignCenter | Qt::TextSingleLine | Qt::TextDontClip,
                     str);
  }};

  if (ticksPosition & TicksTop) {
    // First the time:
    if (printTime) {
      print(printDate, x0, y0, h, time.time().toString());
      y0 += h;
    }
    if (printDate) {
      print(printTime, x0, y0, h, time.date().toString());
    }
  } else {
    // First the date:
    if (printDate) {
      print(printTime, x0, y0, h, time.date().toString());
      y0 += h;
    }
    if (printTime) {
      print(printDate, x0, y0, h, time.time().toString());
    }
  }
}

void TimeLine::paintEvent(QPaintEvent *event) {
  AbstractTimeLine::paintEvent(event);

  static QColor const ticksColor{palette().color(QPalette::Text)};
  static QColor const labelsColor{palette().color(QPalette::Text)};
  int const ticksHeight{height() / 8};
  int const labelsHeight{3 * height() / 4};

  /* List of tick marks we want displayed: */
  QVector<qreal> ticks{getTicks(5, m_viewPort)};

  QPainter painter{this};

  painter.setPen(ticksColor);
  for (qreal t : ticks) {
    paintTick(painter, t, ticksHeight);
  }

  // Once again for the tick labels
  painter.setPen(labelsColor);
  QFont const smallTimeFont{"Arial", 3 * labelsHeight / 8};
  QFont const largeTimeFont{"Arial", 9 * labelsHeight / 32};

  QDateTime lastTime;
  for (qreal t : ticks) {
    paintLabel(painter, smallTimeFont, largeTimeFont, t, &lastTime, ticksHeight,
               labelsHeight);
  }

  // And the current time:
  qreal t{currentTime()};
  painter.setPen(AbstractTimeLine::cursorColor);
  paintTick(painter, t, ticksHeight);
  paintLabel(painter, smallTimeFont, largeTimeFont, t, nullptr, ticksHeight,
             labelsHeight);
}
