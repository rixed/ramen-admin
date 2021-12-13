#ifndef DESSSER_GEN_alert
#define DESSSER_GEN_alert
#include <arpa/inet.h>
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

struct td771ddde7c5e379015a4c13cee45ad3e : public std::variant<
  double, // Absolute
  double // Relative
> { using variant::variant; };

inline bool operator==(td771ddde7c5e379015a4c13cee45ad3e const &a, td771ddde7c5e379015a4c13cee45ad3e const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Absolute
    case 1: return std::get<1>(a) == std::get<1>(b); // Relative
  };
  return false;
}
inline bool operator!=(td771ddde7c5e379015a4c13cee45ad3e const &a, td771ddde7c5e379015a4c13cee45ad3e const &b) {
  return !operator==(a, b);
}
enum Constr_td771ddde7c5e379015a4c13cee45ad3e {
  Absolute,
  Relative,
};

inline std::ostream &operator<<(std::ostream &os, td771ddde7c5e379015a4c13cee45ad3e const &v) {
  switch (v.index()) {
    case 0: os << "Absolute " << std::get<0>(v); break;
    case 1: os << "Relative " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td771ddde7c5e379015a4c13cee45ad3e> const v) { os << *v; return os; }

struct tbe2e56baf82b7af4d9ea2714b1b36b50 {
  double avg_window;
  ::dessser::gen::alert::td771ddde7c5e379015a4c13cee45ad3e max_distance;
  double percentile;
  uint32_t sample_size;
  uint32_t seasonality;
  double smooth_factor;
  tbe2e56baf82b7af4d9ea2714b1b36b50(double avg_window_, ::dessser::gen::alert::td771ddde7c5e379015a4c13cee45ad3e max_distance_, double percentile_, uint32_t sample_size_, uint32_t seasonality_, double smooth_factor_) : avg_window(avg_window_), max_distance(max_distance_), percentile(percentile_), sample_size(sample_size_), seasonality(seasonality_), smooth_factor(smooth_factor_) {}
  tbe2e56baf82b7af4d9ea2714b1b36b50() = default;
};
inline bool operator==(tbe2e56baf82b7af4d9ea2714b1b36b50 const &a, tbe2e56baf82b7af4d9ea2714b1b36b50 const &b) {
  return a.avg_window == b.avg_window && a.max_distance == b.max_distance && a.percentile == b.percentile && a.sample_size == b.sample_size && a.seasonality == b.seasonality && a.smooth_factor == b.smooth_factor;
}

inline bool operator!=(tbe2e56baf82b7af4d9ea2714b1b36b50 const &a, tbe2e56baf82b7af4d9ea2714b1b36b50 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tbe2e56baf82b7af4d9ea2714b1b36b50 const &r) {
  os << '{';
  os << "avg_window:" << r.avg_window << ',';
  os << "max_distance:" << r.max_distance << ',';
  os << "percentile:" << r.percentile << ',';
  os << "sample_size:" << r.sample_size << ',';
  os << "seasonality:" << r.seasonality << ',';
  os << "smooth_factor:" << r.smooth_factor;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tbe2e56baf82b7af4d9ea2714b1b36b50> const r) { os << *r; return os; }

struct threshold : public std::variant<
  double, // Constant
  ::dessser::gen::alert::tbe2e56baf82b7af4d9ea2714b1b36b50 // Baseline
> { using variant::variant; };

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
  Lst<std::shared_ptr<::dessser::gen::alert::constant> > carry_csts;
  Lst<dessser::gen::field_name::t_ext> carry_fields;
  dessser::gen::field_name::t_ext column;
  std::string desc_firing;
  std::string desc_recovery;
  std::string desc_title;
  double duration;
  bool enabled;
  std::optional<Lst<dessser::gen::field_name::t_ext>> group_by;
  Lst<dessser::gen::simple_filter::t_ext> having;
  double hysteresis;
  std::string id;
  double ratio;
  dessser::gen::fq_name::t_ext table;
  std::shared_ptr<::dessser::gen::alert::threshold>  threshold;
  double time_step;
  Lst<dessser::gen::field_name::t_ext> tops;
  Lst<dessser::gen::simple_filter::t_ext> where;
  t(Lst<std::shared_ptr<::dessser::gen::alert::constant> > carry_csts_, Lst<dessser::gen::field_name::t_ext> carry_fields_, dessser::gen::field_name::t_ext column_, std::string desc_firing_, std::string desc_recovery_, std::string desc_title_, double duration_, bool enabled_, std::optional<Lst<dessser::gen::field_name::t_ext>> group_by_, Lst<dessser::gen::simple_filter::t_ext> having_, double hysteresis_, std::string id_, double ratio_, dessser::gen::fq_name::t_ext table_, std::shared_ptr<::dessser::gen::alert::threshold>  threshold_, double time_step_, Lst<dessser::gen::field_name::t_ext> tops_, Lst<dessser::gen::simple_filter::t_ext> where_) : carry_csts(carry_csts_), carry_fields(carry_fields_), column(column_), desc_firing(desc_firing_), desc_recovery(desc_recovery_), desc_title(desc_title_), duration(duration_), enabled(enabled_), group_by(group_by_), having(having_), hysteresis(hysteresis_), id(id_), ratio(ratio_), table(table_), threshold(threshold_), time_step(time_step_), tops(tops_), where(where_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.carry_csts == b.carry_csts && a.carry_fields == b.carry_fields && ::dessser::gen::field_name::Deref(a.column) == ::dessser::gen::field_name::Deref(b.column) && a.desc_firing == b.desc_firing && a.desc_recovery == b.desc_recovery && a.desc_title == b.desc_title && a.duration == b.duration && a.enabled == b.enabled && ((a.group_by && b.group_by && a.group_by.value() == b.group_by.value()) || (!a.group_by && !b.group_by)) && a.having == b.having && a.hysteresis == b.hysteresis && a.id == b.id && a.ratio == b.ratio && ::dessser::gen::fq_name::Deref(a.table) == ::dessser::gen::fq_name::Deref(b.table) && (*a.threshold) == (*b.threshold) && a.time_step == b.time_step && a.tops == b.tops && a.where == b.where;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "carry_csts:" << r.carry_csts << ',';
  os << "carry_fields:" << r.carry_fields << ',';
  os << "column:" << r.column << ',';
  os << "desc_firing:" << r.desc_firing << ',';
  os << "desc_recovery:" << r.desc_recovery << ',';
  os << "desc_title:" << r.desc_title << ',';
  os << "duration:" << r.duration << ',';
  os << "enabled:" << r.enabled << ',';
  if (r.group_by) os << "group_by:" << r.group_by.value() << ',';
  os << "having:" << r.having << ',';
  os << "hysteresis:" << r.hysteresis << ',';
  os << "id:" << r.id << ',';
  os << "ratio:" << r.ratio << ',';
  os << "table:" << r.table << ',';
  os << "threshold:" << r.threshold << ',';
  os << "time_step:" << r.time_step << ',';
  os << "tops:" << r.tops << ',';
  os << "where:" << r.where;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t0bfcffcbe1f8fa26793acf604a6fe904 : public std::tuple<
  std::shared_ptr<::dessser::gen::alert::constant> ,
  Pointer
> {
  using tuple::tuple;
  t0bfcffcbe1f8fa26793acf604a6fe904(std::tuple<std::shared_ptr<::dessser::gen::alert::constant> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alert::constant> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0bfcffcbe1f8fa26793acf604a6fe904 const &a, t0bfcffcbe1f8fa26793acf604a6fe904 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0bfcffcbe1f8fa26793acf604a6fe904 const &a, t0bfcffcbe1f8fa26793acf604a6fe904 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0bfcffcbe1f8fa26793acf604a6fe904 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0bfcffcbe1f8fa26793acf604a6fe904> const t) { os << *t; return os; }

struct t55387dac503088b8cd86859bdfba5c91 : public std::tuple<
  std::shared_ptr<::dessser::gen::alert::threshold> ,
  Pointer
> {
  using tuple::tuple;
  t55387dac503088b8cd86859bdfba5c91(std::tuple<std::shared_ptr<::dessser::gen::alert::threshold> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alert::threshold> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t55387dac503088b8cd86859bdfba5c91 const &a, t55387dac503088b8cd86859bdfba5c91 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t55387dac503088b8cd86859bdfba5c91 const &a, t55387dac503088b8cd86859bdfba5c91 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t55387dac503088b8cd86859bdfba5c91 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t55387dac503088b8cd86859bdfba5c91> const t) { os << *t; return os; }

struct tc6d52773763d322654577a54bd0001f6 : public std::tuple<
  std::shared_ptr<::dessser::gen::alert::t> ,
  Pointer
> {
  using tuple::tuple;
  tc6d52773763d322654577a54bd0001f6(std::tuple<std::shared_ptr<::dessser::gen::alert::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alert::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc6d52773763d322654577a54bd0001f6 const &a, tc6d52773763d322654577a54bd0001f6 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc6d52773763d322654577a54bd0001f6 const &a, tc6d52773763d322654577a54bd0001f6 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc6d52773763d322654577a54bd0001f6 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc6d52773763d322654577a54bd0001f6> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alert::constant> ,Pointer)> constant_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alert::threshold> ,Pointer)> threshold_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alert::constant> )> constant_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alert::threshold> )> threshold_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alert::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904(Pointer)> constant_of_row_binary;
extern std::function<::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91(Pointer)> threshold_of_row_binary;
extern std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> of_row_binary;
extern std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
