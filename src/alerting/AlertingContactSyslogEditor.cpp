// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingContactSyslogEditor.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "desssergen/alerting_contact.h"

AlertingContactSyslogEditor::AlertingContactSyslogEditor(QWidget *parent)
    : AlertingContactViaEditor(parent) {
  QHBoxLayout *layout{new QHBoxLayout};
  layout->addWidget(new QLabel(tr("Message:")));
  edit = new QLineEdit;
  edit->setPlaceholderText(tr("message to log"));
  layout->addWidget(edit);
  setLayout(layout);
}

std::shared_ptr<dessser::gen::alerting_contact::via>
AlertingContactSyslogEditor::getValue() const {
  return std::make_shared<dessser::gen::alerting_contact::via>(
      std::in_place_index<dessser::gen::alerting_contact::SysLog>,
      edit->text().toStdString());
}

bool AlertingContactSyslogEditor::setValue(
    std::shared_ptr<dessser::gen::alerting_contact::via const> v) {
  if (v->index() != dessser::gen::alerting_contact::SysLog) return false;
  edit->setText(QString::fromStdString(
      std::get<dessser::gen::alerting_contact::SysLog>(*v)));
  return true;
}
