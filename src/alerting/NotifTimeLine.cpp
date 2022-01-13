// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/NotifTimeLine.h"

#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QToolTip>
#include <cmath>
#include <utility>
#include <vector>

#include "alerting/AlertingLogsModel.h"
#include "alerting/tools.h"
#include "desssergen/alerting_log.h"
#include "misc.h"

static constexpr bool verbose{false};

static constexpr qreal unselected_opacity{0.3};

NotifTimeLine::NotifTimeLine(std::string const incidentId_, qreal beginOftime,
                             qreal endOfTime, bool withCursor, bool doScroll,
                             QWidget *parent)
    : AbstractTimeLine(beginOftime, endOfTime, withCursor, doScroll, parent),
      incidentId(incidentId_) {}

void NotifTimeLine::paintTick(dessser::gen::alerting_log::t const &log,
                              QPainter *painter, qreal width, qreal x, qreal y0,
                              qreal y1, bool is_selected) const {
  qreal const tickWidth{14};
  qreal const x0{x - 0.5 * tickWidth};
  qreal const x1{x + 0.5 * tickWidth};
  qreal const y{0.5 * (y0 + y1)};
  qreal const h{y1 - y0};
  if (x0 > width || x1 < 0) return;
  QPointF const rightTriangle[3]{QPointF(x, y0), QPointF(x1, y),
                                 QPointF(x, y1)};
  // Same color than BinaryHeatLine blocks
  QColor tickColor{25, 25, 25};
  painter->setPen(Qt::NoPen);
  painter->setPen(Qt::NoBrush);
  QPen thick{tickColor};
  thick.setWidth(2);
  painter->setRenderHint(QPainter::Antialiasing, true);
  painter->setOpacity(is_selected ? 1. : unselected_opacity);

  switch (log.index()) {
    case dessser::gen::alerting_log::NewNotification:
      switch (
          std::get<dessser::gen::alerting_log::NewNotification>(log).index()) {
        case dessser::gen::alerting_log::Duplicate:
          painter->setPen(thick);
          painter->drawLine(x0, y0, x0, y1);
          painter->setPen(Qt::NoPen);
          painter->setBrush(tickColor);
          painter->drawConvexPolygon(rightTriangle,
                                     SIZEOF_ARRAY(rightTriangle));
          break;
        case dessser::gen::alerting_log::Inhibited:
          [[fallthrough]];
        case dessser::gen::alerting_log::STFU:
          painter->setPen(thick);
          painter->setBrush(Qt::NoBrush);
          painter->drawConvexPolygon(rightTriangle,
                                     SIZEOF_ARRAY(rightTriangle));
          break;
        case dessser::gen::alerting_log::StartEscalation:
          painter->setPen(thick);
          painter->drawConvexPolygon(rightTriangle,
                                     SIZEOF_ARRAY(rightTriangle));
          break;
      }
      break;
    case dessser::gen::alerting_log::Outcry:
      painter->setPen(thick);
      painter->drawLine(x, y0, x, y1);
      painter->setPen(tickColor);
      {
        qreal dr{0};
        for (int count = 0; count < 3 && dr > h; count++, dr += 4) {
          QRectF const sq{x0 + dr, y0 + dr, h - 2 * dr, h - 2 * dr};
          painter->drawArc(sq, -45 * 16, 45 * 16);
        }
      }
      break;
    case dessser::gen::alerting_log::Ack:
      painter->setPen(thick);
      painter->drawLine(x, y0, x, y1);
      painter->setPen(tickColor);
      {
        qreal dr{0};
        painter->setPen(tickColor);
        for (int count = 0; count < 3 && dr > h; count++, dr += 4) {
          QRectF const sq{x0 + dr, y0 + dr, h - 2 * dr, h - 2 * dr};
          painter->drawArc(sq, 135 * 16, 225 * 16);
        }
      }
      break;
    case dessser::gen::alerting_log::Stop: {
      QPointF const leftTriangle[3]{QPointF(x, y0), QPointF(x, y1),
                                    QPointF(x0, y)};
      painter->setBrush(tickColor);
      painter->drawConvexPolygon(leftTriangle, SIZEOF_ARRAY(leftTriangle));
    } break;
    case dessser::gen::alerting_log::Cancel:
      painter->setPen(thick);
      painter->drawLine(x0, y0, x1, y1);
      painter->drawLine(x1, y0, x0, y1);
      break;
  }
}

void NotifTimeLine::paintEvent(QPaintEvent *event) {
  /* In chronological order: */
  std::vector<
      std::pair<double, std::shared_ptr<dessser::gen::alerting_log::t const> > >
      logs;
  logs.reserve(100);
  /* While at it, look for the closest log (and select it): */
  qreal closest_time;
  std::shared_ptr<dessser::gen::alerting_log::t const> closest_log;
  double closest_dist;
  QPoint const pos{mapFromGlobal(QCursor::pos())};
  bool const hover{rect().contains(pos)};
  qreal const curs_time{toTime(pos.x())};

  iterLogs(
      incidentId,
      [&logs, &closest_time, &closest_log, &closest_dist, &hover, &curs_time](
          double time,
          std::shared_ptr<dessser::gen::alerting_log::t const> log) {
        logs.emplace_back(time, log);

        double const this_dist{std::abs(time - curs_time)};
        if (hover && (!closest_log || this_dist < closest_dist)) {
          closest_time = time;
          closest_log = log;
          closest_dist = this_dist;
        }
      });
  if (verbose)
    qDebug() << "NotifTimeLine::paintEvent:" << logs.size() << "log entries";
  if (closest_log) {
    selected = closest_log;
  } else {
    selected = nullptr;
  }

  struct {
    bool operator()(
        std::pair<double,
                  std::shared_ptr<dessser::gen::alerting_log::t const> > const
            &a,
        std::pair<double,
                  std::shared_ptr<dessser::gen::alerting_log::t const> > const
            &b) const {
      return a.first < b.first;
    }
  } chronologicalOrder;
  std::sort(logs.begin(), logs.end(), chronologicalOrder);

  QPainter painter{this};

  /* Paint the background: */
  std::optional<qreal> prevX;
  bool was_selected;
  for (std::pair<double,
                 std::shared_ptr<dessser::gen::alerting_log::t const> > const
           &l : logs) {
    double const time{l.first};
    std::shared_ptr<dessser::gen::alerting_log::t const> const log{l.second};

    qreal const x{toPixel(time)};
    if (prevX) {
      painter.setPen(Qt::NoPen);

      switch (log->index()) {
        case dessser::gen::alerting_log::NewNotification:
          switch (std::get<dessser::gen::alerting_log::NewNotification>(*log)
                      .index()) {
            case dessser::gen::alerting_log::Duplicate:
              painter.setBrush(Qt::white);
              break;
            case dessser::gen::alerting_log::Inhibited:
              [[fallthrough]];
            case dessser::gen::alerting_log::STFU:
              painter.setBrush(Qt::yellow);
              break;
            case dessser::gen::alerting_log::StartEscalation:
              painter.setBrush(Qt::white);
              break;
          }
          break;
        case dessser::gen::alerting_log::Outcry:
          painter.setBrush(Qt::red);
          break;
        case dessser::gen::alerting_log::Ack:
          painter.setBrush(Qt::yellow);
          break;
        case dessser::gen::alerting_log::Stop:
          [[fallthrough]];
        case dessser::gen::alerting_log::Cancel:
          painter.setBrush(Qt::NoBrush);
          break;
      }

      painter.setOpacity(was_selected ? 1. : unselected_opacity);
      painter.drawRect(QRectF(*prevX, 0., x - *prevX, qreal(height())));
    }

    prevX = x;
    was_selected = log.get() == selected.get();
  }

  /* Paint the log ticks: */
  for (std::pair<double,
                 std::shared_ptr<dessser::gen::alerting_log::t const> > const
           &l : logs) {
    double const time{l.first};
    std::shared_ptr<dessser::gen::alerting_log::t const> const log{l.second};

    qreal const x{toPixel(time)};
    paintTick(*log, &painter, width(), x, 0, height(),
              log.get() == selected.get());
  }

  /* Paint the cursor over: */
  AbstractTimeLine::paintEvent(event);
}

bool NotifTimeLine::event(QEvent *event) {
  if (event->type() != QEvent::ToolTip) return AbstractTimeLine::event(event);

  QHelpEvent *help_event{static_cast<QHelpEvent *>(event)};

  if (selected) {
    // TODO: also highlight that entry in the journal, scrolling to it first
    QToolTip::showText(help_event->globalPos(),
                       alertingLogToQString(*selected));
  } else {
    QToolTip::hideText();
    event->ignore();
  }

  return true;
}
