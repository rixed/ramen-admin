#include <cassert>
#include "RangeIntValidator.h"
#include "KIntEditor.h"

#pragma GCC diagnostic ignored "-Wtautological-constant-out-of-range-compare"
#pragma GCC diagnostic ignored "-Wsign-compare"

KIntEditor::KIntEditor(
    std::function<RamenValue *(QString const &)> ofQString_,
    conf::Key const &key,
    QWidget *parent,
    std::optional<int128_t> min,
    std::optional<int128_t> max) :
  AtomicWidget(key, parent),
  ofQString(ofQString_)
{
  lineEdit = new QLineEdit;
  setCentralWidget(lineEdit);

  int imin =
    min.has_value() && *min >= std::numeric_limits<int>::min() ?
      *min : std::numeric_limits<int>::min();
  int imax =
    max.has_value() && *max <= std::numeric_limits<int>::max() ?
      *max : std::numeric_limits<int>::max();
  lineEdit->setValidator(RangeIntValidator::forRange(imin, imax));

  conf::kvs_lock.lock_shared();
  KValue &kv = conf::kvs[key];
  if (kv.isSet()) {
    bool ok = setValue(key, kv.val);
    assert(ok); // ?
  }
  setEnabled(kv.isMine());
  conf::kvs_lock.unlock_shared();

  connect(&kv, &KValue::valueCreated, this, &KIntEditor::setValue);
  connect(&kv, &KValue::valueChanged, this, &KIntEditor::setValue);
  connect(&kv, &KValue::valueLocked, this, &KIntEditor::lockValue);
  connect(&kv, &KValue::valueUnlocked, this, &KIntEditor::unlockValue);
}

std::shared_ptr<conf::Value const> KIntEditor::getValue() const
{
  RamenValue *v = ofQString(lineEdit->text());
  return std::shared_ptr<conf::Value const>(new conf::RamenValueValue(v));
}

void KIntEditor::setEnabled(bool enabled)
{
  AtomicWidget::setEnabled(enabled);
  lineEdit->setEnabled(enabled);
}

/* TODO: returning an actual error message that could be used in the error
 * label would be better */
bool KIntEditor::setValue(conf::Key const &k, std::shared_ptr<conf::Value const> v)
{
  QString new_v(v->toQString(k));
  if (new_v != lineEdit->text()) {
    lineEdit->setText(new_v);
    emit valueChanged(k, v);
  }

  return true;
}

#undef MakeKIntEditor