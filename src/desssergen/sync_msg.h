#ifndef DESSSER_GEN_sync_msg
#define DESSSER_GEN_sync_msg
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_msg {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t206fd5d881820fd19331922d3e213def {
  Bytes nonce;
  Bytes public_key;
  Bytes message;
  t206fd5d881820fd19331922d3e213def(Bytes nonce_, Bytes public_key_, Bytes message_) : nonce(nonce_), public_key(public_key_), message(message_) {}
  t206fd5d881820fd19331922d3e213def() = default;
};
inline bool operator==(t206fd5d881820fd19331922d3e213def const &a, t206fd5d881820fd19331922d3e213def const &b) {
  return a.nonce == b.nonce && a.public_key == b.public_key && a.message == b.message;
}

inline bool operator!=(t206fd5d881820fd19331922d3e213def const &a, t206fd5d881820fd19331922d3e213def const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t206fd5d881820fd19331922d3e213def const &r) {
  os << '{';
  os << "nonce:" << r.nonce << ',';
  os << "public_key:" << r.public_key << ',';
  os << "message:" << r.message;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t206fd5d881820fd19331922d3e213def> const r) { os << *r; return os; }

struct t : public std::variant<
  ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def, // SendSessionKey
  Bytes, // Crypted
  Bytes, // ClearText
  std::string // Error
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 4 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // SendSessionKey
    case 1: return std::get<1>(a) == std::get<1>(b); // Crypted
    case 2: return std::get<2>(a) == std::get<2>(b); // ClearText
    case 3: return std::get<3>(a) == std::get<3>(b); // Error
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  SendSessionKey,
  Crypted,
  ClearText,
  Error,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "SendSessionKey " << std::get<0>(v); break;
    case 1: os << "Crypted " << std::get<1>(v); break;
    case 2: os << "ClearText " << std::get<2>(v); break;
    case 3: os << "Error " << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct tc374fe7e38202b30396ee364cbb6d53e : public std::tuple<
  ::dessser::gen::sync_msg::t,
  Pointer
> {
  using tuple::tuple;
  tc374fe7e38202b30396ee364cbb6d53e(std::tuple<::dessser::gen::sync_msg::t, Pointer> p)
    : std::tuple<::dessser::gen::sync_msg::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc374fe7e38202b30396ee364cbb6d53e const &a, tc374fe7e38202b30396ee364cbb6d53e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc374fe7e38202b30396ee364cbb6d53e const &a, tc374fe7e38202b30396ee364cbb6d53e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc374fe7e38202b30396ee364cbb6d53e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc374fe7e38202b30396ee364cbb6d53e> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_msg::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
