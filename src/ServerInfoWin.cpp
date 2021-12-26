// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ServerInfoWin.h"

#include "ServerInfoWidget.h"

ServerInfoWin::ServerInfoWin(QString const &srvUrl, QWidget *parent)
    : SavedWindow("ServerInfoWindow", tr("Server Information"), true, parent) {
  ServerInfoWidget *serverInfoWidget = new ServerInfoWidget(srvUrl, this);
  setCentralWidget(serverInfoWidget);
}
