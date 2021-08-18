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
struct tdbd12962476f144875d773c02a947df4 : public std::variant<
  dessser::gen::file_path::t_ext,
  std::string,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tdbd12962476f144875d773c02a947df4 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t30ed65daad192934da3b9130ff139b6d {
  bool with_index;
  uint32_t batch_size;
  uint32_t num_batches;
  bool operator==(t30ed65daad192934da3b9130ff139b6d const &other) const {
    return with_index == other.with_index && batch_size == other.batch_size && num_batches == other.num_batches;
  }
};
inline std::ostream &operator<<(std::ostream &os, t30ed65daad192934da3b9130ff139b6d const &r) {
  os << '{';
  os << "with_index:" << r.with_index << ',';
  os << "batch_size:" << r.batch_size << ',';
  os << "num_batches:" << r.num_batches;
  os << '}';
  return os;
}

struct t9dcc0668efb2fb438da4910d5084602f : public std::variant<
  Void,
  t30ed65daad192934da3b9130ff139b6d
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t9dcc0668efb2fb438da4910d5084602f const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> t4b7f8f0e420ffe218b8bc466a29068c5;

struct t38ed0a12e3c65cf35e64def56de661a7 : public std::tuple<
  double,
  int16_t,
  uint32_t
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t38ed0a12e3c65cf35e64def56de661a7 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

typedef std::tuple<
  uint16_t,
  t38ed0a12e3c65cf35e64def56de661a7
> t49bfe1f14983e0c992ccaef7a2dce15f;

struct t573aabfd464fe4a04b1ebdf05abf810d {
  t9dcc0668efb2fb438da4910d5084602f file_type;
  dessser::gen::fieldmask::t_ext fieldmask;
  Arr<t4b7f8f0e420ffe218b8bc466a29068c5> filters;
  Arr<t49bfe1f14983e0c992ccaef7a2dce15f> channels;
  bool operator==(t573aabfd464fe4a04b1ebdf05abf810d const &other) const {
    return file_type == other.file_type && fieldmask == other.fieldmask && filters == other.filters && channels == other.channels;
  }
};
inline std::ostream &operator<<(std::ostream &os, t573aabfd464fe4a04b1ebdf05abf810d const &r) {
  os << '{';
  os << "file_type:" << r.file_type << ',';
  os << "fieldmask:" << r.fieldmask << ',';
  os << "filters:" << r.filters << ',';
  os << "channels:" << r.channels;
  os << '}';
  return os;
}

typedef std::tuple<
  tdbd12962476f144875d773c02a947df4,
  t573aabfd464fe4a04b1ebdf05abf810d
> t1058c157cbb898507951a5a66a19e7a7;

typedef Arr<t1058c157cbb898507951a5a66a19e7a7> t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;

}
#endif
