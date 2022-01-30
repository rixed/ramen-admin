// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "source/SourceEditForm.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QVBoxLayout>

#include "KTextEdit.h"
#include "ProgramItem.h"
#include "misc_dessser.h"
#include "source/AlertEditor.h"
#include "source/SourceCloneDialog.h"
#include "source/SourceEdit.h"
#include "source/SourceInfoViewer.h"

static constexpr bool verbose{false};

SourceEditForm::SourceEditForm(QWidget *parent) : AtomicForm(true, parent) {
  layout()->setContentsMargins(QMargins());

  QPushButton *cloneButton{new QPushButton("&Clone…")};
  // Because that AtomicForm was created with buttons just above
  Q_ASSERT(buttonsLayout);
  buttonsLayout->insertWidget(0, cloneButton);

  codeEdit = new SourceEdit;
  codeEdit->setObjectName("codeEdit");
  // FIXME: codeEdit should inherit AtomicWidgetAlternative
  setCentralWidget(codeEdit);
  addWidget(codeEdit->alertEditor, true);
  addWidget(codeEdit->textEditor, true);
  addWidget(codeEdit->infoEditor, true);

  // Connect the clone button to the creation of a cloning dialog:
  connect(cloneButton, &QPushButton::clicked, this, &SourceEditForm::wantClone);
  // Disable language switcher in edit mode
  connect(this, &SourceEditForm::changeEnabled, codeEdit,
          &SourceEdit::disableLanguageSwitch);
}

void SourceEditForm::wantClone() {
  if (verbose)
    qDebug() << "SourceEditForm::wantClone: srcPath="
             << QString::fromStdString(codeEdit->srcPath) << ", extension="
             << codeEdit->extensionsCombo->currentData().toString();

  if (codeEdit->srcPath.size() == 0) return;

  /* We might want to have as many of those dialogues open as we want
   * to create clones (possibly of the same source); So just create
   * a new dialog each time the clone button is clicked.
   * Note that we clone only the selected extension. */
  std::shared_ptr<dessser::gen::sync_key::t const> orig{keyOfSrcPath(
      codeEdit->srcPath,
      codeEdit->extensionsCombo->currentData().toString().toStdString())};

  SourceCloneDialog *dialog{new SourceCloneDialog(orig, this)};
  dialog->show();
}
