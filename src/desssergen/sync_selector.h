#ifndef DESSSER_GEN_sync_selector
#define DESSSER_GEN_sync_selector
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_selector {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::string t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t,Pointer)> to_row_binary;
extern std::function<Size(t)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_selector::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;

}
#endif
