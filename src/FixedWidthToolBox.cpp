// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "FixedWidthToolBox.h"

FixedWidthToolBox::FixedWidthToolBox(QWidget *parent) : QToolBox(parent) {}

QSize FixedWidthToolBox::minimumSizeHint() const {
  int width{0};

  for (int i = 0; i < count(); i++) {
    QWidget *w{widget(i)};
    width = std::max(width, w->width());
  }

  return QSize(width, height());
}
