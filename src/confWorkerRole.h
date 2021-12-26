// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef CONFWORKERROLE_H_190618
#define CONFWORKERROLE_H_190618
#include <QString>
extern "C" {
#include <caml/mlvalues.h>
// Defined by OCaml mlvalues but conflicting with further Qt includes:
#undef alloc
#undef flush
}

namespace conf {

struct WorkerRole {
  bool isTopHalf;
  WorkerRole(bool isTopHalf_) : isTopHalf(isTopHalf_) {}

  static WorkerRole *ofOCamlValue(value);
  QString const toQString() const;
};

};  // namespace conf

#endif
