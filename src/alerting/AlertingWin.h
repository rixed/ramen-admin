// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGWINDOW_H_200525
#define ALERTINGWINDOW_H_200525
#include "SavedWindow.h"

class AlertingJournal;
class AlertingStats;
class AlertingTimeLine;

class AlertingWin : public SavedWindow {
  Q_OBJECT

  AlertingStats *stats;
  AlertingTimeLine *timeLine;
  AlertingJournal *journal;

 public:
  AlertingWin(QWidget *parent = nullptr);
};

#endif
