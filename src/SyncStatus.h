#ifndef SYNCSTATUS_H_20190503
#define SYNCSTATUS_H_20190503
#include <string>
#include <optional>
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

  void set(Status);

  Status get() const {
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
  Status status;

  std::string errMsg;

  std::optional<Status> prevStatus; // Previous status
  std::optional<qint64> lastChange; // Timestamp (ms) when the status was changed last
  std::optional<qint64> lastDuration; // Duration between the last two status changes
};

QDebug operator<<(QDebug, SyncStatus const &);

Q_DECLARE_METATYPE(SyncStatus);

#endif
