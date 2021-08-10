#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct c1cc8a2c9779db1c5df618b834848368 : public std::variant<
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, c1cc8a2c9779db1c5df618b834848368 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t {
  c1cc8a2c9779db1c5df618b834848368 scope;
  *field_name name;
  *raql_type typ;
  bool operator==(t const &other) const {
    return scope == other.scope && name == other.name && typ == other.typ;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "scope:" << r.scope << ',';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ;
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
