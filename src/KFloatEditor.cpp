#include <cassert>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "misc_dessser.h"
#include "RangeDoubleValidator.h"

#include "KFloatEditor.h"

KFloatEditor::KFloatEditor(QWidget *parent, double min, double max) :
  AtomicWidget(parent)
{
  lineEdit = new QLineEdit;
  lineEdit->setValidator(RangeDoubleValidator::forRange(min, max));
  relayoutWidget(lineEdit);
  connect(lineEdit, &QLineEdit::editingFinished,
          this, &KFloatEditor::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KFloatEditor::getValue() const
{
  return floatOfQString(lineEdit->text());
}

void KFloatEditor::setEnabled(bool enabled)
{
  lineEdit->setEnabled(enabled);
}

/* TODO: returning an actual error message that could be used in the error
 * label would be better */
bool KFloatEditor::setValue(
  dessser::gen::sync_key::t const &k,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  QString new_v { syncValToQString(*v, k) };

  if (new_v != lineEdit->text()) {
    lineEdit->setText(new_v);
    emit valueChanged(k, v);
  }

  return true;
}
