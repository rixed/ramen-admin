#ifndef NEWPROGRAMDIALOG_H_190731
#define NEWPROGRAMDIALOG_H_190731
#include <memory>
#include <QDialog>

#include "ConfChange.h"

class QPushButton;
class RCEntryEditor;

struct KValue;

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
    namespace sync_value { struct t; }
  }
}

class NewProgramDialog : public QDialog
{
  Q_OBJECT

  RCEntryEditor *editor;
  bool mustSave;

  QPushButton *okButton;

  void mayWriteRC(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &);

public:
  NewProgramDialog(QString const &sourceName = "", QWidget *parent = nullptr);

private:
  void appendEntry(dessser::gen::sync_value::t const &);

protected slots:
  void createProgram();
  void onChange(QList<ConfChange> const &);
  // Called whenever the form is updated to maybe enable/disable the okButton:
  void validate();
};

#endif
