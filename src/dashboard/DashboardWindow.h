#ifndef DASHBOARDWINDOW_H_200304
#define DASHBOARDWINDOW_H_200304
#include <string>
#include <QString>

#include "SavedWindow.h"

class Dashboard;

class DashboardWindow : public SavedWindow
{
  Q_OBJECT

  Dashboard *dashboard;

public:
  DashboardWindow(std::string const &dash_name, QWidget *parent = nullptr);
};

#endif
