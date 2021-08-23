#ifndef DESSSER_GEN_alerting_log
#define DESSSER_GEN_alerting_log
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_log {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t94d3f63f7a6f4439feec5972b0434d93 : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t94d3f63f7a6f4439feec5972b0434d93 const &v) {
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
> t8fac3da053db9cb461751be833f41f86;

struct t2e2e392d252acd9be53198082dfdc293 : public std::variant<
  Void,
  std::string,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t2e2e392d252acd9be53198082dfdc293 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t : public std::variant<
  ::dessser::gen::alerting_log::t94d3f63f7a6f4439feec5972b0434d93,
  ::dessser::gen::alerting_log::t8fac3da053db9cb461751be833f41f86,
  std::string,
  ::dessser::gen::alerting_log::t2e2e392d252acd9be53198082dfdc293,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
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
  ::dessser::gen::alerting_log::t*,
  Pointer
> t7ed4ba740a9d377e5cafe90b9af62314;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_log::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_log::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_log::t7ed4ba740a9d377e5cafe90b9af62314(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
