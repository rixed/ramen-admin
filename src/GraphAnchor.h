// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef GRAPHANCHOR_H_190509
#define GRAPHANCHOR_H_190509
#include <QGraphicsItem>

class GraphAnchor : public QGraphicsItem {
 public:
  GraphAnchor(QGraphicsItem *parent = nullptr);
  ~GraphAnchor();
  QRectF boundingRect() const override;
  void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif
