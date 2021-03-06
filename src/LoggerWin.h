// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef LOGGERWIN_H_191025
#define LOGGERWIN_H_191025
#include "SavedWindow.h"

class Logger;
class LoggerView;

class LoggerWin : public SavedWindow {
  Q_OBJECT

 public:
  LoggerView *loggerView;
  Logger *logger;

  LoggerWin(QWidget *parent = nullptr);
};

#endif
