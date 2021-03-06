// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "KShortLabel.h"

#include <QFontMetrics>
#include <QPainter>
#include <QTextLayout>

#include "desssergen/sync_value.h"
#include "misc_dessser.h"

KShortLabel::KShortLabel(QWidget *parent)
    : AtomicWidget(parent),
      leftMargin(0),
      topMargin(0),
      rightMargin(0),
      bottomMargin(0) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

bool KShortLabel::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  QString new_v{syncValToQString(*v, key())};

  if (new_v != text) {
    text = new_v;
    update();
    emit valueChanged(v);
  }

  return true;
}

void KShortLabel::setContentsMargins(int l, int t, int r, int b) {
  leftMargin = l;
  topMargin = t;
  rightMargin = r;
  bottomMargin = b;
}

void KShortLabel::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QFontMetrics fontMetrics = painter.fontMetrics();
  QRect const bbox = event->rect();

  int lineSpacing = fontMetrics.lineSpacing();
  int y = topMargin;
  QStringList lines(text.split('\n'));

  for (QString const &l : lines) {
    if (y >= bbox.bottom() || y >= height() - bottomMargin) break;

    if (y <= bbox.bottom()) {
      QTextLayout textLayout(l, painter.font());
      textLayout.beginLayout();
      QTextLine line = textLayout.createLine();
      if (!line.isValid()) continue;  // ?

      int const w = width() - leftMargin - rightMargin;
      line.setLineWidth(w);
      QString elidedLastLine = fontMetrics.elidedText(l, Qt::ElideRight, w);

      painter.drawText(QPoint(leftMargin, y + fontMetrics.ascent()),
                       elidedLastLine);

      textLayout.endLayout();
    }

    y += lineSpacing;
  }
}
