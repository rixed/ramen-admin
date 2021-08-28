#include <cassert>
#include <iostream>
#include <string>
#include <cstdlib>
#include <QAbstractSocket>
#include <QApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QVector>

#include "ConfClient.h"
#include "UserIdentity.h"
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

  qRegisterMetaType<QAbstractSocket::SocketError>();
  qRegisterMetaType<SyncStatus>();

  // test ConfClient:
  QString const idFile { configDir + "/identity" };
  QFile file(idFile);
  std::shared_ptr<UserIdentity> id = std::make_shared<UserIdentity>(file);
  if (! id->isValid) {
    qCritical() << "Identity file" << idFile << "is not valid";
    return 1;
  }
  ConfClient *client = new ConfClient("localhost:29340", "rixed", id, nullptr);

  int ret = app.exec();

  return ret;
}
