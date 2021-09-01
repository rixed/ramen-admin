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
inline std::ostream &operator<<(std::ostream &os, channel_specs const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct tdefd8f93c6467b334d51fff5eb7ebaec {
  uint32_t batch_size;
  uint32_t num_batches;
  bool with_index;
  tdefd8f93c6467b334d51fff5eb7ebaec(uint32_t batch_size_, uint32_t num_batches_, bool with_index_) : batch_size(batch_size_), num_batches(num_batches_), with_index(with_index_) {}
  tdefd8f93c6467b334d51fff5eb7ebaec() = default;
  bool operator==(tdefd8f93c6467b334d51fff5eb7ebaec const &other) const {
    return batch_size == other.batch_size && num_batches == other.num_batches && with_index == other.with_index;
  }
};
inline std::ostream &operator<<(std::ostream &os, tdefd8f93c6467b334d51fff5eb7ebaec const &r) {
  os << '{';
  os << "batch_size:" << r.batch_size << ',';
  os << "num_batches:" << r.num_batches << ',';
  os << "with_index:" << r.with_index;
  os << '}';
  return os;
}

struct file_type : public std::variant<
  Void, // RingBuf
  ::dessser::gen::output_specs::tdefd8f93c6467b334d51fff5eb7ebaec // Orc
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

inline std::ostream &operator<<(std::ostream &os, recipient const &v) {
  switch (v.index()) {
    case 0: os << "DirectFile " << std::get<0>(v); break;
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

struct tbbb940473915e6698de9222ad2dc2d95 {
  Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> channels;
  dessser::gen::fieldmask::t_ext fieldmask;
  ::dessser::gen::output_specs::file_type* file_type;
  Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> filters;
  tbbb940473915e6698de9222ad2dc2d95(Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> channels_, dessser::gen::fieldmask::t_ext fieldmask_, ::dessser::gen::output_specs::file_type* file_type_, Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> filters_) : channels(channels_), fieldmask(fieldmask_), file_type(file_type_), filters(filters_) {}
  tbbb940473915e6698de9222ad2dc2d95() = default;
  bool operator==(tbbb940473915e6698de9222ad2dc2d95 const &other) const {
    return channels == other.channels && fieldmask == other.fieldmask && file_type == other.file_type && filters == other.filters;
  }
};
inline std::ostream &operator<<(std::ostream &os, tbbb940473915e6698de9222ad2dc2d95 const &r) {
  os << '{';
  os << "channels:" << r.channels << ',';
  os << "fieldmask:" << r.fieldmask << ',';
  os << "file_type:" << r.file_type << ',';
  os << "filters:" << r.filters;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::output_specs::recipient*,
  ::dessser::gen::output_specs::tbbb940473915e6698de9222ad2dc2d95
> t8de4c85b0875f15962dc1a78186107e2;

typedef Arr<::dessser::gen::output_specs::t8de4c85b0875f15962dc1a78186107e2> t;
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

}
#endif
