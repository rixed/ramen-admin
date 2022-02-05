// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingContactExecuteEditor.h"

#include <QLabel>
#include <QPlainTextEdit>
#include <QVBoxLayout>

#include "desssergen/alerting_contact.h"

AlertingContactExecuteEditor::AlertingContactExecuteEditor(QWidget *parent)
    : AlertingContactViaEditor(parent) {
  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(new QLabel(tr("Command:")));
  edit = new QPlainTextEdit;
  edit->setPlaceholderText(tr("enter command to execute"));
  layout->addWidget(edit);
  setLayout(layout);
}

std::shared_ptr<dessser::gen::alerting_contact::via>
AlertingContactExecuteEditor::getValue() const {
  return std::make_shared<dessser::gen::alerting_contact::via>(
      std::in_place_index<dessser::gen::alerting_contact::Exec>,
      edit->toPlainText().toStdString());
}

bool AlertingContactExecuteEditor::setValue(
    std::shared_ptr<dessser::gen::alerting_contact::via const> v) {
  if (v->index() != dessser::gen::alerting_contact::Exec) return false;
  edit->setPlainText(QString::fromStdString(
      std::get<dessser::gen::alerting_contact::Exec>(*v)));
  return true;
}
