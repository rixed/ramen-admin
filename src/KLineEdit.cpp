#include <cassert>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "misc_dessser.h"

#include "KLineEdit.h"

KLineEdit::KLineEdit(QWidget *parent) :
  AtomicWidget(parent)
{
  lineEdit = new QLineEdit;
  relayoutWidget(lineEdit);
  connect(lineEdit, &QLineEdit::editingFinished,
          this, &KLineEdit::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KLineEdit::getValue() const
{
  return stringOfQString(lineEdit->text());
}

void KLineEdit::setEnabled(bool enabled)
{
  lineEdit->setEnabled(enabled);
}

bool KLineEdit::setValue(
  std::shared_ptr<dessser::gen::sync_key::t const> k,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  QString new_v { syncValToQString(*v, k) };

  if (new_v != lineEdit->text()) {
    lineEdit->setText(new_v);
    emit valueChanged(k, v);
  }

  return true;
}
