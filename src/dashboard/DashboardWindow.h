// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef DASHBOARDWINDOW_H_200304
#define DASHBOARDWINDOW_H_200304
#include <QString>
#include <string>

#include "SavedWindow.h"

class Dashboard;

class DashboardWindow : public SavedWindow {
  Q_OBJECT

  Dashboard *dashboard;

 public:
  DashboardWindow(std::string const &dash_name, QWidget *parent = nullptr);
};

#endif
