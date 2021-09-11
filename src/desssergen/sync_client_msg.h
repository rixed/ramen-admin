#ifndef DESSSER_GEN_sync_client_msg
#define DESSSER_GEN_sync_client_msg
#include <arpa/inet.h>
#include <functional>
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
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "cmd:" << ::dessser::gen::sync_client_cmd::Deref(r.cmd) << ',';
  os << "confirm_success:" << r.confirm_success << ',';
  os << "echo:" << r.echo << ',';
  os << "seq:" << r.seq;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::sync_client_cmd::Deref(a.cmd) == ::dessser::gen::sync_client_cmd::Deref(b.cmd) && a.confirm_success == b.confirm_success && a.echo == b.echo && a.seq == b.seq;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t4409d3791506989c07ce018cc8d6db69 : public std::tuple<
  ::dessser::gen::sync_client_msg::t*,
  Pointer
> {
  using tuple::tuple;
  t4409d3791506989c07ce018cc8d6db69(std::tuple<::dessser::gen::sync_client_msg::t*, Pointer> p)
    : std::tuple<::dessser::gen::sync_client_msg::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4409d3791506989c07ce018cc8d6db69 const &a, t4409d3791506989c07ce018cc8d6db69 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4409d3791506989c07ce018cc8d6db69 const &a, t4409d3791506989c07ce018cc8d6db69 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4409d3791506989c07ce018cc8d6db69 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_client_msg::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_client_msg::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_client_msg::t4409d3791506989c07ce018cc8d6db69(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
