// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef CODEEDIT_H_220119
#define CODEEDIT_H_220119
/* A QPlainTextEdit with a left margin for line numbers and annotations
 * (for compilation errors and warnings).
 * Largely inspired by Qt's CodeEditor sample. */
#include <QPlainTextEdit>

#include "AtomicWidget.h"

class CodeEdit : public QPlainTextEdit {
  Q_OBJECT

  QWidget *lineNumberArea;

  QWidget *annotationArea;

  // Ordered by line/column:
 public:
  struct Annotation {
    int line;
    int column;  // if >= 0
    bool isErr;  // or warning
    QString text;
  };

 private:
  QVector<Annotation> annotations;

  int charWidth;

 public:
  CodeEdit(QWidget *parent = nullptr);

  void lineNumberAreaPaintEvent(QPaintEvent *);

  void annotationAreaPaintEvent(QPaintEvent *);

  int lineNumberAreaWidth();

  int annotationAreaWidth();

  void setAnnotations(QVector<Annotation> const &);

  // "Override" this because the readOnly property has no associated signal:
  void setReadOnly(bool);

 protected:
  void resizeEvent(QResizeEvent *) override;

 private slots:
  void updateLeftAreaWidth(int newBlockCount);

  void highlightImportantLines();

  void updateLineNumberArea(QRect const &, int dy);

  void updateAnnotationArea(QRect const &, int dy);

  void resetAnnotations();
};

#endif
