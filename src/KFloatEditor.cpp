// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "KFloatEditor.h"

#include <cassert>

#include "MakeSyncValue.h"
#include "RangeDoubleValidator.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

KFloatEditor::KFloatEditor(QWidget *parent, double min, double max)
    : AtomicWidget(parent) {
  lineEdit = new QLineEdit;
  lineEdit->setValidator(RangeDoubleValidator::forRange(min, max));
  relayoutWidget(lineEdit);
  connect(lineEdit, &QLineEdit::editingFinished, this,
          &KFloatEditor::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KFloatEditor::getValue()
    const {
  return floatOfQString(lineEdit->text());
}

void KFloatEditor::setEnabled(bool enabled) { lineEdit->setEnabled(enabled); }

/* TODO: returning an actual error message that could be used in the error
 * label would be better */
bool KFloatEditor::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  QString new_v{syncValToQString(*v, key())};

  if (new_v != lineEdit->text()) {
    lineEdit->setText(new_v);
    emit valueChanged(v);
  }

  return true;
}
