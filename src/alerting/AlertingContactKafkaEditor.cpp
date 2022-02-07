// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingContactKafkaEditor.h"

#include <QFormLayout>
#include <QLineEdit>
#include <QPlainTextEdit>

#include "RangeIntValidator.h"
#include "desssergen/alerting_contact.h"

AlertingContactKafkaEditor::AlertingContactKafkaEditor(QWidget *parent)
    : AlertingContactViaEditor(parent) {
  QFormLayout *layout{new QFormLayout};

  // TODO: list

  topicEdit = new QLineEdit;
  topicEdit->setPlaceholderText(tr("topic name"));
  layout->addRow(tr("Topic:"), topicEdit);

  partitionEdit = new QLineEdit;
  partitionEdit->setPlaceholderText(tr("partition number"));
  partitionEdit->setValidator(RangeIntValidator::forRange(0, 65535));
  layout->addRow(tr("Partition:"), partitionEdit);

  textEdit = new QPlainTextEdit;
  textEdit->setPlaceholderText(tr("message to send via Kafka"));
  layout->addRow(tr("Message:"), textEdit);

  setLayout(layout);
}

std::shared_ptr<dessser::gen::alerting_contact::via>
AlertingContactKafkaEditor::getValue() const {
  return std::make_shared<dessser::gen::alerting_contact::via>(
      std::in_place_index<dessser::gen::alerting_contact::Kafka>,
      dessser::Lst<dessser::gen::alerting_contact::
                       t720047405469e43c41ae902df9d2c463>(),  // TODO
      topicEdit->text().toStdString(), uint16_t(partitionEdit->text().toInt()),
      textEdit->toPlainText().toStdString());
}

bool AlertingContactKafkaEditor::setValue(
    std::shared_ptr<dessser::gen::alerting_contact::via const> v) {
  if (v->index() != dessser::gen::alerting_contact::Kafka) return false;
  auto const &k{std::get<dessser::gen::alerting_contact::Kafka>(*v)};
  // TODO: options
  topicEdit->setText(QString::fromStdString(k.topic));
  partitionEdit->setText(QString::number(k.partition));
  textEdit->setPlainText(QString::fromStdString(k.text));
  return true;
}

void AlertingContactKafkaEditor::clear() {
  topicEdit->clear();
  partitionEdit->clear();
  textEdit->clear();
}
