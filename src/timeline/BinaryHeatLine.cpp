#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>

#include "misc.h"

#include "timeline/BinaryHeatLine.h"

BinaryHeatLine::BinaryHeatLine(
  qreal beginOftime, qreal endOfTime,
  bool withCursor,
  bool doScroll,
  QWidget *parent)
  : HeatLine(beginOftime, endOfTime, withCursor, doScroll, parent)
{
}

void BinaryHeatLine::add(qreal start, qreal stop)
{
  /* Cannot be Qt::black because of this bug:
   * https://bugreports.qt.io/browse/QTBUG-9343 */
  HeatLine::add(start, stop, QColor(25, 25, 25));
}

void BinaryHeatLine::setArchivedTimes(dessser::gen::time_range::t const &archivedTimes)
{
  reset();
  for (auto const &r : archivedTimes) {
    if (r.since >= r.until) {
      qWarning() << "BinaryHeatLine: Skip invalid range "
                 << stringOfDate(r.since) << "..." << stringOfDate(r.until);
      continue;
    }
    add(r.since, r.until);
  }
  update();
}
