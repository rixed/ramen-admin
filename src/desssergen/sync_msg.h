#ifndef DESSSER_GEN_sync_msg
#define DESSSER_GEN_sync_msg
#include <arpa/inet.h>
#include <functional>
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
struct tdb9685b762777dddeea8bb04805eb8cf {
  Bytes SendSessionKey_message;
  Bytes SendSessionKey_nonce;
  Bytes public_key;
  bool operator==(tdb9685b762777dddeea8bb04805eb8cf const &other) const {
    return SendSessionKey_message == other.SendSessionKey_message && SendSessionKey_nonce == other.SendSessionKey_nonce && public_key == other.public_key;
  }
};
inline std::ostream &operator<<(std::ostream &os, tdb9685b762777dddeea8bb04805eb8cf const &r) {
  os << '{';
  os << "SendSessionKey_message:" << r.SendSessionKey_message << ',';
  os << "SendSessionKey_nonce:" << r.SendSessionKey_nonce << ',';
  os << "public_key:" << r.public_key;
  os << '}';
  return os;
}

struct t10b7d87ea3b6637868bb9b5cc57e7b11 {
  Bytes message;
  Bytes nonce;
  bool operator==(t10b7d87ea3b6637868bb9b5cc57e7b11 const &other) const {
    return message == other.message && nonce == other.nonce;
  }
};
inline std::ostream &operator<<(std::ostream &os, t10b7d87ea3b6637868bb9b5cc57e7b11 const &r) {
  os << '{';
  os << "message:" << r.message << ',';
  os << "nonce:" << r.nonce;
  os << '}';
  return os;
}

struct t : public std::variant<
  ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf, // SendSessionKey
  ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11, // Crypted
  Bytes, // ClearText
  std::string // Error
> { using variant::variant; };

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

typedef std::tuple<
  ::dessser::gen::sync_msg::t*,
  Pointer
> t225ef9f1e97f4882d6b6a9f870881a23;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_msg::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_msg::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
