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

namespace dessser::gen::raql_value {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t690438e8d106ddec68c668ab00e5188a : public std::variant<
  uint32_t, // v4
  uint128_t // v6
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t690438e8d106ddec68c668ab00e5188a const &a, t690438e8d106ddec68c668ab00e5188a const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // v4
    case 1: return std::get<1>(a) == std::get<1>(b); // v6
  };
  return false;
}
inline bool operator!=(t690438e8d106ddec68c668ab00e5188a const &a, t690438e8d106ddec68c668ab00e5188a const &b) {
  return !operator==(a, b);
}
struct t5d7b802285da2586acaa54f62df2bed3 {
  uint32_t Cidr4_ip;
  uint8_t Cidr4_mask;
  t5d7b802285da2586acaa54f62df2bed3(uint32_t Cidr4_ip_, uint8_t Cidr4_mask_) : Cidr4_ip(Cidr4_ip_), Cidr4_mask(Cidr4_mask_) {}
  t5d7b802285da2586acaa54f62df2bed3() = default;
};
inline bool operator==(t5d7b802285da2586acaa54f62df2bed3 const &a, t5d7b802285da2586acaa54f62df2bed3 const &b) {
  return a.Cidr4_ip == b.Cidr4_ip && a.Cidr4_mask == b.Cidr4_mask;
}

inline bool operator!=(t5d7b802285da2586acaa54f62df2bed3 const &a, t5d7b802285da2586acaa54f62df2bed3 const &b) {
  return !operator==(a, b);
}
struct t44c6447d638b93b2e8d0887b360afa41 {
  uint128_t ip;
  uint8_t mask;
  t44c6447d638b93b2e8d0887b360afa41(uint128_t ip_, uint8_t mask_) : ip(ip_), mask(mask_) {}
  t44c6447d638b93b2e8d0887b360afa41() = default;
};
inline bool operator==(t44c6447d638b93b2e8d0887b360afa41 const &a, t44c6447d638b93b2e8d0887b360afa41 const &b) {
  return a.ip == b.ip && a.mask == b.mask;
}

inline bool operator!=(t44c6447d638b93b2e8d0887b360afa41 const &a, t44c6447d638b93b2e8d0887b360afa41 const &b) {
  return !operator==(a, b);
}
struct teb043643295bb7cc6656bec6dd6fd6e1 : public std::variant<
  ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3, // v4
  ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 // v6
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(teb043643295bb7cc6656bec6dd6fd6e1 const &a, teb043643295bb7cc6656bec6dd6fd6e1 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // v4
    case 1: return std::get<1>(a) == std::get<1>(b); // v6
  };
  return false;
}
inline bool operator!=(teb043643295bb7cc6656bec6dd6fd6e1 const &a, teb043643295bb7cc6656bec6dd6fd6e1 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_value : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::raql_value::t> 
> {
  using tuple::tuple;
};
inline bool operator==(named_value const &a, named_value const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(named_value const &a, named_value const &b) {
  return !operator==(a, b);
}
struct ta4246d307efc26a581b0c83fdec1c21f : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_value::t> ,
  std::shared_ptr<::dessser::gen::raql_value::t> 
> {
  using tuple::tuple;
};
inline bool operator==(ta4246d307efc26a581b0c83fdec1c21f const &a, ta4246d307efc26a581b0c83fdec1c21f const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(ta4246d307efc26a581b0c83fdec1c21f const &a, ta4246d307efc26a581b0c83fdec1c21f const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  Void, // VNull
  Void, // VUnit
  double, // VFloat
  std::string, // VString
  bool, // VBool
  char, // VChar
  uint8_t, // VU8
  uint16_t, // VU16
  uint32_t, // VU24
  uint32_t, // VU32
  uint64_t, // VU40
  uint64_t, // VU48
  uint64_t, // VU56
  uint64_t, // VU64
  uint128_t, // VU128
  int8_t, // VI8
  int16_t, // VI16
  int32_t, // VI24
  int32_t, // VI32
  int64_t, // VI40
  int64_t, // VI48
  int64_t, // VI56
  int64_t, // VI64
  int128_t, // VI128
  uint64_t, // VEth
  uint32_t, // VIpv4
  uint128_t, // VIpv6
  ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a, // VIp
  ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3, // VCidrv4
  ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41, // VCidrv6
  ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1, // VCidr
  Arr<std::shared_ptr<::dessser::gen::raql_value::t> >, // VTup
  Arr<std::shared_ptr<::dessser::gen::raql_value::t> >, // VVec
  Arr<std::shared_ptr<::dessser::gen::raql_value::t> >, // VArr
  Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> >, // VRec
  Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> // VMap
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 36 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // VNull
    case 1: return std::get<1>(a) == std::get<1>(b); // VUnit
    case 2: return std::get<2>(a) == std::get<2>(b); // VFloat
    case 3: return std::get<3>(a) == std::get<3>(b); // VString
    case 4: return std::get<4>(a) == std::get<4>(b); // VBool
    case 5: return std::get<5>(a) == std::get<5>(b); // VChar
    case 6: return std::get<6>(a) == std::get<6>(b); // VU8
    case 7: return std::get<7>(a) == std::get<7>(b); // VU16
    case 8: return std::get<8>(a) == std::get<8>(b); // VU24
    case 9: return std::get<9>(a) == std::get<9>(b); // VU32
    case 10: return std::get<10>(a) == std::get<10>(b); // VU40
    case 11: return std::get<11>(a) == std::get<11>(b); // VU48
    case 12: return std::get<12>(a) == std::get<12>(b); // VU56
    case 13: return std::get<13>(a) == std::get<13>(b); // VU64
    case 14: return std::get<14>(a) == std::get<14>(b); // VU128
    case 15: return std::get<15>(a) == std::get<15>(b); // VI8
    case 16: return std::get<16>(a) == std::get<16>(b); // VI16
    case 17: return std::get<17>(a) == std::get<17>(b); // VI24
    case 18: return std::get<18>(a) == std::get<18>(b); // VI32
    case 19: return std::get<19>(a) == std::get<19>(b); // VI40
    case 20: return std::get<20>(a) == std::get<20>(b); // VI48
    case 21: return std::get<21>(a) == std::get<21>(b); // VI56
    case 22: return std::get<22>(a) == std::get<22>(b); // VI64
    case 23: return std::get<23>(a) == std::get<23>(b); // VI128
    case 24: return std::get<24>(a) == std::get<24>(b); // VEth
    case 25: return std::get<25>(a) == std::get<25>(b); // VIpv4
    case 26: return std::get<26>(a) == std::get<26>(b); // VIpv6
    case 27: return std::get<27>(a) == std::get<27>(b); // VIp
    case 28: return std::get<28>(a) == std::get<28>(b); // VCidrv4
    case 29: return std::get<29>(a) == std::get<29>(b); // VCidrv6
    case 30: return std::get<30>(a) == std::get<30>(b); // VCidr
    case 31: return std::get<31>(a) == std::get<31>(b); // VTup
    case 32: return std::get<32>(a) == std::get<32>(b); // VVec
    case 33: return std::get<33>(a) == std::get<33>(b); // VArr
    case 34: return std::get<34>(a) == std::get<34>(b); // VRec
    case 35: return std::get<35>(a) == std::get<35>(b); // VMap
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t154914fa186327343906567bc094f08e : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_value::t> ,
  Pointer
> {
  using tuple::tuple;
  t154914fa186327343906567bc094f08e(std::tuple<std::shared_ptr<::dessser::gen::raql_value::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_value::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t154914fa186327343906567bc094f08e const &a, t154914fa186327343906567bc094f08e const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t154914fa186327343906567bc094f08e const &a, t154914fa186327343906567bc094f08e const &b) {
  return !operator==(a, b);
}
extern std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> of_row_binary;
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
struct td2cd337bb3c8bc04d5603393d084985b : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  td2cd337bb3c8bc04d5603393d084985b(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return !operator==(a, b);
}
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
struct t859e6a4cc938643a1d59426a3bf7b15a : public std::tuple<
  uint128_t,
  Pointer
> {
  using tuple::tuple;
  t859e6a4cc938643a1d59426a3bf7b15a(std::tuple<uint128_t, Pointer> p)
    : std::tuple<uint128_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t859e6a4cc938643a1d59426a3bf7b15a const &a, t859e6a4cc938643a1d59426a3bf7b15a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t859e6a4cc938643a1d59426a3bf7b15a const &a, t859e6a4cc938643a1d59426a3bf7b15a const &b) {
  return !operator==(a, b);
}
struct td5b91cc4eacb7073aad7ac65784b815a : public std::tuple<
  ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a,
  Pointer
> {
  using tuple::tuple;
  td5b91cc4eacb7073aad7ac65784b815a(std::tuple<::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a, Pointer> p)
    : std::tuple<::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td5b91cc4eacb7073aad7ac65784b815a const &a, td5b91cc4eacb7073aad7ac65784b815a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td5b91cc4eacb7073aad7ac65784b815a const &a, td5b91cc4eacb7073aad7ac65784b815a const &b) {
  return !operator==(a, b);
}
struct t9843563dda20212bcf7939af05663f34 : public std::tuple<
  ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1,
  Pointer
> {
  using tuple::tuple;
  t9843563dda20212bcf7939af05663f34(std::tuple<::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1, Pointer> p)
    : std::tuple<::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9843563dda20212bcf7939af05663f34 const &a, t9843563dda20212bcf7939af05663f34 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9843563dda20212bcf7939af05663f34 const &a, t9843563dda20212bcf7939af05663f34 const &b) {
  return !operator==(a, b);
}
struct td7923d3f6d8f6add6849bd1b0a41351f : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_value::t> >,
  Pointer
> {
  using tuple::tuple;
  td7923d3f6d8f6add6849bd1b0a41351f(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::t> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::t> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td7923d3f6d8f6add6849bd1b0a41351f const &a, td7923d3f6d8f6add6849bd1b0a41351f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td7923d3f6d8f6add6849bd1b0a41351f const &a, td7923d3f6d8f6add6849bd1b0a41351f const &b) {
  return !operator==(a, b);
}
struct t7edef2aa82c167066e365042d8a9a97e : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> >,
  Pointer
> {
  using tuple::tuple;
  t7edef2aa82c167066e365042d8a9a97e(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7edef2aa82c167066e365042d8a9a97e const &a, t7edef2aa82c167066e365042d8a9a97e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7edef2aa82c167066e365042d8a9a97e const &a, t7edef2aa82c167066e365042d8a9a97e const &b) {
  return !operator==(a, b);
}
struct t9f25ed50c831f0d73db2f922456ab51a : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_value::named_value> ,
  Pointer
> {
  using tuple::tuple;
  t9f25ed50c831f0d73db2f922456ab51a(std::tuple<std::shared_ptr<::dessser::gen::raql_value::named_value> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_value::named_value> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9f25ed50c831f0d73db2f922456ab51a const &a, t9f25ed50c831f0d73db2f922456ab51a const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9f25ed50c831f0d73db2f922456ab51a const &a, t9f25ed50c831f0d73db2f922456ab51a const &b) {
  return !operator==(a, b);
}
struct t217cee98ec313f21a12369fd1762c5c4 : public std::tuple<
  Lst<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f>,
  Pointer
> {
  using tuple::tuple;
  t217cee98ec313f21a12369fd1762c5c4(std::tuple<Lst<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t217cee98ec313f21a12369fd1762c5c4 const &a, t217cee98ec313f21a12369fd1762c5c4 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t217cee98ec313f21a12369fd1762c5c4 const &a, t217cee98ec313f21a12369fd1762c5c4 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a(Pointer)> named_value_of_row_binary;
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
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> wrap_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> named_value_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> named_value_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> wrap_to_row_binary;
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("Ptr")
      (let "dsum1_81" (let-pair "du16_fst_76" "du16_snd_77" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_76") (identifier "du16_snd_77")))
        (let-pair "dsum1_fst_82" "dsum1_snd_83" (identifier "dsum1_81")
          (if (eq (u16 0) (identifier "dsum1_fst_82"))
            (make-tup
              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 0
                (nop)) (identifier "dsum1_snd_83"))
            (if (eq (u16 1) (identifier "dsum1_fst_82"))
              (make-tup
                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 1
                  (nop)) (identifier "dsum1_snd_83"))
              (if (eq (u16 2) (identifier "dsum1_fst_82"))
                (let-pair "dfloat_fst_515" "dfloat_snd_516" (read-u64 little-endian (identifier "dsum1_snd_83"))
                  (make-tup
                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 2
                      (float-of-u64 (identifier "dfloat_fst_515"))) (identifier "dfloat_snd_516")))
                (if (eq (u16 3) (identifier "dsum1_fst_82"))
                  (let "dstring1_505"
                    (let "leb_ref_499" (make-vec (u32 0))
                      (let "shft_ref_500" (make-vec (u8 0))
                        (let "p_ref_501" (make-vec (identifier "dsum1_snd_83"))
                          (seq
                            (while
                              (let "leb128_502" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_501")))
                                (let-pair "leb128_fst_503" "leb128_snd_504" 
                                  (identifier "leb128_502")
                                  (seq (set-vec (u8 0) (identifier "p_ref_501") (identifier "leb128_snd_504"))
                                    (set-vec (u8 0) (identifier "leb_ref_499")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_503") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_500"))) (unsafe-nth (u8 0) (identifier "leb_ref_499"))))
                                    (set-vec (u8 0) (identifier "shft_ref_500") (add (unsafe-nth (u8 0) (identifier "shft_ref_500")) (u8 7))) 
                                    (ge (identifier "leb128_fst_503") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_499"))) (unsafe-nth (u8 0) (identifier "p_ref_501")))))))
                    (let-pair "dstring1_fst_506" "dstring1_snd_507" (identifier "dstring1_505")
                      (let-pair "dstring2_fst_509" "dstring2_snd_510" 
                        (read-bytes (identifier "dstring1_snd_507") (identifier "dstring1_fst_506"))
                        (make-tup
                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 3
                            (string-of-bytes (identifier "dstring2_fst_509"))) 
                          (identifier "dstring2_snd_510")))))
                  (if (eq (u16 4) (identifier "dsum1_fst_82"))
                    (let-pair "dbool_fst_494" "dbool_snd_495" (read-u8 (identifier "dsum1_snd_83"))
                      (make-tup
                        (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 4
                          (not (eq (identifier "dbool_fst_494") (u8 0)))) 
                        (identifier "dbool_snd_495")))
                    (if (eq (u16 5) (identifier "dsum1_fst_82"))
                      (let-pair "dchar_fst_488" "dchar_snd_489" (read-u8 (identifier "dsum1_snd_83"))
                        (make-tup
                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 5
                            (char-of-u8 (identifier "dchar_fst_488"))) 
                          (identifier "dchar_snd_489")))
                      (if (eq (u16 6) (identifier "dsum1_fst_82"))
                        (let-pair "du8_fst_482" "du8_snd_483" (read-u8 (identifier "dsum1_snd_83"))
                          (make-tup
                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 6
                              (identifier "du8_fst_482")) (identifier "du8_snd_483")))
                        (if (eq (u16 7) (identifier "dsum1_fst_82"))
                          (let-pair "du16_fst_476" "du16_snd_477" (read-u16 little-endian (identifier "dsum1_snd_83"))
                            (make-tup
                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 7
                                (identifier "du16_fst_476")) (identifier "du16_snd_477")))
                          (if (eq (u16 8) (identifier "dsum1_fst_82"))
                            (let-pair "du24_fst_470" "du24_snd_471" (read-u32 little-endian (identifier "dsum1_snd_83"))
                              (make-tup
                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 8
                                  (to-u24 (identifier "du24_fst_470"))) 
                                (identifier "du24_snd_471")))
                            (if (eq (u16 9) (identifier "dsum1_fst_82"))
                              (let-pair "du32_fst_464" "du32_snd_465" 
                                (read-u32 little-endian (identifier "dsum1_snd_83"))
                                (make-tup
                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 9
                                    (identifier "du32_fst_464")) (identifier "du32_snd_465")))
                              (if (eq (u16 10) (identifier "dsum1_fst_82"))
                                (let-pair "du40_fst_458" "du40_snd_459" 
                                  (read-u64 little-endian (identifier "dsum1_snd_83"))
                                  (make-tup
                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 10
                                      (to-u40 (identifier "du40_fst_458"))) 
                                    (identifier "du40_snd_459")))
                                (if (eq (u16 11) (identifier "dsum1_fst_82"))
                                  (let-pair "du48_fst_452" "du48_snd_453" 
                                    (read-u64 little-endian (identifier "dsum1_snd_83"))
                                    (make-tup
                                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 11
                                        (to-u48 (identifier "du48_fst_452"))) 
                                      (identifier "du48_snd_453")))
                                  (if (eq (u16 12) (identifier "dsum1_fst_82"))
                                    (let-pair "du56_fst_446" "du56_snd_447" 
                                      (read-u64 little-endian (identifier "dsum1_snd_83"))
                                      (make-tup
                                        (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 12
                                          (to-u56 (identifier "du56_fst_446"))) 
                                        (identifier "du56_snd_447")))
                                    (if (eq (u16 13) (identifier "dsum1_fst_82"))
                                      (let-pair "du64_fst_440" "du64_snd_441" 
                                        (read-u64 little-endian (identifier "dsum1_snd_83"))
                                        (make-tup
                                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 13
                                            (identifier "du64_fst_440")) 
                                          (identifier "du64_snd_441")))
                                      (if (eq (u16 14) (identifier "dsum1_fst_82"))
                                        (let-pair "di128_fst_434" "di128_snd_435" 
                                          (read-u128 little-endian (identifier "dsum1_snd_83"))
                                          (make-tup
                                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 14
                                              (identifier "di128_fst_434")) 
                                            (identifier "di128_snd_435")))
                                        (if (eq (u16 15) (identifier "dsum1_fst_82"))
                                          (let-pair "di8_fst_428" "di8_snd_429" 
                                            (read-u8 (identifier "dsum1_snd_83"))
                                            (make-tup
                                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 15
                                                (to-i8 (identifier "di8_fst_428"))) 
                                              (identifier "di8_snd_429")))
                                          (if (eq (u16 16) (identifier "dsum1_fst_82"))
                                            (let-pair "di16_fst_422" "di16_snd_423" 
                                              (read-u16 little-endian (identifier "dsum1_snd_83"))
                                              (make-tup
                                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 16
                                                  (to-i16 (identifier "di16_fst_422"))) 
                                                (identifier "di16_snd_423")))
                                            (if (eq (u16 17) (identifier "dsum1_fst_82"))
                                              (let-pair "di24_fst_416" "di24_snd_417" 
                                                (read-u32 little-endian (identifier "dsum1_snd_83"))
                                                (make-tup
                                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 17
                                                    (to-i24 (identifier "di24_fst_416"))) 
                                                  (identifier "di24_snd_417")))
                                              (if (eq (u16 18) (identifier "dsum1_fst_82"))
                                                (let-pair "di32_fst_410" "di32_snd_411" 
                                                  (read-u32 little-endian (identifier "dsum1_snd_83"))
                                                  (make-tup
                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 18
                                                      (to-i32 (identifier "di32_fst_410"))) 
                                                    (identifier "di32_snd_411")))
                                                (if (eq (u16 19) (identifier "dsum1_fst_82"))
                                                  (let-pair "di40_fst_404" "di40_snd_405" 
                                                    (read-u64 little-endian (identifier "dsum1_snd_83"))
                                                    (make-tup
                                                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 19
                                                        (to-i40 (identifier "di40_fst_404"))) 
                                                      (identifier "di40_snd_405")))
                                                  (if (eq (u16 20) (identifier "dsum1_fst_82"))
                                                    (let-pair "di48_fst_398" "di48_snd_399" 
                                                      (read-u64 little-endian (identifier "dsum1_snd_83"))
                                                      (make-tup
                                                        (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 20
                                                          (to-i48 (identifier "di48_fst_398"))) 
                                                        (identifier "di48_snd_399")))
                                                    (if (eq (u16 21) (identifier "dsum1_fst_82"))
                                                      (let-pair "di56_fst_392" "di56_snd_393" 
                                                        (read-u64 little-endian (identifier "dsum1_snd_83"))
                                                        (make-tup
                                                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 21
                                                            (to-i56 (identifier "di56_fst_392"))) 
                                                          (identifier "di56_snd_393")))
                                                      (if (eq (u16 22) (identifier "dsum1_fst_82"))
                                                        (let-pair "di64_fst_386" "di64_snd_387" 
                                                          (read-u64 little-endian (identifier "dsum1_snd_83"))
                                                          (make-tup
                                                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 22
                                                              (to-i64 (identifier "di64_fst_386"))) 
                                                            (identifier "di64_snd_387")))
                                                        (if (eq (u16 23) (identifier "dsum1_fst_82"))
                                                          (let-pair "di128_fst_380" "di128_snd_381" 
                                                            (read-u128 little-endian (identifier "dsum1_snd_83"))
                                                            (make-tup
                                                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 23
                                                                (to-i128 (identifier "di128_fst_380"))) 
                                                              (identifier "di128_snd_381")))
                                                          (if (eq (u16 24) (identifier "dsum1_fst_82"))
                                                            (let-pair "du48_fst_371" "du48_snd_372" 
                                                              (read-u64 little-endian (identifier "dsum1_snd_83"))
                                                              (make-tup
                                                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 24
                                                                  (make-usr "Eth" (to-u48 (identifier "du48_fst_371")))) 
                                                                (identifier "du48_snd_372")))
                                                            (if (eq (u16 25) (identifier "dsum1_fst_82"))
                                                              (let-pair "du32_fst_362" "du32_snd_363" 
                                                                (read-u32 little-endian (identifier "dsum1_snd_83"))
                                                                (make-tup
                                                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 25
                                                                    (make-usr "Ip4" (identifier "du32_fst_362"))) 
                                                                  (identifier "du32_snd_363")))
                                                              (if (eq (u16 26) (identifier "dsum1_fst_82"))
                                                                (let-pair "di128_fst_353" "di128_snd_354" 
                                                                  (read-u128 little-endian (identifier "dsum1_snd_83"))
                                                                  (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 26
                                                                    (make-usr "Ip6" (identifier "di128_fst_353"))) 
                                                                    (identifier "di128_snd_354")))
                                                                (if (eq (u16 27) (identifier "dsum1_fst_82"))
                                                                  (let-pair "des_usr_type_fst_347" "des_usr_type_snd_348"
                                                                    (let "dsum1_325"
                                                                    (let-pair "du16_fst_320" "du16_snd_321" (read-u16 little-endian (identifier "dsum1_snd_83")) (make-tup (identifier "du16_fst_320") (identifier "du16_snd_321")))
                                                                    (let-pair "dsum1_fst_326" "dsum1_snd_327" 
                                                                    (identifier "dsum1_325")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_326"))
                                                                    (let-pair "du32_fst_338" "du32_snd_339" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_327"))
                                                                    (make-tup (construct "[v4 Ip4 | v6 Ip6]" 0 (make-usr "Ip4" (identifier "du32_fst_338"))) (identifier "du32_snd_339")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_326") (u16 1)))
                                                                    (let-pair "di128_fst_329" "di128_snd_330" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_327"))
                                                                    (make-tup (construct "[v4 Ip4 | v6 Ip6]" 1 (make-usr "Ip6" (identifier "di128_fst_329"))) (identifier "di128_snd_330")))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 27
                                                                    (make-usr "Ip" (identifier "des_usr_type_fst_347"))) 
                                                                    (identifier "des_usr_type_snd_348")))
                                                                  (if 
                                                                    (eq (u16 28) (identifier "dsum1_fst_82"))
                                                                    (let "drec_304"
                                                                    (let-pair "du32_fst_299" "du32_snd_300" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_83")) 
                                                                    (make-tup (make-usr "Ip4" (identifier "du32_fst_299")) (identifier "du32_snd_300")))
                                                                    (let-pair "drec_fst_305" "drec_snd_306" 
                                                                    (identifier "drec_304")
                                                                    (let-pair "du8_fst_308" "du8_snd_309" 
                                                                    (read-u8 (identifier "drec_snd_306"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 28
                                                                    (make-usr "Cidr4" (make-rec (string "mask") (identifier "du8_fst_308") (string "ip") (identifier "drec_fst_305")))) 
                                                                    (identifier "du8_snd_309")))))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "dsum1_fst_82"))
                                                                    (let "drec_283"
                                                                    (let-pair "di128_fst_278" "di128_snd_279" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_83")) 
                                                                    (make-tup (make-usr "Ip6" (identifier "di128_fst_278")) (identifier "di128_snd_279")))
                                                                    (let-pair "drec_fst_284" "drec_snd_285" 
                                                                    (identifier "drec_283")
                                                                    (let-pair "du8_fst_287" "du8_snd_288" 
                                                                    (read-u8 (identifier "drec_snd_285"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 29
                                                                    (make-usr "Cidr6" (make-rec (string "mask") (identifier "du8_fst_287") (string "ip") (identifier "drec_fst_284")))) 
                                                                    (identifier "du8_snd_288")))))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "dsum1_fst_82"))
                                                                    (let-pair "des_usr_type_fst_272" "des_usr_type_snd_273"
                                                                    (let "dsum1_226"
                                                                    (let-pair "du16_fst_221" "du16_snd_222" (read-u16 little-endian (identifier "dsum1_snd_83")) (make-tup (identifier "du16_fst_221") (identifier "du16_snd_222")))
                                                                    (let-pair "dsum1_fst_227" "dsum1_snd_228" 
                                                                    (identifier "dsum1_226")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_227"))
                                                                    (let "drec_256"
                                                                    (let-pair "du32_fst_251" "du32_snd_252" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_228")) 
                                                                    (make-tup (make-usr "Ip4" (identifier "du32_fst_251")) (identifier "du32_snd_252")))
                                                                    (let-pair "drec_fst_257" "drec_snd_258" 
                                                                    (identifier "drec_256")
                                                                    (let-pair "du8_fst_260" "du8_snd_261" 
                                                                    (read-u8 (identifier "drec_snd_258"))
                                                                    (make-tup
                                                                    (construct "[v4 Cidr4 | v6 Cidr6]" 0 (make-usr "Cidr4" (make-rec (string "mask") (identifier "du8_fst_260") (string "ip") (identifier "drec_fst_257"))))
                                                                    (identifier "du8_snd_261")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_227") (u16 1)))
                                                                    (let "drec_235"
                                                                    (let-pair "di128_fst_230" "di128_snd_231" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_228")) 
                                                                    (make-tup (make-usr "Ip6" (identifier "di128_fst_230")) (identifier "di128_snd_231")))
                                                                    (let-pair "drec_fst_236" "drec_snd_237" 
                                                                    (identifier "drec_235")
                                                                    (let-pair "du8_fst_239" "du8_snd_240" 
                                                                    (read-u8 (identifier "drec_snd_237"))
                                                                    (make-tup
                                                                    (construct "[v4 Cidr4 | v6 Cidr6]" 1 (make-usr "Cidr6" (make-rec (string "mask") (identifier "du8_fst_239") (string "ip") (identifier "drec_fst_236"))))
                                                                    (identifier "du8_snd_240")))))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 30
                                                                    (make-usr "Cidr" (identifier "des_usr_type_fst_272"))) 
                                                                    (identifier "des_usr_type_snd_273")))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dlist4_fst_215" "dlist4_snd_216"
                                                                    (let "dlist1_203"
                                                                    (let "leb_ref_194" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_195" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_196" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_197" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_196")))
                                                                    (let-pair "leb128_fst_198" "leb128_snd_199" 
                                                                    (identifier "leb128_197")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_196") (identifier "leb128_snd_199"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_194")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_198") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_195")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_194")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_195") (add (unsafe-nth (u8 0) (identifier "shft_ref_195")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_198") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_194")) (unsafe-nth (u8 0) (identifier "p_ref_196")))))))
                                                                    (let-pair "dlist1_fst_204" "dlist1_snd_205" 
                                                                    (identifier "dlist1_203")
                                                                    (let "inits_src_ref_206" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_205")))
                                                                    (seq
                                                                    (let "repeat_n_207" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_204")) (unsafe-nth (u8 0) (identifier "repeat_n_207")))
                                                                    (seq
                                                                    (let "dlist2_208" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_206"))
                                                                    (let-pair "dlist2_fst_209" "dlist2_snd_210" 
                                                                    (identifier "dlist2_208")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_206")
                                                                    (let-pair "dlist3_fst_212" "dlist3_snd_213" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_210"))
                                                                    (make-tup (cons (identifier "dlist3_fst_212") (identifier "dlist2_fst_209")) (identifier "dlist3_snd_213"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_207") (add (unsafe-nth (u8 0) (identifier "repeat_n_207")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_206"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 31
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_215"))) 
                                                                    (identifier "dlist4_snd_216")))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dlist4_fst_189" "dlist4_snd_190"
                                                                    (let "dlist1_177"
                                                                    (let "leb_ref_168" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_169" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_170" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_171" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_170")))
                                                                    (let-pair "leb128_fst_172" "leb128_snd_173" 
                                                                    (identifier "leb128_171")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_170") (identifier "leb128_snd_173"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_168")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_172") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_169")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_168")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_169") (add (unsafe-nth (u8 0) (identifier "shft_ref_169")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_172") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_168")) (unsafe-nth (u8 0) (identifier "p_ref_170")))))))
                                                                    (let-pair "dlist1_fst_178" "dlist1_snd_179" 
                                                                    (identifier "dlist1_177")
                                                                    (let "inits_src_ref_180" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_179")))
                                                                    (seq
                                                                    (let "repeat_n_181" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_178")) (unsafe-nth (u8 0) (identifier "repeat_n_181")))
                                                                    (seq
                                                                    (let "dlist2_182" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_180"))
                                                                    (let-pair "dlist2_fst_183" "dlist2_snd_184" 
                                                                    (identifier "dlist2_182")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_180")
                                                                    (let-pair "dlist3_fst_186" "dlist3_snd_187" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_184"))
                                                                    (make-tup (cons (identifier "dlist3_fst_186") (identifier "dlist2_fst_183")) (identifier "dlist3_snd_187"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_181") (add (unsafe-nth (u8 0) (identifier "repeat_n_181")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_180"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 32
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_189"))) 
                                                                    (identifier "dlist4_snd_190")))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dlist4_fst_163" "dlist4_snd_164"
                                                                    (let "dlist1_151"
                                                                    (let "leb_ref_142" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_143" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_144" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_145" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_144")))
                                                                    (let-pair "leb128_fst_146" "leb128_snd_147" 
                                                                    (identifier "leb128_145")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_144") (identifier "leb128_snd_147"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_142")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_146") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_143")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_142")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_143") (add (unsafe-nth (u8 0) (identifier "shft_ref_143")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_146") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_142")) (unsafe-nth (u8 0) (identifier "p_ref_144")))))))
                                                                    (let-pair "dlist1_fst_152" "dlist1_snd_153" 
                                                                    (identifier "dlist1_151")
                                                                    (let "inits_src_ref_154" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_153")))
                                                                    (seq
                                                                    (let "repeat_n_155" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_152")) (unsafe-nth (u8 0) (identifier "repeat_n_155")))
                                                                    (seq
                                                                    (let "dlist2_156" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_154"))
                                                                    (let-pair "dlist2_fst_157" "dlist2_snd_158" 
                                                                    (identifier "dlist2_156")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_154")
                                                                    (let-pair "dlist3_fst_160" "dlist3_snd_161" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_158"))
                                                                    (make-tup (cons (identifier "dlist3_fst_160") (identifier "dlist2_fst_157")) (identifier "dlist3_snd_161"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_155") (add (unsafe-nth (u8 0) (identifier "repeat_n_155")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_154"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 33
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_163"))) 
                                                                    (identifier "dlist4_snd_164")))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "dsum1_fst_82"))
                                                                    (let-pair "dlist4_fst_137" "dlist4_snd_138"
                                                                    (let "dlist1_125"
                                                                    (let "leb_ref_116" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_117" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_118" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_119" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_118")))
                                                                    (let-pair "leb128_fst_120" "leb128_snd_121" 
                                                                    (identifier "leb128_119")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_118") (identifier "leb128_snd_121"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_116")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_120") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_117")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_116")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_117") (add (unsafe-nth (u8 0) (identifier "shft_ref_117")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_120") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_116")) (unsafe-nth (u8 0) (identifier "p_ref_118")))))))
                                                                    (let-pair "dlist1_fst_126" "dlist1_snd_127" 
                                                                    (identifier "dlist1_125")
                                                                    (let "inits_src_ref_128" 
                                                                    (make-vec (make-tup (end-of-list "(named_value AS (STRING; THIS))") (identifier "dlist1_snd_127")))
                                                                    (seq
                                                                    (let "repeat_n_129" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_126")) (unsafe-nth (u8 0) (identifier "repeat_n_129")))
                                                                    (seq
                                                                    (let "dlist2_130" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_128"))
                                                                    (let-pair "dlist2_fst_131" "dlist2_snd_132" 
                                                                    (identifier "dlist2_130")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_128")
                                                                    (let-pair "dlist3_fst_134" "dlist3_snd_135" 
                                                                    (apply (identifier "named_value-of-row-binary") (identifier "dlist2_snd_132"))
                                                                    (make-tup (cons (identifier "dlist3_fst_134") (identifier "dlist2_fst_131")) (identifier "dlist3_snd_135"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_129") (add (unsafe-nth (u8 0) (identifier "repeat_n_129")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_128"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 34
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_137"))) 
                                                                    (identifier "dlist4_snd_138")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_82") (u16 35)))
                                                                    (let-pair "dlist4_fst_111" "dlist4_snd_112"
                                                                    (let "dlist1_93"
                                                                    (let "leb_ref_84" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_85" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_86" 
                                                                    (make-vec (identifier "dsum1_snd_83"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_87" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_86")))
                                                                    (let-pair "leb128_fst_88" "leb128_snd_89" 
                                                                    (identifier "leb128_87")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_86") (identifier "leb128_snd_89"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_84")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_88") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_85")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_84")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_85") (add (unsafe-nth (u8 0) (identifier "shft_ref_85")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_88") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_84")) (unsafe-nth (u8 0) (identifier "p_ref_86")))))))
                                                                    (let-pair "dlist1_fst_94" "dlist1_snd_95" 
                                                                    (identifier "dlist1_93")
                                                                    (let "inits_src_ref_96" 
                                                                    (make-vec (make-tup (end-of-list "(THIS; THIS)") (identifier "dlist1_snd_95")))
                                                                    (seq
                                                                    (let "repeat_n_97" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_94")) (unsafe-nth (u8 0) (identifier "repeat_n_97")))
                                                                    (seq
                                                                    (let "dlist2_98" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_96"))
                                                                    (let-pair "dlist2_fst_99" "dlist2_snd_100" 
                                                                    (identifier "dlist2_98")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_96")
                                                                    (let-pair "dtup_fst_102" "dtup_snd_103" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_100"))
                                                                    (let-pair "dtup_fst_105" "dtup_snd_106" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_103"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_102") (identifier "dtup_fst_105")) (identifier "dlist2_fst_99")) (identifier "dtup_snd_106")))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_97") (add (unsafe-nth (u8 0) (identifier "repeat_n_97")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_96"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 35
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_111"))) 
                                                                    (identifier "dlist4_snd_112"))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> fun0 { [&](Pointer p_0) {
    ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_1 { p_0.readU16Le() };
    ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2;
    {
      auto du16_fst_76 { std::get<0>(id_1) };
      auto du16_snd_77 { std::get<1>(id_1) };
      ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_3 { du16_fst_76, du16_snd_77 };
      letpair_res_2 = id_3;
    }
    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e let_res_4;
    {
      ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 dsum1_81 { letpair_res_2 };
      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_5;
      {
        auto dsum1_fst_82 { std::get<0>(dsum1_81) };
        auto dsum1_snd_83 { std::get<1>(dsum1_81) };
        uint16_t id_6 { 0 };
        bool id_7 { bool(id_6 == dsum1_fst_82) };
        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_8;
        if (id_7) {
          (void)::dessser::Void();
          std::shared_ptr<::dessser::gen::raql_value::t>  id_9 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<0>, ::dessser::Void()) };
          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_10 { id_9, dsum1_snd_83 };
          choose_res_8 = id_10;
        } else {
          uint16_t id_11 { 1 };
          bool id_12 { bool(id_11 == dsum1_fst_82) };
          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_13;
          if (id_12) {
            (void)::dessser::Void();
            std::shared_ptr<::dessser::gen::raql_value::t>  id_14 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<1>, ::dessser::Void()) };
            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_15 { id_14, dsum1_snd_83 };
            choose_res_13 = id_15;
          } else {
            uint16_t id_16 { 2 };
            bool id_17 { bool(id_16 == dsum1_fst_82) };
            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_18;
            if (id_17) {
              ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_19 { dsum1_snd_83.readU64Le() };
              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_20;
              {
                auto dfloat_fst_515 { std::get<0>(id_19) };
                auto dfloat_snd_516 { std::get<1>(id_19) };
                double id_21 { float_of_qword(dfloat_fst_515) };
                std::shared_ptr<::dessser::gen::raql_value::t>  id_22 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<2>, id_21) };
                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_23 { id_22, dfloat_snd_516 };
                letpair_res_20 = id_23;
              }
              choose_res_18 = letpair_res_20;
            } else {
              uint16_t id_24 { 3 };
              bool id_25 { bool(id_24 == dsum1_fst_82) };
              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_26;
              if (id_25) {
                uint32_t id_27 { 0U };
                Vec<1, uint32_t> id_28 {  id_27  };
                ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa let_res_29;
                {
                  Vec<1, uint32_t> leb_ref_499 { id_28 };
                  uint8_t id_30 { 0 };
                  Vec<1, uint8_t> id_31 {  id_30  };
                  ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa let_res_32;
                  {
                    Vec<1, uint8_t> shft_ref_500 { id_31 };
                    Vec<1, Pointer> id_33 {  dsum1_snd_83  };
                    ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa let_res_34;
                    {
                      Vec<1, Pointer> p_ref_501 { id_33 };
                      bool while_flag_35 { true };
                      do {
                        uint8_t id_36 { 0 };
                        Pointer id_37 { p_ref_501[id_36] };
                        ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_38 { id_37.readU8() };
                        bool let_res_39;
                        {
                          ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_502 { id_38 };
                          bool letpair_res_40;
                          {
                            auto leb128_fst_503 { std::get<0>(leb128_502) };
                            auto leb128_snd_504 { std::get<1>(leb128_502) };
                            uint8_t id_41 { 0 };
                            Void id_42 { ((void)(p_ref_501[id_41] = leb128_snd_504), ::dessser::Void()) };
                            (void)id_42;
                            uint8_t id_43 { 0 };
                            uint8_t id_44 { 127 };
                            uint8_t id_45 { uint8_t(leb128_fst_503 & id_44) };
                            uint32_t id_46 { uint32_t(id_45) };
                            uint8_t id_47 { 0 };
                            uint8_t id_48 { shft_ref_500[id_47] };
                            uint32_t id_49 { uint32_t(id_46 << id_48) };
                            uint8_t id_50 { 0 };
                            uint32_t id_51 { leb_ref_499[id_50] };
                            uint32_t id_52 { uint32_t(id_49 | id_51) };
                            Void id_53 { ((void)(leb_ref_499[id_43] = id_52), ::dessser::Void()) };
                            (void)id_53;
                            uint8_t id_54 { 0 };
                            uint8_t id_55 { 0 };
                            uint8_t id_56 { shft_ref_500[id_55] };
                            uint8_t id_57 { 7 };
                            uint8_t id_58 { uint8_t(id_56 + id_57) };
                            Void id_59 { ((void)(shft_ref_500[id_54] = id_58), ::dessser::Void()) };
                            (void)id_59;
                            uint8_t id_60 { 128 };
                            bool id_61 { bool(leb128_fst_503 >= id_60) };
                            letpair_res_40 = id_61;
                          }
                          let_res_39 = letpair_res_40;
                        }
                        while_flag_35 = let_res_39;
                        if (while_flag_35) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_35);
                      (void)::dessser::Void();
                      uint8_t id_62 { 0 };
                      uint32_t id_63 { leb_ref_499[id_62] };
                      Size id_64 { Size(id_63) };
                      uint8_t id_65 { 0 };
                      Pointer id_66 { p_ref_501[id_65] };
                      ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa id_67 { id_64, id_66 };
                      let_res_34 = id_67;
                    }
                    let_res_32 = let_res_34;
                  }
                  let_res_29 = let_res_32;
                }
                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e let_res_68;
                {
                  ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa dstring1_505 { let_res_29 };
                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_69;
                  {
                    auto dstring1_fst_506 { std::get<0>(dstring1_505) };
                    auto dstring1_snd_507 { std::get<1>(dstring1_505) };
                    ::dessser::gen::raql_value::t9ef6882174ae71a34a3c5ef6b29242fb id_70 { dstring1_snd_507.readBytes(dstring1_fst_506) };
                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_71;
                    {
                      auto dstring2_fst_509 { std::get<0>(id_70) };
                      auto dstring2_snd_510 { std::get<1>(id_70) };
                      std::string id_72 { dstring2_fst_509.toString() };
                      std::shared_ptr<::dessser::gen::raql_value::t>  id_73 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<3>, id_72) };
                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_74 { id_73, dstring2_snd_510 };
                      letpair_res_71 = id_74;
                    }
                    letpair_res_69 = letpair_res_71;
                  }
                  let_res_68 = letpair_res_69;
                }
                choose_res_26 = let_res_68;
              } else {
                uint16_t id_75 { 4 };
                bool id_76 { bool(id_75 == dsum1_fst_82) };
                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_77;
                if (id_76) {
                  ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_78 { dsum1_snd_83.readU8() };
                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_79;
                  {
                    auto dbool_fst_494 { std::get<0>(id_78) };
                    auto dbool_snd_495 { std::get<1>(id_78) };
                    uint8_t id_80 { 0 };
                    bool id_81 { bool(dbool_fst_494 == id_80) };
                    bool id_82 { ! id_81 };
                    std::shared_ptr<::dessser::gen::raql_value::t>  id_83 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<4>, id_82) };
                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_84 { id_83, dbool_snd_495 };
                    letpair_res_79 = id_84;
                  }
                  choose_res_77 = letpair_res_79;
                } else {
                  uint16_t id_85 { 5 };
                  bool id_86 { bool(id_85 == dsum1_fst_82) };
                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_87;
                  if (id_86) {
                    ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_88 { dsum1_snd_83.readU8() };
                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_89;
                    {
                      auto dchar_fst_488 { std::get<0>(id_88) };
                      auto dchar_snd_489 { std::get<1>(id_88) };
                      char id_90 { char(dchar_fst_488) };
                      std::shared_ptr<::dessser::gen::raql_value::t>  id_91 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<5>, id_90) };
                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_92 { id_91, dchar_snd_489 };
                      letpair_res_89 = id_92;
                    }
                    choose_res_87 = letpair_res_89;
                  } else {
                    uint16_t id_93 { 6 };
                    bool id_94 { bool(id_93 == dsum1_fst_82) };
                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_95;
                    if (id_94) {
                      ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_96 { dsum1_snd_83.readU8() };
                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_97;
                      {
                        auto du8_fst_482 { std::get<0>(id_96) };
                        auto du8_snd_483 { std::get<1>(id_96) };
                        std::shared_ptr<::dessser::gen::raql_value::t>  id_98 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<6>, du8_fst_482) };
                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_99 { id_98, du8_snd_483 };
                        letpair_res_97 = id_99;
                      }
                      choose_res_95 = letpair_res_97;
                    } else {
                      uint16_t id_100 { 7 };
                      bool id_101 { bool(id_100 == dsum1_fst_82) };
                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_102;
                      if (id_101) {
                        ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_103 { dsum1_snd_83.readU16Le() };
                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_104;
                        {
                          auto du16_fst_476 { std::get<0>(id_103) };
                          auto du16_snd_477 { std::get<1>(id_103) };
                          std::shared_ptr<::dessser::gen::raql_value::t>  id_105 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<7>, du16_fst_476) };
                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_106 { id_105, du16_snd_477 };
                          letpair_res_104 = id_106;
                        }
                        choose_res_102 = letpair_res_104;
                      } else {
                        uint16_t id_107 { 8 };
                        bool id_108 { bool(id_107 == dsum1_fst_82) };
                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_109;
                        if (id_108) {
                          ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_110 { dsum1_snd_83.readU32Le() };
                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_111;
                          {
                            auto du24_fst_470 { std::get<0>(id_110) };
                            auto du24_snd_471 { std::get<1>(id_110) };
                            uint32_t id_112 { uint32_t(du24_fst_470) };
                            std::shared_ptr<::dessser::gen::raql_value::t>  id_113 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<8>, id_112) };
                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_114 { id_113, du24_snd_471 };
                            letpair_res_111 = id_114;
                          }
                          choose_res_109 = letpair_res_111;
                        } else {
                          uint16_t id_115 { 9 };
                          bool id_116 { bool(id_115 == dsum1_fst_82) };
                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_117;
                          if (id_116) {
                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_118 { dsum1_snd_83.readU32Le() };
                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_119;
                            {
                              auto du32_fst_464 { std::get<0>(id_118) };
                              auto du32_snd_465 { std::get<1>(id_118) };
                              std::shared_ptr<::dessser::gen::raql_value::t>  id_120 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<9>, du32_fst_464) };
                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_121 { id_120, du32_snd_465 };
                              letpair_res_119 = id_121;
                            }
                            choose_res_117 = letpair_res_119;
                          } else {
                            uint16_t id_122 { 10 };
                            bool id_123 { bool(id_122 == dsum1_fst_82) };
                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_124;
                            if (id_123) {
                              ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_125 { dsum1_snd_83.readU64Le() };
                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_126;
                              {
                                auto du40_fst_458 { std::get<0>(id_125) };
                                auto du40_snd_459 { std::get<1>(id_125) };
                                uint64_t id_127 { uint64_t(du40_fst_458) };
                                std::shared_ptr<::dessser::gen::raql_value::t>  id_128 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<10>, id_127) };
                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_129 { id_128, du40_snd_459 };
                                letpair_res_126 = id_129;
                              }
                              choose_res_124 = letpair_res_126;
                            } else {
                              uint16_t id_130 { 11 };
                              bool id_131 { bool(id_130 == dsum1_fst_82) };
                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_132;
                              if (id_131) {
                                ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_133 { dsum1_snd_83.readU64Le() };
                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_134;
                                {
                                  auto du48_fst_452 { std::get<0>(id_133) };
                                  auto du48_snd_453 { std::get<1>(id_133) };
                                  uint64_t id_135 { uint64_t(du48_fst_452) };
                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_136 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<11>, id_135) };
                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_137 { id_136, du48_snd_453 };
                                  letpair_res_134 = id_137;
                                }
                                choose_res_132 = letpair_res_134;
                              } else {
                                uint16_t id_138 { 12 };
                                bool id_139 { bool(id_138 == dsum1_fst_82) };
                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_140;
                                if (id_139) {
                                  ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_141 { dsum1_snd_83.readU64Le() };
                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_142;
                                  {
                                    auto du56_fst_446 { std::get<0>(id_141) };
                                    auto du56_snd_447 { std::get<1>(id_141) };
                                    uint64_t id_143 { uint64_t(du56_fst_446) };
                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_144 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<12>, id_143) };
                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_145 { id_144, du56_snd_447 };
                                    letpair_res_142 = id_145;
                                  }
                                  choose_res_140 = letpair_res_142;
                                } else {
                                  uint16_t id_146 { 13 };
                                  bool id_147 { bool(id_146 == dsum1_fst_82) };
                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_148;
                                  if (id_147) {
                                    ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_149 { dsum1_snd_83.readU64Le() };
                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_150;
                                    {
                                      auto du64_fst_440 { std::get<0>(id_149) };
                                      auto du64_snd_441 { std::get<1>(id_149) };
                                      std::shared_ptr<::dessser::gen::raql_value::t>  id_151 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<13>, du64_fst_440) };
                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_152 { id_151, du64_snd_441 };
                                      letpair_res_150 = id_152;
                                    }
                                    choose_res_148 = letpair_res_150;
                                  } else {
                                    uint16_t id_153 { 14 };
                                    bool id_154 { bool(id_153 == dsum1_fst_82) };
                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_155;
                                    if (id_154) {
                                      ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_156 { dsum1_snd_83.readU128Le() };
                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_157;
                                      {
                                        auto di128_fst_434 { std::get<0>(id_156) };
                                        auto di128_snd_435 { std::get<1>(id_156) };
                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_158 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<14>, di128_fst_434) };
                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_159 { id_158, di128_snd_435 };
                                        letpair_res_157 = id_159;
                                      }
                                      choose_res_155 = letpair_res_157;
                                    } else {
                                      uint16_t id_160 { 15 };
                                      bool id_161 { bool(id_160 == dsum1_fst_82) };
                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_162;
                                      if (id_161) {
                                        ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_163 { dsum1_snd_83.readU8() };
                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_164;
                                        {
                                          auto di8_fst_428 { std::get<0>(id_163) };
                                          auto di8_snd_429 { std::get<1>(id_163) };
                                          int8_t id_165 { int8_t(di8_fst_428) };
                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_166 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<15>, id_165) };
                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_167 { id_166, di8_snd_429 };
                                          letpair_res_164 = id_167;
                                        }
                                        choose_res_162 = letpair_res_164;
                                      } else {
                                        uint16_t id_168 { 16 };
                                        bool id_169 { bool(id_168 == dsum1_fst_82) };
                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_170;
                                        if (id_169) {
                                          ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_171 { dsum1_snd_83.readU16Le() };
                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_172;
                                          {
                                            auto di16_fst_422 { std::get<0>(id_171) };
                                            auto di16_snd_423 { std::get<1>(id_171) };
                                            int16_t id_173 { int16_t(di16_fst_422) };
                                            std::shared_ptr<::dessser::gen::raql_value::t>  id_174 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<16>, id_173) };
                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_175 { id_174, di16_snd_423 };
                                            letpair_res_172 = id_175;
                                          }
                                          choose_res_170 = letpair_res_172;
                                        } else {
                                          uint16_t id_176 { 17 };
                                          bool id_177 { bool(id_176 == dsum1_fst_82) };
                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_178;
                                          if (id_177) {
                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_179 { dsum1_snd_83.readU32Le() };
                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_180;
                                            {
                                              auto di24_fst_416 { std::get<0>(id_179) };
                                              auto di24_snd_417 { std::get<1>(id_179) };
                                              int32_t id_181 { int32_t(di24_fst_416) };
                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_182 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<17>, id_181) };
                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_183 { id_182, di24_snd_417 };
                                              letpair_res_180 = id_183;
                                            }
                                            choose_res_178 = letpair_res_180;
                                          } else {
                                            uint16_t id_184 { 18 };
                                            bool id_185 { bool(id_184 == dsum1_fst_82) };
                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_186;
                                            if (id_185) {
                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_187 { dsum1_snd_83.readU32Le() };
                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_188;
                                              {
                                                auto di32_fst_410 { std::get<0>(id_187) };
                                                auto di32_snd_411 { std::get<1>(id_187) };
                                                int32_t id_189 { int32_t(di32_fst_410) };
                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_190 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<18>, id_189) };
                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_191 { id_190, di32_snd_411 };
                                                letpair_res_188 = id_191;
                                              }
                                              choose_res_186 = letpair_res_188;
                                            } else {
                                              uint16_t id_192 { 19 };
                                              bool id_193 { bool(id_192 == dsum1_fst_82) };
                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_194;
                                              if (id_193) {
                                                ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_195 { dsum1_snd_83.readU64Le() };
                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_196;
                                                {
                                                  auto di40_fst_404 { std::get<0>(id_195) };
                                                  auto di40_snd_405 { std::get<1>(id_195) };
                                                  int64_t id_197 { int64_t(di40_fst_404) };
                                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_198 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<19>, id_197) };
                                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_199 { id_198, di40_snd_405 };
                                                  letpair_res_196 = id_199;
                                                }
                                                choose_res_194 = letpair_res_196;
                                              } else {
                                                uint16_t id_200 { 20 };
                                                bool id_201 { bool(id_200 == dsum1_fst_82) };
                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_202;
                                                if (id_201) {
                                                  ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_203 { dsum1_snd_83.readU64Le() };
                                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_204;
                                                  {
                                                    auto di48_fst_398 { std::get<0>(id_203) };
                                                    auto di48_snd_399 { std::get<1>(id_203) };
                                                    int64_t id_205 { int64_t(di48_fst_398) };
                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_206 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<20>, id_205) };
                                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_207 { id_206, di48_snd_399 };
                                                    letpair_res_204 = id_207;
                                                  }
                                                  choose_res_202 = letpair_res_204;
                                                } else {
                                                  uint16_t id_208 { 21 };
                                                  bool id_209 { bool(id_208 == dsum1_fst_82) };
                                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_210;
                                                  if (id_209) {
                                                    ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_211 { dsum1_snd_83.readU64Le() };
                                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_212;
                                                    {
                                                      auto di56_fst_392 { std::get<0>(id_211) };
                                                      auto di56_snd_393 { std::get<1>(id_211) };
                                                      int64_t id_213 { int64_t(di56_fst_392) };
                                                      std::shared_ptr<::dessser::gen::raql_value::t>  id_214 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<21>, id_213) };
                                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_215 { id_214, di56_snd_393 };
                                                      letpair_res_212 = id_215;
                                                    }
                                                    choose_res_210 = letpair_res_212;
                                                  } else {
                                                    uint16_t id_216 { 22 };
                                                    bool id_217 { bool(id_216 == dsum1_fst_82) };
                                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_218;
                                                    if (id_217) {
                                                      ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_219 { dsum1_snd_83.readU64Le() };
                                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_220;
                                                      {
                                                        auto di64_fst_386 { std::get<0>(id_219) };
                                                        auto di64_snd_387 { std::get<1>(id_219) };
                                                        int64_t id_221 { int64_t(di64_fst_386) };
                                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_222 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<22>, id_221) };
                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_223 { id_222, di64_snd_387 };
                                                        letpair_res_220 = id_223;
                                                      }
                                                      choose_res_218 = letpair_res_220;
                                                    } else {
                                                      uint16_t id_224 { 23 };
                                                      bool id_225 { bool(id_224 == dsum1_fst_82) };
                                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_226;
                                                      if (id_225) {
                                                        ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_227 { dsum1_snd_83.readU128Le() };
                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_228;
                                                        {
                                                          auto di128_fst_380 { std::get<0>(id_227) };
                                                          auto di128_snd_381 { std::get<1>(id_227) };
                                                          int128_t id_229 { int128_t(di128_fst_380) };
                                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_230 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<23>, id_229) };
                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_231 { id_230, di128_snd_381 };
                                                          letpair_res_228 = id_231;
                                                        }
                                                        choose_res_226 = letpair_res_228;
                                                      } else {
                                                        uint16_t id_232 { 24 };
                                                        bool id_233 { bool(id_232 == dsum1_fst_82) };
                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_234;
                                                        if (id_233) {
                                                          ::dessser::gen::raql_value::td2cd337bb3c8bc04d5603393d084985b id_235 { dsum1_snd_83.readU64Le() };
                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_236;
                                                          {
                                                            auto du48_fst_371 { std::get<0>(id_235) };
                                                            auto du48_snd_372 { std::get<1>(id_235) };
                                                            std::function<uint64_t(uint64_t)> fun237 { [&](uint64_t p_0) {
                                                              return p_0;
                                                            }
                                                             };
                                                            uint64_t id_238 { uint64_t(du48_fst_371) };
                                                            uint64_t id_239 { fun237(id_238) };
                                                            std::shared_ptr<::dessser::gen::raql_value::t>  id_240 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<24>, id_239) };
                                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_241 { id_240, du48_snd_372 };
                                                            letpair_res_236 = id_241;
                                                          }
                                                          choose_res_234 = letpair_res_236;
                                                        } else {
                                                          uint16_t id_242 { 25 };
                                                          bool id_243 { bool(id_242 == dsum1_fst_82) };
                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_244;
                                                          if (id_243) {
                                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_245 { dsum1_snd_83.readU32Le() };
                                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_246;
                                                            {
                                                              auto du32_fst_362 { std::get<0>(id_245) };
                                                              auto du32_snd_363 { std::get<1>(id_245) };
                                                              std::function<uint32_t(uint32_t)> fun247 { [&](uint32_t p_0) {
                                                                return p_0;
                                                              }
                                                               };
                                                              uint32_t id_248 { fun247(du32_fst_362) };
                                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_249 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<25>, id_248) };
                                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_250 { id_249, du32_snd_363 };
                                                              letpair_res_246 = id_250;
                                                            }
                                                            choose_res_244 = letpair_res_246;
                                                          } else {
                                                            uint16_t id_251 { 26 };
                                                            bool id_252 { bool(id_251 == dsum1_fst_82) };
                                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_253;
                                                            if (id_252) {
                                                              ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_254 { dsum1_snd_83.readU128Le() };
                                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_255;
                                                              {
                                                                auto di128_fst_353 { std::get<0>(id_254) };
                                                                auto di128_snd_354 { std::get<1>(id_254) };
                                                                std::function<uint128_t(uint128_t)> fun256 { [&](uint128_t p_0) {
                                                                  return p_0;
                                                                }
                                                                 };
                                                                uint128_t id_257 { fun256(di128_fst_353) };
                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_258 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<26>, id_257) };
                                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_259 { id_258, di128_snd_354 };
                                                                letpair_res_255 = id_259;
                                                              }
                                                              choose_res_253 = letpair_res_255;
                                                            } else {
                                                              uint16_t id_260 { 27 };
                                                              bool id_261 { bool(id_260 == dsum1_fst_82) };
                                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_262;
                                                              if (id_261) {
                                                                ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_263 { dsum1_snd_83.readU16Le() };
                                                                ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 letpair_res_264;
                                                                {
                                                                  auto du16_fst_320 { std::get<0>(id_263) };
                                                                  auto du16_snd_321 { std::get<1>(id_263) };
                                                                  ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_265 { du16_fst_320, du16_snd_321 };
                                                                  letpair_res_264 = id_265;
                                                                }
                                                                ::dessser::gen::raql_value::td5b91cc4eacb7073aad7ac65784b815a let_res_266;
                                                                {
                                                                  ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 dsum1_325 { letpair_res_264 };
                                                                  ::dessser::gen::raql_value::td5b91cc4eacb7073aad7ac65784b815a letpair_res_267;
                                                                  {
                                                                    auto dsum1_fst_326 { std::get<0>(dsum1_325) };
                                                                    auto dsum1_snd_327 { std::get<1>(dsum1_325) };
                                                                    uint16_t id_268 { 0 };
                                                                    bool id_269 { bool(id_268 == dsum1_fst_326) };
                                                                    ::dessser::gen::raql_value::td5b91cc4eacb7073aad7ac65784b815a choose_res_270;
                                                                    if (id_269) {
                                                                      ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_271 { dsum1_snd_327.readU32Le() };
                                                                      ::dessser::gen::raql_value::td5b91cc4eacb7073aad7ac65784b815a letpair_res_272;
                                                                      {
                                                                        auto du32_fst_338 { std::get<0>(id_271) };
                                                                        auto du32_snd_339 { std::get<1>(id_271) };
                                                                        std::function<uint32_t(uint32_t)> fun273 { [&](uint32_t p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        uint32_t id_274 { fun273(du32_fst_338) };
                                                                        ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_275 { std::in_place_index<0>, id_274 };
                                                                        ::dessser::gen::raql_value::td5b91cc4eacb7073aad7ac65784b815a id_276 { id_275, du32_snd_339 };
                                                                        letpair_res_272 = id_276;
                                                                      }
                                                                      choose_res_270 = letpair_res_272;
                                                                    } else {
                                                                      uint16_t id_277 { 1 };
                                                                      bool id_278 { bool(dsum1_fst_326 == id_277) };
                                                                      Void id_279 { ((void)(assert(id_278)), ::dessser::Void()) };
                                                                      (void)id_279;
                                                                      ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_280 { dsum1_snd_327.readU128Le() };
                                                                      ::dessser::gen::raql_value::td5b91cc4eacb7073aad7ac65784b815a letpair_res_281;
                                                                      {
                                                                        auto di128_fst_329 { std::get<0>(id_280) };
                                                                        auto di128_snd_330 { std::get<1>(id_280) };
                                                                        std::function<uint128_t(uint128_t)> fun282 { [&](uint128_t p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        uint128_t id_283 { fun282(di128_fst_329) };
                                                                        ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_284 { std::in_place_index<1>, id_283 };
                                                                        ::dessser::gen::raql_value::td5b91cc4eacb7073aad7ac65784b815a id_285 { id_284, di128_snd_330 };
                                                                        letpair_res_281 = id_285;
                                                                      }
                                                                      choose_res_270 = letpair_res_281;
                                                                    }
                                                                    letpair_res_267 = choose_res_270;
                                                                  }
                                                                  let_res_266 = letpair_res_267;
                                                                }
                                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_286;
                                                                {
                                                                  auto des_usr_type_fst_347 { std::get<0>(let_res_266) };
                                                                  auto des_usr_type_snd_348 { std::get<1>(let_res_266) };
                                                                  std::function<::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a(::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a)> fun287 { [&](::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a p_0) {
                                                                    return p_0;
                                                                  }
                                                                   };
                                                                  ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_288 { fun287(des_usr_type_fst_347) };
                                                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_289 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<27>, id_288) };
                                                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_290 { id_289, des_usr_type_snd_348 };
                                                                  letpair_res_286 = id_290;
                                                                }
                                                                choose_res_262 = letpair_res_286;
                                                              } else {
                                                                uint16_t id_291 { 28 };
                                                                bool id_292 { bool(id_291 == dsum1_fst_82) };
                                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_293;
                                                                if (id_292) {
                                                                  ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_294 { dsum1_snd_83.readU32Le() };
                                                                  ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 letpair_res_295;
                                                                  {
                                                                    auto du32_fst_299 { std::get<0>(id_294) };
                                                                    auto du32_snd_300 { std::get<1>(id_294) };
                                                                    std::function<uint32_t(uint32_t)> fun296 { [&](uint32_t p_0) {
                                                                      return p_0;
                                                                    }
                                                                     };
                                                                    uint32_t id_297 { fun296(du32_fst_299) };
                                                                    ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_298 { id_297, du32_snd_300 };
                                                                    letpair_res_295 = id_298;
                                                                  }
                                                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e let_res_299;
                                                                  {
                                                                    ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 drec_304 { letpair_res_295 };
                                                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_300;
                                                                    {
                                                                      auto drec_fst_305 { std::get<0>(drec_304) };
                                                                      auto drec_snd_306 { std::get<1>(drec_304) };
                                                                      ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_301 { drec_snd_306.readU8() };
                                                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_302;
                                                                      {
                                                                        auto du8_fst_308 { std::get<0>(id_301) };
                                                                        auto du8_snd_309 { std::get<1>(id_301) };
                                                                        std::function<::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3(::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3)> fun303 { [&](::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_304 { drec_fst_305, du8_fst_308 };
                                                                        ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_305 { fun303(id_304) };
                                                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_306 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<28>, id_305) };
                                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_307 { id_306, du8_snd_309 };
                                                                        letpair_res_302 = id_307;
                                                                      }
                                                                      letpair_res_300 = letpair_res_302;
                                                                    }
                                                                    let_res_299 = letpair_res_300;
                                                                  }
                                                                  choose_res_293 = let_res_299;
                                                                } else {
                                                                  uint16_t id_308 { 29 };
                                                                  bool id_309 { bool(id_308 == dsum1_fst_82) };
                                                                  ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_310;
                                                                  if (id_309) {
                                                                    ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_311 { dsum1_snd_83.readU128Le() };
                                                                    ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a letpair_res_312;
                                                                    {
                                                                      auto di128_fst_278 { std::get<0>(id_311) };
                                                                      auto di128_snd_279 { std::get<1>(id_311) };
                                                                      std::function<uint128_t(uint128_t)> fun313 { [&](uint128_t p_0) {
                                                                        return p_0;
                                                                      }
                                                                       };
                                                                      uint128_t id_314 { fun313(di128_fst_278) };
                                                                      ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_315 { id_314, di128_snd_279 };
                                                                      letpair_res_312 = id_315;
                                                                    }
                                                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e let_res_316;
                                                                    {
                                                                      ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a drec_283 { letpair_res_312 };
                                                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_317;
                                                                      {
                                                                        auto drec_fst_284 { std::get<0>(drec_283) };
                                                                        auto drec_snd_285 { std::get<1>(drec_283) };
                                                                        ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_318 { drec_snd_285.readU8() };
                                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_319;
                                                                        {
                                                                          auto du8_fst_287 { std::get<0>(id_318) };
                                                                          auto du8_snd_288 { std::get<1>(id_318) };
                                                                          std::function<::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41(::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41)> fun320 { [&](::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 p_0) {
                                                                            return p_0;
                                                                          }
                                                                           };
                                                                          ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_321 { drec_fst_284, du8_fst_287 };
                                                                          ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_322 { fun320(id_321) };
                                                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_323 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<29>, id_322) };
                                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_324 { id_323, du8_snd_288 };
                                                                          letpair_res_319 = id_324;
                                                                        }
                                                                        letpair_res_317 = letpair_res_319;
                                                                      }
                                                                      let_res_316 = letpair_res_317;
                                                                    }
                                                                    choose_res_310 = let_res_316;
                                                                  } else {
                                                                    uint16_t id_325 { 30 };
                                                                    bool id_326 { bool(id_325 == dsum1_fst_82) };
                                                                    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_327;
                                                                    if (id_326) {
                                                                      ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_328 { dsum1_snd_83.readU16Le() };
                                                                      ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 letpair_res_329;
                                                                      {
                                                                        auto du16_fst_221 { std::get<0>(id_328) };
                                                                        auto du16_snd_222 { std::get<1>(id_328) };
                                                                        ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 id_330 { du16_fst_221, du16_snd_222 };
                                                                        letpair_res_329 = id_330;
                                                                      }
                                                                      ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 let_res_331;
                                                                      {
                                                                        ::dessser::gen::raql_value::ta97bb48ed75bbda6173555873826c8c6 dsum1_226 { letpair_res_329 };
                                                                        ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 letpair_res_332;
                                                                        {
                                                                          auto dsum1_fst_227 { std::get<0>(dsum1_226) };
                                                                          auto dsum1_snd_228 { std::get<1>(dsum1_226) };
                                                                          uint16_t id_333 { 0 };
                                                                          bool id_334 { bool(id_333 == dsum1_fst_227) };
                                                                          ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 choose_res_335;
                                                                          if (id_334) {
                                                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_336 { dsum1_snd_228.readU32Le() };
                                                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 letpair_res_337;
                                                                            {
                                                                              auto du32_fst_251 { std::get<0>(id_336) };
                                                                              auto du32_snd_252 { std::get<1>(id_336) };
                                                                              std::function<uint32_t(uint32_t)> fun338 { [&](uint32_t p_0) {
                                                                                return p_0;
                                                                              }
                                                                               };
                                                                              uint32_t id_339 { fun338(du32_fst_251) };
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_340 { id_339, du32_snd_252 };
                                                                              letpair_res_337 = id_340;
                                                                            }
                                                                            ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 let_res_341;
                                                                            {
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 drec_256 { letpair_res_337 };
                                                                              ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 letpair_res_342;
                                                                              {
                                                                                auto drec_fst_257 { std::get<0>(drec_256) };
                                                                                auto drec_snd_258 { std::get<1>(drec_256) };
                                                                                ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_343 { drec_snd_258.readU8() };
                                                                                ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 letpair_res_344;
                                                                                {
                                                                                  auto du8_fst_260 { std::get<0>(id_343) };
                                                                                  auto du8_snd_261 { std::get<1>(id_343) };
                                                                                  std::function<::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3(::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3)> fun345 { [&](::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 p_0) {
                                                                                    return p_0;
                                                                                  }
                                                                                   };
                                                                                  ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_346 { drec_fst_257, du8_fst_260 };
                                                                                  ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_347 { fun345(id_346) };
                                                                                  ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_348 { std::in_place_index<0>, id_347 };
                                                                                  ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 id_349 { id_348, du8_snd_261 };
                                                                                  letpair_res_344 = id_349;
                                                                                }
                                                                                letpair_res_342 = letpair_res_344;
                                                                              }
                                                                              let_res_341 = letpair_res_342;
                                                                            }
                                                                            choose_res_335 = let_res_341;
                                                                          } else {
                                                                            uint16_t id_350 { 1 };
                                                                            bool id_351 { bool(dsum1_fst_227 == id_350) };
                                                                            Void id_352 { ((void)(assert(id_351)), ::dessser::Void()) };
                                                                            (void)id_352;
                                                                            ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_353 { dsum1_snd_228.readU128Le() };
                                                                            ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a letpair_res_354;
                                                                            {
                                                                              auto di128_fst_230 { std::get<0>(id_353) };
                                                                              auto di128_snd_231 { std::get<1>(id_353) };
                                                                              std::function<uint128_t(uint128_t)> fun355 { [&](uint128_t p_0) {
                                                                                return p_0;
                                                                              }
                                                                               };
                                                                              uint128_t id_356 { fun355(di128_fst_230) };
                                                                              ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a id_357 { id_356, di128_snd_231 };
                                                                              letpair_res_354 = id_357;
                                                                            }
                                                                            ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 let_res_358;
                                                                            {
                                                                              ::dessser::gen::raql_value::t859e6a4cc938643a1d59426a3bf7b15a drec_235 { letpair_res_354 };
                                                                              ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 letpair_res_359;
                                                                              {
                                                                                auto drec_fst_236 { std::get<0>(drec_235) };
                                                                                auto drec_snd_237 { std::get<1>(drec_235) };
                                                                                ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_360 { drec_snd_237.readU8() };
                                                                                ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 letpair_res_361;
                                                                                {
                                                                                  auto du8_fst_239 { std::get<0>(id_360) };
                                                                                  auto du8_snd_240 { std::get<1>(id_360) };
                                                                                  std::function<::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41(::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41)> fun362 { [&](::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 p_0) {
                                                                                    return p_0;
                                                                                  }
                                                                                   };
                                                                                  ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_363 { drec_fst_236, du8_fst_239 };
                                                                                  ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_364 { fun362(id_363) };
                                                                                  ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_365 { std::in_place_index<1>, id_364 };
                                                                                  ::dessser::gen::raql_value::t9843563dda20212bcf7939af05663f34 id_366 { id_365, du8_snd_240 };
                                                                                  letpair_res_361 = id_366;
                                                                                }
                                                                                letpair_res_359 = letpair_res_361;
                                                                              }
                                                                              let_res_358 = letpair_res_359;
                                                                            }
                                                                            choose_res_335 = let_res_358;
                                                                          }
                                                                          letpair_res_332 = choose_res_335;
                                                                        }
                                                                        let_res_331 = letpair_res_332;
                                                                      }
                                                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_367;
                                                                      {
                                                                        auto des_usr_type_fst_272 { std::get<0>(let_res_331) };
                                                                        auto des_usr_type_snd_273 { std::get<1>(let_res_331) };
                                                                        std::function<::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1(::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1)> fun368 { [&](::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_369 { fun368(des_usr_type_fst_272) };
                                                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_370 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<30>, id_369) };
                                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_371 { id_370, des_usr_type_snd_273 };
                                                                        letpair_res_367 = id_371;
                                                                      }
                                                                      choose_res_327 = letpair_res_367;
                                                                    } else {
                                                                      uint16_t id_372 { 31 };
                                                                      bool id_373 { bool(id_372 == dsum1_fst_82) };
                                                                      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_374;
                                                                      if (id_373) {
                                                                        uint32_t id_375 { 0U };
                                                                        Vec<1, uint32_t> id_376 {  id_375  };
                                                                        ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_377;
                                                                        {
                                                                          Vec<1, uint32_t> leb_ref_194 { id_376 };
                                                                          uint8_t id_378 { 0 };
                                                                          Vec<1, uint8_t> id_379 {  id_378  };
                                                                          ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_380;
                                                                          {
                                                                            Vec<1, uint8_t> shft_ref_195 { id_379 };
                                                                            Vec<1, Pointer> id_381 {  dsum1_snd_83  };
                                                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_382;
                                                                            {
                                                                              Vec<1, Pointer> p_ref_196 { id_381 };
                                                                              bool while_flag_383 { true };
                                                                              do {
                                                                                uint8_t id_384 { 0 };
                                                                                Pointer id_385 { p_ref_196[id_384] };
                                                                                ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_386 { id_385.readU8() };
                                                                                bool let_res_387;
                                                                                {
                                                                                  ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_197 { id_386 };
                                                                                  bool letpair_res_388;
                                                                                  {
                                                                                    auto leb128_fst_198 { std::get<0>(leb128_197) };
                                                                                    auto leb128_snd_199 { std::get<1>(leb128_197) };
                                                                                    uint8_t id_389 { 0 };
                                                                                    Void id_390 { ((void)(p_ref_196[id_389] = leb128_snd_199), ::dessser::Void()) };
                                                                                    (void)id_390;
                                                                                    uint8_t id_391 { 0 };
                                                                                    uint8_t id_392 { 127 };
                                                                                    uint8_t id_393 { uint8_t(leb128_fst_198 & id_392) };
                                                                                    uint32_t id_394 { uint32_t(id_393) };
                                                                                    uint8_t id_395 { 0 };
                                                                                    uint8_t id_396 { shft_ref_195[id_395] };
                                                                                    uint32_t id_397 { uint32_t(id_394 << id_396) };
                                                                                    uint8_t id_398 { 0 };
                                                                                    uint32_t id_399 { leb_ref_194[id_398] };
                                                                                    uint32_t id_400 { uint32_t(id_397 | id_399) };
                                                                                    Void id_401 { ((void)(leb_ref_194[id_391] = id_400), ::dessser::Void()) };
                                                                                    (void)id_401;
                                                                                    uint8_t id_402 { 0 };
                                                                                    uint8_t id_403 { 0 };
                                                                                    uint8_t id_404 { shft_ref_195[id_403] };
                                                                                    uint8_t id_405 { 7 };
                                                                                    uint8_t id_406 { uint8_t(id_404 + id_405) };
                                                                                    Void id_407 { ((void)(shft_ref_195[id_402] = id_406), ::dessser::Void()) };
                                                                                    (void)id_407;
                                                                                    uint8_t id_408 { 128 };
                                                                                    bool id_409 { bool(leb128_fst_198 >= id_408) };
                                                                                    letpair_res_388 = id_409;
                                                                                  }
                                                                                  let_res_387 = letpair_res_388;
                                                                                }
                                                                                while_flag_383 = let_res_387;
                                                                                if (while_flag_383) {
                                                                                  (void)::dessser::Void();
                                                                                }
                                                                              } while (while_flag_383);
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_410 { 0 };
                                                                              uint32_t id_411 { leb_ref_194[id_410] };
                                                                              uint8_t id_412 { 0 };
                                                                              Pointer id_413 { p_ref_196[id_412] };
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_414 { id_411, id_413 };
                                                                              let_res_382 = id_414;
                                                                            }
                                                                            let_res_380 = let_res_382;
                                                                          }
                                                                          let_res_377 = let_res_380;
                                                                        }
                                                                        ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f let_res_415;
                                                                        {
                                                                          ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 dlist1_203 { let_res_377 };
                                                                          ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f letpair_res_416;
                                                                          {
                                                                            auto dlist1_fst_204 { std::get<0>(dlist1_203) };
                                                                            auto dlist1_snd_205 { std::get<1>(dlist1_203) };
                                                                            Lst<std::shared_ptr<::dessser::gen::raql_value::t> > endoflist_417;
                                                                            ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_418 { endoflist_417, dlist1_snd_205 };
                                                                            Vec<1, ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f> id_419 {  id_418  };
                                                                            ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f let_res_420;
                                                                            {
                                                                              Vec<1, ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f> inits_src_ref_206 { id_419 };
                                                                              int32_t id_421 { 0L };
                                                                              Vec<1, int32_t> id_422 {  id_421  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_207 { id_422 };
                                                                                bool while_flag_423 { true };
                                                                                do {
                                                                                  int32_t id_424 { int32_t(dlist1_fst_204) };
                                                                                  uint8_t id_425 { 0 };
                                                                                  int32_t id_426 { repeat_n_207[id_425] };
                                                                                  bool id_427 { bool(id_424 > id_426) };
                                                                                  while_flag_423 = id_427;
                                                                                  if (while_flag_423) {
                                                                                    uint8_t id_428 { 0 };
                                                                                    ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_429 { inits_src_ref_206[id_428] };
                                                                                    {
                                                                                      ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f dlist2_208 { id_429 };
                                                                                      {
                                                                                        auto dlist2_fst_209 { std::get<0>(dlist2_208) };
                                                                                        auto dlist2_snd_210 { std::get<1>(dlist2_208) };
                                                                                        uint8_t id_430 { 0 };
                                                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_431 { fun0(dlist2_snd_210) };
                                                                                        ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f letpair_res_432;
                                                                                        {
                                                                                          auto dlist3_fst_212 { std::get<0>(id_431) };
                                                                                          auto dlist3_snd_213 { std::get<1>(id_431) };
                                                                                          Lst<std::shared_ptr<::dessser::gen::raql_value::t> > id_433 { dlist3_fst_212, dlist2_fst_209 };
                                                                                          ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_434 { id_433, dlist3_snd_213 };
                                                                                          letpair_res_432 = id_434;
                                                                                        }
                                                                                        Void id_435 { ((void)(inits_src_ref_206[id_430] = letpair_res_432), ::dessser::Void()) };
                                                                                        (void)id_435;
                                                                                      }
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_436 { 0 };
                                                                                    uint8_t id_437 { 0 };
                                                                                    int32_t id_438 { repeat_n_207[id_437] };
                                                                                    int32_t id_439 { 1L };
                                                                                    int32_t id_440 { int32_t(id_438 + id_439) };
                                                                                    Void id_441 { ((void)(repeat_n_207[id_436] = id_440), ::dessser::Void()) };
                                                                                    (void)id_441;
                                                                                    (void)id_441;
                                                                                  }
                                                                                } while (while_flag_423);
                                                                                (void)::dessser::Void();
                                                                              }
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_442 { 0 };
                                                                              ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_443 { inits_src_ref_206[id_442] };
                                                                              let_res_420 = id_443;
                                                                            }
                                                                            letpair_res_416 = let_res_420;
                                                                          }
                                                                          let_res_415 = letpair_res_416;
                                                                        }
                                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_444;
                                                                        {
                                                                          auto dlist4_fst_215 { std::get<0>(let_res_415) };
                                                                          auto dlist4_snd_216 { std::get<1>(let_res_415) };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_445 { dlist4_fst_215.toListRev() };
                                                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_446 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<31>, id_445) };
                                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_447 { id_446, dlist4_snd_216 };
                                                                          letpair_res_444 = id_447;
                                                                        }
                                                                        choose_res_374 = letpair_res_444;
                                                                      } else {
                                                                        uint16_t id_448 { 32 };
                                                                        bool id_449 { bool(id_448 == dsum1_fst_82) };
                                                                        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_450;
                                                                        if (id_449) {
                                                                          uint32_t id_451 { 0U };
                                                                          Vec<1, uint32_t> id_452 {  id_451  };
                                                                          ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_453;
                                                                          {
                                                                            Vec<1, uint32_t> leb_ref_168 { id_452 };
                                                                            uint8_t id_454 { 0 };
                                                                            Vec<1, uint8_t> id_455 {  id_454  };
                                                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_456;
                                                                            {
                                                                              Vec<1, uint8_t> shft_ref_169 { id_455 };
                                                                              Vec<1, Pointer> id_457 {  dsum1_snd_83  };
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_458;
                                                                              {
                                                                                Vec<1, Pointer> p_ref_170 { id_457 };
                                                                                bool while_flag_459 { true };
                                                                                do {
                                                                                  uint8_t id_460 { 0 };
                                                                                  Pointer id_461 { p_ref_170[id_460] };
                                                                                  ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_462 { id_461.readU8() };
                                                                                  bool let_res_463;
                                                                                  {
                                                                                    ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_171 { id_462 };
                                                                                    bool letpair_res_464;
                                                                                    {
                                                                                      auto leb128_fst_172 { std::get<0>(leb128_171) };
                                                                                      auto leb128_snd_173 { std::get<1>(leb128_171) };
                                                                                      uint8_t id_465 { 0 };
                                                                                      Void id_466 { ((void)(p_ref_170[id_465] = leb128_snd_173), ::dessser::Void()) };
                                                                                      (void)id_466;
                                                                                      uint8_t id_467 { 0 };
                                                                                      uint8_t id_468 { 127 };
                                                                                      uint8_t id_469 { uint8_t(leb128_fst_172 & id_468) };
                                                                                      uint32_t id_470 { uint32_t(id_469) };
                                                                                      uint8_t id_471 { 0 };
                                                                                      uint8_t id_472 { shft_ref_169[id_471] };
                                                                                      uint32_t id_473 { uint32_t(id_470 << id_472) };
                                                                                      uint8_t id_474 { 0 };
                                                                                      uint32_t id_475 { leb_ref_168[id_474] };
                                                                                      uint32_t id_476 { uint32_t(id_473 | id_475) };
                                                                                      Void id_477 { ((void)(leb_ref_168[id_467] = id_476), ::dessser::Void()) };
                                                                                      (void)id_477;
                                                                                      uint8_t id_478 { 0 };
                                                                                      uint8_t id_479 { 0 };
                                                                                      uint8_t id_480 { shft_ref_169[id_479] };
                                                                                      uint8_t id_481 { 7 };
                                                                                      uint8_t id_482 { uint8_t(id_480 + id_481) };
                                                                                      Void id_483 { ((void)(shft_ref_169[id_478] = id_482), ::dessser::Void()) };
                                                                                      (void)id_483;
                                                                                      uint8_t id_484 { 128 };
                                                                                      bool id_485 { bool(leb128_fst_172 >= id_484) };
                                                                                      letpair_res_464 = id_485;
                                                                                    }
                                                                                    let_res_463 = letpair_res_464;
                                                                                  }
                                                                                  while_flag_459 = let_res_463;
                                                                                  if (while_flag_459) {
                                                                                    (void)::dessser::Void();
                                                                                  }
                                                                                } while (while_flag_459);
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_486 { 0 };
                                                                                uint32_t id_487 { leb_ref_168[id_486] };
                                                                                uint8_t id_488 { 0 };
                                                                                Pointer id_489 { p_ref_170[id_488] };
                                                                                ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_490 { id_487, id_489 };
                                                                                let_res_458 = id_490;
                                                                              }
                                                                              let_res_456 = let_res_458;
                                                                            }
                                                                            let_res_453 = let_res_456;
                                                                          }
                                                                          ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f let_res_491;
                                                                          {
                                                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 dlist1_177 { let_res_453 };
                                                                            ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f letpair_res_492;
                                                                            {
                                                                              auto dlist1_fst_178 { std::get<0>(dlist1_177) };
                                                                              auto dlist1_snd_179 { std::get<1>(dlist1_177) };
                                                                              Lst<std::shared_ptr<::dessser::gen::raql_value::t> > endoflist_493;
                                                                              ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_494 { endoflist_493, dlist1_snd_179 };
                                                                              Vec<1, ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f> id_495 {  id_494  };
                                                                              ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f let_res_496;
                                                                              {
                                                                                Vec<1, ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f> inits_src_ref_180 { id_495 };
                                                                                int32_t id_497 { 0L };
                                                                                Vec<1, int32_t> id_498 {  id_497  };
                                                                                {
                                                                                  Vec<1, int32_t> repeat_n_181 { id_498 };
                                                                                  bool while_flag_499 { true };
                                                                                  do {
                                                                                    int32_t id_500 { int32_t(dlist1_fst_178) };
                                                                                    uint8_t id_501 { 0 };
                                                                                    int32_t id_502 { repeat_n_181[id_501] };
                                                                                    bool id_503 { bool(id_500 > id_502) };
                                                                                    while_flag_499 = id_503;
                                                                                    if (while_flag_499) {
                                                                                      uint8_t id_504 { 0 };
                                                                                      ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_505 { inits_src_ref_180[id_504] };
                                                                                      {
                                                                                        ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f dlist2_182 { id_505 };
                                                                                        {
                                                                                          auto dlist2_fst_183 { std::get<0>(dlist2_182) };
                                                                                          auto dlist2_snd_184 { std::get<1>(dlist2_182) };
                                                                                          uint8_t id_506 { 0 };
                                                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_507 { fun0(dlist2_snd_184) };
                                                                                          ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f letpair_res_508;
                                                                                          {
                                                                                            auto dlist3_fst_186 { std::get<0>(id_507) };
                                                                                            auto dlist3_snd_187 { std::get<1>(id_507) };
                                                                                            Lst<std::shared_ptr<::dessser::gen::raql_value::t> > id_509 { dlist3_fst_186, dlist2_fst_183 };
                                                                                            ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_510 { id_509, dlist3_snd_187 };
                                                                                            letpair_res_508 = id_510;
                                                                                          }
                                                                                          Void id_511 { ((void)(inits_src_ref_180[id_506] = letpair_res_508), ::dessser::Void()) };
                                                                                          (void)id_511;
                                                                                        }
                                                                                        (void)::dessser::Void();
                                                                                      }
                                                                                      (void)::dessser::Void();
                                                                                      uint8_t id_512 { 0 };
                                                                                      uint8_t id_513 { 0 };
                                                                                      int32_t id_514 { repeat_n_181[id_513] };
                                                                                      int32_t id_515 { 1L };
                                                                                      int32_t id_516 { int32_t(id_514 + id_515) };
                                                                                      Void id_517 { ((void)(repeat_n_181[id_512] = id_516), ::dessser::Void()) };
                                                                                      (void)id_517;
                                                                                      (void)id_517;
                                                                                    }
                                                                                  } while (while_flag_499);
                                                                                  (void)::dessser::Void();
                                                                                }
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_518 { 0 };
                                                                                ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_519 { inits_src_ref_180[id_518] };
                                                                                let_res_496 = id_519;
                                                                              }
                                                                              letpair_res_492 = let_res_496;
                                                                            }
                                                                            let_res_491 = letpair_res_492;
                                                                          }
                                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_520;
                                                                          {
                                                                            auto dlist4_fst_189 { std::get<0>(let_res_491) };
                                                                            auto dlist4_snd_190 { std::get<1>(let_res_491) };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_521 { dlist4_fst_189.toListRev() };
                                                                            std::shared_ptr<::dessser::gen::raql_value::t>  id_522 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<32>, id_521) };
                                                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_523 { id_522, dlist4_snd_190 };
                                                                            letpair_res_520 = id_523;
                                                                          }
                                                                          choose_res_450 = letpair_res_520;
                                                                        } else {
                                                                          uint16_t id_524 { 33 };
                                                                          bool id_525 { bool(id_524 == dsum1_fst_82) };
                                                                          ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_526;
                                                                          if (id_525) {
                                                                            uint32_t id_527 { 0U };
                                                                            Vec<1, uint32_t> id_528 {  id_527  };
                                                                            ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_529;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_142 { id_528 };
                                                                              uint8_t id_530 { 0 };
                                                                              Vec<1, uint8_t> id_531 {  id_530  };
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_532;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_143 { id_531 };
                                                                                Vec<1, Pointer> id_533 {  dsum1_snd_83  };
                                                                                ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_534;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_144 { id_533 };
                                                                                  bool while_flag_535 { true };
                                                                                  do {
                                                                                    uint8_t id_536 { 0 };
                                                                                    Pointer id_537 { p_ref_144[id_536] };
                                                                                    ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_538 { id_537.readU8() };
                                                                                    bool let_res_539;
                                                                                    {
                                                                                      ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_145 { id_538 };
                                                                                      bool letpair_res_540;
                                                                                      {
                                                                                        auto leb128_fst_146 { std::get<0>(leb128_145) };
                                                                                        auto leb128_snd_147 { std::get<1>(leb128_145) };
                                                                                        uint8_t id_541 { 0 };
                                                                                        Void id_542 { ((void)(p_ref_144[id_541] = leb128_snd_147), ::dessser::Void()) };
                                                                                        (void)id_542;
                                                                                        uint8_t id_543 { 0 };
                                                                                        uint8_t id_544 { 127 };
                                                                                        uint8_t id_545 { uint8_t(leb128_fst_146 & id_544) };
                                                                                        uint32_t id_546 { uint32_t(id_545) };
                                                                                        uint8_t id_547 { 0 };
                                                                                        uint8_t id_548 { shft_ref_143[id_547] };
                                                                                        uint32_t id_549 { uint32_t(id_546 << id_548) };
                                                                                        uint8_t id_550 { 0 };
                                                                                        uint32_t id_551 { leb_ref_142[id_550] };
                                                                                        uint32_t id_552 { uint32_t(id_549 | id_551) };
                                                                                        Void id_553 { ((void)(leb_ref_142[id_543] = id_552), ::dessser::Void()) };
                                                                                        (void)id_553;
                                                                                        uint8_t id_554 { 0 };
                                                                                        uint8_t id_555 { 0 };
                                                                                        uint8_t id_556 { shft_ref_143[id_555] };
                                                                                        uint8_t id_557 { 7 };
                                                                                        uint8_t id_558 { uint8_t(id_556 + id_557) };
                                                                                        Void id_559 { ((void)(shft_ref_143[id_554] = id_558), ::dessser::Void()) };
                                                                                        (void)id_559;
                                                                                        uint8_t id_560 { 128 };
                                                                                        bool id_561 { bool(leb128_fst_146 >= id_560) };
                                                                                        letpair_res_540 = id_561;
                                                                                      }
                                                                                      let_res_539 = letpair_res_540;
                                                                                    }
                                                                                    while_flag_535 = let_res_539;
                                                                                    if (while_flag_535) {
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                  } while (while_flag_535);
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_562 { 0 };
                                                                                  uint32_t id_563 { leb_ref_142[id_562] };
                                                                                  uint8_t id_564 { 0 };
                                                                                  Pointer id_565 { p_ref_144[id_564] };
                                                                                  ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_566 { id_563, id_565 };
                                                                                  let_res_534 = id_566;
                                                                                }
                                                                                let_res_532 = let_res_534;
                                                                              }
                                                                              let_res_529 = let_res_532;
                                                                            }
                                                                            ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f let_res_567;
                                                                            {
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 dlist1_151 { let_res_529 };
                                                                              ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f letpair_res_568;
                                                                              {
                                                                                auto dlist1_fst_152 { std::get<0>(dlist1_151) };
                                                                                auto dlist1_snd_153 { std::get<1>(dlist1_151) };
                                                                                Lst<std::shared_ptr<::dessser::gen::raql_value::t> > endoflist_569;
                                                                                ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_570 { endoflist_569, dlist1_snd_153 };
                                                                                Vec<1, ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f> id_571 {  id_570  };
                                                                                ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f let_res_572;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f> inits_src_ref_154 { id_571 };
                                                                                  int32_t id_573 { 0L };
                                                                                  Vec<1, int32_t> id_574 {  id_573  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_155 { id_574 };
                                                                                    bool while_flag_575 { true };
                                                                                    do {
                                                                                      int32_t id_576 { int32_t(dlist1_fst_152) };
                                                                                      uint8_t id_577 { 0 };
                                                                                      int32_t id_578 { repeat_n_155[id_577] };
                                                                                      bool id_579 { bool(id_576 > id_578) };
                                                                                      while_flag_575 = id_579;
                                                                                      if (while_flag_575) {
                                                                                        uint8_t id_580 { 0 };
                                                                                        ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_581 { inits_src_ref_154[id_580] };
                                                                                        {
                                                                                          ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f dlist2_156 { id_581 };
                                                                                          {
                                                                                            auto dlist2_fst_157 { std::get<0>(dlist2_156) };
                                                                                            auto dlist2_snd_158 { std::get<1>(dlist2_156) };
                                                                                            uint8_t id_582 { 0 };
                                                                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_583 { fun0(dlist2_snd_158) };
                                                                                            ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f letpair_res_584;
                                                                                            {
                                                                                              auto dlist3_fst_160 { std::get<0>(id_583) };
                                                                                              auto dlist3_snd_161 { std::get<1>(id_583) };
                                                                                              Lst<std::shared_ptr<::dessser::gen::raql_value::t> > id_585 { dlist3_fst_160, dlist2_fst_157 };
                                                                                              ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_586 { id_585, dlist3_snd_161 };
                                                                                              letpair_res_584 = id_586;
                                                                                            }
                                                                                            Void id_587 { ((void)(inits_src_ref_154[id_582] = letpair_res_584), ::dessser::Void()) };
                                                                                            (void)id_587;
                                                                                          }
                                                                                          (void)::dessser::Void();
                                                                                        }
                                                                                        (void)::dessser::Void();
                                                                                        uint8_t id_588 { 0 };
                                                                                        uint8_t id_589 { 0 };
                                                                                        int32_t id_590 { repeat_n_155[id_589] };
                                                                                        int32_t id_591 { 1L };
                                                                                        int32_t id_592 { int32_t(id_590 + id_591) };
                                                                                        Void id_593 { ((void)(repeat_n_155[id_588] = id_592), ::dessser::Void()) };
                                                                                        (void)id_593;
                                                                                        (void)id_593;
                                                                                      }
                                                                                    } while (while_flag_575);
                                                                                    (void)::dessser::Void();
                                                                                  }
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_594 { 0 };
                                                                                  ::dessser::gen::raql_value::td7923d3f6d8f6add6849bd1b0a41351f id_595 { inits_src_ref_154[id_594] };
                                                                                  let_res_572 = id_595;
                                                                                }
                                                                                letpair_res_568 = let_res_572;
                                                                              }
                                                                              let_res_567 = letpair_res_568;
                                                                            }
                                                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_596;
                                                                            {
                                                                              auto dlist4_fst_163 { std::get<0>(let_res_567) };
                                                                              auto dlist4_snd_164 { std::get<1>(let_res_567) };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_597 { dlist4_fst_163.toListRev() };
                                                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_598 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<33>, id_597) };
                                                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_599 { id_598, dlist4_snd_164 };
                                                                              letpair_res_596 = id_599;
                                                                            }
                                                                            choose_res_526 = letpair_res_596;
                                                                          } else {
                                                                            uint16_t id_600 { 34 };
                                                                            bool id_601 { bool(id_600 == dsum1_fst_82) };
                                                                            ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e choose_res_602;
                                                                            if (id_601) {
                                                                              uint32_t id_603 { 0U };
                                                                              Vec<1, uint32_t> id_604 {  id_603  };
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_605;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_116 { id_604 };
                                                                                uint8_t id_606 { 0 };
                                                                                Vec<1, uint8_t> id_607 {  id_606  };
                                                                                ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_608;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_117 { id_607 };
                                                                                  Vec<1, Pointer> id_609 {  dsum1_snd_83  };
                                                                                  ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_610;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_118 { id_609 };
                                                                                    bool while_flag_611 { true };
                                                                                    do {
                                                                                      uint8_t id_612 { 0 };
                                                                                      Pointer id_613 { p_ref_118[id_612] };
                                                                                      ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_614 { id_613.readU8() };
                                                                                      bool let_res_615;
                                                                                      {
                                                                                        ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_119 { id_614 };
                                                                                        bool letpair_res_616;
                                                                                        {
                                                                                          auto leb128_fst_120 { std::get<0>(leb128_119) };
                                                                                          auto leb128_snd_121 { std::get<1>(leb128_119) };
                                                                                          uint8_t id_617 { 0 };
                                                                                          Void id_618 { ((void)(p_ref_118[id_617] = leb128_snd_121), ::dessser::Void()) };
                                                                                          (void)id_618;
                                                                                          uint8_t id_619 { 0 };
                                                                                          uint8_t id_620 { 127 };
                                                                                          uint8_t id_621 { uint8_t(leb128_fst_120 & id_620) };
                                                                                          uint32_t id_622 { uint32_t(id_621) };
                                                                                          uint8_t id_623 { 0 };
                                                                                          uint8_t id_624 { shft_ref_117[id_623] };
                                                                                          uint32_t id_625 { uint32_t(id_622 << id_624) };
                                                                                          uint8_t id_626 { 0 };
                                                                                          uint32_t id_627 { leb_ref_116[id_626] };
                                                                                          uint32_t id_628 { uint32_t(id_625 | id_627) };
                                                                                          Void id_629 { ((void)(leb_ref_116[id_619] = id_628), ::dessser::Void()) };
                                                                                          (void)id_629;
                                                                                          uint8_t id_630 { 0 };
                                                                                          uint8_t id_631 { 0 };
                                                                                          uint8_t id_632 { shft_ref_117[id_631] };
                                                                                          uint8_t id_633 { 7 };
                                                                                          uint8_t id_634 { uint8_t(id_632 + id_633) };
                                                                                          Void id_635 { ((void)(shft_ref_117[id_630] = id_634), ::dessser::Void()) };
                                                                                          (void)id_635;
                                                                                          uint8_t id_636 { 128 };
                                                                                          bool id_637 { bool(leb128_fst_120 >= id_636) };
                                                                                          letpair_res_616 = id_637;
                                                                                        }
                                                                                        let_res_615 = letpair_res_616;
                                                                                      }
                                                                                      while_flag_611 = let_res_615;
                                                                                      if (while_flag_611) {
                                                                                        (void)::dessser::Void();
                                                                                      }
                                                                                    } while (while_flag_611);
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_638 { 0 };
                                                                                    uint32_t id_639 { leb_ref_116[id_638] };
                                                                                    uint8_t id_640 { 0 };
                                                                                    Pointer id_641 { p_ref_118[id_640] };
                                                                                    ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_642 { id_639, id_641 };
                                                                                    let_res_610 = id_642;
                                                                                  }
                                                                                  let_res_608 = let_res_610;
                                                                                }
                                                                                let_res_605 = let_res_608;
                                                                              }
                                                                              ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e let_res_643;
                                                                              {
                                                                                ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 dlist1_125 { let_res_605 };
                                                                                ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e letpair_res_644;
                                                                                {
                                                                                  auto dlist1_fst_126 { std::get<0>(dlist1_125) };
                                                                                  auto dlist1_snd_127 { std::get<1>(dlist1_125) };
                                                                                  Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> > endoflist_645;
                                                                                  ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e id_646 { endoflist_645, dlist1_snd_127 };
                                                                                  Vec<1, ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e> id_647 {  id_646  };
                                                                                  ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e let_res_648;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e> inits_src_ref_128 { id_647 };
                                                                                    int32_t id_649 { 0L };
                                                                                    Vec<1, int32_t> id_650 {  id_649  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_129 { id_650 };
                                                                                      bool while_flag_651 { true };
                                                                                      do {
                                                                                        int32_t id_652 { int32_t(dlist1_fst_126) };
                                                                                        uint8_t id_653 { 0 };
                                                                                        int32_t id_654 { repeat_n_129[id_653] };
                                                                                        bool id_655 { bool(id_652 > id_654) };
                                                                                        while_flag_651 = id_655;
                                                                                        if (while_flag_651) {
                                                                                          uint8_t id_656 { 0 };
                                                                                          ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e id_657 { inits_src_ref_128[id_656] };
                                                                                          {
                                                                                            ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e dlist2_130 { id_657 };
                                                                                            {
                                                                                              auto dlist2_fst_131 { std::get<0>(dlist2_130) };
                                                                                              auto dlist2_snd_132 { std::get<1>(dlist2_130) };
                                                                                              uint8_t id_658 { 0 };
                                                                                              ::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a id_659 { named_value_of_row_binary(dlist2_snd_132) };
                                                                                              ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e letpair_res_660;
                                                                                              {
                                                                                                auto dlist3_fst_134 { std::get<0>(id_659) };
                                                                                                auto dlist3_snd_135 { std::get<1>(id_659) };
                                                                                                Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_661 { dlist3_fst_134, dlist2_fst_131 };
                                                                                                ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e id_662 { id_661, dlist3_snd_135 };
                                                                                                letpair_res_660 = id_662;
                                                                                              }
                                                                                              Void id_663 { ((void)(inits_src_ref_128[id_658] = letpair_res_660), ::dessser::Void()) };
                                                                                              (void)id_663;
                                                                                            }
                                                                                            (void)::dessser::Void();
                                                                                          }
                                                                                          (void)::dessser::Void();
                                                                                          uint8_t id_664 { 0 };
                                                                                          uint8_t id_665 { 0 };
                                                                                          int32_t id_666 { repeat_n_129[id_665] };
                                                                                          int32_t id_667 { 1L };
                                                                                          int32_t id_668 { int32_t(id_666 + id_667) };
                                                                                          Void id_669 { ((void)(repeat_n_129[id_664] = id_668), ::dessser::Void()) };
                                                                                          (void)id_669;
                                                                                          (void)id_669;
                                                                                        }
                                                                                      } while (while_flag_651);
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_670 { 0 };
                                                                                    ::dessser::gen::raql_value::t7edef2aa82c167066e365042d8a9a97e id_671 { inits_src_ref_128[id_670] };
                                                                                    let_res_648 = id_671;
                                                                                  }
                                                                                  letpair_res_644 = let_res_648;
                                                                                }
                                                                                let_res_643 = letpair_res_644;
                                                                              }
                                                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_672;
                                                                              {
                                                                                auto dlist4_fst_137 { std::get<0>(let_res_643) };
                                                                                auto dlist4_snd_138 { std::get<1>(let_res_643) };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_673 { dlist4_fst_137.toListRev() };
                                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_674 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<34>, id_673) };
                                                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_675 { id_674, dlist4_snd_138 };
                                                                                letpair_res_672 = id_675;
                                                                              }
                                                                              choose_res_602 = letpair_res_672;
                                                                            } else {
                                                                              uint16_t id_676 { 35 };
                                                                              bool id_677 { bool(dsum1_fst_82 == id_676) };
                                                                              Void id_678 { ((void)(assert(id_677)), ::dessser::Void()) };
                                                                              (void)id_678;
                                                                              uint32_t id_679 { 0U };
                                                                              Vec<1, uint32_t> id_680 {  id_679  };
                                                                              ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_681;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_84 { id_680 };
                                                                                uint8_t id_682 { 0 };
                                                                                Vec<1, uint8_t> id_683 {  id_682  };
                                                                                ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_684;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_85 { id_683 };
                                                                                  Vec<1, Pointer> id_685 {  dsum1_snd_83  };
                                                                                  ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 let_res_686;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_86 { id_685 };
                                                                                    bool while_flag_687 { true };
                                                                                    do {
                                                                                      uint8_t id_688 { 0 };
                                                                                      Pointer id_689 { p_ref_86[id_688] };
                                                                                      ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_690 { id_689.readU8() };
                                                                                      bool let_res_691;
                                                                                      {
                                                                                        ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_87 { id_690 };
                                                                                        bool letpair_res_692;
                                                                                        {
                                                                                          auto leb128_fst_88 { std::get<0>(leb128_87) };
                                                                                          auto leb128_snd_89 { std::get<1>(leb128_87) };
                                                                                          uint8_t id_693 { 0 };
                                                                                          Void id_694 { ((void)(p_ref_86[id_693] = leb128_snd_89), ::dessser::Void()) };
                                                                                          (void)id_694;
                                                                                          uint8_t id_695 { 0 };
                                                                                          uint8_t id_696 { 127 };
                                                                                          uint8_t id_697 { uint8_t(leb128_fst_88 & id_696) };
                                                                                          uint32_t id_698 { uint32_t(id_697) };
                                                                                          uint8_t id_699 { 0 };
                                                                                          uint8_t id_700 { shft_ref_85[id_699] };
                                                                                          uint32_t id_701 { uint32_t(id_698 << id_700) };
                                                                                          uint8_t id_702 { 0 };
                                                                                          uint32_t id_703 { leb_ref_84[id_702] };
                                                                                          uint32_t id_704 { uint32_t(id_701 | id_703) };
                                                                                          Void id_705 { ((void)(leb_ref_84[id_695] = id_704), ::dessser::Void()) };
                                                                                          (void)id_705;
                                                                                          uint8_t id_706 { 0 };
                                                                                          uint8_t id_707 { 0 };
                                                                                          uint8_t id_708 { shft_ref_85[id_707] };
                                                                                          uint8_t id_709 { 7 };
                                                                                          uint8_t id_710 { uint8_t(id_708 + id_709) };
                                                                                          Void id_711 { ((void)(shft_ref_85[id_706] = id_710), ::dessser::Void()) };
                                                                                          (void)id_711;
                                                                                          uint8_t id_712 { 128 };
                                                                                          bool id_713 { bool(leb128_fst_88 >= id_712) };
                                                                                          letpair_res_692 = id_713;
                                                                                        }
                                                                                        let_res_691 = letpair_res_692;
                                                                                      }
                                                                                      while_flag_687 = let_res_691;
                                                                                      if (while_flag_687) {
                                                                                        (void)::dessser::Void();
                                                                                      }
                                                                                    } while (while_flag_687);
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_714 { 0 };
                                                                                    uint32_t id_715 { leb_ref_84[id_714] };
                                                                                    uint8_t id_716 { 0 };
                                                                                    Pointer id_717 { p_ref_86[id_716] };
                                                                                    ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 id_718 { id_715, id_717 };
                                                                                    let_res_686 = id_718;
                                                                                  }
                                                                                  let_res_684 = let_res_686;
                                                                                }
                                                                                let_res_681 = let_res_684;
                                                                              }
                                                                              ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 let_res_719;
                                                                              {
                                                                                ::dessser::gen::raql_value::t491c44439106a32f896827242e8e76a1 dlist1_93 { let_res_681 };
                                                                                ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 letpair_res_720;
                                                                                {
                                                                                  auto dlist1_fst_94 { std::get<0>(dlist1_93) };
                                                                                  auto dlist1_snd_95 { std::get<1>(dlist1_93) };
                                                                                  Lst<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> endoflist_721;
                                                                                  ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 id_722 { endoflist_721, dlist1_snd_95 };
                                                                                  Vec<1, ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4> id_723 {  id_722  };
                                                                                  ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 let_res_724;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4> inits_src_ref_96 { id_723 };
                                                                                    int32_t id_725 { 0L };
                                                                                    Vec<1, int32_t> id_726 {  id_725  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_97 { id_726 };
                                                                                      bool while_flag_727 { true };
                                                                                      do {
                                                                                        int32_t id_728 { int32_t(dlist1_fst_94) };
                                                                                        uint8_t id_729 { 0 };
                                                                                        int32_t id_730 { repeat_n_97[id_729] };
                                                                                        bool id_731 { bool(id_728 > id_730) };
                                                                                        while_flag_727 = id_731;
                                                                                        if (while_flag_727) {
                                                                                          uint8_t id_732 { 0 };
                                                                                          ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 id_733 { inits_src_ref_96[id_732] };
                                                                                          {
                                                                                            ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 dlist2_98 { id_733 };
                                                                                            {
                                                                                              auto dlist2_fst_99 { std::get<0>(dlist2_98) };
                                                                                              auto dlist2_snd_100 { std::get<1>(dlist2_98) };
                                                                                              uint8_t id_734 { 0 };
                                                                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_735 { fun0(dlist2_snd_100) };
                                                                                              ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 letpair_res_736;
                                                                                              {
                                                                                                auto dtup_fst_102 { std::get<0>(id_735) };
                                                                                                auto dtup_snd_103 { std::get<1>(id_735) };
                                                                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_737 { fun0(dtup_snd_103) };
                                                                                                ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 letpair_res_738;
                                                                                                {
                                                                                                  auto dtup_fst_105 { std::get<0>(id_737) };
                                                                                                  auto dtup_snd_106 { std::get<1>(id_737) };
                                                                                                  ::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f id_739 { dtup_fst_102, dtup_fst_105 };
                                                                                                  Lst<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_740 { id_739, dlist2_fst_99 };
                                                                                                  ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 id_741 { id_740, dtup_snd_106 };
                                                                                                  letpair_res_738 = id_741;
                                                                                                }
                                                                                                letpair_res_736 = letpair_res_738;
                                                                                              }
                                                                                              Void id_742 { ((void)(inits_src_ref_96[id_734] = letpair_res_736), ::dessser::Void()) };
                                                                                              (void)id_742;
                                                                                            }
                                                                                            (void)::dessser::Void();
                                                                                          }
                                                                                          (void)::dessser::Void();
                                                                                          uint8_t id_743 { 0 };
                                                                                          uint8_t id_744 { 0 };
                                                                                          int32_t id_745 { repeat_n_97[id_744] };
                                                                                          int32_t id_746 { 1L };
                                                                                          int32_t id_747 { int32_t(id_745 + id_746) };
                                                                                          Void id_748 { ((void)(repeat_n_97[id_743] = id_747), ::dessser::Void()) };
                                                                                          (void)id_748;
                                                                                          (void)id_748;
                                                                                        }
                                                                                      } while (while_flag_727);
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_749 { 0 };
                                                                                    ::dessser::gen::raql_value::t217cee98ec313f21a12369fd1762c5c4 id_750 { inits_src_ref_96[id_749] };
                                                                                    let_res_724 = id_750;
                                                                                  }
                                                                                  letpair_res_720 = let_res_724;
                                                                                }
                                                                                let_res_719 = letpair_res_720;
                                                                              }
                                                                              ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_751;
                                                                              {
                                                                                auto dlist4_fst_111 { std::get<0>(let_res_719) };
                                                                                auto dlist4_snd_112 { std::get<1>(let_res_719) };
                                                                                Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_752 { dlist4_fst_111.toListRev() };
                                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_753 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<35>, id_752) };
                                                                                ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_754 { id_753, dlist4_snd_112 };
                                                                                letpair_res_751 = id_754;
                                                                              }
                                                                              choose_res_602 = letpair_res_751;
                                                                            }
                                                                            choose_res_526 = choose_res_602;
                                                                          }
                                                                          choose_res_450 = choose_res_526;
                                                                        }
                                                                        choose_res_374 = choose_res_450;
                                                                      }
                                                                      choose_res_327 = choose_res_374;
                                                                    }
                                                                    choose_res_310 = choose_res_327;
                                                                  }
                                                                  choose_res_293 = choose_res_310;
                                                                }
                                                                choose_res_262 = choose_res_293;
                                                              }
                                                              choose_res_253 = choose_res_262;
                                                            }
                                                            choose_res_244 = choose_res_253;
                                                          }
                                                          choose_res_234 = choose_res_244;
                                                        }
                                                        choose_res_226 = choose_res_234;
                                                      }
                                                      choose_res_218 = choose_res_226;
                                                    }
                                                    choose_res_210 = choose_res_218;
                                                  }
                                                  choose_res_202 = choose_res_210;
                                                }
                                                choose_res_194 = choose_res_202;
                                              }
                                              choose_res_186 = choose_res_194;
                                            }
                                            choose_res_178 = choose_res_186;
                                          }
                                          choose_res_170 = choose_res_178;
                                        }
                                        choose_res_162 = choose_res_170;
                                      }
                                      choose_res_155 = choose_res_162;
                                    }
                                    choose_res_148 = choose_res_155;
                                  }
                                  choose_res_140 = choose_res_148;
                                }
                                choose_res_132 = choose_res_140;
                              }
                              choose_res_124 = choose_res_132;
                            }
                            choose_res_117 = choose_res_124;
                          }
                          choose_res_109 = choose_res_117;
                        }
                        choose_res_102 = choose_res_109;
                      }
                      choose_res_95 = choose_res_102;
                    }
                    choose_res_87 = choose_res_95;
                  }
                  choose_res_77 = choose_res_87;
                }
                choose_res_26 = choose_res_77;
              }
              choose_res_18 = choose_res_26;
            }
            choose_res_13 = choose_res_18;
          }
          choose_res_8 = choose_res_13;
        }
        letpair_res_5 = choose_res_8;
      }
      let_res_4 = letpair_res_5;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> of_row_binary(of_row_binary_init());

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
static std::function<::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a(Pointer)> named_value_of_row_binary_init()
{
  std::function<::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a(Pointer)> fun755 { [&](Pointer p_0) {
    uint32_t id_756 { 0U };
    Vec<1, uint32_t> id_757 {  id_756  };
    ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa let_res_758;
    {
      Vec<1, uint32_t> leb_ref_57 { id_757 };
      uint8_t id_759 { 0 };
      Vec<1, uint8_t> id_760 {  id_759  };
      ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa let_res_761;
      {
        Vec<1, uint8_t> shft_ref_58 { id_760 };
        Vec<1, Pointer> id_762 {  p_0  };
        ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa let_res_763;
        {
          Vec<1, Pointer> p_ref_59 { id_762 };
          bool while_flag_764 { true };
          do {
            uint8_t id_765 { 0 };
            Pointer id_766 { p_ref_59[id_765] };
            ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 id_767 { id_766.readU8() };
            bool let_res_768;
            {
              ::dessser::gen::raql_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_60 { id_767 };
              bool letpair_res_769;
              {
                auto leb128_fst_61 { std::get<0>(leb128_60) };
                auto leb128_snd_62 { std::get<1>(leb128_60) };
                uint8_t id_770 { 0 };
                Void id_771 { ((void)(p_ref_59[id_770] = leb128_snd_62), ::dessser::Void()) };
                (void)id_771;
                uint8_t id_772 { 0 };
                uint8_t id_773 { 127 };
                uint8_t id_774 { uint8_t(leb128_fst_61 & id_773) };
                uint32_t id_775 { uint32_t(id_774) };
                uint8_t id_776 { 0 };
                uint8_t id_777 { shft_ref_58[id_776] };
                uint32_t id_778 { uint32_t(id_775 << id_777) };
                uint8_t id_779 { 0 };
                uint32_t id_780 { leb_ref_57[id_779] };
                uint32_t id_781 { uint32_t(id_778 | id_780) };
                Void id_782 { ((void)(leb_ref_57[id_772] = id_781), ::dessser::Void()) };
                (void)id_782;
                uint8_t id_783 { 0 };
                uint8_t id_784 { 0 };
                uint8_t id_785 { shft_ref_58[id_784] };
                uint8_t id_786 { 7 };
                uint8_t id_787 { uint8_t(id_785 + id_786) };
                Void id_788 { ((void)(shft_ref_58[id_783] = id_787), ::dessser::Void()) };
                (void)id_788;
                uint8_t id_789 { 128 };
                bool id_790 { bool(leb128_fst_61 >= id_789) };
                letpair_res_769 = id_790;
              }
              let_res_768 = letpair_res_769;
            }
            while_flag_764 = let_res_768;
            if (while_flag_764) {
              (void)::dessser::Void();
            }
          } while (while_flag_764);
          (void)::dessser::Void();
          uint8_t id_791 { 0 };
          uint32_t id_792 { leb_ref_57[id_791] };
          Size id_793 { Size(id_792) };
          uint8_t id_794 { 0 };
          Pointer id_795 { p_ref_59[id_794] };
          ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa id_796 { id_793, id_795 };
          let_res_763 = id_796;
        }
        let_res_761 = let_res_763;
      }
      let_res_758 = let_res_761;
    }
    ::dessser::gen::raql_value::t13a07ee37ab40962540da8534858dc07 let_res_797;
    {
      ::dessser::gen::raql_value::t12fb9c475959b52bf7b17b155a955ffa dstring1_63 { let_res_758 };
      ::dessser::gen::raql_value::t13a07ee37ab40962540da8534858dc07 letpair_res_798;
      {
        auto dstring1_fst_64 { std::get<0>(dstring1_63) };
        auto dstring1_snd_65 { std::get<1>(dstring1_63) };
        ::dessser::gen::raql_value::t9ef6882174ae71a34a3c5ef6b29242fb id_799 { dstring1_snd_65.readBytes(dstring1_fst_64) };
        ::dessser::gen::raql_value::t13a07ee37ab40962540da8534858dc07 letpair_res_800;
        {
          auto dstring2_fst_67 { std::get<0>(id_799) };
          auto dstring2_snd_68 { std::get<1>(id_799) };
          std::string id_801 { dstring2_fst_67.toString() };
          ::dessser::gen::raql_value::t13a07ee37ab40962540da8534858dc07 id_802 { id_801, dstring2_snd_68 };
          letpair_res_800 = id_802;
        }
        letpair_res_798 = letpair_res_800;
      }
      let_res_797 = letpair_res_798;
    }
    ::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a let_res_803;
    {
      ::dessser::gen::raql_value::t13a07ee37ab40962540da8534858dc07 dtup_69 { let_res_797 };
      ::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a letpair_res_804;
      {
        auto dtup_fst_70 { std::get<0>(dtup_69) };
        auto dtup_snd_71 { std::get<1>(dtup_69) };
        ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_805 { of_row_binary(dtup_snd_71) };
        ::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a letpair_res_806;
        {
          auto dtup_fst_73 { std::get<0>(id_805) };
          auto dtup_snd_74 { std::get<1>(id_805) };
          std::shared_ptr<::dessser::gen::raql_value::named_value>  id_807 { std::make_shared<::dessser::gen::raql_value::named_value>(dtup_fst_70, dtup_fst_73) };
          ::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a id_808 { id_807, dtup_snd_74 };
          letpair_res_806 = id_808;
        }
        letpair_res_804 = letpair_res_806;
      }
      let_res_803 = letpair_res_804;
    }
    return let_res_803;
  }
   };
  return fun755;
}
std::function<::dessser::gen::raql_value::t9f25ed50c831f0d73db2f922456ab51a(Pointer)> named_value_of_row_binary(named_value_of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_527" "make_snd_528" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_527") (identifier "make_snd_528"))))
 */
static std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> fun809 { [&](Pointer p_0) {
    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_810 { of_row_binary(p_0) };
    ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e letpair_res_811;
    {
      auto make_fst_527 { std::get<0>(id_810) };
      auto make_snd_528 { std::get<1>(id_810) };
      ::dessser::gen::raql_value::t154914fa186327343906567bc094f08e id_812 { make_fst_527, make_snd_528 };
      letpair_res_811 = id_812;
    }
    return letpair_res_811;
  }
   };
  return fun809;
}
std::function<::dessser::gen::raql_value::t154914fa186327343906567bc094f08e(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]")
      (let "label2_534" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_534")) (size 2)
          (if (eq (u16 1) (identifier "label2_534")) (size 2)
            (if (eq (u16 2) (identifier "label2_534")) (size 10)
              (if (eq (u16 3) (identifier "label2_534"))
                (add (size 2)
                  (add
                    (let "n_ref_568" (make-vec (string-length (get-alt "VString" (param 0))))
                      (let "lebsz_ref_569" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_568")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_569")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_569") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_569")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_569")))))) 
                    (size-of-u32 (string-length (get-alt "VString" (param 0))))))
                (if (eq (u16 4) (identifier "label2_534")) (size 3)
                  (if (eq (u16 5) (identifier "label2_534")) (size 3)
                    (if (eq (u16 6) (identifier "label2_534")) (size 3)
                      (if (eq (u16 7) (identifier "label2_534")) (size 4)
                        (if (eq (u16 8) (identifier "label2_534")) (size 6)
                          (if (eq (u16 9) (identifier "label2_534")) 
                            (size 6)
                            (if (eq (u16 10) (identifier "label2_534")) 
                              (size 10)
                              (if (eq (u16 11) (identifier "label2_534")) 
                                (size 10)
                                (if (eq (u16 12) (identifier "label2_534")) 
                                  (size 10)
                                  (if (eq (u16 13) (identifier "label2_534")) 
                                    (size 10)
                                    (if (eq (u16 14) (identifier "label2_534")) 
                                      (size 18)
                                      (if (eq (u16 15) (identifier "label2_534")) 
                                        (size 3)
                                        (if (eq (u16 16) (identifier "label2_534")) 
                                          (size 4)
                                          (if (eq (u16 17) (identifier "label2_534")) 
                                            (size 6)
                                            (if (eq (u16 18) (identifier "label2_534")) 
                                              (size 6)
                                              (if (eq (u16 19) (identifier "label2_534")) 
                                                (size 10)
                                                (if (eq (u16 20) (identifier "label2_534")) 
                                                  (size 10)
                                                  (if (eq (u16 21) (identifier "label2_534")) 
                                                    (size 10)
                                                    (if (eq (u16 22) (identifier "label2_534")) 
                                                      (size 10)
                                                      (if (eq (u16 23) (identifier "label2_534")) 
                                                        (size 18)
                                                        (if (eq (u16 24) (identifier "label2_534")) 
                                                          (size 10)
                                                          (if (eq (u16 25) (identifier "label2_534")) 
                                                            (size 6)
                                                            (if (eq (u16 26) (identifier "label2_534")) 
                                                              (size 18)
                                                              (if (eq (u16 27) (identifier "label2_534"))
                                                                (if (eq (u16 0) (label-of (get-alt "VIp" (param 0)))) (size 8) (seq (assert (eq (label-of (get-alt "VIp" (param 0))) (u16 1))) (size 20)))
                                                                (if (eq (u16 28) (identifier "label2_534")) 
                                                                  (size 7)
                                                                  (if 
                                                                    (eq (u16 29) (identifier "label2_534")) 
                                                                    (size 19)
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_534"))
                                                                    (if (eq (u16 0) (label-of (get-alt "VCidr" (param 0)))) (size 9) (seq (assert (eq (label-of (get-alt "VCidr" (param 0))) (u16 1))) (size 21)))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_534"))
                                                                    (let "sz_ref_555"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_553" 
                                                                    (make-vec (cardinality (get-alt "VTup" (param 0))))
                                                                    (let "lebsz_ref_554" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_553")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_554")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_554") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_554")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_554"))))))))
                                                                    (seq
                                                                    (let "repeat_n_556" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VTup" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_556")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_555")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_555")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_556")) (get-alt "VTup" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_556") (add (unsafe-nth (u8 0) (identifier "repeat_n_556")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_555"))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_534"))
                                                                    (let "sz_ref_551"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_549" 
                                                                    (make-vec (cardinality (get-alt "VVec" (param 0))))
                                                                    (let "lebsz_ref_550" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_549")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_550")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_550") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_550")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_550"))))))))
                                                                    (seq
                                                                    (let "repeat_n_552" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VVec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_552")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_551")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_551")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_552")) (get-alt "VVec" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_552") (add (unsafe-nth (u8 0) (identifier "repeat_n_552")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_551"))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_534"))
                                                                    (let "sz_ref_547"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_545" 
                                                                    (make-vec (cardinality (get-alt "VArr" (param 0))))
                                                                    (let "lebsz_ref_546" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_545")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_546")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_546") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_546")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_546"))))))))
                                                                    (seq
                                                                    (let "repeat_n_548" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VArr" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_548")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_547")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_547")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_548")) (get-alt "VArr" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_548") (add (unsafe-nth (u8 0) (identifier "repeat_n_548")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_547"))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_534"))
                                                                    (let "sz_ref_543"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_541" 
                                                                    (make-vec (cardinality (get-alt "VRec" (param 0))))
                                                                    (let "lebsz_ref_542" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_541")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_542")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_542") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_542")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_542"))))))))
                                                                    (seq
                                                                    (let "repeat_n_544" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VRec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_544")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_543")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_543"))
                                                                    (apply (identifier "named_value-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_544")) (get-alt "VRec" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_544") (add (unsafe-nth (u8 0) (identifier "repeat_n_544")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_543"))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label2_534") (u16 35)))
                                                                    (let "sz_ref_537"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_535" 
                                                                    (make-vec (cardinality (get-alt "VMap" (param 0))))
                                                                    (let "lebsz_ref_536" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_535")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_536")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_536") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_536")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_536"))))))))
                                                                    (seq
                                                                    (let "repeat_n_538" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VMap" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_538")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_537")
                                                                    (add
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_537"))
                                                                    (apply (myself "Size") (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_538")) (get-alt "VMap" (param 0))))))
                                                                    (apply (myself "Size") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_538")) (get-alt "VMap" (param 0)))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_538") (add (unsafe-nth (u8 0) (identifier "repeat_n_538")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_537"))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> fun813 { [&](std::shared_ptr<::dessser::gen::raql_value::t>  p_0) {
    uint16_t id_814 { uint16_t((*p_0).index()) };
    Size let_res_815;
    {
      uint16_t label2_534 { id_814 };
      uint16_t id_816 { 0 };
      bool id_817 { bool(id_816 == label2_534) };
      Size choose_res_818;
      if (id_817) {
        Size id_819 { 2UL };
        choose_res_818 = id_819;
      } else {
        uint16_t id_820 { 1 };
        bool id_821 { bool(id_820 == label2_534) };
        Size choose_res_822;
        if (id_821) {
          Size id_823 { 2UL };
          choose_res_822 = id_823;
        } else {
          uint16_t id_824 { 2 };
          bool id_825 { bool(id_824 == label2_534) };
          Size choose_res_826;
          if (id_825) {
            Size id_827 { 10UL };
            choose_res_826 = id_827;
          } else {
            uint16_t id_828 { 3 };
            bool id_829 { bool(id_828 == label2_534) };
            Size choose_res_830;
            if (id_829) {
              Size id_831 { 2UL };
              std::string id_832 { std::get<3 /* VString */>((*p_0)) };
              uint32_t id_833 { (uint32_t)id_832.size() };
              Vec<1, uint32_t> id_834 {  id_833  };
              Size let_res_835;
              {
                Vec<1, uint32_t> n_ref_568 { id_834 };
                uint32_t id_836 { 1U };
                Vec<1, uint32_t> id_837 {  id_836  };
                Size let_res_838;
                {
                  Vec<1, uint32_t> lebsz_ref_569 { id_837 };
                  bool while_flag_839 { true };
                  do {
                    uint8_t id_840 { 0 };
                    uint32_t id_841 { n_ref_568[id_840] };
                    uint8_t id_842 { 0 };
                    uint32_t id_843 { lebsz_ref_569[id_842] };
                    uint8_t id_844 { 7 };
                    uint32_t id_845 { uint32_t(id_843 << id_844) };
                    bool id_846 { bool(id_841 >= id_845) };
                    while_flag_839 = id_846;
                    if (while_flag_839) {
                      uint8_t id_847 { 0 };
                      uint8_t id_848 { 0 };
                      uint32_t id_849 { lebsz_ref_569[id_848] };
                      uint32_t id_850 { 1U };
                      uint32_t id_851 { uint32_t(id_849 + id_850) };
                      Void id_852 { ((void)(lebsz_ref_569[id_847] = id_851), ::dessser::Void()) };
                      (void)id_852;
                    }
                  } while (while_flag_839);
                  (void)::dessser::Void();
                  uint8_t id_853 { 0 };
                  uint32_t id_854 { lebsz_ref_569[id_853] };
                  Size id_855 { Size(id_854) };
                  let_res_838 = id_855;
                }
                let_res_835 = let_res_838;
              }
              std::string id_856 { std::get<3 /* VString */>((*p_0)) };
              uint32_t id_857 { (uint32_t)id_856.size() };
              Size id_858 { Size(id_857) };
              Size id_859 { Size(let_res_835 + id_858) };
              Size id_860 { Size(id_831 + id_859) };
              choose_res_830 = id_860;
            } else {
              uint16_t id_861 { 4 };
              bool id_862 { bool(id_861 == label2_534) };
              Size choose_res_863;
              if (id_862) {
                Size id_864 { 3UL };
                choose_res_863 = id_864;
              } else {
                uint16_t id_865 { 5 };
                bool id_866 { bool(id_865 == label2_534) };
                Size choose_res_867;
                if (id_866) {
                  Size id_868 { 3UL };
                  choose_res_867 = id_868;
                } else {
                  uint16_t id_869 { 6 };
                  bool id_870 { bool(id_869 == label2_534) };
                  Size choose_res_871;
                  if (id_870) {
                    Size id_872 { 3UL };
                    choose_res_871 = id_872;
                  } else {
                    uint16_t id_873 { 7 };
                    bool id_874 { bool(id_873 == label2_534) };
                    Size choose_res_875;
                    if (id_874) {
                      Size id_876 { 4UL };
                      choose_res_875 = id_876;
                    } else {
                      uint16_t id_877 { 8 };
                      bool id_878 { bool(id_877 == label2_534) };
                      Size choose_res_879;
                      if (id_878) {
                        Size id_880 { 6UL };
                        choose_res_879 = id_880;
                      } else {
                        uint16_t id_881 { 9 };
                        bool id_882 { bool(id_881 == label2_534) };
                        Size choose_res_883;
                        if (id_882) {
                          Size id_884 { 6UL };
                          choose_res_883 = id_884;
                        } else {
                          uint16_t id_885 { 10 };
                          bool id_886 { bool(id_885 == label2_534) };
                          Size choose_res_887;
                          if (id_886) {
                            Size id_888 { 10UL };
                            choose_res_887 = id_888;
                          } else {
                            uint16_t id_889 { 11 };
                            bool id_890 { bool(id_889 == label2_534) };
                            Size choose_res_891;
                            if (id_890) {
                              Size id_892 { 10UL };
                              choose_res_891 = id_892;
                            } else {
                              uint16_t id_893 { 12 };
                              bool id_894 { bool(id_893 == label2_534) };
                              Size choose_res_895;
                              if (id_894) {
                                Size id_896 { 10UL };
                                choose_res_895 = id_896;
                              } else {
                                uint16_t id_897 { 13 };
                                bool id_898 { bool(id_897 == label2_534) };
                                Size choose_res_899;
                                if (id_898) {
                                  Size id_900 { 10UL };
                                  choose_res_899 = id_900;
                                } else {
                                  uint16_t id_901 { 14 };
                                  bool id_902 { bool(id_901 == label2_534) };
                                  Size choose_res_903;
                                  if (id_902) {
                                    Size id_904 { 18UL };
                                    choose_res_903 = id_904;
                                  } else {
                                    uint16_t id_905 { 15 };
                                    bool id_906 { bool(id_905 == label2_534) };
                                    Size choose_res_907;
                                    if (id_906) {
                                      Size id_908 { 3UL };
                                      choose_res_907 = id_908;
                                    } else {
                                      uint16_t id_909 { 16 };
                                      bool id_910 { bool(id_909 == label2_534) };
                                      Size choose_res_911;
                                      if (id_910) {
                                        Size id_912 { 4UL };
                                        choose_res_911 = id_912;
                                      } else {
                                        uint16_t id_913 { 17 };
                                        bool id_914 { bool(id_913 == label2_534) };
                                        Size choose_res_915;
                                        if (id_914) {
                                          Size id_916 { 6UL };
                                          choose_res_915 = id_916;
                                        } else {
                                          uint16_t id_917 { 18 };
                                          bool id_918 { bool(id_917 == label2_534) };
                                          Size choose_res_919;
                                          if (id_918) {
                                            Size id_920 { 6UL };
                                            choose_res_919 = id_920;
                                          } else {
                                            uint16_t id_921 { 19 };
                                            bool id_922 { bool(id_921 == label2_534) };
                                            Size choose_res_923;
                                            if (id_922) {
                                              Size id_924 { 10UL };
                                              choose_res_923 = id_924;
                                            } else {
                                              uint16_t id_925 { 20 };
                                              bool id_926 { bool(id_925 == label2_534) };
                                              Size choose_res_927;
                                              if (id_926) {
                                                Size id_928 { 10UL };
                                                choose_res_927 = id_928;
                                              } else {
                                                uint16_t id_929 { 21 };
                                                bool id_930 { bool(id_929 == label2_534) };
                                                Size choose_res_931;
                                                if (id_930) {
                                                  Size id_932 { 10UL };
                                                  choose_res_931 = id_932;
                                                } else {
                                                  uint16_t id_933 { 22 };
                                                  bool id_934 { bool(id_933 == label2_534) };
                                                  Size choose_res_935;
                                                  if (id_934) {
                                                    Size id_936 { 10UL };
                                                    choose_res_935 = id_936;
                                                  } else {
                                                    uint16_t id_937 { 23 };
                                                    bool id_938 { bool(id_937 == label2_534) };
                                                    Size choose_res_939;
                                                    if (id_938) {
                                                      Size id_940 { 18UL };
                                                      choose_res_939 = id_940;
                                                    } else {
                                                      uint16_t id_941 { 24 };
                                                      bool id_942 { bool(id_941 == label2_534) };
                                                      Size choose_res_943;
                                                      if (id_942) {
                                                        Size id_944 { 10UL };
                                                        choose_res_943 = id_944;
                                                      } else {
                                                        uint16_t id_945 { 25 };
                                                        bool id_946 { bool(id_945 == label2_534) };
                                                        Size choose_res_947;
                                                        if (id_946) {
                                                          Size id_948 { 6UL };
                                                          choose_res_947 = id_948;
                                                        } else {
                                                          uint16_t id_949 { 26 };
                                                          bool id_950 { bool(id_949 == label2_534) };
                                                          Size choose_res_951;
                                                          if (id_950) {
                                                            Size id_952 { 18UL };
                                                            choose_res_951 = id_952;
                                                          } else {
                                                            uint16_t id_953 { 27 };
                                                            bool id_954 { bool(id_953 == label2_534) };
                                                            Size choose_res_955;
                                                            if (id_954) {
                                                              uint16_t id_956 { 0 };
                                                              ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_957 { std::get<27 /* VIp */>((*p_0)) };
                                                              uint16_t id_958 { uint16_t(id_957.index()) };
                                                              bool id_959 { bool(id_956 == id_958) };
                                                              Size choose_res_960;
                                                              if (id_959) {
                                                                Size id_961 { 8UL };
                                                                choose_res_960 = id_961;
                                                              } else {
                                                                ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_962 { std::get<27 /* VIp */>((*p_0)) };
                                                                uint16_t id_963 { uint16_t(id_962.index()) };
                                                                uint16_t id_964 { 1 };
                                                                bool id_965 { bool(id_963 == id_964) };
                                                                Void id_966 { ((void)(assert(id_965)), ::dessser::Void()) };
                                                                (void)id_966;
                                                                Size id_967 { 20UL };
                                                                choose_res_960 = id_967;
                                                              }
                                                              choose_res_955 = choose_res_960;
                                                            } else {
                                                              uint16_t id_968 { 28 };
                                                              bool id_969 { bool(id_968 == label2_534) };
                                                              Size choose_res_970;
                                                              if (id_969) {
                                                                Size id_971 { 7UL };
                                                                choose_res_970 = id_971;
                                                              } else {
                                                                uint16_t id_972 { 29 };
                                                                bool id_973 { bool(id_972 == label2_534) };
                                                                Size choose_res_974;
                                                                if (id_973) {
                                                                  Size id_975 { 19UL };
                                                                  choose_res_974 = id_975;
                                                                } else {
                                                                  uint16_t id_976 { 30 };
                                                                  bool id_977 { bool(id_976 == label2_534) };
                                                                  Size choose_res_978;
                                                                  if (id_977) {
                                                                    uint16_t id_979 { 0 };
                                                                    ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_980 { std::get<30 /* VCidr */>((*p_0)) };
                                                                    uint16_t id_981 { uint16_t(id_980.index()) };
                                                                    bool id_982 { bool(id_979 == id_981) };
                                                                    Size choose_res_983;
                                                                    if (id_982) {
                                                                      Size id_984 { 9UL };
                                                                      choose_res_983 = id_984;
                                                                    } else {
                                                                      ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_985 { std::get<30 /* VCidr */>((*p_0)) };
                                                                      uint16_t id_986 { uint16_t(id_985.index()) };
                                                                      uint16_t id_987 { 1 };
                                                                      bool id_988 { bool(id_986 == id_987) };
                                                                      Void id_989 { ((void)(assert(id_988)), ::dessser::Void()) };
                                                                      (void)id_989;
                                                                      Size id_990 { 21UL };
                                                                      choose_res_983 = id_990;
                                                                    }
                                                                    choose_res_978 = choose_res_983;
                                                                  } else {
                                                                    uint16_t id_991 { 31 };
                                                                    bool id_992 { bool(id_991 == label2_534) };
                                                                    Size choose_res_993;
                                                                    if (id_992) {
                                                                      Size id_994 { 2UL };
                                                                      Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_995 { std::get<31 /* VTup */>((*p_0)) };
                                                                      uint32_t id_996 { id_995.size() };
                                                                      Vec<1, uint32_t> id_997 {  id_996  };
                                                                      Size let_res_998;
                                                                      {
                                                                        Vec<1, uint32_t> n_ref_553 { id_997 };
                                                                        uint32_t id_999 { 1U };
                                                                        Vec<1, uint32_t> id_1000 {  id_999  };
                                                                        Size let_res_1001;
                                                                        {
                                                                          Vec<1, uint32_t> lebsz_ref_554 { id_1000 };
                                                                          bool while_flag_1002 { true };
                                                                          do {
                                                                            uint8_t id_1003 { 0 };
                                                                            uint32_t id_1004 { n_ref_553[id_1003] };
                                                                            uint8_t id_1005 { 0 };
                                                                            uint32_t id_1006 { lebsz_ref_554[id_1005] };
                                                                            uint8_t id_1007 { 7 };
                                                                            uint32_t id_1008 { uint32_t(id_1006 << id_1007) };
                                                                            bool id_1009 { bool(id_1004 >= id_1008) };
                                                                            while_flag_1002 = id_1009;
                                                                            if (while_flag_1002) {
                                                                              uint8_t id_1010 { 0 };
                                                                              uint8_t id_1011 { 0 };
                                                                              uint32_t id_1012 { lebsz_ref_554[id_1011] };
                                                                              uint32_t id_1013 { 1U };
                                                                              uint32_t id_1014 { uint32_t(id_1012 + id_1013) };
                                                                              Void id_1015 { ((void)(lebsz_ref_554[id_1010] = id_1014), ::dessser::Void()) };
                                                                              (void)id_1015;
                                                                            }
                                                                          } while (while_flag_1002);
                                                                          (void)::dessser::Void();
                                                                          uint8_t id_1016 { 0 };
                                                                          uint32_t id_1017 { lebsz_ref_554[id_1016] };
                                                                          Size id_1018 { Size(id_1017) };
                                                                          let_res_1001 = id_1018;
                                                                        }
                                                                        let_res_998 = let_res_1001;
                                                                      }
                                                                      Size id_1019 { Size(id_994 + let_res_998) };
                                                                      Vec<1, Size> id_1020 {  id_1019  };
                                                                      Size let_res_1021;
                                                                      {
                                                                        Vec<1, Size> sz_ref_555 { id_1020 };
                                                                        int32_t id_1022 { 0L };
                                                                        Vec<1, int32_t> id_1023 {  id_1022  };
                                                                        {
                                                                          Vec<1, int32_t> repeat_n_556 { id_1023 };
                                                                          bool while_flag_1024 { true };
                                                                          do {
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1025 { std::get<31 /* VTup */>((*p_0)) };
                                                                            uint32_t id_1026 { id_1025.size() };
                                                                            int32_t id_1027 { int32_t(id_1026) };
                                                                            uint8_t id_1028 { 0 };
                                                                            int32_t id_1029 { repeat_n_556[id_1028] };
                                                                            bool id_1030 { bool(id_1027 > id_1029) };
                                                                            while_flag_1024 = id_1030;
                                                                            if (while_flag_1024) {
                                                                              uint8_t id_1031 { 0 };
                                                                              uint8_t id_1032 { 0 };
                                                                              Size id_1033 { sz_ref_555[id_1032] };
                                                                              uint8_t id_1034 { 0 };
                                                                              int32_t id_1035 { repeat_n_556[id_1034] };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1036 { std::get<31 /* VTup */>((*p_0)) };
                                                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_1037 { id_1036[id_1035] };
                                                                              Size id_1038 { fun813(id_1037) };
                                                                              Size id_1039 { Size(id_1033 + id_1038) };
                                                                              Void id_1040 { ((void)(sz_ref_555[id_1031] = id_1039), ::dessser::Void()) };
                                                                              (void)id_1040;
                                                                              uint8_t id_1041 { 0 };
                                                                              uint8_t id_1042 { 0 };
                                                                              int32_t id_1043 { repeat_n_556[id_1042] };
                                                                              int32_t id_1044 { 1L };
                                                                              int32_t id_1045 { int32_t(id_1043 + id_1044) };
                                                                              Void id_1046 { ((void)(repeat_n_556[id_1041] = id_1045), ::dessser::Void()) };
                                                                              (void)id_1046;
                                                                              (void)id_1046;
                                                                            }
                                                                          } while (while_flag_1024);
                                                                          (void)::dessser::Void();
                                                                        }
                                                                        (void)::dessser::Void();
                                                                        uint8_t id_1047 { 0 };
                                                                        Size id_1048 { sz_ref_555[id_1047] };
                                                                        let_res_1021 = id_1048;
                                                                      }
                                                                      choose_res_993 = let_res_1021;
                                                                    } else {
                                                                      uint16_t id_1049 { 32 };
                                                                      bool id_1050 { bool(id_1049 == label2_534) };
                                                                      Size choose_res_1051;
                                                                      if (id_1050) {
                                                                        Size id_1052 { 2UL };
                                                                        Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1053 { std::get<32 /* VVec */>((*p_0)) };
                                                                        uint32_t id_1054 { id_1053.size() };
                                                                        Vec<1, uint32_t> id_1055 {  id_1054  };
                                                                        Size let_res_1056;
                                                                        {
                                                                          Vec<1, uint32_t> n_ref_549 { id_1055 };
                                                                          uint32_t id_1057 { 1U };
                                                                          Vec<1, uint32_t> id_1058 {  id_1057  };
                                                                          Size let_res_1059;
                                                                          {
                                                                            Vec<1, uint32_t> lebsz_ref_550 { id_1058 };
                                                                            bool while_flag_1060 { true };
                                                                            do {
                                                                              uint8_t id_1061 { 0 };
                                                                              uint32_t id_1062 { n_ref_549[id_1061] };
                                                                              uint8_t id_1063 { 0 };
                                                                              uint32_t id_1064 { lebsz_ref_550[id_1063] };
                                                                              uint8_t id_1065 { 7 };
                                                                              uint32_t id_1066 { uint32_t(id_1064 << id_1065) };
                                                                              bool id_1067 { bool(id_1062 >= id_1066) };
                                                                              while_flag_1060 = id_1067;
                                                                              if (while_flag_1060) {
                                                                                uint8_t id_1068 { 0 };
                                                                                uint8_t id_1069 { 0 };
                                                                                uint32_t id_1070 { lebsz_ref_550[id_1069] };
                                                                                uint32_t id_1071 { 1U };
                                                                                uint32_t id_1072 { uint32_t(id_1070 + id_1071) };
                                                                                Void id_1073 { ((void)(lebsz_ref_550[id_1068] = id_1072), ::dessser::Void()) };
                                                                                (void)id_1073;
                                                                              }
                                                                            } while (while_flag_1060);
                                                                            (void)::dessser::Void();
                                                                            uint8_t id_1074 { 0 };
                                                                            uint32_t id_1075 { lebsz_ref_550[id_1074] };
                                                                            Size id_1076 { Size(id_1075) };
                                                                            let_res_1059 = id_1076;
                                                                          }
                                                                          let_res_1056 = let_res_1059;
                                                                        }
                                                                        Size id_1077 { Size(id_1052 + let_res_1056) };
                                                                        Vec<1, Size> id_1078 {  id_1077  };
                                                                        Size let_res_1079;
                                                                        {
                                                                          Vec<1, Size> sz_ref_551 { id_1078 };
                                                                          int32_t id_1080 { 0L };
                                                                          Vec<1, int32_t> id_1081 {  id_1080  };
                                                                          {
                                                                            Vec<1, int32_t> repeat_n_552 { id_1081 };
                                                                            bool while_flag_1082 { true };
                                                                            do {
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1083 { std::get<32 /* VVec */>((*p_0)) };
                                                                              uint32_t id_1084 { id_1083.size() };
                                                                              int32_t id_1085 { int32_t(id_1084) };
                                                                              uint8_t id_1086 { 0 };
                                                                              int32_t id_1087 { repeat_n_552[id_1086] };
                                                                              bool id_1088 { bool(id_1085 > id_1087) };
                                                                              while_flag_1082 = id_1088;
                                                                              if (while_flag_1082) {
                                                                                uint8_t id_1089 { 0 };
                                                                                uint8_t id_1090 { 0 };
                                                                                Size id_1091 { sz_ref_551[id_1090] };
                                                                                uint8_t id_1092 { 0 };
                                                                                int32_t id_1093 { repeat_n_552[id_1092] };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1094 { std::get<32 /* VVec */>((*p_0)) };
                                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_1095 { id_1094[id_1093] };
                                                                                Size id_1096 { fun813(id_1095) };
                                                                                Size id_1097 { Size(id_1091 + id_1096) };
                                                                                Void id_1098 { ((void)(sz_ref_551[id_1089] = id_1097), ::dessser::Void()) };
                                                                                (void)id_1098;
                                                                                uint8_t id_1099 { 0 };
                                                                                uint8_t id_1100 { 0 };
                                                                                int32_t id_1101 { repeat_n_552[id_1100] };
                                                                                int32_t id_1102 { 1L };
                                                                                int32_t id_1103 { int32_t(id_1101 + id_1102) };
                                                                                Void id_1104 { ((void)(repeat_n_552[id_1099] = id_1103), ::dessser::Void()) };
                                                                                (void)id_1104;
                                                                                (void)id_1104;
                                                                              }
                                                                            } while (while_flag_1082);
                                                                            (void)::dessser::Void();
                                                                          }
                                                                          (void)::dessser::Void();
                                                                          uint8_t id_1105 { 0 };
                                                                          Size id_1106 { sz_ref_551[id_1105] };
                                                                          let_res_1079 = id_1106;
                                                                        }
                                                                        choose_res_1051 = let_res_1079;
                                                                      } else {
                                                                        uint16_t id_1107 { 33 };
                                                                        bool id_1108 { bool(id_1107 == label2_534) };
                                                                        Size choose_res_1109;
                                                                        if (id_1108) {
                                                                          Size id_1110 { 2UL };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1111 { std::get<33 /* VArr */>((*p_0)) };
                                                                          uint32_t id_1112 { id_1111.size() };
                                                                          Vec<1, uint32_t> id_1113 {  id_1112  };
                                                                          Size let_res_1114;
                                                                          {
                                                                            Vec<1, uint32_t> n_ref_545 { id_1113 };
                                                                            uint32_t id_1115 { 1U };
                                                                            Vec<1, uint32_t> id_1116 {  id_1115  };
                                                                            Size let_res_1117;
                                                                            {
                                                                              Vec<1, uint32_t> lebsz_ref_546 { id_1116 };
                                                                              bool while_flag_1118 { true };
                                                                              do {
                                                                                uint8_t id_1119 { 0 };
                                                                                uint32_t id_1120 { n_ref_545[id_1119] };
                                                                                uint8_t id_1121 { 0 };
                                                                                uint32_t id_1122 { lebsz_ref_546[id_1121] };
                                                                                uint8_t id_1123 { 7 };
                                                                                uint32_t id_1124 { uint32_t(id_1122 << id_1123) };
                                                                                bool id_1125 { bool(id_1120 >= id_1124) };
                                                                                while_flag_1118 = id_1125;
                                                                                if (while_flag_1118) {
                                                                                  uint8_t id_1126 { 0 };
                                                                                  uint8_t id_1127 { 0 };
                                                                                  uint32_t id_1128 { lebsz_ref_546[id_1127] };
                                                                                  uint32_t id_1129 { 1U };
                                                                                  uint32_t id_1130 { uint32_t(id_1128 + id_1129) };
                                                                                  Void id_1131 { ((void)(lebsz_ref_546[id_1126] = id_1130), ::dessser::Void()) };
                                                                                  (void)id_1131;
                                                                                }
                                                                              } while (while_flag_1118);
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_1132 { 0 };
                                                                              uint32_t id_1133 { lebsz_ref_546[id_1132] };
                                                                              Size id_1134 { Size(id_1133) };
                                                                              let_res_1117 = id_1134;
                                                                            }
                                                                            let_res_1114 = let_res_1117;
                                                                          }
                                                                          Size id_1135 { Size(id_1110 + let_res_1114) };
                                                                          Vec<1, Size> id_1136 {  id_1135  };
                                                                          Size let_res_1137;
                                                                          {
                                                                            Vec<1, Size> sz_ref_547 { id_1136 };
                                                                            int32_t id_1138 { 0L };
                                                                            Vec<1, int32_t> id_1139 {  id_1138  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_548 { id_1139 };
                                                                              bool while_flag_1140 { true };
                                                                              do {
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1141 { std::get<33 /* VArr */>((*p_0)) };
                                                                                uint32_t id_1142 { id_1141.size() };
                                                                                int32_t id_1143 { int32_t(id_1142) };
                                                                                uint8_t id_1144 { 0 };
                                                                                int32_t id_1145 { repeat_n_548[id_1144] };
                                                                                bool id_1146 { bool(id_1143 > id_1145) };
                                                                                while_flag_1140 = id_1146;
                                                                                if (while_flag_1140) {
                                                                                  uint8_t id_1147 { 0 };
                                                                                  uint8_t id_1148 { 0 };
                                                                                  Size id_1149 { sz_ref_547[id_1148] };
                                                                                  uint8_t id_1150 { 0 };
                                                                                  int32_t id_1151 { repeat_n_548[id_1150] };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1152 { std::get<33 /* VArr */>((*p_0)) };
                                                                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_1153 { id_1152[id_1151] };
                                                                                  Size id_1154 { fun813(id_1153) };
                                                                                  Size id_1155 { Size(id_1149 + id_1154) };
                                                                                  Void id_1156 { ((void)(sz_ref_547[id_1147] = id_1155), ::dessser::Void()) };
                                                                                  (void)id_1156;
                                                                                  uint8_t id_1157 { 0 };
                                                                                  uint8_t id_1158 { 0 };
                                                                                  int32_t id_1159 { repeat_n_548[id_1158] };
                                                                                  int32_t id_1160 { 1L };
                                                                                  int32_t id_1161 { int32_t(id_1159 + id_1160) };
                                                                                  Void id_1162 { ((void)(repeat_n_548[id_1157] = id_1161), ::dessser::Void()) };
                                                                                  (void)id_1162;
                                                                                  (void)id_1162;
                                                                                }
                                                                              } while (while_flag_1140);
                                                                              (void)::dessser::Void();
                                                                            }
                                                                            (void)::dessser::Void();
                                                                            uint8_t id_1163 { 0 };
                                                                            Size id_1164 { sz_ref_547[id_1163] };
                                                                            let_res_1137 = id_1164;
                                                                          }
                                                                          choose_res_1109 = let_res_1137;
                                                                        } else {
                                                                          uint16_t id_1165 { 34 };
                                                                          bool id_1166 { bool(id_1165 == label2_534) };
                                                                          Size choose_res_1167;
                                                                          if (id_1166) {
                                                                            Size id_1168 { 2UL };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1169 { std::get<34 /* VRec */>((*p_0)) };
                                                                            uint32_t id_1170 { id_1169.size() };
                                                                            Vec<1, uint32_t> id_1171 {  id_1170  };
                                                                            Size let_res_1172;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_541 { id_1171 };
                                                                              uint32_t id_1173 { 1U };
                                                                              Vec<1, uint32_t> id_1174 {  id_1173  };
                                                                              Size let_res_1175;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_542 { id_1174 };
                                                                                bool while_flag_1176 { true };
                                                                                do {
                                                                                  uint8_t id_1177 { 0 };
                                                                                  uint32_t id_1178 { n_ref_541[id_1177] };
                                                                                  uint8_t id_1179 { 0 };
                                                                                  uint32_t id_1180 { lebsz_ref_542[id_1179] };
                                                                                  uint8_t id_1181 { 7 };
                                                                                  uint32_t id_1182 { uint32_t(id_1180 << id_1181) };
                                                                                  bool id_1183 { bool(id_1178 >= id_1182) };
                                                                                  while_flag_1176 = id_1183;
                                                                                  if (while_flag_1176) {
                                                                                    uint8_t id_1184 { 0 };
                                                                                    uint8_t id_1185 { 0 };
                                                                                    uint32_t id_1186 { lebsz_ref_542[id_1185] };
                                                                                    uint32_t id_1187 { 1U };
                                                                                    uint32_t id_1188 { uint32_t(id_1186 + id_1187) };
                                                                                    Void id_1189 { ((void)(lebsz_ref_542[id_1184] = id_1188), ::dessser::Void()) };
                                                                                    (void)id_1189;
                                                                                  }
                                                                                } while (while_flag_1176);
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_1190 { 0 };
                                                                                uint32_t id_1191 { lebsz_ref_542[id_1190] };
                                                                                Size id_1192 { Size(id_1191) };
                                                                                let_res_1175 = id_1192;
                                                                              }
                                                                              let_res_1172 = let_res_1175;
                                                                            }
                                                                            Size id_1193 { Size(id_1168 + let_res_1172) };
                                                                            Vec<1, Size> id_1194 {  id_1193  };
                                                                            Size let_res_1195;
                                                                            {
                                                                              Vec<1, Size> sz_ref_543 { id_1194 };
                                                                              int32_t id_1196 { 0L };
                                                                              Vec<1, int32_t> id_1197 {  id_1196  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_544 { id_1197 };
                                                                                bool while_flag_1198 { true };
                                                                                do {
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1199 { std::get<34 /* VRec */>((*p_0)) };
                                                                                  uint32_t id_1200 { id_1199.size() };
                                                                                  int32_t id_1201 { int32_t(id_1200) };
                                                                                  uint8_t id_1202 { 0 };
                                                                                  int32_t id_1203 { repeat_n_544[id_1202] };
                                                                                  bool id_1204 { bool(id_1201 > id_1203) };
                                                                                  while_flag_1198 = id_1204;
                                                                                  if (while_flag_1198) {
                                                                                    uint8_t id_1205 { 0 };
                                                                                    uint8_t id_1206 { 0 };
                                                                                    Size id_1207 { sz_ref_543[id_1206] };
                                                                                    uint8_t id_1208 { 0 };
                                                                                    int32_t id_1209 { repeat_n_544[id_1208] };
                                                                                    Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1210 { std::get<34 /* VRec */>((*p_0)) };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::named_value>  id_1211 { id_1210[id_1209] };
                                                                                    Size id_1212 { named_value_sersize_of_row_binary(id_1211) };
                                                                                    Size id_1213 { Size(id_1207 + id_1212) };
                                                                                    Void id_1214 { ((void)(sz_ref_543[id_1205] = id_1213), ::dessser::Void()) };
                                                                                    (void)id_1214;
                                                                                    uint8_t id_1215 { 0 };
                                                                                    uint8_t id_1216 { 0 };
                                                                                    int32_t id_1217 { repeat_n_544[id_1216] };
                                                                                    int32_t id_1218 { 1L };
                                                                                    int32_t id_1219 { int32_t(id_1217 + id_1218) };
                                                                                    Void id_1220 { ((void)(repeat_n_544[id_1215] = id_1219), ::dessser::Void()) };
                                                                                    (void)id_1220;
                                                                                    (void)id_1220;
                                                                                  }
                                                                                } while (while_flag_1198);
                                                                                (void)::dessser::Void();
                                                                              }
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_1221 { 0 };
                                                                              Size id_1222 { sz_ref_543[id_1221] };
                                                                              let_res_1195 = id_1222;
                                                                            }
                                                                            choose_res_1167 = let_res_1195;
                                                                          } else {
                                                                            uint16_t id_1223 { 35 };
                                                                            bool id_1224 { bool(label2_534 == id_1223) };
                                                                            Void id_1225 { ((void)(assert(id_1224)), ::dessser::Void()) };
                                                                            (void)id_1225;
                                                                            Size id_1226 { 2UL };
                                                                            Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_1227 { std::get<35 /* VMap */>((*p_0)) };
                                                                            uint32_t id_1228 { id_1227.size() };
                                                                            Vec<1, uint32_t> id_1229 {  id_1228  };
                                                                            Size let_res_1230;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_535 { id_1229 };
                                                                              uint32_t id_1231 { 1U };
                                                                              Vec<1, uint32_t> id_1232 {  id_1231  };
                                                                              Size let_res_1233;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_536 { id_1232 };
                                                                                bool while_flag_1234 { true };
                                                                                do {
                                                                                  uint8_t id_1235 { 0 };
                                                                                  uint32_t id_1236 { n_ref_535[id_1235] };
                                                                                  uint8_t id_1237 { 0 };
                                                                                  uint32_t id_1238 { lebsz_ref_536[id_1237] };
                                                                                  uint8_t id_1239 { 7 };
                                                                                  uint32_t id_1240 { uint32_t(id_1238 << id_1239) };
                                                                                  bool id_1241 { bool(id_1236 >= id_1240) };
                                                                                  while_flag_1234 = id_1241;
                                                                                  if (while_flag_1234) {
                                                                                    uint8_t id_1242 { 0 };
                                                                                    uint8_t id_1243 { 0 };
                                                                                    uint32_t id_1244 { lebsz_ref_536[id_1243] };
                                                                                    uint32_t id_1245 { 1U };
                                                                                    uint32_t id_1246 { uint32_t(id_1244 + id_1245) };
                                                                                    Void id_1247 { ((void)(lebsz_ref_536[id_1242] = id_1246), ::dessser::Void()) };
                                                                                    (void)id_1247;
                                                                                  }
                                                                                } while (while_flag_1234);
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_1248 { 0 };
                                                                                uint32_t id_1249 { lebsz_ref_536[id_1248] };
                                                                                Size id_1250 { Size(id_1249) };
                                                                                let_res_1233 = id_1250;
                                                                              }
                                                                              let_res_1230 = let_res_1233;
                                                                            }
                                                                            Size id_1251 { Size(id_1226 + let_res_1230) };
                                                                            Vec<1, Size> id_1252 {  id_1251  };
                                                                            Size let_res_1253;
                                                                            {
                                                                              Vec<1, Size> sz_ref_537 { id_1252 };
                                                                              int32_t id_1254 { 0L };
                                                                              Vec<1, int32_t> id_1255 {  id_1254  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_538 { id_1255 };
                                                                                bool while_flag_1256 { true };
                                                                                do {
                                                                                  Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_1257 { std::get<35 /* VMap */>((*p_0)) };
                                                                                  uint32_t id_1258 { id_1257.size() };
                                                                                  int32_t id_1259 { int32_t(id_1258) };
                                                                                  uint8_t id_1260 { 0 };
                                                                                  int32_t id_1261 { repeat_n_538[id_1260] };
                                                                                  bool id_1262 { bool(id_1259 > id_1261) };
                                                                                  while_flag_1256 = id_1262;
                                                                                  if (while_flag_1256) {
                                                                                    uint8_t id_1263 { 0 };
                                                                                    uint8_t id_1264 { 0 };
                                                                                    Size id_1265 { sz_ref_537[id_1264] };
                                                                                    uint8_t id_1266 { 0 };
                                                                                    int32_t id_1267 { repeat_n_538[id_1266] };
                                                                                    Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_1268 { std::get<35 /* VMap */>((*p_0)) };
                                                                                    ::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f id_1269 { id_1268[id_1267] };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1270 { std::get<0>(id_1269) };
                                                                                    Size id_1271 { fun813(id_1270) };
                                                                                    Size id_1272 { Size(id_1265 + id_1271) };
                                                                                    uint8_t id_1273 { 0 };
                                                                                    int32_t id_1274 { repeat_n_538[id_1273] };
                                                                                    Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_1275 { std::get<35 /* VMap */>((*p_0)) };
                                                                                    ::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f id_1276 { id_1275[id_1274] };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1277 { std::get<1>(id_1276) };
                                                                                    Size id_1278 { fun813(id_1277) };
                                                                                    Size id_1279 { Size(id_1272 + id_1278) };
                                                                                    Void id_1280 { ((void)(sz_ref_537[id_1263] = id_1279), ::dessser::Void()) };
                                                                                    (void)id_1280;
                                                                                    uint8_t id_1281 { 0 };
                                                                                    uint8_t id_1282 { 0 };
                                                                                    int32_t id_1283 { repeat_n_538[id_1282] };
                                                                                    int32_t id_1284 { 1L };
                                                                                    int32_t id_1285 { int32_t(id_1283 + id_1284) };
                                                                                    Void id_1286 { ((void)(repeat_n_538[id_1281] = id_1285), ::dessser::Void()) };
                                                                                    (void)id_1286;
                                                                                    (void)id_1286;
                                                                                  }
                                                                                } while (while_flag_1256);
                                                                                (void)::dessser::Void();
                                                                              }
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_1287 { 0 };
                                                                              Size id_1288 { sz_ref_537[id_1287] };
                                                                              let_res_1253 = id_1288;
                                                                            }
                                                                            choose_res_1167 = let_res_1253;
                                                                          }
                                                                          choose_res_1109 = choose_res_1167;
                                                                        }
                                                                        choose_res_1051 = choose_res_1109;
                                                                      }
                                                                      choose_res_993 = choose_res_1051;
                                                                    }
                                                                    choose_res_978 = choose_res_993;
                                                                  }
                                                                  choose_res_974 = choose_res_978;
                                                                }
                                                                choose_res_970 = choose_res_974;
                                                              }
                                                              choose_res_955 = choose_res_970;
                                                            }
                                                            choose_res_951 = choose_res_955;
                                                          }
                                                          choose_res_947 = choose_res_951;
                                                        }
                                                        choose_res_943 = choose_res_947;
                                                      }
                                                      choose_res_939 = choose_res_943;
                                                    }
                                                    choose_res_935 = choose_res_939;
                                                  }
                                                  choose_res_931 = choose_res_935;
                                                }
                                                choose_res_927 = choose_res_931;
                                              }
                                              choose_res_923 = choose_res_927;
                                            }
                                            choose_res_919 = choose_res_923;
                                          }
                                          choose_res_915 = choose_res_919;
                                        }
                                        choose_res_911 = choose_res_915;
                                      }
                                      choose_res_907 = choose_res_911;
                                    }
                                    choose_res_903 = choose_res_907;
                                  }
                                  choose_res_899 = choose_res_903;
                                }
                                choose_res_895 = choose_res_899;
                              }
                              choose_res_891 = choose_res_895;
                            }
                            choose_res_887 = choose_res_891;
                          }
                          choose_res_883 = choose_res_887;
                        }
                        choose_res_879 = choose_res_883;
                      }
                      choose_res_875 = choose_res_879;
                    }
                    choose_res_871 = choose_res_875;
                  }
                  choose_res_867 = choose_res_871;
                }
                choose_res_863 = choose_res_867;
              }
              choose_res_830 = choose_res_863;
            }
            choose_res_826 = choose_res_830;
          }
          choose_res_822 = choose_res_826;
        }
        choose_res_818 = choose_res_822;
      }
      let_res_815 = choose_res_818;
    }
    return let_res_815;
  }
   };
  return fun813;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("(STRING; THIS)")
      (let "sz_533"
        (add
          (let "n_ref_531" (make-vec (string-length (get-item 0 (param 0))))
            (let "lebsz_ref_532" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_531")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_532")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_532") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_532")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_532")))))) 
          (size-of-u32 (string-length (get-item 0 (param 0))))) (add (identifier "sz_533") (apply (identifier "sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> named_value_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> fun1289 { [&](std::shared_ptr<::dessser::gen::raql_value::named_value>  p_0) {
    std::string id_1290 { std::get<0>((*p_0)) };
    uint32_t id_1291 { (uint32_t)id_1290.size() };
    Vec<1, uint32_t> id_1292 {  id_1291  };
    Size let_res_1293;
    {
      Vec<1, uint32_t> n_ref_531 { id_1292 };
      uint32_t id_1294 { 1U };
      Vec<1, uint32_t> id_1295 {  id_1294  };
      Size let_res_1296;
      {
        Vec<1, uint32_t> lebsz_ref_532 { id_1295 };
        bool while_flag_1297 { true };
        do {
          uint8_t id_1298 { 0 };
          uint32_t id_1299 { n_ref_531[id_1298] };
          uint8_t id_1300 { 0 };
          uint32_t id_1301 { lebsz_ref_532[id_1300] };
          uint8_t id_1302 { 7 };
          uint32_t id_1303 { uint32_t(id_1301 << id_1302) };
          bool id_1304 { bool(id_1299 >= id_1303) };
          while_flag_1297 = id_1304;
          if (while_flag_1297) {
            uint8_t id_1305 { 0 };
            uint8_t id_1306 { 0 };
            uint32_t id_1307 { lebsz_ref_532[id_1306] };
            uint32_t id_1308 { 1U };
            uint32_t id_1309 { uint32_t(id_1307 + id_1308) };
            Void id_1310 { ((void)(lebsz_ref_532[id_1305] = id_1309), ::dessser::Void()) };
            (void)id_1310;
          }
        } while (while_flag_1297);
        (void)::dessser::Void();
        uint8_t id_1311 { 0 };
        uint32_t id_1312 { lebsz_ref_532[id_1311] };
        Size id_1313 { Size(id_1312) };
        let_res_1296 = id_1313;
      }
      let_res_1293 = let_res_1296;
    }
    std::string id_1314 { std::get<0>((*p_0)) };
    uint32_t id_1315 { (uint32_t)id_1314.size() };
    Size id_1316 { Size(id_1315) };
    Size id_1317 { Size(let_res_1293 + id_1316) };
    Size let_res_1318;
    {
      Size sz_533 { id_1317 };
      std::shared_ptr<::dessser::gen::raql_value::t>  id_1319 { std::get<1>((*p_0)) };
      Size id_1320 { sersize_of_row_binary(id_1319) };
      Size id_1321 { Size(sz_533 + id_1320) };
      let_res_1318 = id_1321;
    }
    return let_res_1318;
  }
   };
  return fun1289;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> named_value_sersize_of_row_binary(named_value_sersize_of_row_binary_init());

/* 
    (fun ("[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" "Ptr")
      (let "label1_573" (label-of (param 0))
        (let "ssum_dst_574" (write-u16 little-endian (param 1) (identifier "label1_573"))
          (if (eq (u16 0) (identifier "label1_573")) (identifier "ssum_dst_574")
            (if (eq (u16 1) (identifier "label1_573")) (identifier "ssum_dst_574")
              (if (eq (u16 2) (identifier "label1_573")) (write-u64 little-endian (identifier "ssum_dst_574") (u64-of-float (get-alt "VFloat" (param 0))))
                (if (eq (u16 3) (identifier "label1_573"))
                  (write-bytes
                    (let "leb128_sz_610" (make-vec (string-length (get-alt "VString" (param 0))))
                      (let "leb128_ptr_611" (make-vec (identifier "ssum_dst_574"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_611")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_611"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_610"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_610"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_610"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_610") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_610")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_610")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_611"))))) 
                    (bytes-of-string (get-alt "VString" (param 0))))
                  (if (eq (u16 4) (identifier "label1_573")) (write-u8 (identifier "ssum_dst_574") (u8-of-bool (get-alt "VBool" (param 0))))
                    (if (eq (u16 5) (identifier "label1_573")) (write-u8 (identifier "ssum_dst_574") (u8-of-char (get-alt "VChar" (param 0))))
                      (if (eq (u16 6) (identifier "label1_573")) (write-u8 (identifier "ssum_dst_574") (get-alt "VU8" (param 0)))
                        (if (eq (u16 7) (identifier "label1_573")) (write-u16 little-endian (identifier "ssum_dst_574") (get-alt "VU16" (param 0)))
                          (if (eq (u16 8) (identifier "label1_573")) 
                            (write-u32 little-endian (identifier "ssum_dst_574") (to-u32 (get-alt "VU24" (param 0))))
                            (if (eq (u16 9) (identifier "label1_573")) 
                              (write-u32 little-endian (identifier "ssum_dst_574") (get-alt "VU32" (param 0)))
                              (if (eq (u16 10) (identifier "label1_573")) 
                                (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (get-alt "VU40" (param 0))))
                                (if (eq (u16 11) (identifier "label1_573")) 
                                  (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (get-alt "VU48" (param 0))))
                                  (if (eq (u16 12) (identifier "label1_573")) 
                                    (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (get-alt "VU56" (param 0))))
                                    (if (eq (u16 13) (identifier "label1_573")) 
                                      (write-u64 little-endian (identifier "ssum_dst_574") (get-alt "VU64" (param 0)))
                                      (if (eq (u16 14) (identifier "label1_573")) 
                                        (write-u128 little-endian (identifier "ssum_dst_574") (get-alt "VU128" (param 0)))
                                        (if (eq (u16 15) (identifier "label1_573")) 
                                          (write-u8 (identifier "ssum_dst_574") (to-u8 (get-alt "VI8" (param 0))))
                                          (if (eq (u16 16) (identifier "label1_573")) 
                                            (write-u16 little-endian (identifier "ssum_dst_574") (to-u16 (get-alt "VI16" (param 0))))
                                            (if (eq (u16 17) (identifier "label1_573")) 
                                              (write-u32 little-endian (identifier "ssum_dst_574") (to-u32 (to-i32 (get-alt "VI24" (param 0)))))
                                              (if (eq (u16 18) (identifier "label1_573")) 
                                                (write-u32 little-endian (identifier "ssum_dst_574") (to-u32 (get-alt "VI32" (param 0))))
                                                (if (eq (u16 19) (identifier "label1_573")) 
                                                  (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (to-i64 (get-alt "VI40" (param 0)))))
                                                  (if (eq (u16 20) (identifier "label1_573")) 
                                                    (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (to-i64 (get-alt "VI48" (param 0)))))
                                                    (if (eq (u16 21) (identifier "label1_573")) 
                                                      (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (to-i64 (get-alt "VI56" (param 0)))))
                                                      (if (eq (u16 22) (identifier "label1_573")) 
                                                        (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (get-alt "VI64" (param 0))))
                                                        (if (eq (u16 23) (identifier "label1_573")) 
                                                          (write-u128 little-endian (identifier "ssum_dst_574") (to-u128 (get-alt "VI128" (param 0))))
                                                          (if (eq (u16 24) (identifier "label1_573")) 
                                                            (write-u64 little-endian (identifier "ssum_dst_574") (to-u64 (get-alt "VEth" (param 0))))
                                                            (if (eq (u16 25) (identifier "label1_573")) 
                                                              (write-u32 little-endian (identifier "ssum_dst_574") (get-alt "VIpv4" (param 0)))
                                                              (if (eq (u16 26) (identifier "label1_573")) 
                                                                (write-u128 little-endian (identifier "ssum_dst_574") (get-alt "VIpv6" (param 0)))
                                                                (if (eq (u16 27) (identifier "label1_573"))
                                                                  (let "ssum_dst_609" 
                                                                    (write-u16 little-endian (identifier "ssum_dst_574") (label-of (get-alt "VIp" (param 0))))
                                                                    (if 
                                                                    (eq (u16 0) (label-of (get-alt "VIp" (param 0)))) 
                                                                    (write-u32 little-endian (identifier "ssum_dst_609") (get-alt "v4" (get-alt "VIp" (param 0))))
                                                                    (seq (assert (eq (label-of (get-alt "VIp" (param 0))) (u16 1))) (write-u128 little-endian (identifier "ssum_dst_609") (get-alt "v6" (get-alt "VIp" (param 0)))))))
                                                                  (if 
                                                                    (eq (u16 28) (identifier "label1_573"))
                                                                    (let "srec_dst_607" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_574") (get-field "ip" (get-alt "VCidrv4" (param 0))))
                                                                    (write-u8 (identifier "srec_dst_607") (get-field "mask" (get-alt "VCidrv4" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_573"))
                                                                    (let "srec_dst_606" 
                                                                    (write-u128 little-endian (identifier "ssum_dst_574") (get-field "ip" (get-alt "VCidrv6" (param 0))))
                                                                    (write-u8 (identifier "srec_dst_606") (get-field "mask" (get-alt "VCidrv6" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_573"))
                                                                    (let "ssum_dst_603" 
                                                                    (write-u16 little-endian (identifier "ssum_dst_574") (label-of (get-alt "VCidr" (param 0))))
                                                                    (if 
                                                                    (eq (u16 0) (label-of (get-alt "VCidr" (param 0))))
                                                                    (let "srec_dst_605" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_603") (get-field "ip" (get-alt "v4" (get-alt "VCidr" (param 0)))))
                                                                    (write-u8 (identifier "srec_dst_605") (get-field "mask" (get-alt "v4" (get-alt "VCidr" (param 0))))))
                                                                    (seq 
                                                                    (assert (eq (label-of (get-alt "VCidr" (param 0))) (u16 1)))
                                                                    (let "srec_dst_604" 
                                                                    (write-u128 little-endian (identifier "ssum_dst_603") (get-field "ip" (get-alt "v6" (get-alt "VCidr" (param 0)))))
                                                                    (write-u8 (identifier "srec_dst_604") (get-field "mask" (get-alt "v6" (get-alt "VCidr" (param 0)))))))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_573"))
                                                                    (let "dst_ref_599"
                                                                    (make-vec
                                                                    (let "leb128_sz_597" 
                                                                    (make-vec (cardinality (get-alt "VTup" (param 0))))
                                                                    (let "leb128_ptr_598" 
                                                                    (make-vec (identifier "ssum_dst_574"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_598")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_598"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_597"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_597"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_597"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_597") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_597")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_597")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_598"))))))
                                                                    (let "n_ref_600" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_601" 
                                                                    (get-alt "VTup" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_599") (apply (myself "Ptr") (identifier "x_601") (unsafe-nth (u8 0) (identifier "dst_ref_599"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_600") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_600")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_599")))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_573"))
                                                                    (let "dst_ref_594"
                                                                    (make-vec
                                                                    (let "leb128_sz_592" 
                                                                    (make-vec (cardinality (get-alt "VVec" (param 0))))
                                                                    (let "leb128_ptr_593" 
                                                                    (make-vec (identifier "ssum_dst_574"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_593")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_593"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_592"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_592"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_592"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_592") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_592")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_592")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_593"))))))
                                                                    (let "n_ref_595" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_596" 
                                                                    (get-alt "VVec" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_594") (apply (myself "Ptr") (identifier "x_596") (unsafe-nth (u8 0) (identifier "dst_ref_594"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_595") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_595")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_594")))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_573"))
                                                                    (let "dst_ref_589"
                                                                    (make-vec
                                                                    (let "leb128_sz_587" 
                                                                    (make-vec (cardinality (get-alt "VArr" (param 0))))
                                                                    (let "leb128_ptr_588" 
                                                                    (make-vec (identifier "ssum_dst_574"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_588")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_588"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_587"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_587"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_587"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_587") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_587")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_587")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_588"))))))
                                                                    (let "n_ref_590" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_591" 
                                                                    (get-alt "VArr" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_589") (apply (myself "Ptr") (identifier "x_591") (unsafe-nth (u8 0) (identifier "dst_ref_589"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_590") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_590")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_589")))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_573"))
                                                                    (let "dst_ref_584"
                                                                    (make-vec
                                                                    (let "leb128_sz_582" 
                                                                    (make-vec (cardinality (get-alt "VRec" (param 0))))
                                                                    (let "leb128_ptr_583" 
                                                                    (make-vec (identifier "ssum_dst_574"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_583")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_583"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_582"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_582"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_582"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_582") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_582")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_582")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_583"))))))
                                                                    (let "n_ref_585" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_586" 
                                                                    (get-alt "VRec" (param 0))
                                                                    (seq
                                                                    (set-vec (u8 0) (identifier "dst_ref_584") (apply (identifier "named_value-to-row-binary") (identifier "x_586") (unsafe-nth (u8 0) (identifier "dst_ref_584"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_585") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_585")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_584")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label1_573") (u16 35)))
                                                                    (let "dst_ref_577"
                                                                    (make-vec
                                                                    (let "leb128_sz_575" 
                                                                    (make-vec (cardinality (get-alt "VMap" (param 0))))
                                                                    (let "leb128_ptr_576" 
                                                                    (make-vec (identifier "ssum_dst_574"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_576")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_576"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_575"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_575"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_575"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_575") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_575")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_575")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_576"))))))
                                                                    (let "n_ref_578" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_579" 
                                                                    (get-alt "VMap" (param 0))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_577")
                                                                    (apply (myself "Ptr") (get-item 1 (identifier "x_579")) (apply (myself "Ptr") (get-item 0 (identifier "x_579")) (unsafe-nth (u8 0) (identifier "dst_ref_577")))))
                                                                    (set-vec (u8 0) (identifier "n_ref_578") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_578")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_577"))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> fun1322 { [&](std::shared_ptr<::dessser::gen::raql_value::t>  p_0, Pointer p_1) {
    uint16_t id_1323 { uint16_t((*p_0).index()) };
    Pointer let_res_1324;
    {
      uint16_t label1_573 { id_1323 };
      Pointer id_1325 { p_1.writeU16Le(label1_573) };
      Pointer let_res_1326;
      {
        Pointer ssum_dst_574 { id_1325 };
        uint16_t id_1327 { 0 };
        bool id_1328 { bool(id_1327 == label1_573) };
        Pointer choose_res_1329;
        if (id_1328) {
          choose_res_1329 = ssum_dst_574;
        } else {
          uint16_t id_1330 { 1 };
          bool id_1331 { bool(id_1330 == label1_573) };
          Pointer choose_res_1332;
          if (id_1331) {
            choose_res_1332 = ssum_dst_574;
          } else {
            uint16_t id_1333 { 2 };
            bool id_1334 { bool(id_1333 == label1_573) };
            Pointer choose_res_1335;
            if (id_1334) {
              double id_1336 { std::get<2 /* VFloat */>((*p_0)) };
              uint64_t id_1337 { qword_of_float(id_1336) };
              Pointer id_1338 { ssum_dst_574.writeU64Le(id_1337) };
              choose_res_1335 = id_1338;
            } else {
              uint16_t id_1339 { 3 };
              bool id_1340 { bool(id_1339 == label1_573) };
              Pointer choose_res_1341;
              if (id_1340) {
                std::string id_1342 { std::get<3 /* VString */>((*p_0)) };
                uint32_t id_1343 { (uint32_t)id_1342.size() };
                Vec<1, uint32_t> id_1344 {  id_1343  };
                Pointer let_res_1345;
                {
                  Vec<1, uint32_t> leb128_sz_610 { id_1344 };
                  Vec<1, Pointer> id_1346 {  ssum_dst_574  };
                  Pointer let_res_1347;
                  {
                    Vec<1, Pointer> leb128_ptr_611 { id_1346 };
                    bool while_flag_1348 { true };
                    do {
                      uint8_t id_1349 { 0 };
                      uint8_t id_1350 { 0 };
                      Pointer id_1351 { leb128_ptr_611[id_1350] };
                      uint32_t id_1352 { 128U };
                      uint8_t id_1353 { 0 };
                      uint32_t id_1354 { leb128_sz_610[id_1353] };
                      bool id_1355 { bool(id_1352 > id_1354) };
                      uint8_t choose_res_1356;
                      if (id_1355) {
                        uint8_t id_1357 { 0 };
                        uint32_t id_1358 { leb128_sz_610[id_1357] };
                        uint8_t id_1359 { uint8_t(id_1358) };
                        choose_res_1356 = id_1359;
                      } else {
                        uint8_t id_1360 { 0 };
                        uint32_t id_1361 { leb128_sz_610[id_1360] };
                        uint8_t id_1362 { uint8_t(id_1361) };
                        uint8_t id_1363 { 128 };
                        uint8_t id_1364 { uint8_t(id_1362 | id_1363) };
                        choose_res_1356 = id_1364;
                      }
                      Pointer id_1365 { id_1351.writeU8(choose_res_1356) };
                      Void id_1366 { ((void)(leb128_ptr_611[id_1349] = id_1365), ::dessser::Void()) };
                      (void)id_1366;
                      uint8_t id_1367 { 0 };
                      uint8_t id_1368 { 0 };
                      uint32_t id_1369 { leb128_sz_610[id_1368] };
                      uint8_t id_1370 { 7 };
                      uint32_t id_1371 { uint32_t(id_1369 >> id_1370) };
                      Void id_1372 { ((void)(leb128_sz_610[id_1367] = id_1371), ::dessser::Void()) };
                      (void)id_1372;
                      uint8_t id_1373 { 0 };
                      uint32_t id_1374 { leb128_sz_610[id_1373] };
                      uint32_t id_1375 { 0U };
                      bool id_1376 { bool(id_1374 > id_1375) };
                      while_flag_1348 = id_1376;
                      if (while_flag_1348) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_1348);
                    (void)::dessser::Void();
                    uint8_t id_1377 { 0 };
                    Pointer id_1378 { leb128_ptr_611[id_1377] };
                    let_res_1347 = id_1378;
                  }
                  let_res_1345 = let_res_1347;
                }
                std::string id_1379 { std::get<3 /* VString */>((*p_0)) };
                Bytes id_1380 { id_1379 };
                Pointer id_1381 { let_res_1345.writeBytes(id_1380) };
                choose_res_1341 = id_1381;
              } else {
                uint16_t id_1382 { 4 };
                bool id_1383 { bool(id_1382 == label1_573) };
                Pointer choose_res_1384;
                if (id_1383) {
                  bool id_1385 { std::get<4 /* VBool */>((*p_0)) };
                  uint8_t id_1386 { uint8_t(id_1385) };
                  Pointer id_1387 { ssum_dst_574.writeU8(id_1386) };
                  choose_res_1384 = id_1387;
                } else {
                  uint16_t id_1388 { 5 };
                  bool id_1389 { bool(id_1388 == label1_573) };
                  Pointer choose_res_1390;
                  if (id_1389) {
                    char id_1391 { std::get<5 /* VChar */>((*p_0)) };
                    uint8_t id_1392 { uint8_t(id_1391) };
                    Pointer id_1393 { ssum_dst_574.writeU8(id_1392) };
                    choose_res_1390 = id_1393;
                  } else {
                    uint16_t id_1394 { 6 };
                    bool id_1395 { bool(id_1394 == label1_573) };
                    Pointer choose_res_1396;
                    if (id_1395) {
                      uint8_t id_1397 { std::get<6 /* VU8 */>((*p_0)) };
                      Pointer id_1398 { ssum_dst_574.writeU8(id_1397) };
                      choose_res_1396 = id_1398;
                    } else {
                      uint16_t id_1399 { 7 };
                      bool id_1400 { bool(id_1399 == label1_573) };
                      Pointer choose_res_1401;
                      if (id_1400) {
                        uint16_t id_1402 { std::get<7 /* VU16 */>((*p_0)) };
                        Pointer id_1403 { ssum_dst_574.writeU16Le(id_1402) };
                        choose_res_1401 = id_1403;
                      } else {
                        uint16_t id_1404 { 8 };
                        bool id_1405 { bool(id_1404 == label1_573) };
                        Pointer choose_res_1406;
                        if (id_1405) {
                          uint32_t id_1407 { std::get<8 /* VU24 */>((*p_0)) };
                          uint32_t id_1408 { uint32_t(id_1407) };
                          Pointer id_1409 { ssum_dst_574.writeU32Le(id_1408) };
                          choose_res_1406 = id_1409;
                        } else {
                          uint16_t id_1410 { 9 };
                          bool id_1411 { bool(id_1410 == label1_573) };
                          Pointer choose_res_1412;
                          if (id_1411) {
                            uint32_t id_1413 { std::get<9 /* VU32 */>((*p_0)) };
                            Pointer id_1414 { ssum_dst_574.writeU32Le(id_1413) };
                            choose_res_1412 = id_1414;
                          } else {
                            uint16_t id_1415 { 10 };
                            bool id_1416 { bool(id_1415 == label1_573) };
                            Pointer choose_res_1417;
                            if (id_1416) {
                              uint64_t id_1418 { std::get<10 /* VU40 */>((*p_0)) };
                              uint64_t id_1419 { uint64_t(id_1418) };
                              Pointer id_1420 { ssum_dst_574.writeU64Le(id_1419) };
                              choose_res_1417 = id_1420;
                            } else {
                              uint16_t id_1421 { 11 };
                              bool id_1422 { bool(id_1421 == label1_573) };
                              Pointer choose_res_1423;
                              if (id_1422) {
                                uint64_t id_1424 { std::get<11 /* VU48 */>((*p_0)) };
                                uint64_t id_1425 { uint64_t(id_1424) };
                                Pointer id_1426 { ssum_dst_574.writeU64Le(id_1425) };
                                choose_res_1423 = id_1426;
                              } else {
                                uint16_t id_1427 { 12 };
                                bool id_1428 { bool(id_1427 == label1_573) };
                                Pointer choose_res_1429;
                                if (id_1428) {
                                  uint64_t id_1430 { std::get<12 /* VU56 */>((*p_0)) };
                                  uint64_t id_1431 { uint64_t(id_1430) };
                                  Pointer id_1432 { ssum_dst_574.writeU64Le(id_1431) };
                                  choose_res_1429 = id_1432;
                                } else {
                                  uint16_t id_1433 { 13 };
                                  bool id_1434 { bool(id_1433 == label1_573) };
                                  Pointer choose_res_1435;
                                  if (id_1434) {
                                    uint64_t id_1436 { std::get<13 /* VU64 */>((*p_0)) };
                                    Pointer id_1437 { ssum_dst_574.writeU64Le(id_1436) };
                                    choose_res_1435 = id_1437;
                                  } else {
                                    uint16_t id_1438 { 14 };
                                    bool id_1439 { bool(id_1438 == label1_573) };
                                    Pointer choose_res_1440;
                                    if (id_1439) {
                                      uint128_t id_1441 { std::get<14 /* VU128 */>((*p_0)) };
                                      Pointer id_1442 { ssum_dst_574.writeU128Le(id_1441) };
                                      choose_res_1440 = id_1442;
                                    } else {
                                      uint16_t id_1443 { 15 };
                                      bool id_1444 { bool(id_1443 == label1_573) };
                                      Pointer choose_res_1445;
                                      if (id_1444) {
                                        int8_t id_1446 { std::get<15 /* VI8 */>((*p_0)) };
                                        uint8_t id_1447 { uint8_t(id_1446) };
                                        Pointer id_1448 { ssum_dst_574.writeU8(id_1447) };
                                        choose_res_1445 = id_1448;
                                      } else {
                                        uint16_t id_1449 { 16 };
                                        bool id_1450 { bool(id_1449 == label1_573) };
                                        Pointer choose_res_1451;
                                        if (id_1450) {
                                          int16_t id_1452 { std::get<16 /* VI16 */>((*p_0)) };
                                          uint16_t id_1453 { uint16_t(id_1452) };
                                          Pointer id_1454 { ssum_dst_574.writeU16Le(id_1453) };
                                          choose_res_1451 = id_1454;
                                        } else {
                                          uint16_t id_1455 { 17 };
                                          bool id_1456 { bool(id_1455 == label1_573) };
                                          Pointer choose_res_1457;
                                          if (id_1456) {
                                            int32_t id_1458 { std::get<17 /* VI24 */>((*p_0)) };
                                            int32_t id_1459 { int32_t(id_1458) };
                                            uint32_t id_1460 { uint32_t(id_1459) };
                                            Pointer id_1461 { ssum_dst_574.writeU32Le(id_1460) };
                                            choose_res_1457 = id_1461;
                                          } else {
                                            uint16_t id_1462 { 18 };
                                            bool id_1463 { bool(id_1462 == label1_573) };
                                            Pointer choose_res_1464;
                                            if (id_1463) {
                                              int32_t id_1465 { std::get<18 /* VI32 */>((*p_0)) };
                                              uint32_t id_1466 { uint32_t(id_1465) };
                                              Pointer id_1467 { ssum_dst_574.writeU32Le(id_1466) };
                                              choose_res_1464 = id_1467;
                                            } else {
                                              uint16_t id_1468 { 19 };
                                              bool id_1469 { bool(id_1468 == label1_573) };
                                              Pointer choose_res_1470;
                                              if (id_1469) {
                                                int64_t id_1471 { std::get<19 /* VI40 */>((*p_0)) };
                                                int64_t id_1472 { int64_t(id_1471) };
                                                uint64_t id_1473 { uint64_t(id_1472) };
                                                Pointer id_1474 { ssum_dst_574.writeU64Le(id_1473) };
                                                choose_res_1470 = id_1474;
                                              } else {
                                                uint16_t id_1475 { 20 };
                                                bool id_1476 { bool(id_1475 == label1_573) };
                                                Pointer choose_res_1477;
                                                if (id_1476) {
                                                  int64_t id_1478 { std::get<20 /* VI48 */>((*p_0)) };
                                                  int64_t id_1479 { int64_t(id_1478) };
                                                  uint64_t id_1480 { uint64_t(id_1479) };
                                                  Pointer id_1481 { ssum_dst_574.writeU64Le(id_1480) };
                                                  choose_res_1477 = id_1481;
                                                } else {
                                                  uint16_t id_1482 { 21 };
                                                  bool id_1483 { bool(id_1482 == label1_573) };
                                                  Pointer choose_res_1484;
                                                  if (id_1483) {
                                                    int64_t id_1485 { std::get<21 /* VI56 */>((*p_0)) };
                                                    int64_t id_1486 { int64_t(id_1485) };
                                                    uint64_t id_1487 { uint64_t(id_1486) };
                                                    Pointer id_1488 { ssum_dst_574.writeU64Le(id_1487) };
                                                    choose_res_1484 = id_1488;
                                                  } else {
                                                    uint16_t id_1489 { 22 };
                                                    bool id_1490 { bool(id_1489 == label1_573) };
                                                    Pointer choose_res_1491;
                                                    if (id_1490) {
                                                      int64_t id_1492 { std::get<22 /* VI64 */>((*p_0)) };
                                                      uint64_t id_1493 { uint64_t(id_1492) };
                                                      Pointer id_1494 { ssum_dst_574.writeU64Le(id_1493) };
                                                      choose_res_1491 = id_1494;
                                                    } else {
                                                      uint16_t id_1495 { 23 };
                                                      bool id_1496 { bool(id_1495 == label1_573) };
                                                      Pointer choose_res_1497;
                                                      if (id_1496) {
                                                        int128_t id_1498 { std::get<23 /* VI128 */>((*p_0)) };
                                                        uint128_t id_1499 { uint128_t(id_1498) };
                                                        Pointer id_1500 { ssum_dst_574.writeU128Le(id_1499) };
                                                        choose_res_1497 = id_1500;
                                                      } else {
                                                        uint16_t id_1501 { 24 };
                                                        bool id_1502 { bool(id_1501 == label1_573) };
                                                        Pointer choose_res_1503;
                                                        if (id_1502) {
                                                          uint64_t id_1504 { std::get<24 /* VEth */>((*p_0)) };
                                                          uint64_t id_1505 { uint64_t(id_1504) };
                                                          Pointer id_1506 { ssum_dst_574.writeU64Le(id_1505) };
                                                          choose_res_1503 = id_1506;
                                                        } else {
                                                          uint16_t id_1507 { 25 };
                                                          bool id_1508 { bool(id_1507 == label1_573) };
                                                          Pointer choose_res_1509;
                                                          if (id_1508) {
                                                            uint32_t id_1510 { std::get<25 /* VIpv4 */>((*p_0)) };
                                                            Pointer id_1511 { ssum_dst_574.writeU32Le(id_1510) };
                                                            choose_res_1509 = id_1511;
                                                          } else {
                                                            uint16_t id_1512 { 26 };
                                                            bool id_1513 { bool(id_1512 == label1_573) };
                                                            Pointer choose_res_1514;
                                                            if (id_1513) {
                                                              uint128_t id_1515 { std::get<26 /* VIpv6 */>((*p_0)) };
                                                              Pointer id_1516 { ssum_dst_574.writeU128Le(id_1515) };
                                                              choose_res_1514 = id_1516;
                                                            } else {
                                                              uint16_t id_1517 { 27 };
                                                              bool id_1518 { bool(id_1517 == label1_573) };
                                                              Pointer choose_res_1519;
                                                              if (id_1518) {
                                                                ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_1520 { std::get<27 /* VIp */>((*p_0)) };
                                                                uint16_t id_1521 { uint16_t(id_1520.index()) };
                                                                Pointer id_1522 { ssum_dst_574.writeU16Le(id_1521) };
                                                                Pointer let_res_1523;
                                                                {
                                                                  Pointer ssum_dst_609 { id_1522 };
                                                                  uint16_t id_1524 { 0 };
                                                                  ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_1525 { std::get<27 /* VIp */>((*p_0)) };
                                                                  uint16_t id_1526 { uint16_t(id_1525.index()) };
                                                                  bool id_1527 { bool(id_1524 == id_1526) };
                                                                  Pointer choose_res_1528;
                                                                  if (id_1527) {
                                                                    ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_1529 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint32_t id_1530 { std::get<0 /* v4 */>(id_1529) };
                                                                    Pointer id_1531 { ssum_dst_609.writeU32Le(id_1530) };
                                                                    choose_res_1528 = id_1531;
                                                                  } else {
                                                                    ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_1532 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint16_t id_1533 { uint16_t(id_1532.index()) };
                                                                    uint16_t id_1534 { 1 };
                                                                    bool id_1535 { bool(id_1533 == id_1534) };
                                                                    Void id_1536 { ((void)(assert(id_1535)), ::dessser::Void()) };
                                                                    (void)id_1536;
                                                                    ::dessser::gen::raql_value::t690438e8d106ddec68c668ab00e5188a id_1537 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint128_t id_1538 { std::get<1 /* v6 */>(id_1537) };
                                                                    Pointer id_1539 { ssum_dst_609.writeU128Le(id_1538) };
                                                                    choose_res_1528 = id_1539;
                                                                  }
                                                                  let_res_1523 = choose_res_1528;
                                                                }
                                                                choose_res_1519 = let_res_1523;
                                                              } else {
                                                                uint16_t id_1540 { 28 };
                                                                bool id_1541 { bool(id_1540 == label1_573) };
                                                                Pointer choose_res_1542;
                                                                if (id_1541) {
                                                                  ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_1543 { std::get<28 /* VCidrv4 */>((*p_0)) };
                                                                  uint32_t id_1544 { id_1543.Cidr4_ip };
                                                                  Pointer id_1545 { ssum_dst_574.writeU32Le(id_1544) };
                                                                  Pointer let_res_1546;
                                                                  {
                                                                    Pointer srec_dst_607 { id_1545 };
                                                                    ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_1547 { std::get<28 /* VCidrv4 */>((*p_0)) };
                                                                    uint8_t id_1548 { id_1547.Cidr4_mask };
                                                                    Pointer id_1549 { srec_dst_607.writeU8(id_1548) };
                                                                    let_res_1546 = id_1549;
                                                                  }
                                                                  choose_res_1542 = let_res_1546;
                                                                } else {
                                                                  uint16_t id_1550 { 29 };
                                                                  bool id_1551 { bool(id_1550 == label1_573) };
                                                                  Pointer choose_res_1552;
                                                                  if (id_1551) {
                                                                    ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_1553 { std::get<29 /* VCidrv6 */>((*p_0)) };
                                                                    uint128_t id_1554 { id_1553.ip };
                                                                    Pointer id_1555 { ssum_dst_574.writeU128Le(id_1554) };
                                                                    Pointer let_res_1556;
                                                                    {
                                                                      Pointer srec_dst_606 { id_1555 };
                                                                      ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_1557 { std::get<29 /* VCidrv6 */>((*p_0)) };
                                                                      uint8_t id_1558 { id_1557.mask };
                                                                      Pointer id_1559 { srec_dst_606.writeU8(id_1558) };
                                                                      let_res_1556 = id_1559;
                                                                    }
                                                                    choose_res_1552 = let_res_1556;
                                                                  } else {
                                                                    uint16_t id_1560 { 30 };
                                                                    bool id_1561 { bool(id_1560 == label1_573) };
                                                                    Pointer choose_res_1562;
                                                                    if (id_1561) {
                                                                      ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_1563 { std::get<30 /* VCidr */>((*p_0)) };
                                                                      uint16_t id_1564 { uint16_t(id_1563.index()) };
                                                                      Pointer id_1565 { ssum_dst_574.writeU16Le(id_1564) };
                                                                      Pointer let_res_1566;
                                                                      {
                                                                        Pointer ssum_dst_603 { id_1565 };
                                                                        uint16_t id_1567 { 0 };
                                                                        ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_1568 { std::get<30 /* VCidr */>((*p_0)) };
                                                                        uint16_t id_1569 { uint16_t(id_1568.index()) };
                                                                        bool id_1570 { bool(id_1567 == id_1569) };
                                                                        Pointer choose_res_1571;
                                                                        if (id_1570) {
                                                                          ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_1572 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_1573 { std::get<0 /* v4 */>(id_1572) };
                                                                          uint32_t id_1574 { id_1573.Cidr4_ip };
                                                                          Pointer id_1575 { ssum_dst_603.writeU32Le(id_1574) };
                                                                          Pointer let_res_1576;
                                                                          {
                                                                            Pointer srec_dst_605 { id_1575 };
                                                                            ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_1577 { std::get<30 /* VCidr */>((*p_0)) };
                                                                            ::dessser::gen::raql_value::t5d7b802285da2586acaa54f62df2bed3 id_1578 { std::get<0 /* v4 */>(id_1577) };
                                                                            uint8_t id_1579 { id_1578.Cidr4_mask };
                                                                            Pointer id_1580 { srec_dst_605.writeU8(id_1579) };
                                                                            let_res_1576 = id_1580;
                                                                          }
                                                                          choose_res_1571 = let_res_1576;
                                                                        } else {
                                                                          ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_1581 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          uint16_t id_1582 { uint16_t(id_1581.index()) };
                                                                          uint16_t id_1583 { 1 };
                                                                          bool id_1584 { bool(id_1582 == id_1583) };
                                                                          Void id_1585 { ((void)(assert(id_1584)), ::dessser::Void()) };
                                                                          (void)id_1585;
                                                                          ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_1586 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_1587 { std::get<1 /* v6 */>(id_1586) };
                                                                          uint128_t id_1588 { id_1587.ip };
                                                                          Pointer id_1589 { ssum_dst_603.writeU128Le(id_1588) };
                                                                          Pointer let_res_1590;
                                                                          {
                                                                            Pointer srec_dst_604 { id_1589 };
                                                                            ::dessser::gen::raql_value::teb043643295bb7cc6656bec6dd6fd6e1 id_1591 { std::get<30 /* VCidr */>((*p_0)) };
                                                                            ::dessser::gen::raql_value::t44c6447d638b93b2e8d0887b360afa41 id_1592 { std::get<1 /* v6 */>(id_1591) };
                                                                            uint8_t id_1593 { id_1592.mask };
                                                                            Pointer id_1594 { srec_dst_604.writeU8(id_1593) };
                                                                            let_res_1590 = id_1594;
                                                                          }
                                                                          choose_res_1571 = let_res_1590;
                                                                        }
                                                                        let_res_1566 = choose_res_1571;
                                                                      }
                                                                      choose_res_1562 = let_res_1566;
                                                                    } else {
                                                                      uint16_t id_1595 { 31 };
                                                                      bool id_1596 { bool(id_1595 == label1_573) };
                                                                      Pointer choose_res_1597;
                                                                      if (id_1596) {
                                                                        Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1598 { std::get<31 /* VTup */>((*p_0)) };
                                                                        uint32_t id_1599 { id_1598.size() };
                                                                        Vec<1, uint32_t> id_1600 {  id_1599  };
                                                                        Pointer let_res_1601;
                                                                        {
                                                                          Vec<1, uint32_t> leb128_sz_597 { id_1600 };
                                                                          Vec<1, Pointer> id_1602 {  ssum_dst_574  };
                                                                          Pointer let_res_1603;
                                                                          {
                                                                            Vec<1, Pointer> leb128_ptr_598 { id_1602 };
                                                                            bool while_flag_1604 { true };
                                                                            do {
                                                                              uint8_t id_1605 { 0 };
                                                                              uint8_t id_1606 { 0 };
                                                                              Pointer id_1607 { leb128_ptr_598[id_1606] };
                                                                              uint32_t id_1608 { 128U };
                                                                              uint8_t id_1609 { 0 };
                                                                              uint32_t id_1610 { leb128_sz_597[id_1609] };
                                                                              bool id_1611 { bool(id_1608 > id_1610) };
                                                                              uint8_t choose_res_1612;
                                                                              if (id_1611) {
                                                                                uint8_t id_1613 { 0 };
                                                                                uint32_t id_1614 { leb128_sz_597[id_1613] };
                                                                                uint8_t id_1615 { uint8_t(id_1614) };
                                                                                choose_res_1612 = id_1615;
                                                                              } else {
                                                                                uint8_t id_1616 { 0 };
                                                                                uint32_t id_1617 { leb128_sz_597[id_1616] };
                                                                                uint8_t id_1618 { uint8_t(id_1617) };
                                                                                uint8_t id_1619 { 128 };
                                                                                uint8_t id_1620 { uint8_t(id_1618 | id_1619) };
                                                                                choose_res_1612 = id_1620;
                                                                              }
                                                                              Pointer id_1621 { id_1607.writeU8(choose_res_1612) };
                                                                              Void id_1622 { ((void)(leb128_ptr_598[id_1605] = id_1621), ::dessser::Void()) };
                                                                              (void)id_1622;
                                                                              uint8_t id_1623 { 0 };
                                                                              uint8_t id_1624 { 0 };
                                                                              uint32_t id_1625 { leb128_sz_597[id_1624] };
                                                                              uint8_t id_1626 { 7 };
                                                                              uint32_t id_1627 { uint32_t(id_1625 >> id_1626) };
                                                                              Void id_1628 { ((void)(leb128_sz_597[id_1623] = id_1627), ::dessser::Void()) };
                                                                              (void)id_1628;
                                                                              uint8_t id_1629 { 0 };
                                                                              uint32_t id_1630 { leb128_sz_597[id_1629] };
                                                                              uint32_t id_1631 { 0U };
                                                                              bool id_1632 { bool(id_1630 > id_1631) };
                                                                              while_flag_1604 = id_1632;
                                                                              if (while_flag_1604) {
                                                                                (void)::dessser::Void();
                                                                              }
                                                                            } while (while_flag_1604);
                                                                            (void)::dessser::Void();
                                                                            uint8_t id_1633 { 0 };
                                                                            Pointer id_1634 { leb128_ptr_598[id_1633] };
                                                                            let_res_1603 = id_1634;
                                                                          }
                                                                          let_res_1601 = let_res_1603;
                                                                        }
                                                                        Vec<1, Pointer> id_1635 {  let_res_1601  };
                                                                        Pointer let_res_1636;
                                                                        {
                                                                          Vec<1, Pointer> dst_ref_599 { id_1635 };
                                                                          int32_t id_1637 { 0L };
                                                                          Vec<1, int32_t> id_1638 {  id_1637  };
                                                                          Pointer let_res_1639;
                                                                          {
                                                                            Vec<1, int32_t> n_ref_600 { id_1638 };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1640 { std::get<31 /* VTup */>((*p_0)) };
                                                                            for (std::shared_ptr<::dessser::gen::raql_value::t>  &x_601 : id_1640) {
                                                                              uint8_t id_1641 { 0 };
                                                                              uint8_t id_1642 { 0 };
                                                                              Pointer id_1643 { dst_ref_599[id_1642] };
                                                                              Pointer id_1644 { fun1322(x_601, id_1643) };
                                                                              Void id_1645 { ((void)(dst_ref_599[id_1641] = id_1644), ::dessser::Void()) };
                                                                              (void)id_1645;
                                                                              uint8_t id_1646 { 0 };
                                                                              int32_t id_1647 { 1L };
                                                                              uint8_t id_1648 { 0 };
                                                                              int32_t id_1649 { n_ref_600[id_1648] };
                                                                              int32_t id_1650 { int32_t(id_1647 + id_1649) };
                                                                              Void id_1651 { ((void)(n_ref_600[id_1646] = id_1650), ::dessser::Void()) };
                                                                              (void)id_1651;
                                                                              (void)id_1651;
                                                                            }
                                                                            (void)::dessser::Void();
                                                                            uint8_t id_1652 { 0 };
                                                                            Pointer id_1653 { dst_ref_599[id_1652] };
                                                                            let_res_1639 = id_1653;
                                                                          }
                                                                          let_res_1636 = let_res_1639;
                                                                        }
                                                                        choose_res_1597 = let_res_1636;
                                                                      } else {
                                                                        uint16_t id_1654 { 32 };
                                                                        bool id_1655 { bool(id_1654 == label1_573) };
                                                                        Pointer choose_res_1656;
                                                                        if (id_1655) {
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1657 { std::get<32 /* VVec */>((*p_0)) };
                                                                          uint32_t id_1658 { id_1657.size() };
                                                                          Vec<1, uint32_t> id_1659 {  id_1658  };
                                                                          Pointer let_res_1660;
                                                                          {
                                                                            Vec<1, uint32_t> leb128_sz_592 { id_1659 };
                                                                            Vec<1, Pointer> id_1661 {  ssum_dst_574  };
                                                                            Pointer let_res_1662;
                                                                            {
                                                                              Vec<1, Pointer> leb128_ptr_593 { id_1661 };
                                                                              bool while_flag_1663 { true };
                                                                              do {
                                                                                uint8_t id_1664 { 0 };
                                                                                uint8_t id_1665 { 0 };
                                                                                Pointer id_1666 { leb128_ptr_593[id_1665] };
                                                                                uint32_t id_1667 { 128U };
                                                                                uint8_t id_1668 { 0 };
                                                                                uint32_t id_1669 { leb128_sz_592[id_1668] };
                                                                                bool id_1670 { bool(id_1667 > id_1669) };
                                                                                uint8_t choose_res_1671;
                                                                                if (id_1670) {
                                                                                  uint8_t id_1672 { 0 };
                                                                                  uint32_t id_1673 { leb128_sz_592[id_1672] };
                                                                                  uint8_t id_1674 { uint8_t(id_1673) };
                                                                                  choose_res_1671 = id_1674;
                                                                                } else {
                                                                                  uint8_t id_1675 { 0 };
                                                                                  uint32_t id_1676 { leb128_sz_592[id_1675] };
                                                                                  uint8_t id_1677 { uint8_t(id_1676) };
                                                                                  uint8_t id_1678 { 128 };
                                                                                  uint8_t id_1679 { uint8_t(id_1677 | id_1678) };
                                                                                  choose_res_1671 = id_1679;
                                                                                }
                                                                                Pointer id_1680 { id_1666.writeU8(choose_res_1671) };
                                                                                Void id_1681 { ((void)(leb128_ptr_593[id_1664] = id_1680), ::dessser::Void()) };
                                                                                (void)id_1681;
                                                                                uint8_t id_1682 { 0 };
                                                                                uint8_t id_1683 { 0 };
                                                                                uint32_t id_1684 { leb128_sz_592[id_1683] };
                                                                                uint8_t id_1685 { 7 };
                                                                                uint32_t id_1686 { uint32_t(id_1684 >> id_1685) };
                                                                                Void id_1687 { ((void)(leb128_sz_592[id_1682] = id_1686), ::dessser::Void()) };
                                                                                (void)id_1687;
                                                                                uint8_t id_1688 { 0 };
                                                                                uint32_t id_1689 { leb128_sz_592[id_1688] };
                                                                                uint32_t id_1690 { 0U };
                                                                                bool id_1691 { bool(id_1689 > id_1690) };
                                                                                while_flag_1663 = id_1691;
                                                                                if (while_flag_1663) {
                                                                                  (void)::dessser::Void();
                                                                                }
                                                                              } while (while_flag_1663);
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_1692 { 0 };
                                                                              Pointer id_1693 { leb128_ptr_593[id_1692] };
                                                                              let_res_1662 = id_1693;
                                                                            }
                                                                            let_res_1660 = let_res_1662;
                                                                          }
                                                                          Vec<1, Pointer> id_1694 {  let_res_1660  };
                                                                          Pointer let_res_1695;
                                                                          {
                                                                            Vec<1, Pointer> dst_ref_594 { id_1694 };
                                                                            int32_t id_1696 { 0L };
                                                                            Vec<1, int32_t> id_1697 {  id_1696  };
                                                                            Pointer let_res_1698;
                                                                            {
                                                                              Vec<1, int32_t> n_ref_595 { id_1697 };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1699 { std::get<32 /* VVec */>((*p_0)) };
                                                                              for (std::shared_ptr<::dessser::gen::raql_value::t>  &x_596 : id_1699) {
                                                                                uint8_t id_1700 { 0 };
                                                                                uint8_t id_1701 { 0 };
                                                                                Pointer id_1702 { dst_ref_594[id_1701] };
                                                                                Pointer id_1703 { fun1322(x_596, id_1702) };
                                                                                Void id_1704 { ((void)(dst_ref_594[id_1700] = id_1703), ::dessser::Void()) };
                                                                                (void)id_1704;
                                                                                uint8_t id_1705 { 0 };
                                                                                int32_t id_1706 { 1L };
                                                                                uint8_t id_1707 { 0 };
                                                                                int32_t id_1708 { n_ref_595[id_1707] };
                                                                                int32_t id_1709 { int32_t(id_1706 + id_1708) };
                                                                                Void id_1710 { ((void)(n_ref_595[id_1705] = id_1709), ::dessser::Void()) };
                                                                                (void)id_1710;
                                                                                (void)id_1710;
                                                                              }
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_1711 { 0 };
                                                                              Pointer id_1712 { dst_ref_594[id_1711] };
                                                                              let_res_1698 = id_1712;
                                                                            }
                                                                            let_res_1695 = let_res_1698;
                                                                          }
                                                                          choose_res_1656 = let_res_1695;
                                                                        } else {
                                                                          uint16_t id_1713 { 33 };
                                                                          bool id_1714 { bool(id_1713 == label1_573) };
                                                                          Pointer choose_res_1715;
                                                                          if (id_1714) {
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1716 { std::get<33 /* VArr */>((*p_0)) };
                                                                            uint32_t id_1717 { id_1716.size() };
                                                                            Vec<1, uint32_t> id_1718 {  id_1717  };
                                                                            Pointer let_res_1719;
                                                                            {
                                                                              Vec<1, uint32_t> leb128_sz_587 { id_1718 };
                                                                              Vec<1, Pointer> id_1720 {  ssum_dst_574  };
                                                                              Pointer let_res_1721;
                                                                              {
                                                                                Vec<1, Pointer> leb128_ptr_588 { id_1720 };
                                                                                bool while_flag_1722 { true };
                                                                                do {
                                                                                  uint8_t id_1723 { 0 };
                                                                                  uint8_t id_1724 { 0 };
                                                                                  Pointer id_1725 { leb128_ptr_588[id_1724] };
                                                                                  uint32_t id_1726 { 128U };
                                                                                  uint8_t id_1727 { 0 };
                                                                                  uint32_t id_1728 { leb128_sz_587[id_1727] };
                                                                                  bool id_1729 { bool(id_1726 > id_1728) };
                                                                                  uint8_t choose_res_1730;
                                                                                  if (id_1729) {
                                                                                    uint8_t id_1731 { 0 };
                                                                                    uint32_t id_1732 { leb128_sz_587[id_1731] };
                                                                                    uint8_t id_1733 { uint8_t(id_1732) };
                                                                                    choose_res_1730 = id_1733;
                                                                                  } else {
                                                                                    uint8_t id_1734 { 0 };
                                                                                    uint32_t id_1735 { leb128_sz_587[id_1734] };
                                                                                    uint8_t id_1736 { uint8_t(id_1735) };
                                                                                    uint8_t id_1737 { 128 };
                                                                                    uint8_t id_1738 { uint8_t(id_1736 | id_1737) };
                                                                                    choose_res_1730 = id_1738;
                                                                                  }
                                                                                  Pointer id_1739 { id_1725.writeU8(choose_res_1730) };
                                                                                  Void id_1740 { ((void)(leb128_ptr_588[id_1723] = id_1739), ::dessser::Void()) };
                                                                                  (void)id_1740;
                                                                                  uint8_t id_1741 { 0 };
                                                                                  uint8_t id_1742 { 0 };
                                                                                  uint32_t id_1743 { leb128_sz_587[id_1742] };
                                                                                  uint8_t id_1744 { 7 };
                                                                                  uint32_t id_1745 { uint32_t(id_1743 >> id_1744) };
                                                                                  Void id_1746 { ((void)(leb128_sz_587[id_1741] = id_1745), ::dessser::Void()) };
                                                                                  (void)id_1746;
                                                                                  uint8_t id_1747 { 0 };
                                                                                  uint32_t id_1748 { leb128_sz_587[id_1747] };
                                                                                  uint32_t id_1749 { 0U };
                                                                                  bool id_1750 { bool(id_1748 > id_1749) };
                                                                                  while_flag_1722 = id_1750;
                                                                                  if (while_flag_1722) {
                                                                                    (void)::dessser::Void();
                                                                                  }
                                                                                } while (while_flag_1722);
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_1751 { 0 };
                                                                                Pointer id_1752 { leb128_ptr_588[id_1751] };
                                                                                let_res_1721 = id_1752;
                                                                              }
                                                                              let_res_1719 = let_res_1721;
                                                                            }
                                                                            Vec<1, Pointer> id_1753 {  let_res_1719  };
                                                                            Pointer let_res_1754;
                                                                            {
                                                                              Vec<1, Pointer> dst_ref_589 { id_1753 };
                                                                              int32_t id_1755 { 0L };
                                                                              Vec<1, int32_t> id_1756 {  id_1755  };
                                                                              Pointer let_res_1757;
                                                                              {
                                                                                Vec<1, int32_t> n_ref_590 { id_1756 };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1758 { std::get<33 /* VArr */>((*p_0)) };
                                                                                for (std::shared_ptr<::dessser::gen::raql_value::t>  &x_591 : id_1758) {
                                                                                  uint8_t id_1759 { 0 };
                                                                                  uint8_t id_1760 { 0 };
                                                                                  Pointer id_1761 { dst_ref_589[id_1760] };
                                                                                  Pointer id_1762 { fun1322(x_591, id_1761) };
                                                                                  Void id_1763 { ((void)(dst_ref_589[id_1759] = id_1762), ::dessser::Void()) };
                                                                                  (void)id_1763;
                                                                                  uint8_t id_1764 { 0 };
                                                                                  int32_t id_1765 { 1L };
                                                                                  uint8_t id_1766 { 0 };
                                                                                  int32_t id_1767 { n_ref_590[id_1766] };
                                                                                  int32_t id_1768 { int32_t(id_1765 + id_1767) };
                                                                                  Void id_1769 { ((void)(n_ref_590[id_1764] = id_1768), ::dessser::Void()) };
                                                                                  (void)id_1769;
                                                                                  (void)id_1769;
                                                                                }
                                                                                (void)::dessser::Void();
                                                                                uint8_t id_1770 { 0 };
                                                                                Pointer id_1771 { dst_ref_589[id_1770] };
                                                                                let_res_1757 = id_1771;
                                                                              }
                                                                              let_res_1754 = let_res_1757;
                                                                            }
                                                                            choose_res_1715 = let_res_1754;
                                                                          } else {
                                                                            uint16_t id_1772 { 34 };
                                                                            bool id_1773 { bool(id_1772 == label1_573) };
                                                                            Pointer choose_res_1774;
                                                                            if (id_1773) {
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1775 { std::get<34 /* VRec */>((*p_0)) };
                                                                              uint32_t id_1776 { id_1775.size() };
                                                                              Vec<1, uint32_t> id_1777 {  id_1776  };
                                                                              Pointer let_res_1778;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_582 { id_1777 };
                                                                                Vec<1, Pointer> id_1779 {  ssum_dst_574  };
                                                                                Pointer let_res_1780;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_583 { id_1779 };
                                                                                  bool while_flag_1781 { true };
                                                                                  do {
                                                                                    uint8_t id_1782 { 0 };
                                                                                    uint8_t id_1783 { 0 };
                                                                                    Pointer id_1784 { leb128_ptr_583[id_1783] };
                                                                                    uint32_t id_1785 { 128U };
                                                                                    uint8_t id_1786 { 0 };
                                                                                    uint32_t id_1787 { leb128_sz_582[id_1786] };
                                                                                    bool id_1788 { bool(id_1785 > id_1787) };
                                                                                    uint8_t choose_res_1789;
                                                                                    if (id_1788) {
                                                                                      uint8_t id_1790 { 0 };
                                                                                      uint32_t id_1791 { leb128_sz_582[id_1790] };
                                                                                      uint8_t id_1792 { uint8_t(id_1791) };
                                                                                      choose_res_1789 = id_1792;
                                                                                    } else {
                                                                                      uint8_t id_1793 { 0 };
                                                                                      uint32_t id_1794 { leb128_sz_582[id_1793] };
                                                                                      uint8_t id_1795 { uint8_t(id_1794) };
                                                                                      uint8_t id_1796 { 128 };
                                                                                      uint8_t id_1797 { uint8_t(id_1795 | id_1796) };
                                                                                      choose_res_1789 = id_1797;
                                                                                    }
                                                                                    Pointer id_1798 { id_1784.writeU8(choose_res_1789) };
                                                                                    Void id_1799 { ((void)(leb128_ptr_583[id_1782] = id_1798), ::dessser::Void()) };
                                                                                    (void)id_1799;
                                                                                    uint8_t id_1800 { 0 };
                                                                                    uint8_t id_1801 { 0 };
                                                                                    uint32_t id_1802 { leb128_sz_582[id_1801] };
                                                                                    uint8_t id_1803 { 7 };
                                                                                    uint32_t id_1804 { uint32_t(id_1802 >> id_1803) };
                                                                                    Void id_1805 { ((void)(leb128_sz_582[id_1800] = id_1804), ::dessser::Void()) };
                                                                                    (void)id_1805;
                                                                                    uint8_t id_1806 { 0 };
                                                                                    uint32_t id_1807 { leb128_sz_582[id_1806] };
                                                                                    uint32_t id_1808 { 0U };
                                                                                    bool id_1809 { bool(id_1807 > id_1808) };
                                                                                    while_flag_1781 = id_1809;
                                                                                    if (while_flag_1781) {
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                  } while (while_flag_1781);
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1810 { 0 };
                                                                                  Pointer id_1811 { leb128_ptr_583[id_1810] };
                                                                                  let_res_1780 = id_1811;
                                                                                }
                                                                                let_res_1778 = let_res_1780;
                                                                              }
                                                                              Vec<1, Pointer> id_1812 {  let_res_1778  };
                                                                              Pointer let_res_1813;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_584 { id_1812 };
                                                                                int32_t id_1814 { 0L };
                                                                                Vec<1, int32_t> id_1815 {  id_1814  };
                                                                                Pointer let_res_1816;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_585 { id_1815 };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1817 { std::get<34 /* VRec */>((*p_0)) };
                                                                                  for (std::shared_ptr<::dessser::gen::raql_value::named_value>  &x_586 : id_1817) {
                                                                                    uint8_t id_1818 { 0 };
                                                                                    uint8_t id_1819 { 0 };
                                                                                    Pointer id_1820 { dst_ref_584[id_1819] };
                                                                                    Pointer id_1821 { named_value_to_row_binary(x_586, id_1820) };
                                                                                    Void id_1822 { ((void)(dst_ref_584[id_1818] = id_1821), ::dessser::Void()) };
                                                                                    (void)id_1822;
                                                                                    uint8_t id_1823 { 0 };
                                                                                    int32_t id_1824 { 1L };
                                                                                    uint8_t id_1825 { 0 };
                                                                                    int32_t id_1826 { n_ref_585[id_1825] };
                                                                                    int32_t id_1827 { int32_t(id_1824 + id_1826) };
                                                                                    Void id_1828 { ((void)(n_ref_585[id_1823] = id_1827), ::dessser::Void()) };
                                                                                    (void)id_1828;
                                                                                    (void)id_1828;
                                                                                  }
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1829 { 0 };
                                                                                  Pointer id_1830 { dst_ref_584[id_1829] };
                                                                                  let_res_1816 = id_1830;
                                                                                }
                                                                                let_res_1813 = let_res_1816;
                                                                              }
                                                                              choose_res_1774 = let_res_1813;
                                                                            } else {
                                                                              uint16_t id_1831 { 35 };
                                                                              bool id_1832 { bool(label1_573 == id_1831) };
                                                                              Void id_1833 { ((void)(assert(id_1832)), ::dessser::Void()) };
                                                                              (void)id_1833;
                                                                              Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_1834 { std::get<35 /* VMap */>((*p_0)) };
                                                                              uint32_t id_1835 { id_1834.size() };
                                                                              Vec<1, uint32_t> id_1836 {  id_1835  };
                                                                              Pointer let_res_1837;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_575 { id_1836 };
                                                                                Vec<1, Pointer> id_1838 {  ssum_dst_574  };
                                                                                Pointer let_res_1839;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_576 { id_1838 };
                                                                                  bool while_flag_1840 { true };
                                                                                  do {
                                                                                    uint8_t id_1841 { 0 };
                                                                                    uint8_t id_1842 { 0 };
                                                                                    Pointer id_1843 { leb128_ptr_576[id_1842] };
                                                                                    uint32_t id_1844 { 128U };
                                                                                    uint8_t id_1845 { 0 };
                                                                                    uint32_t id_1846 { leb128_sz_575[id_1845] };
                                                                                    bool id_1847 { bool(id_1844 > id_1846) };
                                                                                    uint8_t choose_res_1848;
                                                                                    if (id_1847) {
                                                                                      uint8_t id_1849 { 0 };
                                                                                      uint32_t id_1850 { leb128_sz_575[id_1849] };
                                                                                      uint8_t id_1851 { uint8_t(id_1850) };
                                                                                      choose_res_1848 = id_1851;
                                                                                    } else {
                                                                                      uint8_t id_1852 { 0 };
                                                                                      uint32_t id_1853 { leb128_sz_575[id_1852] };
                                                                                      uint8_t id_1854 { uint8_t(id_1853) };
                                                                                      uint8_t id_1855 { 128 };
                                                                                      uint8_t id_1856 { uint8_t(id_1854 | id_1855) };
                                                                                      choose_res_1848 = id_1856;
                                                                                    }
                                                                                    Pointer id_1857 { id_1843.writeU8(choose_res_1848) };
                                                                                    Void id_1858 { ((void)(leb128_ptr_576[id_1841] = id_1857), ::dessser::Void()) };
                                                                                    (void)id_1858;
                                                                                    uint8_t id_1859 { 0 };
                                                                                    uint8_t id_1860 { 0 };
                                                                                    uint32_t id_1861 { leb128_sz_575[id_1860] };
                                                                                    uint8_t id_1862 { 7 };
                                                                                    uint32_t id_1863 { uint32_t(id_1861 >> id_1862) };
                                                                                    Void id_1864 { ((void)(leb128_sz_575[id_1859] = id_1863), ::dessser::Void()) };
                                                                                    (void)id_1864;
                                                                                    uint8_t id_1865 { 0 };
                                                                                    uint32_t id_1866 { leb128_sz_575[id_1865] };
                                                                                    uint32_t id_1867 { 0U };
                                                                                    bool id_1868 { bool(id_1866 > id_1867) };
                                                                                    while_flag_1840 = id_1868;
                                                                                    if (while_flag_1840) {
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                  } while (while_flag_1840);
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1869 { 0 };
                                                                                  Pointer id_1870 { leb128_ptr_576[id_1869] };
                                                                                  let_res_1839 = id_1870;
                                                                                }
                                                                                let_res_1837 = let_res_1839;
                                                                              }
                                                                              Vec<1, Pointer> id_1871 {  let_res_1837  };
                                                                              Pointer let_res_1872;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_577 { id_1871 };
                                                                                int32_t id_1873 { 0L };
                                                                                Vec<1, int32_t> id_1874 {  id_1873  };
                                                                                Pointer let_res_1875;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_578 { id_1874 };
                                                                                  Arr<::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f> id_1876 { std::get<35 /* VMap */>((*p_0)) };
                                                                                  for (::dessser::gen::raql_value::ta4246d307efc26a581b0c83fdec1c21f &x_579 : id_1876) {
                                                                                    uint8_t id_1877 { 0 };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1878 { std::get<1>(x_579) };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1879 { std::get<0>(x_579) };
                                                                                    uint8_t id_1880 { 0 };
                                                                                    Pointer id_1881 { dst_ref_577[id_1880] };
                                                                                    Pointer id_1882 { fun1322(id_1879, id_1881) };
                                                                                    Pointer id_1883 { fun1322(id_1878, id_1882) };
                                                                                    Void id_1884 { ((void)(dst_ref_577[id_1877] = id_1883), ::dessser::Void()) };
                                                                                    (void)id_1884;
                                                                                    uint8_t id_1885 { 0 };
                                                                                    int32_t id_1886 { 1L };
                                                                                    uint8_t id_1887 { 0 };
                                                                                    int32_t id_1888 { n_ref_578[id_1887] };
                                                                                    int32_t id_1889 { int32_t(id_1886 + id_1888) };
                                                                                    Void id_1890 { ((void)(n_ref_578[id_1885] = id_1889), ::dessser::Void()) };
                                                                                    (void)id_1890;
                                                                                    (void)id_1890;
                                                                                  }
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1891 { 0 };
                                                                                  Pointer id_1892 { dst_ref_577[id_1891] };
                                                                                  let_res_1875 = id_1892;
                                                                                }
                                                                                let_res_1872 = let_res_1875;
                                                                              }
                                                                              choose_res_1774 = let_res_1872;
                                                                            }
                                                                            choose_res_1715 = choose_res_1774;
                                                                          }
                                                                          choose_res_1656 = choose_res_1715;
                                                                        }
                                                                        choose_res_1597 = choose_res_1656;
                                                                      }
                                                                      choose_res_1562 = choose_res_1597;
                                                                    }
                                                                    choose_res_1552 = choose_res_1562;
                                                                  }
                                                                  choose_res_1542 = choose_res_1552;
                                                                }
                                                                choose_res_1519 = choose_res_1542;
                                                              }
                                                              choose_res_1514 = choose_res_1519;
                                                            }
                                                            choose_res_1509 = choose_res_1514;
                                                          }
                                                          choose_res_1503 = choose_res_1509;
                                                        }
                                                        choose_res_1497 = choose_res_1503;
                                                      }
                                                      choose_res_1491 = choose_res_1497;
                                                    }
                                                    choose_res_1484 = choose_res_1491;
                                                  }
                                                  choose_res_1477 = choose_res_1484;
                                                }
                                                choose_res_1470 = choose_res_1477;
                                              }
                                              choose_res_1464 = choose_res_1470;
                                            }
                                            choose_res_1457 = choose_res_1464;
                                          }
                                          choose_res_1451 = choose_res_1457;
                                        }
                                        choose_res_1445 = choose_res_1451;
                                      }
                                      choose_res_1440 = choose_res_1445;
                                    }
                                    choose_res_1435 = choose_res_1440;
                                  }
                                  choose_res_1429 = choose_res_1435;
                                }
                                choose_res_1423 = choose_res_1429;
                              }
                              choose_res_1417 = choose_res_1423;
                            }
                            choose_res_1412 = choose_res_1417;
                          }
                          choose_res_1406 = choose_res_1412;
                        }
                        choose_res_1401 = choose_res_1406;
                      }
                      choose_res_1396 = choose_res_1401;
                    }
                    choose_res_1390 = choose_res_1396;
                  }
                  choose_res_1384 = choose_res_1390;
                }
                choose_res_1341 = choose_res_1384;
              }
              choose_res_1335 = choose_res_1341;
            }
            choose_res_1332 = choose_res_1335;
          }
          choose_res_1329 = choose_res_1332;
        }
        let_res_1326 = choose_res_1329;
      }
      let_res_1324 = let_res_1326;
    }
    return let_res_1324;
  }
   };
  return fun1322;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("(STRING; THIS)" "Ptr")
      (let "stup_dst_572"
        (write-bytes
          (let "leb128_sz_570" (make-vec (string-length (get-item 0 (param 0))))
            (let "leb128_ptr_571" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_571")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_571"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_570"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_570"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_570"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_570") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_570")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_570")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_571"))))) 
          (bytes-of-string (get-item 0 (param 0)))) (apply (identifier "to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_572"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> named_value_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> fun1893 { [&](std::shared_ptr<::dessser::gen::raql_value::named_value>  p_0, Pointer p_1) {
    std::string id_1894 { std::get<0>((*p_0)) };
    uint32_t id_1895 { (uint32_t)id_1894.size() };
    Vec<1, uint32_t> id_1896 {  id_1895  };
    Pointer let_res_1897;
    {
      Vec<1, uint32_t> leb128_sz_570 { id_1896 };
      Vec<1, Pointer> id_1898 {  p_1  };
      Pointer let_res_1899;
      {
        Vec<1, Pointer> leb128_ptr_571 { id_1898 };
        bool while_flag_1900 { true };
        do {
          uint8_t id_1901 { 0 };
          uint8_t id_1902 { 0 };
          Pointer id_1903 { leb128_ptr_571[id_1902] };
          uint32_t id_1904 { 128U };
          uint8_t id_1905 { 0 };
          uint32_t id_1906 { leb128_sz_570[id_1905] };
          bool id_1907 { bool(id_1904 > id_1906) };
          uint8_t choose_res_1908;
          if (id_1907) {
            uint8_t id_1909 { 0 };
            uint32_t id_1910 { leb128_sz_570[id_1909] };
            uint8_t id_1911 { uint8_t(id_1910) };
            choose_res_1908 = id_1911;
          } else {
            uint8_t id_1912 { 0 };
            uint32_t id_1913 { leb128_sz_570[id_1912] };
            uint8_t id_1914 { uint8_t(id_1913) };
            uint8_t id_1915 { 128 };
            uint8_t id_1916 { uint8_t(id_1914 | id_1915) };
            choose_res_1908 = id_1916;
          }
          Pointer id_1917 { id_1903.writeU8(choose_res_1908) };
          Void id_1918 { ((void)(leb128_ptr_571[id_1901] = id_1917), ::dessser::Void()) };
          (void)id_1918;
          uint8_t id_1919 { 0 };
          uint8_t id_1920 { 0 };
          uint32_t id_1921 { leb128_sz_570[id_1920] };
          uint8_t id_1922 { 7 };
          uint32_t id_1923 { uint32_t(id_1921 >> id_1922) };
          Void id_1924 { ((void)(leb128_sz_570[id_1919] = id_1923), ::dessser::Void()) };
          (void)id_1924;
          uint8_t id_1925 { 0 };
          uint32_t id_1926 { leb128_sz_570[id_1925] };
          uint32_t id_1927 { 0U };
          bool id_1928 { bool(id_1926 > id_1927) };
          while_flag_1900 = id_1928;
          if (while_flag_1900) {
            (void)::dessser::Void();
          }
        } while (while_flag_1900);
        (void)::dessser::Void();
        uint8_t id_1929 { 0 };
        Pointer id_1930 { leb128_ptr_571[id_1929] };
        let_res_1899 = id_1930;
      }
      let_res_1897 = let_res_1899;
    }
    std::string id_1931 { std::get<0>((*p_0)) };
    Bytes id_1932 { id_1931 };
    Pointer id_1933 { let_res_1897.writeBytes(id_1932) };
    Pointer let_res_1934;
    {
      Pointer stup_dst_572 { id_1933 };
      std::shared_ptr<::dessser::gen::raql_value::t>  id_1935 { std::get<1>((*p_0)) };
      Pointer id_1936 { to_row_binary(id_1935, stup_dst_572) };
      let_res_1934 = id_1936;
    }
    return let_res_1934;
  }
   };
  return fun1893;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> named_value_to_row_binary(named_value_to_row_binary_init());

/* 
    (fun ("[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> fun1937 { [&](std::shared_ptr<::dessser::gen::raql_value::t>  p_0, Pointer p_1) {
    Pointer id_1938 { to_row_binary(p_0, p_1) };
    return id_1938;
  }
   };
  return fun1937;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
