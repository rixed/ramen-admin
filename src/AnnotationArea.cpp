// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "AnnotationArea.h"

#include "CodeEdit.h"

AnnotationArea::AnnotationArea(CodeEdit *codeEdit_)
    : QWidget(codeEdit_), codeEdit(codeEdit_) {}

QSize AnnotationArea::sizeHint() const {
  return QSize(codeEdit->annotationAreaWidth(), 0);
}

void AnnotationArea::paintEvent(QPaintEvent *event) {
  codeEdit->annotationAreaPaintEvent(event);
}
