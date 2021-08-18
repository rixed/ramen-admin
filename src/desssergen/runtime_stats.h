#ifndef DESSSER_GEN_runtime_stats
#define DESSSER_GEN_runtime_stats
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::runtime_stats {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  double stats_time;
  double first_startup;
  double last_startup;
  std::optional<double> min_etime;
  std::optional<double> max_etime;
  std::optional<double> first_input;
  std::optional<double> last_input;
  std::optional<double> first_output;
  std::optional<double> last_output;
  uint64_t tot_in_tuples;
  uint64_t tot_sel_tuples;
  uint64_t tot_out_filtered;
  uint64_t tot_out_tuples;
  uint64_t tot_out_errs;
  uint64_t tot_full_bytes;
  uint64_t tot_full_bytes_samples;
  uint64_t cur_groups;
  uint64_t max_groups;
  uint64_t tot_in_bytes;
  uint64_t tot_out_bytes;
  double tot_wait_in;
  double tot_wait_out;
  uint64_t tot_firing_notifs;
  uint64_t tot_extinguished_notifs;
  double tot_cpu;
  uint64_t cur_ram;
  uint64_t max_ram;
  bool operator==(t const &other) const {
    return stats_time == other.stats_time && first_startup == other.first_startup && last_startup == other.last_startup && min_etime == other.min_etime && max_etime == other.max_etime && first_input == other.first_input && last_input == other.last_input && first_output == other.first_output && last_output == other.last_output && tot_in_tuples == other.tot_in_tuples && tot_sel_tuples == other.tot_sel_tuples && tot_out_filtered == other.tot_out_filtered && tot_out_tuples == other.tot_out_tuples && tot_out_errs == other.tot_out_errs && tot_full_bytes == other.tot_full_bytes && tot_full_bytes_samples == other.tot_full_bytes_samples && cur_groups == other.cur_groups && max_groups == other.max_groups && tot_in_bytes == other.tot_in_bytes && tot_out_bytes == other.tot_out_bytes && tot_wait_in == other.tot_wait_in && tot_wait_out == other.tot_wait_out && tot_firing_notifs == other.tot_firing_notifs && tot_extinguished_notifs == other.tot_extinguished_notifs && tot_cpu == other.tot_cpu && cur_ram == other.cur_ram && max_ram == other.max_ram;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "stats_time:" << r.stats_time << ',';
  os << "first_startup:" << r.first_startup << ',';
  os << "last_startup:" << r.last_startup << ',';
  os << "min_etime:" << r.min_etime << ',';
  os << "max_etime:" << r.max_etime << ',';
  os << "first_input:" << r.first_input << ',';
  os << "last_input:" << r.last_input << ',';
  os << "first_output:" << r.first_output << ',';
  os << "last_output:" << r.last_output << ',';
  os << "tot_in_tuples:" << r.tot_in_tuples << ',';
  os << "tot_sel_tuples:" << r.tot_sel_tuples << ',';
  os << "tot_out_filtered:" << r.tot_out_filtered << ',';
  os << "tot_out_tuples:" << r.tot_out_tuples << ',';
  os << "tot_out_errs:" << r.tot_out_errs << ',';
  os << "tot_full_bytes:" << r.tot_full_bytes << ',';
  os << "tot_full_bytes_samples:" << r.tot_full_bytes_samples << ',';
  os << "cur_groups:" << r.cur_groups << ',';
  os << "max_groups:" << r.max_groups << ',';
  os << "tot_in_bytes:" << r.tot_in_bytes << ',';
  os << "tot_out_bytes:" << r.tot_out_bytes << ',';
  os << "tot_wait_in:" << r.tot_wait_in << ',';
  os << "tot_wait_out:" << r.tot_wait_out << ',';
  os << "tot_firing_notifs:" << r.tot_firing_notifs << ',';
  os << "tot_extinguished_notifs:" << r.tot_extinguished_notifs << ',';
  os << "tot_cpu:" << r.tot_cpu << ',';
  os << "cur_ram:" << r.cur_ram << ',';
  os << "max_ram:" << r.max_ram;
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
