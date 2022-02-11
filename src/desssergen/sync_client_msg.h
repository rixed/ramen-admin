#ifndef DESSSER_GEN_sync_client_msg
#define DESSSER_GEN_sync_client_msg
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
  uint32_t seq;
  bool confirm_success;
  bool echo;
  dessser::gen::sync_client_cmd::t_ext cmd;
  t(uint32_t seq_, bool confirm_success_, bool echo_, dessser::gen::sync_client_cmd::t_ext cmd_) : seq(seq_), confirm_success(confirm_success_), echo(echo_), cmd(cmd_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.seq == b.seq && a.confirm_success == b.confirm_success && a.echo == b.echo && ::dessser::gen::sync_client_cmd::Deref(a.cmd) == ::dessser::gen::sync_client_cmd::Deref(b.cmd);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "seq:" << r.seq << ',';
  os << "confirm_success:" << r.confirm_success << ',';
  os << "echo:" << r.echo << ',';
  os << "cmd:" << r.cmd;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t10fccc1fc82a483b9253f6641bf88774 : public std::tuple<
  ::dessser::gen::sync_client_msg::t,
  Pointer
> {
  using tuple::tuple;
  t10fccc1fc82a483b9253f6641bf88774(std::tuple<::dessser::gen::sync_client_msg::t, Pointer> p)
    : std::tuple<::dessser::gen::sync_client_msg::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t10fccc1fc82a483b9253f6641bf88774 const &a, t10fccc1fc82a483b9253f6641bf88774 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t10fccc1fc82a483b9253f6641bf88774 const &a, t10fccc1fc82a483b9253f6641bf88774 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t10fccc1fc82a483b9253f6641bf88774 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t10fccc1fc82a483b9253f6641bf88774> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_client_msg::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_client_msg::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_client_msg::t10fccc1fc82a483b9253f6641bf88774(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::sync_client_msg::t10fccc1fc82a483b9253f6641bf88774(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::sync_client_msg::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
