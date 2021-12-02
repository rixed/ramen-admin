#ifndef DESSSER_GEN_dashboard_widget
#define DESSSER_GEN_dashboard_widget
#include <arpa/inet.h>
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
> { using variant::variant; };

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
struct field {
  uint8_t axis;
  uint32_t color;
  std::string column;
  Arr<std::string> factors;
  double opacity;
  std::shared_ptr<::dessser::gen::dashboard_widget::representation>  representation;
  field(uint8_t axis_, uint32_t color_, std::string column_, Arr<std::string> factors_, double opacity_, std::shared_ptr<::dessser::gen::dashboard_widget::representation>  representation_) : axis(axis_), color(color_), column(column_), factors(factors_), opacity(opacity_), representation(representation_) {}
  field() = default;
};
inline std::ostream &operator<<(std::ostream &os, field const &r) {
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<field> const r) { os << *r; return os; }

inline bool operator==(field const &a, field const &b) {
  return a.axis == b.axis && a.color == b.color && a.column == b.column && a.factors == b.factors && a.opacity == b.opacity && (*a.representation) == (*b.representation);
}

inline bool operator!=(field const &a, field const &b) {
  return !operator==(a, b);
}
struct source {
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  source(Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > fields_, dessser::gen::fq_function_name::t_ext name_, bool visible_) : fields(fields_), name(name_), visible(visible_) {}
  source() = default;
};
inline std::ostream &operator<<(std::ostream &os, source const &r) {
  os << '{';
  os << "fields:" << r.fields << ',';
  os << "name:" << r.name << ',';
  os << "visible:" << r.visible;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<source> const r) { os << *r; return os; }

inline bool operator==(source const &a, source const &b) {
  return a.fields == b.fields && ::dessser::gen::fq_function_name::Deref(a.name) == ::dessser::gen::fq_function_name::Deref(b.name) && a.visible == b.visible;
}

inline bool operator!=(source const &a, source const &b) {
  return !operator==(a, b);
}
struct scale : public std::variant<
  Void, // Linear
  Void // Logarithmic
> { using variant::variant; };

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
struct axis {
  bool force_zero;
  bool left;
  std::shared_ptr<::dessser::gen::dashboard_widget::scale>  scale;
  axis(bool force_zero_, bool left_, std::shared_ptr<::dessser::gen::dashboard_widget::scale>  scale_) : force_zero(force_zero_), left(left_), scale(scale_) {}
  axis() = default;
};
inline std::ostream &operator<<(std::ostream &os, axis const &r) {
  os << '{';
  os << "force_zero:" << r.force_zero << ',';
  os << "left:" << r.left << ',';
  os << "scale:" << r.scale;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<axis> const r) { os << *r; return os; }

inline bool operator==(axis const &a, axis const &b) {
  return a.force_zero == b.force_zero && a.left == b.left && (*a.scale) == (*b.scale);
}

inline bool operator!=(axis const &a, axis const &b) {
  return !operator==(a, b);
}
struct type : public std::variant<
  Void // Plot
> { using variant::variant; };

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
struct chart {
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > axes;
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > sources;
  std::string title;
  std::shared_ptr<::dessser::gen::dashboard_widget::type>  type;
  chart(Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > axes_, Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > sources_, std::string title_, std::shared_ptr<::dessser::gen::dashboard_widget::type>  type_) : axes(axes_), sources(sources_), title(title_), type(type_) {}
  chart() = default;
};
inline std::ostream &operator<<(std::ostream &os, chart const &r) {
  os << '{';
  os << "axes:" << r.axes << ',';
  os << "sources:" << r.sources << ',';
  os << "title:" << r.title << ',';
  os << "type:" << r.type;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<chart> const r) { os << *r; return os; }

inline bool operator==(chart const &a, chart const &b) {
  return a.axes == b.axes && a.sources == b.sources && a.title == b.title && (*a.type) == (*b.type);
}

inline bool operator!=(chart const &a, chart const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  std::string, // Text
  std::shared_ptr<::dessser::gen::dashboard_widget::chart>  // Chart
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

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
struct t8ef1c95fd186832d880a2244303e9cea : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::representation> ,
  Pointer
> {
  using tuple::tuple;
  t8ef1c95fd186832d880a2244303e9cea(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::representation> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::representation> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8ef1c95fd186832d880a2244303e9cea const &a, t8ef1c95fd186832d880a2244303e9cea const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8ef1c95fd186832d880a2244303e9cea const &a, t8ef1c95fd186832d880a2244303e9cea const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t8ef1c95fd186832d880a2244303e9cea const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8ef1c95fd186832d880a2244303e9cea> const t) { os << *t; return os; }

struct t14c207e65f8f77a76ec87f66e5566060 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::field> ,
  Pointer
> {
  using tuple::tuple;
  t14c207e65f8f77a76ec87f66e5566060(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::field> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::field> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t14c207e65f8f77a76ec87f66e5566060 const &a, t14c207e65f8f77a76ec87f66e5566060 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t14c207e65f8f77a76ec87f66e5566060 const &a, t14c207e65f8f77a76ec87f66e5566060 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t14c207e65f8f77a76ec87f66e5566060 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t14c207e65f8f77a76ec87f66e5566060> const t) { os << *t; return os; }

struct t97cba01e43a21515748b36fb32be3b3e : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::source> ,
  Pointer
> {
  using tuple::tuple;
  t97cba01e43a21515748b36fb32be3b3e(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::source> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::source> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t97cba01e43a21515748b36fb32be3b3e const &a, t97cba01e43a21515748b36fb32be3b3e const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t97cba01e43a21515748b36fb32be3b3e const &a, t97cba01e43a21515748b36fb32be3b3e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t97cba01e43a21515748b36fb32be3b3e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t97cba01e43a21515748b36fb32be3b3e> const t) { os << *t; return os; }

struct tf9ef46e559cc4aa51a61b6310df405c7 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,
  Pointer
> {
  using tuple::tuple;
  tf9ef46e559cc4aa51a61b6310df405c7(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::scale> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::scale> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf9ef46e559cc4aa51a61b6310df405c7 const &a, tf9ef46e559cc4aa51a61b6310df405c7 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf9ef46e559cc4aa51a61b6310df405c7 const &a, tf9ef46e559cc4aa51a61b6310df405c7 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf9ef46e559cc4aa51a61b6310df405c7 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf9ef46e559cc4aa51a61b6310df405c7> const t) { os << *t; return os; }

struct t6ac8518a7138f46f9eb6363b25e26552 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,
  Pointer
> {
  using tuple::tuple;
  t6ac8518a7138f46f9eb6363b25e26552(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::axis> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::axis> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6ac8518a7138f46f9eb6363b25e26552 const &a, t6ac8518a7138f46f9eb6363b25e26552 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6ac8518a7138f46f9eb6363b25e26552 const &a, t6ac8518a7138f46f9eb6363b25e26552 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6ac8518a7138f46f9eb6363b25e26552 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6ac8518a7138f46f9eb6363b25e26552> const t) { os << *t; return os; }

struct tb8736edae5c2876425e55b9d652a8681 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::type> ,
  Pointer
> {
  using tuple::tuple;
  tb8736edae5c2876425e55b9d652a8681(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::type> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::type> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb8736edae5c2876425e55b9d652a8681 const &a, tb8736edae5c2876425e55b9d652a8681 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb8736edae5c2876425e55b9d652a8681 const &a, tb8736edae5c2876425e55b9d652a8681 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb8736edae5c2876425e55b9d652a8681 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb8736edae5c2876425e55b9d652a8681> const t) { os << *t; return os; }

struct tef7a76372bf1c1fa490f519ad932fc70 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,
  Pointer
> {
  using tuple::tuple;
  tef7a76372bf1c1fa490f519ad932fc70(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::chart> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::chart> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tef7a76372bf1c1fa490f519ad932fc70 const &a, tef7a76372bf1c1fa490f519ad932fc70 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tef7a76372bf1c1fa490f519ad932fc70 const &a, tef7a76372bf1c1fa490f519ad932fc70 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tef7a76372bf1c1fa490f519ad932fc70 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tef7a76372bf1c1fa490f519ad932fc70> const t) { os << *t; return os; }

struct t206086bb48fe7c1f7a2a1b42bad30939 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::t> ,
  Pointer
> {
  using tuple::tuple;
  t206086bb48fe7c1f7a2a1b42bad30939(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t206086bb48fe7c1f7a2a1b42bad30939 const &a, t206086bb48fe7c1f7a2a1b42bad30939 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t206086bb48fe7c1f7a2a1b42bad30939 const &a, t206086bb48fe7c1f7a2a1b42bad30939 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t206086bb48fe7c1f7a2a1b42bad30939 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t206086bb48fe7c1f7a2a1b42bad30939> const t) { os << *t; return os; }

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
extern std::function<::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea(Pointer)> representation_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060(Pointer)> field_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e(Pointer)> source_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7(Pointer)> scale_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552(Pointer)> axis_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681(Pointer)> type_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70(Pointer)> chart_of_row_binary;
extern std::function<::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
