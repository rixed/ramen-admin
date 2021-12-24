#ifndef DESSSER_GEN_raql_type
#define DESSSER_GEN_raql_type
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_type {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t9acdca30308e28313c3977aa48ab367d : public std::tuple<
  uint32_t,
  std::shared_ptr<::dessser::gen::raql_type::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t9acdca30308e28313c3977aa48ab367d const &a, t9acdca30308e28313c3977aa48ab367d const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t9acdca30308e28313c3977aa48ab367d const &a, t9acdca30308e28313c3977aa48ab367d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t9acdca30308e28313c3977aa48ab367d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9acdca30308e28313c3977aa48ab367d> const t) { os << *t; return os; }

struct named_type : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::raql_type::t> 
> {
  using tuple::tuple;
};
inline bool operator==(named_type const &a, named_type const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(named_type const &a, named_type const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, named_type const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<named_type> const t) { os << *t; return os; }

struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t550173c9cc042d56a37c01d7d8bbfa95 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::t> ,
  std::shared_ptr<::dessser::gen::raql_type::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t550173c9cc042d56a37c01d7d8bbfa95 const &a, t550173c9cc042d56a37c01d7d8bbfa95 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t550173c9cc042d56a37c01d7d8bbfa95 const &a, t550173c9cc042d56a37c01d7d8bbfa95 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t550173c9cc042d56a37c01d7d8bbfa95 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t550173c9cc042d56a37c01d7d8bbfa95> const t) { os << *t; return os; }

struct base : public std::variant<
  Void, // Void
  Void, // Bool
  Void, // Char
  Void, // Float
  Void, // String
  Void, // U8
  Void, // U16
  Void, // U24
  Void, // U32
  Void, // U40
  Void, // U48
  Void, // U56
  Void, // U64
  Void, // U128
  Void, // I8
  Void, // I16
  Void, // I24
  Void, // I32
  Void, // I40
  Void, // I48
  Void, // I56
  Void, // I64
  Void, // I128
  Void, // Eth
  Void, // Ipv4
  Void, // Ipv6
  Void, // Ip
  Void, // Cidrv4
  Void, // Cidrv6
  Void, // Cidr
  Arr<std::shared_ptr<::dessser::gen::raql_type::t> >, // Tup
  ::dessser::gen::raql_type::t9acdca30308e28313c3977aa48ab367d, // Vec
  std::shared_ptr<::dessser::gen::raql_type::t> , // Arr
  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> >, // Rec
  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> >, // Sum
  ::dessser::gen::raql_type::t550173c9cc042d56a37c01d7d8bbfa95 // Map
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 36 };
};

inline bool operator==(base const &a, base const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Void
    case 1: return std::get<1>(a) == std::get<1>(b); // Bool
    case 2: return std::get<2>(a) == std::get<2>(b); // Char
    case 3: return std::get<3>(a) == std::get<3>(b); // Float
    case 4: return std::get<4>(a) == std::get<4>(b); // String
    case 5: return std::get<5>(a) == std::get<5>(b); // U8
    case 6: return std::get<6>(a) == std::get<6>(b); // U16
    case 7: return std::get<7>(a) == std::get<7>(b); // U24
    case 8: return std::get<8>(a) == std::get<8>(b); // U32
    case 9: return std::get<9>(a) == std::get<9>(b); // U40
    case 10: return std::get<10>(a) == std::get<10>(b); // U48
    case 11: return std::get<11>(a) == std::get<11>(b); // U56
    case 12: return std::get<12>(a) == std::get<12>(b); // U64
    case 13: return std::get<13>(a) == std::get<13>(b); // U128
    case 14: return std::get<14>(a) == std::get<14>(b); // I8
    case 15: return std::get<15>(a) == std::get<15>(b); // I16
    case 16: return std::get<16>(a) == std::get<16>(b); // I24
    case 17: return std::get<17>(a) == std::get<17>(b); // I32
    case 18: return std::get<18>(a) == std::get<18>(b); // I40
    case 19: return std::get<19>(a) == std::get<19>(b); // I48
    case 20: return std::get<20>(a) == std::get<20>(b); // I56
    case 21: return std::get<21>(a) == std::get<21>(b); // I64
    case 22: return std::get<22>(a) == std::get<22>(b); // I128
    case 23: return std::get<23>(a) == std::get<23>(b); // Eth
    case 24: return std::get<24>(a) == std::get<24>(b); // Ipv4
    case 25: return std::get<25>(a) == std::get<25>(b); // Ipv6
    case 26: return std::get<26>(a) == std::get<26>(b); // Ip
    case 27: return std::get<27>(a) == std::get<27>(b); // Cidrv4
    case 28: return std::get<28>(a) == std::get<28>(b); // Cidrv6
    case 29: return std::get<29>(a) == std::get<29>(b); // Cidr
    case 30: return std::get<30>(a) == std::get<30>(b); // Tup
    case 31: return std::get<31>(a) == std::get<31>(b); // Vec
    case 32: return (*std::get<32>(a)) == (*std::get<32>(b)); // Arr
    case 33: return std::get<33>(a) == std::get<33>(b); // Rec
    case 34: return std::get<34>(a) == std::get<34>(b); // Sum
    case 35: return std::get<35>(a) == std::get<35>(b); // Map
  };
  return false;
}
inline bool operator!=(base const &a, base const &b) {
  return !operator==(a, b);
}
enum Constr_base {
  Void,
  Bool,
  Char,
  Float,
  String,
  U8,
  U16,
  U24,
  U32,
  U40,
  U48,
  U56,
  U64,
  U128,
  I8,
  I16,
  I24,
  I32,
  I40,
  I48,
  I56,
  I64,
  I128,
  Eth,
  Ipv4,
  Ipv6,
  Ip,
  Cidrv4,
  Cidrv6,
  Cidr,
  Tup,
  Vec,
  Arr,
  Rec,
  Sum,
  Map,
};

inline std::ostream &operator<<(std::ostream &os, base const &v) {
  switch (v.index()) {
    case 0: os << "Void" << std::get<0>(v); break;
    case 1: os << "Bool" << std::get<1>(v); break;
    case 2: os << "Char" << std::get<2>(v); break;
    case 3: os << "Float" << std::get<3>(v); break;
    case 4: os << "String" << std::get<4>(v); break;
    case 5: os << "U8" << std::get<5>(v); break;
    case 6: os << "U16" << std::get<6>(v); break;
    case 7: os << "U24" << std::get<7>(v); break;
    case 8: os << "U32" << std::get<8>(v); break;
    case 9: os << "U40" << std::get<9>(v); break;
    case 10: os << "U48" << std::get<10>(v); break;
    case 11: os << "U56" << std::get<11>(v); break;
    case 12: os << "U64" << std::get<12>(v); break;
    case 13: os << "U128" << std::get<13>(v); break;
    case 14: os << "I8" << std::get<14>(v); break;
    case 15: os << "I16" << std::get<15>(v); break;
    case 16: os << "I24" << std::get<16>(v); break;
    case 17: os << "I32" << std::get<17>(v); break;
    case 18: os << "I40" << std::get<18>(v); break;
    case 19: os << "I48" << std::get<19>(v); break;
    case 20: os << "I56" << std::get<20>(v); break;
    case 21: os << "I64" << std::get<21>(v); break;
    case 22: os << "I128" << std::get<22>(v); break;
    case 23: os << "Eth" << std::get<23>(v); break;
    case 24: os << "Ipv4" << std::get<24>(v); break;
    case 25: os << "Ipv6" << std::get<25>(v); break;
    case 26: os << "Ip" << std::get<26>(v); break;
    case 27: os << "Cidrv4" << std::get<27>(v); break;
    case 28: os << "Cidrv6" << std::get<28>(v); break;
    case 29: os << "Cidr" << std::get<29>(v); break;
    case 30: os << "Tup " << std::get<30>(v); break;
    case 31: os << "Vec " << std::get<31>(v); break;
    case 32: os << "Arr " << std::get<32>(v); break;
    case 33: os << "Rec " << std::get<33>(v); break;
    case 34: os << "Sum " << std::get<34>(v); break;
    case 35: os << "Map " << std::get<35>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<base> const v) { os << *v; return os; }

struct t {
  bool nullable;
  std::shared_ptr<::dessser::gen::raql_type::base>  type;
  t(bool nullable_, std::shared_ptr<::dessser::gen::raql_type::base>  type_) : nullable(nullable_), type(type_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.nullable == b.nullable && (*a.type) == (*b.type);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "nullable:" << r.nullable << ',';
  os << "type:" << r.type;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t8b07d6797983610fb5146e4336d56033 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::t> ,
  Pointer
> {
  using tuple::tuple;
  t8b07d6797983610fb5146e4336d56033(std::tuple<std::shared_ptr<::dessser::gen::raql_type::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_type::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8b07d6797983610fb5146e4336d56033 const &a, t8b07d6797983610fb5146e4336d56033 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8b07d6797983610fb5146e4336d56033 const &a, t8b07d6797983610fb5146e4336d56033 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t8b07d6797983610fb5146e4336d56033 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8b07d6797983610fb5146e4336d56033> const t) { os << *t; return os; }

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct tf8a88b53b4c47066834e94151000bfaf : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::base> ,
  Pointer
> {
  using tuple::tuple;
  tf8a88b53b4c47066834e94151000bfaf(std::tuple<std::shared_ptr<::dessser::gen::raql_type::base> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_type::base> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf8a88b53b4c47066834e94151000bfaf const &a, tf8a88b53b4c47066834e94151000bfaf const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf8a88b53b4c47066834e94151000bfaf const &a, tf8a88b53b4c47066834e94151000bfaf const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf8a88b53b4c47066834e94151000bfaf const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf8a88b53b4c47066834e94151000bfaf> const t) { os << *t; return os; }

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t7fbe1cfb5917a94fd4534c65eba54a27 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::named_type> ,
  Pointer
> {
  using tuple::tuple;
  t7fbe1cfb5917a94fd4534c65eba54a27(std::tuple<std::shared_ptr<::dessser::gen::raql_type::named_type> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_type::named_type> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7fbe1cfb5917a94fd4534c65eba54a27 const &a, t7fbe1cfb5917a94fd4534c65eba54a27 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7fbe1cfb5917a94fd4534c65eba54a27 const &a, t7fbe1cfb5917a94fd4534c65eba54a27 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7fbe1cfb5917a94fd4534c65eba54a27 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7fbe1cfb5917a94fd4534c65eba54a27> const t) { os << *t; return os; }

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer)> of_row_binary;
extern std::function<::dessser::gen::raql_type::tf8a88b53b4c47066834e94151000bfaf(Pointer)> base_of_row_binary;
extern std::function<::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27(Pointer)> named_type_of_row_binary;
extern std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer)> wrap_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> base_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type> )> named_type_sersize_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> base_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type> ,Pointer)> named_type_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
