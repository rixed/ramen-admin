// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/NewTeamDialog.h"

#include <QDebug>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

NewTeamDialog::NewTeamDialog(QWidget *parent) : QDialog(parent) {
  nameEdit = new QLineEdit;
  nameEdit->setPlaceholderText("Unique name");
  // TODO: Validate that the name is unique

  QLabel *doc{
      new QLabel(tr("Alerts will be assigned to the team which name has the "
                    "longest matching prefix with the alert name."))};
  doc->setStyleSheet("font-style: italic");
  doc->setWordWrap(true);

  QDialogButtonBox *buttonBox{
      new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel)};

  QFormLayout *layout{new QFormLayout};
  layout->addRow(tr("Team name"), nameEdit);
  layout->addRow(doc);
  layout->addRow(buttonBox);
  setLayout(layout);

  setWindowTitle(tr("Create A New Team"));
  setModal(true);

  connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
  connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void NewTeamDialog::clear() { nameEdit->clear(); }

QString const NewTeamDialog::getValue() const { return nameEdit->text(); }
