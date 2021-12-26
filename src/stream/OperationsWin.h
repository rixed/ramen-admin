// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OPERATIONSWIN_H_191111
#define OPERATIONSWIN_H_191111
/* A window displaying the OperationsView widget. */
#include "SavedWindow.h"

class QWidget;

class OperationsWin : public SavedWindow {
  Q_OBJECT

 public:
  explicit OperationsWin(QWidget *parent = nullptr);
};

#endif
