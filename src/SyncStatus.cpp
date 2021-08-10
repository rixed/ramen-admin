#include <cassert>
#include "SyncStatus.h"

SyncStatus::SyncStatus(enum Status status_) : status(status_)
{
}

SyncStatus::~SyncStatus()
{
}

QString SyncStatus::message() const
{
  switch(status) {
    case Undef:
      return QCoreApplication::translate("QMainWindow", "undefined");
    case Resolving:
      return QCoreApplication::translate("QMainWindow", "Resolving...");
    case Connecting:
      return QCoreApplication::translate("QMainWindow", "Connecting...");
    case Authenticating:
      return QCoreApplication::translate("QMainWindow", "Authenticating...");
    case Synchronizing:
      return QCoreApplication::translate("QMainWindow", "Synchronizing...");
    case Synchronized:
      return QCoreApplication::translate("QMainWindow", "Synchronized.");
    case Closing:
      return QCoreApplication::translate("QMainWindow", "Closing...");
    case Failed:
      return QCoreApplication::translate("QMainWindow", "Failed: ").
             append(msg.c_str());
  }
  assert(!"Invalid sync status");
}

QDebug operator<<(QDebug debug, SyncStatus const &s)
{
  QDebugStateSaver saver(debug);
  debug.nospace() << s.message();
  return debug;
}
