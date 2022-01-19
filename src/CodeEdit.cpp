// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "CodeEdit.h"

#include <QColor>
#include <QList>
#include <QPainter>
#include <QRect>
#include <QString>
#include <QTextBlock>
#include <QTextEdit>

#include "LineNumberArea.h"

CodeEdit::CodeEdit(QWidget *parent) : QPlainTextEdit(parent) {
  lineNumberArea = new LineNumberArea(this);

  connect(this, &CodeEdit::blockCountChanged, this,
          &CodeEdit::updateLineNumberAreaWidth);
  connect(this, &CodeEdit::updateRequest, this,
          &CodeEdit::updateLineNumberArea);
  connect(this, &CodeEdit::cursorPositionChanged, this,
          &CodeEdit::highlightCurrentLine);

  updateLineNumberAreaWidth(0);
  highlightCurrentLine();
}

int CodeEdit::lineNumberAreaWidth() {
  int digits{1};
  int max{qMax(1, blockCount())};
  while (max >= 10) {
    max /= 10;
    ++digits;
  }

  return 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
}

void CodeEdit::setReadOnly(bool ro) {
  QPlainTextEdit::setReadOnly(ro);
  highlightCurrentLine();
}

void CodeEdit::updateLineNumberAreaWidth(int /* newBlockCount */) {
  setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEdit::updateLineNumberArea(const QRect &rect, int dy) {
  if (dy)
    lineNumberArea->scroll(0, dy);
  else
    lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

  if (rect.contains(viewport()->rect())) updateLineNumberAreaWidth(0);
}

void CodeEdit::resizeEvent(QResizeEvent *e) {
  QPlainTextEdit::resizeEvent(e);

  QRect cr{contentsRect()};
  lineNumberArea->setGeometry(
      QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEdit::highlightCurrentLine() {
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

  setExtraSelections(extraSelections);
}

void CodeEdit::lineNumberAreaPaintEvent(QPaintEvent *event) {
  QPainter painter(lineNumberArea);
  painter.fillRect(event->rect(), Qt::lightGray);

  QTextBlock block{firstVisibleBlock()};
  int blockNumber{block.blockNumber()};
  int top{
      qRound(blockBoundingGeometry(block).translated(contentOffset()).top())};
  int bottom{top + qRound(blockBoundingRect(block).height())};

  while (block.isValid() && top <= event->rect().bottom()) {
    if (block.isVisible() && bottom >= event->rect().top()) {
      QString number = QString::number(blockNumber + 1);
      painter.setPen(Qt::black);
      painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                       Qt::AlignRight, number);
    }
    block = block.next();
    top = bottom;
    bottom = top + qRound(blockBoundingRect(block).height());
    ++blockNumber;
  }
}
