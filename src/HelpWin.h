// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef HELPWIN_H_220301
#define HELPWIN_H_220301
#include "SavedWindow.h"

#define HELP_WINDOW_NAME "HelpWindow"

class HelpWin : public SavedWindow {
  Q_OBJECT

 public:
  HelpWin(QWidget *parent = nullptr);
};

#endif
