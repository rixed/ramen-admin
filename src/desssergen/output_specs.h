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
> { using tuple::tuple; };
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
inline std::ostream &operator<<(std::ostream &os, file_type const &v) {
  switch (v.index()) {
    case 0: os << "RingBuf " << std::get<0>(v); break;
    case 1: os << "Orc " << std::get<1>(v); break;
  }
  return os;
}

struct recipient : public std::variant<
  dessser::gen::file_path::t_ext, // DirectFile
  std::string, // IndirectFile
  std::string // SyncKey
> { using variant::variant; };

enum Constr_recipient {
  DirectFile,
  IndirectFile,
  SyncKey,
};

inline bool operator==(recipient const &a, recipient const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)); // DirectFile
    case 1: return std::get<1>(a) == std::get<1>(b); // IndirectFile
    case 2: return std::get<2>(a) == std::get<2>(b); // SyncKey
  };
  return false;
}
inline bool operator!=(recipient const &a, recipient const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, recipient const &v) {
  switch (v.index()) {
    case 0: os << "DirectFile " << ::dessser::gen::file_path::Deref(std::get<0>(v)); break;
    case 1: os << "IndirectFile " << std::get<1>(v); break;
    case 2: os << "SyncKey " << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  uint16_t,
  ::dessser::gen::output_specs::channel_specs*
> t0e5aeccd6bdb25fe3e41dac725c20413;

typedef std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> t4b7f8f0e420ffe218b8bc466a29068c5;

struct t0580f3cfb08cb32041a63b1331642ca4 {
  Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> channels;
  dessser::gen::fieldmask::t_ext fieldmask;
  ::dessser::gen::output_specs::file_type* file_type;
  Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> filters;
  t0580f3cfb08cb32041a63b1331642ca4(Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> channels_, dessser::gen::fieldmask::t_ext fieldmask_, ::dessser::gen::output_specs::file_type* file_type_, Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> filters_) : channels(channels_), fieldmask(fieldmask_), file_type(file_type_), filters(filters_) {}
  t0580f3cfb08cb32041a63b1331642ca4() = default;
};
inline std::ostream &operator<<(std::ostream &os, t0580f3cfb08cb32041a63b1331642ca4 const &r) {
  os << '{';
  os << "channels:" << r.channels << ',';
  os << "fieldmask:" << ::dessser::gen::fieldmask::Deref(r.fieldmask) << ',';
  os << "file_type:" << r.file_type << ',';
  os << "filters:" << r.filters;
  os << '}';
  return os;
}
inline bool operator==(t0580f3cfb08cb32041a63b1331642ca4 const &a, t0580f3cfb08cb32041a63b1331642ca4 const &b) {
  return a.channels == b.channels && ::dessser::gen::fieldmask::Deref(a.fieldmask) == ::dessser::gen::fieldmask::Deref(b.fieldmask) && a.file_type == b.file_type && a.filters == b.filters;
}

inline bool operator!=(t0580f3cfb08cb32041a63b1331642ca4 const &a, t0580f3cfb08cb32041a63b1331642ca4 const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::output_specs::recipient*,
  ::dessser::gen::output_specs::t0580f3cfb08cb32041a63b1331642ca4
> t46f7bc657e31d987d610677185800303;

typedef Arr<::dessser::gen::output_specs::t46f7bc657e31d987d610677185800303> t;
typedef std::tuple<
  ::dessser::gen::output_specs::channel_specs*,
  Pointer
> t6df20c301dedeef88b07b4e609cf70cc;

typedef std::tuple<
  ::dessser::gen::output_specs::file_type*,
  Pointer
> tc1a246d65b8ec8a1b6abc7902e02e4ae;

typedef std::tuple<
  ::dessser::gen::output_specs::recipient*,
  Pointer
> tef522899602bf7c23a3b80730ab356df;

typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

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
extern std::function<::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc(Pointer)> channel_specs_of_row_binary;
extern std::function<::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae(Pointer)> file_type_of_row_binary;
extern std::function<::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df(Pointer)> recipient_of_row_binary;
extern std::function<::dessser::gen::output_specs::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
