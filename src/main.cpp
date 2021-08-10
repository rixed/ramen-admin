#include <cassert>
#include <iostream>
#include <string>
#include <cstdlib>
#include <QApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QVector>
#include "ConfClient.h"
#include "config.h"

int main(int argc, char *argv[])
{
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

  qRegisterMetaType<SyncStatus>();

  int ret = app.exec();

  return ret;
}
