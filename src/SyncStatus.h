#ifndef SYNCSTATUS_H_20190503
#define SYNCSTATUS_H_20190503
#include <string>
#include <QDebug>
#include <QtWidgets>

class SyncStatus {
  std::string msg;

public:
  enum Status {
    Disconnected,
    Resolving,
    Connecting,
    Authenticating,
    Synchronizing,
    Synchronized,
    Closing,
    Failed
  } status;

  SyncStatus(Status = Disconnected);
  ~SyncStatus();

  QString message() const;

  bool operator==(SyncStatus const &other) const {
    return status == other.status;
  }
  bool operator!=(SyncStatus const &other) const {
    return status != other.status;
  }
};

QDebug operator<<(QDebug, SyncStatus const &);

Q_DECLARE_METATYPE(SyncStatus);

#endif
