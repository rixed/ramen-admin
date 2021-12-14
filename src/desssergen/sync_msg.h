#ifndef DESSSER_GEN_sync_msg
#define DESSSER_GEN_sync_msg
#include <arpa/inet.h>
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
  Bytes message;
  Bytes nonce;
  Bytes public_key;
  t206fd5d881820fd19331922d3e213def(Bytes message_, Bytes nonce_, Bytes public_key_) : message(message_), nonce(nonce_), public_key(public_key_) {}
  t206fd5d881820fd19331922d3e213def() = default;
};
inline bool operator==(t206fd5d881820fd19331922d3e213def const &a, t206fd5d881820fd19331922d3e213def const &b) {
  return a.message == b.message && a.nonce == b.nonce && a.public_key == b.public_key;
}

inline bool operator!=(t206fd5d881820fd19331922d3e213def const &a, t206fd5d881820fd19331922d3e213def const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t206fd5d881820fd19331922d3e213def const &r) {
  os << '{';
  os << "message:" << r.message << ',';
  os << "nonce:" << r.nonce << ',';
  os << "public_key:" << r.public_key;
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

struct t12f53a0c7c008f43bd9f6aa8e2c9a88a : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_msg::t> ,
  Pointer
> {
  using tuple::tuple;
  t12f53a0c7c008f43bd9f6aa8e2c9a88a(std::tuple<std::shared_ptr<::dessser::gen::sync_msg::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_msg::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12f53a0c7c008f43bd9f6aa8e2c9a88a const &a, t12f53a0c7c008f43bd9f6aa8e2c9a88a const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12f53a0c7c008f43bd9f6aa8e2c9a88a const &a, t12f53a0c7c008f43bd9f6aa8e2c9a88a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t12f53a0c7c008f43bd9f6aa8e2c9a88a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t12f53a0c7c008f43bd9f6aa8e2c9a88a> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_msg::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_msg::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_msg::t12f53a0c7c008f43bd9f6aa8e2c9a88a(Pointer)> of_row_binary;
extern std::function<::dessser::gen::sync_msg::t12f53a0c7c008f43bd9f6aa8e2c9a88a(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_msg::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
