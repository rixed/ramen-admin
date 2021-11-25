#include <cassert>
#include <QLineEdit>

#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "misc_dessser.h"

#include "KIpEditor.h"

KIpEditor::KIpEditor(bool allow_v4, bool allow_v6, QWidget *parent)
  : AtomicWidget(parent),
    allowV4(allow_v4),
    allowV6(allow_v6)
{
  lineEdit = new QLineEdit;
  relayoutWidget(lineEdit);
  connect(lineEdit, &QLineEdit::editingFinished,
          this, &KIpEditor::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KIpEditor::getValue() const
{
  if (allowV4 && allowV6) {
    // returns an Ip
    return ipOfQString(lineEdit->text());
  } else if (allowV4) {
    // returns an Ipv4
    return ipv4OfQString(lineEdit->text());
  } else if (allowV6) {
    // returns an Ipv6
    return ipv6OfQString(lineEdit->text());
  } else {
    return nullptr;
  }
}

void KIpEditor::setEnabled(bool enabled)
{
  lineEdit->setEnabled(enabled);
}

bool KIpEditor::setValue(
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
