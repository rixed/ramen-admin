#ifndef DESSSER_GEN_dashboard_widget
#define DESSSER_GEN_dashboard_widget
#include <functional>
#include <memory>
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
struct representation : public std::variant<
  Void, // Unused
  Void, // Independent
  Void, // Stacked
  Void // StackCentered
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 4 };
};

inline bool operator==(representation const &a, representation const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Unused
    case 1: return std::get<1>(a) == std::get<1>(b); // Independent
    case 2: return std::get<2>(a) == std::get<2>(b); // Stacked
    case 3: return std::get<3>(a) == std::get<3>(b); // StackCentered
  };
  return false;
}
inline bool operator!=(representation const &a, representation const &b) {
  return !operator==(a, b);
}
enum Constr_representation {
  Unused,
  Independent,
  Stacked,
  StackCentered,
};

inline std::ostream &operator<<(std::ostream &os, representation const &v) {
  switch (v.index()) {
    case 0: os << "Unused" << std::get<0>(v); break;
    case 1: os << "Independent" << std::get<1>(v); break;
    case 2: os << "Stacked" << std::get<2>(v); break;
    case 3: os << "StackCentered" << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<representation> const v) { os << *v; return os; }

struct field {
  double opacity;
  uint32_t color;
  ::dessser::gen::dashboard_widget::representation representation;
  std::string column;
  Arr<std::string> factors;
  uint8_t axis;
  field(double opacity_, uint32_t color_, ::dessser::gen::dashboard_widget::representation representation_, std::string column_, Arr<std::string> factors_, uint8_t axis_) : opacity(opacity_), color(color_), representation(representation_), column(column_), factors(factors_), axis(axis_) {}
  field() = default;
};
inline bool operator==(field const &a, field const &b) {
  return a.opacity == b.opacity && a.color == b.color && a.representation == b.representation && a.column == b.column && a.factors == b.factors && a.axis == b.axis;
}

inline bool operator!=(field const &a, field const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, field const &r) {
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<field> const r) { os << *r; return os; }

struct source {
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  Arr<::dessser::gen::dashboard_widget::field> fields;
  source(dessser::gen::fq_function_name::t_ext name_, bool visible_, Arr<::dessser::gen::dashboard_widget::field> fields_) : name(name_), visible(visible_), fields(fields_) {}
  source() = default;
};
inline bool operator==(source const &a, source const &b) {
  return ::dessser::gen::fq_function_name::Deref(a.name) == ::dessser::gen::fq_function_name::Deref(b.name) && a.visible == b.visible && a.fields == b.fields;
}

inline bool operator!=(source const &a, source const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, source const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "visible:" << r.visible << ',';
  os << "fields:" << r.fields;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<source> const r) { os << *r; return os; }

struct scale : public std::variant<
  Void, // Linear
  Void // Logarithmic
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(scale const &a, scale const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Linear
    case 1: return std::get<1>(a) == std::get<1>(b); // Logarithmic
  };
  return false;
}
inline bool operator!=(scale const &a, scale const &b) {
  return !operator==(a, b);
}
enum Constr_scale {
  Linear,
  Logarithmic,
};

inline std::ostream &operator<<(std::ostream &os, scale const &v) {
  switch (v.index()) {
    case 0: os << "Linear" << std::get<0>(v); break;
    case 1: os << "Logarithmic" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<scale> const v) { os << *v; return os; }

struct axis {
  bool left;
  bool force_zero;
  ::dessser::gen::dashboard_widget::scale scale;
  axis(bool left_, bool force_zero_, ::dessser::gen::dashboard_widget::scale scale_) : left(left_), force_zero(force_zero_), scale(scale_) {}
  axis() = default;
};
inline bool operator==(axis const &a, axis const &b) {
  return a.left == b.left && a.force_zero == b.force_zero && a.scale == b.scale;
}

inline bool operator!=(axis const &a, axis const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, axis const &r) {
  os << '{';
  os << "left:" << r.left << ',';
  os << "force_zero:" << r.force_zero << ',';
  os << "scale:" << r.scale;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<axis> const r) { os << *r; return os; }

struct type : public std::variant<
  Void // Plot
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 1 };
};

inline bool operator==(type const &a, type const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Plot
  };
  return false;
}
inline bool operator!=(type const &a, type const &b) {
  return !operator==(a, b);
}
enum Constr_type {
  Plot,
};

inline std::ostream &operator<<(std::ostream &os, type const &v) {
  switch (v.index()) {
    case 0: os << "Plot" << std::get<0>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<type> const v) { os << *v; return os; }

struct chart {
  std::string title;
  ::dessser::gen::dashboard_widget::type type;
  Arr<::dessser::gen::dashboard_widget::axis> axes;
  Arr<::dessser::gen::dashboard_widget::source> sources;
  chart(std::string title_, ::dessser::gen::dashboard_widget::type type_, Arr<::dessser::gen::dashboard_widget::axis> axes_, Arr<::dessser::gen::dashboard_widget::source> sources_) : title(title_), type(type_), axes(axes_), sources(sources_) {}
  chart() = default;
};
inline bool operator==(chart const &a, chart const &b) {
  return a.title == b.title && a.type == b.type && a.axes == b.axes && a.sources == b.sources;
}

inline bool operator!=(chart const &a, chart const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, chart const &r) {
  os << '{';
  os << "title:" << r.title << ',';
  os << "type:" << r.type << ',';
  os << "axes:" << r.axes << ',';
  os << "sources:" << r.sources;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<chart> const r) { os << *r; return os; }

struct t : public std::variant<
  std::string, // Text
  ::dessser::gen::dashboard_widget::chart // Chart
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct tc1bf32b9478802aec66a4e35731c20e3 : public std::tuple<
  ::dessser::gen::dashboard_widget::representation,
  Pointer
> {
  using tuple::tuple;
  tc1bf32b9478802aec66a4e35731c20e3(std::tuple<::dessser::gen::dashboard_widget::representation, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::representation, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc1bf32b9478802aec66a4e35731c20e3 const &a, tc1bf32b9478802aec66a4e35731c20e3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc1bf32b9478802aec66a4e35731c20e3 const &a, tc1bf32b9478802aec66a4e35731c20e3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc1bf32b9478802aec66a4e35731c20e3 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc1bf32b9478802aec66a4e35731c20e3> const t) { os << *t; return os; }

struct t749cc30fe799f5ca72ede312d96197a8 : public std::tuple<
  ::dessser::gen::dashboard_widget::field,
  Pointer
> {
  using tuple::tuple;
  t749cc30fe799f5ca72ede312d96197a8(std::tuple<::dessser::gen::dashboard_widget::field, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::field, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t749cc30fe799f5ca72ede312d96197a8 const &a, t749cc30fe799f5ca72ede312d96197a8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t749cc30fe799f5ca72ede312d96197a8 const &a, t749cc30fe799f5ca72ede312d96197a8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t749cc30fe799f5ca72ede312d96197a8 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t749cc30fe799f5ca72ede312d96197a8> const t) { os << *t; return os; }

struct t98c1df55b587e112639e677d8810f238 : public std::tuple<
  ::dessser::gen::dashboard_widget::source,
  Pointer
> {
  using tuple::tuple;
  t98c1df55b587e112639e677d8810f238(std::tuple<::dessser::gen::dashboard_widget::source, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::source, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t98c1df55b587e112639e677d8810f238 const &a, t98c1df55b587e112639e677d8810f238 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t98c1df55b587e112639e677d8810f238 const &a, t98c1df55b587e112639e677d8810f238 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t98c1df55b587e112639e677d8810f238 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t98c1df55b587e112639e677d8810f238> const t) { os << *t; return os; }

struct te827b27d5f16cf2c14d368442731b974 : public std::tuple<
  ::dessser::gen::dashboard_widget::scale,
  Pointer
> {
  using tuple::tuple;
  te827b27d5f16cf2c14d368442731b974(std::tuple<::dessser::gen::dashboard_widget::scale, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::scale, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te827b27d5f16cf2c14d368442731b974 const &a, te827b27d5f16cf2c14d368442731b974 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te827b27d5f16cf2c14d368442731b974 const &a, te827b27d5f16cf2c14d368442731b974 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te827b27d5f16cf2c14d368442731b974 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te827b27d5f16cf2c14d368442731b974> const t) { os << *t; return os; }

struct t9a8d4d78c988f5d0b49fc7d7daee92e4 : public std::tuple<
  ::dessser::gen::dashboard_widget::axis,
  Pointer
> {
  using tuple::tuple;
  t9a8d4d78c988f5d0b49fc7d7daee92e4(std::tuple<::dessser::gen::dashboard_widget::axis, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::axis, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a8d4d78c988f5d0b49fc7d7daee92e4 const &a, t9a8d4d78c988f5d0b49fc7d7daee92e4 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a8d4d78c988f5d0b49fc7d7daee92e4 const &a, t9a8d4d78c988f5d0b49fc7d7daee92e4 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t9a8d4d78c988f5d0b49fc7d7daee92e4 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9a8d4d78c988f5d0b49fc7d7daee92e4> const t) { os << *t; return os; }

struct td081d579116db2384d0a1d4e0dd44fc6 : public std::tuple<
  ::dessser::gen::dashboard_widget::type,
  Pointer
> {
  using tuple::tuple;
  td081d579116db2384d0a1d4e0dd44fc6(std::tuple<::dessser::gen::dashboard_widget::type, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::type, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td081d579116db2384d0a1d4e0dd44fc6 const &a, td081d579116db2384d0a1d4e0dd44fc6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td081d579116db2384d0a1d4e0dd44fc6 const &a, td081d579116db2384d0a1d4e0dd44fc6 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td081d579116db2384d0a1d4e0dd44fc6 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td081d579116db2384d0a1d4e0dd44fc6> const t) { os << *t; return os; }

struct t62f7c15233495a7fd1923d1cb45a742f : public std::tuple<
  ::dessser::gen::dashboard_widget::chart,
  Pointer
> {
  using tuple::tuple;
  t62f7c15233495a7fd1923d1cb45a742f(std::tuple<::dessser::gen::dashboard_widget::chart, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::chart, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t62f7c15233495a7fd1923d1cb45a742f const &a, t62f7c15233495a7fd1923d1cb45a742f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t62f7c15233495a7fd1923d1cb45a742f const &a, t62f7c15233495a7fd1923d1cb45a742f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t62f7c15233495a7fd1923d1cb45a742f const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t62f7c15233495a7fd1923d1cb45a742f> const t) { os << *t; return os; }

struct t02960804d32fdda6972311266df50308 : public std::tuple<
  ::dessser::gen::dashboard_widget::t,
  Pointer
> {
  using tuple::tuple;
  t02960804d32fdda6972311266df50308(std::tuple<::dessser::gen::dashboard_widget::t, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t02960804d32fdda6972311266df50308 const &a, t02960804d32fdda6972311266df50308 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t02960804d32fdda6972311266df50308 const &a, t02960804d32fdda6972311266df50308 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t02960804d32fdda6972311266df50308 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t02960804d32fdda6972311266df50308> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::dashboard_widget::representation const &,Pointer &)> representation_to_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::field &,Pointer &)> field_to_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::source &,Pointer &)> source_to_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::scale const &,Pointer &)> scale_to_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::axis const &,Pointer &)> axis_to_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::type const &,Pointer &)> type_to_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::chart &,Pointer &)> chart_to_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::representation const &)> representation_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::field &)> field_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::source &)> source_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::scale const &)> scale_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::axis const &)> axis_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::type const &)> type_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::chart &)> chart_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::dashboard_widget::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3(Pointer &)> representation_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8(Pointer &)> field_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238(Pointer &)> source_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974(Pointer &)> scale_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4(Pointer &)> axis_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6(Pointer &)> type_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f(Pointer &)> chart_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
