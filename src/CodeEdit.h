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

 public:
  CodeEdit(QWidget *parent = nullptr);

  void lineNumberAreaPaintEvent(QPaintEvent *event);

  int lineNumberAreaWidth();

  // "Override" this because the readOnly property has no associated signal:
  void setReadOnly(bool);

 protected:
  void resizeEvent(QResizeEvent *event) override;

 private slots:
  void updateLineNumberAreaWidth(int newBlockCount);

  void highlightCurrentLine();

  void updateLineNumberArea(QRect const &rect, int dy);
};

#endif
