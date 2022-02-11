// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingContactSqliteEditor.h"

#include <QFormLayout>
#include <QLineEdit>
#include <QPlainTextEdit>

#include "desssergen/alerting_contact.h"

AlertingContactSqliteEditor::AlertingContactSqliteEditor(QWidget *parent)
    : AlertingContactViaEditor(parent) {
  QFormLayout *layout{new QFormLayout};

  fileEdit = new QLineEdit;
  fileEdit->setPlaceholderText(tr("path to sqlite DB file"));
  layout->addRow(tr("File:"), fileEdit);

  createEdit = new QPlainTextEdit;
  createEdit->setPlaceholderText(tr(
      "SQL command to create the DB when the above file does not exist yet."));
  layout->addRow(tr("Create:"), createEdit);

  insertEdit = new QPlainTextEdit;
  insertEdit->setPlaceholderText(
      tr("SQL command to insert an incident in the DB."));
  layout->addRow(tr("Insert:"), insertEdit);

  setLayout(layout);
}

std::shared_ptr<dessser::gen::alerting_contact::via>
AlertingContactSqliteEditor::getValue() const {
  return std::make_shared<dessser::gen::alerting_contact::via>(
      std::in_place_index<dessser::gen::alerting_contact::Sqlite>,
      fileEdit->text().toStdString(), insertEdit->toPlainText().toStdString(),
      createEdit->toPlainText().toStdString());
}

bool AlertingContactSqliteEditor::setValue(
    dessser::gen::alerting_contact::via const &v) {
  if (v.index() != dessser::gen::alerting_contact::Sqlite) return false;
  auto const &s{std::get<dessser::gen::alerting_contact::Sqlite>(v)};
  fileEdit->setText(QString::fromStdString(s.file));
  insertEdit->setPlainText(QString::fromStdString(s.insert));
  createEdit->setPlainText(QString::fromStdString(s.create));
  return true;
}

void AlertingContactSqliteEditor::clear() {
  fileEdit->clear();
  insertEdit->clear();
  createEdit->clear();
}
