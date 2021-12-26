// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "source/NewSourceDialog.h"

#include <QComboBox>
#include <QDebug>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <ctime>

#include "ConfClient.h"
#include "KTextEdit.h"
#include "MakeSyncValue.h"
#include "Menu.h"
#include "PathNameValidator.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"
#include "source/CodeEdit.h"

static bool const verbose{false};

NewSourceDialog::NewSourceDialog(QWidget *parent) : QDialog(parent) {
  nameEdit = new QLineEdit;
  nameEdit->setPlaceholderText("Unique name");
  nameEdit->setValidator(new PathNameValidator(this));
  connect(nameEdit, &QLineEdit::textChanged, this,
          &NewSourceDialog::checkValidity);
  // TODO: Validate that the name is unique

  codeEdit = new CodeEdit;
  codeEdit->setEnabled(true);
  connect(codeEdit, &CodeEdit::inputChanged, this,
          &NewSourceDialog::checkValidity);

  buttonBox =
      new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

  connect(buttonBox, &QDialogButtonBox::accepted, this,
          &NewSourceDialog::createSource);
  connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

  QFormLayout *formLayout{new QFormLayout};
  formLayout->addRow(tr("Source name"), nameEdit);
  formLayout->addRow(codeEdit);
  QVBoxLayout *layout{new QVBoxLayout};
  layout->addLayout(formLayout);
  layout->addWidget(buttonBox);
  setLayout(layout);

  setWindowTitle(tr("Create New Source"));
  setModal(true);
}

void NewSourceDialog::checkValidity() {
  if (verbose) qDebug() << "NewSourceDialog::checkValidity()";

  buttonBox->button(QDialogButtonBox::Ok)
      ->setEnabled(nameEdit->hasAcceptableInput() && codeEdit->hasValidInput());
}

void NewSourceDialog::createSource() {
  std::string const extension{
      codeEdit->extensionsCombo->currentData().toString().toStdString()};
  std::shared_ptr<dessser::gen::sync_value::t const> val{codeEdit->getValue()};

  std::shared_ptr<dessser::gen::sync_key::t const> key{
      keyOfSrcPath(nameEdit->text().toStdString(), extension)};
  Menu::getClient()->sendNew(key, val);

  clear();
  QDialog::accept();
}

void NewSourceDialog::clear() {
  codeEdit->enableLanguage(codeEdit->alertEditorIndex, true);
  codeEdit->enableLanguage(codeEdit->textEditorIndex, true);
  codeEdit->enableLanguage(codeEdit->infoEditorIndex, false);
  codeEdit->setLanguage(codeEdit->textEditorIndex);
  codeEdit->textEditor->setValue(
      ofString("-- Created by " + my_uid->toStdString() + " the " +
               stringOfDate(std::time(nullptr)).toStdString()));
}
