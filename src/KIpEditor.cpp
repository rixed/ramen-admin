#include "KIpEditor.h"

#include <QLineEdit>
#include <cassert>

#include "MakeSyncValue.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

KIpEditor::KIpEditor(bool allow_v4, bool allow_v6, QWidget *parent)
    : AtomicWidget(parent), allowV4(allow_v4), allowV6(allow_v6) {
  lineEdit = new QLineEdit;
  lineEdit->setPlaceholderText(tr("Enter an IP address (v4 or v6)"));
  relayoutWidget(lineEdit);
  connect(lineEdit, &QLineEdit::editingFinished, this,
          &KIpEditor::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KIpEditor::getValue() const {
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

void KIpEditor::setEnabled(bool enabled) { lineEdit->setEnabled(enabled); }

bool KIpEditor::setValue(std::shared_ptr<dessser::gen::sync_value::t const> v) {
  QString new_v{syncValToQString(*v, key())};

  if (new_v != lineEdit->text()) {
    lineEdit->setText(new_v);
    emit valueChanged(v);
  }

  return true;
}
