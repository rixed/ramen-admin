#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_log {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct v_53c0e376e5645c9395bb7436d28074f2 : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_53c0e376e5645c9395bb7436d28074f2 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  uint32_t
> c9034d297e61f13fa539d402e882ed63;

struct f5612b432a19dbfc96bbe5b8c2733ed3 : public std::variant<
  Void,
  std::string,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, f5612b432a19dbfc96bbe5b8c2733ed3 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t : public std::variant<
  v_53c0e376e5645c9395bb7436d28074f2,
  c9034d297e61f13fa539d402e882ed63,
  std::string,
  f5612b432a19dbfc96bbe5b8c2733ed3,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
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
