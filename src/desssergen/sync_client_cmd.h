#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_client_cmd {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  dessser::gen::sync_user_id::t,
  double
> dbf2e0bf3a7180017cc36adb825f391b;

typedef std::tuple<
  dessser::gen::sync_key::t,
  dessser::gen::sync_value::t
> v_576cf0b907acee9866e8dcab8f842c70;

struct b4834b9b54082be3172ea167d55892f5 : public std::tuple<
  dessser::gen::sync_key::t,
  dessser::gen::sync_value::t,
  double,
  bool
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, b4834b9b54082be3172ea167d55892f5 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct e23ab991ab36f2a4daa504088db7bf59 : public std::tuple<
  dessser::gen::sync_key::t,
  double,
  bool
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, e23ab991ab36f2a4daa504088db7bf59 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t : public std::variant<
  dbf2e0bf3a7180017cc36adb825f391b,
  dessser::gen::sync_selector::t,
  v_576cf0b907acee9866e8dcab8f842c70,
  b4834b9b54082be3172ea167d55892f5,
  v_576cf0b907acee9866e8dcab8f842c70,
  dessser::gen::sync_key::t,
  e23ab991ab36f2a4daa504088db7bf59,
  e23ab991ab36f2a4daa504088db7bf59,
  dessser::gen::sync_key::t,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
    case 9: os << std::get<9>(v); break;
  }
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
