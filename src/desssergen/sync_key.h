#ifndef DESSSER_GEN_sync_key
#define DESSSER_GEN_sync_key
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/sync_socket.h"
#include "desssergen/sync_socket.h"
#include "desssergen/fq_name.h"
#include "desssergen/site_name.h"
#include "desssergen/fq_name.h"
#include "desssergen/site_name.h"
#include "desssergen/src_path.h"

namespace dessser::gen::sync_key {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct per_dash_key : public std::variant<
  uint32_t
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, per_dash_key const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> t274013922fc0b2cd45c289bf2ba4463d;

struct t48b79f232880b7b4f6fa63fb49447c29 : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t48b79f232880b7b4f6fa63fb49447c29 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t48b79f232880b7b4f6fa63fb49447c29
> tf0a0ad10d734d315321b48396e83fd03;

struct t6ea6cf7054c56538f07bf99eebd02522 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t6ea6cf7054c56538f07bf99eebd02522 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t6ea6cf7054c56538f07bf99eebd02522
> t95d8536ce921c6066c854b6bc84360b8;

struct t27ff275a7d47fb8500c754d55872983e : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  ::dessser::gen::sync_key::t95d8536ce921c6066c854b6bc84360b8,
  uint32_t,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t27ff275a7d47fb8500c754d55872983e const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::fq_name::t_ext,
  ::dessser::gen::sync_key::t27ff275a7d47fb8500c754d55872983e
> t65e25d96bee949c32b7774a7b484e600;

struct t113d89516a2c18ae050fd882eee5a84a : public std::variant<
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t113d89516a2c18ae050fd882eee5a84a const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t113d89516a2c18ae050fd882eee5a84a
> tfdf5b7c8e501192389e343be7eb20d66;

struct tbf1f5ce3da70cd06f89908b60a244a3c : public std::variant<
  Void,
  ::dessser::gen::sync_key::tf0a0ad10d734d315321b48396e83fd03,
  ::dessser::gen::sync_key::t65e25d96bee949c32b7774a7b484e600,
  ::dessser::gen::sync_key::tfdf5b7c8e501192389e343be7eb20d66
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tbf1f5ce3da70cd06f89908b60a244a3c const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::site_name::t_ext,
  ::dessser::gen::sync_key::tbf1f5ce3da70cd06f89908b60a244a3c
> t5071856bab52708dcad9e743e6938e04;

struct t8a4d8e18af3c831cb1dab68a04f11d43 : public std::variant<
  Void,
  Void,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t8a4d8e18af3c831cb1dab68a04f11d43 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct td8ce606393f1007a357680bee7619549 : public std::variant<
  std::string,
  uint32_t
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, td8ce606393f1007a357680bee7619549 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t33595e61bdd85939f0c28e2627b6c1dc : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  ::dessser::gen::sync_key::td8ce606393f1007a357680bee7619549
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t33595e61bdd85939f0c28e2627b6c1dc const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct t3637c321a9608545c9d26877563b9989 : public std::variant<
  std::string,
  ::dessser::gen::sync_key::per_dash_key*
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t3637c321a9608545c9d26877563b9989 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::sync_socket::t_ext,
  ::dessser::gen::sync_key::t3637c321a9608545c9d26877563b9989
> t1ab59b166c808cdef72585f5b6a0f7c7;

struct per_dash_key;
struct per_dash_key;
typedef std::tuple<
  std::string,
  per_dash_key*
> tdf6d0a87bf373d7d4ea33113dc8a8b30;

struct ted9e752b7d1d6a43944401a4f8ee788b : public std::variant<
  std::string,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, ted9e752b7d1d6a43944401a4f8ee788b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::ted9e752b7d1d6a43944401a4f8ee788b
> td405459d2d5431f7062c2f6c6e9974b2;

struct t6cb141d81e51acb4e49955bbd4f267b4 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t6cb141d81e51acb4e49955bbd4f267b4 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t6cb141d81e51acb4e49955bbd4f267b4
> t2e47fa53042642c267b4e218bf415c27;

typedef std::tuple<
  double,
  uint32_t
> t66e64aa59a640b5ac04dd276fa3e8463;

struct t22e36b2453c238d435e2756c532fdbfd : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  ::dessser::gen::sync_key::t2e47fa53042642c267b4e218bf415c27,
  ::dessser::gen::sync_key::t66e64aa59a640b5ac04dd276fa3e8463
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t22e36b2453c238d435e2756c532fdbfd const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t22e36b2453c238d435e2756c532fdbfd
> t053424b471037b98d9833afa61f2b4be;

struct per_dash_key;
struct t : public std::variant<
  Void,
  Void,
  std::string,
  ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d,
  Void,
  ::dessser::gen::sync_key::t5071856bab52708dcad9e743e6938e04,
  ::dessser::gen::sync_key::t8a4d8e18af3c831cb1dab68a04f11d43,
  ::dessser::gen::sync_key::t33595e61bdd85939f0c28e2627b6c1dc,
  uint16_t,
  std::optional<dessser::gen::sync_socket::t_ext>,
  Void,
  ::dessser::gen::sync_key::t1ab59b166c808cdef72585f5b6a0f7c7,
  ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30,
  Void,
  ::dessser::gen::sync_key::td405459d2d5431f7062c2f6c6e9974b2,
  ::dessser::gen::sync_key::t053424b471037b98d9833afa61f2b4be
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
    case 9: os << std::get<9>(v); break;
    case 10: os << std::get<10>(v); break;
    case 11: os << std::get<11>(v); break;
    case 12: os << std::get<12>(v); break;
    case 13: os << std::get<13>(v); break;
    case 14: os << std::get<14>(v); break;
    case 15: os << std::get<15>(v); break;
  }
  return os;
}

struct per_dash_key;
typedef std::tuple<
  ::dessser::gen::sync_key::per_dash_key*,
  Pointer
> t74d8a287d0a13dbe7e14118a085f0fb9;

struct per_dash_key;
struct per_dash_key;
typedef std::tuple<
  ::dessser::gen::sync_key::t*,
  Pointer
> t3161399693367e6234a99fd179dbbb5d;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> per_dash_key_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_dash_key*)> per_dash_key_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9(Pointer)> per_dash_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
