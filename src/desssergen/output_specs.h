#ifndef DESSSER_GEN_output_specs
#define DESSSER_GEN_output_specs
#include <arpa/inet.h>
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t55234e0caf6cba9a33ddd852496b1d7b> const r) { os << *r; return os; }

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
    case 0: os << "RingBuf" << std::get<0>(v); break;
    case 1: os << "Orc " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<file_type> const v) { os << *v; return os; }

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
    case 0: os << "DirectFile " << std::get<0>(v); break;
    case 1: os << "IndirectFile " << std::get<1>(v); break;
    case 2: os << "SyncKey " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<recipient> const v) { os << *v; return os; }

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
struct t784c9e092e6dc8e0c9c5fd1cc3093085 : public std::tuple<
  uint16_t,
  std::shared_ptr<::dessser::gen::output_specs::channel_specs> 
> {
  using tuple::tuple;
  t784c9e092e6dc8e0c9c5fd1cc3093085(std::tuple<uint16_t, std::shared_ptr<::dessser::gen::output_specs::channel_specs> > p)
    : std::tuple<uint16_t, std::shared_ptr<::dessser::gen::output_specs::channel_specs> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t784c9e092e6dc8e0c9c5fd1cc3093085 const &a, t784c9e092e6dc8e0c9c5fd1cc3093085 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t784c9e092e6dc8e0c9c5fd1cc3093085 const &a, t784c9e092e6dc8e0c9c5fd1cc3093085 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t784c9e092e6dc8e0c9c5fd1cc3093085 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t784c9e092e6dc8e0c9c5fd1cc3093085> const t) { os << *t; return os; }

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
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0b14edd3739ead719254746b30f1350c> const t) { os << *t; return os; }

struct td4b276c89163d76d7a872961502751f6 {
  Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> channels;
  dessser::gen::fieldmask::t_ext fieldmask;
  std::shared_ptr<::dessser::gen::output_specs::file_type>  file_type;
  Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> filters;
  td4b276c89163d76d7a872961502751f6(Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> channels_, dessser::gen::fieldmask::t_ext fieldmask_, std::shared_ptr<::dessser::gen::output_specs::file_type>  file_type_, Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> filters_) : channels(channels_), fieldmask(fieldmask_), file_type(file_type_), filters(filters_) {}
  td4b276c89163d76d7a872961502751f6() = default;
};
inline std::ostream &operator<<(std::ostream &os, td4b276c89163d76d7a872961502751f6 const &r) {
  os << '{';
  os << "channels:" << r.channels << ',';
  os << "fieldmask:" << r.fieldmask << ',';
  os << "file_type:" << r.file_type << ',';
  os << "filters:" << r.filters;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td4b276c89163d76d7a872961502751f6> const r) { os << *r; return os; }

inline bool operator==(td4b276c89163d76d7a872961502751f6 const &a, td4b276c89163d76d7a872961502751f6 const &b) {
  return a.channels == b.channels && ::dessser::gen::fieldmask::Deref(a.fieldmask) == ::dessser::gen::fieldmask::Deref(b.fieldmask) && (*a.file_type) == (*b.file_type) && a.filters == b.filters;
}

inline bool operator!=(td4b276c89163d76d7a872961502751f6 const &a, td4b276c89163d76d7a872961502751f6 const &b) {
  return !operator==(a, b);
}
struct tba04231272fbebb3d3653fbc82bc2eee : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::recipient> ,
  ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6
> {
  using tuple::tuple;
  tba04231272fbebb3d3653fbc82bc2eee(std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tba04231272fbebb3d3653fbc82bc2eee const &a, tba04231272fbebb3d3653fbc82bc2eee const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tba04231272fbebb3d3653fbc82bc2eee const &a, tba04231272fbebb3d3653fbc82bc2eee const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tba04231272fbebb3d3653fbc82bc2eee const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tba04231272fbebb3d3653fbc82bc2eee> const t) { os << *t; return os; }

typedef Arr<::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee> t;
struct t092f0ef972407382249d7ed7a5dafaca : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::channel_specs> ,
  Pointer
> {
  using tuple::tuple;
  t092f0ef972407382249d7ed7a5dafaca(std::tuple<std::shared_ptr<::dessser::gen::output_specs::channel_specs> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::channel_specs> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t092f0ef972407382249d7ed7a5dafaca const &a, t092f0ef972407382249d7ed7a5dafaca const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t092f0ef972407382249d7ed7a5dafaca const &a, t092f0ef972407382249d7ed7a5dafaca const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t092f0ef972407382249d7ed7a5dafaca const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t092f0ef972407382249d7ed7a5dafaca> const t) { os << *t; return os; }

struct tdad017d875a8dc0f7c36bbe3dba6e956 : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::file_type> ,
  Pointer
> {
  using tuple::tuple;
  tdad017d875a8dc0f7c36bbe3dba6e956(std::tuple<std::shared_ptr<::dessser::gen::output_specs::file_type> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::file_type> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tdad017d875a8dc0f7c36bbe3dba6e956 const &a, tdad017d875a8dc0f7c36bbe3dba6e956 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tdad017d875a8dc0f7c36bbe3dba6e956 const &a, tdad017d875a8dc0f7c36bbe3dba6e956 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tdad017d875a8dc0f7c36bbe3dba6e956 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tdad017d875a8dc0f7c36bbe3dba6e956> const t) { os << *t; return os; }

struct te1550c6bf972eb31c7ccc68cf1702abf : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::recipient> ,
  Pointer
> {
  using tuple::tuple;
  te1550c6bf972eb31c7ccc68cf1702abf(std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te1550c6bf972eb31c7ccc68cf1702abf const &a, te1550c6bf972eb31c7ccc68cf1702abf const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te1550c6bf972eb31c7ccc68cf1702abf const &a, te1550c6bf972eb31c7ccc68cf1702abf const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te1550c6bf972eb31c7ccc68cf1702abf const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te1550c6bf972eb31c7ccc68cf1702abf> const t) { os << *t; return os; }

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
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf6138ae5919ddcb1cb9a935a9dc7190a> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::channel_specs> ,Pointer)> channel_specs_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::file_type> ,Pointer)> file_type_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::recipient> ,Pointer)> recipient_to_row_binary;
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::output_specs::channel_specs> )> channel_specs_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::output_specs::file_type> )> file_type_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::output_specs::recipient> )> recipient_sersize_of_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca(Pointer)> channel_specs_of_row_binary;
extern std::function<::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956(Pointer)> file_type_of_row_binary;
extern std::function<::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf(Pointer)> recipient_of_row_binary;
extern std::function<::dessser::gen::output_specs::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
