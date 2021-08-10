#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct ef03b54a365ad221a03e049955658b7b : public std::variant<
  *file_path,
  std::string,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, ef03b54a365ad221a03e049955658b7b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct v_7c75f538f80ab09c5efa2e5e858fb373 {
  bool with_index;
  uint32_t batch_size;
  uint32_t num_batches;
  bool operator==(v_7c75f538f80ab09c5efa2e5e858fb373 const &other) const {
    return with_index == other.with_index && batch_size == other.batch_size && num_batches == other.num_batches;
  }
};
std::ostream &operator<<(std::ostream &os, v_7c75f538f80ab09c5efa2e5e858fb373 const &r) {
  os << '{';
  os << "with_index:" << r.with_index << ',';
  os << "batch_size:" << r.batch_size << ',';
  os << "num_batches:" << r.num_batches;
  os << '}';
  return os;
}

struct v_18d04b7ea857ab950a4107886a579c47 : public std::variant<
  Void,
  v_7c75f538f80ab09c5efa2e5e858fb373
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_18d04b7ea857ab950a4107886a579c47 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  uint16_t,
  Arr<*raql_value>
> bdfcb86aee1b5624e0990e13acb37f3d;

struct c6ce9cb69d610f4c0bcb5bf84f534f8a : public std::tuple<
  double,
  int16_t,
  uint32_t
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, c6ce9cb69d610f4c0bcb5bf84f534f8a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

typedef std::tuple<
  uint16_t,
  c6ce9cb69d610f4c0bcb5bf84f534f8a
> c6e7176b6a7a6739584314d753c4b1c9;

struct ff86648a206e9a3c6ff0423baf23a3a5 {
  v_18d04b7ea857ab950a4107886a579c47 file_type;
  *fieldmask fieldmask;
  Arr<bdfcb86aee1b5624e0990e13acb37f3d> filters;
  Arr<c6e7176b6a7a6739584314d753c4b1c9> channels;
  bool operator==(ff86648a206e9a3c6ff0423baf23a3a5 const &other) const {
    return file_type == other.file_type && fieldmask == other.fieldmask && filters == other.filters && channels == other.channels;
  }
};
std::ostream &operator<<(std::ostream &os, ff86648a206e9a3c6ff0423baf23a3a5 const &r) {
  os << '{';
  os << "file_type:" << r.file_type << ',';
  os << "fieldmask:" << r.fieldmask << ',';
  os << "filters:" << r.filters << ',';
  os << "channels:" << r.channels;
  os << '}';
  return os;
}

typedef std::tuple<
  ef03b54a365ad221a03e049955658b7b,
  ff86648a206e9a3c6ff0423baf23a3a5
> badedfcce4cfd1443322e6435c2cc493;

typedef std::tuple<
  Arr<badedfcce4cfd1443322e6435c2cc493>,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(Arr<badedfcce4cfd1443322e6435c2cc493>&,Pointer)> to_row_binary;
std::function<Size(Arr<badedfcce4cfd1443322e6435c2cc493>&)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
