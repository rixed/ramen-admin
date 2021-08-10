#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_client_msg {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  uint32_t seq;
  bool confirm_success;
  bool echo;
  dessser::gen::sync_client_cmd::t cmd;
  bool operator==(t const &other) const {
    return seq == other.seq && confirm_success == other.confirm_success && echo == other.echo && cmd == other.cmd;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "seq:" << r.seq << ',';
  os << "confirm_success:" << r.confirm_success << ',';
  os << "echo:" << r.echo << ',';
  os << "cmd:" << r.cmd;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
