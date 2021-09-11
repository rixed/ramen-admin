#ifndef DESSSER_GEN_output_specs
#define DESSSER_GEN_output_specs
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_value.h"
#include "desssergen/fieldmask.h"
#include "desssergen/sync_key.h"
#include "desssergen/file_path.h"

namespace dessser::gen::output_specs {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct channel_specs : public std::tuple<
  double,
  int16_t,
  uint32_t
> {
  using tuple::tuple;
};
inline bool operator==(channel_specs const &a, channel_specs const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(channel_specs const &a, channel_specs const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, channel_specs const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t55234e0caf6cba9a33ddd852496b1d7b {
  uint32_t batch_size;
  uint32_t num_batches;
  bool with_index;
  t55234e0caf6cba9a33ddd852496b1d7b(uint32_t batch_size_, uint32_t num_batches_, bool with_index_) : batch_size(batch_size_), num_batches(num_batches_), with_index(with_index_) {}
  t55234e0caf6cba9a33ddd852496b1d7b() = default;
};
inline std::ostream &operator<<(std::ostream &os, t55234e0caf6cba9a33ddd852496b1d7b const &r) {
  os << '{';
  os << "batch_size:" << r.batch_size << ',';
  os << "num_batches:" << r.num_batches << ',';
  os << "with_index:" << r.with_index;
  os << '}';
  return os;
}
inline bool operator==(t55234e0caf6cba9a33ddd852496b1d7b const &a, t55234e0caf6cba9a33ddd852496b1d7b const &b) {
  return a.batch_size == b.batch_size && a.num_batches == b.num_batches && a.with_index == b.with_index;
}

inline bool operator!=(t55234e0caf6cba9a33ddd852496b1d7b const &a, t55234e0caf6cba9a33ddd852496b1d7b const &b) {
  return !operator==(a, b);
}
struct file_type : public std::variant<
  Void, // RingBuf
  ::dessser::gen::output_specs::t55234e0caf6cba9a33ddd852496b1d7b // Orc
> { using variant::variant; };

enum Constr_file_type {
  RingBuf,
  Orc,
};

inline std::ostream &operator<<(std::ostream &os, file_type const &v) {
  switch (v.index()) {
    case 0: os << "RingBuf " << std::get<0>(v); break;
    case 1: os << "Orc " << std::get<1>(v); break;
  }
  return os;
}

inline bool operator==(file_type const &a, file_type const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // RingBuf
    case 1: return std::get<1>(a) == std::get<1>(b); // Orc
  };
  return false;
}
inline bool operator!=(file_type const &a, file_type const &b) {
  return !operator==(a, b);
}
struct recipient : public std::variant<
  dessser::gen::file_path::t_ext, // DirectFile
  std::string, // IndirectFile
  dessser::gen::sync_key::t_ext // SyncKey
> { using variant::variant; };

enum Constr_recipient {
  DirectFile,
  IndirectFile,
  SyncKey,
};

inline std::ostream &operator<<(std::ostream &os, recipient const &v) {
  switch (v.index()) {
    case 0: os << "DirectFile " << ::dessser::gen::file_path::Deref(std::get<0>(v)); break;
    case 1: os << "IndirectFile " << std::get<1>(v); break;
    case 2: os << "SyncKey " << ::dessser::gen::sync_key::Deref(std::get<2>(v)); break;
  }
  return os;
}

inline bool operator==(recipient const &a, recipient const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)); // DirectFile
    case 1: return std::get<1>(a) == std::get<1>(b); // IndirectFile
    case 2: return ::dessser::gen::sync_key::Deref(std::get<2>(a)) == ::dessser::gen::sync_key::Deref(std::get<2>(b)); // SyncKey
  };
  return false;
}
inline bool operator!=(recipient const &a, recipient const &b) {
  return !operator==(a, b);
}
struct te4c4fc93d886f75ad3a4c47dcf350bfe : public std::tuple<
  uint16_t,
  ::dessser::gen::output_specs::channel_specs*
> {
  using tuple::tuple;
  te4c4fc93d886f75ad3a4c47dcf350bfe(std::tuple<uint16_t, ::dessser::gen::output_specs::channel_specs*> p)
    : std::tuple<uint16_t, ::dessser::gen::output_specs::channel_specs*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te4c4fc93d886f75ad3a4c47dcf350bfe const &a, te4c4fc93d886f75ad3a4c47dcf350bfe const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te4c4fc93d886f75ad3a4c47dcf350bfe const &a, te4c4fc93d886f75ad3a4c47dcf350bfe const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te4c4fc93d886f75ad3a4c47dcf350bfe const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t0b14edd3739ead719254746b30f1350c : public std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> {
  using tuple::tuple;
  t0b14edd3739ead719254746b30f1350c(std::tuple<uint16_t, Arr<dessser::gen::raql_value::t_ext>> p)
    : std::tuple<uint16_t, Arr<dessser::gen::raql_value::t_ext>>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0b14edd3739ead719254746b30f1350c const &a, t0b14edd3739ead719254746b30f1350c const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0b14edd3739ead719254746b30f1350c const &a, t0b14edd3739ead719254746b30f1350c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0b14edd3739ead719254746b30f1350c const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t09ed983fbf58eb1b2ba3e79aee535b96 {
  Arr<::dessser::gen::output_specs::te4c4fc93d886f75ad3a4c47dcf350bfe> channels;
  dessser::gen::fieldmask::t_ext fieldmask;
  ::dessser::gen::output_specs::file_type* file_type;
  Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> filters;
  t09ed983fbf58eb1b2ba3e79aee535b96(Arr<::dessser::gen::output_specs::te4c4fc93d886f75ad3a4c47dcf350bfe> channels_, dessser::gen::fieldmask::t_ext fieldmask_, ::dessser::gen::output_specs::file_type* file_type_, Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> filters_) : channels(channels_), fieldmask(fieldmask_), file_type(file_type_), filters(filters_) {}
  t09ed983fbf58eb1b2ba3e79aee535b96() = default;
};
inline std::ostream &operator<<(std::ostream &os, t09ed983fbf58eb1b2ba3e79aee535b96 const &r) {
  os << '{';
  os << "channels:" << r.channels << ',';
  os << "fieldmask:" << ::dessser::gen::fieldmask::Deref(r.fieldmask) << ',';
  os << "file_type:" << r.file_type << ',';
  os << "filters:" << r.filters;
  os << '}';
  return os;
}
inline bool operator==(t09ed983fbf58eb1b2ba3e79aee535b96 const &a, t09ed983fbf58eb1b2ba3e79aee535b96 const &b) {
  return a.channels == b.channels && ::dessser::gen::fieldmask::Deref(a.fieldmask) == ::dessser::gen::fieldmask::Deref(b.fieldmask) && a.file_type == b.file_type && a.filters == b.filters;
}

inline bool operator!=(t09ed983fbf58eb1b2ba3e79aee535b96 const &a, t09ed983fbf58eb1b2ba3e79aee535b96 const &b) {
  return !operator==(a, b);
}
struct t1ef03b4a7a480e0e4d46675869c6a594 : public std::tuple<
  ::dessser::gen::output_specs::recipient*,
  ::dessser::gen::output_specs::t09ed983fbf58eb1b2ba3e79aee535b96
> {
  using tuple::tuple;
  t1ef03b4a7a480e0e4d46675869c6a594(std::tuple<::dessser::gen::output_specs::recipient*, ::dessser::gen::output_specs::t09ed983fbf58eb1b2ba3e79aee535b96> p)
    : std::tuple<::dessser::gen::output_specs::recipient*, ::dessser::gen::output_specs::t09ed983fbf58eb1b2ba3e79aee535b96>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1ef03b4a7a480e0e4d46675869c6a594 const &a, t1ef03b4a7a480e0e4d46675869c6a594 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1ef03b4a7a480e0e4d46675869c6a594 const &a, t1ef03b4a7a480e0e4d46675869c6a594 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t1ef03b4a7a480e0e4d46675869c6a594 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

typedef Arr<::dessser::gen::output_specs::t1ef03b4a7a480e0e4d46675869c6a594> t;
struct t908e3cf486ffb78b83b72354d2605714 : public std::tuple<
  ::dessser::gen::output_specs::channel_specs*,
  Pointer
> {
  using tuple::tuple;
  t908e3cf486ffb78b83b72354d2605714(std::tuple<::dessser::gen::output_specs::channel_specs*, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::channel_specs*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t908e3cf486ffb78b83b72354d2605714 const &a, t908e3cf486ffb78b83b72354d2605714 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t908e3cf486ffb78b83b72354d2605714 const &a, t908e3cf486ffb78b83b72354d2605714 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t908e3cf486ffb78b83b72354d2605714 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct tc6e0a3d92ad1a0dc71b26f93d6511bba : public std::tuple<
  ::dessser::gen::output_specs::file_type*,
  Pointer
> {
  using tuple::tuple;
  tc6e0a3d92ad1a0dc71b26f93d6511bba(std::tuple<::dessser::gen::output_specs::file_type*, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::file_type*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc6e0a3d92ad1a0dc71b26f93d6511bba const &a, tc6e0a3d92ad1a0dc71b26f93d6511bba const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc6e0a3d92ad1a0dc71b26f93d6511bba const &a, tc6e0a3d92ad1a0dc71b26f93d6511bba const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc6e0a3d92ad1a0dc71b26f93d6511bba const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct tb36c3ec530eb035831e04b4c5a579751 : public std::tuple<
  ::dessser::gen::output_specs::recipient*,
  Pointer
> {
  using tuple::tuple;
  tb36c3ec530eb035831e04b4c5a579751(std::tuple<::dessser::gen::output_specs::recipient*, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::recipient*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb36c3ec530eb035831e04b4c5a579751 const &a, tb36c3ec530eb035831e04b4c5a579751 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb36c3ec530eb035831e04b4c5a579751 const &a, tb36c3ec530eb035831e04b4c5a579751 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb36c3ec530eb035831e04b4c5a579751 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct tf6138ae5919ddcb1cb9a935a9dc7190a : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  tf6138ae5919ddcb1cb9a935a9dc7190a(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf6138ae5919ddcb1cb9a935a9dc7190a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::output_specs::channel_specs*,Pointer)> channel_specs_to_row_binary;
extern std::function<Pointer(::dessser::gen::output_specs::file_type*,Pointer)> file_type_to_row_binary;
extern std::function<Pointer(::dessser::gen::output_specs::recipient*,Pointer)> recipient_to_row_binary;
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::output_specs::channel_specs*)> channel_specs_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::output_specs::file_type*)> file_type_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::output_specs::recipient*)> recipient_sersize_of_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::output_specs::t908e3cf486ffb78b83b72354d2605714(Pointer)> channel_specs_of_row_binary;
extern std::function<::dessser::gen::output_specs::tc6e0a3d92ad1a0dc71b26f93d6511bba(Pointer)> file_type_of_row_binary;
extern std::function<::dessser::gen::output_specs::tb36c3ec530eb035831e04b4c5a579751(Pointer)> recipient_of_row_binary;
extern std::function<::dessser::gen::output_specs::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
