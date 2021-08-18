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
  uint32_t seq;
  bool confirm_success;
  bool echo;
  dessser::gen::sync_client_cmd::t_ext cmd;
  bool operator==(t const &other) const {
    return seq == other.seq && confirm_success == other.confirm_success && echo == other.echo && cmd == other.cmd;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "seq:" << r.seq << ',';
  os << "confirm_success:" << r.confirm_success << ',';
  os << "echo:" << r.echo << ',';
  os << "cmd:" << r.cmd;
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
