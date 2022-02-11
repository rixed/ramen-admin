// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingContactIgnoreEditor.h"

#include <QLabel>
#include <QVBoxLayout>

#include "desssergen/alerting_contact.h"

AlertingContactIgnoreEditor::AlertingContactIgnoreEditor(QWidget *parent)
    : AlertingContactViaEditor(parent) {
  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(
      new QLabel(tr("No attempt will be made to contact any oncaller.")));
  setLayout(layout);
}

std::shared_ptr<dessser::gen::alerting_contact::via>
AlertingContactIgnoreEditor::getValue() const {
  return std::make_shared<dessser::gen::alerting_contact::via>(
      std::in_place_index<dessser::gen::alerting_contact::Ignore>,
      dessser::Void());
}

bool AlertingContactIgnoreEditor::setValue(
    dessser::gen::alerting_contact::via const &v) {
  return v.index() == dessser::gen::alerting_contact::Ignore;
}

void AlertingContactIgnoreEditor::clear() {}
