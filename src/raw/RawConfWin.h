// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef RAWCONFWIN_H_190731
#define RAWCONFWIN_H_190731
#include "SavedWindow.h"

class ConfTreeWidget;

class RawConfWin : public SavedWindow {
  Q_OBJECT

  ConfTreeWidget *confTreeWidget;

 public:
  RawConfWin(QWidget *parent = nullptr);
};

#endif
