// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef CONFCLIENT_H_210810
#define CONFCLIENT_H_210810
/* A configuration client handle the connection to the configuration server,
 * starts the synchronization and feed the designated KVStore with changes. */

#include <sodium.h>

#include <QAbstractSocket>
#include <QObject>
#include <QString>
#include <cstddef>
#include <functional>
#include <list>
#include <memory>
#include <optional>
#include <string>

#include "SyncStatus.h"
#include "desssergen/sync_socket.h"

class QTcpSocket;
class QTimer;
struct UserIdentity;
class KVStore;

namespace dessser {
struct Bytes;

namespace gen {
namespace sync_client_cmd {
struct t;
}
namespace sync_client_msg {
struct t;
}
namespace sync_server_msg {
struct t;
}
namespace sync_msg {
struct t;
}
namespace sync_key {
struct t;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class ConfClient : public QObject {
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

  // Used for applicative keep-alive (0 means not ready yet)
  qint64 lastSent = 0U;
  QTimer *timer;

  struct OnDoneCallback {
    uint32_t seq;
    std::function<int(std::string const &)> callback;

    OnDoneCallback(uint32_t seq_,
                   std::function<int(std::string const &)> callback_)
        : seq(seq_), callback(callback_) {}
  };

  std::list<OnDoneCallback> onDoneCallbacks;

  void fatalErr(QString const &errString);

  int sendAuth();

  int sendMsg(dessser::gen::sync_client_msg::t const &);

  int sendBytes(char const *, size_t);

  int readSrvMsg(dessser::Bytes const &);

  int rcvdSessionKey(dessser::Bytes const &public_key,
                     dessser::Bytes const &nonce,
                     dessser::Bytes const &message);

  // Decrypt the given message and call readSrvMsg:
  int readCrypted(dessser::Bytes const &);

  int rcvdAuthOk(dessser::gen::sync_socket::t const &);

  int rcvdAuthErr(QString const &err);

  int rcvdSetKey(std::shared_ptr<dessser::gen::sync_key::t const>,
                 std::shared_ptr<dessser::gen::sync_value::t const>,
                 QString const &set_by_uid, double const mtime);

  int rcvdNewKey(std::shared_ptr<dessser::gen::sync_key::t const>,
                 std::shared_ptr<dessser::gen::sync_value::t const>,
                 QString const &set_by_uid, double const mtime,
                 bool const can_write, bool const can_del, QString const &owner,
                 double const expiry);

  int rcvdDelKey(std::shared_ptr<dessser::gen::sync_key::t const>,
                 std::string const &uid);

  int rcvdLockKey(std::shared_ptr<dessser::gen::sync_key::t const>,
                  QString const &owner, double const expiry);

  int rcvdUnlockKey(std::shared_ptr<dessser::gen::sync_key::t const>);

  int startSynchronization();

  bool isCrypted() const;

  QString const username() const;

  // Checks whether we had a call-back for that key and execute it
  int checkDones(dessser::gen::sync_key::t const &,
                 dessser::gen::sync_value::t const &);

 public:
  /* Some stats about the connection */
  qint64 sentBytes = 0U, rcvdBytes = 0U;
  qint64 sentMsgs = 0U, rcvdMsgs = 0U;

  /* Configuration server's representation of my socket, identifying this
   * connection (although most configuration objects are associated to a user
   * name, some are with a specific socket). */
  std::optional<dessser::gen::sync_socket::t> syncSocket;
  std::shared_ptr<dessser::gen::sync_key::t const> myErrKey;

  // confserver as in "host:port"
  ConfClient(QString const &server, QString const &username,
             std::shared_ptr<UserIdentity const>, std::shared_ptr<KVStore>);

  bool isSynced() const;

  int sendNew(dessser::gen::sync_key::t const &,
              dessser::gen::sync_value::t const &, double timeout = 0.);

  int sendSet(dessser::gen::sync_key::t const &,
              dessser::gen::sync_value::t const &);

#define DEFAULT_LOCK_TIMEOUT 600.
  int sendLock(dessser::gen::sync_key::t const &,
               double timeout = DEFAULT_LOCK_TIMEOUT);

  int sendUnlock(dessser::gen::sync_key::t const &);

  int sendDel(dessser::gen::sync_key::t const &);

  int sendCmd(
      dessser::gen::sync_client_cmd::t const &,
      /* Register what should happen when the result is received (with err
       * message, empty if no error). */
      std::optional<std::function<int(std::string const &)> > = std::nullopt,
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
  void keepAlive();
};

#endif
