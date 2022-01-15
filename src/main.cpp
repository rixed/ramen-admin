// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include <sodium.h>

//#define TEST_MODEL
#ifdef TEST_MODEL
#include <QAbstractItemModelTester>
#endif
#include <QAbstractSocket>
#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QVector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>

#include "GraphModel.h"
#include "KVStore.h"
#include "Menu.h"
#include "NamesTree.h"
#include "SyncStatus.h"
#include "UserIdentity.h"
#include "alerting/AlertingLogsModel.h"
#include "config.h"
#include "dashboard/DashboardTreeModel.h"
#include "misc.h"
#include "stream/GraphViewSettings.h"

int main(int argc, char *argv[]) {
  if (sodium_init() < 0) {
    std::cerr << "Cannot initialize libsodium!?" << std::endl;
    return 1;
  }

  QApplication app(argc, argv);
  QCoreApplication::setOrganizationName("Accedian");
  QCoreApplication::setOrganizationDomain("accedian.com");
  QCoreApplication::setApplicationName("RmAdmin");
  QCoreApplication::setApplicationVersion(PACKAGE_VERSION);

  QCommandLineParser parser;
  parser.setApplicationDescription("Ramen Client GUI");
  parser.addHelpOption();
  parser.addVersionOption();

  /* For GuiHelper: */
  QCommandLineOption debugOption(
      QString("debug"),
      QCoreApplication::translate("main", "Display confserver messages"));
  parser.addOption(debugOption);

  parser.process(app);

  QString configDir = getenv("HOME")
                          ? qgetenv("HOME") + QString("/.config/rmadmin")
                          : QString("/etc/rmadmin");

  qRegisterMetaType<KValue>();
  qRegisterMetaType<QAbstractSocket::SocketError>();
  qRegisterMetaType<QList<ConfChange> >();
  qRegisterMetaType<SyncStatus>();

  // Creates the global kvs (store of keys) before widgets start to use it:
  kvs = std::make_shared<KVStore>();

  NamesTree::globalNamesTree = new NamesTree(true);
  NamesTree::globalNamesTreeAnySites = new NamesTree(false);

  /* A GraphModel satisfies both the TreeView and the GraphView
   * requirements: */
  GraphViewSettings settings;
  GraphModel::globalGraphModel = new GraphModel(settings);

#ifdef TEST_MODEL
  auto tester = new QAbstractItemModelTester(
      GraphModel::globalGraphModel,
      QAbstractItemModelTester::FailureReportingMode::Fatal);
  (void)tester;
#endif

  DashboardTreeModel::globalDashboardTree = new DashboardTreeModel;
  AlertingLogsModel::globalLogsModel = new AlertingLogsModel;

  Menu::initLoginWin(configDir);
  Menu::openLoginWin();

  int ret = app.exec();

  Menu::deleteDialogs();
  danceOfDelLater<NamesTree>(&NamesTree::globalNamesTree);

  return ret;
}
