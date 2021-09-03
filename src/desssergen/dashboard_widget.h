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

inline bool operator==(tf285c6d4be19a8e3e994b3792fed4f11 const &a, tf285c6d4be19a8e3e994b3792fed4f11 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Linear
    case 1: return std::get<1>(a) == std::get<1>(b); // Logarithmic
  };
  return false;
}
inline bool operator!=(tf285c6d4be19a8e3e994b3792fed4f11 const &a, tf285c6d4be19a8e3e994b3792fed4f11 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf285c6d4be19a8e3e994b3792fed4f11 const &v) {
  switch (v.index()) {
    case 0: os << "Linear " << std::get<0>(v); break;
    case 1: os << "Logarithmic " << std::get<1>(v); break;
  }
  return os;
}

struct t7a73277e81021fc63d7d1b63bc3beba6 {
  bool force_zero;
  bool left;
  ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 scale;
  t7a73277e81021fc63d7d1b63bc3beba6(bool force_zero_, bool left_, ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 scale_) : force_zero(force_zero_), left(left_), scale(scale_) {}
  t7a73277e81021fc63d7d1b63bc3beba6() = default;
};
inline std::ostream &operator<<(std::ostream &os, t7a73277e81021fc63d7d1b63bc3beba6 const &r) {
  os << '{';
  os << "force_zero:" << r.force_zero << ',';
  os << "left:" << r.left << ',';
  os << "scale:" << r.scale;
  os << '}';
  return os;
}
inline bool operator==(t7a73277e81021fc63d7d1b63bc3beba6 const &a, t7a73277e81021fc63d7d1b63bc3beba6 const &b) {
  return a.force_zero == b.force_zero && a.left == b.left && a.scale == b.scale;
}

inline bool operator!=(t7a73277e81021fc63d7d1b63bc3beba6 const &a, t7a73277e81021fc63d7d1b63bc3beba6 const &b) {
  return !operator==(a, b);
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

inline bool operator==(tc758d36a6b58d564436d5e1104817704 const &a, tc758d36a6b58d564436d5e1104817704 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Unused
    case 1: return std::get<1>(a) == std::get<1>(b); // Independent
    case 2: return std::get<2>(a) == std::get<2>(b); // Stacked
    case 3: return std::get<3>(a) == std::get<3>(b); // StackCentered
  };
  return false;
}
inline bool operator!=(tc758d36a6b58d564436d5e1104817704 const &a, tc758d36a6b58d564436d5e1104817704 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc758d36a6b58d564436d5e1104817704 const &v) {
  switch (v.index()) {
    case 0: os << "Unused " << std::get<0>(v); break;
    case 1: os << "Independent " << std::get<1>(v); break;
    case 2: os << "Stacked " << std::get<2>(v); break;
    case 3: os << "StackCentered " << std::get<3>(v); break;
  }
  return os;
}

struct t4014451f4abcdfd5489869fefe1eca82 {
  uint8_t axis;
  uint32_t color;
  std::string column;
  Arr<std::string> factors;
  double opacity;
  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 representation;
  t4014451f4abcdfd5489869fefe1eca82(uint8_t axis_, uint32_t color_, std::string column_, Arr<std::string> factors_, double opacity_, ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 representation_) : axis(axis_), color(color_), column(column_), factors(factors_), opacity(opacity_), representation(representation_) {}
  t4014451f4abcdfd5489869fefe1eca82() = default;
};
inline std::ostream &operator<<(std::ostream &os, t4014451f4abcdfd5489869fefe1eca82 const &r) {
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
inline bool operator==(t4014451f4abcdfd5489869fefe1eca82 const &a, t4014451f4abcdfd5489869fefe1eca82 const &b) {
  return a.axis == b.axis && a.color == b.color && a.column == b.column && a.factors == b.factors && a.opacity == b.opacity && a.representation == b.representation;
}

inline bool operator!=(t4014451f4abcdfd5489869fefe1eca82 const &a, t4014451f4abcdfd5489869fefe1eca82 const &b) {
  return !operator==(a, b);
}
struct t79826a59cc1e8c45c3ad94e8417c3225 {
  Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  t79826a59cc1e8c45c3ad94e8417c3225(Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> fields_, dessser::gen::fq_function_name::t_ext name_, bool visible_) : fields(fields_), name(name_), visible(visible_) {}
  t79826a59cc1e8c45c3ad94e8417c3225() = default;
};
inline std::ostream &operator<<(std::ostream &os, t79826a59cc1e8c45c3ad94e8417c3225 const &r) {
  os << '{';
  os << "fields:" << r.fields << ',';
  os << "name:" << ::dessser::gen::fq_function_name::Deref(r.name) << ',';
  os << "visible:" << r.visible;
  os << '}';
  return os;
}
inline bool operator==(t79826a59cc1e8c45c3ad94e8417c3225 const &a, t79826a59cc1e8c45c3ad94e8417c3225 const &b) {
  return a.fields == b.fields && ::dessser::gen::fq_function_name::Deref(a.name) == ::dessser::gen::fq_function_name::Deref(b.name) && a.visible == b.visible;
}

inline bool operator!=(t79826a59cc1e8c45c3ad94e8417c3225 const &a, t79826a59cc1e8c45c3ad94e8417c3225 const &b) {
  return !operator==(a, b);
}
struct t3ef59f16a0cdd3a9e330e7c5bf93b091 : public std::variant<
  Void // Plot
> { using variant::variant; };

enum Constr_t3ef59f16a0cdd3a9e330e7c5bf93b091 {
  Plot,
};

inline bool operator==(t3ef59f16a0cdd3a9e330e7c5bf93b091 const &a, t3ef59f16a0cdd3a9e330e7c5bf93b091 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Plot
  };
  return false;
}
inline bool operator!=(t3ef59f16a0cdd3a9e330e7c5bf93b091 const &a, t3ef59f16a0cdd3a9e330e7c5bf93b091 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3ef59f16a0cdd3a9e330e7c5bf93b091 const &v) {
  switch (v.index()) {
    case 0: os << "Plot " << std::get<0>(v); break;
  }
  return os;
}

struct ta3280375be63ffe37d86976d93bf0304 {
  Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> Chart_axis;
  Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> sources;
  std::string title;
  ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 type;
  ta3280375be63ffe37d86976d93bf0304(Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> Chart_axis_, Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> sources_, std::string title_, ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 type_) : Chart_axis(Chart_axis_), sources(sources_), title(title_), type(type_) {}
  ta3280375be63ffe37d86976d93bf0304() = default;
};
inline std::ostream &operator<<(std::ostream &os, ta3280375be63ffe37d86976d93bf0304 const &r) {
  os << '{';
  os << "Chart_axis:" << r.Chart_axis << ',';
  os << "sources:" << r.sources << ',';
  os << "title:" << r.title << ',';
  os << "type:" << r.type;
  os << '}';
  return os;
}
inline bool operator==(ta3280375be63ffe37d86976d93bf0304 const &a, ta3280375be63ffe37d86976d93bf0304 const &b) {
  return a.Chart_axis == b.Chart_axis && a.sources == b.sources && a.title == b.title && a.type == b.type;
}

inline bool operator!=(ta3280375be63ffe37d86976d93bf0304 const &a, ta3280375be63ffe37d86976d93bf0304 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  std::string, // Text
  ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 // Chart
> { using variant::variant; };

enum Constr_t {
  Text,
  Chart,
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Text
    case 1: return std::get<1>(a) == std::get<1>(b); // Chart
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
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
inline t Deref(t_ext x) { return *x; }

}
#endif
