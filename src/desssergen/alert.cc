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
  Arr<dessser::gen::simple_filter::t_ext> where;
  std::optional<Arr<dessser::gen::field_name::t_ext>> group_by;
  Arr<dessser::gen::simple_filter::t_ext> having;
  std::shared_ptr<::dessser::gen::alert::threshold>  threshold;
  double hysteresis;
  double duration;
  double ratio;
  double time_step;
  Arr<dessser::gen::field_name::t_ext> tops;
  Arr<dessser::gen::field_name::t_ext> carry_fields;
  Arr<std::shared_ptr<::dessser::gen::alert::constant> > carry_csts;
  std::string id;
  std::string desc_title;
  std::string desc_firing;
  std::string desc_recovery;
  t(dessser::gen::fq_name::t_ext table_, dessser::gen::field_name::t_ext column_, bool enabled_, Arr<dessser::gen::simple_filter::t_ext> where_, std::optional<Arr<dessser::gen::field_name::t_ext>> group_by_, Arr<dessser::gen::simple_filter::t_ext> having_, std::shared_ptr<::dessser::gen::alert::threshold>  threshold_, double hysteresis_, double duration_, double ratio_, double time_step_, Arr<dessser::gen::field_name::t_ext> tops_, Arr<dessser::gen::field_name::t_ext> carry_fields_, Arr<std::shared_ptr<::dessser::gen::alert::constant> > carry_csts_, std::string id_, std::string desc_title_, std::string desc_firing_, std::string desc_recovery_) : table(table_), column(column_), enabled(enabled_), where(where_), group_by(group_by_), having(having_), threshold(threshold_), hysteresis(hysteresis_), duration(duration_), ratio(ratio_), time_step(time_step_), tops(tops_), carry_fields(carry_fields_), carry_csts(carry_csts_), id(id_), desc_title(desc_title_), desc_firing(desc_firing_), desc_recovery(desc_recovery_) {}
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
struct td403d13122fd20ecb97f01e7b85a9dea : public std::tuple<
  Arr<dessser::gen::simple_filter::t_ext>,
  Pointer
> {
  using tuple::tuple;
  td403d13122fd20ecb97f01e7b85a9dea(std::tuple<Arr<dessser::gen::simple_filter::t_ext>, Pointer> p)
    : std::tuple<Arr<dessser::gen::simple_filter::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td403d13122fd20ecb97f01e7b85a9dea const &a, td403d13122fd20ecb97f01e7b85a9dea const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td403d13122fd20ecb97f01e7b85a9dea const &a, td403d13122fd20ecb97f01e7b85a9dea const &b) {
  return !operator==(a, b);
}
struct t0792b3e797566a05cd2e25d5f448d59b : public std::tuple<
  std::optional<Arr<dessser::gen::field_name::t_ext>>,
  Pointer
> {
  using tuple::tuple;
  t0792b3e797566a05cd2e25d5f448d59b(std::tuple<std::optional<Arr<dessser::gen::field_name::t_ext>>, Pointer> p)
    : std::tuple<std::optional<Arr<dessser::gen::field_name::t_ext>>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0792b3e797566a05cd2e25d5f448d59b const &a, t0792b3e797566a05cd2e25d5f448d59b const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0792b3e797566a05cd2e25d5f448d59b const &a, t0792b3e797566a05cd2e25d5f448d59b const &b) {
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
struct t5f8c7f0089c13d8e90b66cd6d8db085d : public std::tuple<
  Arr<dessser::gen::field_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t5f8c7f0089c13d8e90b66cd6d8db085d(std::tuple<Arr<dessser::gen::field_name::t_ext>, Pointer> p)
    : std::tuple<Arr<dessser::gen::field_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5f8c7f0089c13d8e90b66cd6d8db085d const &a, t5f8c7f0089c13d8e90b66cd6d8db085d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5f8c7f0089c13d8e90b66cd6d8db085d const &a, t5f8c7f0089c13d8e90b66cd6d8db085d const &b) {
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
struct t039e94b31ddf5a8d0097a51fda754c54 : public std::tuple<
  Arr<std::shared_ptr<::dessser::gen::alert::constant> >,
  Pointer
> {
  using tuple::tuple;
  t039e94b31ddf5a8d0097a51fda754c54(std::tuple<Arr<std::shared_ptr<::dessser::gen::alert::constant> >, Pointer> p)
    : std::tuple<Arr<std::shared_ptr<::dessser::gen::alert::constant> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t039e94b31ddf5a8d0097a51fda754c54 const &a, t039e94b31ddf5a8d0097a51fda754c54 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t039e94b31ddf5a8d0097a51fda754c54 const &a, t039e94b31ddf5a8d0097a51fda754c54 const &b) {
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
      (let "srec_dst_484" (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (param 1))
        (write-bytes
          (let "leb128_sz_485" (make-vec (string-length (get-field "value" (param 0))))
            (let "leb128_ptr_486" (make-vec (identifier "srec_dst_484"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_486")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_486"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_485"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_485"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_485"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_485") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_485")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_485")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_486"))))) 
          (bytes-of-string (get-field "value" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::constant> ,Pointer)> constant_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::constant> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::alert::constant>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { (*p_0).name };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_484 { id_3 };
      std::string id_5 { (*p_0).value };
      uint32_t id_6 { (uint32_t)id_5.size() };
      Vec<1, uint32_t> id_7 {  id_6  };
      Pointer let_res_8;
      {
        Vec<1, uint32_t> leb128_sz_485 { id_7 };
        Vec<1, Pointer> id_9 {  srec_dst_484  };
        Pointer let_res_10;
        {
          Vec<1, Pointer> leb128_ptr_486 { id_9 };
          bool while_flag_11 { true };
          do {
            uint8_t id_12 { 0 };
            uint8_t id_13 { 0 };
            Pointer id_14 { leb128_ptr_486[id_13] };
            uint32_t id_15 { 128U };
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_485[id_16] };
            bool id_18 { bool(id_15 > id_17) };
            uint8_t choose_res_19;
            if (id_18) {
              uint8_t id_20 { 0 };
              uint32_t id_21 { leb128_sz_485[id_20] };
              uint8_t id_22 { uint8_t(id_21) };
              choose_res_19 = id_22;
            } else {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_485[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              uint8_t id_26 { 128 };
              uint8_t id_27 { uint8_t(id_25 | id_26) };
              choose_res_19 = id_27;
            }
            Pointer id_28 { id_14.writeU8(choose_res_19) };
            Void id_29 { ((void)(leb128_ptr_486[id_12] = id_28), ::dessser::Void()) };
            (void)id_29;
            uint8_t id_30 { 0 };
            uint8_t id_31 { 0 };
            uint32_t id_32 { leb128_sz_485[id_31] };
            uint8_t id_33 { 7 };
            uint32_t id_34 { uint32_t(id_32 >> id_33) };
            Void id_35 { ((void)(leb128_sz_485[id_30] = id_34), ::dessser::Void()) };
            (void)id_35;
            uint8_t id_36 { 0 };
            uint32_t id_37 { leb128_sz_485[id_36] };
            uint32_t id_38 { 0U };
            bool id_39 { bool(id_37 > id_38) };
            while_flag_11 = id_39;
            if (while_flag_11) {
              (void)::dessser::Void();
            }
          } while (while_flag_11);
          (void)::dessser::Void();
          uint8_t id_40 { 0 };
          Pointer id_41 { leb128_ptr_486[id_40] };
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
      (let "ssum_dst_476" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (write-u64 little-endian (identifier "ssum_dst_476") (u64-of-float (get-alt "Constant" (param 0))))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_481"
              (let "srec_dst_480"
                (let "srec_dst_479"
                  (let "srec_dst_478"
                    (let "srec_dst_477" (write-u64 little-endian (identifier "ssum_dst_476") (u64-of-float (get-field "avg_window" (get-alt "Baseline" (param 0)))))
                      (write-u32 little-endian (identifier "srec_dst_477") (get-field "sample_size" (get-alt "Baseline" (param 0)))))
                    (write-u64 little-endian (identifier "srec_dst_478") (u64-of-float (get-field "percentile" (get-alt "Baseline" (param 0))))))
                  (write-u32 little-endian (identifier "srec_dst_479") (get-field "seasonality" (get-alt "Baseline" (param 0)))))
                (write-u64 little-endian (identifier "srec_dst_480") (u64-of-float (get-field "smooth_factor" (get-alt "Baseline" (param 0))))))
              (let "ssum_dst_483" (write-u16 little-endian (identifier "srec_dst_481") (label-of (get-field "max_distance" (get-alt "Baseline" (param 0)))))
                (if (eq (u16 0) (label-of (get-field "max_distance" (get-alt "Baseline" (param 0)))))
                  (write-u64 little-endian (identifier "ssum_dst_483") (u64-of-float (get-alt "Absolute" (get-field "max_distance" (get-alt "Baseline" (param 0))))))
                  (seq (assert (eq (label-of (get-field "max_distance" (get-alt "Baseline" (param 0)))) (u16 1)))
                    (write-u64 little-endian (identifier "ssum_dst_483") (u64-of-float (get-alt "Relative" (get-field "max_distance" (get-alt "Baseline" (param 0))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::threshold> ,Pointer)> threshold_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::threshold> ,Pointer)> fun45 { [&](std::shared_ptr<::dessser::gen::alert::threshold>  p_0, Pointer p_1) {
    uint16_t id_46 { uint16_t((*p_0).index()) };
    Pointer id_47 { p_1.writeU16Le(id_46) };
    Pointer let_res_48;
    {
      Pointer ssum_dst_476 { id_47 };
      uint16_t id_49 { 0 };
      uint16_t id_50 { uint16_t((*p_0).index()) };
      bool id_51 { bool(id_49 == id_50) };
      Pointer choose_res_52;
      if (id_51) {
        double id_53 { std::get<0 /* Constant */>((*p_0)) };
        uint64_t id_54 { qword_of_float(id_53) };
        Pointer id_55 { ssum_dst_476.writeU64Le(id_54) };
        choose_res_52 = id_55;
      } else {
        uint16_t id_56 { uint16_t((*p_0).index()) };
        uint16_t id_57 { 1 };
        bool id_58 { bool(id_56 == id_57) };
        Void id_59 { ((void)(assert(id_58)), ::dessser::Void()) };
        (void)id_59;
        ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_60 { std::get<1 /* Baseline */>((*p_0)) };
        double id_61 { id_60.avg_window };
        uint64_t id_62 { qword_of_float(id_61) };
        Pointer id_63 { ssum_dst_476.writeU64Le(id_62) };
        Pointer let_res_64;
        {
          Pointer srec_dst_477 { id_63 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_65 { std::get<1 /* Baseline */>((*p_0)) };
          uint32_t id_66 { id_65.sample_size };
          Pointer id_67 { srec_dst_477.writeU32Le(id_66) };
          let_res_64 = id_67;
        }
        Pointer let_res_68;
        {
          Pointer srec_dst_478 { let_res_64 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_69 { std::get<1 /* Baseline */>((*p_0)) };
          double id_70 { id_69.percentile };
          uint64_t id_71 { qword_of_float(id_70) };
          Pointer id_72 { srec_dst_478.writeU64Le(id_71) };
          let_res_68 = id_72;
        }
        Pointer let_res_73;
        {
          Pointer srec_dst_479 { let_res_68 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_74 { std::get<1 /* Baseline */>((*p_0)) };
          uint32_t id_75 { id_74.seasonality };
          Pointer id_76 { srec_dst_479.writeU32Le(id_75) };
          let_res_73 = id_76;
        }
        Pointer let_res_77;
        {
          Pointer srec_dst_480 { let_res_73 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_78 { std::get<1 /* Baseline */>((*p_0)) };
          double id_79 { id_78.smooth_factor };
          uint64_t id_80 { qword_of_float(id_79) };
          Pointer id_81 { srec_dst_480.writeU64Le(id_80) };
          let_res_77 = id_81;
        }
        Pointer let_res_82;
        {
          Pointer srec_dst_481 { let_res_77 };
          ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_83 { std::get<1 /* Baseline */>((*p_0)) };
          ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_84 { id_83.max_distance };
          uint16_t id_85 { uint16_t(id_84.index()) };
          Pointer id_86 { srec_dst_481.writeU16Le(id_85) };
          Pointer let_res_87;
          {
            Pointer ssum_dst_483 { id_86 };
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
              Pointer id_98 { ssum_dst_483.writeU64Le(id_97) };
              choose_res_93 = id_98;
            } else {
              ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_99 { std::get<1 /* Baseline */>((*p_0)) };
              ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_100 { id_99.max_distance };
              uint16_t id_101 { uint16_t(id_100.index()) };
              uint16_t id_102 { 1 };
              bool id_103 { bool(id_101 == id_102) };
              Void id_104 { ((void)(assert(id_103)), ::dessser::Void()) };
              (void)id_104;
              ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_105 { std::get<1 /* Baseline */>((*p_0)) };
              ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_106 { id_105.max_distance };
              double id_107 { std::get<1 /* Relative */>(id_106) };
              uint64_t id_108 { qword_of_float(id_107) };
              Pointer id_109 { ssum_dst_483.writeU64Le(id_108) };
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
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[]; group-by: $field_name[]?; having: $simple_filter[]; threshold: (threshold AS [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]); hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[]; carry-fields: $field_name[]; carry-csts: (constant AS {name: $field_name; value: STRING})[]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}" "Ptr")
      (let "srec_dst_539"
        (let "srec_dst_536"
          (let "srec_dst_533"
            (let "srec_dst_530"
              (let "srec_dst_524"
                (let "srec_dst_518"
                  (let "srec_dst_512"
                    (let "srec_dst_511"
                      (let "srec_dst_510"
                        (let "srec_dst_509"
                          (let "srec_dst_508"
                            (let "srec_dst_507"
                              (let "srec_dst_501"
                                (let "srec_dst_495"
                                  (let "srec_dst_489"
                                    (let "srec_dst_488"
                                      (let "srec_dst_487" (apply (ext-identifier fq_name to-row-binary) (get-field "table" (param 0)) (param 1))
                                        (apply (ext-identifier field_name to-row-binary) (get-field "column" (param 0)) (identifier "srec_dst_487")))
                                      (write-u8 (identifier "srec_dst_488") (u8-of-bool (get-field "enabled" (param 0)))))
                                    (let "dst_ref_492"
                                      (make-vec
                                        (let "leb128_sz_490" (make-vec (cardinality (get-field "where" (param 0))))
                                          (let "leb128_ptr_491" (make-vec (identifier "srec_dst_489"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_491")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_491"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_490"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_490"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_490"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_490") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_490")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_490")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_491"))))))
                                      (let "n_ref_493" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_494" (get-field "where" (param 0))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_492") (apply (ext-identifier simple_filter to-row-binary) (identifier "x_494") (unsafe-nth (u8 0) (identifier "dst_ref_492"))))
                                              (set-vec (u8 0) (identifier "n_ref_493") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_493")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_492"))))))
                                  (if (is-null (get-field "group-by" (param 0))) 
                                    (write-u8 (identifier "srec_dst_495") (u8 1))
                                    (let "dst_ref_498"
                                      (make-vec
                                        (let "leb128_sz_496" (make-vec (cardinality (force (get-field "group-by" (param 0)))))
                                          (let "leb128_ptr_497" (make-vec (write-u8 (identifier "srec_dst_495") (u8 0)))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_497")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_497"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_496"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_496"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_496"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_496") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_496")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_496")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_497"))))))
                                      (let "n_ref_499" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_500" (force (get-field "group-by" (param 0)))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_498") (apply (ext-identifier field_name to-row-binary) (identifier "x_500") (unsafe-nth (u8 0) (identifier "dst_ref_498"))))
                                              (set-vec (u8 0) (identifier "n_ref_499") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_499")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_498")))))))
                                (let "dst_ref_504"
                                  (make-vec
                                    (let "leb128_sz_502" (make-vec (cardinality (get-field "having" (param 0))))
                                      (let "leb128_ptr_503" (make-vec (identifier "srec_dst_501"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_503")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_503"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_502"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_502"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_502"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_502") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_502")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_502")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_503"))))))
                                  (let "n_ref_505" (make-vec (i32 0))
                                    (seq
                                      (for-each "x_506" (get-field "having" (param 0))
                                        (seq (set-vec (u8 0) (identifier "dst_ref_504") (apply (ext-identifier simple_filter to-row-binary) (identifier "x_506") (unsafe-nth (u8 0) (identifier "dst_ref_504"))))
                                          (set-vec (u8 0) (identifier "n_ref_505") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_505")))))) 
                                      (unsafe-nth (u8 0) (identifier "dst_ref_504")))))) 
                              (apply (identifier "threshold-to-row-binary") (get-field "threshold" (param 0)) (identifier "srec_dst_507")))
                            (write-u64 little-endian (identifier "srec_dst_508") (u64-of-float (get-field "hysteresis" (param 0)))))
                          (write-u64 little-endian (identifier "srec_dst_509") (u64-of-float (get-field "duration" (param 0))))) 
                        (write-u64 little-endian (identifier "srec_dst_510") (u64-of-float (get-field "ratio" (param 0))))) 
                      (write-u64 little-endian (identifier "srec_dst_511") (u64-of-float (get-field "time-step" (param 0)))))
                    (let "dst_ref_515"
                      (make-vec
                        (let "leb128_sz_513" (make-vec (cardinality (get-field "tops" (param 0))))
                          (let "leb128_ptr_514" (make-vec (identifier "srec_dst_512"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_514")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_514"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_513"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_513"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_513"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_513") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_513")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_513")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_514"))))))
                      (let "n_ref_516" (make-vec (i32 0))
                        (seq
                          (for-each "x_517" (get-field "tops" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_515") (apply (ext-identifier field_name to-row-binary) (identifier "x_517") (unsafe-nth (u8 0) (identifier "dst_ref_515"))))
                              (set-vec (u8 0) (identifier "n_ref_516") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_516")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_515"))))))
                  (let "dst_ref_521"
                    (make-vec
                      (let "leb128_sz_519" (make-vec (cardinality (get-field "carry-fields" (param 0))))
                        (let "leb128_ptr_520" (make-vec (identifier "srec_dst_518"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_520")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_520"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_519"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_519"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_519"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_519") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_519")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_519")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_520"))))))
                    (let "n_ref_522" (make-vec (i32 0))
                      (seq
                        (for-each "x_523" (get-field "carry-fields" (param 0))
                          (seq (set-vec (u8 0) (identifier "dst_ref_521") (apply (ext-identifier field_name to-row-binary) (identifier "x_523") (unsafe-nth (u8 0) (identifier "dst_ref_521"))))
                            (set-vec (u8 0) (identifier "n_ref_522") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_522")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_521"))))))
                (let "dst_ref_527"
                  (make-vec
                    (let "leb128_sz_525" (make-vec (cardinality (get-field "carry-csts" (param 0))))
                      (let "leb128_ptr_526" (make-vec (identifier "srec_dst_524"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_526")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_526"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_525"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_525"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_525"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_525") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_525")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_525")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_526"))))))
                  (let "n_ref_528" (make-vec (i32 0))
                    (seq
                      (for-each "x_529" (get-field "carry-csts" (param 0))
                        (seq (set-vec (u8 0) (identifier "dst_ref_527") (apply (identifier "constant-to-row-binary") (identifier "x_529") (unsafe-nth (u8 0) (identifier "dst_ref_527"))))
                          (set-vec (u8 0) (identifier "n_ref_528") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_528")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_527"))))))
              (write-bytes
                (let "leb128_sz_531" (make-vec (string-length (get-field "id" (param 0))))
                  (let "leb128_ptr_532" (make-vec (identifier "srec_dst_530"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_532")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_532"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_531"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_531"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_531"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_531") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_531")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_531")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_532"))))) 
                (bytes-of-string (get-field "id" (param 0)))))
            (write-bytes
              (let "leb128_sz_534" (make-vec (string-length (get-field "desc-title" (param 0))))
                (let "leb128_ptr_535" (make-vec (identifier "srec_dst_533"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_535")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_535"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_534"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_534"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_534"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_534") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_534")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_534")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_535"))))) 
              (bytes-of-string (get-field "desc-title" (param 0)))))
          (write-bytes
            (let "leb128_sz_537" (make-vec (string-length (get-field "desc-firing" (param 0))))
              (let "leb128_ptr_538" (make-vec (identifier "srec_dst_536"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_538")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_538"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_537"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_537"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_537"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_537") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_537")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_537")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_538"))))) 
            (bytes-of-string (get-field "desc-firing" (param 0)))))
        (write-bytes
          (let "leb128_sz_540" (make-vec (string-length (get-field "desc-recovery" (param 0))))
            (let "leb128_ptr_541" (make-vec (identifier "srec_dst_539"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_541")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_541"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_540"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_540"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_540"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_540") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_540")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_540")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_541"))))) 
          (bytes-of-string (get-field "desc-recovery" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> fun110 { [&](std::shared_ptr<::dessser::gen::alert::t>  p_0, Pointer p_1) {
    auto fun111 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_112 { (*p_0).table };
    Pointer id_113 { fun111(id_112, p_1) };
    Pointer let_res_114;
    {
      Pointer srec_dst_487 { id_113 };
      auto fun115 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_116 { (*p_0).column };
      Pointer id_117 { fun115(id_116, srec_dst_487) };
      let_res_114 = id_117;
    }
    Pointer let_res_118;
    {
      Pointer srec_dst_488 { let_res_114 };
      bool id_119 { (*p_0).enabled };
      uint8_t id_120 { uint8_t(id_119) };
      Pointer id_121 { srec_dst_488.writeU8(id_120) };
      let_res_118 = id_121;
    }
    Pointer let_res_122;
    {
      Pointer srec_dst_489 { let_res_118 };
      Arr<dessser::gen::simple_filter::t_ext> id_123 { (*p_0).where };
      uint32_t id_124 { id_123.size() };
      Vec<1, uint32_t> id_125 {  id_124  };
      Pointer let_res_126;
      {
        Vec<1, uint32_t> leb128_sz_490 { id_125 };
        Vec<1, Pointer> id_127 {  srec_dst_489  };
        Pointer let_res_128;
        {
          Vec<1, Pointer> leb128_ptr_491 { id_127 };
          bool while_flag_129 { true };
          do {
            uint8_t id_130 { 0 };
            uint8_t id_131 { 0 };
            Pointer id_132 { leb128_ptr_491[id_131] };
            uint32_t id_133 { 128U };
            uint8_t id_134 { 0 };
            uint32_t id_135 { leb128_sz_490[id_134] };
            bool id_136 { bool(id_133 > id_135) };
            uint8_t choose_res_137;
            if (id_136) {
              uint8_t id_138 { 0 };
              uint32_t id_139 { leb128_sz_490[id_138] };
              uint8_t id_140 { uint8_t(id_139) };
              choose_res_137 = id_140;
            } else {
              uint8_t id_141 { 0 };
              uint32_t id_142 { leb128_sz_490[id_141] };
              uint8_t id_143 { uint8_t(id_142) };
              uint8_t id_144 { 128 };
              uint8_t id_145 { uint8_t(id_143 | id_144) };
              choose_res_137 = id_145;
            }
            Pointer id_146 { id_132.writeU8(choose_res_137) };
            Void id_147 { ((void)(leb128_ptr_491[id_130] = id_146), ::dessser::Void()) };
            (void)id_147;
            uint8_t id_148 { 0 };
            uint8_t id_149 { 0 };
            uint32_t id_150 { leb128_sz_490[id_149] };
            uint8_t id_151 { 7 };
            uint32_t id_152 { uint32_t(id_150 >> id_151) };
            Void id_153 { ((void)(leb128_sz_490[id_148] = id_152), ::dessser::Void()) };
            (void)id_153;
            uint8_t id_154 { 0 };
            uint32_t id_155 { leb128_sz_490[id_154] };
            uint32_t id_156 { 0U };
            bool id_157 { bool(id_155 > id_156) };
            while_flag_129 = id_157;
            if (while_flag_129) {
              (void)::dessser::Void();
            }
          } while (while_flag_129);
          (void)::dessser::Void();
          uint8_t id_158 { 0 };
          Pointer id_159 { leb128_ptr_491[id_158] };
          let_res_128 = id_159;
        }
        let_res_126 = let_res_128;
      }
      Vec<1, Pointer> id_160 {  let_res_126  };
      Pointer let_res_161;
      {
        Vec<1, Pointer> dst_ref_492 { id_160 };
        int32_t id_162 { 0L };
        Vec<1, int32_t> id_163 {  id_162  };
        Pointer let_res_164;
        {
          Vec<1, int32_t> n_ref_493 { id_163 };
          Arr<dessser::gen::simple_filter::t_ext> id_165 { (*p_0).where };
          for (dessser::gen::simple_filter::t_ext &x_494 : id_165) {
            uint8_t id_166 { 0 };
            auto fun167 { dessser::gen::simple_filter::to_row_binary };
            uint8_t id_168 { 0 };
            Pointer id_169 { dst_ref_492[id_168] };
            Pointer id_170 { fun167(x_494, id_169) };
            Void id_171 { ((void)(dst_ref_492[id_166] = id_170), ::dessser::Void()) };
            (void)id_171;
            uint8_t id_172 { 0 };
            int32_t id_173 { 1L };
            uint8_t id_174 { 0 };
            int32_t id_175 { n_ref_493[id_174] };
            int32_t id_176 { int32_t(id_173 + id_175) };
            Void id_177 { ((void)(n_ref_493[id_172] = id_176), ::dessser::Void()) };
            (void)id_177;
            (void)id_177;
          }
          (void)::dessser::Void();
          uint8_t id_178 { 0 };
          Pointer id_179 { dst_ref_492[id_178] };
          let_res_164 = id_179;
        }
        let_res_161 = let_res_164;
      }
      let_res_122 = let_res_161;
    }
    Pointer let_res_180;
    {
      Pointer srec_dst_495 { let_res_122 };
      std::optional<Arr<dessser::gen::field_name::t_ext>> id_181 { (*p_0).group_by };
      bool id_182 { !(id_181.has_value ()) };
      Pointer choose_res_183;
      if (id_182) {
        uint8_t id_184 { 1 };
        Pointer id_185 { srec_dst_495.writeU8(id_184) };
        choose_res_183 = id_185;
      } else {
        std::optional<Arr<dessser::gen::field_name::t_ext>> id_186 { (*p_0).group_by };
        Arr<dessser::gen::field_name::t_ext> id_187 { id_186.value() };
        uint32_t id_188 { id_187.size() };
        Vec<1, uint32_t> id_189 {  id_188  };
        Pointer let_res_190;
        {
          Vec<1, uint32_t> leb128_sz_496 { id_189 };
          uint8_t id_191 { 0 };
          Pointer id_192 { srec_dst_495.writeU8(id_191) };
          Vec<1, Pointer> id_193 {  id_192  };
          Pointer let_res_194;
          {
            Vec<1, Pointer> leb128_ptr_497 { id_193 };
            bool while_flag_195 { true };
            do {
              uint8_t id_196 { 0 };
              uint8_t id_197 { 0 };
              Pointer id_198 { leb128_ptr_497[id_197] };
              uint32_t id_199 { 128U };
              uint8_t id_200 { 0 };
              uint32_t id_201 { leb128_sz_496[id_200] };
              bool id_202 { bool(id_199 > id_201) };
              uint8_t choose_res_203;
              if (id_202) {
                uint8_t id_204 { 0 };
                uint32_t id_205 { leb128_sz_496[id_204] };
                uint8_t id_206 { uint8_t(id_205) };
                choose_res_203 = id_206;
              } else {
                uint8_t id_207 { 0 };
                uint32_t id_208 { leb128_sz_496[id_207] };
                uint8_t id_209 { uint8_t(id_208) };
                uint8_t id_210 { 128 };
                uint8_t id_211 { uint8_t(id_209 | id_210) };
                choose_res_203 = id_211;
              }
              Pointer id_212 { id_198.writeU8(choose_res_203) };
              Void id_213 { ((void)(leb128_ptr_497[id_196] = id_212), ::dessser::Void()) };
              (void)id_213;
              uint8_t id_214 { 0 };
              uint8_t id_215 { 0 };
              uint32_t id_216 { leb128_sz_496[id_215] };
              uint8_t id_217 { 7 };
              uint32_t id_218 { uint32_t(id_216 >> id_217) };
              Void id_219 { ((void)(leb128_sz_496[id_214] = id_218), ::dessser::Void()) };
              (void)id_219;
              uint8_t id_220 { 0 };
              uint32_t id_221 { leb128_sz_496[id_220] };
              uint32_t id_222 { 0U };
              bool id_223 { bool(id_221 > id_222) };
              while_flag_195 = id_223;
              if (while_flag_195) {
                (void)::dessser::Void();
              }
            } while (while_flag_195);
            (void)::dessser::Void();
            uint8_t id_224 { 0 };
            Pointer id_225 { leb128_ptr_497[id_224] };
            let_res_194 = id_225;
          }
          let_res_190 = let_res_194;
        }
        Vec<1, Pointer> id_226 {  let_res_190  };
        Pointer let_res_227;
        {
          Vec<1, Pointer> dst_ref_498 { id_226 };
          int32_t id_228 { 0L };
          Vec<1, int32_t> id_229 {  id_228  };
          Pointer let_res_230;
          {
            Vec<1, int32_t> n_ref_499 { id_229 };
            std::optional<Arr<dessser::gen::field_name::t_ext>> id_231 { (*p_0).group_by };
            Arr<dessser::gen::field_name::t_ext> id_232 { id_231.value() };
            for (dessser::gen::field_name::t_ext &x_500 : id_232) {
              uint8_t id_233 { 0 };
              auto fun234 { dessser::gen::field_name::to_row_binary };
              uint8_t id_235 { 0 };
              Pointer id_236 { dst_ref_498[id_235] };
              Pointer id_237 { fun234(x_500, id_236) };
              Void id_238 { ((void)(dst_ref_498[id_233] = id_237), ::dessser::Void()) };
              (void)id_238;
              uint8_t id_239 { 0 };
              int32_t id_240 { 1L };
              uint8_t id_241 { 0 };
              int32_t id_242 { n_ref_499[id_241] };
              int32_t id_243 { int32_t(id_240 + id_242) };
              Void id_244 { ((void)(n_ref_499[id_239] = id_243), ::dessser::Void()) };
              (void)id_244;
              (void)id_244;
            }
            (void)::dessser::Void();
            uint8_t id_245 { 0 };
            Pointer id_246 { dst_ref_498[id_245] };
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
      Pointer srec_dst_501 { let_res_180 };
      Arr<dessser::gen::simple_filter::t_ext> id_248 { (*p_0).having };
      uint32_t id_249 { id_248.size() };
      Vec<1, uint32_t> id_250 {  id_249  };
      Pointer let_res_251;
      {
        Vec<1, uint32_t> leb128_sz_502 { id_250 };
        Vec<1, Pointer> id_252 {  srec_dst_501  };
        Pointer let_res_253;
        {
          Vec<1, Pointer> leb128_ptr_503 { id_252 };
          bool while_flag_254 { true };
          do {
            uint8_t id_255 { 0 };
            uint8_t id_256 { 0 };
            Pointer id_257 { leb128_ptr_503[id_256] };
            uint32_t id_258 { 128U };
            uint8_t id_259 { 0 };
            uint32_t id_260 { leb128_sz_502[id_259] };
            bool id_261 { bool(id_258 > id_260) };
            uint8_t choose_res_262;
            if (id_261) {
              uint8_t id_263 { 0 };
              uint32_t id_264 { leb128_sz_502[id_263] };
              uint8_t id_265 { uint8_t(id_264) };
              choose_res_262 = id_265;
            } else {
              uint8_t id_266 { 0 };
              uint32_t id_267 { leb128_sz_502[id_266] };
              uint8_t id_268 { uint8_t(id_267) };
              uint8_t id_269 { 128 };
              uint8_t id_270 { uint8_t(id_268 | id_269) };
              choose_res_262 = id_270;
            }
            Pointer id_271 { id_257.writeU8(choose_res_262) };
            Void id_272 { ((void)(leb128_ptr_503[id_255] = id_271), ::dessser::Void()) };
            (void)id_272;
            uint8_t id_273 { 0 };
            uint8_t id_274 { 0 };
            uint32_t id_275 { leb128_sz_502[id_274] };
            uint8_t id_276 { 7 };
            uint32_t id_277 { uint32_t(id_275 >> id_276) };
            Void id_278 { ((void)(leb128_sz_502[id_273] = id_277), ::dessser::Void()) };
            (void)id_278;
            uint8_t id_279 { 0 };
            uint32_t id_280 { leb128_sz_502[id_279] };
            uint32_t id_281 { 0U };
            bool id_282 { bool(id_280 > id_281) };
            while_flag_254 = id_282;
            if (while_flag_254) {
              (void)::dessser::Void();
            }
          } while (while_flag_254);
          (void)::dessser::Void();
          uint8_t id_283 { 0 };
          Pointer id_284 { leb128_ptr_503[id_283] };
          let_res_253 = id_284;
        }
        let_res_251 = let_res_253;
      }
      Vec<1, Pointer> id_285 {  let_res_251  };
      Pointer let_res_286;
      {
        Vec<1, Pointer> dst_ref_504 { id_285 };
        int32_t id_287 { 0L };
        Vec<1, int32_t> id_288 {  id_287  };
        Pointer let_res_289;
        {
          Vec<1, int32_t> n_ref_505 { id_288 };
          Arr<dessser::gen::simple_filter::t_ext> id_290 { (*p_0).having };
          for (dessser::gen::simple_filter::t_ext &x_506 : id_290) {
            uint8_t id_291 { 0 };
            auto fun292 { dessser::gen::simple_filter::to_row_binary };
            uint8_t id_293 { 0 };
            Pointer id_294 { dst_ref_504[id_293] };
            Pointer id_295 { fun292(x_506, id_294) };
            Void id_296 { ((void)(dst_ref_504[id_291] = id_295), ::dessser::Void()) };
            (void)id_296;
            uint8_t id_297 { 0 };
            int32_t id_298 { 1L };
            uint8_t id_299 { 0 };
            int32_t id_300 { n_ref_505[id_299] };
            int32_t id_301 { int32_t(id_298 + id_300) };
            Void id_302 { ((void)(n_ref_505[id_297] = id_301), ::dessser::Void()) };
            (void)id_302;
            (void)id_302;
          }
          (void)::dessser::Void();
          uint8_t id_303 { 0 };
          Pointer id_304 { dst_ref_504[id_303] };
          let_res_289 = id_304;
        }
        let_res_286 = let_res_289;
      }
      let_res_247 = let_res_286;
    }
    Pointer let_res_305;
    {
      Pointer srec_dst_507 { let_res_247 };
      std::shared_ptr<::dessser::gen::alert::threshold>  id_306 { (*p_0).threshold };
      Pointer id_307 { threshold_to_row_binary(id_306, srec_dst_507) };
      let_res_305 = id_307;
    }
    Pointer let_res_308;
    {
      Pointer srec_dst_508 { let_res_305 };
      double id_309 { (*p_0).hysteresis };
      uint64_t id_310 { qword_of_float(id_309) };
      Pointer id_311 { srec_dst_508.writeU64Le(id_310) };
      let_res_308 = id_311;
    }
    Pointer let_res_312;
    {
      Pointer srec_dst_509 { let_res_308 };
      double id_313 { (*p_0).duration };
      uint64_t id_314 { qword_of_float(id_313) };
      Pointer id_315 { srec_dst_509.writeU64Le(id_314) };
      let_res_312 = id_315;
    }
    Pointer let_res_316;
    {
      Pointer srec_dst_510 { let_res_312 };
      double id_317 { (*p_0).ratio };
      uint64_t id_318 { qword_of_float(id_317) };
      Pointer id_319 { srec_dst_510.writeU64Le(id_318) };
      let_res_316 = id_319;
    }
    Pointer let_res_320;
    {
      Pointer srec_dst_511 { let_res_316 };
      double id_321 { (*p_0).time_step };
      uint64_t id_322 { qword_of_float(id_321) };
      Pointer id_323 { srec_dst_511.writeU64Le(id_322) };
      let_res_320 = id_323;
    }
    Pointer let_res_324;
    {
      Pointer srec_dst_512 { let_res_320 };
      Arr<dessser::gen::field_name::t_ext> id_325 { (*p_0).tops };
      uint32_t id_326 { id_325.size() };
      Vec<1, uint32_t> id_327 {  id_326  };
      Pointer let_res_328;
      {
        Vec<1, uint32_t> leb128_sz_513 { id_327 };
        Vec<1, Pointer> id_329 {  srec_dst_512  };
        Pointer let_res_330;
        {
          Vec<1, Pointer> leb128_ptr_514 { id_329 };
          bool while_flag_331 { true };
          do {
            uint8_t id_332 { 0 };
            uint8_t id_333 { 0 };
            Pointer id_334 { leb128_ptr_514[id_333] };
            uint32_t id_335 { 128U };
            uint8_t id_336 { 0 };
            uint32_t id_337 { leb128_sz_513[id_336] };
            bool id_338 { bool(id_335 > id_337) };
            uint8_t choose_res_339;
            if (id_338) {
              uint8_t id_340 { 0 };
              uint32_t id_341 { leb128_sz_513[id_340] };
              uint8_t id_342 { uint8_t(id_341) };
              choose_res_339 = id_342;
            } else {
              uint8_t id_343 { 0 };
              uint32_t id_344 { leb128_sz_513[id_343] };
              uint8_t id_345 { uint8_t(id_344) };
              uint8_t id_346 { 128 };
              uint8_t id_347 { uint8_t(id_345 | id_346) };
              choose_res_339 = id_347;
            }
            Pointer id_348 { id_334.writeU8(choose_res_339) };
            Void id_349 { ((void)(leb128_ptr_514[id_332] = id_348), ::dessser::Void()) };
            (void)id_349;
            uint8_t id_350 { 0 };
            uint8_t id_351 { 0 };
            uint32_t id_352 { leb128_sz_513[id_351] };
            uint8_t id_353 { 7 };
            uint32_t id_354 { uint32_t(id_352 >> id_353) };
            Void id_355 { ((void)(leb128_sz_513[id_350] = id_354), ::dessser::Void()) };
            (void)id_355;
            uint8_t id_356 { 0 };
            uint32_t id_357 { leb128_sz_513[id_356] };
            uint32_t id_358 { 0U };
            bool id_359 { bool(id_357 > id_358) };
            while_flag_331 = id_359;
            if (while_flag_331) {
              (void)::dessser::Void();
            }
          } while (while_flag_331);
          (void)::dessser::Void();
          uint8_t id_360 { 0 };
          Pointer id_361 { leb128_ptr_514[id_360] };
          let_res_330 = id_361;
        }
        let_res_328 = let_res_330;
      }
      Vec<1, Pointer> id_362 {  let_res_328  };
      Pointer let_res_363;
      {
        Vec<1, Pointer> dst_ref_515 { id_362 };
        int32_t id_364 { 0L };
        Vec<1, int32_t> id_365 {  id_364  };
        Pointer let_res_366;
        {
          Vec<1, int32_t> n_ref_516 { id_365 };
          Arr<dessser::gen::field_name::t_ext> id_367 { (*p_0).tops };
          for (dessser::gen::field_name::t_ext &x_517 : id_367) {
            uint8_t id_368 { 0 };
            auto fun369 { dessser::gen::field_name::to_row_binary };
            uint8_t id_370 { 0 };
            Pointer id_371 { dst_ref_515[id_370] };
            Pointer id_372 { fun369(x_517, id_371) };
            Void id_373 { ((void)(dst_ref_515[id_368] = id_372), ::dessser::Void()) };
            (void)id_373;
            uint8_t id_374 { 0 };
            int32_t id_375 { 1L };
            uint8_t id_376 { 0 };
            int32_t id_377 { n_ref_516[id_376] };
            int32_t id_378 { int32_t(id_375 + id_377) };
            Void id_379 { ((void)(n_ref_516[id_374] = id_378), ::dessser::Void()) };
            (void)id_379;
            (void)id_379;
          }
          (void)::dessser::Void();
          uint8_t id_380 { 0 };
          Pointer id_381 { dst_ref_515[id_380] };
          let_res_366 = id_381;
        }
        let_res_363 = let_res_366;
      }
      let_res_324 = let_res_363;
    }
    Pointer let_res_382;
    {
      Pointer srec_dst_518 { let_res_324 };
      Arr<dessser::gen::field_name::t_ext> id_383 { (*p_0).carry_fields };
      uint32_t id_384 { id_383.size() };
      Vec<1, uint32_t> id_385 {  id_384  };
      Pointer let_res_386;
      {
        Vec<1, uint32_t> leb128_sz_519 { id_385 };
        Vec<1, Pointer> id_387 {  srec_dst_518  };
        Pointer let_res_388;
        {
          Vec<1, Pointer> leb128_ptr_520 { id_387 };
          bool while_flag_389 { true };
          do {
            uint8_t id_390 { 0 };
            uint8_t id_391 { 0 };
            Pointer id_392 { leb128_ptr_520[id_391] };
            uint32_t id_393 { 128U };
            uint8_t id_394 { 0 };
            uint32_t id_395 { leb128_sz_519[id_394] };
            bool id_396 { bool(id_393 > id_395) };
            uint8_t choose_res_397;
            if (id_396) {
              uint8_t id_398 { 0 };
              uint32_t id_399 { leb128_sz_519[id_398] };
              uint8_t id_400 { uint8_t(id_399) };
              choose_res_397 = id_400;
            } else {
              uint8_t id_401 { 0 };
              uint32_t id_402 { leb128_sz_519[id_401] };
              uint8_t id_403 { uint8_t(id_402) };
              uint8_t id_404 { 128 };
              uint8_t id_405 { uint8_t(id_403 | id_404) };
              choose_res_397 = id_405;
            }
            Pointer id_406 { id_392.writeU8(choose_res_397) };
            Void id_407 { ((void)(leb128_ptr_520[id_390] = id_406), ::dessser::Void()) };
            (void)id_407;
            uint8_t id_408 { 0 };
            uint8_t id_409 { 0 };
            uint32_t id_410 { leb128_sz_519[id_409] };
            uint8_t id_411 { 7 };
            uint32_t id_412 { uint32_t(id_410 >> id_411) };
            Void id_413 { ((void)(leb128_sz_519[id_408] = id_412), ::dessser::Void()) };
            (void)id_413;
            uint8_t id_414 { 0 };
            uint32_t id_415 { leb128_sz_519[id_414] };
            uint32_t id_416 { 0U };
            bool id_417 { bool(id_415 > id_416) };
            while_flag_389 = id_417;
            if (while_flag_389) {
              (void)::dessser::Void();
            }
          } while (while_flag_389);
          (void)::dessser::Void();
          uint8_t id_418 { 0 };
          Pointer id_419 { leb128_ptr_520[id_418] };
          let_res_388 = id_419;
        }
        let_res_386 = let_res_388;
      }
      Vec<1, Pointer> id_420 {  let_res_386  };
      Pointer let_res_421;
      {
        Vec<1, Pointer> dst_ref_521 { id_420 };
        int32_t id_422 { 0L };
        Vec<1, int32_t> id_423 {  id_422  };
        Pointer let_res_424;
        {
          Vec<1, int32_t> n_ref_522 { id_423 };
          Arr<dessser::gen::field_name::t_ext> id_425 { (*p_0).carry_fields };
          for (dessser::gen::field_name::t_ext &x_523 : id_425) {
            uint8_t id_426 { 0 };
            auto fun427 { dessser::gen::field_name::to_row_binary };
            uint8_t id_428 { 0 };
            Pointer id_429 { dst_ref_521[id_428] };
            Pointer id_430 { fun427(x_523, id_429) };
            Void id_431 { ((void)(dst_ref_521[id_426] = id_430), ::dessser::Void()) };
            (void)id_431;
            uint8_t id_432 { 0 };
            int32_t id_433 { 1L };
            uint8_t id_434 { 0 };
            int32_t id_435 { n_ref_522[id_434] };
            int32_t id_436 { int32_t(id_433 + id_435) };
            Void id_437 { ((void)(n_ref_522[id_432] = id_436), ::dessser::Void()) };
            (void)id_437;
            (void)id_437;
          }
          (void)::dessser::Void();
          uint8_t id_438 { 0 };
          Pointer id_439 { dst_ref_521[id_438] };
          let_res_424 = id_439;
        }
        let_res_421 = let_res_424;
      }
      let_res_382 = let_res_421;
    }
    Pointer let_res_440;
    {
      Pointer srec_dst_524 { let_res_382 };
      Arr<std::shared_ptr<::dessser::gen::alert::constant> > id_441 { (*p_0).carry_csts };
      uint32_t id_442 { id_441.size() };
      Vec<1, uint32_t> id_443 {  id_442  };
      Pointer let_res_444;
      {
        Vec<1, uint32_t> leb128_sz_525 { id_443 };
        Vec<1, Pointer> id_445 {  srec_dst_524  };
        Pointer let_res_446;
        {
          Vec<1, Pointer> leb128_ptr_526 { id_445 };
          bool while_flag_447 { true };
          do {
            uint8_t id_448 { 0 };
            uint8_t id_449 { 0 };
            Pointer id_450 { leb128_ptr_526[id_449] };
            uint32_t id_451 { 128U };
            uint8_t id_452 { 0 };
            uint32_t id_453 { leb128_sz_525[id_452] };
            bool id_454 { bool(id_451 > id_453) };
            uint8_t choose_res_455;
            if (id_454) {
              uint8_t id_456 { 0 };
              uint32_t id_457 { leb128_sz_525[id_456] };
              uint8_t id_458 { uint8_t(id_457) };
              choose_res_455 = id_458;
            } else {
              uint8_t id_459 { 0 };
              uint32_t id_460 { leb128_sz_525[id_459] };
              uint8_t id_461 { uint8_t(id_460) };
              uint8_t id_462 { 128 };
              uint8_t id_463 { uint8_t(id_461 | id_462) };
              choose_res_455 = id_463;
            }
            Pointer id_464 { id_450.writeU8(choose_res_455) };
            Void id_465 { ((void)(leb128_ptr_526[id_448] = id_464), ::dessser::Void()) };
            (void)id_465;
            uint8_t id_466 { 0 };
            uint8_t id_467 { 0 };
            uint32_t id_468 { leb128_sz_525[id_467] };
            uint8_t id_469 { 7 };
            uint32_t id_470 { uint32_t(id_468 >> id_469) };
            Void id_471 { ((void)(leb128_sz_525[id_466] = id_470), ::dessser::Void()) };
            (void)id_471;
            uint8_t id_472 { 0 };
            uint32_t id_473 { leb128_sz_525[id_472] };
            uint32_t id_474 { 0U };
            bool id_475 { bool(id_473 > id_474) };
            while_flag_447 = id_475;
            if (while_flag_447) {
              (void)::dessser::Void();
            }
          } while (while_flag_447);
          (void)::dessser::Void();
          uint8_t id_476 { 0 };
          Pointer id_477 { leb128_ptr_526[id_476] };
          let_res_446 = id_477;
        }
        let_res_444 = let_res_446;
      }
      Vec<1, Pointer> id_478 {  let_res_444  };
      Pointer let_res_479;
      {
        Vec<1, Pointer> dst_ref_527 { id_478 };
        int32_t id_480 { 0L };
        Vec<1, int32_t> id_481 {  id_480  };
        Pointer let_res_482;
        {
          Vec<1, int32_t> n_ref_528 { id_481 };
          Arr<std::shared_ptr<::dessser::gen::alert::constant> > id_483 { (*p_0).carry_csts };
          for (std::shared_ptr<::dessser::gen::alert::constant>  &x_529 : id_483) {
            uint8_t id_484 { 0 };
            uint8_t id_485 { 0 };
            Pointer id_486 { dst_ref_527[id_485] };
            Pointer id_487 { constant_to_row_binary(x_529, id_486) };
            Void id_488 { ((void)(dst_ref_527[id_484] = id_487), ::dessser::Void()) };
            (void)id_488;
            uint8_t id_489 { 0 };
            int32_t id_490 { 1L };
            uint8_t id_491 { 0 };
            int32_t id_492 { n_ref_528[id_491] };
            int32_t id_493 { int32_t(id_490 + id_492) };
            Void id_494 { ((void)(n_ref_528[id_489] = id_493), ::dessser::Void()) };
            (void)id_494;
            (void)id_494;
          }
          (void)::dessser::Void();
          uint8_t id_495 { 0 };
          Pointer id_496 { dst_ref_527[id_495] };
          let_res_482 = id_496;
        }
        let_res_479 = let_res_482;
      }
      let_res_440 = let_res_479;
    }
    Pointer let_res_497;
    {
      Pointer srec_dst_530 { let_res_440 };
      std::string id_498 { (*p_0).id };
      uint32_t id_499 { (uint32_t)id_498.size() };
      Vec<1, uint32_t> id_500 {  id_499  };
      Pointer let_res_501;
      {
        Vec<1, uint32_t> leb128_sz_531 { id_500 };
        Vec<1, Pointer> id_502 {  srec_dst_530  };
        Pointer let_res_503;
        {
          Vec<1, Pointer> leb128_ptr_532 { id_502 };
          bool while_flag_504 { true };
          do {
            uint8_t id_505 { 0 };
            uint8_t id_506 { 0 };
            Pointer id_507 { leb128_ptr_532[id_506] };
            uint32_t id_508 { 128U };
            uint8_t id_509 { 0 };
            uint32_t id_510 { leb128_sz_531[id_509] };
            bool id_511 { bool(id_508 > id_510) };
            uint8_t choose_res_512;
            if (id_511) {
              uint8_t id_513 { 0 };
              uint32_t id_514 { leb128_sz_531[id_513] };
              uint8_t id_515 { uint8_t(id_514) };
              choose_res_512 = id_515;
            } else {
              uint8_t id_516 { 0 };
              uint32_t id_517 { leb128_sz_531[id_516] };
              uint8_t id_518 { uint8_t(id_517) };
              uint8_t id_519 { 128 };
              uint8_t id_520 { uint8_t(id_518 | id_519) };
              choose_res_512 = id_520;
            }
            Pointer id_521 { id_507.writeU8(choose_res_512) };
            Void id_522 { ((void)(leb128_ptr_532[id_505] = id_521), ::dessser::Void()) };
            (void)id_522;
            uint8_t id_523 { 0 };
            uint8_t id_524 { 0 };
            uint32_t id_525 { leb128_sz_531[id_524] };
            uint8_t id_526 { 7 };
            uint32_t id_527 { uint32_t(id_525 >> id_526) };
            Void id_528 { ((void)(leb128_sz_531[id_523] = id_527), ::dessser::Void()) };
            (void)id_528;
            uint8_t id_529 { 0 };
            uint32_t id_530 { leb128_sz_531[id_529] };
            uint32_t id_531 { 0U };
            bool id_532 { bool(id_530 > id_531) };
            while_flag_504 = id_532;
            if (while_flag_504) {
              (void)::dessser::Void();
            }
          } while (while_flag_504);
          (void)::dessser::Void();
          uint8_t id_533 { 0 };
          Pointer id_534 { leb128_ptr_532[id_533] };
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
      Pointer srec_dst_533 { let_res_497 };
      std::string id_539 { (*p_0).desc_title };
      uint32_t id_540 { (uint32_t)id_539.size() };
      Vec<1, uint32_t> id_541 {  id_540  };
      Pointer let_res_542;
      {
        Vec<1, uint32_t> leb128_sz_534 { id_541 };
        Vec<1, Pointer> id_543 {  srec_dst_533  };
        Pointer let_res_544;
        {
          Vec<1, Pointer> leb128_ptr_535 { id_543 };
          bool while_flag_545 { true };
          do {
            uint8_t id_546 { 0 };
            uint8_t id_547 { 0 };
            Pointer id_548 { leb128_ptr_535[id_547] };
            uint32_t id_549 { 128U };
            uint8_t id_550 { 0 };
            uint32_t id_551 { leb128_sz_534[id_550] };
            bool id_552 { bool(id_549 > id_551) };
            uint8_t choose_res_553;
            if (id_552) {
              uint8_t id_554 { 0 };
              uint32_t id_555 { leb128_sz_534[id_554] };
              uint8_t id_556 { uint8_t(id_555) };
              choose_res_553 = id_556;
            } else {
              uint8_t id_557 { 0 };
              uint32_t id_558 { leb128_sz_534[id_557] };
              uint8_t id_559 { uint8_t(id_558) };
              uint8_t id_560 { 128 };
              uint8_t id_561 { uint8_t(id_559 | id_560) };
              choose_res_553 = id_561;
            }
            Pointer id_562 { id_548.writeU8(choose_res_553) };
            Void id_563 { ((void)(leb128_ptr_535[id_546] = id_562), ::dessser::Void()) };
            (void)id_563;
            uint8_t id_564 { 0 };
            uint8_t id_565 { 0 };
            uint32_t id_566 { leb128_sz_534[id_565] };
            uint8_t id_567 { 7 };
            uint32_t id_568 { uint32_t(id_566 >> id_567) };
            Void id_569 { ((void)(leb128_sz_534[id_564] = id_568), ::dessser::Void()) };
            (void)id_569;
            uint8_t id_570 { 0 };
            uint32_t id_571 { leb128_sz_534[id_570] };
            uint32_t id_572 { 0U };
            bool id_573 { bool(id_571 > id_572) };
            while_flag_545 = id_573;
            if (while_flag_545) {
              (void)::dessser::Void();
            }
          } while (while_flag_545);
          (void)::dessser::Void();
          uint8_t id_574 { 0 };
          Pointer id_575 { leb128_ptr_535[id_574] };
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
      Pointer srec_dst_536 { let_res_538 };
      std::string id_580 { (*p_0).desc_firing };
      uint32_t id_581 { (uint32_t)id_580.size() };
      Vec<1, uint32_t> id_582 {  id_581  };
      Pointer let_res_583;
      {
        Vec<1, uint32_t> leb128_sz_537 { id_582 };
        Vec<1, Pointer> id_584 {  srec_dst_536  };
        Pointer let_res_585;
        {
          Vec<1, Pointer> leb128_ptr_538 { id_584 };
          bool while_flag_586 { true };
          do {
            uint8_t id_587 { 0 };
            uint8_t id_588 { 0 };
            Pointer id_589 { leb128_ptr_538[id_588] };
            uint32_t id_590 { 128U };
            uint8_t id_591 { 0 };
            uint32_t id_592 { leb128_sz_537[id_591] };
            bool id_593 { bool(id_590 > id_592) };
            uint8_t choose_res_594;
            if (id_593) {
              uint8_t id_595 { 0 };
              uint32_t id_596 { leb128_sz_537[id_595] };
              uint8_t id_597 { uint8_t(id_596) };
              choose_res_594 = id_597;
            } else {
              uint8_t id_598 { 0 };
              uint32_t id_599 { leb128_sz_537[id_598] };
              uint8_t id_600 { uint8_t(id_599) };
              uint8_t id_601 { 128 };
              uint8_t id_602 { uint8_t(id_600 | id_601) };
              choose_res_594 = id_602;
            }
            Pointer id_603 { id_589.writeU8(choose_res_594) };
            Void id_604 { ((void)(leb128_ptr_538[id_587] = id_603), ::dessser::Void()) };
            (void)id_604;
            uint8_t id_605 { 0 };
            uint8_t id_606 { 0 };
            uint32_t id_607 { leb128_sz_537[id_606] };
            uint8_t id_608 { 7 };
            uint32_t id_609 { uint32_t(id_607 >> id_608) };
            Void id_610 { ((void)(leb128_sz_537[id_605] = id_609), ::dessser::Void()) };
            (void)id_610;
            uint8_t id_611 { 0 };
            uint32_t id_612 { leb128_sz_537[id_611] };
            uint32_t id_613 { 0U };
            bool id_614 { bool(id_612 > id_613) };
            while_flag_586 = id_614;
            if (while_flag_586) {
              (void)::dessser::Void();
            }
          } while (while_flag_586);
          (void)::dessser::Void();
          uint8_t id_615 { 0 };
          Pointer id_616 { leb128_ptr_538[id_615] };
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
      Pointer srec_dst_539 { let_res_579 };
      std::string id_621 { (*p_0).desc_recovery };
      uint32_t id_622 { (uint32_t)id_621.size() };
      Vec<1, uint32_t> id_623 {  id_622  };
      Pointer let_res_624;
      {
        Vec<1, uint32_t> leb128_sz_540 { id_623 };
        Vec<1, Pointer> id_625 {  srec_dst_539  };
        Pointer let_res_626;
        {
          Vec<1, Pointer> leb128_ptr_541 { id_625 };
          bool while_flag_627 { true };
          do {
            uint8_t id_628 { 0 };
            uint8_t id_629 { 0 };
            Pointer id_630 { leb128_ptr_541[id_629] };
            uint32_t id_631 { 128U };
            uint8_t id_632 { 0 };
            uint32_t id_633 { leb128_sz_540[id_632] };
            bool id_634 { bool(id_631 > id_633) };
            uint8_t choose_res_635;
            if (id_634) {
              uint8_t id_636 { 0 };
              uint32_t id_637 { leb128_sz_540[id_636] };
              uint8_t id_638 { uint8_t(id_637) };
              choose_res_635 = id_638;
            } else {
              uint8_t id_639 { 0 };
              uint32_t id_640 { leb128_sz_540[id_639] };
              uint8_t id_641 { uint8_t(id_640) };
              uint8_t id_642 { 128 };
              uint8_t id_643 { uint8_t(id_641 | id_642) };
              choose_res_635 = id_643;
            }
            Pointer id_644 { id_630.writeU8(choose_res_635) };
            Void id_645 { ((void)(leb128_ptr_541[id_628] = id_644), ::dessser::Void()) };
            (void)id_645;
            uint8_t id_646 { 0 };
            uint8_t id_647 { 0 };
            uint32_t id_648 { leb128_sz_540[id_647] };
            uint8_t id_649 { 7 };
            uint32_t id_650 { uint32_t(id_648 >> id_649) };
            Void id_651 { ((void)(leb128_sz_540[id_646] = id_650), ::dessser::Void()) };
            (void)id_651;
            uint8_t id_652 { 0 };
            uint32_t id_653 { leb128_sz_540[id_652] };
            uint32_t id_654 { 0U };
            bool id_655 { bool(id_653 > id_654) };
            while_flag_627 = id_655;
            if (while_flag_627) {
              (void)::dessser::Void();
            }
          } while (while_flag_627);
          (void)::dessser::Void();
          uint8_t id_656 { 0 };
          Pointer id_657 { leb128_ptr_541[id_656] };
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
      (let "sz_417" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0)))
        (add (identifier "sz_417")
          (add
            (let "n_ref_419" (make-vec (string-length (get-field "value" (param 0))))
              (let "lebsz_ref_420" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_419")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_420")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_420") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_420")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_420")))))) 
            (size-of-u32 (string-length (get-field "value" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alert::constant> )> constant_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alert::constant> )> fun661 { [&](std::shared_ptr<::dessser::gen::alert::constant>  p_0) {
    auto fun662 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_663 { (*p_0).name };
    Size id_664 { fun662(id_663) };
    Size let_res_665;
    {
      Size sz_417 { id_664 };
      std::string id_666 { (*p_0).value };
      uint32_t id_667 { (uint32_t)id_666.size() };
      Vec<1, uint32_t> id_668 {  id_667  };
      Size let_res_669;
      {
        Vec<1, uint32_t> n_ref_419 { id_668 };
        uint32_t id_670 { 1U };
        Vec<1, uint32_t> id_671 {  id_670  };
        Size let_res_672;
        {
          Vec<1, uint32_t> lebsz_ref_420 { id_671 };
          bool while_flag_673 { true };
          do {
            uint8_t id_674 { 0 };
            uint32_t id_675 { n_ref_419[id_674] };
            uint8_t id_676 { 0 };
            uint32_t id_677 { lebsz_ref_420[id_676] };
            uint8_t id_678 { 7 };
            uint32_t id_679 { uint32_t(id_677 << id_678) };
            bool id_680 { bool(id_675 >= id_679) };
            while_flag_673 = id_680;
            if (while_flag_673) {
              uint8_t id_681 { 0 };
              uint8_t id_682 { 0 };
              uint32_t id_683 { lebsz_ref_420[id_682] };
              uint32_t id_684 { 1U };
              uint32_t id_685 { uint32_t(id_683 + id_684) };
              Void id_686 { ((void)(lebsz_ref_420[id_681] = id_685), ::dessser::Void()) };
              (void)id_686;
            }
          } while (while_flag_673);
          (void)::dessser::Void();
          uint8_t id_687 { 0 };
          uint32_t id_688 { lebsz_ref_420[id_687] };
          Size id_689 { Size(id_688) };
          let_res_672 = id_689;
        }
        let_res_669 = let_res_672;
      }
      std::string id_690 { (*p_0).value };
      uint32_t id_691 { (uint32_t)id_690.size() };
      Size id_692 { Size(id_691) };
      Size id_693 { Size(let_res_669 + id_692) };
      Size id_694 { Size(sz_417 + id_693) };
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
  std::function<Size(std::shared_ptr<::dessser::gen::alert::threshold> )> fun695 { [&](std::shared_ptr<::dessser::gen::alert::threshold>  p_0) {
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
      Void id_704 { ((void)(assert(id_703)), ::dessser::Void()) };
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
        Void id_717 { ((void)(assert(id_716)), ::dessser::Void()) };
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
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[]; group-by: $field_name[]?; having: $simple_filter[]; threshold: (threshold AS [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]); hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[]; carry-fields: $field_name[]; carry-csts: (constant AS {name: $field_name; value: STRING})[]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}")
      (let "sz_471"
        (let "sz_467"
          (let "sz_463"
            (let "sz_459"
              (let "sz_454"
                (let "sz_449"
                  (let "sz_444"
                    (add
                      (add
                        (add
                          (add
                            (let "sz_439"
                              (let "sz_434"
                                (let "sz_429"
                                  (let "sz_424"
                                    (add
                                      (let "sz_422" (apply (ext-identifier fq_name sersize-of-row-binary) (get-field "table" (param 0)))
                                        (add (identifier "sz_422") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "column" (param 0))))) 
                                      (size 1))
                                    (let "sz_ref_427"
                                      (make-vec
                                        (add (identifier "sz_424")
                                          (let "n_ref_425" (make-vec (cardinality (get-field "where" (param 0))))
                                            (let "lebsz_ref_426" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_425")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_426")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_426") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_426")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_426"))))))))
                                      (seq
                                        (let "repeat_n_428" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (get-field "where" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_428")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_427")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_427"))
                                                  (apply (ext-identifier simple_filter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_428")) (get-field "where" (param 0))))))
                                              (set-vec (u8 0) (identifier "repeat_n_428") (add (unsafe-nth (u8 0) (identifier "repeat_n_428")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_427")))))
                                  (if (is-null (get-field "group-by" (param 0))) 
                                    (add (identifier "sz_429") (size 1))
                                    (add
                                      (let "sz_ref_432"
                                        (make-vec
                                          (add (identifier "sz_429")
                                            (let "n_ref_430" (make-vec (cardinality (force (get-field "group-by" (param 0)))))
                                              (let "lebsz_ref_431" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_430")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_431")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_431") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_431")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_431"))))))))
                                        (seq
                                          (let "repeat_n_433" (make-vec (i32 0))
                                            (while (gt (to-i32 (cardinality (force (get-field "group-by" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_433")))
                                              (seq
                                                (set-vec (u8 0) (identifier "sz_ref_432")
                                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_432"))
                                                    (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_433")) (force (get-field "group-by" (param 0)))))))
                                                (set-vec (u8 0) (identifier "repeat_n_433") (add (unsafe-nth (u8 0) (identifier "repeat_n_433")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "sz_ref_432")))) 
                                      (size 1))))
                                (let "sz_ref_437"
                                  (make-vec
                                    (add (identifier "sz_434")
                                      (let "n_ref_435" (make-vec (cardinality (get-field "having" (param 0))))
                                        (let "lebsz_ref_436" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_435")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_436")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_436") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_436")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_436"))))))))
                                  (seq
                                    (let "repeat_n_438" (make-vec (i32 0))
                                      (while (gt (to-i32 (cardinality (get-field "having" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_438")))
                                        (seq
                                          (set-vec (u8 0) (identifier "sz_ref_437")
                                            (add (unsafe-nth (u8 0) (identifier "sz_ref_437"))
                                              (apply (ext-identifier simple_filter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_438")) (get-field "having" (param 0))))))
                                          (set-vec (u8 0) (identifier "repeat_n_438") (add (unsafe-nth (u8 0) (identifier "repeat_n_438")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "sz_ref_437"))))) 
                              (add (identifier "sz_439") (apply (identifier "threshold-sersize-of-row-binary") (get-field "threshold" (param 0))))) 
                            (size 8)) (size 8)) (size 8)) (size 8))
                    (let "sz_ref_447"
                      (make-vec
                        (add (identifier "sz_444")
                          (let "n_ref_445" (make-vec (cardinality (get-field "tops" (param 0))))
                            (let "lebsz_ref_446" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_445")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_446")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_446") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_446")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_446"))))))))
                      (seq
                        (let "repeat_n_448" (make-vec (i32 0))
                          (while (gt (to-i32 (cardinality (get-field "tops" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_448")))
                            (seq
                              (set-vec (u8 0) (identifier "sz_ref_447")
                                (add (unsafe-nth (u8 0) (identifier "sz_ref_447"))
                                  (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_448")) (get-field "tops" (param 0))))))
                              (set-vec (u8 0) (identifier "repeat_n_448") (add (unsafe-nth (u8 0) (identifier "repeat_n_448")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "sz_ref_447")))))
                  (let "sz_ref_452"
                    (make-vec
                      (add (identifier "sz_449")
                        (let "n_ref_450" (make-vec (cardinality (get-field "carry-fields" (param 0))))
                          (let "lebsz_ref_451" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_450")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_451")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_451") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_451")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_451"))))))))
                    (seq
                      (let "repeat_n_453" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-field "carry-fields" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_453")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_452")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_452"))
                                (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_453")) (get-field "carry-fields" (param 0))))))
                            (set-vec (u8 0) (identifier "repeat_n_453") (add (unsafe-nth (u8 0) (identifier "repeat_n_453")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_452")))))
                (let "sz_ref_457"
                  (make-vec
                    (add (identifier "sz_454")
                      (let "n_ref_455" (make-vec (cardinality (get-field "carry-csts" (param 0))))
                        (let "lebsz_ref_456" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_455")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_456")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_456") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_456")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_456"))))))))
                  (seq
                    (let "repeat_n_458" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "carry-csts" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_458")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_457")
                            (add (unsafe-nth (u8 0) (identifier "sz_ref_457")) (apply (identifier "constant-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_458")) (get-field "carry-csts" (param 0))))))
                          (set-vec (u8 0) (identifier "repeat_n_458") (add (unsafe-nth (u8 0) (identifier "repeat_n_458")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_457")))))
              (add (identifier "sz_459")
                (add
                  (let "n_ref_461" (make-vec (string-length (get-field "id" (param 0))))
                    (let "lebsz_ref_462" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_461")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_462")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_462") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_462")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_462")))))) 
                  (size-of-u32 (string-length (get-field "id" (param 0)))))))
            (add (identifier "sz_463")
              (add
                (let "n_ref_465" (make-vec (string-length (get-field "desc-title" (param 0))))
                  (let "lebsz_ref_466" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_465")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_466")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_466") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_466")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_466")))))) 
                (size-of-u32 (string-length (get-field "desc-title" (param 0)))))))
          (add (identifier "sz_467")
            (add
              (let "n_ref_469" (make-vec (string-length (get-field "desc-firing" (param 0))))
                (let "lebsz_ref_470" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_469")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_470")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_470") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_470")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_470")))))) 
              (size-of-u32 (string-length (get-field "desc-firing" (param 0)))))))
        (add (identifier "sz_471")
          (add
            (let "n_ref_473" (make-vec (string-length (get-field "desc-recovery" (param 0))))
              (let "lebsz_ref_474" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_473")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_474")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_474") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_474")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_474")))))) 
            (size-of-u32 (string-length (get-field "desc-recovery" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alert::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alert::t> )> fun719 { [&](std::shared_ptr<::dessser::gen::alert::t>  p_0) {
    auto fun720 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_721 { (*p_0).table };
    Size id_722 { fun720(id_721) };
    Size let_res_723;
    {
      Size sz_422 { id_722 };
      auto fun724 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_725 { (*p_0).column };
      Size id_726 { fun724(id_725) };
      Size id_727 { Size(sz_422 + id_726) };
      let_res_723 = id_727;
    }
    Size id_728 { 1UL };
    Size id_729 { Size(let_res_723 + id_728) };
    Size let_res_730;
    {
      Size sz_424 { id_729 };
      Arr<dessser::gen::simple_filter::t_ext> id_731 { (*p_0).where };
      uint32_t id_732 { id_731.size() };
      Vec<1, uint32_t> id_733 {  id_732  };
      Size let_res_734;
      {
        Vec<1, uint32_t> n_ref_425 { id_733 };
        uint32_t id_735 { 1U };
        Vec<1, uint32_t> id_736 {  id_735  };
        Size let_res_737;
        {
          Vec<1, uint32_t> lebsz_ref_426 { id_736 };
          bool while_flag_738 { true };
          do {
            uint8_t id_739 { 0 };
            uint32_t id_740 { n_ref_425[id_739] };
            uint8_t id_741 { 0 };
            uint32_t id_742 { lebsz_ref_426[id_741] };
            uint8_t id_743 { 7 };
            uint32_t id_744 { uint32_t(id_742 << id_743) };
            bool id_745 { bool(id_740 >= id_744) };
            while_flag_738 = id_745;
            if (while_flag_738) {
              uint8_t id_746 { 0 };
              uint8_t id_747 { 0 };
              uint32_t id_748 { lebsz_ref_426[id_747] };
              uint32_t id_749 { 1U };
              uint32_t id_750 { uint32_t(id_748 + id_749) };
              Void id_751 { ((void)(lebsz_ref_426[id_746] = id_750), ::dessser::Void()) };
              (void)id_751;
            }
          } while (while_flag_738);
          (void)::dessser::Void();
          uint8_t id_752 { 0 };
          uint32_t id_753 { lebsz_ref_426[id_752] };
          Size id_754 { Size(id_753) };
          let_res_737 = id_754;
        }
        let_res_734 = let_res_737;
      }
      Size id_755 { Size(sz_424 + let_res_734) };
      Vec<1, Size> id_756 {  id_755  };
      Size let_res_757;
      {
        Vec<1, Size> sz_ref_427 { id_756 };
        int32_t id_758 { 0L };
        Vec<1, int32_t> id_759 {  id_758  };
        {
          Vec<1, int32_t> repeat_n_428 { id_759 };
          bool while_flag_760 { true };
          do {
            Arr<dessser::gen::simple_filter::t_ext> id_761 { (*p_0).where };
            uint32_t id_762 { id_761.size() };
            int32_t id_763 { int32_t(id_762) };
            uint8_t id_764 { 0 };
            int32_t id_765 { repeat_n_428[id_764] };
            bool id_766 { bool(id_763 > id_765) };
            while_flag_760 = id_766;
            if (while_flag_760) {
              uint8_t id_767 { 0 };
              uint8_t id_768 { 0 };
              Size id_769 { sz_ref_427[id_768] };
              auto fun770 { dessser::gen::simple_filter::sersize_of_row_binary };
              uint8_t id_771 { 0 };
              int32_t id_772 { repeat_n_428[id_771] };
              Arr<dessser::gen::simple_filter::t_ext> id_773 { (*p_0).where };
              dessser::gen::simple_filter::t_ext id_774 { id_773[id_772] };
              Size id_775 { fun770(id_774) };
              Size id_776 { Size(id_769 + id_775) };
              Void id_777 { ((void)(sz_ref_427[id_767] = id_776), ::dessser::Void()) };
              (void)id_777;
              uint8_t id_778 { 0 };
              uint8_t id_779 { 0 };
              int32_t id_780 { repeat_n_428[id_779] };
              int32_t id_781 { 1L };
              int32_t id_782 { int32_t(id_780 + id_781) };
              Void id_783 { ((void)(repeat_n_428[id_778] = id_782), ::dessser::Void()) };
              (void)id_783;
              (void)id_783;
            }
          } while (while_flag_760);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_784 { 0 };
        Size id_785 { sz_ref_427[id_784] };
        let_res_757 = id_785;
      }
      let_res_730 = let_res_757;
    }
    Size let_res_786;
    {
      Size sz_429 { let_res_730 };
      std::optional<Arr<dessser::gen::field_name::t_ext>> id_787 { (*p_0).group_by };
      bool id_788 { !(id_787.has_value ()) };
      Size choose_res_789;
      if (id_788) {
        Size id_790 { 1UL };
        Size id_791 { Size(sz_429 + id_790) };
        choose_res_789 = id_791;
      } else {
        std::optional<Arr<dessser::gen::field_name::t_ext>> id_792 { (*p_0).group_by };
        Arr<dessser::gen::field_name::t_ext> id_793 { id_792.value() };
        uint32_t id_794 { id_793.size() };
        Vec<1, uint32_t> id_795 {  id_794  };
        Size let_res_796;
        {
          Vec<1, uint32_t> n_ref_430 { id_795 };
          uint32_t id_797 { 1U };
          Vec<1, uint32_t> id_798 {  id_797  };
          Size let_res_799;
          {
            Vec<1, uint32_t> lebsz_ref_431 { id_798 };
            bool while_flag_800 { true };
            do {
              uint8_t id_801 { 0 };
              uint32_t id_802 { n_ref_430[id_801] };
              uint8_t id_803 { 0 };
              uint32_t id_804 { lebsz_ref_431[id_803] };
              uint8_t id_805 { 7 };
              uint32_t id_806 { uint32_t(id_804 << id_805) };
              bool id_807 { bool(id_802 >= id_806) };
              while_flag_800 = id_807;
              if (while_flag_800) {
                uint8_t id_808 { 0 };
                uint8_t id_809 { 0 };
                uint32_t id_810 { lebsz_ref_431[id_809] };
                uint32_t id_811 { 1U };
                uint32_t id_812 { uint32_t(id_810 + id_811) };
                Void id_813 { ((void)(lebsz_ref_431[id_808] = id_812), ::dessser::Void()) };
                (void)id_813;
              }
            } while (while_flag_800);
            (void)::dessser::Void();
            uint8_t id_814 { 0 };
            uint32_t id_815 { lebsz_ref_431[id_814] };
            Size id_816 { Size(id_815) };
            let_res_799 = id_816;
          }
          let_res_796 = let_res_799;
        }
        Size id_817 { Size(sz_429 + let_res_796) };
        Vec<1, Size> id_818 {  id_817  };
        Size let_res_819;
        {
          Vec<1, Size> sz_ref_432 { id_818 };
          int32_t id_820 { 0L };
          Vec<1, int32_t> id_821 {  id_820  };
          {
            Vec<1, int32_t> repeat_n_433 { id_821 };
            bool while_flag_822 { true };
            do {
              std::optional<Arr<dessser::gen::field_name::t_ext>> id_823 { (*p_0).group_by };
              Arr<dessser::gen::field_name::t_ext> id_824 { id_823.value() };
              uint32_t id_825 { id_824.size() };
              int32_t id_826 { int32_t(id_825) };
              uint8_t id_827 { 0 };
              int32_t id_828 { repeat_n_433[id_827] };
              bool id_829 { bool(id_826 > id_828) };
              while_flag_822 = id_829;
              if (while_flag_822) {
                uint8_t id_830 { 0 };
                uint8_t id_831 { 0 };
                Size id_832 { sz_ref_432[id_831] };
                auto fun833 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_834 { 0 };
                int32_t id_835 { repeat_n_433[id_834] };
                std::optional<Arr<dessser::gen::field_name::t_ext>> id_836 { (*p_0).group_by };
                Arr<dessser::gen::field_name::t_ext> id_837 { id_836.value() };
                dessser::gen::field_name::t_ext id_838 { id_837[id_835] };
                Size id_839 { fun833(id_838) };
                Size id_840 { Size(id_832 + id_839) };
                Void id_841 { ((void)(sz_ref_432[id_830] = id_840), ::dessser::Void()) };
                (void)id_841;
                uint8_t id_842 { 0 };
                uint8_t id_843 { 0 };
                int32_t id_844 { repeat_n_433[id_843] };
                int32_t id_845 { 1L };
                int32_t id_846 { int32_t(id_844 + id_845) };
                Void id_847 { ((void)(repeat_n_433[id_842] = id_846), ::dessser::Void()) };
                (void)id_847;
                (void)id_847;
              }
            } while (while_flag_822);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_848 { 0 };
          Size id_849 { sz_ref_432[id_848] };
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
      Size sz_434 { let_res_786 };
      Arr<dessser::gen::simple_filter::t_ext> id_853 { (*p_0).having };
      uint32_t id_854 { id_853.size() };
      Vec<1, uint32_t> id_855 {  id_854  };
      Size let_res_856;
      {
        Vec<1, uint32_t> n_ref_435 { id_855 };
        uint32_t id_857 { 1U };
        Vec<1, uint32_t> id_858 {  id_857  };
        Size let_res_859;
        {
          Vec<1, uint32_t> lebsz_ref_436 { id_858 };
          bool while_flag_860 { true };
          do {
            uint8_t id_861 { 0 };
            uint32_t id_862 { n_ref_435[id_861] };
            uint8_t id_863 { 0 };
            uint32_t id_864 { lebsz_ref_436[id_863] };
            uint8_t id_865 { 7 };
            uint32_t id_866 { uint32_t(id_864 << id_865) };
            bool id_867 { bool(id_862 >= id_866) };
            while_flag_860 = id_867;
            if (while_flag_860) {
              uint8_t id_868 { 0 };
              uint8_t id_869 { 0 };
              uint32_t id_870 { lebsz_ref_436[id_869] };
              uint32_t id_871 { 1U };
              uint32_t id_872 { uint32_t(id_870 + id_871) };
              Void id_873 { ((void)(lebsz_ref_436[id_868] = id_872), ::dessser::Void()) };
              (void)id_873;
            }
          } while (while_flag_860);
          (void)::dessser::Void();
          uint8_t id_874 { 0 };
          uint32_t id_875 { lebsz_ref_436[id_874] };
          Size id_876 { Size(id_875) };
          let_res_859 = id_876;
        }
        let_res_856 = let_res_859;
      }
      Size id_877 { Size(sz_434 + let_res_856) };
      Vec<1, Size> id_878 {  id_877  };
      Size let_res_879;
      {
        Vec<1, Size> sz_ref_437 { id_878 };
        int32_t id_880 { 0L };
        Vec<1, int32_t> id_881 {  id_880  };
        {
          Vec<1, int32_t> repeat_n_438 { id_881 };
          bool while_flag_882 { true };
          do {
            Arr<dessser::gen::simple_filter::t_ext> id_883 { (*p_0).having };
            uint32_t id_884 { id_883.size() };
            int32_t id_885 { int32_t(id_884) };
            uint8_t id_886 { 0 };
            int32_t id_887 { repeat_n_438[id_886] };
            bool id_888 { bool(id_885 > id_887) };
            while_flag_882 = id_888;
            if (while_flag_882) {
              uint8_t id_889 { 0 };
              uint8_t id_890 { 0 };
              Size id_891 { sz_ref_437[id_890] };
              auto fun892 { dessser::gen::simple_filter::sersize_of_row_binary };
              uint8_t id_893 { 0 };
              int32_t id_894 { repeat_n_438[id_893] };
              Arr<dessser::gen::simple_filter::t_ext> id_895 { (*p_0).having };
              dessser::gen::simple_filter::t_ext id_896 { id_895[id_894] };
              Size id_897 { fun892(id_896) };
              Size id_898 { Size(id_891 + id_897) };
              Void id_899 { ((void)(sz_ref_437[id_889] = id_898), ::dessser::Void()) };
              (void)id_899;
              uint8_t id_900 { 0 };
              uint8_t id_901 { 0 };
              int32_t id_902 { repeat_n_438[id_901] };
              int32_t id_903 { 1L };
              int32_t id_904 { int32_t(id_902 + id_903) };
              Void id_905 { ((void)(repeat_n_438[id_900] = id_904), ::dessser::Void()) };
              (void)id_905;
              (void)id_905;
            }
          } while (while_flag_882);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_906 { 0 };
        Size id_907 { sz_ref_437[id_906] };
        let_res_879 = id_907;
      }
      let_res_852 = let_res_879;
    }
    Size let_res_908;
    {
      Size sz_439 { let_res_852 };
      std::shared_ptr<::dessser::gen::alert::threshold>  id_909 { (*p_0).threshold };
      Size id_910 { threshold_sersize_of_row_binary(id_909) };
      Size id_911 { Size(sz_439 + id_910) };
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
      Size sz_444 { id_919 };
      Arr<dessser::gen::field_name::t_ext> id_921 { (*p_0).tops };
      uint32_t id_922 { id_921.size() };
      Vec<1, uint32_t> id_923 {  id_922  };
      Size let_res_924;
      {
        Vec<1, uint32_t> n_ref_445 { id_923 };
        uint32_t id_925 { 1U };
        Vec<1, uint32_t> id_926 {  id_925  };
        Size let_res_927;
        {
          Vec<1, uint32_t> lebsz_ref_446 { id_926 };
          bool while_flag_928 { true };
          do {
            uint8_t id_929 { 0 };
            uint32_t id_930 { n_ref_445[id_929] };
            uint8_t id_931 { 0 };
            uint32_t id_932 { lebsz_ref_446[id_931] };
            uint8_t id_933 { 7 };
            uint32_t id_934 { uint32_t(id_932 << id_933) };
            bool id_935 { bool(id_930 >= id_934) };
            while_flag_928 = id_935;
            if (while_flag_928) {
              uint8_t id_936 { 0 };
              uint8_t id_937 { 0 };
              uint32_t id_938 { lebsz_ref_446[id_937] };
              uint32_t id_939 { 1U };
              uint32_t id_940 { uint32_t(id_938 + id_939) };
              Void id_941 { ((void)(lebsz_ref_446[id_936] = id_940), ::dessser::Void()) };
              (void)id_941;
            }
          } while (while_flag_928);
          (void)::dessser::Void();
          uint8_t id_942 { 0 };
          uint32_t id_943 { lebsz_ref_446[id_942] };
          Size id_944 { Size(id_943) };
          let_res_927 = id_944;
        }
        let_res_924 = let_res_927;
      }
      Size id_945 { Size(sz_444 + let_res_924) };
      Vec<1, Size> id_946 {  id_945  };
      Size let_res_947;
      {
        Vec<1, Size> sz_ref_447 { id_946 };
        int32_t id_948 { 0L };
        Vec<1, int32_t> id_949 {  id_948  };
        {
          Vec<1, int32_t> repeat_n_448 { id_949 };
          bool while_flag_950 { true };
          do {
            Arr<dessser::gen::field_name::t_ext> id_951 { (*p_0).tops };
            uint32_t id_952 { id_951.size() };
            int32_t id_953 { int32_t(id_952) };
            uint8_t id_954 { 0 };
            int32_t id_955 { repeat_n_448[id_954] };
            bool id_956 { bool(id_953 > id_955) };
            while_flag_950 = id_956;
            if (while_flag_950) {
              uint8_t id_957 { 0 };
              uint8_t id_958 { 0 };
              Size id_959 { sz_ref_447[id_958] };
              auto fun960 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_961 { 0 };
              int32_t id_962 { repeat_n_448[id_961] };
              Arr<dessser::gen::field_name::t_ext> id_963 { (*p_0).tops };
              dessser::gen::field_name::t_ext id_964 { id_963[id_962] };
              Size id_965 { fun960(id_964) };
              Size id_966 { Size(id_959 + id_965) };
              Void id_967 { ((void)(sz_ref_447[id_957] = id_966), ::dessser::Void()) };
              (void)id_967;
              uint8_t id_968 { 0 };
              uint8_t id_969 { 0 };
              int32_t id_970 { repeat_n_448[id_969] };
              int32_t id_971 { 1L };
              int32_t id_972 { int32_t(id_970 + id_971) };
              Void id_973 { ((void)(repeat_n_448[id_968] = id_972), ::dessser::Void()) };
              (void)id_973;
              (void)id_973;
            }
          } while (while_flag_950);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_974 { 0 };
        Size id_975 { sz_ref_447[id_974] };
        let_res_947 = id_975;
      }
      let_res_920 = let_res_947;
    }
    Size let_res_976;
    {
      Size sz_449 { let_res_920 };
      Arr<dessser::gen::field_name::t_ext> id_977 { (*p_0).carry_fields };
      uint32_t id_978 { id_977.size() };
      Vec<1, uint32_t> id_979 {  id_978  };
      Size let_res_980;
      {
        Vec<1, uint32_t> n_ref_450 { id_979 };
        uint32_t id_981 { 1U };
        Vec<1, uint32_t> id_982 {  id_981  };
        Size let_res_983;
        {
          Vec<1, uint32_t> lebsz_ref_451 { id_982 };
          bool while_flag_984 { true };
          do {
            uint8_t id_985 { 0 };
            uint32_t id_986 { n_ref_450[id_985] };
            uint8_t id_987 { 0 };
            uint32_t id_988 { lebsz_ref_451[id_987] };
            uint8_t id_989 { 7 };
            uint32_t id_990 { uint32_t(id_988 << id_989) };
            bool id_991 { bool(id_986 >= id_990) };
            while_flag_984 = id_991;
            if (while_flag_984) {
              uint8_t id_992 { 0 };
              uint8_t id_993 { 0 };
              uint32_t id_994 { lebsz_ref_451[id_993] };
              uint32_t id_995 { 1U };
              uint32_t id_996 { uint32_t(id_994 + id_995) };
              Void id_997 { ((void)(lebsz_ref_451[id_992] = id_996), ::dessser::Void()) };
              (void)id_997;
            }
          } while (while_flag_984);
          (void)::dessser::Void();
          uint8_t id_998 { 0 };
          uint32_t id_999 { lebsz_ref_451[id_998] };
          Size id_1000 { Size(id_999) };
          let_res_983 = id_1000;
        }
        let_res_980 = let_res_983;
      }
      Size id_1001 { Size(sz_449 + let_res_980) };
      Vec<1, Size> id_1002 {  id_1001  };
      Size let_res_1003;
      {
        Vec<1, Size> sz_ref_452 { id_1002 };
        int32_t id_1004 { 0L };
        Vec<1, int32_t> id_1005 {  id_1004  };
        {
          Vec<1, int32_t> repeat_n_453 { id_1005 };
          bool while_flag_1006 { true };
          do {
            Arr<dessser::gen::field_name::t_ext> id_1007 { (*p_0).carry_fields };
            uint32_t id_1008 { id_1007.size() };
            int32_t id_1009 { int32_t(id_1008) };
            uint8_t id_1010 { 0 };
            int32_t id_1011 { repeat_n_453[id_1010] };
            bool id_1012 { bool(id_1009 > id_1011) };
            while_flag_1006 = id_1012;
            if (while_flag_1006) {
              uint8_t id_1013 { 0 };
              uint8_t id_1014 { 0 };
              Size id_1015 { sz_ref_452[id_1014] };
              auto fun1016 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_1017 { 0 };
              int32_t id_1018 { repeat_n_453[id_1017] };
              Arr<dessser::gen::field_name::t_ext> id_1019 { (*p_0).carry_fields };
              dessser::gen::field_name::t_ext id_1020 { id_1019[id_1018] };
              Size id_1021 { fun1016(id_1020) };
              Size id_1022 { Size(id_1015 + id_1021) };
              Void id_1023 { ((void)(sz_ref_452[id_1013] = id_1022), ::dessser::Void()) };
              (void)id_1023;
              uint8_t id_1024 { 0 };
              uint8_t id_1025 { 0 };
              int32_t id_1026 { repeat_n_453[id_1025] };
              int32_t id_1027 { 1L };
              int32_t id_1028 { int32_t(id_1026 + id_1027) };
              Void id_1029 { ((void)(repeat_n_453[id_1024] = id_1028), ::dessser::Void()) };
              (void)id_1029;
              (void)id_1029;
            }
          } while (while_flag_1006);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1030 { 0 };
        Size id_1031 { sz_ref_452[id_1030] };
        let_res_1003 = id_1031;
      }
      let_res_976 = let_res_1003;
    }
    Size let_res_1032;
    {
      Size sz_454 { let_res_976 };
      Arr<std::shared_ptr<::dessser::gen::alert::constant> > id_1033 { (*p_0).carry_csts };
      uint32_t id_1034 { id_1033.size() };
      Vec<1, uint32_t> id_1035 {  id_1034  };
      Size let_res_1036;
      {
        Vec<1, uint32_t> n_ref_455 { id_1035 };
        uint32_t id_1037 { 1U };
        Vec<1, uint32_t> id_1038 {  id_1037  };
        Size let_res_1039;
        {
          Vec<1, uint32_t> lebsz_ref_456 { id_1038 };
          bool while_flag_1040 { true };
          do {
            uint8_t id_1041 { 0 };
            uint32_t id_1042 { n_ref_455[id_1041] };
            uint8_t id_1043 { 0 };
            uint32_t id_1044 { lebsz_ref_456[id_1043] };
            uint8_t id_1045 { 7 };
            uint32_t id_1046 { uint32_t(id_1044 << id_1045) };
            bool id_1047 { bool(id_1042 >= id_1046) };
            while_flag_1040 = id_1047;
            if (while_flag_1040) {
              uint8_t id_1048 { 0 };
              uint8_t id_1049 { 0 };
              uint32_t id_1050 { lebsz_ref_456[id_1049] };
              uint32_t id_1051 { 1U };
              uint32_t id_1052 { uint32_t(id_1050 + id_1051) };
              Void id_1053 { ((void)(lebsz_ref_456[id_1048] = id_1052), ::dessser::Void()) };
              (void)id_1053;
            }
          } while (while_flag_1040);
          (void)::dessser::Void();
          uint8_t id_1054 { 0 };
          uint32_t id_1055 { lebsz_ref_456[id_1054] };
          Size id_1056 { Size(id_1055) };
          let_res_1039 = id_1056;
        }
        let_res_1036 = let_res_1039;
      }
      Size id_1057 { Size(sz_454 + let_res_1036) };
      Vec<1, Size> id_1058 {  id_1057  };
      Size let_res_1059;
      {
        Vec<1, Size> sz_ref_457 { id_1058 };
        int32_t id_1060 { 0L };
        Vec<1, int32_t> id_1061 {  id_1060  };
        {
          Vec<1, int32_t> repeat_n_458 { id_1061 };
          bool while_flag_1062 { true };
          do {
            Arr<std::shared_ptr<::dessser::gen::alert::constant> > id_1063 { (*p_0).carry_csts };
            uint32_t id_1064 { id_1063.size() };
            int32_t id_1065 { int32_t(id_1064) };
            uint8_t id_1066 { 0 };
            int32_t id_1067 { repeat_n_458[id_1066] };
            bool id_1068 { bool(id_1065 > id_1067) };
            while_flag_1062 = id_1068;
            if (while_flag_1062) {
              uint8_t id_1069 { 0 };
              uint8_t id_1070 { 0 };
              Size id_1071 { sz_ref_457[id_1070] };
              uint8_t id_1072 { 0 };
              int32_t id_1073 { repeat_n_458[id_1072] };
              Arr<std::shared_ptr<::dessser::gen::alert::constant> > id_1074 { (*p_0).carry_csts };
              std::shared_ptr<::dessser::gen::alert::constant>  id_1075 { id_1074[id_1073] };
              Size id_1076 { constant_sersize_of_row_binary(id_1075) };
              Size id_1077 { Size(id_1071 + id_1076) };
              Void id_1078 { ((void)(sz_ref_457[id_1069] = id_1077), ::dessser::Void()) };
              (void)id_1078;
              uint8_t id_1079 { 0 };
              uint8_t id_1080 { 0 };
              int32_t id_1081 { repeat_n_458[id_1080] };
              int32_t id_1082 { 1L };
              int32_t id_1083 { int32_t(id_1081 + id_1082) };
              Void id_1084 { ((void)(repeat_n_458[id_1079] = id_1083), ::dessser::Void()) };
              (void)id_1084;
              (void)id_1084;
            }
          } while (while_flag_1062);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1085 { 0 };
        Size id_1086 { sz_ref_457[id_1085] };
        let_res_1059 = id_1086;
      }
      let_res_1032 = let_res_1059;
    }
    Size let_res_1087;
    {
      Size sz_459 { let_res_1032 };
      std::string id_1088 { (*p_0).id };
      uint32_t id_1089 { (uint32_t)id_1088.size() };
      Vec<1, uint32_t> id_1090 {  id_1089  };
      Size let_res_1091;
      {
        Vec<1, uint32_t> n_ref_461 { id_1090 };
        uint32_t id_1092 { 1U };
        Vec<1, uint32_t> id_1093 {  id_1092  };
        Size let_res_1094;
        {
          Vec<1, uint32_t> lebsz_ref_462 { id_1093 };
          bool while_flag_1095 { true };
          do {
            uint8_t id_1096 { 0 };
            uint32_t id_1097 { n_ref_461[id_1096] };
            uint8_t id_1098 { 0 };
            uint32_t id_1099 { lebsz_ref_462[id_1098] };
            uint8_t id_1100 { 7 };
            uint32_t id_1101 { uint32_t(id_1099 << id_1100) };
            bool id_1102 { bool(id_1097 >= id_1101) };
            while_flag_1095 = id_1102;
            if (while_flag_1095) {
              uint8_t id_1103 { 0 };
              uint8_t id_1104 { 0 };
              uint32_t id_1105 { lebsz_ref_462[id_1104] };
              uint32_t id_1106 { 1U };
              uint32_t id_1107 { uint32_t(id_1105 + id_1106) };
              Void id_1108 { ((void)(lebsz_ref_462[id_1103] = id_1107), ::dessser::Void()) };
              (void)id_1108;
            }
          } while (while_flag_1095);
          (void)::dessser::Void();
          uint8_t id_1109 { 0 };
          uint32_t id_1110 { lebsz_ref_462[id_1109] };
          Size id_1111 { Size(id_1110) };
          let_res_1094 = id_1111;
        }
        let_res_1091 = let_res_1094;
      }
      std::string id_1112 { (*p_0).id };
      uint32_t id_1113 { (uint32_t)id_1112.size() };
      Size id_1114 { Size(id_1113) };
      Size id_1115 { Size(let_res_1091 + id_1114) };
      Size id_1116 { Size(sz_459 + id_1115) };
      let_res_1087 = id_1116;
    }
    Size let_res_1117;
    {
      Size sz_463 { let_res_1087 };
      std::string id_1118 { (*p_0).desc_title };
      uint32_t id_1119 { (uint32_t)id_1118.size() };
      Vec<1, uint32_t> id_1120 {  id_1119  };
      Size let_res_1121;
      {
        Vec<1, uint32_t> n_ref_465 { id_1120 };
        uint32_t id_1122 { 1U };
        Vec<1, uint32_t> id_1123 {  id_1122  };
        Size let_res_1124;
        {
          Vec<1, uint32_t> lebsz_ref_466 { id_1123 };
          bool while_flag_1125 { true };
          do {
            uint8_t id_1126 { 0 };
            uint32_t id_1127 { n_ref_465[id_1126] };
            uint8_t id_1128 { 0 };
            uint32_t id_1129 { lebsz_ref_466[id_1128] };
            uint8_t id_1130 { 7 };
            uint32_t id_1131 { uint32_t(id_1129 << id_1130) };
            bool id_1132 { bool(id_1127 >= id_1131) };
            while_flag_1125 = id_1132;
            if (while_flag_1125) {
              uint8_t id_1133 { 0 };
              uint8_t id_1134 { 0 };
              uint32_t id_1135 { lebsz_ref_466[id_1134] };
              uint32_t id_1136 { 1U };
              uint32_t id_1137 { uint32_t(id_1135 + id_1136) };
              Void id_1138 { ((void)(lebsz_ref_466[id_1133] = id_1137), ::dessser::Void()) };
              (void)id_1138;
            }
          } while (while_flag_1125);
          (void)::dessser::Void();
          uint8_t id_1139 { 0 };
          uint32_t id_1140 { lebsz_ref_466[id_1139] };
          Size id_1141 { Size(id_1140) };
          let_res_1124 = id_1141;
        }
        let_res_1121 = let_res_1124;
      }
      std::string id_1142 { (*p_0).desc_title };
      uint32_t id_1143 { (uint32_t)id_1142.size() };
      Size id_1144 { Size(id_1143) };
      Size id_1145 { Size(let_res_1121 + id_1144) };
      Size id_1146 { Size(sz_463 + id_1145) };
      let_res_1117 = id_1146;
    }
    Size let_res_1147;
    {
      Size sz_467 { let_res_1117 };
      std::string id_1148 { (*p_0).desc_firing };
      uint32_t id_1149 { (uint32_t)id_1148.size() };
      Vec<1, uint32_t> id_1150 {  id_1149  };
      Size let_res_1151;
      {
        Vec<1, uint32_t> n_ref_469 { id_1150 };
        uint32_t id_1152 { 1U };
        Vec<1, uint32_t> id_1153 {  id_1152  };
        Size let_res_1154;
        {
          Vec<1, uint32_t> lebsz_ref_470 { id_1153 };
          bool while_flag_1155 { true };
          do {
            uint8_t id_1156 { 0 };
            uint32_t id_1157 { n_ref_469[id_1156] };
            uint8_t id_1158 { 0 };
            uint32_t id_1159 { lebsz_ref_470[id_1158] };
            uint8_t id_1160 { 7 };
            uint32_t id_1161 { uint32_t(id_1159 << id_1160) };
            bool id_1162 { bool(id_1157 >= id_1161) };
            while_flag_1155 = id_1162;
            if (while_flag_1155) {
              uint8_t id_1163 { 0 };
              uint8_t id_1164 { 0 };
              uint32_t id_1165 { lebsz_ref_470[id_1164] };
              uint32_t id_1166 { 1U };
              uint32_t id_1167 { uint32_t(id_1165 + id_1166) };
              Void id_1168 { ((void)(lebsz_ref_470[id_1163] = id_1167), ::dessser::Void()) };
              (void)id_1168;
            }
          } while (while_flag_1155);
          (void)::dessser::Void();
          uint8_t id_1169 { 0 };
          uint32_t id_1170 { lebsz_ref_470[id_1169] };
          Size id_1171 { Size(id_1170) };
          let_res_1154 = id_1171;
        }
        let_res_1151 = let_res_1154;
      }
      std::string id_1172 { (*p_0).desc_firing };
      uint32_t id_1173 { (uint32_t)id_1172.size() };
      Size id_1174 { Size(id_1173) };
      Size id_1175 { Size(let_res_1151 + id_1174) };
      Size id_1176 { Size(sz_467 + id_1175) };
      let_res_1147 = id_1176;
    }
    Size let_res_1177;
    {
      Size sz_471 { let_res_1147 };
      std::string id_1178 { (*p_0).desc_recovery };
      uint32_t id_1179 { (uint32_t)id_1178.size() };
      Vec<1, uint32_t> id_1180 {  id_1179  };
      Size let_res_1181;
      {
        Vec<1, uint32_t> n_ref_473 { id_1180 };
        uint32_t id_1182 { 1U };
        Vec<1, uint32_t> id_1183 {  id_1182  };
        Size let_res_1184;
        {
          Vec<1, uint32_t> lebsz_ref_474 { id_1183 };
          bool while_flag_1185 { true };
          do {
            uint8_t id_1186 { 0 };
            uint32_t id_1187 { n_ref_473[id_1186] };
            uint8_t id_1188 { 0 };
            uint32_t id_1189 { lebsz_ref_474[id_1188] };
            uint8_t id_1190 { 7 };
            uint32_t id_1191 { uint32_t(id_1189 << id_1190) };
            bool id_1192 { bool(id_1187 >= id_1191) };
            while_flag_1185 = id_1192;
            if (while_flag_1185) {
              uint8_t id_1193 { 0 };
              uint8_t id_1194 { 0 };
              uint32_t id_1195 { lebsz_ref_474[id_1194] };
              uint32_t id_1196 { 1U };
              uint32_t id_1197 { uint32_t(id_1195 + id_1196) };
              Void id_1198 { ((void)(lebsz_ref_474[id_1193] = id_1197), ::dessser::Void()) };
              (void)id_1198;
            }
          } while (while_flag_1185);
          (void)::dessser::Void();
          uint8_t id_1199 { 0 };
          uint32_t id_1200 { lebsz_ref_474[id_1199] };
          Size id_1201 { Size(id_1200) };
          let_res_1184 = id_1201;
        }
        let_res_1181 = let_res_1184;
      }
      std::string id_1202 { (*p_0).desc_recovery };
      uint32_t id_1203 { (uint32_t)id_1202.size() };
      Size id_1204 { Size(id_1203) };
      Size id_1205 { Size(let_res_1181 + id_1204) };
      Size id_1206 { Size(sz_471 + id_1205) };
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
      (let "drec_129" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_130" "drec_snd_131" (identifier "drec_129")
          (let "dstring1_138"
            (let "leb_ref_132" (make-vec (u32 0))
              (let "shft_ref_133" (make-vec (u8 0))
                (let "p_ref_134" (make-vec (identifier "drec_snd_131"))
                  (seq
                    (while
                      (let "leb128_135" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_134")))
                        (let-pair "leb128_fst_136" "leb128_snd_137" (identifier "leb128_135")
                          (seq (set-vec (u8 0) (identifier "p_ref_134") (identifier "leb128_snd_137"))
                            (set-vec (u8 0) (identifier "leb_ref_132")
                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_136") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_133"))) (unsafe-nth (u8 0) (identifier "leb_ref_132"))))
                            (set-vec (u8 0) (identifier "shft_ref_133") (add (unsafe-nth (u8 0) (identifier "shft_ref_133")) (u8 7))) 
                            (ge (identifier "leb128_fst_136") (u8 128))))) 
                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_132"))) (unsafe-nth (u8 0) (identifier "p_ref_134")))))))
            (let-pair "dstring1_fst_139" "dstring1_snd_140" (identifier "dstring1_138")
              (let-pair "dstring2_fst_142" "dstring2_snd_143" (read-bytes (identifier "dstring1_snd_140") (identifier "dstring1_fst_139"))
                (make-tup (make-rec (string "value") (string-of-bytes (identifier "dstring2_fst_142")) (string "name") (identifier "drec_fst_130")) (identifier "dstring2_snd_143"))))))))
 */
static std::function<::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904(Pointer)> constant_of_row_binary_init()
{
  std::function<::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904(Pointer)> fun1207 { [&](Pointer p_0) {
    auto fun1208 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1209 { fun1208(p_0) };
    ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 let_res_1210;
    {
      ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 drec_129 { id_1209 };
      ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 letpair_res_1211;
      {
        auto drec_fst_130 { std::get<0>(drec_129) };
        auto drec_snd_131 { std::get<1>(drec_129) };
        uint32_t id_1212 { 0U };
        Vec<1, uint32_t> id_1213 {  id_1212  };
        ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1214;
        {
          Vec<1, uint32_t> leb_ref_132 { id_1213 };
          uint8_t id_1215 { 0 };
          Vec<1, uint8_t> id_1216 {  id_1215  };
          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1217;
          {
            Vec<1, uint8_t> shft_ref_133 { id_1216 };
            Vec<1, Pointer> id_1218 {  drec_snd_131  };
            ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1219;
            {
              Vec<1, Pointer> p_ref_134 { id_1218 };
              bool while_flag_1220 { true };
              do {
                uint8_t id_1221 { 0 };
                Pointer id_1222 { p_ref_134[id_1221] };
                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1223 { id_1222.readU8() };
                bool let_res_1224;
                {
                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_135 { id_1223 };
                  bool letpair_res_1225;
                  {
                    auto leb128_fst_136 { std::get<0>(leb128_135) };
                    auto leb128_snd_137 { std::get<1>(leb128_135) };
                    uint8_t id_1226 { 0 };
                    Void id_1227 { ((void)(p_ref_134[id_1226] = leb128_snd_137), ::dessser::Void()) };
                    (void)id_1227;
                    uint8_t id_1228 { 0 };
                    uint8_t id_1229 { 127 };
                    uint8_t id_1230 { uint8_t(leb128_fst_136 & id_1229) };
                    uint32_t id_1231 { uint32_t(id_1230) };
                    uint8_t id_1232 { 0 };
                    uint8_t id_1233 { shft_ref_133[id_1232] };
                    uint32_t id_1234 { uint32_t(id_1231 << id_1233) };
                    uint8_t id_1235 { 0 };
                    uint32_t id_1236 { leb_ref_132[id_1235] };
                    uint32_t id_1237 { uint32_t(id_1234 | id_1236) };
                    Void id_1238 { ((void)(leb_ref_132[id_1228] = id_1237), ::dessser::Void()) };
                    (void)id_1238;
                    uint8_t id_1239 { 0 };
                    uint8_t id_1240 { 0 };
                    uint8_t id_1241 { shft_ref_133[id_1240] };
                    uint8_t id_1242 { 7 };
                    uint8_t id_1243 { uint8_t(id_1241 + id_1242) };
                    Void id_1244 { ((void)(shft_ref_133[id_1239] = id_1243), ::dessser::Void()) };
                    (void)id_1244;
                    uint8_t id_1245 { 128 };
                    bool id_1246 { bool(leb128_fst_136 >= id_1245) };
                    letpair_res_1225 = id_1246;
                  }
                  let_res_1224 = letpair_res_1225;
                }
                while_flag_1220 = let_res_1224;
                if (while_flag_1220) {
                  (void)::dessser::Void();
                }
              } while (while_flag_1220);
              (void)::dessser::Void();
              uint8_t id_1247 { 0 };
              uint32_t id_1248 { leb_ref_132[id_1247] };
              Size id_1249 { Size(id_1248) };
              uint8_t id_1250 { 0 };
              Pointer id_1251 { p_ref_134[id_1250] };
              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1252 { id_1249, id_1251 };
              let_res_1219 = id_1252;
            }
            let_res_1217 = let_res_1219;
          }
          let_res_1214 = let_res_1217;
        }
        ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 let_res_1253;
        {
          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_138 { let_res_1214 };
          ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 letpair_res_1254;
          {
            auto dstring1_fst_139 { std::get<0>(dstring1_138) };
            auto dstring1_snd_140 { std::get<1>(dstring1_138) };
            ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1255 { dstring1_snd_140.readBytes(dstring1_fst_139) };
            ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 letpair_res_1256;
            {
              auto dstring2_fst_142 { std::get<0>(id_1255) };
              auto dstring2_snd_143 { std::get<1>(id_1255) };
              std::string id_1257 { dstring2_fst_142.toString() };
              std::shared_ptr<::dessser::gen::alert::constant>  id_1258 { std::make_shared<::dessser::gen::alert::constant>(drec_fst_130, id_1257) };
              ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 id_1259 { id_1258, dstring2_snd_143 };
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
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (let-pair "dfloat_fst_124" "dfloat_snd_125" (read-u64 little-endian (identifier "dsum1_snd_65"))
              (make-tup
                (construct "[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]" 0
                  (float-of-u64 (identifier "dfloat_fst_124"))) (identifier "dfloat_snd_125")))
            (seq (assert (eq (identifier "dsum1_fst_64") (u16 1)))
              (let "drec_69" (let-pair "dfloat_fst_67" "dfloat_snd_68" (read-u64 little-endian (identifier "dsum1_snd_65")) (make-tup (float-of-u64 (identifier "dfloat_fst_67")) (identifier "dfloat_snd_68")))
                (let-pair "drec_fst_70" "drec_snd_71" (identifier "drec_69")
                  (let "drec_75" (let-pair "du32_fst_73" "du32_snd_74" (read-u32 little-endian (identifier "drec_snd_71")) (make-tup (identifier "du32_fst_73") (identifier "du32_snd_74")))
                    (let-pair "drec_fst_76" "drec_snd_77" (identifier "drec_75")
                      (let "drec_81" (let-pair "dfloat_fst_79" "dfloat_snd_80" (read-u64 little-endian (identifier "drec_snd_77")) (make-tup (float-of-u64 (identifier "dfloat_fst_79")) (identifier "dfloat_snd_80")))
                        (let-pair "drec_fst_82" "drec_snd_83" (identifier "drec_81")
                          (let "drec_87" (let-pair "du32_fst_85" "du32_snd_86" (read-u32 little-endian (identifier "drec_snd_83")) (make-tup (identifier "du32_fst_85") (identifier "du32_snd_86")))
                            (let-pair "drec_fst_88" "drec_snd_89" (identifier "drec_87")
                              (let "drec_93" (let-pair "dfloat_fst_91" "dfloat_snd_92" (read-u64 little-endian (identifier "drec_snd_89")) (make-tup (float-of-u64 (identifier "dfloat_fst_91")) (identifier "dfloat_snd_92")))
                                (let-pair "drec_fst_94" "drec_snd_95" 
                                  (identifier "drec_93")
                                  (let-pair "drec_fst_118" "drec_snd_119"
                                    (let "dsum1_102" (let-pair "du16_fst_97" "du16_snd_98" (read-u16 little-endian (identifier "drec_snd_95")) (make-tup (identifier "du16_fst_97") (identifier "du16_snd_98")))
                                      (let-pair "dsum1_fst_103" "dsum1_snd_104" 
                                        (identifier "dsum1_102")
                                        (if (eq (u16 0) (identifier "dsum1_fst_103"))
                                          (let-pair "dfloat_fst_112" "dfloat_snd_113" 
                                            (read-u64 little-endian (identifier "dsum1_snd_104"))
                                            (make-tup (construct "[Absolute FLOAT | Relative FLOAT]" 0 (float-of-u64 (identifier "dfloat_fst_112"))) (identifier "dfloat_snd_113")))
                                          (seq (assert (eq (identifier "dsum1_fst_103") (u16 1)))
                                            (let-pair "dfloat_fst_106" "dfloat_snd_107" 
                                              (read-u64 little-endian (identifier "dsum1_snd_104"))
                                              (make-tup (construct "[Absolute FLOAT | Relative FLOAT]" 1 (float-of-u64 (identifier "dfloat_fst_106"))) (identifier "dfloat_snd_107")))))))
                                    (make-tup
                                      (construct "[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]" 1
                                        (make-rec (string "max_distance") 
                                          (identifier "drec_fst_118") 
                                          (string "smooth_factor") (identifier "drec_fst_94") 
                                          (string "seasonality") (identifier "drec_fst_88") 
                                          (string "percentile") (identifier "drec_fst_82") 
                                          (string "sample_size") (identifier "drec_fst_76") 
                                          (string "avg_window") (identifier "drec_fst_70"))) 
                                      (identifier "drec_snd_119"))))))))))))))))))
 */
static std::function<::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91(Pointer)> threshold_of_row_binary_init()
{
  std::function<::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91(Pointer)> fun1260 { [&](Pointer p_0) {
    ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1261 { p_0.readU16Le() };
    ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1262;
    {
      auto du16_fst_58 { std::get<0>(id_1261) };
      auto du16_snd_59 { std::get<1>(id_1261) };
      ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1263 { du16_fst_58, du16_snd_59 };
      letpair_res_1262 = id_1263;
    }
    ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1264;
    {
      ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_1262 };
      ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1265;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_1266 { 0 };
        bool id_1267 { bool(id_1266 == dsum1_fst_64) };
        ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 choose_res_1268;
        if (id_1267) {
          ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1269 { dsum1_snd_65.readU64Le() };
          ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1270;
          {
            auto dfloat_fst_124 { std::get<0>(id_1269) };
            auto dfloat_snd_125 { std::get<1>(id_1269) };
            double id_1271 { float_of_qword(dfloat_fst_124) };
            std::shared_ptr<::dessser::gen::alert::threshold>  id_1272 { std::make_shared<::dessser::gen::alert::threshold>(std::in_place_index<0>, id_1271) };
            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 id_1273 { id_1272, dfloat_snd_125 };
            letpair_res_1270 = id_1273;
          }
          choose_res_1268 = letpair_res_1270;
        } else {
          uint16_t id_1274 { 1 };
          bool id_1275 { bool(dsum1_fst_64 == id_1274) };
          Void id_1276 { ((void)(assert(id_1275)), ::dessser::Void()) };
          (void)id_1276;
          ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1277 { dsum1_snd_65.readU64Le() };
          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1278;
          {
            auto dfloat_fst_67 { std::get<0>(id_1277) };
            auto dfloat_snd_68 { std::get<1>(id_1277) };
            double id_1279 { float_of_qword(dfloat_fst_67) };
            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1280 { id_1279, dfloat_snd_68 };
            letpair_res_1278 = id_1280;
          }
          ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1281;
          {
            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_69 { letpair_res_1278 };
            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1282;
            {
              auto drec_fst_70 { std::get<0>(drec_69) };
              auto drec_snd_71 { std::get<1>(drec_69) };
              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1283 { drec_snd_71.readU32Le() };
              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 letpair_res_1284;
              {
                auto du32_fst_73 { std::get<0>(id_1283) };
                auto du32_snd_74 { std::get<1>(id_1283) };
                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1285 { du32_fst_73, du32_snd_74 };
                letpair_res_1284 = id_1285;
              }
              ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1286;
              {
                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 drec_75 { letpair_res_1284 };
                ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1287;
                {
                  auto drec_fst_76 { std::get<0>(drec_75) };
                  auto drec_snd_77 { std::get<1>(drec_75) };
                  ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1288 { drec_snd_77.readU64Le() };
                  ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1289;
                  {
                    auto dfloat_fst_79 { std::get<0>(id_1288) };
                    auto dfloat_snd_80 { std::get<1>(id_1288) };
                    double id_1290 { float_of_qword(dfloat_fst_79) };
                    ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1291 { id_1290, dfloat_snd_80 };
                    letpair_res_1289 = id_1291;
                  }
                  ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1292;
                  {
                    ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_81 { letpair_res_1289 };
                    ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1293;
                    {
                      auto drec_fst_82 { std::get<0>(drec_81) };
                      auto drec_snd_83 { std::get<1>(drec_81) };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1294 { drec_snd_83.readU32Le() };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 letpair_res_1295;
                      {
                        auto du32_fst_85 { std::get<0>(id_1294) };
                        auto du32_snd_86 { std::get<1>(id_1294) };
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1296 { du32_fst_85, du32_snd_86 };
                        letpair_res_1295 = id_1296;
                      }
                      ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1297;
                      {
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 drec_87 { letpair_res_1295 };
                        ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1298;
                        {
                          auto drec_fst_88 { std::get<0>(drec_87) };
                          auto drec_snd_89 { std::get<1>(drec_87) };
                          ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1299 { drec_snd_89.readU64Le() };
                          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1300;
                          {
                            auto dfloat_fst_91 { std::get<0>(id_1299) };
                            auto dfloat_snd_92 { std::get<1>(id_1299) };
                            double id_1301 { float_of_qword(dfloat_fst_91) };
                            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1302 { id_1301, dfloat_snd_92 };
                            letpair_res_1300 = id_1302;
                          }
                          ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 let_res_1303;
                          {
                            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_93 { letpair_res_1300 };
                            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 letpair_res_1304;
                            {
                              auto drec_fst_94 { std::get<0>(drec_93) };
                              auto drec_snd_95 { std::get<1>(drec_93) };
                              ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1305 { drec_snd_95.readU16Le() };
                              ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1306;
                              {
                                auto du16_fst_97 { std::get<0>(id_1305) };
                                auto du16_snd_98 { std::get<1>(id_1305) };
                                ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 id_1307 { du16_fst_97, du16_snd_98 };
                                letpair_res_1306 = id_1307;
                              }
                              ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 let_res_1308;
                              {
                                ::dessser::gen::alert::ta97bb48ed75bbda6173555873826c8c6 dsum1_102 { letpair_res_1306 };
                                ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 letpair_res_1309;
                                {
                                  auto dsum1_fst_103 { std::get<0>(dsum1_102) };
                                  auto dsum1_snd_104 { std::get<1>(dsum1_102) };
                                  uint16_t id_1310 { 0 };
                                  bool id_1311 { bool(id_1310 == dsum1_fst_103) };
                                  ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 choose_res_1312;
                                  if (id_1311) {
                                    ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1313 { dsum1_snd_104.readU64Le() };
                                    ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 letpair_res_1314;
                                    {
                                      auto dfloat_fst_112 { std::get<0>(id_1313) };
                                      auto dfloat_snd_113 { std::get<1>(id_1313) };
                                      double id_1315 { float_of_qword(dfloat_fst_112) };
                                      ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_1316 { std::in_place_index<0>, id_1315 };
                                      ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 id_1317 { id_1316, dfloat_snd_113 };
                                      letpair_res_1314 = id_1317;
                                    }
                                    choose_res_1312 = letpair_res_1314;
                                  } else {
                                    uint16_t id_1318 { 1 };
                                    bool id_1319 { bool(dsum1_fst_103 == id_1318) };
                                    Void id_1320 { ((void)(assert(id_1319)), ::dessser::Void()) };
                                    (void)id_1320;
                                    ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1321 { dsum1_snd_104.readU64Le() };
                                    ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 letpair_res_1322;
                                    {
                                      auto dfloat_fst_106 { std::get<0>(id_1321) };
                                      auto dfloat_snd_107 { std::get<1>(id_1321) };
                                      double id_1323 { float_of_qword(dfloat_fst_106) };
                                      ::dessser::gen::alert::t1287f5ccd09b12d10e0e8359b374ce64 id_1324 { std::in_place_index<1>, id_1323 };
                                      ::dessser::gen::alert::tc35264428ed4b717e8fbc891998f97e3 id_1325 { id_1324, dfloat_snd_107 };
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
                                auto drec_fst_118 { std::get<0>(let_res_1308) };
                                auto drec_snd_119 { std::get<1>(let_res_1308) };
                                ::dessser::gen::alert::t4d94676e99bfec48ddb223ef58e339ac id_1327 { drec_fst_70, drec_fst_76, drec_fst_82, drec_fst_88, drec_fst_94, drec_fst_118 };
                                std::shared_ptr<::dessser::gen::alert::threshold>  id_1328 { std::make_shared<::dessser::gen::alert::threshold>(std::in_place_index<1>, id_1327) };
                                ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 id_1329 { id_1328, drec_snd_119 };
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
      (let "drec_147" (apply (ext-identifier fq_name of-row-binary) (param 0))
        (let-pair "drec_fst_148" "drec_snd_149" (identifier "drec_147")
          (let "drec_150" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_149"))
            (let-pair "drec_fst_151" "drec_snd_152" (identifier "drec_150")
              (let "drec_156" (let-pair "dbool_fst_154" "dbool_snd_155" (read-u8 (identifier "drec_snd_152")) (make-tup (not (eq (identifier "dbool_fst_154") (u8 0))) (identifier "dbool_snd_155")))
                (let-pair "drec_fst_157" "drec_snd_158" (identifier "drec_156")
                  (let "drec_182"
                    (let-pair "dlist4_fst_180" "dlist4_snd_181"
                      (let "dlist1_168"
                        (let "leb_ref_159" (make-vec (u32 0))
                          (let "shft_ref_160" (make-vec (u8 0))
                            (let "p_ref_161" (make-vec (identifier "drec_snd_158"))
                              (seq
                                (while
                                  (let "leb128_162" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_161")))
                                    (let-pair "leb128_fst_163" "leb128_snd_164" 
                                      (identifier "leb128_162")
                                      (seq (set-vec (u8 0) (identifier "p_ref_161") (identifier "leb128_snd_164"))
                                        (set-vec (u8 0) (identifier "leb_ref_159")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_163") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_160"))) (unsafe-nth (u8 0) (identifier "leb_ref_159"))))
                                        (set-vec (u8 0) (identifier "shft_ref_160") (add (unsafe-nth (u8 0) (identifier "shft_ref_160")) (u8 7))) 
                                        (ge (identifier "leb128_fst_163") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_159")) (unsafe-nth (u8 0) (identifier "p_ref_161")))))))
                        (let-pair "dlist1_fst_169" "dlist1_snd_170" (identifier "dlist1_168")
                          (let "inits_src_ref_171" (make-vec (make-tup (end-of-list "$simple_filter") (identifier "dlist1_snd_170")))
                            (seq
                              (let "repeat_n_172" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_169")) (unsafe-nth (u8 0) (identifier "repeat_n_172")))
                                  (seq
                                    (let "dlist2_173" (unsafe-nth (u8 0) (identifier "inits_src_ref_171"))
                                      (let-pair "dlist2_fst_174" "dlist2_snd_175" 
                                        (identifier "dlist2_173")
                                        (set-vec (u8 0) (identifier "inits_src_ref_171")
                                          (let-pair "dlist3_fst_177" "dlist3_snd_178" 
                                            (apply (ext-identifier simple_filter of-row-binary) (identifier "dlist2_snd_175"))
                                            (make-tup (cons (identifier "dlist3_fst_177") (identifier "dlist2_fst_174")) (identifier "dlist3_snd_178"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_172") (add (unsafe-nth (u8 0) (identifier "repeat_n_172")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_171")))))) 
                      (make-tup (arr-of-lst-rev (identifier "dlist4_fst_180")) (identifier "dlist4_snd_181")))
                    (let-pair "drec_fst_183" "drec_snd_184" (identifier "drec_182")
                      (let "drec_211"
                        (if (eq (peek-u8 (identifier "drec_snd_184") (size 0)) (u8 1)) 
                          (make-tup (null "$field_name[]") (ptr-add (identifier "drec_snd_184") (size 1)))
                          (let-pair "dlist4_fst_206" "dlist4_snd_207"
                            (let "dlist1_194"
                              (let "leb_ref_185" (make-vec (u32 0))
                                (let "shft_ref_186" (make-vec (u8 0))
                                  (let "p_ref_187" (make-vec (ptr-add (identifier "drec_snd_184") (size 1)))
                                    (seq
                                      (while
                                        (let "leb128_188" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_187")))
                                          (let-pair "leb128_fst_189" "leb128_snd_190" 
                                            (identifier "leb128_188")
                                            (seq (set-vec (u8 0) (identifier "p_ref_187") (identifier "leb128_snd_190"))
                                              (set-vec (u8 0) (identifier "leb_ref_185")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_189") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_186"))) (unsafe-nth (u8 0) (identifier "leb_ref_185"))))
                                              (set-vec (u8 0) (identifier "shft_ref_186") (add (unsafe-nth (u8 0) (identifier "shft_ref_186")) (u8 7))) 
                                              (ge (identifier "leb128_fst_189") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_185")) (unsafe-nth (u8 0) (identifier "p_ref_187")))))))
                              (let-pair "dlist1_fst_195" "dlist1_snd_196" 
                                (identifier "dlist1_194")
                                (let "inits_src_ref_197" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_196")))
                                  (seq
                                    (let "repeat_n_198" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_195")) (unsafe-nth (u8 0) (identifier "repeat_n_198")))
                                        (seq
                                          (let "dlist2_199" (unsafe-nth (u8 0) (identifier "inits_src_ref_197"))
                                            (let-pair "dlist2_fst_200" "dlist2_snd_201" 
                                              (identifier "dlist2_199")
                                              (set-vec (u8 0) (identifier "inits_src_ref_197")
                                                (let-pair "dlist3_fst_203" "dlist3_snd_204" 
                                                  (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_201"))
                                                  (make-tup (cons (identifier "dlist3_fst_203") (identifier "dlist2_fst_200")) (identifier "dlist3_snd_204"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_198") (add (unsafe-nth (u8 0) (identifier "repeat_n_198")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_197")))))) 
                            (make-tup (not-null (arr-of-lst-rev (identifier "dlist4_fst_206"))) (identifier "dlist4_snd_207"))))
                        (let-pair "drec_fst_212" "drec_snd_213" (identifier "drec_211")
                          (let "drec_237"
                            (let-pair "dlist4_fst_235" "dlist4_snd_236"
                              (let "dlist1_223"
                                (let "leb_ref_214" (make-vec (u32 0))
                                  (let "shft_ref_215" (make-vec (u8 0))
                                    (let "p_ref_216" (make-vec (identifier "drec_snd_213"))
                                      (seq
                                        (while
                                          (let "leb128_217" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_216")))
                                            (let-pair "leb128_fst_218" "leb128_snd_219" 
                                              (identifier "leb128_217")
                                              (seq (set-vec (u8 0) (identifier "p_ref_216") (identifier "leb128_snd_219"))
                                                (set-vec (u8 0) (identifier "leb_ref_214")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_218") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_215"))) (unsafe-nth (u8 0) (identifier "leb_ref_214"))))
                                                (set-vec (u8 0) (identifier "shft_ref_215") (add (unsafe-nth (u8 0) (identifier "shft_ref_215")) (u8 7))) 
                                                (ge (identifier "leb128_fst_218") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_214")) (unsafe-nth (u8 0) (identifier "p_ref_216")))))))
                                (let-pair "dlist1_fst_224" "dlist1_snd_225" 
                                  (identifier "dlist1_223")
                                  (let "inits_src_ref_226" (make-vec (make-tup (end-of-list "$simple_filter") (identifier "dlist1_snd_225")))
                                    (seq
                                      (let "repeat_n_227" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_224")) (unsafe-nth (u8 0) (identifier "repeat_n_227")))
                                          (seq
                                            (let "dlist2_228" (unsafe-nth (u8 0) (identifier "inits_src_ref_226"))
                                              (let-pair "dlist2_fst_229" "dlist2_snd_230" 
                                                (identifier "dlist2_228")
                                                (set-vec (u8 0) (identifier "inits_src_ref_226")
                                                  (let-pair "dlist3_fst_232" "dlist3_snd_233" 
                                                    (apply (ext-identifier simple_filter of-row-binary) (identifier "dlist2_snd_230"))
                                                    (make-tup (cons (identifier "dlist3_fst_232") (identifier "dlist2_fst_229")) (identifier "dlist3_snd_233"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_227") (add (unsafe-nth (u8 0) (identifier "repeat_n_227")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_226")))))) 
                              (make-tup (arr-of-lst-rev (identifier "dlist4_fst_235")) (identifier "dlist4_snd_236")))
                            (let-pair "drec_fst_238" "drec_snd_239" (identifier "drec_237")
                              (let "drec_240" (apply (identifier "threshold-of-row-binary") (identifier "drec_snd_239"))
                                (let-pair "drec_fst_241" "drec_snd_242" 
                                  (identifier "drec_240")
                                  (let "drec_246"
                                    (let-pair "dfloat_fst_244" "dfloat_snd_245" (read-u64 little-endian (identifier "drec_snd_242")) (make-tup (float-of-u64 (identifier "dfloat_fst_244")) (identifier "dfloat_snd_245")))
                                    (let-pair "drec_fst_247" "drec_snd_248" 
                                      (identifier "drec_246")
                                      (let "drec_252"
                                        (let-pair "dfloat_fst_250" "dfloat_snd_251" (read-u64 little-endian (identifier "drec_snd_248")) (make-tup (float-of-u64 (identifier "dfloat_fst_250")) (identifier "dfloat_snd_251")))
                                        (let-pair "drec_fst_253" "drec_snd_254" 
                                          (identifier "drec_252")
                                          (let "drec_258"
                                            (let-pair "dfloat_fst_256" "dfloat_snd_257" (read-u64 little-endian (identifier "drec_snd_254")) (make-tup (float-of-u64 (identifier "dfloat_fst_256")) (identifier "dfloat_snd_257")))
                                            (let-pair "drec_fst_259" "drec_snd_260" 
                                              (identifier "drec_258")
                                              (let "drec_264"
                                                (let-pair "dfloat_fst_262" "dfloat_snd_263" 
                                                  (read-u64 little-endian (identifier "drec_snd_260")) 
                                                  (make-tup (float-of-u64 (identifier "dfloat_fst_262")) (identifier "dfloat_snd_263")))
                                                (let-pair "drec_fst_265" "drec_snd_266" 
                                                  (identifier "drec_264")
                                                  (let "drec_290"
                                                    (let-pair "dlist4_fst_288" "dlist4_snd_289"
                                                      (let "dlist1_276"
                                                        (let "leb_ref_267" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_268" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_269" 
                                                              (make-vec (identifier "drec_snd_266"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_270" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_269")))
                                                                    (let-pair "leb128_fst_271" "leb128_snd_272" 
                                                                    (identifier "leb128_270")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_269") (identifier "leb128_snd_272"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_267")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_271") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_268")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_267")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_268") (add (unsafe-nth (u8 0) (identifier "shft_ref_268")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_271") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_267")) (unsafe-nth (u8 0) (identifier "p_ref_269")))))))
                                                        (let-pair "dlist1_fst_277" "dlist1_snd_278" 
                                                          (identifier "dlist1_276")
                                                          (let "inits_src_ref_279" 
                                                            (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_278")))
                                                            (seq
                                                              (let "repeat_n_280" 
                                                                (make-vec (i32 0))
                                                                (while 
                                                                  (gt (to-i32 (identifier "dlist1_fst_277")) (unsafe-nth (u8 0) (identifier "repeat_n_280")))
                                                                  (seq
                                                                    (let "dlist2_281" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_279"))
                                                                    (let-pair "dlist2_fst_282" "dlist2_snd_283" 
                                                                    (identifier "dlist2_281")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_279")
                                                                    (let-pair "dlist3_fst_285" "dlist3_snd_286" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_283"))
                                                                    (make-tup (cons (identifier "dlist3_fst_285") (identifier "dlist2_fst_282")) (identifier "dlist3_snd_286"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_280") (add (unsafe-nth (u8 0) (identifier "repeat_n_280")) (i32 1))))))
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_279")))))) 
                                                      (make-tup (arr-of-lst-rev (identifier "dlist4_fst_288")) (identifier "dlist4_snd_289")))
                                                    (let-pair "drec_fst_291" "drec_snd_292" 
                                                      (identifier "drec_290")
                                                      (let "drec_316"
                                                        (let-pair "dlist4_fst_314" "dlist4_snd_315"
                                                          (let "dlist1_302"
                                                            (let "leb_ref_293" 
                                                              (make-vec (u32 0))
                                                              (let "shft_ref_294" 
                                                                (make-vec (u8 0))
                                                                (let "p_ref_295" 
                                                                  (make-vec (identifier "drec_snd_292"))
                                                                  (seq
                                                                    (while
                                                                    (let "leb128_296" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_295")))
                                                                    (let-pair "leb128_fst_297" "leb128_snd_298" 
                                                                    (identifier "leb128_296")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_295") (identifier "leb128_snd_298"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_293")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_297") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_294")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_293")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_294") (add (unsafe-nth (u8 0) (identifier "shft_ref_294")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_297") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_293")) (unsafe-nth (u8 0) (identifier "p_ref_295")))))))
                                                            (let-pair "dlist1_fst_303" "dlist1_snd_304" 
                                                              (identifier "dlist1_302")
                                                              (let "inits_src_ref_305" 
                                                                (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_304")))
                                                                (seq
                                                                  (let "repeat_n_306" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_303")) (unsafe-nth (u8 0) (identifier "repeat_n_306")))
                                                                    (seq
                                                                    (let "dlist2_307" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_305"))
                                                                    (let-pair "dlist2_fst_308" "dlist2_snd_309" 
                                                                    (identifier "dlist2_307")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_305")
                                                                    (let-pair "dlist3_fst_311" "dlist3_snd_312" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_309"))
                                                                    (make-tup (cons (identifier "dlist3_fst_311") (identifier "dlist2_fst_308")) (identifier "dlist3_snd_312"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_306") (add (unsafe-nth (u8 0) (identifier "repeat_n_306")) (i32 1))))))
                                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_305")))))) 
                                                          (make-tup (arr-of-lst-rev (identifier "dlist4_fst_314")) (identifier "dlist4_snd_315")))
                                                        (let-pair "drec_fst_317" "drec_snd_318" 
                                                          (identifier "drec_316")
                                                          (let "drec_342"
                                                            (let-pair "dlist4_fst_340" "dlist4_snd_341"
                                                              (let "dlist1_328"
                                                                (let "leb_ref_319" 
                                                                  (make-vec (u32 0))
                                                                  (let "shft_ref_320" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_321" 
                                                                    (make-vec (identifier "drec_snd_318"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_322" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_321")))
                                                                    (let-pair "leb128_fst_323" "leb128_snd_324" 
                                                                    (identifier "leb128_322")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_321") (identifier "leb128_snd_324"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_319")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_323") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_320")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_319")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_320") (add (unsafe-nth (u8 0) (identifier "shft_ref_320")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_323") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_319")) (unsafe-nth (u8 0) (identifier "p_ref_321")))))))
                                                                (let-pair "dlist1_fst_329" "dlist1_snd_330" 
                                                                  (identifier "dlist1_328")
                                                                  (let "inits_src_ref_331" 
                                                                    (make-vec (make-tup (end-of-list "(constant AS {name: $field_name; value: STRING})") (identifier "dlist1_snd_330")))
                                                                    (seq
                                                                    (let "repeat_n_332" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_329")) (unsafe-nth (u8 0) (identifier "repeat_n_332")))
                                                                    (seq
                                                                    (let "dlist2_333" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_331"))
                                                                    (let-pair "dlist2_fst_334" "dlist2_snd_335" 
                                                                    (identifier "dlist2_333")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_331")
                                                                    (let-pair "dlist3_fst_337" "dlist3_snd_338" 
                                                                    (apply (identifier "constant-of-row-binary") (identifier "dlist2_snd_335"))
                                                                    (make-tup (cons (identifier "dlist3_fst_337") (identifier "dlist2_fst_334")) (identifier "dlist3_snd_338"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_332") (add (unsafe-nth (u8 0) (identifier "repeat_n_332")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_331")))))) 
                                                              (make-tup (arr-of-lst-rev (identifier "dlist4_fst_340")) (identifier "dlist4_snd_341")))
                                                            (let-pair "drec_fst_343" "drec_snd_344" 
                                                              (identifier "drec_342")
                                                              (let "drec_357"
                                                                (let "dstring1_351"
                                                                  (let "leb_ref_345" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_346" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_347" 
                                                                    (make-vec (identifier "drec_snd_344"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_348" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_347")))
                                                                    (let-pair "leb128_fst_349" "leb128_snd_350" 
                                                                    (identifier "leb128_348")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_347") (identifier "leb128_snd_350"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_345")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_349") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_346")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_345")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_346") (add (unsafe-nth (u8 0) (identifier "shft_ref_346")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_349") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_345"))) (unsafe-nth (u8 0) (identifier "p_ref_347")))))))
                                                                  (let-pair "dstring1_fst_352" "dstring1_snd_353" 
                                                                    (identifier "dstring1_351")
                                                                    (let-pair "dstring2_fst_355" "dstring2_snd_356" 
                                                                    (read-bytes (identifier "dstring1_snd_353") (identifier "dstring1_fst_352"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_355")) (identifier "dstring2_snd_356")))))
                                                                (let-pair "drec_fst_358" "drec_snd_359" 
                                                                  (identifier "drec_357")
                                                                  (let "drec_372"
                                                                    (let "dstring1_366"
                                                                    (let "leb_ref_360" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_361" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_362" 
                                                                    (make-vec (identifier "drec_snd_359"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_363" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_362")))
                                                                    (let-pair "leb128_fst_364" "leb128_snd_365" 
                                                                    (identifier "leb128_363")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_362") (identifier "leb128_snd_365"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_360")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_364") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_361")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_360")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_361") (add (unsafe-nth (u8 0) (identifier "shft_ref_361")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_364") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_360"))) (unsafe-nth (u8 0) (identifier "p_ref_362")))))))
                                                                    (let-pair "dstring1_fst_367" "dstring1_snd_368" 
                                                                    (identifier "dstring1_366")
                                                                    (let-pair "dstring2_fst_370" "dstring2_snd_371" 
                                                                    (read-bytes (identifier "dstring1_snd_368") (identifier "dstring1_fst_367"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_370")) (identifier "dstring2_snd_371")))))
                                                                    (let-pair "drec_fst_373" "drec_snd_374" 
                                                                    (identifier "drec_372")
                                                                    (let "drec_387"
                                                                    (let "dstring1_381"
                                                                    (let "leb_ref_375" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_376" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_377" 
                                                                    (make-vec (identifier "drec_snd_374"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_378" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_377")))
                                                                    (let-pair "leb128_fst_379" "leb128_snd_380" 
                                                                    (identifier "leb128_378")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_377") (identifier "leb128_snd_380"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_375")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_379") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_376")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_375")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_376") (add (unsafe-nth (u8 0) (identifier "shft_ref_376")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_379") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_375"))) (unsafe-nth (u8 0) (identifier "p_ref_377")))))))
                                                                    (let-pair "dstring1_fst_382" "dstring1_snd_383" 
                                                                    (identifier "dstring1_381")
                                                                    (let-pair "dstring2_fst_385" "dstring2_snd_386" 
                                                                    (read-bytes (identifier "dstring1_snd_383") (identifier "dstring1_fst_382"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_385")) (identifier "dstring2_snd_386")))))
                                                                    (let-pair "drec_fst_388" "drec_snd_389" 
                                                                    (identifier "drec_387")
                                                                    (let "dstring1_396"
                                                                    (let "leb_ref_390" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_391" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_392" 
                                                                    (make-vec (identifier "drec_snd_389"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_393" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_392")))
                                                                    (let-pair "leb128_fst_394" "leb128_snd_395" 
                                                                    (identifier "leb128_393")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_392") (identifier "leb128_snd_395"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_390")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_394") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_391")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_390")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_391") (add (unsafe-nth (u8 0) (identifier "shft_ref_391")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_394") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_390"))) (unsafe-nth (u8 0) (identifier "p_ref_392")))))))
                                                                    (let-pair "dstring1_fst_397" "dstring1_snd_398" 
                                                                    (identifier "dstring1_396")
                                                                    (let-pair "dstring2_fst_400" "dstring2_snd_401" 
                                                                    (read-bytes (identifier "dstring1_snd_398") (identifier "dstring1_fst_397"))
                                                                    (make-tup
                                                                    (make-rec 
                                                                    (string "desc-recovery") 
                                                                    (string-of-bytes (identifier "dstring2_fst_400")) 
                                                                    (string "desc-firing") 
                                                                    (identifier "drec_fst_388") 
                                                                    (string "desc-title") 
                                                                    (identifier "drec_fst_373") 
                                                                    (string "id") 
                                                                    (identifier "drec_fst_358") 
                                                                    (string "carry-csts") 
                                                                    (identifier "drec_fst_343") 
                                                                    (string "carry-fields") 
                                                                    (identifier "drec_fst_317") 
                                                                    (string "tops") 
                                                                    (identifier "drec_fst_291") 
                                                                    (string "time-step") 
                                                                    (identifier "drec_fst_265") 
                                                                    (string "ratio") 
                                                                    (identifier "drec_fst_259") 
                                                                    (string "duration") 
                                                                    (identifier "drec_fst_253") 
                                                                    (string "hysteresis") 
                                                                    (identifier "drec_fst_247") 
                                                                    (string "threshold") 
                                                                    (identifier "drec_fst_241") 
                                                                    (string "having") 
                                                                    (identifier "drec_fst_238") 
                                                                    (string "group-by") 
                                                                    (identifier "drec_fst_212") 
                                                                    (string "where") 
                                                                    (identifier "drec_fst_183") 
                                                                    (string "enabled") 
                                                                    (identifier "drec_fst_157") 
                                                                    (string "column") 
                                                                    (identifier "drec_fst_151") 
                                                                    (string "table") 
                                                                    (identifier "drec_fst_148")) 
                                                                    (identifier "dstring2_snd_401"))))))))))))))))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> fun1330 { [&](Pointer p_0) {
    auto fun1331 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::alert::t1067cf8ed87e4e016349f71797fb0661 id_1332 { fun1331(p_0) };
    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1333;
    {
      ::dessser::gen::alert::t1067cf8ed87e4e016349f71797fb0661 drec_147 { id_1332 };
      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1334;
      {
        auto drec_fst_148 { std::get<0>(drec_147) };
        auto drec_snd_149 { std::get<1>(drec_147) };
        auto fun1335 { dessser::gen::field_name::of_row_binary };
        ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1336 { fun1335(drec_snd_149) };
        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1337;
        {
          ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 drec_150 { id_1336 };
          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1338;
          {
            auto drec_fst_151 { std::get<0>(drec_150) };
            auto drec_snd_152 { std::get<1>(drec_150) };
            ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1339 { drec_snd_152.readU8() };
            ::dessser::gen::alert::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1340;
            {
              auto dbool_fst_154 { std::get<0>(id_1339) };
              auto dbool_snd_155 { std::get<1>(id_1339) };
              uint8_t id_1341 { 0 };
              bool id_1342 { bool(dbool_fst_154 == id_1341) };
              bool id_1343 { ! id_1342 };
              ::dessser::gen::alert::tf9a0a3fefc87c9e10a93d3a172850c26 id_1344 { id_1343, dbool_snd_155 };
              letpair_res_1340 = id_1344;
            }
            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1345;
            {
              ::dessser::gen::alert::tf9a0a3fefc87c9e10a93d3a172850c26 drec_156 { letpair_res_1340 };
              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1346;
              {
                auto drec_fst_157 { std::get<0>(drec_156) };
                auto drec_snd_158 { std::get<1>(drec_156) };
                uint32_t id_1347 { 0U };
                Vec<1, uint32_t> id_1348 {  id_1347  };
                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1349;
                {
                  Vec<1, uint32_t> leb_ref_159 { id_1348 };
                  uint8_t id_1350 { 0 };
                  Vec<1, uint8_t> id_1351 {  id_1350  };
                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1352;
                  {
                    Vec<1, uint8_t> shft_ref_160 { id_1351 };
                    Vec<1, Pointer> id_1353 {  drec_snd_158  };
                    ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1354;
                    {
                      Vec<1, Pointer> p_ref_161 { id_1353 };
                      bool while_flag_1355 { true };
                      do {
                        uint8_t id_1356 { 0 };
                        Pointer id_1357 { p_ref_161[id_1356] };
                        ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1358 { id_1357.readU8() };
                        bool let_res_1359;
                        {
                          ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_162 { id_1358 };
                          bool letpair_res_1360;
                          {
                            auto leb128_fst_163 { std::get<0>(leb128_162) };
                            auto leb128_snd_164 { std::get<1>(leb128_162) };
                            uint8_t id_1361 { 0 };
                            Void id_1362 { ((void)(p_ref_161[id_1361] = leb128_snd_164), ::dessser::Void()) };
                            (void)id_1362;
                            uint8_t id_1363 { 0 };
                            uint8_t id_1364 { 127 };
                            uint8_t id_1365 { uint8_t(leb128_fst_163 & id_1364) };
                            uint32_t id_1366 { uint32_t(id_1365) };
                            uint8_t id_1367 { 0 };
                            uint8_t id_1368 { shft_ref_160[id_1367] };
                            uint32_t id_1369 { uint32_t(id_1366 << id_1368) };
                            uint8_t id_1370 { 0 };
                            uint32_t id_1371 { leb_ref_159[id_1370] };
                            uint32_t id_1372 { uint32_t(id_1369 | id_1371) };
                            Void id_1373 { ((void)(leb_ref_159[id_1363] = id_1372), ::dessser::Void()) };
                            (void)id_1373;
                            uint8_t id_1374 { 0 };
                            uint8_t id_1375 { 0 };
                            uint8_t id_1376 { shft_ref_160[id_1375] };
                            uint8_t id_1377 { 7 };
                            uint8_t id_1378 { uint8_t(id_1376 + id_1377) };
                            Void id_1379 { ((void)(shft_ref_160[id_1374] = id_1378), ::dessser::Void()) };
                            (void)id_1379;
                            uint8_t id_1380 { 128 };
                            bool id_1381 { bool(leb128_fst_163 >= id_1380) };
                            letpair_res_1360 = id_1381;
                          }
                          let_res_1359 = letpair_res_1360;
                        }
                        while_flag_1355 = let_res_1359;
                        if (while_flag_1355) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_1355);
                      (void)::dessser::Void();
                      uint8_t id_1382 { 0 };
                      uint32_t id_1383 { leb_ref_159[id_1382] };
                      uint8_t id_1384 { 0 };
                      Pointer id_1385 { p_ref_161[id_1384] };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1386 { id_1383, id_1385 };
                      let_res_1354 = id_1386;
                    }
                    let_res_1352 = let_res_1354;
                  }
                  let_res_1349 = let_res_1352;
                }
                ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1387;
                {
                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_168 { let_res_1349 };
                  ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1388;
                  {
                    auto dlist1_fst_169 { std::get<0>(dlist1_168) };
                    auto dlist1_snd_170 { std::get<1>(dlist1_168) };
                    Lst<dessser::gen::simple_filter::t_ext> endoflist_1389;
                    ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1390 { endoflist_1389, dlist1_snd_170 };
                    Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> id_1391 {  id_1390  };
                    ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1392;
                    {
                      Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> inits_src_ref_171 { id_1391 };
                      int32_t id_1393 { 0L };
                      Vec<1, int32_t> id_1394 {  id_1393  };
                      {
                        Vec<1, int32_t> repeat_n_172 { id_1394 };
                        bool while_flag_1395 { true };
                        do {
                          int32_t id_1396 { int32_t(dlist1_fst_169) };
                          uint8_t id_1397 { 0 };
                          int32_t id_1398 { repeat_n_172[id_1397] };
                          bool id_1399 { bool(id_1396 > id_1398) };
                          while_flag_1395 = id_1399;
                          if (while_flag_1395) {
                            uint8_t id_1400 { 0 };
                            ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1401 { inits_src_ref_171[id_1400] };
                            {
                              ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d dlist2_173 { id_1401 };
                              {
                                auto dlist2_fst_174 { std::get<0>(dlist2_173) };
                                auto dlist2_snd_175 { std::get<1>(dlist2_173) };
                                uint8_t id_1402 { 0 };
                                auto fun1403 { dessser::gen::simple_filter::of_row_binary };
                                ::dessser::gen::alert::t718468920e01b4b984449c743ae99792 id_1404 { fun1403(dlist2_snd_175) };
                                ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1405;
                                {
                                  auto dlist3_fst_177 { std::get<0>(id_1404) };
                                  auto dlist3_snd_178 { std::get<1>(id_1404) };
                                  Lst<dessser::gen::simple_filter::t_ext> id_1406 { dlist3_fst_177, dlist2_fst_174 };
                                  ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1407 { id_1406, dlist3_snd_178 };
                                  letpair_res_1405 = id_1407;
                                }
                                Void id_1408 { ((void)(inits_src_ref_171[id_1402] = letpair_res_1405), ::dessser::Void()) };
                                (void)id_1408;
                              }
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_1409 { 0 };
                            uint8_t id_1410 { 0 };
                            int32_t id_1411 { repeat_n_172[id_1410] };
                            int32_t id_1412 { 1L };
                            int32_t id_1413 { int32_t(id_1411 + id_1412) };
                            Void id_1414 { ((void)(repeat_n_172[id_1409] = id_1413), ::dessser::Void()) };
                            (void)id_1414;
                            (void)id_1414;
                          }
                        } while (while_flag_1395);
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_1415 { 0 };
                      ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1416 { inits_src_ref_171[id_1415] };
                      let_res_1392 = id_1416;
                    }
                    letpair_res_1388 = let_res_1392;
                  }
                  let_res_1387 = letpair_res_1388;
                }
                ::dessser::gen::alert::td403d13122fd20ecb97f01e7b85a9dea letpair_res_1417;
                {
                  auto dlist4_fst_180 { std::get<0>(let_res_1387) };
                  auto dlist4_snd_181 { std::get<1>(let_res_1387) };
                  Arr<dessser::gen::simple_filter::t_ext> id_1418 { dlist4_fst_180.toListRev() };
                  ::dessser::gen::alert::td403d13122fd20ecb97f01e7b85a9dea id_1419 { id_1418, dlist4_snd_181 };
                  letpair_res_1417 = id_1419;
                }
                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1420;
                {
                  ::dessser::gen::alert::td403d13122fd20ecb97f01e7b85a9dea drec_182 { letpair_res_1417 };
                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1421;
                  {
                    auto drec_fst_183 { std::get<0>(drec_182) };
                    auto drec_snd_184 { std::get<1>(drec_182) };
                    Size id_1422 { 0UL };
                    uint8_t id_1423 { drec_snd_184.peekU8(id_1422) };
                    uint8_t id_1424 { 1 };
                    bool id_1425 { bool(id_1423 == id_1424) };
                    ::dessser::gen::alert::t0792b3e797566a05cd2e25d5f448d59b choose_res_1426;
                    if (id_1425) {
                      std::optional<Arr<dessser::gen::field_name::t_ext>> id_1427 { std::nullopt };
                      Size id_1428 { 1UL };
                      Pointer id_1429 { drec_snd_184.skip(id_1428) };
                      ::dessser::gen::alert::t0792b3e797566a05cd2e25d5f448d59b id_1430 { id_1427, id_1429 };
                      choose_res_1426 = id_1430;
                    } else {
                      uint32_t id_1431 { 0U };
                      Vec<1, uint32_t> id_1432 {  id_1431  };
                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1433;
                      {
                        Vec<1, uint32_t> leb_ref_185 { id_1432 };
                        uint8_t id_1434 { 0 };
                        Vec<1, uint8_t> id_1435 {  id_1434  };
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1436;
                        {
                          Vec<1, uint8_t> shft_ref_186 { id_1435 };
                          Size id_1437 { 1UL };
                          Pointer id_1438 { drec_snd_184.skip(id_1437) };
                          Vec<1, Pointer> id_1439 {  id_1438  };
                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1440;
                          {
                            Vec<1, Pointer> p_ref_187 { id_1439 };
                            bool while_flag_1441 { true };
                            do {
                              uint8_t id_1442 { 0 };
                              Pointer id_1443 { p_ref_187[id_1442] };
                              ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1444 { id_1443.readU8() };
                              bool let_res_1445;
                              {
                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_188 { id_1444 };
                                bool letpair_res_1446;
                                {
                                  auto leb128_fst_189 { std::get<0>(leb128_188) };
                                  auto leb128_snd_190 { std::get<1>(leb128_188) };
                                  uint8_t id_1447 { 0 };
                                  Void id_1448 { ((void)(p_ref_187[id_1447] = leb128_snd_190), ::dessser::Void()) };
                                  (void)id_1448;
                                  uint8_t id_1449 { 0 };
                                  uint8_t id_1450 { 127 };
                                  uint8_t id_1451 { uint8_t(leb128_fst_189 & id_1450) };
                                  uint32_t id_1452 { uint32_t(id_1451) };
                                  uint8_t id_1453 { 0 };
                                  uint8_t id_1454 { shft_ref_186[id_1453] };
                                  uint32_t id_1455 { uint32_t(id_1452 << id_1454) };
                                  uint8_t id_1456 { 0 };
                                  uint32_t id_1457 { leb_ref_185[id_1456] };
                                  uint32_t id_1458 { uint32_t(id_1455 | id_1457) };
                                  Void id_1459 { ((void)(leb_ref_185[id_1449] = id_1458), ::dessser::Void()) };
                                  (void)id_1459;
                                  uint8_t id_1460 { 0 };
                                  uint8_t id_1461 { 0 };
                                  uint8_t id_1462 { shft_ref_186[id_1461] };
                                  uint8_t id_1463 { 7 };
                                  uint8_t id_1464 { uint8_t(id_1462 + id_1463) };
                                  Void id_1465 { ((void)(shft_ref_186[id_1460] = id_1464), ::dessser::Void()) };
                                  (void)id_1465;
                                  uint8_t id_1466 { 128 };
                                  bool id_1467 { bool(leb128_fst_189 >= id_1466) };
                                  letpair_res_1446 = id_1467;
                                }
                                let_res_1445 = letpair_res_1446;
                              }
                              while_flag_1441 = let_res_1445;
                              if (while_flag_1441) {
                                (void)::dessser::Void();
                              }
                            } while (while_flag_1441);
                            (void)::dessser::Void();
                            uint8_t id_1468 { 0 };
                            uint32_t id_1469 { leb_ref_185[id_1468] };
                            uint8_t id_1470 { 0 };
                            Pointer id_1471 { p_ref_187[id_1470] };
                            ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1472 { id_1469, id_1471 };
                            let_res_1440 = id_1472;
                          }
                          let_res_1436 = let_res_1440;
                        }
                        let_res_1433 = let_res_1436;
                      }
                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1473;
                      {
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_194 { let_res_1433 };
                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1474;
                        {
                          auto dlist1_fst_195 { std::get<0>(dlist1_194) };
                          auto dlist1_snd_196 { std::get<1>(dlist1_194) };
                          Lst<dessser::gen::field_name::t_ext> endoflist_1475;
                          ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1476 { endoflist_1475, dlist1_snd_196 };
                          Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1477 {  id_1476  };
                          ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1478;
                          {
                            Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_197 { id_1477 };
                            int32_t id_1479 { 0L };
                            Vec<1, int32_t> id_1480 {  id_1479  };
                            {
                              Vec<1, int32_t> repeat_n_198 { id_1480 };
                              bool while_flag_1481 { true };
                              do {
                                int32_t id_1482 { int32_t(dlist1_fst_195) };
                                uint8_t id_1483 { 0 };
                                int32_t id_1484 { repeat_n_198[id_1483] };
                                bool id_1485 { bool(id_1482 > id_1484) };
                                while_flag_1481 = id_1485;
                                if (while_flag_1481) {
                                  uint8_t id_1486 { 0 };
                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1487 { inits_src_ref_197[id_1486] };
                                  {
                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_199 { id_1487 };
                                    {
                                      auto dlist2_fst_200 { std::get<0>(dlist2_199) };
                                      auto dlist2_snd_201 { std::get<1>(dlist2_199) };
                                      uint8_t id_1488 { 0 };
                                      auto fun1489 { dessser::gen::field_name::of_row_binary };
                                      ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1490 { fun1489(dlist2_snd_201) };
                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1491;
                                      {
                                        auto dlist3_fst_203 { std::get<0>(id_1490) };
                                        auto dlist3_snd_204 { std::get<1>(id_1490) };
                                        Lst<dessser::gen::field_name::t_ext> id_1492 { dlist3_fst_203, dlist2_fst_200 };
                                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1493 { id_1492, dlist3_snd_204 };
                                        letpair_res_1491 = id_1493;
                                      }
                                      Void id_1494 { ((void)(inits_src_ref_197[id_1488] = letpair_res_1491), ::dessser::Void()) };
                                      (void)id_1494;
                                    }
                                    (void)::dessser::Void();
                                  }
                                  (void)::dessser::Void();
                                  uint8_t id_1495 { 0 };
                                  uint8_t id_1496 { 0 };
                                  int32_t id_1497 { repeat_n_198[id_1496] };
                                  int32_t id_1498 { 1L };
                                  int32_t id_1499 { int32_t(id_1497 + id_1498) };
                                  Void id_1500 { ((void)(repeat_n_198[id_1495] = id_1499), ::dessser::Void()) };
                                  (void)id_1500;
                                  (void)id_1500;
                                }
                              } while (while_flag_1481);
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_1501 { 0 };
                            ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1502 { inits_src_ref_197[id_1501] };
                            let_res_1478 = id_1502;
                          }
                          letpair_res_1474 = let_res_1478;
                        }
                        let_res_1473 = letpair_res_1474;
                      }
                      ::dessser::gen::alert::t0792b3e797566a05cd2e25d5f448d59b letpair_res_1503;
                      {
                        auto dlist4_fst_206 { std::get<0>(let_res_1473) };
                        auto dlist4_snd_207 { std::get<1>(let_res_1473) };
                        Arr<dessser::gen::field_name::t_ext> id_1504 { dlist4_fst_206.toListRev() };
                        std::optional<Arr<dessser::gen::field_name::t_ext>> id_1505 { id_1504 };
                        ::dessser::gen::alert::t0792b3e797566a05cd2e25d5f448d59b id_1506 { id_1505, dlist4_snd_207 };
                        letpair_res_1503 = id_1506;
                      }
                      choose_res_1426 = letpair_res_1503;
                    }
                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1507;
                    {
                      ::dessser::gen::alert::t0792b3e797566a05cd2e25d5f448d59b drec_211 { choose_res_1426 };
                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1508;
                      {
                        auto drec_fst_212 { std::get<0>(drec_211) };
                        auto drec_snd_213 { std::get<1>(drec_211) };
                        uint32_t id_1509 { 0U };
                        Vec<1, uint32_t> id_1510 {  id_1509  };
                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1511;
                        {
                          Vec<1, uint32_t> leb_ref_214 { id_1510 };
                          uint8_t id_1512 { 0 };
                          Vec<1, uint8_t> id_1513 {  id_1512  };
                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1514;
                          {
                            Vec<1, uint8_t> shft_ref_215 { id_1513 };
                            Vec<1, Pointer> id_1515 {  drec_snd_213  };
                            ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1516;
                            {
                              Vec<1, Pointer> p_ref_216 { id_1515 };
                              bool while_flag_1517 { true };
                              do {
                                uint8_t id_1518 { 0 };
                                Pointer id_1519 { p_ref_216[id_1518] };
                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1520 { id_1519.readU8() };
                                bool let_res_1521;
                                {
                                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_217 { id_1520 };
                                  bool letpair_res_1522;
                                  {
                                    auto leb128_fst_218 { std::get<0>(leb128_217) };
                                    auto leb128_snd_219 { std::get<1>(leb128_217) };
                                    uint8_t id_1523 { 0 };
                                    Void id_1524 { ((void)(p_ref_216[id_1523] = leb128_snd_219), ::dessser::Void()) };
                                    (void)id_1524;
                                    uint8_t id_1525 { 0 };
                                    uint8_t id_1526 { 127 };
                                    uint8_t id_1527 { uint8_t(leb128_fst_218 & id_1526) };
                                    uint32_t id_1528 { uint32_t(id_1527) };
                                    uint8_t id_1529 { 0 };
                                    uint8_t id_1530 { shft_ref_215[id_1529] };
                                    uint32_t id_1531 { uint32_t(id_1528 << id_1530) };
                                    uint8_t id_1532 { 0 };
                                    uint32_t id_1533 { leb_ref_214[id_1532] };
                                    uint32_t id_1534 { uint32_t(id_1531 | id_1533) };
                                    Void id_1535 { ((void)(leb_ref_214[id_1525] = id_1534), ::dessser::Void()) };
                                    (void)id_1535;
                                    uint8_t id_1536 { 0 };
                                    uint8_t id_1537 { 0 };
                                    uint8_t id_1538 { shft_ref_215[id_1537] };
                                    uint8_t id_1539 { 7 };
                                    uint8_t id_1540 { uint8_t(id_1538 + id_1539) };
                                    Void id_1541 { ((void)(shft_ref_215[id_1536] = id_1540), ::dessser::Void()) };
                                    (void)id_1541;
                                    uint8_t id_1542 { 128 };
                                    bool id_1543 { bool(leb128_fst_218 >= id_1542) };
                                    letpair_res_1522 = id_1543;
                                  }
                                  let_res_1521 = letpair_res_1522;
                                }
                                while_flag_1517 = let_res_1521;
                                if (while_flag_1517) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_1517);
                              (void)::dessser::Void();
                              uint8_t id_1544 { 0 };
                              uint32_t id_1545 { leb_ref_214[id_1544] };
                              uint8_t id_1546 { 0 };
                              Pointer id_1547 { p_ref_216[id_1546] };
                              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1548 { id_1545, id_1547 };
                              let_res_1516 = id_1548;
                            }
                            let_res_1514 = let_res_1516;
                          }
                          let_res_1511 = let_res_1514;
                        }
                        ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1549;
                        {
                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_223 { let_res_1511 };
                          ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1550;
                          {
                            auto dlist1_fst_224 { std::get<0>(dlist1_223) };
                            auto dlist1_snd_225 { std::get<1>(dlist1_223) };
                            Lst<dessser::gen::simple_filter::t_ext> endoflist_1551;
                            ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1552 { endoflist_1551, dlist1_snd_225 };
                            Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> id_1553 {  id_1552  };
                            ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d let_res_1554;
                            {
                              Vec<1, ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d> inits_src_ref_226 { id_1553 };
                              int32_t id_1555 { 0L };
                              Vec<1, int32_t> id_1556 {  id_1555  };
                              {
                                Vec<1, int32_t> repeat_n_227 { id_1556 };
                                bool while_flag_1557 { true };
                                do {
                                  int32_t id_1558 { int32_t(dlist1_fst_224) };
                                  uint8_t id_1559 { 0 };
                                  int32_t id_1560 { repeat_n_227[id_1559] };
                                  bool id_1561 { bool(id_1558 > id_1560) };
                                  while_flag_1557 = id_1561;
                                  if (while_flag_1557) {
                                    uint8_t id_1562 { 0 };
                                    ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1563 { inits_src_ref_226[id_1562] };
                                    {
                                      ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d dlist2_228 { id_1563 };
                                      {
                                        auto dlist2_fst_229 { std::get<0>(dlist2_228) };
                                        auto dlist2_snd_230 { std::get<1>(dlist2_228) };
                                        uint8_t id_1564 { 0 };
                                        auto fun1565 { dessser::gen::simple_filter::of_row_binary };
                                        ::dessser::gen::alert::t718468920e01b4b984449c743ae99792 id_1566 { fun1565(dlist2_snd_230) };
                                        ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_1567;
                                        {
                                          auto dlist3_fst_232 { std::get<0>(id_1566) };
                                          auto dlist3_snd_233 { std::get<1>(id_1566) };
                                          Lst<dessser::gen::simple_filter::t_ext> id_1568 { dlist3_fst_232, dlist2_fst_229 };
                                          ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1569 { id_1568, dlist3_snd_233 };
                                          letpair_res_1567 = id_1569;
                                        }
                                        Void id_1570 { ((void)(inits_src_ref_226[id_1564] = letpair_res_1567), ::dessser::Void()) };
                                        (void)id_1570;
                                      }
                                      (void)::dessser::Void();
                                    }
                                    (void)::dessser::Void();
                                    uint8_t id_1571 { 0 };
                                    uint8_t id_1572 { 0 };
                                    int32_t id_1573 { repeat_n_227[id_1572] };
                                    int32_t id_1574 { 1L };
                                    int32_t id_1575 { int32_t(id_1573 + id_1574) };
                                    Void id_1576 { ((void)(repeat_n_227[id_1571] = id_1575), ::dessser::Void()) };
                                    (void)id_1576;
                                    (void)id_1576;
                                  }
                                } while (while_flag_1557);
                                (void)::dessser::Void();
                              }
                              (void)::dessser::Void();
                              uint8_t id_1577 { 0 };
                              ::dessser::gen::alert::tc42fa697e1caa84eb8919e899ae45a1d id_1578 { inits_src_ref_226[id_1577] };
                              let_res_1554 = id_1578;
                            }
                            letpair_res_1550 = let_res_1554;
                          }
                          let_res_1549 = letpair_res_1550;
                        }
                        ::dessser::gen::alert::td403d13122fd20ecb97f01e7b85a9dea letpair_res_1579;
                        {
                          auto dlist4_fst_235 { std::get<0>(let_res_1549) };
                          auto dlist4_snd_236 { std::get<1>(let_res_1549) };
                          Arr<dessser::gen::simple_filter::t_ext> id_1580 { dlist4_fst_235.toListRev() };
                          ::dessser::gen::alert::td403d13122fd20ecb97f01e7b85a9dea id_1581 { id_1580, dlist4_snd_236 };
                          letpair_res_1579 = id_1581;
                        }
                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1582;
                        {
                          ::dessser::gen::alert::td403d13122fd20ecb97f01e7b85a9dea drec_237 { letpair_res_1579 };
                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1583;
                          {
                            auto drec_fst_238 { std::get<0>(drec_237) };
                            auto drec_snd_239 { std::get<1>(drec_237) };
                            ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 id_1584 { threshold_of_row_binary(drec_snd_239) };
                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1585;
                            {
                              ::dessser::gen::alert::t55387dac503088b8cd86859bdfba5c91 drec_240 { id_1584 };
                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1586;
                              {
                                auto drec_fst_241 { std::get<0>(drec_240) };
                                auto drec_snd_242 { std::get<1>(drec_240) };
                                ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1587 { drec_snd_242.readU64Le() };
                                ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1588;
                                {
                                  auto dfloat_fst_244 { std::get<0>(id_1587) };
                                  auto dfloat_snd_245 { std::get<1>(id_1587) };
                                  double id_1589 { float_of_qword(dfloat_fst_244) };
                                  ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1590 { id_1589, dfloat_snd_245 };
                                  letpair_res_1588 = id_1590;
                                }
                                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1591;
                                {
                                  ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_246 { letpair_res_1588 };
                                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1592;
                                  {
                                    auto drec_fst_247 { std::get<0>(drec_246) };
                                    auto drec_snd_248 { std::get<1>(drec_246) };
                                    ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1593 { drec_snd_248.readU64Le() };
                                    ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1594;
                                    {
                                      auto dfloat_fst_250 { std::get<0>(id_1593) };
                                      auto dfloat_snd_251 { std::get<1>(id_1593) };
                                      double id_1595 { float_of_qword(dfloat_fst_250) };
                                      ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1596 { id_1595, dfloat_snd_251 };
                                      letpair_res_1594 = id_1596;
                                    }
                                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1597;
                                    {
                                      ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_252 { letpair_res_1594 };
                                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1598;
                                      {
                                        auto drec_fst_253 { std::get<0>(drec_252) };
                                        auto drec_snd_254 { std::get<1>(drec_252) };
                                        ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1599 { drec_snd_254.readU64Le() };
                                        ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1600;
                                        {
                                          auto dfloat_fst_256 { std::get<0>(id_1599) };
                                          auto dfloat_snd_257 { std::get<1>(id_1599) };
                                          double id_1601 { float_of_qword(dfloat_fst_256) };
                                          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1602 { id_1601, dfloat_snd_257 };
                                          letpair_res_1600 = id_1602;
                                        }
                                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1603;
                                        {
                                          ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_258 { letpair_res_1600 };
                                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1604;
                                          {
                                            auto drec_fst_259 { std::get<0>(drec_258) };
                                            auto drec_snd_260 { std::get<1>(drec_258) };
                                            ::dessser::gen::alert::td2cd337bb3c8bc04d5603393d084985b id_1605 { drec_snd_260.readU64Le() };
                                            ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 letpair_res_1606;
                                            {
                                              auto dfloat_fst_262 { std::get<0>(id_1605) };
                                              auto dfloat_snd_263 { std::get<1>(id_1605) };
                                              double id_1607 { float_of_qword(dfloat_fst_262) };
                                              ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 id_1608 { id_1607, dfloat_snd_263 };
                                              letpair_res_1606 = id_1608;
                                            }
                                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1609;
                                            {
                                              ::dessser::gen::alert::t9a758baeff17224a77e1a522010b4168 drec_264 { letpair_res_1606 };
                                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1610;
                                              {
                                                auto drec_fst_265 { std::get<0>(drec_264) };
                                                auto drec_snd_266 { std::get<1>(drec_264) };
                                                uint32_t id_1611 { 0U };
                                                Vec<1, uint32_t> id_1612 {  id_1611  };
                                                ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1613;
                                                {
                                                  Vec<1, uint32_t> leb_ref_267 { id_1612 };
                                                  uint8_t id_1614 { 0 };
                                                  Vec<1, uint8_t> id_1615 {  id_1614  };
                                                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1616;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_268 { id_1615 };
                                                    Vec<1, Pointer> id_1617 {  drec_snd_266  };
                                                    ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1618;
                                                    {
                                                      Vec<1, Pointer> p_ref_269 { id_1617 };
                                                      bool while_flag_1619 { true };
                                                      do {
                                                        uint8_t id_1620 { 0 };
                                                        Pointer id_1621 { p_ref_269[id_1620] };
                                                        ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1622 { id_1621.readU8() };
                                                        bool let_res_1623;
                                                        {
                                                          ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_270 { id_1622 };
                                                          bool letpair_res_1624;
                                                          {
                                                            auto leb128_fst_271 { std::get<0>(leb128_270) };
                                                            auto leb128_snd_272 { std::get<1>(leb128_270) };
                                                            uint8_t id_1625 { 0 };
                                                            Void id_1626 { ((void)(p_ref_269[id_1625] = leb128_snd_272), ::dessser::Void()) };
                                                            (void)id_1626;
                                                            uint8_t id_1627 { 0 };
                                                            uint8_t id_1628 { 127 };
                                                            uint8_t id_1629 { uint8_t(leb128_fst_271 & id_1628) };
                                                            uint32_t id_1630 { uint32_t(id_1629) };
                                                            uint8_t id_1631 { 0 };
                                                            uint8_t id_1632 { shft_ref_268[id_1631] };
                                                            uint32_t id_1633 { uint32_t(id_1630 << id_1632) };
                                                            uint8_t id_1634 { 0 };
                                                            uint32_t id_1635 { leb_ref_267[id_1634] };
                                                            uint32_t id_1636 { uint32_t(id_1633 | id_1635) };
                                                            Void id_1637 { ((void)(leb_ref_267[id_1627] = id_1636), ::dessser::Void()) };
                                                            (void)id_1637;
                                                            uint8_t id_1638 { 0 };
                                                            uint8_t id_1639 { 0 };
                                                            uint8_t id_1640 { shft_ref_268[id_1639] };
                                                            uint8_t id_1641 { 7 };
                                                            uint8_t id_1642 { uint8_t(id_1640 + id_1641) };
                                                            Void id_1643 { ((void)(shft_ref_268[id_1638] = id_1642), ::dessser::Void()) };
                                                            (void)id_1643;
                                                            uint8_t id_1644 { 128 };
                                                            bool id_1645 { bool(leb128_fst_271 >= id_1644) };
                                                            letpair_res_1624 = id_1645;
                                                          }
                                                          let_res_1623 = letpair_res_1624;
                                                        }
                                                        while_flag_1619 = let_res_1623;
                                                        if (while_flag_1619) {
                                                          (void)::dessser::Void();
                                                        }
                                                      } while (while_flag_1619);
                                                      (void)::dessser::Void();
                                                      uint8_t id_1646 { 0 };
                                                      uint32_t id_1647 { leb_ref_267[id_1646] };
                                                      uint8_t id_1648 { 0 };
                                                      Pointer id_1649 { p_ref_269[id_1648] };
                                                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1650 { id_1647, id_1649 };
                                                      let_res_1618 = id_1650;
                                                    }
                                                    let_res_1616 = let_res_1618;
                                                  }
                                                  let_res_1613 = let_res_1616;
                                                }
                                                ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1651;
                                                {
                                                  ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_276 { let_res_1613 };
                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1652;
                                                  {
                                                    auto dlist1_fst_277 { std::get<0>(dlist1_276) };
                                                    auto dlist1_snd_278 { std::get<1>(dlist1_276) };
                                                    Lst<dessser::gen::field_name::t_ext> endoflist_1653;
                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1654 { endoflist_1653, dlist1_snd_278 };
                                                    Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1655 {  id_1654  };
                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1656;
                                                    {
                                                      Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_279 { id_1655 };
                                                      int32_t id_1657 { 0L };
                                                      Vec<1, int32_t> id_1658 {  id_1657  };
                                                      {
                                                        Vec<1, int32_t> repeat_n_280 { id_1658 };
                                                        bool while_flag_1659 { true };
                                                        do {
                                                          int32_t id_1660 { int32_t(dlist1_fst_277) };
                                                          uint8_t id_1661 { 0 };
                                                          int32_t id_1662 { repeat_n_280[id_1661] };
                                                          bool id_1663 { bool(id_1660 > id_1662) };
                                                          while_flag_1659 = id_1663;
                                                          if (while_flag_1659) {
                                                            uint8_t id_1664 { 0 };
                                                            ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1665 { inits_src_ref_279[id_1664] };
                                                            {
                                                              ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_281 { id_1665 };
                                                              {
                                                                auto dlist2_fst_282 { std::get<0>(dlist2_281) };
                                                                auto dlist2_snd_283 { std::get<1>(dlist2_281) };
                                                                uint8_t id_1666 { 0 };
                                                                auto fun1667 { dessser::gen::field_name::of_row_binary };
                                                                ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1668 { fun1667(dlist2_snd_283) };
                                                                ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1669;
                                                                {
                                                                  auto dlist3_fst_285 { std::get<0>(id_1668) };
                                                                  auto dlist3_snd_286 { std::get<1>(id_1668) };
                                                                  Lst<dessser::gen::field_name::t_ext> id_1670 { dlist3_fst_285, dlist2_fst_282 };
                                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1671 { id_1670, dlist3_snd_286 };
                                                                  letpair_res_1669 = id_1671;
                                                                }
                                                                Void id_1672 { ((void)(inits_src_ref_279[id_1666] = letpair_res_1669), ::dessser::Void()) };
                                                                (void)id_1672;
                                                              }
                                                              (void)::dessser::Void();
                                                            }
                                                            (void)::dessser::Void();
                                                            uint8_t id_1673 { 0 };
                                                            uint8_t id_1674 { 0 };
                                                            int32_t id_1675 { repeat_n_280[id_1674] };
                                                            int32_t id_1676 { 1L };
                                                            int32_t id_1677 { int32_t(id_1675 + id_1676) };
                                                            Void id_1678 { ((void)(repeat_n_280[id_1673] = id_1677), ::dessser::Void()) };
                                                            (void)id_1678;
                                                            (void)id_1678;
                                                          }
                                                        } while (while_flag_1659);
                                                        (void)::dessser::Void();
                                                      }
                                                      (void)::dessser::Void();
                                                      uint8_t id_1679 { 0 };
                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1680 { inits_src_ref_279[id_1679] };
                                                      let_res_1656 = id_1680;
                                                    }
                                                    letpair_res_1652 = let_res_1656;
                                                  }
                                                  let_res_1651 = letpair_res_1652;
                                                }
                                                ::dessser::gen::alert::t5f8c7f0089c13d8e90b66cd6d8db085d letpair_res_1681;
                                                {
                                                  auto dlist4_fst_288 { std::get<0>(let_res_1651) };
                                                  auto dlist4_snd_289 { std::get<1>(let_res_1651) };
                                                  Arr<dessser::gen::field_name::t_ext> id_1682 { dlist4_fst_288.toListRev() };
                                                  ::dessser::gen::alert::t5f8c7f0089c13d8e90b66cd6d8db085d id_1683 { id_1682, dlist4_snd_289 };
                                                  letpair_res_1681 = id_1683;
                                                }
                                                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1684;
                                                {
                                                  ::dessser::gen::alert::t5f8c7f0089c13d8e90b66cd6d8db085d drec_290 { letpair_res_1681 };
                                                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1685;
                                                  {
                                                    auto drec_fst_291 { std::get<0>(drec_290) };
                                                    auto drec_snd_292 { std::get<1>(drec_290) };
                                                    uint32_t id_1686 { 0U };
                                                    Vec<1, uint32_t> id_1687 {  id_1686  };
                                                    ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1688;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_293 { id_1687 };
                                                      uint8_t id_1689 { 0 };
                                                      Vec<1, uint8_t> id_1690 {  id_1689  };
                                                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1691;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_294 { id_1690 };
                                                        Vec<1, Pointer> id_1692 {  drec_snd_292  };
                                                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1693;
                                                        {
                                                          Vec<1, Pointer> p_ref_295 { id_1692 };
                                                          bool while_flag_1694 { true };
                                                          do {
                                                            uint8_t id_1695 { 0 };
                                                            Pointer id_1696 { p_ref_295[id_1695] };
                                                            ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1697 { id_1696.readU8() };
                                                            bool let_res_1698;
                                                            {
                                                              ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_296 { id_1697 };
                                                              bool letpair_res_1699;
                                                              {
                                                                auto leb128_fst_297 { std::get<0>(leb128_296) };
                                                                auto leb128_snd_298 { std::get<1>(leb128_296) };
                                                                uint8_t id_1700 { 0 };
                                                                Void id_1701 { ((void)(p_ref_295[id_1700] = leb128_snd_298), ::dessser::Void()) };
                                                                (void)id_1701;
                                                                uint8_t id_1702 { 0 };
                                                                uint8_t id_1703 { 127 };
                                                                uint8_t id_1704 { uint8_t(leb128_fst_297 & id_1703) };
                                                                uint32_t id_1705 { uint32_t(id_1704) };
                                                                uint8_t id_1706 { 0 };
                                                                uint8_t id_1707 { shft_ref_294[id_1706] };
                                                                uint32_t id_1708 { uint32_t(id_1705 << id_1707) };
                                                                uint8_t id_1709 { 0 };
                                                                uint32_t id_1710 { leb_ref_293[id_1709] };
                                                                uint32_t id_1711 { uint32_t(id_1708 | id_1710) };
                                                                Void id_1712 { ((void)(leb_ref_293[id_1702] = id_1711), ::dessser::Void()) };
                                                                (void)id_1712;
                                                                uint8_t id_1713 { 0 };
                                                                uint8_t id_1714 { 0 };
                                                                uint8_t id_1715 { shft_ref_294[id_1714] };
                                                                uint8_t id_1716 { 7 };
                                                                uint8_t id_1717 { uint8_t(id_1715 + id_1716) };
                                                                Void id_1718 { ((void)(shft_ref_294[id_1713] = id_1717), ::dessser::Void()) };
                                                                (void)id_1718;
                                                                uint8_t id_1719 { 128 };
                                                                bool id_1720 { bool(leb128_fst_297 >= id_1719) };
                                                                letpair_res_1699 = id_1720;
                                                              }
                                                              let_res_1698 = letpair_res_1699;
                                                            }
                                                            while_flag_1694 = let_res_1698;
                                                            if (while_flag_1694) {
                                                              (void)::dessser::Void();
                                                            }
                                                          } while (while_flag_1694);
                                                          (void)::dessser::Void();
                                                          uint8_t id_1721 { 0 };
                                                          uint32_t id_1722 { leb_ref_293[id_1721] };
                                                          uint8_t id_1723 { 0 };
                                                          Pointer id_1724 { p_ref_295[id_1723] };
                                                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1725 { id_1722, id_1724 };
                                                          let_res_1693 = id_1725;
                                                        }
                                                        let_res_1691 = let_res_1693;
                                                      }
                                                      let_res_1688 = let_res_1691;
                                                    }
                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1726;
                                                    {
                                                      ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_302 { let_res_1688 };
                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1727;
                                                      {
                                                        auto dlist1_fst_303 { std::get<0>(dlist1_302) };
                                                        auto dlist1_snd_304 { std::get<1>(dlist1_302) };
                                                        Lst<dessser::gen::field_name::t_ext> endoflist_1728;
                                                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1729 { endoflist_1728, dlist1_snd_304 };
                                                        Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1730 {  id_1729  };
                                                        ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1731;
                                                        {
                                                          Vec<1, ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_305 { id_1730 };
                                                          int32_t id_1732 { 0L };
                                                          Vec<1, int32_t> id_1733 {  id_1732  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_306 { id_1733 };
                                                            bool while_flag_1734 { true };
                                                            do {
                                                              int32_t id_1735 { int32_t(dlist1_fst_303) };
                                                              uint8_t id_1736 { 0 };
                                                              int32_t id_1737 { repeat_n_306[id_1736] };
                                                              bool id_1738 { bool(id_1735 > id_1737) };
                                                              while_flag_1734 = id_1738;
                                                              if (while_flag_1734) {
                                                                uint8_t id_1739 { 0 };
                                                                ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1740 { inits_src_ref_305[id_1739] };
                                                                {
                                                                  ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_307 { id_1740 };
                                                                  {
                                                                    auto dlist2_fst_308 { std::get<0>(dlist2_307) };
                                                                    auto dlist2_snd_309 { std::get<1>(dlist2_307) };
                                                                    uint8_t id_1741 { 0 };
                                                                    auto fun1742 { dessser::gen::field_name::of_row_binary };
                                                                    ::dessser::gen::alert::t18cecf882d7ac80cef37dfe6b22279d4 id_1743 { fun1742(dlist2_snd_309) };
                                                                    ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1744;
                                                                    {
                                                                      auto dlist3_fst_311 { std::get<0>(id_1743) };
                                                                      auto dlist3_snd_312 { std::get<1>(id_1743) };
                                                                      Lst<dessser::gen::field_name::t_ext> id_1745 { dlist3_fst_311, dlist2_fst_308 };
                                                                      ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1746 { id_1745, dlist3_snd_312 };
                                                                      letpair_res_1744 = id_1746;
                                                                    }
                                                                    Void id_1747 { ((void)(inits_src_ref_305[id_1741] = letpair_res_1744), ::dessser::Void()) };
                                                                    (void)id_1747;
                                                                  }
                                                                  (void)::dessser::Void();
                                                                }
                                                                (void)::dessser::Void();
                                                                uint8_t id_1748 { 0 };
                                                                uint8_t id_1749 { 0 };
                                                                int32_t id_1750 { repeat_n_306[id_1749] };
                                                                int32_t id_1751 { 1L };
                                                                int32_t id_1752 { int32_t(id_1750 + id_1751) };
                                                                Void id_1753 { ((void)(repeat_n_306[id_1748] = id_1752), ::dessser::Void()) };
                                                                (void)id_1753;
                                                                (void)id_1753;
                                                              }
                                                            } while (while_flag_1734);
                                                            (void)::dessser::Void();
                                                          }
                                                          (void)::dessser::Void();
                                                          uint8_t id_1754 { 0 };
                                                          ::dessser::gen::alert::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1755 { inits_src_ref_305[id_1754] };
                                                          let_res_1731 = id_1755;
                                                        }
                                                        letpair_res_1727 = let_res_1731;
                                                      }
                                                      let_res_1726 = letpair_res_1727;
                                                    }
                                                    ::dessser::gen::alert::t5f8c7f0089c13d8e90b66cd6d8db085d letpair_res_1756;
                                                    {
                                                      auto dlist4_fst_314 { std::get<0>(let_res_1726) };
                                                      auto dlist4_snd_315 { std::get<1>(let_res_1726) };
                                                      Arr<dessser::gen::field_name::t_ext> id_1757 { dlist4_fst_314.toListRev() };
                                                      ::dessser::gen::alert::t5f8c7f0089c13d8e90b66cd6d8db085d id_1758 { id_1757, dlist4_snd_315 };
                                                      letpair_res_1756 = id_1758;
                                                    }
                                                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1759;
                                                    {
                                                      ::dessser::gen::alert::t5f8c7f0089c13d8e90b66cd6d8db085d drec_316 { letpair_res_1756 };
                                                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1760;
                                                      {
                                                        auto drec_fst_317 { std::get<0>(drec_316) };
                                                        auto drec_snd_318 { std::get<1>(drec_316) };
                                                        uint32_t id_1761 { 0U };
                                                        Vec<1, uint32_t> id_1762 {  id_1761  };
                                                        ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1763;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_319 { id_1762 };
                                                          uint8_t id_1764 { 0 };
                                                          Vec<1, uint8_t> id_1765 {  id_1764  };
                                                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1766;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_320 { id_1765 };
                                                            Vec<1, Pointer> id_1767 {  drec_snd_318  };
                                                            ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 let_res_1768;
                                                            {
                                                              Vec<1, Pointer> p_ref_321 { id_1767 };
                                                              bool while_flag_1769 { true };
                                                              do {
                                                                uint8_t id_1770 { 0 };
                                                                Pointer id_1771 { p_ref_321[id_1770] };
                                                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1772 { id_1771.readU8() };
                                                                bool let_res_1773;
                                                                {
                                                                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_322 { id_1772 };
                                                                  bool letpair_res_1774;
                                                                  {
                                                                    auto leb128_fst_323 { std::get<0>(leb128_322) };
                                                                    auto leb128_snd_324 { std::get<1>(leb128_322) };
                                                                    uint8_t id_1775 { 0 };
                                                                    Void id_1776 { ((void)(p_ref_321[id_1775] = leb128_snd_324), ::dessser::Void()) };
                                                                    (void)id_1776;
                                                                    uint8_t id_1777 { 0 };
                                                                    uint8_t id_1778 { 127 };
                                                                    uint8_t id_1779 { uint8_t(leb128_fst_323 & id_1778) };
                                                                    uint32_t id_1780 { uint32_t(id_1779) };
                                                                    uint8_t id_1781 { 0 };
                                                                    uint8_t id_1782 { shft_ref_320[id_1781] };
                                                                    uint32_t id_1783 { uint32_t(id_1780 << id_1782) };
                                                                    uint8_t id_1784 { 0 };
                                                                    uint32_t id_1785 { leb_ref_319[id_1784] };
                                                                    uint32_t id_1786 { uint32_t(id_1783 | id_1785) };
                                                                    Void id_1787 { ((void)(leb_ref_319[id_1777] = id_1786), ::dessser::Void()) };
                                                                    (void)id_1787;
                                                                    uint8_t id_1788 { 0 };
                                                                    uint8_t id_1789 { 0 };
                                                                    uint8_t id_1790 { shft_ref_320[id_1789] };
                                                                    uint8_t id_1791 { 7 };
                                                                    uint8_t id_1792 { uint8_t(id_1790 + id_1791) };
                                                                    Void id_1793 { ((void)(shft_ref_320[id_1788] = id_1792), ::dessser::Void()) };
                                                                    (void)id_1793;
                                                                    uint8_t id_1794 { 128 };
                                                                    bool id_1795 { bool(leb128_fst_323 >= id_1794) };
                                                                    letpair_res_1774 = id_1795;
                                                                  }
                                                                  let_res_1773 = letpair_res_1774;
                                                                }
                                                                while_flag_1769 = let_res_1773;
                                                                if (while_flag_1769) {
                                                                  (void)::dessser::Void();
                                                                }
                                                              } while (while_flag_1769);
                                                              (void)::dessser::Void();
                                                              uint8_t id_1796 { 0 };
                                                              uint32_t id_1797 { leb_ref_319[id_1796] };
                                                              uint8_t id_1798 { 0 };
                                                              Pointer id_1799 { p_ref_321[id_1798] };
                                                              ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 id_1800 { id_1797, id_1799 };
                                                              let_res_1768 = id_1800;
                                                            }
                                                            let_res_1766 = let_res_1768;
                                                          }
                                                          let_res_1763 = let_res_1766;
                                                        }
                                                        ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e let_res_1801;
                                                        {
                                                          ::dessser::gen::alert::t491c44439106a32f896827242e8e76a1 dlist1_328 { let_res_1763 };
                                                          ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e letpair_res_1802;
                                                          {
                                                            auto dlist1_fst_329 { std::get<0>(dlist1_328) };
                                                            auto dlist1_snd_330 { std::get<1>(dlist1_328) };
                                                            Lst<std::shared_ptr<::dessser::gen::alert::constant> > endoflist_1803;
                                                            ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1804 { endoflist_1803, dlist1_snd_330 };
                                                            Vec<1, ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e> id_1805 {  id_1804  };
                                                            ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e let_res_1806;
                                                            {
                                                              Vec<1, ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e> inits_src_ref_331 { id_1805 };
                                                              int32_t id_1807 { 0L };
                                                              Vec<1, int32_t> id_1808 {  id_1807  };
                                                              {
                                                                Vec<1, int32_t> repeat_n_332 { id_1808 };
                                                                bool while_flag_1809 { true };
                                                                do {
                                                                  int32_t id_1810 { int32_t(dlist1_fst_329) };
                                                                  uint8_t id_1811 { 0 };
                                                                  int32_t id_1812 { repeat_n_332[id_1811] };
                                                                  bool id_1813 { bool(id_1810 > id_1812) };
                                                                  while_flag_1809 = id_1813;
                                                                  if (while_flag_1809) {
                                                                    uint8_t id_1814 { 0 };
                                                                    ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1815 { inits_src_ref_331[id_1814] };
                                                                    {
                                                                      ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e dlist2_333 { id_1815 };
                                                                      {
                                                                        auto dlist2_fst_334 { std::get<0>(dlist2_333) };
                                                                        auto dlist2_snd_335 { std::get<1>(dlist2_333) };
                                                                        uint8_t id_1816 { 0 };
                                                                        ::dessser::gen::alert::t0bfcffcbe1f8fa26793acf604a6fe904 id_1817 { constant_of_row_binary(dlist2_snd_335) };
                                                                        ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e letpair_res_1818;
                                                                        {
                                                                          auto dlist3_fst_337 { std::get<0>(id_1817) };
                                                                          auto dlist3_snd_338 { std::get<1>(id_1817) };
                                                                          Lst<std::shared_ptr<::dessser::gen::alert::constant> > id_1819 { dlist3_fst_337, dlist2_fst_334 };
                                                                          ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1820 { id_1819, dlist3_snd_338 };
                                                                          letpair_res_1818 = id_1820;
                                                                        }
                                                                        Void id_1821 { ((void)(inits_src_ref_331[id_1816] = letpair_res_1818), ::dessser::Void()) };
                                                                        (void)id_1821;
                                                                      }
                                                                      (void)::dessser::Void();
                                                                    }
                                                                    (void)::dessser::Void();
                                                                    uint8_t id_1822 { 0 };
                                                                    uint8_t id_1823 { 0 };
                                                                    int32_t id_1824 { repeat_n_332[id_1823] };
                                                                    int32_t id_1825 { 1L };
                                                                    int32_t id_1826 { int32_t(id_1824 + id_1825) };
                                                                    Void id_1827 { ((void)(repeat_n_332[id_1822] = id_1826), ::dessser::Void()) };
                                                                    (void)id_1827;
                                                                    (void)id_1827;
                                                                  }
                                                                } while (while_flag_1809);
                                                                (void)::dessser::Void();
                                                              }
                                                              (void)::dessser::Void();
                                                              uint8_t id_1828 { 0 };
                                                              ::dessser::gen::alert::ted4b695d380cc59a0573f58c72d5df5e id_1829 { inits_src_ref_331[id_1828] };
                                                              let_res_1806 = id_1829;
                                                            }
                                                            letpair_res_1802 = let_res_1806;
                                                          }
                                                          let_res_1801 = letpair_res_1802;
                                                        }
                                                        ::dessser::gen::alert::t039e94b31ddf5a8d0097a51fda754c54 letpair_res_1830;
                                                        {
                                                          auto dlist4_fst_340 { std::get<0>(let_res_1801) };
                                                          auto dlist4_snd_341 { std::get<1>(let_res_1801) };
                                                          Arr<std::shared_ptr<::dessser::gen::alert::constant> > id_1831 { dlist4_fst_340.toListRev() };
                                                          ::dessser::gen::alert::t039e94b31ddf5a8d0097a51fda754c54 id_1832 { id_1831, dlist4_snd_341 };
                                                          letpair_res_1830 = id_1832;
                                                        }
                                                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1833;
                                                        {
                                                          ::dessser::gen::alert::t039e94b31ddf5a8d0097a51fda754c54 drec_342 { letpair_res_1830 };
                                                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1834;
                                                          {
                                                            auto drec_fst_343 { std::get<0>(drec_342) };
                                                            auto drec_snd_344 { std::get<1>(drec_342) };
                                                            uint32_t id_1835 { 0U };
                                                            Vec<1, uint32_t> id_1836 {  id_1835  };
                                                            ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1837;
                                                            {
                                                              Vec<1, uint32_t> leb_ref_345 { id_1836 };
                                                              uint8_t id_1838 { 0 };
                                                              Vec<1, uint8_t> id_1839 {  id_1838  };
                                                              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1840;
                                                              {
                                                                Vec<1, uint8_t> shft_ref_346 { id_1839 };
                                                                Vec<1, Pointer> id_1841 {  drec_snd_344  };
                                                                ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1842;
                                                                {
                                                                  Vec<1, Pointer> p_ref_347 { id_1841 };
                                                                  bool while_flag_1843 { true };
                                                                  do {
                                                                    uint8_t id_1844 { 0 };
                                                                    Pointer id_1845 { p_ref_347[id_1844] };
                                                                    ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1846 { id_1845.readU8() };
                                                                    bool let_res_1847;
                                                                    {
                                                                      ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_348 { id_1846 };
                                                                      bool letpair_res_1848;
                                                                      {
                                                                        auto leb128_fst_349 { std::get<0>(leb128_348) };
                                                                        auto leb128_snd_350 { std::get<1>(leb128_348) };
                                                                        uint8_t id_1849 { 0 };
                                                                        Void id_1850 { ((void)(p_ref_347[id_1849] = leb128_snd_350), ::dessser::Void()) };
                                                                        (void)id_1850;
                                                                        uint8_t id_1851 { 0 };
                                                                        uint8_t id_1852 { 127 };
                                                                        uint8_t id_1853 { uint8_t(leb128_fst_349 & id_1852) };
                                                                        uint32_t id_1854 { uint32_t(id_1853) };
                                                                        uint8_t id_1855 { 0 };
                                                                        uint8_t id_1856 { shft_ref_346[id_1855] };
                                                                        uint32_t id_1857 { uint32_t(id_1854 << id_1856) };
                                                                        uint8_t id_1858 { 0 };
                                                                        uint32_t id_1859 { leb_ref_345[id_1858] };
                                                                        uint32_t id_1860 { uint32_t(id_1857 | id_1859) };
                                                                        Void id_1861 { ((void)(leb_ref_345[id_1851] = id_1860), ::dessser::Void()) };
                                                                        (void)id_1861;
                                                                        uint8_t id_1862 { 0 };
                                                                        uint8_t id_1863 { 0 };
                                                                        uint8_t id_1864 { shft_ref_346[id_1863] };
                                                                        uint8_t id_1865 { 7 };
                                                                        uint8_t id_1866 { uint8_t(id_1864 + id_1865) };
                                                                        Void id_1867 { ((void)(shft_ref_346[id_1862] = id_1866), ::dessser::Void()) };
                                                                        (void)id_1867;
                                                                        uint8_t id_1868 { 128 };
                                                                        bool id_1869 { bool(leb128_fst_349 >= id_1868) };
                                                                        letpair_res_1848 = id_1869;
                                                                      }
                                                                      let_res_1847 = letpair_res_1848;
                                                                    }
                                                                    while_flag_1843 = let_res_1847;
                                                                    if (while_flag_1843) {
                                                                      (void)::dessser::Void();
                                                                    }
                                                                  } while (while_flag_1843);
                                                                  (void)::dessser::Void();
                                                                  uint8_t id_1870 { 0 };
                                                                  uint32_t id_1871 { leb_ref_345[id_1870] };
                                                                  Size id_1872 { Size(id_1871) };
                                                                  uint8_t id_1873 { 0 };
                                                                  Pointer id_1874 { p_ref_347[id_1873] };
                                                                  ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1875 { id_1872, id_1874 };
                                                                  let_res_1842 = id_1875;
                                                                }
                                                                let_res_1840 = let_res_1842;
                                                              }
                                                              let_res_1837 = let_res_1840;
                                                            }
                                                            ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 let_res_1876;
                                                            {
                                                              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_351 { let_res_1837 };
                                                              ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1877;
                                                              {
                                                                auto dstring1_fst_352 { std::get<0>(dstring1_351) };
                                                                auto dstring1_snd_353 { std::get<1>(dstring1_351) };
                                                                ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1878 { dstring1_snd_353.readBytes(dstring1_fst_352) };
                                                                ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1879;
                                                                {
                                                                  auto dstring2_fst_355 { std::get<0>(id_1878) };
                                                                  auto dstring2_snd_356 { std::get<1>(id_1878) };
                                                                  std::string id_1880 { dstring2_fst_355.toString() };
                                                                  ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 id_1881 { id_1880, dstring2_snd_356 };
                                                                  letpair_res_1879 = id_1881;
                                                                }
                                                                letpair_res_1877 = letpair_res_1879;
                                                              }
                                                              let_res_1876 = letpair_res_1877;
                                                            }
                                                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1882;
                                                            {
                                                              ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 drec_357 { let_res_1876 };
                                                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1883;
                                                              {
                                                                auto drec_fst_358 { std::get<0>(drec_357) };
                                                                auto drec_snd_359 { std::get<1>(drec_357) };
                                                                uint32_t id_1884 { 0U };
                                                                Vec<1, uint32_t> id_1885 {  id_1884  };
                                                                ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1886;
                                                                {
                                                                  Vec<1, uint32_t> leb_ref_360 { id_1885 };
                                                                  uint8_t id_1887 { 0 };
                                                                  Vec<1, uint8_t> id_1888 {  id_1887  };
                                                                  ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1889;
                                                                  {
                                                                    Vec<1, uint8_t> shft_ref_361 { id_1888 };
                                                                    Vec<1, Pointer> id_1890 {  drec_snd_359  };
                                                                    ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1891;
                                                                    {
                                                                      Vec<1, Pointer> p_ref_362 { id_1890 };
                                                                      bool while_flag_1892 { true };
                                                                      do {
                                                                        uint8_t id_1893 { 0 };
                                                                        Pointer id_1894 { p_ref_362[id_1893] };
                                                                        ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1895 { id_1894.readU8() };
                                                                        bool let_res_1896;
                                                                        {
                                                                          ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_363 { id_1895 };
                                                                          bool letpair_res_1897;
                                                                          {
                                                                            auto leb128_fst_364 { std::get<0>(leb128_363) };
                                                                            auto leb128_snd_365 { std::get<1>(leb128_363) };
                                                                            uint8_t id_1898 { 0 };
                                                                            Void id_1899 { ((void)(p_ref_362[id_1898] = leb128_snd_365), ::dessser::Void()) };
                                                                            (void)id_1899;
                                                                            uint8_t id_1900 { 0 };
                                                                            uint8_t id_1901 { 127 };
                                                                            uint8_t id_1902 { uint8_t(leb128_fst_364 & id_1901) };
                                                                            uint32_t id_1903 { uint32_t(id_1902) };
                                                                            uint8_t id_1904 { 0 };
                                                                            uint8_t id_1905 { shft_ref_361[id_1904] };
                                                                            uint32_t id_1906 { uint32_t(id_1903 << id_1905) };
                                                                            uint8_t id_1907 { 0 };
                                                                            uint32_t id_1908 { leb_ref_360[id_1907] };
                                                                            uint32_t id_1909 { uint32_t(id_1906 | id_1908) };
                                                                            Void id_1910 { ((void)(leb_ref_360[id_1900] = id_1909), ::dessser::Void()) };
                                                                            (void)id_1910;
                                                                            uint8_t id_1911 { 0 };
                                                                            uint8_t id_1912 { 0 };
                                                                            uint8_t id_1913 { shft_ref_361[id_1912] };
                                                                            uint8_t id_1914 { 7 };
                                                                            uint8_t id_1915 { uint8_t(id_1913 + id_1914) };
                                                                            Void id_1916 { ((void)(shft_ref_361[id_1911] = id_1915), ::dessser::Void()) };
                                                                            (void)id_1916;
                                                                            uint8_t id_1917 { 128 };
                                                                            bool id_1918 { bool(leb128_fst_364 >= id_1917) };
                                                                            letpair_res_1897 = id_1918;
                                                                          }
                                                                          let_res_1896 = letpair_res_1897;
                                                                        }
                                                                        while_flag_1892 = let_res_1896;
                                                                        if (while_flag_1892) {
                                                                          (void)::dessser::Void();
                                                                        }
                                                                      } while (while_flag_1892);
                                                                      (void)::dessser::Void();
                                                                      uint8_t id_1919 { 0 };
                                                                      uint32_t id_1920 { leb_ref_360[id_1919] };
                                                                      Size id_1921 { Size(id_1920) };
                                                                      uint8_t id_1922 { 0 };
                                                                      Pointer id_1923 { p_ref_362[id_1922] };
                                                                      ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1924 { id_1921, id_1923 };
                                                                      let_res_1891 = id_1924;
                                                                    }
                                                                    let_res_1889 = let_res_1891;
                                                                  }
                                                                  let_res_1886 = let_res_1889;
                                                                }
                                                                ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 let_res_1925;
                                                                {
                                                                  ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_366 { let_res_1886 };
                                                                  ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1926;
                                                                  {
                                                                    auto dstring1_fst_367 { std::get<0>(dstring1_366) };
                                                                    auto dstring1_snd_368 { std::get<1>(dstring1_366) };
                                                                    ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1927 { dstring1_snd_368.readBytes(dstring1_fst_367) };
                                                                    ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1928;
                                                                    {
                                                                      auto dstring2_fst_370 { std::get<0>(id_1927) };
                                                                      auto dstring2_snd_371 { std::get<1>(id_1927) };
                                                                      std::string id_1929 { dstring2_fst_370.toString() };
                                                                      ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 id_1930 { id_1929, dstring2_snd_371 };
                                                                      letpair_res_1928 = id_1930;
                                                                    }
                                                                    letpair_res_1926 = letpair_res_1928;
                                                                  }
                                                                  let_res_1925 = letpair_res_1926;
                                                                }
                                                                ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1931;
                                                                {
                                                                  ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 drec_372 { let_res_1925 };
                                                                  ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1932;
                                                                  {
                                                                    auto drec_fst_373 { std::get<0>(drec_372) };
                                                                    auto drec_snd_374 { std::get<1>(drec_372) };
                                                                    uint32_t id_1933 { 0U };
                                                                    Vec<1, uint32_t> id_1934 {  id_1933  };
                                                                    ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1935;
                                                                    {
                                                                      Vec<1, uint32_t> leb_ref_375 { id_1934 };
                                                                      uint8_t id_1936 { 0 };
                                                                      Vec<1, uint8_t> id_1937 {  id_1936  };
                                                                      ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1938;
                                                                      {
                                                                        Vec<1, uint8_t> shft_ref_376 { id_1937 };
                                                                        Vec<1, Pointer> id_1939 {  drec_snd_374  };
                                                                        ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1940;
                                                                        {
                                                                          Vec<1, Pointer> p_ref_377 { id_1939 };
                                                                          bool while_flag_1941 { true };
                                                                          do {
                                                                            uint8_t id_1942 { 0 };
                                                                            Pointer id_1943 { p_ref_377[id_1942] };
                                                                            ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1944 { id_1943.readU8() };
                                                                            bool let_res_1945;
                                                                            {
                                                                              ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_378 { id_1944 };
                                                                              bool letpair_res_1946;
                                                                              {
                                                                                auto leb128_fst_379 { std::get<0>(leb128_378) };
                                                                                auto leb128_snd_380 { std::get<1>(leb128_378) };
                                                                                uint8_t id_1947 { 0 };
                                                                                Void id_1948 { ((void)(p_ref_377[id_1947] = leb128_snd_380), ::dessser::Void()) };
                                                                                (void)id_1948;
                                                                                uint8_t id_1949 { 0 };
                                                                                uint8_t id_1950 { 127 };
                                                                                uint8_t id_1951 { uint8_t(leb128_fst_379 & id_1950) };
                                                                                uint32_t id_1952 { uint32_t(id_1951) };
                                                                                uint8_t id_1953 { 0 };
                                                                                uint8_t id_1954 { shft_ref_376[id_1953] };
                                                                                uint32_t id_1955 { uint32_t(id_1952 << id_1954) };
                                                                                uint8_t id_1956 { 0 };
                                                                                uint32_t id_1957 { leb_ref_375[id_1956] };
                                                                                uint32_t id_1958 { uint32_t(id_1955 | id_1957) };
                                                                                Void id_1959 { ((void)(leb_ref_375[id_1949] = id_1958), ::dessser::Void()) };
                                                                                (void)id_1959;
                                                                                uint8_t id_1960 { 0 };
                                                                                uint8_t id_1961 { 0 };
                                                                                uint8_t id_1962 { shft_ref_376[id_1961] };
                                                                                uint8_t id_1963 { 7 };
                                                                                uint8_t id_1964 { uint8_t(id_1962 + id_1963) };
                                                                                Void id_1965 { ((void)(shft_ref_376[id_1960] = id_1964), ::dessser::Void()) };
                                                                                (void)id_1965;
                                                                                uint8_t id_1966 { 128 };
                                                                                bool id_1967 { bool(leb128_fst_379 >= id_1966) };
                                                                                letpair_res_1946 = id_1967;
                                                                              }
                                                                              let_res_1945 = letpair_res_1946;
                                                                            }
                                                                            while_flag_1941 = let_res_1945;
                                                                            if (while_flag_1941) {
                                                                              (void)::dessser::Void();
                                                                            }
                                                                          } while (while_flag_1941);
                                                                          (void)::dessser::Void();
                                                                          uint8_t id_1968 { 0 };
                                                                          uint32_t id_1969 { leb_ref_375[id_1968] };
                                                                          Size id_1970 { Size(id_1969) };
                                                                          uint8_t id_1971 { 0 };
                                                                          Pointer id_1972 { p_ref_377[id_1971] };
                                                                          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_1973 { id_1970, id_1972 };
                                                                          let_res_1940 = id_1973;
                                                                        }
                                                                        let_res_1938 = let_res_1940;
                                                                      }
                                                                      let_res_1935 = let_res_1938;
                                                                    }
                                                                    ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 let_res_1974;
                                                                    {
                                                                      ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_381 { let_res_1935 };
                                                                      ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1975;
                                                                      {
                                                                        auto dstring1_fst_382 { std::get<0>(dstring1_381) };
                                                                        auto dstring1_snd_383 { std::get<1>(dstring1_381) };
                                                                        ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_1976 { dstring1_snd_383.readBytes(dstring1_fst_382) };
                                                                        ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 letpair_res_1977;
                                                                        {
                                                                          auto dstring2_fst_385 { std::get<0>(id_1976) };
                                                                          auto dstring2_snd_386 { std::get<1>(id_1976) };
                                                                          std::string id_1978 { dstring2_fst_385.toString() };
                                                                          ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 id_1979 { id_1978, dstring2_snd_386 };
                                                                          letpair_res_1977 = id_1979;
                                                                        }
                                                                        letpair_res_1975 = letpair_res_1977;
                                                                      }
                                                                      let_res_1974 = letpair_res_1975;
                                                                    }
                                                                    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_1980;
                                                                    {
                                                                      ::dessser::gen::alert::t13a07ee37ab40962540da8534858dc07 drec_387 { let_res_1974 };
                                                                      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_1981;
                                                                      {
                                                                        auto drec_fst_388 { std::get<0>(drec_387) };
                                                                        auto drec_snd_389 { std::get<1>(drec_387) };
                                                                        uint32_t id_1982 { 0U };
                                                                        Vec<1, uint32_t> id_1983 {  id_1982  };
                                                                        ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1984;
                                                                        {
                                                                          Vec<1, uint32_t> leb_ref_390 { id_1983 };
                                                                          uint8_t id_1985 { 0 };
                                                                          Vec<1, uint8_t> id_1986 {  id_1985  };
                                                                          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1987;
                                                                          {
                                                                            Vec<1, uint8_t> shft_ref_391 { id_1986 };
                                                                            Vec<1, Pointer> id_1988 {  drec_snd_389  };
                                                                            ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa let_res_1989;
                                                                            {
                                                                              Vec<1, Pointer> p_ref_392 { id_1988 };
                                                                              bool while_flag_1990 { true };
                                                                              do {
                                                                                uint8_t id_1991 { 0 };
                                                                                Pointer id_1992 { p_ref_392[id_1991] };
                                                                                ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 id_1993 { id_1992.readU8() };
                                                                                bool let_res_1994;
                                                                                {
                                                                                  ::dessser::gen::alert::t1a5d74abf838df33f185a72a8912f5c9 leb128_393 { id_1993 };
                                                                                  bool letpair_res_1995;
                                                                                  {
                                                                                    auto leb128_fst_394 { std::get<0>(leb128_393) };
                                                                                    auto leb128_snd_395 { std::get<1>(leb128_393) };
                                                                                    uint8_t id_1996 { 0 };
                                                                                    Void id_1997 { ((void)(p_ref_392[id_1996] = leb128_snd_395), ::dessser::Void()) };
                                                                                    (void)id_1997;
                                                                                    uint8_t id_1998 { 0 };
                                                                                    uint8_t id_1999 { 127 };
                                                                                    uint8_t id_2000 { uint8_t(leb128_fst_394 & id_1999) };
                                                                                    uint32_t id_2001 { uint32_t(id_2000) };
                                                                                    uint8_t id_2002 { 0 };
                                                                                    uint8_t id_2003 { shft_ref_391[id_2002] };
                                                                                    uint32_t id_2004 { uint32_t(id_2001 << id_2003) };
                                                                                    uint8_t id_2005 { 0 };
                                                                                    uint32_t id_2006 { leb_ref_390[id_2005] };
                                                                                    uint32_t id_2007 { uint32_t(id_2004 | id_2006) };
                                                                                    Void id_2008 { ((void)(leb_ref_390[id_1998] = id_2007), ::dessser::Void()) };
                                                                                    (void)id_2008;
                                                                                    uint8_t id_2009 { 0 };
                                                                                    uint8_t id_2010 { 0 };
                                                                                    uint8_t id_2011 { shft_ref_391[id_2010] };
                                                                                    uint8_t id_2012 { 7 };
                                                                                    uint8_t id_2013 { uint8_t(id_2011 + id_2012) };
                                                                                    Void id_2014 { ((void)(shft_ref_391[id_2009] = id_2013), ::dessser::Void()) };
                                                                                    (void)id_2014;
                                                                                    uint8_t id_2015 { 128 };
                                                                                    bool id_2016 { bool(leb128_fst_394 >= id_2015) };
                                                                                    letpair_res_1995 = id_2016;
                                                                                  }
                                                                                  let_res_1994 = letpair_res_1995;
                                                                                }
                                                                                while_flag_1990 = let_res_1994;
                                                                                if (while_flag_1990) {
                                                                                  (void)::dessser::Void();
                                                                                }
                                                                              } while (while_flag_1990);
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_2017 { 0 };
                                                                              uint32_t id_2018 { leb_ref_390[id_2017] };
                                                                              Size id_2019 { Size(id_2018) };
                                                                              uint8_t id_2020 { 0 };
                                                                              Pointer id_2021 { p_ref_392[id_2020] };
                                                                              ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa id_2022 { id_2019, id_2021 };
                                                                              let_res_1989 = id_2022;
                                                                            }
                                                                            let_res_1987 = let_res_1989;
                                                                          }
                                                                          let_res_1984 = let_res_1987;
                                                                        }
                                                                        ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 let_res_2023;
                                                                        {
                                                                          ::dessser::gen::alert::t12fb9c475959b52bf7b17b155a955ffa dstring1_396 { let_res_1984 };
                                                                          ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_2024;
                                                                          {
                                                                            auto dstring1_fst_397 { std::get<0>(dstring1_396) };
                                                                            auto dstring1_snd_398 { std::get<1>(dstring1_396) };
                                                                            ::dessser::gen::alert::t9ef6882174ae71a34a3c5ef6b29242fb id_2025 { dstring1_snd_398.readBytes(dstring1_fst_397) };
                                                                            ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_2026;
                                                                            {
                                                                              auto dstring2_fst_400 { std::get<0>(id_2025) };
                                                                              auto dstring2_snd_401 { std::get<1>(id_2025) };
                                                                              std::string id_2027 { dstring2_fst_400.toString() };
                                                                              std::shared_ptr<::dessser::gen::alert::t>  id_2028 { std::make_shared<::dessser::gen::alert::t>(drec_fst_148, drec_fst_151, drec_fst_157, drec_fst_183, drec_fst_212, drec_fst_238, drec_fst_241, drec_fst_247, drec_fst_253, drec_fst_259, drec_fst_265, drec_fst_291, drec_fst_317, drec_fst_343, drec_fst_358, drec_fst_373, drec_fst_388, id_2027) };
                                                                              ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 id_2029 { id_2028, dstring2_snd_401 };
                                                                              letpair_res_2026 = id_2029;
                                                                            }
                                                                            letpair_res_2024 = letpair_res_2026;
                                                                          }
                                                                          let_res_2023 = letpair_res_2024;
                                                                        }
                                                                        letpair_res_1981 = let_res_2023;
                                                                      }
                                                                      let_res_1980 = letpair_res_1981;
                                                                    }
                                                                    letpair_res_1932 = let_res_1980;
                                                                  }
                                                                  let_res_1931 = letpair_res_1932;
                                                                }
                                                                letpair_res_1883 = let_res_1931;
                                                              }
                                                              let_res_1882 = letpair_res_1883;
                                                            }
                                                            letpair_res_1834 = let_res_1882;
                                                          }
                                                          let_res_1833 = letpair_res_1834;
                                                        }
                                                        letpair_res_1760 = let_res_1833;
                                                      }
                                                      let_res_1759 = letpair_res_1760;
                                                    }
                                                    letpair_res_1685 = let_res_1759;
                                                  }
                                                  let_res_1684 = letpair_res_1685;
                                                }
                                                letpair_res_1610 = let_res_1684;
                                              }
                                              let_res_1609 = letpair_res_1610;
                                            }
                                            letpair_res_1604 = let_res_1609;
                                          }
                                          let_res_1603 = letpair_res_1604;
                                        }
                                        letpair_res_1598 = let_res_1603;
                                      }
                                      let_res_1597 = letpair_res_1598;
                                    }
                                    letpair_res_1592 = let_res_1597;
                                  }
                                  let_res_1591 = letpair_res_1592;
                                }
                                letpair_res_1586 = let_res_1591;
                              }
                              let_res_1585 = letpair_res_1586;
                            }
                            letpair_res_1583 = let_res_1585;
                          }
                          let_res_1582 = letpair_res_1583;
                        }
                        letpair_res_1508 = let_res_1582;
                      }
                      let_res_1507 = letpair_res_1508;
                    }
                    letpair_res_1421 = let_res_1507;
                  }
                  let_res_1420 = letpair_res_1421;
                }
                letpair_res_1346 = let_res_1420;
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
    (fun ("Ptr") (let-pair "make_fst_406" "make_snd_407" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_406") (identifier "make_snd_407"))))
 */
static std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> fun2030 { [&](Pointer p_0) {
    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 id_2031 { of_row_binary(p_0) };
    ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 letpair_res_2032;
    {
      auto make_fst_406 { std::get<0>(id_2031) };
      auto make_snd_407 { std::get<1>(id_2031) };
      ::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6 id_2033 { make_fst_406, make_snd_407 };
      letpair_res_2032 = id_2033;
    }
    return letpair_res_2032;
  }
   };
  return fun2030;
}
std::function<::dessser::gen::alert::tc6d52773763d322654577a54bd0001f6(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[]; group-by: $field_name[]?; having: $simple_filter[]; threshold: (threshold AS [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]); hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[]; carry-fields: $field_name[]; carry-csts: (constant AS {name: $field_name; value: STRING})[]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> fun2034 { [&](std::shared_ptr<::dessser::gen::alert::t>  p_0, Pointer p_1) {
    Pointer id_2035 { to_row_binary(p_0, p_1) };
    return id_2035;
  }
   };
  return fun2034;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alert::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
