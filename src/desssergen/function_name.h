#ifndef DESSSER_GEN_function_name
#define DESSSER_GEN_function_name
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::function_name {
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
extern std::function<::dessser::gen::function_name::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
