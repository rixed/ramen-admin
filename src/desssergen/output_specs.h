#ifndef DESSSER_GEN_output_specs
#define DESSSER_GEN_output_specs
#include <functional>
#include <memory>
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
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<channel_specs> const t) { os << *t; return os; }

struct ta86dfe69264c9600d57a3b5ead0f7951 {
  bool with_index;
  uint32_t batch_size;
  uint32_t num_batches;
  ta86dfe69264c9600d57a3b5ead0f7951(bool with_index_, uint32_t batch_size_, uint32_t num_batches_) : with_index(with_index_), batch_size(batch_size_), num_batches(num_batches_) {}
  ta86dfe69264c9600d57a3b5ead0f7951() = default;
};
inline bool operator==(ta86dfe69264c9600d57a3b5ead0f7951 const &a, ta86dfe69264c9600d57a3b5ead0f7951 const &b) {
  return a.with_index == b.with_index && a.batch_size == b.batch_size && a.num_batches == b.num_batches;
}

inline bool operator!=(ta86dfe69264c9600d57a3b5ead0f7951 const &a, ta86dfe69264c9600d57a3b5ead0f7951 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta86dfe69264c9600d57a3b5ead0f7951 const &r) {
  os << '{';
  os << "with_index:" << r.with_index << ',';
  os << "batch_size:" << r.batch_size << ',';
  os << "num_batches:" << r.num_batches;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta86dfe69264c9600d57a3b5ead0f7951> const r) { os << *r; return os; }

struct file_type : public std::variant<
  Void, // RingBuf
  ::dessser::gen::output_specs::ta86dfe69264c9600d57a3b5ead0f7951 // Orc
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

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
enum Constr_file_type {
  RingBuf,
  Orc,
};

inline std::ostream &operator<<(std::ostream &os, file_type const &v) {
  switch (v.index()) {
    case 0: os << "RingBuf" << std::get<0>(v); break;
    case 1: os << "Orc " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<file_type> const v) { os << *v; return os; }

struct recipient : public std::variant<
  dessser::gen::file_path::t_ext, // DirectFile
  std::string, // IndirectFile
  dessser::gen::sync_key::t_ext // SyncKey
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

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
enum Constr_recipient {
  DirectFile,
  IndirectFile,
  SyncKey,
};

inline std::ostream &operator<<(std::ostream &os, recipient const &v) {
  switch (v.index()) {
    case 0: os << "DirectFile " << std::get<0>(v); break;
    case 1: os << "IndirectFile " << std::get<1>(v); break;
    case 2: os << "SyncKey " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<recipient> const v) { os << *v; return os; }

struct te2535d14520252a621d726d279906e71 : public std::tuple<
  uint16_t,
  ::dessser::gen::output_specs::channel_specs
> {
  using tuple::tuple;
};
inline bool operator==(te2535d14520252a621d726d279906e71 const &a, te2535d14520252a621d726d279906e71 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te2535d14520252a621d726d279906e71 const &a, te2535d14520252a621d726d279906e71 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te2535d14520252a621d726d279906e71 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te2535d14520252a621d726d279906e71> const t) { os << *t; return os; }

struct t6f037f9cb4c8fd79d46fb7db1c2b9a46 : public std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> {
  using tuple::tuple;
};
inline bool operator==(t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &a, t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &a, t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6f037f9cb4c8fd79d46fb7db1c2b9a46> const t) { os << *t; return os; }

struct t6d8876cd95eb52df46270873f955e58e {
  ::dessser::gen::output_specs::file_type file_type;
  dessser::gen::fieldmask::t_ext fieldmask;
  Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> filters;
  Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> channels;
  t6d8876cd95eb52df46270873f955e58e(::dessser::gen::output_specs::file_type file_type_, dessser::gen::fieldmask::t_ext fieldmask_, Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> filters_, Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> channels_) : file_type(file_type_), fieldmask(fieldmask_), filters(filters_), channels(channels_) {}
  t6d8876cd95eb52df46270873f955e58e() = default;
};
inline bool operator==(t6d8876cd95eb52df46270873f955e58e const &a, t6d8876cd95eb52df46270873f955e58e const &b) {
  return a.file_type == b.file_type && ::dessser::gen::fieldmask::Deref(a.fieldmask) == ::dessser::gen::fieldmask::Deref(b.fieldmask) && a.filters == b.filters && a.channels == b.channels;
}

inline bool operator!=(t6d8876cd95eb52df46270873f955e58e const &a, t6d8876cd95eb52df46270873f955e58e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6d8876cd95eb52df46270873f955e58e const &r) {
  os << '{';
  os << "file_type:" << r.file_type << ',';
  os << "fieldmask:" << r.fieldmask << ',';
  os << "filters:" << r.filters << ',';
  os << "channels:" << r.channels;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6d8876cd95eb52df46270873f955e58e> const r) { os << *r; return os; }

struct t132ce9f388dc6ee5c0fd05918c829523 : public std::tuple<
  ::dessser::gen::output_specs::recipient,
  ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e
> {
  using tuple::tuple;
};
inline bool operator==(t132ce9f388dc6ee5c0fd05918c829523 const &a, t132ce9f388dc6ee5c0fd05918c829523 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t132ce9f388dc6ee5c0fd05918c829523 const &a, t132ce9f388dc6ee5c0fd05918c829523 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t132ce9f388dc6ee5c0fd05918c829523 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t132ce9f388dc6ee5c0fd05918c829523> const t) { os << *t; return os; }

typedef Arr<::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523> t;
struct t7ce21e44309db7c6914cc41eb440af04 : public std::tuple<
  ::dessser::gen::output_specs::channel_specs,
  Pointer
> {
  using tuple::tuple;
  t7ce21e44309db7c6914cc41eb440af04(std::tuple<::dessser::gen::output_specs::channel_specs, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::channel_specs, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7ce21e44309db7c6914cc41eb440af04 const &a, t7ce21e44309db7c6914cc41eb440af04 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7ce21e44309db7c6914cc41eb440af04 const &a, t7ce21e44309db7c6914cc41eb440af04 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7ce21e44309db7c6914cc41eb440af04 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7ce21e44309db7c6914cc41eb440af04> const t) { os << *t; return os; }

struct te5b605570c13dd86d5874e55c6b74a31 : public std::tuple<
  ::dessser::gen::output_specs::file_type,
  Pointer
> {
  using tuple::tuple;
  te5b605570c13dd86d5874e55c6b74a31(std::tuple<::dessser::gen::output_specs::file_type, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::file_type, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te5b605570c13dd86d5874e55c6b74a31 const &a, te5b605570c13dd86d5874e55c6b74a31 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te5b605570c13dd86d5874e55c6b74a31 const &a, te5b605570c13dd86d5874e55c6b74a31 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te5b605570c13dd86d5874e55c6b74a31 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te5b605570c13dd86d5874e55c6b74a31> const t) { os << *t; return os; }

struct t5bd421c43649a0ea41776ce18e1f03c1 : public std::tuple<
  ::dessser::gen::output_specs::recipient,
  Pointer
> {
  using tuple::tuple;
  t5bd421c43649a0ea41776ce18e1f03c1(std::tuple<::dessser::gen::output_specs::recipient, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::recipient, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5bd421c43649a0ea41776ce18e1f03c1 const &a, t5bd421c43649a0ea41776ce18e1f03c1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5bd421c43649a0ea41776ce18e1f03c1 const &a, t5bd421c43649a0ea41776ce18e1f03c1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t5bd421c43649a0ea41776ce18e1f03c1 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5bd421c43649a0ea41776ce18e1f03c1> const t) { os << *t; return os; }

struct ta30293a82943182cab78182f33b18016 : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  ta30293a82943182cab78182f33b18016(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta30293a82943182cab78182f33b18016 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta30293a82943182cab78182f33b18016> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::output_specs::channel_specs const &,Pointer &)> channel_specs_to_row_binary;
extern std::function<Pointer(::dessser::gen::output_specs::file_type const &,Pointer &)> file_type_to_row_binary;
extern std::function<Pointer(::dessser::gen::output_specs::recipient &,Pointer &)> recipient_to_row_binary;
extern std::function<Pointer(t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::output_specs::channel_specs const &)> channel_specs_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::output_specs::file_type const &)> file_type_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::output_specs::recipient &)> recipient_sersize_of_row_binary;
extern std::function<Size(t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04(Pointer &)> channel_specs_of_row_binary;
extern std::function<::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31(Pointer &)> file_type_of_row_binary;
extern std::function<::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1(Pointer &)> recipient_of_row_binary;
extern std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
