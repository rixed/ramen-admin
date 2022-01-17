// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TARGETCONFIGEDITORWIN_H_190809
#define TARGETCONFIGEDITORWIN_H_190809
#include "SavedWindow.h"

namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class AtomicForm;
class QMessageBox;
class QPushButton;
class QString;
class TargetConfigEditor;

class TargetConfigEditorWin : public SavedWindow {
  Q_OBJECT

  AtomicForm *form;

  TargetConfigEditor *targetConfigEditor;

  QMessageBox *confirmDeleteDialog;

  /* The TargetConfigEditor itself is not deletable (so the delete button of
   * if AtomicWidgte won't be displayed. But we need a delete button to delete
   * a single entry: */
  QPushButton *deleteButton;

 public:
  TargetConfigEditorWin(QWidget *parent = nullptr);

  void preselect(QString const &programName);

 protected slots:
  void wantDeleteEntry();
  void wantNewEntry();
  void disableEditIfEmpty(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
