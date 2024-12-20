// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "chart/TimeChart.h"

#include <QApplication>
#include <QBrush>
#include <QDebug>
#include <QFont>
#include <QFontMetrics>
#include <QFontMetricsF>
#include <QPainter>
#include <QPen>
#include <QPointF>
#include <QSizePolicy>
#include <QStaticText>
#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <mutex>
#include <optional>
#include <tuple>

#include "EventTime.h"
#include "FunctionItem.h"
#include "PastData.h"
#include "TailModel.h"
#include "chart/Ticks.h"
#include "chart/TimeChartEditWidget.h"
#include "colorOfString.h"
#include "desssergen/raql_value.h"
#include "misc.h"
#include "misc_dessser.h"

static constexpr bool verbose{false};

static constexpr double defaultBeginOftime{0.};
static constexpr double defaultEndOfTime{600.};

static constexpr int tickLabelWidth{50};
static constexpr int tickLabelHeight{15};
static constexpr int minorTickLabelHeight{10};
static constexpr int dotLabelHeight{10};
static constexpr int minPlotWidth{300};
static constexpr int metaFontHeight{18};
/* Leave that many pixels above and below a chart to leave some room to draw dot
 * labels: */
static constexpr int plotVerticalMargin{1 + dotLabelHeight / 2};
/* Radius of an hovered dot: */
// TODO: radius and font larger if the axis is focused?
static constexpr int dotRadius{5};
/* Blank space between the hovered dots and the legend: */
static constexpr int legendToDots{dotRadius + 40};
/* Internal margin in the legend box */
static constexpr int legendMargin{10};

TimeChart::TimeChart(TimeChartEditWidget *editWidget_, QWidget *parent)
    : AbstractTimeLine(defaultBeginOftime, defaultEndOfTime, true, true,
                       parent),
      editWidget(editWidget_) {
  setMinimumSize(tickLabelWidth * 2 + minPlotWidth + 2 * plotVerticalMargin,
                 tickLabelHeight * 5);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  /* Connect to signals from the editWidget:
   * - for axis, a signal when any axis config is changed
   * - for fields, a signal when any field config is changed */
  connect(editWidget, &TimeChartEditWidget::axisChanged, this,
          &TimeChart::redrawAxis);
  connect(editWidget, &TimeChartEditWidget::fieldChanged, this,
          &TimeChart::redrawField);
  /* TODO: when many fields change simultaneously (such as when the dashboard
   * widget value is swapped for another one) we are going to be signaled once
   * per displayed field, which will trigger as many redraw. Maybe another
   * signal would be better in this case, that redraw everything without
   * changing the focusedField? */

  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

std::optional<int> TimeChart::anyAxis(bool left) const {
  for (int i = 0; i < editWidget->axisCount(); i++) {
    std::shared_ptr<dessser::gen::dashboard_widget::axis const> axis{
        editWidget->axis(i)};
    Q_ASSERT(axis);
    if (axis->left == left) return i;
  }

  return std::nullopt;
}

void TimeChart::redrawAxis(int axisNum) {
  if (verbose) qDebug() << "TimeChart::redrawAxis" << axisNum;

  std::shared_ptr<dessser::gen::dashboard_widget::axis const> axis{
      editWidget->axis(axisNum)};
  if (axis) {
    // If the axis switched side, remove it from the old side:
    if (axis->left && focusedAxis[Right] == axisNum) {
      focusedAxis[Right] = anyAxis(false);
    } else if (!axis->left && focusedAxis[Left] == axisNum) {
      focusedAxis[Left] = anyAxis(true);
    }

    // In any case, focus that axis on its side, and take control of the
    // grid:
    if (axis->left) {
      focusedAxis[Left] = focusedGridAxis = axisNum;
    } else {
      focusedAxis[Right] = focusedGridAxis = axisNum;
    }

    update();
  } else {
    // Axis is no more: remove it from focus.
    if (focusedAxis[Left] == axisNum) {
      focusedAxis[Left] = anyAxis(true);
      if (focusedGridAxis == axisNum) focusedGridAxis = focusedAxis[Left];

      update();
    } else if (focusedAxis[Right] == axisNum) {
      focusedAxis[Right] = anyAxis(false);
      if (focusedGridAxis == axisNum) focusedGridAxis = focusedAxis[Right];

      update();
    }
  }
}

void TimeChart::redrawField(std::string const &site, std::string const &program,
                            std::string const &function,
                            std::string const &name) {
  QString const funcFq{QString::fromStdString(site) + ":" +
                       QString::fromStdString(program) + "/" +
                       QString::fromStdString(function)};

  if (verbose)
    qDebug() << "TimeChart::redrawField" << funcFq
             << QString::fromStdString(name);

  // Make that field the focused one
  focusedField = FieldFQ({funcFq, name});

  update();
}

/* Given v_ratio = (v-min)/(max-min), return the Y pixel coordinate: */
qreal TimeChart::YofV(double v, double min, double max, bool log,
                      int base) const {
  if (log) {
    v = logOfBase(base, v);
    min = logOfBase(base, min);
    max = logOfBase(base, max);
  }

  int const h{height() - 2 * plotVerticalMargin};

  return plotVerticalMargin + (1 - (v - min) / (max - min)) * qreal(h);
}

double TimeChart::VofY(qreal y, qreal min, qreal max, bool log,
                       int base) const {
  if (log) {
    min = logOfBase(base, min);
    max = logOfBase(base, max);
  }

  int const h{height() - 2 * plotVerticalMargin};

  qreal v{(1 - (y - plotVerticalMargin) / qreal(h)) * (max - min) + min};

  if (log) {
    return sameSign(v, std::pow(base, std::abs(v)));
  } else {
    return v;
  }
}

static std::pair<bool, int> get_log_base(
    std::shared_ptr<dessser::gen::dashboard_widget::axis const> const &conf) {
  if (conf) {
    switch (conf->scale) {
      case dessser::gen::dashboard_widget::Linear:
        break;  // default
      case dessser::gen::dashboard_widget::Logarithmic:
        return std::make_pair(true, 10);
        /* TODO: Later when units have their own scales we could
         * choose another base (such as 2 or 8 for data volumes,
         * 60 for durations...) to pick the ticks */
    }
  }
  return std::make_pair(false, 10);
}

void TimeChart::paintGrid(Axis const &axis) {
  QPainter painter{this};
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setRenderHint(QPainter::TextAntialiasing);
  QColor const bgColor{palette().color(QWidget::backgroundRole())};
  QColor const gridColor{bgColor.lighter(120)};
  QColor const errColor{200, 30, 30};

  if (axis.min >= axis.max) {
    bool const hasEventTime{axis.hasEventTime()};

    QPen pen{hasEventTime ? gridColor : errColor, 1};
    painter.setPen(pen);
    QFont font{painter.font()};
    font.setPixelSize(tickLabelHeight);
    painter.setFont(font);
    painter.drawText(rect(), Qt::AlignCenter,
                     hasEventTime ? "no data" : "no event-time information");
    return;
  }

  QPen majorPen{gridColor, 1.5, Qt::SolidLine};
  QPen minorPen{gridColor, 1, Qt::DashLine};

  std::pair<bool, int> log_base{get_log_base(axis.conf)};
  Ticks ticks{axis.min, axis.max, log_base.first, log_base.second};

  int const x1{0 /*tickLabelWidth*/};
  int const x2{width() /* - tickLabelWidth*/};
  for (struct Tick const &tick : ticks.ticks) {
    /*qDebug() << (tick.major ? "major" : "minor") << "tick at"
     << tick.pos << ":" << tick.label;*/

    painter.setPen(tick.major ? majorPen : minorPen);
    qreal const y{
        YofV(tick.pos, axis.min, axis.max, log_base.first, log_base.second)};
    if (!std::isnan(y)) painter.drawLine(x1, y, x2, y);
  }
}

void TimeChart::paintTicks(Side const side, Axis const &axis,
                           std::map<QString, PerFunctionResults> &) {
  if (axis.min >= axis.max) return;

  QPainter painter{this};
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setRenderHint(QPainter::TextAntialiasing);
  QColor const tickColor{palette().color(QPalette::Text)};

  painter.setPen(tickColor);
  QFont majorFont{painter.font()};
  majorFont.setPixelSize(tickLabelHeight);
  QFont minorFont{painter.font()};
  minorFont.setPixelSize(minorTickLabelHeight);

  std::pair<bool, int> log_base{get_log_base(axis.conf)};
  Ticks ticks{axis.min, axis.max, log_base.first, log_base.second};

  int const x2{width() - tickLabelWidth};
  int lastY{-99};
  for (struct Tick const &tick : ticks.ticks) {
    painter.setFont(tick.major ? majorFont : minorFont);
    int const fontHeight{tick.major ? tickLabelHeight : minorTickLabelHeight};
    qreal const y{
        YofV(tick.pos, axis.min, axis.max, log_base.first, log_base.second)};
    if (!std::isnan(y)) {
      if (tick.major || std::abs(lastY - y) > fontHeight * 2) {
        if (side == Left) {
          painter.drawText(
              QRect(0, y - fontHeight / 2, tickLabelWidth, 2 * tickLabelHeight),
              Qt::AlignLeft, tick.label);
        } else {
          Q_ASSERT(side == Right);
          painter.drawText(QRect(x2, y - fontHeight / 2, tickLabelWidth,
                                 2 * tickLabelHeight),
                           Qt::AlignRight, tick.label);
        }
      }
      lastY = y;
    }
  }
}

void TimeChart::paintTailMeta(QPainter &painter, TailModel const &tail,
                              QColor const &col) {
  QFont font{painter.font()};
  font.setPixelSize(metaFontHeight);
  painter.setFont(font);
  QFontMetricsF const fontMetrics{font};

  qreal const x_start{toPixel(tail.minEventTime())},
      x_stop{toPixel(tail.maxEventTime())};
  QPen pen{col.darker()};
  pen.setStyle(Qt::DashDotLine);
  painter.setPen(pen);
  painter.drawLine(QPointF(x_start, 0.), QPointF(x_start, height()));
  painter.drawLine(QPointF(x_stop, 0.), QPointF(x_stop, height()));
  painter.setPen(col);
  painter.rotate(-90);  // Note: rotate is clockwise
  static QString const tail_end_str{"…tail end"};
  static QStaticText const start_tail_text{"Tail start…"},
      stop_tail_text{tail_end_str};
  QRectF bbox{fontMetrics.boundingRect(tail_end_str)};
  // Possibly: display tail size
  // Note: unlike drawFont, y is here the top f the font
  painter.drawStaticText(-height(), x_start, start_tail_text);
  // Note: additional shift required for some reason
  painter.drawStaticText(-(4 + bbox.width()), x_stop - bbox.height(),
                         stop_tail_text);
  painter.rotate(90);
}

void TimeChart::paintReplayRequestsMeta(QPainter &painter, PastData &past,
                                        QColor const &col, double now) {
  QFont font{painter.font()};
  font.setPixelSize(metaFontHeight);
  painter.setFont(font);
  QFontMetricsF const fontMetrics{font};
  QColor const darkCol{col.darker()};

  for (ReplayRequest &replay : past.replayRequests) {
    qreal x1, x2;
    QColor bgCol{darkCol};
    bool drawBg{false};
    QString status;
    // Ratio of the requested time covered by the received tuples:
    std::optional<double> gauge;
    {
      std::lock_guard<std::mutex> guard{replay.lock};
      if (replay.isCompleted(guard)) {
        // Dim the color with age
        double const age{now - replay.started};
        static double const maxAge{10};
        if (age < 0) continue;
        if (age < maxAge) {
          bgCol =
              blendColor(darkCol, painter.background().color(), age / maxAge);
          drawBg = true;
        }
        size_t const num_tuples{replay.tuples.size()};
        status = QString("completed %1 tuples").arg(num_tuples);
      } else if (replay.isWaiting(guard)) {  // Not yet sent
        status = "preparing…";
      } else {  // Sent
        size_t const num_tuples{replay.tuples.size()};
        if (num_tuples > 0) {
          double const recvd_dt{replay.tuples.crbegin()->first -
                                replay.tuples.cbegin()->first};
          Q_ASSERT(recvd_dt >= 0 && replay.until > replay.since);
          if (recvd_dt > 0) gauge = recvd_dt / (replay.until - replay.since);
        }
        status = QString("received %1 tuples").arg(num_tuples);
      }
      x1 = toPixel(replay.since);
      x2 = toPixel(replay.until);
    }  // replay locked
    QPen pen{darkCol};
    pen.setStyle(Qt::DashDotLine);
    painter.setPen(pen);
    if (drawBg) {
      /* Draw a hashed pattern in the background of this replay to help
       * visually distinguish several replays from each others: */
      QBrush const brush{bgCol, Qt::BDiagPattern};
      painter.setBrush(brush);
      QRectF const r{x1, 0., x2 - x1, static_cast<qreal>(height())};
      painter.drawRect(r);
    }
    painter.rotate(-90);
    // Note: unlike drawStaticText, y is here the baseline of the font
    QRectF bbox{fontMetrics.boundingRect(status)};
    painter.drawText(-height(), x1 + bbox.height(), status);
    if (gauge) {
      qreal const gauge_height{0.7 * bbox.height()};
      qreal const gauge_line_width{2.};
      painter.setPen(QPen{QBrush{darkCol}, gauge_line_width});
      painter.setBrush(Qt::NoBrush);
      painter.drawRect(-height() + gauge_line_width, x1 + bbox.height() * 1.5,
                       height() - gauge_line_width * 2, gauge_height);
      painter.setBrush(QBrush{darkCol});
      painter.drawRect(-height() + gauge_line_width * 3,
                       x1 + bbox.height() * 1.5 + gauge_line_width * 2,
                       *gauge * height() - gauge_line_width * 6,
                       gauge_height - gauge_line_width * 4);
    }
    painter.rotate(90);
  }
}

void TimeChart::paintAxis(Axis const &axis, double const now) {
  if (axis.min >= axis.max) return;

  std::pair<bool, int> log_base{get_log_base(axis.conf)};

  QPainter painter{this};
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setRenderHint(QPainter::TextAntialiasing);

  /* Save the set of dots that are going to be drawn over all this at the
   * end: */
  std::vector<Dot> dots;
  dots.reserve(10);

  // Draw each independent fields
  for (Line const &line : axis.independent) {
    if (line.res->noEventTime) {
      QFont font{painter.font()};
      font.setPixelSize(tickLabelHeight);
      painter.setFont(font);
      painter.setPen(line.color);
      painter.drawText(rect(), Qt::AlignCenter, "no event-time information");
      continue;
    }

    QString const line_label{axis.independent.size() > 1
                                 ? QString::fromStdString(line.fieldName)
                                 : QString()};

    /* Draw some meta informations: ongoing queries, where the tail begin. */
    std::shared_ptr<TailModel> tail{line.res->func->getTail()};
    if (tail) paintTailMeta(painter, *tail, line.color);
    std::shared_ptr<PastData> past{line.res->func->getPast()};
    if (past) paintReplayRequestsMeta(painter, *past, line.color, now);

    /* Now draw the line, actually one per factor combination. */
    FactorValues const &factorValues{line.res->factorValues[line.factorValues]};
    for (std::pair<QString const, std::pair<std::vector<size_t>, QColor>> const
             &p : factorValues.labels) {
      QString const &factor_label{p.first};
      std::vector<size_t> const &tupleIndices{p.second.first};
      QColor const &factor_color{p.second.second};

      /* We use the color of the line if there is only one possible value
       * for the functors, or the color associated with the factor labels
       * otherwise. */
      QColor const color{factorValues.labels.size() <= 1 ? line.color
                                                         : factor_color};
      painter.setPen(color);
      std::optional<QPointF> last;  // the last point
      bool last_drawn{false};       // was the last point drawn somehow?
      // Best distance so far from m_currentTime and location where it happened:
      std::optional<double> best_dt;
      double closest_value;
      QPointF closest_location;
      for (size_t i = 0; i < tupleIndices.size(); i++) {
        CategorizedTuple const &tuple{line.res->tuples[tupleIndices[i]]};
        std::optional<double> const v{tuple.values[line.columnIndex]};
        if (v) {
          qreal const y{
              YofV(*v, axis.min, axis.max, log_base.first, log_base.second)};
          if (!std::isnan(y)) {
            QPointF cur{toPixel(tuple.time), y};
            if (last) painter.drawLine(*last, cur);
            last_drawn = (bool)last;
            last = cur;
            // Check time distance:
            double const dt{std::abs(tuple.time - m_currentTime)};
            if (!best_dt || dt < *best_dt) {
              best_dt = dt;
              closest_value = *v;
              closest_location = cur;
            }
          } else {
            last = std::nullopt;
          }
        } else {
          if (last && !last_drawn)
            painter.drawPoint(*last);  // Probably a larger pen is in order
          last = std::nullopt;
        }
      }
      if (last && !last_drawn) painter.drawPoint(*last);
      if (best_dt) {
        QString const value_label{QString::number(closest_value)};
        QString const dot_label{
            factor_label.isEmpty()
                ? line_label +
                      (line_label.isEmpty() ? QString() : QString(": ")) +
                      value_label
                : line_label +
                      (line_label.isEmpty() ? QString() : QString(' ')) +
                      factor_label + QString(": ") + value_label};
        dots.emplace_back(closest_location, color, dot_label);
      }
    }
  }

  /* Draw stacked lines.
   * That's a bit more involved as each stacked "line" can use factors,
   * and then some factor values may be missing for some time steps. */
  std::function<void(std::vector<Line> const &, bool)> drawStacked =
      [this, &axis, log_base, &painter, now, &dots](
          std::vector<Line> const &lines, bool center) {
        qreal const zeroY{
            YofV(0, axis.min, axis.max, log_base.first, log_base.second)};

        size_t numValues{0};  // one per line per factor values
        for (Line const &line : lines)
          numValues += line.res->factorValues[line.factorValues].labels.size();

        std::optional<QPointF> last[numValues];
        qreal lastOffs[numValues];
        for (size_t l = 0; l < numValues; l++) lastOffs[l] = zeroY;
        qreal lastX{0};
        /* Best distance so far from m_currentTime and location where it
         * happened: */
        std::optional<double> best_dt;
        std::optional<std::tuple<double, qreal, QString, QColor>>
            closest_ys[numValues];
        qreal closest_x;
        // Now loop over all factor values of all lines
        Axis::iterTime(
            lines,
            [this, &axis, &painter, log_base, numValues, &last, &lastOffs,
             &lastX, center, &dots, &best_dt, &closest_ys, &closest_x](
                double time,
                std::vector<std::tuple<std::optional<qreal>, QString, QColor>>
                    values) {
              Q_ASSERT(values.size() == numValues);
              if (false && verbose) {
                std::vector<QString> dbgValues;
                dbgValues.reserve(numValues);
                for (auto const &value : values)
                  dbgValues.push_back(std::get<0>(value)
                                          ? QString::number(*std::get<0>(value))
                                          : QString("null"));
                qDebug() << qSetRealNumberPrecision(13) << "t=" << time
                         << "values=" << dbgValues;
              }

              qreal totVal{0.};
              if (center) {
                for (auto const &value : values)
                  totVal += std::get<0>(value).value_or(0);
              }
              qreal const x{toPixel(time)};
              qreal tot{-totVal / 2};
              qreal prevY{YofV(tot, axis.min, axis.max, log_base.first,
                               log_base.second)};
              // Check time distance:
              double const dt{std::abs(time - m_currentTime)};
              bool save_values{false};
              if (!best_dt || dt < *best_dt) {
                best_dt = dt;
                closest_x = x;
                save_values = true;
              }

              for (size_t l = 0; l < values.size(); l++) {
                if (std::get<0>(values[l])) {
                  qreal const v{*std::get<0>(values[l])};
                  if (verbose && v < 0)
                    qDebug() << "Stacked chart with negative values";
                  QString const &label{std::get<1>(values[l])};
                  QColor const &color{std::get<2>(values[l])};
                  qreal const y{YofV(v + tot, axis.min, axis.max,
                                     log_base.first, log_base.second)};
                  if (!std::isnan(y)) {
                    QPointF cur{x, y};
                    if (last[l]) {
                      QPointF const points[4]{*last[l],
                                              QPointF(lastX, lastOffs[l]),
                                              QPointF(x, prevY), cur};
                      painter.setPen(Qt::NoPen);
                      QColor fill{color};
                      fill.setAlpha(100);
                      painter.setBrush(fill);
                      painter.setRenderHint(QPainter::Antialiasing, false);
                      painter.drawConvexPolygon(points, 4);
                      painter.setPen(color);
                      painter.setRenderHint(QPainter::Antialiasing);
                      painter.drawLine(*last[l], cur);
                    }
                    last[l] = cur;
                    lastOffs[l] = prevY;
                    prevY = y;
                    tot += v;
                    if (save_values)
                      closest_ys[l] = std::make_tuple(v, y, label, color);
                  } else {
                    last[l] = std::nullopt;
                    if (save_values) closest_ys[l] = std::nullopt;
                  }
                } else {
                  last[l] = std::nullopt;
                  if (save_values) closest_ys[l] = std::nullopt;
                }
              }
              lastX = x;
            });

        /* Save the dots: */
        if (best_dt) {
          for (size_t i = 0; i < numValues; i++) {
            if (!closest_ys[i]) continue;
            double const v{std::get<0>(*closest_ys[i])};
            qreal const closest_y{std::get<1>(*closest_ys[i])};
            QString const &label{std::get<2>(*closest_ys[i])};
            QColor const &color{std::get<3>(*closest_ys[i])};
            QString const value_label{QString::number(v)};
            QString const dot_label{label.isEmpty()
                                        ? value_label
                                        : label + QString(": ") + value_label};
            dots.emplace_back(QPointF(closest_x, closest_y), color, dot_label);
          }
        }

        /* Also display tails and replay requests: */
        for (Line const &line : lines) {
          std::shared_ptr<TailModel> tail{line.res->func->getTail()};
          if (tail) paintTailMeta(painter, *tail, line.color);
          std::shared_ptr<PastData> past{line.res->func->getPast()};
          if (past) paintReplayRequestsMeta(painter, *past, line.color, now);
        }
      };

  drawStacked(axis.stacked, false);
  drawStacked(axis.stackCentered, true);

  /* Finally, draw all dots on top of this: */
  QFont font{painter.font()};
  font.setPixelSize(dotLabelHeight);
  painter.setFont(font);
  /* First step is to layout the labels, which can be moved on the left side of
   * the dot to avoid being clipped by the viewport, and can then be moved
   * vertically to avoid overwrites: */
  Legend left_legend{dots.size(), false};
  Legend right_legend{dots.size(), true};
  QFontMetricsF const font_metrics{font};
  bool lastLeft{false};
  for (size_t i = 0; i < dots.size(); i++) {
    QRectF const label_metrics{font_metrics.boundingRect(dots[i].label)};
    /* Invert lastLeft if that fits, so that we alternate between right and
     * left legend frames: */
    if ((lastLeft && dots[i].pos.x() + legendToDots + label_metrics.width() <=
                         painter.viewport().width()) ||
        (!lastLeft &&
         dots[i].pos.x() - legendToDots - label_metrics.width() >= 0))
      lastLeft = !lastLeft;
    (lastLeft ? left_legend : right_legend).add(&dots[i], label_metrics);
  }
  for (Dot const &dot : dots) dot.paint(painter);
  QColor const bg_color{palette().color(QWidget::backgroundRole())};
  left_legend.paint(painter, bg_color);
  right_legend.paint(painter, bg_color);
}

static int getFieldNum(std::shared_ptr<Function const> func,
                       std::string const &fieldName) {
  // Prepare the field number in the function output type:
  std::shared_ptr<dessser::gen::raql_type::t const> outType{func->outType()};
  if (!outType) {
    qWarning().nospace() << "TimeChart: Cannot find outType for "
                         << QString::fromStdString(func->siteName) << ':'
                         << QString::fromStdString(func->fqName);
    return -1;
  }
  for (unsigned c = 0; c < numColumns(*outType); c++) {
    std::string const name{columnName(*outType, c)};
    if (name == fieldName) return c;
  }
  qWarning() << "TimeChart: Cannot find field number for"
             << QString::fromStdString(fieldName);
  return -1;
}

void TimeChart::paintEvent(QPaintEvent *event) {
  AbstractTimeLine::paintEvent(event);

  /* Start by collecting all the points per axis: */
  int const numAxes{editWidget->axisCount()};

  /* For each axis, remember the field name and which position its
   * value will be in the result columns vector */
  std::vector<Axis> axes;
  for (int i = 0; i < numAxes; i++) {
    axes.emplace_back(editWidget->axis(i));
  }

  /* Cache the required function and the columns we need from them: */
  std::map<QString, PerFunctionResults> funcs;

  /* First, collect the Function pointer and columns vectors (ie fill
   * the above funcs map) */
  editWidget->iterFields(
      [this, numAxes, &funcs, &axes](
          std::string const &site, std::string const &program,
          std::string const &function,
          dessser::gen::dashboard_widget::field const &field) {
        if (field.axis >= numAxes) {
          /* Can happen in between a new axis is used in the fields and that
           * axis being added to the axis editor. */
          qDebug() << "Field uses axis" << field.axis
                   << "that's not been created yet";
          return;
        }

        // Lookup the function:
        std::shared_ptr<Function> func;
        QString const funcFq{QString::fromStdString(site) + ":" +
                             QString::fromStdString(program) + "/" +
                             QString::fromStdString(function)};
        auto it{funcs.find(funcFq)};
        if (it != funcs.end()) {
          func = it->second.func;
        } else {
          func = Function::find(QString::fromStdString(site),
                                QString::fromStdString(program),
                                QString::fromStdString(function));
          if (!func) {
            qCritical("TimeChart: Cannot find Function for %s:%s/%s",
                      site.c_str(), program.c_str(), function.c_str());
            return;  // better safe than sorry
          }

          // Redisplay on new arrivals:
          std::shared_ptr<PastData> past{func->getPast()};
          if (past) {
            // Trust Qt to return quickly if it's already connected
            connect(past.get(), &PastData::tupleReceived, this,
                    qOverload<>(&QWidget::update), Qt::UniqueConnection);
          }

          auto emplaced{funcs.emplace(funcFq, func)};
          it = emplaced.first;

          /* Also ask for this function's tail: */
          std::shared_ptr<TailModel const> tailModel{func->getTail()};
          if (!tailModel) {
            if (verbose) qDebug() << "TimeChart: Requesting tail";
            tailModel = func->getOrCreateTail();
            if (tailModel) {
              connect(tailModel.get(), &TailModel::rowsInserted, this,
                      qOverload<>(&QWidget::update));
            } else {
              qCritical().nospace()
                  << "TimeChart: Cannot get tail for function "
                  << QString::fromStdString(func->siteName) << ':'
                  << QString::fromStdString(func->fqName);
            }
          }
        }
        Q_ASSERT(func);
        int const fieldNum{getFieldNum(func, field.column)};
        if (fieldNum < 0) return;

        // Add this field in the request and remember its location:
        PerFunctionResults &res{it->second};

        size_t const factorValues{res.addFactors(field.factors)};
        switch (field.representation) {
          case dessser::gen::dashboard_widget::Unused:
            break;  // Well tried!
          case dessser::gen::dashboard_widget::Independent:
            axes[field.axis].independent.emplace_back(
                &res, field.column, res.columns.size(), factorValues,
                field.color);
            break;
          case dessser::gen::dashboard_widget::Stacked:
            axes[field.axis].stacked.emplace_back(&res, field.column,
                                                  res.columns.size(),
                                                  factorValues, field.color);
            break;
          case dessser::gen::dashboard_widget::StackCentered:
            axes[field.axis].stackCentered.emplace_back(
                &res, field.column, res.columns.size(), factorValues,
                field.color);
            break;
        }

        res.columns.push_back(fieldNum);
      });

  // Then iterate over all functions and fill in the results with actual
  // tuples:
  for (auto &it : funcs) {
    PerFunctionResults &res{it.second};

    // Can happen if fieldNum could not be found:
    if (res.columns.empty()) continue;

    std::shared_ptr<EventTime const> eventTime{res.func->getTime()};
    if (!eventTime || !eventTime->isValid()) {
      res.noEventTime = true;
      continue;
    }

    if (verbose)
      qDebug().nospace() << qSetRealNumberPrecision(13)
                         << "TimeChart: Collecting tuples for "
                         << res.columns.size() << " columns of "
                         << QString::fromStdString(res.func->siteName) << ':'
                         << QString::fromStdString(res.func->fqName)
                         << " between " << stringOfDate(m_viewPort.first)
                         << " and " << stringOfDate(m_viewPort.second);

    /* In order to be able to draw the chart properly we must extend the
     * requested time range (note that for stacked charts it is not enough to
     * ask for just one more point; All points from the previous/next time
     * steps are needed. */
    double const since_{m_viewPort.first};
    double const since{res.func->previousTime(since_).value_or(since_)};
    double const until_{m_viewPort.second};
    double const until{res.func->nextTime(until_).value_or(until_)};
    res.func->iterValues(
        since, until, res.columns,
        [&res](double time,
               std::vector<std::shared_ptr<
                   dessser::gen::raql_value::t const>> const values) {
          /* Store this tuple (as doubles) */
          size_t const tupleIdx{res.tuples.size()};
          res.tuples.emplace_back(time, values);

          /* Also update the possible values for every defined combination of
           * factors: */
          std::string const noStr;
          for (FactorValues &f : res.factorValues) {
            QString label;
            for (std::pair<std::string, int> const &idx : f.indices) {
              QString const value{raqlValToQString(*values[idx.second])};
              label += (label.isEmpty() ? QString() : QString(',')) +
                       QString::fromStdString(idx.first) + '=' + value;
            }
            auto emplaced{f.labels.emplace(std::make_pair(
                label, std::make_pair(std::vector<size_t>(),
                                      colorOfString(label, 0.3))))};
            bool const isNew{emplaced.second};
            std::vector<size_t> &tupleIndices{emplaced.first->second.first};
            if (isNew) tupleIndices.reserve(100);
            tupleIndices.push_back(tupleIdx);
          }
        });

    if (verbose) {
      qDebug() << "TimeChart: got" << res.tuples.size() << "tuples";
      //      for (FactorValues &f : res.factorValues) {
      //        for (std::pair<QString, std::vector<size_t>> const &p :
      //        f.labels) {
      //          qDebug() << "  " << p.first << ":" << p.second.size();
      //        }
      //      }
    }
  }

  /* Compute the extremums per axis: */
  for (int i = 0; i < numAxes; i++) {
    Axis &axis{axes[i]};
    std::function<void(double const min, double const max)> updateExtremums =
        [&axis](double const min, double const max) {
          if (min < axis.min &&
              min > -std::numeric_limits<double>::infinity() &&
              !std::isnan(min))
            axis.min = min;
          if (max > axis.max && max < std::numeric_limits<double>::infinity() &&
              !std::isnan(max))
            axis.max = max;
        };

    if (axis.conf && axis.conf->force_zero) updateExtremums(0., 0.);

    for (auto &line : axis.independent) {
      // Get the min/max over the whole time range:
      for (CategorizedTuple const &tuple : line.res->tuples) {
        std::optional<double> const &v{tuple.values[line.columnIndex]};
        if (v) updateExtremums(*v, *v);
      }
    }

    /* Set extremums for stacked lines. */
    Axis::iterTime(
        axis.stacked,
        [updateExtremums](
            double,
            std::vector<std::tuple<std::optional<double>, QString, QColor>>
                values) {
          double totHeight{0.};
          for (auto const &value : values) {
            totHeight += std::get<0>(value).value_or(0.);
          }
          updateExtremums(0., totHeight);
        });

    /* Set extremums for stack-centered lines. */
    Axis::iterTime(
        axis.stackCentered,
        [updateExtremums](
            double,
            std::vector<std::tuple<std::optional<double>, QString, QColor>>
                values) {
          double totHeight{0.};
          for (auto const &value : values) {
            totHeight += std::get<0>(value).value_or(0.);
          }
          updateExtremums(-totHeight / 2, totHeight / 2);
        });

    /* Improve readability (and fix issues when all values are constant for the
     * whole duration of the chart) by enlarging the scale a bit) */
    double const dy{axis.max - axis.min};
    if (dy == 0) {
      axis.max += 1.;
      axis.min -= 1.;
    } else if (dy > 0) {
      // Makes the scale 5% larger:
      double const p{dy * 0.025};
      axis.max += p;
      axis.min -= p;
    }
  }

  /* If the focused axis does not exist any longer, of if no axis is focused,
   * then focus the first left and right ones: */
  if (!focusedAxis[Left] || *focusedAxis[Left] >= numAxes)
    focusedAxis[Left] = editWidget->firstAxisOnSide(true);
  if (!focusedAxis[Right] || *focusedAxis[Right] >= numAxes)
    focusedAxis[Right] = editWidget->firstAxisOnSide(false);
  if (!focusedGridAxis || *focusedGridAxis >= numAxes)
    focusedGridAxis =
        focusedAxis[Left] ? focusedAxis[Left] : focusedAxis[Right];

  if (focusedGridAxis) {
    Q_ASSERT(*focusedGridAxis < numAxes);
    paintGrid(axes[*focusedGridAxis]);
  }

  if (focusedAxis[Left]) {
    Q_ASSERT(*focusedAxis[Left] < numAxes);
    paintTicks(Left, axes[*focusedAxis[Left]], funcs);
  }

  if (focusedAxis[Right]) {
    Q_ASSERT(*focusedAxis[Right] < numAxes);
    paintTicks(Right, axes[*focusedAxis[Right]], funcs);
  }

  double const now{getTime()};

  /* Draw all axes but the main one: */
  for (int i = 0; i < numAxes; i++) {
    if (focusedGridAxis && i == *focusedGridAxis)
      continue;  // keep this for later

    paintAxis(axes[i], now);
  }

  // Finally, the focused one:
  if (focusedGridAxis) paintAxis(axes[*focusedGridAxis], now);
}

size_t TimeChart::PerFunctionResults::addFactors(
    std::vector<std::string> const &factors) {
  std::vector<std::pair<std::string, int>> factorIndices;
  factorIndices.reserve(2);

  bool canHaveIt{true};
  for (std::string const &factor : factors) {
    int const factorNum{getFieldNum(func, factor)};
    if (factorNum < 0) continue;
    // If this column was already asked, reuse it:
    for (int idx = 0; idx < (int)columns.size(); idx++) {
      if (columns[idx] == factorNum) {
        factorIndices.emplace_back(factor, idx);
        goto found;
      }
    }
    // otherwise, add it to the list of requested columns:
    factorIndices.emplace_back(factor, columns.size());
    columns.push_back(factorNum);
    canHaveIt = false;  // no need to look if we already have this combination
  found:;
  }

  // Maybe we have this exact combination of factors already?
  if (canHaveIt) {
    for (size_t i = 0; i < factorValues.size(); i++) {
      FactorValues const &f{factorValues[i]};
      if (f.indices.size() != factorIndices.size()) continue;
      size_t j{0};
      for (; j < factorIndices.size(); j++) {
        // No need to compare the names
        if (f.indices[j].second != factorIndices[j].second) break;
      }
      if (j == factorIndices.size()) return i;
    }
  }

  factorValues.emplace_back(factorIndices);

  return factorValues.size() - 1;
}

/* For each time step, call the provided function with a vector of one value
 * per factor value per line. */
void TimeChart::Axis::iterTime(
    std::vector<Line> const &lines,
    std::function<void(
        double, std::vector<std::tuple<std::optional<qreal>, QString, QColor>>)>
        cb) {
  /* For every time step, we will have as many values as we have possible
   * factor values per lines: */
  size_t numValues{0};
  for (Line const &line : lines)
    numValues += line.res->factorValues[line.factorValues].labels.size();

  if (0 == numValues) return;

  std::vector<std::tuple<std::optional<qreal>, QString, QColor>> values(
      numValues);

  size_t num_tuples[1 + numValues];  // 1+ to satisfies clang-tidy

  size_t valIdx{0};
  for (Line const &line : lines) {
    FactorValues const &factorValues{line.res->factorValues[line.factorValues]};
    bool const noFactor{factorValues.labels.size() <= 1};
    for (std::pair<QString const, std::pair<std::vector<size_t>, QColor>> const
             &p : factorValues.labels) {
      QString const &label{p.first};
      std::vector<size_t> const &tupleIndices{p.second.first};
      QColor const &label_color{p.second.second};
      std::get<1>(values[valIdx]) =
          // Only prefix with the fieldName if we have several:
          lines.size() > 1
              ? (label.isEmpty() ? QString::fromStdString(line.fieldName)
                                 : QString::fromStdString(line.fieldName) +
                                       QString(' ') + label)
              : label;
      std::get<2>(values[valIdx]) = noFactor ? line.color : label_color;
      num_tuples[valIdx] = tupleIndices.size();

      valIdx++;
    }
  }

  /* Iterate over time steps: */
  std::vector<size_t> nextTupleIdx(numValues, 0);  // Not list-init here!
  std::vector<bool> done(numValues, false);        // Not list-init here!
  unsigned numDone{0};

  while (numDone < numValues) {
    size_t valIdx{0};
    double minTime{std::numeric_limits<double>::max()};

    for (Line const &line : lines) {
      FactorValues const &factorValues{
          line.res->factorValues[line.factorValues]};

      for (std::pair<QString const,
                     std::pair<std::vector<size_t>, QColor>> const &p :
           factorValues.labels) {
        std::vector<size_t> const &tupleIndices{p.second.first};

        if (!done[valIdx]) {
          size_t const tupleIdx{tupleIndices[nextTupleIdx[valIdx]]};
          CategorizedTuple const &tuple{line.res->tuples[tupleIdx]};

          minTime = std::min(minTime, tuple.time);
        }

        valIdx++;
      }
    }

    /* Now we know the minTime, aggregate all values that we want in
     * this time step. Empty the values that are too far in the future. */
    static double const minDT{.0001};  // Helps with epsilons
    valIdx = 0;
    for (Line const &line : lines) {
      FactorValues const &factorValues{
          line.res->factorValues[line.factorValues]};

      for (std::pair<QString const,
                     std::pair<std::vector<size_t>, QColor>> const &p :
           factorValues.labels) {
        std::vector<size_t> const &tupleIndices{p.second.first};

        std::get<0>(values[valIdx]) = 0.;

        if (!done[valIdx]) {
          /* While nextTupleIdx < limit and time is in range, sum the
           * value. Then iterTime should sum the values, and we should
           * then also use iterTime to draw independent lines, and the
           * DT used for the pivot should be configurable. */
          while (true) {
            size_t const tupleIdx{tupleIndices[nextTupleIdx[valIdx]]};
            CategorizedTuple const &tuple{line.res->tuples[tupleIdx]};
            if (tuple.time > minTime + minDT) break;
            std::get<0>(values[valIdx]) =
                *std::get<0>(values[valIdx]) +
                tuple.values[line.columnIndex].value_or(0.);
            if (++nextTupleIdx[valIdx] >= num_tuples[valIdx]) {
              done[valIdx] = true;
              numDone++;
              break;
            }
          }
        }

        valIdx++;
      }
    }

    cb(minTime, values);
  }
}

bool TimeChart::Axis::hasEventTime() const {
  for (Line const &l : stacked)
    if (l.res->noEventTime) return false;
  for (Line const &l : stackCentered)
    if (l.res->noEventTime) return false;
  for (Line const &l : independent)
    if (l.res->noEventTime) return false;

  return true;
}

void TimeChart::Dot::paint(QPainter &painter) const {
  QFontMetricsF const font_metrics{painter.font()};
  QRectF const text_metrics{font_metrics.boundingRect(label)};

  QPen pen{painter.pen()};
  pen.setColor(color);
  pen.setWidth(2);
  painter.setPen(pen);
  painter.drawEllipse(pos, dotRadius, dotRadius);
}

TimeChart::Legend::Legend(size_t max_dots, bool left_justify)
    : leftJustify(left_justify) {
  dots.reserve(max_dots);
}

void TimeChart::Legend::add(Dot *dot, QRectF const &metrics) {
  dots.emplace_back(dot, metrics);

  size.setHeight(size.height() + metrics.height());
  size.setWidth(std::max(size.width(), metrics.width()));

  if (xAnchor) {
    xAnchor = leftJustify ? std::max(*xAnchor, dot->pos.x())
                          : std::min(*xAnchor, dot->pos.x());
  } else {
    xAnchor = dot->pos.x();
  }
}

void TimeChart::Legend::paint(QPainter &painter, QColor const &bg_color) {
  if (!xAnchor) return;
  Q_ASSERT(dots.size() > 0);

  /* First, draw the frame, aiming at the average dots' Y position: */
  qreal top_y{0.};
  for (auto const &p : dots) top_y += p.first->pos.y();
  top_y /= dots.size();
  top_y -= size.height() / 2;
  if (top_y + size.height() > painter.viewport().height())
    top_y = painter.viewport().height() - size.height();
  if (top_y < 0) top_y = 0;

  QPointF const orig{leftJustify ? *xAnchor + legendToDots
                                 : *xAnchor - legendToDots - size.width(),
                     top_y};
  QRectF const frame{orig, size};
  QRectF const frame_with_margins{frame + QMarginsF(legendMargin, legendMargin,
                                                    legendMargin,
                                                    legendMargin)};
  QColor frame_color{bg_color};
  frame_color.setAlpha(180);
  painter.setBrush(frame_color);
  painter.setPen(Qt::NoPen);
  painter.drawRect(frame_with_margins);

  int const descent{QFontMetrics{painter.font()}.descent()};

  /* Order the dots by Y coordinate: */
  std::sort(dots.begin(), dots.end(),
            [](std::pair<Dot const *, QRectF> const &p1,
               std::pair<Dot const *, QRectF> const &p2) {
              return p1.first->pos.y() < p2.first->pos.y();
            });

  /* Draw the legend: */
  painter.setBrush(Qt::NoBrush);
  qreal y_offset{0.};
  for (auto const &p : dots) {
    Dot const *dot{p.first};
    QRectF const &metrics{p.second};

    QColor c{dot->color};
    painter.setPen(c);
    y_offset += metrics.height();
    QPointF const pos{
        leftJustify ? frame.left() : frame.right() - metrics.width(),
        frame.top() + y_offset - descent};
    painter.drawText(pos, dot->label);

    c.setAlpha(100);
    painter.setPen(c);
    qreal const mid_y{frame.top() + y_offset -
                      metrics.height() / 3 /* works better than height/2 */};
    QPainterPath path{QPointF(
        leftJustify ? frame_with_margins.left() : frame_with_margins.right(),
        mid_y)};
    path.cubicTo(
        QPointF(leftJustify ? frame_with_margins.left() - legendToDots / 2
                            : frame_with_margins.right() + legendToDots / 2,
                mid_y),
        dot->pos +
            QPointF(leftJustify ? legendToDots / 2 : -legendToDots / 2, 0),
        dot->pos + QPointF(leftJustify ? dotRadius / 2 : -dotRadius / 2, 0));
    painter.drawPath(path);
  }
}
