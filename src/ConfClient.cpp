#include <cstdlib>
#include <memory>
#include <QDebug>
#include <QTcpSocket>
#include <QtGlobal>

#include <dessser/Pointer.h>

#include "desssergen/sync_server_msg.h"
#include "ConfClient.h"
#include "UserIdentity.h"

void ConfClient::fatalErr(QString const &errString)
{
  // Emit the signal with the status we were in before the error occurred:
  emit connectionFatalError(syncStatus, errString);
  syncStatus = SyncStatus::Failed;
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
  connect(tcpSocket, &QIODevice::readyRead, this, &ConfClient::onDataReady);

  QString host;
  quint16 port;
  if (0 != parseUrl(host, port, target)) {
    fatalErr("Cannot parse configuration server URL: " + target);
  } else {
    tcpSocket->connectToHost(host, port);
  }
  (void)username;
  (void)id;
}

void ConfClient::onTcpError(QAbstractSocket::SocketError err)
{
  // In any case, signal the error:
  QString errString { tcpSocket->errorString() };
  bool isFatal { true };

  switch (err) {
    case QAbstractSocket::UnfinishedSocketOperationError:
      // Should not happen
      // pass
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
      syncStatus = SyncStatus::Authenticating;
      // TODO: actually do it
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

  if (syncStatus != oldStage) emit connectionProgressed(syncStatus);
}

void ConfClient::onDataReady()
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
      qDebug() << "Only " << avail_sz << " bytes available to read, will wait.";
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
      qDebug() << "Have to wait for " << (2 + msg_sz) - avail_sz
               << " more bytes.";
      break;
    }

    // Alloc the message...
    std::shared_ptr<char> msg { (char *)std::malloc(msg_sz) };
    if (! msg) {
      qWarning() << "Cannot alloc " << 2 + msg_sz << "bytes!";
      emit connectionFatalError(syncStatus, QString("Cannot allocate memory"));
      syncStatus = SyncStatus::Failed;
      break;
    }

    // ...and read it, skipping the prefix:
    qint64 const skip_sz { tcpSocket->skip(2) };
    Q_ASSERT(skip_sz == 2);
    qint64 const read_sz { tcpSocket->read(msg.get(), msg_sz) };
    Q_ASSERT((size_t)read_sz == msg_sz);
    avail_sz -= skip_sz + read_sz;

    // Now for the real meat: parse it!
    dessser::Pointer in_ptr { msg };
    auto t_ptr { dessser::gen::sync_server_msg::of_row_binary(in_ptr) };
    size_t const dec_sz { std::get<1>(t_ptr).offset };
    if (dec_sz < msg_sz) {
      qWarning() << "Cannot decode configuration message: consumed only "
                 << dec_sz << " bytes out of " << msg_sz;
      goto cannot_decode;
    }
    qDebug() << "TODO: execute that command";

  } while (avail_sz > 0);
}
