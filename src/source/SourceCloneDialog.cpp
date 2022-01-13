// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "source/SourceCloneDialog.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtGlobal>

#include "ConfClient.h"
#include "Menu.h"
#include "PathNameValidator.h"
#include "misc_dessser.h"

static constexpr bool verbose{false};

SourceCloneDialog::SourceCloneDialog(
    std::shared_ptr<dessser::gen::sync_key::t const> origKey, QWidget *parent)
    : QDialog(parent) {
  std::optional<std::pair<std::string const, std::string const> > src_path{
      srcPathOfKey(*origKey)};
  if (!src_path) {
    qCritical() << "SourceCloneDialog: Invalid origKey:" << *origKey;
    newKeyEdit = nullptr;
    cloneButton = nullptr;
    return;
  }
  srcPath = src_path->first;
  extension = src_path->second;

  kvs->lock.lock_shared();
  auto it{kvs->map.find(origKey)};
  if (it != kvs->map.end()) value = it->second.val;
  kvs->lock.unlock_shared();

  QVBoxLayout *layout{new QVBoxLayout};

  if (value) {
    QLabel *label{new QLabel(
        tr("Where to clone %1 into?").arg(QString::fromStdString(srcPath)))};
    newKeyEdit = new QLineEdit;
    newKeyEdit->setValidator(new PathNameValidator(this));

    cloneButton = new QPushButton(tr("Clone"));
    cloneButton->setAutoDefault(false);
    cloneButton->setDefault(false);
    cloneButton->setEnabled(false);
    QPushButton *cancelButton{new QPushButton(tr("Cancel"))};
    cancelButton->setAutoDefault(false);
    cancelButton->setDefault(false);
    QHBoxLayout *buttonBox{new QHBoxLayout};
    buttonBox->addStretch();
    buttonBox->addWidget(cancelButton);
    buttonBox->addWidget(cloneButton);

    layout->addWidget(label);
    layout->addWidget(newKeyEdit);
    layout->addLayout(buttonBox);

    connect(cloneButton, &QPushButton::clicked, this,
            &SourceCloneDialog::cloneSource);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    connect(newKeyEdit, &QLineEdit::textChanged, this,
            &SourceCloneDialog::validate);
  } else {  // no such key

    newKeyEdit = nullptr;
    cloneButton = nullptr;
    QLabel *label{new QLabel(tr("Source for %1 has no value!?")
                                 .arg(QString::fromStdString(srcPath)))};
    layout->addWidget(label);
  }

  setLayout(layout);
}

void SourceCloneDialog::cloneSource() {
  std::shared_ptr<dessser::gen::sync_key::t const> newKey{
      keyOfSrcPath(newKeyEdit->text().toStdString(), extension)};
  // FIXME: validate that this name is free and valid

  if (verbose) qDebug() << "Saving cloned value into" << *newKey;

  Menu::getClient()->sendNew(newKey, value);
  QDialog::accept();
}

void SourceCloneDialog::validate() {
  bool const isValid{newKeyEdit->hasAcceptableInput()};
  cloneButton->setEnabled(isValid);
}
