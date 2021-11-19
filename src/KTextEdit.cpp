#include <math.h>
#include <cassert>
#include <QDebug>
#include <QDesktopWidget>
#include <QFontMetrics>
#include <QPlainTextEdit>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "misc_dessser.h"
#include "RamenSyntaxHighlighter.h"
#include "RangeDoubleValidator.h"

#include "KTextEdit.h"

static bool const verbose { false };

KTextEdit::KTextEdit(QWidget *parent) :
  AtomicWidget(parent)
{
  textEdit = new QPlainTextEdit;
  relayoutWidget(textEdit);
  new RamenSyntaxHighlighter(textEdit->document()); // the document becomes owner

  /* Set a monospaced font: */
  QFont font = textEdit->document()->defaultFont();
  font.setFamily("Courier New");
  textEdit->document()->setDefaultFont(font);

  /* Set tab stops to 4 spaces: */
  QFontMetricsF fontMetrics(font);
  float tabWidth = fontMetrics.width("    ");
# if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  textEdit->setTabStopDistance(roundf(tabWidth));
# else
  textEdit->setTabStopWidth(roundf(tabWidth));
#endif
  connect(textEdit, &QPlainTextEdit::textChanged, // ouch!
          this, &KTextEdit::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KTextEdit::getValue() const
{
  return stringOfQString(textEdit->toPlainText());
}

void KTextEdit::setEnabled(bool enabled)
{
  textEdit->setReadOnly(! enabled);
}

bool KTextEdit::setValue(
  std::shared_ptr<dessser::gen::sync_key::t const> k,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  QString new_v { syncValToQString(*v, k) };

  if (new_v != textEdit->toPlainText()) {
    textEdit->setPlainText(new_v);

    /* We'd like the size to be that of the widest line of text,
     * within reason: */
    QFont font(textEdit->document()->defaultFont());
    QFontMetrics fontMetrics((QFontMetrics(font)));
    int const tabWidth = 20;  // FIXME: get this from somewhere
    QSize const maxSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    QSize textSize(fontMetrics.size(Qt::TextExpandTabs, new_v, tabWidth));
    suggestedSize = QSize(
      std::min(maxSize.width(), textSize.width()),
      std::min(maxSize.height(), textSize.height()));

    if (verbose)
      qDebug() << "KTextEdit: suggestedSize=" << suggestedSize
               << "(max is" << maxSize << ")";

    emit valueChanged(k, v);
  }

  return true;
}

QSize KTextEdit::sizeHint() const
{
  return suggestedSize;
}
