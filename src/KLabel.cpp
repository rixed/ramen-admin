#include <QLabel>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "misc_dessser.h"

#include "KLabel.h"

KLabel::KLabel(QWidget *parent, bool wordWrap) :
  AtomicWidget(parent)
{
  label = new QLabel;
  label->setWordWrap(wordWrap);
  relayoutWidget(label);
}

bool KLabel::setValue(
  std::shared_ptr<dessser::gen::sync_key::t const> k,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  QString new_v { syncValToQString(*v, k) };

  if (new_v != label->text()) {
    label->setText(new_v);
    emit valueChanged(k, v);
  }

  return true;
}
