// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef KVOIDEDITOR_H_211124
#define KVOIDEDITOR_H_211124
/* Editor for a raql_value of type Void */
#include "AtomicWidget.h"

class KVoidEditor : public AtomicWidget {
  Q_OBJECT

 public:
  KVoidEditor(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
