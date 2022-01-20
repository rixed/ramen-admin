// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "KTextEdit.h"

#include <math.h>

#include <QDebug>
#include <QFontMetrics>
#include <QGuiApplication>
#include <QScreen>
#include <cassert>

#include "CodeEdit.h"
#include "KVStore.h"
#include "LineNumberArea.h"
#include "MakeSyncValue.h"
#include "RamenSyntaxHighlighter.h"
#include "RangeDoubleValidator.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static constexpr bool verbose{false};

KTextEdit::KTextEdit(bool raql_, QWidget *parent)
    : AtomicWidget(parent), raql(raql_) {
  codeEdit = new CodeEdit;
  relayoutWidget(codeEdit);

  if (raql) {
    new RamenSyntaxHighlighter(
        codeEdit->document());  // the document becomes owner

    /* Set a monospaced font: */
    QFont font{codeEdit->document()->defaultFont()};
    font.setFamily("Courier New");
    codeEdit->document()->setDefaultFont(font);

    /* Set tab stops to 4 spaces: */
    QFontMetricsF fontMetrics{font};
    qreal tabWidth{fontMetrics.boundingRect("    ").width()};
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    codeEdit->setTabStopDistance(roundf(tabWidth));
#else
    codeEdit->setTabStopWidth(roundf(tabWidth));
#endif
  }

  connect(codeEdit,
          &CodeEdit::textChanged,  // ouch!
          this, &KTextEdit::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KTextEdit::getValue() const {
  return stringOfQString(codeEdit->toPlainText());
}

void KTextEdit::setEnabled(bool enabled) { codeEdit->setReadOnly(!enabled); }

bool KTextEdit::setValue(std::shared_ptr<dessser::gen::sync_value::t const> v) {
  QString new_v{syncValToQString(*v, key())};

  if (new_v != codeEdit->toPlainText()) {
    codeEdit->setPlainText(new_v);

    if (raql) {
      /* We'd like the size to be that of the widest line of text,
       * within reason: */
      QFont font{codeEdit->document()->defaultFont()};
      QFontMetrics fontMetrics{(QFontMetrics(font))};
      int const tabWidth{20};  // FIXME: get this from somewhere
      QSize const maxSize{
          QGuiApplication::primaryScreen()->availableGeometry().size() * 0.7};
      QSize textSize{fontMetrics.size(Qt::TextExpandTabs, new_v, tabWidth)};
      suggestedSize = QSize(std::min(maxSize.width(), textSize.width()),
                            std::min(maxSize.height(), textSize.height()));

      if (verbose)
        qDebug() << "KTextEdit: suggestedSize=" << suggestedSize << "(max is"
                 << maxSize << ")";
    }

    emit valueChanged(v);
  }

  /* Also reset annotations since the editor clears them: */
  resetAnnotations();

  return true;
}

void KTextEdit::resetAnnotations() {
  if (!key()) return;  // new source

  std::shared_ptr<dessser::gen::sync_key::t const> info_key{
      changeSourceExtension(*key(), "info")};
  if (!info_key) return;  // not compiled yet?

  auto it{kvs->map.find(info_key)};
  if (it == kvs->map.end() ||
      it->second.val->index() != dessser::gen::sync_value::SourceInfo)
    return;

  auto const &detail{
      std::get<dessser::gen::sync_value::SourceInfo>(*it->second.val)->detail};
  QVector<CodeEdit::Annotation> annotations;
  switch (detail.index()) {
    case dessser::gen::source_info::Compiled:
      for (auto const &err :
           std::get<dessser::gen::source_info::Compiled>(detail)->warnings) {
        if (err->line) {
          annotations.append(CodeEdit::Annotation{
              (int)*err->line, err->column ? (int)*err->column : -1, false,
              QString::fromStdString(err->message)});
        }
      }
      break;
    case dessser::gen::source_info::Failed:
      for (auto const &err :
           std::get<dessser::gen::source_info::Failed>(detail).errors) {
        if (err->line) {
          annotations.append(CodeEdit::Annotation{
              (int)*err->line, err->column ? (int)*err->column : -1, true,
              QString::fromStdString(err->message)});
        }
      }
      break;
  }
  codeEdit->setAnnotations(annotations);
}

QSize KTextEdit::sizeHint() const { return suggestedSize; }
