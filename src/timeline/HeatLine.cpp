// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "timeline/HeatLine.h"

#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

HeatLine::HeatLine(qreal beginOftime, qreal endOfTime, bool withCursor,
                   bool doScroll, QWidget *parent)
    : AbstractTimeLine(beginOftime, endOfTime, withCursor, doScroll, parent) {
  blocks.reserve(20);
}

void HeatLine::paintEvent(QPaintEvent *event) {
  QPainter painter{this};
  painter.setPen(Qt::NoPen);

  static QColor const hoveredColor{"dimgrey"};
  if (hovered) painter.fillRect(event->rect(), hoveredColor);

  for (int i = 0; i < blocks.size(); i++) {
    Block const &block{blocks[i]};

    qreal const start{block.start};
    qreal const stop{block.stop};

    qreal const xStart{toPixel(start)};

    painter.setBrush(hovered ? block.color.lighter() : block.color);
    painter.drawRect(
        QRectF{xStart, 0., toPixel(stop) - xStart, qreal(height())});
  }

  // Paint the cursor over the heatmap:
  AbstractTimeLine::paintEvent(event);
}

void HeatLine::add(qreal start, qreal stop, QColor const &color) {
  if (start >= stop) return;

  /* Maintain the blocks in start order and without overlap: */
  int i;
  for (i = 0; i < blocks.count() && start < blocks[i].start; i++)
    ;
  blocks.insert(i, Block{start, stop, color});
  /* Since there was no overlap between block i-1 and i, then there is still
   * no overlap with the new block. But there could be overlap after. */
  while (blocks.count() > i + 1 && blocks[i + 1].start < stop) {
    if (blocks[i + 1].stop <= stop)
      blocks.removeAt(i + 1);
    else
      blocks[i + 1].start = stop;
  }

  if (start < m_beginOfTime) {
    setBeginOfTime(start);
    emit beginOfTimeChanged(start);
  }
  if (stop > m_endOfTime) {
    setEndOfTime(stop);
    emit endOfTimeChanged(stop);
  }
}
