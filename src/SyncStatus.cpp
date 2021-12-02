#include <cassert>
#include <QDateTime>

#include "misc.h"
#include "SyncStatus.h"

SyncStatus::SyncStatus(Status status_)
  : status(status_)
{
}

SyncStatus::~SyncStatus()
{
}

void SyncStatus::set(Status new_status) {
  prevStatus = status;
  status = new_status;

  qint64 const now { QDateTime::currentMSecsSinceEpoch() };
  if (lastChange) lastDuration = now - *lastChange;
  lastChange = now;
}

QString SyncStatus::message() const
{
  QString curr;
  switch (status) {
    case Disconnected:
      curr = QCoreApplication::translate("QMainWindow", "Disconnected.");
      break;
    case Resolving:
      curr = QCoreApplication::translate("QMainWindow", "Resolving...");
      break;
    case Connecting:
      curr = QCoreApplication::translate("QMainWindow", "Connecting...");
      break;
    case Authenticating:
      curr = QCoreApplication::translate("QMainWindow", "Authenticating...");
      break;
    case Synchronizing:
      curr = QCoreApplication::translate("QMainWindow", "Synchronizing...");
      break;
    case Synchronized:
      curr = QCoreApplication::translate("QMainWindow", "Done!");
      break;
    case Closing:
      curr = QCoreApplication::translate("QMainWindow", "Closing...");
      break;
    case Failed:
      curr = QCoreApplication::translate("QMainWindow", "Failed: ").
             append(errMsg.c_str());
      break;
    default:
      Q_ASSERT(false);
  }

  if (lastDuration && prevStatus) {
    QString const duration { stringOfDuration((double)*lastDuration / 1000) };

    if (*prevStatus == status) {
      return QCoreApplication::translate("QMainWindow", "Retrying after %1: %2").
             arg(duration).arg(curr);
    } else {
      switch (*prevStatus) {
        case Disconnected:
          return curr;
        case Resolving:
          return QCoreApplication::translate("QMainWindow", "Resolved in %1, %2").
                 arg(duration).arg(curr);
        case Connecting:
          return QCoreApplication::translate("QMainWindow", "Connected in %1, %2").
                 arg(duration).arg(curr);
        case Authenticating:
          return QCoreApplication::translate("QMainWindow", "Authenticated in %1, %2").
                 arg(duration).arg(curr);
        case Synchronizing:
          return QCoreApplication::translate("QMainWindow", "Synchronized in %1, %2").
                 arg(duration).arg(curr);
        case Synchronized:
          return curr;
        case Closing:
          return QCoreApplication::translate("QMainWindow", "Closed in %1, %2").
                 arg(duration).arg(curr);
        case Failed:
          return curr;
      }
    }
  }

  return curr;
}

QDebug operator<<(QDebug debug, SyncStatus const &s)
{
  QDebugStateSaver saver(debug);
  debug.nospace() << s.message();
  return debug;
}
