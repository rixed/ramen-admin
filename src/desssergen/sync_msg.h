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
struct t8e318f9b56dd08757b5d842d3860cfce {
  Bytes message;
  Bytes nonce;
  Bytes public_key;
  t8e318f9b56dd08757b5d842d3860cfce(Bytes message_, Bytes nonce_, Bytes public_key_) : message(message_), nonce(nonce_), public_key(public_key_) {}
  t8e318f9b56dd08757b5d842d3860cfce() = default;
  bool operator==(t8e318f9b56dd08757b5d842d3860cfce const &other) const {
    return message == other.message && nonce == other.nonce && public_key == other.public_key;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8e318f9b56dd08757b5d842d3860cfce const &r) {
  os << '{';
  os << "message:" << r.message << ',';
  os << "nonce:" << r.nonce << ',';
  os << "public_key:" << r.public_key;
  os << '}';
  return os;
}

struct t : public std::variant<
  ::dessser::gen::sync_msg::t8e318f9b56dd08757b5d842d3860cfce, // SendSessionKey
  Bytes, // Crypted
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
