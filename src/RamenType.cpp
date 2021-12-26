// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include <QString>
extern "C" {
#include <caml/alloc.h>
#include <caml/custom.h>
#include <caml/memory.h>
// Defined by OCaml mlvalues but conflicting with further Qt includes:
#undef alloc
#undef flush
}
#include "RamenType.h"
#include "RamenValue.h"

value RamenType::toOCamlValue() const {
  Q_ASSERT(!"Don't know how to convert from a RamenType");
}

RamenValue* RamenType::valueOfQString(QString const s) const {
  if (s.length() == 0 && nullable) return new VNull;
  return vtyp->valueOfQString(s);
}

// Does not alloc on OCaml heap
RamenType::RamenType(value v_) {
  Q_ASSERT(Is_block(v_));
  Q_ASSERT(Wosize_val(v_) == 2);
  value vtyp_ = Field(v_, 0);  // value type
  value nul_ = Field(v_, 1);   // nullable
  Q_ASSERT(!Is_block(nul_));
  vtyp = std::shared_ptr<DessserValueType>(DessserValueType::ofOCaml(vtyp_));
  nullable = Bool_val(nul_);
}
