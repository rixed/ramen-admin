#include <cassert>
#include <limits>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "misc_dessser.h"
#include "RangeIntValidator.h"

#include "KIntEditor.h"

KIntEditor::KIntEditor(
    std::function<std::shared_ptr<dessser::gen::sync_value::t>(QString const &)> ofQString_,
    QWidget *parent,
    std::optional<int128_t> min,
    std::optional<int128_t> max) :
  AtomicWidget(parent),
  ofQString(ofQString_)
{
  lineEdit = new QLineEdit;
  relayoutWidget(lineEdit);

  int imin =
    min && *min >= std::numeric_limits<int>::min() ?
      *min : std::numeric_limits<int>::min();
  int imax =
    max && *max <= std::numeric_limits<int>::max() ?
      *max : std::numeric_limits<int>::max();
  lineEdit->setValidator(RangeIntValidator::forRange(imin, imax));

  connect(lineEdit, &QLineEdit::editingFinished,
          this, &KIntEditor::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KIntEditor::getValue() const
{
  return stringOfQString(lineEdit->text());
}

void KIntEditor::setEnabled(bool enabled)
{
  lineEdit->setEnabled(enabled);
}

/* TODO: returning an actual error message that could be used in the error
 * label would be better */
bool KIntEditor::setValue(
  dessser::gen::sync_key::t const &k,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  QString new_v { valToQString(*v, k) };

  if (new_v != lineEdit->text()) {
    lineEdit->setText(new_v);
    emit valueChanged(k, v);
  }

  return true;
}

#undef MakeKIntEditor
