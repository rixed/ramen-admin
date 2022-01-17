// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "TargetConfigEditorWin.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QStackedLayout>

#include "AtomicForm.h"
#include "Menu.h"
#include "Resources.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"
#include "target_config/TargetConfigEditor.h"
#include "target_config/TargetConfigEntryEditor.h"

TargetConfigEditorWin::TargetConfigEditorWin(QWidget *parent)
    : SavedWindow("TargetConfigWindow", tr("Target Configuration"), true,
                  parent) {
  form = new AtomicForm(true, this);

  Resources *r{Resources::get()};
  /* Prepare to add a delete button to the form.
   * Notice that RC entries being just elements of the TargetConfig
   * they have no independent keys that could be deleted independently.
   * Instead, we need an ad-hoc delete function. */
  deleteButton = new QPushButton(r->deletePixmap, tr("Delete this entry"));
  form->buttonsLayout->insertWidget(2, deleteButton);
  connect(form, &AtomicForm::changeEnabled, deleteButton,
          &QPushButton::setEnabled);
  // Every form start disabled (thus won't signal changeEnabled at init):
  deleteButton->setEnabled(form->isEnabled());
  connect(deleteButton, &QPushButton::clicked, this,
          &TargetConfigEditorWin::wantDeleteEntry);
  /* Similarly, we want a "new" button that will add an entry */
  QPushButton *newButton{new QPushButton(r->addPixmap, tr("New entry"))};
  form->buttonsLayout->addWidget(newButton);
  connect(newButton, &QPushButton::clicked, this,
          &TargetConfigEditorWin::wantNewEntry);

  targetConfigEditor = new TargetConfigEditor;
  connect(targetConfigEditor, &TargetConfigEditor::valueChanged, this,
          &TargetConfigEditorWin::disableEditIfEmpty);
  targetConfigEditor->setKey(targetConfig);
  targetConfigEditor->setValueFromStore();
  form->setCentralWidget(targetConfigEditor);
  form->addWidget(targetConfigEditor);

  setCentralWidget(form);

  // Prepare the confirmation dialog for deletion:
  confirmDeleteDialog = new QMessageBox(this);
  confirmDeleteDialog->setText(
      tr("Are you sure you want to delete this entry?"));
  confirmDeleteDialog->setStandardButtons(QMessageBox::Yes |
                                          QMessageBox::Cancel);
  confirmDeleteDialog->setDefaultButton(QMessageBox::Cancel);
  confirmDeleteDialog->setIcon(QMessageBox::Warning);
}

void TargetConfigEditorWin::wantDeleteEntry() {
  // Retrieve the entry.
  if (targetConfigEditor->stackedLayout->currentIndex() !=
      targetConfigEditor->entryEditorIdx)
    return;

  QString info{tr("This program will no longer be running.")};
  if (targetConfigEditor->entryEditor->programIsEnabled())
    info.append(
        tr("\n\nAlternatively, this program could be "
           "temporarily disabled."));
  confirmDeleteDialog->setInformativeText(info);

  if (QMessageBox::Yes == confirmDeleteDialog->exec()) {
    targetConfigEditor->removeCurrentEntry();
    // Also submit the form:
    form->wantSubmit();
  }
}

void TargetConfigEditorWin::wantNewEntry() {
  Menu::openNewTargetConfigEntryDialog();
}

void TargetConfigEditorWin::preselect(QString const &programName) {
  targetConfigEditor->preselect(programName);
}

void TargetConfigEditorWin::disableEditIfEmpty(
    std::shared_ptr<dessser::gen::sync_value::t const> sync_value) {
  if (sync_value->index() != dessser::gen::sync_value::TargetConfig) {
    qWarning() << "target-config is actually:" << *sync_value;
    return;
  }
  dessser::Arr<dessser::gen::rc_entry::t_ext> const &target_config{
      std::get<dessser::gen::sync_value::TargetConfig>(*sync_value)};

  bool has_entries{target_config.size() > 0};
  form->editButton->setVisible(has_entries);
  form->cancelButton->setVisible(has_entries ||
                                 form->cancelButton->isEnabled());
  deleteButton->setVisible(has_entries);
  form->submitButton->setVisible(has_entries ||
                                 form->submitButton->isEnabled());
}
