#ifndef DESSSER_GEN_dashboard_widget
#define DESSSER_GEN_dashboard_widget
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::dashboard_widget {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tafdc15d083fb8c2b34d5c9537c7c3b35 : public std::variant<
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tafdc15d083fb8c2b34d5c9537c7c3b35 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

struct t2dbd741445d7e42b47d58662914c784b : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t2dbd741445d7e42b47d58662914c784b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct tc9794b1ac9bbf493d6865b43481eb540 {
  bool left;
  bool force_zero;
  t2dbd741445d7e42b47d58662914c784b scale;
  bool operator==(tc9794b1ac9bbf493d6865b43481eb540 const &other) const {
    return left == other.left && force_zero == other.force_zero && scale == other.scale;
  }
};
inline std::ostream &operator<<(std::ostream &os, tc9794b1ac9bbf493d6865b43481eb540 const &r) {
  os << '{';
  os << "left:" << r.left << ',';
  os << "force_zero:" << r.force_zero << ',';
  os << "scale:" << r.scale;
  os << '}';
  return os;
}

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

struct t7e17ba75dba75985229ebaad844892a6 {
  double opacity;
  uint32_t color;
  t7ae9bb09a1a0070adced41151deef93f representation;
  std::string column;
  Arr<std::string> factors;
  uint8_t axis;
  bool operator==(t7e17ba75dba75985229ebaad844892a6 const &other) const {
    return opacity == other.opacity && color == other.color && representation == other.representation && column == other.column && factors == other.factors && axis == other.axis;
  }
};
inline std::ostream &operator<<(std::ostream &os, t7e17ba75dba75985229ebaad844892a6 const &r) {
  os << '{';
  os << "opacity:" << r.opacity << ',';
  os << "color:" << r.color << ',';
  os << "representation:" << r.representation << ',';
  os << "column:" << r.column << ',';
  os << "factors:" << r.factors << ',';
  os << "axis:" << r.axis;
  os << '}';
  return os;
}

struct t5d631a64ea9c402d0c5d7cfc444ea81f {
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  Arr<t7e17ba75dba75985229ebaad844892a6> fields;
  bool operator==(t5d631a64ea9c402d0c5d7cfc444ea81f const &other) const {
    return name == other.name && visible == other.visible && fields == other.fields;
  }
};
inline std::ostream &operator<<(std::ostream &os, t5d631a64ea9c402d0c5d7cfc444ea81f const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "visible:" << r.visible << ',';
  os << "fields:" << r.fields;
  os << '}';
  return os;
}

struct td2824ba1e2122bef42fbf431cc11ae12 {
  std::string title;
  tafdc15d083fb8c2b34d5c9537c7c3b35 type;
  Arr<tc9794b1ac9bbf493d6865b43481eb540> axis;
  Arr<t5d631a64ea9c402d0c5d7cfc444ea81f> sources;
  bool operator==(td2824ba1e2122bef42fbf431cc11ae12 const &other) const {
    return title == other.title && type == other.type && axis == other.axis && sources == other.sources;
  }
};
inline std::ostream &operator<<(std::ostream &os, td2824ba1e2122bef42fbf431cc11ae12 const &r) {
  os << '{';
  os << "title:" << r.title << ',';
  os << "type:" << r.type << ',';
  os << "axis:" << r.axis << ',';
  os << "sources:" << r.sources;
  os << '}';
  return os;
}

struct t : public std::variant<
  std::string,
  td2824ba1e2122bef42fbf431cc11ae12
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
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
