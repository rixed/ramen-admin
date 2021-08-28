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

struct tba7ef6a2b89382f283b750ac4fbf5e6d {
  bool force_zero;
  bool left;
  ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 scale;
  bool operator==(tba7ef6a2b89382f283b750ac4fbf5e6d const &other) const {
    return force_zero == other.force_zero && left == other.left && scale == other.scale;
  }
};
inline std::ostream &operator<<(std::ostream &os, tba7ef6a2b89382f283b750ac4fbf5e6d const &r) {
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

struct t4419d30cb2b0a80e59ffc034e0c20136 {
  uint8_t axis;
  uint32_t color;
  std::string column;
  Arr<std::string> factors;
  double opacity;
  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 representation;
  bool operator==(t4419d30cb2b0a80e59ffc034e0c20136 const &other) const {
    return axis == other.axis && color == other.color && column == other.column && factors == other.factors && opacity == other.opacity && representation == other.representation;
  }
};
inline std::ostream &operator<<(std::ostream &os, t4419d30cb2b0a80e59ffc034e0c20136 const &r) {
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

struct te656ad6c7a50d20bed39c72121f1bc2d {
  Arr<::dessser::gen::dashboard_widget::t4419d30cb2b0a80e59ffc034e0c20136> fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  bool operator==(te656ad6c7a50d20bed39c72121f1bc2d const &other) const {
    return fields == other.fields && name == other.name && visible == other.visible;
  }
};
inline std::ostream &operator<<(std::ostream &os, te656ad6c7a50d20bed39c72121f1bc2d const &r) {
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

struct ta1f207834d08b85ce654fc130a9cb3fc {
  Arr<::dessser::gen::dashboard_widget::tba7ef6a2b89382f283b750ac4fbf5e6d> Chart_axis;
  Arr<::dessser::gen::dashboard_widget::te656ad6c7a50d20bed39c72121f1bc2d> sources;
  std::string title;
  ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 type;
  bool operator==(ta1f207834d08b85ce654fc130a9cb3fc const &other) const {
    return Chart_axis == other.Chart_axis && sources == other.sources && title == other.title && type == other.type;
  }
};
inline std::ostream &operator<<(std::ostream &os, ta1f207834d08b85ce654fc130a9cb3fc const &r) {
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
  ::dessser::gen::dashboard_widget::ta1f207834d08b85ce654fc130a9cb3fc // Chart
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
