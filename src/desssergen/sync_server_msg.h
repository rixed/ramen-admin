#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_server_msg {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct v_940f244208f0d3b12c9ae508dcaea75c {
  dessser::gen::sync_key::t k;
  dessser::gen::sync_value::t v;
  std::string uid;
  double mtime;
  bool operator==(v_940f244208f0d3b12c9ae508dcaea75c const &other) const {
    return k == other.k && v == other.v && uid == other.uid && mtime == other.mtime;
  }
};
std::ostream &operator<<(std::ostream &os, v_940f244208f0d3b12c9ae508dcaea75c const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "v:" << r.v << ',';
  os << "uid:" << r.uid << ',';
  os << "mtime:" << r.mtime;
  os << '}';
  return os;
}

struct v_5e1953df5130fdcab794186d201fd5e8 {
  dessser::gen::sync_key::t k;
  dessser::gen::sync_value::t v;
  std::string uid;
  double mtime;
  bool can_write;
  bool can_del;
  std::string owner;
  double expiry;
  bool operator==(v_5e1953df5130fdcab794186d201fd5e8 const &other) const {
    return k == other.k && v == other.v && uid == other.uid && mtime == other.mtime && can_write == other.can_write && can_del == other.can_del && owner == other.owner && expiry == other.expiry;
  }
};
std::ostream &operator<<(std::ostream &os, v_5e1953df5130fdcab794186d201fd5e8 const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "v:" << r.v << ',';
  os << "uid:" << r.uid << ',';
  os << "mtime:" << r.mtime << ',';
  os << "can_write:" << r.can_write << ',';
  os << "can_del:" << r.can_del << ',';
  os << "owner:" << r.owner << ',';
  os << "expiry:" << r.expiry;
  os << '}';
  return os;
}

struct v_3cca14702fcf070f776a6badc4224e9d {
  dessser::gen::sync_key::t k;
  std::string owner;
  double expiry;
  bool operator==(v_3cca14702fcf070f776a6badc4224e9d const &other) const {
    return k == other.k && owner == other.owner && expiry == other.expiry;
  }
};
std::ostream &operator<<(std::ostream &os, v_3cca14702fcf070f776a6badc4224e9d const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "owner:" << r.owner << ',';
  os << "expiry:" << r.expiry;
  os << '}';
  return os;
}

struct t : public std::variant<
  dessser::gen::sync_socket::t,
  std::string,
  v_940f244208f0d3b12c9ae508dcaea75c,
  v_5e1953df5130fdcab794186d201fd5e8,
  dessser::gen::sync_key::t,
  v_3cca14702fcf070f776a6badc4224e9d,
  dessser::gen::sync_key::t
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
