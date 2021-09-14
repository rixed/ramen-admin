#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <QAbstractSocket>
#include <QApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QVector>
#include <sodium.h>

#include "KVStore.h"
#include "Menu.h"
#include "misc.h"
#include "NamesTree.h"
#include "SyncStatus.h"
#include "UserIdentity.h"
#include "config.h"

int main(int argc, char *argv[])
{
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

  QString configDir =
    getenv("HOME") ?
      qgetenv("HOME") + QString("/.config/rmadmin") :
      QString("/etc/rmadmin");

  qRegisterMetaType<KValue>();
  qRegisterMetaType<QAbstractSocket::SocketError>();
  qRegisterMetaType<QList<ConfChange>>();
  qRegisterMetaType<SyncStatus>();

  // Creates the global kvs (store of keys) before widgets start to use it:
  kvs = std::make_shared<KVStore>();

  NamesTree::globalNamesTree = new NamesTree(true);

  Menu::initLoginWin(configDir);
  Menu::openLoginWin();

  int ret = app.exec();

  Menu::deleteDialogs();
  danceOfDelLater<NamesTree>(&NamesTree::globalNamesTree);

  return ret;
}