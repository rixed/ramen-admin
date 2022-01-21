// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "KIntEditor.h"

#include <limits>

#include "MakeSyncValue.h"
#include "RangeIntValidator.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

KIntEditor::KIntEditor(
    std::function<std::shared_ptr<dessser::gen::sync_value::t>(QString const &)>
        ofQString_,
    QWidget *parent, std::optional<int128_t> min, std::optional<int128_t> max)
    : AtomicWidget(parent), ofQString(ofQString_) {
  lineEdit = new QLineEdit;
  relayoutWidget(lineEdit);

  int imin = min && *min >= std::numeric_limits<int>::min()
                 ? *min
                 : std::numeric_limits<int>::min();
  int imax = max && *max <= std::numeric_limits<int>::max()
                 ? *max
                 : std::numeric_limits<int>::max();
  lineEdit->setValidator(RangeIntValidator::forRange(imin, imax));

  connect(lineEdit, &QLineEdit::editingFinished, this,
          &KIntEditor::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KIntEditor::getValue()
    const {
  return ofQString(lineEdit->text());
}

void KIntEditor::setEnabled(bool enabled) { lineEdit->setEnabled(enabled); }

/* TODO: returning an actual error message that could be used in the error
 * label would be better */
bool KIntEditor::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  QString new_v{syncValToQString(*v, key())};

  if (new_v != lineEdit->text()) {
    lineEdit->setText(new_v);
    emit valueChanged(v);
  }

  return true;
}
