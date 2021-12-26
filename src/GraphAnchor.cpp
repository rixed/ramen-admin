// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "GraphAnchor.h"

#include <QPainter>

GraphAnchor::GraphAnchor(QGraphicsItem *parent) : QGraphicsItem(parent) {}

GraphAnchor::~GraphAnchor() {}

static const int anchorRadius = 3;

QRectF GraphAnchor::boundingRect() const {
  return QRectF(-anchorRadius, -anchorRadius, anchorRadius * 2,
                anchorRadius * 2);
}

void GraphAnchor::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option, QWidget *) {
  (void)option;
  painter->drawEllipse(0, 0, anchorRadius, anchorRadius);
}
