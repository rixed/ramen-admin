#ifndef SYNCSTATUS_H_20190503
#define SYNCSTATUS_H_20190503
#include <string>
#include <QDebug>
#include <QtWidgets>

struct SyncStatus {
  enum Status {
    Disconnected,
    Resolving,
    Connecting,
    Authenticating,
    Synchronizing,
    Synchronized,
    Closing,
    Failed
  };

  SyncStatus(Status = Disconnected);
  ~SyncStatus();

  void set(enum Status);

  enum Status get() const {
    return status;
  }

  QString message() const;

  bool operator==(SyncStatus const &other) const {
    return status == other.status;
  }
  bool operator!=(SyncStatus const &other) const {
    return status != other.status;
  }

private:
  enum Status status;

  std::string errMsg;

  qint64 lastChange; // Timestamp (ms) when the status was changed last
  QString lastDuration;
};

QDebug operator<<(QDebug, SyncStatus const &);

Q_DECLARE_METATYPE(SyncStatus);

#endif
