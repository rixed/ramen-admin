#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::simple_filter {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t lhs;
  std::string rhs;
  std::string op;
  bool operator==(t const &other) const {
    return lhs == other.lhs && rhs == other.rhs && op == other.op;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "lhs:" << r.lhs << ',';
  os << "rhs:" << r.rhs << ',';
  os << "op:" << r.op;
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
