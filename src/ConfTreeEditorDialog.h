#ifndef CONFTREEEDITORDIALOG_H_190729
#define CONFTREEEDITORDIALOG_H_190729
#include <QDialog>

#include "desssergen/sync_key.h"

class AtomicWidget;

class ConfTreeEditorDialog : public QDialog
{
  Q_OBJECT

  AtomicWidget *editor;
  dessser::gen::sync_key::t const key;
  bool can_write;

public:
  ConfTreeEditorDialog(dessser::gen::sync_key::t const &k, QWidget *parent = nullptr);

private slots:
  void save();
  void cancel();
};

#endif
