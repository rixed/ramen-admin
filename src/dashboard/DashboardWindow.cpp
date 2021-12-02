#include <QDebug>

#include "dashboard/Dashboard.h"
#include "Menu.h"

#include "dashboard/DashboardWindow.h"

static bool const verbose { false };

DashboardWindow::DashboardWindow(std::string const &dash_name, QWidget *parent)
  : SavedWindow(
      QString("dashboardWindow/") + Menu::nameOfDashboard(dash_name),
      QString("Dashboard: ") + Menu::nameOfDashboard(dash_name),
      true,
      parent,
      true)
{
  dashboard = new Dashboard(dash_name, this);
  setCentralWidget(dashboard);

  resize(700, 700);

  if (verbose)
    qDebug() << "New dashboard window created";
}
