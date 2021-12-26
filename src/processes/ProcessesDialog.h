// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef PROCESSESDIALOG_H_190806
#define PROCESSESDIALOG_H_190806
#include "SavedWindow.h"

class ProcessesWidget;
class GraphModel;

class ProcessesDialog : public SavedWindow {
  Q_OBJECT

  ProcessesWidget *processesWidget;

 public:
  ProcessesDialog(QWidget *parent = nullptr);

 protected:
  void keyPressEvent(QKeyEvent *);
};

#endif
