// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ConfClient.h"

#include <dessser/Bytes.h>
#include <dessser/Pointer.h>
#include <sodium.h>

#include <QByteArray>
#include <QDateTime>
#include <QDebug>
#include <QTcpSocket>
#include <QTimer>
#include <QtGlobal>
#include <cstdlib>
#include <memory>

#include "KVStore.h"
#include "UserIdentity.h"
#include "desssergen/sync_client_msg.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_msg.h"
#include "desssergen/sync_server_msg.h"
#include "misc_dessser.h"
#include "z85.h"

static bool const verbose{false};

static double const sessionTimeout{300.};

static std::shared_ptr<dessser::gen::sync_key::t const> const devNull{
    std::make_shared<dessser::gen::sync_key::t const>(
        std::in_place_index<dessser::gen::sync_key::DevNull>, dessser::Void())};

void ConfClient::fatalErr(QString const &errString) {
  // Emit the signal with the status we were in before the error occurred:
  emit connectionFatalError(syncStatus, errString);
  syncStatus.set(SyncStatus::Failed);
  qDebug().nospace() << "ConfClient::fatalErr(" << errString << ")!";
}

#include "ConfClientTools.cpp"

ConfClient::ConfClient(QString const &target, QString const &username_,
                       std::shared_ptr<UserIdentity const> id_,
                       std::shared_ptr<KVStore> kvs_)
    : kvs(kvs_),
      tcpSocket(new QTcpSocket(this)),
      syncStatus(SyncStatus::Disconnected),
      clearUsername(username_),
      id(id_) {
  connect(tcpSocket,
          QOverload<QAbstractSocket::SocketError>::of(
              &QAbstractSocket::errorOccurred),
          this, &ConfClient::onTcpError);
  connect(tcpSocket, &QAbstractSocket::stateChanged, this,
          &ConfClient::onStateChange);
  connect(tcpSocket, &QIODevice::readyRead, this, &ConfClient::readMsg);

  QString host;
  quint16 port;
  if (0 != parseUrl(host, port, target)) {
    fatalErr("Cannot parse configuration server URL: " + target);
  } else {
    tcpSocket->connectToHost(host, port);
  }

  if (isCrypted()) {
    /* Pick a nonce */
    randombytes_buf(clt_nonce, sizeof clt_nonce);
    /* Prepare keys: */
    size_t const pub_capa{sizeof srv_pub_key};
    if (z85_decode(id->srv_pub_key.length(),
                   (unsigned char const *)id->srv_pub_key.toStdString().c_str(),
                   pub_capa, srv_pub_key) != pub_capa) {
      qCritical() << "Invalid server public key";
    }
    if (z85_decode(id->clt_pub_key.length(),
                   (unsigned char const *)id->clt_pub_key.toStdString().c_str(),
                   pub_capa, clt_pub_key) != pub_capa) {
      qCritical() << "Invalid client public key";
    }
    size_t const priv_capa{sizeof clt_priv_key};
    if (z85_decode(
            id->clt_priv_key.length(),
            (unsigned char const *)id->clt_priv_key.toStdString().c_str(),
            priv_capa, clt_priv_key) != priv_capa) {
      qCritical() << "Invalid client private key";
    }
  }

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &ConfClient::keepAlive);
  timer->start(1000);
}

void ConfClient::onTcpError(QAbstractSocket::SocketError err) {
  // In any case, signal the error:
  QString errString{tcpSocket->errorString()};
  bool isFatal{true};

  switch (err) {
    case QAbstractSocket::UnfinishedSocketOperationError:
      // Should not happen
      qCritical() << "ConfClient::onTcpError(UnfinishedSocketOperationError)?!";
      [[fallthrough]];
    case QAbstractSocket::TemporaryError:
      // Just ignore it
      isFatal = false;
      break;
    default:
      break;
  }

  if (isFatal) {
    fatalErr(errString);
  } else {
    emit connectionNonFatalError(syncStatus, errString);
  }
}

void ConfClient::onStateChange(QAbstractSocket::SocketState sockState) {
  SyncStatus oldStage{syncStatus};

  switch (sockState) {
    case QAbstractSocket::UnconnectedState:
      syncStatus.set(SyncStatus::Resolving);
      break;
    case QAbstractSocket::HostLookupState:
      syncStatus.set(SyncStatus::Resolving);
      break;
    case QAbstractSocket::ConnectingState:
      syncStatus.set(SyncStatus::Connecting);
      break;
    case QAbstractSocket::ConnectedState:
      if (0 == sendAuth()) syncStatus.set(SyncStatus::Authenticating);
      break;
    case QAbstractSocket::BoundState:
      // Should not happen on a client
      qWarning() << "ConfClient received stateChanged to BoundState!?";
      break;
    case QAbstractSocket::ClosingState:
      syncStatus.set(SyncStatus::Closing);
      break;
    case QAbstractSocket::ListeningState:
      // Should not happen at all
      qWarning() << "ConfClient received stateChanged to ListeningState!?";
      break;
  }

  if (syncStatus != oldStage) {
    if (verbose) qDebug() << "ConfClient::onStateChange(" << sockState << ")";
    emit connectionProgressed(syncStatus);
  }
}

void ConfClient::readMsg() {
  if (syncStatus == SyncStatus::Failed) return;
  if (syncStatus != SyncStatus::Authenticating &&
      syncStatus != SyncStatus::Synchronizing &&
      syncStatus != SyncStatus::Synchronized)
    qWarning() << "Received data while in syncStatus" << syncStatus;

  // Check we can read the message size:
  qint64 avail_sz{tcpSocket->bytesAvailable()};
  Q_ASSERT(avail_sz >= 0);

  rcvdBytes += avail_sz;

  while (avail_sz > 0) {
    if (avail_sz < 4) {
      if (verbose)
        qDebug() << "Only" << avail_sz << "bytes available to read, will wait.";
      break;
    }

    // read the message size:
    unsigned char prefix[4];
    qint64 const peeked{tcpSocket->peek((char *)prefix, 4)};
    Q_ASSERT(peeked == 4);

    // Prefix is little endian:
    size_t msg_sz{((size_t)prefix[3] << 24U) | ((size_t)prefix[2] << 16U) |
                  ((size_t)prefix[1] << 8U) | ((size_t)prefix[0] << 0U)};
    // Sanity check:
    if (msg_sz > 10 * 1024 * (size_t)1024) {  // Nope
      qWarning() << "Received a message pretending to be" << msg_sz
                 << "bytes long, quitting.";
    cannot_decode:
      emit connectionFatalError(syncStatus,
                                QString("Cannot decode configuration message"));
      syncStatus.set(SyncStatus::Failed);
      break;
    }

    // Do not read until the whole message is there:
    if ((size_t)avail_sz < 4 + msg_sz) {
      if (verbose)
        qDebug() << "Have to wait for" << (4 + msg_sz) - avail_sz
                 << "more bytes.";
      break;
    }

    // Alloc the message...
    std::shared_ptr<uint8_t[]> msg{(uint8_t *)std::malloc(msg_sz)};
    if (!msg) {
      qWarning() << "Cannot alloc" << 4 + msg_sz << "bytes!";
      emit connectionFatalError(syncStatus, QString("Cannot allocate memory"));
      syncStatus.set(SyncStatus::Failed);
      break;
    }

    // ...and read it, skipping the prefix:
    qint64 const skip_sz{tcpSocket->skip(4)};
    Q_ASSERT(skip_sz == 4);
    qint64 const read_sz{tcpSocket->read((char *)msg.get(), msg_sz)};
    Q_ASSERT((size_t)read_sz == msg_sz);
    avail_sz -= skip_sz + read_sz;

    if (msg_sz > (size_t)500000)
      qWarning() << "Message is" << msg_sz << "bytes!";

    // Parse it:
    dessser::Pointer in_ptr{msg, msg_sz};
    auto t_ptr{dessser::gen::sync_msg::of_row_binary(in_ptr)};
    size_t const dec_sz{std::get<1>(t_ptr).offset};
    if (dec_sz < msg_sz) {
      qWarning() << "Cannot decode configuration message: consumed only"
                 << dec_sz << "bytes out of" << msg_sz;
      goto cannot_decode;
    }
    std::shared_ptr<dessser::gen::sync_msg::t> authn{std::get<0>(t_ptr)};

    switch ((dessser::gen::sync_msg::Constr_t)authn->index()) {
      case dessser::gen::sync_msg::SendSessionKey: {
        auto const sess_keys{
            std::get<dessser::gen::sync_msg::SendSessionKey>(*authn)};
        if (0 != rcvdSessionKey(sess_keys.public_key, sess_keys.nonce,
                                sess_keys.message))
          goto cannot_decode;
      } break;
      case dessser::gen::sync_msg::Crypted: {
        dessser::Bytes const cipher{
            std::get<dessser::gen::sync_msg::Crypted>(*authn)};
        if (0 != readCrypted(cipher)) goto cannot_decode;
      } break;
      case dessser::gen::sync_msg::ClearText: {
        dessser::Bytes const msg_{
            std::get<dessser::gen::sync_msg::ClearText>(*authn)};
        if (0 != readSrvMsg(msg_)) goto cannot_decode;
      } break;
      case dessser::gen::sync_msg::Error: {
        QString errMsg{QString::fromStdString(
            std::get<dessser::gen::sync_msg::Error>(*authn))};
        qCritical() << "Error from confserver:" << errMsg;
        emit connectionNonFatalError(syncStatus, errMsg);
      } break;
      default:
        qCritical() << "Invalid authenticated message type";
        goto cannot_decode;
    }

    rcvdMsgs++;
  }
}

int ConfClient::rcvdSessionKey(dessser::Bytes const &public_key,
                               dessser::Bytes const &nonce,
                               dessser::Bytes const &message) {
  if (!keySent) {
    qCritical() << "Received session keys too early!";
    return -1;
  }
  // Replace server public key with that one:
  if (public_key.length() != sizeof srv_pub_key) {
    qCritical() << "Bad length for public key:" << public_key.length()
                << "Instead of" << sizeof srv_pub_key;
    return -1;
  }
  memcpy(srv_pub_key, public_key.get(), sizeof srv_pub_key);
  // precompute the channel key:
  if (0 != crypto_box_beforenm(channel_key, srv_pub_key, clt_priv_key)) {
    qCritical() << "Cannot crypto_box_beforenm";
    return -1;
  }
  // decrypt the message:
  memcpy(srv_nonce, nonce.get(), nonce.length());
  return readCrypted(message);
}

/* OCaml binding to libsodium implements its own version of increment for some
 * reason, and does so in a way that's incompatible with libsodium v1.0.18.
 * Namely, it increments from the end whereas libsodium increments from the
 * beginning. So let's implement the same increment here: */
static void sodium_increment_rev(unsigned char *b, size_t sz) {
  while (sz-- != 0) [[likely]] {
      uint_fast16_t const c{(uint_fast16_t)(b[sz] + 1)};
      b[sz] = c;
      if (!(c & 0x100)) [[likely]]
        break;
    }
}

/* Assumes srv_nonce and channel_key are up to date: */
int ConfClient::readCrypted(dessser::Bytes const &cipher) {
  /* clear_buffer must have capacity for the clear text, ie.
   * crypto_box_BOXZEROBYTES longer than cipher (cipher is MAC + message, NaCl
   * wants 32 zeros) */
  uint8_t clear_buffer[crypto_box_BOXZEROBYTES + cipher.length()];
  bzero(clear_buffer, crypto_box_ZEROBYTES);
  // Have to copy cipher for 0 headers:
  unsigned char cipher_[crypto_box_BOXZEROBYTES + cipher.length()];
  bzero(cipher_, crypto_box_BOXZEROBYTES);
  memcpy(cipher_ + crypto_box_BOXZEROBYTES, cipher.get(), cipher.length());
  if (0 != crypto_box_open_afternm(clear_buffer, cipher_, sizeof cipher_,
                                   srv_nonce, channel_key)) {
    qCritical() << "Cannot crypto_box_open_afternm";
    return -1;
  }

  // Increment server nonce:
  sodium_increment_rev(srv_nonce, sizeof srv_nonce);

  dessser::Bytes msg{// Points after padding and mac:
                     std::shared_ptr<uint8_t[]>(clear_buffer, [](uint8_t *) {}),
                     sizeof clear_buffer - crypto_box_ZEROBYTES,
                     size_t(crypto_box_ZEROBYTES)};

  return readSrvMsg(msg);
}

int ConfClient::startSynchronization() {
  syncStatus.set(SyncStatus::Synchronizing);
  emit connectionProgressed(syncStatus);

  /* Subscribe to all keys for now: */
  std::shared_ptr<dessser::gen::sync_client_cmd::t const> start_sync{
      std::make_shared<dessser::gen::sync_client_cmd::t const>(
          std::in_place_index<dessser::gen::sync_client_cmd::StartSync>,
          std::string("*"))};

  return sendCmd(start_sync, [this](std::string const &err) {
    if (err.empty()) {
      if (verbose) qDebug() << "Synchronisation completed";
      Q_ASSERT(syncStatus == SyncStatus::Synchronizing);
      syncStatus.set(SyncStatus::Synchronized);
      emit connectionProgressed(syncStatus);
      return 0;
    } else {
      qCritical() << "Cannot synchronize:" << QString::fromStdString(err);
      return -1;
    }
  });

  return 0;
}

int ConfClient::readSrvMsg(dessser::Bytes const &bytes) {
  dessser::Pointer in_ptr{bytes};
  auto t_ptr{dessser::gen::sync_server_msg::of_row_binary(in_ptr)};
  size_t const dec_sz{std::get<1>(t_ptr).offset};
  if (dec_sz < bytes.length()) {
    qWarning()
        << "Cannot decode configuration clear text message: consumed only"
        << dec_sz << "bytes out of" << bytes.length();
    return -1;
  }

  std::shared_ptr<dessser::gen::sync_server_msg::t> msg{std::get<0>(t_ptr)};
  if (verbose) qDebug() << "Received:" << *msg;

  switch ((dessser::gen::sync_server_msg::Constr_t)msg->index()) {
    case dessser::gen::sync_server_msg::AuthOk: {
      std::shared_ptr<dessser::gen::sync_socket::t const> sync_socket{
          std::get<dessser::gen::sync_server_msg::AuthOk>(*msg)};
      return rcvdAuthOk(sync_socket);
    }
    case dessser::gen::sync_server_msg::AuthErr: {
      std::string const err{
          std::get<dessser::gen::sync_server_msg::AuthErr>(*msg)};
      return rcvdAuthErr(QString::fromStdString(err));
    }
    case dessser::gen::sync_server_msg::SetKey: {
      auto const &set_key{
          std::get<dessser::gen::sync_server_msg::SetKey>(*msg)};
      std::shared_ptr<dessser::gen::sync_key::t const> k{set_key.SetKey_k};
      std::shared_ptr<dessser::gen::sync_value::t const> v{set_key.SetKey_v};
      return rcvdSetKey(k, v, QString::fromStdString(set_key.SetKey_uid),
                        set_key.SetKey_mtime);
    }
    case dessser::gen::sync_server_msg::NewKey: {
      auto const &new_key{
          std::get<dessser::gen::sync_server_msg::NewKey>(*msg)};
      std::shared_ptr<dessser::gen::sync_key::t const> k{new_key.NewKey_k};
      std::shared_ptr<dessser::gen::sync_value::t const> v{new_key.v};
      return rcvdNewKey(k, v, QString::fromStdString(new_key.NewKey_uid),
                        new_key.mtime, new_key.can_write, new_key.can_del,
                        QString::fromStdString(new_key.NewKey_owner),
                        new_key.NewKey_expiry);
    }
    case dessser::gen::sync_server_msg::DelKey: {
      auto const &del_key{
          std::get<dessser::gen::sync_server_msg::DelKey>(*msg)};
      std::shared_ptr<dessser::gen::sync_key::t const> k{del_key.DelKey_k};
      std::string const &uid{del_key.uid};
      return rcvdDelKey(k, uid);
    }
    case dessser::gen::sync_server_msg::LockKey: {
      auto const &lock{std::get<dessser::gen::sync_server_msg::LockKey>(*msg)};
      std::shared_ptr<dessser::gen::sync_key::t const> k{lock.k};
      return rcvdLockKey(k, QString::fromStdString(lock.owner), lock.expiry);
    }
    case dessser::gen::sync_server_msg::UnlockKey: {
      std::shared_ptr<dessser::gen::sync_key::t const> k{
          std::get<dessser::gen::sync_server_msg::UnlockKey>(*msg)};
      return rcvdUnlockKey(k);
    }
    default:
      qCritical() << "Invalid sync_server_msg type";
      return -1;
  }

  return -1;
}

int ConfClient::rcvdAuthErr(QString const &err) {
  fatalErr(err);
  return 0;
}

int ConfClient::rcvdAuthOk(
    std::shared_ptr<dessser::gen::sync_socket::t const> sync_socket) {
  syncSocket = sync_socket;
  // Also precompute our error key for faster comparison when messages are
  // received:
  myErrKey = std::make_shared<dessser::gen::sync_key::t const>(
      std::in_place_index<dessser::gen::sync_key::Error>,
      /* WARNING: the variant takes a *pointer* to the socket. Here we
       * reuse the one in syncSocket, which lifespan is the same as
       * myErrKey. */
      std::optional<dessser::gen::sync_socket::t_ext>(
          // dessser requires non-const although does not modify it:
          std::const_pointer_cast<dessser::gen::sync_socket::t>(syncSocket)));
  emit knownErrKey(myErrKey);
  return startSynchronization();
}

int ConfClient::rcvdSetKey(std::shared_ptr<dessser::gen::sync_key::t const> k,
                           std::shared_ptr<dessser::gen::sync_value::t const> v,
                           QString const &set_by_uid, double const mtime) {
  kvs->lock.lock();

  /* If that key already exists, change its value, otherwise create it: */
  // TODO: can_write/del ?
  auto const &[it, inserted] = kvs->map.emplace(
      std::piecewise_construct, std::forward_as_tuple(k),
      std::forward_as_tuple(v, set_by_uid, mtime, false, false));
  if (inserted) {
    kvs->addIncident(k);
  } else {
    it->second.set(v, set_by_uid, mtime);
  }

  {
    // Prepare the ConfChange to be signaled:
    std::lock_guard<std::mutex> guard{kvs->confChangesLock};
    kvs->confChanges.append({KeyChanged, it->first, it->second});
  }

  kvs->lock.unlock();

  return checkDones(*k, *v);
}

int ConfClient::rcvdNewKey(std::shared_ptr<dessser::gen::sync_key::t const> k,
                           std::shared_ptr<dessser::gen::sync_value::t const> v,
                           QString const &set_by_uid, double const mtime,
                           bool const can_write, bool const can_del,
                           QString const &owner, double const expiry) {
  kvs->lock.lock();
  int ret{-1};

  auto const it{
      kvs->map.try_emplace(k, v, set_by_uid, mtime, can_write, can_del)};
  if (it.second) [[likely]] {
    if (!owner.isEmpty()) [[unlikely]]
      it.first->second.setLock(owner, expiry);
    kvs->addIncident(k);
    ret = checkDones(*k, *v);
  } else {
    // Not supposed to happen but harmless
    qCritical() << "NewKey" << *k << "was not new, keeping previous value!";
  }

  {
    // Prepare the ConfChange to be signaled:
    std::lock_guard<std::mutex> guard{kvs->confChangesLock};
    kvs->confChanges.append({KeyCreated, it.first->first, it.first->second});
  }

  kvs->lock.unlock();

  return ret;
}

int ConfClient::rcvdDelKey(std::shared_ptr<dessser::gen::sync_key::t const> k,
                           std::string const &uid) {
  (void)uid;
  kvs->lock.lock();

  auto it{kvs->map.find(k)};
  if (it == kvs->map.end()) {
    // Not supposed to happen but harmless:
    qCritical() << "Cannot delete unbound key" << *k;
  } else {
    std::lock_guard<std::mutex> guard{kvs->confChangesLock};
    kvs->confChanges.append({KeyDeleted, it->first, it->second});
    kvs->map.erase(it);
    kvs->delIncident(k);
  }

  kvs->lock.unlock();

  return 0;
}

int ConfClient::rcvdLockKey(std::shared_ptr<dessser::gen::sync_key::t const> k,
                            QString const &owner, double const expiry) {
  int ret{-1};
  kvs->lock.lock();

  auto const it{kvs->map.find(k)};
  if (it == kvs->map.end()) {
    qCritical() << "Cannot lock unbound key" << *k;
  } else {
    it->second.setLock(owner, expiry);
    std::lock_guard<std::mutex> guard{kvs->confChangesLock};
    kvs->confChanges.append({KeyLocked, it->first, it->second});
    ret = 0;
  }

  kvs->lock.unlock();

  return ret;
}

int ConfClient::rcvdUnlockKey(
    std::shared_ptr<dessser::gen::sync_key::t const> k) {
  int ret{-1};
  kvs->lock.lock();

  auto const it{kvs->map.find(k)};
  if (it == kvs->map.end()) {
    qCritical() << "Cannot unlock unbound key" << *k;
  } else {
    it->second.setUnlock();
    std::lock_guard<std::mutex> guard{kvs->confChangesLock};
    kvs->confChanges.append({KeyUnlocked, it->first, it->second});
    ret = 0;
  }

  kvs->lock.unlock();
  return ret;
}

int ConfClient::sendAuth() {
  if (verbose) qDebug() << "ConfClient::sendAuth";

  std::shared_ptr<dessser::gen::sync_client_cmd::t const> auth{
      std::make_shared<dessser::gen::sync_client_cmd::t const>(
          std::in_place_index<dessser::gen::sync_client_cmd::Auth>,
          username().toStdString(), sessionTimeout)};

  return sendCmd(auth);
}

int ConfClient::sendNew(std::shared_ptr<dessser::gen::sync_key::t const> key,
                        std::shared_ptr<dessser::gen::sync_value::t const> val,
                        double timeout) {
  // Set a placeholder null value by default:
  if (!val)
    val = std::static_pointer_cast<dessser::gen::sync_value::t const>(nullVal);

  if (verbose)
    if (val) qDebug() << "ConfClient::sendNew:" << *key << "=" << *val;

  std::shared_ptr<dessser::gen::sync_client_cmd::t const> cmd{
      std::make_shared<dessser::gen::sync_client_cmd::t const>(
          std::in_place_index<dessser::gen::sync_client_cmd::NewKey>,
          std::const_pointer_cast<dessser::gen::sync_key::t>(key),
          std::const_pointer_cast<dessser::gen::sync_value::t>(val), timeout,
          false /* TODO: also pass recurs */)};

  return sendCmd(cmd);
}

int ConfClient::sendSet(
    std::shared_ptr<dessser::gen::sync_key::t const> key,
    std::shared_ptr<dessser::gen::sync_value::t const> val) {
  if (verbose) qDebug() << "ConfClient::sendSet:" << *key << "=" << *val;

  std::shared_ptr<dessser::gen::sync_client_cmd::t const> cmd{
      std::make_shared<dessser::gen::sync_client_cmd::t const>(
          std::in_place_index<dessser::gen::sync_client_cmd::SetKey>,
          std::const_pointer_cast<dessser::gen::sync_key::t>(key),
          std::const_pointer_cast<dessser::gen::sync_value::t>(val))};

  return sendCmd(cmd);
}

int ConfClient::sendLock(std::shared_ptr<dessser::gen::sync_key::t const> key,
                         double timeout) {
  if (verbose) qDebug() << "ConfClient::sendLock:" << *key;

  std::shared_ptr<dessser::gen::sync_client_cmd::t const> cmd{
      std::make_shared<dessser::gen::sync_client_cmd::t const>(
          std::in_place_index<dessser::gen::sync_client_cmd::LockKey>,
          std::const_pointer_cast<dessser::gen::sync_key::t>(key), timeout,
          false /* TODO: also pass recurs */)};

  return sendCmd(cmd);
}

int ConfClient::sendUnlock(
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  if (verbose) qDebug() << "ConfClient::sendUnlock:" << *key;

  std::shared_ptr<dessser::gen::sync_client_cmd::t const> cmd{
      std::make_shared<dessser::gen::sync_client_cmd::t const>(
          std::in_place_index<dessser::gen::sync_client_cmd::UnlockKey>,
          std::const_pointer_cast<dessser::gen::sync_key::t>(key))};

  return sendCmd(cmd);
}

int ConfClient::sendDel(std::shared_ptr<dessser::gen::sync_key::t const> key) {
  if (verbose) qDebug() << "ConfClient::sendDel:" << *key;

  std::shared_ptr<dessser::gen::sync_client_cmd::t const> cmd{
      std::make_shared<dessser::gen::sync_client_cmd::t const>(
          std::in_place_index<dessser::gen::sync_client_cmd::DelKey>,
          std::const_pointer_cast<dessser::gen::sync_key::t>(key))};

  return sendCmd(cmd);
}

int ConfClient::sendCmd(
    std::shared_ptr<dessser::gen::sync_client_cmd::t const> cmd,
    std::optional<std::function<int(std::string const &)> > onDone, bool echo) {
  dessser::gen::sync_client_msg::t_ext msg{
      std::make_shared<dessser::gen::sync_client_msg::t>(
          seq, onDone.has_value(), echo,
          std::const_pointer_cast<dessser::gen::sync_client_cmd::t>(cmd))};

  if (onDone.has_value()) {
    onDoneCallbacks.emplace_back(seq, *onDone);
    // TODO: timeout old callbacks
    if (onDoneCallbacks.size() > 10)
      qWarning() << "onDoneCallbacks:" << onDoneCallbacks.size() << "entries";
  }

  seq++;

  int const err{sendMsg(msg)};
  if (!err) lastSent = QDateTime::currentMSecsSinceEpoch();
  return err;
}

int ConfClient::sendMsg(
    std::shared_ptr<dessser::gen::sync_client_msg::t const> msg) {
  /*
   * Serialize
   *
   * FIXME: Because of how generic the authn wrapper is we have to serialize
   * in two steps: first the message then the wrapper with the message as an
   * embedded byte string. It would be worthwhile to have the wrapper accept
   * a sum type for client or server message (wasting some bytes), or move both
   * client and server messages under the same sum type.
   */
  size_t const ser_sz{dessser::gen::sync_client_msg::sersize_of_row_binary(
      std::const_pointer_cast<dessser::gen::sync_client_msg::t>(msg))};
  dessser::Pointer ptr{ser_sz};
  dessser::Pointer const end{dessser::gen::sync_client_msg::to_row_binary(
      std::const_pointer_cast<dessser::gen::sync_client_msg::t>(msg), ptr)};
  size_t const act_sz{end.getOffset()};

  if (act_sz > ser_sz) {
    qCritical().nospace() << "Failed to serialize message " << *msg
                          << ": actual size (" << act_sz
                          << ") is larger than expected (" << ser_sz << ")";
    return -1;
  }

  qDebug().nospace() << "Sending: " << *msg << " (" << ser_sz << " bytes)";

  /* Second serialization: Wrap the message into an Authn message */
  dessser::Bytes const text{std::get<0>(ptr.readBytes(act_sz))};
  dessser::gen::sync_msg::t_ext auth;
  /* Prepare all the buffers that may appear in the sent message: */
  size_t text_len{text.length()};
  /* clear_text must have some zeros header:
   * "crypto_box() takes a pointer to 32 bytes before the message, and stores
   *  the ciphertext 16 bytes after the destination pointer, the first 16 bytes
   * being overwritten with zeros. crypto_box_open() takes a pointer to 16
   * bytes before the ciphertext and stores the message 32 bytes after the
   * destination pointer, overwriting the first 32 bytes with zeros." So long
   * for NaCl being misuse-resistant. */
  Q_ASSERT(crypto_box_ZEROBYTES == 32 && crypto_box_BOXZEROBYTES == 16);
  unsigned char clear_text[crypto_box_ZEROBYTES + text_len];
  /* Size for cipher_text is not crypto_box_BOXZEROBYTES + text_len, as there
   * will be 16 zeros + MAC (16 bytes) + encrypted. */
  unsigned char cipher_text[sizeof clear_text];

  if (isCrypted()) {
    /* Encrypt using server public key and that nonce: */
    if (verbose) qDebug() << "Encrypting" << text_len << "bytes";
    bzero(clear_text, crypto_box_ZEROBYTES);
    memcpy(clear_text + crypto_box_ZEROBYTES,
           reinterpret_cast<unsigned char const *>(text.toString().c_str()),
           text_len);
    if (crypto_box(cipher_text, clear_text, crypto_box_ZEROBYTES + text_len,
                   clt_nonce, srv_pub_key, clt_priv_key) < 0) {
      qCritical() << "Cannot encrypt message";
      return -1;
    }
    dessser::Bytes const send_msg{
        std::shared_ptr<uint8_t[]>(
            reinterpret_cast<uint8_t *>(cipher_text + crypto_box_BOXZEROBYTES),
            /* Do not delete for real: */ [](uint8_t *) {}),
        sizeof cipher_text - crypto_box_BOXZEROBYTES, size_t(0)};
    if (keySent) {  // encrypt
      auth = std::make_shared<dessser::gen::sync_msg::t>(
          std::in_place_index<dessser::gen::sync_msg::Crypted>, send_msg);
    } else {
      dessser::Bytes const send_nonce{
          std::shared_ptr<uint8_t[]>(reinterpret_cast<uint8_t *>(clt_nonce),
                                     [](uint8_t *) {}),
          sizeof(clt_nonce), size_t(0)};
      dessser::Bytes const send_clt_pub_key{
          std::shared_ptr<uint8_t[]>(reinterpret_cast<uint8_t *>(clt_pub_key),
                                     [](uint8_t *) {}),
          sizeof(clt_pub_key), size_t(0)};
      auth = std::make_shared<dessser::gen::sync_msg::t>(
          std::in_place_index<dessser::gen::sync_msg::SendSessionKey>,
          send_nonce, send_clt_pub_key, send_msg);
      keySent = true;
    }
  } else {
    auth = std::make_shared<dessser::gen::sync_msg::t>(
        std::in_place_index<dessser::gen::sync_msg::ClearText>, text);
  }

  Q_ASSERT(!auth->valueless_by_exception());
  size_t const auth_ser_sz{dessser::gen::sync_msg::sersize_of_row_binary(auth)};
  dessser::Pointer auth_ptr{auth_ser_sz};
  dessser::Pointer const auth_end{
      dessser::gen::sync_msg::to_row_binary(auth, auth_ptr)};
  size_t const auth_act_sz{auth_end.getOffset()};

  if (auth_act_sz > auth_ser_sz) {
    qCritical().nospace() << "Failed to serialize Authentified message "
                          << *auth << ": actual size (" << auth_act_sz
                          << ") is larger than expected (" << auth_ser_sz
                          << ")";
    return -1;
  }

  // Prepend the length and send:
  // FIXME: This assumes little endian
  uint32_t const lenPrefix{(uint32_t)auth_act_sz};
  // Note: A TcpSocket buffers internally and never short writes
  if (0 != sendBytes(reinterpret_cast<char const *>(&lenPrefix), 4) ||
      0 != sendBytes(reinterpret_cast<char const *>(auth_ptr.buffer.get()),
                     auth_act_sz))
    return -1;

  // If we have used the nonce, increment it (*AFTER* it's serialized!)
  if (isCrypted()) sodium_increment_rev(clt_nonce, sizeof clt_nonce);

  sentMsgs++;

  return 0;
}

void ConfClient::keepAlive() {
  qint64 const now{QDateTime::currentMSecsSinceEpoch()};

  if (now - lastSent > 1000. * 0.7 * sessionTimeout) sendSet(devNull, nullVal);
}

bool ConfClient::isCrypted() const { return id && !id->srv_pub_key.isEmpty(); }

bool ConfClient::isSynced() const {
  return syncStatus == SyncStatus::Synchronized ||
         syncStatus == SyncStatus::Closing;
}

QString const ConfClient::username() const {
  if (isCrypted()) {
    return id->username;
  } else {
    return clearUsername;
  }
}

int ConfClient::sendBytes(char const *bytes, size_t sz) {
  qint64 const written{tcpSocket->write(bytes, sz)};
  if (written < 0) {
    qCritical() << "Could not write" << sz << "bytes to confserver";
    return -1;
  }
  Q_ASSERT(written == (qint64)sz);

  sentBytes += written;

  return 0;
}

int ConfClient::checkDones(dessser::gen::sync_key::t const &k,
                           dessser::gen::sync_value::t const &v) {
  if (!myErrKey || k != *myErrKey) return 0;

  if (v.index() != dessser::gen::sync_value::Error) {
    qCritical() << "Not an error value in" << k;
    return -1;
  }
  auto const err{std::get<dessser::gen::sync_value::Error>(v)};
  uint32_t const err_seq{std::get<1>(err)};
  std::string const &err_msg{std::get<2>(err)};

  for (auto it = onDoneCallbacks.begin(); it != onDoneCallbacks.end(); it++) {
    if (it->seq != err_seq) continue;

    qDebug() << "onDone callback found for" << err_seq;
    int const ret{it->callback(err_msg)};
    onDoneCallbacks.erase(it);
    return ret;
  }

  qDebug() << "No callback was found for" << err_seq;
  return 0;
}
