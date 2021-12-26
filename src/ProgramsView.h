// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef PROGRAMSVIEW_H_190611
#define PROGRAMSVIEW_H_190611
#include "AtomicForm.h"

class TargetConfigEditor;

class ProgramsView : public AtomicForm {
  Q_OBJECT

  TargetConfigEditor *rcEditor;

 public:
  ProgramsView(QWidget *parent = nullptr);
};

#endif
