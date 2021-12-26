// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "KLabel.h"

#include <QLabel>

#include "MakeSyncValue.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

KLabel::KLabel(QWidget *parent, bool wordWrap) : AtomicWidget(parent) {
  label = new QLabel;
  label->setWordWrap(wordWrap);
  relayoutWidget(label);
}

bool KLabel::setValue(std::shared_ptr<dessser::gen::sync_value::t const> v) {
  QString new_v{syncValToQString(*v, key())};

  if (new_v != label->text()) {
    label->setText(new_v);
    emit valueChanged(v);
  }

  return true;
}
