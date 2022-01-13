// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "dashboard/DashboardWindow.h"

#include <QDebug>

#include "Menu.h"
#include "dashboard/Dashboard.h"

static constexpr bool verbose{false};

DashboardWindow::DashboardWindow(std::string const &dash_name, QWidget *parent)
    : SavedWindow(
          QString("dashboardWindow/") + Menu::nameOfDashboard(dash_name),
          QString("Dashboard: ") + Menu::nameOfDashboard(dash_name), true,
          parent, true) {
  dashboard = new Dashboard(dash_name, this);
  setCentralWidget(dashboard);

  resize(700, 700);

  if (verbose) qDebug() << "New dashboard window created";
}
