// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "timeline/AbstractTimeLine.h"

#include <QDebug>
#include <QEnterEvent>
#include <QLineF>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPair>
#include <QPinchGesture>
#include <QPoint>
#include <QRectF>
#include <QSizePolicy>
#include <QWheelEvent>
#include <cmath>

#include "TimeRange.h"
#include "misc.h"

static constexpr bool verbose{false};

QColor const AbstractTimeLine::cursorColor{"orange"};
QColor const AbstractTimeLine::highlightColor{"orange"};

AbstractTimeLine::AbstractTimeLine(qreal beginOftime, qreal endOfTime,
                                   bool withCursor, bool doScroll,
                                   QWidget *parent)
    : QWidget(parent),
      m_beginOfTime(std::min(beginOftime, endOfTime)),
      m_endOfTime(std::max(beginOftime, endOfTime)),
      m_viewPort(QPair<qreal, qreal>(m_beginOfTime, m_endOfTime)),
      m_currentTime(
          m_beginOfTime),  // first mouse move will set this more accurately
      m_selection(noSelection),
      m_withCursor(withCursor),
      m_doScroll(doScroll),
      hovered(false) {
  setMouseTracking(true);
  setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));
  grabGesture(Qt::PinchGesture);
  setFocusPolicy(Qt::StrongFocus);
}

/*
 * Utilities
 */

qreal AbstractTimeLine::toPixel(qreal t) const {
  return ((t - m_viewPort.first) / viewPortWidth()) * width();
}

qreal AbstractTimeLine::toTime(qreal x) const {
  return (x / width()) * viewPortWidth() + m_viewPort.first;
}

/*
 * Event Handling
 */

void AbstractTimeLine::mousePressEvent(QMouseEvent *event) {
  switch (event->button()) {
    case Qt::LeftButton:
      if (m_doScroll) {
        scrollStart =
#if QT_VERSION > QT_VERSION_CHECK(6, 0, 0)
            event->position().x();
#else
            event->x();
#endif
        viewPortStartScroll = m_viewPort;
      } else {
        QWidget::mousePressEvent(event);
      }
      break;

    case Qt::RightButton:
      /* Start a new (candidate) selection: */
      candidateSelectionStart = m_currentTime;

      if (verbose)
        qDebug() << "candidate selection started at"
                 << stringOfDate(m_currentTime);
      break;

    default:
      /* Do not call this unless we really want to ignore the event, as
       * otherwise window-manager might start a window move for instance */
      QWidget::mousePressEvent(event);
      break;
  }
}

void AbstractTimeLine::mouseReleaseEvent(QMouseEvent *event) {
  /* If there was a selection going on, submit it: */
  if (candidateSelectionStart) {
    if (verbose)
      qDebug() << "candidate selection stopped at"
               << stringOfDate(m_currentTime);
    setSelection(QPair<qreal, qreal>(*candidateSelectionStart, m_currentTime));
    candidateSelectionStart.reset();
    emit selectionChanged(m_selection);
  }

  if (scrollStart) {
    scrollStart.reset();
  }

  QWidget::mouseReleaseEvent(event);
}

void AbstractTimeLine::mouseMoveEvent(QMouseEvent *event) {
  if (scrollStart) {
    /* Scrolling mode: offset the viewport */
    int const dx {
#if QT_VERSION > QT_VERSION_CHECK(6, 0, 0)
      int(round(event->position().x() - *scrollStart))
#else
      event->x() - *scrollStart
#endif
    };
    panViewPort(dx, &viewPortStartScroll);
  }

  /* Normal mouse move: update current time.
   * Note: selection might happen at the same time. */
#if QT_VERSION > QT_VERSION_CHECK(6, 0, 0)
  qreal const x{event->position().x()};
#else
  qreal const x{(qreal)event->x()};
#endif
  setCurrentPos(x, true);
  QWidget::mouseMoveEvent(event);
}

bool AbstractTimeLine::event(QEvent *event) {
  if (event->type() != QEvent::Gesture) {
  ignore:
    return QWidget::event(event);
  }

  QGestureEvent *e{static_cast<QGestureEvent *>(event)};
  QGesture *pinch_{e->gesture(Qt::PinchGesture)};
  if (!pinch_) goto ignore;

  QPinchGesture *pinch{static_cast<QPinchGesture *>(pinch_)};

  switch (pinch->state()) {
    case Qt::GestureUpdated: {
      qreal const centerTime{toTime(pinch->centerPoint().x())};
      setZoom(pinch->scaleFactor(), centerTime);
    } break;
    default:
      break;
  }
  return true;
}

void AbstractTimeLine::wheelEvent(QWheelEvent *event) {
  if (!m_doScroll) {
  ignore:
    QWidget::wheelEvent(event);  // will ignore() the event
    return;
  }

  QPoint p{event->pixelDelta()};
  if (p.isNull()) {
    p = event->angleDelta() / 8;
  }

  /* Handle horizontal panning */
  if (!p.isNull()) {
    int const dx{p.x()};
    panViewPort(dx);
    setCurrentPos(event->position().x(), true);
    /* Ideally we would reset this coordinate in the event so that it's
     * not again used by the parent event handers in case we eventually do not
     * accept the event. */
  }

  /* Zooming with the mouse wheel is more convenient than with the keyboard,
   * but it will prevent any enclosing scroll area to get the event, so for
   * instance in a long dashboard the user scrolling through the dashboard
   * would be interrupted with zooms. To limit this annoyance only the top left
   * corner is sensitive to zoom (FIXME: at least, display something there) */
  QPointF const mouse_pos{event->position()};
  if (mouse_pos.x() > 20 || mouse_pos.y() > 20) goto ignore;

  if (!p.isNull()) {
    qreal zoom{p.y() >= 0 ? 0.97 : 1.03};

    qreal const leftWidth{zoom * (m_currentTime - m_viewPort.first)};
    qreal const rightWidth{zoom * (m_viewPort.second - m_currentTime)};

    auto newViewPort{
        QPair<qreal, qreal>(std::max(m_currentTime - leftWidth, m_beginOfTime),
                            std::min(m_currentTime + rightWidth, m_endOfTime))};
    if (newViewPort == m_viewPort) goto ignore;

    setViewPort(newViewPort);
    emit viewPortChanged(m_viewPort);
  }

  /* Prevent propagation to any QScrollArea: */
  event->accept();
}

void AbstractTimeLine::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Plus:
      setZoom(1.1, m_currentTime);
      return;
    case Qt::Key_Minus:
      setZoom(0.9, m_currentTime);
      return;
    case Qt::Key_Left:
      moveViewPort(-0.1);
      return;
    case Qt::Key_Right:
      moveViewPort(0.1);
      return;
  }

  QWidget::keyPressEvent(event);
}

/*
 * Painting
 */

void AbstractTimeLine::paintEvent(QPaintEvent *event) {
  QWidget::paintEvent(event);

  QPainter painter{this};

  painter.setPen(Qt::NoPen);
  painter.setBrush(highlightColor);
  for (QPair<qreal, qreal> const &range : qAsConst(highlights)) {
    qreal const xStart{toPixel(range.first)};
    qreal const xStop{toPixel(range.second)};
    if (verbose)
      qDebug() << "AbstractTimeLine::paintEvent: highlighting from" << xStart
               << "to" << xStop;
    painter.drawRect(QRectF{std::floor(xStart), 0., std::ceil(xStop - xStart),
                            (qreal)height()});
  }

  if (m_withCursor && m_currentTime > m_beginOfTime) {
    painter.setPen(cursorColor);
    painter.setBrush(Qt::NoBrush);
    qreal const x{toPixel(m_currentTime)};
    painter.drawLine(QLineF{x, 0, x, (qreal)height()});
  }
}

/*
 * Properties and slots
 */

void AbstractTimeLine::setBeginOfTime(qreal t) {
  if (m_beginOfTime == t) return;

  if (verbose)
    qDebug() << "AbstractTimeLine: setBeginOfTime" << stringOfDate(t);

  // If we were looking at the end, keep tracking
  bool const trackEnd{m_viewPort.second >= m_endOfTime};

  if (m_endOfTime <= t) m_endOfTime += t - m_beginOfTime;

  m_beginOfTime = t;
  if (m_viewPort.first < t) {
    m_viewPort.second = std::min<qreal>(
        m_endOfTime, m_viewPort.second + (t - m_viewPort.first));
    m_viewPort.first = t;
  }

  if (trackEnd) {
    double const dt{m_endOfTime - m_viewPort.second};
    m_viewPort.first += dt;
    m_viewPort.second += dt;
  }

  update();
}

void AbstractTimeLine::setEndOfTime(qreal t) {
  if (m_endOfTime == t) return;

  if (verbose) qDebug() << "AbstractTimeLine: setEndOfTime" << stringOfDate(t);

  // If we were looking at the end, keep tracking
  bool const trackEnd{m_viewPort.second >= m_endOfTime};

  if (m_beginOfTime >= t) m_beginOfTime -= m_endOfTime - t;

  m_endOfTime = t;
  if (m_viewPort.second > t) {
    m_viewPort.first = std::max<qreal>(
        m_beginOfTime, m_viewPort.first - (m_viewPort.second - t));
    m_viewPort.second = t;
  }

  if (trackEnd) {
    double const dt{m_endOfTime - m_viewPort.second};
    m_viewPort.first += dt;
    m_viewPort.second += dt;
  }

  update();
}

void AbstractTimeLine::setCurrentTime(qreal t, bool signal_if_changed) {
  if (t < m_beginOfTime)
    t = m_beginOfTime;
  else if (t > m_endOfTime)
    t = m_endOfTime;

  if (t != m_currentTime) {
    m_currentTime = t;
    if (signal_if_changed) emit currentTimeChanged(t);
    update();
  }
}

void AbstractTimeLine::setCurrentPos(int const x, bool signal_if_changed) {
  qreal const ratio{qreal(x) / width()};
  qreal const offs{viewPortWidth() * ratio};
  qreal t{m_viewPort.first + offs};
  setCurrentTime(t, signal_if_changed);
}

void AbstractTimeLine::setViewPort(QPair<qreal, qreal> const &vp) {
  /* Should not happen but better safe than sorry: */
  if (vp.first < m_beginOfTime || vp.first >= m_endOfTime ||
      vp.second <= m_beginOfTime || vp.second > m_endOfTime) {
    qCritical() << "AbstractTimeLine: Invalid viewPort:"
                << qSetRealNumberPrecision(13) << vp << "not within"
                << m_beginOfTime << "…" << m_endOfTime;
    return;
  }

  m_viewPort = QPair<qreal, qreal>(std::min<qreal>(vp.first, vp.second),
                                   std::max<qreal>(vp.first, vp.second));

  static qreal const min_viewport_width{1.};
  if (viewPortWidth() < min_viewport_width) {
    qreal const mid{0.5 * (m_viewPort.second + m_viewPort.first)};
    m_viewPort.first = mid - min_viewport_width / 2;
    m_viewPort.second = mid + min_viewport_width / 2;
  }

  if (verbose)
    qDebug() << "viewPort =" << stringOfDate(m_viewPort.first) << "..."
             << stringOfDate(m_viewPort.second);

  update();
}

void AbstractTimeLine::setZoom(qreal z, qreal centerTime) {
  if (z <= 0) {
    qCritical() << "Invalid zoom" << z;
    return;
  }

  if (verbose)
    qDebug() << "AbstractTimeLine: setZoom(" << z << "," << centerTime << ")";

  setViewPort(QPair<qreal, qreal>(
      std::max(centerTime - (centerTime - m_viewPort.first) / z, m_beginOfTime),
      std::min(centerTime + (m_viewPort.second - centerTime) / z,
               m_endOfTime)));
  emit viewPortChanged(m_viewPort);
}

void AbstractTimeLine::moveViewPort(qreal ratio) {
  qreal const dt{viewPortWidth() * ratio};
  setViewPort(
      QPair<qreal, qreal>(std::max(m_viewPort.first + dt, m_beginOfTime),
                          std::min(m_viewPort.second + dt, m_endOfTime)));
  emit viewPortChanged(m_viewPort);
}

void AbstractTimeLine::panViewPort(int const dx,
                                   QPair<qreal, qreal> const *origin) {
  if (dx == 0) return;

  if (!origin) origin = &m_viewPort;

  qreal const ratio{(qreal)dx / width()};
  qreal dt{viewPortWidth() * ratio};
  if (origin->first - dt < m_beginOfTime) {
    dt = origin->first - m_beginOfTime;
  } else if (origin->second - dt > m_endOfTime) {
    dt = origin->second - m_endOfTime;
  }
  setViewPort(QPair<qreal, qreal>(std::max(origin->first - dt, m_beginOfTime),
                                  std::min(origin->second - dt, m_endOfTime)));
  emit viewPortChanged(m_viewPort);
}

void AbstractTimeLine::setSelection(QPair<qreal, qreal> const &sel) {
  m_selection = QPair<qreal, qreal>(std::min<qreal>(sel.first, sel.second),
                                    std::max<qreal>(sel.first, sel.second));

  qDebug() << "selection =" << stringOfDate(m_selection.first) << "..."
           << stringOfDate(m_selection.second);
}

QPair<qreal, qreal> AbstractTimeLine::noSelection(0, 0);

void AbstractTimeLine::clearSelection() { m_selection = noSelection; }

/* This is called when the time range selector is changed by the user.
 * If the range is relative though our controlling TimeLineGroup will use
 * a 1sec timer to offset the begin and end of time (while keeping the viewport
 * steady as long as possible). */
void AbstractTimeLine::setTimeRange(TimeRange const &range) {
  double since, until;
  range.absRange(&since, &until);
  if (verbose)
    qDebug() << "AbstractTimeLine: setTimeRange(" << stringOfDate(since) << ","
             << stringOfDate(until) << ")";
  setBeginOfTime(since);
  setEndOfTime(until);
  // Also reset the zoom
  setViewPort(QPair<qreal, qreal>{since, until});
}

void AbstractTimeLine::offset(double dt) {
  qreal const vp_start{m_viewPort.first};
  setBeginOfTime(m_beginOfTime + dt);
  setEndOfTime(m_endOfTime + dt);
  // Only if the viewport has changed to tracks the time!
  if (m_viewPort.first != vp_start) setCurrentTime(m_currentTime + dt, false);
}

void AbstractTimeLine::highlightRange(QPair<qreal, qreal> const range) {
  if (verbose) qDebug() << "AbstractTimeLine: highlight range" << range;
  highlights.append(range);
  update();
}

void AbstractTimeLine::resetHighlights() {
  if (verbose) qDebug() << "AbstractTimeLine: reset highlights";
  highlights.clear();
  update();
}
