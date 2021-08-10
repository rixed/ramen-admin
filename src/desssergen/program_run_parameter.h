#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::program_run_parameter {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t name;
  dessser::gen::raql_value::t value;
  bool operator==(t const &other) const {
    return name == other.name && value == other.value;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "value:" << r.value;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
