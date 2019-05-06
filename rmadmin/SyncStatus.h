#ifndef SYNCSTATUS_H_20190503
#define SYNCSTATUS_H_20190503
#include <string>
#include <QtWidgets>
extern "C" {
#  include <caml/mlvalues.h>
}

struct SyncStatus {
  SyncStatus();
  SyncStatus(value s_);
  ~SyncStatus();
  QString message();

private:
  enum Status {
    Undef, InitStart, InitOk, InitFail, Ok, Fail
  } status;
  std::string msg;
};
#endif
