// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "timeline/TimeLineGroup.h"

#include <QDebug>
#include <QTimer>
#include <limits>

#include "TimeRange.h"
#include "misc.h"
#include "timeline/AbstractTimeLine.h"
#include "timeline/TimeLine.h"

static constexpr bool verbose{false};

TimeLineGroup::TimeLineGroup(QObject *parent)
    : QObject(parent),
      minBeginOfTime(std::numeric_limits<qreal>::max()),
      maxEndOfTime(std::numeric_limits<qreal>::min()),
      largestViewPort(QPair<qreal, qreal>(std::numeric_limits<qreal>::max(),
                                          std::numeric_limits<qreal>::min())) {
  items.reserve(20);

  /* We want relative time ranges (Last X seconds) to track real time, for
   * simplicity and also because that's probably the intent (rather than
   * "Last X seconds _of_data_").
   * Connect a 1sec timer to a slot in this TimeLineGroup, that will then
   * emit a signal with the desired offset, to which all items will be
   * connected. */
  relativeRangeTimer = new QTimer(this);
  connect(relativeRangeTimer, &QTimer::timeout, this,
          &TimeLineGroup::mayOffsetItems);
  relativeRangeTimer->start(1000);
}

void TimeLineGroup::add(AbstractTimeLine *w) {
  /* Make all time ranges the same: */
  if (w->beginOfTime() < minBeginOfTime) {
    minBeginOfTime = w->beginOfTime();
    for (int i = 0; i < items.size(); i++)
      items[i]->setBeginOfTime(minBeginOfTime);
  } else {
    w->setBeginOfTime(minBeginOfTime);
  }

  if (w->endOfTime() > maxEndOfTime) {
    maxEndOfTime = w->endOfTime();
    for (int i = 0; i < items.size(); i++) items[i]->setEndOfTime(maxEndOfTime);
  } else {
    w->setEndOfTime(maxEndOfTime);
  }

  QPair<qreal, qreal> vp(w->viewPort());
  if (vp.first < largestViewPort.first || vp.second > largestViewPort.second) {
    largestViewPort.first = std::min(largestViewPort.first, vp.first);
    largestViewPort.second = std::max(largestViewPort.second, vp.second);
    for (int i = 0; i < items.size(); i++)
      items[i]->setViewPort(largestViewPort);
  }
  w->setViewPort(largestViewPort);

  if (!items.empty()) {
    w->setCurrentTime(items[0]->currentTime());
  }

  /* If this is a TimeLine, connect its scrolling into all other widgets.
   * Also, connect scrolling of all previous TimeLines to this widget.
   * Also, connect all other cursors to this one and the other way around. */
  connect(w, &AbstractTimeLine::currentTimeChanged, this,
          &TimeLineGroup::setCurrentTimes);
  connect(w, &AbstractTimeLine::beginOfTimeChanged, this,
          &TimeLineGroup::setBeginOfTimes);
  connect(w, &AbstractTimeLine::endOfTimeChanged, this,
          &TimeLineGroup::setEndOfTimes);

  for (int i = 0; i < items.size(); i++) {
    AbstractTimeLine *w2 = items[i];

    if (w->doScroll()) {
      connect(w, &TimeLine::viewPortChanged, w2,
              &AbstractTimeLine::setViewPort);
    }
    if (w2->doScroll()) {
      connect(w2, &AbstractTimeLine::viewPortChanged, w,
              &AbstractTimeLine::setViewPort);
    }
  }

  // Finally, connect this new item to our offsetItems signal:
  connect(this, &TimeLineGroup::offsetItems, w, &AbstractTimeLine::offset);

  items.append(w);
  connect(w, &AbstractTimeLine::destroyed, this, &TimeLineGroup::remove);
}

// Beware that the QObject might already have been destroyed!
void TimeLineGroup::remove(QObject *w) {
  for (int i = 0; i < items.size(); i++) {
    if (items[i] == w) {
      items.remove(i);
      return;
    }
  }

  qWarning() << "TimeLineGroup: Asked to remove an unknown AbstractTimeLine"
             << w;
}

void TimeLineGroup::setCurrentTimes(qreal t) const {
  for (AbstractTimeLine *w : items) {
    if (w == sender()) continue;
    w->setCurrentTime(t);
  }
}

void TimeLineGroup::setBeginOfTimes(qreal t) const {
  for (AbstractTimeLine *w : items) {
    if (w == sender()) continue;
    w->setBeginOfTime(t);
  }
}

void TimeLineGroup::setEndOfTimes(qreal t) const {
  for (AbstractTimeLine *w : items) {
    if (w == sender()) continue;
    w->setEndOfTime(t);
  }
}

void TimeLineGroup::setTimeRange(TimeRange const &range) {
  if (verbose) qDebug() << "TimeLineGroup::setTimeRange to" << range;

  for (AbstractTimeLine *w : items) {
    if (w == sender()) continue;
    w->setTimeRange(range);
  }

  if (range.relative) {
    relativeRangeEnd = getTime() + range.until;
  } else {
    relativeRangeEnd = std::nullopt;
  }
}

void TimeLineGroup::mayOffsetItems() {
  if (!relativeRangeEnd) return;
  double const now{getTime()};
  emit offsetItems(now - *relativeRangeEnd);
  relativeRangeEnd = now;
}
