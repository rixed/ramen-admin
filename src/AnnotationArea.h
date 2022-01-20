// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ANNOTATIONAREA_H_220120
#define ANNOTATIONAREA_H_220120
/* Similar to LineNumberArea, but to display errors/warnings annotations
 * rather than line numbers. */
#include <QVector>
#include <QWidget>

class CodeEdit;

class AnnotationArea : public QWidget {
  Q_OBJECT

  CodeEdit *codeEdit;

 public:
  AnnotationArea(CodeEdit *);

  QSize sizeHint() const override;

 protected:
  void paintEvent(QPaintEvent *) override;
};

#endif
