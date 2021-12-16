#include <algorithm>
#include <arpa/inet.h>
#include <charconv>
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
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/fq_name.h"

namespace dessser::gen::alert {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct constant {
  dessser::gen::field_name::t_ext name;
  std::string value;
  constant(dessser::gen::field_name::t_ext name_, std::string value_) : name(name_), value(value_) {}
  constant() = default;
};
inline bool operator==(constant const &a, constant const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && a.value == b.value;
}

inline bool operator!=(constant const &a, constant const &b) {
  return !operator==(a, b);
}
struct t1287f5ccd09b12d10e0e8359b374ce64 : public std::variant<
  double, // Absolute
  double // Relative
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t1287f5ccd09b12d10e0e8359b374ce64 const &a, t1287f5ccd09b12d10e0e8359b374ce64 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Absolute
    case 1: return std::get<1>(a) == std::get<1>(b); // Relative
  };
  return false;
}
inline bool operator!=(t1287f5ccd09b12d10e0e8359b374ce64 const &a, t1287f5ccd09b12d10e0e8359b374ce64 const &b) {
  return !operator==(a, b);
}
struct t4d94676e99bfec48ddb223ef58e339ac {
  double avg_window;
  uint32_t sample_size;
  double percentile;
  uint32_t seasonality;
  double smooth_factor;
  ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 max_distance;
  t4d94676e99bfec48ddb223ef58e339ac(double avg_window_, uint32_t sample_size_, double percentile_, uint32_t seasonality_, double smooth_factor_, ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 max_distance_) : avg_window(avg_window_), sample_size(sample_size_), percentile(percentile_), seasonality(seasonality_), smooth_factor(smooth_factor_), max_distance(max_distance_) {}
  t4d94676e99bfec48ddb223ef58e339ac() = default;
};
inline bool operator==(t4d94676e99bfec48ddb223ef58e339ac const &a, t4d94676e99bfec48ddb223ef58e339ac const &b) {
  return a.avg_window == b.avg_window && a.sample_size == b.sample_size && a.percentile == b.percentile && a.seasonality == b.seasonality && a.smooth_factor == b.smooth_factor && a.max_distance == b.max_distance;
}

inline bool operator!=(t4d94676e99bfec48ddb223ef58e339ac const &a, t4d94676e99bfec48ddb223ef58e339ac const &b) {
  return !operator==(a, b);
}
struct threshold : public std::variant<
  double, // Constant
  ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac // Baseline
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(threshold const &a, threshold const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Constant
    case 1: return std::get<1>(a) == std::get<1>(b); // Baseline
  };
  return false;
}
inline bool operator!=(threshold const &a, threshold const &b) {
  return !operator==(a, b);
}
struct t {
  dessser::gen::fq_name::t_ext table;
  dessser::gen::field_name::t_ext column;
  bool enabled;
  Lst<dessser::gen::simple_filter::t_ext> where;
  std::optional<Lst<dessser::gen::field_name::t_ext>> group_by;
  Lst<dessser::gen::simple_filter::t_ext> having;
  std::shared_ptr<::dessser::gen::alert::threshold>  threshold;
  double hysteresis;
  double duration;
  double ratio;
  double time_step;
  Lst<dessser::gen::field_name::t_ext> tops;
  Lst<dessser::gen::field_name::t_ext> carry_fields;
  Lst<std::shared_ptr<::dessser::gen::alert::constant> > carry_csts;
  std::string id;
  std::string desc_title;
  std::string desc_firing;
  std::string desc_recovery;
  t(dessser::gen::fq_name::t_ext table_, dessser::gen::field_name::t_ext column_, bool enabled_, Lst<dessser::gen::simple_filter::t_ext> where_, std::optional<Lst<dessser::gen::field_name::t_ext>> group_by_, Lst<dessser::gen::simple_filter::t_ext> having_, std::shared_ptr<::dessser::gen::alert::threshold>  threshold_, double hysteresis_, double duration_, double ratio_, double time_step_, Lst<dessser::gen::field_name::t_ext> tops_, Lst<dessser::gen::field_name::t_ext> carry_fields_, Lst<std::shared_ptr<::dessser::gen::alert::constant> > carry_csts_, std::string id_, std::string desc_title_, std::string desc_firing_, std::string desc_recovery_) : table(table_), column(column_), enabled(enabled_), where(where_), group_by(group_by_), having(having_), threshold(threshold_), hysteresis(hysteresis_), duration(duration_), ratio(ratio_), time_step(time_step_), tops(tops_), carry_fields(carry_fields_), carry_csts(carry_csts_), id(id_), desc_title(desc_title_), desc_firing(desc_firing_), desc_recovery(desc_recovery_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::fq_name::Deref(a.table) == ::dessser::gen::fq_name::Deref(b.table) && ::dessser::gen::field_name::Deref(a.column) == ::dessser::gen::field_name::Deref(b.column) && a.enabled == b.enabled && a.where == b.where && ((a.group_by && b.group_by && a.group_by.value() == b.group_by.value()) || (!a.group_by && !b.group_by)) && a.having == b.having && (*a.threshold) == (*b.threshold) && a.hysteresis == b.hysteresis && a.duration == b.duration && a.ratio == b.ratio && a.time_step == b.time_step && a.tops == b.tops && a.carry_fields == b.carry_fields && a.carry_csts == b.carry_csts && a.id == b.id && a.desc_title == b.desc_title && a.desc_firing == b.desc_firing && a.desc_recovery == b.desc_recovery;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t0bfcffcbe1f8fa26793acf604a6fe904 : public std::tuple<
  std::shared_ptr<::dessser::gen::alert::constant> ,
  Pointer
> {
  using tuple::tuple;
  t0bfcffcbe1f8fa26793acf604a6fe904(std::tuple<std::shared_ptr<::dessser::gen::alert::constant> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alert::constant> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0bfcffcbe1f8fa26793acf604a6fe904 const &a, t0bfcffcbe1f8fa26793acf604a6fe904 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0bfcffcbe1f8fa26793acf604a6fe904 const &a, t0bfcffcbe1f8fa26793acf604a6fe904 const &b) {
  return !operator==(a, b);
}
struct t18cecf882d7ac80cef37dfe6b22279d4 : public std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t18cecf882d7ac80cef37dfe6b22279d4(std::tuple<dessser::gen::field_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::field_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
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
struct t55387dac503088b8cd86859bdfba5c91 : public std::tuple<
  std::shared_ptr<::dessser::gen::alert::threshold> ,
  Pointer
> {
  using tuple::tuple;
  t55387dac503088b8cd86859bdfba5c91(std::tuple<std::shared_ptr<::dessser::gen::alert::threshold> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alert::threshold> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t55387dac503088b8cd86859bdfba5c91 const &a, t55387dac503088b8cd86859bdfba5c91 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t55387dac503088b8cd86859bdfba5c91 const &a, t55387dac503088b8cd86859bdfba5c91 const &b) {
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
struct tc35264428ed4b717e8fbc891998f97e3 : public std::tuple<
  ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64,
  Pointer
> {
  using tuple::tuple;
  tc35264428ed4b717e8fbc891998f97e3(std::tuple<::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64, Pointer> p)
    : std::tuple<::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc35264428ed4b717e8fbc891998f97e3 const &a, tc35264428ed4b717e8fbc891998f97e3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc35264428ed4b717e8fbc891998f97e3 const &a, tc35264428ed4b717e8fbc891998f97e3 const &b) {
  return !operator==(a, b);
}
struct tc6d52773763d322654577a54bd0001f6 : public std::tuple<
  std::shared_ptr<::dessser::gen::alert::t> ,
  Pointer
> {
  using tuple::tuple;
  tc6d52773763d322654577a54bd0001f6(std::tuple<std::shared_ptr<::dessser::gen::alert::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alert::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc6d52773763d322654577a54bd0001f6 const &a, tc6d52773763d322654577a54bd0001f6 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc6d52773763d322654577a54bd0001f6 const &a, tc6d52773763d322654577a54bd0001f6 const &b) {
  return !operator==(a, b);
}
struct t1067cf8ed87e4e016349f71797fb0661 : public std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t1067cf8ed87e4e016349f71797fb0661(std::tuple<dessser::gen::fq_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1067cf8ed87e4e016349f71797fb0661 const &a, t1067cf8ed87e4e016349f71797fb0661 const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1067cf8ed87e4e016349f71797fb0661 const &a, t1067cf8ed87e4e016349f71797fb0661 const &b) {
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
struct tc42fa697e1caa84eb8919e899ae45a1d : public std::tuple<
  Lst<dessser::gen::simple_filter::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tc42fa697e1caa84eb8919e899ae45a1d(std::tuple<Lst<dessser::gen::simple_filter::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::simple_filter::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc42fa697e1caa84eb8919e899ae45a1d const &a, tc42fa697e1caa84eb8919e899ae45a1d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc42fa697e1caa84eb8919e899ae45a1d const &a, tc42fa697e1caa84eb8919e899ae45a1d const &b) {
  return !operator==(a, b);
}
struct t718468920e01b4b984449c743ae99792 : public std::tuple<
  dessser::gen::simple_filter::t_ext,
  Pointer
> {
  using tuple::tuple;
  t718468920e01b4b984449c743ae99792(std::tuple<dessser::gen::simple_filter::t_ext, Pointer> p)
    : std::tuple<dessser::gen::simple_filter::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t718468920e01b4b984449c743ae99792 const &a, t718468920e01b4b984449c743ae99792 const &b) {
  return ::dessser::gen::simple_filter::Deref(std::get<0>(a)) == ::dessser::gen::simple_filter::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t718468920e01b4b984449c743ae99792 const &a, t718468920e01b4b984449c743ae99792 const &b) {
  return !operator==(a, b);
}
struct t2fa56af3afd4098bea1b66e93db81284 : public std::tuple<
  std::optional<Lst<dessser::gen::field_name::t_ext>>,
  Pointer
> {
  using tuple::tuple;
  t2fa56af3afd4098bea1b66e93db81284(std::tuple<std::optional<Lst<dessser::gen::field_name::t_ext>>, Pointer> p)
    : std::tuple<std::optional<Lst<dessser::gen::field_name::t_ext>>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2fa56af3afd4098bea1b66e93db81284 const &a, t2fa56af3afd4098bea1b66e93db81284 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2fa56af3afd4098bea1b66e93db81284 const &a, t2fa56af3afd4098bea1b66e93db81284 const &b) {
  return !operator==(a, b);
}
struct tae4ac4fd187cdebd0a4f6d30f229fbc5 : public std::tuple<
  Lst<dessser::gen::field_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tae4ac4fd187cdebd0a4f6d30f229fbc5(std::tuple<Lst<dessser::gen::field_name::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::field_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tae4ac4fd187cdebd0a4f6d30f229fbc5 const &a, tae4ac4fd187cdebd0a4f6d30f229fbc5 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tae4ac4fd187cdebd0a4f6d30f229fbc5 const &a, tae4ac4fd187cdebd0a4f6d30f229fbc5 const &b) {
  return !operator==(a, b);
}
struct ted4b695d380cc59a0573f58c72d5df5e : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::alert::constant> >,
  Pointer
> {
  using tuple::tuple;
  ted4b695d380cc59a0573f58c72d5df5e(std::tuple<Lst<std::shared_ptr<::dessser::gen::alert::constant> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::alert::constant> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ted4b695d380cc59a0573f58c72d5df5e const &a, ted4b695d380cc59a0573f58c72d5df5e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ted4b695d380cc59a0573f58c72d5df5e const &a, ted4b695d380cc59a0573f58c72d5df5e const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{name: $field_name; value: STRING}" "Ptr")
      (let "srec_dst_483" (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (param 1))
        (write-bytes
          (let "leb128_sz_484" (make-vec (string-length (get-field "value" (param 0))))
            (let "leb128_ptr_485" (make-vec (identifier "srec_dst_483"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_485")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_485"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_484"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_484"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_484"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_484") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_484")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_484")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_485"))))) 
          (bytes-of-string (get-field "value" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::constant> ,Pointer)> constant_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::constant> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::alert::constant>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { (*p_0).name };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_483 { id_3 };
      std::string id_5 { (*p_0).value };
      uint32_t id_6 { (uint32_t)id_5.size() };
      Vec<1, uint32_t> id_7 {  id_6  };
      Pointer let_res_8;
      {
        Vec<1, uint32_t> leb128_sz_484 { id_7 };
        Vec<1, Pointer> id_9 {  srec_dst_483  };
        Pointer let_res_10;
        {
          Vec<1, Pointer> leb128_ptr_485 { id_9 };
          bool while_flag_11 { true };
          do {
            uint8_t id_12 { 0 };
            uint8_t id_13 { 0 };
            Pointer id_14 { leb128_ptr_485[id_13] };
            uint32_t id_15 { 128U };
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_484[id_16] };
            bool id_18 { bool(id_15 > id_17) };
            uint8_t choose_res_19;
            if (id_18) {
              uint8_t id_20 { 0 };
              uint32_t id_21 { leb128_sz_484[id_20] };
              uint8_t id_22 { uint8_t(id_21) };
              choose_res_19 = id_22;
            } else {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_484[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              uint8_t id_26 { 128 };
              uint8_t id_27 { uint8_t(id_25 | id_26) };
              choose_res_19 = id_27;
            }
            Pointer id_28 { id_14.writeU8(choose_res_19) };
            Void id_29 { ((void)(leb128_ptr_485[id_12] = id_28), ::dessser::VOID) };
            (void)id_29;
            uint8_t id_30 { 0 };
            uint8_t id_31 { 0 };
            uint32_t id_32 { leb128_sz_484[id_31] };
            uint8_t id_33 { 7 };
            uint32_t id_34 { uint32_t(id_32 >> id_33) };
            Void id_35 { ((void)(leb128_sz_484[id_30] = id_34), ::dessser::VOID) };
            (void)id_35;
            uint8_t id_36 { 0 };
            uint32_t id_37 { leb128_sz_484[id_36] };
            uint32_t id_38 { 0U };
            bool id_39 { bool(id_37 > id_38) };
            while_flag_11 = id_39;
            if (while_flag_11) {
              (void)::dessser::VOID;
            }
          } while (while_flag_11);
          (void)::dessser::VOID;
          uint8_t id_40 { 0 };
          Pointer id_41 { leb128_ptr_485[id_40] };
          let_res_10 = id_41;
        }
        let_res_8 = let_res_10;
      }
      std::string id_42 { (*p_0).value };
      Bytes id_43 { id_42 };
      Pointer id_44 { let_res_8.writeBytes(id_43) };
      let_res_4 = id_44;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alert::constant> ,Pointer)> constant_to_row_binary(constant_to_row_binary_init());

/* 
    (fun ("[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]" "Ptr")
      (let "ssum_dst_475" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (write-u64 little-endian (identifier "ssum_dst_475") (u64-of-float (get-alt "Constant" (param 0))))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_480"
              (let "srec_dst_479"
                (let "srec_dst_478"
                  (let "srec_dst_477"
                    (let "srec_dst_476" (write-u64 little-endian (identifier "ssum_dst_475") (u64-of-float (get-field "avg_window" (get-alt "Baseline" (param 0)))))
                      (write-u32 little-endian (identifier "srec_dst_476") (get-field "sample_size" (get-alt "Baseline" (param 0)))))
                    (write-u64 little-endian (identifier "srec_dst_477") (u64-of-float (get-field "percentile" (get-alt "Baseline" (param 0))))))
                  (write-u32 little-endian (identifier "srec_dst_478") (get-field "seasonality" (get-alt "Baseline" (param 0)))))
                (write-u64 little-endian (identifier "srec_dst_479") (u64-of-float (get-field "smooth_factor" (get-alt "Baseline" (param 0))))))
              (let "ssum_dst_482" (write-u16 little-endian (identifier "srec_dst_480") (label-of (get-field "max_distance" (get-alt "Baseline" (param 0)))))
                (if (eq (u16 0) (label-of (get-field "max_distance" (get-alt "Baseline" (param 0)))))
                  (write-u64 little-endian (identifier "ssum_dst_482") (u64-of-float (get-alt "Absolute" (get-field "max_distance" (get-alt "Baseline" (param 0))))))
                  (seq (assert (eq (label-of (get-field "max_distance" (get-alt "Baseline" (param 0)))) (u16 1)))
                    (write-u64 little-endian (identifier "ssum_dst_482") (u64-of-float (get-alt "Relative" (get-field "max_distance" (get-alt "Baseline" (param 0))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::threshold> ,Pointer)> threshold_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::threshold> ,Pointer)> fun45 { [&fun45](std::shared_ptr<::dessser::gen::alert::threshold>  p_0, Pointer p_1) {
    uint16_t id_46 { uint16_t((*p_0).index()) };
    Pointer id_47 { p_1.writeU16Le(id_46) };
    Pointer let_res_48;
    {
      Pointer ssum_dst_475 { id_47 };
      uint16_t id_49 { 0 };
      uint16_t id_50 { uint16_t((*p_0).index()) };
      bool id_51 { bool(id_49 == id_50) };
      Pointer choose_res_52;
      if (id_51) {
        double id_53 { std::get<0 /* Constant */>((*p_0)) };
        uint64_t id_54 { qword_of_float(id_53) };
        Pointer id_55 { ssum_dst_475.writeU64Le(id_54) };
        choose_res_52 = id_55;
      } else {
        uint16_t id_56 { uint16_t((*p_0).index()) };
        uint16_t id_57 { 1 };
        bool id_58 { bool(id_56 == id_57) };
        Void id_59 { ((void)(assert(id_58)), ::dessser::VOID) };
        (void)id_59;
        ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_60 { std::get<1 /* Baseline */>((*p_0)) };
        double id_61 { id_60.avg_window };
        uint64_t id_62 { qword_of_float(id_61) };
        Pointer id_63 { ssum_dst_475.writeU64Le(id_62) };
        Pointer let_res_64;
        {
          Pointer srec_dst_476 { id_63 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_65 { std::get<1 /* Baseline */>((*p_0)) };
          uint32_t id_66 { id_65.sample_size };
          Pointer id_67 { srec_dst_476.writeU32Le(id_66) };
          let_res_64 = id_67;
        }
        Pointer let_res_68;
        {
          Pointer srec_dst_477 { let_res_64 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_69 { std::get<1 /* Baseline */>((*p_0)) };
          double id_70 { id_69.percentile };
          uint64_t id_71 { qword_of_float(id_70) };
          Pointer id_72 { srec_dst_477.writeU64Le(id_71) };
          let_res_68 = id_72;
        }
        Pointer let_res_73;
        {
          Pointer srec_dst_478 { let_res_68 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_74 { std::get<1 /* Baseline */>((*p_0)) };
          uint32_t id_75 { id_74.seasonality };
          Pointer id_76 { srec_dst_478.writeU32Le(id_75) };
          let_res_73 = id_76;
        }
        Pointer let_res_77;
        {
          Pointer srec_dst_479 { let_res_73 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_78 { std::get<1 /* Baseline */>((*p_0)) };
          double id_79 { id_78.smooth_factor };
          uint64_t id_80 { qword_of_float(id_79) };
          Pointer id_81 { srec_dst_479.writeU64Le(id_80) };
          let_res_77 = id_81;
        }
        Pointer let_res_82;
        {
          Pointer srec_dst_480 { let_res_77 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_83 { std::get<1 /* Baseline */>((*p_0)) };
          ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_84 { id_83.max_distance };
          uint16_t id_85 { uint16_t(id_84.index()) };
          Pointer id_86 { srec_dst_480.writeU16Le(id_85) };
          Pointer let_res_87;
          {
            Pointer ssum_dst_482 { id_86 };
            uint16_t id_88 { 0 };
            ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_89 { std::get<1 /* Baseline */>((*p_0)) };
            ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_90 { id_89.max_distance };
            uint16_t id_91 { uint16_t(id_90.index()) };
            bool id_92 { bool(id_88 == id_91) };
            Pointer choose_res_93;
            if (id_92) {
              ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_94 { std::get<1 /* Baseline */>((*p_0)) };
              ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_95 { id_94.max_distance };
              double id_96 { std::get<0 /* Absolute */>(id_95) };
              uint64_t id_97 { qword_of_float(id_96) };
              Pointer id_98 { ssum_dst_482.writeU64Le(id_97) };
              choose_res_93 = id_98;
            } else {
              ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_99 { std::get<1 /* Baseline */>((*p_0)) };
              ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_100 { id_99.max_distance };
              uint16_t id_101 { uint16_t(id_100.index()) };
              uint16_t id_102 { 1 };
              bool id_103 { bool(id_101 == id_102) };
              Void id_104 { ((void)(assert(id_103)), ::dessser::VOID) };
              (void)id_104;
              ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_105 { std::get<1 /* Baseline */>((*p_0)) };
              ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_106 { id_105.max_distance };
              double id_107 { std::get<1 /* Relative */>(id_106) };
              uint64_t id_108 { qword_of_float(id_107) };
              Pointer id_109 { ssum_dst_482.writeU64Le(id_108) };
              choose_res_93 = id_109;
            }
            let_res_87 = choose_res_93;
          }
          let_res_82 = let_res_87;
        }
        choose_res_52 = let_res_82;
      }
      let_res_48 = choose_res_52;
    }
    return let_res_48;
  }
   };
  return fun45;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alert::threshold> ,Pointer)> threshold_to_row_binary(threshold_to_row_binary_init());

/* 
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[[]]; group-by: $field_name[[]]?; having: $simple_filter[[]]; threshold: (threshold AS [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]); hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[[]]; carry-fields: $field_name[[]]; carry-csts: (constant AS {name: $field_name; value: STRING})[[]]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}" "Ptr")
      (let "srec_dst_538"
        (let "srec_dst_535"
          (let "srec_dst_532"
            (let "srec_dst_529"
              (let "srec_dst_523"
                (let "srec_dst_517"
                  (let "srec_dst_511"
                    (let "srec_dst_510"
                      (let "srec_dst_509"
                        (let "srec_dst_508"
                          (let "srec_dst_507"
                            (let "srec_dst_506"
                              (let "srec_dst_500"
                                (let "srec_dst_494"
                                  (let "srec_dst_488"
                                    (let "srec_dst_487"
                                      (let "srec_dst_486" (apply (ext-identifier fq_name to-row-binary) (get-field "table" (param 0)) (param 1))
                                        (apply (ext-identifier field_name to-row-binary) (get-field "column" (param 0)) (identifier "srec_dst_486")))
                                      (write-u8 (identifier "srec_dst_487") (u8-of-bool (get-field "enabled" (param 0)))))
                                    (let "dst_ref_491"
                                      (make-vec
                                        (let "leb128_sz_489" (make-vec (cardinality (get-field "where" (param 0))))
                                          (let "leb128_ptr_490" (make-vec (identifier "srec_dst_488"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_490")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_490"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_489"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_489"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_489"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_489") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_489")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_489")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_490"))))))
                                      (let "n_ref_492" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_493" (get-field "where" (param 0))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_491") (apply (ext-identifier simple_filter to-row-binary) (identifier "x_493") (unsafe-nth (u8 0) (identifier "dst_ref_491"))))
                                              (set-vec (u8 0) (identifier "n_ref_492") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_492")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_491"))))))
                                  (if (is-null (get-field "group-by" (param 0))) 
                                    (write-u8 (identifier "srec_dst_494") (u8 1))
                                    (let "dst_ref_497"
                                      (make-vec
                                        (let "leb128_sz_495" (make-vec (cardinality (force (get-field "group-by" (param 0)))))
                                          (let "leb128_ptr_496" (make-vec (write-u8 (identifier "srec_dst_494") (u8 0)))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_496")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_496"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_495"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_495"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_495"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_495") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_495")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_495")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_496"))))))
                                      (let "n_ref_498" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_499" (force (get-field "group-by" (param 0)))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_497") (apply (ext-identifier field_name to-row-binary) (identifier "x_499") (unsafe-nth (u8 0) (identifier "dst_ref_497"))))
                                              (set-vec (u8 0) (identifier "n_ref_498") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_498")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_497")))))))
                                (let "dst_ref_503"
                                  (make-vec
                                    (let "leb128_sz_501" (make-vec (cardinality (get-field "having" (param 0))))
                                      (let "leb128_ptr_502" (make-vec (identifier "srec_dst_500"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_502")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_502"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_501"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_501"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_501"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_501") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_501")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_501")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_502"))))))
                                  (let "n_ref_504" (make-vec (i32 0))
                                    (seq
                                      (for-each "x_505" (get-field "having" (param 0))
                                        (seq (set-vec (u8 0) (identifier "dst_ref_503") (apply (ext-identifier simple_filter to-row-binary) (identifier "x_505") (unsafe-nth (u8 0) (identifier "dst_ref_503"))))
                                          (set-vec (u8 0) (identifier "n_ref_504") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_504")))))) 
                                      (unsafe-nth (u8 0) (identifier "dst_ref_503")))))) 
                              (apply (identifier "threshold-to-row-binary") (get-field "threshold" (param 0)) (identifier "srec_dst_506")))
                            (write-u64 little-endian (identifier "srec_dst_507") (u64-of-float (get-field "hysteresis" (param 0)))))
                          (write-u64 little-endian (identifier "srec_dst_508") (u64-of-float (get-field "duration" (param 0))))) 
                        (write-u64 little-endian (identifier "srec_dst_509") (u64-of-float (get-field "ratio" (param 0))))) 
                      (write-u64 little-endian (identifier "srec_dst_510") (u64-of-float (get-field "time-step" (param 0)))))
                    (let "dst_ref_514"
                      (make-vec
                        (let "leb128_sz_512" (make-vec (cardinality (get-field "tops" (param 0))))
                          (let "leb128_ptr_513" (make-vec (identifier "srec_dst_511"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_513")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_513"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_512"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_512"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_512"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_512") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_512")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_512")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_513"))))))
                      (let "n_ref_515" (make-vec (i32 0))
                        (seq
                          (for-each "x_516" (get-field "tops" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_514") (apply (ext-identifier field_name to-row-binary) (identifier "x_516") (unsafe-nth (u8 0) (identifier "dst_ref_514"))))
                              (set-vec (u8 0) (identifier "n_ref_515") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_515")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_514"))))))
                  (let "dst_ref_520"
                    (make-vec
                      (let "leb128_sz_518" (make-vec (cardinality (get-field "carry-fields" (param 0))))
                        (let "leb128_ptr_519" (make-vec (identifier "srec_dst_517"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_519")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_519"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_518"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_518"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_518"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_518") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_518")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_518")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_519"))))))
                    (let "n_ref_521" (make-vec (i32 0))
                      (seq
                        (for-each "x_522" (get-field "carry-fields" (param 0))
                          (seq (set-vec (u8 0) (identifier "dst_ref_520") (apply (ext-identifier field_name to-row-binary) (identifier "x_522") (unsafe-nth (u8 0) (identifier "dst_ref_520"))))
                            (set-vec (u8 0) (identifier "n_ref_521") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_521")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_520"))))))
                (let "dst_ref_526"
                  (make-vec
                    (let "leb128_sz_524" (make-vec (cardinality (get-field "carry-csts" (param 0))))
                      (let "leb128_ptr_525" (make-vec (identifier "srec_dst_523"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_525")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_525"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_524"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_524"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_524"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_524") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_524")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_524")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_525"))))))
                  (let "n_ref_527" (make-vec (i32 0))
                    (seq
                      (for-each "x_528" (get-field "carry-csts" (param 0))
                        (seq (set-vec (u8 0) (identifier "dst_ref_526") (apply (identifier "constant-to-row-binary") (identifier "x_528") (unsafe-nth (u8 0) (identifier "dst_ref_526"))))
                          (set-vec (u8 0) (identifier "n_ref_527") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_527")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_526"))))))
              (write-bytes
                (let "leb128_sz_530" (make-vec (string-length (get-field "id" (param 0))))
                  (let "leb128_ptr_531" (make-vec (identifier "srec_dst_529"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_531")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_531"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_530"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_530"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_530"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_530") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_530")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_530")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_531"))))) 
                (bytes-of-string (get-field "id" (param 0)))))
            (write-bytes
              (let "leb128_sz_533" (make-vec (string-length (get-field "desc-title" (param 0))))
                (let "leb128_ptr_534" (make-vec (identifier "srec_dst_532"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_534")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_534"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_533"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_533"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_533"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_533") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_533")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_533")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_534"))))) 
              (bytes-of-string (get-field "desc-title" (param 0)))))
          (write-bytes
            (let "leb128_sz_536" (make-vec (string-length (get-field "desc-firing" (param 0))))
              (let "leb128_ptr_537" (make-vec (identifier "srec_dst_535"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_537")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_537"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_536"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_536"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_536"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_536") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_536")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_536")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_537"))))) 
            (bytes-of-string (get-field "desc-firing" (param 0)))))
        (write-bytes
          (let "leb128_sz_539" (make-vec (string-length (get-field "desc-recovery" (param 0))))
            (let "leb128_ptr_540" (make-vec (identifier "srec_dst_538"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_540")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_540"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_539"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_539"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_539"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_539") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_539")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_539")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_540"))))) 
          (bytes-of-string (get-field "desc-recovery" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> fun110 { [&fun110](std::shared_ptr<::dessser::gen::alert::t>  p_0, Pointer p_1) {
    auto fun111 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_112 { (*p_0).table };
    Pointer id_113 { fun111(id_112, p_1) };
    Pointer let_res_114;
    {
      Pointer srec_dst_486 { id_113 };
      auto fun115 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_116 { (*p_0).column };
      Pointer id_117 { fun115(id_116, srec_dst_486) };
      let_res_114 = id_117;
    }
    Pointer let_res_118;
    {
      Pointer srec_dst_487 { let_res_114 };
      bool id_119 { (*p_0).enabled };
      uint8_t id_120 { uint8_t(id_119) };
      Pointer id_121 { srec_dst_487.writeU8(id_120) };
      let_res_118 = id_121;
    }
    Pointer let_res_122;
    {
      Pointer srec_dst_488 { let_res_118 };
      Lst<dessser::gen::simple_filter::t_ext> id_123 { (*p_0).where };
      uint32_t id_124 { id_123.size() };
      Vec<1, uint32_t> id_125 {  id_124  };
      Pointer let_res_126;
      {
        Vec<1, uint32_t> leb128_sz_489 { id_125 };
        Vec<1, Pointer> id_127 {  srec_dst_488  };
        Pointer let_res_128;
        {
          Vec<1, Pointer> leb128_ptr_490 { id_127 };
          bool while_flag_129 { true };
          do {
            uint8_t id_130 { 0 };
            uint8_t id_131 { 0 };
            Pointer id_132 { leb128_ptr_490[id_131] };
            uint32_t id_133 { 128U };
            uint8_t id_134 { 0 };
            uint32_t id_135 { leb128_sz_489[id_134] };
            bool id_136 { bool(id_133 > id_135) };
            uint8_t choose_res_137;
            if (id_136) {
              uint8_t id_138 { 0 };
              uint32_t id_139 { leb128_sz_489[id_138] };
              uint8_t id_140 { uint8_t(id_139) };
              choose_res_137 = id_140;
            } else {
              uint8_t id_141 { 0 };
              uint32_t id_142 { leb128_sz_489[id_141] };
              uint8_t id_143 { uint8_t(id_142) };
              uint8_t id_144 { 128 };
              uint8_t id_145 { uint8_t(id_143 | id_144) };
              choose_res_137 = id_145;
            }
            Pointer id_146 { id_132.writeU8(choose_res_137) };
            Void id_147 { ((void)(leb128_ptr_490[id_130] = id_146), ::dessser::VOID) };
            (void)id_147;
            uint8_t id_148 { 0 };
            uint8_t id_149 { 0 };
            uint32_t id_150 { leb128_sz_489[id_149] };
            uint8_t id_151 { 7 };
            uint32_t id_152 { uint32_t(id_150 >> id_151) };
            Void id_153 { ((void)(leb128_sz_489[id_148] = id_152), ::dessser::VOID) };
            (void)id_153;
            uint8_t id_154 { 0 };
            uint32_t id_155 { leb128_sz_489[id_154] };
            uint32_t id_156 { 0U };
            bool id_157 { bool(id_155 > id_156) };
            while_flag_129 = id_157;
            if (while_flag_129) {
              (void)::dessser::VOID;
            }
          } while (while_flag_129);
          (void)::dessser::VOID;
          uint8_t id_158 { 0 };
          Pointer id_159 { leb128_ptr_490[id_158] };
          let_res_128 = id_159;
        }
        let_res_126 = let_res_128;
      }
      Vec<1, Pointer> id_160 {  let_res_126  };
      Pointer let_res_161;
      {
        Vec<1, Pointer> dst_ref_491 { id_160 };
        int32_t id_162 { 0L };
        Vec<1, int32_t> id_163 {  id_162  };
        Pointer let_res_164;
        {
          Vec<1, int32_t> n_ref_492 { id_163 };
          Lst<dessser::gen::simple_filter::t_ext> id_165 { (*p_0).where };
          for (dessser::gen::simple_filter::t_ext x_493 : id_165) {
            uint8_t id_166 { 0 };
            auto fun167 { dessser::gen::simple_filter::to_row_binary };
            uint8_t id_168 { 0 };
            Pointer id_169 { dst_ref_491[id_168] };
            Pointer id_170 { fun167(x_493, id_169) };
            Void id_171 { ((void)(dst_ref_491[id_166] = id_170), ::dessser::VOID) };
            (void)id_171;
            uint8_t id_172 { 0 };
            int32_t id_173 { 1L };
            uint8_t id_174 { 0 };
            int32_t id_175 { n_ref_492[id_174] };
            int32_t id_176 { int32_t(id_173 + id_175) };
            Void id_177 { ((void)(n_ref_492[id_172] = id_176), ::dessser::VOID) };
            (void)id_177;
            (void)id_177;
          }
          (void)::dessser::VOID;
          uint8_t id_178 { 0 };
          Pointer id_179 { dst_ref_491[id_178] };
          let_res_164 = id_179;
        }
        let_res_161 = let_res_164;
      }
      let_res_122 = let_res_161;
    }
    Pointer let_res_180;
    {
      Pointer srec_dst_494 { let_res_122 };
      std::optional<Lst<dessser::gen::field_name::t_ext>> id_181 { (*p_0).group_by };
      bool id_182 { !(id_181.has_value ()) };
      Pointer choose_res_183;
      if (id_182) {
        uint8_t id_184 { 1 };
        Pointer id_185 { srec_dst_494.writeU8(id_184) };
        choose_res_183 = id_185;
      } else {
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_186 { (*p_0).group_by };
        Lst<dessser::gen::field_name::t_ext> id_187 { id_186.value() };
        uint32_t id_188 { id_187.size() };
        Vec<1, uint32_t> id_189 {  id_188  };
        Pointer let_res_190;
        {
          Vec<1, uint32_t> leb128_sz_495 { id_189 };
          uint8_t id_191 { 0 };
          Pointer id_192 { srec_dst_494.writeU8(id_191) };
          Vec<1, Pointer> id_193 {  id_192  };
          Pointer let_res_194;
          {
            Vec<1, Pointer> leb128_ptr_496 { id_193 };
            bool while_flag_195 { true };
            do {
              uint8_t id_196 { 0 };
              uint8_t id_197 { 0 };
              Pointer id_198 { leb128_ptr_496[id_197] };
              uint32_t id_199 { 128U };
              uint8_t id_200 { 0 };
              uint32_t id_201 { leb128_sz_495[id_200] };
              bool id_202 { bool(id_199 > id_201) };
              uint8_t choose_res_203;
              if (id_202) {
                uint8_t id_204 { 0 };
                uint32_t id_205 { leb128_sz_495[id_204] };
                uint8_t id_206 { uint8_t(id_205) };
                choose_res_203 = id_206;
              } else {
                uint8_t id_207 { 0 };
                uint32_t id_208 { leb128_sz_495[id_207] };
                uint8_t id_209 { uint8_t(id_208) };
                uint8_t id_210 { 128 };
                uint8_t id_211 { uint8_t(id_209 | id_210) };
                choose_res_203 = id_211;
              }
              Pointer id_212 { id_198.writeU8(choose_res_203) };
              Void id_213 { ((void)(leb128_ptr_496[id_196] = id_212), ::dessser::VOID) };
              (void)id_213;
              uint8_t id_214 { 0 };
              uint8_t id_215 { 0 };
              uint32_t id_216 { leb128_sz_495[id_215] };
              uint8_t id_217 { 7 };
              uint32_t id_218 { uint32_t(id_216 >> id_217) };
              Void id_219 { ((void)(leb128_sz_495[id_214] = id_218), ::dessser::VOID) };
              (void)id_219;
              uint8_t id_220 { 0 };
              uint32_t id_221 { leb128_sz_495[id_220] };
              uint32_t id_222 { 0U };
              bool id_223 { bool(id_221 > id_222) };
              while_flag_195 = id_223;
              if (while_flag_195) {
                (void)::dessser::VOID;
              }
            } while (while_flag_195);
            (void)::dessser::VOID;
            uint8_t id_224 { 0 };
            Pointer id_225 { leb128_ptr_496[id_224] };
            let_res_194 = id_225;
          }
          let_res_190 = let_res_194;
        }
        Vec<1, Pointer> id_226 {  let_res_190  };
        Pointer let_res_227;
        {
          Vec<1, Pointer> dst_ref_497 { id_226 };
          int32_t id_228 { 0L };
          Vec<1, int32_t> id_229 {  id_228  };
          Pointer let_res_230;
          {
            Vec<1, int32_t> n_ref_498 { id_229 };
            std::optional<Lst<dessser::gen::field_name::t_ext>> id_231 { (*p_0).group_by };
            Lst<dessser::gen::field_name::t_ext> id_232 { id_231.value() };
            for (dessser::gen::field_name::t_ext x_499 : id_232) {
              uint8_t id_233 { 0 };
              auto fun234 { dessser::gen::field_name::to_row_binary };
              uint8_t id_235 { 0 };
              Pointer id_236 { dst_ref_497[id_235] };
              Pointer id_237 { fun234(x_499, id_236) };
              Void id_238 { ((void)(dst_ref_497[id_233] = id_237), ::dessser::VOID) };
              (void)id_238;
              uint8_t id_239 { 0 };
              int32_t id_240 { 1L };
              uint8_t id_241 { 0 };
              int32_t id_242 { n_ref_498[id_241] };
              int32_t id_243 { int32_t(id_240 + id_242) };
              Void id_244 { ((void)(n_ref_498[id_239] = id_243), ::dessser::VOID) };
              (void)id_244;
              (void)id_244;
            }
            (void)::dessser::VOID;
            uint8_t id_245 { 0 };
            Pointer id_246 { dst_ref_497[id_245] };
            let_res_230 = id_246;
          }
          let_res_227 = let_res_230;
        }
        choose_res_183 = let_res_227;
      }
      let_res_180 = choose_res_183;
    }
    Pointer let_res_247;
    {
      Pointer srec_dst_500 { let_res_180 };
      Lst<dessser::gen::simple_filter::t_ext> id_248 { (*p_0).having };
      uint32_t id_249 { id_248.size() };
      Vec<1, uint32_t> id_250 {  id_249  };
      Pointer let_res_251;
      {
        Vec<1, uint32_t> leb128_sz_501 { id_250 };
        Vec<1, Pointer> id_252 {  srec_dst_500  };
        Pointer let_res_253;
        {
          Vec<1, Pointer> leb128_ptr_502 { id_252 };
          bool while_flag_254 { true };
          do {
            uint8_t id_255 { 0 };
            uint8_t id_256 { 0 };
            Pointer id_257 { leb128_ptr_502[id_256] };
            uint32_t id_258 { 128U };
            uint8_t id_259 { 0 };
            uint32_t id_260 { leb128_sz_501[id_259] };
            bool id_261 { bool(id_258 > id_260) };
            uint8_t choose_res_262;
            if (id_261) {
              uint8_t id_263 { 0 };
              uint32_t id_264 { leb128_sz_501[id_263] };
              uint8_t id_265 { uint8_t(id_264) };
              choose_res_262 = id_265;
            } else {
              uint8_t id_266 { 0 };
              uint32_t id_267 { leb128_sz_501[id_266] };
              uint8_t id_268 { uint8_t(id_267) };
              uint8_t id_269 { 128 };
              uint8_t id_270 { uint8_t(id_268 | id_269) };
              choose_res_262 = id_270;
            }
            Pointer id_271 { id_257.writeU8(choose_res_262) };
            Void id_272 { ((void)(leb128_ptr_502[id_255] = id_271), ::dessser::VOID) };
            (void)id_272;
            uint8_t id_273 { 0 };
            uint8_t id_274 { 0 };
            uint32_t id_275 { leb128_sz_501[id_274] };
            uint8_t id_276 { 7 };
            uint32_t id_277 { uint32_t(id_275 >> id_276) };
            Void id_278 { ((void)(leb128_sz_501[id_273] = id_277), ::dessser::VOID) };
            (void)id_278;
            uint8_t id_279 { 0 };
            uint32_t id_280 { leb128_sz_501[id_279] };
            uint32_t id_281 { 0U };
            bool id_282 { bool(id_280 > id_281) };
            while_flag_254 = id_282;
            if (while_flag_254) {
              (void)::dessser::VOID;
            }
          } while (while_flag_254);
          (void)::dessser::VOID;
          uint8_t id_283 { 0 };
          Pointer id_284 { leb128_ptr_502[id_283] };
          let_res_253 = id_284;
        }
        let_res_251 = let_res_253;
      }
      Vec<1, Pointer> id_285 {  let_res_251  };
      Pointer let_res_286;
      {
        Vec<1, Pointer> dst_ref_503 { id_285 };
        int32_t id_287 { 0L };
        Vec<1, int32_t> id_288 {  id_287  };
        Pointer let_res_289;
        {
          Vec<1, int32_t> n_ref_504 { id_288 };
          Lst<dessser::gen::simple_filter::t_ext> id_290 { (*p_0).having };
          for (dessser::gen::simple_filter::t_ext x_505 : id_290) {
            uint8_t id_291 { 0 };
            auto fun292 { dessser::gen::simple_filter::to_row_binary };
            uint8_t id_293 { 0 };
            Pointer id_294 { dst_ref_503[id_293] };
            Pointer id_295 { fun292(x_505, id_294) };
            Void id_296 { ((void)(dst_ref_503[id_291] = id_295), ::dessser::VOID) };
            (void)id_296;
            uint8_t id_297 { 0 };
            int32_t id_298 { 1L };
            uint8_t id_299 { 0 };
            int32_t id_300 { n_ref_504[id_299] };
            int32_t id_301 { int32_t(id_298 + id_300) };
            Void id_302 { ((void)(n_ref_504[id_297] = id_301), ::dessser::VOID) };
            (void)id_302;
            (void)id_302;
          }
          (void)::dessser::VOID;
          uint8_t id_303 { 0 };
          Pointer id_304 { dst_ref_503[id_303] };
          let_res_289 = id_304;
        }
        let_res_286 = let_res_289;
      }
      let_res_247 = let_res_286;
    }
    Pointer let_res_305;
    {
      Pointer srec_dst_506 { let_res_247 };
      std::shared_ptr<::dessser::gen::alert::threshold>  id_306 { (*p_0).threshold };
      Pointer id_307 { threshold_to_row_binary(id_306, srec_dst_506) };
      let_res_305 = id_307;
    }
    Pointer let_res_308;
    {
      Pointer srec_dst_507 { let_res_305 };
      double id_309 { (*p_0).hysteresis };
      uint64_t id_310 { qword_of_float(id_309) };
      Pointer id_311 { srec_dst_507.writeU64Le(id_310) };
      let_res_308 = id_311;
    }
    Pointer let_res_312;
    {
      Pointer srec_dst_508 { let_res_308 };
      double id_313 { (*p_0).duration };
      uint64_t id_314 { qword_of_float(id_313) };
      Pointer id_315 { srec_dst_508.writeU64Le(id_314) };
      let_res_312 = id_315;
    }
    Pointer let_res_316;
    {
      Pointer srec_dst_509 { let_res_312 };
      double id_317 { (*p_0).ratio };
      uint64_t id_318 { qword_of_float(id_317) };
      Pointer id_319 { srec_dst_509.writeU64Le(id_318) };
      let_res_316 = id_319;
    }
    Pointer let_res_320;
    {
      Pointer srec_dst_510 { let_res_316 };
      double id_321 { (*p_0).time_step };
      uint64_t id_322 { qword_of_float(id_321) };
      Pointer id_323 { srec_dst_510.writeU64Le(id_322) };
      let_res_320 = id_323;
    }
    Pointer let_res_324;
    {
      Pointer srec_dst_511 { let_res_320 };
      Lst<dessser::gen::field_name::t_ext> id_325 { (*p_0).tops };
      uint32_t id_326 { id_325.size() };
      Vec<1, uint32_t> id_327 {  id_326  };
      Pointer let_res_328;
      {
        Vec<1, uint32_t> leb128_sz_512 { id_327 };
        Vec<1, Pointer> id_329 {  srec_dst_511  };
        Pointer let_res_330;
        {
          Vec<1, Pointer> leb128_ptr_513 { id_329 };
          bool while_flag_331 { true };
          do {
            uint8_t id_332 { 0 };
            uint8_t id_333 { 0 };
            Pointer id_334 { leb128_ptr_513[id_333] };
            uint32_t id_335 { 128U };
            uint8_t id_336 { 0 };
            uint32_t id_337 { leb128_sz_512[id_336] };
            bool id_338 { bool(id_335 > id_337) };
            uint8_t choose_res_339;
            if (id_338) {
              uint8_t id_340 { 0 };
              uint32_t id_341 { leb128_sz_512[id_340] };
              uint8_t id_342 { uint8_t(id_341) };
              choose_res_339 = id_342;
            } else {
              uint8_t id_343 { 0 };
              uint32_t id_344 { leb128_sz_512[id_343] };
              uint8_t id_345 { uint8_t(id_344) };
              uint8_t id_346 { 128 };
              uint8_t id_347 { uint8_t(id_345 | id_346) };
              choose_res_339 = id_347;
            }
            Pointer id_348 { id_334.writeU8(choose_res_339) };
            Void id_349 { ((void)(leb128_ptr_513[id_332] = id_348), ::dessser::VOID) };
            (void)id_349;
            uint8_t id_350 { 0 };
            uint8_t id_351 { 0 };
            uint32_t id_352 { leb128_sz_512[id_351] };
            uint8_t id_353 { 7 };
            uint32_t id_354 { uint32_t(id_352 >> id_353) };
            Void id_355 { ((void)(leb128_sz_512[id_350] = id_354), ::dessser::VOID) };
            (void)id_355;
            uint8_t id_356 { 0 };
            uint32_t id_357 { leb128_sz_512[id_356] };
            uint32_t id_358 { 0U };
            bool id_359 { bool(id_357 > id_358) };
            while_flag_331 = id_359;
            if (while_flag_331) {
              (void)::dessser::VOID;
            }
          } while (while_flag_331);
          (void)::dessser::VOID;
          uint8_t id_360 { 0 };
          Pointer id_361 { leb128_ptr_513[id_360] };
          let_res_330 = id_361;
        }
        let_res_328 = let_res_330;
      }
      Vec<1, Pointer> id_362 {  let_res_328  };
      Pointer let_res_363;
      {
        Vec<1, Pointer> dst_ref_514 { id_362 };
        int32_t id_364 { 0L };
        Vec<1, int32_t> id_365 {  id_364  };
        Pointer let_res_366;
        {
          Vec<1, int32_t> n_ref_515 { id_365 };
          Lst<dessser::gen::field_name::t_ext> id_367 { (*p_0).tops };
          for (dessser::gen::field_name::t_ext x_516 : id_367) {
            uint8_t id_368 { 0 };
            auto fun369 { dessser::gen::field_name::to_row_binary };
            uint8_t id_370 { 0 };
            Pointer id_371 { dst_ref_514[id_370] };
            Pointer id_372 { fun369(x_516, id_371) };
            Void id_373 { ((void)(dst_ref_514[id_368] = id_372), ::dessser::VOID) };
            (void)id_373;
            uint8_t id_374 { 0 };
            int32_t id_375 { 1L };
            uint8_t id_376 { 0 };
            int32_t id_377 { n_ref_515[id_376] };
            int32_t id_378 { int32_t(id_375 + id_377) };
            Void id_379 { ((void)(n_ref_515[id_374] = id_378), ::dessser::VOID) };
            (void)id_379;
            (void)id_379;
          }
          (void)::dessser::VOID;
          uint8_t id_380 { 0 };
          Pointer id_381 { dst_ref_514[id_380] };
          let_res_366 = id_381;
        }
        let_res_363 = let_res_366;
      }
      let_res_324 = let_res_363;
    }
    Pointer let_res_382;
    {
      Pointer srec_dst_517 { let_res_324 };
      Lst<dessser::gen::field_name::t_ext> id_383 { (*p_0).carry_fields };
      uint32_t id_384 { id_383.size() };
      Vec<1, uint32_t> id_385 {  id_384  };
      Pointer let_res_386;
      {
        Vec<1, uint32_t> leb128_sz_518 { id_385 };
        Vec<1, Pointer> id_387 {  srec_dst_517  };
        Pointer let_res_388;
        {
          Vec<1, Pointer> leb128_ptr_519 { id_387 };
          bool while_flag_389 { true };
          do {
            uint8_t id_390 { 0 };
            uint8_t id_391 { 0 };
            Pointer id_392 { leb128_ptr_519[id_391] };
            uint32_t id_393 { 128U };
            uint8_t id_394 { 0 };
            uint32_t id_395 { leb128_sz_518[id_394] };
            bool id_396 { bool(id_393 > id_395) };
            uint8_t choose_res_397;
            if (id_396) {
              uint8_t id_398 { 0 };
              uint32_t id_399 { leb128_sz_518[id_398] };
              uint8_t id_400 { uint8_t(id_399) };
              choose_res_397 = id_400;
            } else {
              uint8_t id_401 { 0 };
              uint32_t id_402 { leb128_sz_518[id_401] };
              uint8_t id_403 { uint8_t(id_402) };
              uint8_t id_404 { 128 };
              uint8_t id_405 { uint8_t(id_403 | id_404) };
              choose_res_397 = id_405;
            }
            Pointer id_406 { id_392.writeU8(choose_res_397) };
            Void id_407 { ((void)(leb128_ptr_519[id_390] = id_406), ::dessser::VOID) };
            (void)id_407;
            uint8_t id_408 { 0 };
            uint8_t id_409 { 0 };
            uint32_t id_410 { leb128_sz_518[id_409] };
            uint8_t id_411 { 7 };
            uint32_t id_412 { uint32_t(id_410 >> id_411) };
            Void id_413 { ((void)(leb128_sz_518[id_408] = id_412), ::dessser::VOID) };
            (void)id_413;
            uint8_t id_414 { 0 };
            uint32_t id_415 { leb128_sz_518[id_414] };
            uint32_t id_416 { 0U };
            bool id_417 { bool(id_415 > id_416) };
            while_flag_389 = id_417;
            if (while_flag_389) {
              (void)::dessser::VOID;
            }
          } while (while_flag_389);
          (void)::dessser::VOID;
          uint8_t id_418 { 0 };
          Pointer id_419 { leb128_ptr_519[id_418] };
          let_res_388 = id_419;
        }
        let_res_386 = let_res_388;
      }
      Vec<1, Pointer> id_420 {  let_res_386  };
      Pointer let_res_421;
      {
        Vec<1, Pointer> dst_ref_520 { id_420 };
        int32_t id_422 { 0L };
        Vec<1, int32_t> id_423 {  id_422  };
        Pointer let_res_424;
        {
          Vec<1, int32_t> n_ref_521 { id_423 };
          Lst<dessser::gen::field_name::t_ext> id_425 { (*p_0).carry_fields };
          for (dessser::gen::field_name::t_ext x_522 : id_425) {
            uint8_t id_426 { 0 };
            auto fun427 { dessser::gen::field_name::to_row_binary };
            uint8_t id_428 { 0 };
            Pointer id_429 { dst_ref_520[id_428] };
            Pointer id_430 { fun427(x_522, id_429) };
            Void id_431 { ((void)(dst_ref_520[id_426] = id_430), ::dessser::VOID) };
            (void)id_431;
            uint8_t id_432 { 0 };
            int32_t id_433 { 1L };
            uint8_t id_434 { 0 };
            int32_t id_435 { n_ref_521[id_434] };
            int32_t id_436 { int32_t(id_433 + id_435) };
            Void id_437 { ((void)(n_ref_521[id_432] = id_436), ::dessser::VOID) };
            (void)id_437;
            (void)id_437;
          }
          (void)::dessser::VOID;
          uint8_t id_438 { 0 };
          Pointer id_439 { dst_ref_520[id_438] };
          let_res_424 = id_439;
        }
        let_res_421 = let_res_424;
      }
      let_res_382 = let_res_421;
    }
    Pointer let_res_440;
    {
      Pointer srec_dst_523 { let_res_382 };
      Lst<std::shared_ptr<::dessser::gen::alert::constant> > id_441 { (*p_0).carry_csts };
      uint32_t id_442 { id_441.size() };
      Vec<1, uint32_t> id_443 {  id_442  };
      Pointer let_res_444;
      {
        Vec<1, uint32_t> leb128_sz_524 { id_443 };
        Vec<1, Pointer> id_445 {  srec_dst_523  };
        Pointer let_res_446;
        {
          Vec<1, Pointer> leb128_ptr_525 { id_445 };
          bool while_flag_447 { true };
          do {
            uint8_t id_448 { 0 };
            uint8_t id_449 { 0 };
            Pointer id_450 { leb128_ptr_525[id_449] };
            uint32_t id_451 { 128U };
            uint8_t id_452 { 0 };
            uint32_t id_453 { leb128_sz_524[id_452] };
            bool id_454 { bool(id_451 > id_453) };
            uint8_t choose_res_455;
            if (id_454) {
              uint8_t id_456 { 0 };
              uint32_t id_457 { leb128_sz_524[id_456] };
              uint8_t id_458 { uint8_t(id_457) };
              choose_res_455 = id_458;
            } else {
              uint8_t id_459 { 0 };
              uint32_t id_460 { leb128_sz_524[id_459] };
              uint8_t id_461 { uint8_t(id_460) };
              uint8_t id_462 { 128 };
              uint8_t id_463 { uint8_t(id_461 | id_462) };
              choose_res_455 = id_463;
            }
            Pointer id_464 { id_450.writeU8(choose_res_455) };
            Void id_465 { ((void)(leb128_ptr_525[id_448] = id_464), ::dessser::VOID) };
            (void)id_465;
            uint8_t id_466 { 0 };
            uint8_t id_467 { 0 };
            uint32_t id_468 { leb128_sz_524[id_467] };
            uint8_t id_469 { 7 };
            uint32_t id_470 { uint32_t(id_468 >> id_469) };
            Void id_471 { ((void)(leb128_sz_524[id_466] = id_470), ::dessser::VOID) };
            (void)id_471;
            uint8_t id_472 { 0 };
            uint32_t id_473 { leb128_sz_524[id_472] };
            uint32_t id_474 { 0U };
            bool id_475 { bool(id_473 > id_474) };
            while_flag_447 = id_475;
            if (while_flag_447) {
              (void)::dessser::VOID;
            }
          } while (while_flag_447);
          (void)::dessser::VOID;
          uint8_t id_476 { 0 };
          Pointer id_477 { leb128_ptr_525[id_476] };
          let_res_446 = id_477;
        }
        let_res_444 = let_res_446;
      }
      Vec<1, Pointer> id_478 {  let_res_444  };
      Pointer let_res_479;
      {
        Vec<1, Pointer> dst_ref_526 { id_478 };
        int32_t id_480 { 0L };
        Vec<1, int32_t> id_481 {  id_480  };
        Pointer let_res_482;
        {
          Vec<1, int32_t> n_ref_527 { id_481 };
          Lst<std::shared_ptr<::dessser::gen::alert::constant> > id_483 { (*p_0).carry_csts };
          for (std::shared_ptr<::dessser::gen::alert::constant>  x_528 : id_483) {
            uint8_t id_484 { 0 };
            uint8_t id_485 { 0 };
            Pointer id_486 { dst_ref_526[id_485] };
            Pointer id_487 { constant_to_row_binary(x_528, id_486) };
            Void id_488 { ((void)(dst_ref_526[id_484] = id_487), ::dessser::VOID) };
            (void)id_488;
            uint8_t id_489 { 0 };
            int32_t id_490 { 1L };
            uint8_t id_491 { 0 };
            int32_t id_492 { n_ref_527[id_491] };
            int32_t id_493 { int32_t(id_490 + id_492) };
            Void id_494 { ((void)(n_ref_527[id_489] = id_493), ::dessser::VOID) };
            (void)id_494;
            (void)id_494;
          }
          (void)::dessser::VOID;
          uint8_t id_495 { 0 };
          Pointer id_496 { dst_ref_526[id_495] };
          let_res_482 = id_496;
        }
        let_res_479 = let_res_482;
      }
      let_res_440 = let_res_479;
    }
    Pointer let_res_497;
    {
      Pointer srec_dst_529 { let_res_440 };
      std::string id_498 { (*p_0).id };
      uint32_t id_499 { (uint32_t)id_498.size() };
      Vec<1, uint32_t> id_500 {  id_499  };
      Pointer let_res_501;
      {
        Vec<1, uint32_t> leb128_sz_530 { id_500 };
        Vec<1, Pointer> id_502 {  srec_dst_529  };
        Pointer let_res_503;
        {
          Vec<1, Pointer> leb128_ptr_531 { id_502 };
          bool while_flag_504 { true };
          do {
            uint8_t id_505 { 0 };
            uint8_t id_506 { 0 };
            Pointer id_507 { leb128_ptr_531[id_506] };
            uint32_t id_508 { 128U };
            uint8_t id_509 { 0 };
            uint32_t id_510 { leb128_sz_530[id_509] };
            bool id_511 { bool(id_508 > id_510) };
            uint8_t choose_res_512;
            if (id_511) {
              uint8_t id_513 { 0 };
              uint32_t id_514 { leb128_sz_530[id_513] };
              uint8_t id_515 { uint8_t(id_514) };
              choose_res_512 = id_515;
            } else {
              uint8_t id_516 { 0 };
              uint32_t id_517 { leb128_sz_530[id_516] };
              uint8_t id_518 { uint8_t(id_517) };
              uint8_t id_519 { 128 };
              uint8_t id_520 { uint8_t(id_518 | id_519) };
              choose_res_512 = id_520;
            }
            Pointer id_521 { id_507.writeU8(choose_res_512) };
            Void id_522 { ((void)(leb128_ptr_531[id_505] = id_521), ::dessser::VOID) };
            (void)id_522;
            uint8_t id_523 { 0 };
            uint8_t id_524 { 0 };
            uint32_t id_525 { leb128_sz_530[id_524] };
            uint8_t id_526 { 7 };
            uint32_t id_527 { uint32_t(id_525 >> id_526) };
            Void id_528 { ((void)(leb128_sz_530[id_523] = id_527), ::dessser::VOID) };
            (void)id_528;
            uint8_t id_529 { 0 };
            uint32_t id_530 { leb128_sz_530[id_529] };
            uint32_t id_531 { 0U };
            bool id_532 { bool(id_530 > id_531) };
            while_flag_504 = id_532;
            if (while_flag_504) {
              (void)::dessser::VOID;
            }
          } while (while_flag_504);
          (void)::dessser::VOID;
          uint8_t id_533 { 0 };
          Pointer id_534 { leb128_ptr_531[id_533] };
          let_res_503 = id_534;
        }
        let_res_501 = let_res_503;
      }
      std::string id_535 { (*p_0).id };
      Bytes id_536 { id_535 };
      Pointer id_537 { let_res_501.writeBytes(id_536) };
      let_res_497 = id_537;
    }
    Pointer let_res_538;
    {
      Pointer srec_dst_532 { let_res_497 };
      std::string id_539 { (*p_0).desc_title };
      uint32_t id_540 { (uint32_t)id_539.size() };
      Vec<1, uint32_t> id_541 {  id_540  };
      Pointer let_res_542;
      {
        Vec<1, uint32_t> leb128_sz_533 { id_541 };
        Vec<1, Pointer> id_543 {  srec_dst_532  };
        Pointer let_res_544;
        {
          Vec<1, Pointer> leb128_ptr_534 { id_543 };
          bool while_flag_545 { true };
          do {
            uint8_t id_546 { 0 };
            uint8_t id_547 { 0 };
            Pointer id_548 { leb128_ptr_534[id_547] };
            uint32_t id_549 { 128U };
            uint8_t id_550 { 0 };
            uint32_t id_551 { leb128_sz_533[id_550] };
            bool id_552 { bool(id_549 > id_551) };
            uint8_t choose_res_553;
            if (id_552) {
              uint8_t id_554 { 0 };
              uint32_t id_555 { leb128_sz_533[id_554] };
              uint8_t id_556 { uint8_t(id_555) };
              choose_res_553 = id_556;
            } else {
              uint8_t id_557 { 0 };
              uint32_t id_558 { leb128_sz_533[id_557] };
              uint8_t id_559 { uint8_t(id_558) };
              uint8_t id_560 { 128 };
              uint8_t id_561 { uint8_t(id_559 | id_560) };
              choose_res_553 = id_561;
            }
            Pointer id_562 { id_548.writeU8(choose_res_553) };
            Void id_563 { ((void)(leb128_ptr_534[id_546] = id_562), ::dessser::VOID) };
            (void)id_563;
            uint8_t id_564 { 0 };
            uint8_t id_565 { 0 };
            uint32_t id_566 { leb128_sz_533[id_565] };
            uint8_t id_567 { 7 };
            uint32_t id_568 { uint32_t(id_566 >> id_567) };
            Void id_569 { ((void)(leb128_sz_533[id_564] = id_568), ::dessser::VOID) };
            (void)id_569;
            uint8_t id_570 { 0 };
            uint32_t id_571 { leb128_sz_533[id_570] };
            uint32_t id_572 { 0U };
            bool id_573 { bool(id_571 > id_572) };
            while_flag_545 = id_573;
            if (while_flag_545) {
              (void)::dessser::VOID;
            }
          } while (while_flag_545);
          (void)::dessser::VOID;
          uint8_t id_574 { 0 };
          Pointer id_575 { leb128_ptr_534[id_574] };
          let_res_544 = id_575;
        }
        let_res_542 = let_res_544;
      }
      std::string id_576 { (*p_0).desc_title };
      Bytes id_577 { id_576 };
      Pointer id_578 { let_res_542.writeBytes(id_577) };
      let_res_538 = id_578;
    }
    Pointer let_res_579;
    {
      Pointer srec_dst_535 { let_res_538 };
      std::string id_580 { (*p_0).desc_firing };
      uint32_t id_581 { (uint32_t)id_580.size() };
      Vec<1, uint32_t> id_582 {  id_581  };
      Pointer let_res_583;
      {
        Vec<1, uint32_t> leb128_sz_536 { id_582 };
        Vec<1, Pointer> id_584 {  srec_dst_535  };
        Pointer let_res_585;
        {
          Vec<1, Pointer> leb128_ptr_537 { id_584 };
          bool while_flag_586 { true };
          do {
            uint8_t id_587 { 0 };
            uint8_t id_588 { 0 };
            Pointer id_589 { leb128_ptr_537[id_588] };
            uint32_t id_590 { 128U };
            uint8_t id_591 { 0 };
            uint32_t id_592 { leb128_sz_536[id_591] };
            bool id_593 { bool(id_590 > id_592) };
            uint8_t choose_res_594;
            if (id_593) {
              uint8_t id_595 { 0 };
              uint32_t id_596 { leb128_sz_536[id_595] };
              uint8_t id_597 { uint8_t(id_596) };
              choose_res_594 = id_597;
            } else {
              uint8_t id_598 { 0 };
              uint32_t id_599 { leb128_sz_536[id_598] };
              uint8_t id_600 { uint8_t(id_599) };
              uint8_t id_601 { 128 };
              uint8_t id_602 { uint8_t(id_600 | id_601) };
              choose_res_594 = id_602;
            }
            Pointer id_603 { id_589.writeU8(choose_res_594) };
            Void id_604 { ((void)(leb128_ptr_537[id_587] = id_603), ::dessser::VOID) };
            (void)id_604;
            uint8_t id_605 { 0 };
            uint8_t id_606 { 0 };
            uint32_t id_607 { leb128_sz_536[id_606] };
            uint8_t id_608 { 7 };
            uint32_t id_609 { uint32_t(id_607 >> id_608) };
            Void id_610 { ((void)(leb128_sz_536[id_605] = id_609), ::dessser::VOID) };
            (void)id_610;
            uint8_t id_611 { 0 };
            uint32_t id_612 { leb128_sz_536[id_611] };
            uint32_t id_613 { 0U };
            bool id_614 { bool(id_612 > id_613) };
            while_flag_586 = id_614;
            if (while_flag_586) {
              (void)::dessser::VOID;
            }
          } while (while_flag_586);
          (void)::dessser::VOID;
          uint8_t id_615 { 0 };
          Pointer id_616 { leb128_ptr_537[id_615] };
          let_res_585 = id_616;
        }
        let_res_583 = let_res_585;
      }
      std::string id_617 { (*p_0).desc_firing };
      Bytes id_618 { id_617 };
      Pointer id_619 { let_res_583.writeBytes(id_618) };
      let_res_579 = id_619;
    }
    Pointer let_res_620;
    {
      Pointer srec_dst_538 { let_res_579 };
      std::string id_621 { (*p_0).desc_recovery };
      uint32_t id_622 { (uint32_t)id_621.size() };
      Vec<1, uint32_t> id_623 {  id_622  };
      Pointer let_res_624;
      {
        Vec<1, uint32_t> leb128_sz_539 { id_623 };
        Vec<1, Pointer> id_625 {  srec_dst_538  };
        Pointer let_res_626;
        {
          Vec<1, Pointer> leb128_ptr_540 { id_625 };
          bool while_flag_627 { true };
          do {
            uint8_t id_628 { 0 };
            uint8_t id_629 { 0 };
            Pointer id_630 { leb128_ptr_540[id_629] };
            uint32_t id_631 { 128U };
            uint8_t id_632 { 0 };
            uint32_t id_633 { leb128_sz_539[id_632] };
            bool id_634 { bool(id_631 > id_633) };
            uint8_t choose_res_635;
            if (id_634) {
              uint8_t id_636 { 0 };
              uint32_t id_637 { leb128_sz_539[id_636] };
              uint8_t id_638 { uint8_t(id_637) };
              choose_res_635 = id_638;
            } else {
              uint8_t id_639 { 0 };
              uint32_t id_640 { leb128_sz_539[id_639] };
              uint8_t id_641 { uint8_t(id_640) };
              uint8_t id_642 { 128 };
              uint8_t id_643 { uint8_t(id_641 | id_642) };
              choose_res_635 = id_643;
            }
            Pointer id_644 { id_630.writeU8(choose_res_635) };
            Void id_645 { ((void)(leb128_ptr_540[id_628] = id_644), ::dessser::VOID) };
            (void)id_645;
            uint8_t id_646 { 0 };
            uint8_t id_647 { 0 };
            uint32_t id_648 { leb128_sz_539[id_647] };
            uint8_t id_649 { 7 };
            uint32_t id_650 { uint32_t(id_648 >> id_649) };
            Void id_651 { ((void)(leb128_sz_539[id_646] = id_650), ::dessser::VOID) };
            (void)id_651;
            uint8_t id_652 { 0 };
            uint32_t id_653 { leb128_sz_539[id_652] };
            uint32_t id_654 { 0U };
            bool id_655 { bool(id_653 > id_654) };
            while_flag_627 = id_655;
            if (while_flag_627) {
              (void)::dessser::VOID;
            }
          } while (while_flag_627);
          (void)::dessser::VOID;
          uint8_t id_656 { 0 };
          Pointer id_657 { leb128_ptr_540[id_656] };
          let_res_626 = id_657;
        }
        let_res_624 = let_res_626;
      }
      std::string id_658 { (*p_0).desc_recovery };
      Bytes id_659 { id_658 };
      Pointer id_660 { let_res_624.writeBytes(id_659) };
      let_res_620 = id_660;
    }
    return let_res_620;
  }
   };
  return fun110;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $field_name; value: STRING}")
      (let "sz_416" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0)))
        (add (identifier "sz_416")
          (add
            (let "n_ref_418" (make-vec (string-length (get-field "value" (param 0))))
              (let "lebsz_ref_419" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_418")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_419")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_419") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_419")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_419")))))) 
            (size-of-u32 (string-length (get-field "value" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alert::constant> )> constant_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alert::constant> )> fun661 { [&fun661](std::shared_ptr<::dessser::gen::alert::constant>  p_0) {
    auto fun662 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_663 { (*p_0).name };
    Size id_664 { fun662(id_663) };
    Size let_res_665;
    {
      Size sz_416 { id_664 };
      std::string id_666 { (*p_0).value };
      uint32_t id_667 { (uint32_t)id_666.size() };
      Vec<1, uint32_t> id_668 {  id_667  };
      Size let_res_669;
      {
        Vec<1, uint32_t> n_ref_418 { id_668 };
        uint32_t id_670 { 1U };
        Vec<1, uint32_t> id_671 {  id_670  };
        Size let_res_672;
        {
          Vec<1, uint32_t> lebsz_ref_419 { id_671 };
          bool while_flag_673 { true };
          do {
            uint8_t id_674 { 0 };
            uint32_t id_675 { n_ref_418[id_674] };
            uint8_t id_676 { 0 };
            uint32_t id_677 { lebsz_ref_419[id_676] };
            uint8_t id_678 { 7 };
            uint32_t id_679 { uint32_t(id_677 << id_678) };
            bool id_680 { bool(id_675 >= id_679) };
            while_flag_673 = id_680;
            if (while_flag_673) {
              uint8_t id_681 { 0 };
              uint8_t id_682 { 0 };
              uint32_t id_683 { lebsz_ref_419[id_682] };
              uint32_t id_684 { 1U };
              uint32_t id_685 { uint32_t(id_683 + id_684) };
              Void id_686 { ((void)(lebsz_ref_419[id_681] = id_685), ::dessser::VOID) };
              (void)id_686;
            }
          } while (while_flag_673);
          (void)::dessser::VOID;
          uint8_t id_687 { 0 };
          uint32_t id_688 { lebsz_ref_419[id_687] };
          Size id_689 { Size(id_688) };
          let_res_672 = id_689;
        }
        let_res_669 = let_res_672;
      }
      std::string id_690 { (*p_0).value };
      uint32_t id_691 { (uint32_t)id_690.size() };
      Size id_692 { Size(id_691) };
      Size id_693 { Size(let_res_669 + id_692) };
      Size id_694 { Size(sz_416 + id_693) };
      let_res_665 = id_694;
    }
    return let_res_665;
  }
   };
  return fun661;
}
std::function<Size(std::shared_ptr<::dessser::gen::alert::constant> )> constant_sersize_of_row_binary(constant_sersize_of_row_binary_init());

/* 
    (fun ("[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]")
      (if (eq (u16 0) (label-of (param 0))) (size 10)
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (if (eq (u16 0) (label-of (get-field "max_distance" (get-alt "Baseline" (param 0))))) (size 44) (seq (assert (eq (label-of (get-field "max_distance" (get-alt "Baseline" (param 0)))) (u16 1))) (size 44))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alert::threshold> )> threshold_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alert::threshold> )> fun695 { [&fun695](std::shared_ptr<::dessser::gen::alert::threshold>  p_0) {
    uint16_t id_696 { 0 };
    uint16_t id_697 { uint16_t((*p_0).index()) };
    bool id_698 { bool(id_696 == id_697) };
    Size choose_res_699;
    if (id_698) {
      Size id_700 { 10UL };
      choose_res_699 = id_700;
    } else {
      uint16_t id_701 { uint16_t((*p_0).index()) };
      uint16_t id_702 { 1 };
      bool id_703 { bool(id_701 == id_702) };
      Void id_704 { ((void)(assert(id_703)), ::dessser::VOID) };
      (void)id_704;
      uint16_t id_705 { 0 };
      ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_706 { std::get<1 /* Baseline */>((*p_0)) };
      ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_707 { id_706.max_distance };
      uint16_t id_708 { uint16_t(id_707.index()) };
      bool id_709 { bool(id_705 == id_708) };
      Size choose_res_710;
      if (id_709) {
        Size id_711 { 44UL };
        choose_res_710 = id_711;
      } else {
        ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_712 { std::get<1 /* Baseline */>((*p_0)) };
        ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_713 { id_712.max_distance };
        uint16_t id_714 { uint16_t(id_713.index()) };
        uint16_t id_715 { 1 };
        bool id_716 { bool(id_714 == id_715) };
        Void id_717 { ((void)(assert(id_716)), ::dessser::VOID) };
        (void)id_717;
        Size id_718 { 44UL };
        choose_res_710 = id_718;
      }
      choose_res_699 = choose_res_710;
    }
    return choose_res_699;
  }
   };
  return fun695;
}
std::function<Size(std::shared_ptr<::dessser::gen::alert::threshold> )> threshold_sersize_of_row_binary(threshold_sersize_of_row_binary_init());

/* 
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[[]]; group-by: $field_name[[]]?; having: $simple_filter[[]]; threshold: (threshold AS [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]); hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[[]]; carry-fields: $field_name[[]]; carry-csts: (constant AS {name: $field_name; value: STRING})[[]]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}")
      (let "sz_470"
        (let "sz_466"
          (let "sz_462"
            (let "sz_458"
              (let "sz_453"
                (let "sz_448"
                  (let "sz_443"
                    (add
                      (add
                        (add
                          (add
                            (let "sz_438"
                              (let "sz_433"
                                (let "sz_428"
                                  (let "sz_423"
                                    (add
                                      (let "sz_421" (apply (ext-identifier fq_name sersize-of-row-binary) (get-field "table" (param 0)))
                                        (add (identifier "sz_421") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "column" (param 0))))) 
                                      (size 1))
                                    (let "sz_ref_426"
                                      (make-vec
                                        (add (identifier "sz_423")
                                          (let "n_ref_424" (make-vec (cardinality (get-field "where" (param 0))))
                                            (let "lebsz_ref_425" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_424")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_425")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_425") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_425")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_425"))))))))
                                      (seq
                                        (let "repeat_n_427" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (get-field "where" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_427")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_426")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_426"))
                                                  (apply (ext-identifier simple_filter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_427")) (get-field "where" (param 0))))))
                                              (set-vec (u8 0) (identifier "repeat_n_427") (add (unsafe-nth (u8 0) (identifier "repeat_n_427")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_426")))))
                                  (if (is-null (get-field "group-by" (param 0))) 
                                    (add (identifier "sz_428") (size 1))
                                    (add
                                      (let "sz_ref_431"
                                        (make-vec
                                          (add (identifier "sz_428")
                                            (let "n_ref_429" (make-vec (cardinality (force (get-field "group-by" (param 0)))))
                                              (let "lebsz_ref_430" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_429")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_430")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_430") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_430")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_430"))))))))
                                        (seq
                                          (let "repeat_n_432" (make-vec (i32 0))
                                            (while (gt (to-i32 (cardinality (force (get-field "group-by" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_432")))
                                              (seq
                                                (set-vec (u8 0) (identifier "sz_ref_431")
                                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_431"))
                                                    (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_432")) (force (get-field "group-by" (param 0)))))))
                                                (set-vec (u8 0) (identifier "repeat_n_432") (add (unsafe-nth (u8 0) (identifier "repeat_n_432")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "sz_ref_431")))) 
                                      (size 1))))
                                (let "sz_ref_436"
                                  (make-vec
                                    (add (identifier "sz_433")
                                      (let "n_ref_434" (make-vec (cardinality (get-field "having" (param 0))))
                                        (let "lebsz_ref_435" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_434")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_435")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_435") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_435")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_435"))))))))
                                  (seq
                                    (let "repeat_n_437" (make-vec (i32 0))
                                      (while (gt (to-i32 (cardinality (get-field "having" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_437")))
                                        (seq
                                          (set-vec (u8 0) (identifier "sz_ref_436")
                                            (add (unsafe-nth (u8 0) (identifier "sz_ref_436"))
                                              (apply (ext-identifier simple_filter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_437")) (get-field "having" (param 0))))))
                                          (set-vec (u8 0) (identifier "repeat_n_437") (add (unsafe-nth (u8 0) (identifier "repeat_n_437")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "sz_ref_436"))))) 
                              (add (identifier "sz_438") (apply (identifier "threshold-sersize-of-row-binary") (get-field "threshold" (param 0))))) 
                            (size 8)) (size 8)) (size 8)) (size 8))
                    (let "sz_ref_446"
                      (make-vec
                        (add (identifier "sz_443")
                          (let "n_ref_444" (make-vec (cardinality (get-field "tops" (param 0))))
                            (let "lebsz_ref_445" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_444")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_445")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_445") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_445")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_445"))))))))
                      (seq
                        (let "repeat_n_447" (make-vec (i32 0))
                          (while (gt (to-i32 (cardinality (get-field "tops" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_447")))
                            (seq
                              (set-vec (u8 0) (identifier "sz_ref_446")
                                (add (unsafe-nth (u8 0) (identifier "sz_ref_446"))
                                  (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_447")) (get-field "tops" (param 0))))))
                              (set-vec (u8 0) (identifier "repeat_n_447") (add (unsafe-nth (u8 0) (identifier "repeat_n_447")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "sz_ref_446")))))
                  (let "sz_ref_451"
                    (make-vec
                      (add (identifier "sz_448")
                        (let "n_ref_449" (make-vec (cardinality (get-field "carry-fields" (param 0))))
                          (let "lebsz_ref_450" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_449")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_450")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_450") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_450")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_450"))))))))
                    (seq
                      (let "repeat_n_452" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-field "carry-fields" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_452")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_451")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_451"))
                                (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_452")) (get-field "carry-fields" (param 0))))))
                            (set-vec (u8 0) (identifier "repeat_n_452") (add (unsafe-nth (u8 0) (identifier "repeat_n_452")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_451")))))
                (let "sz_ref_456"
                  (make-vec
                    (add (identifier "sz_453")
                      (let "n_ref_454" (make-vec (cardinality (get-field "carry-csts" (param 0))))
                        (let "lebsz_ref_455" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_454")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_455")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_455") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_455")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_455"))))))))
                  (seq
                    (let "repeat_n_457" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "carry-csts" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_457")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_456")
                            (add (unsafe-nth (u8 0) (identifier "sz_ref_456")) (apply (identifier "constant-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_457")) (get-field "carry-csts" (param 0))))))
                          (set-vec (u8 0) (identifier "repeat_n_457") (add (unsafe-nth (u8 0) (identifier "repeat_n_457")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_456")))))
              (add (identifier "sz_458")
                (add
                  (let "n_ref_460" (make-vec (string-length (get-field "id" (param 0))))
                    (let "lebsz_ref_461" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_460")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_461")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_461") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_461")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_461")))))) 
                  (size-of-u32 (string-length (get-field "id" (param 0)))))))
            (add (identifier "sz_462")
              (add
                (let "n_ref_464" (make-vec (string-length (get-field "desc-title" (param 0))))
                  (let "lebsz_ref_465" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_464")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_465")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_465") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_465")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_465")))))) 
                (size-of-u32 (string-length (get-field "desc-title" (param 0)))))))
          (add (identifier "sz_466")
            (add
              (let "n_ref_468" (make-vec (string-length (get-field "desc-firing" (param 0))))
                (let "lebsz_ref_469" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_468")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_469")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_469") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_469")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_469")))))) 
              (size-of-u32 (string-length (get-field "desc-firing" (param 0)))))))
        (add (identifier "sz_470")
          (add
            (let "n_ref_472" (make-vec (string-length (get-field "desc-recovery" (param 0))))
              (let "lebsz_ref_473" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_472")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_473")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_473") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_473")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_473")))))) 
            (size-of-u32 (string-length (get-field "desc-recovery" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alert::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alert::t> )> fun719 { [&fun719](std::shared_ptr<::dessser::gen::alert::t>  p_0) {
    auto fun720 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_721 { (*p_0).table };
    Size id_722 { fun720(id_721) };
    Size let_res_723;
    {
      Size sz_421 { id_722 };
      auto fun724 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_725 { (*p_0).column };
      Size id_726 { fun724(id_725) };
      Size id_727 { Size(sz_421 + id_726) };
      let_res_723 = id_727;
    }
    Size id_728 { 1UL };
    Size id_729 { Size(let_res_723 + id_728) };
    Size let_res_730;
    {
      Size sz_423 { id_729 };
      Lst<dessser::gen::simple_filter::t_ext> id_731 { (*p_0).where };
      uint32_t id_732 { id_731.size() };
      Vec<1, uint32_t> id_733 {  id_732  };
      Size let_res_734;
      {
        Vec<1, uint32_t> n_ref_424 { id_733 };
        uint32_t id_735 { 1U };
        Vec<1, uint32_t> id_736 {  id_735  };
        Size let_res_737;
        {
          Vec<1, uint32_t> lebsz_ref_425 { id_736 };
          bool while_flag_738 { true };
          do {
            uint8_t id_739 { 0 };
            uint32_t id_740 { n_ref_424[id_739] };
            uint8_t id_741 { 0 };
            uint32_t id_742 { lebsz_ref_425[id_741] };
            uint8_t id_743 { 7 };
            uint32_t id_744 { uint32_t(id_742 << id_743) };
            bool id_745 { bool(id_740 >= id_744) };
            while_flag_738 = id_745;
            if (while_flag_738) {
              uint8_t id_746 { 0 };
              uint8_t id_747 { 0 };
              uint32_t id_748 { lebsz_ref_425[id_747] };
              uint32_t id_749 { 1U };
              uint32_t id_750 { uint32_t(id_748 + id_749) };
              Void id_751 { ((void)(lebsz_ref_425[id_746] = id_750), ::dessser::VOID) };
              (void)id_751;
            }
          } while (while_flag_738);
          (void)::dessser::VOID;
          uint8_t id_752 { 0 };
          uint32_t id_753 { lebsz_ref_425[id_752] };
          Size id_754 { Size(id_753) };
          let_res_737 = id_754;
        }
        let_res_734 = let_res_737;
      }
      Size id_755 { Size(sz_423 + let_res_734) };
      Vec<1, Size> id_756 {  id_755  };
      Size let_res_757;
      {
        Vec<1, Size> sz_ref_426 { id_756 };
        int32_t id_758 { 0L };
        Vec<1, int32_t> id_759 {  id_758  };
        {
          Vec<1, int32_t> repeat_n_427 { id_759 };
          bool while_flag_760 { true };
          do {
            Lst<dessser::gen::simple_filter::t_ext> id_761 { (*p_0).where };
            uint32_t id_762 { id_761.size() };
            int32_t id_763 { int32_t(id_762) };
            uint8_t id_764 { 0 };
            int32_t id_765 { repeat_n_427[id_764] };
            bool id_766 { bool(id_763 > id_765) };
            while_flag_760 = id_766;
            if (while_flag_760) {
              uint8_t id_767 { 0 };
              uint8_t id_768 { 0 };
              Size id_769 { sz_ref_426[id_768] };
              auto fun770 { dessser::gen::simple_filter::sersize_of_row_binary };
              uint8_t id_771 { 0 };
              int32_t id_772 { repeat_n_427[id_771] };
              Lst<dessser::gen::simple_filter::t_ext> id_773 { (*p_0).where };
              dessser::gen::simple_filter::t_ext id_774 { id_773[id_772] };
              Size id_775 { fun770(id_774) };
              Size id_776 { Size(id_769 + id_775) };
              Void id_777 { ((void)(sz_ref_426[id_767] = id_776), ::dessser::VOID) };
              (void)id_777;
              uint8_t id_778 { 0 };
              uint8_t id_779 { 0 };
              int32_t id_780 { repeat_n_427[id_779] };
              int32_t id_781 { 1L };
              int32_t id_782 { int32_t(id_780 + id_781) };
              Void id_783 { ((void)(repeat_n_427[id_778] = id_782), ::dessser::VOID) };
              (void)id_783;
              (void)id_783;
            }
          } while (while_flag_760);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_784 { 0 };
        Size id_785 { sz_ref_426[id_784] };
        let_res_757 = id_785;
      }
      let_res_730 = let_res_757;
    }
    Size let_res_786;
    {
      Size sz_428 { let_res_730 };
      std::optional<Lst<dessser::gen::field_name::t_ext>> id_787 { (*p_0).group_by };
      bool id_788 { !(id_787.has_value ()) };
      Size choose_res_789;
      if (id_788) {
        Size id_790 { 1UL };
        Size id_791 { Size(sz_428 + id_790) };
        choose_res_789 = id_791;
      } else {
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_792 { (*p_0).group_by };
        Lst<dessser::gen::field_name::t_ext> id_793 { id_792.value() };
        uint32_t id_794 { id_793.size() };
        Vec<1, uint32_t> id_795 {  id_794  };
        Size let_res_796;
        {
          Vec<1, uint32_t> n_ref_429 { id_795 };
          uint32_t id_797 { 1U };
          Vec<1, uint32_t> id_798 {  id_797  };
          Size let_res_799;
          {
            Vec<1, uint32_t> lebsz_ref_430 { id_798 };
            bool while_flag_800 { true };
            do {
              uint8_t id_801 { 0 };
              uint32_t id_802 { n_ref_429[id_801] };
              uint8_t id_803 { 0 };
              uint32_t id_804 { lebsz_ref_430[id_803] };
              uint8_t id_805 { 7 };
              uint32_t id_806 { uint32_t(id_804 << id_805) };
              bool id_807 { bool(id_802 >= id_806) };
              while_flag_800 = id_807;
              if (while_flag_800) {
                uint8_t id_808 { 0 };
                uint8_t id_809 { 0 };
                uint32_t id_810 { lebsz_ref_430[id_809] };
                uint32_t id_811 { 1U };
                uint32_t id_812 { uint32_t(id_810 + id_811) };
                Void id_813 { ((void)(lebsz_ref_430[id_808] = id_812), ::dessser::VOID) };
                (void)id_813;
              }
            } while (while_flag_800);
            (void)::dessser::VOID;
            uint8_t id_814 { 0 };
            uint32_t id_815 { lebsz_ref_430[id_814] };
            Size id_816 { Size(id_815) };
            let_res_799 = id_816;
          }
          let_res_796 = let_res_799;
        }
        Size id_817 { Size(sz_428 + let_res_796) };
        Vec<1, Size> id_818 {  id_817  };
        Size let_res_819;
        {
          Vec<1, Size> sz_ref_431 { id_818 };
          int32_t id_820 { 0L };
          Vec<1, int32_t> id_821 {  id_820  };
          {
            Vec<1, int32_t> repeat_n_432 { id_821 };
            bool while_flag_822 { true };
            do {
              std::optional<Lst<dessser::gen::field_name::t_ext>> id_823 { (*p_0).group_by };
              Lst<dessser::gen::field_name::t_ext> id_824 { id_823.value() };
              uint32_t id_825 { id_824.size() };
              int32_t id_826 { int32_t(id_825) };
              uint8_t id_827 { 0 };
              int32_t id_828 { repeat_n_432[id_827] };
              bool id_829 { bool(id_826 > id_828) };
              while_flag_822 = id_829;
              if (while_flag_822) {
                uint8_t id_830 { 0 };
                uint8_t id_831 { 0 };
                Size id_832 { sz_ref_431[id_831] };
                auto fun833 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_834 { 0 };
                int32_t id_835 { repeat_n_432[id_834] };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_836 { (*p_0).group_by };
                Lst<dessser::gen::field_name::t_ext> id_837 { id_836.value() };
                dessser::gen::field_name::t_ext id_838 { id_837[id_835] };
                Size id_839 { fun833(id_838) };
                Size id_840 { Size(id_832 + id_839) };
                Void id_841 { ((void)(sz_ref_431[id_830] = id_840), ::dessser::VOID) };
                (void)id_841;
                uint8_t id_842 { 0 };
                uint8_t id_843 { 0 };
                int32_t id_844 { repeat_n_432[id_843] };
                int32_t id_845 { 1L };
                int32_t id_846 { int32_t(id_844 + id_845) };
                Void id_847 { ((void)(repeat_n_432[id_842] = id_846), ::dessser::VOID) };
                (void)id_847;
                (void)id_847;
              }
            } while (while_flag_822);
            (void)::dessser::VOID;
          }
          (void)::dessser::VOID;
          uint8_t id_848 { 0 };
          Size id_849 { sz_ref_431[id_848] };
          let_res_819 = id_849;
        }
        Size id_850 { 1UL };
        Size id_851 { Size(let_res_819 + id_850) };
        choose_res_789 = id_851;
      }
      let_res_786 = choose_res_789;
    }
    Size let_res_852;
    {
      Size sz_433 { let_res_786 };
      Lst<dessser::gen::simple_filter::t_ext> id_853 { (*p_0).having };
      uint32_t id_854 { id_853.size() };
      Vec<1, uint32_t> id_855 {  id_854  };
      Size let_res_856;
      {
        Vec<1, uint32_t> n_ref_434 { id_855 };
        uint32_t id_857 { 1U };
        Vec<1, uint32_t> id_858 {  id_857  };
        Size let_res_859;
        {
          Vec<1, uint32_t> lebsz_ref_435 { id_858 };
          bool while_flag_860 { true };
          do {
            uint8_t id_861 { 0 };
            uint32_t id_862 { n_ref_434[id_861] };
            uint8_t id_863 { 0 };
            uint32_t id_864 { lebsz_ref_435[id_863] };
            uint8_t id_865 { 7 };
            uint32_t id_866 { uint32_t(id_864 << id_865) };
            bool id_867 { bool(id_862 >= id_866) };
            while_flag_860 = id_867;
            if (while_flag_860) {
              uint8_t id_868 { 0 };
              uint8_t id_869 { 0 };
              uint32_t id_870 { lebsz_ref_435[id_869] };
              uint32_t id_871 { 1U };
              uint32_t id_872 { uint32_t(id_870 + id_871) };
              Void id_873 { ((void)(lebsz_ref_435[id_868] = id_872), ::dessser::VOID) };
              (void)id_873;
            }
          } while (while_flag_860);
          (void)::dessser::VOID;
          uint8_t id_874 { 0 };
          uint32_t id_875 { lebsz_ref_435[id_874] };
          Size id_876 { Size(id_875) };
          let_res_859 = id_876;
        }
        let_res_856 = let_res_859;
      }
      Size id_877 { Size(sz_433 + let_res_856) };
      Vec<1, Size> id_878 {  id_877  };
      Size let_res_879;
      {
        Vec<1, Size> sz_ref_436 { id_878 };
        int32_t id_880 { 0L };
        Vec<1, int32_t> id_881 {  id_880  };
        {
          Vec<1, int32_t> repeat_n_437 { id_881 };
          bool while_flag_882 { true };
          do {
            Lst<dessser::gen::simple_filter::t_ext> id_883 { (*p_0).having };
            uint32_t id_884 { id_883.size() };
            int32_t id_885 { int32_t(id_884) };
            uint8_t id_886 { 0 };
            int32_t id_887 { repeat_n_437[id_886] };
            bool id_888 { bool(id_885 > id_887) };
            while_flag_882 = id_888;
            if (while_flag_882) {
              uint8_t id_889 { 0 };
              uint8_t id_890 { 0 };
              Size id_891 { sz_ref_436[id_890] };
              auto fun892 { dessser::gen::simple_filter::sersize_of_row_binary };
              uint8_t id_893 { 0 };
              int32_t id_894 { repeat_n_437[id_893] };
              Lst<dessser::gen::simple_filter::t_ext> id_895 { (*p_0).having };
              dessser::gen::simple_filter::t_ext id_896 { id_895[id_894] };
              Size id_897 { fun892(id_896) };
              Size id_898 { Size(id_891 + id_897) };
              Void id_899 { ((void)(sz_ref_436[id_889] = id_898), ::dessser::VOID) };
              (void)id_899;
              uint8_t id_900 { 0 };
              uint8_t id_901 { 0 };
              int32_t id_902 { repeat_n_437[id_901] };
              int32_t id_903 { 1L };
              int32_t id_904 { int32_t(id_902 + id_903) };
              Void id_905 { ((void)(repeat_n_437[id_900] = id_904), ::dessser::VOID) };
              (void)id_905;
              (void)id_905;
            }
          } while (while_flag_882);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_906 { 0 };
        Size id_907 { sz_ref_436[id_906] };
        let_res_879 = id_907;
      }
      let_res_852 = let_res_879;
    }
    Size let_res_908;
    {
      Size sz_438 { let_res_852 };
      std::shared_ptr<::dessser::gen::alert::threshold>  id_909 { (*p_0).threshold };
      Size id_910 { threshold_sersize_of_row_binary(id_909) };
      Size id_911 { Size(sz_438 + id_910) };
      let_res_908 = id_911;
    }
    Size id_912 { 8UL };
    Size id_913 { Size(let_res_908 + id_912) };
    Size id_914 { 8UL };
    Size id_915 { Size(id_913 + id_914) };
    Size id_916 { 8UL };
    Size id_917 { Size(id_915 + id_916) };
    Size id_918 { 8UL };
    Size id_919 { Size(id_917 + id_918) };
    Size let_res_920;
    {
      Size sz_443 { id_919 };
      Lst<dessser::gen::field_name::t_ext> id_921 { (*p_0).tops };
      uint32_t id_922 { id_921.size() };
      Vec<1, uint32_t> id_923 {  id_922  };
      Size let_res_924;
      {
        Vec<1, uint32_t> n_ref_444 { id_923 };
        uint32_t id_925 { 1U };
        Vec<1, uint32_t> id_926 {  id_925  };
        Size let_res_927;
        {
          Vec<1, uint32_t> lebsz_ref_445 { id_926 };
          bool while_flag_928 { true };
          do {
            uint8_t id_929 { 0 };
            uint32_t id_930 { n_ref_444[id_929] };
            uint8_t id_931 { 0 };
            uint32_t id_932 { lebsz_ref_445[id_931] };
            uint8_t id_933 { 7 };
            uint32_t id_934 { uint32_t(id_932 << id_933) };
            bool id_935 { bool(id_930 >= id_934) };
            while_flag_928 = id_935;
            if (while_flag_928) {
              uint8_t id_936 { 0 };
              uint8_t id_937 { 0 };
              uint32_t id_938 { lebsz_ref_445[id_937] };
              uint32_t id_939 { 1U };
              uint32_t id_940 { uint32_t(id_938 + id_939) };
              Void id_941 { ((void)(lebsz_ref_445[id_936] = id_940), ::dessser::VOID) };
              (void)id_941;
            }
          } while (while_flag_928);
          (void)::dessser::VOID;
          uint8_t id_942 { 0 };
          uint32_t id_943 { lebsz_ref_445[id_942] };
          Size id_944 { Size(id_943) };
          let_res_927 = id_944;
        }
        let_res_924 = let_res_927;
      }
      Size id_945 { Size(sz_443 + let_res_924) };
      Vec<1, Size> id_946 {  id_945  };
      Size let_res_947;
      {
        Vec<1, Size> sz_ref_446 { id_946 };
        int32_t id_948 { 0L };
        Vec<1, int32_t> id_949 {  id_948  };
        {
          Vec<1, int32_t> repeat_n_447 { id_949 };
          bool while_flag_950 { true };
          do {
            Lst<dessser::gen::field_name::t_ext> id_951 { (*p_0).tops };
            uint32_t id_952 { id_951.size() };
            int32_t id_953 { int32_t(id_952) };
            uint8_t id_954 { 0 };
            int32_t id_955 { repeat_n_447[id_954] };
            bool id_956 { bool(id_953 > id_955) };
            while_flag_950 = id_956;
            if (while_flag_950) {
              uint8_t id_957 { 0 };
              uint8_t id_958 { 0 };
              Size id_959 { sz_ref_446[id_958] };
              auto fun960 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_961 { 0 };
              int32_t id_962 { repeat_n_447[id_961] };
              Lst<dessser::gen::field_name::t_ext> id_963 { (*p_0).tops };
              dessser::gen::field_name::t_ext id_964 { id_963[id_962] };
              Size id_965 { fun960(id_964) };
              Size id_966 { Size(id_959 + id_965) };
              Void id_967 { ((void)(sz_ref_446[id_957] = id_966), ::dessser::VOID) };
              (void)id_967;
              uint8_t id_968 { 0 };
              uint8_t id_969 { 0 };
              int32_t id_970 { repeat_n_447[id_969] };
              int32_t id_971 { 1L };
              int32_t id_972 { int32_t(id_970 + id_971) };
              Void id_973 { ((void)(repeat_n_447[id_968] = id_972), ::dessser::VOID) };
              (void)id_973;
              (void)id_973;
            }
          } while (while_flag_950);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_974 { 0 };
        Size id_975 { sz_ref_446[id_974] };
        let_res_947 = id_975;
      }
      let_res_920 = let_res_947;
    }
    Size let_res_976;
    {
      Size sz_448 { let_res_920 };
      Lst<dessser::gen::field_name::t_ext> id_977 { (*p_0).carry_fields };
      uint32_t id_978 { id_977.size() };
      Vec<1, uint32_t> id_979 {  id_978  };
      Size let_res_980;
      {
        Vec<1, uint32_t> n_ref_449 { id_979 };
        uint32_t id_981 { 1U };
        Vec<1, uint32_t> id_982 {  id_981  };
        Size let_res_983;
        {
          Vec<1, uint32_t> lebsz_ref_450 { id_982 };
          bool while_flag_984 { true };
          do {
            uint8_t id_985 { 0 };
            uint32_t id_986 { n_ref_449[id_985] };
            uint8_t id_987 { 0 };
            uint32_t id_988 { lebsz_ref_450[id_987] };
            uint8_t id_989 { 7 };
            uint32_t id_990 { uint32_t(id_988 << id_989) };
            bool id_991 { bool(id_986 >= id_990) };
            while_flag_984 = id_991;
            if (while_flag_984) {
              uint8_t id_992 { 0 };
              uint8_t id_993 { 0 };
              uint32_t id_994 { lebsz_ref_450[id_993] };
              uint32_t id_995 { 1U };
              uint32_t id_996 { uint32_t(id_994 + id_995) };
              Void id_997 { ((void)(lebsz_ref_450[id_992] = id_996), ::dessser::VOID) };
              (void)id_997;
            }
          } while (while_flag_984);
          (void)::dessser::VOID;
          uint8_t id_998 { 0 };
          uint32_t id_999 { lebsz_ref_450[id_998] };
          Size id_1000 { Size(id_999) };
          let_res_983 = id_1000;
        }
        let_res_980 = let_res_983;
      }
      Size id_1001 { Size(sz_448 + let_res_980) };
      Vec<1, Size> id_1002 {  id_1001  };
      Size let_res_1003;
      {
        Vec<1, Size> sz_ref_451 { id_1002 };
        int32_t id_1004 { 0L };
        Vec<1, int32_t> id_1005 {  id_1004  };
        {
          Vec<1, int32_t> repeat_n_452 { id_1005 };
          bool while_flag_1006 { true };
          do {
            Lst<dessser::gen::field_name::t_ext> id_1007 { (*p_0).carry_fields };
            uint32_t id_1008 { id_1007.size() };
            int32_t id_1009 { int32_t(id_1008) };
            uint8_t id_1010 { 0 };
            int32_t id_1011 { repeat_n_452[id_1010] };
            bool id_1012 { bool(id_1009 > id_1011) };
            while_flag_1006 = id_1012;
            if (while_flag_1006) {
              uint8_t id_1013 { 0 };
              uint8_t id_1014 { 0 };
              Size id_1015 { sz_ref_451[id_1014] };
              auto fun1016 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_1017 { 0 };
              int32_t id_1018 { repeat_n_452[id_1017] };
              Lst<dessser::gen::field_name::t_ext> id_1019 { (*p_0).carry_fields };
              dessser::gen::field_name::t_ext id_1020 { id_1019[id_1018] };
              Size id_1021 { fun1016(id_1020) };
              Size id_1022 { Size(id_1015 + id_1021) };
              Void id_1023 { ((void)(sz_ref_451[id_1013] = id_1022), ::dessser::VOID) };
              (void)id_1023;
              uint8_t id_1024 { 0 };
              uint8_t id_1025 { 0 };
              int32_t id_1026 { repeat_n_452[id_1025] };
              int32_t id_1027 { 1L };
              int32_t id_1028 { int32_t(id_1026 + id_1027) };
              Void id_1029 { ((void)(repeat_n_452[id_1024] = id_1028), ::dessser::VOID) };
              (void)id_1029;
              (void)id_1029;
            }
          } while (while_flag_1006);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_1030 { 0 };
        Size id_1031 { sz_ref_451[id_1030] };
        let_res_1003 = id_1031;
      }
      let_res_976 = let_res_1003;
    }
    Size let_res_1032;
    {
      Size sz_453 { let_res_976 };
      Lst<std::shared_ptr<::dessser::gen::alert::constant> > id_1033 { (*p_0).carry_csts };
      uint32_t id_1034 { id_1033.size() };
      Vec<1, uint32_t> id_1035 {  id_1034  };
      Size let_res_1036;
      {
        Vec<1, uint32_t> n_ref_454 { id_1035 };
        uint32_t id_1037 { 1U };
        Vec<1, uint32_t> id_1038 {  id_1037  };
        Size let_res_1039;
        {
          Vec<1, uint32_t> lebsz_ref_455 { id_1038 };
          bool while_flag_1040 { true };
          do {
            uint8_t id_1041 { 0 };
            uint32_t id_1042 { n_ref_454[id_1041] };
            uint8_t id_1043 { 0 };
            uint32_t id_1044 { lebsz_ref_455[id_1043] };
            uint8_t id_1045 { 7 };
            uint32_t id_1046 { uint32_t(id_1044 << id_1045) };
            bool id_1047 { bool(id_1042 >= id_1046) };
            while_flag_1040 = id_1047;
            if (while_flag_1040) {
              uint8_t id_1048 { 0 };
              uint8_t id_1049 { 0 };
              uint32_t id_1050 { lebsz_ref_455[id_1049] };
              uint32_t id_1051 { 1U };
              uint32_t id_1052 { uint32_t(id_1050 + id_1051) };
              Void id_1053 { ((void)(lebsz_ref_455[id_1048] = id_1052), ::dessser::VOID) };
              (void)id_1053;
            }
          } while (while_flag_1040);
          (void)::dessser::VOID;
          uint8_t id_1054 { 0 };
          uint32_t id_1055 { lebsz_ref_455[id_1054] };
          Size id_1056 { Size(id_1055) };
          let_res_1039 = id_1056;
        }
        let_res_1036 = let_res_1039;
      }
      Size id_1057 { Size(sz_453 + let_res_1036) };
      Vec<1, Size> id_1058 {  id_1057  };
      Size let_res_1059;
      {
        Vec<1, Size> sz_ref_456 { id_1058 };
        int32_t id_1060 { 0L };
        Vec<1, int32_t> id_1061 {  id_1060  };
        {
          Vec<1, int32_t> repeat_n_457 { id_1061 };
          bool while_flag_1062 { true };
          do {
            Lst<std::shared_ptr<::dessser::gen::alert::constant> > id_1063 { (*p_0).carry_csts };
            uint32_t id_1064 { id_1063.size() };
            int32_t id_1065 { int32_t(id_1064) };
            uint8_t id_1066 { 0 };
            int32_t id_1067 { repeat_n_457[id_1066] };
            bool id_1068 { bool(id_1065 > id_1067) };
            while_flag_1062 = id_1068;
            if (while_flag_1062) {
              uint8_t id_1069 { 0 };
              uint8_t id_1070 { 0 };
              Size id_1071 { sz_ref_456[id_1070] };
              uint8_t id_1072 { 0 };
              int32_t id_1073 { repeat_n_457[id_1072] };
              Lst<std::shared_ptr<::dessser::gen::alert::constant> > id_1074 { (*p_0).carry_csts };
              std::shared_ptr<::dessser::gen::alert::constant>  id_1075 { id_1074[id_1073] };
              Size id_1076 { constant_sersize_of_row_binary(id_1075) };
              Size id_1077 { Size(id_1071 + id_1076) };
              Void id_1078 { ((void)(sz_ref_456[id_1069] = id_1077), ::dessser::VOID) };
              (void)id_1078;
              uint8_t id_1079 { 0 };
              uint8_t id_1080 { 0 };
              int32_t id_1081 { repeat_n_457[id_1080] };
              int32_t id_1082 { 1L };
              int32_t id_1083 { int32_t(id_1081 + id_1082) };
              Void id_1084 { ((void)(repeat_n_457[id_1079] = id_1083), ::dessser::VOID) };
              (void)id_1084;
              (void)id_1084;
            }
          } while (while_flag_1062);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_1085 { 0 };
        Size id_1086 { sz_ref_456[id_1085] };
        let_res_1059 = id_1086;
      }
      let_res_1032 = let_res_1059;
    }
    Size let_res_1087;
    {
      Size sz_458 { let_res_1032 };
      std::string id_1088 { (*p_0).id };
      uint32_t id_1089 { (uint32_t)id_1088.size() };
      Vec<1, uint32_t> id_1090 {  id_1089  };
      Size let_res_1091;
      {
        Vec<1, uint32_t> n_ref_460 { id_1090 };
        uint32_t id_1092 { 1U };
        Vec<1, uint32_t> id_1093 {  id_1092  };
        Size let_res_1094;
        {
          Vec<1, uint32_t> lebsz_ref_461 { id_1093 };
          bool while_flag_1095 { true };
          do {
            uint8_t id_1096 { 0 };
            uint32_t id_1097 { n_ref_460[id_1096] };
            uint8_t id_1098 { 0 };
            uint32_t id_1099 { lebsz_ref_461[id_1098] };
            uint8_t id_1100 { 7 };
            uint32_t id_1101 { uint32_t(id_1099 << id_1100) };
            bool id_1102 { bool(id_1097 >= id_1101) };
            while_flag_1095 = id_1102;
            if (while_flag_1095) {
              uint8_t id_1103 { 0 };
              uint8_t id_1104 { 0 };
              uint32_t id_1105 { lebsz_ref_461[id_1104] };
              uint32_t id_1106 { 1U };
              uint32_t id_1107 { uint32_t(id_1105 + id_1106) };
              Void id_1108 { ((void)(lebsz_ref_461[id_1103] = id_1107), ::dessser::VOID) };
              (void)id_1108;
            }
          } while (while_flag_1095);
          (void)::dessser::VOID;
          uint8_t id_1109 { 0 };
          uint32_t id_1110 { lebsz_ref_461[id_1109] };
          Size id_1111 { Size(id_1110) };
          let_res_1094 = id_1111;
        }
        let_res_1091 = let_res_1094;
      }
      std::string id_1112 { (*p_0).id };
      uint32_t id_1113 { (uint32_t)id_1112.size() };
      Size id_1114 { Size(id_1113) };
      Size id_1115 { Size(let_res_1091 + id_1114) };
      Size id_1116 { Size(sz_458 + id_1115) };
      let_res_1087 = id_1116;
    }
    Size let_res_1117;
    {
      Size sz_462 { let_res_1087 };
      std::string id_1118 { (*p_0).desc_title };
      uint32_t id_1119 { (uint32_t)id_1118.size() };
      Vec<1, uint32_t> id_1120 {  id_1119  };
      Size let_res_1121;
      {
        Vec<1, uint32_t> n_ref_464 { id_1120 };
        uint32_t id_1122 { 1U };
        Vec<1, uint32_t> id_1123 {  id_1122  };
        Size let_res_1124;
        {
          Vec<1, uint32_t> lebsz_ref_465 { id_1123 };
          bool while_flag_1125 { true };
          do {
            uint8_t id_1126 { 0 };
            uint32_t id_1127 { n_ref_464[id_1126] };
            uint8_t id_1128 { 0 };
            uint32_t id_1129 { lebsz_ref_465[id_1128] };
            uint8_t id_1130 { 7 };
            uint32_t id_1131 { uint32_t(id_1129 << id_1130) };
            bool id_1132 { bool(id_1127 >= id_1131) };
            while_flag_1125 = id_1132;
            if (while_flag_1125) {
              uint8_t id_1133 { 0 };
              uint8_t id_1134 { 0 };
              uint32_t id_1135 { lebsz_ref_465[id_1134] };
              uint32_t id_1136 { 1U };
              uint32_t id_1137 { uint32_t(id_1135 + id_1136) };
              Void id_1138 { ((void)(lebsz_ref_465[id_1133] = id_1137), ::dessser::VOID) };
              (void)id_1138;
            }
          } while (while_flag_1125);
          (void)::dessser::VOID;
          uint8_t id_1139 { 0 };
          uint32_t id_1140 { lebsz_ref_465[id_1139] };
          Size id_1141 { Size(id_1140) };
          let_res_1124 = id_1141;
        }
        let_res_1121 = let_res_1124;
      }
      std::string id_1142 { (*p_0).desc_title };
      uint32_t id_1143 { (uint32_t)id_1142.size() };
      Size id_1144 { Size(id_1143) };
      Size id_1145 { Size(let_res_1121 + id_1144) };
      Size id_1146 { Size(sz_462 + id_1145) };
      let_res_1117 = id_1146;
    }
    Size let_res_1147;
    {
      Size sz_466 { let_res_1117 };
      std::string id_1148 { (*p_0).desc_firing };
      uint32_t id_1149 { (uint32_t)id_1148.size() };
      Vec<1, uint32_t> id_1150 {  id_1149  };
      Size let_res_1151;
      {
        Vec<1, uint32_t> n_ref_468 { id_1150 };
        uint32_t id_1152 { 1U };
        Vec<1, uint32_t> id_1153 {  id_1152  };
        Size let_res_1154;
        {
          Vec<1, uint32_t> lebsz_ref_469 { id_1153 };
          bool while_flag_1155 { true };
          do {
            uint8_t id_1156 { 0 };
            uint32_t id_1157 { n_ref_468[id_1156] };
            uint8_t id_1158 { 0 };
            uint32_t id_1159 { lebsz_ref_469[id_1158] };
            uint8_t id_1160 { 7 };
            uint32_t id_1161 { uint32_t(id_1159 << id_1160) };
            bool id_1162 { bool(id_1157 >= id_1161) };
            while_flag_1155 = id_1162;
            if (while_flag_1155) {
              uint8_t id_1163 { 0 };
              uint8_t id_1164 { 0 };
              uint32_t id_1165 { lebsz_ref_469[id_1164] };
              uint32_t id_1166 { 1U };
              uint32_t id_1167 { uint32_t(id_1165 + id_1166) };
              Void id_1168 { ((void)(lebsz_ref_469[id_1163] = id_1167), ::dessser::VOID) };
              (void)id_1168;
            }
          } while (while_flag_1155);
          (void)::dessser::VOID;
          uint8_t id_1169 { 0 };
          uint32_t id_1170 { lebsz_ref_469[id_1169] };
          Size id_1171 { Size(id_1170) };
          let_res_1154 = id_1171;
        }
        let_res_1151 = let_res_1154;
      }
      std::string id_1172 { (*p_0).desc_firing };
      uint32_t id_1173 { (uint32_t)id_1172.size() };
      Size id_1174 { Size(id_1173) };
      Size id_1175 { Size(let_res_1151 + id_1174) };
      Size id_1176 { Size(sz_466 + id_1175) };
      let_res_1147 = id_1176;
    }
    Size let_res_1177;
    {
      Size sz_470 { let_res_1147 };
      std::string id_1178 { (*p_0).desc_recovery };
      uint32_t id_1179 { (uint32_t)id_1178.size() };
      Vec<1, uint32_t> id_1180 {  id_1179  };
      Size let_res_1181;
      {
        Vec<1, uint32_t> n_ref_472 { id_1180 };
        uint32_t id_1182 { 1U };
        Vec<1, uint32_t> id_1183 {  id_1182  };
        Size let_res_1184;
        {
          Vec<1, uint32_t> lebsz_ref_473 { id_1183 };
          bool while_flag_1185 { true };
          do {
            uint8_t id_1186 { 0 };
            uint32_t id_1187 { n_ref_472[id_1186] };
            uint8_t id_1188 { 0 };
            uint32_t id_1189 { lebsz_ref_473[id_1188] };
            uint8_t id_1190 { 7 };
            uint32_t id_1191 { uint32_t(id_1189 << id_1190) };
            bool id_1192 { bool(id_1187 >= id_1191) };
            while_flag_1185 = id_1192;
            if (while_flag_1185) {
              uint8_t id_1193 { 0 };
              uint8_t id_1194 { 0 };
              uint32_t id_1195 { lebsz_ref_473[id_1194] };
              uint32_t id_1196 { 1U };
              uint32_t id_1197 { uint32_t(id_1195 + id_1196) };
              Void id_1198 { ((void)(lebsz_ref_473[id_1193] = id_1197), ::dessser::VOID) };
              (void)id_1198;
            }
          } while (while_flag_1185);
          (void)::dessser::VOID;
          uint8_t id_1199 { 0 };
          uint32_t id_1200 { lebsz_ref_473[id_1199] };
          Size id_1201 { Size(id_1200) };
          let_res_1184 = id_1201;
        }
        let_res_1181 = let_res_1184;
      }
      std::string id_1202 { (*p_0).desc_recovery };
      uint32_t id_1203 { (uint32_t)id_1202.size() };
      Size id_1204 { Size(id_1203) };
      Size id_1205 { Size(let_res_1181 + id_1204) };
      Size id_1206 { Size(sz_470 + id_1205) };
      let_res_1177 = id_1206;
    }
    return let_res_1177;
  }
   };
  return fun719;
}
std::function<Size(std::shared_ptr<::dessser::gen::alert::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_128" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_129" "drec_snd_130" (identifier "drec_128")
          (let "dstring1_137"
            (let "leb_ref_131" (make-vec (u32 0))
              (let "shft_ref_132" (make-vec (u8 0))
                (let "p_ref_133" (make-vec (identifier "drec_snd_130"))
                  (seq
                    (while
                      (let "leb128_134" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_133")))
                        (let-pair "leb128_fst_135" "leb128_snd_136" (identifier "leb128_134")
                          (seq (set-vec (u8 0) (identifier "p_ref_133") (identifier "leb128_snd_136"))
                            (set-vec (u8 0) (identifier "leb_ref_131")
                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_135") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_132"))) (unsafe-nth (u8 0) (identifier "leb_ref_131"))))
                            (set-vec (u8 0) (identifier "shft_ref_132") (add (unsafe-nth (u8 0) (identifier "shft_ref_132")) (u8 7))) 
                            (ge (identifier "leb128_fst_135") (u8 128))))) 
                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_131"))) (unsafe-nth (u8 0) (identifier "p_ref_133")))))))
            (let-pair "dstring1_fst_138" "dstring1_snd_139" (identifier "dstring1_137")
              (let-pair "dstring2_fst_141" "dstring2_snd_142" (read-bytes (identifier "dstring1_snd_139") (identifier "dstring1_fst_138"))
                (make-tup (make-rec (string "value") (string-of-bytes (identifier "dstring2_fst_141")) (string "name") (identifier "drec_fst_129")) (identifier "dstring2_snd_142"))))))))
 */
static std::function<::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904(Pointer)> constant_of_row_binary_init()
{
  std::function<::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904(Pointer)> fun1207 { [&fun1207](Pointer p_0) {
    auto fun1208 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1209 { fun1208(p_0) };
    ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 let_res_1210;
    {
      ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 drec_128 { id_1209 };
      ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 letpair_res_1211;
      {
        auto drec_fst_129 { std::get<0>(drec_128) };
        auto drec_snd_130 { std::get<1>(drec_128) };
        uint32_t id_1212 { 0U };
        Vec<1, uint32_t> id_1213 {  id_1212  };
        ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1214;
        {
          Vec<1, uint32_t> leb_ref_131 { id_1213 };
          uint8_t id_1215 { 0 };
          Vec<1, uint8_t> id_1216 {  id_1215  };
          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1217;
          {
            Vec<1, uint8_t> shft_ref_132 { id_1216 };
            Vec<1, Pointer> id_1218 {  drec_snd_130  };
            ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1219;
            {
              Vec<1, Pointer> p_ref_133 { id_1218 };
              bool while_flag_1220 { true };
              do {
                uint8_t id_1221 { 0 };
                Pointer id_1222 { p_ref_133[id_1221] };
                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1223 { id_1222.readU8() };
                bool let_res_1224;
                {
                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_134 { id_1223 };
                  bool letpair_res_1225;
                  {
                    auto leb128_fst_135 { std::get<0>(leb128_134) };
                    auto leb128_snd_136 { std::get<1>(leb128_134) };
                    uint8_t id_1226 { 0 };
                    Void id_1227 { ((void)(p_ref_133[id_1226] = leb128_snd_136), ::dessser::VOID) };
                    (void)id_1227;
                    uint8_t id_1228 { 0 };
                    uint8_t id_1229 { 127 };
                    uint8_t id_1230 { uint8_t(leb128_fst_135 & id_1229) };
                    uint32_t id_1231 { uint32_t(id_1230) };
                    uint8_t id_1232 { 0 };
                    uint8_t id_1233 { shft_ref_132[id_1232] };
                    uint32_t id_1234 { uint32_t(id_1231 << id_1233) };
                    uint8_t id_1235 { 0 };
                    uint32_t id_1236 { leb_ref_131[id_1235] };
                    uint32_t id_1237 { uint32_t(id_1234 | id_1236) };
                    Void id_1238 { ((void)(leb_ref_131[id_1228] = id_1237), ::dessser::VOID) };
                    (void)id_1238;
                    uint8_t id_1239 { 0 };
                    uint8_t id_1240 { 0 };
                    uint8_t id_1241 { shft_ref_132[id_1240] };
                    uint8_t id_1242 { 7 };
                    uint8_t id_1243 { uint8_t(id_1241 + id_1242) };
                    Void id_1244 { ((void)(shft_ref_132[id_1239] = id_1243), ::dessser::VOID) };
                    (void)id_1244;
                    uint8_t id_1245 { 128 };
                    bool id_1246 { bool(leb128_fst_135 >= id_1245) };
                    letpair_res_1225 = id_1246;
                  }
                  let_res_1224 = letpair_res_1225;
                }
                while_flag_1220 = let_res_1224;
                if (while_flag_1220) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_1220);
              (void)::dessser::VOID;
              uint8_t id_1247 { 0 };
              uint32_t id_1248 { leb_ref_131[id_1247] };
              Size id_1249 { Size(id_1248) };
              uint8_t id_1250 { 0 };
              Pointer id_1251 { p_ref_133[id_1250] };
              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1252 { id_1249, id_1251 };
              let_res_1219 = id_1252;
            }
            let_res_1217 = let_res_1219;
          }
          let_res_1214 = let_res_1217;
        }
        ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 let_res_1253;
        {
          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_137 { let_res_1214 };
          ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 letpair_res_1254;
          {
            auto dstring1_fst_138 { std::get<0>(dstring1_137) };
            auto dstring1_snd_139 { std::get<1>(dstring1_137) };
            ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1255 { dstring1_snd_139.readBytes(dstring1_fst_138) };
            ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 letpair_res_1256;
            {
              auto dstring2_fst_141 { std::get<0>(id_1255) };
              auto dstring2_snd_142 { std::get<1>(id_1255) };
              std::string id_1257 { dstring2_fst_141.toString() };
              std::shared_ptr<::dessser::gen::alert::constant>  id_1258 { std::make_shared<::dessser::gen::alert::constant>(drec_fst_129, id_1257) };
              ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 id_1259 { id_1258, dstring2_snd_142 };
              letpair_res_1256 = id_1259;
            }
            letpair_res_1254 = letpair_res_1256;
          }
          let_res_1253 = letpair_res_1254;
        }
        letpair_res_1211 = let_res_1253;
      }
      let_res_1210 = letpair_res_1211;
    }
    return let_res_1210;
  }
   };
  return fun1207;
}
std::function<::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904(Pointer)> constant_of_row_binary(constant_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
          (if (eq (u16 0) (identifier "dsum1_fst_63"))
            (let-pair "dfloat_fst_123" "dfloat_snd_124" (read-u64 little-endian (identifier "dsum1_snd_64"))
              (make-tup
                (construct "[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]" 0
                  (float-of-u64 (identifier "dfloat_fst_123"))) (identifier "dfloat_snd_124")))
            (seq (assert (eq (identifier "dsum1_fst_63") (u16 1)))
              (let "drec_68" (let-pair "dfloat_fst_66" "dfloat_snd_67" (read-u64 little-endian (identifier "dsum1_snd_64")) (make-tup (float-of-u64 (identifier "dfloat_fst_66")) (identifier "dfloat_snd_67")))
                (let-pair "drec_fst_69" "drec_snd_70" (identifier "drec_68")
                  (let "drec_74" (let-pair "du32_fst_72" "du32_snd_73" (read-u32 little-endian (identifier "drec_snd_70")) (make-tup (identifier "du32_fst_72") (identifier "du32_snd_73")))
                    (let-pair "drec_fst_75" "drec_snd_76" (identifier "drec_74")
                      (let "drec_80" (let-pair "dfloat_fst_78" "dfloat_snd_79" (read-u64 little-endian (identifier "drec_snd_76")) (make-tup (float-of-u64 (identifier "dfloat_fst_78")) (identifier "dfloat_snd_79")))
                        (let-pair "drec_fst_81" "drec_snd_82" (identifier "drec_80")
                          (let "drec_86" (let-pair "du32_fst_84" "du32_snd_85" (read-u32 little-endian (identifier "drec_snd_82")) (make-tup (identifier "du32_fst_84") (identifier "du32_snd_85")))
                            (let-pair "drec_fst_87" "drec_snd_88" (identifier "drec_86")
                              (let "drec_92" (let-pair "dfloat_fst_90" "dfloat_snd_91" (read-u64 little-endian (identifier "drec_snd_88")) (make-tup (float-of-u64 (identifier "dfloat_fst_90")) (identifier "dfloat_snd_91")))
                                (let-pair "drec_fst_93" "drec_snd_94" 
                                  (identifier "drec_92")
                                  (let-pair "drec_fst_117" "drec_snd_118"
                                    (let "dsum1_101" (let-pair "du16_fst_96" "du16_snd_97" (read-u16 little-endian (identifier "drec_snd_94")) (make-tup (identifier "du16_fst_96") (identifier "du16_snd_97")))
                                      (let-pair "dsum1_fst_102" "dsum1_snd_103" 
                                        (identifier "dsum1_101")
                                        (if (eq (u16 0) (identifier "dsum1_fst_102"))
                                          (let-pair "dfloat_fst_111" "dfloat_snd_112" 
                                            (read-u64 little-endian (identifier "dsum1_snd_103"))
                                            (make-tup (construct "[Absolute FLOAT | Relative FLOAT]" 0 (float-of-u64 (identifier "dfloat_fst_111"))) (identifier "dfloat_snd_112")))
                                          (seq (assert (eq (identifier "dsum1_fst_102") (u16 1)))
                                            (let-pair "dfloat_fst_105" "dfloat_snd_106" 
                                              (read-u64 little-endian (identifier "dsum1_snd_103"))
                                              (make-tup (construct "[Absolute FLOAT | Relative FLOAT]" 1 (float-of-u64 (identifier "dfloat_fst_105"))) (identifier "dfloat_snd_106")))))))
                                    (make-tup
                                      (construct "[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]" 1
                                        (make-rec (string "max_distance") 
                                          (identifier "drec_fst_117") 
                                          (string "smooth_factor") (identifier "drec_fst_93") 
                                          (string "seasonality") (identifier "drec_fst_87") 
                                          (string "percentile") (identifier "drec_fst_81") 
                                          (string "sample_size") (identifier "drec_fst_75") 
                                          (string "avg_window") (identifier "drec_fst_69"))) 
                                      (identifier "drec_snd_118"))))))))))))))))))
 */
static std::function<::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91(Pointer)> threshold_of_row_binary_init()
{
  std::function<::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91(Pointer)> fun1260 { [&fun1260](Pointer p_0) {
    ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1261 { p_0.readU16Le() };
    ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1262;
    {
      auto du16_fst_57 { std::get<0>(id_1261) };
      auto du16_snd_58 { std::get<1>(id_1261) };
      ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1263 { du16_fst_57, du16_snd_58 };
      letpair_res_1262 = id_1263;
    }
    ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1264;
    {
      ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 dsum1_62 { letpair_res_1262 };
      ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1265;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_1266 { 0 };
        bool id_1267 { bool(id_1266 == dsum1_fst_63) };
        ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 choose_res_1268;
        if (id_1267) {
          ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1269 { dsum1_snd_64.readU64Le() };
          ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1270;
          {
            auto dfloat_fst_123 { std::get<0>(id_1269) };
            auto dfloat_snd_124 { std::get<1>(id_1269) };
            double id_1271 { float_of_qword(dfloat_fst_123) };
            std::shared_ptr<::dessser::gen::alert::threshold>  id_1272 { std::make_shared<::dessser::gen::alert::threshold>(std::in_place_index<0>, id_1271) };
            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 id_1273 { id_1272, dfloat_snd_124 };
            letpair_res_1270 = id_1273;
          }
          choose_res_1268 = letpair_res_1270;
        } else {
          uint16_t id_1274 { 1 };
          bool id_1275 { bool(dsum1_fst_63 == id_1274) };
          Void id_1276 { ((void)(assert(id_1275)), ::dessser::VOID) };
          (void)id_1276;
          ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1277 { dsum1_snd_64.readU64Le() };
          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1278;
          {
            auto dfloat_fst_66 { std::get<0>(id_1277) };
            auto dfloat_snd_67 { std::get<1>(id_1277) };
            double id_1279 { float_of_qword(dfloat_fst_66) };
            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1280 { id_1279, dfloat_snd_67 };
            letpair_res_1278 = id_1280;
          }
          ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1281;
          {
            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_68 { letpair_res_1278 };
            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1282;
            {
              auto drec_fst_69 { std::get<0>(drec_68) };
              auto drec_snd_70 { std::get<1>(drec_68) };
              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1283 { drec_snd_70.readU32Le() };
              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 letpair_res_1284;
              {
                auto du32_fst_72 { std::get<0>(id_1283) };
                auto du32_snd_73 { std::get<1>(id_1283) };
                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1285 { du32_fst_72, du32_snd_73 };
                letpair_res_1284 = id_1285;
              }
              ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1286;
              {
                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 drec_74 { letpair_res_1284 };
                ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1287;
                {
                  auto drec_fst_75 { std::get<0>(drec_74) };
                  auto drec_snd_76 { std::get<1>(drec_74) };
                  ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1288 { drec_snd_76.readU64Le() };
                  ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1289;
                  {
                    auto dfloat_fst_78 { std::get<0>(id_1288) };
                    auto dfloat_snd_79 { std::get<1>(id_1288) };
                    double id_1290 { float_of_qword(dfloat_fst_78) };
                    ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1291 { id_1290, dfloat_snd_79 };
                    letpair_res_1289 = id_1291;
                  }
                  ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1292;
                  {
                    ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_80 { letpair_res_1289 };
                    ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1293;
                    {
                      auto drec_fst_81 { std::get<0>(drec_80) };
                      auto drec_snd_82 { std::get<1>(drec_80) };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1294 { drec_snd_82.readU32Le() };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 letpair_res_1295;
                      {
                        auto du32_fst_84 { std::get<0>(id_1294) };
                        auto du32_snd_85 { std::get<1>(id_1294) };
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1296 { du32_fst_84, du32_snd_85 };
                        letpair_res_1295 = id_1296;
                      }
                      ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1297;
                      {
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 drec_86 { letpair_res_1295 };
                        ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1298;
                        {
                          auto drec_fst_87 { std::get<0>(drec_86) };
                          auto drec_snd_88 { std::get<1>(drec_86) };
                          ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1299 { drec_snd_88.readU64Le() };
                          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1300;
                          {
                            auto dfloat_fst_90 { std::get<0>(id_1299) };
                            auto dfloat_snd_91 { std::get<1>(id_1299) };
                            double id_1301 { float_of_qword(dfloat_fst_90) };
                            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1302 { id_1301, dfloat_snd_91 };
                            letpair_res_1300 = id_1302;
                          }
                          ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1303;
                          {
                            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_92 { letpair_res_1300 };
                            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1304;
                            {
                              auto drec_fst_93 { std::get<0>(drec_92) };
                              auto drec_snd_94 { std::get<1>(drec_92) };
                              ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1305 { drec_snd_94.readU16Le() };
                              ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1306;
                              {
                                auto du16_fst_96 { std::get<0>(id_1305) };
                                auto du16_snd_97 { std::get<1>(id_1305) };
                                ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1307 { du16_fst_96, du16_snd_97 };
                                letpair_res_1306 = id_1307;
                              }
                              ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 let_res_1308;
                              {
                                ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 dsum1_101 { letpair_res_1306 };
                                ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 letpair_res_1309;
                                {
                                  auto dsum1_fst_102 { std::get<0>(dsum1_101) };
                                  auto dsum1_snd_103 { std::get<1>(dsum1_101) };
                                  uint16_t id_1310 { 0 };
                                  bool id_1311 { bool(id_1310 == dsum1_fst_102) };
                                  ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 choose_res_1312;
                                  if (id_1311) {
                                    ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1313 { dsum1_snd_103.readU64Le() };
                                    ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 letpair_res_1314;
                                    {
                                      auto dfloat_fst_111 { std::get<0>(id_1313) };
                                      auto dfloat_snd_112 { std::get<1>(id_1313) };
                                      double id_1315 { float_of_qword(dfloat_fst_111) };
                                      ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_1316 { std::in_place_index<0>, id_1315 };
                                      ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 id_1317 { id_1316, dfloat_snd_112 };
                                      letpair_res_1314 = id_1317;
                                    }
                                    choose_res_1312 = letpair_res_1314;
                                  } else {
                                    uint16_t id_1318 { 1 };
                                    bool id_1319 { bool(dsum1_fst_102 == id_1318) };
                                    Void id_1320 { ((void)(assert(id_1319)), ::dessser::VOID) };
                                    (void)id_1320;
                                    ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1321 { dsum1_snd_103.readU64Le() };
                                    ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 letpair_res_1322;
                                    {
                                      auto dfloat_fst_105 { std::get<0>(id_1321) };
                                      auto dfloat_snd_106 { std::get<1>(id_1321) };
                                      double id_1323 { float_of_qword(dfloat_fst_105) };
                                      ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_1324 { std::in_place_index<1>, id_1323 };
                                      ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 id_1325 { id_1324, dfloat_snd_106 };
                                      letpair_res_1322 = id_1325;
                                    }
                                    choose_res_1312 = letpair_res_1322;
                                  }
                                  letpair_res_1309 = choose_res_1312;
                                }
                                let_res_1308 = letpair_res_1309;
                              }
                              ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1326;
                              {
                                auto drec_fst_117 { std::get<0>(let_res_1308) };
                                auto drec_snd_118 { std::get<1>(let_res_1308) };
                                ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_1327 { drec_fst_69, drec_fst_75, drec_fst_81, drec_fst_87, drec_fst_93, drec_fst_117 };
                                std::shared_ptr<::dessser::gen::alert::threshold>  id_1328 { std::make_shared<::dessser::gen::alert::threshold>(std::in_place_index<1>, id_1327) };
                                ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 id_1329 { id_1328, drec_snd_118 };
                                letpair_res_1326 = id_1329;
                              }
                              letpair_res_1304 = letpair_res_1326;
                            }
                            let_res_1303 = letpair_res_1304;
                          }
                          letpair_res_1298 = let_res_1303;
                        }
                        let_res_1297 = letpair_res_1298;
                      }
                      letpair_res_1293 = let_res_1297;
                    }
                    let_res_1292 = letpair_res_1293;
                  }
                  letpair_res_1287 = let_res_1292;
                }
                let_res_1286 = letpair_res_1287;
              }
              letpair_res_1282 = let_res_1286;
            }
            let_res_1281 = letpair_res_1282;
          }
          choose_res_1268 = let_res_1281;
        }
        letpair_res_1265 = choose_res_1268;
      }
      let_res_1264 = letpair_res_1265;
    }
    return let_res_1264;
  }
   };
  return fun1260;
}
std::function<::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91(Pointer)> threshold_of_row_binary(threshold_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_146" (apply (ext-identifier fq_name of-row-binary) (param 0))
        (let-pair "drec_fst_147" "drec_snd_148" (identifier "drec_146")
          (let "drec_149" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_148"))
            (let-pair "drec_fst_150" "drec_snd_151" (identifier "drec_149")
              (let "drec_155" (let-pair "dbool_fst_153" "dbool_snd_154" (read-u8 (identifier "drec_snd_151")) (make-tup (not (eq (identifier "dbool_fst_153") (u8 0))) (identifier "dbool_snd_154")))
                (let-pair "drec_fst_156" "drec_snd_157" (identifier "drec_155")
                  (let "drec_181"
                    (let-pair "dlist4_fst_179" "dlist4_snd_180"
                      (let "dlist1_167"
                        (let "leb_ref_158" (make-vec (u32 0))
                          (let "shft_ref_159" (make-vec (u8 0))
                            (let "p_ref_160" (make-vec (identifier "drec_snd_157"))
                              (seq
                                (while
                                  (let "leb128_161" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_160")))
                                    (let-pair "leb128_fst_162" "leb128_snd_163" 
                                      (identifier "leb128_161")
                                      (seq (set-vec (u8 0) (identifier "p_ref_160") (identifier "leb128_snd_163"))
                                        (set-vec (u8 0) (identifier "leb_ref_158")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_162") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_159"))) (unsafe-nth (u8 0) (identifier "leb_ref_158"))))
                                        (set-vec (u8 0) (identifier "shft_ref_159") (add (unsafe-nth (u8 0) (identifier "shft_ref_159")) (u8 7))) 
                                        (ge (identifier "leb128_fst_162") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_158")) (unsafe-nth (u8 0) (identifier "p_ref_160")))))))
                        (let-pair "dlist1_fst_168" "dlist1_snd_169" (identifier "dlist1_167")
                          (let "inits_src_ref_170" (make-vec (make-tup (end-of-list "$simple_filter") (identifier "dlist1_snd_169")))
                            (seq
                              (let "repeat_n_171" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_168")) (unsafe-nth (u8 0) (identifier "repeat_n_171")))
                                  (seq
                                    (let "dlist2_172" (unsafe-nth (u8 0) (identifier "inits_src_ref_170"))
                                      (let-pair "dlist2_fst_173" "dlist2_snd_174" 
                                        (identifier "dlist2_172")
                                        (set-vec (u8 0) (identifier "inits_src_ref_170")
                                          (let-pair "dlist3_fst_176" "dlist3_snd_177" 
                                            (apply (ext-identifier simple_filter of-row-binary) (identifier "dlist2_snd_174"))
                                            (make-tup (cons (identifier "dlist3_fst_176") (identifier "dlist2_fst_173")) (identifier "dlist3_snd_177"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_171") (add (unsafe-nth (u8 0) (identifier "repeat_n_171")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_170")))))) 
                      (make-tup (identity (identifier "dlist4_fst_179")) (identifier "dlist4_snd_180")))
                    (let-pair "drec_fst_182" "drec_snd_183" (identifier "drec_181")
                      (let "drec_210"
                        (if (eq (peek-u8 (identifier "drec_snd_183") (size 0)) (u8 1)) 
                          (make-tup (null "$field_name[[]]") (ptr-add (identifier "drec_snd_183") (size 1)))
                          (let-pair "dlist4_fst_205" "dlist4_snd_206"
                            (let "dlist1_193"
                              (let "leb_ref_184" (make-vec (u32 0))
                                (let "shft_ref_185" (make-vec (u8 0))
                                  (let "p_ref_186" (make-vec (ptr-add (identifier "drec_snd_183") (size 1)))
                                    (seq
                                      (while
                                        (let "leb128_187" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_186")))
                                          (let-pair "leb128_fst_188" "leb128_snd_189" 
                                            (identifier "leb128_187")
                                            (seq (set-vec (u8 0) (identifier "p_ref_186") (identifier "leb128_snd_189"))
                                              (set-vec (u8 0) (identifier "leb_ref_184")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_188") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_185"))) (unsafe-nth (u8 0) (identifier "leb_ref_184"))))
                                              (set-vec (u8 0) (identifier "shft_ref_185") (add (unsafe-nth (u8 0) (identifier "shft_ref_185")) (u8 7))) 
                                              (ge (identifier "leb128_fst_188") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_184")) (unsafe-nth (u8 0) (identifier "p_ref_186")))))))
                              (let-pair "dlist1_fst_194" "dlist1_snd_195" 
                                (identifier "dlist1_193")
                                (let "inits_src_ref_196" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_195")))
                                  (seq
                                    (let "repeat_n_197" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_194")) (unsafe-nth (u8 0) (identifier "repeat_n_197")))
                                        (seq
                                          (let "dlist2_198" (unsafe-nth (u8 0) (identifier "inits_src_ref_196"))
                                            (let-pair "dlist2_fst_199" "dlist2_snd_200" 
                                              (identifier "dlist2_198")
                                              (set-vec (u8 0) (identifier "inits_src_ref_196")
                                                (let-pair "dlist3_fst_202" "dlist3_snd_203" 
                                                  (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_200"))
                                                  (make-tup (cons (identifier "dlist3_fst_202") (identifier "dlist2_fst_199")) (identifier "dlist3_snd_203"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_197") (add (unsafe-nth (u8 0) (identifier "repeat_n_197")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_196")))))) 
                            (make-tup (not-null (identity (identifier "dlist4_fst_205"))) (identifier "dlist4_snd_206"))))
                        (let-pair "drec_fst_211" "drec_snd_212" (identifier "drec_210")
                          (let "drec_236"
                            (let-pair "dlist4_fst_234" "dlist4_snd_235"
                              (let "dlist1_222"
                                (let "leb_ref_213" (make-vec (u32 0))
                                  (let "shft_ref_214" (make-vec (u8 0))
                                    (let "p_ref_215" (make-vec (identifier "drec_snd_212"))
                                      (seq
                                        (while
                                          (let "leb128_216" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_215")))
                                            (let-pair "leb128_fst_217" "leb128_snd_218" 
                                              (identifier "leb128_216")
                                              (seq (set-vec (u8 0) (identifier "p_ref_215") (identifier "leb128_snd_218"))
                                                (set-vec (u8 0) (identifier "leb_ref_213")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_217") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_214"))) (unsafe-nth (u8 0) (identifier "leb_ref_213"))))
                                                (set-vec (u8 0) (identifier "shft_ref_214") (add (unsafe-nth (u8 0) (identifier "shft_ref_214")) (u8 7))) 
                                                (ge (identifier "leb128_fst_217") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_213")) (unsafe-nth (u8 0) (identifier "p_ref_215")))))))
                                (let-pair "dlist1_fst_223" "dlist1_snd_224" 
                                  (identifier "dlist1_222")
                                  (let "inits_src_ref_225" (make-vec (make-tup (end-of-list "$simple_filter") (identifier "dlist1_snd_224")))
                                    (seq
                                      (let "repeat_n_226" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_223")) (unsafe-nth (u8 0) (identifier "repeat_n_226")))
                                          (seq
                                            (let "dlist2_227" (unsafe-nth (u8 0) (identifier "inits_src_ref_225"))
                                              (let-pair "dlist2_fst_228" "dlist2_snd_229" 
                                                (identifier "dlist2_227")
                                                (set-vec (u8 0) (identifier "inits_src_ref_225")
                                                  (let-pair "dlist3_fst_231" "dlist3_snd_232" 
                                                    (apply (ext-identifier simple_filter of-row-binary) (identifier "dlist2_snd_229"))
                                                    (make-tup (cons (identifier "dlist3_fst_231") (identifier "dlist2_fst_228")) (identifier "dlist3_snd_232"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_226") (add (unsafe-nth (u8 0) (identifier "repeat_n_226")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_225")))))) 
                              (make-tup (identity (identifier "dlist4_fst_234")) (identifier "dlist4_snd_235")))
                            (let-pair "drec_fst_237" "drec_snd_238" (identifier "drec_236")
                              (let "drec_239" (apply (identifier "threshold-of-row-binary") (identifier "drec_snd_238"))
                                (let-pair "drec_fst_240" "drec_snd_241" 
                                  (identifier "drec_239")
                                  (let "drec_245"
                                    (let-pair "dfloat_fst_243" "dfloat_snd_244" (read-u64 little-endian (identifier "drec_snd_241")) (make-tup (float-of-u64 (identifier "dfloat_fst_243")) (identifier "dfloat_snd_244")))
                                    (let-pair "drec_fst_246" "drec_snd_247" 
                                      (identifier "drec_245")
                                      (let "drec_251"
                                        (let-pair "dfloat_fst_249" "dfloat_snd_250" (read-u64 little-endian (identifier "drec_snd_247")) (make-tup (float-of-u64 (identifier "dfloat_fst_249")) (identifier "dfloat_snd_250")))
                                        (let-pair "drec_fst_252" "drec_snd_253" 
                                          (identifier "drec_251")
                                          (let "drec_257"
                                            (let-pair "dfloat_fst_255" "dfloat_snd_256" (read-u64 little-endian (identifier "drec_snd_253")) (make-tup (float-of-u64 (identifier "dfloat_fst_255")) (identifier "dfloat_snd_256")))
                                            (let-pair "drec_fst_258" "drec_snd_259" 
                                              (identifier "drec_257")
                                              (let "drec_263"
                                                (let-pair "dfloat_fst_261" "dfloat_snd_262" 
                                                  (read-u64 little-endian (identifier "drec_snd_259")) 
                                                  (make-tup (float-of-u64 (identifier "dfloat_fst_261")) (identifier "dfloat_snd_262")))
                                                (let-pair "drec_fst_264" "drec_snd_265" 
                                                  (identifier "drec_263")
                                                  (let "drec_289"
                                                    (let-pair "dlist4_fst_287" "dlist4_snd_288"
                                                      (let "dlist1_275"
                                                        (let "leb_ref_266" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_267" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_268" 
                                                              (make-vec (identifier "drec_snd_265"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_269" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_268")))
                                                                    (let-pair "leb128_fst_270" "leb128_snd_271" 
                                                                    (identifier "leb128_269")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_268") (identifier "leb128_snd_271"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_266")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_270") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_267")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_266")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_267") (add (unsafe-nth (u8 0) (identifier "shft_ref_267")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_270") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_266")) (unsafe-nth (u8 0) (identifier "p_ref_268")))))))
                                                        (let-pair "dlist1_fst_276" "dlist1_snd_277" 
                                                          (identifier "dlist1_275")
                                                          (let "inits_src_ref_278" 
                                                            (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_277")))
                                                            (seq
                                                              (let "repeat_n_279" 
                                                                (make-vec (i32 0))
                                                                (while 
                                                                  (gt (to-i32 (identifier "dlist1_fst_276")) (unsafe-nth (u8 0) (identifier "repeat_n_279")))
                                                                  (seq
                                                                    (let "dlist2_280" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_278"))
                                                                    (let-pair "dlist2_fst_281" "dlist2_snd_282" 
                                                                    (identifier "dlist2_280")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_278")
                                                                    (let-pair "dlist3_fst_284" "dlist3_snd_285" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_282"))
                                                                    (make-tup (cons (identifier "dlist3_fst_284") (identifier "dlist2_fst_281")) (identifier "dlist3_snd_285"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_279") (add (unsafe-nth (u8 0) (identifier "repeat_n_279")) (i32 1))))))
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_278")))))) 
                                                      (make-tup (identity (identifier "dlist4_fst_287")) (identifier "dlist4_snd_288")))
                                                    (let-pair "drec_fst_290" "drec_snd_291" 
                                                      (identifier "drec_289")
                                                      (let "drec_315"
                                                        (let-pair "dlist4_fst_313" "dlist4_snd_314"
                                                          (let "dlist1_301"
                                                            (let "leb_ref_292" 
                                                              (make-vec (u32 0))
                                                              (let "shft_ref_293" 
                                                                (make-vec (u8 0))
                                                                (let "p_ref_294" 
                                                                  (make-vec (identifier "drec_snd_291"))
                                                                  (seq
                                                                    (while
                                                                    (let "leb128_295" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_294")))
                                                                    (let-pair "leb128_fst_296" "leb128_snd_297" 
                                                                    (identifier "leb128_295")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_294") (identifier "leb128_snd_297"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_292")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_296") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_293")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_292")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_293") (add (unsafe-nth (u8 0) (identifier "shft_ref_293")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_296") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_292")) (unsafe-nth (u8 0) (identifier "p_ref_294")))))))
                                                            (let-pair "dlist1_fst_302" "dlist1_snd_303" 
                                                              (identifier "dlist1_301")
                                                              (let "inits_src_ref_304" 
                                                                (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_303")))
                                                                (seq
                                                                  (let "repeat_n_305" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_302")) (unsafe-nth (u8 0) (identifier "repeat_n_305")))
                                                                    (seq
                                                                    (let "dlist2_306" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_304"))
                                                                    (let-pair "dlist2_fst_307" "dlist2_snd_308" 
                                                                    (identifier "dlist2_306")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_304")
                                                                    (let-pair "dlist3_fst_310" "dlist3_snd_311" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_308"))
                                                                    (make-tup (cons (identifier "dlist3_fst_310") (identifier "dlist2_fst_307")) (identifier "dlist3_snd_311"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_305") (add (unsafe-nth (u8 0) (identifier "repeat_n_305")) (i32 1))))))
                                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_304")))))) 
                                                          (make-tup (identity (identifier "dlist4_fst_313")) (identifier "dlist4_snd_314")))
                                                        (let-pair "drec_fst_316" "drec_snd_317" 
                                                          (identifier "drec_315")
                                                          (let "drec_341"
                                                            (let-pair "dlist4_fst_339" "dlist4_snd_340"
                                                              (let "dlist1_327"
                                                                (let "leb_ref_318" 
                                                                  (make-vec (u32 0))
                                                                  (let "shft_ref_319" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_320" 
                                                                    (make-vec (identifier "drec_snd_317"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_321" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_320")))
                                                                    (let-pair "leb128_fst_322" "leb128_snd_323" 
                                                                    (identifier "leb128_321")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_320") (identifier "leb128_snd_323"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_318")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_322") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_319")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_318")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_319") (add (unsafe-nth (u8 0) (identifier "shft_ref_319")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_322") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_318")) (unsafe-nth (u8 0) (identifier "p_ref_320")))))))
                                                                (let-pair "dlist1_fst_328" "dlist1_snd_329" 
                                                                  (identifier "dlist1_327")
                                                                  (let "inits_src_ref_330" 
                                                                    (make-vec (make-tup (end-of-list "(constant AS {name: $field_name; value: STRING})") (identifier "dlist1_snd_329")))
                                                                    (seq
                                                                    (let "repeat_n_331" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_328")) (unsafe-nth (u8 0) (identifier "repeat_n_331")))
                                                                    (seq
                                                                    (let "dlist2_332" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_330"))
                                                                    (let-pair "dlist2_fst_333" "dlist2_snd_334" 
                                                                    (identifier "dlist2_332")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_330")
                                                                    (let-pair "dlist3_fst_336" "dlist3_snd_337" 
                                                                    (apply (identifier "constant-of-row-binary") (identifier "dlist2_snd_334"))
                                                                    (make-tup (cons (identifier "dlist3_fst_336") (identifier "dlist2_fst_333")) (identifier "dlist3_snd_337"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_331") (add (unsafe-nth (u8 0) (identifier "repeat_n_331")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_330")))))) 
                                                              (make-tup (identity (identifier "dlist4_fst_339")) (identifier "dlist4_snd_340")))
                                                            (let-pair "drec_fst_342" "drec_snd_343" 
                                                              (identifier "drec_341")
                                                              (let "drec_356"
                                                                (let "dstring1_350"
                                                                  (let "leb_ref_344" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_345" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_346" 
                                                                    (make-vec (identifier "drec_snd_343"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_347" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_346")))
                                                                    (let-pair "leb128_fst_348" "leb128_snd_349" 
                                                                    (identifier "leb128_347")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_346") (identifier "leb128_snd_349"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_344")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_348") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_345")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_344")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_345") (add (unsafe-nth (u8 0) (identifier "shft_ref_345")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_348") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_344"))) (unsafe-nth (u8 0) (identifier "p_ref_346")))))))
                                                                  (let-pair "dstring1_fst_351" "dstring1_snd_352" 
                                                                    (identifier "dstring1_350")
                                                                    (let-pair "dstring2_fst_354" "dstring2_snd_355" 
                                                                    (read-bytes (identifier "dstring1_snd_352") (identifier "dstring1_fst_351"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_354")) (identifier "dstring2_snd_355")))))
                                                                (let-pair "drec_fst_357" "drec_snd_358" 
                                                                  (identifier "drec_356")
                                                                  (let "drec_371"
                                                                    (let "dstring1_365"
                                                                    (let "leb_ref_359" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_360" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_361" 
                                                                    (make-vec (identifier "drec_snd_358"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_362" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_361")))
                                                                    (let-pair "leb128_fst_363" "leb128_snd_364" 
                                                                    (identifier "leb128_362")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_361") (identifier "leb128_snd_364"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_359")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_363") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_360")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_359")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_360") (add (unsafe-nth (u8 0) (identifier "shft_ref_360")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_363") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_359"))) (unsafe-nth (u8 0) (identifier "p_ref_361")))))))
                                                                    (let-pair "dstring1_fst_366" "dstring1_snd_367" 
                                                                    (identifier "dstring1_365")
                                                                    (let-pair "dstring2_fst_369" "dstring2_snd_370" 
                                                                    (read-bytes (identifier "dstring1_snd_367") (identifier "dstring1_fst_366"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_369")) (identifier "dstring2_snd_370")))))
                                                                    (let-pair "drec_fst_372" "drec_snd_373" 
                                                                    (identifier "drec_371")
                                                                    (let "drec_386"
                                                                    (let "dstring1_380"
                                                                    (let "leb_ref_374" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_375" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_376" 
                                                                    (make-vec (identifier "drec_snd_373"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_377" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_376")))
                                                                    (let-pair "leb128_fst_378" "leb128_snd_379" 
                                                                    (identifier "leb128_377")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_376") (identifier "leb128_snd_379"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_374")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_378") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_375")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_374")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_375") (add (unsafe-nth (u8 0) (identifier "shft_ref_375")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_378") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_374"))) (unsafe-nth (u8 0) (identifier "p_ref_376")))))))
                                                                    (let-pair "dstring1_fst_381" "dstring1_snd_382" 
                                                                    (identifier "dstring1_380")
                                                                    (let-pair "dstring2_fst_384" "dstring2_snd_385" 
                                                                    (read-bytes (identifier "dstring1_snd_382") (identifier "dstring1_fst_381"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_384")) (identifier "dstring2_snd_385")))))
                                                                    (let-pair "drec_fst_387" "drec_snd_388" 
                                                                    (identifier "drec_386")
                                                                    (let "dstring1_395"
                                                                    (let "leb_ref_389" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_390" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_391" 
                                                                    (make-vec (identifier "drec_snd_388"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_392" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_391")))
                                                                    (let-pair "leb128_fst_393" "leb128_snd_394" 
                                                                    (identifier "leb128_392")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_391") (identifier "leb128_snd_394"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_389")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_393") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_390")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_389")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_390") (add (unsafe-nth (u8 0) (identifier "shft_ref_390")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_393") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_389"))) (unsafe-nth (u8 0) (identifier "p_ref_391")))))))
                                                                    (let-pair "dstring1_fst_396" "dstring1_snd_397" 
                                                                    (identifier "dstring1_395")
                                                                    (let-pair "dstring2_fst_399" "dstring2_snd_400" 
                                                                    (read-bytes (identifier "dstring1_snd_397") (identifier "dstring1_fst_396"))
                                                                    (make-tup
                                                                    (make-rec 
                                                                    (string "desc-recovery") 
                                                                    (string-of-bytes (identifier "dstring2_fst_399")) 
                                                                    (string "desc-firing") 
                                                                    (identifier "drec_fst_387") 
                                                                    (string "desc-title") 
                                                                    (identifier "drec_fst_372") 
                                                                    (string "id") 
                                                                    (identifier "drec_fst_357") 
                                                                    (string "carry-csts") 
                                                                    (identifier "drec_fst_342") 
                                                                    (string "carry-fields") 
                                                                    (identifier "drec_fst_316") 
                                                                    (string "tops") 
                                                                    (identifier "drec_fst_290") 
                                                                    (string "time-step") 
                                                                    (identifier "drec_fst_264") 
                                                                    (string "ratio") 
                                                                    (identifier "drec_fst_258") 
                                                                    (string "duration") 
                                                                    (identifier "drec_fst_252") 
                                                                    (string "hysteresis") 
                                                                    (identifier "drec_fst_246") 
                                                                    (string "threshold") 
                                                                    (identifier "drec_fst_240") 
                                                                    (string "having") 
                                                                    (identifier "drec_fst_237") 
                                                                    (string "group-by") 
                                                                    (identifier "drec_fst_211") 
                                                                    (string "where") 
                                                                    (identifier "drec_fst_182") 
                                                                    (string "enabled") 
                                                                    (identifier "drec_fst_156") 
                                                                    (string "column") 
                                                                    (identifier "drec_fst_150") 
                                                                    (string "table") 
                                                                    (identifier "drec_fst_147")) 
                                                                    (identifier "dstring2_snd_400"))))))))))))))))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> fun1330 { [&fun1330](Pointer p_0) {
    auto fun1331 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::alert::t1067cf8ed87e4e016349f71797fb0661 id_1332 { fun1331(p_0) };
    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1333;
    {
      ::dessser::gen::alert::t1067cf8ed87e4e016349f71797fb0661 drec_146 { id_1332 };
      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1334;
      {
        auto drec_fst_147 { std::get<0>(drec_146) };
        auto drec_snd_148 { std::get<1>(drec_146) };
        auto fun1335 { dessser::gen::field_name::of_row_binary };
        ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1336 { fun1335(drec_snd_148) };
        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1337;
        {
          ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 drec_149 { id_1336 };
          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1338;
          {
            auto drec_fst_150 { std::get<0>(drec_149) };
            auto drec_snd_151 { std::get<1>(drec_149) };
            ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1339 { drec_snd_151.readU8() };
            ::dessser::gen::alert::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1340;
            {
              auto dbool_fst_153 { std::get<0>(id_1339) };
              auto dbool_snd_154 { std::get<1>(id_1339) };
              uint8_t id_1341 { 0 };
              bool id_1342 { bool(dbool_fst_153 == id_1341) };
              bool id_1343 { ! id_1342 };
              ::dessser::gen::alert::tf9a0a3fefc87c9e10a93d3a172850c26 id_1344 { id_1343, dbool_snd_154 };
              letpair_res_1340 = id_1344;
            }
            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1345;
            {
              ::dessser::gen::alert::tf9a0a3fefc87c9e10a93d3a172850c26 drec_155 { letpair_res_1340 };
              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1346;
              {
                auto drec_fst_156 { std::get<0>(drec_155) };
                auto drec_snd_157 { std::get<1>(drec_155) };
                uint32_t id_1347 { 0U };
                Vec<1, uint32_t> id_1348 {  id_1347  };
                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1349;
                {
                  Vec<1, uint32_t> leb_ref_158 { id_1348 };
                  uint8_t id_1350 { 0 };
                  Vec<1, uint8_t> id_1351 {  id_1350  };
                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1352;
                  {
                    Vec<1, uint8_t> shft_ref_159 { id_1351 };
                    Vec<1, Pointer> id_1353 {  drec_snd_157  };
                    ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1354;
                    {
                      Vec<1, Pointer> p_ref_160 { id_1353 };
                      bool while_flag_1355 { true };
                      do {
                        uint8_t id_1356 { 0 };
                        Pointer id_1357 { p_ref_160[id_1356] };
                        ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1358 { id_1357.readU8() };
                        bool let_res_1359;
                        {
                          ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_161 { id_1358 };
                          bool letpair_res_1360;
                          {
                            auto leb128_fst_162 { std::get<0>(leb128_161) };
                            auto leb128_snd_163 { std::get<1>(leb128_161) };
                            uint8_t id_1361 { 0 };
                            Void id_1362 { ((void)(p_ref_160[id_1361] = leb128_snd_163), ::dessser::VOID) };
                            (void)id_1362;
                            uint8_t id_1363 { 0 };
                            uint8_t id_1364 { 127 };
                            uint8_t id_1365 { uint8_t(leb128_fst_162 & id_1364) };
                            uint32_t id_1366 { uint32_t(id_1365) };
                            uint8_t id_1367 { 0 };
                            uint8_t id_1368 { shft_ref_159[id_1367] };
                            uint32_t id_1369 { uint32_t(id_1366 << id_1368) };
                            uint8_t id_1370 { 0 };
                            uint32_t id_1371 { leb_ref_158[id_1370] };
                            uint32_t id_1372 { uint32_t(id_1369 | id_1371) };
                            Void id_1373 { ((void)(leb_ref_158[id_1363] = id_1372), ::dessser::VOID) };
                            (void)id_1373;
                            uint8_t id_1374 { 0 };
                            uint8_t id_1375 { 0 };
                            uint8_t id_1376 { shft_ref_159[id_1375] };
                            uint8_t id_1377 { 7 };
                            uint8_t id_1378 { uint8_t(id_1376 + id_1377) };
                            Void id_1379 { ((void)(shft_ref_159[id_1374] = id_1378), ::dessser::VOID) };
                            (void)id_1379;
                            uint8_t id_1380 { 128 };
                            bool id_1381 { bool(leb128_fst_162 >= id_1380) };
                            letpair_res_1360 = id_1381;
                          }
                          let_res_1359 = letpair_res_1360;
                        }
                        while_flag_1355 = let_res_1359;
                        if (while_flag_1355) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_1355);
                      (void)::dessser::VOID;
                      uint8_t id_1382 { 0 };
                      uint32_t id_1383 { leb_ref_158[id_1382] };
                      uint8_t id_1384 { 0 };
                      Pointer id_1385 { p_ref_160[id_1384] };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1386 { id_1383, id_1385 };
                      let_res_1354 = id_1386;
                    }
                    let_res_1352 = let_res_1354;
                  }
                  let_res_1349 = let_res_1352;
                }
                ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1387;
                {
                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_167 { let_res_1349 };
                  ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1388;
                  {
                    auto dlist1_fst_168 { std::get<0>(dlist1_167) };
                    auto dlist1_snd_169 { std::get<1>(dlist1_167) };
                    Lst<dessser::gen::simple_filter::t_ext> endoflist_1389;
                    ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1390 { endoflist_1389, dlist1_snd_169 };
                    Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> id_1391 {  id_1390  };
                    ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1392;
                    {
                      Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> inits_src_ref_170 { id_1391 };
                      int32_t id_1393 { 0L };
                      Vec<1, int32_t> id_1394 {  id_1393  };
                      {
                        Vec<1, int32_t> repeat_n_171 { id_1394 };
                        bool while_flag_1395 { true };
                        do {
                          int32_t id_1396 { int32_t(dlist1_fst_168) };
                          uint8_t id_1397 { 0 };
                          int32_t id_1398 { repeat_n_171[id_1397] };
                          bool id_1399 { bool(id_1396 > id_1398) };
                          while_flag_1395 = id_1399;
                          if (while_flag_1395) {
                            uint8_t id_1400 { 0 };
                            ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1401 { inits_src_ref_170[id_1400] };
                            {
                              ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d dlist2_172 { id_1401 };
                              {
                                auto dlist2_fst_173 { std::get<0>(dlist2_172) };
                                auto dlist2_snd_174 { std::get<1>(dlist2_172) };
                                uint8_t id_1402 { 0 };
                                auto fun1403 { dessser::gen::simple_filter::of_row_binary };
                                ::dessser::gen::alert::t718468920e01b4b984449c743ae99792 id_1404 { fun1403(dlist2_snd_174) };
                                ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1405;
                                {
                                  auto dlist3_fst_176 { std::get<0>(id_1404) };
                                  auto dlist3_snd_177 { std::get<1>(id_1404) };
                                  Lst<dessser::gen::simple_filter::t_ext> id_1406 { dlist3_fst_176, dlist2_fst_173 };
                                  ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1407 { id_1406, dlist3_snd_177 };
                                  letpair_res_1405 = id_1407;
                                }
                                Void id_1408 { ((void)(inits_src_ref_170[id_1402] = letpair_res_1405), ::dessser::VOID) };
                                (void)id_1408;
                              }
                              (void)::dessser::VOID;
                            }
                            (void)::dessser::VOID;
                            uint8_t id_1409 { 0 };
                            uint8_t id_1410 { 0 };
                            int32_t id_1411 { repeat_n_171[id_1410] };
                            int32_t id_1412 { 1L };
                            int32_t id_1413 { int32_t(id_1411 + id_1412) };
                            Void id_1414 { ((void)(repeat_n_171[id_1409] = id_1413), ::dessser::VOID) };
                            (void)id_1414;
                            (void)id_1414;
                          }
                        } while (while_flag_1395);
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_1415 { 0 };
                      ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1416 { inits_src_ref_170[id_1415] };
                      let_res_1392 = id_1416;
                    }
                    letpair_res_1388 = let_res_1392;
                  }
                  let_res_1387 = letpair_res_1388;
                }
                ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1417;
                {
                  auto dlist4_fst_179 { std::get<0>(let_res_1387) };
                  auto dlist4_snd_180 { std::get<1>(let_res_1387) };
                  ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1418 { dlist4_fst_179, dlist4_snd_180 };
                  letpair_res_1417 = id_1418;
                }
                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1419;
                {
                  ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d drec_181 { letpair_res_1417 };
                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1420;
                  {
                    auto drec_fst_182 { std::get<0>(drec_181) };
                    auto drec_snd_183 { std::get<1>(drec_181) };
                    Size id_1421 { 0UL };
                    uint8_t id_1422 { drec_snd_183.peekU8(id_1421) };
                    uint8_t id_1423 { 1 };
                    bool id_1424 { bool(id_1422 == id_1423) };
                    ::dessser::gen::alert::t2fa56af3afd4098bea1b66e93db81284 choose_res_1425;
                    if (id_1424) {
                      std::optional<Lst<dessser::gen::field_name::t_ext>> id_1426 { std::nullopt };
                      Size id_1427 { 1UL };
                      Pointer id_1428 { drec_snd_183.skip(id_1427) };
                      ::dessser::gen::alert::t2fa56af3afd4098bea1b66e93db81284 id_1429 { id_1426, id_1428 };
                      choose_res_1425 = id_1429;
                    } else {
                      uint32_t id_1430 { 0U };
                      Vec<1, uint32_t> id_1431 {  id_1430  };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1432;
                      {
                        Vec<1, uint32_t> leb_ref_184 { id_1431 };
                        uint8_t id_1433 { 0 };
                        Vec<1, uint8_t> id_1434 {  id_1433  };
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1435;
                        {
                          Vec<1, uint8_t> shft_ref_185 { id_1434 };
                          Size id_1436 { 1UL };
                          Pointer id_1437 { drec_snd_183.skip(id_1436) };
                          Vec<1, Pointer> id_1438 {  id_1437  };
                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1439;
                          {
                            Vec<1, Pointer> p_ref_186 { id_1438 };
                            bool while_flag_1440 { true };
                            do {
                              uint8_t id_1441 { 0 };
                              Pointer id_1442 { p_ref_186[id_1441] };
                              ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1443 { id_1442.readU8() };
                              bool let_res_1444;
                              {
                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_187 { id_1443 };
                                bool letpair_res_1445;
                                {
                                  auto leb128_fst_188 { std::get<0>(leb128_187) };
                                  auto leb128_snd_189 { std::get<1>(leb128_187) };
                                  uint8_t id_1446 { 0 };
                                  Void id_1447 { ((void)(p_ref_186[id_1446] = leb128_snd_189), ::dessser::VOID) };
                                  (void)id_1447;
                                  uint8_t id_1448 { 0 };
                                  uint8_t id_1449 { 127 };
                                  uint8_t id_1450 { uint8_t(leb128_fst_188 & id_1449) };
                                  uint32_t id_1451 { uint32_t(id_1450) };
                                  uint8_t id_1452 { 0 };
                                  uint8_t id_1453 { shft_ref_185[id_1452] };
                                  uint32_t id_1454 { uint32_t(id_1451 << id_1453) };
                                  uint8_t id_1455 { 0 };
                                  uint32_t id_1456 { leb_ref_184[id_1455] };
                                  uint32_t id_1457 { uint32_t(id_1454 | id_1456) };
                                  Void id_1458 { ((void)(leb_ref_184[id_1448] = id_1457), ::dessser::VOID) };
                                  (void)id_1458;
                                  uint8_t id_1459 { 0 };
                                  uint8_t id_1460 { 0 };
                                  uint8_t id_1461 { shft_ref_185[id_1460] };
                                  uint8_t id_1462 { 7 };
                                  uint8_t id_1463 { uint8_t(id_1461 + id_1462) };
                                  Void id_1464 { ((void)(shft_ref_185[id_1459] = id_1463), ::dessser::VOID) };
                                  (void)id_1464;
                                  uint8_t id_1465 { 128 };
                                  bool id_1466 { bool(leb128_fst_188 >= id_1465) };
                                  letpair_res_1445 = id_1466;
                                }
                                let_res_1444 = letpair_res_1445;
                              }
                              while_flag_1440 = let_res_1444;
                              if (while_flag_1440) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_1440);
                            (void)::dessser::VOID;
                            uint8_t id_1467 { 0 };
                            uint32_t id_1468 { leb_ref_184[id_1467] };
                            uint8_t id_1469 { 0 };
                            Pointer id_1470 { p_ref_186[id_1469] };
                            ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1471 { id_1468, id_1470 };
                            let_res_1439 = id_1471;
                          }
                          let_res_1435 = let_res_1439;
                        }
                        let_res_1432 = let_res_1435;
                      }
                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1472;
                      {
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_193 { let_res_1432 };
                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1473;
                        {
                          auto dlist1_fst_194 { std::get<0>(dlist1_193) };
                          auto dlist1_snd_195 { std::get<1>(dlist1_193) };
                          Lst<dessser::gen::field_name::t_ext> endoflist_1474;
                          ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1475 { endoflist_1474, dlist1_snd_195 };
                          Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1476 {  id_1475  };
                          ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1477;
                          {
                            Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_196 { id_1476 };
                            int32_t id_1478 { 0L };
                            Vec<1, int32_t> id_1479 {  id_1478  };
                            {
                              Vec<1, int32_t> repeat_n_197 { id_1479 };
                              bool while_flag_1480 { true };
                              do {
                                int32_t id_1481 { int32_t(dlist1_fst_194) };
                                uint8_t id_1482 { 0 };
                                int32_t id_1483 { repeat_n_197[id_1482] };
                                bool id_1484 { bool(id_1481 > id_1483) };
                                while_flag_1480 = id_1484;
                                if (while_flag_1480) {
                                  uint8_t id_1485 { 0 };
                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1486 { inits_src_ref_196[id_1485] };
                                  {
                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_198 { id_1486 };
                                    {
                                      auto dlist2_fst_199 { std::get<0>(dlist2_198) };
                                      auto dlist2_snd_200 { std::get<1>(dlist2_198) };
                                      uint8_t id_1487 { 0 };
                                      auto fun1488 { dessser::gen::field_name::of_row_binary };
                                      ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1489 { fun1488(dlist2_snd_200) };
                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1490;
                                      {
                                        auto dlist3_fst_202 { std::get<0>(id_1489) };
                                        auto dlist3_snd_203 { std::get<1>(id_1489) };
                                        Lst<dessser::gen::field_name::t_ext> id_1491 { dlist3_fst_202, dlist2_fst_199 };
                                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1492 { id_1491, dlist3_snd_203 };
                                        letpair_res_1490 = id_1492;
                                      }
                                      Void id_1493 { ((void)(inits_src_ref_196[id_1487] = letpair_res_1490), ::dessser::VOID) };
                                      (void)id_1493;
                                    }
                                    (void)::dessser::VOID;
                                  }
                                  (void)::dessser::VOID;
                                  uint8_t id_1494 { 0 };
                                  uint8_t id_1495 { 0 };
                                  int32_t id_1496 { repeat_n_197[id_1495] };
                                  int32_t id_1497 { 1L };
                                  int32_t id_1498 { int32_t(id_1496 + id_1497) };
                                  Void id_1499 { ((void)(repeat_n_197[id_1494] = id_1498), ::dessser::VOID) };
                                  (void)id_1499;
                                  (void)id_1499;
                                }
                              } while (while_flag_1480);
                              (void)::dessser::VOID;
                            }
                            (void)::dessser::VOID;
                            uint8_t id_1500 { 0 };
                            ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1501 { inits_src_ref_196[id_1500] };
                            let_res_1477 = id_1501;
                          }
                          letpair_res_1473 = let_res_1477;
                        }
                        let_res_1472 = letpair_res_1473;
                      }
                      ::dessser::gen::alert::t2fa56af3afd4098bea1b66e93db81284 letpair_res_1502;
                      {
                        auto dlist4_fst_205 { std::get<0>(let_res_1472) };
                        auto dlist4_snd_206 { std::get<1>(let_res_1472) };
                        std::optional<Lst<dessser::gen::field_name::t_ext>> id_1503 { dlist4_fst_205 };
                        ::dessser::gen::alert::t2fa56af3afd4098bea1b66e93db81284 id_1504 { id_1503, dlist4_snd_206 };
                        letpair_res_1502 = id_1504;
                      }
                      choose_res_1425 = letpair_res_1502;
                    }
                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1505;
                    {
                      ::dessser::gen::alert::t2fa56af3afd4098bea1b66e93db81284 drec_210 { choose_res_1425 };
                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1506;
                      {
                        auto drec_fst_211 { std::get<0>(drec_210) };
                        auto drec_snd_212 { std::get<1>(drec_210) };
                        uint32_t id_1507 { 0U };
                        Vec<1, uint32_t> id_1508 {  id_1507  };
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1509;
                        {
                          Vec<1, uint32_t> leb_ref_213 { id_1508 };
                          uint8_t id_1510 { 0 };
                          Vec<1, uint8_t> id_1511 {  id_1510  };
                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1512;
                          {
                            Vec<1, uint8_t> shft_ref_214 { id_1511 };
                            Vec<1, Pointer> id_1513 {  drec_snd_212  };
                            ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1514;
                            {
                              Vec<1, Pointer> p_ref_215 { id_1513 };
                              bool while_flag_1515 { true };
                              do {
                                uint8_t id_1516 { 0 };
                                Pointer id_1517 { p_ref_215[id_1516] };
                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1518 { id_1517.readU8() };
                                bool let_res_1519;
                                {
                                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_216 { id_1518 };
                                  bool letpair_res_1520;
                                  {
                                    auto leb128_fst_217 { std::get<0>(leb128_216) };
                                    auto leb128_snd_218 { std::get<1>(leb128_216) };
                                    uint8_t id_1521 { 0 };
                                    Void id_1522 { ((void)(p_ref_215[id_1521] = leb128_snd_218), ::dessser::VOID) };
                                    (void)id_1522;
                                    uint8_t id_1523 { 0 };
                                    uint8_t id_1524 { 127 };
                                    uint8_t id_1525 { uint8_t(leb128_fst_217 & id_1524) };
                                    uint32_t id_1526 { uint32_t(id_1525) };
                                    uint8_t id_1527 { 0 };
                                    uint8_t id_1528 { shft_ref_214[id_1527] };
                                    uint32_t id_1529 { uint32_t(id_1526 << id_1528) };
                                    uint8_t id_1530 { 0 };
                                    uint32_t id_1531 { leb_ref_213[id_1530] };
                                    uint32_t id_1532 { uint32_t(id_1529 | id_1531) };
                                    Void id_1533 { ((void)(leb_ref_213[id_1523] = id_1532), ::dessser::VOID) };
                                    (void)id_1533;
                                    uint8_t id_1534 { 0 };
                                    uint8_t id_1535 { 0 };
                                    uint8_t id_1536 { shft_ref_214[id_1535] };
                                    uint8_t id_1537 { 7 };
                                    uint8_t id_1538 { uint8_t(id_1536 + id_1537) };
                                    Void id_1539 { ((void)(shft_ref_214[id_1534] = id_1538), ::dessser::VOID) };
                                    (void)id_1539;
                                    uint8_t id_1540 { 128 };
                                    bool id_1541 { bool(leb128_fst_217 >= id_1540) };
                                    letpair_res_1520 = id_1541;
                                  }
                                  let_res_1519 = letpair_res_1520;
                                }
                                while_flag_1515 = let_res_1519;
                                if (while_flag_1515) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_1515);
                              (void)::dessser::VOID;
                              uint8_t id_1542 { 0 };
                              uint32_t id_1543 { leb_ref_213[id_1542] };
                              uint8_t id_1544 { 0 };
                              Pointer id_1545 { p_ref_215[id_1544] };
                              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1546 { id_1543, id_1545 };
                              let_res_1514 = id_1546;
                            }
                            let_res_1512 = let_res_1514;
                          }
                          let_res_1509 = let_res_1512;
                        }
                        ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1547;
                        {
                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_222 { let_res_1509 };
                          ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1548;
                          {
                            auto dlist1_fst_223 { std::get<0>(dlist1_222) };
                            auto dlist1_snd_224 { std::get<1>(dlist1_222) };
                            Lst<dessser::gen::simple_filter::t_ext> endoflist_1549;
                            ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1550 { endoflist_1549, dlist1_snd_224 };
                            Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> id_1551 {  id_1550  };
                            ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1552;
                            {
                              Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> inits_src_ref_225 { id_1551 };
                              int32_t id_1553 { 0L };
                              Vec<1, int32_t> id_1554 {  id_1553  };
                              {
                                Vec<1, int32_t> repeat_n_226 { id_1554 };
                                bool while_flag_1555 { true };
                                do {
                                  int32_t id_1556 { int32_t(dlist1_fst_223) };
                                  uint8_t id_1557 { 0 };
                                  int32_t id_1558 { repeat_n_226[id_1557] };
                                  bool id_1559 { bool(id_1556 > id_1558) };
                                  while_flag_1555 = id_1559;
                                  if (while_flag_1555) {
                                    uint8_t id_1560 { 0 };
                                    ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1561 { inits_src_ref_225[id_1560] };
                                    {
                                      ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d dlist2_227 { id_1561 };
                                      {
                                        auto dlist2_fst_228 { std::get<0>(dlist2_227) };
                                        auto dlist2_snd_229 { std::get<1>(dlist2_227) };
                                        uint8_t id_1562 { 0 };
                                        auto fun1563 { dessser::gen::simple_filter::of_row_binary };
                                        ::dessser::gen::alert::t718468920e01b4b984449c743ae99792 id_1564 { fun1563(dlist2_snd_229) };
                                        ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1565;
                                        {
                                          auto dlist3_fst_231 { std::get<0>(id_1564) };
                                          auto dlist3_snd_232 { std::get<1>(id_1564) };
                                          Lst<dessser::gen::simple_filter::t_ext> id_1566 { dlist3_fst_231, dlist2_fst_228 };
                                          ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1567 { id_1566, dlist3_snd_232 };
                                          letpair_res_1565 = id_1567;
                                        }
                                        Void id_1568 { ((void)(inits_src_ref_225[id_1562] = letpair_res_1565), ::dessser::VOID) };
                                        (void)id_1568;
                                      }
                                      (void)::dessser::VOID;
                                    }
                                    (void)::dessser::VOID;
                                    uint8_t id_1569 { 0 };
                                    uint8_t id_1570 { 0 };
                                    int32_t id_1571 { repeat_n_226[id_1570] };
                                    int32_t id_1572 { 1L };
                                    int32_t id_1573 { int32_t(id_1571 + id_1572) };
                                    Void id_1574 { ((void)(repeat_n_226[id_1569] = id_1573), ::dessser::VOID) };
                                    (void)id_1574;
                                    (void)id_1574;
                                  }
                                } while (while_flag_1555);
                                (void)::dessser::VOID;
                              }
                              (void)::dessser::VOID;
                              uint8_t id_1575 { 0 };
                              ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1576 { inits_src_ref_225[id_1575] };
                              let_res_1552 = id_1576;
                            }
                            letpair_res_1548 = let_res_1552;
                          }
                          let_res_1547 = letpair_res_1548;
                        }
                        ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1577;
                        {
                          auto dlist4_fst_234 { std::get<0>(let_res_1547) };
                          auto dlist4_snd_235 { std::get<1>(let_res_1547) };
                          ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1578 { dlist4_fst_234, dlist4_snd_235 };
                          letpair_res_1577 = id_1578;
                        }
                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1579;
                        {
                          ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d drec_236 { letpair_res_1577 };
                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1580;
                          {
                            auto drec_fst_237 { std::get<0>(drec_236) };
                            auto drec_snd_238 { std::get<1>(drec_236) };
                            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 id_1581 { threshold_of_row_binary(drec_snd_238) };
                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1582;
                            {
                              ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 drec_239 { id_1581 };
                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1583;
                              {
                                auto drec_fst_240 { std::get<0>(drec_239) };
                                auto drec_snd_241 { std::get<1>(drec_239) };
                                ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1584 { drec_snd_241.readU64Le() };
                                ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1585;
                                {
                                  auto dfloat_fst_243 { std::get<0>(id_1584) };
                                  auto dfloat_snd_244 { std::get<1>(id_1584) };
                                  double id_1586 { float_of_qword(dfloat_fst_243) };
                                  ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1587 { id_1586, dfloat_snd_244 };
                                  letpair_res_1585 = id_1587;
                                }
                                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1588;
                                {
                                  ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_245 { letpair_res_1585 };
                                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1589;
                                  {
                                    auto drec_fst_246 { std::get<0>(drec_245) };
                                    auto drec_snd_247 { std::get<1>(drec_245) };
                                    ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1590 { drec_snd_247.readU64Le() };
                                    ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1591;
                                    {
                                      auto dfloat_fst_249 { std::get<0>(id_1590) };
                                      auto dfloat_snd_250 { std::get<1>(id_1590) };
                                      double id_1592 { float_of_qword(dfloat_fst_249) };
                                      ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1593 { id_1592, dfloat_snd_250 };
                                      letpair_res_1591 = id_1593;
                                    }
                                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1594;
                                    {
                                      ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_251 { letpair_res_1591 };
                                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1595;
                                      {
                                        auto drec_fst_252 { std::get<0>(drec_251) };
                                        auto drec_snd_253 { std::get<1>(drec_251) };
                                        ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1596 { drec_snd_253.readU64Le() };
                                        ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1597;
                                        {
                                          auto dfloat_fst_255 { std::get<0>(id_1596) };
                                          auto dfloat_snd_256 { std::get<1>(id_1596) };
                                          double id_1598 { float_of_qword(dfloat_fst_255) };
                                          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1599 { id_1598, dfloat_snd_256 };
                                          letpair_res_1597 = id_1599;
                                        }
                                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1600;
                                        {
                                          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_257 { letpair_res_1597 };
                                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1601;
                                          {
                                            auto drec_fst_258 { std::get<0>(drec_257) };
                                            auto drec_snd_259 { std::get<1>(drec_257) };
                                            ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1602 { drec_snd_259.readU64Le() };
                                            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1603;
                                            {
                                              auto dfloat_fst_261 { std::get<0>(id_1602) };
                                              auto dfloat_snd_262 { std::get<1>(id_1602) };
                                              double id_1604 { float_of_qword(dfloat_fst_261) };
                                              ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1605 { id_1604, dfloat_snd_262 };
                                              letpair_res_1603 = id_1605;
                                            }
                                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1606;
                                            {
                                              ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_263 { letpair_res_1603 };
                                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1607;
                                              {
                                                auto drec_fst_264 { std::get<0>(drec_263) };
                                                auto drec_snd_265 { std::get<1>(drec_263) };
                                                uint32_t id_1608 { 0U };
                                                Vec<1, uint32_t> id_1609 {  id_1608  };
                                                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1610;
                                                {
                                                  Vec<1, uint32_t> leb_ref_266 { id_1609 };
                                                  uint8_t id_1611 { 0 };
                                                  Vec<1, uint8_t> id_1612 {  id_1611  };
                                                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1613;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_267 { id_1612 };
                                                    Vec<1, Pointer> id_1614 {  drec_snd_265  };
                                                    ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1615;
                                                    {
                                                      Vec<1, Pointer> p_ref_268 { id_1614 };
                                                      bool while_flag_1616 { true };
                                                      do {
                                                        uint8_t id_1617 { 0 };
                                                        Pointer id_1618 { p_ref_268[id_1617] };
                                                        ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1619 { id_1618.readU8() };
                                                        bool let_res_1620;
                                                        {
                                                          ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_269 { id_1619 };
                                                          bool letpair_res_1621;
                                                          {
                                                            auto leb128_fst_270 { std::get<0>(leb128_269) };
                                                            auto leb128_snd_271 { std::get<1>(leb128_269) };
                                                            uint8_t id_1622 { 0 };
                                                            Void id_1623 { ((void)(p_ref_268[id_1622] = leb128_snd_271), ::dessser::VOID) };
                                                            (void)id_1623;
                                                            uint8_t id_1624 { 0 };
                                                            uint8_t id_1625 { 127 };
                                                            uint8_t id_1626 { uint8_t(leb128_fst_270 & id_1625) };
                                                            uint32_t id_1627 { uint32_t(id_1626) };
                                                            uint8_t id_1628 { 0 };
                                                            uint8_t id_1629 { shft_ref_267[id_1628] };
                                                            uint32_t id_1630 { uint32_t(id_1627 << id_1629) };
                                                            uint8_t id_1631 { 0 };
                                                            uint32_t id_1632 { leb_ref_266[id_1631] };
                                                            uint32_t id_1633 { uint32_t(id_1630 | id_1632) };
                                                            Void id_1634 { ((void)(leb_ref_266[id_1624] = id_1633), ::dessser::VOID) };
                                                            (void)id_1634;
                                                            uint8_t id_1635 { 0 };
                                                            uint8_t id_1636 { 0 };
                                                            uint8_t id_1637 { shft_ref_267[id_1636] };
                                                            uint8_t id_1638 { 7 };
                                                            uint8_t id_1639 { uint8_t(id_1637 + id_1638) };
                                                            Void id_1640 { ((void)(shft_ref_267[id_1635] = id_1639), ::dessser::VOID) };
                                                            (void)id_1640;
                                                            uint8_t id_1641 { 128 };
                                                            bool id_1642 { bool(leb128_fst_270 >= id_1641) };
                                                            letpair_res_1621 = id_1642;
                                                          }
                                                          let_res_1620 = letpair_res_1621;
                                                        }
                                                        while_flag_1616 = let_res_1620;
                                                        if (while_flag_1616) {
                                                          (void)::dessser::VOID;
                                                        }
                                                      } while (while_flag_1616);
                                                      (void)::dessser::VOID;
                                                      uint8_t id_1643 { 0 };
                                                      uint32_t id_1644 { leb_ref_266[id_1643] };
                                                      uint8_t id_1645 { 0 };
                                                      Pointer id_1646 { p_ref_268[id_1645] };
                                                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1647 { id_1644, id_1646 };
                                                      let_res_1615 = id_1647;
                                                    }
                                                    let_res_1613 = let_res_1615;
                                                  }
                                                  let_res_1610 = let_res_1613;
                                                }
                                                ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1648;
                                                {
                                                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_275 { let_res_1610 };
                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1649;
                                                  {
                                                    auto dlist1_fst_276 { std::get<0>(dlist1_275) };
                                                    auto dlist1_snd_277 { std::get<1>(dlist1_275) };
                                                    Lst<dessser::gen::field_name::t_ext> endoflist_1650;
                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1651 { endoflist_1650, dlist1_snd_277 };
                                                    Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1652 {  id_1651  };
                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1653;
                                                    {
                                                      Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_278 { id_1652 };
                                                      int32_t id_1654 { 0L };
                                                      Vec<1, int32_t> id_1655 {  id_1654  };
                                                      {
                                                        Vec<1, int32_t> repeat_n_279 { id_1655 };
                                                        bool while_flag_1656 { true };
                                                        do {
                                                          int32_t id_1657 { int32_t(dlist1_fst_276) };
                                                          uint8_t id_1658 { 0 };
                                                          int32_t id_1659 { repeat_n_279[id_1658] };
                                                          bool id_1660 { bool(id_1657 > id_1659) };
                                                          while_flag_1656 = id_1660;
                                                          if (while_flag_1656) {
                                                            uint8_t id_1661 { 0 };
                                                            ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1662 { inits_src_ref_278[id_1661] };
                                                            {
                                                              ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_280 { id_1662 };
                                                              {
                                                                auto dlist2_fst_281 { std::get<0>(dlist2_280) };
                                                                auto dlist2_snd_282 { std::get<1>(dlist2_280) };
                                                                uint8_t id_1663 { 0 };
                                                                auto fun1664 { dessser::gen::field_name::of_row_binary };
                                                                ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1665 { fun1664(dlist2_snd_282) };
                                                                ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1666;
                                                                {
                                                                  auto dlist3_fst_284 { std::get<0>(id_1665) };
                                                                  auto dlist3_snd_285 { std::get<1>(id_1665) };
                                                                  Lst<dessser::gen::field_name::t_ext> id_1667 { dlist3_fst_284, dlist2_fst_281 };
                                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1668 { id_1667, dlist3_snd_285 };
                                                                  letpair_res_1666 = id_1668;
                                                                }
                                                                Void id_1669 { ((void)(inits_src_ref_278[id_1663] = letpair_res_1666), ::dessser::VOID) };
                                                                (void)id_1669;
                                                              }
                                                              (void)::dessser::VOID;
                                                            }
                                                            (void)::dessser::VOID;
                                                            uint8_t id_1670 { 0 };
                                                            uint8_t id_1671 { 0 };
                                                            int32_t id_1672 { repeat_n_279[id_1671] };
                                                            int32_t id_1673 { 1L };
                                                            int32_t id_1674 { int32_t(id_1672 + id_1673) };
                                                            Void id_1675 { ((void)(repeat_n_279[id_1670] = id_1674), ::dessser::VOID) };
                                                            (void)id_1675;
                                                            (void)id_1675;
                                                          }
                                                        } while (while_flag_1656);
                                                        (void)::dessser::VOID;
                                                      }
                                                      (void)::dessser::VOID;
                                                      uint8_t id_1676 { 0 };
                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1677 { inits_src_ref_278[id_1676] };
                                                      let_res_1653 = id_1677;
                                                    }
                                                    letpair_res_1649 = let_res_1653;
                                                  }
                                                  let_res_1648 = letpair_res_1649;
                                                }
                                                ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1678;
                                                {
                                                  auto dlist4_fst_287 { std::get<0>(let_res_1648) };
                                                  auto dlist4_snd_288 { std::get<1>(let_res_1648) };
                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1679 { dlist4_fst_287, dlist4_snd_288 };
                                                  letpair_res_1678 = id_1679;
                                                }
                                                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1680;
                                                {
                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 drec_289 { letpair_res_1678 };
                                                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1681;
                                                  {
                                                    auto drec_fst_290 { std::get<0>(drec_289) };
                                                    auto drec_snd_291 { std::get<1>(drec_289) };
                                                    uint32_t id_1682 { 0U };
                                                    Vec<1, uint32_t> id_1683 {  id_1682  };
                                                    ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1684;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_292 { id_1683 };
                                                      uint8_t id_1685 { 0 };
                                                      Vec<1, uint8_t> id_1686 {  id_1685  };
                                                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1687;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_293 { id_1686 };
                                                        Vec<1, Pointer> id_1688 {  drec_snd_291  };
                                                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1689;
                                                        {
                                                          Vec<1, Pointer> p_ref_294 { id_1688 };
                                                          bool while_flag_1690 { true };
                                                          do {
                                                            uint8_t id_1691 { 0 };
                                                            Pointer id_1692 { p_ref_294[id_1691] };
                                                            ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1693 { id_1692.readU8() };
                                                            bool let_res_1694;
                                                            {
                                                              ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_295 { id_1693 };
                                                              bool letpair_res_1695;
                                                              {
                                                                auto leb128_fst_296 { std::get<0>(leb128_295) };
                                                                auto leb128_snd_297 { std::get<1>(leb128_295) };
                                                                uint8_t id_1696 { 0 };
                                                                Void id_1697 { ((void)(p_ref_294[id_1696] = leb128_snd_297), ::dessser::VOID) };
                                                                (void)id_1697;
                                                                uint8_t id_1698 { 0 };
                                                                uint8_t id_1699 { 127 };
                                                                uint8_t id_1700 { uint8_t(leb128_fst_296 & id_1699) };
                                                                uint32_t id_1701 { uint32_t(id_1700) };
                                                                uint8_t id_1702 { 0 };
                                                                uint8_t id_1703 { shft_ref_293[id_1702] };
                                                                uint32_t id_1704 { uint32_t(id_1701 << id_1703) };
                                                                uint8_t id_1705 { 0 };
                                                                uint32_t id_1706 { leb_ref_292[id_1705] };
                                                                uint32_t id_1707 { uint32_t(id_1704 | id_1706) };
                                                                Void id_1708 { ((void)(leb_ref_292[id_1698] = id_1707), ::dessser::VOID) };
                                                                (void)id_1708;
                                                                uint8_t id_1709 { 0 };
                                                                uint8_t id_1710 { 0 };
                                                                uint8_t id_1711 { shft_ref_293[id_1710] };
                                                                uint8_t id_1712 { 7 };
                                                                uint8_t id_1713 { uint8_t(id_1711 + id_1712) };
                                                                Void id_1714 { ((void)(shft_ref_293[id_1709] = id_1713), ::dessser::VOID) };
                                                                (void)id_1714;
                                                                uint8_t id_1715 { 128 };
                                                                bool id_1716 { bool(leb128_fst_296 >= id_1715) };
                                                                letpair_res_1695 = id_1716;
                                                              }
                                                              let_res_1694 = letpair_res_1695;
                                                            }
                                                            while_flag_1690 = let_res_1694;
                                                            if (while_flag_1690) {
                                                              (void)::dessser::VOID;
                                                            }
                                                          } while (while_flag_1690);
                                                          (void)::dessser::VOID;
                                                          uint8_t id_1717 { 0 };
                                                          uint32_t id_1718 { leb_ref_292[id_1717] };
                                                          uint8_t id_1719 { 0 };
                                                          Pointer id_1720 { p_ref_294[id_1719] };
                                                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1721 { id_1718, id_1720 };
                                                          let_res_1689 = id_1721;
                                                        }
                                                        let_res_1687 = let_res_1689;
                                                      }
                                                      let_res_1684 = let_res_1687;
                                                    }
                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1722;
                                                    {
                                                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_301 { let_res_1684 };
                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1723;
                                                      {
                                                        auto dlist1_fst_302 { std::get<0>(dlist1_301) };
                                                        auto dlist1_snd_303 { std::get<1>(dlist1_301) };
                                                        Lst<dessser::gen::field_name::t_ext> endoflist_1724;
                                                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1725 { endoflist_1724, dlist1_snd_303 };
                                                        Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1726 {  id_1725  };
                                                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1727;
                                                        {
                                                          Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_304 { id_1726 };
                                                          int32_t id_1728 { 0L };
                                                          Vec<1, int32_t> id_1729 {  id_1728  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_305 { id_1729 };
                                                            bool while_flag_1730 { true };
                                                            do {
                                                              int32_t id_1731 { int32_t(dlist1_fst_302) };
                                                              uint8_t id_1732 { 0 };
                                                              int32_t id_1733 { repeat_n_305[id_1732] };
                                                              bool id_1734 { bool(id_1731 > id_1733) };
                                                              while_flag_1730 = id_1734;
                                                              if (while_flag_1730) {
                                                                uint8_t id_1735 { 0 };
                                                                ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1736 { inits_src_ref_304[id_1735] };
                                                                {
                                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_306 { id_1736 };
                                                                  {
                                                                    auto dlist2_fst_307 { std::get<0>(dlist2_306) };
                                                                    auto dlist2_snd_308 { std::get<1>(dlist2_306) };
                                                                    uint8_t id_1737 { 0 };
                                                                    auto fun1738 { dessser::gen::field_name::of_row_binary };
                                                                    ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1739 { fun1738(dlist2_snd_308) };
                                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1740;
                                                                    {
                                                                      auto dlist3_fst_310 { std::get<0>(id_1739) };
                                                                      auto dlist3_snd_311 { std::get<1>(id_1739) };
                                                                      Lst<dessser::gen::field_name::t_ext> id_1741 { dlist3_fst_310, dlist2_fst_307 };
                                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1742 { id_1741, dlist3_snd_311 };
                                                                      letpair_res_1740 = id_1742;
                                                                    }
                                                                    Void id_1743 { ((void)(inits_src_ref_304[id_1737] = letpair_res_1740), ::dessser::VOID) };
                                                                    (void)id_1743;
                                                                  }
                                                                  (void)::dessser::VOID;
                                                                }
                                                                (void)::dessser::VOID;
                                                                uint8_t id_1744 { 0 };
                                                                uint8_t id_1745 { 0 };
                                                                int32_t id_1746 { repeat_n_305[id_1745] };
                                                                int32_t id_1747 { 1L };
                                                                int32_t id_1748 { int32_t(id_1746 + id_1747) };
                                                                Void id_1749 { ((void)(repeat_n_305[id_1744] = id_1748), ::dessser::VOID) };
                                                                (void)id_1749;
                                                                (void)id_1749;
                                                              }
                                                            } while (while_flag_1730);
                                                            (void)::dessser::VOID;
                                                          }
                                                          (void)::dessser::VOID;
                                                          uint8_t id_1750 { 0 };
                                                          ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1751 { inits_src_ref_304[id_1750] };
                                                          let_res_1727 = id_1751;
                                                        }
                                                        letpair_res_1723 = let_res_1727;
                                                      }
                                                      let_res_1722 = letpair_res_1723;
                                                    }
                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1752;
                                                    {
                                                      auto dlist4_fst_313 { std::get<0>(let_res_1722) };
                                                      auto dlist4_snd_314 { std::get<1>(let_res_1722) };
                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1753 { dlist4_fst_313, dlist4_snd_314 };
                                                      letpair_res_1752 = id_1753;
                                                    }
                                                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1754;
                                                    {
                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 drec_315 { letpair_res_1752 };
                                                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1755;
                                                      {
                                                        auto drec_fst_316 { std::get<0>(drec_315) };
                                                        auto drec_snd_317 { std::get<1>(drec_315) };
                                                        uint32_t id_1756 { 0U };
                                                        Vec<1, uint32_t> id_1757 {  id_1756  };
                                                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1758;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_318 { id_1757 };
                                                          uint8_t id_1759 { 0 };
                                                          Vec<1, uint8_t> id_1760 {  id_1759  };
                                                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1761;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_319 { id_1760 };
                                                            Vec<1, Pointer> id_1762 {  drec_snd_317  };
                                                            ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1763;
                                                            {
                                                              Vec<1, Pointer> p_ref_320 { id_1762 };
                                                              bool while_flag_1764 { true };
                                                              do {
                                                                uint8_t id_1765 { 0 };
                                                                Pointer id_1766 { p_ref_320[id_1765] };
                                                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1767 { id_1766.readU8() };
                                                                bool let_res_1768;
                                                                {
                                                                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_321 { id_1767 };
                                                                  bool letpair_res_1769;
                                                                  {
                                                                    auto leb128_fst_322 { std::get<0>(leb128_321) };
                                                                    auto leb128_snd_323 { std::get<1>(leb128_321) };
                                                                    uint8_t id_1770 { 0 };
                                                                    Void id_1771 { ((void)(p_ref_320[id_1770] = leb128_snd_323), ::dessser::VOID) };
                                                                    (void)id_1771;
                                                                    uint8_t id_1772 { 0 };
                                                                    uint8_t id_1773 { 127 };
                                                                    uint8_t id_1774 { uint8_t(leb128_fst_322 & id_1773) };
                                                                    uint32_t id_1775 { uint32_t(id_1774) };
                                                                    uint8_t id_1776 { 0 };
                                                                    uint8_t id_1777 { shft_ref_319[id_1776] };
                                                                    uint32_t id_1778 { uint32_t(id_1775 << id_1777) };
                                                                    uint8_t id_1779 { 0 };
                                                                    uint32_t id_1780 { leb_ref_318[id_1779] };
                                                                    uint32_t id_1781 { uint32_t(id_1778 | id_1780) };
                                                                    Void id_1782 { ((void)(leb_ref_318[id_1772] = id_1781), ::dessser::VOID) };
                                                                    (void)id_1782;
                                                                    uint8_t id_1783 { 0 };
                                                                    uint8_t id_1784 { 0 };
                                                                    uint8_t id_1785 { shft_ref_319[id_1784] };
                                                                    uint8_t id_1786 { 7 };
                                                                    uint8_t id_1787 { uint8_t(id_1785 + id_1786) };
                                                                    Void id_1788 { ((void)(shft_ref_319[id_1783] = id_1787), ::dessser::VOID) };
                                                                    (void)id_1788;
                                                                    uint8_t id_1789 { 128 };
                                                                    bool id_1790 { bool(leb128_fst_322 >= id_1789) };
                                                                    letpair_res_1769 = id_1790;
                                                                  }
                                                                  let_res_1768 = letpair_res_1769;
                                                                }
                                                                while_flag_1764 = let_res_1768;
                                                                if (while_flag_1764) {
                                                                  (void)::dessser::VOID;
                                                                }
                                                              } while (while_flag_1764);
                                                              (void)::dessser::VOID;
                                                              uint8_t id_1791 { 0 };
                                                              uint32_t id_1792 { leb_ref_318[id_1791] };
                                                              uint8_t id_1793 { 0 };
                                                              Pointer id_1794 { p_ref_320[id_1793] };
                                                              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1795 { id_1792, id_1794 };
                                                              let_res_1763 = id_1795;
                                                            }
                                                            let_res_1761 = let_res_1763;
                                                          }
                                                          let_res_1758 = let_res_1761;
                                                        }
                                                        ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e let_res_1796;
                                                        {
                                                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_327 { let_res_1758 };
                                                          ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e letpair_res_1797;
                                                          {
                                                            auto dlist1_fst_328 { std::get<0>(dlist1_327) };
                                                            auto dlist1_snd_329 { std::get<1>(dlist1_327) };
                                                            Lst<std::shared_ptr<::dessser::gen::alert::constant> > endoflist_1798;
                                                            ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1799 { endoflist_1798, dlist1_snd_329 };
                                                            Vec<1, ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e> id_1800 {  id_1799  };
                                                            ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e let_res_1801;
                                                            {
                                                              Vec<1, ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e> inits_src_ref_330 { id_1800 };
                                                              int32_t id_1802 { 0L };
                                                              Vec<1, int32_t> id_1803 {  id_1802  };
                                                              {
                                                                Vec<1, int32_t> repeat_n_331 { id_1803 };
                                                                bool while_flag_1804 { true };
                                                                do {
                                                                  int32_t id_1805 { int32_t(dlist1_fst_328) };
                                                                  uint8_t id_1806 { 0 };
                                                                  int32_t id_1807 { repeat_n_331[id_1806] };
                                                                  bool id_1808 { bool(id_1805 > id_1807) };
                                                                  while_flag_1804 = id_1808;
                                                                  if (while_flag_1804) {
                                                                    uint8_t id_1809 { 0 };
                                                                    ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1810 { inits_src_ref_330[id_1809] };
                                                                    {
                                                                      ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e dlist2_332 { id_1810 };
                                                                      {
                                                                        auto dlist2_fst_333 { std::get<0>(dlist2_332) };
                                                                        auto dlist2_snd_334 { std::get<1>(dlist2_332) };
                                                                        uint8_t id_1811 { 0 };
                                                                        ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 id_1812 { constant_of_row_binary(dlist2_snd_334) };
                                                                        ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e letpair_res_1813;
                                                                        {
                                                                          auto dlist3_fst_336 { std::get<0>(id_1812) };
                                                                          auto dlist3_snd_337 { std::get<1>(id_1812) };
                                                                          Lst<std::shared_ptr<::dessser::gen::alert::constant> > id_1814 { dlist3_fst_336, dlist2_fst_333 };
                                                                          ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1815 { id_1814, dlist3_snd_337 };
                                                                          letpair_res_1813 = id_1815;
                                                                        }
                                                                        Void id_1816 { ((void)(inits_src_ref_330[id_1811] = letpair_res_1813), ::dessser::VOID) };
                                                                        (void)id_1816;
                                                                      }
                                                                      (void)::dessser::VOID;
                                                                    }
                                                                    (void)::dessser::VOID;
                                                                    uint8_t id_1817 { 0 };
                                                                    uint8_t id_1818 { 0 };
                                                                    int32_t id_1819 { repeat_n_331[id_1818] };
                                                                    int32_t id_1820 { 1L };
                                                                    int32_t id_1821 { int32_t(id_1819 + id_1820) };
                                                                    Void id_1822 { ((void)(repeat_n_331[id_1817] = id_1821), ::dessser::VOID) };
                                                                    (void)id_1822;
                                                                    (void)id_1822;
                                                                  }
                                                                } while (while_flag_1804);
                                                                (void)::dessser::VOID;
                                                              }
                                                              (void)::dessser::VOID;
                                                              uint8_t id_1823 { 0 };
                                                              ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1824 { inits_src_ref_330[id_1823] };
                                                              let_res_1801 = id_1824;
                                                            }
                                                            letpair_res_1797 = let_res_1801;
                                                          }
                                                          let_res_1796 = letpair_res_1797;
                                                        }
                                                        ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e letpair_res_1825;
                                                        {
                                                          auto dlist4_fst_339 { std::get<0>(let_res_1796) };
                                                          auto dlist4_snd_340 { std::get<1>(let_res_1796) };
                                                          ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1826 { dlist4_fst_339, dlist4_snd_340 };
                                                          letpair_res_1825 = id_1826;
                                                        }
                                                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1827;
                                                        {
                                                          ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e drec_341 { letpair_res_1825 };
                                                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1828;
                                                          {
                                                            auto drec_fst_342 { std::get<0>(drec_341) };
                                                            auto drec_snd_343 { std::get<1>(drec_341) };
                                                            uint32_t id_1829 { 0U };
                                                            Vec<1, uint32_t> id_1830 {  id_1829  };
                                                            ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1831;
                                                            {
                                                              Vec<1, uint32_t> leb_ref_344 { id_1830 };
                                                              uint8_t id_1832 { 0 };
                                                              Vec<1, uint8_t> id_1833 {  id_1832  };
                                                              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1834;
                                                              {
                                                                Vec<1, uint8_t> shft_ref_345 { id_1833 };
                                                                Vec<1, Pointer> id_1835 {  drec_snd_343  };
                                                                ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1836;
                                                                {
                                                                  Vec<1, Pointer> p_ref_346 { id_1835 };
                                                                  bool while_flag_1837 { true };
                                                                  do {
                                                                    uint8_t id_1838 { 0 };
                                                                    Pointer id_1839 { p_ref_346[id_1838] };
                                                                    ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1840 { id_1839.readU8() };
                                                                    bool let_res_1841;
                                                                    {
                                                                      ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_347 { id_1840 };
                                                                      bool letpair_res_1842;
                                                                      {
                                                                        auto leb128_fst_348 { std::get<0>(leb128_347) };
                                                                        auto leb128_snd_349 { std::get<1>(leb128_347) };
                                                                        uint8_t id_1843 { 0 };
                                                                        Void id_1844 { ((void)(p_ref_346[id_1843] = leb128_snd_349), ::dessser::VOID) };
                                                                        (void)id_1844;
                                                                        uint8_t id_1845 { 0 };
                                                                        uint8_t id_1846 { 127 };
                                                                        uint8_t id_1847 { uint8_t(leb128_fst_348 & id_1846) };
                                                                        uint32_t id_1848 { uint32_t(id_1847) };
                                                                        uint8_t id_1849 { 0 };
                                                                        uint8_t id_1850 { shft_ref_345[id_1849] };
                                                                        uint32_t id_1851 { uint32_t(id_1848 << id_1850) };
                                                                        uint8_t id_1852 { 0 };
                                                                        uint32_t id_1853 { leb_ref_344[id_1852] };
                                                                        uint32_t id_1854 { uint32_t(id_1851 | id_1853) };
                                                                        Void id_1855 { ((void)(leb_ref_344[id_1845] = id_1854), ::dessser::VOID) };
                                                                        (void)id_1855;
                                                                        uint8_t id_1856 { 0 };
                                                                        uint8_t id_1857 { 0 };
                                                                        uint8_t id_1858 { shft_ref_345[id_1857] };
                                                                        uint8_t id_1859 { 7 };
                                                                        uint8_t id_1860 { uint8_t(id_1858 + id_1859) };
                                                                        Void id_1861 { ((void)(shft_ref_345[id_1856] = id_1860), ::dessser::VOID) };
                                                                        (void)id_1861;
                                                                        uint8_t id_1862 { 128 };
                                                                        bool id_1863 { bool(leb128_fst_348 >= id_1862) };
                                                                        letpair_res_1842 = id_1863;
                                                                      }
                                                                      let_res_1841 = letpair_res_1842;
                                                                    }
                                                                    while_flag_1837 = let_res_1841;
                                                                    if (while_flag_1837) {
                                                                      (void)::dessser::VOID;
                                                                    }
                                                                  } while (while_flag_1837);
                                                                  (void)::dessser::VOID;
                                                                  uint8_t id_1864 { 0 };
                                                                  uint32_t id_1865 { leb_ref_344[id_1864] };
                                                                  Size id_1866 { Size(id_1865) };
                                                                  uint8_t id_1867 { 0 };
                                                                  Pointer id_1868 { p_ref_346[id_1867] };
                                                                  ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1869 { id_1866, id_1868 };
                                                                  let_res_1836 = id_1869;
                                                                }
                                                                let_res_1834 = let_res_1836;
                                                              }
                                                              let_res_1831 = let_res_1834;
                                                            }
                                                            ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 let_res_1870;
                                                            {
                                                              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_350 { let_res_1831 };
                                                              ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1871;
                                                              {
                                                                auto dstring1_fst_351 { std::get<0>(dstring1_350) };
                                                                auto dstring1_snd_352 { std::get<1>(dstring1_350) };
                                                                ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1872 { dstring1_snd_352.readBytes(dstring1_fst_351) };
                                                                ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1873;
                                                                {
                                                                  auto dstring2_fst_354 { std::get<0>(id_1872) };
                                                                  auto dstring2_snd_355 { std::get<1>(id_1872) };
                                                                  std::string id_1874 { dstring2_fst_354.toString() };
                                                                  ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 id_1875 { id_1874, dstring2_snd_355 };
                                                                  letpair_res_1873 = id_1875;
                                                                }
                                                                letpair_res_1871 = letpair_res_1873;
                                                              }
                                                              let_res_1870 = letpair_res_1871;
                                                            }
                                                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1876;
                                                            {
                                                              ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 drec_356 { let_res_1870 };
                                                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1877;
                                                              {
                                                                auto drec_fst_357 { std::get<0>(drec_356) };
                                                                auto drec_snd_358 { std::get<1>(drec_356) };
                                                                uint32_t id_1878 { 0U };
                                                                Vec<1, uint32_t> id_1879 {  id_1878  };
                                                                ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1880;
                                                                {
                                                                  Vec<1, uint32_t> leb_ref_359 { id_1879 };
                                                                  uint8_t id_1881 { 0 };
                                                                  Vec<1, uint8_t> id_1882 {  id_1881  };
                                                                  ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1883;
                                                                  {
                                                                    Vec<1, uint8_t> shft_ref_360 { id_1882 };
                                                                    Vec<1, Pointer> id_1884 {  drec_snd_358  };
                                                                    ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1885;
                                                                    {
                                                                      Vec<1, Pointer> p_ref_361 { id_1884 };
                                                                      bool while_flag_1886 { true };
                                                                      do {
                                                                        uint8_t id_1887 { 0 };
                                                                        Pointer id_1888 { p_ref_361[id_1887] };
                                                                        ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1889 { id_1888.readU8() };
                                                                        bool let_res_1890;
                                                                        {
                                                                          ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_362 { id_1889 };
                                                                          bool letpair_res_1891;
                                                                          {
                                                                            auto leb128_fst_363 { std::get<0>(leb128_362) };
                                                                            auto leb128_snd_364 { std::get<1>(leb128_362) };
                                                                            uint8_t id_1892 { 0 };
                                                                            Void id_1893 { ((void)(p_ref_361[id_1892] = leb128_snd_364), ::dessser::VOID) };
                                                                            (void)id_1893;
                                                                            uint8_t id_1894 { 0 };
                                                                            uint8_t id_1895 { 127 };
                                                                            uint8_t id_1896 { uint8_t(leb128_fst_363 & id_1895) };
                                                                            uint32_t id_1897 { uint32_t(id_1896) };
                                                                            uint8_t id_1898 { 0 };
                                                                            uint8_t id_1899 { shft_ref_360[id_1898] };
                                                                            uint32_t id_1900 { uint32_t(id_1897 << id_1899) };
                                                                            uint8_t id_1901 { 0 };
                                                                            uint32_t id_1902 { leb_ref_359[id_1901] };
                                                                            uint32_t id_1903 { uint32_t(id_1900 | id_1902) };
                                                                            Void id_1904 { ((void)(leb_ref_359[id_1894] = id_1903), ::dessser::VOID) };
                                                                            (void)id_1904;
                                                                            uint8_t id_1905 { 0 };
                                                                            uint8_t id_1906 { 0 };
                                                                            uint8_t id_1907 { shft_ref_360[id_1906] };
                                                                            uint8_t id_1908 { 7 };
                                                                            uint8_t id_1909 { uint8_t(id_1907 + id_1908) };
                                                                            Void id_1910 { ((void)(shft_ref_360[id_1905] = id_1909), ::dessser::VOID) };
                                                                            (void)id_1910;
                                                                            uint8_t id_1911 { 128 };
                                                                            bool id_1912 { bool(leb128_fst_363 >= id_1911) };
                                                                            letpair_res_1891 = id_1912;
                                                                          }
                                                                          let_res_1890 = letpair_res_1891;
                                                                        }
                                                                        while_flag_1886 = let_res_1890;
                                                                        if (while_flag_1886) {
                                                                          (void)::dessser::VOID;
                                                                        }
                                                                      } while (while_flag_1886);
                                                                      (void)::dessser::VOID;
                                                                      uint8_t id_1913 { 0 };
                                                                      uint32_t id_1914 { leb_ref_359[id_1913] };
                                                                      Size id_1915 { Size(id_1914) };
                                                                      uint8_t id_1916 { 0 };
                                                                      Pointer id_1917 { p_ref_361[id_1916] };
                                                                      ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1918 { id_1915, id_1917 };
                                                                      let_res_1885 = id_1918;
                                                                    }
                                                                    let_res_1883 = let_res_1885;
                                                                  }
                                                                  let_res_1880 = let_res_1883;
                                                                }
                                                                ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 let_res_1919;
                                                                {
                                                                  ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_365 { let_res_1880 };
                                                                  ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1920;
                                                                  {
                                                                    auto dstring1_fst_366 { std::get<0>(dstring1_365) };
                                                                    auto dstring1_snd_367 { std::get<1>(dstring1_365) };
                                                                    ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1921 { dstring1_snd_367.readBytes(dstring1_fst_366) };
                                                                    ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1922;
                                                                    {
                                                                      auto dstring2_fst_369 { std::get<0>(id_1921) };
                                                                      auto dstring2_snd_370 { std::get<1>(id_1921) };
                                                                      std::string id_1923 { dstring2_fst_369.toString() };
                                                                      ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 id_1924 { id_1923, dstring2_snd_370 };
                                                                      letpair_res_1922 = id_1924;
                                                                    }
                                                                    letpair_res_1920 = letpair_res_1922;
                                                                  }
                                                                  let_res_1919 = letpair_res_1920;
                                                                }
                                                                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1925;
                                                                {
                                                                  ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 drec_371 { let_res_1919 };
                                                                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1926;
                                                                  {
                                                                    auto drec_fst_372 { std::get<0>(drec_371) };
                                                                    auto drec_snd_373 { std::get<1>(drec_371) };
                                                                    uint32_t id_1927 { 0U };
                                                                    Vec<1, uint32_t> id_1928 {  id_1927  };
                                                                    ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1929;
                                                                    {
                                                                      Vec<1, uint32_t> leb_ref_374 { id_1928 };
                                                                      uint8_t id_1930 { 0 };
                                                                      Vec<1, uint8_t> id_1931 {  id_1930  };
                                                                      ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1932;
                                                                      {
                                                                        Vec<1, uint8_t> shft_ref_375 { id_1931 };
                                                                        Vec<1, Pointer> id_1933 {  drec_snd_373  };
                                                                        ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1934;
                                                                        {
                                                                          Vec<1, Pointer> p_ref_376 { id_1933 };
                                                                          bool while_flag_1935 { true };
                                                                          do {
                                                                            uint8_t id_1936 { 0 };
                                                                            Pointer id_1937 { p_ref_376[id_1936] };
                                                                            ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1938 { id_1937.readU8() };
                                                                            bool let_res_1939;
                                                                            {
                                                                              ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_377 { id_1938 };
                                                                              bool letpair_res_1940;
                                                                              {
                                                                                auto leb128_fst_378 { std::get<0>(leb128_377) };
                                                                                auto leb128_snd_379 { std::get<1>(leb128_377) };
                                                                                uint8_t id_1941 { 0 };
                                                                                Void id_1942 { ((void)(p_ref_376[id_1941] = leb128_snd_379), ::dessser::VOID) };
                                                                                (void)id_1942;
                                                                                uint8_t id_1943 { 0 };
                                                                                uint8_t id_1944 { 127 };
                                                                                uint8_t id_1945 { uint8_t(leb128_fst_378 & id_1944) };
                                                                                uint32_t id_1946 { uint32_t(id_1945) };
                                                                                uint8_t id_1947 { 0 };
                                                                                uint8_t id_1948 { shft_ref_375[id_1947] };
                                                                                uint32_t id_1949 { uint32_t(id_1946 << id_1948) };
                                                                                uint8_t id_1950 { 0 };
                                                                                uint32_t id_1951 { leb_ref_374[id_1950] };
                                                                                uint32_t id_1952 { uint32_t(id_1949 | id_1951) };
                                                                                Void id_1953 { ((void)(leb_ref_374[id_1943] = id_1952), ::dessser::VOID) };
                                                                                (void)id_1953;
                                                                                uint8_t id_1954 { 0 };
                                                                                uint8_t id_1955 { 0 };
                                                                                uint8_t id_1956 { shft_ref_375[id_1955] };
                                                                                uint8_t id_1957 { 7 };
                                                                                uint8_t id_1958 { uint8_t(id_1956 + id_1957) };
                                                                                Void id_1959 { ((void)(shft_ref_375[id_1954] = id_1958), ::dessser::VOID) };
                                                                                (void)id_1959;
                                                                                uint8_t id_1960 { 128 };
                                                                                bool id_1961 { bool(leb128_fst_378 >= id_1960) };
                                                                                letpair_res_1940 = id_1961;
                                                                              }
                                                                              let_res_1939 = letpair_res_1940;
                                                                            }
                                                                            while_flag_1935 = let_res_1939;
                                                                            if (while_flag_1935) {
                                                                              (void)::dessser::VOID;
                                                                            }
                                                                          } while (while_flag_1935);
                                                                          (void)::dessser::VOID;
                                                                          uint8_t id_1962 { 0 };
                                                                          uint32_t id_1963 { leb_ref_374[id_1962] };
                                                                          Size id_1964 { Size(id_1963) };
                                                                          uint8_t id_1965 { 0 };
                                                                          Pointer id_1966 { p_ref_376[id_1965] };
                                                                          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1967 { id_1964, id_1966 };
                                                                          let_res_1934 = id_1967;
                                                                        }
                                                                        let_res_1932 = let_res_1934;
                                                                      }
                                                                      let_res_1929 = let_res_1932;
                                                                    }
                                                                    ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 let_res_1968;
                                                                    {
                                                                      ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_380 { let_res_1929 };
                                                                      ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1969;
                                                                      {
                                                                        auto dstring1_fst_381 { std::get<0>(dstring1_380) };
                                                                        auto dstring1_snd_382 { std::get<1>(dstring1_380) };
                                                                        ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1970 { dstring1_snd_382.readBytes(dstring1_fst_381) };
                                                                        ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1971;
                                                                        {
                                                                          auto dstring2_fst_384 { std::get<0>(id_1970) };
                                                                          auto dstring2_snd_385 { std::get<1>(id_1970) };
                                                                          std::string id_1972 { dstring2_fst_384.toString() };
                                                                          ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 id_1973 { id_1972, dstring2_snd_385 };
                                                                          letpair_res_1971 = id_1973;
                                                                        }
                                                                        letpair_res_1969 = letpair_res_1971;
                                                                      }
                                                                      let_res_1968 = letpair_res_1969;
                                                                    }
                                                                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1974;
                                                                    {
                                                                      ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 drec_386 { let_res_1968 };
                                                                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1975;
                                                                      {
                                                                        auto drec_fst_387 { std::get<0>(drec_386) };
                                                                        auto drec_snd_388 { std::get<1>(drec_386) };
                                                                        uint32_t id_1976 { 0U };
                                                                        Vec<1, uint32_t> id_1977 {  id_1976  };
                                                                        ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1978;
                                                                        {
                                                                          Vec<1, uint32_t> leb_ref_389 { id_1977 };
                                                                          uint8_t id_1979 { 0 };
                                                                          Vec<1, uint8_t> id_1980 {  id_1979  };
                                                                          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1981;
                                                                          {
                                                                            Vec<1, uint8_t> shft_ref_390 { id_1980 };
                                                                            Vec<1, Pointer> id_1982 {  drec_snd_388  };
                                                                            ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1983;
                                                                            {
                                                                              Vec<1, Pointer> p_ref_391 { id_1982 };
                                                                              bool while_flag_1984 { true };
                                                                              do {
                                                                                uint8_t id_1985 { 0 };
                                                                                Pointer id_1986 { p_ref_391[id_1985] };
                                                                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1987 { id_1986.readU8() };
                                                                                bool let_res_1988;
                                                                                {
                                                                                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_392 { id_1987 };
                                                                                  bool letpair_res_1989;
                                                                                  {
                                                                                    auto leb128_fst_393 { std::get<0>(leb128_392) };
                                                                                    auto leb128_snd_394 { std::get<1>(leb128_392) };
                                                                                    uint8_t id_1990 { 0 };
                                                                                    Void id_1991 { ((void)(p_ref_391[id_1990] = leb128_snd_394), ::dessser::VOID) };
                                                                                    (void)id_1991;
                                                                                    uint8_t id_1992 { 0 };
                                                                                    uint8_t id_1993 { 127 };
                                                                                    uint8_t id_1994 { uint8_t(leb128_fst_393 & id_1993) };
                                                                                    uint32_t id_1995 { uint32_t(id_1994) };
                                                                                    uint8_t id_1996 { 0 };
                                                                                    uint8_t id_1997 { shft_ref_390[id_1996] };
                                                                                    uint32_t id_1998 { uint32_t(id_1995 << id_1997) };
                                                                                    uint8_t id_1999 { 0 };
                                                                                    uint32_t id_2000 { leb_ref_389[id_1999] };
                                                                                    uint32_t id_2001 { uint32_t(id_1998 | id_2000) };
                                                                                    Void id_2002 { ((void)(leb_ref_389[id_1992] = id_2001), ::dessser::VOID) };
                                                                                    (void)id_2002;
                                                                                    uint8_t id_2003 { 0 };
                                                                                    uint8_t id_2004 { 0 };
                                                                                    uint8_t id_2005 { shft_ref_390[id_2004] };
                                                                                    uint8_t id_2006 { 7 };
                                                                                    uint8_t id_2007 { uint8_t(id_2005 + id_2006) };
                                                                                    Void id_2008 { ((void)(shft_ref_390[id_2003] = id_2007), ::dessser::VOID) };
                                                                                    (void)id_2008;
                                                                                    uint8_t id_2009 { 128 };
                                                                                    bool id_2010 { bool(leb128_fst_393 >= id_2009) };
                                                                                    letpair_res_1989 = id_2010;
                                                                                  }
                                                                                  let_res_1988 = letpair_res_1989;
                                                                                }
                                                                                while_flag_1984 = let_res_1988;
                                                                                if (while_flag_1984) {
                                                                                  (void)::dessser::VOID;
                                                                                }
                                                                              } while (while_flag_1984);
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_2011 { 0 };
                                                                              uint32_t id_2012 { leb_ref_389[id_2011] };
                                                                              Size id_2013 { Size(id_2012) };
                                                                              uint8_t id_2014 { 0 };
                                                                              Pointer id_2015 { p_ref_391[id_2014] };
                                                                              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_2016 { id_2013, id_2015 };
                                                                              let_res_1983 = id_2016;
                                                                            }
                                                                            let_res_1981 = let_res_1983;
                                                                          }
                                                                          let_res_1978 = let_res_1981;
                                                                        }
                                                                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_2017;
                                                                        {
                                                                          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_395 { let_res_1978 };
                                                                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_2018;
                                                                          {
                                                                            auto dstring1_fst_396 { std::get<0>(dstring1_395) };
                                                                            auto dstring1_snd_397 { std::get<1>(dstring1_395) };
                                                                            ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_2019 { dstring1_snd_397.readBytes(dstring1_fst_396) };
                                                                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_2020;
                                                                            {
                                                                              auto dstring2_fst_399 { std::get<0>(id_2019) };
                                                                              auto dstring2_snd_400 { std::get<1>(id_2019) };
                                                                              std::string id_2021 { dstring2_fst_399.toString() };
                                                                              std::shared_ptr<::dessser::gen::alert::t>  id_2022 { std::make_shared<::dessser::gen::alert::t>(drec_fst_147, drec_fst_150, drec_fst_156, drec_fst_182, drec_fst_211, drec_fst_237, drec_fst_240, drec_fst_246, drec_fst_252, drec_fst_258, drec_fst_264, drec_fst_290, drec_fst_316, drec_fst_342, drec_fst_357, drec_fst_372, drec_fst_387, id_2021) };
                                                                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 id_2023 { id_2022, dstring2_snd_400 };
                                                                              letpair_res_2020 = id_2023;
                                                                            }
                                                                            letpair_res_2018 = letpair_res_2020;
                                                                          }
                                                                          let_res_2017 = letpair_res_2018;
                                                                        }
                                                                        letpair_res_1975 = let_res_2017;
                                                                      }
                                                                      let_res_1974 = letpair_res_1975;
                                                                    }
                                                                    letpair_res_1926 = let_res_1974;
                                                                  }
                                                                  let_res_1925 = letpair_res_1926;
                                                                }
                                                                letpair_res_1877 = let_res_1925;
                                                              }
                                                              let_res_1876 = letpair_res_1877;
                                                            }
                                                            letpair_res_1828 = let_res_1876;
                                                          }
                                                          let_res_1827 = letpair_res_1828;
                                                        }
                                                        letpair_res_1755 = let_res_1827;
                                                      }
                                                      let_res_1754 = letpair_res_1755;
                                                    }
                                                    letpair_res_1681 = let_res_1754;
                                                  }
                                                  let_res_1680 = letpair_res_1681;
                                                }
                                                letpair_res_1607 = let_res_1680;
                                              }
                                              let_res_1606 = letpair_res_1607;
                                            }
                                            letpair_res_1601 = let_res_1606;
                                          }
                                          let_res_1600 = letpair_res_1601;
                                        }
                                        letpair_res_1595 = let_res_1600;
                                      }
                                      let_res_1594 = letpair_res_1595;
                                    }
                                    letpair_res_1589 = let_res_1594;
                                  }
                                  let_res_1588 = letpair_res_1589;
                                }
                                letpair_res_1583 = let_res_1588;
                              }
                              let_res_1582 = letpair_res_1583;
                            }
                            letpair_res_1580 = let_res_1582;
                          }
                          let_res_1579 = letpair_res_1580;
                        }
                        letpair_res_1506 = let_res_1579;
                      }
                      let_res_1505 = letpair_res_1506;
                    }
                    letpair_res_1420 = let_res_1505;
                  }
                  let_res_1419 = letpair_res_1420;
                }
                letpair_res_1346 = let_res_1419;
              }
              let_res_1345 = letpair_res_1346;
            }
            letpair_res_1338 = let_res_1345;
          }
          let_res_1337 = letpair_res_1338;
        }
        letpair_res_1334 = let_res_1337;
      }
      let_res_1333 = letpair_res_1334;
    }
    return let_res_1333;
  }
   };
  return fun1330;
}
std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_405" "make_snd_406" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_405") (identifier "make_snd_406"))))
 */
static std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> fun2024 { [&fun2024](Pointer p_0) {
    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 id_2025 { of_row_binary(p_0) };
    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_2026;
    {
      auto make_fst_405 { std::get<0>(id_2025) };
      auto make_snd_406 { std::get<1>(id_2025) };
      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 id_2027 { make_fst_405, make_snd_406 };
      letpair_res_2026 = id_2027;
    }
    return letpair_res_2026;
  }
   };
  return fun2024;
}
std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[[]]; group-by: $field_name[[]]?; having: $simple_filter[[]]; threshold: (threshold AS [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]); hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[[]]; carry-fields: $field_name[[]]; carry-csts: (constant AS {name: $field_name; value: STRING})[[]]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> fun2028 { [&fun2028](std::shared_ptr<::dessser::gen::alert::t>  p_0, Pointer p_1) {
    Pointer id_2029 { to_row_binary(p_0, p_1) };
    return id_2029;
  }
   };
  return fun2028;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
