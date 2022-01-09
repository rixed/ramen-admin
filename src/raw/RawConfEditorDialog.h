// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef RAWCONFEDITORDIALOG_H_190729
#define RAWCONFEDITORDIALOG_H_190729
#include <QDialog>
#include <memory>

#include "desssergen/sync_key.h"

class AtomicWidget;

class RawConfEditorDialog : public QDialog {
  Q_OBJECT

  AtomicWidget *editor;
  std::shared_ptr<dessser::gen::sync_key::t const> key;
  bool canWrite, showEditor;

 public:
  RawConfEditorDialog(
      std::shared_ptr<dessser::gen::sync_key::t const>,
      // Even if we can write that key we might prefer not to show the editor:
      bool show_editor = true, QWidget *parent = nullptr);

 private slots:
  void save();
  void cancel();
};

#endif
