#ifndef KLINEEDIT_H_190505
#define KLINEEDIT_H_190505
#include <QLineEdit>
#include "AtomicWidget.h"

class KLineEdit : public AtomicWidget
{
  Q_OBJECT

  QLineEdit *lineEdit;

public:
  KLineEdit(QWidget *parent = nullptr);

  void setPlaceholderText(QString const s) {
    lineEdit->setPlaceholderText(s);
  }

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
