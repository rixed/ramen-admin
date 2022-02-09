// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/NewInhibitionDialog.h"

#include <QDebug>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

#include "alerting/AlertingInhibitionEditor.h"

NewInhibitionDialog::NewInhibitionDialog(QWidget *parent) : QDialog(parent) {
  title = new QLabel;

  nameEdit = new QLineEdit;
  nameEdit->setPlaceholderText("Unique name");
  // TODO: Validate that the name is unique

  editor = new AlertingInhibitionEditor;

  QDialogButtonBox *buttonBox{
      new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel)};

  QFormLayout *layout{new QFormLayout};
  layout->addRow(title);
  layout->addRow(tr("Name"), nameEdit);
  layout->addRow(editor);
  layout->addRow(buttonBox);
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
