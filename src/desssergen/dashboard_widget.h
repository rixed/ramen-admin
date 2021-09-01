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
struct tf285c6d4be19a8e3e994b3792fed4f11 : public std::variant<
  Void, // Linear
  Void // Logarithmic
> { using variant::variant; };

enum Constr_tf285c6d4be19a8e3e994b3792fed4f11 {
  Linear,
  Logarithmic,
};

inline std::ostream &operator<<(std::ostream &os, tf285c6d4be19a8e3e994b3792fed4f11 const &v) {
  switch (v.index()) {
    case 0: os << "Linear " << std::get<0>(v); break;
    case 1: os << "Logarithmic " << std::get<1>(v); break;
  }
  return os;
}

struct td829267f693347bdfd48821a09eebaae {
  bool force_zero;
  bool left;
  ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 scale;
  td829267f693347bdfd48821a09eebaae(bool force_zero_, bool left_, ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 scale_) : force_zero(force_zero_), left(left_), scale(scale_) {}
  td829267f693347bdfd48821a09eebaae() = default;
  bool operator==(td829267f693347bdfd48821a09eebaae const &other) const {
    return force_zero == other.force_zero && left == other.left && scale == other.scale;
  }
};
inline std::ostream &operator<<(std::ostream &os, td829267f693347bdfd48821a09eebaae const &r) {
  os << '{';
  os << "force_zero:" << r.force_zero << ',';
  os << "left:" << r.left << ',';
  os << "scale:" << r.scale;
  os << '}';
  return os;
}

struct tc758d36a6b58d564436d5e1104817704 : public std::variant<
  Void, // Unused
  Void, // Independent
  Void, // Stacked
  Void // StackCentered
> { using variant::variant; };

enum Constr_tc758d36a6b58d564436d5e1104817704 {
  Unused,
  Independent,
  Stacked,
  StackCentered,
};

inline std::ostream &operator<<(std::ostream &os, tc758d36a6b58d564436d5e1104817704 const &v) {
  switch (v.index()) {
    case 0: os << "Unused " << std::get<0>(v); break;
    case 1: os << "Independent " << std::get<1>(v); break;
    case 2: os << "Stacked " << std::get<2>(v); break;
    case 3: os << "StackCentered " << std::get<3>(v); break;
  }
  return os;
}

struct tb51b41a880c2ae6dd20d6e8d4b27e71f {
  uint8_t axis;
  uint32_t color;
  std::string column;
  Arr<std::string> factors;
  double opacity;
  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 representation;
  tb51b41a880c2ae6dd20d6e8d4b27e71f(uint8_t axis_, uint32_t color_, std::string column_, Arr<std::string> factors_, double opacity_, ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 representation_) : axis(axis_), color(color_), column(column_), factors(factors_), opacity(opacity_), representation(representation_) {}
  tb51b41a880c2ae6dd20d6e8d4b27e71f() = default;
  bool operator==(tb51b41a880c2ae6dd20d6e8d4b27e71f const &other) const {
    return axis == other.axis && color == other.color && column == other.column && factors == other.factors && opacity == other.opacity && representation == other.representation;
  }
};
inline std::ostream &operator<<(std::ostream &os, tb51b41a880c2ae6dd20d6e8d4b27e71f const &r) {
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

struct t2958b4be951f2940fe1f4fe3e7336e60 {
  Arr<::dessser::gen::dashboard_widget::tb51b41a880c2ae6dd20d6e8d4b27e71f> fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  t2958b4be951f2940fe1f4fe3e7336e60(Arr<::dessser::gen::dashboard_widget::tb51b41a880c2ae6dd20d6e8d4b27e71f> fields_, dessser::gen::fq_function_name::t_ext name_, bool visible_) : fields(fields_), name(name_), visible(visible_) {}
  t2958b4be951f2940fe1f4fe3e7336e60() = default;
  bool operator==(t2958b4be951f2940fe1f4fe3e7336e60 const &other) const {
    return fields == other.fields && name == other.name && visible == other.visible;
  }
};
inline std::ostream &operator<<(std::ostream &os, t2958b4be951f2940fe1f4fe3e7336e60 const &r) {
  os << '{';
  os << "fields:" << r.fields << ',';
  os << "name:" << r.name << ',';
  os << "visible:" << r.visible;
  os << '}';
  return os;
}

struct t3ef59f16a0cdd3a9e330e7c5bf93b091 : public std::variant<
  Void // Plot
> { using variant::variant; };

enum Constr_t3ef59f16a0cdd3a9e330e7c5bf93b091 {
  Plot,
};

inline std::ostream &operator<<(std::ostream &os, t3ef59f16a0cdd3a9e330e7c5bf93b091 const &v) {
  switch (v.index()) {
    case 0: os << "Plot " << std::get<0>(v); break;
  }
  return os;
}

struct t5383e291bb0cfc4e60684e58d6fb9e1a {
  Arr<::dessser::gen::dashboard_widget::td829267f693347bdfd48821a09eebaae> Chart_axis;
  Arr<::dessser::gen::dashboard_widget::t2958b4be951f2940fe1f4fe3e7336e60> sources;
  std::string title;
  ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 type;
  t5383e291bb0cfc4e60684e58d6fb9e1a(Arr<::dessser::gen::dashboard_widget::td829267f693347bdfd48821a09eebaae> Chart_axis_, Arr<::dessser::gen::dashboard_widget::t2958b4be951f2940fe1f4fe3e7336e60> sources_, std::string title_, ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 type_) : Chart_axis(Chart_axis_), sources(sources_), title(title_), type(type_) {}
  t5383e291bb0cfc4e60684e58d6fb9e1a() = default;
  bool operator==(t5383e291bb0cfc4e60684e58d6fb9e1a const &other) const {
    return Chart_axis == other.Chart_axis && sources == other.sources && title == other.title && type == other.type;
  }
};
inline std::ostream &operator<<(std::ostream &os, t5383e291bb0cfc4e60684e58d6fb9e1a const &r) {
  os << '{';
  os << "Chart_axis:" << r.Chart_axis << ',';
  os << "sources:" << r.sources << ',';
  os << "title:" << r.title << ',';
  os << "type:" << r.type;
  os << '}';
  return os;
}

struct t : public std::variant<
  std::string, // Text
  ::dessser::gen::dashboard_widget::t5383e291bb0cfc4e60684e58d6fb9e1a // Chart
> { using variant::variant; };

enum Constr_t {
  Text,
  Chart,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Text " << std::get<0>(v); break;
    case 1: os << "Chart " << std::get<1>(v); break;
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
