#ifndef DESSSER_GEN_alert
#define DESSSER_GEN_alert
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/fq_name.h"

namespace dessser::gen::alert {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct constant {
  dessser::gen::field_name::t_ext name;
  std::string value;
  constant(dessser::gen::field_name::t_ext name_, std::string value_) : name(name_), value(value_) {}
  constant() = default;
};
inline bool operator==(constant const &a, constant const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && a.value == b.value;
}

inline bool operator!=(constant const &a, constant const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, constant const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "value:" << r.value;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<constant> const r) { os << *r; return os; }

struct t1287f5ccd09b12d10e0e8359b374ce64 : public std::variant<
  double, // Absolute
  double // Relative
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t1287f5ccd09b12d10e0e8359b374ce64 const &a, t1287f5ccd09b12d10e0e8359b374ce64 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Absolute
    case 1: return std::get<1>(a) == std::get<1>(b); // Relative
  };
  return false;
}
inline bool operator!=(t1287f5ccd09b12d10e0e8359b374ce64 const &a, t1287f5ccd09b12d10e0e8359b374ce64 const &b) {
  return !operator==(a, b);
}
enum Constr_t1287f5ccd09b12d10e0e8359b374ce64 {
  Absolute,
  Relative,
};

inline std::ostream &operator<<(std::ostream &os, t1287f5ccd09b12d10e0e8359b374ce64 const &v) {
  switch (v.index()) {
    case 0: os << "Absolute " << std::get<0>(v); break;
    case 1: os << "Relative " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t1287f5ccd09b12d10e0e8359b374ce64> const v) { os << *v; return os; }

struct t4d94676e99bfec48ddb223ef58e339ac {
  double avg_window;
  uint32_t sample_size;
  double percentile;
  uint32_t seasonality;
  double smooth_factor;
  ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 max_distance;
  t4d94676e99bfec48ddb223ef58e339ac(double avg_window_, uint32_t sample_size_, double percentile_, uint32_t seasonality_, double smooth_factor_, ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 max_distance_) : avg_window(avg_window_), sample_size(sample_size_), percentile(percentile_), seasonality(seasonality_), smooth_factor(smooth_factor_), max_distance(max_distance_) {}
  t4d94676e99bfec48ddb223ef58e339ac() = default;
};
inline bool operator==(t4d94676e99bfec48ddb223ef58e339ac const &a, t4d94676e99bfec48ddb223ef58e339ac const &b) {
  return a.avg_window == b.avg_window && a.sample_size == b.sample_size && a.percentile == b.percentile && a.seasonality == b.seasonality && a.smooth_factor == b.smooth_factor && a.max_distance == b.max_distance;
}

inline bool operator!=(t4d94676e99bfec48ddb223ef58e339ac const &a, t4d94676e99bfec48ddb223ef58e339ac const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4d94676e99bfec48ddb223ef58e339ac const &r) {
  os << '{';
  os << "avg_window:" << r.avg_window << ',';
  os << "sample_size:" << r.sample_size << ',';
  os << "percentile:" << r.percentile << ',';
  os << "seasonality:" << r.seasonality << ',';
  os << "smooth_factor:" << r.smooth_factor << ',';
  os << "max_distance:" << r.max_distance;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4d94676e99bfec48ddb223ef58e339ac> const r) { os << *r; return os; }

struct threshold : public std::variant<
  double, // Constant
  ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac // Baseline
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(threshold const &a, threshold const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Constant
    case 1: return std::get<1>(a) == std::get<1>(b); // Baseline
  };
  return false;
}
inline bool operator!=(threshold const &a, threshold const &b) {
  return !operator==(a, b);
}
enum Constr_threshold {
  Constant,
  Baseline,
};

inline std::ostream &operator<<(std::ostream &os, threshold const &v) {
  switch (v.index()) {
    case 0: os << "Constant " << std::get<0>(v); break;
    case 1: os << "Baseline " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<threshold> const v) { os << *v; return os; }

struct t {
  dessser::gen::fq_name::t_ext table;
  dessser::gen::field_name::t_ext column;
  bool enabled;
  Arr<dessser::gen::simple_filter::t_ext> where;
  std::optional<Arr<dessser::gen::field_name::t_ext>> group_by;
  Arr<dessser::gen::simple_filter::t_ext> having;
  ::dessser::gen::alert::threshold threshold;
  double hysteresis;
  double duration;
  double ratio;
  double time_step;
  Arr<dessser::gen::field_name::t_ext> tops;
  Arr<dessser::gen::field_name::t_ext> carry_fields;
  Arr<::dessser::gen::alert::constant> carry_csts;
  std::string id;
  std::string desc_title;
  std::string desc_firing;
  std::string desc_recovery;
  t(dessser::gen::fq_name::t_ext table_, dessser::gen::field_name::t_ext column_, bool enabled_, Arr<dessser::gen::simple_filter::t_ext> where_, std::optional<Arr<dessser::gen::field_name::t_ext>> group_by_, Arr<dessser::gen::simple_filter::t_ext> having_, ::dessser::gen::alert::threshold threshold_, double hysteresis_, double duration_, double ratio_, double time_step_, Arr<dessser::gen::field_name::t_ext> tops_, Arr<dessser::gen::field_name::t_ext> carry_fields_, Arr<::dessser::gen::alert::constant> carry_csts_, std::string id_, std::string desc_title_, std::string desc_firing_, std::string desc_recovery_) : table(table_), column(column_), enabled(enabled_), where(where_), group_by(group_by_), having(having_), threshold(threshold_), hysteresis(hysteresis_), duration(duration_), ratio(ratio_), time_step(time_step_), tops(tops_), carry_fields(carry_fields_), carry_csts(carry_csts_), id(id_), desc_title(desc_title_), desc_firing(desc_firing_), desc_recovery(desc_recovery_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::fq_name::Deref(a.table) == ::dessser::gen::fq_name::Deref(b.table) && ::dessser::gen::field_name::Deref(a.column) == ::dessser::gen::field_name::Deref(b.column) && a.enabled == b.enabled && a.where == b.where && ((a.group_by && b.group_by && a.group_by.value() == b.group_by.value()) || (!a.group_by && !b.group_by)) && a.having == b.having && a.threshold == b.threshold && a.hysteresis == b.hysteresis && a.duration == b.duration && a.ratio == b.ratio && a.time_step == b.time_step && a.tops == b.tops && a.carry_fields == b.carry_fields && a.carry_csts == b.carry_csts && a.id == b.id && a.desc_title == b.desc_title && a.desc_firing == b.desc_firing && a.desc_recovery == b.desc_recovery;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "table:" << r.table << ',';
  os << "column:" << r.column << ',';
  os << "enabled:" << r.enabled << ',';
  os << "where:" << r.where << ',';
  if (r.group_by) os << "group_by:" << r.group_by.value() << ',';
  os << "having:" << r.having << ',';
  os << "threshold:" << r.threshold << ',';
  os << "hysteresis:" << r.hysteresis << ',';
  os << "duration:" << r.duration << ',';
  os << "ratio:" << r.ratio << ',';
  os << "time_step:" << r.time_step << ',';
  os << "tops:" << r.tops << ',';
  os << "carry_fields:" << r.carry_fields << ',';
  os << "carry_csts:" << r.carry_csts << ',';
  os << "id:" << r.id << ',';
  os << "desc_title:" << r.desc_title << ',';
  os << "desc_firing:" << r.desc_firing << ',';
  os << "desc_recovery:" << r.desc_recovery;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tbba7e1164dfe2bee4f085ba6914431f0 : public std::tuple<
  ::dessser::gen::alert::constant,
  Pointer
> {
  using tuple::tuple;
  tbba7e1164dfe2bee4f085ba6914431f0(std::tuple<::dessser::gen::alert::constant, Pointer> p)
    : std::tuple<::dessser::gen::alert::constant, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tbba7e1164dfe2bee4f085ba6914431f0 const &a, tbba7e1164dfe2bee4f085ba6914431f0 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tbba7e1164dfe2bee4f085ba6914431f0 const &a, tbba7e1164dfe2bee4f085ba6914431f0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tbba7e1164dfe2bee4f085ba6914431f0 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tbba7e1164dfe2bee4f085ba6914431f0> const t) { os << *t; return os; }

struct t9c5031c324db4d785b63a3fba0d407ed : public std::tuple<
  ::dessser::gen::alert::threshold,
  Pointer
> {
  using tuple::tuple;
  t9c5031c324db4d785b63a3fba0d407ed(std::tuple<::dessser::gen::alert::threshold, Pointer> p)
    : std::tuple<::dessser::gen::alert::threshold, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9c5031c324db4d785b63a3fba0d407ed const &a, t9c5031c324db4d785b63a3fba0d407ed const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9c5031c324db4d785b63a3fba0d407ed const &a, t9c5031c324db4d785b63a3fba0d407ed const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t9c5031c324db4d785b63a3fba0d407ed const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9c5031c324db4d785b63a3fba0d407ed> const t) { os << *t; return os; }

struct tcfd366a0398a3b3e2eef85934996309d : public std::tuple<
  ::dessser::gen::alert::t,
  Pointer
> {
  using tuple::tuple;
  tcfd366a0398a3b3e2eef85934996309d(std::tuple<::dessser::gen::alert::t, Pointer> p)
    : std::tuple<::dessser::gen::alert::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcfd366a0398a3b3e2eef85934996309d const &a, tcfd366a0398a3b3e2eef85934996309d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcfd366a0398a3b3e2eef85934996309d const &a, tcfd366a0398a3b3e2eef85934996309d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tcfd366a0398a3b3e2eef85934996309d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcfd366a0398a3b3e2eef85934996309d> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alert::constant &,Pointer &)> constant_to_row_binary;
extern std::function<Pointer(::dessser::gen::alert::threshold const &,Pointer &)> threshold_to_row_binary;
extern std::function<Pointer(::dessser::gen::alert::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::alert::constant &)> constant_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::alert::threshold const &)> threshold_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::alert::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::alert::tbba7e1164dfe2bee4f085ba6914431f0(Pointer &)> constant_of_row_binary;
extern std::function<::dessser::gen::alert::t9c5031c324db4d785b63a3fba0d407ed(Pointer &)> threshold_of_row_binary;
extern std::function<::dessser::gen::alert::tcfd366a0398a3b3e2eef85934996309d(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::alert::tcfd366a0398a3b3e2eef85934996309d(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::alert::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
