#ifndef DESSSER_GEN_sync_client_msg
#define DESSSER_GEN_sync_client_msg
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/sync_client_cmd.h"

namespace dessser::gen::sync_client_msg {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::sync_client_cmd::t_ext cmd;
  bool confirm_success;
  bool echo;
  uint32_t seq;
  t(dessser::gen::sync_client_cmd::t_ext cmd_, bool confirm_success_, bool echo_, uint32_t seq_) : cmd(cmd_), confirm_success(confirm_success_), echo(echo_), seq(seq_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::sync_client_cmd::Deref(a.cmd) == ::dessser::gen::sync_client_cmd::Deref(b.cmd) && a.confirm_success == b.confirm_success && a.echo == b.echo && a.seq == b.seq;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "cmd:" << r.cmd << ',';
  os << "confirm_success:" << r.confirm_success << ',';
  os << "echo:" << r.echo << ',';
  os << "seq:" << r.seq;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tfe3f0576fe9e9064fe3aa37bd76eb46a : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_client_msg::t> ,
  Pointer
> {
  using tuple::tuple;
  tfe3f0576fe9e9064fe3aa37bd76eb46a(std::tuple<std::shared_ptr<::dessser::gen::sync_client_msg::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_client_msg::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfe3f0576fe9e9064fe3aa37bd76eb46a const &a, tfe3f0576fe9e9064fe3aa37bd76eb46a const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfe3f0576fe9e9064fe3aa37bd76eb46a const &a, tfe3f0576fe9e9064fe3aa37bd76eb46a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tfe3f0576fe9e9064fe3aa37bd76eb46a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tfe3f0576fe9e9064fe3aa37bd76eb46a> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_client_msg::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> of_row_binary;
extern std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
