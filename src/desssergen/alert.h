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
typedef std::tuple<
  dessser::gen::field_name::t_ext,
  std::string
> t7d737a471b58c17b56f5c31f8c6e717d;

struct t6429737710ee6dfa45554f94e4dae501 : public std::variant<
  double,
  double
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t6429737710ee6dfa45554f94e4dae501 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t7e204ba6cbd6ac534eec586ab04c0d36 {
  double avg_window;
  ::dessser::gen::alert::t6429737710ee6dfa45554f94e4dae501 max_distance;
  double percentile;
  uint32_t sample_size;
  uint32_t seasonality;
  double smooth_factor;
  bool operator==(t7e204ba6cbd6ac534eec586ab04c0d36 const &other) const {
    return avg_window == other.avg_window && max_distance == other.max_distance && percentile == other.percentile && sample_size == other.sample_size && seasonality == other.seasonality && smooth_factor == other.smooth_factor;
  }
};
inline std::ostream &operator<<(std::ostream &os, t7e204ba6cbd6ac534eec586ab04c0d36 const &r) {
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

struct t5a4aa402f4219918c5e2ea767413a5e5 : public std::variant<
  double,
  ::dessser::gen::alert::t7e204ba6cbd6ac534eec586ab04c0d36
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t5a4aa402f4219918c5e2ea767413a5e5 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> carry_csts;
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
  ::dessser::gen::alert::t5a4aa402f4219918c5e2ea767413a5e5 threshold;
  double time_step;
  Lst<dessser::gen::field_name::t_ext> tops;
  Lst<dessser::gen::simple_filter::t_ext> where;
  bool operator==(t const &other) const {
    return carry_csts == other.carry_csts && carry_fields == other.carry_fields && column == other.column && desc_firing == other.desc_firing && desc_recovery == other.desc_recovery && desc_title == other.desc_title && duration == other.duration && enabled == other.enabled && group_by == other.group_by && having == other.having && hysteresis == other.hysteresis && id == other.id && ratio == other.ratio && table == other.table && threshold == other.threshold && time_step == other.time_step && tops == other.tops && where == other.where;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "carry-csts:" << r.carry_csts << ',';
  os << "carry-fields:" << r.carry_fields << ',';
  os << "column:" << r.column << ',';
  os << "desc-firing:" << r.desc_firing << ',';
  os << "desc-recovery:" << r.desc_recovery << ',';
  os << "desc-title:" << r.desc_title << ',';
  os << "duration:" << r.duration << ',';
  os << "enabled:" << r.enabled << ',';
  os << "group-by:" << r.group_by << ',';
  os << "having:" << r.having << ',';
  os << "hysteresis:" << r.hysteresis << ',';
  os << "id:" << r.id << ',';
  os << "ratio:" << r.ratio << ',';
  os << "table:" << r.table << ',';
  os << "threshold:" << r.threshold << ',';
  os << "time-step:" << r.time_step << ',';
  os << "tops:" << r.tops << ',';
  os << "where:" << r.where;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::alert::t*,
  Pointer
> t9dbb79f443cdcf3340bfdfbf1b06c337;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alert::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alert::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
