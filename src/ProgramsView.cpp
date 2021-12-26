// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ProgramsView.h"

#include "TargetConfigEditor.h"

ProgramsView::ProgramsView(QWidget *parent) : AtomicForm(parent) {
  // TODO: Add a search box

  rcEditor = new TargetConfigEditor;
  rcEditor->setKey("target_config");
  setCentralWidget(rcEditor);
  addWidget(rcEditor);
}
