#include <cstdlib>
#include <memory>
#include <sstream>
#include <QDebug>
#include <QTcpSocket>
#include <QtGlobal>

#include <dessser/Pointer.h>
#include <dessser/Bytes.h>

#include "desssergen/sync_server_msg.h"
#include "desssergen/sync_client_msg.h"
#include "desssergen/sync_msg.h"
#include "ConfClient.h"
#include "UserIdentity.h"

void ConfClient::fatalErr(QString const &errString)
{
  // Emit the signal with the status we were in before the error occurred:
  emit connectionFatalError(syncStatus, errString);
  syncStatus = SyncStatus::Failed;
  qDebug().nospace() << "ConfClient::fatalErr(" << errString << ")!";
}

#include "ConfClientTools.cpp"

ConfClient::ConfClient(QString const &target, QString const &username_, std::shared_ptr<UserIdentity const> id_, std::shared_ptr<KVStore> kvs_)
  : kvs(kvs_),
    tcpSocket(new QTcpSocket(this)),
    syncStatus(SyncStatus::Disconnected),
    username(username_),
    id(id_)
{
  connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred),
          this, &ConfClient::onTcpError);
  connect(tcpSocket, &QAbstractSocket::stateChanged,
          this, &ConfClient::onStateChange);
  connect(tcpSocket, &QIODevice::readyRead, this, &ConfClient::readMsg);

  QString host;
  quint16 port;
  if (0 != parseUrl(host, port, target)) {
    fatalErr("Cannot parse configuration server URL: " + target);
  } else {
    tcpSocket->connectToHost(host, port);
  }
}

void ConfClient::onTcpError(QAbstractSocket::SocketError err)
{
  // In any case, signal the error:
  QString errString { tcpSocket->errorString() };
  bool isFatal { true };

  switch (err) {
    case QAbstractSocket::UnfinishedSocketOperationError:
      // Should not happen
      qDebug("ConfClient::onTcpError(UnfinishedSocketOperationError)?!");
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

void ConfClient::onStateChange(QAbstractSocket::SocketState sockState)
{
  SyncStatus oldStage = syncStatus;

  switch (sockState) {
    case QAbstractSocket::UnconnectedState:
      syncStatus = SyncStatus::Resolving;
      break;
    case QAbstractSocket::HostLookupState:
      syncStatus = SyncStatus::Resolving;
      break;
    case QAbstractSocket::ConnectingState:
      syncStatus = SyncStatus::Connecting;
      break;
    case QAbstractSocket::ConnectedState:
      if (0 == sendAuth())
        syncStatus = SyncStatus::Authenticating;
      break;
    case QAbstractSocket::BoundState:
      // Should not happen on a client
      qWarning() << "ConfClient received stateChanged to BoundState!?";
      break;
    case QAbstractSocket::ClosingState:
      syncStatus = SyncStatus::Closing;
      break;
    case QAbstractSocket::ListeningState:
      // Should not happen at all
      qWarning() << "ConfClient received stateChanged to ListeningState!?";
      break;
  }

  if (syncStatus != oldStage) {
    qDebug() << "ConfClient::onStateChange(" << sockState << ")";
    emit connectionProgressed(syncStatus);
  }
}

void ConfClient::readMsg()
{
  if (syncStatus == SyncStatus::Failed) return;
  if (syncStatus != SyncStatus::Authenticating &&
      syncStatus != SyncStatus::Synchronizing &&
      syncStatus != SyncStatus::Synchronized)
    qWarning() << "Received data while in syncStatus " << syncStatus;

  // Check we can read the message size:
  qint64 avail_sz { tcpSocket->bytesAvailable() };
  Q_ASSERT(avail_sz >= 0);

  do {
    if (avail_sz < 2) {
      qDebug() << "Only" << avail_sz << "bytes available to read, will wait.";
      break;
    }

    // read the message size:
    unsigned char prefix[2];
    qint64 peeked { tcpSocket->peek((char *)prefix, 2) };
    Q_ASSERT(peeked == 2);

    // Prefix is little endian:
    size_t msg_sz { ((size_t)prefix[1] << 8U) | prefix[0] };
    // Sanity check:
    if (msg_sz > 500000U) {  // Nope
      qWarning() << "Received a message pretending to be " << msg_sz
                 << " bytes long, quitting.";
cannot_decode:
      emit connectionFatalError(syncStatus, QString("Cannot decode configuration message"));
      syncStatus = SyncStatus::Failed;
      break;
    }

    // Do not read until the whole message is there:
    if ((size_t)avail_sz < 2 + msg_sz) {
      qDebug() << "Have to wait for" << (2 + msg_sz) - avail_sz << "more bytes.";
      break;
    }

    // Alloc the message...
    std::shared_ptr<uint8_t> msg { (uint8_t *)std::malloc(msg_sz) };
    if (! msg) {
      qWarning() << "Cannot alloc " << 2 + msg_sz << "bytes!";
      emit connectionFatalError(syncStatus, QString("Cannot allocate memory"));
      syncStatus = SyncStatus::Failed;
      break;
    }

    // ...and read it, skipping the prefix:
    qint64 const skip_sz { tcpSocket->skip(2) };
    Q_ASSERT(skip_sz == 2);
    qint64 const read_sz { tcpSocket->read((char *)msg.get(), msg_sz) };
    Q_ASSERT((size_t)read_sz == msg_sz);
    avail_sz -= skip_sz + read_sz;

    // Parse it:
    dessser::Pointer in_ptr { msg, msg_sz };
    auto t_ptr { dessser::gen::sync_msg::of_row_binary(in_ptr) };
    size_t const dec_sz { std::get<1>(t_ptr).offset };
    if (dec_sz < msg_sz) {
      qWarning() << "Cannot decode configuration message: consumed only"
                 << dec_sz << "bytes out of" << msg_sz;
      goto cannot_decode;
    }
    std::shared_ptr<dessser::gen::sync_msg::t> auth { std::get<0>(t_ptr) };

    switch ((dessser::gen::sync_msg::Constr_t)auth->index()) {
      case dessser::gen::sync_msg::SendSessionKey:
        qDebug() << "TODO: Received session keys";
        break;
      case dessser::gen::sync_msg::Crypted:
        qDebug() << "TODO: decrypting";
        break;
      case dessser::gen::sync_msg::ClearText:
        {
          dessser::Bytes const msg { std::get<dessser::gen::sync_msg::ClearText>(*auth) };
          if (0 != readSrvMsg(msg)) goto cannot_decode;
        }
        break;
      case dessser::gen::sync_msg::Error:
        {
          QString errMsg {
            QString::fromStdString(std::get<dessser::gen::sync_msg::Error>(*auth)) };
          qCritical() << "Error from confserver:" << errMsg;
          emit connectionNonFatalError(syncStatus, errMsg);
        }
        break;
      default:
        qCritical() << "Invalid auth message type";
        goto cannot_decode;
    }

  } while (avail_sz > 0);
}

int ConfClient::startSynchronization()
{
  /* Subscribe to all keys for now: */
  dessser::gen::sync_client_cmd::t const start_sync {
    std::in_place_index<dessser::gen::sync_client_cmd::StartSync>,
    std::string("*") };

  return sendCmd(start_sync);
}

int ConfClient::readSrvMsg(dessser::Bytes const &bytes)
{
  dessser::Pointer in_ptr { bytes };
  auto t_ptr { dessser::gen::sync_server_msg::of_row_binary(in_ptr) };
  size_t const dec_sz { std::get<1>(t_ptr).offset };
  if (dec_sz < bytes.length()) {
    qWarning() << "Cannot decode configuration clear text message: consumed only"
               << dec_sz << "bytes out of" << bytes.length();
    return -1;
  }

  std::shared_ptr<dessser::gen::sync_server_msg::t> msg { std::get<0>(t_ptr) };
  qDebug() << "Received:" << *msg;

  switch ((dessser::gen::sync_server_msg::Constr_t)msg->index()) {
    case dessser::gen::sync_server_msg::AuthOk:
      {
        std::shared_ptr<dessser::gen::sync_socket::t const> sync_socket {
          std::get<dessser::gen::sync_server_msg::AuthOk>(*msg) };
        return recvdAuthOk(sync_socket);
      }
    case dessser::gen::sync_server_msg::AuthErr:
      {
        std::string const err { std::get<dessser::gen::sync_server_msg::AuthErr>(*msg) };
        return recvdAuthErr(QString::fromStdString(err));
      }
    case dessser::gen::sync_server_msg::SetKey:
      {
        auto const &set_key { std::get<dessser::gen::sync_server_msg::SetKey>(*msg) };
        std::shared_ptr<dessser::gen::sync_key::t const> k { set_key.SetKey_k };
        std::shared_ptr<dessser::gen::sync_value::t const> v { set_key.SetKey_v };
        return recvdSetKey(k, v, QString::fromStdString(set_key.SetKey_uid),
                           set_key.SetKey_mtime);
      }
    case dessser::gen::sync_server_msg::NewKey:
      {
        auto const &new_key { std::get<dessser::gen::sync_server_msg::NewKey>(*msg) };
        std::shared_ptr<dessser::gen::sync_key::t const> k { new_key.NewKey_k };
        std::shared_ptr<dessser::gen::sync_value::t const> v { new_key.v };
        return recvdNewKey(k, v, QString::fromStdString(new_key.uid), new_key.mtime,
                           new_key.can_write, new_key.can_del,
                           QString::fromStdString(new_key.NewKey_owner),
                           new_key.NewKey_expiry);
      }
    case dessser::gen::sync_server_msg::DelKey:
      {
        std::shared_ptr<dessser::gen::sync_key::t const> k {
          std::get<dessser::gen::sync_server_msg::DelKey>(*msg) };
        return recvdDelKey(k);
      }
    case dessser::gen::sync_server_msg::LockKey:
      {
        auto const &lock { std::get<dessser::gen::sync_server_msg::LockKey>(*msg) };
        std::shared_ptr<dessser::gen::sync_key::t const> k { lock.k };
        return recvdLockKey(k, QString::fromStdString(lock.owner), lock.expiry);
      }
    case dessser::gen::sync_server_msg::UnlockKey:
      {
        std::shared_ptr<dessser::gen::sync_key::t const> k {
          std::get<dessser::gen::sync_server_msg::UnlockKey>(*msg) };
        return recvdUnlockKey(k);
      }
    default:
      qCritical() << "Invalid sync_server_msg type";
      return -1;
  }

  return -1;
}

int ConfClient::recvdAuthErr(QString const &err)
{
  fatalErr(err);
  return 0;
}

int ConfClient::recvdAuthOk(std::shared_ptr<dessser::gen::sync_socket::t const> sync_socket)
{
  syncSocket = sync_socket;
  return startSynchronization();
}

int ConfClient::recvdSetKey(
      std::shared_ptr<dessser::gen::sync_key::t const> k,
      std::shared_ptr<dessser::gen::sync_value::t const> v,
      QString const &set_by_uid,
      double const mtime)
{
  qDebug() << *k << "<-" << *v << "set by" << set_by_uid << "at" << mtime;
  // TODO, let's pretend for now.
  return 0;
}

int ConfClient::recvdNewKey(
      std::shared_ptr<dessser::gen::sync_key::t const> k,
      std::shared_ptr<dessser::gen::sync_value::t const> v,
      QString const &set_by_uid,
      double const mtime,
      bool const can_write, bool const can_del,
      QString const &owner,
      double const expiry)
{
  qDebug() << *k << "<-" << *v << "set by" << set_by_uid << "at" << mtime
           << "owned by" << owner << "expiring at" << expiry
           << "can_write" << can_write << "can_del" << can_del;
  return 0;
}

int ConfClient::recvdDelKey(std::shared_ptr<dessser::gen::sync_key::t const> k)
{
  qDebug() << "del" << *k;
  return 0;
}

int ConfClient::recvdLockKey(
      std::shared_ptr<dessser::gen::sync_key::t const> k, QString const &owner,
      double const expiry)
{
  qDebug() << "lock" << *k << "owned by" << owner << "expiring at" << expiry;
  return 0;
}

int ConfClient::recvdUnlockKey(std::shared_ptr<dessser::gen::sync_key::t const> k)
{
  qDebug() << "unlock" << *k;
  return 0;
}

int ConfClient::sendAuth()
{
  double const sessionTimeout { 300. };
  dessser::gen::sync_client_cmd::t const auth {
    std::in_place_index<dessser::gen::sync_client_cmd::Auth>,
    id->username.toStdString(),
    sessionTimeout };

  return sendCmd(auth);
}

int ConfClient::sendCmd(
      dessser::gen::sync_client_cmd::t const &cmd,
      bool confirm_success,
      bool echo)
{
  dessser::gen::sync_client_msg::t msg {
    .cmd = const_cast<dessser::gen::sync_client_cmd::t *>(&cmd),
    .confirm_success = confirm_success,
    .echo = echo,
    .seq = seq++ };

  return sendMsg(msg);
}

int ConfClient::sendMsg(dessser::gen::sync_client_msg::t const &msg)
{
  /*
   * Serialize
   *
   * FIXME: Because of how generic the authn wrapper is we have to serialize
   * in two steps: first the message then the wrapper with the message as an
   * embedded byte string. It would be worthwhile to have the wrapper accept
   * a sum type for client or server message (wasting some bytes), or move both
   * client and server messages under the same sum type.
   */
  dessser::gen::sync_client_msg::t *msg_ {
    const_cast<dessser::gen::sync_client_msg::t *>(&msg) };
  size_t const ser_sz { dessser::gen::sync_client_msg::sersize_of_row_binary(msg_) };
  dessser::Pointer ptr { ser_sz };
  dessser::Pointer const end { dessser::gen::sync_client_msg::to_row_binary(msg_, ptr) };
  size_t const act_sz { end.getOffset() };

  if (act_sz > ser_sz) {
    qCritical().nospace()
      << "Failed to serialize message " << msg
      << ": actual size (" << act_sz
      << ") is larger than expected (" << ser_sz << ")";
    return -1;
  }

  qDebug().nospace() << "Sending:" << msg << " (" << ser_sz << " bytes)";

  /* Second serialization: Wrap the message into an Authn message
   * TODO: non ClearText */
  dessser::Bytes clearText { std::get<0>(ptr.readBytes(act_sz)) };
  dessser::gen::sync_msg::t auth {
    std::in_place_index<dessser::gen::sync_msg::ClearText>,
    clearText };

  dessser::gen::sync_msg::t *auth_ { const_cast<dessser::gen::sync_msg::t *>(&auth) };
  size_t const auth_ser_sz { dessser::gen::sync_msg::sersize_of_row_binary(auth_) };
  dessser::Pointer auth_ptr { auth_ser_sz };
  dessser::Pointer const auth_end { dessser::gen::sync_msg::to_row_binary(auth_, auth_ptr) };
  size_t const auth_act_sz { auth_end.getOffset() };

  if (auth_act_sz > auth_ser_sz) {
    qCritical().nospace()
      << "Failed to serialize Authentified message " << auth
      << ": actual size (" << auth_act_sz
      << ") is larger than expected (" << auth_ser_sz << ")";
    return -1;
  }

  // Prepend the length and send:
  // FIXME: This assumes little endian
  uint16_t lenPrefix = auth_act_sz;
  // Note: A TcpSocket buffers internally and never short writes
  if (0 == sendBytes(reinterpret_cast<char const *>(&lenPrefix), 2) &&
      0 == sendBytes(reinterpret_cast<char const *>(auth_ptr.buffer.get()), auth_act_sz))
    return 0;

  return -1;
}

int ConfClient::sendBytes(char const *bytes, size_t sz)
{
  qint64 const written { tcpSocket->write(bytes, sz) };
  if (written < 0) {
    qCritical() << "Could not write" << sz << "bytes to confserver";
    return -1;
  }
  Q_ASSERT(written == (qint64)sz);

  return 0;
}

/* Generic qDebug printer using stringstream: */
template<typename T>
QDebug printerOfStream(QDebug debug, T const &t)
{
  QDebugStateSaver saver(debug);
  std::ostringstream s;
  s << t;
  debug << QString::fromStdString(s.str());
  return debug;
}

QDebug operator<<(QDebug debug, dessser::gen::sync_client_cmd::t const &cmd)
{
  return printerOfStream<dessser::gen::sync_client_cmd::t>(debug, cmd);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_client_msg::t const &msg)
{
  return printerOfStream<dessser::gen::sync_client_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_server_msg::t const &msg)
{
  return printerOfStream<dessser::gen::sync_server_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_msg::t const &msg)
{
  return printerOfStream<dessser::gen::sync_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_socket::t const &msg)
{
  return printerOfStream<dessser::gen::sync_socket::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_key::t const &msg)
{
  return printerOfStream<dessser::gen::sync_key::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_value::t const &msg)
{
  return printerOfStream<dessser::gen::sync_value::t>(debug, msg);
}
