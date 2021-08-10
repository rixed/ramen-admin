#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct ed606adbafa604d06597791e201d008c : public std::variant<
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, ed606adbafa604d06597791e201d008c const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

struct v_64020630bdd04b37ed2ef6f539d0c800 : public std::variant<
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_64020630bdd04b37ed2ef6f539d0c800 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct v_5fc1c30a943a0c1ef8da3535f3079eba {
  bool left;
  bool force_zero;
  v_64020630bdd04b37ed2ef6f539d0c800 scale;
  bool operator==(v_5fc1c30a943a0c1ef8da3535f3079eba const &other) const {
    return left == other.left && force_zero == other.force_zero && scale == other.scale;
  }
};
std::ostream &operator<<(std::ostream &os, v_5fc1c30a943a0c1ef8da3535f3079eba const &r) {
  os << '{';
  os << "left:" << r.left << ',';
  os << "force_zero:" << r.force_zero << ',';
  os << "scale:" << r.scale;
  os << '}';
  return os;
}

struct e5c3611dd9d3a05067d08e10507ebe28 : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, e5c3611dd9d3a05067d08e10507ebe28 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

struct v_67a0e55ce68284d9f234903bf8ef7907 {
  double opacity;
  uint32_t color;
  e5c3611dd9d3a05067d08e10507ebe28 representation;
  std::string column;
  Arr<std::string> factors;
  uint8_t axis;
  bool operator==(v_67a0e55ce68284d9f234903bf8ef7907 const &other) const {
    return opacity == other.opacity && color == other.color && representation == other.representation && column == other.column && factors == other.factors && axis == other.axis;
  }
};
std::ostream &operator<<(std::ostream &os, v_67a0e55ce68284d9f234903bf8ef7907 const &r) {
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

struct b057734d3828999a4e463dd04964f728 {
  *fq_function_name name;
  bool visible;
  Arr<v_67a0e55ce68284d9f234903bf8ef7907> fields;
  bool operator==(b057734d3828999a4e463dd04964f728 const &other) const {
    return name == other.name && visible == other.visible && fields == other.fields;
  }
};
std::ostream &operator<<(std::ostream &os, b057734d3828999a4e463dd04964f728 const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "visible:" << r.visible << ',';
  os << "fields:" << r.fields;
  os << '}';
  return os;
}

struct ec882bee7facda78cc914d658392c714 {
  std::string title;
  ed606adbafa604d06597791e201d008c type;
  Arr<v_5fc1c30a943a0c1ef8da3535f3079eba> axis;
  Arr<b057734d3828999a4e463dd04964f728> sources;
  bool operator==(ec882bee7facda78cc914d658392c714 const &other) const {
    return title == other.title && type == other.type && axis == other.axis && sources == other.sources;
  }
};
std::ostream &operator<<(std::ostream &os, ec882bee7facda78cc914d658392c714 const &r) {
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
  ec882bee7facda78cc914d658392c714
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
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
