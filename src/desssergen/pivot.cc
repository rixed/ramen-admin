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
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/fq_name.h"

namespace dessser::gen::pivot {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct top {
  uint16_t n;
  std::optional<dessser::gen::field_name::t_ext> by;
  top(uint16_t n_, std::optional<dessser::gen::field_name::t_ext> by_) : n(n_), by(by_) {}
  top() = default;
};
inline bool operator==(top const &a, top const &b) {
  return a.n == b.n && ((a.by && b.by && ::dessser::gen::field_name::Deref(a.by.value()) == ::dessser::gen::field_name::Deref(b.by.value())) || (!a.by && !b.by));
}

inline bool operator!=(top const &a, top const &b) {
  return !operator==(a, b);
}
struct t26b95203b7d109bdca2c935b0d6e7ca0 {
  dessser::gen::field_name::t_ext name;
  Arr<std::string> types;
  bool count;
  bool first;
  bool last;
  bool min;
  bool max;
  bool sum;
  bool avg;
  Arr<double> percentiles;
  Arr<::dessser::gen::pivot::top> tops;
  t26b95203b7d109bdca2c935b0d6e7ca0(dessser::gen::field_name::t_ext name_, Arr<std::string> types_, bool count_, bool first_, bool last_, bool min_, bool max_, bool sum_, bool avg_, Arr<double> percentiles_, Arr<::dessser::gen::pivot::top> tops_) : name(name_), types(types_), count(count_), first(first_), last(last_), min(min_), max(max_), sum(sum_), avg(avg_), percentiles(percentiles_), tops(tops_) {}
  t26b95203b7d109bdca2c935b0d6e7ca0() = default;
};
inline bool operator==(t26b95203b7d109bdca2c935b0d6e7ca0 const &a, t26b95203b7d109bdca2c935b0d6e7ca0 const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && a.types == b.types && a.count == b.count && a.first == b.first && a.last == b.last && a.min == b.min && a.max == b.max && a.sum == b.sum && a.avg == b.avg && a.percentiles == b.percentiles && a.tops == b.tops;
}

inline bool operator!=(t26b95203b7d109bdca2c935b0d6e7ca0 const &a, t26b95203b7d109bdca2c935b0d6e7ca0 const &b) {
  return !operator==(a, b);
}
struct t {
  dessser::gen::fq_name::t_ext from;
  Arr<dessser::gen::simple_filter::t_ext> where;
  dessser::gen::field_name::t_ext type_field;
  dessser::gen::field_name::t_ext value_field;
  Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> fields;
  Arr<dessser::gen::field_name::t_ext> group_by;
  double duration;
  double max_lateness;
  t(dessser::gen::fq_name::t_ext from_, Arr<dessser::gen::simple_filter::t_ext> where_, dessser::gen::field_name::t_ext type_field_, dessser::gen::field_name::t_ext value_field_, Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> fields_, Arr<dessser::gen::field_name::t_ext> group_by_, double duration_, double max_lateness_) : from(from_), where(where_), type_field(type_field_), value_field(value_field_), fields(fields_), group_by(group_by_), duration(duration_), max_lateness(max_lateness_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::fq_name::Deref(a.from) == ::dessser::gen::fq_name::Deref(b.from) && a.where == b.where && ::dessser::gen::field_name::Deref(a.type_field) == ::dessser::gen::field_name::Deref(b.type_field) && ::dessser::gen::field_name::Deref(a.value_field) == ::dessser::gen::field_name::Deref(b.value_field) && a.fields == b.fields && a.group_by == b.group_by && a.duration == b.duration && a.max_lateness == b.max_lateness;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t7aae03d1a1a74f1dfca1edade27a0c74 : public std::tuple<
  ::dessser::gen::pivot::top,
  Pointer
> {
  using tuple::tuple;
  t7aae03d1a1a74f1dfca1edade27a0c74(std::tuple<::dessser::gen::pivot::top, Pointer> p)
    : std::tuple<::dessser::gen::pivot::top, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7aae03d1a1a74f1dfca1edade27a0c74 const &a, t7aae03d1a1a74f1dfca1edade27a0c74 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7aae03d1a1a74f1dfca1edade27a0c74 const &a, t7aae03d1a1a74f1dfca1edade27a0c74 const &b) {
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
struct t017c58e4a7553374b91a64cd4c386334 : public std::tuple<
  std::optional<dessser::gen::field_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t017c58e4a7553374b91a64cd4c386334(std::tuple<std::optional<dessser::gen::field_name::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::field_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t017c58e4a7553374b91a64cd4c386334 const &a, t017c58e4a7553374b91a64cd4c386334 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::field_name::Deref(std::get<0>(a).value()) == ::dessser::gen::field_name::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t017c58e4a7553374b91a64cd4c386334 const &a, t017c58e4a7553374b91a64cd4c386334 const &b) {
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
struct t8ee925d72cfbfe36ed4ad9adbc5f4519 : public std::tuple<
  ::dessser::gen::pivot::t,
  Pointer
> {
  using tuple::tuple;
  t8ee925d72cfbfe36ed4ad9adbc5f4519(std::tuple<::dessser::gen::pivot::t, Pointer> p)
    : std::tuple<::dessser::gen::pivot::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8ee925d72cfbfe36ed4ad9adbc5f4519 const &a, t8ee925d72cfbfe36ed4ad9adbc5f4519 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8ee925d72cfbfe36ed4ad9adbc5f4519 const &a, t8ee925d72cfbfe36ed4ad9adbc5f4519 const &b) {
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
struct ta0e4b5c632ab9a7e56d2036a227274e7 : public std::tuple<
  Lst<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0>,
  Pointer
> {
  using tuple::tuple;
  ta0e4b5c632ab9a7e56d2036a227274e7(std::tuple<Lst<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta0e4b5c632ab9a7e56d2036a227274e7 const &a, ta0e4b5c632ab9a7e56d2036a227274e7 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta0e4b5c632ab9a7e56d2036a227274e7 const &a, ta0e4b5c632ab9a7e56d2036a227274e7 const &b) {
  return !operator==(a, b);
}
struct t941fe844f492c6f2281f99ea362423fc : public std::tuple<
  Lst<std::string>,
  Pointer
> {
  using tuple::tuple;
  t941fe844f492c6f2281f99ea362423fc(std::tuple<Lst<std::string>, Pointer> p)
    : std::tuple<Lst<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t941fe844f492c6f2281f99ea362423fc const &a, t941fe844f492c6f2281f99ea362423fc const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t941fe844f492c6f2281f99ea362423fc const &a, t941fe844f492c6f2281f99ea362423fc const &b) {
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
struct t8293f5c3f24638d91c1ca307ed4a5278 : public std::tuple<
  Arr<std::string>,
  Pointer
> {
  using tuple::tuple;
  t8293f5c3f24638d91c1ca307ed4a5278(std::tuple<Arr<std::string>, Pointer> p)
    : std::tuple<Arr<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8293f5c3f24638d91c1ca307ed4a5278 const &a, t8293f5c3f24638d91c1ca307ed4a5278 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8293f5c3f24638d91c1ca307ed4a5278 const &a, t8293f5c3f24638d91c1ca307ed4a5278 const &b) {
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
struct t9fb99a328772de0c291da3838a4bcfe3 : public std::tuple<
  Lst<double>,
  Pointer
> {
  using tuple::tuple;
  t9fb99a328772de0c291da3838a4bcfe3(std::tuple<Lst<double>, Pointer> p)
    : std::tuple<Lst<double>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9fb99a328772de0c291da3838a4bcfe3 const &a, t9fb99a328772de0c291da3838a4bcfe3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9fb99a328772de0c291da3838a4bcfe3 const &a, t9fb99a328772de0c291da3838a4bcfe3 const &b) {
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
struct t72f695ab4fb53702c7aa92b69429e954 : public std::tuple<
  Arr<double>,
  Pointer
> {
  using tuple::tuple;
  t72f695ab4fb53702c7aa92b69429e954(std::tuple<Arr<double>, Pointer> p)
    : std::tuple<Arr<double>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t72f695ab4fb53702c7aa92b69429e954 const &a, t72f695ab4fb53702c7aa92b69429e954 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t72f695ab4fb53702c7aa92b69429e954 const &a, t72f695ab4fb53702c7aa92b69429e954 const &b) {
  return !operator==(a, b);
}
struct t2fb7622ec11d8dfa2277a4f79bf3dc30 : public std::tuple<
  Lst<::dessser::gen::pivot::top>,
  Pointer
> {
  using tuple::tuple;
  t2fb7622ec11d8dfa2277a4f79bf3dc30(std::tuple<Lst<::dessser::gen::pivot::top>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::pivot::top>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2fb7622ec11d8dfa2277a4f79bf3dc30 const &a, t2fb7622ec11d8dfa2277a4f79bf3dc30 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2fb7622ec11d8dfa2277a4f79bf3dc30 const &a, t2fb7622ec11d8dfa2277a4f79bf3dc30 const &b) {
  return !operator==(a, b);
}
struct t6eabb53e3ce0d815c25a2418c3f9e53e : public std::tuple<
  Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0>,
  Pointer
> {
  using tuple::tuple;
  t6eabb53e3ce0d815c25a2418c3f9e53e(std::tuple<Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0>, Pointer> p)
    : std::tuple<Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6eabb53e3ce0d815c25a2418c3f9e53e const &a, t6eabb53e3ce0d815c25a2418c3f9e53e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6eabb53e3ce0d815c25a2418c3f9e53e const &a, t6eabb53e3ce0d815c25a2418c3f9e53e const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{n: U16; by: $field_name?}" "Ptr")
      (let "srec_dst_357" (write-u16 little-endian (param 1) (get-field "n" (param 0)))
        (if (is-null (get-field "by" (param 0))) (write-u8 (identifier "srec_dst_357") (u8 1)) (apply (ext-identifier field_name to-row-binary) (force (get-field "by" (param 0))) (write-u8 (identifier "srec_dst_357") (u8 0))))))
 */
static std::function<Pointer(::dessser::gen::pivot::top &,Pointer &)> top_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::pivot::top &,Pointer &)> fun0 { [&](::dessser::gen::pivot::top p_0, Pointer p_1) {
    uint16_t id_1 { p_0.n };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_357 { id_2 };
      std::optional<dessser::gen::field_name::t_ext> id_4 { p_0.by };
      bool id_5 { !(id_4.has_value ()) };
      Pointer choose_res_6;
      if (id_5) {
        uint8_t id_7 { 1 };
        Pointer id_8 { srec_dst_357.writeU8(id_7) };
        choose_res_6 = id_8;
      } else {
        auto fun9 { dessser::gen::field_name::to_row_binary };
        std::optional<dessser::gen::field_name::t_ext> id_10 { p_0.by };
        dessser::gen::field_name::t_ext id_11 { id_10.value() };
        uint8_t id_12 { 0 };
        Pointer id_13 { srec_dst_357.writeU8(id_12) };
        Pointer id_14 { fun9(id_11, id_13) };
        choose_res_6 = id_14;
      }
      let_res_3 = choose_res_6;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::pivot::top &,Pointer &)> top_to_row_binary(top_to_row_binary_init());

/* 
    (fun ("{from: $fq_name; where: $simple_filter[]; type-field: $field_name; value-field: $field_name; fields: {name: $field_name; types: STRING[]; count: BOOL; first: BOOL; last: BOOL; min: BOOL; max: BOOL; sum: BOOL; avg: BOOL; percentiles: FLOAT[]; tops: (top AS {n: U16; by: $field_name?})[]}[]; group-by: $field_name[]; duration: FLOAT; max-lateness: FLOAT}" "Ptr")
      (let "srec_dst_407"
        (let "srec_dst_406"
          (let "srec_dst_400"
            (let "srec_dst_366"
              (let "srec_dst_365"
                (let "srec_dst_364"
                  (let "srec_dst_358" (apply (ext-identifier fq_name to-row-binary) (get-field "from" (param 0)) (param 1))
                    (let "dst_ref_361"
                      (make-vec
                        (let "leb128_sz_359" (make-vec (cardinality (get-field "where" (param 0))))
                          (let "leb128_ptr_360" (make-vec (identifier "srec_dst_358"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_360")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_360"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_359"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_359"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_359"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_359") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_359")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_359")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_360"))))))
                      (let "n_ref_362" (make-vec (i32 0))
                        (seq
                          (for-each "x_363" (get-field "where" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_361") (apply (ext-identifier simple_filter to-row-binary) (identifier "x_363") (unsafe-nth (u8 0) (identifier "dst_ref_361"))))
                              (set-vec (u8 0) (identifier "n_ref_362") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_362")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_361")))))) 
                  (apply (ext-identifier field_name to-row-binary) (get-field "type-field" (param 0)) (identifier "srec_dst_364")))
                (apply (ext-identifier field_name to-row-binary) (get-field "value-field" (param 0)) (identifier "srec_dst_365")))
              (let "dst_ref_369"
                (make-vec
                  (let "leb128_sz_367" (make-vec (cardinality (get-field "fields" (param 0))))
                    (let "leb128_ptr_368" (make-vec (identifier "srec_dst_366"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_368")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_368"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_367"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_367"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_367"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_367") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_367")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_367")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_368"))))))
                (let "n_ref_370" (make-vec (i32 0))
                  (seq
                    (for-each "x_371" (get-field "fields" (param 0))
                      (seq
                        (set-vec (u8 0) (identifier "dst_ref_369")
                          (let "srec_dst_394"
                            (let "srec_dst_388"
                              (let "srec_dst_387"
                                (let "srec_dst_386"
                                  (let "srec_dst_385"
                                    (let "srec_dst_384"
                                      (let "srec_dst_383"
                                        (let "srec_dst_382"
                                          (let "srec_dst_381"
                                            (let "srec_dst_373"
                                              (let "srec_dst_372" (unsafe-nth (u8 0) (identifier "dst_ref_369"))
                                                (apply (ext-identifier field_name to-row-binary) (get-field "name" (identifier "x_371")) (identifier "srec_dst_372")))
                                              (let "dst_ref_376"
                                                (make-vec
                                                  (let "leb128_sz_374" 
                                                    (make-vec (cardinality (get-field "types" (identifier "x_371"))))
                                                    (let "leb128_ptr_375" 
                                                      (make-vec (identifier "srec_dst_373"))
                                                      (seq
                                                        (while
                                                          (seq
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb128_ptr_375")
                                                              (write-u8 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_375"))
                                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_374"))) 
                                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_374"))) 
                                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_374"))) (u8 128)))))
                                                            (set-vec (u8 0) (identifier "leb128_sz_374") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_374")) (u8 7)))
                                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_374")) (u32 0))) 
                                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_375"))))))
                                                (let "n_ref_377" (make-vec (i32 0))
                                                  (seq
                                                    (for-each "x_378" 
                                                      (get-field "types" (identifier "x_371"))
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "dst_ref_376")
                                                          (write-bytes
                                                            (let "leb128_sz_379" 
                                                              (make-vec (string-length (identifier "x_378")))
                                                              (let "leb128_ptr_380" 
                                                                (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_376")))
                                                                (seq
                                                                  (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_380")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_380"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_379"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_379"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_379"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_379") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_379")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_379")) (u32 0))) 
                                                                    (nop)) 
                                                                  (unsafe-nth (u8 0) (identifier "leb128_ptr_380"))))) 
                                                            (bytes-of-string (identifier "x_378")))) 
                                                        (set-vec (u8 0) (identifier "n_ref_377") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_377")))))) 
                                                    (unsafe-nth (u8 0) (identifier "dst_ref_376")))))) 
                                            (write-u8 (identifier "srec_dst_381") (u8-of-bool (get-field "count" (identifier "x_371")))))
                                          (write-u8 (identifier "srec_dst_382") (u8-of-bool (get-field "first" (identifier "x_371"))))) 
                                        (write-u8 (identifier "srec_dst_383") (u8-of-bool (get-field "last" (identifier "x_371"))))) 
                                      (write-u8 (identifier "srec_dst_384") (u8-of-bool (get-field "min" (identifier "x_371"))))) 
                                    (write-u8 (identifier "srec_dst_385") (u8-of-bool (get-field "max" (identifier "x_371"))))) 
                                  (write-u8 (identifier "srec_dst_386") (u8-of-bool (get-field "sum" (identifier "x_371"))))) 
                                (write-u8 (identifier "srec_dst_387") (u8-of-bool (get-field "avg" (identifier "x_371")))))
                              (let "dst_ref_391"
                                (make-vec
                                  (let "leb128_sz_389" (make-vec (cardinality (get-field "percentiles" (identifier "x_371"))))
                                    (let "leb128_ptr_390" (make-vec (identifier "srec_dst_388"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_390")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_390"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_389"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_389"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_389"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_389") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_389")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_389")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_390"))))))
                                (let "n_ref_392" (make-vec (i32 0))
                                  (seq
                                    (for-each "x_393" (get-field "percentiles" (identifier "x_371"))
                                      (seq (set-vec (u8 0) (identifier "dst_ref_391") (write-u64 little-endian (unsafe-nth (u8 0) (identifier "dst_ref_391")) (u64-of-float (identifier "x_393"))))
                                        (set-vec (u8 0) (identifier "n_ref_392") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_392")))))) 
                                    (unsafe-nth (u8 0) (identifier "dst_ref_391"))))))
                            (let "dst_ref_397"
                              (make-vec
                                (let "leb128_sz_395" (make-vec (cardinality (get-field "tops" (identifier "x_371"))))
                                  (let "leb128_ptr_396" (make-vec (identifier "srec_dst_394"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_396")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_396"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_395") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_395")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_395")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_396"))))))
                              (let "n_ref_398" (make-vec (i32 0))
                                (seq
                                  (for-each "x_399" (get-field "tops" (identifier "x_371"))
                                    (seq (set-vec (u8 0) (identifier "dst_ref_397") (apply (identifier "top-to-row-binary") (identifier "x_399") (unsafe-nth (u8 0) (identifier "dst_ref_397"))))
                                      (set-vec (u8 0) (identifier "n_ref_398") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_398")))))) 
                                  (unsafe-nth (u8 0) (identifier "dst_ref_397"))))))) 
                        (set-vec (u8 0) (identifier "n_ref_370") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_370")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_369"))))))
            (let "dst_ref_403"
              (make-vec
                (let "leb128_sz_401" (make-vec (cardinality (get-field "group-by" (param 0))))
                  (let "leb128_ptr_402" (make-vec (identifier "srec_dst_400"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_402")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_402"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_401"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_401"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_401"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_401") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_401")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_401")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_402"))))))
              (let "n_ref_404" (make-vec (i32 0))
                (seq
                  (for-each "x_405" (get-field "group-by" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_403") (apply (ext-identifier field_name to-row-binary) (identifier "x_405") (unsafe-nth (u8 0) (identifier "dst_ref_403"))))
                      (set-vec (u8 0) (identifier "n_ref_404") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_404")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_403")))))) 
          (write-u64 little-endian (identifier "srec_dst_406") (u64-of-float (get-field "duration" (param 0))))) 
        (write-u64 little-endian (identifier "srec_dst_407") (u64-of-float (get-field "max-lateness" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::pivot::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::pivot::t &,Pointer &)> fun15 { [&](::dessser::gen::pivot::t p_0, Pointer p_1) {
    auto fun16 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_17 { p_0.from };
    Pointer id_18 { fun16(id_17, p_1) };
    Pointer let_res_19;
    {
      Pointer srec_dst_358 { id_18 };
      Arr<dessser::gen::simple_filter::t_ext> id_20 { p_0.where };
      uint32_t id_21 { id_20.size() };
      Vec<1, uint32_t> id_22 {  id_21  };
      Pointer let_res_23;
      {
        Vec<1, uint32_t> leb128_sz_359 { id_22 };
        Vec<1, Pointer> id_24 {  srec_dst_358  };
        Pointer let_res_25;
        {
          Vec<1, Pointer> leb128_ptr_360 { id_24 };
          bool while_flag_26 { true };
          do {
            uint8_t id_27 { 0 };
            uint8_t id_28 { 0 };
            Pointer id_29 { leb128_ptr_360[id_28] };
            uint32_t id_30 { 128U };
            uint8_t id_31 { 0 };
            uint32_t id_32 { leb128_sz_359[id_31] };
            bool id_33 { bool(id_30 > id_32) };
            uint8_t choose_res_34;
            if (id_33) {
              uint8_t id_35 { 0 };
              uint32_t id_36 { leb128_sz_359[id_35] };
              uint8_t id_37 { uint8_t(id_36) };
              choose_res_34 = id_37;
            } else {
              uint8_t id_38 { 0 };
              uint32_t id_39 { leb128_sz_359[id_38] };
              uint8_t id_40 { uint8_t(id_39) };
              uint8_t id_41 { 128 };
              uint8_t id_42 { uint8_t(id_40 | id_41) };
              choose_res_34 = id_42;
            }
            Pointer id_43 { id_29.writeU8(choose_res_34) };
            Void id_44 { ((void)(leb128_ptr_360[id_27] = id_43), ::dessser::Void()) };
            (void)id_44;
            uint8_t id_45 { 0 };
            uint8_t id_46 { 0 };
            uint32_t id_47 { leb128_sz_359[id_46] };
            uint8_t id_48 { 7 };
            uint32_t id_49 { uint32_t(id_47 >> id_48) };
            Void id_50 { ((void)(leb128_sz_359[id_45] = id_49), ::dessser::Void()) };
            (void)id_50;
            uint8_t id_51 { 0 };
            uint32_t id_52 { leb128_sz_359[id_51] };
            uint32_t id_53 { 0U };
            bool id_54 { bool(id_52 > id_53) };
            while_flag_26 = id_54;
            if (while_flag_26) {
              (void)::dessser::Void();
            }
          } while (while_flag_26);
          (void)::dessser::Void();
          uint8_t id_55 { 0 };
          Pointer id_56 { leb128_ptr_360[id_55] };
          let_res_25 = id_56;
        }
        let_res_23 = let_res_25;
      }
      Vec<1, Pointer> id_57 {  let_res_23  };
      Pointer let_res_58;
      {
        Vec<1, Pointer> dst_ref_361 { id_57 };
        int32_t id_59 { 0L };
        Vec<1, int32_t> id_60 {  id_59  };
        Pointer let_res_61;
        {
          Vec<1, int32_t> n_ref_362 { id_60 };
          Arr<dessser::gen::simple_filter::t_ext> id_62 { p_0.where };
          for (dessser::gen::simple_filter::t_ext &x_363 : id_62) {
            uint8_t id_63 { 0 };
            auto fun64 { dessser::gen::simple_filter::to_row_binary };
            uint8_t id_65 { 0 };
            Pointer id_66 { dst_ref_361[id_65] };
            Pointer id_67 { fun64(x_363, id_66) };
            Void id_68 { ((void)(dst_ref_361[id_63] = id_67), ::dessser::Void()) };
            (void)id_68;
            uint8_t id_69 { 0 };
            int32_t id_70 { 1L };
            uint8_t id_71 { 0 };
            int32_t id_72 { n_ref_362[id_71] };
            int32_t id_73 { int32_t(id_70 + id_72) };
            Void id_74 { ((void)(n_ref_362[id_69] = id_73), ::dessser::Void()) };
            (void)id_74;
            (void)id_74;
          }
          (void)::dessser::Void();
          uint8_t id_75 { 0 };
          Pointer id_76 { dst_ref_361[id_75] };
          let_res_61 = id_76;
        }
        let_res_58 = let_res_61;
      }
      let_res_19 = let_res_58;
    }
    Pointer let_res_77;
    {
      Pointer srec_dst_364 { let_res_19 };
      auto fun78 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_79 { p_0.type_field };
      Pointer id_80 { fun78(id_79, srec_dst_364) };
      let_res_77 = id_80;
    }
    Pointer let_res_81;
    {
      Pointer srec_dst_365 { let_res_77 };
      auto fun82 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_83 { p_0.value_field };
      Pointer id_84 { fun82(id_83, srec_dst_365) };
      let_res_81 = id_84;
    }
    Pointer let_res_85;
    {
      Pointer srec_dst_366 { let_res_81 };
      Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_86 { p_0.fields };
      uint32_t id_87 { id_86.size() };
      Vec<1, uint32_t> id_88 {  id_87  };
      Pointer let_res_89;
      {
        Vec<1, uint32_t> leb128_sz_367 { id_88 };
        Vec<1, Pointer> id_90 {  srec_dst_366  };
        Pointer let_res_91;
        {
          Vec<1, Pointer> leb128_ptr_368 { id_90 };
          bool while_flag_92 { true };
          do {
            uint8_t id_93 { 0 };
            uint8_t id_94 { 0 };
            Pointer id_95 { leb128_ptr_368[id_94] };
            uint32_t id_96 { 128U };
            uint8_t id_97 { 0 };
            uint32_t id_98 { leb128_sz_367[id_97] };
            bool id_99 { bool(id_96 > id_98) };
            uint8_t choose_res_100;
            if (id_99) {
              uint8_t id_101 { 0 };
              uint32_t id_102 { leb128_sz_367[id_101] };
              uint8_t id_103 { uint8_t(id_102) };
              choose_res_100 = id_103;
            } else {
              uint8_t id_104 { 0 };
              uint32_t id_105 { leb128_sz_367[id_104] };
              uint8_t id_106 { uint8_t(id_105) };
              uint8_t id_107 { 128 };
              uint8_t id_108 { uint8_t(id_106 | id_107) };
              choose_res_100 = id_108;
            }
            Pointer id_109 { id_95.writeU8(choose_res_100) };
            Void id_110 { ((void)(leb128_ptr_368[id_93] = id_109), ::dessser::Void()) };
            (void)id_110;
            uint8_t id_111 { 0 };
            uint8_t id_112 { 0 };
            uint32_t id_113 { leb128_sz_367[id_112] };
            uint8_t id_114 { 7 };
            uint32_t id_115 { uint32_t(id_113 >> id_114) };
            Void id_116 { ((void)(leb128_sz_367[id_111] = id_115), ::dessser::Void()) };
            (void)id_116;
            uint8_t id_117 { 0 };
            uint32_t id_118 { leb128_sz_367[id_117] };
            uint32_t id_119 { 0U };
            bool id_120 { bool(id_118 > id_119) };
            while_flag_92 = id_120;
            if (while_flag_92) {
              (void)::dessser::Void();
            }
          } while (while_flag_92);
          (void)::dessser::Void();
          uint8_t id_121 { 0 };
          Pointer id_122 { leb128_ptr_368[id_121] };
          let_res_91 = id_122;
        }
        let_res_89 = let_res_91;
      }
      Vec<1, Pointer> id_123 {  let_res_89  };
      Pointer let_res_124;
      {
        Vec<1, Pointer> dst_ref_369 { id_123 };
        int32_t id_125 { 0L };
        Vec<1, int32_t> id_126 {  id_125  };
        Pointer let_res_127;
        {
          Vec<1, int32_t> n_ref_370 { id_126 };
          Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_128 { p_0.fields };
          for (::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 &x_371 : id_128) {
            uint8_t id_129 { 0 };
            uint8_t id_130 { 0 };
            Pointer id_131 { dst_ref_369[id_130] };
            Pointer let_res_132;
            {
              Pointer srec_dst_372 { id_131 };
              auto fun133 { dessser::gen::field_name::to_row_binary };
              dessser::gen::field_name::t_ext id_134 { x_371.name };
              Pointer id_135 { fun133(id_134, srec_dst_372) };
              let_res_132 = id_135;
            }
            Pointer let_res_136;
            {
              Pointer srec_dst_373 { let_res_132 };
              Arr<std::string> id_137 { x_371.types };
              uint32_t id_138 { id_137.size() };
              Vec<1, uint32_t> id_139 {  id_138  };
              Pointer let_res_140;
              {
                Vec<1, uint32_t> leb128_sz_374 { id_139 };
                Vec<1, Pointer> id_141 {  srec_dst_373  };
                Pointer let_res_142;
                {
                  Vec<1, Pointer> leb128_ptr_375 { id_141 };
                  bool while_flag_143 { true };
                  do {
                    uint8_t id_144 { 0 };
                    uint8_t id_145 { 0 };
                    Pointer id_146 { leb128_ptr_375[id_145] };
                    uint32_t id_147 { 128U };
                    uint8_t id_148 { 0 };
                    uint32_t id_149 { leb128_sz_374[id_148] };
                    bool id_150 { bool(id_147 > id_149) };
                    uint8_t choose_res_151;
                    if (id_150) {
                      uint8_t id_152 { 0 };
                      uint32_t id_153 { leb128_sz_374[id_152] };
                      uint8_t id_154 { uint8_t(id_153) };
                      choose_res_151 = id_154;
                    } else {
                      uint8_t id_155 { 0 };
                      uint32_t id_156 { leb128_sz_374[id_155] };
                      uint8_t id_157 { uint8_t(id_156) };
                      uint8_t id_158 { 128 };
                      uint8_t id_159 { uint8_t(id_157 | id_158) };
                      choose_res_151 = id_159;
                    }
                    Pointer id_160 { id_146.writeU8(choose_res_151) };
                    Void id_161 { ((void)(leb128_ptr_375[id_144] = id_160), ::dessser::Void()) };
                    (void)id_161;
                    uint8_t id_162 { 0 };
                    uint8_t id_163 { 0 };
                    uint32_t id_164 { leb128_sz_374[id_163] };
                    uint8_t id_165 { 7 };
                    uint32_t id_166 { uint32_t(id_164 >> id_165) };
                    Void id_167 { ((void)(leb128_sz_374[id_162] = id_166), ::dessser::Void()) };
                    (void)id_167;
                    uint8_t id_168 { 0 };
                    uint32_t id_169 { leb128_sz_374[id_168] };
                    uint32_t id_170 { 0U };
                    bool id_171 { bool(id_169 > id_170) };
                    while_flag_143 = id_171;
                    if (while_flag_143) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_143);
                  (void)::dessser::Void();
                  uint8_t id_172 { 0 };
                  Pointer id_173 { leb128_ptr_375[id_172] };
                  let_res_142 = id_173;
                }
                let_res_140 = let_res_142;
              }
              Vec<1, Pointer> id_174 {  let_res_140  };
              Pointer let_res_175;
              {
                Vec<1, Pointer> dst_ref_376 { id_174 };
                int32_t id_176 { 0L };
                Vec<1, int32_t> id_177 {  id_176  };
                Pointer let_res_178;
                {
                  Vec<1, int32_t> n_ref_377 { id_177 };
                  Arr<std::string> id_179 { x_371.types };
                  for (std::string const &x_378 : id_179) {
                    uint8_t id_180 { 0 };
                    uint32_t id_181 { (uint32_t)x_378.size() };
                    Vec<1, uint32_t> id_182 {  id_181  };
                    Pointer let_res_183;
                    {
                      Vec<1, uint32_t> leb128_sz_379 { id_182 };
                      uint8_t id_184 { 0 };
                      Pointer id_185 { dst_ref_376[id_184] };
                      Vec<1, Pointer> id_186 {  id_185  };
                      Pointer let_res_187;
                      {
                        Vec<1, Pointer> leb128_ptr_380 { id_186 };
                        bool while_flag_188 { true };
                        do {
                          uint8_t id_189 { 0 };
                          uint8_t id_190 { 0 };
                          Pointer id_191 { leb128_ptr_380[id_190] };
                          uint32_t id_192 { 128U };
                          uint8_t id_193 { 0 };
                          uint32_t id_194 { leb128_sz_379[id_193] };
                          bool id_195 { bool(id_192 > id_194) };
                          uint8_t choose_res_196;
                          if (id_195) {
                            uint8_t id_197 { 0 };
                            uint32_t id_198 { leb128_sz_379[id_197] };
                            uint8_t id_199 { uint8_t(id_198) };
                            choose_res_196 = id_199;
                          } else {
                            uint8_t id_200 { 0 };
                            uint32_t id_201 { leb128_sz_379[id_200] };
                            uint8_t id_202 { uint8_t(id_201) };
                            uint8_t id_203 { 128 };
                            uint8_t id_204 { uint8_t(id_202 | id_203) };
                            choose_res_196 = id_204;
                          }
                          Pointer id_205 { id_191.writeU8(choose_res_196) };
                          Void id_206 { ((void)(leb128_ptr_380[id_189] = id_205), ::dessser::Void()) };
                          (void)id_206;
                          uint8_t id_207 { 0 };
                          uint8_t id_208 { 0 };
                          uint32_t id_209 { leb128_sz_379[id_208] };
                          uint8_t id_210 { 7 };
                          uint32_t id_211 { uint32_t(id_209 >> id_210) };
                          Void id_212 { ((void)(leb128_sz_379[id_207] = id_211), ::dessser::Void()) };
                          (void)id_212;
                          uint8_t id_213 { 0 };
                          uint32_t id_214 { leb128_sz_379[id_213] };
                          uint32_t id_215 { 0U };
                          bool id_216 { bool(id_214 > id_215) };
                          while_flag_188 = id_216;
                          if (while_flag_188) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_188);
                        (void)::dessser::Void();
                        uint8_t id_217 { 0 };
                        Pointer id_218 { leb128_ptr_380[id_217] };
                        let_res_187 = id_218;
                      }
                      let_res_183 = let_res_187;
                    }
                    Bytes id_219 { x_378 };
                    Pointer id_220 { let_res_183.writeBytes(id_219) };
                    Void id_221 { ((void)(dst_ref_376[id_180] = id_220), ::dessser::Void()) };
                    (void)id_221;
                    uint8_t id_222 { 0 };
                    int32_t id_223 { 1L };
                    uint8_t id_224 { 0 };
                    int32_t id_225 { n_ref_377[id_224] };
                    int32_t id_226 { int32_t(id_223 + id_225) };
                    Void id_227 { ((void)(n_ref_377[id_222] = id_226), ::dessser::Void()) };
                    (void)id_227;
                    (void)id_227;
                  }
                  (void)::dessser::Void();
                  uint8_t id_228 { 0 };
                  Pointer id_229 { dst_ref_376[id_228] };
                  let_res_178 = id_229;
                }
                let_res_175 = let_res_178;
              }
              let_res_136 = let_res_175;
            }
            Pointer let_res_230;
            {
              Pointer srec_dst_381 { let_res_136 };
              bool id_231 { x_371.count };
              uint8_t id_232 { uint8_t(id_231) };
              Pointer id_233 { srec_dst_381.writeU8(id_232) };
              let_res_230 = id_233;
            }
            Pointer let_res_234;
            {
              Pointer srec_dst_382 { let_res_230 };
              bool id_235 { x_371.first };
              uint8_t id_236 { uint8_t(id_235) };
              Pointer id_237 { srec_dst_382.writeU8(id_236) };
              let_res_234 = id_237;
            }
            Pointer let_res_238;
            {
              Pointer srec_dst_383 { let_res_234 };
              bool id_239 { x_371.last };
              uint8_t id_240 { uint8_t(id_239) };
              Pointer id_241 { srec_dst_383.writeU8(id_240) };
              let_res_238 = id_241;
            }
            Pointer let_res_242;
            {
              Pointer srec_dst_384 { let_res_238 };
              bool id_243 { x_371.min };
              uint8_t id_244 { uint8_t(id_243) };
              Pointer id_245 { srec_dst_384.writeU8(id_244) };
              let_res_242 = id_245;
            }
            Pointer let_res_246;
            {
              Pointer srec_dst_385 { let_res_242 };
              bool id_247 { x_371.max };
              uint8_t id_248 { uint8_t(id_247) };
              Pointer id_249 { srec_dst_385.writeU8(id_248) };
              let_res_246 = id_249;
            }
            Pointer let_res_250;
            {
              Pointer srec_dst_386 { let_res_246 };
              bool id_251 { x_371.sum };
              uint8_t id_252 { uint8_t(id_251) };
              Pointer id_253 { srec_dst_386.writeU8(id_252) };
              let_res_250 = id_253;
            }
            Pointer let_res_254;
            {
              Pointer srec_dst_387 { let_res_250 };
              bool id_255 { x_371.avg };
              uint8_t id_256 { uint8_t(id_255) };
              Pointer id_257 { srec_dst_387.writeU8(id_256) };
              let_res_254 = id_257;
            }
            Pointer let_res_258;
            {
              Pointer srec_dst_388 { let_res_254 };
              Arr<double> id_259 { x_371.percentiles };
              uint32_t id_260 { id_259.size() };
              Vec<1, uint32_t> id_261 {  id_260  };
              Pointer let_res_262;
              {
                Vec<1, uint32_t> leb128_sz_389 { id_261 };
                Vec<1, Pointer> id_263 {  srec_dst_388  };
                Pointer let_res_264;
                {
                  Vec<1, Pointer> leb128_ptr_390 { id_263 };
                  bool while_flag_265 { true };
                  do {
                    uint8_t id_266 { 0 };
                    uint8_t id_267 { 0 };
                    Pointer id_268 { leb128_ptr_390[id_267] };
                    uint32_t id_269 { 128U };
                    uint8_t id_270 { 0 };
                    uint32_t id_271 { leb128_sz_389[id_270] };
                    bool id_272 { bool(id_269 > id_271) };
                    uint8_t choose_res_273;
                    if (id_272) {
                      uint8_t id_274 { 0 };
                      uint32_t id_275 { leb128_sz_389[id_274] };
                      uint8_t id_276 { uint8_t(id_275) };
                      choose_res_273 = id_276;
                    } else {
                      uint8_t id_277 { 0 };
                      uint32_t id_278 { leb128_sz_389[id_277] };
                      uint8_t id_279 { uint8_t(id_278) };
                      uint8_t id_280 { 128 };
                      uint8_t id_281 { uint8_t(id_279 | id_280) };
                      choose_res_273 = id_281;
                    }
                    Pointer id_282 { id_268.writeU8(choose_res_273) };
                    Void id_283 { ((void)(leb128_ptr_390[id_266] = id_282), ::dessser::Void()) };
                    (void)id_283;
                    uint8_t id_284 { 0 };
                    uint8_t id_285 { 0 };
                    uint32_t id_286 { leb128_sz_389[id_285] };
                    uint8_t id_287 { 7 };
                    uint32_t id_288 { uint32_t(id_286 >> id_287) };
                    Void id_289 { ((void)(leb128_sz_389[id_284] = id_288), ::dessser::Void()) };
                    (void)id_289;
                    uint8_t id_290 { 0 };
                    uint32_t id_291 { leb128_sz_389[id_290] };
                    uint32_t id_292 { 0U };
                    bool id_293 { bool(id_291 > id_292) };
                    while_flag_265 = id_293;
                    if (while_flag_265) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_265);
                  (void)::dessser::Void();
                  uint8_t id_294 { 0 };
                  Pointer id_295 { leb128_ptr_390[id_294] };
                  let_res_264 = id_295;
                }
                let_res_262 = let_res_264;
              }
              Vec<1, Pointer> id_296 {  let_res_262  };
              Pointer let_res_297;
              {
                Vec<1, Pointer> dst_ref_391 { id_296 };
                int32_t id_298 { 0L };
                Vec<1, int32_t> id_299 {  id_298  };
                Pointer let_res_300;
                {
                  Vec<1, int32_t> n_ref_392 { id_299 };
                  Arr<double> id_301 { x_371.percentiles };
                  for (double const x_393 : id_301) {
                    uint8_t id_302 { 0 };
                    uint8_t id_303 { 0 };
                    Pointer id_304 { dst_ref_391[id_303] };
                    uint64_t id_305 { qword_of_float(x_393) };
                    Pointer id_306 { id_304.writeU64Le(id_305) };
                    Void id_307 { ((void)(dst_ref_391[id_302] = id_306), ::dessser::Void()) };
                    (void)id_307;
                    uint8_t id_308 { 0 };
                    int32_t id_309 { 1L };
                    uint8_t id_310 { 0 };
                    int32_t id_311 { n_ref_392[id_310] };
                    int32_t id_312 { int32_t(id_309 + id_311) };
                    Void id_313 { ((void)(n_ref_392[id_308] = id_312), ::dessser::Void()) };
                    (void)id_313;
                    (void)id_313;
                  }
                  (void)::dessser::Void();
                  uint8_t id_314 { 0 };
                  Pointer id_315 { dst_ref_391[id_314] };
                  let_res_300 = id_315;
                }
                let_res_297 = let_res_300;
              }
              let_res_258 = let_res_297;
            }
            Pointer let_res_316;
            {
              Pointer srec_dst_394 { let_res_258 };
              Arr<::dessser::gen::pivot::top> id_317 { x_371.tops };
              uint32_t id_318 { id_317.size() };
              Vec<1, uint32_t> id_319 {  id_318  };
              Pointer let_res_320;
              {
                Vec<1, uint32_t> leb128_sz_395 { id_319 };
                Vec<1, Pointer> id_321 {  srec_dst_394  };
                Pointer let_res_322;
                {
                  Vec<1, Pointer> leb128_ptr_396 { id_321 };
                  bool while_flag_323 { true };
                  do {
                    uint8_t id_324 { 0 };
                    uint8_t id_325 { 0 };
                    Pointer id_326 { leb128_ptr_396[id_325] };
                    uint32_t id_327 { 128U };
                    uint8_t id_328 { 0 };
                    uint32_t id_329 { leb128_sz_395[id_328] };
                    bool id_330 { bool(id_327 > id_329) };
                    uint8_t choose_res_331;
                    if (id_330) {
                      uint8_t id_332 { 0 };
                      uint32_t id_333 { leb128_sz_395[id_332] };
                      uint8_t id_334 { uint8_t(id_333) };
                      choose_res_331 = id_334;
                    } else {
                      uint8_t id_335 { 0 };
                      uint32_t id_336 { leb128_sz_395[id_335] };
                      uint8_t id_337 { uint8_t(id_336) };
                      uint8_t id_338 { 128 };
                      uint8_t id_339 { uint8_t(id_337 | id_338) };
                      choose_res_331 = id_339;
                    }
                    Pointer id_340 { id_326.writeU8(choose_res_331) };
                    Void id_341 { ((void)(leb128_ptr_396[id_324] = id_340), ::dessser::Void()) };
                    (void)id_341;
                    uint8_t id_342 { 0 };
                    uint8_t id_343 { 0 };
                    uint32_t id_344 { leb128_sz_395[id_343] };
                    uint8_t id_345 { 7 };
                    uint32_t id_346 { uint32_t(id_344 >> id_345) };
                    Void id_347 { ((void)(leb128_sz_395[id_342] = id_346), ::dessser::Void()) };
                    (void)id_347;
                    uint8_t id_348 { 0 };
                    uint32_t id_349 { leb128_sz_395[id_348] };
                    uint32_t id_350 { 0U };
                    bool id_351 { bool(id_349 > id_350) };
                    while_flag_323 = id_351;
                    if (while_flag_323) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_323);
                  (void)::dessser::Void();
                  uint8_t id_352 { 0 };
                  Pointer id_353 { leb128_ptr_396[id_352] };
                  let_res_322 = id_353;
                }
                let_res_320 = let_res_322;
              }
              Vec<1, Pointer> id_354 {  let_res_320  };
              Pointer let_res_355;
              {
                Vec<1, Pointer> dst_ref_397 { id_354 };
                int32_t id_356 { 0L };
                Vec<1, int32_t> id_357 {  id_356  };
                Pointer let_res_358;
                {
                  Vec<1, int32_t> n_ref_398 { id_357 };
                  Arr<::dessser::gen::pivot::top> id_359 { x_371.tops };
                  for (::dessser::gen::pivot::top &x_399 : id_359) {
                    uint8_t id_360 { 0 };
                    uint8_t id_361 { 0 };
                    Pointer id_362 { dst_ref_397[id_361] };
                    Pointer id_363 { top_to_row_binary(x_399, id_362) };
                    Void id_364 { ((void)(dst_ref_397[id_360] = id_363), ::dessser::Void()) };
                    (void)id_364;
                    uint8_t id_365 { 0 };
                    int32_t id_366 { 1L };
                    uint8_t id_367 { 0 };
                    int32_t id_368 { n_ref_398[id_367] };
                    int32_t id_369 { int32_t(id_366 + id_368) };
                    Void id_370 { ((void)(n_ref_398[id_365] = id_369), ::dessser::Void()) };
                    (void)id_370;
                    (void)id_370;
                  }
                  (void)::dessser::Void();
                  uint8_t id_371 { 0 };
                  Pointer id_372 { dst_ref_397[id_371] };
                  let_res_358 = id_372;
                }
                let_res_355 = let_res_358;
              }
              let_res_316 = let_res_355;
            }
            Void id_373 { ((void)(dst_ref_369[id_129] = let_res_316), ::dessser::Void()) };
            (void)id_373;
            uint8_t id_374 { 0 };
            int32_t id_375 { 1L };
            uint8_t id_376 { 0 };
            int32_t id_377 { n_ref_370[id_376] };
            int32_t id_378 { int32_t(id_375 + id_377) };
            Void id_379 { ((void)(n_ref_370[id_374] = id_378), ::dessser::Void()) };
            (void)id_379;
            (void)id_379;
          }
          (void)::dessser::Void();
          uint8_t id_380 { 0 };
          Pointer id_381 { dst_ref_369[id_380] };
          let_res_127 = id_381;
        }
        let_res_124 = let_res_127;
      }
      let_res_85 = let_res_124;
    }
    Pointer let_res_382;
    {
      Pointer srec_dst_400 { let_res_85 };
      Arr<dessser::gen::field_name::t_ext> id_383 { p_0.group_by };
      uint32_t id_384 { id_383.size() };
      Vec<1, uint32_t> id_385 {  id_384  };
      Pointer let_res_386;
      {
        Vec<1, uint32_t> leb128_sz_401 { id_385 };
        Vec<1, Pointer> id_387 {  srec_dst_400  };
        Pointer let_res_388;
        {
          Vec<1, Pointer> leb128_ptr_402 { id_387 };
          bool while_flag_389 { true };
          do {
            uint8_t id_390 { 0 };
            uint8_t id_391 { 0 };
            Pointer id_392 { leb128_ptr_402[id_391] };
            uint32_t id_393 { 128U };
            uint8_t id_394 { 0 };
            uint32_t id_395 { leb128_sz_401[id_394] };
            bool id_396 { bool(id_393 > id_395) };
            uint8_t choose_res_397;
            if (id_396) {
              uint8_t id_398 { 0 };
              uint32_t id_399 { leb128_sz_401[id_398] };
              uint8_t id_400 { uint8_t(id_399) };
              choose_res_397 = id_400;
            } else {
              uint8_t id_401 { 0 };
              uint32_t id_402 { leb128_sz_401[id_401] };
              uint8_t id_403 { uint8_t(id_402) };
              uint8_t id_404 { 128 };
              uint8_t id_405 { uint8_t(id_403 | id_404) };
              choose_res_397 = id_405;
            }
            Pointer id_406 { id_392.writeU8(choose_res_397) };
            Void id_407 { ((void)(leb128_ptr_402[id_390] = id_406), ::dessser::Void()) };
            (void)id_407;
            uint8_t id_408 { 0 };
            uint8_t id_409 { 0 };
            uint32_t id_410 { leb128_sz_401[id_409] };
            uint8_t id_411 { 7 };
            uint32_t id_412 { uint32_t(id_410 >> id_411) };
            Void id_413 { ((void)(leb128_sz_401[id_408] = id_412), ::dessser::Void()) };
            (void)id_413;
            uint8_t id_414 { 0 };
            uint32_t id_415 { leb128_sz_401[id_414] };
            uint32_t id_416 { 0U };
            bool id_417 { bool(id_415 > id_416) };
            while_flag_389 = id_417;
            if (while_flag_389) {
              (void)::dessser::Void();
            }
          } while (while_flag_389);
          (void)::dessser::Void();
          uint8_t id_418 { 0 };
          Pointer id_419 { leb128_ptr_402[id_418] };
          let_res_388 = id_419;
        }
        let_res_386 = let_res_388;
      }
      Vec<1, Pointer> id_420 {  let_res_386  };
      Pointer let_res_421;
      {
        Vec<1, Pointer> dst_ref_403 { id_420 };
        int32_t id_422 { 0L };
        Vec<1, int32_t> id_423 {  id_422  };
        Pointer let_res_424;
        {
          Vec<1, int32_t> n_ref_404 { id_423 };
          Arr<dessser::gen::field_name::t_ext> id_425 { p_0.group_by };
          for (dessser::gen::field_name::t_ext &x_405 : id_425) {
            uint8_t id_426 { 0 };
            auto fun427 { dessser::gen::field_name::to_row_binary };
            uint8_t id_428 { 0 };
            Pointer id_429 { dst_ref_403[id_428] };
            Pointer id_430 { fun427(x_405, id_429) };
            Void id_431 { ((void)(dst_ref_403[id_426] = id_430), ::dessser::Void()) };
            (void)id_431;
            uint8_t id_432 { 0 };
            int32_t id_433 { 1L };
            uint8_t id_434 { 0 };
            int32_t id_435 { n_ref_404[id_434] };
            int32_t id_436 { int32_t(id_433 + id_435) };
            Void id_437 { ((void)(n_ref_404[id_432] = id_436), ::dessser::Void()) };
            (void)id_437;
            (void)id_437;
          }
          (void)::dessser::Void();
          uint8_t id_438 { 0 };
          Pointer id_439 { dst_ref_403[id_438] };
          let_res_424 = id_439;
        }
        let_res_421 = let_res_424;
      }
      let_res_382 = let_res_421;
    }
    Pointer let_res_440;
    {
      Pointer srec_dst_406 { let_res_382 };
      double id_441 { p_0.duration };
      uint64_t id_442 { qword_of_float(id_441) };
      Pointer id_443 { srec_dst_406.writeU64Le(id_442) };
      let_res_440 = id_443;
    }
    Pointer let_res_444;
    {
      Pointer srec_dst_407 { let_res_440 };
      double id_445 { p_0.max_lateness };
      uint64_t id_446 { qword_of_float(id_445) };
      Pointer id_447 { srec_dst_407.writeU64Le(id_446) };
      let_res_444 = id_447;
    }
    return let_res_444;
  }
   };
  return fun15;
}
std::function<Pointer(::dessser::gen::pivot::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{n: U16; by: $field_name?}") (if (is-null (get-field "by" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier field_name sersize-of-row-binary) (force (get-field "by" (param 0))))) (size 1))))
 */
static std::function<Size(::dessser::gen::pivot::top &)> top_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::pivot::top &)> fun448 { [&](::dessser::gen::pivot::top p_0) {
    std::optional<dessser::gen::field_name::t_ext> id_449 { p_0.by };
    bool id_450 { !(id_449.has_value ()) };
    Size choose_res_451;
    if (id_450) {
      Size id_452 { 3UL };
      choose_res_451 = id_452;
    } else {
      Size id_453 { 2UL };
      auto fun454 { dessser::gen::field_name::sersize_of_row_binary };
      std::optional<dessser::gen::field_name::t_ext> id_455 { p_0.by };
      dessser::gen::field_name::t_ext id_456 { id_455.value() };
      Size id_457 { fun454(id_456) };
      Size id_458 { Size(id_453 + id_457) };
      Size id_459 { 1UL };
      Size id_460 { Size(id_458 + id_459) };
      choose_res_451 = id_460;
    }
    return choose_res_451;
  }
   };
  return fun448;
}
std::function<Size(::dessser::gen::pivot::top &)> top_sersize_of_row_binary(top_sersize_of_row_binary_init());

/* 
    (fun ("{from: $fq_name; where: $simple_filter[]; type-field: $field_name; value-field: $field_name; fields: {name: $field_name; types: STRING[]; count: BOOL; first: BOOL; last: BOOL; min: BOOL; max: BOOL; sum: BOOL; avg: BOOL; percentiles: FLOAT[]; tops: (top AS {n: U16; by: $field_name?})[]}[]; group-by: $field_name[]; duration: FLOAT; max-lateness: FLOAT}")
      (add
        (add
          (let "sz_350"
            (let "sz_319"
              (let "sz_318"
                (let "sz_317"
                  (let "sz_312" (apply (ext-identifier fq_name sersize-of-row-binary) (get-field "from" (param 0)))
                    (let "sz_ref_315"
                      (make-vec
                        (add (identifier "sz_312")
                          (let "n_ref_313" (make-vec (cardinality (get-field "where" (param 0))))
                            (let "lebsz_ref_314" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_313")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_314")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_314") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_314")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_314"))))))))
                      (seq
                        (let "repeat_n_316" (make-vec (i32 0))
                          (while (gt (to-i32 (cardinality (get-field "where" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_316")))
                            (seq
                              (set-vec (u8 0) (identifier "sz_ref_315")
                                (add (unsafe-nth (u8 0) (identifier "sz_ref_315"))
                                  (apply (ext-identifier simple_filter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_316")) (get-field "where" (param 0))))))
                              (set-vec (u8 0) (identifier "repeat_n_316") (add (unsafe-nth (u8 0) (identifier "repeat_n_316")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "sz_ref_315"))))) 
                  (add (identifier "sz_317") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "type-field" (param 0)))))
                (add (identifier "sz_318") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "value-field" (param 0)))))
              (let "sz_ref_322"
                (make-vec
                  (add (identifier "sz_319")
                    (let "n_ref_320" (make-vec (cardinality (get-field "fields" (param 0))))
                      (let "lebsz_ref_321" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_320")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_321")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_321") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_321")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_321"))))))))
                (seq
                  (let "repeat_n_323" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "fields" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_323")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_322")
                          (let "sz_345"
                            (let "sz_340"
                              (add
                                (add
                                  (add
                                    (add
                                      (add
                                        (add
                                          (add
                                            (let "sz_325"
                                              (let "sz_324" (unsafe-nth (u8 0) (identifier "sz_ref_322"))
                                                (add (identifier "sz_324")
                                                  (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0)))))))
                                              (let "sz_ref_328"
                                                (make-vec
                                                  (add (identifier "sz_325")
                                                    (let "n_ref_326" 
                                                      (make-vec (cardinality (get-field "types" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0))))))
                                                      (let "lebsz_ref_327" 
                                                        (make-vec (u32 1))
                                                        (seq
                                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_326")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_327")) (u8 7)))
                                                            (set-vec (u8 0) (identifier "lebsz_ref_327") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_327")) (u32 1))))
                                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_327"))))))))
                                                (seq
                                                  (let "repeat_n_329" 
                                                    (make-vec (i32 0))
                                                    (while
                                                      (gt (to-i32 (cardinality (get-field "types" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0))))))
                                                        (unsafe-nth (u8 0) (identifier "repeat_n_329")))
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "sz_ref_328")
                                                          (add (unsafe-nth (u8 0) (identifier "sz_ref_328"))
                                                            (let "wlen_330"
                                                              (string-length
                                                                (unsafe-nth 
                                                                  (unsafe-nth (u8 0) (identifier "repeat_n_329")) 
                                                                  (get-field "types" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0))))))
                                                              (add
                                                                (let "n_ref_331" 
                                                                  (make-vec (identifier "wlen_330"))
                                                                  (let "lebsz_ref_332" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_331")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_332")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_332") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_332")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_332")))))) 
                                                                (size-of-u32 (identifier "wlen_330")))))) 
                                                        (set-vec (u8 0) (identifier "repeat_n_329") (add (unsafe-nth (u8 0) (identifier "repeat_n_329")) (i32 1)))))) 
                                                  (unsafe-nth (u8 0) (identifier "sz_ref_328"))))) 
                                            (size 1)) (size 1)) (size 1)) 
                                      (size 1)) (size 1)) (size 1)) (size 1))
                              (let "sz_ref_343"
                                (make-vec
                                  (add (identifier "sz_340")
                                    (let "n_ref_341" (make-vec (cardinality (get-field "percentiles" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0))))))
                                      (let "lebsz_ref_342" (make-vec (u32 1))
                                        (seq
                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_341")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_342")) (u8 7)))
                                            (set-vec (u8 0) (identifier "lebsz_ref_342") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_342")) (u32 1)))) 
                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_342"))))))))
                                (seq
                                  (let "repeat_n_344" (make-vec (i32 0))
                                    (while
                                      (gt (to-i32 (cardinality (get-field "percentiles" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0))))))
                                        (unsafe-nth (u8 0) (identifier "repeat_n_344")))
                                      (seq (set-vec (u8 0) (identifier "sz_ref_343") (add (unsafe-nth (u8 0) (identifier "sz_ref_343")) (size 8)))
                                        (set-vec (u8 0) (identifier "repeat_n_344") (add (unsafe-nth (u8 0) (identifier "repeat_n_344")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "sz_ref_343")))))
                            (let "sz_ref_348"
                              (make-vec
                                (add (identifier "sz_345")
                                  (let "n_ref_346" (make-vec (cardinality (get-field "tops" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0))))))
                                    (let "lebsz_ref_347" (make-vec (u32 1))
                                      (seq
                                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_346")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_347")) (u8 7)))
                                          (set-vec (u8 0) (identifier "lebsz_ref_347") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_347")) (u32 1)))) 
                                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_347"))))))))
                              (seq
                                (let "repeat_n_349" (make-vec (i32 0))
                                  (while (gt (to-i32 (cardinality (get-field "tops" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_349")))
                                    (seq
                                      (set-vec (u8 0) (identifier "sz_ref_348")
                                        (add (unsafe-nth (u8 0) (identifier "sz_ref_348"))
                                          (apply (identifier "top-sersize-of-row-binary")
                                            (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_349")) (get-field "tops" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-field "fields" (param 0))))))))
                                      (set-vec (u8 0) (identifier "repeat_n_349") (add (unsafe-nth (u8 0) (identifier "repeat_n_349")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "sz_ref_348")))))) 
                        (set-vec (u8 0) (identifier "repeat_n_323") (add (unsafe-nth (u8 0) (identifier "repeat_n_323")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_322")))))
            (let "sz_ref_353"
              (make-vec
                (add (identifier "sz_350")
                  (let "n_ref_351" (make-vec (cardinality (get-field "group-by" (param 0))))
                    (let "lebsz_ref_352" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_351")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_352")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_352") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_352")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_352"))))))))
              (seq
                (let "repeat_n_354" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "group-by" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_354")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_353")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_353")) (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_354")) (get-field "group-by" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_354") (add (unsafe-nth (u8 0) (identifier "repeat_n_354")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_353"))))) (size 8)) 
        (size 8)))
 */
static std::function<Size(::dessser::gen::pivot::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::pivot::t &)> fun461 { [&](::dessser::gen::pivot::t p_0) {
    auto fun462 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_463 { p_0.from };
    Size id_464 { fun462(id_463) };
    Size let_res_465;
    {
      Size sz_312 { id_464 };
      Arr<dessser::gen::simple_filter::t_ext> id_466 { p_0.where };
      uint32_t id_467 { id_466.size() };
      Vec<1, uint32_t> id_468 {  id_467  };
      Size let_res_469;
      {
        Vec<1, uint32_t> n_ref_313 { id_468 };
        uint32_t id_470 { 1U };
        Vec<1, uint32_t> id_471 {  id_470  };
        Size let_res_472;
        {
          Vec<1, uint32_t> lebsz_ref_314 { id_471 };
          bool while_flag_473 { true };
          do {
            uint8_t id_474 { 0 };
            uint32_t id_475 { n_ref_313[id_474] };
            uint8_t id_476 { 0 };
            uint32_t id_477 { lebsz_ref_314[id_476] };
            uint8_t id_478 { 7 };
            uint32_t id_479 { uint32_t(id_477 << id_478) };
            bool id_480 { bool(id_475 >= id_479) };
            while_flag_473 = id_480;
            if (while_flag_473) {
              uint8_t id_481 { 0 };
              uint8_t id_482 { 0 };
              uint32_t id_483 { lebsz_ref_314[id_482] };
              uint32_t id_484 { 1U };
              uint32_t id_485 { uint32_t(id_483 + id_484) };
              Void id_486 { ((void)(lebsz_ref_314[id_481] = id_485), ::dessser::Void()) };
              (void)id_486;
            }
          } while (while_flag_473);
          (void)::dessser::Void();
          uint8_t id_487 { 0 };
          uint32_t id_488 { lebsz_ref_314[id_487] };
          Size id_489 { Size(id_488) };
          let_res_472 = id_489;
        }
        let_res_469 = let_res_472;
      }
      Size id_490 { Size(sz_312 + let_res_469) };
      Vec<1, Size> id_491 {  id_490  };
      Size let_res_492;
      {
        Vec<1, Size> sz_ref_315 { id_491 };
        int32_t id_493 { 0L };
        Vec<1, int32_t> id_494 {  id_493  };
        {
          Vec<1, int32_t> repeat_n_316 { id_494 };
          bool while_flag_495 { true };
          do {
            Arr<dessser::gen::simple_filter::t_ext> id_496 { p_0.where };
            uint32_t id_497 { id_496.size() };
            int32_t id_498 { int32_t(id_497) };
            uint8_t id_499 { 0 };
            int32_t id_500 { repeat_n_316[id_499] };
            bool id_501 { bool(id_498 > id_500) };
            while_flag_495 = id_501;
            if (while_flag_495) {
              uint8_t id_502 { 0 };
              uint8_t id_503 { 0 };
              Size id_504 { sz_ref_315[id_503] };
              auto fun505 { dessser::gen::simple_filter::sersize_of_row_binary };
              uint8_t id_506 { 0 };
              int32_t id_507 { repeat_n_316[id_506] };
              Arr<dessser::gen::simple_filter::t_ext> id_508 { p_0.where };
              dessser::gen::simple_filter::t_ext id_509 { id_508[id_507] };
              Size id_510 { fun505(id_509) };
              Size id_511 { Size(id_504 + id_510) };
              Void id_512 { ((void)(sz_ref_315[id_502] = id_511), ::dessser::Void()) };
              (void)id_512;
              uint8_t id_513 { 0 };
              uint8_t id_514 { 0 };
              int32_t id_515 { repeat_n_316[id_514] };
              int32_t id_516 { 1L };
              int32_t id_517 { int32_t(id_515 + id_516) };
              Void id_518 { ((void)(repeat_n_316[id_513] = id_517), ::dessser::Void()) };
              (void)id_518;
              (void)id_518;
            }
          } while (while_flag_495);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_519 { 0 };
        Size id_520 { sz_ref_315[id_519] };
        let_res_492 = id_520;
      }
      let_res_465 = let_res_492;
    }
    Size let_res_521;
    {
      Size sz_317 { let_res_465 };
      auto fun522 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_523 { p_0.type_field };
      Size id_524 { fun522(id_523) };
      Size id_525 { Size(sz_317 + id_524) };
      let_res_521 = id_525;
    }
    Size let_res_526;
    {
      Size sz_318 { let_res_521 };
      auto fun527 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_528 { p_0.value_field };
      Size id_529 { fun527(id_528) };
      Size id_530 { Size(sz_318 + id_529) };
      let_res_526 = id_530;
    }
    Size let_res_531;
    {
      Size sz_319 { let_res_526 };
      Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_532 { p_0.fields };
      uint32_t id_533 { id_532.size() };
      Vec<1, uint32_t> id_534 {  id_533  };
      Size let_res_535;
      {
        Vec<1, uint32_t> n_ref_320 { id_534 };
        uint32_t id_536 { 1U };
        Vec<1, uint32_t> id_537 {  id_536  };
        Size let_res_538;
        {
          Vec<1, uint32_t> lebsz_ref_321 { id_537 };
          bool while_flag_539 { true };
          do {
            uint8_t id_540 { 0 };
            uint32_t id_541 { n_ref_320[id_540] };
            uint8_t id_542 { 0 };
            uint32_t id_543 { lebsz_ref_321[id_542] };
            uint8_t id_544 { 7 };
            uint32_t id_545 { uint32_t(id_543 << id_544) };
            bool id_546 { bool(id_541 >= id_545) };
            while_flag_539 = id_546;
            if (while_flag_539) {
              uint8_t id_547 { 0 };
              uint8_t id_548 { 0 };
              uint32_t id_549 { lebsz_ref_321[id_548] };
              uint32_t id_550 { 1U };
              uint32_t id_551 { uint32_t(id_549 + id_550) };
              Void id_552 { ((void)(lebsz_ref_321[id_547] = id_551), ::dessser::Void()) };
              (void)id_552;
            }
          } while (while_flag_539);
          (void)::dessser::Void();
          uint8_t id_553 { 0 };
          uint32_t id_554 { lebsz_ref_321[id_553] };
          Size id_555 { Size(id_554) };
          let_res_538 = id_555;
        }
        let_res_535 = let_res_538;
      }
      Size id_556 { Size(sz_319 + let_res_535) };
      Vec<1, Size> id_557 {  id_556  };
      Size let_res_558;
      {
        Vec<1, Size> sz_ref_322 { id_557 };
        int32_t id_559 { 0L };
        Vec<1, int32_t> id_560 {  id_559  };
        {
          Vec<1, int32_t> repeat_n_323 { id_560 };
          bool while_flag_561 { true };
          do {
            Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_562 { p_0.fields };
            uint32_t id_563 { id_562.size() };
            int32_t id_564 { int32_t(id_563) };
            uint8_t id_565 { 0 };
            int32_t id_566 { repeat_n_323[id_565] };
            bool id_567 { bool(id_564 > id_566) };
            while_flag_561 = id_567;
            if (while_flag_561) {
              uint8_t id_568 { 0 };
              uint8_t id_569 { 0 };
              Size id_570 { sz_ref_322[id_569] };
              Size let_res_571;
              {
                Size sz_324 { id_570 };
                auto fun572 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_573 { 0 };
                int32_t id_574 { repeat_n_323[id_573] };
                Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_575 { p_0.fields };
                ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_576 { id_575[id_574] };
                dessser::gen::field_name::t_ext id_577 { id_576.name };
                Size id_578 { fun572(id_577) };
                Size id_579 { Size(sz_324 + id_578) };
                let_res_571 = id_579;
              }
              Size let_res_580;
              {
                Size sz_325 { let_res_571 };
                uint8_t id_581 { 0 };
                int32_t id_582 { repeat_n_323[id_581] };
                Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_583 { p_0.fields };
                ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_584 { id_583[id_582] };
                Arr<std::string> id_585 { id_584.types };
                uint32_t id_586 { id_585.size() };
                Vec<1, uint32_t> id_587 {  id_586  };
                Size let_res_588;
                {
                  Vec<1, uint32_t> n_ref_326 { id_587 };
                  uint32_t id_589 { 1U };
                  Vec<1, uint32_t> id_590 {  id_589  };
                  Size let_res_591;
                  {
                    Vec<1, uint32_t> lebsz_ref_327 { id_590 };
                    bool while_flag_592 { true };
                    do {
                      uint8_t id_593 { 0 };
                      uint32_t id_594 { n_ref_326[id_593] };
                      uint8_t id_595 { 0 };
                      uint32_t id_596 { lebsz_ref_327[id_595] };
                      uint8_t id_597 { 7 };
                      uint32_t id_598 { uint32_t(id_596 << id_597) };
                      bool id_599 { bool(id_594 >= id_598) };
                      while_flag_592 = id_599;
                      if (while_flag_592) {
                        uint8_t id_600 { 0 };
                        uint8_t id_601 { 0 };
                        uint32_t id_602 { lebsz_ref_327[id_601] };
                        uint32_t id_603 { 1U };
                        uint32_t id_604 { uint32_t(id_602 + id_603) };
                        Void id_605 { ((void)(lebsz_ref_327[id_600] = id_604), ::dessser::Void()) };
                        (void)id_605;
                      }
                    } while (while_flag_592);
                    (void)::dessser::Void();
                    uint8_t id_606 { 0 };
                    uint32_t id_607 { lebsz_ref_327[id_606] };
                    Size id_608 { Size(id_607) };
                    let_res_591 = id_608;
                  }
                  let_res_588 = let_res_591;
                }
                Size id_609 { Size(sz_325 + let_res_588) };
                Vec<1, Size> id_610 {  id_609  };
                Size let_res_611;
                {
                  Vec<1, Size> sz_ref_328 { id_610 };
                  int32_t id_612 { 0L };
                  Vec<1, int32_t> id_613 {  id_612  };
                  {
                    Vec<1, int32_t> repeat_n_329 { id_613 };
                    bool while_flag_614 { true };
                    do {
                      uint8_t id_615 { 0 };
                      int32_t id_616 { repeat_n_323[id_615] };
                      Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_617 { p_0.fields };
                      ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_618 { id_617[id_616] };
                      Arr<std::string> id_619 { id_618.types };
                      uint32_t id_620 { id_619.size() };
                      int32_t id_621 { int32_t(id_620) };
                      uint8_t id_622 { 0 };
                      int32_t id_623 { repeat_n_329[id_622] };
                      bool id_624 { bool(id_621 > id_623) };
                      while_flag_614 = id_624;
                      if (while_flag_614) {
                        uint8_t id_625 { 0 };
                        uint8_t id_626 { 0 };
                        Size id_627 { sz_ref_328[id_626] };
                        uint8_t id_628 { 0 };
                        int32_t id_629 { repeat_n_329[id_628] };
                        uint8_t id_630 { 0 };
                        int32_t id_631 { repeat_n_323[id_630] };
                        Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_632 { p_0.fields };
                        ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_633 { id_632[id_631] };
                        Arr<std::string> id_634 { id_633.types };
                        std::string id_635 { id_634[id_629] };
                        uint32_t id_636 { (uint32_t)id_635.size() };
                        Size let_res_637;
                        {
                          uint32_t wlen_330 { id_636 };
                          Vec<1, uint32_t> id_638 {  wlen_330  };
                          Size let_res_639;
                          {
                            Vec<1, uint32_t> n_ref_331 { id_638 };
                            uint32_t id_640 { 1U };
                            Vec<1, uint32_t> id_641 {  id_640  };
                            Size let_res_642;
                            {
                              Vec<1, uint32_t> lebsz_ref_332 { id_641 };
                              bool while_flag_643 { true };
                              do {
                                uint8_t id_644 { 0 };
                                uint32_t id_645 { n_ref_331[id_644] };
                                uint8_t id_646 { 0 };
                                uint32_t id_647 { lebsz_ref_332[id_646] };
                                uint8_t id_648 { 7 };
                                uint32_t id_649 { uint32_t(id_647 << id_648) };
                                bool id_650 { bool(id_645 >= id_649) };
                                while_flag_643 = id_650;
                                if (while_flag_643) {
                                  uint8_t id_651 { 0 };
                                  uint8_t id_652 { 0 };
                                  uint32_t id_653 { lebsz_ref_332[id_652] };
                                  uint32_t id_654 { 1U };
                                  uint32_t id_655 { uint32_t(id_653 + id_654) };
                                  Void id_656 { ((void)(lebsz_ref_332[id_651] = id_655), ::dessser::Void()) };
                                  (void)id_656;
                                }
                              } while (while_flag_643);
                              (void)::dessser::Void();
                              uint8_t id_657 { 0 };
                              uint32_t id_658 { lebsz_ref_332[id_657] };
                              Size id_659 { Size(id_658) };
                              let_res_642 = id_659;
                            }
                            let_res_639 = let_res_642;
                          }
                          Size id_660 { Size(wlen_330) };
                          Size id_661 { Size(let_res_639 + id_660) };
                          let_res_637 = id_661;
                        }
                        Size id_662 { Size(id_627 + let_res_637) };
                        Void id_663 { ((void)(sz_ref_328[id_625] = id_662), ::dessser::Void()) };
                        (void)id_663;
                        uint8_t id_664 { 0 };
                        uint8_t id_665 { 0 };
                        int32_t id_666 { repeat_n_329[id_665] };
                        int32_t id_667 { 1L };
                        int32_t id_668 { int32_t(id_666 + id_667) };
                        Void id_669 { ((void)(repeat_n_329[id_664] = id_668), ::dessser::Void()) };
                        (void)id_669;
                        (void)id_669;
                      }
                    } while (while_flag_614);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_670 { 0 };
                  Size id_671 { sz_ref_328[id_670] };
                  let_res_611 = id_671;
                }
                let_res_580 = let_res_611;
              }
              Size id_672 { 1UL };
              Size id_673 { Size(let_res_580 + id_672) };
              Size id_674 { 1UL };
              Size id_675 { Size(id_673 + id_674) };
              Size id_676 { 1UL };
              Size id_677 { Size(id_675 + id_676) };
              Size id_678 { 1UL };
              Size id_679 { Size(id_677 + id_678) };
              Size id_680 { 1UL };
              Size id_681 { Size(id_679 + id_680) };
              Size id_682 { 1UL };
              Size id_683 { Size(id_681 + id_682) };
              Size id_684 { 1UL };
              Size id_685 { Size(id_683 + id_684) };
              Size let_res_686;
              {
                Size sz_340 { id_685 };
                uint8_t id_687 { 0 };
                int32_t id_688 { repeat_n_323[id_687] };
                Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_689 { p_0.fields };
                ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_690 { id_689[id_688] };
                Arr<double> id_691 { id_690.percentiles };
                uint32_t id_692 { id_691.size() };
                Vec<1, uint32_t> id_693 {  id_692  };
                Size let_res_694;
                {
                  Vec<1, uint32_t> n_ref_341 { id_693 };
                  uint32_t id_695 { 1U };
                  Vec<1, uint32_t> id_696 {  id_695  };
                  Size let_res_697;
                  {
                    Vec<1, uint32_t> lebsz_ref_342 { id_696 };
                    bool while_flag_698 { true };
                    do {
                      uint8_t id_699 { 0 };
                      uint32_t id_700 { n_ref_341[id_699] };
                      uint8_t id_701 { 0 };
                      uint32_t id_702 { lebsz_ref_342[id_701] };
                      uint8_t id_703 { 7 };
                      uint32_t id_704 { uint32_t(id_702 << id_703) };
                      bool id_705 { bool(id_700 >= id_704) };
                      while_flag_698 = id_705;
                      if (while_flag_698) {
                        uint8_t id_706 { 0 };
                        uint8_t id_707 { 0 };
                        uint32_t id_708 { lebsz_ref_342[id_707] };
                        uint32_t id_709 { 1U };
                        uint32_t id_710 { uint32_t(id_708 + id_709) };
                        Void id_711 { ((void)(lebsz_ref_342[id_706] = id_710), ::dessser::Void()) };
                        (void)id_711;
                      }
                    } while (while_flag_698);
                    (void)::dessser::Void();
                    uint8_t id_712 { 0 };
                    uint32_t id_713 { lebsz_ref_342[id_712] };
                    Size id_714 { Size(id_713) };
                    let_res_697 = id_714;
                  }
                  let_res_694 = let_res_697;
                }
                Size id_715 { Size(sz_340 + let_res_694) };
                Vec<1, Size> id_716 {  id_715  };
                Size let_res_717;
                {
                  Vec<1, Size> sz_ref_343 { id_716 };
                  int32_t id_718 { 0L };
                  Vec<1, int32_t> id_719 {  id_718  };
                  {
                    Vec<1, int32_t> repeat_n_344 { id_719 };
                    bool while_flag_720 { true };
                    do {
                      uint8_t id_721 { 0 };
                      int32_t id_722 { repeat_n_323[id_721] };
                      Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_723 { p_0.fields };
                      ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_724 { id_723[id_722] };
                      Arr<double> id_725 { id_724.percentiles };
                      uint32_t id_726 { id_725.size() };
                      int32_t id_727 { int32_t(id_726) };
                      uint8_t id_728 { 0 };
                      int32_t id_729 { repeat_n_344[id_728] };
                      bool id_730 { bool(id_727 > id_729) };
                      while_flag_720 = id_730;
                      if (while_flag_720) {
                        uint8_t id_731 { 0 };
                        uint8_t id_732 { 0 };
                        Size id_733 { sz_ref_343[id_732] };
                        Size id_734 { 8UL };
                        Size id_735 { Size(id_733 + id_734) };
                        Void id_736 { ((void)(sz_ref_343[id_731] = id_735), ::dessser::Void()) };
                        (void)id_736;
                        uint8_t id_737 { 0 };
                        uint8_t id_738 { 0 };
                        int32_t id_739 { repeat_n_344[id_738] };
                        int32_t id_740 { 1L };
                        int32_t id_741 { int32_t(id_739 + id_740) };
                        Void id_742 { ((void)(repeat_n_344[id_737] = id_741), ::dessser::Void()) };
                        (void)id_742;
                        (void)id_742;
                      }
                    } while (while_flag_720);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_743 { 0 };
                  Size id_744 { sz_ref_343[id_743] };
                  let_res_717 = id_744;
                }
                let_res_686 = let_res_717;
              }
              Size let_res_745;
              {
                Size sz_345 { let_res_686 };
                uint8_t id_746 { 0 };
                int32_t id_747 { repeat_n_323[id_746] };
                Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_748 { p_0.fields };
                ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_749 { id_748[id_747] };
                Arr<::dessser::gen::pivot::top> id_750 { id_749.tops };
                uint32_t id_751 { id_750.size() };
                Vec<1, uint32_t> id_752 {  id_751  };
                Size let_res_753;
                {
                  Vec<1, uint32_t> n_ref_346 { id_752 };
                  uint32_t id_754 { 1U };
                  Vec<1, uint32_t> id_755 {  id_754  };
                  Size let_res_756;
                  {
                    Vec<1, uint32_t> lebsz_ref_347 { id_755 };
                    bool while_flag_757 { true };
                    do {
                      uint8_t id_758 { 0 };
                      uint32_t id_759 { n_ref_346[id_758] };
                      uint8_t id_760 { 0 };
                      uint32_t id_761 { lebsz_ref_347[id_760] };
                      uint8_t id_762 { 7 };
                      uint32_t id_763 { uint32_t(id_761 << id_762) };
                      bool id_764 { bool(id_759 >= id_763) };
                      while_flag_757 = id_764;
                      if (while_flag_757) {
                        uint8_t id_765 { 0 };
                        uint8_t id_766 { 0 };
                        uint32_t id_767 { lebsz_ref_347[id_766] };
                        uint32_t id_768 { 1U };
                        uint32_t id_769 { uint32_t(id_767 + id_768) };
                        Void id_770 { ((void)(lebsz_ref_347[id_765] = id_769), ::dessser::Void()) };
                        (void)id_770;
                      }
                    } while (while_flag_757);
                    (void)::dessser::Void();
                    uint8_t id_771 { 0 };
                    uint32_t id_772 { lebsz_ref_347[id_771] };
                    Size id_773 { Size(id_772) };
                    let_res_756 = id_773;
                  }
                  let_res_753 = let_res_756;
                }
                Size id_774 { Size(sz_345 + let_res_753) };
                Vec<1, Size> id_775 {  id_774  };
                Size let_res_776;
                {
                  Vec<1, Size> sz_ref_348 { id_775 };
                  int32_t id_777 { 0L };
                  Vec<1, int32_t> id_778 {  id_777  };
                  {
                    Vec<1, int32_t> repeat_n_349 { id_778 };
                    bool while_flag_779 { true };
                    do {
                      uint8_t id_780 { 0 };
                      int32_t id_781 { repeat_n_323[id_780] };
                      Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_782 { p_0.fields };
                      ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_783 { id_782[id_781] };
                      Arr<::dessser::gen::pivot::top> id_784 { id_783.tops };
                      uint32_t id_785 { id_784.size() };
                      int32_t id_786 { int32_t(id_785) };
                      uint8_t id_787 { 0 };
                      int32_t id_788 { repeat_n_349[id_787] };
                      bool id_789 { bool(id_786 > id_788) };
                      while_flag_779 = id_789;
                      if (while_flag_779) {
                        uint8_t id_790 { 0 };
                        uint8_t id_791 { 0 };
                        Size id_792 { sz_ref_348[id_791] };
                        uint8_t id_793 { 0 };
                        int32_t id_794 { repeat_n_349[id_793] };
                        uint8_t id_795 { 0 };
                        int32_t id_796 { repeat_n_323[id_795] };
                        Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_797 { p_0.fields };
                        ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_798 { id_797[id_796] };
                        Arr<::dessser::gen::pivot::top> id_799 { id_798.tops };
                        ::dessser::gen::pivot::top id_800 { id_799[id_794] };
                        Size id_801 { top_sersize_of_row_binary(id_800) };
                        Size id_802 { Size(id_792 + id_801) };
                        Void id_803 { ((void)(sz_ref_348[id_790] = id_802), ::dessser::Void()) };
                        (void)id_803;
                        uint8_t id_804 { 0 };
                        uint8_t id_805 { 0 };
                        int32_t id_806 { repeat_n_349[id_805] };
                        int32_t id_807 { 1L };
                        int32_t id_808 { int32_t(id_806 + id_807) };
                        Void id_809 { ((void)(repeat_n_349[id_804] = id_808), ::dessser::Void()) };
                        (void)id_809;
                        (void)id_809;
                      }
                    } while (while_flag_779);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_810 { 0 };
                  Size id_811 { sz_ref_348[id_810] };
                  let_res_776 = id_811;
                }
                let_res_745 = let_res_776;
              }
              Void id_812 { ((void)(sz_ref_322[id_568] = let_res_745), ::dessser::Void()) };
              (void)id_812;
              uint8_t id_813 { 0 };
              uint8_t id_814 { 0 };
              int32_t id_815 { repeat_n_323[id_814] };
              int32_t id_816 { 1L };
              int32_t id_817 { int32_t(id_815 + id_816) };
              Void id_818 { ((void)(repeat_n_323[id_813] = id_817), ::dessser::Void()) };
              (void)id_818;
              (void)id_818;
            }
          } while (while_flag_561);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_819 { 0 };
        Size id_820 { sz_ref_322[id_819] };
        let_res_558 = id_820;
      }
      let_res_531 = let_res_558;
    }
    Size let_res_821;
    {
      Size sz_350 { let_res_531 };
      Arr<dessser::gen::field_name::t_ext> id_822 { p_0.group_by };
      uint32_t id_823 { id_822.size() };
      Vec<1, uint32_t> id_824 {  id_823  };
      Size let_res_825;
      {
        Vec<1, uint32_t> n_ref_351 { id_824 };
        uint32_t id_826 { 1U };
        Vec<1, uint32_t> id_827 {  id_826  };
        Size let_res_828;
        {
          Vec<1, uint32_t> lebsz_ref_352 { id_827 };
          bool while_flag_829 { true };
          do {
            uint8_t id_830 { 0 };
            uint32_t id_831 { n_ref_351[id_830] };
            uint8_t id_832 { 0 };
            uint32_t id_833 { lebsz_ref_352[id_832] };
            uint8_t id_834 { 7 };
            uint32_t id_835 { uint32_t(id_833 << id_834) };
            bool id_836 { bool(id_831 >= id_835) };
            while_flag_829 = id_836;
            if (while_flag_829) {
              uint8_t id_837 { 0 };
              uint8_t id_838 { 0 };
              uint32_t id_839 { lebsz_ref_352[id_838] };
              uint32_t id_840 { 1U };
              uint32_t id_841 { uint32_t(id_839 + id_840) };
              Void id_842 { ((void)(lebsz_ref_352[id_837] = id_841), ::dessser::Void()) };
              (void)id_842;
            }
          } while (while_flag_829);
          (void)::dessser::Void();
          uint8_t id_843 { 0 };
          uint32_t id_844 { lebsz_ref_352[id_843] };
          Size id_845 { Size(id_844) };
          let_res_828 = id_845;
        }
        let_res_825 = let_res_828;
      }
      Size id_846 { Size(sz_350 + let_res_825) };
      Vec<1, Size> id_847 {  id_846  };
      Size let_res_848;
      {
        Vec<1, Size> sz_ref_353 { id_847 };
        int32_t id_849 { 0L };
        Vec<1, int32_t> id_850 {  id_849  };
        {
          Vec<1, int32_t> repeat_n_354 { id_850 };
          bool while_flag_851 { true };
          do {
            Arr<dessser::gen::field_name::t_ext> id_852 { p_0.group_by };
            uint32_t id_853 { id_852.size() };
            int32_t id_854 { int32_t(id_853) };
            uint8_t id_855 { 0 };
            int32_t id_856 { repeat_n_354[id_855] };
            bool id_857 { bool(id_854 > id_856) };
            while_flag_851 = id_857;
            if (while_flag_851) {
              uint8_t id_858 { 0 };
              uint8_t id_859 { 0 };
              Size id_860 { sz_ref_353[id_859] };
              auto fun861 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_862 { 0 };
              int32_t id_863 { repeat_n_354[id_862] };
              Arr<dessser::gen::field_name::t_ext> id_864 { p_0.group_by };
              dessser::gen::field_name::t_ext id_865 { id_864[id_863] };
              Size id_866 { fun861(id_865) };
              Size id_867 { Size(id_860 + id_866) };
              Void id_868 { ((void)(sz_ref_353[id_858] = id_867), ::dessser::Void()) };
              (void)id_868;
              uint8_t id_869 { 0 };
              uint8_t id_870 { 0 };
              int32_t id_871 { repeat_n_354[id_870] };
              int32_t id_872 { 1L };
              int32_t id_873 { int32_t(id_871 + id_872) };
              Void id_874 { ((void)(repeat_n_354[id_869] = id_873), ::dessser::Void()) };
              (void)id_874;
              (void)id_874;
            }
          } while (while_flag_851);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_875 { 0 };
        Size id_876 { sz_ref_353[id_875] };
        let_res_848 = id_876;
      }
      let_res_821 = let_res_848;
    }
    Size id_877 { 8UL };
    Size id_878 { Size(let_res_821 + id_877) };
    Size id_879 { 8UL };
    Size id_880 { Size(id_878 + id_879) };
    return id_880;
  }
   };
  return fun461;
}
std::function<Size(::dessser::gen::pivot::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_60" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "drec_fst_61" "drec_snd_62" (identifier "drec_60")
          (let-pair "drec_fst_67" "drec_snd_68"
            (if (eq (peek-u8 (identifier "drec_snd_62") (size 0)) (u8 1)) 
              (make-tup (null "$field_name") (ptr-add (identifier "drec_snd_62") (size 1)))
              (let-pair "make1_1_fst_64" "make1_1_snd_65" (apply (ext-identifier field_name of-row-binary) (ptr-add (identifier "drec_snd_62") (size 1)))
                (make-tup (not-null (identifier "make1_1_fst_64")) (identifier "make1_1_snd_65"))))
            (make-tup (make-rec (string "by") (identifier "drec_fst_67") (string "n") (identifier "drec_fst_61")) (identifier "drec_snd_68"))))))
 */
static std::function<::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74(Pointer &)> top_of_row_binary_init()
{
  std::function<::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74(Pointer &)> fun881 { [&](Pointer p_0) {
    ::dessser::gen::pivot::ta97bb48ed75bbda6173555873826c8c6 id_882 { p_0.readU16Le() };
    ::dessser::gen::pivot::ta97bb48ed75bbda6173555873826c8c6 letpair_res_883;
    {
      auto du16_fst_58 { std::get<0>(id_882) };
      auto du16_snd_59 { std::get<1>(id_882) };
      ::dessser::gen::pivot::ta97bb48ed75bbda6173555873826c8c6 id_884 { du16_fst_58, du16_snd_59 };
      letpair_res_883 = id_884;
    }
    ::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74 let_res_885;
    {
      ::dessser::gen::pivot::ta97bb48ed75bbda6173555873826c8c6 drec_60 { letpair_res_883 };
      ::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74 letpair_res_886;
      {
        auto drec_fst_61 { std::get<0>(drec_60) };
        auto drec_snd_62 { std::get<1>(drec_60) };
        Size id_887 { 0UL };
        uint8_t id_888 { drec_snd_62.peekU8(id_887) };
        uint8_t id_889 { 1 };
        bool id_890 { bool(id_888 == id_889) };
        ::dessser::gen::pivot::t017c58e4a7553374b91a64cd4c386334 choose_res_891;
        if (id_890) {
          std::optional<dessser::gen::field_name::t_ext> id_892 { std::nullopt };
          Size id_893 { 1UL };
          Pointer id_894 { drec_snd_62.skip(id_893) };
          ::dessser::gen::pivot::t017c58e4a7553374b91a64cd4c386334 id_895 { id_892, id_894 };
          choose_res_891 = id_895;
        } else {
          auto fun896 { dessser::gen::field_name::of_row_binary };
          Size id_897 { 1UL };
          Pointer id_898 { drec_snd_62.skip(id_897) };
          ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 id_899 { fun896(id_898) };
          ::dessser::gen::pivot::t017c58e4a7553374b91a64cd4c386334 letpair_res_900;
          {
            auto make1_1_fst_64 { std::get<0>(id_899) };
            auto make1_1_snd_65 { std::get<1>(id_899) };
            std::optional<dessser::gen::field_name::t_ext> id_901 { make1_1_fst_64 };
            ::dessser::gen::pivot::t017c58e4a7553374b91a64cd4c386334 id_902 { id_901, make1_1_snd_65 };
            letpair_res_900 = id_902;
          }
          choose_res_891 = letpair_res_900;
        }
        ::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74 letpair_res_903;
        {
          auto drec_fst_67 { std::get<0>(choose_res_891) };
          auto drec_snd_68 { std::get<1>(choose_res_891) };
          ::dessser::gen::pivot::top id_904 { drec_fst_61, drec_fst_67 };
          ::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74 id_905 { id_904, drec_snd_68 };
          letpair_res_903 = id_905;
        }
        letpair_res_886 = letpair_res_903;
      }
      let_res_885 = letpair_res_886;
    }
    return let_res_885;
  }
   };
  return fun881;
}
std::function<::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74(Pointer &)> top_of_row_binary(top_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_69" (apply (ext-identifier fq_name of-row-binary) (param 0))
        (let-pair "drec_fst_70" "drec_snd_71" (identifier "drec_69")
          (let "drec_95"
            (let-pair "dlist4_fst_93" "dlist4_snd_94"
              (let "dlist1_81"
                (let "leb_ref_72" (make-vec (u32 0))
                  (let "shft_ref_73" (make-vec (u8 0))
                    (let "p_ref_74" (make-vec (identifier "drec_snd_71"))
                      (seq
                        (while
                          (let "leb128_75" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_74")))
                            (let-pair "leb128_fst_76" "leb128_snd_77" 
                              (identifier "leb128_75")
                              (seq (set-vec (u8 0) (identifier "p_ref_74") (identifier "leb128_snd_77"))
                                (set-vec (u8 0) (identifier "leb_ref_72")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_76") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_73"))) (unsafe-nth (u8 0) (identifier "leb_ref_72"))))
                                (set-vec (u8 0) (identifier "shft_ref_73") (add (unsafe-nth (u8 0) (identifier "shft_ref_73")) (u8 7))) 
                                (ge (identifier "leb128_fst_76") (u8 128))))) 
                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_72")) (unsafe-nth (u8 0) (identifier "p_ref_74")))))))
                (let-pair "dlist1_fst_82" "dlist1_snd_83" (identifier "dlist1_81")
                  (let "inits_src_ref_84" (make-vec (make-tup (end-of-list "$simple_filter") (identifier "dlist1_snd_83")))
                    (seq
                      (let "repeat_n_85" (make-vec (i32 0))
                        (while (gt (to-i32 (identifier "dlist1_fst_82")) (unsafe-nth (u8 0) (identifier "repeat_n_85")))
                          (seq
                            (let "dlist2_86" (unsafe-nth (u8 0) (identifier "inits_src_ref_84"))
                              (let-pair "dlist2_fst_87" "dlist2_snd_88" 
                                (identifier "dlist2_86")
                                (set-vec (u8 0) (identifier "inits_src_ref_84")
                                  (let-pair "dlist3_fst_90" "dlist3_snd_91" 
                                    (apply (ext-identifier simple_filter of-row-binary) (identifier "dlist2_snd_88")) 
                                    (make-tup (cons (identifier "dlist3_fst_90") (identifier "dlist2_fst_87")) (identifier "dlist3_snd_91"))))))
                            (set-vec (u8 0) (identifier "repeat_n_85") (add (unsafe-nth (u8 0) (identifier "repeat_n_85")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "inits_src_ref_84")))))) 
              (make-tup (arr-of-lst-rev (identifier "dlist4_fst_93")) (identifier "dlist4_snd_94")))
            (let-pair "drec_fst_96" "drec_snd_97" (identifier "drec_95")
              (let "drec_98" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_97"))
                (let-pair "drec_fst_99" "drec_snd_100" (identifier "drec_98")
                  (let "drec_101" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_100"))
                    (let-pair "drec_fst_102" "drec_snd_103" (identifier "drec_101")
                      (let "drec_265"
                        (let-pair "dlist4_fst_263" "dlist4_snd_264"
                          (let "dlist1_113"
                            (let "leb_ref_104" (make-vec (u32 0))
                              (let "shft_ref_105" (make-vec (u8 0))
                                (let "p_ref_106" (make-vec (identifier "drec_snd_103"))
                                  (seq
                                    (while
                                      (let "leb128_107" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_106")))
                                        (let-pair "leb128_fst_108" "leb128_snd_109" 
                                          (identifier "leb128_107")
                                          (seq (set-vec (u8 0) (identifier "p_ref_106") (identifier "leb128_snd_109"))
                                            (set-vec (u8 0) (identifier "leb_ref_104")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_108") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_105"))) (unsafe-nth (u8 0) (identifier "leb_ref_104"))))
                                            (set-vec (u8 0) (identifier "shft_ref_105") (add (unsafe-nth (u8 0) (identifier "shft_ref_105")) (u8 7))) 
                                            (ge (identifier "leb128_fst_108") (u8 128))))) 
                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_104")) (unsafe-nth (u8 0) (identifier "p_ref_106")))))))
                            (let-pair "dlist1_fst_114" "dlist1_snd_115" 
                              (identifier "dlist1_113")
                              (let "inits_src_ref_116"
                                (make-vec
                                  (make-tup
                                    (end-of-list "{name: $field_name; types: STRING[]; count: BOOL; first: BOOL; last: BOOL; min: BOOL; max: BOOL; sum: BOOL; avg: BOOL; percentiles: FLOAT[]; tops: (top AS {n: U16; by: $field_name?})[]}")
                                    (identifier "dlist1_snd_115")))
                                (seq
                                  (let "repeat_n_117" (make-vec (i32 0))
                                    (while (gt (to-i32 (identifier "dlist1_fst_114")) (unsafe-nth (u8 0) (identifier "repeat_n_117")))
                                      (seq
                                        (let "dlist2_118" (unsafe-nth (u8 0) (identifier "inits_src_ref_116"))
                                          (let-pair "dlist2_fst_119" "dlist2_snd_120" 
                                            (identifier "dlist2_118")
                                            (set-vec (u8 0) (identifier "inits_src_ref_116")
                                              (let "drec_121" (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_120"))
                                                (let-pair "drec_fst_122" "drec_snd_123" 
                                                  (identifier "drec_121")
                                                  (let "drec_159"
                                                    (let-pair "dlist4_fst_157" "dlist4_snd_158"
                                                      (let "dlist1_133"
                                                        (let "leb_ref_124" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_125" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_126" 
                                                              (make-vec (identifier "drec_snd_123"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_127" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_126")))
                                                                    (let-pair "leb128_fst_128" "leb128_snd_129" 
                                                                    (identifier "leb128_127")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_126") (identifier "leb128_snd_129"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_124")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_128") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_125")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_124")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_125") (add (unsafe-nth (u8 0) (identifier "shft_ref_125")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_128") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_124")) (unsafe-nth (u8 0) (identifier "p_ref_126")))))))
                                                        (let-pair "dlist1_fst_134" "dlist1_snd_135" 
                                                          (identifier "dlist1_133")
                                                          (let "inits_src_ref_136" 
                                                            (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_135")))
                                                            (seq
                                                              (let "repeat_n_137" 
                                                                (make-vec (i32 0))
                                                                (while 
                                                                  (gt (to-i32 (identifier "dlist1_fst_134")) (unsafe-nth (u8 0) (identifier "repeat_n_137")))
                                                                  (seq
                                                                    (let "dlist2_138" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_136"))
                                                                    (let-pair "dlist2_fst_139" "dlist2_snd_140" 
                                                                    (identifier "dlist2_138")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_136")
                                                                    (let "dstring1_147"
                                                                    (let "leb_ref_141" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_142" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_143" 
                                                                    (make-vec (identifier "dlist2_snd_140"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_144" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_143")))
                                                                    (let-pair "leb128_fst_145" "leb128_snd_146" 
                                                                    (identifier "leb128_144")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_143") (identifier "leb128_snd_146"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_141")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_145") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_142")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_141")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_142") (add (unsafe-nth (u8 0) (identifier "shft_ref_142")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_145") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_141"))) (unsafe-nth (u8 0) (identifier "p_ref_143")))))))
                                                                    (let-pair "dstring1_fst_148" "dstring1_snd_149" 
                                                                    (identifier "dstring1_147")
                                                                    (let-pair "dstring2_fst_151" "dstring2_snd_152" 
                                                                    (read-bytes (identifier "dstring1_snd_149") (identifier "dstring1_fst_148"))
                                                                    (make-tup (cons (string-of-bytes (identifier "dstring2_fst_151")) (identifier "dlist2_fst_139")) (identifier "dstring2_snd_152"))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_137") (add (unsafe-nth (u8 0) (identifier "repeat_n_137")) (i32 1))))))
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_136")))))) 
                                                      (make-tup (arr-of-lst-rev (identifier "dlist4_fst_157")) (identifier "dlist4_snd_158")))
                                                    (let-pair "drec_fst_160" "drec_snd_161" 
                                                      (identifier "drec_159")
                                                      (let "drec_165"
                                                        (let-pair "dbool_fst_163" "dbool_snd_164" (read-u8 (identifier "drec_snd_161")) (make-tup (not (eq (identifier "dbool_fst_163") (u8 0))) (identifier "dbool_snd_164")))
                                                        (let-pair "drec_fst_166" "drec_snd_167" 
                                                          (identifier "drec_165")
                                                          (let "drec_171"
                                                            (let-pair "dbool_fst_169" "dbool_snd_170" (read-u8 (identifier "drec_snd_167")) (make-tup (not (eq (identifier "dbool_fst_169") (u8 0))) (identifier "dbool_snd_170")))
                                                            (let-pair "drec_fst_172" "drec_snd_173" 
                                                              (identifier "drec_171")
                                                              (let "drec_177"
                                                                (let-pair "dbool_fst_175" "dbool_snd_176" 
                                                                  (read-u8 (identifier "drec_snd_173")) 
                                                                  (make-tup (not (eq (identifier "dbool_fst_175") (u8 0))) (identifier "dbool_snd_176")))
                                                                (let-pair "drec_fst_178" "drec_snd_179" 
                                                                  (identifier "drec_177")
                                                                  (let "drec_183"
                                                                    (let-pair "dbool_fst_181" "dbool_snd_182" 
                                                                    (read-u8 (identifier "drec_snd_179")) 
                                                                    (make-tup (not (eq (identifier "dbool_fst_181") (u8 0))) (identifier "dbool_snd_182")))
                                                                    (let-pair "drec_fst_184" "drec_snd_185" 
                                                                    (identifier "drec_183")
                                                                    (let "drec_189"
                                                                    (let-pair "dbool_fst_187" "dbool_snd_188" 
                                                                    (read-u8 (identifier "drec_snd_185")) 
                                                                    (make-tup (not (eq (identifier "dbool_fst_187") (u8 0))) (identifier "dbool_snd_188")))
                                                                    (let-pair "drec_fst_190" "drec_snd_191" 
                                                                    (identifier "drec_189")
                                                                    (let "drec_195"
                                                                    (let-pair "dbool_fst_193" "dbool_snd_194" 
                                                                    (read-u8 (identifier "drec_snd_191")) 
                                                                    (make-tup (not (eq (identifier "dbool_fst_193") (u8 0))) (identifier "dbool_snd_194")))
                                                                    (let-pair "drec_fst_196" "drec_snd_197" 
                                                                    (identifier "drec_195")
                                                                    (let "drec_201"
                                                                    (let-pair "dbool_fst_199" "dbool_snd_200" 
                                                                    (read-u8 (identifier "drec_snd_197")) 
                                                                    (make-tup (not (eq (identifier "dbool_fst_199") (u8 0))) (identifier "dbool_snd_200")))
                                                                    (let-pair "drec_fst_202" "drec_snd_203" 
                                                                    (identifier "drec_201")
                                                                    (let "drec_230"
                                                                    (let-pair "dlist4_fst_228" "dlist4_snd_229"
                                                                    (let "dlist1_213"
                                                                    (let "leb_ref_204" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_205" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_206" 
                                                                    (make-vec (identifier "drec_snd_203"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_207" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_206")))
                                                                    (let-pair "leb128_fst_208" "leb128_snd_209" 
                                                                    (identifier "leb128_207")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_206") (identifier "leb128_snd_209"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_204")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_208") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_205")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_204")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_205") (add (unsafe-nth (u8 0) (identifier "shft_ref_205")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_208") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_204")) (unsafe-nth (u8 0) (identifier "p_ref_206")))))))
                                                                    (let-pair "dlist1_fst_214" "dlist1_snd_215" 
                                                                    (identifier "dlist1_213")
                                                                    (let "inits_src_ref_216" 
                                                                    (make-vec (make-tup (end-of-list "FLOAT") (identifier "dlist1_snd_215")))
                                                                    (seq
                                                                    (let "repeat_n_217" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_214")) (unsafe-nth (u8 0) (identifier "repeat_n_217")))
                                                                    (seq
                                                                    (let "dlist2_218" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_216"))
                                                                    (let-pair "dlist2_fst_219" "dlist2_snd_220" 
                                                                    (identifier "dlist2_218")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_216")
                                                                    (let-pair "dfloat_fst_222" "dfloat_snd_223" 
                                                                    (read-u64 little-endian (identifier "dlist2_snd_220"))
                                                                    (make-tup (cons (float-of-u64 (identifier "dfloat_fst_222")) (identifier "dlist2_fst_219")) (identifier "dfloat_snd_223"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_217") (add (unsafe-nth (u8 0) (identifier "repeat_n_217")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_216")))))) 
                                                                    (make-tup (arr-of-lst-rev (identifier "dlist4_fst_228")) (identifier "dlist4_snd_229")))
                                                                    (let-pair "drec_fst_231" "drec_snd_232" 
                                                                    (identifier "drec_230")
                                                                    (let-pair "dlist4_fst_254" "dlist4_snd_255"
                                                                    (let "dlist1_242"
                                                                    (let "leb_ref_233" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_234" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_235" 
                                                                    (make-vec (identifier "drec_snd_232"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_236" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_235")))
                                                                    (let-pair "leb128_fst_237" "leb128_snd_238" 
                                                                    (identifier "leb128_236")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_235") (identifier "leb128_snd_238"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_233")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_237") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_234")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_233")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_234") (add (unsafe-nth (u8 0) (identifier "shft_ref_234")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_237") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_233")) (unsafe-nth (u8 0) (identifier "p_ref_235")))))))
                                                                    (let-pair "dlist1_fst_243" "dlist1_snd_244" 
                                                                    (identifier "dlist1_242")
                                                                    (let "inits_src_ref_245" 
                                                                    (make-vec (make-tup (end-of-list "(top AS {n: U16; by: $field_name?})") (identifier "dlist1_snd_244")))
                                                                    (seq
                                                                    (let "repeat_n_246" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_243")) (unsafe-nth (u8 0) (identifier "repeat_n_246")))
                                                                    (seq
                                                                    (let "dlist2_247" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_245"))
                                                                    (let-pair "dlist2_fst_248" "dlist2_snd_249" 
                                                                    (identifier "dlist2_247")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_245")
                                                                    (let-pair "dlist3_fst_251" "dlist3_snd_252" 
                                                                    (apply (identifier "top-of-row-binary") (identifier "dlist2_snd_249"))
                                                                    (make-tup (cons (identifier "dlist3_fst_251") (identifier "dlist2_fst_248")) (identifier "dlist3_snd_252"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_246") (add (unsafe-nth (u8 0) (identifier "repeat_n_246")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_245"))))))
                                                                    (make-tup
                                                                    (cons
                                                                    (make-rec 
                                                                    (string "tops") 
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_254")) 
                                                                    (string "percentiles") 
                                                                    (identifier "drec_fst_231") 
                                                                    (string "avg") 
                                                                    (identifier "drec_fst_202") 
                                                                    (string "sum") 
                                                                    (identifier "drec_fst_196") 
                                                                    (string "max") 
                                                                    (identifier "drec_fst_190") 
                                                                    (string "min") 
                                                                    (identifier "drec_fst_184") 
                                                                    (string "last") 
                                                                    (identifier "drec_fst_178") 
                                                                    (string "first") 
                                                                    (identifier "drec_fst_172") 
                                                                    (string "count") 
                                                                    (identifier "drec_fst_166") 
                                                                    (string "types") 
                                                                    (identifier "drec_fst_160") 
                                                                    (string "name") 
                                                                    (identifier "drec_fst_122")) 
                                                                    (identifier "dlist2_fst_119")) 
                                                                    (identifier "dlist4_snd_255"))))))))))))))))))))))))))
                                        (set-vec (u8 0) (identifier "repeat_n_117") (add (unsafe-nth (u8 0) (identifier "repeat_n_117")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_116")))))) 
                          (make-tup (arr-of-lst-rev (identifier "dlist4_fst_263")) (identifier "dlist4_snd_264")))
                        (let-pair "drec_fst_266" "drec_snd_267" (identifier "drec_265")
                          (let "drec_291"
                            (let-pair "dlist4_fst_289" "dlist4_snd_290"
                              (let "dlist1_277"
                                (let "leb_ref_268" (make-vec (u32 0))
                                  (let "shft_ref_269" (make-vec (u8 0))
                                    (let "p_ref_270" (make-vec (identifier "drec_snd_267"))
                                      (seq
                                        (while
                                          (let "leb128_271" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_270")))
                                            (let-pair "leb128_fst_272" "leb128_snd_273" 
                                              (identifier "leb128_271")
                                              (seq (set-vec (u8 0) (identifier "p_ref_270") (identifier "leb128_snd_273"))
                                                (set-vec (u8 0) (identifier "leb_ref_268")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_272") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_269"))) (unsafe-nth (u8 0) (identifier "leb_ref_268"))))
                                                (set-vec (u8 0) (identifier "shft_ref_269") (add (unsafe-nth (u8 0) (identifier "shft_ref_269")) (u8 7))) 
                                                (ge (identifier "leb128_fst_272") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_268")) (unsafe-nth (u8 0) (identifier "p_ref_270")))))))
                                (let-pair "dlist1_fst_278" "dlist1_snd_279" 
                                  (identifier "dlist1_277")
                                  (let "inits_src_ref_280" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_279")))
                                    (seq
                                      (let "repeat_n_281" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_278")) (unsafe-nth (u8 0) (identifier "repeat_n_281")))
                                          (seq
                                            (let "dlist2_282" (unsafe-nth (u8 0) (identifier "inits_src_ref_280"))
                                              (let-pair "dlist2_fst_283" "dlist2_snd_284" 
                                                (identifier "dlist2_282")
                                                (set-vec (u8 0) (identifier "inits_src_ref_280")
                                                  (let-pair "dlist3_fst_286" "dlist3_snd_287" 
                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_284"))
                                                    (make-tup (cons (identifier "dlist3_fst_286") (identifier "dlist2_fst_283")) (identifier "dlist3_snd_287"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_281") (add (unsafe-nth (u8 0) (identifier "repeat_n_281")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_280")))))) 
                              (make-tup (arr-of-lst-rev (identifier "dlist4_fst_289")) (identifier "dlist4_snd_290")))
                            (let-pair "drec_fst_292" "drec_snd_293" (identifier "drec_291")
                              (let "drec_297" (let-pair "dfloat_fst_295" "dfloat_snd_296" (read-u64 little-endian (identifier "drec_snd_293")) (make-tup (float-of-u64 (identifier "dfloat_fst_295")) (identifier "dfloat_snd_296")))
                                (let-pair "drec_fst_298" "drec_snd_299" 
                                  (identifier "drec_297")
                                  (let-pair "dfloat_fst_301" "dfloat_snd_302" 
                                    (read-u64 little-endian (identifier "drec_snd_299"))
                                    (make-tup
                                      (make-rec (string "max-lateness") 
                                        (float-of-u64 (identifier "dfloat_fst_301")) 
                                        (string "duration") (identifier "drec_fst_298") 
                                        (string "group-by") (identifier "drec_fst_292") 
                                        (string "fields") (identifier "drec_fst_266") 
                                        (string "value-field") (identifier "drec_fst_102") 
                                        (string "type-field") (identifier "drec_fst_99") 
                                        (string "where") (identifier "drec_fst_96") 
                                        (string "from") (identifier "drec_fst_70")) 
                                      (identifier "dfloat_snd_302"))))))))))))))))))
 */
static std::function<::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519(Pointer &)> fun906 { [&](Pointer p_0) {
    auto fun907 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::pivot::t1067cf8ed87e4e016349f71797fb0661 id_908 { fun907(p_0) };
    ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 let_res_909;
    {
      ::dessser::gen::pivot::t1067cf8ed87e4e016349f71797fb0661 drec_69 { id_908 };
      ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_910;
      {
        auto drec_fst_70 { std::get<0>(drec_69) };
        auto drec_snd_71 { std::get<1>(drec_69) };
        uint32_t id_911 { 0U };
        Vec<1, uint32_t> id_912 {  id_911  };
        ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_913;
        {
          Vec<1, uint32_t> leb_ref_72 { id_912 };
          uint8_t id_914 { 0 };
          Vec<1, uint8_t> id_915 {  id_914  };
          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_916;
          {
            Vec<1, uint8_t> shft_ref_73 { id_915 };
            Vec<1, Pointer> id_917 {  drec_snd_71  };
            ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_918;
            {
              Vec<1, Pointer> p_ref_74 { id_917 };
              bool while_flag_919 { true };
              do {
                uint8_t id_920 { 0 };
                Pointer id_921 { p_ref_74[id_920] };
                ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_922 { id_921.readU8() };
                bool let_res_923;
                {
                  ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 leb128_75 { id_922 };
                  bool letpair_res_924;
                  {
                    auto leb128_fst_76 { std::get<0>(leb128_75) };
                    auto leb128_snd_77 { std::get<1>(leb128_75) };
                    uint8_t id_925 { 0 };
                    Void id_926 { ((void)(p_ref_74[id_925] = leb128_snd_77), ::dessser::Void()) };
                    (void)id_926;
                    uint8_t id_927 { 0 };
                    uint8_t id_928 { 127 };
                    uint8_t id_929 { uint8_t(leb128_fst_76 & id_928) };
                    uint32_t id_930 { uint32_t(id_929) };
                    uint8_t id_931 { 0 };
                    uint8_t id_932 { shft_ref_73[id_931] };
                    uint32_t id_933 { uint32_t(id_930 << id_932) };
                    uint8_t id_934 { 0 };
                    uint32_t id_935 { leb_ref_72[id_934] };
                    uint32_t id_936 { uint32_t(id_933 | id_935) };
                    Void id_937 { ((void)(leb_ref_72[id_927] = id_936), ::dessser::Void()) };
                    (void)id_937;
                    uint8_t id_938 { 0 };
                    uint8_t id_939 { 0 };
                    uint8_t id_940 { shft_ref_73[id_939] };
                    uint8_t id_941 { 7 };
                    uint8_t id_942 { uint8_t(id_940 + id_941) };
                    Void id_943 { ((void)(shft_ref_73[id_938] = id_942), ::dessser::Void()) };
                    (void)id_943;
                    uint8_t id_944 { 128 };
                    bool id_945 { bool(leb128_fst_76 >= id_944) };
                    letpair_res_924 = id_945;
                  }
                  let_res_923 = letpair_res_924;
                }
                while_flag_919 = let_res_923;
                if (while_flag_919) {
                  (void)::dessser::Void();
                }
              } while (while_flag_919);
              (void)::dessser::Void();
              uint8_t id_946 { 0 };
              uint32_t id_947 { leb_ref_72[id_946] };
              uint8_t id_948 { 0 };
              Pointer id_949 { p_ref_74[id_948] };
              ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 id_950 { id_947, id_949 };
              let_res_918 = id_950;
            }
            let_res_916 = let_res_918;
          }
          let_res_913 = let_res_916;
        }
        ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d let_res_951;
        {
          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 dlist1_81 { let_res_913 };
          ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_952;
          {
            auto dlist1_fst_82 { std::get<0>(dlist1_81) };
            auto dlist1_snd_83 { std::get<1>(dlist1_81) };
            Lst<dessser::gen::simple_filter::t_ext> endoflist_953;
            ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d id_954 { endoflist_953, dlist1_snd_83 };
            Vec<1, ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d> id_955 {  id_954  };
            ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d let_res_956;
            {
              Vec<1, ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d> inits_src_ref_84 { id_955 };
              int32_t id_957 { 0L };
              Vec<1, int32_t> id_958 {  id_957  };
              {
                Vec<1, int32_t> repeat_n_85 { id_958 };
                bool while_flag_959 { true };
                do {
                  int32_t id_960 { int32_t(dlist1_fst_82) };
                  uint8_t id_961 { 0 };
                  int32_t id_962 { repeat_n_85[id_961] };
                  bool id_963 { bool(id_960 > id_962) };
                  while_flag_959 = id_963;
                  if (while_flag_959) {
                    uint8_t id_964 { 0 };
                    ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d id_965 { inits_src_ref_84[id_964] };
                    {
                      ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d dlist2_86 { id_965 };
                      {
                        auto dlist2_fst_87 { std::get<0>(dlist2_86) };
                        auto dlist2_snd_88 { std::get<1>(dlist2_86) };
                        uint8_t id_966 { 0 };
                        auto fun967 { dessser::gen::simple_filter::of_row_binary };
                        ::dessser::gen::pivot::t718468920e01b4b984449c743ae99792 id_968 { fun967(dlist2_snd_88) };
                        ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d letpair_res_969;
                        {
                          auto dlist3_fst_90 { std::get<0>(id_968) };
                          auto dlist3_snd_91 { std::get<1>(id_968) };
                          Lst<dessser::gen::simple_filter::t_ext> id_970 { dlist3_fst_90, dlist2_fst_87 };
                          ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d id_971 { id_970, dlist3_snd_91 };
                          letpair_res_969 = id_971;
                        }
                        Void id_972 { ((void)(inits_src_ref_84[id_966] = letpair_res_969), ::dessser::Void()) };
                        (void)id_972;
                      }
                      (void)::dessser::Void();
                    }
                    (void)::dessser::Void();
                    uint8_t id_973 { 0 };
                    uint8_t id_974 { 0 };
                    int32_t id_975 { repeat_n_85[id_974] };
                    int32_t id_976 { 1L };
                    int32_t id_977 { int32_t(id_975 + id_976) };
                    Void id_978 { ((void)(repeat_n_85[id_973] = id_977), ::dessser::Void()) };
                    (void)id_978;
                    (void)id_978;
                  }
                } while (while_flag_959);
                (void)::dessser::Void();
              }
              (void)::dessser::Void();
              uint8_t id_979 { 0 };
              ::dessser::gen::pivot::tc42fa697e1caa84eb8919e899ae45a1d id_980 { inits_src_ref_84[id_979] };
              let_res_956 = id_980;
            }
            letpair_res_952 = let_res_956;
          }
          let_res_951 = letpair_res_952;
        }
        ::dessser::gen::pivot::td403d13122fd20ecb97f01e7b85a9dea letpair_res_981;
        {
          auto dlist4_fst_93 { std::get<0>(let_res_951) };
          auto dlist4_snd_94 { std::get<1>(let_res_951) };
          Arr<dessser::gen::simple_filter::t_ext> id_982 { dlist4_fst_93.toArrRev() };
          ::dessser::gen::pivot::td403d13122fd20ecb97f01e7b85a9dea id_983 { id_982, dlist4_snd_94 };
          letpair_res_981 = id_983;
        }
        ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 let_res_984;
        {
          ::dessser::gen::pivot::td403d13122fd20ecb97f01e7b85a9dea drec_95 { letpair_res_981 };
          ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_985;
          {
            auto drec_fst_96 { std::get<0>(drec_95) };
            auto drec_snd_97 { std::get<1>(drec_95) };
            auto fun986 { dessser::gen::field_name::of_row_binary };
            ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 id_987 { fun986(drec_snd_97) };
            ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 let_res_988;
            {
              ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 drec_98 { id_987 };
              ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_989;
              {
                auto drec_fst_99 { std::get<0>(drec_98) };
                auto drec_snd_100 { std::get<1>(drec_98) };
                auto fun990 { dessser::gen::field_name::of_row_binary };
                ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 id_991 { fun990(drec_snd_100) };
                ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 let_res_992;
                {
                  ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 drec_101 { id_991 };
                  ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_993;
                  {
                    auto drec_fst_102 { std::get<0>(drec_101) };
                    auto drec_snd_103 { std::get<1>(drec_101) };
                    uint32_t id_994 { 0U };
                    Vec<1, uint32_t> id_995 {  id_994  };
                    ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_996;
                    {
                      Vec<1, uint32_t> leb_ref_104 { id_995 };
                      uint8_t id_997 { 0 };
                      Vec<1, uint8_t> id_998 {  id_997  };
                      ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_999;
                      {
                        Vec<1, uint8_t> shft_ref_105 { id_998 };
                        Vec<1, Pointer> id_1000 {  drec_snd_103  };
                        ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1001;
                        {
                          Vec<1, Pointer> p_ref_106 { id_1000 };
                          bool while_flag_1002 { true };
                          do {
                            uint8_t id_1003 { 0 };
                            Pointer id_1004 { p_ref_106[id_1003] };
                            ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1005 { id_1004.readU8() };
                            bool let_res_1006;
                            {
                              ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 leb128_107 { id_1005 };
                              bool letpair_res_1007;
                              {
                                auto leb128_fst_108 { std::get<0>(leb128_107) };
                                auto leb128_snd_109 { std::get<1>(leb128_107) };
                                uint8_t id_1008 { 0 };
                                Void id_1009 { ((void)(p_ref_106[id_1008] = leb128_snd_109), ::dessser::Void()) };
                                (void)id_1009;
                                uint8_t id_1010 { 0 };
                                uint8_t id_1011 { 127 };
                                uint8_t id_1012 { uint8_t(leb128_fst_108 & id_1011) };
                                uint32_t id_1013 { uint32_t(id_1012) };
                                uint8_t id_1014 { 0 };
                                uint8_t id_1015 { shft_ref_105[id_1014] };
                                uint32_t id_1016 { uint32_t(id_1013 << id_1015) };
                                uint8_t id_1017 { 0 };
                                uint32_t id_1018 { leb_ref_104[id_1017] };
                                uint32_t id_1019 { uint32_t(id_1016 | id_1018) };
                                Void id_1020 { ((void)(leb_ref_104[id_1010] = id_1019), ::dessser::Void()) };
                                (void)id_1020;
                                uint8_t id_1021 { 0 };
                                uint8_t id_1022 { 0 };
                                uint8_t id_1023 { shft_ref_105[id_1022] };
                                uint8_t id_1024 { 7 };
                                uint8_t id_1025 { uint8_t(id_1023 + id_1024) };
                                Void id_1026 { ((void)(shft_ref_105[id_1021] = id_1025), ::dessser::Void()) };
                                (void)id_1026;
                                uint8_t id_1027 { 128 };
                                bool id_1028 { bool(leb128_fst_108 >= id_1027) };
                                letpair_res_1007 = id_1028;
                              }
                              let_res_1006 = letpair_res_1007;
                            }
                            while_flag_1002 = let_res_1006;
                            if (while_flag_1002) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_1002);
                          (void)::dessser::Void();
                          uint8_t id_1029 { 0 };
                          uint32_t id_1030 { leb_ref_104[id_1029] };
                          uint8_t id_1031 { 0 };
                          Pointer id_1032 { p_ref_106[id_1031] };
                          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 id_1033 { id_1030, id_1032 };
                          let_res_1001 = id_1033;
                        }
                        let_res_999 = let_res_1001;
                      }
                      let_res_996 = let_res_999;
                    }
                    ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1034;
                    {
                      ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 dlist1_113 { let_res_996 };
                      ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1035;
                      {
                        auto dlist1_fst_114 { std::get<0>(dlist1_113) };
                        auto dlist1_snd_115 { std::get<1>(dlist1_113) };
                        Lst<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> endoflist_1036;
                        ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 id_1037 { endoflist_1036, dlist1_snd_115 };
                        Vec<1, ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7> id_1038 {  id_1037  };
                        ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1039;
                        {
                          Vec<1, ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7> inits_src_ref_116 { id_1038 };
                          int32_t id_1040 { 0L };
                          Vec<1, int32_t> id_1041 {  id_1040  };
                          {
                            Vec<1, int32_t> repeat_n_117 { id_1041 };
                            bool while_flag_1042 { true };
                            do {
                              int32_t id_1043 { int32_t(dlist1_fst_114) };
                              uint8_t id_1044 { 0 };
                              int32_t id_1045 { repeat_n_117[id_1044] };
                              bool id_1046 { bool(id_1043 > id_1045) };
                              while_flag_1042 = id_1046;
                              if (while_flag_1042) {
                                uint8_t id_1047 { 0 };
                                ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 id_1048 { inits_src_ref_116[id_1047] };
                                {
                                  ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 dlist2_118 { id_1048 };
                                  {
                                    auto dlist2_fst_119 { std::get<0>(dlist2_118) };
                                    auto dlist2_snd_120 { std::get<1>(dlist2_118) };
                                    uint8_t id_1049 { 0 };
                                    auto fun1050 { dessser::gen::field_name::of_row_binary };
                                    ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 id_1051 { fun1050(dlist2_snd_120) };
                                    ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1052;
                                    {
                                      ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 drec_121 { id_1051 };
                                      ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1053;
                                      {
                                        auto drec_fst_122 { std::get<0>(drec_121) };
                                        auto drec_snd_123 { std::get<1>(drec_121) };
                                        uint32_t id_1054 { 0U };
                                        Vec<1, uint32_t> id_1055 {  id_1054  };
                                        ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1056;
                                        {
                                          Vec<1, uint32_t> leb_ref_124 { id_1055 };
                                          uint8_t id_1057 { 0 };
                                          Vec<1, uint8_t> id_1058 {  id_1057  };
                                          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1059;
                                          {
                                            Vec<1, uint8_t> shft_ref_125 { id_1058 };
                                            Vec<1, Pointer> id_1060 {  drec_snd_123  };
                                            ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1061;
                                            {
                                              Vec<1, Pointer> p_ref_126 { id_1060 };
                                              bool while_flag_1062 { true };
                                              do {
                                                uint8_t id_1063 { 0 };
                                                Pointer id_1064 { p_ref_126[id_1063] };
                                                ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1065 { id_1064.readU8() };
                                                bool let_res_1066;
                                                {
                                                  ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 leb128_127 { id_1065 };
                                                  bool letpair_res_1067;
                                                  {
                                                    auto leb128_fst_128 { std::get<0>(leb128_127) };
                                                    auto leb128_snd_129 { std::get<1>(leb128_127) };
                                                    uint8_t id_1068 { 0 };
                                                    Void id_1069 { ((void)(p_ref_126[id_1068] = leb128_snd_129), ::dessser::Void()) };
                                                    (void)id_1069;
                                                    uint8_t id_1070 { 0 };
                                                    uint8_t id_1071 { 127 };
                                                    uint8_t id_1072 { uint8_t(leb128_fst_128 & id_1071) };
                                                    uint32_t id_1073 { uint32_t(id_1072) };
                                                    uint8_t id_1074 { 0 };
                                                    uint8_t id_1075 { shft_ref_125[id_1074] };
                                                    uint32_t id_1076 { uint32_t(id_1073 << id_1075) };
                                                    uint8_t id_1077 { 0 };
                                                    uint32_t id_1078 { leb_ref_124[id_1077] };
                                                    uint32_t id_1079 { uint32_t(id_1076 | id_1078) };
                                                    Void id_1080 { ((void)(leb_ref_124[id_1070] = id_1079), ::dessser::Void()) };
                                                    (void)id_1080;
                                                    uint8_t id_1081 { 0 };
                                                    uint8_t id_1082 { 0 };
                                                    uint8_t id_1083 { shft_ref_125[id_1082] };
                                                    uint8_t id_1084 { 7 };
                                                    uint8_t id_1085 { uint8_t(id_1083 + id_1084) };
                                                    Void id_1086 { ((void)(shft_ref_125[id_1081] = id_1085), ::dessser::Void()) };
                                                    (void)id_1086;
                                                    uint8_t id_1087 { 128 };
                                                    bool id_1088 { bool(leb128_fst_128 >= id_1087) };
                                                    letpair_res_1067 = id_1088;
                                                  }
                                                  let_res_1066 = letpair_res_1067;
                                                }
                                                while_flag_1062 = let_res_1066;
                                                if (while_flag_1062) {
                                                  (void)::dessser::Void();
                                                }
                                              } while (while_flag_1062);
                                              (void)::dessser::Void();
                                              uint8_t id_1089 { 0 };
                                              uint32_t id_1090 { leb_ref_124[id_1089] };
                                              uint8_t id_1091 { 0 };
                                              Pointer id_1092 { p_ref_126[id_1091] };
                                              ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 id_1093 { id_1090, id_1092 };
                                              let_res_1061 = id_1093;
                                            }
                                            let_res_1059 = let_res_1061;
                                          }
                                          let_res_1056 = let_res_1059;
                                        }
                                        ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc let_res_1094;
                                        {
                                          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 dlist1_133 { let_res_1056 };
                                          ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc letpair_res_1095;
                                          {
                                            auto dlist1_fst_134 { std::get<0>(dlist1_133) };
                                            auto dlist1_snd_135 { std::get<1>(dlist1_133) };
                                            Lst<std::string> endoflist_1096;
                                            ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc id_1097 { endoflist_1096, dlist1_snd_135 };
                                            Vec<1, ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc> id_1098 {  id_1097  };
                                            ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc let_res_1099;
                                            {
                                              Vec<1, ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc> inits_src_ref_136 { id_1098 };
                                              int32_t id_1100 { 0L };
                                              Vec<1, int32_t> id_1101 {  id_1100  };
                                              {
                                                Vec<1, int32_t> repeat_n_137 { id_1101 };
                                                bool while_flag_1102 { true };
                                                do {
                                                  int32_t id_1103 { int32_t(dlist1_fst_134) };
                                                  uint8_t id_1104 { 0 };
                                                  int32_t id_1105 { repeat_n_137[id_1104] };
                                                  bool id_1106 { bool(id_1103 > id_1105) };
                                                  while_flag_1102 = id_1106;
                                                  if (while_flag_1102) {
                                                    uint8_t id_1107 { 0 };
                                                    ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc id_1108 { inits_src_ref_136[id_1107] };
                                                    {
                                                      ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc dlist2_138 { id_1108 };
                                                      {
                                                        auto dlist2_fst_139 { std::get<0>(dlist2_138) };
                                                        auto dlist2_snd_140 { std::get<1>(dlist2_138) };
                                                        uint8_t id_1109 { 0 };
                                                        uint32_t id_1110 { 0U };
                                                        Vec<1, uint32_t> id_1111 {  id_1110  };
                                                        ::dessser::gen::pivot::t12fb9c475959b52bf7b17b155a955ffa let_res_1112;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_141 { id_1111 };
                                                          uint8_t id_1113 { 0 };
                                                          Vec<1, uint8_t> id_1114 {  id_1113  };
                                                          ::dessser::gen::pivot::t12fb9c475959b52bf7b17b155a955ffa let_res_1115;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_142 { id_1114 };
                                                            Vec<1, Pointer> id_1116 {  dlist2_snd_140  };
                                                            ::dessser::gen::pivot::t12fb9c475959b52bf7b17b155a955ffa let_res_1117;
                                                            {
                                                              Vec<1, Pointer> p_ref_143 { id_1116 };
                                                              bool while_flag_1118 { true };
                                                              do {
                                                                uint8_t id_1119 { 0 };
                                                                Pointer id_1120 { p_ref_143[id_1119] };
                                                                ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1121 { id_1120.readU8() };
                                                                bool let_res_1122;
                                                                {
                                                                  ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 leb128_144 { id_1121 };
                                                                  bool letpair_res_1123;
                                                                  {
                                                                    auto leb128_fst_145 { std::get<0>(leb128_144) };
                                                                    auto leb128_snd_146 { std::get<1>(leb128_144) };
                                                                    uint8_t id_1124 { 0 };
                                                                    Void id_1125 { ((void)(p_ref_143[id_1124] = leb128_snd_146), ::dessser::Void()) };
                                                                    (void)id_1125;
                                                                    uint8_t id_1126 { 0 };
                                                                    uint8_t id_1127 { 127 };
                                                                    uint8_t id_1128 { uint8_t(leb128_fst_145 & id_1127) };
                                                                    uint32_t id_1129 { uint32_t(id_1128) };
                                                                    uint8_t id_1130 { 0 };
                                                                    uint8_t id_1131 { shft_ref_142[id_1130] };
                                                                    uint32_t id_1132 { uint32_t(id_1129 << id_1131) };
                                                                    uint8_t id_1133 { 0 };
                                                                    uint32_t id_1134 { leb_ref_141[id_1133] };
                                                                    uint32_t id_1135 { uint32_t(id_1132 | id_1134) };
                                                                    Void id_1136 { ((void)(leb_ref_141[id_1126] = id_1135), ::dessser::Void()) };
                                                                    (void)id_1136;
                                                                    uint8_t id_1137 { 0 };
                                                                    uint8_t id_1138 { 0 };
                                                                    uint8_t id_1139 { shft_ref_142[id_1138] };
                                                                    uint8_t id_1140 { 7 };
                                                                    uint8_t id_1141 { uint8_t(id_1139 + id_1140) };
                                                                    Void id_1142 { ((void)(shft_ref_142[id_1137] = id_1141), ::dessser::Void()) };
                                                                    (void)id_1142;
                                                                    uint8_t id_1143 { 128 };
                                                                    bool id_1144 { bool(leb128_fst_145 >= id_1143) };
                                                                    letpair_res_1123 = id_1144;
                                                                  }
                                                                  let_res_1122 = letpair_res_1123;
                                                                }
                                                                while_flag_1118 = let_res_1122;
                                                                if (while_flag_1118) {
                                                                  (void)::dessser::Void();
                                                                }
                                                              } while (while_flag_1118);
                                                              (void)::dessser::Void();
                                                              uint8_t id_1145 { 0 };
                                                              uint32_t id_1146 { leb_ref_141[id_1145] };
                                                              Size id_1147 { Size(id_1146) };
                                                              uint8_t id_1148 { 0 };
                                                              Pointer id_1149 { p_ref_143[id_1148] };
                                                              ::dessser::gen::pivot::t12fb9c475959b52bf7b17b155a955ffa id_1150 { id_1147, id_1149 };
                                                              let_res_1117 = id_1150;
                                                            }
                                                            let_res_1115 = let_res_1117;
                                                          }
                                                          let_res_1112 = let_res_1115;
                                                        }
                                                        ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc let_res_1151;
                                                        {
                                                          ::dessser::gen::pivot::t12fb9c475959b52bf7b17b155a955ffa dstring1_147 { let_res_1112 };
                                                          ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc letpair_res_1152;
                                                          {
                                                            auto dstring1_fst_148 { std::get<0>(dstring1_147) };
                                                            auto dstring1_snd_149 { std::get<1>(dstring1_147) };
                                                            ::dessser::gen::pivot::t9ef6882174ae71a34a3c5ef6b29242fb id_1153 { dstring1_snd_149.readBytes(dstring1_fst_148) };
                                                            ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc letpair_res_1154;
                                                            {
                                                              auto dstring2_fst_151 { std::get<0>(id_1153) };
                                                              auto dstring2_snd_152 { std::get<1>(id_1153) };
                                                              std::string id_1155 { dstring2_fst_151.toString() };
                                                              Lst<std::string> id_1156 { id_1155, dlist2_fst_139 };
                                                              ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc id_1157 { id_1156, dstring2_snd_152 };
                                                              letpair_res_1154 = id_1157;
                                                            }
                                                            letpair_res_1152 = letpair_res_1154;
                                                          }
                                                          let_res_1151 = letpair_res_1152;
                                                        }
                                                        Void id_1158 { ((void)(inits_src_ref_136[id_1109] = let_res_1151), ::dessser::Void()) };
                                                        (void)id_1158;
                                                      }
                                                      (void)::dessser::Void();
                                                    }
                                                    (void)::dessser::Void();
                                                    uint8_t id_1159 { 0 };
                                                    uint8_t id_1160 { 0 };
                                                    int32_t id_1161 { repeat_n_137[id_1160] };
                                                    int32_t id_1162 { 1L };
                                                    int32_t id_1163 { int32_t(id_1161 + id_1162) };
                                                    Void id_1164 { ((void)(repeat_n_137[id_1159] = id_1163), ::dessser::Void()) };
                                                    (void)id_1164;
                                                    (void)id_1164;
                                                  }
                                                } while (while_flag_1102);
                                                (void)::dessser::Void();
                                              }
                                              (void)::dessser::Void();
                                              uint8_t id_1165 { 0 };
                                              ::dessser::gen::pivot::t941fe844f492c6f2281f99ea362423fc id_1166 { inits_src_ref_136[id_1165] };
                                              let_res_1099 = id_1166;
                                            }
                                            letpair_res_1095 = let_res_1099;
                                          }
                                          let_res_1094 = letpair_res_1095;
                                        }
                                        ::dessser::gen::pivot::t8293f5c3f24638d91c1ca307ed4a5278 letpair_res_1167;
                                        {
                                          auto dlist4_fst_157 { std::get<0>(let_res_1094) };
                                          auto dlist4_snd_158 { std::get<1>(let_res_1094) };
                                          Arr<std::string> id_1168 { dlist4_fst_157.toArrRev() };
                                          ::dessser::gen::pivot::t8293f5c3f24638d91c1ca307ed4a5278 id_1169 { id_1168, dlist4_snd_158 };
                                          letpair_res_1167 = id_1169;
                                        }
                                        ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1170;
                                        {
                                          ::dessser::gen::pivot::t8293f5c3f24638d91c1ca307ed4a5278 drec_159 { letpair_res_1167 };
                                          ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1171;
                                          {
                                            auto drec_fst_160 { std::get<0>(drec_159) };
                                            auto drec_snd_161 { std::get<1>(drec_159) };
                                            ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1172 { drec_snd_161.readU8() };
                                            ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1173;
                                            {
                                              auto dbool_fst_163 { std::get<0>(id_1172) };
                                              auto dbool_snd_164 { std::get<1>(id_1172) };
                                              uint8_t id_1174 { 0 };
                                              bool id_1175 { bool(dbool_fst_163 == id_1174) };
                                              bool id_1176 { ! id_1175 };
                                              ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 id_1177 { id_1176, dbool_snd_164 };
                                              letpair_res_1173 = id_1177;
                                            }
                                            ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1178;
                                            {
                                              ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 drec_165 { letpair_res_1173 };
                                              ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1179;
                                              {
                                                auto drec_fst_166 { std::get<0>(drec_165) };
                                                auto drec_snd_167 { std::get<1>(drec_165) };
                                                ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1180 { drec_snd_167.readU8() };
                                                ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1181;
                                                {
                                                  auto dbool_fst_169 { std::get<0>(id_1180) };
                                                  auto dbool_snd_170 { std::get<1>(id_1180) };
                                                  uint8_t id_1182 { 0 };
                                                  bool id_1183 { bool(dbool_fst_169 == id_1182) };
                                                  bool id_1184 { ! id_1183 };
                                                  ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 id_1185 { id_1184, dbool_snd_170 };
                                                  letpair_res_1181 = id_1185;
                                                }
                                                ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1186;
                                                {
                                                  ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 drec_171 { letpair_res_1181 };
                                                  ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1187;
                                                  {
                                                    auto drec_fst_172 { std::get<0>(drec_171) };
                                                    auto drec_snd_173 { std::get<1>(drec_171) };
                                                    ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1188 { drec_snd_173.readU8() };
                                                    ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1189;
                                                    {
                                                      auto dbool_fst_175 { std::get<0>(id_1188) };
                                                      auto dbool_snd_176 { std::get<1>(id_1188) };
                                                      uint8_t id_1190 { 0 };
                                                      bool id_1191 { bool(dbool_fst_175 == id_1190) };
                                                      bool id_1192 { ! id_1191 };
                                                      ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 id_1193 { id_1192, dbool_snd_176 };
                                                      letpair_res_1189 = id_1193;
                                                    }
                                                    ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1194;
                                                    {
                                                      ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 drec_177 { letpair_res_1189 };
                                                      ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1195;
                                                      {
                                                        auto drec_fst_178 { std::get<0>(drec_177) };
                                                        auto drec_snd_179 { std::get<1>(drec_177) };
                                                        ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1196 { drec_snd_179.readU8() };
                                                        ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1197;
                                                        {
                                                          auto dbool_fst_181 { std::get<0>(id_1196) };
                                                          auto dbool_snd_182 { std::get<1>(id_1196) };
                                                          uint8_t id_1198 { 0 };
                                                          bool id_1199 { bool(dbool_fst_181 == id_1198) };
                                                          bool id_1200 { ! id_1199 };
                                                          ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 id_1201 { id_1200, dbool_snd_182 };
                                                          letpair_res_1197 = id_1201;
                                                        }
                                                        ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1202;
                                                        {
                                                          ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 drec_183 { letpair_res_1197 };
                                                          ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1203;
                                                          {
                                                            auto drec_fst_184 { std::get<0>(drec_183) };
                                                            auto drec_snd_185 { std::get<1>(drec_183) };
                                                            ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1204 { drec_snd_185.readU8() };
                                                            ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1205;
                                                            {
                                                              auto dbool_fst_187 { std::get<0>(id_1204) };
                                                              auto dbool_snd_188 { std::get<1>(id_1204) };
                                                              uint8_t id_1206 { 0 };
                                                              bool id_1207 { bool(dbool_fst_187 == id_1206) };
                                                              bool id_1208 { ! id_1207 };
                                                              ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 id_1209 { id_1208, dbool_snd_188 };
                                                              letpair_res_1205 = id_1209;
                                                            }
                                                            ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1210;
                                                            {
                                                              ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 drec_189 { letpair_res_1205 };
                                                              ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1211;
                                                              {
                                                                auto drec_fst_190 { std::get<0>(drec_189) };
                                                                auto drec_snd_191 { std::get<1>(drec_189) };
                                                                ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1212 { drec_snd_191.readU8() };
                                                                ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1213;
                                                                {
                                                                  auto dbool_fst_193 { std::get<0>(id_1212) };
                                                                  auto dbool_snd_194 { std::get<1>(id_1212) };
                                                                  uint8_t id_1214 { 0 };
                                                                  bool id_1215 { bool(dbool_fst_193 == id_1214) };
                                                                  bool id_1216 { ! id_1215 };
                                                                  ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 id_1217 { id_1216, dbool_snd_194 };
                                                                  letpair_res_1213 = id_1217;
                                                                }
                                                                ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1218;
                                                                {
                                                                  ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 drec_195 { letpair_res_1213 };
                                                                  ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1219;
                                                                  {
                                                                    auto drec_fst_196 { std::get<0>(drec_195) };
                                                                    auto drec_snd_197 { std::get<1>(drec_195) };
                                                                    ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1220 { drec_snd_197.readU8() };
                                                                    ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1221;
                                                                    {
                                                                      auto dbool_fst_199 { std::get<0>(id_1220) };
                                                                      auto dbool_snd_200 { std::get<1>(id_1220) };
                                                                      uint8_t id_1222 { 0 };
                                                                      bool id_1223 { bool(dbool_fst_199 == id_1222) };
                                                                      bool id_1224 { ! id_1223 };
                                                                      ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 id_1225 { id_1224, dbool_snd_200 };
                                                                      letpair_res_1221 = id_1225;
                                                                    }
                                                                    ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1226;
                                                                    {
                                                                      ::dessser::gen::pivot::tf9a0a3fefc87c9e10a93d3a172850c26 drec_201 { letpair_res_1221 };
                                                                      ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1227;
                                                                      {
                                                                        auto drec_fst_202 { std::get<0>(drec_201) };
                                                                        auto drec_snd_203 { std::get<1>(drec_201) };
                                                                        uint32_t id_1228 { 0U };
                                                                        Vec<1, uint32_t> id_1229 {  id_1228  };
                                                                        ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1230;
                                                                        {
                                                                          Vec<1, uint32_t> leb_ref_204 { id_1229 };
                                                                          uint8_t id_1231 { 0 };
                                                                          Vec<1, uint8_t> id_1232 {  id_1231  };
                                                                          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1233;
                                                                          {
                                                                            Vec<1, uint8_t> shft_ref_205 { id_1232 };
                                                                            Vec<1, Pointer> id_1234 {  drec_snd_203  };
                                                                            ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1235;
                                                                            {
                                                                              Vec<1, Pointer> p_ref_206 { id_1234 };
                                                                              bool while_flag_1236 { true };
                                                                              do {
                                                                                uint8_t id_1237 { 0 };
                                                                                Pointer id_1238 { p_ref_206[id_1237] };
                                                                                ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1239 { id_1238.readU8() };
                                                                                bool let_res_1240;
                                                                                {
                                                                                  ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 leb128_207 { id_1239 };
                                                                                  bool letpair_res_1241;
                                                                                  {
                                                                                    auto leb128_fst_208 { std::get<0>(leb128_207) };
                                                                                    auto leb128_snd_209 { std::get<1>(leb128_207) };
                                                                                    uint8_t id_1242 { 0 };
                                                                                    Void id_1243 { ((void)(p_ref_206[id_1242] = leb128_snd_209), ::dessser::Void()) };
                                                                                    (void)id_1243;
                                                                                    uint8_t id_1244 { 0 };
                                                                                    uint8_t id_1245 { 127 };
                                                                                    uint8_t id_1246 { uint8_t(leb128_fst_208 & id_1245) };
                                                                                    uint32_t id_1247 { uint32_t(id_1246) };
                                                                                    uint8_t id_1248 { 0 };
                                                                                    uint8_t id_1249 { shft_ref_205[id_1248] };
                                                                                    uint32_t id_1250 { uint32_t(id_1247 << id_1249) };
                                                                                    uint8_t id_1251 { 0 };
                                                                                    uint32_t id_1252 { leb_ref_204[id_1251] };
                                                                                    uint32_t id_1253 { uint32_t(id_1250 | id_1252) };
                                                                                    Void id_1254 { ((void)(leb_ref_204[id_1244] = id_1253), ::dessser::Void()) };
                                                                                    (void)id_1254;
                                                                                    uint8_t id_1255 { 0 };
                                                                                    uint8_t id_1256 { 0 };
                                                                                    uint8_t id_1257 { shft_ref_205[id_1256] };
                                                                                    uint8_t id_1258 { 7 };
                                                                                    uint8_t id_1259 { uint8_t(id_1257 + id_1258) };
                                                                                    Void id_1260 { ((void)(shft_ref_205[id_1255] = id_1259), ::dessser::Void()) };
                                                                                    (void)id_1260;
                                                                                    uint8_t id_1261 { 128 };
                                                                                    bool id_1262 { bool(leb128_fst_208 >= id_1261) };
                                                                                    letpair_res_1241 = id_1262;
                                                                                  }
                                                                                  let_res_1240 = letpair_res_1241;
                                                                                }
                                                                                while_flag_1236 = let_res_1240;
                                                                                if (while_flag_1236) {
                                                                                  (void)::dessser::Void();
                                                                                }
                                                                              } while (while_flag_1236);
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_1263 { 0 };
                                                                              uint32_t id_1264 { leb_ref_204[id_1263] };
                                                                              uint8_t id_1265 { 0 };
                                                                              Pointer id_1266 { p_ref_206[id_1265] };
                                                                              ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 id_1267 { id_1264, id_1266 };
                                                                              let_res_1235 = id_1267;
                                                                            }
                                                                            let_res_1233 = let_res_1235;
                                                                          }
                                                                          let_res_1230 = let_res_1233;
                                                                        }
                                                                        ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 let_res_1268;
                                                                        {
                                                                          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 dlist1_213 { let_res_1230 };
                                                                          ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 letpair_res_1269;
                                                                          {
                                                                            auto dlist1_fst_214 { std::get<0>(dlist1_213) };
                                                                            auto dlist1_snd_215 { std::get<1>(dlist1_213) };
                                                                            Lst<double> endoflist_1270;
                                                                            ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 id_1271 { endoflist_1270, dlist1_snd_215 };
                                                                            Vec<1, ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3> id_1272 {  id_1271  };
                                                                            ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 let_res_1273;
                                                                            {
                                                                              Vec<1, ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3> inits_src_ref_216 { id_1272 };
                                                                              int32_t id_1274 { 0L };
                                                                              Vec<1, int32_t> id_1275 {  id_1274  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_217 { id_1275 };
                                                                                bool while_flag_1276 { true };
                                                                                do {
                                                                                  int32_t id_1277 { int32_t(dlist1_fst_214) };
                                                                                  uint8_t id_1278 { 0 };
                                                                                  int32_t id_1279 { repeat_n_217[id_1278] };
                                                                                  bool id_1280 { bool(id_1277 > id_1279) };
                                                                                  while_flag_1276 = id_1280;
                                                                                  if (while_flag_1276) {
                                                                                    uint8_t id_1281 { 0 };
                                                                                    ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 id_1282 { inits_src_ref_216[id_1281] };
                                                                                    {
                                                                                      ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 dlist2_218 { id_1282 };
                                                                                      {
                                                                                        auto dlist2_fst_219 { std::get<0>(dlist2_218) };
                                                                                        auto dlist2_snd_220 { std::get<1>(dlist2_218) };
                                                                                        uint8_t id_1283 { 0 };
                                                                                        ::dessser::gen::pivot::td2cd337bb3c8bc04d5603393d084985b id_1284 { dlist2_snd_220.readU64Le() };
                                                                                        ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 letpair_res_1285;
                                                                                        {
                                                                                          auto dfloat_fst_222 { std::get<0>(id_1284) };
                                                                                          auto dfloat_snd_223 { std::get<1>(id_1284) };
                                                                                          double id_1286 { float_of_qword(dfloat_fst_222) };
                                                                                          Lst<double> id_1287 { id_1286, dlist2_fst_219 };
                                                                                          ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 id_1288 { id_1287, dfloat_snd_223 };
                                                                                          letpair_res_1285 = id_1288;
                                                                                        }
                                                                                        Void id_1289 { ((void)(inits_src_ref_216[id_1283] = letpair_res_1285), ::dessser::Void()) };
                                                                                        (void)id_1289;
                                                                                      }
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                    (void)::dessser::Void();
                                                                                    uint8_t id_1290 { 0 };
                                                                                    uint8_t id_1291 { 0 };
                                                                                    int32_t id_1292 { repeat_n_217[id_1291] };
                                                                                    int32_t id_1293 { 1L };
                                                                                    int32_t id_1294 { int32_t(id_1292 + id_1293) };
                                                                                    Void id_1295 { ((void)(repeat_n_217[id_1290] = id_1294), ::dessser::Void()) };
                                                                                    (void)id_1295;
                                                                                    (void)id_1295;
                                                                                  }
                                                                                } while (while_flag_1276);
                                                                                (void)::dessser::Void();
                                                                              }
                                                                              (void)::dessser::Void();
                                                                              uint8_t id_1296 { 0 };
                                                                              ::dessser::gen::pivot::t9fb99a328772de0c291da3838a4bcfe3 id_1297 { inits_src_ref_216[id_1296] };
                                                                              let_res_1273 = id_1297;
                                                                            }
                                                                            letpair_res_1269 = let_res_1273;
                                                                          }
                                                                          let_res_1268 = letpair_res_1269;
                                                                        }
                                                                        ::dessser::gen::pivot::t72f695ab4fb53702c7aa92b69429e954 letpair_res_1298;
                                                                        {
                                                                          auto dlist4_fst_228 { std::get<0>(let_res_1268) };
                                                                          auto dlist4_snd_229 { std::get<1>(let_res_1268) };
                                                                          Arr<double> id_1299 { dlist4_fst_228.toArrRev() };
                                                                          ::dessser::gen::pivot::t72f695ab4fb53702c7aa92b69429e954 id_1300 { id_1299, dlist4_snd_229 };
                                                                          letpair_res_1298 = id_1300;
                                                                        }
                                                                        ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 let_res_1301;
                                                                        {
                                                                          ::dessser::gen::pivot::t72f695ab4fb53702c7aa92b69429e954 drec_230 { letpair_res_1298 };
                                                                          ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1302;
                                                                          {
                                                                            auto drec_fst_231 { std::get<0>(drec_230) };
                                                                            auto drec_snd_232 { std::get<1>(drec_230) };
                                                                            uint32_t id_1303 { 0U };
                                                                            Vec<1, uint32_t> id_1304 {  id_1303  };
                                                                            ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1305;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_233 { id_1304 };
                                                                              uint8_t id_1306 { 0 };
                                                                              Vec<1, uint8_t> id_1307 {  id_1306  };
                                                                              ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1308;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_234 { id_1307 };
                                                                                Vec<1, Pointer> id_1309 {  drec_snd_232  };
                                                                                ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1310;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_235 { id_1309 };
                                                                                  bool while_flag_1311 { true };
                                                                                  do {
                                                                                    uint8_t id_1312 { 0 };
                                                                                    Pointer id_1313 { p_ref_235[id_1312] };
                                                                                    ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1314 { id_1313.readU8() };
                                                                                    bool let_res_1315;
                                                                                    {
                                                                                      ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 leb128_236 { id_1314 };
                                                                                      bool letpair_res_1316;
                                                                                      {
                                                                                        auto leb128_fst_237 { std::get<0>(leb128_236) };
                                                                                        auto leb128_snd_238 { std::get<1>(leb128_236) };
                                                                                        uint8_t id_1317 { 0 };
                                                                                        Void id_1318 { ((void)(p_ref_235[id_1317] = leb128_snd_238), ::dessser::Void()) };
                                                                                        (void)id_1318;
                                                                                        uint8_t id_1319 { 0 };
                                                                                        uint8_t id_1320 { 127 };
                                                                                        uint8_t id_1321 { uint8_t(leb128_fst_237 & id_1320) };
                                                                                        uint32_t id_1322 { uint32_t(id_1321) };
                                                                                        uint8_t id_1323 { 0 };
                                                                                        uint8_t id_1324 { shft_ref_234[id_1323] };
                                                                                        uint32_t id_1325 { uint32_t(id_1322 << id_1324) };
                                                                                        uint8_t id_1326 { 0 };
                                                                                        uint32_t id_1327 { leb_ref_233[id_1326] };
                                                                                        uint32_t id_1328 { uint32_t(id_1325 | id_1327) };
                                                                                        Void id_1329 { ((void)(leb_ref_233[id_1319] = id_1328), ::dessser::Void()) };
                                                                                        (void)id_1329;
                                                                                        uint8_t id_1330 { 0 };
                                                                                        uint8_t id_1331 { 0 };
                                                                                        uint8_t id_1332 { shft_ref_234[id_1331] };
                                                                                        uint8_t id_1333 { 7 };
                                                                                        uint8_t id_1334 { uint8_t(id_1332 + id_1333) };
                                                                                        Void id_1335 { ((void)(shft_ref_234[id_1330] = id_1334), ::dessser::Void()) };
                                                                                        (void)id_1335;
                                                                                        uint8_t id_1336 { 128 };
                                                                                        bool id_1337 { bool(leb128_fst_237 >= id_1336) };
                                                                                        letpair_res_1316 = id_1337;
                                                                                      }
                                                                                      let_res_1315 = letpair_res_1316;
                                                                                    }
                                                                                    while_flag_1311 = let_res_1315;
                                                                                    if (while_flag_1311) {
                                                                                      (void)::dessser::Void();
                                                                                    }
                                                                                  } while (while_flag_1311);
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1338 { 0 };
                                                                                  uint32_t id_1339 { leb_ref_233[id_1338] };
                                                                                  uint8_t id_1340 { 0 };
                                                                                  Pointer id_1341 { p_ref_235[id_1340] };
                                                                                  ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 id_1342 { id_1339, id_1341 };
                                                                                  let_res_1310 = id_1342;
                                                                                }
                                                                                let_res_1308 = let_res_1310;
                                                                              }
                                                                              let_res_1305 = let_res_1308;
                                                                            }
                                                                            ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 let_res_1343;
                                                                            {
                                                                              ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 dlist1_242 { let_res_1305 };
                                                                              ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 letpair_res_1344;
                                                                              {
                                                                                auto dlist1_fst_243 { std::get<0>(dlist1_242) };
                                                                                auto dlist1_snd_244 { std::get<1>(dlist1_242) };
                                                                                Lst<::dessser::gen::pivot::top> endoflist_1345;
                                                                                ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 id_1346 { endoflist_1345, dlist1_snd_244 };
                                                                                Vec<1, ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30> id_1347 {  id_1346  };
                                                                                ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 let_res_1348;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30> inits_src_ref_245 { id_1347 };
                                                                                  int32_t id_1349 { 0L };
                                                                                  Vec<1, int32_t> id_1350 {  id_1349  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_246 { id_1350 };
                                                                                    bool while_flag_1351 { true };
                                                                                    do {
                                                                                      int32_t id_1352 { int32_t(dlist1_fst_243) };
                                                                                      uint8_t id_1353 { 0 };
                                                                                      int32_t id_1354 { repeat_n_246[id_1353] };
                                                                                      bool id_1355 { bool(id_1352 > id_1354) };
                                                                                      while_flag_1351 = id_1355;
                                                                                      if (while_flag_1351) {
                                                                                        uint8_t id_1356 { 0 };
                                                                                        ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 id_1357 { inits_src_ref_245[id_1356] };
                                                                                        {
                                                                                          ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 dlist2_247 { id_1357 };
                                                                                          {
                                                                                            auto dlist2_fst_248 { std::get<0>(dlist2_247) };
                                                                                            auto dlist2_snd_249 { std::get<1>(dlist2_247) };
                                                                                            uint8_t id_1358 { 0 };
                                                                                            ::dessser::gen::pivot::t7aae03d1a1a74f1dfca1edade27a0c74 id_1359 { top_of_row_binary(dlist2_snd_249) };
                                                                                            ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 letpair_res_1360;
                                                                                            {
                                                                                              auto dlist3_fst_251 { std::get<0>(id_1359) };
                                                                                              auto dlist3_snd_252 { std::get<1>(id_1359) };
                                                                                              Lst<::dessser::gen::pivot::top> id_1361 { dlist3_fst_251, dlist2_fst_248 };
                                                                                              ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 id_1362 { id_1361, dlist3_snd_252 };
                                                                                              letpair_res_1360 = id_1362;
                                                                                            }
                                                                                            Void id_1363 { ((void)(inits_src_ref_245[id_1358] = letpair_res_1360), ::dessser::Void()) };
                                                                                            (void)id_1363;
                                                                                          }
                                                                                          (void)::dessser::Void();
                                                                                        }
                                                                                        (void)::dessser::Void();
                                                                                        uint8_t id_1364 { 0 };
                                                                                        uint8_t id_1365 { 0 };
                                                                                        int32_t id_1366 { repeat_n_246[id_1365] };
                                                                                        int32_t id_1367 { 1L };
                                                                                        int32_t id_1368 { int32_t(id_1366 + id_1367) };
                                                                                        Void id_1369 { ((void)(repeat_n_246[id_1364] = id_1368), ::dessser::Void()) };
                                                                                        (void)id_1369;
                                                                                        (void)id_1369;
                                                                                      }
                                                                                    } while (while_flag_1351);
                                                                                    (void)::dessser::Void();
                                                                                  }
                                                                                  (void)::dessser::Void();
                                                                                  uint8_t id_1370 { 0 };
                                                                                  ::dessser::gen::pivot::t2fb7622ec11d8dfa2277a4f79bf3dc30 id_1371 { inits_src_ref_245[id_1370] };
                                                                                  let_res_1348 = id_1371;
                                                                                }
                                                                                letpair_res_1344 = let_res_1348;
                                                                              }
                                                                              let_res_1343 = letpair_res_1344;
                                                                            }
                                                                            ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 letpair_res_1372;
                                                                            {
                                                                              auto dlist4_fst_254 { std::get<0>(let_res_1343) };
                                                                              auto dlist4_snd_255 { std::get<1>(let_res_1343) };
                                                                              Arr<::dessser::gen::pivot::top> id_1373 { dlist4_fst_254.toArrRev() };
                                                                              ::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0 id_1374 { drec_fst_122, drec_fst_160, drec_fst_166, drec_fst_172, drec_fst_178, drec_fst_184, drec_fst_190, drec_fst_196, drec_fst_202, drec_fst_231, id_1373 };
                                                                              Lst<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_1375 { id_1374, dlist2_fst_119 };
                                                                              ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 id_1376 { id_1375, dlist4_snd_255 };
                                                                              letpair_res_1372 = id_1376;
                                                                            }
                                                                            letpair_res_1302 = letpair_res_1372;
                                                                          }
                                                                          let_res_1301 = letpair_res_1302;
                                                                        }
                                                                        letpair_res_1227 = let_res_1301;
                                                                      }
                                                                      let_res_1226 = letpair_res_1227;
                                                                    }
                                                                    letpair_res_1219 = let_res_1226;
                                                                  }
                                                                  let_res_1218 = letpair_res_1219;
                                                                }
                                                                letpair_res_1211 = let_res_1218;
                                                              }
                                                              let_res_1210 = letpair_res_1211;
                                                            }
                                                            letpair_res_1203 = let_res_1210;
                                                          }
                                                          let_res_1202 = letpair_res_1203;
                                                        }
                                                        letpair_res_1195 = let_res_1202;
                                                      }
                                                      let_res_1194 = letpair_res_1195;
                                                    }
                                                    letpair_res_1187 = let_res_1194;
                                                  }
                                                  let_res_1186 = letpair_res_1187;
                                                }
                                                letpair_res_1179 = let_res_1186;
                                              }
                                              let_res_1178 = letpair_res_1179;
                                            }
                                            letpair_res_1171 = let_res_1178;
                                          }
                                          let_res_1170 = letpair_res_1171;
                                        }
                                        letpair_res_1053 = let_res_1170;
                                      }
                                      let_res_1052 = letpair_res_1053;
                                    }
                                    Void id_1377 { ((void)(inits_src_ref_116[id_1049] = let_res_1052), ::dessser::Void()) };
                                    (void)id_1377;
                                  }
                                  (void)::dessser::Void();
                                }
                                (void)::dessser::Void();
                                uint8_t id_1378 { 0 };
                                uint8_t id_1379 { 0 };
                                int32_t id_1380 { repeat_n_117[id_1379] };
                                int32_t id_1381 { 1L };
                                int32_t id_1382 { int32_t(id_1380 + id_1381) };
                                Void id_1383 { ((void)(repeat_n_117[id_1378] = id_1382), ::dessser::Void()) };
                                (void)id_1383;
                                (void)id_1383;
                              }
                            } while (while_flag_1042);
                            (void)::dessser::Void();
                          }
                          (void)::dessser::Void();
                          uint8_t id_1384 { 0 };
                          ::dessser::gen::pivot::ta0e4b5c632ab9a7e56d2036a227274e7 id_1385 { inits_src_ref_116[id_1384] };
                          let_res_1039 = id_1385;
                        }
                        letpair_res_1035 = let_res_1039;
                      }
                      let_res_1034 = letpair_res_1035;
                    }
                    ::dessser::gen::pivot::t6eabb53e3ce0d815c25a2418c3f9e53e letpair_res_1386;
                    {
                      auto dlist4_fst_263 { std::get<0>(let_res_1034) };
                      auto dlist4_snd_264 { std::get<1>(let_res_1034) };
                      Arr<::dessser::gen::pivot::t26b95203b7d109bdca2c935b0d6e7ca0> id_1387 { dlist4_fst_263.toArrRev() };
                      ::dessser::gen::pivot::t6eabb53e3ce0d815c25a2418c3f9e53e id_1388 { id_1387, dlist4_snd_264 };
                      letpair_res_1386 = id_1388;
                    }
                    ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 let_res_1389;
                    {
                      ::dessser::gen::pivot::t6eabb53e3ce0d815c25a2418c3f9e53e drec_265 { letpair_res_1386 };
                      ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_1390;
                      {
                        auto drec_fst_266 { std::get<0>(drec_265) };
                        auto drec_snd_267 { std::get<1>(drec_265) };
                        uint32_t id_1391 { 0U };
                        Vec<1, uint32_t> id_1392 {  id_1391  };
                        ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1393;
                        {
                          Vec<1, uint32_t> leb_ref_268 { id_1392 };
                          uint8_t id_1394 { 0 };
                          Vec<1, uint8_t> id_1395 {  id_1394  };
                          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1396;
                          {
                            Vec<1, uint8_t> shft_ref_269 { id_1395 };
                            Vec<1, Pointer> id_1397 {  drec_snd_267  };
                            ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 let_res_1398;
                            {
                              Vec<1, Pointer> p_ref_270 { id_1397 };
                              bool while_flag_1399 { true };
                              do {
                                uint8_t id_1400 { 0 };
                                Pointer id_1401 { p_ref_270[id_1400] };
                                ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 id_1402 { id_1401.readU8() };
                                bool let_res_1403;
                                {
                                  ::dessser::gen::pivot::t1a5d74abf838df33f185a72a8912f5c9 leb128_271 { id_1402 };
                                  bool letpair_res_1404;
                                  {
                                    auto leb128_fst_272 { std::get<0>(leb128_271) };
                                    auto leb128_snd_273 { std::get<1>(leb128_271) };
                                    uint8_t id_1405 { 0 };
                                    Void id_1406 { ((void)(p_ref_270[id_1405] = leb128_snd_273), ::dessser::Void()) };
                                    (void)id_1406;
                                    uint8_t id_1407 { 0 };
                                    uint8_t id_1408 { 127 };
                                    uint8_t id_1409 { uint8_t(leb128_fst_272 & id_1408) };
                                    uint32_t id_1410 { uint32_t(id_1409) };
                                    uint8_t id_1411 { 0 };
                                    uint8_t id_1412 { shft_ref_269[id_1411] };
                                    uint32_t id_1413 { uint32_t(id_1410 << id_1412) };
                                    uint8_t id_1414 { 0 };
                                    uint32_t id_1415 { leb_ref_268[id_1414] };
                                    uint32_t id_1416 { uint32_t(id_1413 | id_1415) };
                                    Void id_1417 { ((void)(leb_ref_268[id_1407] = id_1416), ::dessser::Void()) };
                                    (void)id_1417;
                                    uint8_t id_1418 { 0 };
                                    uint8_t id_1419 { 0 };
                                    uint8_t id_1420 { shft_ref_269[id_1419] };
                                    uint8_t id_1421 { 7 };
                                    uint8_t id_1422 { uint8_t(id_1420 + id_1421) };
                                    Void id_1423 { ((void)(shft_ref_269[id_1418] = id_1422), ::dessser::Void()) };
                                    (void)id_1423;
                                    uint8_t id_1424 { 128 };
                                    bool id_1425 { bool(leb128_fst_272 >= id_1424) };
                                    letpair_res_1404 = id_1425;
                                  }
                                  let_res_1403 = letpair_res_1404;
                                }
                                while_flag_1399 = let_res_1403;
                                if (while_flag_1399) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_1399);
                              (void)::dessser::Void();
                              uint8_t id_1426 { 0 };
                              uint32_t id_1427 { leb_ref_268[id_1426] };
                              uint8_t id_1428 { 0 };
                              Pointer id_1429 { p_ref_270[id_1428] };
                              ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 id_1430 { id_1427, id_1429 };
                              let_res_1398 = id_1430;
                            }
                            let_res_1396 = let_res_1398;
                          }
                          let_res_1393 = let_res_1396;
                        }
                        ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1431;
                        {
                          ::dessser::gen::pivot::t491c44439106a32f896827242e8e76a1 dlist1_277 { let_res_1393 };
                          ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1432;
                          {
                            auto dlist1_fst_278 { std::get<0>(dlist1_277) };
                            auto dlist1_snd_279 { std::get<1>(dlist1_277) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_1433;
                            ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1434 { endoflist_1433, dlist1_snd_279 };
                            Vec<1, ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1435 {  id_1434  };
                            ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1436;
                            {
                              Vec<1, ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_280 { id_1435 };
                              int32_t id_1437 { 0L };
                              Vec<1, int32_t> id_1438 {  id_1437  };
                              {
                                Vec<1, int32_t> repeat_n_281 { id_1438 };
                                bool while_flag_1439 { true };
                                do {
                                  int32_t id_1440 { int32_t(dlist1_fst_278) };
                                  uint8_t id_1441 { 0 };
                                  int32_t id_1442 { repeat_n_281[id_1441] };
                                  bool id_1443 { bool(id_1440 > id_1442) };
                                  while_flag_1439 = id_1443;
                                  if (while_flag_1439) {
                                    uint8_t id_1444 { 0 };
                                    ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1445 { inits_src_ref_280[id_1444] };
                                    {
                                      ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_282 { id_1445 };
                                      {
                                        auto dlist2_fst_283 { std::get<0>(dlist2_282) };
                                        auto dlist2_snd_284 { std::get<1>(dlist2_282) };
                                        uint8_t id_1446 { 0 };
                                        auto fun1447 { dessser::gen::field_name::of_row_binary };
                                        ::dessser::gen::pivot::t18cecf882d7ac80cef37dfe6b22279d4 id_1448 { fun1447(dlist2_snd_284) };
                                        ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1449;
                                        {
                                          auto dlist3_fst_286 { std::get<0>(id_1448) };
                                          auto dlist3_snd_287 { std::get<1>(id_1448) };
                                          Lst<dessser::gen::field_name::t_ext> id_1450 { dlist3_fst_286, dlist2_fst_283 };
                                          ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1451 { id_1450, dlist3_snd_287 };
                                          letpair_res_1449 = id_1451;
                                        }
                                        Void id_1452 { ((void)(inits_src_ref_280[id_1446] = letpair_res_1449), ::dessser::Void()) };
                                        (void)id_1452;
                                      }
                                      (void)::dessser::Void();
                                    }
                                    (void)::dessser::Void();
                                    uint8_t id_1453 { 0 };
                                    uint8_t id_1454 { 0 };
                                    int32_t id_1455 { repeat_n_281[id_1454] };
                                    int32_t id_1456 { 1L };
                                    int32_t id_1457 { int32_t(id_1455 + id_1456) };
                                    Void id_1458 { ((void)(repeat_n_281[id_1453] = id_1457), ::dessser::Void()) };
                                    (void)id_1458;
                                    (void)id_1458;
                                  }
                                } while (while_flag_1439);
                                (void)::dessser::Void();
                              }
                              (void)::dessser::Void();
                              uint8_t id_1459 { 0 };
                              ::dessser::gen::pivot::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1460 { inits_src_ref_280[id_1459] };
                              let_res_1436 = id_1460;
                            }
                            letpair_res_1432 = let_res_1436;
                          }
                          let_res_1431 = letpair_res_1432;
                        }
                        ::dessser::gen::pivot::t5f8c7f0089c13d8e90b66cd6d8db085d letpair_res_1461;
                        {
                          auto dlist4_fst_289 { std::get<0>(let_res_1431) };
                          auto dlist4_snd_290 { std::get<1>(let_res_1431) };
                          Arr<dessser::gen::field_name::t_ext> id_1462 { dlist4_fst_289.toArrRev() };
                          ::dessser::gen::pivot::t5f8c7f0089c13d8e90b66cd6d8db085d id_1463 { id_1462, dlist4_snd_290 };
                          letpair_res_1461 = id_1463;
                        }
                        ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 let_res_1464;
                        {
                          ::dessser::gen::pivot::t5f8c7f0089c13d8e90b66cd6d8db085d drec_291 { letpair_res_1461 };
                          ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_1465;
                          {
                            auto drec_fst_292 { std::get<0>(drec_291) };
                            auto drec_snd_293 { std::get<1>(drec_291) };
                            ::dessser::gen::pivot::td2cd337bb3c8bc04d5603393d084985b id_1466 { drec_snd_293.readU64Le() };
                            ::dessser::gen::pivot::t9a758baeff17224a77e1a522010b4168 letpair_res_1467;
                            {
                              auto dfloat_fst_295 { std::get<0>(id_1466) };
                              auto dfloat_snd_296 { std::get<1>(id_1466) };
                              double id_1468 { float_of_qword(dfloat_fst_295) };
                              ::dessser::gen::pivot::t9a758baeff17224a77e1a522010b4168 id_1469 { id_1468, dfloat_snd_296 };
                              letpair_res_1467 = id_1469;
                            }
                            ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 let_res_1470;
                            {
                              ::dessser::gen::pivot::t9a758baeff17224a77e1a522010b4168 drec_297 { letpair_res_1467 };
                              ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_1471;
                              {
                                auto drec_fst_298 { std::get<0>(drec_297) };
                                auto drec_snd_299 { std::get<1>(drec_297) };
                                ::dessser::gen::pivot::td2cd337bb3c8bc04d5603393d084985b id_1472 { drec_snd_299.readU64Le() };
                                ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_1473;
                                {
                                  auto dfloat_fst_301 { std::get<0>(id_1472) };
                                  auto dfloat_snd_302 { std::get<1>(id_1472) };
                                  double id_1474 { float_of_qword(dfloat_fst_301) };
                                  ::dessser::gen::pivot::t id_1475 { drec_fst_70, drec_fst_96, drec_fst_99, drec_fst_102, drec_fst_266, drec_fst_292, drec_fst_298, id_1474 };
                                  ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 id_1476 { id_1475, dfloat_snd_302 };
                                  letpair_res_1473 = id_1476;
                                }
                                letpair_res_1471 = letpair_res_1473;
                              }
                              let_res_1470 = letpair_res_1471;
                            }
                            letpair_res_1465 = let_res_1470;
                          }
                          let_res_1464 = letpair_res_1465;
                        }
                        letpair_res_1390 = let_res_1464;
                      }
                      let_res_1389 = letpair_res_1390;
                    }
                    letpair_res_993 = let_res_1389;
                  }
                  let_res_992 = letpair_res_993;
                }
                letpair_res_989 = let_res_992;
              }
              let_res_988 = letpair_res_989;
            }
            letpair_res_985 = let_res_988;
          }
          let_res_984 = letpair_res_985;
        }
        letpair_res_910 = let_res_984;
      }
      let_res_909 = letpair_res_910;
    }
    return let_res_909;
  }
   };
  return fun906;
}
std::function<::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_307" "make_snd_308" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_307") (identifier "make_snd_308"))))
 */
static std::function<::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519(Pointer &)> fun1477 { [&](Pointer p_0) {
    ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 id_1478 { of_row_binary(p_0) };
    ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 letpair_res_1479;
    {
      auto make_fst_307 { std::get<0>(id_1478) };
      auto make_snd_308 { std::get<1>(id_1478) };
      ::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519 id_1480 { make_fst_307, make_snd_308 };
      letpair_res_1479 = id_1480;
    }
    return letpair_res_1479;
  }
   };
  return fun1477;
}
std::function<::dessser::gen::pivot::t8ee925d72cfbfe36ed4ad9adbc5f4519(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{from: $fq_name; where: $simple_filter[]; type-field: $field_name; value-field: $field_name; fields: {name: $field_name; types: STRING[]; count: BOOL; first: BOOL; last: BOOL; min: BOOL; max: BOOL; sum: BOOL; avg: BOOL; percentiles: FLOAT[]; tops: (top AS {n: U16; by: $field_name?})[]}[]; group-by: $field_name[]; duration: FLOAT; max-lateness: FLOAT}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::pivot::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::pivot::t &,Pointer &)> fun1481 { [&](::dessser::gen::pivot::t p_0, Pointer p_1) {
    Pointer id_1482 { to_row_binary(p_0, p_1) };
    return id_1482;
  }
   };
  return fun1481;
}
std::function<Pointer(::dessser::gen::pivot::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
