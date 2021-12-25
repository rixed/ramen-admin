#include "ServerInfoWin.h"

#include "ServerInfoWidget.h"

ServerInfoWin::ServerInfoWin(QString const &srvUrl, QWidget *parent)
    : SavedWindow("ServerInfoWindow", tr("Server Information"), true, parent) {
  ServerInfoWidget *serverInfoWidget = new ServerInfoWidget(srvUrl, this);
  setCentralWidget(serverInfoWidget);
}
