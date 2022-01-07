// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef NEWTARGETCONFIGENTRYDIALOG_H_190731
#define NEWTARGETCONFIGENTRYDIALOG_H_190731
#include <QDialog>
#include <memory>

#include "ConfChange.h"

class QPushButton;
class TargetConfigEntryEditor;

struct KValue;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class NewTargetConfigEntryDialog : public QDialog {
  Q_OBJECT

  TargetConfigEntryEditor *editor;
  bool mustSave;

  QPushButton *okButton;

  void mayWriteRC(std::shared_ptr<dessser::gen::sync_key::t const>,
                  KValue const &);

 public:
  NewTargetConfigEntryDialog(QString const &sourceName = "",
                             QWidget *parent = nullptr);

 private:
  void appendEntry(dessser::gen::sync_value::t const &);

 protected slots:
  void createProgram();
  void onChange(QList<ConfChange> const &);
  // Called whenever the form is updated to maybe enable/disable the okButton:
  void validate();
};

#endif
