#include <cassert>
#include <QDateTime>

#include "misc.h"
#include "SyncStatus.h"

SyncStatus::SyncStatus(enum Status status_)
  : status(status_), lastChange(0L)
{
}

SyncStatus::~SyncStatus()
{
}

void SyncStatus::set(enum Status new_status) {
  status = new_status;

  qint64 const now { QDateTime::currentMSecsSinceEpoch() };

  if (lastChange > 0L) {
    lastDuration = stringOfDuration((double)(now - lastChange) / 1000);
  }
  lastChange = now;
}

QString SyncStatus::message() const
{
  switch(status) {
    case Disconnected:
      return QCoreApplication::translate("QMainWindow", "Disconnected");
    case Resolving:
      return QCoreApplication::translate("QMainWindow", "Resolving...");
    case Connecting:
      return QCoreApplication::translate("QMainWindow", "Connecting...");
    case Authenticating:
      return QCoreApplication::translate("QMainWindow", "Authenticating...");
    case Synchronizing:
      return QCoreApplication::translate("QMainWindow", "Synchronizing...");
    case Synchronized:
      return QCoreApplication::translate("QMainWindow", "Synchronized in %1.").
             arg(lastDuration);
    case Closing:
      return QCoreApplication::translate("QMainWindow", "Closing...");
    case Failed:
      return QCoreApplication::translate("QMainWindow", "Failed: ").
             append(errMsg.c_str());
  }
  assert(!"Invalid sync status");
}

QDebug operator<<(QDebug debug, SyncStatus const &s)
{
  QDebugStateSaver saver(debug);
  debug.nospace() << s.message();
  return debug;
}
