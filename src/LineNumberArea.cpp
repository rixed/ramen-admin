// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "LineNumberArea.h"

#include "CodeEdit.h"

LineNumberArea::LineNumberArea(CodeEdit *codeEdit_)
    : QWidget(codeEdit_), codeEdit(codeEdit_) {}

QSize LineNumberArea::sizeHint() const {
  return QSize(codeEdit->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
  codeEdit->lineNumberAreaPaintEvent(event);
}
