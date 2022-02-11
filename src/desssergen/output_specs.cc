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
#include "desssergen/raql_value.h"
#include "desssergen/fieldmask.h"
#include "desssergen/sync_key.h"
#include "desssergen/file_path.h"

namespace dessser::gen::output_specs {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

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
struct ta86dfe69264c9600d57a3b5ead0f7951 {
  bool with_index;
  uint32_t batch_size;
  uint32_t num_batches;
  ta86dfe69264c9600d57a3b5ead0f7951(bool with_index_, uint32_t batch_size_, uint32_t num_batches_) : with_index(with_index_), batch_size(batch_size_), num_batches(num_batches_) {}
  ta86dfe69264c9600d57a3b5ead0f7951() = default;
};
inline bool operator==(ta86dfe69264c9600d57a3b5ead0f7951 const &a, ta86dfe69264c9600d57a3b5ead0f7951 const &b) {
  return a.with_index == b.with_index && a.batch_size == b.batch_size && a.num_batches == b.num_batches;
}

inline bool operator!=(ta86dfe69264c9600d57a3b5ead0f7951 const &a, ta86dfe69264c9600d57a3b5ead0f7951 const &b) {
  return !operator==(a, b);
}
struct file_type : public std::variant<
  Void, // RingBuf
  ::dessser::gen::output_specs::ta86dfe69264c9600d57a3b5ead0f7951 // Orc
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
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
struct recipient : public std::variant<
  dessser::gen::file_path::t_ext, // DirectFile
  std::string, // IndirectFile
  dessser::gen::sync_key::t_ext // SyncKey
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

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
struct te2535d14520252a621d726d279906e71 : public std::tuple<
  uint16_t,
  ::dessser::gen::output_specs::channel_specs
> {
  using tuple::tuple;
};
inline bool operator==(te2535d14520252a621d726d279906e71 const &a, te2535d14520252a621d726d279906e71 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te2535d14520252a621d726d279906e71 const &a, te2535d14520252a621d726d279906e71 const &b) {
  return !operator==(a, b);
}
struct t6f037f9cb4c8fd79d46fb7db1c2b9a46 : public std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> {
  using tuple::tuple;
};
inline bool operator==(t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &a, t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &a, t6f037f9cb4c8fd79d46fb7db1c2b9a46 const &b) {
  return !operator==(a, b);
}
struct t6d8876cd95eb52df46270873f955e58e {
  ::dessser::gen::output_specs::file_type file_type;
  dessser::gen::fieldmask::t_ext fieldmask;
  Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> filters;
  Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> channels;
  t6d8876cd95eb52df46270873f955e58e(::dessser::gen::output_specs::file_type file_type_, dessser::gen::fieldmask::t_ext fieldmask_, Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> filters_, Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> channels_) : file_type(file_type_), fieldmask(fieldmask_), filters(filters_), channels(channels_) {}
  t6d8876cd95eb52df46270873f955e58e() = default;
};
inline bool operator==(t6d8876cd95eb52df46270873f955e58e const &a, t6d8876cd95eb52df46270873f955e58e const &b) {
  return a.file_type == b.file_type && ::dessser::gen::fieldmask::Deref(a.fieldmask) == ::dessser::gen::fieldmask::Deref(b.fieldmask) && a.filters == b.filters && a.channels == b.channels;
}

inline bool operator!=(t6d8876cd95eb52df46270873f955e58e const &a, t6d8876cd95eb52df46270873f955e58e const &b) {
  return !operator==(a, b);
}
struct t132ce9f388dc6ee5c0fd05918c829523 : public std::tuple<
  ::dessser::gen::output_specs::recipient,
  ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e
> {
  using tuple::tuple;
};
inline bool operator==(t132ce9f388dc6ee5c0fd05918c829523 const &a, t132ce9f388dc6ee5c0fd05918c829523 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t132ce9f388dc6ee5c0fd05918c829523 const &a, t132ce9f388dc6ee5c0fd05918c829523 const &b) {
  return !operator==(a, b);
}
typedef Arr<::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523> t;
struct t7ce21e44309db7c6914cc41eb440af04 : public std::tuple<
  ::dessser::gen::output_specs::channel_specs,
  Pointer
> {
  using tuple::tuple;
  t7ce21e44309db7c6914cc41eb440af04(std::tuple<::dessser::gen::output_specs::channel_specs, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::channel_specs, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7ce21e44309db7c6914cc41eb440af04 const &a, t7ce21e44309db7c6914cc41eb440af04 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7ce21e44309db7c6914cc41eb440af04 const &a, t7ce21e44309db7c6914cc41eb440af04 const &b) {
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
struct t9a758baeff17224a77e1a522010b4168 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t9a758baeff17224a77e1a522010b4168(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return !operator==(a, b);
}
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
struct t432678e1cf78673023ea4e019ea3fbd8 : public std::tuple<
  int16_t,
  Pointer
> {
  using tuple::tuple;
  t432678e1cf78673023ea4e019ea3fbd8(std::tuple<int16_t, Pointer> p)
    : std::tuple<int16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t432678e1cf78673023ea4e019ea3fbd8 const &a, t432678e1cf78673023ea4e019ea3fbd8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t432678e1cf78673023ea4e019ea3fbd8 const &a, t432678e1cf78673023ea4e019ea3fbd8 const &b) {
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
struct te5b605570c13dd86d5874e55c6b74a31 : public std::tuple<
  ::dessser::gen::output_specs::file_type,
  Pointer
> {
  using tuple::tuple;
  te5b605570c13dd86d5874e55c6b74a31(std::tuple<::dessser::gen::output_specs::file_type, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::file_type, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te5b605570c13dd86d5874e55c6b74a31 const &a, te5b605570c13dd86d5874e55c6b74a31 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te5b605570c13dd86d5874e55c6b74a31 const &a, te5b605570c13dd86d5874e55c6b74a31 const &b) {
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
struct tf9a0a3fefc87c9e10a93d3a172850c26 : public std::tuple<
  bool,
  Pointer
> {
  using tuple::tuple;
  tf9a0a3fefc87c9e10a93d3a172850c26(std::tuple<bool, Pointer> p)
    : std::tuple<bool, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
  return !operator==(a, b);
}
struct t5bd421c43649a0ea41776ce18e1f03c1 : public std::tuple<
  ::dessser::gen::output_specs::recipient,
  Pointer
> {
  using tuple::tuple;
  t5bd421c43649a0ea41776ce18e1f03c1(std::tuple<::dessser::gen::output_specs::recipient, Pointer> p)
    : std::tuple<::dessser::gen::output_specs::recipient, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5bd421c43649a0ea41776ce18e1f03c1 const &a, t5bd421c43649a0ea41776ce18e1f03c1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5bd421c43649a0ea41776ce18e1f03c1 const &a, t5bd421c43649a0ea41776ce18e1f03c1 const &b) {
  return !operator==(a, b);
}
struct td0a4a9551c4a7c5b58d84275e2a098f7 : public std::tuple<
  dessser::gen::file_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  td0a4a9551c4a7c5b58d84275e2a098f7(std::tuple<dessser::gen::file_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::file_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td0a4a9551c4a7c5b58d84275e2a098f7 const &a, td0a4a9551c4a7c5b58d84275e2a098f7 const &b) {
  return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td0a4a9551c4a7c5b58d84275e2a098f7 const &a, td0a4a9551c4a7c5b58d84275e2a098f7 const &b) {
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
struct t0e7f6ba9e1ceef343afe44456f9067ec : public std::tuple<
  dessser::gen::sync_key::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0e7f6ba9e1ceef343afe44456f9067ec(std::tuple<dessser::gen::sync_key::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_key::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e7f6ba9e1ceef343afe44456f9067ec const &a, t0e7f6ba9e1ceef343afe44456f9067ec const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e7f6ba9e1ceef343afe44456f9067ec const &a, t0e7f6ba9e1ceef343afe44456f9067ec const &b) {
  return !operator==(a, b);
}
struct ta30293a82943182cab78182f33b18016 : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  ta30293a82943182cab78182f33b18016(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
  return !operator==(a, b);
}
struct t0b75cfeb37c549ebf8500c4ccb591b57 : public std::tuple<
  Lst<::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523>,
  Pointer
> {
  using tuple::tuple;
  t0b75cfeb37c549ebf8500c4ccb591b57(std::tuple<Lst<::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0b75cfeb37c549ebf8500c4ccb591b57 const &a, t0b75cfeb37c549ebf8500c4ccb591b57 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0b75cfeb37c549ebf8500c4ccb591b57 const &a, t0b75cfeb37c549ebf8500c4ccb591b57 const &b) {
  return !operator==(a, b);
}
struct t20c08c99d00b8309a3e7d83f43ad946f : public std::tuple<
  dessser::gen::fieldmask::t_ext,
  Pointer
> {
  using tuple::tuple;
  t20c08c99d00b8309a3e7d83f43ad946f(std::tuple<dessser::gen::fieldmask::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fieldmask::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t20c08c99d00b8309a3e7d83f43ad946f const &a, t20c08c99d00b8309a3e7d83f43ad946f const &b) {
  return ::dessser::gen::fieldmask::Deref(std::get<0>(a)) == ::dessser::gen::fieldmask::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t20c08c99d00b8309a3e7d83f43ad946f const &a, t20c08c99d00b8309a3e7d83f43ad946f const &b) {
  return !operator==(a, b);
}
struct t1c1418766eaa98ca7084a7a2c819843f : public std::tuple<
  Lst<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46>,
  Pointer
> {
  using tuple::tuple;
  t1c1418766eaa98ca7084a7a2c819843f(std::tuple<Lst<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1c1418766eaa98ca7084a7a2c819843f const &a, t1c1418766eaa98ca7084a7a2c819843f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1c1418766eaa98ca7084a7a2c819843f const &a, t1c1418766eaa98ca7084a7a2c819843f const &b) {
  return !operator==(a, b);
}
struct t653b877a5045bee09e834195cfdbb7fa : public std::tuple<
  Lst<dessser::gen::raql_value::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t653b877a5045bee09e834195cfdbb7fa(std::tuple<Lst<dessser::gen::raql_value::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::raql_value::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t653b877a5045bee09e834195cfdbb7fa const &a, t653b877a5045bee09e834195cfdbb7fa const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t653b877a5045bee09e834195cfdbb7fa const &a, t653b877a5045bee09e834195cfdbb7fa const &b) {
  return !operator==(a, b);
}
struct tf3063cfb73e0f06d3ea99ebd15a86d50 : public std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf3063cfb73e0f06d3ea99ebd15a86d50(std::tuple<dessser::gen::raql_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return ::dessser::gen::raql_value::Deref(std::get<0>(a)) == ::dessser::gen::raql_value::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return !operator==(a, b);
}
struct t581e8f70011b20941cc1c100327a61cc : public std::tuple<
  Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46>,
  Pointer
> {
  using tuple::tuple;
  t581e8f70011b20941cc1c100327a61cc(std::tuple<Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46>, Pointer> p)
    : std::tuple<Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t581e8f70011b20941cc1c100327a61cc const &a, t581e8f70011b20941cc1c100327a61cc const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t581e8f70011b20941cc1c100327a61cc const &a, t581e8f70011b20941cc1c100327a61cc const &b) {
  return !operator==(a, b);
}
struct t76b716b4c8ac654d9c7ecf84064f11ea : public std::tuple<
  Lst<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71>,
  Pointer
> {
  using tuple::tuple;
  t76b716b4c8ac654d9c7ecf84064f11ea(std::tuple<Lst<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t76b716b4c8ac654d9c7ecf84064f11ea const &a, t76b716b4c8ac654d9c7ecf84064f11ea const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t76b716b4c8ac654d9c7ecf84064f11ea const &a, t76b716b4c8ac654d9c7ecf84064f11ea const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("(FLOAT; I16; U32)" "Ptr")
      (let "stup_dst_315" (let "stup_dst_314" (write-u64 little-endian (param 1) (u64-of-float (get-item 0 (param 0)))) (write-u16 little-endian (identifier "stup_dst_314") (to-u16 (get-item 1 (param 0)))))
        (write-u32 little-endian (identifier "stup_dst_315") (get-item 2 (param 0)))))
 */
static std::function<Pointer(::dessser::gen::output_specs::channel_specs const &,Pointer &)> channel_specs_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::output_specs::channel_specs const &,Pointer &)> fun0 { [&](::dessser::gen::output_specs::channel_specs p_0, Pointer p_1) {
    double id_1 { std::get<0>(p_0) };
    uint64_t id_2 { qword_of_float(id_1) };
    Pointer id_3 { p_1.writeU64Le(id_2) };
    Pointer let_res_4;
    {
      Pointer stup_dst_314 { id_3 };
      int16_t id_5 { std::get<1>(p_0) };
      uint16_t id_6 { uint16_t(id_5) };
      Pointer id_7 { stup_dst_314.writeU16Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer stup_dst_315 { let_res_4 };
      uint32_t id_9 { std::get<2>(p_0) };
      Pointer id_10 { stup_dst_315.writeU32Le(id_9) };
      let_res_8 = id_10;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::output_specs::channel_specs const &,Pointer &)> channel_specs_to_row_binary(channel_specs_to_row_binary_init());

/* 
    (fun ("[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" "Ptr")
      (let "ssum_dst_311" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_311")
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_313"
              (let "srec_dst_312" (write-u8 (identifier "ssum_dst_311") (u8-of-bool (get-field "with_index" (get-alt "Orc" (param 0)))))
                (write-u32 little-endian (identifier "srec_dst_312") (get-field "batch_size" (get-alt "Orc" (param 0))))) 
              (write-u32 little-endian (identifier "srec_dst_313") (get-field "num_batches" (get-alt "Orc" (param 0)))))))))
 */
static std::function<Pointer(::dessser::gen::output_specs::file_type const &,Pointer &)> file_type_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::output_specs::file_type const &,Pointer &)> fun11 { [&](::dessser::gen::output_specs::file_type p_0, Pointer p_1) {
    uint16_t id_12 { uint16_t(p_0.index()) };
    Pointer id_13 { p_1.writeU16Le(id_12) };
    Pointer let_res_14;
    {
      Pointer ssum_dst_311 { id_13 };
      uint16_t id_15 { 0 };
      uint16_t id_16 { uint16_t(p_0.index()) };
      bool id_17 { bool(id_15 == id_16) };
      Pointer choose_res_18;
      if (id_17) {
        choose_res_18 = ssum_dst_311;
      } else {
        uint16_t id_19 { uint16_t(p_0.index()) };
        uint16_t id_20 { 1 };
        bool id_21 { bool(id_19 == id_20) };
        Void id_22 { ((void)(assert(id_21)), ::dessser::Void()) };
        (void)id_22;
        ::dessser::gen::output_specs::ta86dfe69264c9600d57a3b5ead0f7951 id_23 { std::get<1 /* Orc */>(p_0) };
        bool id_24 { id_23.with_index };
        uint8_t id_25 { uint8_t(id_24) };
        Pointer id_26 { ssum_dst_311.writeU8(id_25) };
        Pointer let_res_27;
        {
          Pointer srec_dst_312 { id_26 };
          ::dessser::gen::output_specs::ta86dfe69264c9600d57a3b5ead0f7951 id_28 { std::get<1 /* Orc */>(p_0) };
          uint32_t id_29 { id_28.batch_size };
          Pointer id_30 { srec_dst_312.writeU32Le(id_29) };
          let_res_27 = id_30;
        }
        Pointer let_res_31;
        {
          Pointer srec_dst_313 { let_res_27 };
          ::dessser::gen::output_specs::ta86dfe69264c9600d57a3b5ead0f7951 id_32 { std::get<1 /* Orc */>(p_0) };
          uint32_t id_33 { id_32.num_batches };
          Pointer id_34 { srec_dst_313.writeU32Le(id_33) };
          let_res_31 = id_34;
        }
        choose_res_18 = let_res_31;
      }
      let_res_14 = choose_res_18;
    }
    return let_res_14;
  }
   };
  return fun11;
}
std::function<Pointer(::dessser::gen::output_specs::file_type const &,Pointer &)> file_type_to_row_binary(file_type_to_row_binary_init());

/* 
    (fun ("[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" "Ptr")
      (let "ssum_dst_307" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (apply (ext-identifier file_path to-row-binary) (get-alt "DirectFile" (param 0)) (identifier "ssum_dst_307"))
          (if (eq (u16 1) (label-of (param 0)))
            (write-bytes
              (let "leb128_sz_308" (make-vec (string-length (get-alt "IndirectFile" (param 0))))
                (let "leb128_ptr_309" (make-vec (identifier "ssum_dst_307"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_309")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_309"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_308"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_308"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_308"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_308") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_308")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_308")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_309"))))) 
              (bytes-of-string (get-alt "IndirectFile" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 2))) (apply (ext-identifier sync_key to-row-binary) (get-alt "SyncKey" (param 0)) (identifier "ssum_dst_307")))))))
 */
static std::function<Pointer(::dessser::gen::output_specs::recipient &,Pointer &)> recipient_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::output_specs::recipient &,Pointer &)> fun35 { [&](::dessser::gen::output_specs::recipient p_0, Pointer p_1) {
    uint16_t id_36 { uint16_t(p_0.index()) };
    Pointer id_37 { p_1.writeU16Le(id_36) };
    Pointer let_res_38;
    {
      Pointer ssum_dst_307 { id_37 };
      uint16_t id_39 { 0 };
      uint16_t id_40 { uint16_t(p_0.index()) };
      bool id_41 { bool(id_39 == id_40) };
      Pointer choose_res_42;
      if (id_41) {
        auto fun43 { dessser::gen::file_path::to_row_binary };
        dessser::gen::file_path::t_ext id_44 { std::get<0 /* DirectFile */>(p_0) };
        Pointer id_45 { fun43(id_44, ssum_dst_307) };
        choose_res_42 = id_45;
      } else {
        uint16_t id_46 { 1 };
        uint16_t id_47 { uint16_t(p_0.index()) };
        bool id_48 { bool(id_46 == id_47) };
        Pointer choose_res_49;
        if (id_48) {
          std::string id_50 { std::get<1 /* IndirectFile */>(p_0) };
          uint32_t id_51 { (uint32_t)id_50.size() };
          Vec<1, uint32_t> id_52 {  id_51  };
          Pointer let_res_53;
          {
            Vec<1, uint32_t> leb128_sz_308 { id_52 };
            Vec<1, Pointer> id_54 {  ssum_dst_307  };
            Pointer let_res_55;
            {
              Vec<1, Pointer> leb128_ptr_309 { id_54 };
              bool while_flag_56 { true };
              do {
                uint8_t id_57 { 0 };
                uint8_t id_58 { 0 };
                Pointer id_59 { leb128_ptr_309[id_58] };
                uint32_t id_60 { 128U };
                uint8_t id_61 { 0 };
                uint32_t id_62 { leb128_sz_308[id_61] };
                bool id_63 { bool(id_60 > id_62) };
                uint8_t choose_res_64;
                if (id_63) {
                  uint8_t id_65 { 0 };
                  uint32_t id_66 { leb128_sz_308[id_65] };
                  uint8_t id_67 { uint8_t(id_66) };
                  choose_res_64 = id_67;
                } else {
                  uint8_t id_68 { 0 };
                  uint32_t id_69 { leb128_sz_308[id_68] };
                  uint8_t id_70 { uint8_t(id_69) };
                  uint8_t id_71 { 128 };
                  uint8_t id_72 { uint8_t(id_70 | id_71) };
                  choose_res_64 = id_72;
                }
                Pointer id_73 { id_59.writeU8(choose_res_64) };
                Void id_74 { ((void)(leb128_ptr_309[id_57] = id_73), ::dessser::Void()) };
                (void)id_74;
                uint8_t id_75 { 0 };
                uint8_t id_76 { 0 };
                uint32_t id_77 { leb128_sz_308[id_76] };
                uint8_t id_78 { 7 };
                uint32_t id_79 { uint32_t(id_77 >> id_78) };
                Void id_80 { ((void)(leb128_sz_308[id_75] = id_79), ::dessser::Void()) };
                (void)id_80;
                uint8_t id_81 { 0 };
                uint32_t id_82 { leb128_sz_308[id_81] };
                uint32_t id_83 { 0U };
                bool id_84 { bool(id_82 > id_83) };
                while_flag_56 = id_84;
                if (while_flag_56) {
                  (void)::dessser::Void();
                }
              } while (while_flag_56);
              (void)::dessser::Void();
              uint8_t id_85 { 0 };
              Pointer id_86 { leb128_ptr_309[id_85] };
              let_res_55 = id_86;
            }
            let_res_53 = let_res_55;
          }
          std::string id_87 { std::get<1 /* IndirectFile */>(p_0) };
          Bytes id_88 { id_87 };
          Pointer id_89 { let_res_53.writeBytes(id_88) };
          choose_res_49 = id_89;
        } else {
          uint16_t id_90 { uint16_t(p_0.index()) };
          uint16_t id_91 { 2 };
          bool id_92 { bool(id_90 == id_91) };
          Void id_93 { ((void)(assert(id_92)), ::dessser::Void()) };
          (void)id_93;
          auto fun94 { dessser::gen::sync_key::to_row_binary };
          dessser::gen::sync_key::t_ext id_95 { std::get<2 /* SyncKey */>(p_0) };
          Pointer id_96 { fun94(id_95, ssum_dst_307) };
          choose_res_49 = id_96;
        }
        choose_res_42 = choose_res_49;
      }
      let_res_38 = choose_res_42;
    }
    return let_res_38;
  }
   };
  return fun35;
}
std::function<Pointer(::dessser::gen::output_specs::recipient &,Pointer &)> recipient_to_row_binary(recipient_to_row_binary_init());

/* 
    (fun ("((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})[]" "Ptr")
      (let "dst_ref_318"
        (make-vec
          (let "leb128_sz_316" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_317" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_317")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_317"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_316") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_316")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_316")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_317"))))))
        (let "n_ref_319" (make-vec (i32 0))
          (seq
            (for-each "x_320" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_318")
                  (let "stup_dst_322" (let "stup_dst_321" (unsafe-nth (u8 0) (identifier "dst_ref_318")) (apply (identifier "recipient-to-row-binary") (get-item 0 (identifier "x_320")) (identifier "stup_dst_321")))
                    (let "srec_dst_337"
                      (let "srec_dst_324"
                        (let "srec_dst_323" (apply (identifier "file_type-to-row-binary") (get-field "file_type" (get-item 1 (identifier "x_320"))) (identifier "stup_dst_322"))
                          (apply (ext-identifier fieldmask to-row-binary) (get-field "fieldmask" (get-item 1 (identifier "x_320"))) (identifier "srec_dst_323")))
                        (let "dst_ref_327"
                          (make-vec
                            (let "leb128_sz_325" (make-vec (cardinality (get-field "filters" (get-item 1 (identifier "x_320")))))
                              (let "leb128_ptr_326" (make-vec (identifier "srec_dst_324"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_326")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_326"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_325"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_325"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_325"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_325") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_325")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_325")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_326"))))))
                          (let "n_ref_328" (make-vec (i32 0))
                            (seq
                              (for-each "x_329" (get-field "filters" (get-item 1 (identifier "x_320")))
                                (seq
                                  (set-vec (u8 0) (identifier "dst_ref_327")
                                    (let "stup_dst_331" (let "stup_dst_330" (unsafe-nth (u8 0) (identifier "dst_ref_327")) (write-u16 little-endian (identifier "stup_dst_330") (get-item 0 (identifier "x_329"))))
                                      (let "dst_ref_334"
                                        (make-vec
                                          (let "leb128_sz_332" (make-vec (cardinality (get-item 1 (identifier "x_329"))))
                                            (let "leb128_ptr_333" (make-vec (identifier "stup_dst_331"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_333")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_333"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_332"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_332"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_332"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_332") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_332")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_332")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_333"))))))
                                        (let "n_ref_335" (make-vec (i32 0))
                                          (seq
                                            (for-each "x_336" (get-item 1 (identifier "x_329"))
                                              (seq (set-vec (u8 0) (identifier "dst_ref_334") (apply (ext-identifier raql_value to-row-binary) (identifier "x_336") (unsafe-nth (u8 0) (identifier "dst_ref_334"))))
                                                (set-vec (u8 0) (identifier "n_ref_335") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_335")))))) 
                                            (unsafe-nth (u8 0) (identifier "dst_ref_334"))))))) 
                                  (set-vec (u8 0) (identifier "n_ref_328") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_328")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_327"))))))
                      (let "dst_ref_340"
                        (make-vec
                          (let "leb128_sz_338" (make-vec (cardinality (get-field "channels" (get-item 1 (identifier "x_320")))))
                            (let "leb128_ptr_339" (make-vec (identifier "srec_dst_337"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_339")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_339"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_338"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_338"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_338"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_338") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_338")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_338")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_339"))))))
                        (let "n_ref_341" (make-vec (i32 0))
                          (seq
                            (for-each "x_342" (get-field "channels" (get-item 1 (identifier "x_320")))
                              (seq
                                (set-vec (u8 0) (identifier "dst_ref_340")
                                  (let "stup_dst_344" (let "stup_dst_343" (unsafe-nth (u8 0) (identifier "dst_ref_340")) (write-u16 little-endian (identifier "stup_dst_343") (get-item 0 (identifier "x_342"))))
                                    (apply (identifier "channel_specs-to-row-binary") (get-item 1 (identifier "x_342")) (identifier "stup_dst_344"))))
                                (set-vec (u8 0) (identifier "n_ref_341") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_341")))))) 
                            (unsafe-nth (u8 0) (identifier "dst_ref_340")))))))) 
                (set-vec (u8 0) (identifier "n_ref_319") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_319")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_318"))))))
 */
static std::function<Pointer(t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(t &,Pointer &)> fun97 { [&](t& p_0, Pointer p_1) {
    uint32_t id_98 { p_0.size() };
    Vec<1, uint32_t> id_99 {  id_98  };
    Pointer let_res_100;
    {
      Vec<1, uint32_t> leb128_sz_316 { id_99 };
      Vec<1, Pointer> id_101 {  p_1  };
      Pointer let_res_102;
      {
        Vec<1, Pointer> leb128_ptr_317 { id_101 };
        bool while_flag_103 { true };
        do {
          uint8_t id_104 { 0 };
          uint8_t id_105 { 0 };
          Pointer id_106 { leb128_ptr_317[id_105] };
          uint32_t id_107 { 128U };
          uint8_t id_108 { 0 };
          uint32_t id_109 { leb128_sz_316[id_108] };
          bool id_110 { bool(id_107 > id_109) };
          uint8_t choose_res_111;
          if (id_110) {
            uint8_t id_112 { 0 };
            uint32_t id_113 { leb128_sz_316[id_112] };
            uint8_t id_114 { uint8_t(id_113) };
            choose_res_111 = id_114;
          } else {
            uint8_t id_115 { 0 };
            uint32_t id_116 { leb128_sz_316[id_115] };
            uint8_t id_117 { uint8_t(id_116) };
            uint8_t id_118 { 128 };
            uint8_t id_119 { uint8_t(id_117 | id_118) };
            choose_res_111 = id_119;
          }
          Pointer id_120 { id_106.writeU8(choose_res_111) };
          Void id_121 { ((void)(leb128_ptr_317[id_104] = id_120), ::dessser::Void()) };
          (void)id_121;
          uint8_t id_122 { 0 };
          uint8_t id_123 { 0 };
          uint32_t id_124 { leb128_sz_316[id_123] };
          uint8_t id_125 { 7 };
          uint32_t id_126 { uint32_t(id_124 >> id_125) };
          Void id_127 { ((void)(leb128_sz_316[id_122] = id_126), ::dessser::Void()) };
          (void)id_127;
          uint8_t id_128 { 0 };
          uint32_t id_129 { leb128_sz_316[id_128] };
          uint32_t id_130 { 0U };
          bool id_131 { bool(id_129 > id_130) };
          while_flag_103 = id_131;
          if (while_flag_103) {
            (void)::dessser::Void();
          }
        } while (while_flag_103);
        (void)::dessser::Void();
        uint8_t id_132 { 0 };
        Pointer id_133 { leb128_ptr_317[id_132] };
        let_res_102 = id_133;
      }
      let_res_100 = let_res_102;
    }
    Vec<1, Pointer> id_134 {  let_res_100  };
    Pointer let_res_135;
    {
      Vec<1, Pointer> dst_ref_318 { id_134 };
      int32_t id_136 { 0L };
      Vec<1, int32_t> id_137 {  id_136  };
      Pointer let_res_138;
      {
        Vec<1, int32_t> n_ref_319 { id_137 };
        for (::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 &x_320 : p_0) {
          uint8_t id_139 { 0 };
          uint8_t id_140 { 0 };
          Pointer id_141 { dst_ref_318[id_140] };
          Pointer let_res_142;
          {
            Pointer stup_dst_321 { id_141 };
            ::dessser::gen::output_specs::recipient id_143 { std::get<0>(x_320) };
            Pointer id_144 { recipient_to_row_binary(id_143, stup_dst_321) };
            let_res_142 = id_144;
          }
          Pointer let_res_145;
          {
            Pointer stup_dst_322 { let_res_142 };
            ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_146 { std::get<1>(x_320) };
            ::dessser::gen::output_specs::file_type id_147 { id_146.file_type };
            Pointer id_148 { file_type_to_row_binary(id_147, stup_dst_322) };
            Pointer let_res_149;
            {
              Pointer srec_dst_323 { id_148 };
              auto fun150 { dessser::gen::fieldmask::to_row_binary };
              ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_151 { std::get<1>(x_320) };
              dessser::gen::fieldmask::t_ext id_152 { id_151.fieldmask };
              Pointer id_153 { fun150(id_152, srec_dst_323) };
              let_res_149 = id_153;
            }
            Pointer let_res_154;
            {
              Pointer srec_dst_324 { let_res_149 };
              ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_155 { std::get<1>(x_320) };
              Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_156 { id_155.filters };
              uint32_t id_157 { id_156.size() };
              Vec<1, uint32_t> id_158 {  id_157  };
              Pointer let_res_159;
              {
                Vec<1, uint32_t> leb128_sz_325 { id_158 };
                Vec<1, Pointer> id_160 {  srec_dst_324  };
                Pointer let_res_161;
                {
                  Vec<1, Pointer> leb128_ptr_326 { id_160 };
                  bool while_flag_162 { true };
                  do {
                    uint8_t id_163 { 0 };
                    uint8_t id_164 { 0 };
                    Pointer id_165 { leb128_ptr_326[id_164] };
                    uint32_t id_166 { 128U };
                    uint8_t id_167 { 0 };
                    uint32_t id_168 { leb128_sz_325[id_167] };
                    bool id_169 { bool(id_166 > id_168) };
                    uint8_t choose_res_170;
                    if (id_169) {
                      uint8_t id_171 { 0 };
                      uint32_t id_172 { leb128_sz_325[id_171] };
                      uint8_t id_173 { uint8_t(id_172) };
                      choose_res_170 = id_173;
                    } else {
                      uint8_t id_174 { 0 };
                      uint32_t id_175 { leb128_sz_325[id_174] };
                      uint8_t id_176 { uint8_t(id_175) };
                      uint8_t id_177 { 128 };
                      uint8_t id_178 { uint8_t(id_176 | id_177) };
                      choose_res_170 = id_178;
                    }
                    Pointer id_179 { id_165.writeU8(choose_res_170) };
                    Void id_180 { ((void)(leb128_ptr_326[id_163] = id_179), ::dessser::Void()) };
                    (void)id_180;
                    uint8_t id_181 { 0 };
                    uint8_t id_182 { 0 };
                    uint32_t id_183 { leb128_sz_325[id_182] };
                    uint8_t id_184 { 7 };
                    uint32_t id_185 { uint32_t(id_183 >> id_184) };
                    Void id_186 { ((void)(leb128_sz_325[id_181] = id_185), ::dessser::Void()) };
                    (void)id_186;
                    uint8_t id_187 { 0 };
                    uint32_t id_188 { leb128_sz_325[id_187] };
                    uint32_t id_189 { 0U };
                    bool id_190 { bool(id_188 > id_189) };
                    while_flag_162 = id_190;
                    if (while_flag_162) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_162);
                  (void)::dessser::Void();
                  uint8_t id_191 { 0 };
                  Pointer id_192 { leb128_ptr_326[id_191] };
                  let_res_161 = id_192;
                }
                let_res_159 = let_res_161;
              }
              Vec<1, Pointer> id_193 {  let_res_159  };
              Pointer let_res_194;
              {
                Vec<1, Pointer> dst_ref_327 { id_193 };
                int32_t id_195 { 0L };
                Vec<1, int32_t> id_196 {  id_195  };
                Pointer let_res_197;
                {
                  Vec<1, int32_t> n_ref_328 { id_196 };
                  ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_198 { std::get<1>(x_320) };
                  Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_199 { id_198.filters };
                  for (::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46 &x_329 : id_199) {
                    uint8_t id_200 { 0 };
                    uint8_t id_201 { 0 };
                    Pointer id_202 { dst_ref_327[id_201] };
                    Pointer let_res_203;
                    {
                      Pointer stup_dst_330 { id_202 };
                      uint16_t id_204 { std::get<0>(x_329) };
                      Pointer id_205 { stup_dst_330.writeU16Le(id_204) };
                      let_res_203 = id_205;
                    }
                    Pointer let_res_206;
                    {
                      Pointer stup_dst_331 { let_res_203 };
                      Arr<dessser::gen::raql_value::t_ext> id_207 { std::get<1>(x_329) };
                      uint32_t id_208 { id_207.size() };
                      Vec<1, uint32_t> id_209 {  id_208  };
                      Pointer let_res_210;
                      {
                        Vec<1, uint32_t> leb128_sz_332 { id_209 };
                        Vec<1, Pointer> id_211 {  stup_dst_331  };
                        Pointer let_res_212;
                        {
                          Vec<1, Pointer> leb128_ptr_333 { id_211 };
                          bool while_flag_213 { true };
                          do {
                            uint8_t id_214 { 0 };
                            uint8_t id_215 { 0 };
                            Pointer id_216 { leb128_ptr_333[id_215] };
                            uint32_t id_217 { 128U };
                            uint8_t id_218 { 0 };
                            uint32_t id_219 { leb128_sz_332[id_218] };
                            bool id_220 { bool(id_217 > id_219) };
                            uint8_t choose_res_221;
                            if (id_220) {
                              uint8_t id_222 { 0 };
                              uint32_t id_223 { leb128_sz_332[id_222] };
                              uint8_t id_224 { uint8_t(id_223) };
                              choose_res_221 = id_224;
                            } else {
                              uint8_t id_225 { 0 };
                              uint32_t id_226 { leb128_sz_332[id_225] };
                              uint8_t id_227 { uint8_t(id_226) };
                              uint8_t id_228 { 128 };
                              uint8_t id_229 { uint8_t(id_227 | id_228) };
                              choose_res_221 = id_229;
                            }
                            Pointer id_230 { id_216.writeU8(choose_res_221) };
                            Void id_231 { ((void)(leb128_ptr_333[id_214] = id_230), ::dessser::Void()) };
                            (void)id_231;
                            uint8_t id_232 { 0 };
                            uint8_t id_233 { 0 };
                            uint32_t id_234 { leb128_sz_332[id_233] };
                            uint8_t id_235 { 7 };
                            uint32_t id_236 { uint32_t(id_234 >> id_235) };
                            Void id_237 { ((void)(leb128_sz_332[id_232] = id_236), ::dessser::Void()) };
                            (void)id_237;
                            uint8_t id_238 { 0 };
                            uint32_t id_239 { leb128_sz_332[id_238] };
                            uint32_t id_240 { 0U };
                            bool id_241 { bool(id_239 > id_240) };
                            while_flag_213 = id_241;
                            if (while_flag_213) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_213);
                          (void)::dessser::Void();
                          uint8_t id_242 { 0 };
                          Pointer id_243 { leb128_ptr_333[id_242] };
                          let_res_212 = id_243;
                        }
                        let_res_210 = let_res_212;
                      }
                      Vec<1, Pointer> id_244 {  let_res_210  };
                      Pointer let_res_245;
                      {
                        Vec<1, Pointer> dst_ref_334 { id_244 };
                        int32_t id_246 { 0L };
                        Vec<1, int32_t> id_247 {  id_246  };
                        Pointer let_res_248;
                        {
                          Vec<1, int32_t> n_ref_335 { id_247 };
                          Arr<dessser::gen::raql_value::t_ext> id_249 { std::get<1>(x_329) };
                          for (dessser::gen::raql_value::t_ext &x_336 : id_249) {
                            uint8_t id_250 { 0 };
                            auto fun251 { dessser::gen::raql_value::to_row_binary };
                            uint8_t id_252 { 0 };
                            Pointer id_253 { dst_ref_334[id_252] };
                            Pointer id_254 { fun251(x_336, id_253) };
                            Void id_255 { ((void)(dst_ref_334[id_250] = id_254), ::dessser::Void()) };
                            (void)id_255;
                            uint8_t id_256 { 0 };
                            int32_t id_257 { 1L };
                            uint8_t id_258 { 0 };
                            int32_t id_259 { n_ref_335[id_258] };
                            int32_t id_260 { int32_t(id_257 + id_259) };
                            Void id_261 { ((void)(n_ref_335[id_256] = id_260), ::dessser::Void()) };
                            (void)id_261;
                            (void)id_261;
                          }
                          (void)::dessser::Void();
                          uint8_t id_262 { 0 };
                          Pointer id_263 { dst_ref_334[id_262] };
                          let_res_248 = id_263;
                        }
                        let_res_245 = let_res_248;
                      }
                      let_res_206 = let_res_245;
                    }
                    Void id_264 { ((void)(dst_ref_327[id_200] = let_res_206), ::dessser::Void()) };
                    (void)id_264;
                    uint8_t id_265 { 0 };
                    int32_t id_266 { 1L };
                    uint8_t id_267 { 0 };
                    int32_t id_268 { n_ref_328[id_267] };
                    int32_t id_269 { int32_t(id_266 + id_268) };
                    Void id_270 { ((void)(n_ref_328[id_265] = id_269), ::dessser::Void()) };
                    (void)id_270;
                    (void)id_270;
                  }
                  (void)::dessser::Void();
                  uint8_t id_271 { 0 };
                  Pointer id_272 { dst_ref_327[id_271] };
                  let_res_197 = id_272;
                }
                let_res_194 = let_res_197;
              }
              let_res_154 = let_res_194;
            }
            Pointer let_res_273;
            {
              Pointer srec_dst_337 { let_res_154 };
              ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_274 { std::get<1>(x_320) };
              Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> id_275 { id_274.channels };
              uint32_t id_276 { id_275.size() };
              Vec<1, uint32_t> id_277 {  id_276  };
              Pointer let_res_278;
              {
                Vec<1, uint32_t> leb128_sz_338 { id_277 };
                Vec<1, Pointer> id_279 {  srec_dst_337  };
                Pointer let_res_280;
                {
                  Vec<1, Pointer> leb128_ptr_339 { id_279 };
                  bool while_flag_281 { true };
                  do {
                    uint8_t id_282 { 0 };
                    uint8_t id_283 { 0 };
                    Pointer id_284 { leb128_ptr_339[id_283] };
                    uint32_t id_285 { 128U };
                    uint8_t id_286 { 0 };
                    uint32_t id_287 { leb128_sz_338[id_286] };
                    bool id_288 { bool(id_285 > id_287) };
                    uint8_t choose_res_289;
                    if (id_288) {
                      uint8_t id_290 { 0 };
                      uint32_t id_291 { leb128_sz_338[id_290] };
                      uint8_t id_292 { uint8_t(id_291) };
                      choose_res_289 = id_292;
                    } else {
                      uint8_t id_293 { 0 };
                      uint32_t id_294 { leb128_sz_338[id_293] };
                      uint8_t id_295 { uint8_t(id_294) };
                      uint8_t id_296 { 128 };
                      uint8_t id_297 { uint8_t(id_295 | id_296) };
                      choose_res_289 = id_297;
                    }
                    Pointer id_298 { id_284.writeU8(choose_res_289) };
                    Void id_299 { ((void)(leb128_ptr_339[id_282] = id_298), ::dessser::Void()) };
                    (void)id_299;
                    uint8_t id_300 { 0 };
                    uint8_t id_301 { 0 };
                    uint32_t id_302 { leb128_sz_338[id_301] };
                    uint8_t id_303 { 7 };
                    uint32_t id_304 { uint32_t(id_302 >> id_303) };
                    Void id_305 { ((void)(leb128_sz_338[id_300] = id_304), ::dessser::Void()) };
                    (void)id_305;
                    uint8_t id_306 { 0 };
                    uint32_t id_307 { leb128_sz_338[id_306] };
                    uint32_t id_308 { 0U };
                    bool id_309 { bool(id_307 > id_308) };
                    while_flag_281 = id_309;
                    if (while_flag_281) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_281);
                  (void)::dessser::Void();
                  uint8_t id_310 { 0 };
                  Pointer id_311 { leb128_ptr_339[id_310] };
                  let_res_280 = id_311;
                }
                let_res_278 = let_res_280;
              }
              Vec<1, Pointer> id_312 {  let_res_278  };
              Pointer let_res_313;
              {
                Vec<1, Pointer> dst_ref_340 { id_312 };
                int32_t id_314 { 0L };
                Vec<1, int32_t> id_315 {  id_314  };
                Pointer let_res_316;
                {
                  Vec<1, int32_t> n_ref_341 { id_315 };
                  ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_317 { std::get<1>(x_320) };
                  Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> id_318 { id_317.channels };
                  for (::dessser::gen::output_specs::te2535d14520252a621d726d279906e71 const &x_342 : id_318) {
                    uint8_t id_319 { 0 };
                    uint8_t id_320 { 0 };
                    Pointer id_321 { dst_ref_340[id_320] };
                    Pointer let_res_322;
                    {
                      Pointer stup_dst_343 { id_321 };
                      uint16_t id_323 { std::get<0>(x_342) };
                      Pointer id_324 { stup_dst_343.writeU16Le(id_323) };
                      let_res_322 = id_324;
                    }
                    Pointer let_res_325;
                    {
                      Pointer stup_dst_344 { let_res_322 };
                      ::dessser::gen::output_specs::channel_specs id_326 { std::get<1>(x_342) };
                      Pointer id_327 { channel_specs_to_row_binary(id_326, stup_dst_344) };
                      let_res_325 = id_327;
                    }
                    Void id_328 { ((void)(dst_ref_340[id_319] = let_res_325), ::dessser::Void()) };
                    (void)id_328;
                    uint8_t id_329 { 0 };
                    int32_t id_330 { 1L };
                    uint8_t id_331 { 0 };
                    int32_t id_332 { n_ref_341[id_331] };
                    int32_t id_333 { int32_t(id_330 + id_332) };
                    Void id_334 { ((void)(n_ref_341[id_329] = id_333), ::dessser::Void()) };
                    (void)id_334;
                    (void)id_334;
                  }
                  (void)::dessser::Void();
                  uint8_t id_335 { 0 };
                  Pointer id_336 { dst_ref_340[id_335] };
                  let_res_316 = id_336;
                }
                let_res_313 = let_res_316;
              }
              let_res_273 = let_res_313;
            }
            let_res_145 = let_res_273;
          }
          Void id_337 { ((void)(dst_ref_318[id_139] = let_res_145), ::dessser::Void()) };
          (void)id_337;
          uint8_t id_338 { 0 };
          int32_t id_339 { 1L };
          uint8_t id_340 { 0 };
          int32_t id_341 { n_ref_319[id_340] };
          int32_t id_342 { int32_t(id_339 + id_341) };
          Void id_343 { ((void)(n_ref_319[id_338] = id_342), ::dessser::Void()) };
          (void)id_343;
          (void)id_343;
        }
        (void)::dessser::Void();
        uint8_t id_344 { 0 };
        Pointer id_345 { dst_ref_318[id_344] };
        let_res_138 = id_345;
      }
      let_res_135 = let_res_138;
    }
    return let_res_135;
  }
   };
  return fun97;
}
std::function<Pointer(t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("(FLOAT; I16; U32)") (size 14))
 */
static std::function<Size(::dessser::gen::output_specs::channel_specs const &)> channel_specs_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::output_specs::channel_specs const &)> fun346 { [&](::dessser::gen::output_specs::channel_specs p_0) {
    Size id_347 { 14UL };
    return id_347;
  }
   };
  return fun346;
}
std::function<Size(::dessser::gen::output_specs::channel_specs const &)> channel_specs_sersize_of_row_binary(channel_specs_sersize_of_row_binary_init());

/* 
    (fun ("[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 11))))
 */
static std::function<Size(::dessser::gen::output_specs::file_type const &)> file_type_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::output_specs::file_type const &)> fun348 { [&](::dessser::gen::output_specs::file_type p_0) {
    uint16_t id_349 { 0 };
    uint16_t id_350 { uint16_t(p_0.index()) };
    bool id_351 { bool(id_349 == id_350) };
    Size choose_res_352;
    if (id_351) {
      Size id_353 { 2UL };
      choose_res_352 = id_353;
    } else {
      uint16_t id_354 { uint16_t(p_0.index()) };
      uint16_t id_355 { 1 };
      bool id_356 { bool(id_354 == id_355) };
      Void id_357 { ((void)(assert(id_356)), ::dessser::Void()) };
      (void)id_357;
      Size id_358 { 11UL };
      choose_res_352 = id_358;
    }
    return choose_res_352;
  }
   };
  return fun348;
}
std::function<Size(::dessser::gen::output_specs::file_type const &)> file_type_sersize_of_row_binary(file_type_sersize_of_row_binary_init());

/* 
    (fun ("[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]")
      (if (eq (u16 0) (label-of (param 0))) (add (size 2) (apply (ext-identifier file_path sersize-of-row-binary) (get-alt "DirectFile" (param 0))))
        (if (eq (u16 1) (label-of (param 0)))
          (add (size 2)
            (add
              (let "n_ref_271" (make-vec (string-length (get-alt "IndirectFile" (param 0))))
                (let "lebsz_ref_272" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_271")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_272")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_272") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_272")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_272")))))) 
              (size-of-u32 (string-length (get-alt "IndirectFile" (param 0))))))
          (seq (assert (eq (label-of (param 0)) (u16 2))) (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "SyncKey" (param 0))))))))
 */
static std::function<Size(::dessser::gen::output_specs::recipient &)> recipient_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::output_specs::recipient &)> fun359 { [&](::dessser::gen::output_specs::recipient p_0) {
    uint16_t id_360 { 0 };
    uint16_t id_361 { uint16_t(p_0.index()) };
    bool id_362 { bool(id_360 == id_361) };
    Size choose_res_363;
    if (id_362) {
      Size id_364 { 2UL };
      auto fun365 { dessser::gen::file_path::sersize_of_row_binary };
      dessser::gen::file_path::t_ext id_366 { std::get<0 /* DirectFile */>(p_0) };
      Size id_367 { fun365(id_366) };
      Size id_368 { Size(id_364 + id_367) };
      choose_res_363 = id_368;
    } else {
      uint16_t id_369 { 1 };
      uint16_t id_370 { uint16_t(p_0.index()) };
      bool id_371 { bool(id_369 == id_370) };
      Size choose_res_372;
      if (id_371) {
        Size id_373 { 2UL };
        std::string id_374 { std::get<1 /* IndirectFile */>(p_0) };
        uint32_t id_375 { (uint32_t)id_374.size() };
        Vec<1, uint32_t> id_376 {  id_375  };
        Size let_res_377;
        {
          Vec<1, uint32_t> n_ref_271 { id_376 };
          uint32_t id_378 { 1U };
          Vec<1, uint32_t> id_379 {  id_378  };
          Size let_res_380;
          {
            Vec<1, uint32_t> lebsz_ref_272 { id_379 };
            bool while_flag_381 { true };
            do {
              uint8_t id_382 { 0 };
              uint32_t id_383 { n_ref_271[id_382] };
              uint8_t id_384 { 0 };
              uint32_t id_385 { lebsz_ref_272[id_384] };
              uint8_t id_386 { 7 };
              uint32_t id_387 { uint32_t(id_385 << id_386) };
              bool id_388 { bool(id_383 >= id_387) };
              while_flag_381 = id_388;
              if (while_flag_381) {
                uint8_t id_389 { 0 };
                uint8_t id_390 { 0 };
                uint32_t id_391 { lebsz_ref_272[id_390] };
                uint32_t id_392 { 1U };
                uint32_t id_393 { uint32_t(id_391 + id_392) };
                Void id_394 { ((void)(lebsz_ref_272[id_389] = id_393), ::dessser::Void()) };
                (void)id_394;
              }
            } while (while_flag_381);
            (void)::dessser::Void();
            uint8_t id_395 { 0 };
            uint32_t id_396 { lebsz_ref_272[id_395] };
            Size id_397 { Size(id_396) };
            let_res_380 = id_397;
          }
          let_res_377 = let_res_380;
        }
        std::string id_398 { std::get<1 /* IndirectFile */>(p_0) };
        uint32_t id_399 { (uint32_t)id_398.size() };
        Size id_400 { Size(id_399) };
        Size id_401 { Size(let_res_377 + id_400) };
        Size id_402 { Size(id_373 + id_401) };
        choose_res_372 = id_402;
      } else {
        uint16_t id_403 { uint16_t(p_0.index()) };
        uint16_t id_404 { 2 };
        bool id_405 { bool(id_403 == id_404) };
        Void id_406 { ((void)(assert(id_405)), ::dessser::Void()) };
        (void)id_406;
        Size id_407 { 2UL };
        auto fun408 { dessser::gen::sync_key::sersize_of_row_binary };
        dessser::gen::sync_key::t_ext id_409 { std::get<2 /* SyncKey */>(p_0) };
        Size id_410 { fun408(id_409) };
        Size id_411 { Size(id_407 + id_410) };
        choose_res_372 = id_411;
      }
      choose_res_363 = choose_res_372;
    }
    return choose_res_363;
  }
   };
  return fun359;
}
std::function<Size(::dessser::gen::output_specs::recipient &)> recipient_sersize_of_row_binary(recipient_sersize_of_row_binary_init());

/* 
    (fun ("((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})[]")
      (let "sz_ref_282"
        (make-vec
          (let "n_ref_280" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_281" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_280")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_281")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_281") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_281")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_281")))))))
        (seq
          (let "repeat_n_283" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_283")))
              (seq
                (set-vec (u8 0) (identifier "sz_ref_282")
                  (let "sz_285"
                    (let "sz_284" (unsafe-nth (u8 0) (identifier "sz_ref_282"))
                      (add (identifier "sz_284") (apply (identifier "recipient-sersize-of-row-binary") (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))
                    (let "sz_299"
                      (let "sz_288"
                        (let "sz_287" (add (identifier "sz_285") (apply (identifier "file_type-sersize-of-row-binary") (get-field "file_type" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))
                          (add (identifier "sz_287") (apply (ext-identifier fieldmask sersize-of-row-binary) (get-field "fieldmask" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))))
                        (let "sz_ref_291"
                          (make-vec
                            (add (identifier "sz_288")
                              (let "n_ref_289" (make-vec (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))
                                (let "lebsz_ref_290" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_289")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_290")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_290") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_290")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_290"))))))))
                          (seq
                            (let "repeat_n_292" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_292")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_291")
                                    (let "sz_294" (add (unsafe-nth (u8 0) (identifier "sz_ref_291")) (size 2))
                                      (let "sz_ref_297"
                                        (make-vec
                                          (add (identifier "sz_294")
                                            (let "n_ref_295"
                                              (make-vec
                                                (cardinality
                                                  (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_292")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))))
                                              (let "lebsz_ref_296" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_295")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_296")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_296") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_296")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_296"))))))))
                                        (seq
                                          (let "repeat_n_298" (make-vec (i32 0))
                                            (while
                                              (gt
                                                (to-i32
                                                  (cardinality
                                                    (get-item 1
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_292")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))))
                                                (unsafe-nth (u8 0) (identifier "repeat_n_298")))
                                              (seq
                                                (set-vec (u8 0) (identifier "sz_ref_297")
                                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_297"))
                                                    (apply (ext-identifier raql_value sersize-of-row-binary)
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_298"))
                                                        (get-item 1
                                                          (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_292")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))))))
                                                (set-vec (u8 0) (identifier "repeat_n_298") (add (unsafe-nth (u8 0) (identifier "repeat_n_298")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "sz_ref_297")))))) 
                                  (set-vec (u8 0) (identifier "repeat_n_292") (add (unsafe-nth (u8 0) (identifier "repeat_n_292")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_291")))))
                      (let "sz_ref_302"
                        (make-vec
                          (add (identifier "sz_299")
                            (let "n_ref_300" (make-vec (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))
                              (let "lebsz_ref_301" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_300")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_301")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_301") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_301")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_301"))))))))
                        (seq
                          (let "repeat_n_303" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_303")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_302")
                                  (let "sz_305" (add (unsafe-nth (u8 0) (identifier "sz_ref_302")) (size 2))
                                    (add (identifier "sz_305")
                                      (apply (identifier "channel_specs-sersize-of-row-binary")
                                        (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_303")) (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))))))
                                (set-vec (u8 0) (identifier "repeat_n_303") (add (unsafe-nth (u8 0) (identifier "repeat_n_303")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_302"))))))) 
                (set-vec (u8 0) (identifier "repeat_n_283") (add (unsafe-nth (u8 0) (identifier "repeat_n_283")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_282")))))
 */
static std::function<Size(t &)> sersize_of_row_binary_init()
{
  std::function<Size(t &)> fun412 { [&](t& p_0) {
    uint32_t id_413 { p_0.size() };
    Vec<1, uint32_t> id_414 {  id_413  };
    Size let_res_415;
    {
      Vec<1, uint32_t> n_ref_280 { id_414 };
      uint32_t id_416 { 1U };
      Vec<1, uint32_t> id_417 {  id_416  };
      Size let_res_418;
      {
        Vec<1, uint32_t> lebsz_ref_281 { id_417 };
        bool while_flag_419 { true };
        do {
          uint8_t id_420 { 0 };
          uint32_t id_421 { n_ref_280[id_420] };
          uint8_t id_422 { 0 };
          uint32_t id_423 { lebsz_ref_281[id_422] };
          uint8_t id_424 { 7 };
          uint32_t id_425 { uint32_t(id_423 << id_424) };
          bool id_426 { bool(id_421 >= id_425) };
          while_flag_419 = id_426;
          if (while_flag_419) {
            uint8_t id_427 { 0 };
            uint8_t id_428 { 0 };
            uint32_t id_429 { lebsz_ref_281[id_428] };
            uint32_t id_430 { 1U };
            uint32_t id_431 { uint32_t(id_429 + id_430) };
            Void id_432 { ((void)(lebsz_ref_281[id_427] = id_431), ::dessser::Void()) };
            (void)id_432;
          }
        } while (while_flag_419);
        (void)::dessser::Void();
        uint8_t id_433 { 0 };
        uint32_t id_434 { lebsz_ref_281[id_433] };
        Size id_435 { Size(id_434) };
        let_res_418 = id_435;
      }
      let_res_415 = let_res_418;
    }
    Vec<1, Size> id_436 {  let_res_415  };
    Size let_res_437;
    {
      Vec<1, Size> sz_ref_282 { id_436 };
      int32_t id_438 { 0L };
      Vec<1, int32_t> id_439 {  id_438  };
      {
        Vec<1, int32_t> repeat_n_283 { id_439 };
        bool while_flag_440 { true };
        do {
          uint32_t id_441 { p_0.size() };
          int32_t id_442 { int32_t(id_441) };
          uint8_t id_443 { 0 };
          int32_t id_444 { repeat_n_283[id_443] };
          bool id_445 { bool(id_442 > id_444) };
          while_flag_440 = id_445;
          if (while_flag_440) {
            uint8_t id_446 { 0 };
            uint8_t id_447 { 0 };
            Size id_448 { sz_ref_282[id_447] };
            Size let_res_449;
            {
              Size sz_284 { id_448 };
              uint8_t id_450 { 0 };
              int32_t id_451 { repeat_n_283[id_450] };
              ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_452 { p_0[id_451] };
              ::dessser::gen::output_specs::recipient id_453 { std::get<0>(id_452) };
              Size id_454 { recipient_sersize_of_row_binary(id_453) };
              Size id_455 { Size(sz_284 + id_454) };
              let_res_449 = id_455;
            }
            Size let_res_456;
            {
              Size sz_285 { let_res_449 };
              uint8_t id_457 { 0 };
              int32_t id_458 { repeat_n_283[id_457] };
              ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_459 { p_0[id_458] };
              ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_460 { std::get<1>(id_459) };
              ::dessser::gen::output_specs::file_type id_461 { id_460.file_type };
              Size id_462 { file_type_sersize_of_row_binary(id_461) };
              Size id_463 { Size(sz_285 + id_462) };
              Size let_res_464;
              {
                Size sz_287 { id_463 };
                auto fun465 { dessser::gen::fieldmask::sersize_of_row_binary };
                uint8_t id_466 { 0 };
                int32_t id_467 { repeat_n_283[id_466] };
                ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_468 { p_0[id_467] };
                ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_469 { std::get<1>(id_468) };
                dessser::gen::fieldmask::t_ext id_470 { id_469.fieldmask };
                Size id_471 { fun465(id_470) };
                Size id_472 { Size(sz_287 + id_471) };
                let_res_464 = id_472;
              }
              Size let_res_473;
              {
                Size sz_288 { let_res_464 };
                uint8_t id_474 { 0 };
                int32_t id_475 { repeat_n_283[id_474] };
                ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_476 { p_0[id_475] };
                ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_477 { std::get<1>(id_476) };
                Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_478 { id_477.filters };
                uint32_t id_479 { id_478.size() };
                Vec<1, uint32_t> id_480 {  id_479  };
                Size let_res_481;
                {
                  Vec<1, uint32_t> n_ref_289 { id_480 };
                  uint32_t id_482 { 1U };
                  Vec<1, uint32_t> id_483 {  id_482  };
                  Size let_res_484;
                  {
                    Vec<1, uint32_t> lebsz_ref_290 { id_483 };
                    bool while_flag_485 { true };
                    do {
                      uint8_t id_486 { 0 };
                      uint32_t id_487 { n_ref_289[id_486] };
                      uint8_t id_488 { 0 };
                      uint32_t id_489 { lebsz_ref_290[id_488] };
                      uint8_t id_490 { 7 };
                      uint32_t id_491 { uint32_t(id_489 << id_490) };
                      bool id_492 { bool(id_487 >= id_491) };
                      while_flag_485 = id_492;
                      if (while_flag_485) {
                        uint8_t id_493 { 0 };
                        uint8_t id_494 { 0 };
                        uint32_t id_495 { lebsz_ref_290[id_494] };
                        uint32_t id_496 { 1U };
                        uint32_t id_497 { uint32_t(id_495 + id_496) };
                        Void id_498 { ((void)(lebsz_ref_290[id_493] = id_497), ::dessser::Void()) };
                        (void)id_498;
                      }
                    } while (while_flag_485);
                    (void)::dessser::Void();
                    uint8_t id_499 { 0 };
                    uint32_t id_500 { lebsz_ref_290[id_499] };
                    Size id_501 { Size(id_500) };
                    let_res_484 = id_501;
                  }
                  let_res_481 = let_res_484;
                }
                Size id_502 { Size(sz_288 + let_res_481) };
                Vec<1, Size> id_503 {  id_502  };
                Size let_res_504;
                {
                  Vec<1, Size> sz_ref_291 { id_503 };
                  int32_t id_505 { 0L };
                  Vec<1, int32_t> id_506 {  id_505  };
                  {
                    Vec<1, int32_t> repeat_n_292 { id_506 };
                    bool while_flag_507 { true };
                    do {
                      uint8_t id_508 { 0 };
                      int32_t id_509 { repeat_n_283[id_508] };
                      ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_510 { p_0[id_509] };
                      ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_511 { std::get<1>(id_510) };
                      Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_512 { id_511.filters };
                      uint32_t id_513 { id_512.size() };
                      int32_t id_514 { int32_t(id_513) };
                      uint8_t id_515 { 0 };
                      int32_t id_516 { repeat_n_292[id_515] };
                      bool id_517 { bool(id_514 > id_516) };
                      while_flag_507 = id_517;
                      if (while_flag_507) {
                        uint8_t id_518 { 0 };
                        uint8_t id_519 { 0 };
                        Size id_520 { sz_ref_291[id_519] };
                        Size id_521 { 2UL };
                        Size id_522 { Size(id_520 + id_521) };
                        Size let_res_523;
                        {
                          Size sz_294 { id_522 };
                          uint8_t id_524 { 0 };
                          int32_t id_525 { repeat_n_292[id_524] };
                          uint8_t id_526 { 0 };
                          int32_t id_527 { repeat_n_283[id_526] };
                          ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_528 { p_0[id_527] };
                          ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_529 { std::get<1>(id_528) };
                          Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_530 { id_529.filters };
                          ::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46 id_531 { id_530[id_525] };
                          Arr<dessser::gen::raql_value::t_ext> id_532 { std::get<1>(id_531) };
                          uint32_t id_533 { id_532.size() };
                          Vec<1, uint32_t> id_534 {  id_533  };
                          Size let_res_535;
                          {
                            Vec<1, uint32_t> n_ref_295 { id_534 };
                            uint32_t id_536 { 1U };
                            Vec<1, uint32_t> id_537 {  id_536  };
                            Size let_res_538;
                            {
                              Vec<1, uint32_t> lebsz_ref_296 { id_537 };
                              bool while_flag_539 { true };
                              do {
                                uint8_t id_540 { 0 };
                                uint32_t id_541 { n_ref_295[id_540] };
                                uint8_t id_542 { 0 };
                                uint32_t id_543 { lebsz_ref_296[id_542] };
                                uint8_t id_544 { 7 };
                                uint32_t id_545 { uint32_t(id_543 << id_544) };
                                bool id_546 { bool(id_541 >= id_545) };
                                while_flag_539 = id_546;
                                if (while_flag_539) {
                                  uint8_t id_547 { 0 };
                                  uint8_t id_548 { 0 };
                                  uint32_t id_549 { lebsz_ref_296[id_548] };
                                  uint32_t id_550 { 1U };
                                  uint32_t id_551 { uint32_t(id_549 + id_550) };
                                  Void id_552 { ((void)(lebsz_ref_296[id_547] = id_551), ::dessser::Void()) };
                                  (void)id_552;
                                }
                              } while (while_flag_539);
                              (void)::dessser::Void();
                              uint8_t id_553 { 0 };
                              uint32_t id_554 { lebsz_ref_296[id_553] };
                              Size id_555 { Size(id_554) };
                              let_res_538 = id_555;
                            }
                            let_res_535 = let_res_538;
                          }
                          Size id_556 { Size(sz_294 + let_res_535) };
                          Vec<1, Size> id_557 {  id_556  };
                          Size let_res_558;
                          {
                            Vec<1, Size> sz_ref_297 { id_557 };
                            int32_t id_559 { 0L };
                            Vec<1, int32_t> id_560 {  id_559  };
                            {
                              Vec<1, int32_t> repeat_n_298 { id_560 };
                              bool while_flag_561 { true };
                              do {
                                uint8_t id_562 { 0 };
                                int32_t id_563 { repeat_n_292[id_562] };
                                uint8_t id_564 { 0 };
                                int32_t id_565 { repeat_n_283[id_564] };
                                ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_566 { p_0[id_565] };
                                ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_567 { std::get<1>(id_566) };
                                Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_568 { id_567.filters };
                                ::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46 id_569 { id_568[id_563] };
                                Arr<dessser::gen::raql_value::t_ext> id_570 { std::get<1>(id_569) };
                                uint32_t id_571 { id_570.size() };
                                int32_t id_572 { int32_t(id_571) };
                                uint8_t id_573 { 0 };
                                int32_t id_574 { repeat_n_298[id_573] };
                                bool id_575 { bool(id_572 > id_574) };
                                while_flag_561 = id_575;
                                if (while_flag_561) {
                                  uint8_t id_576 { 0 };
                                  uint8_t id_577 { 0 };
                                  Size id_578 { sz_ref_297[id_577] };
                                  auto fun579 { dessser::gen::raql_value::sersize_of_row_binary };
                                  uint8_t id_580 { 0 };
                                  int32_t id_581 { repeat_n_298[id_580] };
                                  uint8_t id_582 { 0 };
                                  int32_t id_583 { repeat_n_292[id_582] };
                                  uint8_t id_584 { 0 };
                                  int32_t id_585 { repeat_n_283[id_584] };
                                  ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_586 { p_0[id_585] };
                                  ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_587 { std::get<1>(id_586) };
                                  Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_588 { id_587.filters };
                                  ::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46 id_589 { id_588[id_583] };
                                  Arr<dessser::gen::raql_value::t_ext> id_590 { std::get<1>(id_589) };
                                  dessser::gen::raql_value::t_ext id_591 { id_590[id_581] };
                                  Size id_592 { fun579(id_591) };
                                  Size id_593 { Size(id_578 + id_592) };
                                  Void id_594 { ((void)(sz_ref_297[id_576] = id_593), ::dessser::Void()) };
                                  (void)id_594;
                                  uint8_t id_595 { 0 };
                                  uint8_t id_596 { 0 };
                                  int32_t id_597 { repeat_n_298[id_596] };
                                  int32_t id_598 { 1L };
                                  int32_t id_599 { int32_t(id_597 + id_598) };
                                  Void id_600 { ((void)(repeat_n_298[id_595] = id_599), ::dessser::Void()) };
                                  (void)id_600;
                                  (void)id_600;
                                }
                              } while (while_flag_561);
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_601 { 0 };
                            Size id_602 { sz_ref_297[id_601] };
                            let_res_558 = id_602;
                          }
                          let_res_523 = let_res_558;
                        }
                        Void id_603 { ((void)(sz_ref_291[id_518] = let_res_523), ::dessser::Void()) };
                        (void)id_603;
                        uint8_t id_604 { 0 };
                        uint8_t id_605 { 0 };
                        int32_t id_606 { repeat_n_292[id_605] };
                        int32_t id_607 { 1L };
                        int32_t id_608 { int32_t(id_606 + id_607) };
                        Void id_609 { ((void)(repeat_n_292[id_604] = id_608), ::dessser::Void()) };
                        (void)id_609;
                        (void)id_609;
                      }
                    } while (while_flag_507);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_610 { 0 };
                  Size id_611 { sz_ref_291[id_610] };
                  let_res_504 = id_611;
                }
                let_res_473 = let_res_504;
              }
              Size let_res_612;
              {
                Size sz_299 { let_res_473 };
                uint8_t id_613 { 0 };
                int32_t id_614 { repeat_n_283[id_613] };
                ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_615 { p_0[id_614] };
                ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_616 { std::get<1>(id_615) };
                Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> id_617 { id_616.channels };
                uint32_t id_618 { id_617.size() };
                Vec<1, uint32_t> id_619 {  id_618  };
                Size let_res_620;
                {
                  Vec<1, uint32_t> n_ref_300 { id_619 };
                  uint32_t id_621 { 1U };
                  Vec<1, uint32_t> id_622 {  id_621  };
                  Size let_res_623;
                  {
                    Vec<1, uint32_t> lebsz_ref_301 { id_622 };
                    bool while_flag_624 { true };
                    do {
                      uint8_t id_625 { 0 };
                      uint32_t id_626 { n_ref_300[id_625] };
                      uint8_t id_627 { 0 };
                      uint32_t id_628 { lebsz_ref_301[id_627] };
                      uint8_t id_629 { 7 };
                      uint32_t id_630 { uint32_t(id_628 << id_629) };
                      bool id_631 { bool(id_626 >= id_630) };
                      while_flag_624 = id_631;
                      if (while_flag_624) {
                        uint8_t id_632 { 0 };
                        uint8_t id_633 { 0 };
                        uint32_t id_634 { lebsz_ref_301[id_633] };
                        uint32_t id_635 { 1U };
                        uint32_t id_636 { uint32_t(id_634 + id_635) };
                        Void id_637 { ((void)(lebsz_ref_301[id_632] = id_636), ::dessser::Void()) };
                        (void)id_637;
                      }
                    } while (while_flag_624);
                    (void)::dessser::Void();
                    uint8_t id_638 { 0 };
                    uint32_t id_639 { lebsz_ref_301[id_638] };
                    Size id_640 { Size(id_639) };
                    let_res_623 = id_640;
                  }
                  let_res_620 = let_res_623;
                }
                Size id_641 { Size(sz_299 + let_res_620) };
                Vec<1, Size> id_642 {  id_641  };
                Size let_res_643;
                {
                  Vec<1, Size> sz_ref_302 { id_642 };
                  int32_t id_644 { 0L };
                  Vec<1, int32_t> id_645 {  id_644  };
                  {
                    Vec<1, int32_t> repeat_n_303 { id_645 };
                    bool while_flag_646 { true };
                    do {
                      uint8_t id_647 { 0 };
                      int32_t id_648 { repeat_n_283[id_647] };
                      ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_649 { p_0[id_648] };
                      ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_650 { std::get<1>(id_649) };
                      Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> id_651 { id_650.channels };
                      uint32_t id_652 { id_651.size() };
                      int32_t id_653 { int32_t(id_652) };
                      uint8_t id_654 { 0 };
                      int32_t id_655 { repeat_n_303[id_654] };
                      bool id_656 { bool(id_653 > id_655) };
                      while_flag_646 = id_656;
                      if (while_flag_646) {
                        uint8_t id_657 { 0 };
                        uint8_t id_658 { 0 };
                        Size id_659 { sz_ref_302[id_658] };
                        Size id_660 { 2UL };
                        Size id_661 { Size(id_659 + id_660) };
                        Size let_res_662;
                        {
                          Size sz_305 { id_661 };
                          uint8_t id_663 { 0 };
                          int32_t id_664 { repeat_n_303[id_663] };
                          uint8_t id_665 { 0 };
                          int32_t id_666 { repeat_n_283[id_665] };
                          ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_667 { p_0[id_666] };
                          ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_668 { std::get<1>(id_667) };
                          Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> id_669 { id_668.channels };
                          ::dessser::gen::output_specs::te2535d14520252a621d726d279906e71 id_670 { id_669[id_664] };
                          ::dessser::gen::output_specs::channel_specs id_671 { std::get<1>(id_670) };
                          Size id_672 { channel_specs_sersize_of_row_binary(id_671) };
                          Size id_673 { Size(sz_305 + id_672) };
                          let_res_662 = id_673;
                        }
                        Void id_674 { ((void)(sz_ref_302[id_657] = let_res_662), ::dessser::Void()) };
                        (void)id_674;
                        uint8_t id_675 { 0 };
                        uint8_t id_676 { 0 };
                        int32_t id_677 { repeat_n_303[id_676] };
                        int32_t id_678 { 1L };
                        int32_t id_679 { int32_t(id_677 + id_678) };
                        Void id_680 { ((void)(repeat_n_303[id_675] = id_679), ::dessser::Void()) };
                        (void)id_680;
                        (void)id_680;
                      }
                    } while (while_flag_646);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_681 { 0 };
                  Size id_682 { sz_ref_302[id_681] };
                  let_res_643 = id_682;
                }
                let_res_612 = let_res_643;
              }
              let_res_456 = let_res_612;
            }
            Void id_683 { ((void)(sz_ref_282[id_446] = let_res_456), ::dessser::Void()) };
            (void)id_683;
            uint8_t id_684 { 0 };
            uint8_t id_685 { 0 };
            int32_t id_686 { repeat_n_283[id_685] };
            int32_t id_687 { 1L };
            int32_t id_688 { int32_t(id_686 + id_687) };
            Void id_689 { ((void)(repeat_n_283[id_684] = id_688), ::dessser::Void()) };
            (void)id_689;
            (void)id_689;
          }
        } while (while_flag_440);
        (void)::dessser::Void();
      }
      (void)::dessser::Void();
      uint8_t id_690 { 0 };
      Size id_691 { sz_ref_282[id_690] };
      let_res_437 = id_691;
    }
    return let_res_437;
  }
   };
  return fun412;
}
std::function<Size(t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_123" (let-pair "dfloat_fst_121" "dfloat_snd_122" (read-u64 little-endian (param 0)) (make-tup (float-of-u64 (identifier "dfloat_fst_121")) (identifier "dfloat_snd_122")))
        (let-pair "dtup_fst_124" "dtup_snd_125" (identifier "dtup_123")
          (let "dtup_129" (let-pair "di16_fst_127" "di16_snd_128" (read-u16 little-endian (identifier "dtup_snd_125")) (make-tup (to-i16 (identifier "di16_fst_127")) (identifier "di16_snd_128")))
            (let-pair "dtup_fst_130" "dtup_snd_131" (identifier "dtup_129")
              (let-pair "du32_fst_133" "du32_snd_134" (read-u32 little-endian (identifier "dtup_snd_131"))
                (make-tup (make-tup (identifier "dtup_fst_124") (identifier "dtup_fst_130") (identifier "du32_fst_133")) (identifier "du32_snd_134"))))))))
 */
static std::function<::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04(Pointer &)> channel_specs_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04(Pointer &)> fun692 { [&](Pointer p_0) {
    ::dessser::gen::output_specs::td2cd337bb3c8bc04d5603393d084985b id_693 { p_0.readU64Le() };
    ::dessser::gen::output_specs::t9a758baeff17224a77e1a522010b4168 letpair_res_694;
    {
      auto dfloat_fst_121 { std::get<0>(id_693) };
      auto dfloat_snd_122 { std::get<1>(id_693) };
      double id_695 { float_of_qword(dfloat_fst_121) };
      ::dessser::gen::output_specs::t9a758baeff17224a77e1a522010b4168 id_696 { id_695, dfloat_snd_122 };
      letpair_res_694 = id_696;
    }
    ::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04 let_res_697;
    {
      ::dessser::gen::output_specs::t9a758baeff17224a77e1a522010b4168 dtup_123 { letpair_res_694 };
      ::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04 letpair_res_698;
      {
        auto dtup_fst_124 { std::get<0>(dtup_123) };
        auto dtup_snd_125 { std::get<1>(dtup_123) };
        ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_699 { dtup_snd_125.readU16Le() };
        ::dessser::gen::output_specs::t432678e1cf78673023ea4e019ea3fbd8 letpair_res_700;
        {
          auto di16_fst_127 { std::get<0>(id_699) };
          auto di16_snd_128 { std::get<1>(id_699) };
          int16_t id_701 { int16_t(di16_fst_127) };
          ::dessser::gen::output_specs::t432678e1cf78673023ea4e019ea3fbd8 id_702 { id_701, di16_snd_128 };
          letpair_res_700 = id_702;
        }
        ::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04 let_res_703;
        {
          ::dessser::gen::output_specs::t432678e1cf78673023ea4e019ea3fbd8 dtup_129 { letpair_res_700 };
          ::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04 letpair_res_704;
          {
            auto dtup_fst_130 { std::get<0>(dtup_129) };
            auto dtup_snd_131 { std::get<1>(dtup_129) };
            ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_705 { dtup_snd_131.readU32Le() };
            ::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04 letpair_res_706;
            {
              auto du32_fst_133 { std::get<0>(id_705) };
              auto du32_snd_134 { std::get<1>(id_705) };
              ::dessser::gen::output_specs::channel_specs id_707 { dtup_fst_124, dtup_fst_130, du32_fst_133 };
              ::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04 id_708 { id_707, du32_snd_134 };
              letpair_res_706 = id_708;
            }
            letpair_res_704 = letpair_res_706;
          }
          let_res_703 = letpair_res_704;
        }
        letpair_res_698 = let_res_703;
      }
      let_res_697 = letpair_res_698;
    }
    return let_res_697;
  }
   };
  return fun692;
}
std::function<::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04(Pointer &)> channel_specs_of_row_binary(channel_specs_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_93" (let-pair "du16_fst_88" "du16_snd_89" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_88") (identifier "du16_snd_89")))
        (let-pair "dsum1_fst_94" "dsum1_snd_95" (identifier "dsum1_93")
          (if (eq (u16 0) (identifier "dsum1_fst_94")) (make-tup (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 0 (nop)) (identifier "dsum1_snd_95"))
            (seq (assert (eq (identifier "dsum1_fst_94") (u16 1)))
              (let "drec_99" (let-pair "dbool_fst_97" "dbool_snd_98" (read-u8 (identifier "dsum1_snd_95")) (make-tup (not (eq (identifier "dbool_fst_97") (u8 0))) (identifier "dbool_snd_98")))
                (let-pair "drec_fst_100" "drec_snd_101" (identifier "drec_99")
                  (let "drec_105" (let-pair "du32_fst_103" "du32_snd_104" (read-u32 little-endian (identifier "drec_snd_101")) (make-tup (identifier "du32_fst_103") (identifier "du32_snd_104")))
                    (let-pair "drec_fst_106" "drec_snd_107" (identifier "drec_105")
                      (let-pair "du32_fst_109" "du32_snd_110" (read-u32 little-endian (identifier "drec_snd_107"))
                        (make-tup
                          (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 1
                            (make-rec (string "num_batches") (identifier "du32_fst_109") (string "batch_size") (identifier "drec_fst_106") (string "with_index") (identifier "drec_fst_100"))) 
                          (identifier "du32_snd_110"))))))))))))
 */
static std::function<::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31(Pointer &)> file_type_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31(Pointer &)> fun709 { [&](Pointer p_0) {
    ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_710 { p_0.readU16Le() };
    ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 letpair_res_711;
    {
      auto du16_fst_88 { std::get<0>(id_710) };
      auto du16_snd_89 { std::get<1>(id_710) };
      ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_712 { du16_fst_88, du16_snd_89 };
      letpair_res_711 = id_712;
    }
    ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 let_res_713;
    {
      ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 dsum1_93 { letpair_res_711 };
      ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 letpair_res_714;
      {
        auto dsum1_fst_94 { std::get<0>(dsum1_93) };
        auto dsum1_snd_95 { std::get<1>(dsum1_93) };
        uint16_t id_715 { 0 };
        bool id_716 { bool(id_715 == dsum1_fst_94) };
        ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 choose_res_717;
        if (id_716) {
          (void)::dessser::Void();
          ::dessser::gen::output_specs::file_type id_718 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 id_719 { id_718, dsum1_snd_95 };
          choose_res_717 = id_719;
        } else {
          uint16_t id_720 { 1 };
          bool id_721 { bool(dsum1_fst_94 == id_720) };
          Void id_722 { ((void)(assert(id_721)), ::dessser::Void()) };
          (void)id_722;
          ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 id_723 { dsum1_snd_95.readU8() };
          ::dessser::gen::output_specs::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_724;
          {
            auto dbool_fst_97 { std::get<0>(id_723) };
            auto dbool_snd_98 { std::get<1>(id_723) };
            uint8_t id_725 { 0 };
            bool id_726 { bool(dbool_fst_97 == id_725) };
            bool id_727 { ! id_726 };
            ::dessser::gen::output_specs::tf9a0a3fefc87c9e10a93d3a172850c26 id_728 { id_727, dbool_snd_98 };
            letpair_res_724 = id_728;
          }
          ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 let_res_729;
          {
            ::dessser::gen::output_specs::tf9a0a3fefc87c9e10a93d3a172850c26 drec_99 { letpair_res_724 };
            ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 letpair_res_730;
            {
              auto drec_fst_100 { std::get<0>(drec_99) };
              auto drec_snd_101 { std::get<1>(drec_99) };
              ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_731 { drec_snd_101.readU32Le() };
              ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 letpair_res_732;
              {
                auto du32_fst_103 { std::get<0>(id_731) };
                auto du32_snd_104 { std::get<1>(id_731) };
                ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_733 { du32_fst_103, du32_snd_104 };
                letpair_res_732 = id_733;
              }
              ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 let_res_734;
              {
                ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 drec_105 { letpair_res_732 };
                ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 letpair_res_735;
                {
                  auto drec_fst_106 { std::get<0>(drec_105) };
                  auto drec_snd_107 { std::get<1>(drec_105) };
                  ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_736 { drec_snd_107.readU32Le() };
                  ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 letpair_res_737;
                  {
                    auto du32_fst_109 { std::get<0>(id_736) };
                    auto du32_snd_110 { std::get<1>(id_736) };
                    ::dessser::gen::output_specs::ta86dfe69264c9600d57a3b5ead0f7951 id_738 { drec_fst_100, drec_fst_106, du32_fst_109 };
                    ::dessser::gen::output_specs::file_type id_739 { std::in_place_index<1>, id_738 };
                    ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 id_740 { id_739, du32_snd_110 };
                    letpair_res_737 = id_740;
                  }
                  letpair_res_735 = letpair_res_737;
                }
                let_res_734 = letpair_res_735;
              }
              letpair_res_730 = let_res_734;
            }
            let_res_729 = letpair_res_730;
          }
          choose_res_717 = let_res_729;
        }
        letpair_res_714 = choose_res_717;
      }
      let_res_713 = letpair_res_714;
    }
    return let_res_713;
  }
   };
  return fun709;
}
std::function<::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31(Pointer &)> file_type_of_row_binary(file_type_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (let-pair "dsum2_fst_85" "dsum2_snd_86" (apply (ext-identifier file_path of-row-binary) (identifier "dsum1_snd_65"))
              (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" 0 (identifier "dsum2_fst_85")) (identifier "dsum2_snd_86")))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (let "dstring1_75"
                (let "leb_ref_69" (make-vec (u32 0))
                  (let "shft_ref_70" (make-vec (u8 0))
                    (let "p_ref_71" (make-vec (identifier "dsum1_snd_65"))
                      (seq
                        (while
                          (let "leb128_72" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_71")))
                            (let-pair "leb128_fst_73" "leb128_snd_74" 
                              (identifier "leb128_72")
                              (seq (set-vec (u8 0) (identifier "p_ref_71") (identifier "leb128_snd_74"))
                                (set-vec (u8 0) (identifier "leb_ref_69")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_73") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_70"))) (unsafe-nth (u8 0) (identifier "leb_ref_69"))))
                                (set-vec (u8 0) (identifier "shft_ref_70") (add (unsafe-nth (u8 0) (identifier "shft_ref_70")) (u8 7))) 
                                (ge (identifier "leb128_fst_73") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_69"))) (unsafe-nth (u8 0) (identifier "p_ref_71")))))))
                (let-pair "dstring1_fst_76" "dstring1_snd_77" (identifier "dstring1_75")
                  (let-pair "dstring2_fst_79" "dstring2_snd_80" (read-bytes (identifier "dstring1_snd_77") (identifier "dstring1_fst_76"))
                    (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" 1 (string-of-bytes (identifier "dstring2_fst_79"))) (identifier "dstring2_snd_80")))))
              (seq (assert (eq (identifier "dsum1_fst_64") (u16 2)))
                (let-pair "dsum2_fst_67" "dsum2_snd_68" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                  (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" 2 (identifier "dsum2_fst_67")) (identifier "dsum2_snd_68")))))))))
 */
static std::function<::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1(Pointer &)> recipient_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1(Pointer &)> fun741 { [&](Pointer p_0) {
    ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_742 { p_0.readU16Le() };
    ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 letpair_res_743;
    {
      auto du16_fst_58 { std::get<0>(id_742) };
      auto du16_snd_59 { std::get<1>(id_742) };
      ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_744 { du16_fst_58, du16_snd_59 };
      letpair_res_743 = id_744;
    }
    ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 let_res_745;
    {
      ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_743 };
      ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 letpair_res_746;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_747 { 0 };
        bool id_748 { bool(id_747 == dsum1_fst_64) };
        ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 choose_res_749;
        if (id_748) {
          auto fun750 { dessser::gen::file_path::of_row_binary };
          ::dessser::gen::output_specs::td0a4a9551c4a7c5b58d84275e2a098f7 id_751 { fun750(dsum1_snd_65) };
          ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 letpair_res_752;
          {
            auto dsum2_fst_85 { std::get<0>(id_751) };
            auto dsum2_snd_86 { std::get<1>(id_751) };
            ::dessser::gen::output_specs::recipient id_753 { std::in_place_index<0>, dsum2_fst_85 };
            ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 id_754 { id_753, dsum2_snd_86 };
            letpair_res_752 = id_754;
          }
          choose_res_749 = letpair_res_752;
        } else {
          uint16_t id_755 { 1 };
          bool id_756 { bool(id_755 == dsum1_fst_64) };
          ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 choose_res_757;
          if (id_756) {
            uint32_t id_758 { 0U };
            Vec<1, uint32_t> id_759 {  id_758  };
            ::dessser::gen::output_specs::t12fb9c475959b52bf7b17b155a955ffa let_res_760;
            {
              Vec<1, uint32_t> leb_ref_69 { id_759 };
              uint8_t id_761 { 0 };
              Vec<1, uint8_t> id_762 {  id_761  };
              ::dessser::gen::output_specs::t12fb9c475959b52bf7b17b155a955ffa let_res_763;
              {
                Vec<1, uint8_t> shft_ref_70 { id_762 };
                Vec<1, Pointer> id_764 {  dsum1_snd_65  };
                ::dessser::gen::output_specs::t12fb9c475959b52bf7b17b155a955ffa let_res_765;
                {
                  Vec<1, Pointer> p_ref_71 { id_764 };
                  bool while_flag_766 { true };
                  do {
                    uint8_t id_767 { 0 };
                    Pointer id_768 { p_ref_71[id_767] };
                    ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 id_769 { id_768.readU8() };
                    bool let_res_770;
                    {
                      ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 leb128_72 { id_769 };
                      bool letpair_res_771;
                      {
                        auto leb128_fst_73 { std::get<0>(leb128_72) };
                        auto leb128_snd_74 { std::get<1>(leb128_72) };
                        uint8_t id_772 { 0 };
                        Void id_773 { ((void)(p_ref_71[id_772] = leb128_snd_74), ::dessser::Void()) };
                        (void)id_773;
                        uint8_t id_774 { 0 };
                        uint8_t id_775 { 127 };
                        uint8_t id_776 { uint8_t(leb128_fst_73 & id_775) };
                        uint32_t id_777 { uint32_t(id_776) };
                        uint8_t id_778 { 0 };
                        uint8_t id_779 { shft_ref_70[id_778] };
                        uint32_t id_780 { uint32_t(id_777 << id_779) };
                        uint8_t id_781 { 0 };
                        uint32_t id_782 { leb_ref_69[id_781] };
                        uint32_t id_783 { uint32_t(id_780 | id_782) };
                        Void id_784 { ((void)(leb_ref_69[id_774] = id_783), ::dessser::Void()) };
                        (void)id_784;
                        uint8_t id_785 { 0 };
                        uint8_t id_786 { 0 };
                        uint8_t id_787 { shft_ref_70[id_786] };
                        uint8_t id_788 { 7 };
                        uint8_t id_789 { uint8_t(id_787 + id_788) };
                        Void id_790 { ((void)(shft_ref_70[id_785] = id_789), ::dessser::Void()) };
                        (void)id_790;
                        uint8_t id_791 { 128 };
                        bool id_792 { bool(leb128_fst_73 >= id_791) };
                        letpair_res_771 = id_792;
                      }
                      let_res_770 = letpair_res_771;
                    }
                    while_flag_766 = let_res_770;
                    if (while_flag_766) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_766);
                  (void)::dessser::Void();
                  uint8_t id_793 { 0 };
                  uint32_t id_794 { leb_ref_69[id_793] };
                  Size id_795 { Size(id_794) };
                  uint8_t id_796 { 0 };
                  Pointer id_797 { p_ref_71[id_796] };
                  ::dessser::gen::output_specs::t12fb9c475959b52bf7b17b155a955ffa id_798 { id_795, id_797 };
                  let_res_765 = id_798;
                }
                let_res_763 = let_res_765;
              }
              let_res_760 = let_res_763;
            }
            ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 let_res_799;
            {
              ::dessser::gen::output_specs::t12fb9c475959b52bf7b17b155a955ffa dstring1_75 { let_res_760 };
              ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 letpair_res_800;
              {
                auto dstring1_fst_76 { std::get<0>(dstring1_75) };
                auto dstring1_snd_77 { std::get<1>(dstring1_75) };
                ::dessser::gen::output_specs::t9ef6882174ae71a34a3c5ef6b29242fb id_801 { dstring1_snd_77.readBytes(dstring1_fst_76) };
                ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 letpair_res_802;
                {
                  auto dstring2_fst_79 { std::get<0>(id_801) };
                  auto dstring2_snd_80 { std::get<1>(id_801) };
                  std::string id_803 { dstring2_fst_79.toString() };
                  ::dessser::gen::output_specs::recipient id_804 { std::in_place_index<1>, id_803 };
                  ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 id_805 { id_804, dstring2_snd_80 };
                  letpair_res_802 = id_805;
                }
                letpair_res_800 = letpair_res_802;
              }
              let_res_799 = letpair_res_800;
            }
            choose_res_757 = let_res_799;
          } else {
            uint16_t id_806 { 2 };
            bool id_807 { bool(dsum1_fst_64 == id_806) };
            Void id_808 { ((void)(assert(id_807)), ::dessser::Void()) };
            (void)id_808;
            auto fun809 { dessser::gen::sync_key::of_row_binary };
            ::dessser::gen::output_specs::t0e7f6ba9e1ceef343afe44456f9067ec id_810 { fun809(dsum1_snd_65) };
            ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 letpair_res_811;
            {
              auto dsum2_fst_67 { std::get<0>(id_810) };
              auto dsum2_snd_68 { std::get<1>(id_810) };
              ::dessser::gen::output_specs::recipient id_812 { std::in_place_index<2>, dsum2_fst_67 };
              ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 id_813 { id_812, dsum2_snd_68 };
              letpair_res_811 = id_813;
            }
            choose_res_757 = letpair_res_811;
          }
          choose_res_749 = choose_res_757;
        }
        letpair_res_746 = choose_res_749;
      }
      let_res_745 = letpair_res_746;
    }
    return let_res_745;
  }
   };
  return fun741;
}
std::function<::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1(Pointer &)> recipient_of_row_binary(recipient_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "dlist4_fst_264" "dlist4_snd_265"
        (let "dlist1_147"
          (let "leb_ref_138" (make-vec (u32 0))
            (let "shft_ref_139" (make-vec (u8 0))
              (let "p_ref_140" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_141" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_140")))
                      (let-pair "leb128_fst_142" "leb128_snd_143" (identifier "leb128_141")
                        (seq (set-vec (u8 0) (identifier "p_ref_140") (identifier "leb128_snd_143"))
                          (set-vec (u8 0) (identifier "leb_ref_138")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_142") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_139"))) (unsafe-nth (u8 0) (identifier "leb_ref_138"))))
                          (set-vec (u8 0) (identifier "shft_ref_139") (add (unsafe-nth (u8 0) (identifier "shft_ref_139")) (u8 7))) 
                          (ge (identifier "leb128_fst_142") (u8 128))))) 
                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_138")) (unsafe-nth (u8 0) (identifier "p_ref_140")))))))
          (let-pair "dlist1_fst_148" "dlist1_snd_149" (identifier "dlist1_147")
            (let "inits_src_ref_150"
              (make-vec
                (make-tup
                  (end-of-list "((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})")
                  (identifier "dlist1_snd_149")))
              (seq
                (let "repeat_n_151" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_148")) (unsafe-nth (u8 0) (identifier "repeat_n_151")))
                    (seq
                      (let "dlist2_152" (unsafe-nth (u8 0) (identifier "inits_src_ref_150"))
                        (let-pair "dlist2_fst_153" "dlist2_snd_154" (identifier "dlist2_152")
                          (set-vec (u8 0) (identifier "inits_src_ref_150")
                            (let "dtup_155" (apply (identifier "recipient-of-row-binary") (identifier "dlist2_snd_154"))
                              (let-pair "dtup_fst_156" "dtup_snd_157" 
                                (identifier "dtup_155")
                                (let "drec_158" (apply (identifier "file_type-of-row-binary") (identifier "dtup_snd_157"))
                                  (let-pair "drec_fst_159" "drec_snd_160" 
                                    (identifier "drec_158")
                                    (let "drec_161" (apply (ext-identifier fieldmask of-row-binary) (identifier "drec_snd_160"))
                                      (let-pair "drec_fst_162" "drec_snd_163" 
                                        (identifier "drec_161")
                                        (let "drec_219"
                                          (let-pair "dlist4_fst_217" "dlist4_snd_218"
                                            (let "dlist1_173"
                                              (let "leb_ref_164" (make-vec (u32 0))
                                                (let "shft_ref_165" (make-vec (u8 0))
                                                  (let "p_ref_166" (make-vec (identifier "drec_snd_163"))
                                                    (seq
                                                      (while
                                                        (let "leb128_167" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_166")))
                                                          (let-pair "leb128_fst_168" "leb128_snd_169" 
                                                            (identifier "leb128_167")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_166") (identifier "leb128_snd_169"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_164")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_168") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_165")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_164")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_165") (add (unsafe-nth (u8 0) (identifier "shft_ref_165")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_168") (u8 128))))) 
                                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_164")) (unsafe-nth (u8 0) (identifier "p_ref_166")))))))
                                              (let-pair "dlist1_fst_174" "dlist1_snd_175" 
                                                (identifier "dlist1_173")
                                                (let "inits_src_ref_176" 
                                                  (make-vec (make-tup (end-of-list "(U16; $raql_value[])") (identifier "dlist1_snd_175")))
                                                  (seq
                                                    (let "repeat_n_177" 
                                                      (make-vec (i32 0))
                                                      (while (gt (to-i32 (identifier "dlist1_fst_174")) (unsafe-nth (u8 0) (identifier "repeat_n_177")))
                                                        (seq
                                                          (let "dlist2_178" 
                                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_176"))
                                                            (let-pair "dlist2_fst_179" "dlist2_snd_180" 
                                                              (identifier "dlist2_178")
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "inits_src_ref_176")
                                                                (let "dtup_184"
                                                                  (let-pair "du16_fst_182" "du16_snd_183" (read-u16 little-endian (identifier "dlist2_snd_180")) (make-tup (identifier "du16_fst_182") (identifier "du16_snd_183")))
                                                                  (let-pair "dtup_fst_185" "dtup_snd_186" 
                                                                    (identifier "dtup_184")
                                                                    (let-pair "dlist4_fst_208" "dlist4_snd_209"
                                                                    (let "dlist1_196"
                                                                    (let "leb_ref_187" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_188" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_189" 
                                                                    (make-vec (identifier "dtup_snd_186"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_190" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_189")))
                                                                    (let-pair "leb128_fst_191" "leb128_snd_192" 
                                                                    (identifier "leb128_190")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_189") (identifier "leb128_snd_192"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_187")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_191") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_188")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_187")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_188") (add (unsafe-nth (u8 0) (identifier "shft_ref_188")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_191") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_187")) (unsafe-nth (u8 0) (identifier "p_ref_189")))))))
                                                                    (let-pair "dlist1_fst_197" "dlist1_snd_198" 
                                                                    (identifier "dlist1_196")
                                                                    (let "inits_src_ref_199" 
                                                                    (make-vec (make-tup (end-of-list "$raql_value") (identifier "dlist1_snd_198")))
                                                                    (seq
                                                                    (let "repeat_n_200" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_197")) (unsafe-nth (u8 0) (identifier "repeat_n_200")))
                                                                    (seq
                                                                    (let "dlist2_201" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_199"))
                                                                    (let-pair "dlist2_fst_202" "dlist2_snd_203" 
                                                                    (identifier "dlist2_201")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_199")
                                                                    (let-pair "dlist3_fst_205" "dlist3_snd_206" 
                                                                    (apply (ext-identifier raql_value of-row-binary) (identifier "dlist2_snd_203"))
                                                                    (make-tup (cons (identifier "dlist3_fst_205") (identifier "dlist2_fst_202")) (identifier "dlist3_snd_206"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_200") (add (unsafe-nth (u8 0) (identifier "repeat_n_200")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_199"))))))
                                                                    (make-tup 
                                                                    (cons (make-tup (identifier "dtup_fst_185") (arr-of-lst-rev (identifier "dlist4_fst_208"))) (identifier "dlist2_fst_179")) 
                                                                    (identifier "dlist4_snd_209")))))))) 
                                                          (set-vec (u8 0) (identifier "repeat_n_177") (add (unsafe-nth (u8 0) (identifier "repeat_n_177")) (i32 1)))))) 
                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_176")))))) 
                                            (make-tup (arr-of-lst-rev (identifier "dlist4_fst_217")) (identifier "dlist4_snd_218")))
                                          (let-pair "drec_fst_220" "drec_snd_221" 
                                            (identifier "drec_219")
                                            (let-pair "dlist4_fst_252" "dlist4_snd_253"
                                              (let "dlist1_231"
                                                (let "leb_ref_222" (make-vec (u32 0))
                                                  (let "shft_ref_223" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_224" 
                                                      (make-vec (identifier "drec_snd_221"))
                                                      (seq
                                                        (while
                                                          (let "leb128_225" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_224")))
                                                            (let-pair "leb128_fst_226" "leb128_snd_227" 
                                                              (identifier "leb128_225")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_224") (identifier "leb128_snd_227"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_222")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_226") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_223")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_222")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_223") (add (unsafe-nth (u8 0) (identifier "shft_ref_223")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_226") (u8 128))))) 
                                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_222")) (unsafe-nth (u8 0) (identifier "p_ref_224")))))))
                                                (let-pair "dlist1_fst_232" "dlist1_snd_233" 
                                                  (identifier "dlist1_231")
                                                  (let "inits_src_ref_234" 
                                                    (make-vec (make-tup (end-of-list "(U16; (channel_specs AS (FLOAT; I16; U32)))") (identifier "dlist1_snd_233")))
                                                    (seq
                                                      (let "repeat_n_235" 
                                                        (make-vec (i32 0))
                                                        (while (gt (to-i32 (identifier "dlist1_fst_232")) (unsafe-nth (u8 0) (identifier "repeat_n_235")))
                                                          (seq
                                                            (let "dlist2_236" 
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_234"))
                                                              (let-pair "dlist2_fst_237" "dlist2_snd_238" 
                                                                (identifier "dlist2_236")
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "inits_src_ref_234")
                                                                  (let "dtup_242"
                                                                    (let-pair "du16_fst_240" "du16_snd_241" 
                                                                    (read-u16 little-endian (identifier "dlist2_snd_238")) 
                                                                    (make-tup (identifier "du16_fst_240") (identifier "du16_snd_241")))
                                                                    (let-pair "dtup_fst_243" "dtup_snd_244" 
                                                                    (identifier "dtup_242")
                                                                    (let-pair "dtup_fst_246" "dtup_snd_247" 
                                                                    (apply (identifier "channel_specs-of-row-binary") (identifier "dtup_snd_244"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_243") (identifier "dtup_fst_246")) (identifier "dlist2_fst_237")) (identifier "dtup_snd_247"))))))))
                                                            (set-vec (u8 0) (identifier "repeat_n_235") (add (unsafe-nth (u8 0) (identifier "repeat_n_235")) (i32 1)))))) 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_234"))))))
                                              (make-tup
                                                (cons
                                                  (make-tup (identifier "dtup_fst_156")
                                                    (make-rec (string "channels") 
                                                      (arr-of-lst-rev (identifier "dlist4_fst_252")) 
                                                      (string "filters") 
                                                      (identifier "drec_fst_220") 
                                                      (string "fieldmask") 
                                                      (identifier "drec_fst_162") 
                                                      (string "file_type") 
                                                      (identifier "drec_fst_159"))) 
                                                  (identifier "dlist2_fst_153")) 
                                                (identifier "dlist4_snd_253")))))))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_151") (add (unsafe-nth (u8 0) (identifier "repeat_n_151")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_150")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_264")) (identifier "dlist4_snd_265"))))
 */
static std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> fun814 { [&](Pointer p_0) {
    uint32_t id_815 { 0U };
    Vec<1, uint32_t> id_816 {  id_815  };
    ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_817;
    {
      Vec<1, uint32_t> leb_ref_138 { id_816 };
      uint8_t id_818 { 0 };
      Vec<1, uint8_t> id_819 {  id_818  };
      ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_820;
      {
        Vec<1, uint8_t> shft_ref_139 { id_819 };
        Vec<1, Pointer> id_821 {  p_0  };
        ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_822;
        {
          Vec<1, Pointer> p_ref_140 { id_821 };
          bool while_flag_823 { true };
          do {
            uint8_t id_824 { 0 };
            Pointer id_825 { p_ref_140[id_824] };
            ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 id_826 { id_825.readU8() };
            bool let_res_827;
            {
              ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 leb128_141 { id_826 };
              bool letpair_res_828;
              {
                auto leb128_fst_142 { std::get<0>(leb128_141) };
                auto leb128_snd_143 { std::get<1>(leb128_141) };
                uint8_t id_829 { 0 };
                Void id_830 { ((void)(p_ref_140[id_829] = leb128_snd_143), ::dessser::Void()) };
                (void)id_830;
                uint8_t id_831 { 0 };
                uint8_t id_832 { 127 };
                uint8_t id_833 { uint8_t(leb128_fst_142 & id_832) };
                uint32_t id_834 { uint32_t(id_833) };
                uint8_t id_835 { 0 };
                uint8_t id_836 { shft_ref_139[id_835] };
                uint32_t id_837 { uint32_t(id_834 << id_836) };
                uint8_t id_838 { 0 };
                uint32_t id_839 { leb_ref_138[id_838] };
                uint32_t id_840 { uint32_t(id_837 | id_839) };
                Void id_841 { ((void)(leb_ref_138[id_831] = id_840), ::dessser::Void()) };
                (void)id_841;
                uint8_t id_842 { 0 };
                uint8_t id_843 { 0 };
                uint8_t id_844 { shft_ref_139[id_843] };
                uint8_t id_845 { 7 };
                uint8_t id_846 { uint8_t(id_844 + id_845) };
                Void id_847 { ((void)(shft_ref_139[id_842] = id_846), ::dessser::Void()) };
                (void)id_847;
                uint8_t id_848 { 128 };
                bool id_849 { bool(leb128_fst_142 >= id_848) };
                letpair_res_828 = id_849;
              }
              let_res_827 = letpair_res_828;
            }
            while_flag_823 = let_res_827;
            if (while_flag_823) {
              (void)::dessser::Void();
            }
          } while (while_flag_823);
          (void)::dessser::Void();
          uint8_t id_850 { 0 };
          uint32_t id_851 { leb_ref_138[id_850] };
          uint8_t id_852 { 0 };
          Pointer id_853 { p_ref_140[id_852] };
          ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_854 { id_851, id_853 };
          let_res_822 = id_854;
        }
        let_res_820 = let_res_822;
      }
      let_res_817 = let_res_820;
    }
    ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 let_res_855;
    {
      ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 dlist1_147 { let_res_817 };
      ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 letpair_res_856;
      {
        auto dlist1_fst_148 { std::get<0>(dlist1_147) };
        auto dlist1_snd_149 { std::get<1>(dlist1_147) };
        Lst<::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523> endoflist_857;
        ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 id_858 { endoflist_857, dlist1_snd_149 };
        Vec<1, ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57> id_859 {  id_858  };
        ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 let_res_860;
        {
          Vec<1, ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57> inits_src_ref_150 { id_859 };
          int32_t id_861 { 0L };
          Vec<1, int32_t> id_862 {  id_861  };
          {
            Vec<1, int32_t> repeat_n_151 { id_862 };
            bool while_flag_863 { true };
            do {
              int32_t id_864 { int32_t(dlist1_fst_148) };
              uint8_t id_865 { 0 };
              int32_t id_866 { repeat_n_151[id_865] };
              bool id_867 { bool(id_864 > id_866) };
              while_flag_863 = id_867;
              if (while_flag_863) {
                uint8_t id_868 { 0 };
                ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 id_869 { inits_src_ref_150[id_868] };
                {
                  ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 dlist2_152 { id_869 };
                  {
                    auto dlist2_fst_153 { std::get<0>(dlist2_152) };
                    auto dlist2_snd_154 { std::get<1>(dlist2_152) };
                    uint8_t id_870 { 0 };
                    ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 id_871 { recipient_of_row_binary(dlist2_snd_154) };
                    ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 let_res_872;
                    {
                      ::dessser::gen::output_specs::t5bd421c43649a0ea41776ce18e1f03c1 dtup_155 { id_871 };
                      ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 letpair_res_873;
                      {
                        auto dtup_fst_156 { std::get<0>(dtup_155) };
                        auto dtup_snd_157 { std::get<1>(dtup_155) };
                        ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 id_874 { file_type_of_row_binary(dtup_snd_157) };
                        ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 let_res_875;
                        {
                          ::dessser::gen::output_specs::te5b605570c13dd86d5874e55c6b74a31 drec_158 { id_874 };
                          ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 letpair_res_876;
                          {
                            auto drec_fst_159 { std::get<0>(drec_158) };
                            auto drec_snd_160 { std::get<1>(drec_158) };
                            auto fun877 { dessser::gen::fieldmask::of_row_binary };
                            ::dessser::gen::output_specs::t20c08c99d00b8309a3e7d83f43ad946f id_878 { fun877(drec_snd_160) };
                            ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 let_res_879;
                            {
                              ::dessser::gen::output_specs::t20c08c99d00b8309a3e7d83f43ad946f drec_161 { id_878 };
                              ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 letpair_res_880;
                              {
                                auto drec_fst_162 { std::get<0>(drec_161) };
                                auto drec_snd_163 { std::get<1>(drec_161) };
                                uint32_t id_881 { 0U };
                                Vec<1, uint32_t> id_882 {  id_881  };
                                ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_883;
                                {
                                  Vec<1, uint32_t> leb_ref_164 { id_882 };
                                  uint8_t id_884 { 0 };
                                  Vec<1, uint8_t> id_885 {  id_884  };
                                  ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_886;
                                  {
                                    Vec<1, uint8_t> shft_ref_165 { id_885 };
                                    Vec<1, Pointer> id_887 {  drec_snd_163  };
                                    ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_888;
                                    {
                                      Vec<1, Pointer> p_ref_166 { id_887 };
                                      bool while_flag_889 { true };
                                      do {
                                        uint8_t id_890 { 0 };
                                        Pointer id_891 { p_ref_166[id_890] };
                                        ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 id_892 { id_891.readU8() };
                                        bool let_res_893;
                                        {
                                          ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 leb128_167 { id_892 };
                                          bool letpair_res_894;
                                          {
                                            auto leb128_fst_168 { std::get<0>(leb128_167) };
                                            auto leb128_snd_169 { std::get<1>(leb128_167) };
                                            uint8_t id_895 { 0 };
                                            Void id_896 { ((void)(p_ref_166[id_895] = leb128_snd_169), ::dessser::Void()) };
                                            (void)id_896;
                                            uint8_t id_897 { 0 };
                                            uint8_t id_898 { 127 };
                                            uint8_t id_899 { uint8_t(leb128_fst_168 & id_898) };
                                            uint32_t id_900 { uint32_t(id_899) };
                                            uint8_t id_901 { 0 };
                                            uint8_t id_902 { shft_ref_165[id_901] };
                                            uint32_t id_903 { uint32_t(id_900 << id_902) };
                                            uint8_t id_904 { 0 };
                                            uint32_t id_905 { leb_ref_164[id_904] };
                                            uint32_t id_906 { uint32_t(id_903 | id_905) };
                                            Void id_907 { ((void)(leb_ref_164[id_897] = id_906), ::dessser::Void()) };
                                            (void)id_907;
                                            uint8_t id_908 { 0 };
                                            uint8_t id_909 { 0 };
                                            uint8_t id_910 { shft_ref_165[id_909] };
                                            uint8_t id_911 { 7 };
                                            uint8_t id_912 { uint8_t(id_910 + id_911) };
                                            Void id_913 { ((void)(shft_ref_165[id_908] = id_912), ::dessser::Void()) };
                                            (void)id_913;
                                            uint8_t id_914 { 128 };
                                            bool id_915 { bool(leb128_fst_168 >= id_914) };
                                            letpair_res_894 = id_915;
                                          }
                                          let_res_893 = letpair_res_894;
                                        }
                                        while_flag_889 = let_res_893;
                                        if (while_flag_889) {
                                          (void)::dessser::Void();
                                        }
                                      } while (while_flag_889);
                                      (void)::dessser::Void();
                                      uint8_t id_916 { 0 };
                                      uint32_t id_917 { leb_ref_164[id_916] };
                                      uint8_t id_918 { 0 };
                                      Pointer id_919 { p_ref_166[id_918] };
                                      ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_920 { id_917, id_919 };
                                      let_res_888 = id_920;
                                    }
                                    let_res_886 = let_res_888;
                                  }
                                  let_res_883 = let_res_886;
                                }
                                ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f let_res_921;
                                {
                                  ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 dlist1_173 { let_res_883 };
                                  ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f letpair_res_922;
                                  {
                                    auto dlist1_fst_174 { std::get<0>(dlist1_173) };
                                    auto dlist1_snd_175 { std::get<1>(dlist1_173) };
                                    Lst<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> endoflist_923;
                                    ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f id_924 { endoflist_923, dlist1_snd_175 };
                                    Vec<1, ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f> id_925 {  id_924  };
                                    ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f let_res_926;
                                    {
                                      Vec<1, ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f> inits_src_ref_176 { id_925 };
                                      int32_t id_927 { 0L };
                                      Vec<1, int32_t> id_928 {  id_927  };
                                      {
                                        Vec<1, int32_t> repeat_n_177 { id_928 };
                                        bool while_flag_929 { true };
                                        do {
                                          int32_t id_930 { int32_t(dlist1_fst_174) };
                                          uint8_t id_931 { 0 };
                                          int32_t id_932 { repeat_n_177[id_931] };
                                          bool id_933 { bool(id_930 > id_932) };
                                          while_flag_929 = id_933;
                                          if (while_flag_929) {
                                            uint8_t id_934 { 0 };
                                            ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f id_935 { inits_src_ref_176[id_934] };
                                            {
                                              ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f dlist2_178 { id_935 };
                                              {
                                                auto dlist2_fst_179 { std::get<0>(dlist2_178) };
                                                auto dlist2_snd_180 { std::get<1>(dlist2_178) };
                                                uint8_t id_936 { 0 };
                                                ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_937 { dlist2_snd_180.readU16Le() };
                                                ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 letpair_res_938;
                                                {
                                                  auto du16_fst_182 { std::get<0>(id_937) };
                                                  auto du16_snd_183 { std::get<1>(id_937) };
                                                  ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_939 { du16_fst_182, du16_snd_183 };
                                                  letpair_res_938 = id_939;
                                                }
                                                ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f let_res_940;
                                                {
                                                  ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 dtup_184 { letpair_res_938 };
                                                  ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f letpair_res_941;
                                                  {
                                                    auto dtup_fst_185 { std::get<0>(dtup_184) };
                                                    auto dtup_snd_186 { std::get<1>(dtup_184) };
                                                    uint32_t id_942 { 0U };
                                                    Vec<1, uint32_t> id_943 {  id_942  };
                                                    ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_944;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_187 { id_943 };
                                                      uint8_t id_945 { 0 };
                                                      Vec<1, uint8_t> id_946 {  id_945  };
                                                      ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_947;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_188 { id_946 };
                                                        Vec<1, Pointer> id_948 {  dtup_snd_186  };
                                                        ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_949;
                                                        {
                                                          Vec<1, Pointer> p_ref_189 { id_948 };
                                                          bool while_flag_950 { true };
                                                          do {
                                                            uint8_t id_951 { 0 };
                                                            Pointer id_952 { p_ref_189[id_951] };
                                                            ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 id_953 { id_952.readU8() };
                                                            bool let_res_954;
                                                            {
                                                              ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 leb128_190 { id_953 };
                                                              bool letpair_res_955;
                                                              {
                                                                auto leb128_fst_191 { std::get<0>(leb128_190) };
                                                                auto leb128_snd_192 { std::get<1>(leb128_190) };
                                                                uint8_t id_956 { 0 };
                                                                Void id_957 { ((void)(p_ref_189[id_956] = leb128_snd_192), ::dessser::Void()) };
                                                                (void)id_957;
                                                                uint8_t id_958 { 0 };
                                                                uint8_t id_959 { 127 };
                                                                uint8_t id_960 { uint8_t(leb128_fst_191 & id_959) };
                                                                uint32_t id_961 { uint32_t(id_960) };
                                                                uint8_t id_962 { 0 };
                                                                uint8_t id_963 { shft_ref_188[id_962] };
                                                                uint32_t id_964 { uint32_t(id_961 << id_963) };
                                                                uint8_t id_965 { 0 };
                                                                uint32_t id_966 { leb_ref_187[id_965] };
                                                                uint32_t id_967 { uint32_t(id_964 | id_966) };
                                                                Void id_968 { ((void)(leb_ref_187[id_958] = id_967), ::dessser::Void()) };
                                                                (void)id_968;
                                                                uint8_t id_969 { 0 };
                                                                uint8_t id_970 { 0 };
                                                                uint8_t id_971 { shft_ref_188[id_970] };
                                                                uint8_t id_972 { 7 };
                                                                uint8_t id_973 { uint8_t(id_971 + id_972) };
                                                                Void id_974 { ((void)(shft_ref_188[id_969] = id_973), ::dessser::Void()) };
                                                                (void)id_974;
                                                                uint8_t id_975 { 128 };
                                                                bool id_976 { bool(leb128_fst_191 >= id_975) };
                                                                letpair_res_955 = id_976;
                                                              }
                                                              let_res_954 = letpair_res_955;
                                                            }
                                                            while_flag_950 = let_res_954;
                                                            if (while_flag_950) {
                                                              (void)::dessser::Void();
                                                            }
                                                          } while (while_flag_950);
                                                          (void)::dessser::Void();
                                                          uint8_t id_977 { 0 };
                                                          uint32_t id_978 { leb_ref_187[id_977] };
                                                          uint8_t id_979 { 0 };
                                                          Pointer id_980 { p_ref_189[id_979] };
                                                          ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_981 { id_978, id_980 };
                                                          let_res_949 = id_981;
                                                        }
                                                        let_res_947 = let_res_949;
                                                      }
                                                      let_res_944 = let_res_947;
                                                    }
                                                    ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa let_res_982;
                                                    {
                                                      ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 dlist1_196 { let_res_944 };
                                                      ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa letpair_res_983;
                                                      {
                                                        auto dlist1_fst_197 { std::get<0>(dlist1_196) };
                                                        auto dlist1_snd_198 { std::get<1>(dlist1_196) };
                                                        Lst<dessser::gen::raql_value::t_ext> endoflist_984;
                                                        ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa id_985 { endoflist_984, dlist1_snd_198 };
                                                        Vec<1, ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa> id_986 {  id_985  };
                                                        ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa let_res_987;
                                                        {
                                                          Vec<1, ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa> inits_src_ref_199 { id_986 };
                                                          int32_t id_988 { 0L };
                                                          Vec<1, int32_t> id_989 {  id_988  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_200 { id_989 };
                                                            bool while_flag_990 { true };
                                                            do {
                                                              int32_t id_991 { int32_t(dlist1_fst_197) };
                                                              uint8_t id_992 { 0 };
                                                              int32_t id_993 { repeat_n_200[id_992] };
                                                              bool id_994 { bool(id_991 > id_993) };
                                                              while_flag_990 = id_994;
                                                              if (while_flag_990) {
                                                                uint8_t id_995 { 0 };
                                                                ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa id_996 { inits_src_ref_199[id_995] };
                                                                {
                                                                  ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa dlist2_201 { id_996 };
                                                                  {
                                                                    auto dlist2_fst_202 { std::get<0>(dlist2_201) };
                                                                    auto dlist2_snd_203 { std::get<1>(dlist2_201) };
                                                                    uint8_t id_997 { 0 };
                                                                    auto fun998 { dessser::gen::raql_value::of_row_binary };
                                                                    ::dessser::gen::output_specs::tf3063cfb73e0f06d3ea99ebd15a86d50 id_999 { fun998(dlist2_snd_203) };
                                                                    ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa letpair_res_1000;
                                                                    {
                                                                      auto dlist3_fst_205 { std::get<0>(id_999) };
                                                                      auto dlist3_snd_206 { std::get<1>(id_999) };
                                                                      Lst<dessser::gen::raql_value::t_ext> id_1001 { dlist3_fst_205, dlist2_fst_202 };
                                                                      ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa id_1002 { id_1001, dlist3_snd_206 };
                                                                      letpair_res_1000 = id_1002;
                                                                    }
                                                                    Void id_1003 { ((void)(inits_src_ref_199[id_997] = letpair_res_1000), ::dessser::Void()) };
                                                                    (void)id_1003;
                                                                  }
                                                                  (void)::dessser::Void();
                                                                }
                                                                (void)::dessser::Void();
                                                                uint8_t id_1004 { 0 };
                                                                uint8_t id_1005 { 0 };
                                                                int32_t id_1006 { repeat_n_200[id_1005] };
                                                                int32_t id_1007 { 1L };
                                                                int32_t id_1008 { int32_t(id_1006 + id_1007) };
                                                                Void id_1009 { ((void)(repeat_n_200[id_1004] = id_1008), ::dessser::Void()) };
                                                                (void)id_1009;
                                                                (void)id_1009;
                                                              }
                                                            } while (while_flag_990);
                                                            (void)::dessser::Void();
                                                          }
                                                          (void)::dessser::Void();
                                                          uint8_t id_1010 { 0 };
                                                          ::dessser::gen::output_specs::t653b877a5045bee09e834195cfdbb7fa id_1011 { inits_src_ref_199[id_1010] };
                                                          let_res_987 = id_1011;
                                                        }
                                                        letpair_res_983 = let_res_987;
                                                      }
                                                      let_res_982 = letpair_res_983;
                                                    }
                                                    ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f letpair_res_1012;
                                                    {
                                                      auto dlist4_fst_208 { std::get<0>(let_res_982) };
                                                      auto dlist4_snd_209 { std::get<1>(let_res_982) };
                                                      Arr<dessser::gen::raql_value::t_ext> id_1013 { dlist4_fst_208.toArrRev() };
                                                      ::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46 id_1014 { dtup_fst_185, id_1013 };
                                                      Lst<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_1015 { id_1014, dlist2_fst_179 };
                                                      ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f id_1016 { id_1015, dlist4_snd_209 };
                                                      letpair_res_1012 = id_1016;
                                                    }
                                                    letpair_res_941 = letpair_res_1012;
                                                  }
                                                  let_res_940 = letpair_res_941;
                                                }
                                                Void id_1017 { ((void)(inits_src_ref_176[id_936] = let_res_940), ::dessser::Void()) };
                                                (void)id_1017;
                                              }
                                              (void)::dessser::Void();
                                            }
                                            (void)::dessser::Void();
                                            uint8_t id_1018 { 0 };
                                            uint8_t id_1019 { 0 };
                                            int32_t id_1020 { repeat_n_177[id_1019] };
                                            int32_t id_1021 { 1L };
                                            int32_t id_1022 { int32_t(id_1020 + id_1021) };
                                            Void id_1023 { ((void)(repeat_n_177[id_1018] = id_1022), ::dessser::Void()) };
                                            (void)id_1023;
                                            (void)id_1023;
                                          }
                                        } while (while_flag_929);
                                        (void)::dessser::Void();
                                      }
                                      (void)::dessser::Void();
                                      uint8_t id_1024 { 0 };
                                      ::dessser::gen::output_specs::t1c1418766eaa98ca7084a7a2c819843f id_1025 { inits_src_ref_176[id_1024] };
                                      let_res_926 = id_1025;
                                    }
                                    letpair_res_922 = let_res_926;
                                  }
                                  let_res_921 = letpair_res_922;
                                }
                                ::dessser::gen::output_specs::t581e8f70011b20941cc1c100327a61cc letpair_res_1026;
                                {
                                  auto dlist4_fst_217 { std::get<0>(let_res_921) };
                                  auto dlist4_snd_218 { std::get<1>(let_res_921) };
                                  Arr<::dessser::gen::output_specs::t6f037f9cb4c8fd79d46fb7db1c2b9a46> id_1027 { dlist4_fst_217.toArrRev() };
                                  ::dessser::gen::output_specs::t581e8f70011b20941cc1c100327a61cc id_1028 { id_1027, dlist4_snd_218 };
                                  letpair_res_1026 = id_1028;
                                }
                                ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 let_res_1029;
                                {
                                  ::dessser::gen::output_specs::t581e8f70011b20941cc1c100327a61cc drec_219 { letpair_res_1026 };
                                  ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 letpair_res_1030;
                                  {
                                    auto drec_fst_220 { std::get<0>(drec_219) };
                                    auto drec_snd_221 { std::get<1>(drec_219) };
                                    uint32_t id_1031 { 0U };
                                    Vec<1, uint32_t> id_1032 {  id_1031  };
                                    ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_1033;
                                    {
                                      Vec<1, uint32_t> leb_ref_222 { id_1032 };
                                      uint8_t id_1034 { 0 };
                                      Vec<1, uint8_t> id_1035 {  id_1034  };
                                      ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_1036;
                                      {
                                        Vec<1, uint8_t> shft_ref_223 { id_1035 };
                                        Vec<1, Pointer> id_1037 {  drec_snd_221  };
                                        ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 let_res_1038;
                                        {
                                          Vec<1, Pointer> p_ref_224 { id_1037 };
                                          bool while_flag_1039 { true };
                                          do {
                                            uint8_t id_1040 { 0 };
                                            Pointer id_1041 { p_ref_224[id_1040] };
                                            ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 id_1042 { id_1041.readU8() };
                                            bool let_res_1043;
                                            {
                                              ::dessser::gen::output_specs::t1a5d74abf838df33f185a72a8912f5c9 leb128_225 { id_1042 };
                                              bool letpair_res_1044;
                                              {
                                                auto leb128_fst_226 { std::get<0>(leb128_225) };
                                                auto leb128_snd_227 { std::get<1>(leb128_225) };
                                                uint8_t id_1045 { 0 };
                                                Void id_1046 { ((void)(p_ref_224[id_1045] = leb128_snd_227), ::dessser::Void()) };
                                                (void)id_1046;
                                                uint8_t id_1047 { 0 };
                                                uint8_t id_1048 { 127 };
                                                uint8_t id_1049 { uint8_t(leb128_fst_226 & id_1048) };
                                                uint32_t id_1050 { uint32_t(id_1049) };
                                                uint8_t id_1051 { 0 };
                                                uint8_t id_1052 { shft_ref_223[id_1051] };
                                                uint32_t id_1053 { uint32_t(id_1050 << id_1052) };
                                                uint8_t id_1054 { 0 };
                                                uint32_t id_1055 { leb_ref_222[id_1054] };
                                                uint32_t id_1056 { uint32_t(id_1053 | id_1055) };
                                                Void id_1057 { ((void)(leb_ref_222[id_1047] = id_1056), ::dessser::Void()) };
                                                (void)id_1057;
                                                uint8_t id_1058 { 0 };
                                                uint8_t id_1059 { 0 };
                                                uint8_t id_1060 { shft_ref_223[id_1059] };
                                                uint8_t id_1061 { 7 };
                                                uint8_t id_1062 { uint8_t(id_1060 + id_1061) };
                                                Void id_1063 { ((void)(shft_ref_223[id_1058] = id_1062), ::dessser::Void()) };
                                                (void)id_1063;
                                                uint8_t id_1064 { 128 };
                                                bool id_1065 { bool(leb128_fst_226 >= id_1064) };
                                                letpair_res_1044 = id_1065;
                                              }
                                              let_res_1043 = letpair_res_1044;
                                            }
                                            while_flag_1039 = let_res_1043;
                                            if (while_flag_1039) {
                                              (void)::dessser::Void();
                                            }
                                          } while (while_flag_1039);
                                          (void)::dessser::Void();
                                          uint8_t id_1066 { 0 };
                                          uint32_t id_1067 { leb_ref_222[id_1066] };
                                          uint8_t id_1068 { 0 };
                                          Pointer id_1069 { p_ref_224[id_1068] };
                                          ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 id_1070 { id_1067, id_1069 };
                                          let_res_1038 = id_1070;
                                        }
                                        let_res_1036 = let_res_1038;
                                      }
                                      let_res_1033 = let_res_1036;
                                    }
                                    ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea let_res_1071;
                                    {
                                      ::dessser::gen::output_specs::t491c44439106a32f896827242e8e76a1 dlist1_231 { let_res_1033 };
                                      ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea letpair_res_1072;
                                      {
                                        auto dlist1_fst_232 { std::get<0>(dlist1_231) };
                                        auto dlist1_snd_233 { std::get<1>(dlist1_231) };
                                        Lst<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> endoflist_1073;
                                        ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea id_1074 { endoflist_1073, dlist1_snd_233 };
                                        Vec<1, ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea> id_1075 {  id_1074  };
                                        ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea let_res_1076;
                                        {
                                          Vec<1, ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea> inits_src_ref_234 { id_1075 };
                                          int32_t id_1077 { 0L };
                                          Vec<1, int32_t> id_1078 {  id_1077  };
                                          {
                                            Vec<1, int32_t> repeat_n_235 { id_1078 };
                                            bool while_flag_1079 { true };
                                            do {
                                              int32_t id_1080 { int32_t(dlist1_fst_232) };
                                              uint8_t id_1081 { 0 };
                                              int32_t id_1082 { repeat_n_235[id_1081] };
                                              bool id_1083 { bool(id_1080 > id_1082) };
                                              while_flag_1079 = id_1083;
                                              if (while_flag_1079) {
                                                uint8_t id_1084 { 0 };
                                                ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea id_1085 { inits_src_ref_234[id_1084] };
                                                {
                                                  ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea dlist2_236 { id_1085 };
                                                  {
                                                    auto dlist2_fst_237 { std::get<0>(dlist2_236) };
                                                    auto dlist2_snd_238 { std::get<1>(dlist2_236) };
                                                    uint8_t id_1086 { 0 };
                                                    ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_1087 { dlist2_snd_238.readU16Le() };
                                                    ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1088;
                                                    {
                                                      auto du16_fst_240 { std::get<0>(id_1087) };
                                                      auto du16_snd_241 { std::get<1>(id_1087) };
                                                      ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 id_1089 { du16_fst_240, du16_snd_241 };
                                                      letpair_res_1088 = id_1089;
                                                    }
                                                    ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea let_res_1090;
                                                    {
                                                      ::dessser::gen::output_specs::ta97bb48ed75bbda6173555873826c8c6 dtup_242 { letpair_res_1088 };
                                                      ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea letpair_res_1091;
                                                      {
                                                        auto dtup_fst_243 { std::get<0>(dtup_242) };
                                                        auto dtup_snd_244 { std::get<1>(dtup_242) };
                                                        ::dessser::gen::output_specs::t7ce21e44309db7c6914cc41eb440af04 id_1092 { channel_specs_of_row_binary(dtup_snd_244) };
                                                        ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea letpair_res_1093;
                                                        {
                                                          auto dtup_fst_246 { std::get<0>(id_1092) };
                                                          auto dtup_snd_247 { std::get<1>(id_1092) };
                                                          ::dessser::gen::output_specs::te2535d14520252a621d726d279906e71 id_1094 { dtup_fst_243, dtup_fst_246 };
                                                          Lst<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> id_1095 { id_1094, dlist2_fst_237 };
                                                          ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea id_1096 { id_1095, dtup_snd_247 };
                                                          letpair_res_1093 = id_1096;
                                                        }
                                                        letpair_res_1091 = letpair_res_1093;
                                                      }
                                                      let_res_1090 = letpair_res_1091;
                                                    }
                                                    Void id_1097 { ((void)(inits_src_ref_234[id_1086] = let_res_1090), ::dessser::Void()) };
                                                    (void)id_1097;
                                                  }
                                                  (void)::dessser::Void();
                                                }
                                                (void)::dessser::Void();
                                                uint8_t id_1098 { 0 };
                                                uint8_t id_1099 { 0 };
                                                int32_t id_1100 { repeat_n_235[id_1099] };
                                                int32_t id_1101 { 1L };
                                                int32_t id_1102 { int32_t(id_1100 + id_1101) };
                                                Void id_1103 { ((void)(repeat_n_235[id_1098] = id_1102), ::dessser::Void()) };
                                                (void)id_1103;
                                                (void)id_1103;
                                              }
                                            } while (while_flag_1079);
                                            (void)::dessser::Void();
                                          }
                                          (void)::dessser::Void();
                                          uint8_t id_1104 { 0 };
                                          ::dessser::gen::output_specs::t76b716b4c8ac654d9c7ecf84064f11ea id_1105 { inits_src_ref_234[id_1104] };
                                          let_res_1076 = id_1105;
                                        }
                                        letpair_res_1072 = let_res_1076;
                                      }
                                      let_res_1071 = letpair_res_1072;
                                    }
                                    ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 letpair_res_1106;
                                    {
                                      auto dlist4_fst_252 { std::get<0>(let_res_1071) };
                                      auto dlist4_snd_253 { std::get<1>(let_res_1071) };
                                      Arr<::dessser::gen::output_specs::te2535d14520252a621d726d279906e71> id_1107 { dlist4_fst_252.toArrRev() };
                                      ::dessser::gen::output_specs::t6d8876cd95eb52df46270873f955e58e id_1108 { drec_fst_159, drec_fst_162, drec_fst_220, id_1107 };
                                      ::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523 id_1109 { dtup_fst_156, id_1108 };
                                      Lst<::dessser::gen::output_specs::t132ce9f388dc6ee5c0fd05918c829523> id_1110 { id_1109, dlist2_fst_153 };
                                      ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 id_1111 { id_1110, dlist4_snd_253 };
                                      letpair_res_1106 = id_1111;
                                    }
                                    letpair_res_1030 = letpair_res_1106;
                                  }
                                  let_res_1029 = letpair_res_1030;
                                }
                                letpair_res_880 = let_res_1029;
                              }
                              let_res_879 = letpair_res_880;
                            }
                            letpair_res_876 = let_res_879;
                          }
                          let_res_875 = letpair_res_876;
                        }
                        letpair_res_873 = let_res_875;
                      }
                      let_res_872 = letpair_res_873;
                    }
                    Void id_1112 { ((void)(inits_src_ref_150[id_870] = let_res_872), ::dessser::Void()) };
                    (void)id_1112;
                  }
                  (void)::dessser::Void();
                }
                (void)::dessser::Void();
                uint8_t id_1113 { 0 };
                uint8_t id_1114 { 0 };
                int32_t id_1115 { repeat_n_151[id_1114] };
                int32_t id_1116 { 1L };
                int32_t id_1117 { int32_t(id_1115 + id_1116) };
                Void id_1118 { ((void)(repeat_n_151[id_1113] = id_1117), ::dessser::Void()) };
                (void)id_1118;
                (void)id_1118;
              }
            } while (while_flag_863);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_1119 { 0 };
          ::dessser::gen::output_specs::t0b75cfeb37c549ebf8500c4ccb591b57 id_1120 { inits_src_ref_150[id_1119] };
          let_res_860 = id_1120;
        }
        letpair_res_856 = let_res_860;
      }
      let_res_855 = letpair_res_856;
    }
    ::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016 letpair_res_1121;
    {
      auto dlist4_fst_264 { std::get<0>(let_res_855) };
      auto dlist4_snd_265 { std::get<1>(let_res_855) };
      t id_1122 { dlist4_fst_264.toArrRev() };
      ::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016 id_1123 { id_1122, dlist4_snd_265 };
      letpair_res_1121 = id_1123;
    }
    return letpair_res_1121;
  }
   };
  return fun814;
}
std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_267" "make_snd_268" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_267") (identifier "make_snd_268"))))
 */
static std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> fun1124 { [&](Pointer p_0) {
    ::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016 id_1125 { of_row_binary(p_0) };
    ::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016 letpair_res_1126;
    {
      auto make_fst_267 { std::get<0>(id_1125) };
      auto make_snd_268 { std::get<1>(id_1125) };
      ::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016 id_1127 { make_fst_267, make_snd_268 };
      letpair_res_1126 = id_1127;
    }
    return letpair_res_1126;
  }
   };
  return fun1124;
}
std::function<::dessser::gen::output_specs::ta30293a82943182cab78182f33b18016(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})[]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(t &,Pointer &)> fun1128 { [&](t& p_0, Pointer p_1) {
    Pointer id_1129 { to_row_binary(p_0, p_1) };
    return id_1129;
  }
   };
  return fun1128;
}
std::function<Pointer(t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
