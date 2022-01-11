// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef PROCESSESWIN_H_190806
#define PROCESSESWIN_H_190806
#include "SavedWindow.h"

class ProcessesWidget;
class GraphModel;

class ProcessesWin : public SavedWindow {
  Q_OBJECT

  ProcessesWidget *processesWidget;

 public:
  ProcessesWin(QWidget *parent = nullptr);

 protected:
  void keyPressEvent(QKeyEvent *);
};

#endif
