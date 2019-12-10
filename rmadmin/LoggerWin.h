#ifndef LOGGERWIN_H_191025
#define LOGGERWIN_H_191025
#include "SavedWindow.h"

class LoggerView;
class Logger;

class LoggerWin : public SavedWindow
{
  Q_OBJECT

  LoggerView *loggerView;

public:
  Logger *logger;

  LoggerWin(QWidget *parent = nullptr);
};

#endif
