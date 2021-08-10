#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::field_name {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::string t;
typedef std::tuple<
  t,
  Pointer
> v_46a5e81c2410b000ff0adea6dc198147;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<v_46a5e81c2410b000ff0adea6dc198147(Pointer)> of_row_binary;

}
