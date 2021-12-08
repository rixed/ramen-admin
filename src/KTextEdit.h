#ifndef KTEXTEDIT_H_190603
#define KTEXTEDIT_H_190603
#include <QSize>
#include "AtomicWidget.h"

class QPlainTextEdit;

class KTextEdit : public AtomicWidget
{
  Q_OBJECT

  QPlainTextEdit *textEdit;

  QSize suggestedSize;

  // If true (default), editor is configured to edit RaQL syntax
  bool raql;

public:
  KTextEdit(bool raql = true, QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

  QSize sizeHint() const;

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
