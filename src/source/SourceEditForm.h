// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef SOURCEEDITFORM_H_190516
#define SOURCEEDITFORM_H_190516
#include <memory>
#include <string>

#include "AtomicForm.h"

class SourceEdit;

class SourceEditForm : public AtomicForm {
  Q_OBJECT

 public:
  SourceEdit *codeEdit;

  SourceEditForm(QWidget *parent = nullptr);

 protected slots:
  void wantClone();
};

#endif
