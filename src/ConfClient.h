#ifndef CONFCLIENT_H_210810
#define CONFCLIENT_H_210810
/* A configuration client handle the connection to the configuration server,
 * starts the synchronization and feed the designated KVStore with changes. */

#include <cstddef>
#include <string>
#include <QAbstractSocket>
#include <QObject>
#include <QString>

#include "SyncStatus.h"

class QTcpSocket;
class UserIdentity;
class KVStore;

class ConfClient : public QObject
{
  Q_OBJECT

  KVStore *kvs;

  /*
   * Connection state:
   */

  QTcpSocket *tcpSocket;
  SyncStatus syncStatus;

public:
  // confserver as in "host:port"
  ConfClient(QString const &server, QString const &username, UserIdentity const *id, KVStore *);

signals:
  void connectionProgressed(SyncStatus newStage);
  void connectionNonFatalError(SyncStatus currentStatus, QString const error);
  void connectionFatalError(SyncStatus currentStatus, QString const error);

private slots:
  void onTcpError(QAbstractSocket::SocketError);
  void onStateChange(QAbstractSocket::SocketState);
  void onDataReady();
};

#endif
