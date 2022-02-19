// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "FixedTableView.h"

#include <QHeaderView>
#include <QMargins>

FixedTableView::FixedTableView(QWidget *parent) : QTableView(parent) {
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QSize FixedTableView::sizeHint() const {
  QHeaderView const *vHeader{verticalHeader()};
  QHeaderView const *hHeader{horizontalHeader()};
  int const frame{frameWidth()};
  QMargins const m{contentsMargins()};
  return QSize(frame + m.left() + hHeader->length() +
                   vHeader->sizeHint().width() + m.right() + frame,
               frame + m.top() + hHeader->sizeHint().height() +
                   vHeader->length() + m.bottom() + frame);
}

QSize FixedTableView::minimumSizeHint() const { return sizeHint(); }
