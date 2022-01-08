// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TARGETCONFIGEDITORWIN_H_190809
#define TARGETCONFIGEDITORWIN_H_190809
#include "SavedWindow.h"

class AtomicForm;
class QMessageBox;
class QString;
class TargetConfigEditor;

class TargetConfigEditorWin : public SavedWindow {
  Q_OBJECT

  AtomicForm *form;

  TargetConfigEditor *targetConfigEditor;

  QMessageBox *confirmDeleteDialog;

 public:
  TargetConfigEditorWin(QWidget *parent = nullptr);

  void preselect(QString const &programName);

 protected slots:
  void wantDeleteEntry();
  void wantNewEntry();
};

#endif
