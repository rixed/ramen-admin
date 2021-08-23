#ifndef DESSSER_GEN_alerting_contact
#define DESSSER_GEN_alerting_contact
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_contact {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t6856af1ea1ed3febe9b67e297a8e0a96 {
  std::string create;
  std::string file;
  std::string insert;
  bool operator==(t6856af1ea1ed3febe9b67e297a8e0a96 const &other) const {
    return create == other.create && file == other.file && insert == other.insert;
  }
};
inline std::ostream &operator<<(std::ostream &os, t6856af1ea1ed3febe9b67e297a8e0a96 const &r) {
  os << '{';
  os << "create:" << r.create << ',';
  os << "file:" << r.file << ',';
  os << "insert:" << r.insert;
  os << '}';
  return os;
}

typedef std::tuple<
  std::string,
  std::string
> t8961925d22ebc35140986110e41bc2a4;

struct t69017581c1f2e755676a8d0209b65424 {
  Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> options;
  uint16_t partition;
  std::string text;
  std::string topic;
  bool operator==(t69017581c1f2e755676a8d0209b65424 const &other) const {
    return options == other.options && partition == other.partition && text == other.text && topic == other.topic;
  }
};
inline std::ostream &operator<<(std::ostream &os, t69017581c1f2e755676a8d0209b65424 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text << ',';
  os << "topic:" << r.topic;
  os << '}';
  return os;
}

struct t41efd77a12030055a0a0a45dc889f810 : public std::variant<
  Void,
  std::string,
  std::string,
  ::dessser::gen::alerting_contact::t6856af1ea1ed3febe9b67e297a8e0a96,
  ::dessser::gen::alerting_contact::t69017581c1f2e755676a8d0209b65424
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t41efd77a12030055a0a0a45dc889f810 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
  }
  return os;
}

struct t {
  double timeout;
  ::dessser::gen::alerting_contact::t41efd77a12030055a0a0a45dc889f810 via;
  bool operator==(t const &other) const {
    return timeout == other.timeout && via == other.via;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "timeout:" << r.timeout << ',';
  os << "via:" << r.via;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::alerting_contact::t*,
  Pointer
> t6895345151933b08a9380e7a927036c0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_contact::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_contact::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
