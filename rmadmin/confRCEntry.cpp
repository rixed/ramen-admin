#include <iostream>
#include <cassert>
extern "C" {
# include <caml/memory.h>
# include <caml/alloc.h>
}
#include "confRCEntryParam.h"
#include "confRCEntry.h"

namespace conf {

value RCEntry::toOCamlValue() const
{
  CAMLparam0();
  CAMLlocal3(ret, paramLst, cons);
  ret = caml_alloc_tuple(7);
  Store_field(ret, 0, Val_bool(enabled));
  std::cout << "RCEntry::toOCamlValue: debug = " << debug << std::endl;
  Store_field(ret, 1, Val_bool(debug));
  Store_field(ret, 2, caml_copy_double(reportPeriod));
  paramLst = Val_emptylist; // Aka Val_int(0)
  for (auto const param : params) {
    // prepend param:
    cons = caml_alloc(2, Tag_cons);
    Store_field(cons, 1, paramLst);
    Store_field(cons, 0, param->toOCamlValue());
    paramLst = cons;
  }
  Store_field(ret, 3, paramLst);
  Store_field(ret, 4, caml_copy_string(source.c_str()));
  Store_field(ret, 5, caml_copy_string(onSite.c_str()));
  Store_field(ret, 6, Val_bool(automatic));
  CAMLreturn(ret);
}

};