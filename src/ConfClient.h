#ifndef CONFCLIENT_H_210810
#define CONFCLIENT_H_210810
/* A configuration client handle the connection to the configuration server,
 * starts the synchronization and feed the designated KVStore with changes. */

#include <cstddef>
#include <memory>
#include <string>
#include <QAbstractSocket>
#include <QObject>
#include <QString>

#include "SyncStatus.h"

class QTcpSocket;
class UserIdentity;
class KVStore;

namespace dessser {
  struct Bytes;

  namespace gen {
    namespace sync_client_cmd { struct t; }
    namespace sync_client_msg { struct t; }
    namespace sync_server_msg { struct t; }
    namespace sync_msg { struct t; }
    namespace sync_socket { struct t; }
    namespace sync_key { struct t; }
    namespace sync_value { struct t; }
  }
}

class ConfClient : public QObject
{
  Q_OBJECT

  std::shared_ptr<KVStore> kvs;

private:
  QTcpSocket *tcpSocket;
  SyncStatus syncStatus;

  QString const username;
  std::shared_ptr<UserIdentity const> id;

  // Sequence number used for outgoing messages:
  uint32_t seq = 0;

  /* Configuration server's representation of my socket, identifying this
   * connection (although most configuration objects are associated to a user name,
   * some are with a specific socket). */
  std::shared_ptr<dessser::gen::sync_socket::t const> syncSocket;

  void fatalErr(QString const &errString);

  int sendAuth();

  int sendCmd(
    dessser::gen::sync_client_cmd::t const &,
    bool confirm_success = true,
    bool echo = true);

  int sendMsg(dessser::gen::sync_client_msg::t const &);

  int sendBytes(char const *, size_t);

  int readSrvMsg(dessser::Bytes const &);

  int recvdAuthOk(std::shared_ptr<dessser::gen::sync_socket::t const>);

  int recvdAuthErr(QString const &err);

  int recvdSetKey(
        std::shared_ptr<dessser::gen::sync_key::t const>,
        std::shared_ptr<dessser::gen::sync_value::t const>,
        QString const &set_by_uid, double const mtime);

  int recvdNewKey(
        std::shared_ptr<dessser::gen::sync_key::t const>,
        std::shared_ptr<dessser::gen::sync_value::t const>,
        QString const &set_by_uid, double const mtime,
        bool const can_write, bool const can_del,
        QString const &owner, double const expiry);

  int recvdDelKey(std::shared_ptr<dessser::gen::sync_key::t const>);

  int recvdLockKey(
        std::shared_ptr<dessser::gen::sync_key::t const>,
        QString const &owner, double const expiry);

  int recvdUnlockKey(std::shared_ptr<dessser::gen::sync_key::t const>);

  int startSynchronization();

public:
  // confserver as in "host:port"
  ConfClient(QString const &server, QString const &username,
             std::shared_ptr<UserIdentity const>,
             std::shared_ptr<KVStore>);

signals:
  void connectionProgressed(SyncStatus newStage);
  void connectionNonFatalError(SyncStatus currentStatus, QString const error);
  void connectionFatalError(SyncStatus currentStatus, QString const error);

private slots:
  void onTcpError(QAbstractSocket::SocketError);
  void onStateChange(QAbstractSocket::SocketState);
  void readMsg();
};

/* Printer for some dessser generated types: */

QDebug operator<<(QDebug, dessser::gen::sync_client_cmd::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_client_msg::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_server_msg::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_msg::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_socket::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_key::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_value::t const &);

#endif
