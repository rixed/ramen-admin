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
  std::shared_ptr<::dessser::gen::dashboard_widget::representation>  representation;
  std::string column;
  Arr<std::string> factors;
  uint8_t axis;
  field(double opacity_, uint32_t color_, std::shared_ptr<::dessser::gen::dashboard_widget::representation>  representation_, std::string column_, Arr<std::string> factors_, uint8_t axis_) : opacity(opacity_), color(color_), representation(representation_), column(column_), factors(factors_), axis(axis_) {}
  field() = default;
};
inline bool operator==(field const &a, field const &b) {
  return a.opacity == b.opacity && a.color == b.color && (*a.representation) == (*b.representation) && a.column == b.column && a.factors == b.factors && a.axis == b.axis;
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
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > fields;
  source(dessser::gen::fq_function_name::t_ext name_, bool visible_, Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > fields_) : name(name_), visible(visible_), fields(fields_) {}
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
  std::shared_ptr<::dessser::gen::dashboard_widget::scale>  scale;
  axis(bool left_, bool force_zero_, std::shared_ptr<::dessser::gen::dashboard_widget::scale>  scale_) : left(left_), force_zero(force_zero_), scale(scale_) {}
  axis() = default;
};
inline bool operator==(axis const &a, axis const &b) {
  return a.left == b.left && a.force_zero == b.force_zero && (*a.scale) == (*b.scale);
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
  std::shared_ptr<::dessser::gen::dashboard_widget::type>  type;
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > axes;
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > sources;
  chart(std::string title_, std::shared_ptr<::dessser::gen::dashboard_widget::type>  type_, Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > axes_, Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > sources_) : title(title_), type(type_), axes(axes_), sources(sources_) {}
  chart() = default;
};
inline bool operator==(chart const &a, chart const &b) {
  return a.title == b.title && (*a.type) == (*b.type) && a.axes == b.axes && a.sources == b.sources;
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
  std::shared_ptr<::dessser::gen::dashboard_widget::chart>  // Chart
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Text
    case 1: return (*std::get<1>(a)) == (*std::get<1>(b)); // Chart
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

struct t945b5fb3b836d2a43f805e6f4355d00c : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::representation> ,
  Pointer
> {
  using tuple::tuple;
  t945b5fb3b836d2a43f805e6f4355d00c(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::representation> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::representation> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t945b5fb3b836d2a43f805e6f4355d00c const &a, t945b5fb3b836d2a43f805e6f4355d00c const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t945b5fb3b836d2a43f805e6f4355d00c const &a, t945b5fb3b836d2a43f805e6f4355d00c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t945b5fb3b836d2a43f805e6f4355d00c const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t945b5fb3b836d2a43f805e6f4355d00c> const t) { os << *t; return os; }

struct tcdb2d0cead9dfbfdfb999905d0e0abf4 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::field> ,
  Pointer
> {
  using tuple::tuple;
  tcdb2d0cead9dfbfdfb999905d0e0abf4(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::field> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::field> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcdb2d0cead9dfbfdfb999905d0e0abf4 const &a, tcdb2d0cead9dfbfdfb999905d0e0abf4 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcdb2d0cead9dfbfdfb999905d0e0abf4 const &a, tcdb2d0cead9dfbfdfb999905d0e0abf4 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tcdb2d0cead9dfbfdfb999905d0e0abf4 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcdb2d0cead9dfbfdfb999905d0e0abf4> const t) { os << *t; return os; }

struct tca96cdae6bc4278a47336118841a27ae : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::source> ,
  Pointer
> {
  using tuple::tuple;
  tca96cdae6bc4278a47336118841a27ae(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::source> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::source> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tca96cdae6bc4278a47336118841a27ae const &a, tca96cdae6bc4278a47336118841a27ae const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tca96cdae6bc4278a47336118841a27ae const &a, tca96cdae6bc4278a47336118841a27ae const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tca96cdae6bc4278a47336118841a27ae const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tca96cdae6bc4278a47336118841a27ae> const t) { os << *t; return os; }

struct t416f15a8b2d514fc885764ab28b5e70f : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,
  Pointer
> {
  using tuple::tuple;
  t416f15a8b2d514fc885764ab28b5e70f(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::scale> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::scale> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t416f15a8b2d514fc885764ab28b5e70f const &a, t416f15a8b2d514fc885764ab28b5e70f const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t416f15a8b2d514fc885764ab28b5e70f const &a, t416f15a8b2d514fc885764ab28b5e70f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t416f15a8b2d514fc885764ab28b5e70f const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t416f15a8b2d514fc885764ab28b5e70f> const t) { os << *t; return os; }

struct t4c6caa6620f6f91a65b92915a2abd7f0 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,
  Pointer
> {
  using tuple::tuple;
  t4c6caa6620f6f91a65b92915a2abd7f0(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::axis> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::axis> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4c6caa6620f6f91a65b92915a2abd7f0 const &a, t4c6caa6620f6f91a65b92915a2abd7f0 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4c6caa6620f6f91a65b92915a2abd7f0 const &a, t4c6caa6620f6f91a65b92915a2abd7f0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4c6caa6620f6f91a65b92915a2abd7f0 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4c6caa6620f6f91a65b92915a2abd7f0> const t) { os << *t; return os; }

struct tf3a8910aed7f828bbd9860f996df6e62 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::type> ,
  Pointer
> {
  using tuple::tuple;
  tf3a8910aed7f828bbd9860f996df6e62(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::type> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::type> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf3a8910aed7f828bbd9860f996df6e62 const &a, tf3a8910aed7f828bbd9860f996df6e62 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf3a8910aed7f828bbd9860f996df6e62 const &a, tf3a8910aed7f828bbd9860f996df6e62 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf3a8910aed7f828bbd9860f996df6e62 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf3a8910aed7f828bbd9860f996df6e62> const t) { os << *t; return os; }

struct t70bc3c9f630046e2593504ce8a2695cc : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,
  Pointer
> {
  using tuple::tuple;
  t70bc3c9f630046e2593504ce8a2695cc(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::chart> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::chart> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t70bc3c9f630046e2593504ce8a2695cc const &a, t70bc3c9f630046e2593504ce8a2695cc const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t70bc3c9f630046e2593504ce8a2695cc const &a, t70bc3c9f630046e2593504ce8a2695cc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t70bc3c9f630046e2593504ce8a2695cc const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t70bc3c9f630046e2593504ce8a2695cc> const t) { os << *t; return os; }

struct tcedbe6db9a2ca1abdf03f15044f3916c : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::t> ,
  Pointer
> {
  using tuple::tuple;
  tcedbe6db9a2ca1abdf03f15044f3916c(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcedbe6db9a2ca1abdf03f15044f3916c const &a, tcedbe6db9a2ca1abdf03f15044f3916c const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcedbe6db9a2ca1abdf03f15044f3916c const &a, tcedbe6db9a2ca1abdf03f15044f3916c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tcedbe6db9a2ca1abdf03f15044f3916c const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcedbe6db9a2ca1abdf03f15044f3916c> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::representation> ,Pointer)> representation_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::field> ,Pointer)> field_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::source> ,Pointer)> source_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,Pointer)> scale_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,Pointer)> axis_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::type> ,Pointer)> type_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,Pointer)> chart_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::representation> )> representation_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::field> )> field_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::source> )> source_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::scale> )> scale_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::axis> )> axis_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::type> )> type_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::chart> )> chart_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t945b5fb3b836d2a43f805e6f4355d00c(Pointer)> representation_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tcdb2d0cead9dfbfdfb999905d0e0abf4(Pointer)> field_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tca96cdae6bc4278a47336118841a27ae(Pointer)> source_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t416f15a8b2d514fc885764ab28b5e70f(Pointer)> scale_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t4c6caa6620f6f91a65b92915a2abd7f0(Pointer)> axis_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tf3a8910aed7f828bbd9860f996df6e62(Pointer)> type_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t70bc3c9f630046e2593504ce8a2695cc(Pointer)> chart_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tcedbe6db9a2ca1abdf03f15044f3916c(Pointer)> of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tcedbe6db9a2ca1abdf03f15044f3916c(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
