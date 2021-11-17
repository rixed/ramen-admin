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

public:
  KTextEdit(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

  QSize sizeHint() const;

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_key::t const>,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
