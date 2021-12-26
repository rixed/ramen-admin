// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef CODEEDITFORM_H_190516
#define CODEEDITFORM_H_190516
#include <memory>
#include <string>

#include "AtomicForm.h"

class CodeEdit;

class CodeEditForm : public AtomicForm {
  Q_OBJECT

 public:
  CodeEdit *codeEdit;

  CodeEditForm(QWidget *parent = nullptr);

 protected slots:
  void wantClone();
};

#endif
