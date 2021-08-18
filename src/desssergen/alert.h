#ifndef DESSSER_GEN_alert
#define DESSSER_GEN_alert
#include <arpa/inet.h>
#include <functional>
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
struct t8bc49a7c0845592f1da677dadb19d7b9 : public std::variant<
  double,
  double
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t8bc49a7c0845592f1da677dadb19d7b9 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t544a15e8f8751dfc49c4f9b48bdf42f0 {
  double avg_window;
  uint32_t sample_size;
  double percentile;
  uint32_t seasonality;
  double smooth_factor;
  t8bc49a7c0845592f1da677dadb19d7b9 max_distance;
  bool operator==(t544a15e8f8751dfc49c4f9b48bdf42f0 const &other) const {
    return avg_window == other.avg_window && sample_size == other.sample_size && percentile == other.percentile && seasonality == other.seasonality && smooth_factor == other.smooth_factor && max_distance == other.max_distance;
  }
};
inline std::ostream &operator<<(std::ostream &os, t544a15e8f8751dfc49c4f9b48bdf42f0 const &r) {
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

struct t0dfb4ea024145a5cd5544ed59acd06d6 : public std::variant<
  double,
  t544a15e8f8751dfc49c4f9b48bdf42f0
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t0dfb4ea024145a5cd5544ed59acd06d6 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  std::string
> t7d737a471b58c17b56f5c31f8c6e717d;

struct t {
  dessser::gen::fq_name::t_ext table;
  dessser::gen::field_name::t_ext column;
  bool enabled;
  Lst<dessser::gen::simple_filter::t_ext> where;
  std::optional<Lst<dessser::gen::field_name::t_ext>> group_by;
  Lst<dessser::gen::simple_filter::t_ext> having;
  t0dfb4ea024145a5cd5544ed59acd06d6 threshold;
  double hysteresis;
  double duration;
  double ratio;
  double time_step;
  Lst<dessser::gen::field_name::t_ext> tops;
  Lst<dessser::gen::field_name::t_ext> carry_fields;
  Lst<t7d737a471b58c17b56f5c31f8c6e717d> carry_csts;
  std::string id;
  std::string desc_title;
  std::string desc_firing;
  std::string desc_recovery;
  bool operator==(t const &other) const {
    return table == other.table && column == other.column && enabled == other.enabled && where == other.where && group_by == other.group_by && having == other.having && threshold == other.threshold && hysteresis == other.hysteresis && duration == other.duration && ratio == other.ratio && time_step == other.time_step && tops == other.tops && carry_fields == other.carry_fields && carry_csts == other.carry_csts && id == other.id && desc_title == other.desc_title && desc_firing == other.desc_firing && desc_recovery == other.desc_recovery;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "table:" << r.table << ',';
  os << "column:" << r.column << ',';
  os << "enabled:" << r.enabled << ',';
  os << "where:" << r.where << ',';
  os << "group-by:" << r.group_by << ',';
  os << "having:" << r.having << ',';
  os << "threshold:" << r.threshold << ',';
  os << "hysteresis:" << r.hysteresis << ',';
  os << "duration:" << r.duration << ',';
  os << "ratio:" << r.ratio << ',';
  os << "time-step:" << r.time_step << ',';
  os << "tops:" << r.tops << ',';
  os << "carry-fields:" << r.carry_fields << ',';
  os << "carry-csts:" << r.carry_csts << ',';
  os << "id:" << r.id << ',';
  os << "desc-title:" << r.desc_title << ',';
  os << "desc-firing:" << r.desc_firing << ',';
  os << "desc-recovery:" << r.desc_recovery;
  os << '}';
  return os;
}

typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
