// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "timeline/BinaryHeatLine.h"

#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include "misc.h"

BinaryHeatLine::BinaryHeatLine(qreal beginOftime, qreal endOfTime,
                               bool withCursor, bool doScroll, QWidget *parent)
    : HeatLine(beginOftime, endOfTime, withCursor, doScroll, parent) {}

void BinaryHeatLine::add(qreal start, qreal stop) {
  /* Cannot be Qt::black because of this bug:
   * https://bugreports.qt.io/browse/QTBUG-9343 */
  HeatLine::add(start, stop, QColor(25, 25, 25));
}

void BinaryHeatLine::setArchivedTimes(
    dessser::gen::time_range::t const &archivedTimes) {
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
