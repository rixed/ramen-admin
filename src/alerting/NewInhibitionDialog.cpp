// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/NewInhibitionDialog.h"

#include <QDebug>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include "alerting/AlertingInhibitionEditor.h"

NewInhibitionDialog::NewInhibitionDialog(QWidget *parent) : QDialog(parent) {
  title = new QLabel;

  nameEdit = new QLineEdit;
  nameEdit->setPlaceholderText("Unique name");
  // TODO: Validate that the name is unique

  editor = new AlertingInhibitionEditor;

  QDialogButtonBox *buttonBox{
      new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel)};

  QFormLayout *formLayout{new QFormLayout};
  formLayout->addRow(tr("Name"), nameEdit);

  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(title);
  layout->addLayout(formLayout);
  layout->addWidget(editor);
  layout->addWidget(buttonBox);
  setLayout(layout);

  setWindowTitle(tr("Create A New Inhibition"));
  setModal(true);

  connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
  connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void NewInhibitionDialog::reset(QString const &team_name) {
  teamName = team_name;
  editor->clear();
  title->setText(tr("New alert inhibition for team %1:").arg(team_name));
}

std::shared_ptr<dessser::gen::sync_value::t const>
NewInhibitionDialog::getValue() const {
  return editor->getValue();
}

QString NewInhibitionDialog::getTeamName() const { return teamName; }

QString NewInhibitionDialog::getInhibitionName() const {
  return nameEdit->text();
}
