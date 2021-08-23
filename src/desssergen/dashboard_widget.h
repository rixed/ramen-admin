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
struct t48b79f232880b7b4f6fa63fb49447c29 : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t48b79f232880b7b4f6fa63fb49447c29 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct tbeb46a76993830b8ea1335c2c948bd98 {
  bool force_zero;
  bool left;
  ::dessser::gen::dashboard_widget::t48b79f232880b7b4f6fa63fb49447c29 scale;
  bool operator==(tbeb46a76993830b8ea1335c2c948bd98 const &other) const {
    return force_zero == other.force_zero && left == other.left && scale == other.scale;
  }
};
inline std::ostream &operator<<(std::ostream &os, tbeb46a76993830b8ea1335c2c948bd98 const &r) {
  os << '{';
  os << "force_zero:" << r.force_zero << ',';
  os << "left:" << r.left << ',';
  os << "scale:" << r.scale;
  os << '}';
  return os;
}

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

struct t7821a306614093d97806856152d82ee2 {
  uint8_t axis;
  uint32_t color;
  std::string column;
  Arr<std::string> factors;
  double opacity;
  ::dessser::gen::dashboard_widget::t94d3f63f7a6f4439feec5972b0434d93 representation;
  bool operator==(t7821a306614093d97806856152d82ee2 const &other) const {
    return axis == other.axis && color == other.color && column == other.column && factors == other.factors && opacity == other.opacity && representation == other.representation;
  }
};
inline std::ostream &operator<<(std::ostream &os, t7821a306614093d97806856152d82ee2 const &r) {
  os << '{';
  os << "axis:" << r.axis << ',';
  os << "color:" << r.color << ',';
  os << "column:" << r.column << ',';
  os << "factors:" << r.factors << ',';
  os << "opacity:" << r.opacity << ',';
  os << "representation:" << r.representation;
  os << '}';
  return os;
}

struct t0cad8ab96cb8a97d251c5d1f920378ed {
  Arr<::dessser::gen::dashboard_widget::t7821a306614093d97806856152d82ee2> fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  bool operator==(t0cad8ab96cb8a97d251c5d1f920378ed const &other) const {
    return fields == other.fields && name == other.name && visible == other.visible;
  }
};
inline std::ostream &operator<<(std::ostream &os, t0cad8ab96cb8a97d251c5d1f920378ed const &r) {
  os << '{';
  os << "fields:" << r.fields << ',';
  os << "name:" << r.name << ',';
  os << "visible:" << r.visible;
  os << '}';
  return os;
}

struct t113d89516a2c18ae050fd882eee5a84a : public std::variant<
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t113d89516a2c18ae050fd882eee5a84a const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

struct t6ed8621d2a0fd27eb16059ee0823872c {
  Arr<::dessser::gen::dashboard_widget::tbeb46a76993830b8ea1335c2c948bd98> axis;
  Arr<::dessser::gen::dashboard_widget::t0cad8ab96cb8a97d251c5d1f920378ed> sources;
  std::string title;
  ::dessser::gen::dashboard_widget::t113d89516a2c18ae050fd882eee5a84a type;
  bool operator==(t6ed8621d2a0fd27eb16059ee0823872c const &other) const {
    return axis == other.axis && sources == other.sources && title == other.title && type == other.type;
  }
};
inline std::ostream &operator<<(std::ostream &os, t6ed8621d2a0fd27eb16059ee0823872c const &r) {
  os << '{';
  os << "axis:" << r.axis << ',';
  os << "sources:" << r.sources << ',';
  os << "title:" << r.title << ',';
  os << "type:" << r.type;
  os << '}';
  return os;
}

struct t : public std::variant<
  std::string,
  ::dessser::gen::dashboard_widget::t6ed8621d2a0fd27eb16059ee0823872c
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::dashboard_widget::t*,
  Pointer
> t1a99c61debfb8ac5db5347b1cf1a79d1;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::dashboard_widget::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
