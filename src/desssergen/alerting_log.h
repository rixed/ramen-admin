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
struct t7ae9bb09a1a0070adced41151deef93f : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t7ae9bb09a1a0070adced41151deef93f const &v) {
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

struct t8347e1c22520ce64e4427c2d53263f64 : public std::variant<
  Void,
  std::string,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t8347e1c22520ce64e4427c2d53263f64 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t : public std::variant<
  t7ae9bb09a1a0070adced41151deef93f,
  t8fac3da053db9cb461751be833f41f86,
  std::string,
  t8347e1c22520ce64e4427c2d53263f64,
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
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
