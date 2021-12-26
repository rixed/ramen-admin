// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef STORAGEWIN_H_190902
#define STORAGEWIN_H_190902
#include "SavedWindow.h"

class StorageWin : public SavedWindow {
  Q_OBJECT

 public:
  StorageWin(QWidget *parent = nullptr);
};

#endif
