// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/EditContactDialog.h"

#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "AtomicForm.h"
#include "alerting/AlertingContactEditor.h"
#include "misc_dessser.h"

EditContactDialog::EditContactDialog(QWidget *parent) : QDialog(parent) {
  title = new QLabel;
  form = new AtomicForm(true, true, this);
  editor = new AlertingContactEditor(this);

  form->addWidget(editor);
  form->setCentralWidget(editor);

  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(title);
  layout->addWidget(form);
  setLayout(layout);

  setModal(true);

  // Close this window on submit and cancel:
  connect(form, &AtomicForm::changeEnabled, [this](bool enabled) {
    if (!enabled) done(0);
  });
  connect(form->cancelButton, &QPushButton::clicked, [this]() {
    if (!form->isEnabled()) done(1);
  });
}

void EditContactDialog::reset(QString const &team_name,
                              QString const &contact_name) {
  std::shared_ptr<dessser::gen::sync_key::t const> key{
      keyOfTeamContact(team_name.toStdString(), contact_name.toStdString())};
  editor->setKey(key);
  editor->setValueFromStore();
  title->setText(tr("Contact %1 for team %2").arg(contact_name).arg(team_name));
  setWindowTitle(tr("Edit Contact %1").arg(contact_name));
}
