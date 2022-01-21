// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "CodeEdit.h"

#include <QColor>
#include <QList>
#include <QPainter>
#include <QRect>
#include <QString>
#include <QTextBlock>
#include <QTextEdit>

#include "AnnotationArea.h"
#include "LineNumberArea.h"

CodeEdit::CodeEdit(QWidget *parent) : QPlainTextEdit(parent) {
  charWidth = fontMetrics().horizontalAdvance(QLatin1Char('9'));

  lineNumberArea = new LineNumberArea(this);

  connect(this, &CodeEdit::blockCountChanged, this,
          &CodeEdit::updateLeftAreaWidth);
  connect(this, &CodeEdit::updateRequest, this,
          &CodeEdit::updateLineNumberArea);
  connect(this, &CodeEdit::cursorPositionChanged, this,
          &CodeEdit::highlightImportantLines);

  annotationArea = new AnnotationArea(this);

  connect(this, &CodeEdit::updateRequest, this,
          &CodeEdit::updateAnnotationArea);
  /* Since we can't move the annotation with the text changes, let's remove
   * them as soon as a line is added/removed: */
  connect(this, &CodeEdit::blockCountChanged, this,
          &CodeEdit::resetAnnotations);

  // Reset the width of the AnnotationArea:
  setAnnotations(QVector<Annotation>());

  updateLeftAreaWidth(0);
  highlightImportantLines();
}

int CodeEdit::lineNumberAreaWidth() {
  int digits{1};
  int max{qMax(1, blockCount())};
  while (max >= 10) {
    max /= 10;
    ++digits;
  }

  return 3 + charWidth * digits;
}

int CodeEdit::annotationAreaWidth() {
  if (annotations.isEmpty())
    return 0;
  else
    return charWidth;
}

void CodeEdit::setAnnotations(QVector<Annotation> const &a) {
  annotations = a;
  updateLeftAreaWidth(0);
  highlightImportantLines();
}

void CodeEdit::resetAnnotations() { setAnnotations(QVector<Annotation>{}); }

void CodeEdit::setReadOnly(bool ro) {
  QPlainTextEdit::setReadOnly(ro);
  highlightImportantLines();
}

void CodeEdit::updateLeftAreaWidth(int /* newBlockCount */) {
  setViewportMargins(lineNumberAreaWidth() + annotationAreaWidth(), 0, 0, 0);
}

void CodeEdit::updateLineNumberArea(const QRect &rect, int dy) {
  if (dy)
    lineNumberArea->scroll(0, dy);
  else
    lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

  if (rect.contains(viewport()->rect())) updateLeftAreaWidth(0);
}

void CodeEdit::updateAnnotationArea(const QRect &rect, int dy) {
  if (dy)
    annotationArea->scroll(0, dy);
  else
    annotationArea->update(0, rect.y(), annotationArea->width(), rect.height());

  if (rect.contains(viewport()->rect())) updateLeftAreaWidth(0);
}

void CodeEdit::resizeEvent(QResizeEvent *e) {
  QPlainTextEdit::resizeEvent(e);

  int const linenum_width{lineNumberAreaWidth()};
  QRect cr{contentsRect()};
  lineNumberArea->setGeometry(
      QRect(cr.left(), cr.top(), linenum_width, cr.height()));
  annotationArea->setGeometry(QRect(cr.left() + linenum_width, cr.top(),
                                    annotationAreaWidth(), cr.height()));
}

void CodeEdit::highlightImportantLines() {
  QList<QTextEdit::ExtraSelection> extraSelections;

  if (!isReadOnly()) {
    QTextEdit::ExtraSelection selection;

    QColor lineColor{QColor(Qt::yellow).lighter(160)};
    selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);
  }

  QColor errColor{QColor(Qt::red).lighter(160)};
  QColor warnColor{QColor(Qt::darkYellow).lighter(160)};
  for (Annotation const &a : annotations) {
    if (a.line <= 0 || a.line >= document()->blockCount() + 1) continue;
    QTextEdit::ExtraSelection selection;

    selection.format.setBackground(a.isErr ? errColor : warnColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    QTextBlock block{document()->findBlockByLineNumber(a.line - 1)};
    QTextCursor cursor{block};
    selection.cursor = cursor;
    //    selection.cursor.clearSelection();
    extraSelections.append(selection);
  }

  setExtraSelections(extraSelections);
}

void CodeEdit::lineNumberAreaPaintEvent(QPaintEvent *event) {
  QPainter painter(lineNumberArea);
  painter.fillRect(event->rect(), Qt::lightGray);

  QTextBlock block{firstVisibleBlock()};
  int line_num{1 + block.blockNumber()};
  int top{
      qRound(blockBoundingGeometry(block).translated(contentOffset()).top())};
  int bottom{top + qRound(blockBoundingRect(block).height())};

  painter.setPen(Qt::black);

  while (block.isValid() && top <= event->rect().bottom()) {
    if (block.isVisible() && bottom >= event->rect().top()) {
      QString number{QString::number(line_num)};
      painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                       Qt::AlignRight, number);
    }
    block = block.next();
    top = bottom;
    bottom = top + qRound(blockBoundingRect(block).height());
    line_num++;
  }
}

void CodeEdit::annotationAreaPaintEvent(QPaintEvent *event) {
  QPainter painter(annotationArea);
  painter.fillRect(event->rect(), Qt::lightGray);

  QTextBlock block{firstVisibleBlock()};
  int line_num{1 + block.blockNumber()};
  int top{
      qRound(blockBoundingGeometry(block).translated(contentOffset()).top())};
  int bottom{top + qRound(blockBoundingRect(block).height())};
  int nextAnnotation{0};

  while (block.isValid() && top <= event->rect().bottom()) {
    if (block.isVisible() && bottom >= event->rect().top()) {
      while (nextAnnotation < annotations.size() &&
             annotations[nextAnnotation].line < line_num)
        nextAnnotation++;
      if (nextAnnotation >= annotations.size()) break;
      Annotation const &a{annotations[nextAnnotation]};
      if (line_num == a.line) {
        painter.setPen(a.isErr ? Qt::red : Qt::darkYellow);
        QString mark{a.isErr ? 'X' : '?'};
        painter.drawText(0, top, annotationArea->width(),
                         fontMetrics().height(), Qt::AlignCenter, mark);
      }
    }
    block = block.next();
    top = bottom;
    bottom = top + qRound(blockBoundingRect(block).height());
    line_num++;
  }
}
