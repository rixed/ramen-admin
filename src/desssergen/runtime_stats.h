#ifndef DESSSER_GEN_runtime_stats
#define DESSSER_GEN_runtime_stats
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
  uint64_t cur_groups;
  uint64_t cur_ram;
  std::optional<double> first_input;
  std::optional<double> first_output;
  double first_startup;
  std::optional<double> last_input;
  std::optional<double> last_output;
  double last_startup;
  std::optional<double> max_etime;
  uint64_t max_groups;
  uint64_t max_ram;
  std::optional<double> min_etime;
  double stats_time;
  double tot_cpu;
  uint64_t tot_extinguished_notifs;
  uint64_t tot_firing_notifs;
  uint64_t tot_full_bytes;
  uint64_t tot_full_bytes_samples;
  uint64_t tot_in_bytes;
  uint64_t tot_in_tuples;
  uint64_t tot_out_bytes;
  uint64_t tot_out_errs;
  uint64_t tot_out_filtered;
  uint64_t tot_out_tuples;
  uint64_t tot_sel_tuples;
  double tot_wait_in;
  double tot_wait_out;
  t(uint64_t cur_groups_, uint64_t cur_ram_, std::optional<double> first_input_, std::optional<double> first_output_, double first_startup_, std::optional<double> last_input_, std::optional<double> last_output_, double last_startup_, std::optional<double> max_etime_, uint64_t max_groups_, uint64_t max_ram_, std::optional<double> min_etime_, double stats_time_, double tot_cpu_, uint64_t tot_extinguished_notifs_, uint64_t tot_firing_notifs_, uint64_t tot_full_bytes_, uint64_t tot_full_bytes_samples_, uint64_t tot_in_bytes_, uint64_t tot_in_tuples_, uint64_t tot_out_bytes_, uint64_t tot_out_errs_, uint64_t tot_out_filtered_, uint64_t tot_out_tuples_, uint64_t tot_sel_tuples_, double tot_wait_in_, double tot_wait_out_) : cur_groups(cur_groups_), cur_ram(cur_ram_), first_input(first_input_), first_output(first_output_), first_startup(first_startup_), last_input(last_input_), last_output(last_output_), last_startup(last_startup_), max_etime(max_etime_), max_groups(max_groups_), max_ram(max_ram_), min_etime(min_etime_), stats_time(stats_time_), tot_cpu(tot_cpu_), tot_extinguished_notifs(tot_extinguished_notifs_), tot_firing_notifs(tot_firing_notifs_), tot_full_bytes(tot_full_bytes_), tot_full_bytes_samples(tot_full_bytes_samples_), tot_in_bytes(tot_in_bytes_), tot_in_tuples(tot_in_tuples_), tot_out_bytes(tot_out_bytes_), tot_out_errs(tot_out_errs_), tot_out_filtered(tot_out_filtered_), tot_out_tuples(tot_out_tuples_), tot_sel_tuples(tot_sel_tuples_), tot_wait_in(tot_wait_in_), tot_wait_out(tot_wait_out_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "cur_groups:" << r.cur_groups << ',';
  os << "cur_ram:" << r.cur_ram << ',';
  if (r.first_input) os << "first_input:" << r.first_input.value() << ',';
  if (r.first_output) os << "first_output:" << r.first_output.value() << ',';
  os << "first_startup:" << r.first_startup << ',';
  if (r.last_input) os << "last_input:" << r.last_input.value() << ',';
  if (r.last_output) os << "last_output:" << r.last_output.value() << ',';
  os << "last_startup:" << r.last_startup << ',';
  if (r.max_etime) os << "max_etime:" << r.max_etime.value() << ',';
  os << "max_groups:" << r.max_groups << ',';
  os << "max_ram:" << r.max_ram << ',';
  if (r.min_etime) os << "min_etime:" << r.min_etime.value() << ',';
  os << "stats_time:" << r.stats_time << ',';
  os << "tot_cpu:" << r.tot_cpu << ',';
  os << "tot_extinguished_notifs:" << r.tot_extinguished_notifs << ',';
  os << "tot_firing_notifs:" << r.tot_firing_notifs << ',';
  os << "tot_full_bytes:" << r.tot_full_bytes << ',';
  os << "tot_full_bytes_samples:" << r.tot_full_bytes_samples << ',';
  os << "tot_in_bytes:" << r.tot_in_bytes << ',';
  os << "tot_in_tuples:" << r.tot_in_tuples << ',';
  os << "tot_out_bytes:" << r.tot_out_bytes << ',';
  os << "tot_out_errs:" << r.tot_out_errs << ',';
  os << "tot_out_filtered:" << r.tot_out_filtered << ',';
  os << "tot_out_tuples:" << r.tot_out_tuples << ',';
  os << "tot_sel_tuples:" << r.tot_sel_tuples << ',';
  os << "tot_wait_in:" << r.tot_wait_in << ',';
  os << "tot_wait_out:" << r.tot_wait_out;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.cur_groups == b.cur_groups && a.cur_ram == b.cur_ram && ((a.first_input && b.first_input && a.first_input.value() == b.first_input.value()) || (!a.first_input && !b.first_input)) && ((a.first_output && b.first_output && a.first_output.value() == b.first_output.value()) || (!a.first_output && !b.first_output)) && a.first_startup == b.first_startup && ((a.last_input && b.last_input && a.last_input.value() == b.last_input.value()) || (!a.last_input && !b.last_input)) && ((a.last_output && b.last_output && a.last_output.value() == b.last_output.value()) || (!a.last_output && !b.last_output)) && a.last_startup == b.last_startup && ((a.max_etime && b.max_etime && a.max_etime.value() == b.max_etime.value()) || (!a.max_etime && !b.max_etime)) && a.max_groups == b.max_groups && a.max_ram == b.max_ram && ((a.min_etime && b.min_etime && a.min_etime.value() == b.min_etime.value()) || (!a.min_etime && !b.min_etime)) && a.stats_time == b.stats_time && a.tot_cpu == b.tot_cpu && a.tot_extinguished_notifs == b.tot_extinguished_notifs && a.tot_firing_notifs == b.tot_firing_notifs && a.tot_full_bytes == b.tot_full_bytes && a.tot_full_bytes_samples == b.tot_full_bytes_samples && a.tot_in_bytes == b.tot_in_bytes && a.tot_in_tuples == b.tot_in_tuples && a.tot_out_bytes == b.tot_out_bytes && a.tot_out_errs == b.tot_out_errs && a.tot_out_filtered == b.tot_out_filtered && a.tot_out_tuples == b.tot_out_tuples && a.tot_sel_tuples == b.tot_sel_tuples && a.tot_wait_in == b.tot_wait_in && a.tot_wait_out == b.tot_wait_out;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct ted39c8ea485719117d89516f551abd2b : public std::tuple<
  std::shared_ptr<::dessser::gen::runtime_stats::t> ,
  Pointer
> {
  using tuple::tuple;
  ted39c8ea485719117d89516f551abd2b(std::tuple<std::shared_ptr<::dessser::gen::runtime_stats::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::runtime_stats::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ted39c8ea485719117d89516f551abd2b const &a, ted39c8ea485719117d89516f551abd2b const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ted39c8ea485719117d89516f551abd2b const &a, ted39c8ea485719117d89516f551abd2b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ted39c8ea485719117d89516f551abd2b const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::runtime_stats::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::runtime_stats::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::runtime_stats::ted39c8ea485719117d89516f551abd2b(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
