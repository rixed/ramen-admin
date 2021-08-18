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
  per_dash_key*,
  Pointer
> t8b8ea3a157d0ee27f7d96fcdedfb7261;

typedef std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> t274013922fc0b2cd45c289bf2ba4463d;

struct t2dbd741445d7e42b47d58662914c784b : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t2dbd741445d7e42b47d58662914c784b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  t2dbd741445d7e42b47d58662914c784b
> t5704a1e4a54cde77262cfc42bc2a9ce8;

struct t094ecb75525e752d2a2200f2f6d7c70b : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t094ecb75525e752d2a2200f2f6d7c70b const &v) {
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
  t094ecb75525e752d2a2200f2f6d7c70b
> t0f0148bb2c9544dffebf7290f67e9c8f;

struct t50db887b1242932a1202c78cd695f221 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  t0f0148bb2c9544dffebf7290f67e9c8f,
  uint32_t,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t50db887b1242932a1202c78cd695f221 const &v) {
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
  t50db887b1242932a1202c78cd695f221
> t8f47fdb13022563f21b0808f407e0889;

struct tafdc15d083fb8c2b34d5c9537c7c3b35 : public std::variant<
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tafdc15d083fb8c2b34d5c9537c7c3b35 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  tafdc15d083fb8c2b34d5c9537c7c3b35
> tf37a00b15c7c89935fe2eb02e6fb6d72;

struct t77e118d48f52fe54bd67a1e894d8d99c : public std::variant<
  Void,
  t5704a1e4a54cde77262cfc42bc2a9ce8,
  t8f47fdb13022563f21b0808f407e0889,
  tf37a00b15c7c89935fe2eb02e6fb6d72
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t77e118d48f52fe54bd67a1e894d8d99c const &v) {
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
  t77e118d48f52fe54bd67a1e894d8d99c
> tbed32f2c27e6aa8657b18086997e1db0;

struct t5402dfaf528fac1d6cda4b683f904109 : public std::variant<
  Void,
  Void,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t5402dfaf528fac1d6cda4b683f904109 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct ta75345aa05e5dc6cfc9f6dc1de4e4163 : public std::variant<
  std::string,
  uint32_t
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, ta75345aa05e5dc6cfc9f6dc1de4e4163 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t2128960e50a15b7d6b324af8bfd3cf88 : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  ta75345aa05e5dc6cfc9f6dc1de4e4163
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t2128960e50a15b7d6b324af8bfd3cf88 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct tb0d666832ecaef200317ff670e7ddc33 : public std::variant<
  std::string,
  per_dash_key*
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tb0d666832ecaef200317ff670e7ddc33 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::sync_socket::t_ext,
  tb0d666832ecaef200317ff670e7ddc33
> td6cd1e8ad5f4a0b227f4aa6bcf99beac;

struct per_dash_key;
struct per_dash_key;
typedef std::tuple<
  std::string,
  per_dash_key*
> tdf6d0a87bf373d7d4ea33113dc8a8b30;

struct tfa3e3f506bebc60f48978cab55edd02b : public std::variant<
  std::string,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tfa3e3f506bebc60f48978cab55edd02b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  tfa3e3f506bebc60f48978cab55edd02b
> tb2dabfcc709dd11277eeffbb0cbb8720;

struct t536e937e8b3b64f8d6408c380dc87af7 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t536e937e8b3b64f8d6408c380dc87af7 const &v) {
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
  t536e937e8b3b64f8d6408c380dc87af7
> t4e8d3406ac2630cb5635ce0da41bfafa;

typedef std::tuple<
  double,
  uint32_t
> t66e64aa59a640b5ac04dd276fa3e8463;

struct t73aad47a1dc2a288e4a3571003439607 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  t4e8d3406ac2630cb5635ce0da41bfafa,
  t66e64aa59a640b5ac04dd276fa3e8463
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t73aad47a1dc2a288e4a3571003439607 const &v) {
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
  t73aad47a1dc2a288e4a3571003439607
> t0fd545c435bd14b3bfe0905bc3f0e9c3;

struct per_dash_key;
struct t : public std::variant<
  Void,
  Void,
  std::string,
  t274013922fc0b2cd45c289bf2ba4463d,
  Void,
  tbed32f2c27e6aa8657b18086997e1db0,
  t5402dfaf528fac1d6cda4b683f904109,
  t2128960e50a15b7d6b324af8bfd3cf88,
  uint16_t,
  std::optional<dessser::gen::sync_socket::t_ext>,
  Void,
  td6cd1e8ad5f4a0b227f4aa6bcf99beac,
  tdf6d0a87bf373d7d4ea33113dc8a8b30,
  Void,
  tb2dabfcc709dd11277eeffbb0cbb8720,
  t0fd545c435bd14b3bfe0905bc3f0e9c3
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
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

struct per_dash_key;
struct per_dash_key;
/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(per_dash_key*,Pointer)> per_dash_key_to_row_binary;
extern std::function<Size(per_dash_key*)> per_dash_key_sersize_of_row_binary;
extern std::function<t8b8ea3a157d0ee27f7d96fcdedfb7261(Pointer)> per_dash_key_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<Pointer(t*,Pointer)> to_row_binary;
typedef t *t_ext;

}
#endif
