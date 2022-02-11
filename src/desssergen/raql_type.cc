#include <algorithm>
#include <charconv>  // for from_chars
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <random>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_type {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

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
struct t {
  bool nullable;
  ::dessser::gen::raql_type::base type;
  t(bool nullable_, ::dessser::gen::raql_type::base type_) : nullable(nullable_), type(type_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.nullable == b.nullable && a.type == b.type;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
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
extern std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> of_row_binary;
struct t26bed784ba9fd0d7cece3d88b00d59c3 : public std::tuple<
  ::dessser::gen::raql_type::base,
  Pointer
> {
  using tuple::tuple;
  t26bed784ba9fd0d7cece3d88b00d59c3(std::tuple<::dessser::gen::raql_type::base, Pointer> p)
    : std::tuple<::dessser::gen::raql_type::base, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t26bed784ba9fd0d7cece3d88b00d59c3 const &a, t26bed784ba9fd0d7cece3d88b00d59c3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t26bed784ba9fd0d7cece3d88b00d59c3 const &a, t26bed784ba9fd0d7cece3d88b00d59c3 const &b) {
  return !operator==(a, b);
}
struct t1a5d74abf838df33f185a72a8912f5c9 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1a5d74abf838df33f185a72a8912f5c9(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return !operator==(a, b);
}
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
extern std::function<::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3(Pointer &)> base_of_row_binary;
struct ta97bb48ed75bbda6173555873826c8c6 : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  ta97bb48ed75bbda6173555873826c8c6(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return !operator==(a, b);
}
struct t491c44439106a32f896827242e8e76a1 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t491c44439106a32f896827242e8e76a1(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return !operator==(a, b);
}
struct t2e0293a1fa78e04bd095c085288f2f4e : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_type::t> >,
  Pointer
> {
  using tuple::tuple;
  t2e0293a1fa78e04bd095c085288f2f4e(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::t> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::t> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2e0293a1fa78e04bd095c085288f2f4e const &a, t2e0293a1fa78e04bd095c085288f2f4e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2e0293a1fa78e04bd095c085288f2f4e const &a, t2e0293a1fa78e04bd095c085288f2f4e const &b) {
  return !operator==(a, b);
}
struct t0e7feb0b9058bf746404bcfc5913631c : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> >,
  Pointer
> {
  using tuple::tuple;
  t0e7feb0b9058bf746404bcfc5913631c(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e7feb0b9058bf746404bcfc5913631c const &a, t0e7feb0b9058bf746404bcfc5913631c const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e7feb0b9058bf746404bcfc5913631c const &a, t0e7feb0b9058bf746404bcfc5913631c const &b) {
  return !operator==(a, b);
}
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
extern std::function<::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27(Pointer &)> named_type_of_row_binary;
struct t12fb9c475959b52bf7b17b155a955ffa : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t12fb9c475959b52bf7b17b155a955ffa(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return !operator==(a, b);
}
struct t13a07ee37ab40962540da8534858dc07 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t13a07ee37ab40962540da8534858dc07(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return !operator==(a, b);
}
struct t9ef6882174ae71a34a3c5ef6b29242fb : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t9ef6882174ae71a34a3c5ef6b29242fb(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return !operator==(a, b);
}
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
extern std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> wrap_of_row_binary;
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
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t>  &)> sersize_of_row_binary;
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
extern std::function<Size(::dessser::gen::raql_type::base &)> base_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type>  &)> named_type_sersize_of_row_binary;
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
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> to_row_binary;
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
extern std::function<Pointer(::dessser::gen::raql_type::base &,Pointer &)> base_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type>  &,Pointer &)> named_type_to_row_binary;
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
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> wrap_to_row_binary;
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("Ptr")
      (let "drec_276" (apply (identifier "base-of-row-binary") (param 0))
        (let-pair "drec_fst_277" "drec_snd_278" (identifier "drec_276")
          (let-pair "dbool_fst_280" "dbool_snd_281" (read-u8 (identifier "drec_snd_278"))
            (make-tup (make-rec (string "nullable") (not (eq (identifier "dbool_fst_280") (u8 0))) (string "type") (identifier "drec_fst_277")) (identifier "dbool_snd_281"))))))
 */
static std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> fun0 { [&](Pointer p_0) {
    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_1 { base_of_row_binary(p_0) };
    ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 let_res_2;
    {
      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 drec_276 { id_1 };
      ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 letpair_res_3;
      {
        auto drec_fst_277 { std::get<0>(drec_276) };
        auto drec_snd_278 { std::get<1>(drec_276) };
        ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 id_4 { drec_snd_278.readU8() };
        ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 letpair_res_5;
        {
          auto dbool_fst_280 { std::get<0>(id_4) };
          auto dbool_snd_281 { std::get<1>(id_4) };
          uint8_t id_6 { 0 };
          bool id_7 { bool(dbool_fst_280 == id_6) };
          bool id_8 { ! id_7 };
          std::shared_ptr<::dessser::gen::raql_type::t>  id_9 { std::make_shared<::dessser::gen::raql_type::t>(id_8, drec_fst_277) };
          ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_10 { id_9, dbool_snd_281 };
          letpair_res_5 = id_10;
        }
        letpair_res_3 = letpair_res_5;
      }
      let_res_2 = letpair_res_3;
    }
    return let_res_2;
  }
   };
  return fun0;
}
std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_81" (let-pair "du16_fst_76" "du16_snd_77" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_76") (identifier "du16_snd_77")))
        (let-pair "dsum1_fst_82" "dsum1_snd_83" (identifier "dsum1_81")
          (if (eq (u16 0) (identifier "dsum1_fst_82"))
            (make-tup
              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 0
                (nop)) (identifier "dsum1_snd_83"))
            (if (eq (u16 1) (identifier "dsum1_fst_82"))
              (make-tup
                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 1
                  (nop)) (identifier "dsum1_snd_83"))
              (if (eq (u16 2) (identifier "dsum1_fst_82"))
                (make-tup
                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 2
                    (nop)) (identifier "dsum1_snd_83"))
                (if (eq (u16 3) (identifier "dsum1_fst_82"))
                  (make-tup
                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 3
                      (nop)) (identifier "dsum1_snd_83"))
                  (if (eq (u16 4) (identifier "dsum1_fst_82"))
                    (make-tup
                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 4
                        (nop)) (identifier "dsum1_snd_83"))
                    (if (eq (u16 5) (identifier "dsum1_fst_82"))
                      (make-tup
                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 5
                          (nop)) (identifier "dsum1_snd_83"))
                      (if (eq (u16 6) (identifier "dsum1_fst_82"))
                        (make-tup
                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 6
                            (nop)) (identifier "dsum1_snd_83"))
                        (if (eq (u16 7) (identifier "dsum1_fst_82"))
                          (make-tup
                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 7
                              (nop)) (identifier "dsum1_snd_83"))
                          (if (eq (u16 8) (identifier "dsum1_fst_82"))
                            (make-tup
                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 8
                                (nop)) (identifier "dsum1_snd_83"))
                            (if (eq (u16 9) (identifier "dsum1_fst_82"))
                              (make-tup
                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 9
                                  (nop)) (identifier "dsum1_snd_83"))
                              (if (eq (u16 10) (identifier "dsum1_fst_82"))
                                (make-tup
                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 10
                                    (nop)) (identifier "dsum1_snd_83"))
                                (if (eq (u16 11) (identifier "dsum1_fst_82"))
                                  (make-tup
                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 11
                                      (nop)) (identifier "dsum1_snd_83"))
                                  (if (eq (u16 12) (identifier "dsum1_fst_82"))
                                    (make-tup
                                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 12
                                        (nop)) (identifier "dsum1_snd_83"))
                                    (if (eq (u16 13) (identifier "dsum1_fst_82"))
                                      (make-tup
                                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 13
                                          (nop)) (identifier "dsum1_snd_83"))
                                      (if (eq (u16 14) (identifier "dsum1_fst_82"))
                                        (make-tup
                                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 14
                                            (nop)) (identifier "dsum1_snd_83"))
                                        (if (eq (u16 15) (identifier "dsum1_fst_82"))
                                          (make-tup
                                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 15
                                              (nop)) (identifier "dsum1_snd_83"))
                                          (if (eq (u16 16) (identifier "dsum1_fst_82"))
                                            (make-tup
                                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 16
                                                (nop)) (identifier "dsum1_snd_83"))
                                            (if (eq (u16 17) (identifier "dsum1_fst_82"))
                                              (make-tup
                                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 17
                                                  (nop)) (identifier "dsum1_snd_83"))
                                              (if (eq (u16 18) (identifier "dsum1_fst_82"))
                                                (make-tup
                                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 18
                                                    (nop)) (identifier "dsum1_snd_83"))
                                                (if (eq (u16 19) (identifier "dsum1_fst_82"))
                                                  (make-tup
                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 19
                                                      (nop)) (identifier "dsum1_snd_83"))
                                                  (if (eq (u16 20) (identifier "dsum1_fst_82"))
                                                    (make-tup
                                                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 20
                                                        (nop)) (identifier "dsum1_snd_83"))
                                                    (if (eq (u16 21) (identifier "dsum1_fst_82"))
                                                      (make-tup
                                                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 21
                                                          (nop)) (identifier "dsum1_snd_83"))
                                                      (if (eq (u16 22) (identifier "dsum1_fst_82"))
                                                        (make-tup
                                                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 22
                                                            (nop)) (identifier "dsum1_snd_83"))
                                                        (if (eq (u16 23) (identifier "dsum1_fst_82"))
                                                          (make-tup
                                                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 23
                                                              (nop)) 
                                                            (identifier "dsum1_snd_83"))
                                                          (if (eq (u16 24) (identifier "dsum1_fst_82"))
                                                            (make-tup
                                                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 24
                                                                (nop)) 
                                                              (identifier "dsum1_snd_83"))
                                                            (if (eq (u16 25) (identifier "dsum1_fst_82"))
                                                              (make-tup
                                                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 25
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_83"))
                                                              (if (eq (u16 26) (identifier "dsum1_fst_82"))
                                                                (make-tup
                                                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 26
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_83"))
                                                                (if (eq (u16 27) (identifier "dsum1_fst_82"))
                                                                  (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 27
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_83"))
                                                                  (if 
                                                                    (eq (u16 28) (identifier "dsum1_fst_82"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 28
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_83"))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "dsum1_fst_82"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 29
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_83"))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dlist4_fst_181" "dlist4_snd_182"
                                                                    (let "dlist1_169"
                                                                    (let "leb_ref_160" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_161" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_162" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_163" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_162")))
                                                                    (let-pair "leb128_fst_164" "leb128_snd_165" 
                                                                    (identifier "leb128_163")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_162") (identifier "leb128_snd_165"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_160")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_164") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_161")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_160")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_161") (add (unsafe-nth (u8 0) (identifier "shft_ref_161")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_164") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_160")) (unsafe-nth (u8 0) (identifier "p_ref_162")))))))
                                                                    (let-pair "dlist1_fst_170" "dlist1_snd_171" 
                                                                    (identifier "dlist1_169")
                                                                    (let "inits_src_ref_172" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_171")))
                                                                    (seq
                                                                    (let "repeat_n_173" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_170")) (unsafe-nth (u8 0) (identifier "repeat_n_173")))
                                                                    (seq
                                                                    (let "dlist2_174" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_172"))
                                                                    (let-pair "dlist2_fst_175" "dlist2_snd_176" 
                                                                    (identifier "dlist2_174")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_172")
                                                                    (let-pair "dlist3_fst_178" "dlist3_snd_179" 
                                                                    (apply (identifier "of-row-binary") (identifier "dlist2_snd_176"))
                                                                    (make-tup (cons (identifier "dlist3_fst_178") (identifier "dlist2_fst_175")) (identifier "dlist3_snd_179"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_173") (add (unsafe-nth (u8 0) (identifier "repeat_n_173")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_172"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 30
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_181"))) 
                                                                    (identifier "dlist4_snd_182")))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_82"))
                                                                    (let "dtup_151"
                                                                    (let-pair "du32_fst_149" "du32_snd_150" (read-u32 little-endian (identifier "dsum1_snd_83")) (make-tup (identifier "du32_fst_149") (identifier "du32_snd_150")))
                                                                    (let-pair "dtup_fst_152" "dtup_snd_153" 
                                                                    (identifier "dtup_151")
                                                                    (let-pair "dtup_fst_155" "dtup_snd_156" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_153"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 31
                                                                    (make-tup (identifier "dtup_fst_152") (identifier "dtup_fst_155"))) 
                                                                    (identifier "dtup_snd_156")))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dsum2_fst_146" "dsum2_snd_147" 
                                                                    (apply (identifier "of-row-binary") (identifier "dsum1_snd_83"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 32
                                                                    (identifier "dsum2_fst_146")) 
                                                                    (identifier "dsum2_snd_147")))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dlist4_fst_140" "dlist4_snd_141"
                                                                    (let "dlist1_128"
                                                                    (let "leb_ref_119" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_120" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_121" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_122" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_121")))
                                                                    (let-pair "leb128_fst_123" "leb128_snd_124" 
                                                                    (identifier "leb128_122")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_121") (identifier "leb128_snd_124"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_119")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_123") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_120")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_119")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_120") (add (unsafe-nth (u8 0) (identifier "shft_ref_120")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_123") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_119")) (unsafe-nth (u8 0) (identifier "p_ref_121")))))))
                                                                    (let-pair "dlist1_fst_129" "dlist1_snd_130" 
                                                                    (identifier "dlist1_128")
                                                                    (let "inits_src_ref_131" 
                                                                    (make-vec (make-tup (end-of-list "(named_type AS (STRING; THIS))") (identifier "dlist1_snd_130")))
                                                                    (seq
                                                                    (let "repeat_n_132" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_129")) (unsafe-nth (u8 0) (identifier "repeat_n_132")))
                                                                    (seq
                                                                    (let "dlist2_133" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_131"))
                                                                    (let-pair "dlist2_fst_134" "dlist2_snd_135" 
                                                                    (identifier "dlist2_133")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_131")
                                                                    (let-pair "dlist3_fst_137" "dlist3_snd_138" 
                                                                    (apply (identifier "named_type-of-row-binary") (identifier "dlist2_snd_135"))
                                                                    (make-tup (cons (identifier "dlist3_fst_137") (identifier "dlist2_fst_134")) (identifier "dlist3_snd_138"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_132") (add (unsafe-nth (u8 0) (identifier "repeat_n_132")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_131"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 33
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_140"))) 
                                                                    (identifier "dlist4_snd_141")))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dlist4_fst_114" "dlist4_snd_115"
                                                                    (let "dlist1_102"
                                                                    (let "leb_ref_93" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_94" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_95" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_96" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_95")))
                                                                    (let-pair "leb128_fst_97" "leb128_snd_98" 
                                                                    (identifier "leb128_96")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_95") (identifier "leb128_snd_98"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_93")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_97") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_94")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_93")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_94") (add (unsafe-nth (u8 0) (identifier "shft_ref_94")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_97") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_93")) (unsafe-nth (u8 0) (identifier "p_ref_95")))))))
                                                                    (let-pair "dlist1_fst_103" "dlist1_snd_104" 
                                                                    (identifier "dlist1_102")
                                                                    (let "inits_src_ref_105" 
                                                                    (make-vec (make-tup (end-of-list "named_type") (identifier "dlist1_snd_104")))
                                                                    (seq
                                                                    (let "repeat_n_106" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_103")) (unsafe-nth (u8 0) (identifier "repeat_n_106")))
                                                                    (seq
                                                                    (let "dlist2_107" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_105"))
                                                                    (let-pair "dlist2_fst_108" "dlist2_snd_109" 
                                                                    (identifier "dlist2_107")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_105")
                                                                    (let-pair "dlist3_fst_111" "dlist3_snd_112" 
                                                                    (apply (identifier "named_type-of-row-binary") (identifier "dlist2_snd_109"))
                                                                    (make-tup (cons (identifier "dlist3_fst_111") (identifier "dlist2_fst_108")) (identifier "dlist3_snd_112"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_106") (add (unsafe-nth (u8 0) (identifier "repeat_n_106")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_105"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 34
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_114"))) 
                                                                    (identifier "dlist4_snd_115")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_82") (u16 35)))
                                                                    (let "dtup_84" 
                                                                    (apply (identifier "of-row-binary") (identifier "dsum1_snd_83"))
                                                                    (let-pair "dtup_fst_85" "dtup_snd_86" 
                                                                    (identifier "dtup_84")
                                                                    (let-pair "dtup_fst_88" "dtup_snd_89" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_86"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 35
                                                                    (make-tup (identifier "dtup_fst_85") (identifier "dtup_fst_88"))) 
                                                                    (identifier "dtup_snd_89"))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3(Pointer &)> base_of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3(Pointer &)> fun11 { [&](Pointer p_0) {
    ::dessser::gen::raql_type::ta97bb48ed75bbda6173555873826c8c6 id_12 { p_0.readU16Le() };
    ::dessser::gen::raql_type::ta97bb48ed75bbda6173555873826c8c6 letpair_res_13;
    {
      auto du16_fst_76 { std::get<0>(id_12) };
      auto du16_snd_77 { std::get<1>(id_12) };
      ::dessser::gen::raql_type::ta97bb48ed75bbda6173555873826c8c6 id_14 { du16_fst_76, du16_snd_77 };
      letpair_res_13 = id_14;
    }
    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 let_res_15;
    {
      ::dessser::gen::raql_type::ta97bb48ed75bbda6173555873826c8c6 dsum1_81 { letpair_res_13 };
      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_16;
      {
        auto dsum1_fst_82 { std::get<0>(dsum1_81) };
        auto dsum1_snd_83 { std::get<1>(dsum1_81) };
        uint16_t id_17 { 0 };
        bool id_18 { bool(id_17 == dsum1_fst_82) };
        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_19;
        if (id_18) {
          (void)::dessser::Void();
          ::dessser::gen::raql_type::base id_20 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_21 { id_20, dsum1_snd_83 };
          choose_res_19 = id_21;
        } else {
          uint16_t id_22 { 1 };
          bool id_23 { bool(id_22 == dsum1_fst_82) };
          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_24;
          if (id_23) {
            (void)::dessser::Void();
            ::dessser::gen::raql_type::base id_25 { std::in_place_index<1>, ::dessser::Void() };
            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_26 { id_25, dsum1_snd_83 };
            choose_res_24 = id_26;
          } else {
            uint16_t id_27 { 2 };
            bool id_28 { bool(id_27 == dsum1_fst_82) };
            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_29;
            if (id_28) {
              (void)::dessser::Void();
              ::dessser::gen::raql_type::base id_30 { std::in_place_index<2>, ::dessser::Void() };
              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_31 { id_30, dsum1_snd_83 };
              choose_res_29 = id_31;
            } else {
              uint16_t id_32 { 3 };
              bool id_33 { bool(id_32 == dsum1_fst_82) };
              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_34;
              if (id_33) {
                (void)::dessser::Void();
                ::dessser::gen::raql_type::base id_35 { std::in_place_index<3>, ::dessser::Void() };
                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_36 { id_35, dsum1_snd_83 };
                choose_res_34 = id_36;
              } else {
                uint16_t id_37 { 4 };
                bool id_38 { bool(id_37 == dsum1_fst_82) };
                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_39;
                if (id_38) {
                  (void)::dessser::Void();
                  ::dessser::gen::raql_type::base id_40 { std::in_place_index<4>, ::dessser::Void() };
                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_41 { id_40, dsum1_snd_83 };
                  choose_res_39 = id_41;
                } else {
                  uint16_t id_42 { 5 };
                  bool id_43 { bool(id_42 == dsum1_fst_82) };
                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_44;
                  if (id_43) {
                    (void)::dessser::Void();
                    ::dessser::gen::raql_type::base id_45 { std::in_place_index<5>, ::dessser::Void() };
                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_46 { id_45, dsum1_snd_83 };
                    choose_res_44 = id_46;
                  } else {
                    uint16_t id_47 { 6 };
                    bool id_48 { bool(id_47 == dsum1_fst_82) };
                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_49;
                    if (id_48) {
                      (void)::dessser::Void();
                      ::dessser::gen::raql_type::base id_50 { std::in_place_index<6>, ::dessser::Void() };
                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_51 { id_50, dsum1_snd_83 };
                      choose_res_49 = id_51;
                    } else {
                      uint16_t id_52 { 7 };
                      bool id_53 { bool(id_52 == dsum1_fst_82) };
                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_54;
                      if (id_53) {
                        (void)::dessser::Void();
                        ::dessser::gen::raql_type::base id_55 { std::in_place_index<7>, ::dessser::Void() };
                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_56 { id_55, dsum1_snd_83 };
                        choose_res_54 = id_56;
                      } else {
                        uint16_t id_57 { 8 };
                        bool id_58 { bool(id_57 == dsum1_fst_82) };
                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_59;
                        if (id_58) {
                          (void)::dessser::Void();
                          ::dessser::gen::raql_type::base id_60 { std::in_place_index<8>, ::dessser::Void() };
                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_61 { id_60, dsum1_snd_83 };
                          choose_res_59 = id_61;
                        } else {
                          uint16_t id_62 { 9 };
                          bool id_63 { bool(id_62 == dsum1_fst_82) };
                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_64;
                          if (id_63) {
                            (void)::dessser::Void();
                            ::dessser::gen::raql_type::base id_65 { std::in_place_index<9>, ::dessser::Void() };
                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_66 { id_65, dsum1_snd_83 };
                            choose_res_64 = id_66;
                          } else {
                            uint16_t id_67 { 10 };
                            bool id_68 { bool(id_67 == dsum1_fst_82) };
                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_69;
                            if (id_68) {
                              (void)::dessser::Void();
                              ::dessser::gen::raql_type::base id_70 { std::in_place_index<10>, ::dessser::Void() };
                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_71 { id_70, dsum1_snd_83 };
                              choose_res_69 = id_71;
                            } else {
                              uint16_t id_72 { 11 };
                              bool id_73 { bool(id_72 == dsum1_fst_82) };
                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_74;
                              if (id_73) {
                                (void)::dessser::Void();
                                ::dessser::gen::raql_type::base id_75 { std::in_place_index<11>, ::dessser::Void() };
                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_76 { id_75, dsum1_snd_83 };
                                choose_res_74 = id_76;
                              } else {
                                uint16_t id_77 { 12 };
                                bool id_78 { bool(id_77 == dsum1_fst_82) };
                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_79;
                                if (id_78) {
                                  (void)::dessser::Void();
                                  ::dessser::gen::raql_type::base id_80 { std::in_place_index<12>, ::dessser::Void() };
                                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_81 { id_80, dsum1_snd_83 };
                                  choose_res_79 = id_81;
                                } else {
                                  uint16_t id_82 { 13 };
                                  bool id_83 { bool(id_82 == dsum1_fst_82) };
                                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_84;
                                  if (id_83) {
                                    (void)::dessser::Void();
                                    ::dessser::gen::raql_type::base id_85 { std::in_place_index<13>, ::dessser::Void() };
                                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_86 { id_85, dsum1_snd_83 };
                                    choose_res_84 = id_86;
                                  } else {
                                    uint16_t id_87 { 14 };
                                    bool id_88 { bool(id_87 == dsum1_fst_82) };
                                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_89;
                                    if (id_88) {
                                      (void)::dessser::Void();
                                      ::dessser::gen::raql_type::base id_90 { std::in_place_index<14>, ::dessser::Void() };
                                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_91 { id_90, dsum1_snd_83 };
                                      choose_res_89 = id_91;
                                    } else {
                                      uint16_t id_92 { 15 };
                                      bool id_93 { bool(id_92 == dsum1_fst_82) };
                                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_94;
                                      if (id_93) {
                                        (void)::dessser::Void();
                                        ::dessser::gen::raql_type::base id_95 { std::in_place_index<15>, ::dessser::Void() };
                                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_96 { id_95, dsum1_snd_83 };
                                        choose_res_94 = id_96;
                                      } else {
                                        uint16_t id_97 { 16 };
                                        bool id_98 { bool(id_97 == dsum1_fst_82) };
                                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_99;
                                        if (id_98) {
                                          (void)::dessser::Void();
                                          ::dessser::gen::raql_type::base id_100 { std::in_place_index<16>, ::dessser::Void() };
                                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_101 { id_100, dsum1_snd_83 };
                                          choose_res_99 = id_101;
                                        } else {
                                          uint16_t id_102 { 17 };
                                          bool id_103 { bool(id_102 == dsum1_fst_82) };
                                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_104;
                                          if (id_103) {
                                            (void)::dessser::Void();
                                            ::dessser::gen::raql_type::base id_105 { std::in_place_index<17>, ::dessser::Void() };
                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_106 { id_105, dsum1_snd_83 };
                                            choose_res_104 = id_106;
                                          } else {
                                            uint16_t id_107 { 18 };
                                            bool id_108 { bool(id_107 == dsum1_fst_82) };
                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_109;
                                            if (id_108) {
                                              (void)::dessser::Void();
                                              ::dessser::gen::raql_type::base id_110 { std::in_place_index<18>, ::dessser::Void() };
                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_111 { id_110, dsum1_snd_83 };
                                              choose_res_109 = id_111;
                                            } else {
                                              uint16_t id_112 { 19 };
                                              bool id_113 { bool(id_112 == dsum1_fst_82) };
                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_114;
                                              if (id_113) {
                                                (void)::dessser::Void();
                                                ::dessser::gen::raql_type::base id_115 { std::in_place_index<19>, ::dessser::Void() };
                                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_116 { id_115, dsum1_snd_83 };
                                                choose_res_114 = id_116;
                                              } else {
                                                uint16_t id_117 { 20 };
                                                bool id_118 { bool(id_117 == dsum1_fst_82) };
                                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_119;
                                                if (id_118) {
                                                  (void)::dessser::Void();
                                                  ::dessser::gen::raql_type::base id_120 { std::in_place_index<20>, ::dessser::Void() };
                                                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_121 { id_120, dsum1_snd_83 };
                                                  choose_res_119 = id_121;
                                                } else {
                                                  uint16_t id_122 { 21 };
                                                  bool id_123 { bool(id_122 == dsum1_fst_82) };
                                                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_124;
                                                  if (id_123) {
                                                    (void)::dessser::Void();
                                                    ::dessser::gen::raql_type::base id_125 { std::in_place_index<21>, ::dessser::Void() };
                                                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_126 { id_125, dsum1_snd_83 };
                                                    choose_res_124 = id_126;
                                                  } else {
                                                    uint16_t id_127 { 22 };
                                                    bool id_128 { bool(id_127 == dsum1_fst_82) };
                                                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_129;
                                                    if (id_128) {
                                                      (void)::dessser::Void();
                                                      ::dessser::gen::raql_type::base id_130 { std::in_place_index<22>, ::dessser::Void() };
                                                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_131 { id_130, dsum1_snd_83 };
                                                      choose_res_129 = id_131;
                                                    } else {
                                                      uint16_t id_132 { 23 };
                                                      bool id_133 { bool(id_132 == dsum1_fst_82) };
                                                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_134;
                                                      if (id_133) {
                                                        (void)::dessser::Void();
                                                        ::dessser::gen::raql_type::base id_135 { std::in_place_index<23>, ::dessser::Void() };
                                                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_136 { id_135, dsum1_snd_83 };
                                                        choose_res_134 = id_136;
                                                      } else {
                                                        uint16_t id_137 { 24 };
                                                        bool id_138 { bool(id_137 == dsum1_fst_82) };
                                                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_139;
                                                        if (id_138) {
                                                          (void)::dessser::Void();
                                                          ::dessser::gen::raql_type::base id_140 { std::in_place_index<24>, ::dessser::Void() };
                                                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_141 { id_140, dsum1_snd_83 };
                                                          choose_res_139 = id_141;
                                                        } else {
                                                          uint16_t id_142 { 25 };
                                                          bool id_143 { bool(id_142 == dsum1_fst_82) };
                                                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_144;
                                                          if (id_143) {
                                                            (void)::dessser::Void();
                                                            ::dessser::gen::raql_type::base id_145 { std::in_place_index<25>, ::dessser::Void() };
                                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_146 { id_145, dsum1_snd_83 };
                                                            choose_res_144 = id_146;
                                                          } else {
                                                            uint16_t id_147 { 26 };
                                                            bool id_148 { bool(id_147 == dsum1_fst_82) };
                                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_149;
                                                            if (id_148) {
                                                              (void)::dessser::Void();
                                                              ::dessser::gen::raql_type::base id_150 { std::in_place_index<26>, ::dessser::Void() };
                                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_151 { id_150, dsum1_snd_83 };
                                                              choose_res_149 = id_151;
                                                            } else {
                                                              uint16_t id_152 { 27 };
                                                              bool id_153 { bool(id_152 == dsum1_fst_82) };
                                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_154;
                                                              if (id_153) {
                                                                (void)::dessser::Void();
                                                                ::dessser::gen::raql_type::base id_155 { std::in_place_index<27>, ::dessser::Void() };
                                                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_156 { id_155, dsum1_snd_83 };
                                                                choose_res_154 = id_156;
                                                              } else {
                                                                uint16_t id_157 { 28 };
                                                                bool id_158 { bool(id_157 == dsum1_fst_82) };
                                                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_159;
                                                                if (id_158) {
                                                                  (void)::dessser::Void();
                                                                  ::dessser::gen::raql_type::base id_160 { std::in_place_index<28>, ::dessser::Void() };
                                                                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_161 { id_160, dsum1_snd_83 };
                                                                  choose_res_159 = id_161;
                                                                } else {
                                                                  uint16_t id_162 { 29 };
                                                                  bool id_163 { bool(id_162 == dsum1_fst_82) };
                                                                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_164;
                                                                  if (id_163) {
                                                                    (void)::dessser::Void();
                                                                    ::dessser::gen::raql_type::base id_165 { std::in_place_index<29>, ::dessser::Void() };
                                                                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_166 { id_165, dsum1_snd_83 };
                                                                    choose_res_164 = id_166;
                                                                  } else {
                                                                    uint16_t id_167 { 30 };
                                                                    bool id_168 { bool(id_167 == dsum1_fst_82) };
                                                                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_169;
                                                                    if (id_168) {
                                                                      uint32_t id_170 { 0U };
                                                                      Vec<1, uint32_t> id_171 {  id_170  };
                                                                      ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_172;
                                                                      {
                                                                        Vec<1, uint32_t> leb_ref_160 { id_171 };
                                                                        uint8_t id_173 { 0 };
                                                                        Vec<1, uint8_t> id_174 {  id_173  };
                                                                        ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_175;
                                                                        {
                                                                          Vec<1, uint8_t> shft_ref_161 { id_174 };
                                                                          Vec<1, Pointer> id_176 {  dsum1_snd_83  };
                                                                          ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_177;
                                                                          {
                                                                            Vec<1, Pointer> p_ref_162 { id_176 };
                                                                            bool while_flag_178 { true };
                                                                            do {
                                                                              uint8_t id_179 { 0 };
                                                                              Pointer id_180 { p_ref_162[id_179] };
                                                                              ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 id_181 { id_180.readU8() };
                                                                              bool let_res_182;
                                                                              {
                                                                                ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 leb128_163 { id_181 };
                                                                                bool letpair_res_183;
                                                                                {
                                                                                  auto leb128_fst_164 { std::get<0>(leb128_163) };
                                                                                  auto leb128_snd_165 { std::get<1>(leb128_163) };
                                                                                  uint8_t id_184 { 0 };
                                                                                  Void id_185 { ((void)(p_ref_162[id_184] = leb128_snd_165), ::dessser::Void()) };
                                                                                  (void)id_185;
                                                                                  uint8_t id_186 { 0 };
                                                                                  uint8_t id_187 { 127 };
                                                                                  uint8_t id_188 { uint8_t(leb128_fst_164 & id_187) };
                                                                                  uint32_t id_189 { uint32_t(id_188) };
                                                                                  uint8_t id_190 { 0 };
                                                                                  uint8_t id_191 { shft_ref_161[id_190] };
                                                                                  uint32_t id_192 { uint32_t(id_189 << id_191) };
                                                                                  uint8_t id_193 { 0 };
                                                                                  uint32_t id_194 { leb_ref_160[id_193] };
                                                                                  uint32_t id_195 { uint32_t(id_192 | id_194) };
                                                                                  Void id_196 { ((void)(leb_ref_160[id_186] = id_195), ::dessser::Void()) };
                                                                                  (void)id_196;
                                                                                  uint8_t id_197 { 0 };
                                                                                  uint8_t id_198 { 0 };
                                                                                  uint8_t id_199 { shft_ref_161[id_198] };
                                                                                  uint8_t id_200 { 7 };
                                                                                  uint8_t id_201 { uint8_t(id_199 + id_200) };
                                                                                  Void id_202 { ((void)(shft_ref_161[id_197] = id_201), ::dessser::Void()) };
                                                                                  (void)id_202;
                                                                                  uint8_t id_203 { 128 };
                                                                                  bool id_204 { bool(leb128_fst_164 >= id_203) };
                                                                                  letpair_res_183 = id_204;
                                                                                }
                                                                                let_res_182 = letpair_res_183;
                                                                              }
                                                                              while_flag_178 = let_res_182;
                                                                              if (while_flag_178) {
                                                                                (void)::dessser::Void();
                                                                              }
                                                                            } while (while_flag_178);
                                                                            (void)::dessser::Void();
                                                                            uint8_t id_205 { 0 };
                                                                            uint32_t id_206 { leb_ref_160[id_205] };
                                                                            uint8_t id_207 { 0 };
                                                                            Pointer id_208 { p_ref_162[id_207] };
                                                                            ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 id_209 { id_206, id_208 };
                                                                            let_res_177 = id_209;
                                                                          }
                                                                          let_res_175 = let_res_177;
                                                                        }
                                                                        let_res_172 = let_res_175;
                                                                      }
                                                                      ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e let_res_210;
                                                                      {
                                                                        ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 dlist1_169 { let_res_172 };
                                                                        ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e letpair_res_211;
                                                                        {
                                                                          auto dlist1_fst_170 { std::get<0>(dlist1_169) };
                                                                          auto dlist1_snd_171 { std::get<1>(dlist1_169) };
                                                                          Lst<std::shared_ptr<::dessser::gen::raql_type::t> > endoflist_212;
                                                                          ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e id_213 { endoflist_212, dlist1_snd_171 };
                                                                          Vec<1, ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e> id_214 {  id_213  };
                                                                          ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e let_res_215;
                                                                          {
                                                                            Vec<1, ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e> inits_src_ref_172 { id_214 };
                                                                            int32_t id_216 { 0L };
                                                                            Vec<1, int32_t> id_217 {  id_216  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_173 { id_217 };
                                                                              bool while_flag_218 { true };
                                                                              do {
                                                                                int32_t id_219 { int32_t(dlist1_fst_170) };
                                                                                uint8_t id_220 { 0 };
                                                                                int32_t id_221 { repeat_n_173[id_220] };
                                                                                bool id_222 { bool(id_219 > id_221) };
                                                                                while_flag_218 = id_222;
                                                                                if (while_flag_218) {
                                                                                  uint8_t id_223 { 0 };
                                                                                  ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e id_224 { inits_src_ref_172[id_223] };
                                                                                  {
                                                                                    ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e dlist2_174 { id_224 };
                                                                                    {
                                                                                      auto dlist2_fst_175 { std::get<0>(dlist2_174) };
                                                                                      auto dlist2_snd_176 { std::get<1>(dlist2_174) };
                                                                                      uint8_t id_225 { 0 };
                                                                                      ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_226 { of_row_binary(dlist2_snd_176) };
                                                                                      ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e letpair_res_227;
                                                                                      {
                                                                                        auto dlist3_fst_178 { std::get<0>(id_226) };
                                                                                        auto dlist3_snd_179 { std::get<1>(id_226) };
                                                                                        Lst<std::shared_ptr<::dessser::gen::raql_type::t> > id_228 { dlist3_fst_178, dlist2_fst_175 };
                                                                                        ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e id_229 { id_228, dlist3_snd_179 };
                                                                                        letpair_res_227 = id_229;
                                                                                      }
                                                                                      Void id_230 { ((void)(inits_src_ref_172[id_225] = letpair_res_227), ::dessser::Void()) };
                                                                                      (void)id_230;
                                                                                    }
                                                                                    (void)::dessser::Void();
                                                                                  }
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_231 { 0 };
                                                                                  uint8_t id_232 { 0 };
                                                                                  int32_t id_233 { repeat_n_173[id_232] };
                                                                                  int32_t id_234 { 1L };
                                                                                  int32_t id_235 { int32_t(id_233 + id_234) };
                                                                                  Void id_236 { ((void)(repeat_n_173[id_231] = id_235), ::dessser::Void()) };
                                                                                  (void)id_236;
                                                                                  (void)id_236;
                                                                                }
                                                                              } while (while_flag_218);
                                                                              (void)::dessser::Void();
                                                                            }
                                                                            (void)::dessser::Void();
                                                                            uint8_t id_237 { 0 };
                                                                            ::dessser::gen::raql_type::t2e0293a1fa78e04bd095c085288f2f4e id_238 { inits_src_ref_172[id_237] };
                                                                            let_res_215 = id_238;
                                                                          }
                                                                          letpair_res_211 = let_res_215;
                                                                        }
                                                                        let_res_210 = letpair_res_211;
                                                                      }
                                                                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_239;
                                                                      {
                                                                        auto dlist4_fst_181 { std::get<0>(let_res_210) };
                                                                        auto dlist4_snd_182 { std::get<1>(let_res_210) };
                                                                        Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_240 { dlist4_fst_181.toArrRev() };
                                                                        ::dessser::gen::raql_type::base id_241 { std::in_place_index<30>, id_240 };
                                                                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_242 { id_241, dlist4_snd_182 };
                                                                        letpair_res_239 = id_242;
                                                                      }
                                                                      choose_res_169 = letpair_res_239;
                                                                    } else {
                                                                      uint16_t id_243 { 31 };
                                                                      bool id_244 { bool(id_243 == dsum1_fst_82) };
                                                                      ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_245;
                                                                      if (id_244) {
                                                                        ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 id_246 { dsum1_snd_83.readU32Le() };
                                                                        ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 letpair_res_247;
                                                                        {
                                                                          auto du32_fst_149 { std::get<0>(id_246) };
                                                                          auto du32_snd_150 { std::get<1>(id_246) };
                                                                          ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 id_248 { du32_fst_149, du32_snd_150 };
                                                                          letpair_res_247 = id_248;
                                                                        }
                                                                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 let_res_249;
                                                                        {
                                                                          ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 dtup_151 { letpair_res_247 };
                                                                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_250;
                                                                          {
                                                                            auto dtup_fst_152 { std::get<0>(dtup_151) };
                                                                            auto dtup_snd_153 { std::get<1>(dtup_151) };
                                                                            ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_251 { of_row_binary(dtup_snd_153) };
                                                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_252;
                                                                            {
                                                                              auto dtup_fst_155 { std::get<0>(id_251) };
                                                                              auto dtup_snd_156 { std::get<1>(id_251) };
                                                                              ::dessser::gen::raql_type::t9acdca30308e28313c3977aa48ab367d id_253 { dtup_fst_152, dtup_fst_155 };
                                                                              ::dessser::gen::raql_type::base id_254 { std::in_place_index<31>, id_253 };
                                                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_255 { id_254, dtup_snd_156 };
                                                                              letpair_res_252 = id_255;
                                                                            }
                                                                            letpair_res_250 = letpair_res_252;
                                                                          }
                                                                          let_res_249 = letpair_res_250;
                                                                        }
                                                                        choose_res_245 = let_res_249;
                                                                      } else {
                                                                        uint16_t id_256 { 32 };
                                                                        bool id_257 { bool(id_256 == dsum1_fst_82) };
                                                                        ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_258;
                                                                        if (id_257) {
                                                                          ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_259 { of_row_binary(dsum1_snd_83) };
                                                                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_260;
                                                                          {
                                                                            auto dsum2_fst_146 { std::get<0>(id_259) };
                                                                            auto dsum2_snd_147 { std::get<1>(id_259) };
                                                                            ::dessser::gen::raql_type::base id_261 { std::in_place_index<32>, dsum2_fst_146 };
                                                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_262 { id_261, dsum2_snd_147 };
                                                                            letpair_res_260 = id_262;
                                                                          }
                                                                          choose_res_258 = letpair_res_260;
                                                                        } else {
                                                                          uint16_t id_263 { 33 };
                                                                          bool id_264 { bool(id_263 == dsum1_fst_82) };
                                                                          ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_265;
                                                                          if (id_264) {
                                                                            uint32_t id_266 { 0U };
                                                                            Vec<1, uint32_t> id_267 {  id_266  };
                                                                            ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_268;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_119 { id_267 };
                                                                              uint8_t id_269 { 0 };
                                                                              Vec<1, uint8_t> id_270 {  id_269  };
                                                                              ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_271;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_120 { id_270 };
                                                                                Vec<1, Pointer> id_272 {  dsum1_snd_83  };
                                                                                ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_273;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_121 { id_272 };
                                                                                  bool while_flag_274 { true };
                                                                                  do {
                                                                                    uint8_t id_275 { 0 };
                                                                                    Pointer id_276 { p_ref_121[id_275] };
                                                                                    ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 id_277 { id_276.readU8() };
                                                                                    bool let_res_278;
                                                                                    {
                                                                                      ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 leb128_122 { id_277 };
                                                                                      bool letpair_res_279;
                                                                                      {
                                                                                        auto leb128_fst_123 { std::get<0>(leb128_122) };
                                                                                        auto leb128_snd_124 { std::get<1>(leb128_122) };
                                                                                        uint8_t id_280 { 0 };
                                                                                        Void id_281 { ((void)(p_ref_121[id_280] = leb128_snd_124), ::dessser::Void()) };
                                                                                        (void)id_281;
                                                                                        uint8_t id_282 { 0 };
                                                                                        uint8_t id_283 { 127 };
                                                                                        uint8_t id_284 { uint8_t(leb128_fst_123 & id_283) };
                                                                                        uint32_t id_285 { uint32_t(id_284) };
                                                                                        uint8_t id_286 { 0 };
                                                                                        uint8_t id_287 { shft_ref_120[id_286] };
                                                                                        uint32_t id_288 { uint32_t(id_285 << id_287) };
                                                                                        uint8_t id_289 { 0 };
                                                                                        uint32_t id_290 { leb_ref_119[id_289] };
                                                                                        uint32_t id_291 { uint32_t(id_288 | id_290) };
                                                                                        Void id_292 { ((void)(leb_ref_119[id_282] = id_291), ::dessser::Void()) };
                                                                                        (void)id_292;
                                                                                        uint8_t id_293 { 0 };
                                                                                        uint8_t id_294 { 0 };
                                                                                        uint8_t id_295 { shft_ref_120[id_294] };
                                                                                        uint8_t id_296 { 7 };
                                                                                        uint8_t id_297 { uint8_t(id_295 + id_296) };
                                                                                        Void id_298 { ((void)(shft_ref_120[id_293] = id_297), ::dessser::Void()) };
                                                                                        (void)id_298;
                                                                                        uint8_t id_299 { 128 };
                                                                                        bool id_300 { bool(leb128_fst_123 >= id_299) };
                                                                                        letpair_res_279 = id_300;
                                                                                      }
                                                                                      let_res_278 = letpair_res_279;
                                                                                    }
                                                                                    while_flag_274 = let_res_278;
                                                                                    if (while_flag_274) {
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                  } while (while_flag_274);
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_301 { 0 };
                                                                                  uint32_t id_302 { leb_ref_119[id_301] };
                                                                                  uint8_t id_303 { 0 };
                                                                                  Pointer id_304 { p_ref_121[id_303] };
                                                                                  ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 id_305 { id_302, id_304 };
                                                                                  let_res_273 = id_305;
                                                                                }
                                                                                let_res_271 = let_res_273;
                                                                              }
                                                                              let_res_268 = let_res_271;
                                                                            }
                                                                            ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c let_res_306;
                                                                            {
                                                                              ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 dlist1_128 { let_res_268 };
                                                                              ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c letpair_res_307;
                                                                              {
                                                                                auto dlist1_fst_129 { std::get<0>(dlist1_128) };
                                                                                auto dlist1_snd_130 { std::get<1>(dlist1_128) };
                                                                                Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > endoflist_308;
                                                                                ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_309 { endoflist_308, dlist1_snd_130 };
                                                                                Vec<1, ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c> id_310 {  id_309  };
                                                                                ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c let_res_311;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c> inits_src_ref_131 { id_310 };
                                                                                  int32_t id_312 { 0L };
                                                                                  Vec<1, int32_t> id_313 {  id_312  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_132 { id_313 };
                                                                                    bool while_flag_314 { true };
                                                                                    do {
                                                                                      int32_t id_315 { int32_t(dlist1_fst_129) };
                                                                                      uint8_t id_316 { 0 };
                                                                                      int32_t id_317 { repeat_n_132[id_316] };
                                                                                      bool id_318 { bool(id_315 > id_317) };
                                                                                      while_flag_314 = id_318;
                                                                                      if (while_flag_314) {
                                                                                        uint8_t id_319 { 0 };
                                                                                        ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_320 { inits_src_ref_131[id_319] };
                                                                                        {
                                                                                          ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c dlist2_133 { id_320 };
                                                                                          {
                                                                                            auto dlist2_fst_134 { std::get<0>(dlist2_133) };
                                                                                            auto dlist2_snd_135 { std::get<1>(dlist2_133) };
                                                                                            uint8_t id_321 { 0 };
                                                                                            ::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27 id_322 { named_type_of_row_binary(dlist2_snd_135) };
                                                                                            ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c letpair_res_323;
                                                                                            {
                                                                                              auto dlist3_fst_137 { std::get<0>(id_322) };
                                                                                              auto dlist3_snd_138 { std::get<1>(id_322) };
                                                                                              Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_324 { dlist3_fst_137, dlist2_fst_134 };
                                                                                              ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_325 { id_324, dlist3_snd_138 };
                                                                                              letpair_res_323 = id_325;
                                                                                            }
                                                                                            Void id_326 { ((void)(inits_src_ref_131[id_321] = letpair_res_323), ::dessser::Void()) };
                                                                                            (void)id_326;
                                                                                          }
                                                                                          (void)::dessser::Void();
                                                                                        }
                                                                                        (void)::dessser::Void();
                                                                                        uint8_t id_327 { 0 };
                                                                                        uint8_t id_328 { 0 };
                                                                                        int32_t id_329 { repeat_n_132[id_328] };
                                                                                        int32_t id_330 { 1L };
                                                                                        int32_t id_331 { int32_t(id_329 + id_330) };
                                                                                        Void id_332 { ((void)(repeat_n_132[id_327] = id_331), ::dessser::Void()) };
                                                                                        (void)id_332;
                                                                                        (void)id_332;
                                                                                      }
                                                                                    } while (while_flag_314);
                                                                                    (void)::dessser::Void();
                                                                                  }
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_333 { 0 };
                                                                                  ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_334 { inits_src_ref_131[id_333] };
                                                                                  let_res_311 = id_334;
                                                                                }
                                                                                letpair_res_307 = let_res_311;
                                                                              }
                                                                              let_res_306 = letpair_res_307;
                                                                            }
                                                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_335;
                                                                            {
                                                                              auto dlist4_fst_140 { std::get<0>(let_res_306) };
                                                                              auto dlist4_snd_141 { std::get<1>(let_res_306) };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_336 { dlist4_fst_140.toArrRev() };
                                                                              ::dessser::gen::raql_type::base id_337 { std::in_place_index<33>, id_336 };
                                                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_338 { id_337, dlist4_snd_141 };
                                                                              letpair_res_335 = id_338;
                                                                            }
                                                                            choose_res_265 = letpair_res_335;
                                                                          } else {
                                                                            uint16_t id_339 { 34 };
                                                                            bool id_340 { bool(id_339 == dsum1_fst_82) };
                                                                            ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 choose_res_341;
                                                                            if (id_340) {
                                                                              uint32_t id_342 { 0U };
                                                                              Vec<1, uint32_t> id_343 {  id_342  };
                                                                              ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_344;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_93 { id_343 };
                                                                                uint8_t id_345 { 0 };
                                                                                Vec<1, uint8_t> id_346 {  id_345  };
                                                                                ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_347;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_94 { id_346 };
                                                                                  Vec<1, Pointer> id_348 {  dsum1_snd_83  };
                                                                                  ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 let_res_349;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_95 { id_348 };
                                                                                    bool while_flag_350 { true };
                                                                                    do {
                                                                                      uint8_t id_351 { 0 };
                                                                                      Pointer id_352 { p_ref_95[id_351] };
                                                                                      ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 id_353 { id_352.readU8() };
                                                                                      bool let_res_354;
                                                                                      {
                                                                                        ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 leb128_96 { id_353 };
                                                                                        bool letpair_res_355;
                                                                                        {
                                                                                          auto leb128_fst_97 { std::get<0>(leb128_96) };
                                                                                          auto leb128_snd_98 { std::get<1>(leb128_96) };
                                                                                          uint8_t id_356 { 0 };
                                                                                          Void id_357 { ((void)(p_ref_95[id_356] = leb128_snd_98), ::dessser::Void()) };
                                                                                          (void)id_357;
                                                                                          uint8_t id_358 { 0 };
                                                                                          uint8_t id_359 { 127 };
                                                                                          uint8_t id_360 { uint8_t(leb128_fst_97 & id_359) };
                                                                                          uint32_t id_361 { uint32_t(id_360) };
                                                                                          uint8_t id_362 { 0 };
                                                                                          uint8_t id_363 { shft_ref_94[id_362] };
                                                                                          uint32_t id_364 { uint32_t(id_361 << id_363) };
                                                                                          uint8_t id_365 { 0 };
                                                                                          uint32_t id_366 { leb_ref_93[id_365] };
                                                                                          uint32_t id_367 { uint32_t(id_364 | id_366) };
                                                                                          Void id_368 { ((void)(leb_ref_93[id_358] = id_367), ::dessser::Void()) };
                                                                                          (void)id_368;
                                                                                          uint8_t id_369 { 0 };
                                                                                          uint8_t id_370 { 0 };
                                                                                          uint8_t id_371 { shft_ref_94[id_370] };
                                                                                          uint8_t id_372 { 7 };
                                                                                          uint8_t id_373 { uint8_t(id_371 + id_372) };
                                                                                          Void id_374 { ((void)(shft_ref_94[id_369] = id_373), ::dessser::Void()) };
                                                                                          (void)id_374;
                                                                                          uint8_t id_375 { 128 };
                                                                                          bool id_376 { bool(leb128_fst_97 >= id_375) };
                                                                                          letpair_res_355 = id_376;
                                                                                        }
                                                                                        let_res_354 = letpair_res_355;
                                                                                      }
                                                                                      while_flag_350 = let_res_354;
                                                                                      if (while_flag_350) {
                                                                                        (void)::dessser::Void();
                                                                                      }
                                                                                    } while (while_flag_350);
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_377 { 0 };
                                                                                    uint32_t id_378 { leb_ref_93[id_377] };
                                                                                    uint8_t id_379 { 0 };
                                                                                    Pointer id_380 { p_ref_95[id_379] };
                                                                                    ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 id_381 { id_378, id_380 };
                                                                                    let_res_349 = id_381;
                                                                                  }
                                                                                  let_res_347 = let_res_349;
                                                                                }
                                                                                let_res_344 = let_res_347;
                                                                              }
                                                                              ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c let_res_382;
                                                                              {
                                                                                ::dessser::gen::raql_type::t491c44439106a32f896827242e8e76a1 dlist1_102 { let_res_344 };
                                                                                ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c letpair_res_383;
                                                                                {
                                                                                  auto dlist1_fst_103 { std::get<0>(dlist1_102) };
                                                                                  auto dlist1_snd_104 { std::get<1>(dlist1_102) };
                                                                                  Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > endoflist_384;
                                                                                  ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_385 { endoflist_384, dlist1_snd_104 };
                                                                                  Vec<1, ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c> id_386 {  id_385  };
                                                                                  ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c let_res_387;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c> inits_src_ref_105 { id_386 };
                                                                                    int32_t id_388 { 0L };
                                                                                    Vec<1, int32_t> id_389 {  id_388  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_106 { id_389 };
                                                                                      bool while_flag_390 { true };
                                                                                      do {
                                                                                        int32_t id_391 { int32_t(dlist1_fst_103) };
                                                                                        uint8_t id_392 { 0 };
                                                                                        int32_t id_393 { repeat_n_106[id_392] };
                                                                                        bool id_394 { bool(id_391 > id_393) };
                                                                                        while_flag_390 = id_394;
                                                                                        if (while_flag_390) {
                                                                                          uint8_t id_395 { 0 };
                                                                                          ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_396 { inits_src_ref_105[id_395] };
                                                                                          {
                                                                                            ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c dlist2_107 { id_396 };
                                                                                            {
                                                                                              auto dlist2_fst_108 { std::get<0>(dlist2_107) };
                                                                                              auto dlist2_snd_109 { std::get<1>(dlist2_107) };
                                                                                              uint8_t id_397 { 0 };
                                                                                              ::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27 id_398 { named_type_of_row_binary(dlist2_snd_109) };
                                                                                              ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c letpair_res_399;
                                                                                              {
                                                                                                auto dlist3_fst_111 { std::get<0>(id_398) };
                                                                                                auto dlist3_snd_112 { std::get<1>(id_398) };
                                                                                                Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_400 { dlist3_fst_111, dlist2_fst_108 };
                                                                                                ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_401 { id_400, dlist3_snd_112 };
                                                                                                letpair_res_399 = id_401;
                                                                                              }
                                                                                              Void id_402 { ((void)(inits_src_ref_105[id_397] = letpair_res_399), ::dessser::Void()) };
                                                                                              (void)id_402;
                                                                                            }
                                                                                            (void)::dessser::Void();
                                                                                          }
                                                                                          (void)::dessser::Void();
                                                                                          uint8_t id_403 { 0 };
                                                                                          uint8_t id_404 { 0 };
                                                                                          int32_t id_405 { repeat_n_106[id_404] };
                                                                                          int32_t id_406 { 1L };
                                                                                          int32_t id_407 { int32_t(id_405 + id_406) };
                                                                                          Void id_408 { ((void)(repeat_n_106[id_403] = id_407), ::dessser::Void()) };
                                                                                          (void)id_408;
                                                                                          (void)id_408;
                                                                                        }
                                                                                      } while (while_flag_390);
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_409 { 0 };
                                                                                    ::dessser::gen::raql_type::t0e7feb0b9058bf746404bcfc5913631c id_410 { inits_src_ref_105[id_409] };
                                                                                    let_res_387 = id_410;
                                                                                  }
                                                                                  letpair_res_383 = let_res_387;
                                                                                }
                                                                                let_res_382 = letpair_res_383;
                                                                              }
                                                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_411;
                                                                              {
                                                                                auto dlist4_fst_114 { std::get<0>(let_res_382) };
                                                                                auto dlist4_snd_115 { std::get<1>(let_res_382) };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_412 { dlist4_fst_114.toArrRev() };
                                                                                ::dessser::gen::raql_type::base id_413 { std::in_place_index<34>, id_412 };
                                                                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_414 { id_413, dlist4_snd_115 };
                                                                                letpair_res_411 = id_414;
                                                                              }
                                                                              choose_res_341 = letpair_res_411;
                                                                            } else {
                                                                              uint16_t id_415 { 35 };
                                                                              bool id_416 { bool(dsum1_fst_82 == id_415) };
                                                                              Void id_417 { ((void)(assert(id_416)), ::dessser::Void()) };
                                                                              (void)id_417;
                                                                              ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_418 { of_row_binary(dsum1_snd_83) };
                                                                              ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 let_res_419;
                                                                              {
                                                                                ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 dtup_84 { id_418 };
                                                                                ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_420;
                                                                                {
                                                                                  auto dtup_fst_85 { std::get<0>(dtup_84) };
                                                                                  auto dtup_snd_86 { std::get<1>(dtup_84) };
                                                                                  ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_421 { of_row_binary(dtup_snd_86) };
                                                                                  ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 letpair_res_422;
                                                                                  {
                                                                                    auto dtup_fst_88 { std::get<0>(id_421) };
                                                                                    auto dtup_snd_89 { std::get<1>(id_421) };
                                                                                    ::dessser::gen::raql_type::t550173c9cc042d56a37c01d7d8bbfa95 id_423 { dtup_fst_85, dtup_fst_88 };
                                                                                    ::dessser::gen::raql_type::base id_424 { std::in_place_index<35>, id_423 };
                                                                                    ::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3 id_425 { id_424, dtup_snd_89 };
                                                                                    letpair_res_422 = id_425;
                                                                                  }
                                                                                  letpair_res_420 = letpair_res_422;
                                                                                }
                                                                                let_res_419 = letpair_res_420;
                                                                              }
                                                                              choose_res_341 = let_res_419;
                                                                            }
                                                                            choose_res_265 = choose_res_341;
                                                                          }
                                                                          choose_res_258 = choose_res_265;
                                                                        }
                                                                        choose_res_245 = choose_res_258;
                                                                      }
                                                                      choose_res_169 = choose_res_245;
                                                                    }
                                                                    choose_res_164 = choose_res_169;
                                                                  }
                                                                  choose_res_159 = choose_res_164;
                                                                }
                                                                choose_res_154 = choose_res_159;
                                                              }
                                                              choose_res_149 = choose_res_154;
                                                            }
                                                            choose_res_144 = choose_res_149;
                                                          }
                                                          choose_res_139 = choose_res_144;
                                                        }
                                                        choose_res_134 = choose_res_139;
                                                      }
                                                      choose_res_129 = choose_res_134;
                                                    }
                                                    choose_res_124 = choose_res_129;
                                                  }
                                                  choose_res_119 = choose_res_124;
                                                }
                                                choose_res_114 = choose_res_119;
                                              }
                                              choose_res_109 = choose_res_114;
                                            }
                                            choose_res_104 = choose_res_109;
                                          }
                                          choose_res_99 = choose_res_104;
                                        }
                                        choose_res_94 = choose_res_99;
                                      }
                                      choose_res_89 = choose_res_94;
                                    }
                                    choose_res_84 = choose_res_89;
                                  }
                                  choose_res_79 = choose_res_84;
                                }
                                choose_res_74 = choose_res_79;
                              }
                              choose_res_69 = choose_res_74;
                            }
                            choose_res_64 = choose_res_69;
                          }
                          choose_res_59 = choose_res_64;
                        }
                        choose_res_54 = choose_res_59;
                      }
                      choose_res_49 = choose_res_54;
                    }
                    choose_res_44 = choose_res_49;
                  }
                  choose_res_39 = choose_res_44;
                }
                choose_res_34 = choose_res_39;
              }
              choose_res_29 = choose_res_34;
            }
            choose_res_24 = choose_res_29;
          }
          choose_res_19 = choose_res_24;
        }
        letpair_res_16 = choose_res_19;
      }
      let_res_15 = letpair_res_16;
    }
    return let_res_15;
  }
   };
  return fun11;
}
std::function<::dessser::gen::raql_type::t26bed784ba9fd0d7cece3d88b00d59c3(Pointer &)> base_of_row_binary(base_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_69"
        (let "dstring1_63"
          (let "leb_ref_57" (make-vec (u32 0))
            (let "shft_ref_58" (make-vec (u8 0))
              (let "p_ref_59" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_60" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_59")))
                      (let-pair "leb128_fst_61" "leb128_snd_62" (identifier "leb128_60")
                        (seq (set-vec (u8 0) (identifier "p_ref_59") (identifier "leb128_snd_62"))
                          (set-vec (u8 0) (identifier "leb_ref_57")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_61") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_58"))) (unsafe-nth (u8 0) (identifier "leb_ref_57"))))
                          (set-vec (u8 0) (identifier "shft_ref_58") (add (unsafe-nth (u8 0) (identifier "shft_ref_58")) (u8 7))) 
                          (ge (identifier "leb128_fst_61") (u8 128))))) 
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_57"))) (unsafe-nth (u8 0) (identifier "p_ref_59")))))))
          (let-pair "dstring1_fst_64" "dstring1_snd_65" (identifier "dstring1_63")
            (let-pair "dstring2_fst_67" "dstring2_snd_68" (read-bytes (identifier "dstring1_snd_65") (identifier "dstring1_fst_64")) (make-tup (string-of-bytes (identifier "dstring2_fst_67")) (identifier "dstring2_snd_68")))))
        (let-pair "dtup_fst_70" "dtup_snd_71" (identifier "dtup_69")
          (let-pair "dtup_fst_73" "dtup_snd_74" (apply (identifier "of-row-binary") (identifier "dtup_snd_71")) (make-tup (make-tup (identifier "dtup_fst_70") (identifier "dtup_fst_73")) (identifier "dtup_snd_74"))))))
 */
static std::function<::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27(Pointer &)> named_type_of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27(Pointer &)> fun426 { [&](Pointer p_0) {
    uint32_t id_427 { 0U };
    Vec<1, uint32_t> id_428 {  id_427  };
    ::dessser::gen::raql_type::t12fb9c475959b52bf7b17b155a955ffa let_res_429;
    {
      Vec<1, uint32_t> leb_ref_57 { id_428 };
      uint8_t id_430 { 0 };
      Vec<1, uint8_t> id_431 {  id_430  };
      ::dessser::gen::raql_type::t12fb9c475959b52bf7b17b155a955ffa let_res_432;
      {
        Vec<1, uint8_t> shft_ref_58 { id_431 };
        Vec<1, Pointer> id_433 {  p_0  };
        ::dessser::gen::raql_type::t12fb9c475959b52bf7b17b155a955ffa let_res_434;
        {
          Vec<1, Pointer> p_ref_59 { id_433 };
          bool while_flag_435 { true };
          do {
            uint8_t id_436 { 0 };
            Pointer id_437 { p_ref_59[id_436] };
            ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 id_438 { id_437.readU8() };
            bool let_res_439;
            {
              ::dessser::gen::raql_type::t1a5d74abf838df33f185a72a8912f5c9 leb128_60 { id_438 };
              bool letpair_res_440;
              {
                auto leb128_fst_61 { std::get<0>(leb128_60) };
                auto leb128_snd_62 { std::get<1>(leb128_60) };
                uint8_t id_441 { 0 };
                Void id_442 { ((void)(p_ref_59[id_441] = leb128_snd_62), ::dessser::Void()) };
                (void)id_442;
                uint8_t id_443 { 0 };
                uint8_t id_444 { 127 };
                uint8_t id_445 { uint8_t(leb128_fst_61 & id_444) };
                uint32_t id_446 { uint32_t(id_445) };
                uint8_t id_447 { 0 };
                uint8_t id_448 { shft_ref_58[id_447] };
                uint32_t id_449 { uint32_t(id_446 << id_448) };
                uint8_t id_450 { 0 };
                uint32_t id_451 { leb_ref_57[id_450] };
                uint32_t id_452 { uint32_t(id_449 | id_451) };
                Void id_453 { ((void)(leb_ref_57[id_443] = id_452), ::dessser::Void()) };
                (void)id_453;
                uint8_t id_454 { 0 };
                uint8_t id_455 { 0 };
                uint8_t id_456 { shft_ref_58[id_455] };
                uint8_t id_457 { 7 };
                uint8_t id_458 { uint8_t(id_456 + id_457) };
                Void id_459 { ((void)(shft_ref_58[id_454] = id_458), ::dessser::Void()) };
                (void)id_459;
                uint8_t id_460 { 128 };
                bool id_461 { bool(leb128_fst_61 >= id_460) };
                letpair_res_440 = id_461;
              }
              let_res_439 = letpair_res_440;
            }
            while_flag_435 = let_res_439;
            if (while_flag_435) {
              (void)::dessser::Void();
            }
          } while (while_flag_435);
          (void)::dessser::Void();
          uint8_t id_462 { 0 };
          uint32_t id_463 { leb_ref_57[id_462] };
          Size id_464 { Size(id_463) };
          uint8_t id_465 { 0 };
          Pointer id_466 { p_ref_59[id_465] };
          ::dessser::gen::raql_type::t12fb9c475959b52bf7b17b155a955ffa id_467 { id_464, id_466 };
          let_res_434 = id_467;
        }
        let_res_432 = let_res_434;
      }
      let_res_429 = let_res_432;
    }
    ::dessser::gen::raql_type::t13a07ee37ab40962540da8534858dc07 let_res_468;
    {
      ::dessser::gen::raql_type::t12fb9c475959b52bf7b17b155a955ffa dstring1_63 { let_res_429 };
      ::dessser::gen::raql_type::t13a07ee37ab40962540da8534858dc07 letpair_res_469;
      {
        auto dstring1_fst_64 { std::get<0>(dstring1_63) };
        auto dstring1_snd_65 { std::get<1>(dstring1_63) };
        ::dessser::gen::raql_type::t9ef6882174ae71a34a3c5ef6b29242fb id_470 { dstring1_snd_65.readBytes(dstring1_fst_64) };
        ::dessser::gen::raql_type::t13a07ee37ab40962540da8534858dc07 letpair_res_471;
        {
          auto dstring2_fst_67 { std::get<0>(id_470) };
          auto dstring2_snd_68 { std::get<1>(id_470) };
          std::string id_472 { dstring2_fst_67.toString() };
          ::dessser::gen::raql_type::t13a07ee37ab40962540da8534858dc07 id_473 { id_472, dstring2_snd_68 };
          letpair_res_471 = id_473;
        }
        letpair_res_469 = letpair_res_471;
      }
      let_res_468 = letpair_res_469;
    }
    ::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27 let_res_474;
    {
      ::dessser::gen::raql_type::t13a07ee37ab40962540da8534858dc07 dtup_69 { let_res_468 };
      ::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27 letpair_res_475;
      {
        auto dtup_fst_70 { std::get<0>(dtup_69) };
        auto dtup_snd_71 { std::get<1>(dtup_69) };
        ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_476 { of_row_binary(dtup_snd_71) };
        ::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27 letpair_res_477;
        {
          auto dtup_fst_73 { std::get<0>(id_476) };
          auto dtup_snd_74 { std::get<1>(id_476) };
          std::shared_ptr<::dessser::gen::raql_type::named_type>  id_478 { std::make_shared<::dessser::gen::raql_type::named_type>(dtup_fst_70, dtup_fst_73) };
          ::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27 id_479 { id_478, dtup_snd_74 };
          letpair_res_477 = id_479;
        }
        letpair_res_475 = letpair_res_477;
      }
      let_res_474 = letpair_res_475;
    }
    return let_res_474;
  }
   };
  return fun426;
}
std::function<::dessser::gen::raql_type::t7fbe1cfb5917a94fd4534c65eba54a27(Pointer &)> named_type_of_row_binary(named_type_of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_286" "make_snd_287" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_286") (identifier "make_snd_287"))))
 */
static std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> fun480 { [&](Pointer p_0) {
    ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_481 { of_row_binary(p_0) };
    ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 letpair_res_482;
    {
      auto make_fst_286 { std::get<0>(id_481) };
      auto make_snd_287 { std::get<1>(id_481) };
      ::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033 id_483 { make_fst_286, make_snd_287 };
      letpair_res_482 = id_483;
    }
    return letpair_res_482;
  }
   };
  return fun480;
}
std::function<::dessser::gen::raql_type::t8b07d6797983610fb5146e4336d56033(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{type: (base AS [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]); nullable: BOOL}")
      (add (apply (identifier "base-sersize-of-row-binary") (get-field "type" (param 0))) (size 1)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t>  &)> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t>  &)> fun484 { [&](std::shared_ptr<::dessser::gen::raql_type::t>  p_0) {
    ::dessser::gen::raql_type::base id_485 { (*p_0).type };
    Size id_486 { base_sersize_of_row_binary(id_485) };
    Size id_487 { 1UL };
    Size id_488 { Size(id_486 + id_487) };
    return id_488;
  }
   };
  return fun484;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t>  &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]")
      (let "label2_293" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_293")) (size 2)
          (if (eq (u16 1) (identifier "label2_293")) (size 2)
            (if (eq (u16 2) (identifier "label2_293")) (size 2)
              (if (eq (u16 3) (identifier "label2_293")) (size 2)
                (if (eq (u16 4) (identifier "label2_293")) (size 2)
                  (if (eq (u16 5) (identifier "label2_293")) (size 2)
                    (if (eq (u16 6) (identifier "label2_293")) (size 2)
                      (if (eq (u16 7) (identifier "label2_293")) (size 2)
                        (if (eq (u16 8) (identifier "label2_293")) (size 2)
                          (if (eq (u16 9) (identifier "label2_293")) 
                            (size 2)
                            (if (eq (u16 10) (identifier "label2_293")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_293")) 
                                (size 2)
                                (if (eq (u16 12) (identifier "label2_293")) 
                                  (size 2)
                                  (if (eq (u16 13) (identifier "label2_293")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_293")) 
                                      (size 2)
                                      (if (eq (u16 15) (identifier "label2_293")) 
                                        (size 2)
                                        (if (eq (u16 16) (identifier "label2_293")) 
                                          (size 2)
                                          (if (eq (u16 17) (identifier "label2_293")) 
                                            (size 2)
                                            (if (eq (u16 18) (identifier "label2_293")) 
                                              (size 2)
                                              (if (eq (u16 19) (identifier "label2_293")) 
                                                (size 2)
                                                (if (eq (u16 20) (identifier "label2_293")) 
                                                  (size 2)
                                                  (if (eq (u16 21) (identifier "label2_293")) 
                                                    (size 2)
                                                    (if (eq (u16 22) (identifier "label2_293")) 
                                                      (size 2)
                                                      (if (eq (u16 23) (identifier "label2_293")) 
                                                        (size 2)
                                                        (if (eq (u16 24) (identifier "label2_293")) 
                                                          (size 2)
                                                          (if (eq (u16 25) (identifier "label2_293")) 
                                                            (size 2)
                                                            (if (eq (u16 26) (identifier "label2_293")) 
                                                              (size 2)
                                                              (if (eq (u16 27) (identifier "label2_293")) 
                                                                (size 2)
                                                                (if (eq (u16 28) (identifier "label2_293")) 
                                                                  (size 2)
                                                                  (if 
                                                                    (eq (u16 29) (identifier "label2_293")) 
                                                                    (size 2)
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_293"))
                                                                    (let "sz_ref_308"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_306" 
                                                                    (make-vec (cardinality (get-alt "Tup" (param 0))))
                                                                    (let "lebsz_ref_307" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_306")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_307")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_307") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_307")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_307"))))))))
                                                                    (seq
                                                                    (let "repeat_n_309" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Tup" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_309")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_308")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_308"))
                                                                    (apply (identifier "sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_309")) (get-alt "Tup" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_309") (add (unsafe-nth (u8 0) (identifier "repeat_n_309")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_308"))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_293")) 
                                                                    (add (size 6) (apply (identifier "sersize-of-row-binary") (get-item 1 (get-alt "Vec" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_293")) 
                                                                    (add (size 2) (apply (identifier "sersize-of-row-binary") (get-alt "Arr" (param 0))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_293"))
                                                                    (let "sz_ref_302"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_300" 
                                                                    (make-vec (cardinality (get-alt "Rec" (param 0))))
                                                                    (let "lebsz_ref_301" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_300")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_301")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_301") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_301")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_301"))))))))
                                                                    (seq
                                                                    (let "repeat_n_303" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Rec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_303")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_302")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_302"))
                                                                    (apply (identifier "named_type-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_303")) (get-alt "Rec" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_303") (add (unsafe-nth (u8 0) (identifier "repeat_n_303")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_302"))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_293"))
                                                                    (let "sz_ref_298"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_296" 
                                                                    (make-vec (cardinality (get-alt "Sum" (param 0))))
                                                                    (let "lebsz_ref_297" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_296")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_297")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_297") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_297")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_297"))))))))
                                                                    (seq
                                                                    (let "repeat_n_299" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Sum" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_299")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_298")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_298"))
                                                                    (apply (identifier "named_type-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_299")) (get-alt "Sum" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_299") (add (unsafe-nth (u8 0) (identifier "repeat_n_299")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_298"))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label2_293") (u16 35)))
                                                                    (let "sz_295" 
                                                                    (add (size 2) (apply (identifier "sersize-of-row-binary") (get-item 0 (get-alt "Map" (param 0)))))
                                                                    (add (identifier "sz_295") (apply (identifier "sersize-of-row-binary") (get-item 1 (get-alt "Map" (param 0))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::raql_type::base &)> base_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_type::base &)> fun489 { [&](::dessser::gen::raql_type::base p_0) {
    uint16_t id_490 { uint16_t(p_0.index()) };
    Size let_res_491;
    {
      uint16_t label2_293 { id_490 };
      uint16_t id_492 { 0 };
      bool id_493 { bool(id_492 == label2_293) };
      Size choose_res_494;
      if (id_493) {
        Size id_495 { 2UL };
        choose_res_494 = id_495;
      } else {
        uint16_t id_496 { 1 };
        bool id_497 { bool(id_496 == label2_293) };
        Size choose_res_498;
        if (id_497) {
          Size id_499 { 2UL };
          choose_res_498 = id_499;
        } else {
          uint16_t id_500 { 2 };
          bool id_501 { bool(id_500 == label2_293) };
          Size choose_res_502;
          if (id_501) {
            Size id_503 { 2UL };
            choose_res_502 = id_503;
          } else {
            uint16_t id_504 { 3 };
            bool id_505 { bool(id_504 == label2_293) };
            Size choose_res_506;
            if (id_505) {
              Size id_507 { 2UL };
              choose_res_506 = id_507;
            } else {
              uint16_t id_508 { 4 };
              bool id_509 { bool(id_508 == label2_293) };
              Size choose_res_510;
              if (id_509) {
                Size id_511 { 2UL };
                choose_res_510 = id_511;
              } else {
                uint16_t id_512 { 5 };
                bool id_513 { bool(id_512 == label2_293) };
                Size choose_res_514;
                if (id_513) {
                  Size id_515 { 2UL };
                  choose_res_514 = id_515;
                } else {
                  uint16_t id_516 { 6 };
                  bool id_517 { bool(id_516 == label2_293) };
                  Size choose_res_518;
                  if (id_517) {
                    Size id_519 { 2UL };
                    choose_res_518 = id_519;
                  } else {
                    uint16_t id_520 { 7 };
                    bool id_521 { bool(id_520 == label2_293) };
                    Size choose_res_522;
                    if (id_521) {
                      Size id_523 { 2UL };
                      choose_res_522 = id_523;
                    } else {
                      uint16_t id_524 { 8 };
                      bool id_525 { bool(id_524 == label2_293) };
                      Size choose_res_526;
                      if (id_525) {
                        Size id_527 { 2UL };
                        choose_res_526 = id_527;
                      } else {
                        uint16_t id_528 { 9 };
                        bool id_529 { bool(id_528 == label2_293) };
                        Size choose_res_530;
                        if (id_529) {
                          Size id_531 { 2UL };
                          choose_res_530 = id_531;
                        } else {
                          uint16_t id_532 { 10 };
                          bool id_533 { bool(id_532 == label2_293) };
                          Size choose_res_534;
                          if (id_533) {
                            Size id_535 { 2UL };
                            choose_res_534 = id_535;
                          } else {
                            uint16_t id_536 { 11 };
                            bool id_537 { bool(id_536 == label2_293) };
                            Size choose_res_538;
                            if (id_537) {
                              Size id_539 { 2UL };
                              choose_res_538 = id_539;
                            } else {
                              uint16_t id_540 { 12 };
                              bool id_541 { bool(id_540 == label2_293) };
                              Size choose_res_542;
                              if (id_541) {
                                Size id_543 { 2UL };
                                choose_res_542 = id_543;
                              } else {
                                uint16_t id_544 { 13 };
                                bool id_545 { bool(id_544 == label2_293) };
                                Size choose_res_546;
                                if (id_545) {
                                  Size id_547 { 2UL };
                                  choose_res_546 = id_547;
                                } else {
                                  uint16_t id_548 { 14 };
                                  bool id_549 { bool(id_548 == label2_293) };
                                  Size choose_res_550;
                                  if (id_549) {
                                    Size id_551 { 2UL };
                                    choose_res_550 = id_551;
                                  } else {
                                    uint16_t id_552 { 15 };
                                    bool id_553 { bool(id_552 == label2_293) };
                                    Size choose_res_554;
                                    if (id_553) {
                                      Size id_555 { 2UL };
                                      choose_res_554 = id_555;
                                    } else {
                                      uint16_t id_556 { 16 };
                                      bool id_557 { bool(id_556 == label2_293) };
                                      Size choose_res_558;
                                      if (id_557) {
                                        Size id_559 { 2UL };
                                        choose_res_558 = id_559;
                                      } else {
                                        uint16_t id_560 { 17 };
                                        bool id_561 { bool(id_560 == label2_293) };
                                        Size choose_res_562;
                                        if (id_561) {
                                          Size id_563 { 2UL };
                                          choose_res_562 = id_563;
                                        } else {
                                          uint16_t id_564 { 18 };
                                          bool id_565 { bool(id_564 == label2_293) };
                                          Size choose_res_566;
                                          if (id_565) {
                                            Size id_567 { 2UL };
                                            choose_res_566 = id_567;
                                          } else {
                                            uint16_t id_568 { 19 };
                                            bool id_569 { bool(id_568 == label2_293) };
                                            Size choose_res_570;
                                            if (id_569) {
                                              Size id_571 { 2UL };
                                              choose_res_570 = id_571;
                                            } else {
                                              uint16_t id_572 { 20 };
                                              bool id_573 { bool(id_572 == label2_293) };
                                              Size choose_res_574;
                                              if (id_573) {
                                                Size id_575 { 2UL };
                                                choose_res_574 = id_575;
                                              } else {
                                                uint16_t id_576 { 21 };
                                                bool id_577 { bool(id_576 == label2_293) };
                                                Size choose_res_578;
                                                if (id_577) {
                                                  Size id_579 { 2UL };
                                                  choose_res_578 = id_579;
                                                } else {
                                                  uint16_t id_580 { 22 };
                                                  bool id_581 { bool(id_580 == label2_293) };
                                                  Size choose_res_582;
                                                  if (id_581) {
                                                    Size id_583 { 2UL };
                                                    choose_res_582 = id_583;
                                                  } else {
                                                    uint16_t id_584 { 23 };
                                                    bool id_585 { bool(id_584 == label2_293) };
                                                    Size choose_res_586;
                                                    if (id_585) {
                                                      Size id_587 { 2UL };
                                                      choose_res_586 = id_587;
                                                    } else {
                                                      uint16_t id_588 { 24 };
                                                      bool id_589 { bool(id_588 == label2_293) };
                                                      Size choose_res_590;
                                                      if (id_589) {
                                                        Size id_591 { 2UL };
                                                        choose_res_590 = id_591;
                                                      } else {
                                                        uint16_t id_592 { 25 };
                                                        bool id_593 { bool(id_592 == label2_293) };
                                                        Size choose_res_594;
                                                        if (id_593) {
                                                          Size id_595 { 2UL };
                                                          choose_res_594 = id_595;
                                                        } else {
                                                          uint16_t id_596 { 26 };
                                                          bool id_597 { bool(id_596 == label2_293) };
                                                          Size choose_res_598;
                                                          if (id_597) {
                                                            Size id_599 { 2UL };
                                                            choose_res_598 = id_599;
                                                          } else {
                                                            uint16_t id_600 { 27 };
                                                            bool id_601 { bool(id_600 == label2_293) };
                                                            Size choose_res_602;
                                                            if (id_601) {
                                                              Size id_603 { 2UL };
                                                              choose_res_602 = id_603;
                                                            } else {
                                                              uint16_t id_604 { 28 };
                                                              bool id_605 { bool(id_604 == label2_293) };
                                                              Size choose_res_606;
                                                              if (id_605) {
                                                                Size id_607 { 2UL };
                                                                choose_res_606 = id_607;
                                                              } else {
                                                                uint16_t id_608 { 29 };
                                                                bool id_609 { bool(id_608 == label2_293) };
                                                                Size choose_res_610;
                                                                if (id_609) {
                                                                  Size id_611 { 2UL };
                                                                  choose_res_610 = id_611;
                                                                } else {
                                                                  uint16_t id_612 { 30 };
                                                                  bool id_613 { bool(id_612 == label2_293) };
                                                                  Size choose_res_614;
                                                                  if (id_613) {
                                                                    Size id_615 { 2UL };
                                                                    Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_616 { std::get<30 /* Tup */>(p_0) };
                                                                    uint32_t id_617 { id_616.size() };
                                                                    Vec<1, uint32_t> id_618 {  id_617  };
                                                                    Size let_res_619;
                                                                    {
                                                                      Vec<1, uint32_t> n_ref_306 { id_618 };
                                                                      uint32_t id_620 { 1U };
                                                                      Vec<1, uint32_t> id_621 {  id_620  };
                                                                      Size let_res_622;
                                                                      {
                                                                        Vec<1, uint32_t> lebsz_ref_307 { id_621 };
                                                                        bool while_flag_623 { true };
                                                                        do {
                                                                          uint8_t id_624 { 0 };
                                                                          uint32_t id_625 { n_ref_306[id_624] };
                                                                          uint8_t id_626 { 0 };
                                                                          uint32_t id_627 { lebsz_ref_307[id_626] };
                                                                          uint8_t id_628 { 7 };
                                                                          uint32_t id_629 { uint32_t(id_627 << id_628) };
                                                                          bool id_630 { bool(id_625 >= id_629) };
                                                                          while_flag_623 = id_630;
                                                                          if (while_flag_623) {
                                                                            uint8_t id_631 { 0 };
                                                                            uint8_t id_632 { 0 };
                                                                            uint32_t id_633 { lebsz_ref_307[id_632] };
                                                                            uint32_t id_634 { 1U };
                                                                            uint32_t id_635 { uint32_t(id_633 + id_634) };
                                                                            Void id_636 { ((void)(lebsz_ref_307[id_631] = id_635), ::dessser::Void()) };
                                                                            (void)id_636;
                                                                          }
                                                                        } while (while_flag_623);
                                                                        (void)::dessser::Void();
                                                                        uint8_t id_637 { 0 };
                                                                        uint32_t id_638 { lebsz_ref_307[id_637] };
                                                                        Size id_639 { Size(id_638) };
                                                                        let_res_622 = id_639;
                                                                      }
                                                                      let_res_619 = let_res_622;
                                                                    }
                                                                    Size id_640 { Size(id_615 + let_res_619) };
                                                                    Vec<1, Size> id_641 {  id_640  };
                                                                    Size let_res_642;
                                                                    {
                                                                      Vec<1, Size> sz_ref_308 { id_641 };
                                                                      int32_t id_643 { 0L };
                                                                      Vec<1, int32_t> id_644 {  id_643  };
                                                                      {
                                                                        Vec<1, int32_t> repeat_n_309 { id_644 };
                                                                        bool while_flag_645 { true };
                                                                        do {
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_646 { std::get<30 /* Tup */>(p_0) };
                                                                          uint32_t id_647 { id_646.size() };
                                                                          int32_t id_648 { int32_t(id_647) };
                                                                          uint8_t id_649 { 0 };
                                                                          int32_t id_650 { repeat_n_309[id_649] };
                                                                          bool id_651 { bool(id_648 > id_650) };
                                                                          while_flag_645 = id_651;
                                                                          if (while_flag_645) {
                                                                            uint8_t id_652 { 0 };
                                                                            uint8_t id_653 { 0 };
                                                                            Size id_654 { sz_ref_308[id_653] };
                                                                            uint8_t id_655 { 0 };
                                                                            int32_t id_656 { repeat_n_309[id_655] };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_657 { std::get<30 /* Tup */>(p_0) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::t>  id_658 { id_657[id_656] };
                                                                            Size id_659 { sersize_of_row_binary(id_658) };
                                                                            Size id_660 { Size(id_654 + id_659) };
                                                                            Void id_661 { ((void)(sz_ref_308[id_652] = id_660), ::dessser::Void()) };
                                                                            (void)id_661;
                                                                            uint8_t id_662 { 0 };
                                                                            uint8_t id_663 { 0 };
                                                                            int32_t id_664 { repeat_n_309[id_663] };
                                                                            int32_t id_665 { 1L };
                                                                            int32_t id_666 { int32_t(id_664 + id_665) };
                                                                            Void id_667 { ((void)(repeat_n_309[id_662] = id_666), ::dessser::Void()) };
                                                                            (void)id_667;
                                                                            (void)id_667;
                                                                          }
                                                                        } while (while_flag_645);
                                                                        (void)::dessser::Void();
                                                                      }
                                                                      (void)::dessser::Void();
                                                                      uint8_t id_668 { 0 };
                                                                      Size id_669 { sz_ref_308[id_668] };
                                                                      let_res_642 = id_669;
                                                                    }
                                                                    choose_res_614 = let_res_642;
                                                                  } else {
                                                                    uint16_t id_670 { 31 };
                                                                    bool id_671 { bool(id_670 == label2_293) };
                                                                    Size choose_res_672;
                                                                    if (id_671) {
                                                                      Size id_673 { 6UL };
                                                                      ::dessser::gen::raql_type::t9acdca30308e28313c3977aa48ab367d id_674 { std::get<31 /* Vec */>(p_0) };
                                                                      std::shared_ptr<::dessser::gen::raql_type::t>  id_675 { std::get<1>(id_674) };
                                                                      Size id_676 { sersize_of_row_binary(id_675) };
                                                                      Size id_677 { Size(id_673 + id_676) };
                                                                      choose_res_672 = id_677;
                                                                    } else {
                                                                      uint16_t id_678 { 32 };
                                                                      bool id_679 { bool(id_678 == label2_293) };
                                                                      Size choose_res_680;
                                                                      if (id_679) {
                                                                        Size id_681 { 2UL };
                                                                        std::shared_ptr<::dessser::gen::raql_type::t>  id_682 { std::get<32 /* Arr */>(p_0) };
                                                                        Size id_683 { sersize_of_row_binary(id_682) };
                                                                        Size id_684 { Size(id_681 + id_683) };
                                                                        choose_res_680 = id_684;
                                                                      } else {
                                                                        uint16_t id_685 { 33 };
                                                                        bool id_686 { bool(id_685 == label2_293) };
                                                                        Size choose_res_687;
                                                                        if (id_686) {
                                                                          Size id_688 { 2UL };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_689 { std::get<33 /* Rec */>(p_0) };
                                                                          uint32_t id_690 { id_689.size() };
                                                                          Vec<1, uint32_t> id_691 {  id_690  };
                                                                          Size let_res_692;
                                                                          {
                                                                            Vec<1, uint32_t> n_ref_300 { id_691 };
                                                                            uint32_t id_693 { 1U };
                                                                            Vec<1, uint32_t> id_694 {  id_693  };
                                                                            Size let_res_695;
                                                                            {
                                                                              Vec<1, uint32_t> lebsz_ref_301 { id_694 };
                                                                              bool while_flag_696 { true };
                                                                              do {
                                                                                uint8_t id_697 { 0 };
                                                                                uint32_t id_698 { n_ref_300[id_697] };
                                                                                uint8_t id_699 { 0 };
                                                                                uint32_t id_700 { lebsz_ref_301[id_699] };
                                                                                uint8_t id_701 { 7 };
                                                                                uint32_t id_702 { uint32_t(id_700 << id_701) };
                                                                                bool id_703 { bool(id_698 >= id_702) };
                                                                                while_flag_696 = id_703;
                                                                                if (while_flag_696) {
                                                                                  uint8_t id_704 { 0 };
                                                                                  uint8_t id_705 { 0 };
                                                                                  uint32_t id_706 { lebsz_ref_301[id_705] };
                                                                                  uint32_t id_707 { 1U };
                                                                                  uint32_t id_708 { uint32_t(id_706 + id_707) };
                                                                                  Void id_709 { ((void)(lebsz_ref_301[id_704] = id_708), ::dessser::Void()) };
                                                                                  (void)id_709;
                                                                                }
                                                                              } while (while_flag_696);
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_710 { 0 };
                                                                              uint32_t id_711 { lebsz_ref_301[id_710] };
                                                                              Size id_712 { Size(id_711) };
                                                                              let_res_695 = id_712;
                                                                            }
                                                                            let_res_692 = let_res_695;
                                                                          }
                                                                          Size id_713 { Size(id_688 + let_res_692) };
                                                                          Vec<1, Size> id_714 {  id_713  };
                                                                          Size let_res_715;
                                                                          {
                                                                            Vec<1, Size> sz_ref_302 { id_714 };
                                                                            int32_t id_716 { 0L };
                                                                            Vec<1, int32_t> id_717 {  id_716  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_303 { id_717 };
                                                                              bool while_flag_718 { true };
                                                                              do {
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_719 { std::get<33 /* Rec */>(p_0) };
                                                                                uint32_t id_720 { id_719.size() };
                                                                                int32_t id_721 { int32_t(id_720) };
                                                                                uint8_t id_722 { 0 };
                                                                                int32_t id_723 { repeat_n_303[id_722] };
                                                                                bool id_724 { bool(id_721 > id_723) };
                                                                                while_flag_718 = id_724;
                                                                                if (while_flag_718) {
                                                                                  uint8_t id_725 { 0 };
                                                                                  uint8_t id_726 { 0 };
                                                                                  Size id_727 { sz_ref_302[id_726] };
                                                                                  uint8_t id_728 { 0 };
                                                                                  int32_t id_729 { repeat_n_303[id_728] };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_730 { std::get<33 /* Rec */>(p_0) };
                                                                                  std::shared_ptr<::dessser::gen::raql_type::named_type>  id_731 { id_730[id_729] };
                                                                                  Size id_732 { named_type_sersize_of_row_binary(id_731) };
                                                                                  Size id_733 { Size(id_727 + id_732) };
                                                                                  Void id_734 { ((void)(sz_ref_302[id_725] = id_733), ::dessser::Void()) };
                                                                                  (void)id_734;
                                                                                  uint8_t id_735 { 0 };
                                                                                  uint8_t id_736 { 0 };
                                                                                  int32_t id_737 { repeat_n_303[id_736] };
                                                                                  int32_t id_738 { 1L };
                                                                                  int32_t id_739 { int32_t(id_737 + id_738) };
                                                                                  Void id_740 { ((void)(repeat_n_303[id_735] = id_739), ::dessser::Void()) };
                                                                                  (void)id_740;
                                                                                  (void)id_740;
                                                                                }
                                                                              } while (while_flag_718);
                                                                              (void)::dessser::Void();
                                                                            }
                                                                            (void)::dessser::Void();
                                                                            uint8_t id_741 { 0 };
                                                                            Size id_742 { sz_ref_302[id_741] };
                                                                            let_res_715 = id_742;
                                                                          }
                                                                          choose_res_687 = let_res_715;
                                                                        } else {
                                                                          uint16_t id_743 { 34 };
                                                                          bool id_744 { bool(id_743 == label2_293) };
                                                                          Size choose_res_745;
                                                                          if (id_744) {
                                                                            Size id_746 { 2UL };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_747 { std::get<34 /* Sum */>(p_0) };
                                                                            uint32_t id_748 { id_747.size() };
                                                                            Vec<1, uint32_t> id_749 {  id_748  };
                                                                            Size let_res_750;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_296 { id_749 };
                                                                              uint32_t id_751 { 1U };
                                                                              Vec<1, uint32_t> id_752 {  id_751  };
                                                                              Size let_res_753;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_297 { id_752 };
                                                                                bool while_flag_754 { true };
                                                                                do {
                                                                                  uint8_t id_755 { 0 };
                                                                                  uint32_t id_756 { n_ref_296[id_755] };
                                                                                  uint8_t id_757 { 0 };
                                                                                  uint32_t id_758 { lebsz_ref_297[id_757] };
                                                                                  uint8_t id_759 { 7 };
                                                                                  uint32_t id_760 { uint32_t(id_758 << id_759) };
                                                                                  bool id_761 { bool(id_756 >= id_760) };
                                                                                  while_flag_754 = id_761;
                                                                                  if (while_flag_754) {
                                                                                    uint8_t id_762 { 0 };
                                                                                    uint8_t id_763 { 0 };
                                                                                    uint32_t id_764 { lebsz_ref_297[id_763] };
                                                                                    uint32_t id_765 { 1U };
                                                                                    uint32_t id_766 { uint32_t(id_764 + id_765) };
                                                                                    Void id_767 { ((void)(lebsz_ref_297[id_762] = id_766), ::dessser::Void()) };
                                                                                    (void)id_767;
                                                                                  }
                                                                                } while (while_flag_754);
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_768 { 0 };
                                                                                uint32_t id_769 { lebsz_ref_297[id_768] };
                                                                                Size id_770 { Size(id_769) };
                                                                                let_res_753 = id_770;
                                                                              }
                                                                              let_res_750 = let_res_753;
                                                                            }
                                                                            Size id_771 { Size(id_746 + let_res_750) };
                                                                            Vec<1, Size> id_772 {  id_771  };
                                                                            Size let_res_773;
                                                                            {
                                                                              Vec<1, Size> sz_ref_298 { id_772 };
                                                                              int32_t id_774 { 0L };
                                                                              Vec<1, int32_t> id_775 {  id_774  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_299 { id_775 };
                                                                                bool while_flag_776 { true };
                                                                                do {
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_777 { std::get<34 /* Sum */>(p_0) };
                                                                                  uint32_t id_778 { id_777.size() };
                                                                                  int32_t id_779 { int32_t(id_778) };
                                                                                  uint8_t id_780 { 0 };
                                                                                  int32_t id_781 { repeat_n_299[id_780] };
                                                                                  bool id_782 { bool(id_779 > id_781) };
                                                                                  while_flag_776 = id_782;
                                                                                  if (while_flag_776) {
                                                                                    uint8_t id_783 { 0 };
                                                                                    uint8_t id_784 { 0 };
                                                                                    Size id_785 { sz_ref_298[id_784] };
                                                                                    uint8_t id_786 { 0 };
                                                                                    int32_t id_787 { repeat_n_299[id_786] };
                                                                                    Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_788 { std::get<34 /* Sum */>(p_0) };
                                                                                    std::shared_ptr<::dessser::gen::raql_type::named_type>  id_789 { id_788[id_787] };
                                                                                    Size id_790 { named_type_sersize_of_row_binary(id_789) };
                                                                                    Size id_791 { Size(id_785 + id_790) };
                                                                                    Void id_792 { ((void)(sz_ref_298[id_783] = id_791), ::dessser::Void()) };
                                                                                    (void)id_792;
                                                                                    uint8_t id_793 { 0 };
                                                                                    uint8_t id_794 { 0 };
                                                                                    int32_t id_795 { repeat_n_299[id_794] };
                                                                                    int32_t id_796 { 1L };
                                                                                    int32_t id_797 { int32_t(id_795 + id_796) };
                                                                                    Void id_798 { ((void)(repeat_n_299[id_793] = id_797), ::dessser::Void()) };
                                                                                    (void)id_798;
                                                                                    (void)id_798;
                                                                                  }
                                                                                } while (while_flag_776);
                                                                                (void)::dessser::Void();
                                                                              }
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_799 { 0 };
                                                                              Size id_800 { sz_ref_298[id_799] };
                                                                              let_res_773 = id_800;
                                                                            }
                                                                            choose_res_745 = let_res_773;
                                                                          } else {
                                                                            uint16_t id_801 { 35 };
                                                                            bool id_802 { bool(label2_293 == id_801) };
                                                                            Void id_803 { ((void)(assert(id_802)), ::dessser::Void()) };
                                                                            (void)id_803;
                                                                            Size id_804 { 2UL };
                                                                            ::dessser::gen::raql_type::t550173c9cc042d56a37c01d7d8bbfa95 id_805 { std::get<35 /* Map */>(p_0) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::t>  id_806 { std::get<0>(id_805) };
                                                                            Size id_807 { sersize_of_row_binary(id_806) };
                                                                            Size id_808 { Size(id_804 + id_807) };
                                                                            Size let_res_809;
                                                                            {
                                                                              Size sz_295 { id_808 };
                                                                              ::dessser::gen::raql_type::t550173c9cc042d56a37c01d7d8bbfa95 id_810 { std::get<35 /* Map */>(p_0) };
                                                                              std::shared_ptr<::dessser::gen::raql_type::t>  id_811 { std::get<1>(id_810) };
                                                                              Size id_812 { sersize_of_row_binary(id_811) };
                                                                              Size id_813 { Size(sz_295 + id_812) };
                                                                              let_res_809 = id_813;
                                                                            }
                                                                            choose_res_745 = let_res_809;
                                                                          }
                                                                          choose_res_687 = choose_res_745;
                                                                        }
                                                                        choose_res_680 = choose_res_687;
                                                                      }
                                                                      choose_res_672 = choose_res_680;
                                                                    }
                                                                    choose_res_614 = choose_res_672;
                                                                  }
                                                                  choose_res_610 = choose_res_614;
                                                                }
                                                                choose_res_606 = choose_res_610;
                                                              }
                                                              choose_res_602 = choose_res_606;
                                                            }
                                                            choose_res_598 = choose_res_602;
                                                          }
                                                          choose_res_594 = choose_res_598;
                                                        }
                                                        choose_res_590 = choose_res_594;
                                                      }
                                                      choose_res_586 = choose_res_590;
                                                    }
                                                    choose_res_582 = choose_res_586;
                                                  }
                                                  choose_res_578 = choose_res_582;
                                                }
                                                choose_res_574 = choose_res_578;
                                              }
                                              choose_res_570 = choose_res_574;
                                            }
                                            choose_res_566 = choose_res_570;
                                          }
                                          choose_res_562 = choose_res_566;
                                        }
                                        choose_res_558 = choose_res_562;
                                      }
                                      choose_res_554 = choose_res_558;
                                    }
                                    choose_res_550 = choose_res_554;
                                  }
                                  choose_res_546 = choose_res_550;
                                }
                                choose_res_542 = choose_res_546;
                              }
                              choose_res_538 = choose_res_542;
                            }
                            choose_res_534 = choose_res_538;
                          }
                          choose_res_530 = choose_res_534;
                        }
                        choose_res_526 = choose_res_530;
                      }
                      choose_res_522 = choose_res_526;
                    }
                    choose_res_518 = choose_res_522;
                  }
                  choose_res_514 = choose_res_518;
                }
                choose_res_510 = choose_res_514;
              }
              choose_res_506 = choose_res_510;
            }
            choose_res_502 = choose_res_506;
          }
          choose_res_498 = choose_res_502;
        }
        choose_res_494 = choose_res_498;
      }
      let_res_491 = choose_res_494;
    }
    return let_res_491;
  }
   };
  return fun489;
}
std::function<Size(::dessser::gen::raql_type::base &)> base_sersize_of_row_binary(base_sersize_of_row_binary_init());

/* 
    (fun ("(STRING; THIS)")
      (let "sz_292"
        (add
          (let "n_ref_290" (make-vec (string-length (get-item 0 (param 0))))
            (let "lebsz_ref_291" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_290")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_291") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_291")))))) 
          (size-of-u32 (string-length (get-item 0 (param 0))))) (add (identifier "sz_292") (apply (identifier "sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type>  &)> named_type_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type>  &)> fun814 { [&](std::shared_ptr<::dessser::gen::raql_type::named_type>  p_0) {
    std::string id_815 { std::get<0>((*p_0)) };
    uint32_t id_816 { (uint32_t)id_815.size() };
    Vec<1, uint32_t> id_817 {  id_816  };
    Size let_res_818;
    {
      Vec<1, uint32_t> n_ref_290 { id_817 };
      uint32_t id_819 { 1U };
      Vec<1, uint32_t> id_820 {  id_819  };
      Size let_res_821;
      {
        Vec<1, uint32_t> lebsz_ref_291 { id_820 };
        bool while_flag_822 { true };
        do {
          uint8_t id_823 { 0 };
          uint32_t id_824 { n_ref_290[id_823] };
          uint8_t id_825 { 0 };
          uint32_t id_826 { lebsz_ref_291[id_825] };
          uint8_t id_827 { 7 };
          uint32_t id_828 { uint32_t(id_826 << id_827) };
          bool id_829 { bool(id_824 >= id_828) };
          while_flag_822 = id_829;
          if (while_flag_822) {
            uint8_t id_830 { 0 };
            uint8_t id_831 { 0 };
            uint32_t id_832 { lebsz_ref_291[id_831] };
            uint32_t id_833 { 1U };
            uint32_t id_834 { uint32_t(id_832 + id_833) };
            Void id_835 { ((void)(lebsz_ref_291[id_830] = id_834), ::dessser::Void()) };
            (void)id_835;
          }
        } while (while_flag_822);
        (void)::dessser::Void();
        uint8_t id_836 { 0 };
        uint32_t id_837 { lebsz_ref_291[id_836] };
        Size id_838 { Size(id_837) };
        let_res_821 = id_838;
      }
      let_res_818 = let_res_821;
    }
    std::string id_839 { std::get<0>((*p_0)) };
    uint32_t id_840 { (uint32_t)id_839.size() };
    Size id_841 { Size(id_840) };
    Size id_842 { Size(let_res_818 + id_841) };
    Size let_res_843;
    {
      Size sz_292 { id_842 };
      std::shared_ptr<::dessser::gen::raql_type::t>  id_844 { std::get<1>((*p_0)) };
      Size id_845 { sersize_of_row_binary(id_844) };
      Size id_846 { Size(sz_292 + id_845) };
      let_res_843 = id_846;
    }
    return let_res_843;
  }
   };
  return fun814;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type>  &)> named_type_sersize_of_row_binary(named_type_sersize_of_row_binary_init());

/* 
    (fun ("{type: (base AS [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]); nullable: BOOL}" "Ptr")
      (let "srec_dst_334" (apply (identifier "base-to-row-binary") (get-field "type" (param 0)) (param 1)) (write-u8 (identifier "srec_dst_334") (u8-of-bool (get-field "nullable" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> fun847 { [&](std::shared_ptr<::dessser::gen::raql_type::t>  p_0, Pointer p_1) {
    ::dessser::gen::raql_type::base id_848 { (*p_0).type };
    Pointer id_849 { base_to_row_binary(id_848, p_1) };
    Pointer let_res_850;
    {
      Pointer srec_dst_334 { id_849 };
      bool id_851 { (*p_0).nullable };
      uint8_t id_852 { uint8_t(id_851) };
      Pointer id_853 { srec_dst_334.writeU8(id_852) };
      let_res_850 = id_853;
    }
    return let_res_850;
  }
   };
  return fun847;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" "Ptr")
      (let "label1_315" (label-of (param 0))
        (let "ssum_dst_316" (write-u16 little-endian (param 1) (identifier "label1_315"))
          (if (eq (u16 0) (identifier "label1_315")) (identifier "ssum_dst_316")
            (if (eq (u16 1) (identifier "label1_315")) (identifier "ssum_dst_316")
              (if (eq (u16 2) (identifier "label1_315")) (identifier "ssum_dst_316")
                (if (eq (u16 3) (identifier "label1_315")) (identifier "ssum_dst_316")
                  (if (eq (u16 4) (identifier "label1_315")) (identifier "ssum_dst_316")
                    (if (eq (u16 5) (identifier "label1_315")) (identifier "ssum_dst_316")
                      (if (eq (u16 6) (identifier "label1_315")) (identifier "ssum_dst_316")
                        (if (eq (u16 7) (identifier "label1_315")) (identifier "ssum_dst_316")
                          (if (eq (u16 8) (identifier "label1_315")) 
                            (identifier "ssum_dst_316")
                            (if (eq (u16 9) (identifier "label1_315")) 
                              (identifier "ssum_dst_316")
                              (if (eq (u16 10) (identifier "label1_315")) 
                                (identifier "ssum_dst_316")
                                (if (eq (u16 11) (identifier "label1_315")) 
                                  (identifier "ssum_dst_316")
                                  (if (eq (u16 12) (identifier "label1_315")) 
                                    (identifier "ssum_dst_316")
                                    (if (eq (u16 13) (identifier "label1_315")) 
                                      (identifier "ssum_dst_316")
                                      (if (eq (u16 14) (identifier "label1_315")) 
                                        (identifier "ssum_dst_316")
                                        (if (eq (u16 15) (identifier "label1_315")) 
                                          (identifier "ssum_dst_316")
                                          (if (eq (u16 16) (identifier "label1_315")) 
                                            (identifier "ssum_dst_316")
                                            (if (eq (u16 17) (identifier "label1_315")) 
                                              (identifier "ssum_dst_316")
                                              (if (eq (u16 18) (identifier "label1_315")) 
                                                (identifier "ssum_dst_316")
                                                (if (eq (u16 19) (identifier "label1_315")) 
                                                  (identifier "ssum_dst_316")
                                                  (if (eq (u16 20) (identifier "label1_315")) 
                                                    (identifier "ssum_dst_316")
                                                    (if (eq (u16 21) (identifier "label1_315")) 
                                                      (identifier "ssum_dst_316")
                                                      (if (eq (u16 22) (identifier "label1_315")) 
                                                        (identifier "ssum_dst_316")
                                                        (if (eq (u16 23) (identifier "label1_315")) 
                                                          (identifier "ssum_dst_316")
                                                          (if (eq (u16 24) (identifier "label1_315")) 
                                                            (identifier "ssum_dst_316")
                                                            (if (eq (u16 25) (identifier "label1_315")) 
                                                              (identifier "ssum_dst_316")
                                                              (if (eq (u16 26) (identifier "label1_315")) 
                                                                (identifier "ssum_dst_316")
                                                                (if (eq (u16 27) (identifier "label1_315")) 
                                                                  (identifier "ssum_dst_316")
                                                                  (if 
                                                                    (eq (u16 28) (identifier "label1_315")) 
                                                                    (identifier "ssum_dst_316")
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_315")) 
                                                                    (identifier "ssum_dst_316")
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_315"))
                                                                    (let "dst_ref_331"
                                                                    (make-vec
                                                                    (let "leb128_sz_329" 
                                                                    (make-vec (cardinality (get-alt "Tup" (param 0))))
                                                                    (let "leb128_ptr_330" 
                                                                    (make-vec (identifier "ssum_dst_316"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_330")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_330"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_329"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_329"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_329"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_329") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_329")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_329")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_330"))))))
                                                                    (let "n_ref_332" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_333" 
                                                                    (get-alt "Tup" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_331") (apply (identifier "to-row-binary") (identifier "x_333") (unsafe-nth (u8 0) (identifier "dst_ref_331"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_332") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_332")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_331")))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_315"))
                                                                    (let "stup_dst_328" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_316") (get-item 0 (get-alt "Vec" (param 0))))
                                                                    (apply (identifier "to-row-binary") (get-item 1 (get-alt "Vec" (param 0))) (identifier "stup_dst_328")))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_315")) 
                                                                    (apply (identifier "to-row-binary") (get-alt "Arr" (param 0)) (identifier "ssum_dst_316"))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_315"))
                                                                    (let "dst_ref_325"
                                                                    (make-vec
                                                                    (let "leb128_sz_323" 
                                                                    (make-vec (cardinality (get-alt "Rec" (param 0))))
                                                                    (let "leb128_ptr_324" 
                                                                    (make-vec (identifier "ssum_dst_316"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_324")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_324"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_323") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_323")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_323")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_324"))))))
                                                                    (let "n_ref_326" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_327" 
                                                                    (get-alt "Rec" (param 0))
                                                                    (seq
                                                                    (set-vec (u8 0) (identifier "dst_ref_325") (apply (identifier "named_type-to-row-binary") (identifier "x_327") (unsafe-nth (u8 0) (identifier "dst_ref_325"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_326") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_326")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_325")))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_315"))
                                                                    (let "dst_ref_320"
                                                                    (make-vec
                                                                    (let "leb128_sz_318" 
                                                                    (make-vec (cardinality (get-alt "Sum" (param 0))))
                                                                    (let "leb128_ptr_319" 
                                                                    (make-vec (identifier "ssum_dst_316"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_319")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_319"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_318"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_318"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_318"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_318") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_318")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_318")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_319"))))))
                                                                    (let "n_ref_321" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_322" 
                                                                    (get-alt "Sum" (param 0))
                                                                    (seq
                                                                    (set-vec (u8 0) (identifier "dst_ref_320") (apply (identifier "named_type-to-row-binary") (identifier "x_322") (unsafe-nth (u8 0) (identifier "dst_ref_320"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_321") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_321")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_320")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label1_315") (u16 35)))
                                                                    (let "stup_dst_317" 
                                                                    (apply (identifier "to-row-binary") (get-item 0 (get-alt "Map" (param 0))) (identifier "ssum_dst_316"))
                                                                    (apply (identifier "to-row-binary") (get-item 1 (get-alt "Map" (param 0))) (identifier "stup_dst_317"))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::raql_type::base &,Pointer &)> base_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_type::base &,Pointer &)> fun854 { [&](::dessser::gen::raql_type::base p_0, Pointer p_1) {
    uint16_t id_855 { uint16_t(p_0.index()) };
    Pointer let_res_856;
    {
      uint16_t label1_315 { id_855 };
      Pointer id_857 { p_1.writeU16Le(label1_315) };
      Pointer let_res_858;
      {
        Pointer ssum_dst_316 { id_857 };
        uint16_t id_859 { 0 };
        bool id_860 { bool(id_859 == label1_315) };
        Pointer choose_res_861;
        if (id_860) {
          choose_res_861 = ssum_dst_316;
        } else {
          uint16_t id_862 { 1 };
          bool id_863 { bool(id_862 == label1_315) };
          Pointer choose_res_864;
          if (id_863) {
            choose_res_864 = ssum_dst_316;
          } else {
            uint16_t id_865 { 2 };
            bool id_866 { bool(id_865 == label1_315) };
            Pointer choose_res_867;
            if (id_866) {
              choose_res_867 = ssum_dst_316;
            } else {
              uint16_t id_868 { 3 };
              bool id_869 { bool(id_868 == label1_315) };
              Pointer choose_res_870;
              if (id_869) {
                choose_res_870 = ssum_dst_316;
              } else {
                uint16_t id_871 { 4 };
                bool id_872 { bool(id_871 == label1_315) };
                Pointer choose_res_873;
                if (id_872) {
                  choose_res_873 = ssum_dst_316;
                } else {
                  uint16_t id_874 { 5 };
                  bool id_875 { bool(id_874 == label1_315) };
                  Pointer choose_res_876;
                  if (id_875) {
                    choose_res_876 = ssum_dst_316;
                  } else {
                    uint16_t id_877 { 6 };
                    bool id_878 { bool(id_877 == label1_315) };
                    Pointer choose_res_879;
                    if (id_878) {
                      choose_res_879 = ssum_dst_316;
                    } else {
                      uint16_t id_880 { 7 };
                      bool id_881 { bool(id_880 == label1_315) };
                      Pointer choose_res_882;
                      if (id_881) {
                        choose_res_882 = ssum_dst_316;
                      } else {
                        uint16_t id_883 { 8 };
                        bool id_884 { bool(id_883 == label1_315) };
                        Pointer choose_res_885;
                        if (id_884) {
                          choose_res_885 = ssum_dst_316;
                        } else {
                          uint16_t id_886 { 9 };
                          bool id_887 { bool(id_886 == label1_315) };
                          Pointer choose_res_888;
                          if (id_887) {
                            choose_res_888 = ssum_dst_316;
                          } else {
                            uint16_t id_889 { 10 };
                            bool id_890 { bool(id_889 == label1_315) };
                            Pointer choose_res_891;
                            if (id_890) {
                              choose_res_891 = ssum_dst_316;
                            } else {
                              uint16_t id_892 { 11 };
                              bool id_893 { bool(id_892 == label1_315) };
                              Pointer choose_res_894;
                              if (id_893) {
                                choose_res_894 = ssum_dst_316;
                              } else {
                                uint16_t id_895 { 12 };
                                bool id_896 { bool(id_895 == label1_315) };
                                Pointer choose_res_897;
                                if (id_896) {
                                  choose_res_897 = ssum_dst_316;
                                } else {
                                  uint16_t id_898 { 13 };
                                  bool id_899 { bool(id_898 == label1_315) };
                                  Pointer choose_res_900;
                                  if (id_899) {
                                    choose_res_900 = ssum_dst_316;
                                  } else {
                                    uint16_t id_901 { 14 };
                                    bool id_902 { bool(id_901 == label1_315) };
                                    Pointer choose_res_903;
                                    if (id_902) {
                                      choose_res_903 = ssum_dst_316;
                                    } else {
                                      uint16_t id_904 { 15 };
                                      bool id_905 { bool(id_904 == label1_315) };
                                      Pointer choose_res_906;
                                      if (id_905) {
                                        choose_res_906 = ssum_dst_316;
                                      } else {
                                        uint16_t id_907 { 16 };
                                        bool id_908 { bool(id_907 == label1_315) };
                                        Pointer choose_res_909;
                                        if (id_908) {
                                          choose_res_909 = ssum_dst_316;
                                        } else {
                                          uint16_t id_910 { 17 };
                                          bool id_911 { bool(id_910 == label1_315) };
                                          Pointer choose_res_912;
                                          if (id_911) {
                                            choose_res_912 = ssum_dst_316;
                                          } else {
                                            uint16_t id_913 { 18 };
                                            bool id_914 { bool(id_913 == label1_315) };
                                            Pointer choose_res_915;
                                            if (id_914) {
                                              choose_res_915 = ssum_dst_316;
                                            } else {
                                              uint16_t id_916 { 19 };
                                              bool id_917 { bool(id_916 == label1_315) };
                                              Pointer choose_res_918;
                                              if (id_917) {
                                                choose_res_918 = ssum_dst_316;
                                              } else {
                                                uint16_t id_919 { 20 };
                                                bool id_920 { bool(id_919 == label1_315) };
                                                Pointer choose_res_921;
                                                if (id_920) {
                                                  choose_res_921 = ssum_dst_316;
                                                } else {
                                                  uint16_t id_922 { 21 };
                                                  bool id_923 { bool(id_922 == label1_315) };
                                                  Pointer choose_res_924;
                                                  if (id_923) {
                                                    choose_res_924 = ssum_dst_316;
                                                  } else {
                                                    uint16_t id_925 { 22 };
                                                    bool id_926 { bool(id_925 == label1_315) };
                                                    Pointer choose_res_927;
                                                    if (id_926) {
                                                      choose_res_927 = ssum_dst_316;
                                                    } else {
                                                      uint16_t id_928 { 23 };
                                                      bool id_929 { bool(id_928 == label1_315) };
                                                      Pointer choose_res_930;
                                                      if (id_929) {
                                                        choose_res_930 = ssum_dst_316;
                                                      } else {
                                                        uint16_t id_931 { 24 };
                                                        bool id_932 { bool(id_931 == label1_315) };
                                                        Pointer choose_res_933;
                                                        if (id_932) {
                                                          choose_res_933 = ssum_dst_316;
                                                        } else {
                                                          uint16_t id_934 { 25 };
                                                          bool id_935 { bool(id_934 == label1_315) };
                                                          Pointer choose_res_936;
                                                          if (id_935) {
                                                            choose_res_936 = ssum_dst_316;
                                                          } else {
                                                            uint16_t id_937 { 26 };
                                                            bool id_938 { bool(id_937 == label1_315) };
                                                            Pointer choose_res_939;
                                                            if (id_938) {
                                                              choose_res_939 = ssum_dst_316;
                                                            } else {
                                                              uint16_t id_940 { 27 };
                                                              bool id_941 { bool(id_940 == label1_315) };
                                                              Pointer choose_res_942;
                                                              if (id_941) {
                                                                choose_res_942 = ssum_dst_316;
                                                              } else {
                                                                uint16_t id_943 { 28 };
                                                                bool id_944 { bool(id_943 == label1_315) };
                                                                Pointer choose_res_945;
                                                                if (id_944) {
                                                                  choose_res_945 = ssum_dst_316;
                                                                } else {
                                                                  uint16_t id_946 { 29 };
                                                                  bool id_947 { bool(id_946 == label1_315) };
                                                                  Pointer choose_res_948;
                                                                  if (id_947) {
                                                                    choose_res_948 = ssum_dst_316;
                                                                  } else {
                                                                    uint16_t id_949 { 30 };
                                                                    bool id_950 { bool(id_949 == label1_315) };
                                                                    Pointer choose_res_951;
                                                                    if (id_950) {
                                                                      Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_952 { std::get<30 /* Tup */>(p_0) };
                                                                      uint32_t id_953 { id_952.size() };
                                                                      Vec<1, uint32_t> id_954 {  id_953  };
                                                                      Pointer let_res_955;
                                                                      {
                                                                        Vec<1, uint32_t> leb128_sz_329 { id_954 };
                                                                        Vec<1, Pointer> id_956 {  ssum_dst_316  };
                                                                        Pointer let_res_957;
                                                                        {
                                                                          Vec<1, Pointer> leb128_ptr_330 { id_956 };
                                                                          bool while_flag_958 { true };
                                                                          do {
                                                                            uint8_t id_959 { 0 };
                                                                            uint8_t id_960 { 0 };
                                                                            Pointer id_961 { leb128_ptr_330[id_960] };
                                                                            uint32_t id_962 { 128U };
                                                                            uint8_t id_963 { 0 };
                                                                            uint32_t id_964 { leb128_sz_329[id_963] };
                                                                            bool id_965 { bool(id_962 > id_964) };
                                                                            uint8_t choose_res_966;
                                                                            if (id_965) {
                                                                              uint8_t id_967 { 0 };
                                                                              uint32_t id_968 { leb128_sz_329[id_967] };
                                                                              uint8_t id_969 { uint8_t(id_968) };
                                                                              choose_res_966 = id_969;
                                                                            } else {
                                                                              uint8_t id_970 { 0 };
                                                                              uint32_t id_971 { leb128_sz_329[id_970] };
                                                                              uint8_t id_972 { uint8_t(id_971) };
                                                                              uint8_t id_973 { 128 };
                                                                              uint8_t id_974 { uint8_t(id_972 | id_973) };
                                                                              choose_res_966 = id_974;
                                                                            }
                                                                            Pointer id_975 { id_961.writeU8(choose_res_966) };
                                                                            Void id_976 { ((void)(leb128_ptr_330[id_959] = id_975), ::dessser::Void()) };
                                                                            (void)id_976;
                                                                            uint8_t id_977 { 0 };
                                                                            uint8_t id_978 { 0 };
                                                                            uint32_t id_979 { leb128_sz_329[id_978] };
                                                                            uint8_t id_980 { 7 };
                                                                            uint32_t id_981 { uint32_t(id_979 >> id_980) };
                                                                            Void id_982 { ((void)(leb128_sz_329[id_977] = id_981), ::dessser::Void()) };
                                                                            (void)id_982;
                                                                            uint8_t id_983 { 0 };
                                                                            uint32_t id_984 { leb128_sz_329[id_983] };
                                                                            uint32_t id_985 { 0U };
                                                                            bool id_986 { bool(id_984 > id_985) };
                                                                            while_flag_958 = id_986;
                                                                            if (while_flag_958) {
                                                                              (void)::dessser::Void();
                                                                            }
                                                                          } while (while_flag_958);
                                                                          (void)::dessser::Void();
                                                                          uint8_t id_987 { 0 };
                                                                          Pointer id_988 { leb128_ptr_330[id_987] };
                                                                          let_res_957 = id_988;
                                                                        }
                                                                        let_res_955 = let_res_957;
                                                                      }
                                                                      Vec<1, Pointer> id_989 {  let_res_955  };
                                                                      Pointer let_res_990;
                                                                      {
                                                                        Vec<1, Pointer> dst_ref_331 { id_989 };
                                                                        int32_t id_991 { 0L };
                                                                        Vec<1, int32_t> id_992 {  id_991  };
                                                                        Pointer let_res_993;
                                                                        {
                                                                          Vec<1, int32_t> n_ref_332 { id_992 };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_994 { std::get<30 /* Tup */>(p_0) };
                                                                          for (std::shared_ptr<::dessser::gen::raql_type::t>  &x_333 : id_994) {
                                                                            uint8_t id_995 { 0 };
                                                                            uint8_t id_996 { 0 };
                                                                            Pointer id_997 { dst_ref_331[id_996] };
                                                                            Pointer id_998 { to_row_binary(x_333, id_997) };
                                                                            Void id_999 { ((void)(dst_ref_331[id_995] = id_998), ::dessser::Void()) };
                                                                            (void)id_999;
                                                                            uint8_t id_1000 { 0 };
                                                                            int32_t id_1001 { 1L };
                                                                            uint8_t id_1002 { 0 };
                                                                            int32_t id_1003 { n_ref_332[id_1002] };
                                                                            int32_t id_1004 { int32_t(id_1001 + id_1003) };
                                                                            Void id_1005 { ((void)(n_ref_332[id_1000] = id_1004), ::dessser::Void()) };
                                                                            (void)id_1005;
                                                                            (void)id_1005;
                                                                          }
                                                                          (void)::dessser::Void();
                                                                          uint8_t id_1006 { 0 };
                                                                          Pointer id_1007 { dst_ref_331[id_1006] };
                                                                          let_res_993 = id_1007;
                                                                        }
                                                                        let_res_990 = let_res_993;
                                                                      }
                                                                      choose_res_951 = let_res_990;
                                                                    } else {
                                                                      uint16_t id_1008 { 31 };
                                                                      bool id_1009 { bool(id_1008 == label1_315) };
                                                                      Pointer choose_res_1010;
                                                                      if (id_1009) {
                                                                        ::dessser::gen::raql_type::t9acdca30308e28313c3977aa48ab367d id_1011 { std::get<31 /* Vec */>(p_0) };
                                                                        uint32_t id_1012 { std::get<0>(id_1011) };
                                                                        Pointer id_1013 { ssum_dst_316.writeU32Le(id_1012) };
                                                                        Pointer let_res_1014;
                                                                        {
                                                                          Pointer stup_dst_328 { id_1013 };
                                                                          ::dessser::gen::raql_type::t9acdca30308e28313c3977aa48ab367d id_1015 { std::get<31 /* Vec */>(p_0) };
                                                                          std::shared_ptr<::dessser::gen::raql_type::t>  id_1016 { std::get<1>(id_1015) };
                                                                          Pointer id_1017 { to_row_binary(id_1016, stup_dst_328) };
                                                                          let_res_1014 = id_1017;
                                                                        }
                                                                        choose_res_1010 = let_res_1014;
                                                                      } else {
                                                                        uint16_t id_1018 { 32 };
                                                                        bool id_1019 { bool(id_1018 == label1_315) };
                                                                        Pointer choose_res_1020;
                                                                        if (id_1019) {
                                                                          std::shared_ptr<::dessser::gen::raql_type::t>  id_1021 { std::get<32 /* Arr */>(p_0) };
                                                                          Pointer id_1022 { to_row_binary(id_1021, ssum_dst_316) };
                                                                          choose_res_1020 = id_1022;
                                                                        } else {
                                                                          uint16_t id_1023 { 33 };
                                                                          bool id_1024 { bool(id_1023 == label1_315) };
                                                                          Pointer choose_res_1025;
                                                                          if (id_1024) {
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1026 { std::get<33 /* Rec */>(p_0) };
                                                                            uint32_t id_1027 { id_1026.size() };
                                                                            Vec<1, uint32_t> id_1028 {  id_1027  };
                                                                            Pointer let_res_1029;
                                                                            {
                                                                              Vec<1, uint32_t> leb128_sz_323 { id_1028 };
                                                                              Vec<1, Pointer> id_1030 {  ssum_dst_316  };
                                                                              Pointer let_res_1031;
                                                                              {
                                                                                Vec<1, Pointer> leb128_ptr_324 { id_1030 };
                                                                                bool while_flag_1032 { true };
                                                                                do {
                                                                                  uint8_t id_1033 { 0 };
                                                                                  uint8_t id_1034 { 0 };
                                                                                  Pointer id_1035 { leb128_ptr_324[id_1034] };
                                                                                  uint32_t id_1036 { 128U };
                                                                                  uint8_t id_1037 { 0 };
                                                                                  uint32_t id_1038 { leb128_sz_323[id_1037] };
                                                                                  bool id_1039 { bool(id_1036 > id_1038) };
                                                                                  uint8_t choose_res_1040;
                                                                                  if (id_1039) {
                                                                                    uint8_t id_1041 { 0 };
                                                                                    uint32_t id_1042 { leb128_sz_323[id_1041] };
                                                                                    uint8_t id_1043 { uint8_t(id_1042) };
                                                                                    choose_res_1040 = id_1043;
                                                                                  } else {
                                                                                    uint8_t id_1044 { 0 };
                                                                                    uint32_t id_1045 { leb128_sz_323[id_1044] };
                                                                                    uint8_t id_1046 { uint8_t(id_1045) };
                                                                                    uint8_t id_1047 { 128 };
                                                                                    uint8_t id_1048 { uint8_t(id_1046 | id_1047) };
                                                                                    choose_res_1040 = id_1048;
                                                                                  }
                                                                                  Pointer id_1049 { id_1035.writeU8(choose_res_1040) };
                                                                                  Void id_1050 { ((void)(leb128_ptr_324[id_1033] = id_1049), ::dessser::Void()) };
                                                                                  (void)id_1050;
                                                                                  uint8_t id_1051 { 0 };
                                                                                  uint8_t id_1052 { 0 };
                                                                                  uint32_t id_1053 { leb128_sz_323[id_1052] };
                                                                                  uint8_t id_1054 { 7 };
                                                                                  uint32_t id_1055 { uint32_t(id_1053 >> id_1054) };
                                                                                  Void id_1056 { ((void)(leb128_sz_323[id_1051] = id_1055), ::dessser::Void()) };
                                                                                  (void)id_1056;
                                                                                  uint8_t id_1057 { 0 };
                                                                                  uint32_t id_1058 { leb128_sz_323[id_1057] };
                                                                                  uint32_t id_1059 { 0U };
                                                                                  bool id_1060 { bool(id_1058 > id_1059) };
                                                                                  while_flag_1032 = id_1060;
                                                                                  if (while_flag_1032) {
                                                                                    (void)::dessser::Void();
                                                                                  }
                                                                                } while (while_flag_1032);
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_1061 { 0 };
                                                                                Pointer id_1062 { leb128_ptr_324[id_1061] };
                                                                                let_res_1031 = id_1062;
                                                                              }
                                                                              let_res_1029 = let_res_1031;
                                                                            }
                                                                            Vec<1, Pointer> id_1063 {  let_res_1029  };
                                                                            Pointer let_res_1064;
                                                                            {
                                                                              Vec<1, Pointer> dst_ref_325 { id_1063 };
                                                                              int32_t id_1065 { 0L };
                                                                              Vec<1, int32_t> id_1066 {  id_1065  };
                                                                              Pointer let_res_1067;
                                                                              {
                                                                                Vec<1, int32_t> n_ref_326 { id_1066 };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1068 { std::get<33 /* Rec */>(p_0) };
                                                                                for (std::shared_ptr<::dessser::gen::raql_type::named_type>  &x_327 : id_1068) {
                                                                                  uint8_t id_1069 { 0 };
                                                                                  uint8_t id_1070 { 0 };
                                                                                  Pointer id_1071 { dst_ref_325[id_1070] };
                                                                                  Pointer id_1072 { named_type_to_row_binary(x_327, id_1071) };
                                                                                  Void id_1073 { ((void)(dst_ref_325[id_1069] = id_1072), ::dessser::Void()) };
                                                                                  (void)id_1073;
                                                                                  uint8_t id_1074 { 0 };
                                                                                  int32_t id_1075 { 1L };
                                                                                  uint8_t id_1076 { 0 };
                                                                                  int32_t id_1077 { n_ref_326[id_1076] };
                                                                                  int32_t id_1078 { int32_t(id_1075 + id_1077) };
                                                                                  Void id_1079 { ((void)(n_ref_326[id_1074] = id_1078), ::dessser::Void()) };
                                                                                  (void)id_1079;
                                                                                  (void)id_1079;
                                                                                }
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_1080 { 0 };
                                                                                Pointer id_1081 { dst_ref_325[id_1080] };
                                                                                let_res_1067 = id_1081;
                                                                              }
                                                                              let_res_1064 = let_res_1067;
                                                                            }
                                                                            choose_res_1025 = let_res_1064;
                                                                          } else {
                                                                            uint16_t id_1082 { 34 };
                                                                            bool id_1083 { bool(id_1082 == label1_315) };
                                                                            Pointer choose_res_1084;
                                                                            if (id_1083) {
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1085 { std::get<34 /* Sum */>(p_0) };
                                                                              uint32_t id_1086 { id_1085.size() };
                                                                              Vec<1, uint32_t> id_1087 {  id_1086  };
                                                                              Pointer let_res_1088;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_318 { id_1087 };
                                                                                Vec<1, Pointer> id_1089 {  ssum_dst_316  };
                                                                                Pointer let_res_1090;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_319 { id_1089 };
                                                                                  bool while_flag_1091 { true };
                                                                                  do {
                                                                                    uint8_t id_1092 { 0 };
                                                                                    uint8_t id_1093 { 0 };
                                                                                    Pointer id_1094 { leb128_ptr_319[id_1093] };
                                                                                    uint32_t id_1095 { 128U };
                                                                                    uint8_t id_1096 { 0 };
                                                                                    uint32_t id_1097 { leb128_sz_318[id_1096] };
                                                                                    bool id_1098 { bool(id_1095 > id_1097) };
                                                                                    uint8_t choose_res_1099;
                                                                                    if (id_1098) {
                                                                                      uint8_t id_1100 { 0 };
                                                                                      uint32_t id_1101 { leb128_sz_318[id_1100] };
                                                                                      uint8_t id_1102 { uint8_t(id_1101) };
                                                                                      choose_res_1099 = id_1102;
                                                                                    } else {
                                                                                      uint8_t id_1103 { 0 };
                                                                                      uint32_t id_1104 { leb128_sz_318[id_1103] };
                                                                                      uint8_t id_1105 { uint8_t(id_1104) };
                                                                                      uint8_t id_1106 { 128 };
                                                                                      uint8_t id_1107 { uint8_t(id_1105 | id_1106) };
                                                                                      choose_res_1099 = id_1107;
                                                                                    }
                                                                                    Pointer id_1108 { id_1094.writeU8(choose_res_1099) };
                                                                                    Void id_1109 { ((void)(leb128_ptr_319[id_1092] = id_1108), ::dessser::Void()) };
                                                                                    (void)id_1109;
                                                                                    uint8_t id_1110 { 0 };
                                                                                    uint8_t id_1111 { 0 };
                                                                                    uint32_t id_1112 { leb128_sz_318[id_1111] };
                                                                                    uint8_t id_1113 { 7 };
                                                                                    uint32_t id_1114 { uint32_t(id_1112 >> id_1113) };
                                                                                    Void id_1115 { ((void)(leb128_sz_318[id_1110] = id_1114), ::dessser::Void()) };
                                                                                    (void)id_1115;
                                                                                    uint8_t id_1116 { 0 };
                                                                                    uint32_t id_1117 { leb128_sz_318[id_1116] };
                                                                                    uint32_t id_1118 { 0U };
                                                                                    bool id_1119 { bool(id_1117 > id_1118) };
                                                                                    while_flag_1091 = id_1119;
                                                                                    if (while_flag_1091) {
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                  } while (while_flag_1091);
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1120 { 0 };
                                                                                  Pointer id_1121 { leb128_ptr_319[id_1120] };
                                                                                  let_res_1090 = id_1121;
                                                                                }
                                                                                let_res_1088 = let_res_1090;
                                                                              }
                                                                              Vec<1, Pointer> id_1122 {  let_res_1088  };
                                                                              Pointer let_res_1123;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_320 { id_1122 };
                                                                                int32_t id_1124 { 0L };
                                                                                Vec<1, int32_t> id_1125 {  id_1124  };
                                                                                Pointer let_res_1126;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_321 { id_1125 };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1127 { std::get<34 /* Sum */>(p_0) };
                                                                                  for (std::shared_ptr<::dessser::gen::raql_type::named_type>  &x_322 : id_1127) {
                                                                                    uint8_t id_1128 { 0 };
                                                                                    uint8_t id_1129 { 0 };
                                                                                    Pointer id_1130 { dst_ref_320[id_1129] };
                                                                                    Pointer id_1131 { named_type_to_row_binary(x_322, id_1130) };
                                                                                    Void id_1132 { ((void)(dst_ref_320[id_1128] = id_1131), ::dessser::Void()) };
                                                                                    (void)id_1132;
                                                                                    uint8_t id_1133 { 0 };
                                                                                    int32_t id_1134 { 1L };
                                                                                    uint8_t id_1135 { 0 };
                                                                                    int32_t id_1136 { n_ref_321[id_1135] };
                                                                                    int32_t id_1137 { int32_t(id_1134 + id_1136) };
                                                                                    Void id_1138 { ((void)(n_ref_321[id_1133] = id_1137), ::dessser::Void()) };
                                                                                    (void)id_1138;
                                                                                    (void)id_1138;
                                                                                  }
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1139 { 0 };
                                                                                  Pointer id_1140 { dst_ref_320[id_1139] };
                                                                                  let_res_1126 = id_1140;
                                                                                }
                                                                                let_res_1123 = let_res_1126;
                                                                              }
                                                                              choose_res_1084 = let_res_1123;
                                                                            } else {
                                                                              uint16_t id_1141 { 35 };
                                                                              bool id_1142 { bool(label1_315 == id_1141) };
                                                                              Void id_1143 { ((void)(assert(id_1142)), ::dessser::Void()) };
                                                                              (void)id_1143;
                                                                              ::dessser::gen::raql_type::t550173c9cc042d56a37c01d7d8bbfa95 id_1144 { std::get<35 /* Map */>(p_0) };
                                                                              std::shared_ptr<::dessser::gen::raql_type::t>  id_1145 { std::get<0>(id_1144) };
                                                                              Pointer id_1146 { to_row_binary(id_1145, ssum_dst_316) };
                                                                              Pointer let_res_1147;
                                                                              {
                                                                                Pointer stup_dst_317 { id_1146 };
                                                                                ::dessser::gen::raql_type::t550173c9cc042d56a37c01d7d8bbfa95 id_1148 { std::get<35 /* Map */>(p_0) };
                                                                                std::shared_ptr<::dessser::gen::raql_type::t>  id_1149 { std::get<1>(id_1148) };
                                                                                Pointer id_1150 { to_row_binary(id_1149, stup_dst_317) };
                                                                                let_res_1147 = id_1150;
                                                                              }
                                                                              choose_res_1084 = let_res_1147;
                                                                            }
                                                                            choose_res_1025 = choose_res_1084;
                                                                          }
                                                                          choose_res_1020 = choose_res_1025;
                                                                        }
                                                                        choose_res_1010 = choose_res_1020;
                                                                      }
                                                                      choose_res_951 = choose_res_1010;
                                                                    }
                                                                    choose_res_948 = choose_res_951;
                                                                  }
                                                                  choose_res_945 = choose_res_948;
                                                                }
                                                                choose_res_942 = choose_res_945;
                                                              }
                                                              choose_res_939 = choose_res_942;
                                                            }
                                                            choose_res_936 = choose_res_939;
                                                          }
                                                          choose_res_933 = choose_res_936;
                                                        }
                                                        choose_res_930 = choose_res_933;
                                                      }
                                                      choose_res_927 = choose_res_930;
                                                    }
                                                    choose_res_924 = choose_res_927;
                                                  }
                                                  choose_res_921 = choose_res_924;
                                                }
                                                choose_res_918 = choose_res_921;
                                              }
                                              choose_res_915 = choose_res_918;
                                            }
                                            choose_res_912 = choose_res_915;
                                          }
                                          choose_res_909 = choose_res_912;
                                        }
                                        choose_res_906 = choose_res_909;
                                      }
                                      choose_res_903 = choose_res_906;
                                    }
                                    choose_res_900 = choose_res_903;
                                  }
                                  choose_res_897 = choose_res_900;
                                }
                                choose_res_894 = choose_res_897;
                              }
                              choose_res_891 = choose_res_894;
                            }
                            choose_res_888 = choose_res_891;
                          }
                          choose_res_885 = choose_res_888;
                        }
                        choose_res_882 = choose_res_885;
                      }
                      choose_res_879 = choose_res_882;
                    }
                    choose_res_876 = choose_res_879;
                  }
                  choose_res_873 = choose_res_876;
                }
                choose_res_870 = choose_res_873;
              }
              choose_res_867 = choose_res_870;
            }
            choose_res_864 = choose_res_867;
          }
          choose_res_861 = choose_res_864;
        }
        let_res_858 = choose_res_861;
      }
      let_res_856 = let_res_858;
    }
    return let_res_856;
  }
   };
  return fun854;
}
std::function<Pointer(::dessser::gen::raql_type::base &,Pointer &)> base_to_row_binary(base_to_row_binary_init());

/* 
    (fun ("(STRING; THIS)" "Ptr")
      (let "stup_dst_314"
        (write-bytes
          (let "leb128_sz_312" (make-vec (string-length (get-item 0 (param 0))))
            (let "leb128_ptr_313" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_313")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_313"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_312"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_312"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_312"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_312") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_312")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_312")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_313"))))) 
          (bytes-of-string (get-item 0 (param 0)))) (apply (identifier "to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_314"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type>  &,Pointer &)> named_type_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type>  &,Pointer &)> fun1151 { [&](std::shared_ptr<::dessser::gen::raql_type::named_type>  p_0, Pointer p_1) {
    std::string id_1152 { std::get<0>((*p_0)) };
    uint32_t id_1153 { (uint32_t)id_1152.size() };
    Vec<1, uint32_t> id_1154 {  id_1153  };
    Pointer let_res_1155;
    {
      Vec<1, uint32_t> leb128_sz_312 { id_1154 };
      Vec<1, Pointer> id_1156 {  p_1  };
      Pointer let_res_1157;
      {
        Vec<1, Pointer> leb128_ptr_313 { id_1156 };
        bool while_flag_1158 { true };
        do {
          uint8_t id_1159 { 0 };
          uint8_t id_1160 { 0 };
          Pointer id_1161 { leb128_ptr_313[id_1160] };
          uint32_t id_1162 { 128U };
          uint8_t id_1163 { 0 };
          uint32_t id_1164 { leb128_sz_312[id_1163] };
          bool id_1165 { bool(id_1162 > id_1164) };
          uint8_t choose_res_1166;
          if (id_1165) {
            uint8_t id_1167 { 0 };
            uint32_t id_1168 { leb128_sz_312[id_1167] };
            uint8_t id_1169 { uint8_t(id_1168) };
            choose_res_1166 = id_1169;
          } else {
            uint8_t id_1170 { 0 };
            uint32_t id_1171 { leb128_sz_312[id_1170] };
            uint8_t id_1172 { uint8_t(id_1171) };
            uint8_t id_1173 { 128 };
            uint8_t id_1174 { uint8_t(id_1172 | id_1173) };
            choose_res_1166 = id_1174;
          }
          Pointer id_1175 { id_1161.writeU8(choose_res_1166) };
          Void id_1176 { ((void)(leb128_ptr_313[id_1159] = id_1175), ::dessser::Void()) };
          (void)id_1176;
          uint8_t id_1177 { 0 };
          uint8_t id_1178 { 0 };
          uint32_t id_1179 { leb128_sz_312[id_1178] };
          uint8_t id_1180 { 7 };
          uint32_t id_1181 { uint32_t(id_1179 >> id_1180) };
          Void id_1182 { ((void)(leb128_sz_312[id_1177] = id_1181), ::dessser::Void()) };
          (void)id_1182;
          uint8_t id_1183 { 0 };
          uint32_t id_1184 { leb128_sz_312[id_1183] };
          uint32_t id_1185 { 0U };
          bool id_1186 { bool(id_1184 > id_1185) };
          while_flag_1158 = id_1186;
          if (while_flag_1158) {
            (void)::dessser::Void();
          }
        } while (while_flag_1158);
        (void)::dessser::Void();
        uint8_t id_1187 { 0 };
        Pointer id_1188 { leb128_ptr_313[id_1187] };
        let_res_1157 = id_1188;
      }
      let_res_1155 = let_res_1157;
    }
    std::string id_1189 { std::get<0>((*p_0)) };
    Bytes id_1190 { id_1189 };
    Pointer id_1191 { let_res_1155.writeBytes(id_1190) };
    Pointer let_res_1192;
    {
      Pointer stup_dst_314 { id_1191 };
      std::shared_ptr<::dessser::gen::raql_type::t>  id_1193 { std::get<1>((*p_0)) };
      Pointer id_1194 { to_row_binary(id_1193, stup_dst_314) };
      let_res_1192 = id_1194;
    }
    return let_res_1192;
  }
   };
  return fun1151;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type>  &,Pointer &)> named_type_to_row_binary(named_type_to_row_binary_init());

/* 
    (fun ("{type: (base AS [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]); nullable: BOOL}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> fun1195 { [&](std::shared_ptr<::dessser::gen::raql_type::t>  p_0, Pointer p_1) {
    Pointer id_1196 { to_row_binary(p_0, p_1) };
    return id_1196;
  }
   };
  return fun1195;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t>  &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
