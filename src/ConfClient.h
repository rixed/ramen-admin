#ifndef CONFCLIENT_H_210810
#define CONFCLIENT_H_210810
/* A configuration client handle the connection to the configuration server,
 * starts the synchronization and feed the designated KVStore with changes. */

#include <cstddef>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <list>
#include <QAbstractSocket>
#include <QObject>
#include <QString>
#include <sodium.h>

#include "SyncStatus.h"

class QTcpSocket;
struct UserIdentity;
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
  QTcpSocket *tcpSocket;
  SyncStatus syncStatus;

  // Either one or the other:
  QString const clearUsername;
  std::shared_ptr<UserIdentity const> id;

  // Sequence number used for outgoing messages:
  uint32_t seq = 0;

  // Used for secure channel (using libsodium)
  unsigned char clt_nonce[crypto_box_NONCEBYTES];
  unsigned char srv_nonce[crypto_box_NONCEBYTES];
  /* srv_pub_key starts with the well known server public key and is replaced
   * by a session public key after SendSessionKey have been received: */
  unsigned char srv_pub_key[crypto_box_PUBLICKEYBYTES];
  // Also whenever the server keys are received this is precomputed:
  unsigned char channel_key[crypto_box_BEFORENMBYTES];
  unsigned char clt_pub_key[crypto_box_PUBLICKEYBYTES];
  unsigned char clt_priv_key[crypto_box_SECRETKEYBYTES];
  bool keySent = false;
  // Used for applicative keep-alive (TODO) (0 means not ready yet)
  qint64 lastSent = 0U;

  struct OnDoneCallback {
    uint32_t seq;
    std::function<int(std::string const &)> callback;

    OnDoneCallback(uint32_t seq_, std::function<int(std::string const &)> callback_)
      : seq(seq_), callback(callback_) {}
  };

  std::list<OnDoneCallback> onDoneCallbacks;

  void fatalErr(QString const &errString);

  int sendAuth();

  int sendMsg(std::shared_ptr<dessser::gen::sync_client_msg::t const>);

  int sendBytes(char const *, size_t);

  int readSrvMsg(dessser::Bytes const &);

  int recvdSessionKey(
        dessser::Bytes const &public_key,
        dessser::Bytes const &nonce,
        dessser::Bytes const &message);

  // Decrypt the given message and call readSrvMsg:
  int readCrypted(dessser::Bytes const &);

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

  bool isCrypted() const;

  QString const username() const;

  // Checks whether we had a call-back for that key and execute it
  int checkDones(
        std::shared_ptr<dessser::gen::sync_key::t const>,
        std::shared_ptr<dessser::gen::sync_value::t const>);

public:
  /* Configuration server's representation of my socket, identifying this
   * connection (although most configuration objects are associated to a user name,
   * some are with a specific socket). */
  std::shared_ptr<dessser::gen::sync_socket::t const> syncSocket;
  std::shared_ptr<dessser::gen::sync_key::t const> myErrKey;

  // confserver as in "host:port"
  ConfClient(QString const &server, QString const &username,
             std::shared_ptr<UserIdentity const>,
             std::shared_ptr<KVStore>);

  bool isSynced() const;

  int sendNew(
        std::shared_ptr<dessser::gen::sync_key::t const>,
        std::shared_ptr<dessser::gen::sync_value::t const> = nullptr,
        double timeout = 0.);

  int sendSet(
        std::shared_ptr<dessser::gen::sync_key::t const>,
        std::shared_ptr<dessser::gen::sync_value::t const>);

# define DEFAULT_LOCK_TIMEOUT 600.
  int sendLock(
        std::shared_ptr<dessser::gen::sync_key::t const>,
        double timeout = DEFAULT_LOCK_TIMEOUT);

  int sendUnlock(
        std::shared_ptr<dessser::gen::sync_key::t const>);

  int sendDel(
        std::shared_ptr<dessser::gen::sync_key::t const>);

  int sendCmd(
    std::shared_ptr<dessser::gen::sync_client_cmd::t const>,
    /* Register what should happen when the result is received (with err message,
     * empty if no error). */
    std::optional<std::function<int(std::string const &)>> = std::nullopt,
    bool echo = true);

signals:
  void connectionProgressed(SyncStatus newStage);
  void connectionNonFatalError(SyncStatus currentStatus, QString const &error);
  void connectionFatalError(SyncStatus currentStatus, QString const &error);
  void knownErrKey(std::shared_ptr<dessser::gen::sync_key::t const>);

private slots:
  void onTcpError(QAbstractSocket::SocketError);
  void onStateChange(QAbstractSocket::SocketState);
  void readMsg();
};

#endif
