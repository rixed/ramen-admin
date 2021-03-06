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
#include "desssergen/fq_function_name.h"

namespace dessser::gen::dashboard_widget {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
enum representation {
  Unused,
  Independent,
  Stacked,
  StackCentered,
};

constexpr size_t representation_size { 4 };
struct field {
  double opacity;
  uint32_t color;
  ::dessser::gen::dashboard_widget::representation representation;
  std::string column;
  Arr<std::string> factors;
  uint8_t axis;
  field(double opacity_, uint32_t color_, ::dessser::gen::dashboard_widget::representation representation_, std::string column_, Arr<std::string> factors_, uint8_t axis_) : opacity(opacity_), color(color_), representation(representation_), column(column_), factors(factors_), axis(axis_) {}
  field() = default;
};
inline bool operator==(field const &a, field const &b) {
  return a.opacity == b.opacity && a.color == b.color && a.representation == b.representation && a.column == b.column && a.factors == b.factors && a.axis == b.axis;
}

inline bool operator!=(field const &a, field const &b) {
  return !operator==(a, b);
}
struct source {
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  Arr<::dessser::gen::dashboard_widget::field> fields;
  source(dessser::gen::fq_function_name::t_ext name_, bool visible_, Arr<::dessser::gen::dashboard_widget::field> fields_) : name(name_), visible(visible_), fields(fields_) {}
  source() = default;
};
inline bool operator==(source const &a, source const &b) {
  return ::dessser::gen::fq_function_name::Deref(a.name) == ::dessser::gen::fq_function_name::Deref(b.name) && a.visible == b.visible && a.fields == b.fields;
}

inline bool operator!=(source const &a, source const &b) {
  return !operator==(a, b);
}
enum scale {
  Linear,
  Logarithmic,
};

constexpr size_t scale_size { 2 };
struct axis {
  bool left;
  bool force_zero;
  ::dessser::gen::dashboard_widget::scale scale;
  axis(bool left_, bool force_zero_, ::dessser::gen::dashboard_widget::scale scale_) : left(left_), force_zero(force_zero_), scale(scale_) {}
  axis() = default;
};
inline bool operator==(axis const &a, axis const &b) {
  return a.left == b.left && a.force_zero == b.force_zero && a.scale == b.scale;
}

inline bool operator!=(axis const &a, axis const &b) {
  return !operator==(a, b);
}
enum type {
  Plot,
};

constexpr size_t type_size { 1 };
struct chart {
  std::string title;
  ::dessser::gen::dashboard_widget::type type;
  Arr<::dessser::gen::dashboard_widget::axis> axes;
  Arr<::dessser::gen::dashboard_widget::source> sources;
  chart(std::string title_, ::dessser::gen::dashboard_widget::type type_, Arr<::dessser::gen::dashboard_widget::axis> axes_, Arr<::dessser::gen::dashboard_widget::source> sources_) : title(title_), type(type_), axes(axes_), sources(sources_) {}
  chart() = default;
};
inline bool operator==(chart const &a, chart const &b) {
  return a.title == b.title && a.type == b.type && a.axes == b.axes && a.sources == b.sources;
}

inline bool operator!=(chart const &a, chart const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  std::string, // Text
  ::dessser::gen::dashboard_widget::chart // Chart
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Text
    case 1: return std::get<1>(a) == std::get<1>(b); // Chart
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tc1bf32b9478802aec66a4e35731c20e3 : public std::tuple<
  ::dessser::gen::dashboard_widget::representation,
  Pointer
> {
  using tuple::tuple;
  tc1bf32b9478802aec66a4e35731c20e3(std::tuple<::dessser::gen::dashboard_widget::representation, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::representation, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc1bf32b9478802aec66a4e35731c20e3 const &a, tc1bf32b9478802aec66a4e35731c20e3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc1bf32b9478802aec66a4e35731c20e3 const &a, tc1bf32b9478802aec66a4e35731c20e3 const &b) {
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
struct t749cc30fe799f5ca72ede312d96197a8 : public std::tuple<
  ::dessser::gen::dashboard_widget::field,
  Pointer
> {
  using tuple::tuple;
  t749cc30fe799f5ca72ede312d96197a8(std::tuple<::dessser::gen::dashboard_widget::field, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::field, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t749cc30fe799f5ca72ede312d96197a8 const &a, t749cc30fe799f5ca72ede312d96197a8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t749cc30fe799f5ca72ede312d96197a8 const &a, t749cc30fe799f5ca72ede312d96197a8 const &b) {
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
struct t98c1df55b587e112639e677d8810f238 : public std::tuple<
  ::dessser::gen::dashboard_widget::source,
  Pointer
> {
  using tuple::tuple;
  t98c1df55b587e112639e677d8810f238(std::tuple<::dessser::gen::dashboard_widget::source, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::source, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t98c1df55b587e112639e677d8810f238 const &a, t98c1df55b587e112639e677d8810f238 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t98c1df55b587e112639e677d8810f238 const &a, t98c1df55b587e112639e677d8810f238 const &b) {
  return !operator==(a, b);
}
struct tafdf48d85e3efdf5b24e3fa2741562be : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tafdf48d85e3efdf5b24e3fa2741562be(std::tuple<dessser::gen::fq_function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tafdf48d85e3efdf5b24e3fa2741562be const &a, tafdf48d85e3efdf5b24e3fa2741562be const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tafdf48d85e3efdf5b24e3fa2741562be const &a, tafdf48d85e3efdf5b24e3fa2741562be const &b) {
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
struct tcb7b01c316b4ea76130319ada34983b6 : public std::tuple<
  Lst<::dessser::gen::dashboard_widget::field>,
  Pointer
> {
  using tuple::tuple;
  tcb7b01c316b4ea76130319ada34983b6(std::tuple<Lst<::dessser::gen::dashboard_widget::field>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::dashboard_widget::field>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcb7b01c316b4ea76130319ada34983b6 const &a, tcb7b01c316b4ea76130319ada34983b6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcb7b01c316b4ea76130319ada34983b6 const &a, tcb7b01c316b4ea76130319ada34983b6 const &b) {
  return !operator==(a, b);
}
struct te827b27d5f16cf2c14d368442731b974 : public std::tuple<
  ::dessser::gen::dashboard_widget::scale,
  Pointer
> {
  using tuple::tuple;
  te827b27d5f16cf2c14d368442731b974(std::tuple<::dessser::gen::dashboard_widget::scale, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::scale, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te827b27d5f16cf2c14d368442731b974 const &a, te827b27d5f16cf2c14d368442731b974 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te827b27d5f16cf2c14d368442731b974 const &a, te827b27d5f16cf2c14d368442731b974 const &b) {
  return !operator==(a, b);
}
struct t9a8d4d78c988f5d0b49fc7d7daee92e4 : public std::tuple<
  ::dessser::gen::dashboard_widget::axis,
  Pointer
> {
  using tuple::tuple;
  t9a8d4d78c988f5d0b49fc7d7daee92e4(std::tuple<::dessser::gen::dashboard_widget::axis, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::axis, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a8d4d78c988f5d0b49fc7d7daee92e4 const &a, t9a8d4d78c988f5d0b49fc7d7daee92e4 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a8d4d78c988f5d0b49fc7d7daee92e4 const &a, t9a8d4d78c988f5d0b49fc7d7daee92e4 const &b) {
  return !operator==(a, b);
}
struct td081d579116db2384d0a1d4e0dd44fc6 : public std::tuple<
  ::dessser::gen::dashboard_widget::type,
  Pointer
> {
  using tuple::tuple;
  td081d579116db2384d0a1d4e0dd44fc6(std::tuple<::dessser::gen::dashboard_widget::type, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::type, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td081d579116db2384d0a1d4e0dd44fc6 const &a, td081d579116db2384d0a1d4e0dd44fc6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td081d579116db2384d0a1d4e0dd44fc6 const &a, td081d579116db2384d0a1d4e0dd44fc6 const &b) {
  return !operator==(a, b);
}
struct t62f7c15233495a7fd1923d1cb45a742f : public std::tuple<
  ::dessser::gen::dashboard_widget::chart,
  Pointer
> {
  using tuple::tuple;
  t62f7c15233495a7fd1923d1cb45a742f(std::tuple<::dessser::gen::dashboard_widget::chart, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::chart, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t62f7c15233495a7fd1923d1cb45a742f const &a, t62f7c15233495a7fd1923d1cb45a742f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t62f7c15233495a7fd1923d1cb45a742f const &a, t62f7c15233495a7fd1923d1cb45a742f const &b) {
  return !operator==(a, b);
}
struct t4c3e9d1a56152b42310744919f17b6d8 : public std::tuple<
  Lst<::dessser::gen::dashboard_widget::axis>,
  Pointer
> {
  using tuple::tuple;
  t4c3e9d1a56152b42310744919f17b6d8(std::tuple<Lst<::dessser::gen::dashboard_widget::axis>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::dashboard_widget::axis>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4c3e9d1a56152b42310744919f17b6d8 const &a, t4c3e9d1a56152b42310744919f17b6d8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4c3e9d1a56152b42310744919f17b6d8 const &a, t4c3e9d1a56152b42310744919f17b6d8 const &b) {
  return !operator==(a, b);
}
struct t747bb378febaae5fd0b66480643426e2 : public std::tuple<
  Arr<::dessser::gen::dashboard_widget::axis>,
  Pointer
> {
  using tuple::tuple;
  t747bb378febaae5fd0b66480643426e2(std::tuple<Arr<::dessser::gen::dashboard_widget::axis>, Pointer> p)
    : std::tuple<Arr<::dessser::gen::dashboard_widget::axis>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t747bb378febaae5fd0b66480643426e2 const &a, t747bb378febaae5fd0b66480643426e2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t747bb378febaae5fd0b66480643426e2 const &a, t747bb378febaae5fd0b66480643426e2 const &b) {
  return !operator==(a, b);
}
struct tddb6f2327241eb998908208af4a5b9a0 : public std::tuple<
  Lst<::dessser::gen::dashboard_widget::source>,
  Pointer
> {
  using tuple::tuple;
  tddb6f2327241eb998908208af4a5b9a0(std::tuple<Lst<::dessser::gen::dashboard_widget::source>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::dashboard_widget::source>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tddb6f2327241eb998908208af4a5b9a0 const &a, tddb6f2327241eb998908208af4a5b9a0 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tddb6f2327241eb998908208af4a5b9a0 const &a, tddb6f2327241eb998908208af4a5b9a0 const &b) {
  return !operator==(a, b);
}
struct t02960804d32fdda6972311266df50308 : public std::tuple<
  ::dessser::gen::dashboard_widget::t,
  Pointer
> {
  using tuple::tuple;
  t02960804d32fdda6972311266df50308(std::tuple<::dessser::gen::dashboard_widget::t, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t02960804d32fdda6972311266df50308 const &a, t02960804d32fdda6972311266df50308 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t02960804d32fdda6972311266df50308 const &a, t02960804d32fdda6972311266df50308 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Unused Void | Independent Void | Stacked Void | StackCentered Void]" "Ptr")
      (let "ssum_dst_384" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_384")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_384") (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_384") (seq (assert (eq (label-of (param 0)) (u16 3))) (identifier "ssum_dst_384")))))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::representation const &,Pointer &)> representation_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::representation const &,Pointer &)> fun0 { [&](::dessser::gen::dashboard_widget::representation p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_384 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_384;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t(p_0) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          choose_res_11 = ssum_dst_384;
        } else {
          uint16_t id_12 { 2 };
          uint16_t id_13 { uint16_t(p_0) };
          bool id_14 { bool(id_12 == id_13) };
          Pointer choose_res_15;
          if (id_14) {
            choose_res_15 = ssum_dst_384;
          } else {
            uint16_t id_16 { uint16_t(p_0) };
            uint16_t id_17 { 3 };
            bool id_18 { bool(id_16 == id_17) };
            Void id_19 { ((void)(assert(id_18)), ::dessser::Void()) };
            (void)id_19;
            choose_res_15 = ssum_dst_384;
          }
          choose_res_11 = choose_res_15;
        }
        choose_res_7 = choose_res_11;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::dashboard_widget::representation const &,Pointer &)> representation_to_row_binary(representation_to_row_binary_init());

/* 
    (fun ("{opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8}" "Ptr")
      (let "srec_dst_398"
        (let "srec_dst_390"
          (let "srec_dst_387"
            (let "srec_dst_386" (let "srec_dst_385" (write-u64 little-endian (param 1) (u64-of-float (get-field "opacity" (param 0)))) (write-u32 little-endian (identifier "srec_dst_385") (get-field "color" (param 0))))
              (apply (identifier "representation-to-row-binary") (get-field "representation" (param 0)) (identifier "srec_dst_386")))
            (write-bytes
              (let "leb128_sz_388" (make-vec (string-length (get-field "column" (param 0))))
                (let "leb128_ptr_389" (make-vec (identifier "srec_dst_387"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_389")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_389"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_388"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_388"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_388"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_388") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_388")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_388")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_389"))))) 
              (bytes-of-string (get-field "column" (param 0)))))
          (let "dst_ref_393"
            (make-vec
              (let "leb128_sz_391" (make-vec (cardinality (get-field "factors" (param 0))))
                (let "leb128_ptr_392" (make-vec (identifier "srec_dst_390"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_392")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_392"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_391"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_391"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_391"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_391") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_391")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_391")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_392"))))))
            (let "n_ref_394" (make-vec (i32 0))
              (seq
                (for-each "x_395" (get-field "factors" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_393")
                      (write-bytes
                        (let "leb128_sz_396" (make-vec (string-length (identifier "x_395")))
                          (let "leb128_ptr_397" (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_393")))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_397")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_397"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_396"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_396"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_396"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_396") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_396")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_396")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_397"))))) 
                        (bytes-of-string (identifier "x_395")))) (set-vec (u8 0) (identifier "n_ref_394") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_394")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_393")))))) (write-u8 (identifier "srec_dst_398") (get-field "axis" (param 0)))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::field &,Pointer &)> field_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::field &,Pointer &)> fun20 { [&](::dessser::gen::dashboard_widget::field p_0, Pointer p_1) {
    double id_21 { p_0.opacity };
    uint64_t id_22 { qword_of_float(id_21) };
    Pointer id_23 { p_1.writeU64Le(id_22) };
    Pointer let_res_24;
    {
      Pointer srec_dst_385 { id_23 };
      uint32_t id_25 { p_0.color };
      Pointer id_26 { srec_dst_385.writeU32Le(id_25) };
      let_res_24 = id_26;
    }
    Pointer let_res_27;
    {
      Pointer srec_dst_386 { let_res_24 };
      ::dessser::gen::dashboard_widget::representation id_28 { p_0.representation };
      Pointer id_29 { representation_to_row_binary(id_28, srec_dst_386) };
      let_res_27 = id_29;
    }
    Pointer let_res_30;
    {
      Pointer srec_dst_387 { let_res_27 };
      std::string id_31 { p_0.column };
      uint32_t id_32 { (uint32_t)id_31.size() };
      Vec<1, uint32_t> id_33 {  id_32  };
      Pointer let_res_34;
      {
        Vec<1, uint32_t> leb128_sz_388 { id_33 };
        Vec<1, Pointer> id_35 {  srec_dst_387  };
        Pointer let_res_36;
        {
          Vec<1, Pointer> leb128_ptr_389 { id_35 };
          bool while_flag_37 { true };
          do {
            uint8_t id_38 { 0 };
            uint8_t id_39 { 0 };
            Pointer id_40 { leb128_ptr_389[id_39] };
            uint32_t id_41 { 128U };
            uint8_t id_42 { 0 };
            uint32_t id_43 { leb128_sz_388[id_42] };
            bool id_44 { bool(id_41 > id_43) };
            uint8_t choose_res_45;
            if (id_44) {
              uint8_t id_46 { 0 };
              uint32_t id_47 { leb128_sz_388[id_46] };
              uint8_t id_48 { uint8_t(id_47) };
              choose_res_45 = id_48;
            } else {
              uint8_t id_49 { 0 };
              uint32_t id_50 { leb128_sz_388[id_49] };
              uint8_t id_51 { uint8_t(id_50) };
              uint8_t id_52 { 128 };
              uint8_t id_53 { uint8_t(id_51 | id_52) };
              choose_res_45 = id_53;
            }
            Pointer id_54 { id_40.writeU8(choose_res_45) };
            Void id_55 { ((void)(leb128_ptr_389[id_38] = id_54), ::dessser::Void()) };
            (void)id_55;
            uint8_t id_56 { 0 };
            uint8_t id_57 { 0 };
            uint32_t id_58 { leb128_sz_388[id_57] };
            uint8_t id_59 { 7 };
            uint32_t id_60 { uint32_t(id_58 >> id_59) };
            Void id_61 { ((void)(leb128_sz_388[id_56] = id_60), ::dessser::Void()) };
            (void)id_61;
            uint8_t id_62 { 0 };
            uint32_t id_63 { leb128_sz_388[id_62] };
            uint32_t id_64 { 0U };
            bool id_65 { bool(id_63 > id_64) };
            while_flag_37 = id_65;
            if (while_flag_37) {
              (void)::dessser::Void();
            }
          } while (while_flag_37);
          (void)::dessser::Void();
          uint8_t id_66 { 0 };
          Pointer id_67 { leb128_ptr_389[id_66] };
          let_res_36 = id_67;
        }
        let_res_34 = let_res_36;
      }
      std::string id_68 { p_0.column };
      Bytes id_69 { id_68 };
      Pointer id_70 { let_res_34.writeBytes(id_69) };
      let_res_30 = id_70;
    }
    Pointer let_res_71;
    {
      Pointer srec_dst_390 { let_res_30 };
      Arr<std::string> id_72 { p_0.factors };
      uint32_t id_73 { id_72.size() };
      Vec<1, uint32_t> id_74 {  id_73  };
      Pointer let_res_75;
      {
        Vec<1, uint32_t> leb128_sz_391 { id_74 };
        Vec<1, Pointer> id_76 {  srec_dst_390  };
        Pointer let_res_77;
        {
          Vec<1, Pointer> leb128_ptr_392 { id_76 };
          bool while_flag_78 { true };
          do {
            uint8_t id_79 { 0 };
            uint8_t id_80 { 0 };
            Pointer id_81 { leb128_ptr_392[id_80] };
            uint32_t id_82 { 128U };
            uint8_t id_83 { 0 };
            uint32_t id_84 { leb128_sz_391[id_83] };
            bool id_85 { bool(id_82 > id_84) };
            uint8_t choose_res_86;
            if (id_85) {
              uint8_t id_87 { 0 };
              uint32_t id_88 { leb128_sz_391[id_87] };
              uint8_t id_89 { uint8_t(id_88) };
              choose_res_86 = id_89;
            } else {
              uint8_t id_90 { 0 };
              uint32_t id_91 { leb128_sz_391[id_90] };
              uint8_t id_92 { uint8_t(id_91) };
              uint8_t id_93 { 128 };
              uint8_t id_94 { uint8_t(id_92 | id_93) };
              choose_res_86 = id_94;
            }
            Pointer id_95 { id_81.writeU8(choose_res_86) };
            Void id_96 { ((void)(leb128_ptr_392[id_79] = id_95), ::dessser::Void()) };
            (void)id_96;
            uint8_t id_97 { 0 };
            uint8_t id_98 { 0 };
            uint32_t id_99 { leb128_sz_391[id_98] };
            uint8_t id_100 { 7 };
            uint32_t id_101 { uint32_t(id_99 >> id_100) };
            Void id_102 { ((void)(leb128_sz_391[id_97] = id_101), ::dessser::Void()) };
            (void)id_102;
            uint8_t id_103 { 0 };
            uint32_t id_104 { leb128_sz_391[id_103] };
            uint32_t id_105 { 0U };
            bool id_106 { bool(id_104 > id_105) };
            while_flag_78 = id_106;
            if (while_flag_78) {
              (void)::dessser::Void();
            }
          } while (while_flag_78);
          (void)::dessser::Void();
          uint8_t id_107 { 0 };
          Pointer id_108 { leb128_ptr_392[id_107] };
          let_res_77 = id_108;
        }
        let_res_75 = let_res_77;
      }
      Vec<1, Pointer> id_109 {  let_res_75  };
      Pointer let_res_110;
      {
        Vec<1, Pointer> dst_ref_393 { id_109 };
        int32_t id_111 { 0L };
        Vec<1, int32_t> id_112 {  id_111  };
        Pointer let_res_113;
        {
          Vec<1, int32_t> n_ref_394 { id_112 };
          Arr<std::string> id_114 { p_0.factors };
          for (std::string const &x_395 : id_114) {
            uint8_t id_115 { 0 };
            uint32_t id_116 { (uint32_t)x_395.size() };
            Vec<1, uint32_t> id_117 {  id_116  };
            Pointer let_res_118;
            {
              Vec<1, uint32_t> leb128_sz_396 { id_117 };
              uint8_t id_119 { 0 };
              Pointer id_120 { dst_ref_393[id_119] };
              Vec<1, Pointer> id_121 {  id_120  };
              Pointer let_res_122;
              {
                Vec<1, Pointer> leb128_ptr_397 { id_121 };
                bool while_flag_123 { true };
                do {
                  uint8_t id_124 { 0 };
                  uint8_t id_125 { 0 };
                  Pointer id_126 { leb128_ptr_397[id_125] };
                  uint32_t id_127 { 128U };
                  uint8_t id_128 { 0 };
                  uint32_t id_129 { leb128_sz_396[id_128] };
                  bool id_130 { bool(id_127 > id_129) };
                  uint8_t choose_res_131;
                  if (id_130) {
                    uint8_t id_132 { 0 };
                    uint32_t id_133 { leb128_sz_396[id_132] };
                    uint8_t id_134 { uint8_t(id_133) };
                    choose_res_131 = id_134;
                  } else {
                    uint8_t id_135 { 0 };
                    uint32_t id_136 { leb128_sz_396[id_135] };
                    uint8_t id_137 { uint8_t(id_136) };
                    uint8_t id_138 { 128 };
                    uint8_t id_139 { uint8_t(id_137 | id_138) };
                    choose_res_131 = id_139;
                  }
                  Pointer id_140 { id_126.writeU8(choose_res_131) };
                  Void id_141 { ((void)(leb128_ptr_397[id_124] = id_140), ::dessser::Void()) };
                  (void)id_141;
                  uint8_t id_142 { 0 };
                  uint8_t id_143 { 0 };
                  uint32_t id_144 { leb128_sz_396[id_143] };
                  uint8_t id_145 { 7 };
                  uint32_t id_146 { uint32_t(id_144 >> id_145) };
                  Void id_147 { ((void)(leb128_sz_396[id_142] = id_146), ::dessser::Void()) };
                  (void)id_147;
                  uint8_t id_148 { 0 };
                  uint32_t id_149 { leb128_sz_396[id_148] };
                  uint32_t id_150 { 0U };
                  bool id_151 { bool(id_149 > id_150) };
                  while_flag_123 = id_151;
                  if (while_flag_123) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_123);
                (void)::dessser::Void();
                uint8_t id_152 { 0 };
                Pointer id_153 { leb128_ptr_397[id_152] };
                let_res_122 = id_153;
              }
              let_res_118 = let_res_122;
            }
            Bytes id_154 { x_395 };
            Pointer id_155 { let_res_118.writeBytes(id_154) };
            Void id_156 { ((void)(dst_ref_393[id_115] = id_155), ::dessser::Void()) };
            (void)id_156;
            uint8_t id_157 { 0 };
            int32_t id_158 { 1L };
            uint8_t id_159 { 0 };
            int32_t id_160 { n_ref_394[id_159] };
            int32_t id_161 { int32_t(id_158 + id_160) };
            Void id_162 { ((void)(n_ref_394[id_157] = id_161), ::dessser::Void()) };
            (void)id_162;
            (void)id_162;
          }
          (void)::dessser::Void();
          uint8_t id_163 { 0 };
          Pointer id_164 { dst_ref_393[id_163] };
          let_res_113 = id_164;
        }
        let_res_110 = let_res_113;
      }
      let_res_71 = let_res_110;
    }
    Pointer let_res_165;
    {
      Pointer srec_dst_398 { let_res_71 };
      uint8_t id_166 { p_0.axis };
      Pointer id_167 { srec_dst_398.writeU8(id_166) };
      let_res_165 = id_167;
    }
    return let_res_165;
  }
   };
  return fun20;
}
std::function<Pointer(::dessser::gen::dashboard_widget::field &,Pointer &)> field_to_row_binary(field_to_row_binary_init());

/* 
    (fun ("{name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]}" "Ptr")
      (let "srec_dst_400" (let "srec_dst_399" (apply (ext-identifier fq_function_name to-row-binary) (get-field "name" (param 0)) (param 1)) (write-u8 (identifier "srec_dst_399") (u8-of-bool (get-field "visible" (param 0)))))
        (let "dst_ref_403"
          (make-vec
            (let "leb128_sz_401" (make-vec (cardinality (get-field "fields" (param 0))))
              (let "leb128_ptr_402" (make-vec (identifier "srec_dst_400"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_402")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_402"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_401"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_401"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_401"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_401") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_401")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_401")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_402"))))))
          (let "n_ref_404" (make-vec (i32 0))
            (seq
              (for-each "x_405" (get-field "fields" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_403") (apply (identifier "field-to-row-binary") (identifier "x_405") (unsafe-nth (u8 0) (identifier "dst_ref_403"))))
                  (set-vec (u8 0) (identifier "n_ref_404") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_404")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_403")))))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::source &,Pointer &)> source_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::source &,Pointer &)> fun168 { [&](::dessser::gen::dashboard_widget::source p_0, Pointer p_1) {
    auto fun169 { dessser::gen::fq_function_name::to_row_binary };
    dessser::gen::fq_function_name::t_ext id_170 { p_0.name };
    Pointer id_171 { fun169(id_170, p_1) };
    Pointer let_res_172;
    {
      Pointer srec_dst_399 { id_171 };
      bool id_173 { p_0.visible };
      uint8_t id_174 { uint8_t(id_173) };
      Pointer id_175 { srec_dst_399.writeU8(id_174) };
      let_res_172 = id_175;
    }
    Pointer let_res_176;
    {
      Pointer srec_dst_400 { let_res_172 };
      Arr<::dessser::gen::dashboard_widget::field> id_177 { p_0.fields };
      uint32_t id_178 { id_177.size() };
      Vec<1, uint32_t> id_179 {  id_178  };
      Pointer let_res_180;
      {
        Vec<1, uint32_t> leb128_sz_401 { id_179 };
        Vec<1, Pointer> id_181 {  srec_dst_400  };
        Pointer let_res_182;
        {
          Vec<1, Pointer> leb128_ptr_402 { id_181 };
          bool while_flag_183 { true };
          do {
            uint8_t id_184 { 0 };
            uint8_t id_185 { 0 };
            Pointer id_186 { leb128_ptr_402[id_185] };
            uint32_t id_187 { 128U };
            uint8_t id_188 { 0 };
            uint32_t id_189 { leb128_sz_401[id_188] };
            bool id_190 { bool(id_187 > id_189) };
            uint8_t choose_res_191;
            if (id_190) {
              uint8_t id_192 { 0 };
              uint32_t id_193 { leb128_sz_401[id_192] };
              uint8_t id_194 { uint8_t(id_193) };
              choose_res_191 = id_194;
            } else {
              uint8_t id_195 { 0 };
              uint32_t id_196 { leb128_sz_401[id_195] };
              uint8_t id_197 { uint8_t(id_196) };
              uint8_t id_198 { 128 };
              uint8_t id_199 { uint8_t(id_197 | id_198) };
              choose_res_191 = id_199;
            }
            Pointer id_200 { id_186.writeU8(choose_res_191) };
            Void id_201 { ((void)(leb128_ptr_402[id_184] = id_200), ::dessser::Void()) };
            (void)id_201;
            uint8_t id_202 { 0 };
            uint8_t id_203 { 0 };
            uint32_t id_204 { leb128_sz_401[id_203] };
            uint8_t id_205 { 7 };
            uint32_t id_206 { uint32_t(id_204 >> id_205) };
            Void id_207 { ((void)(leb128_sz_401[id_202] = id_206), ::dessser::Void()) };
            (void)id_207;
            uint8_t id_208 { 0 };
            uint32_t id_209 { leb128_sz_401[id_208] };
            uint32_t id_210 { 0U };
            bool id_211 { bool(id_209 > id_210) };
            while_flag_183 = id_211;
            if (while_flag_183) {
              (void)::dessser::Void();
            }
          } while (while_flag_183);
          (void)::dessser::Void();
          uint8_t id_212 { 0 };
          Pointer id_213 { leb128_ptr_402[id_212] };
          let_res_182 = id_213;
        }
        let_res_180 = let_res_182;
      }
      Vec<1, Pointer> id_214 {  let_res_180  };
      Pointer let_res_215;
      {
        Vec<1, Pointer> dst_ref_403 { id_214 };
        int32_t id_216 { 0L };
        Vec<1, int32_t> id_217 {  id_216  };
        Pointer let_res_218;
        {
          Vec<1, int32_t> n_ref_404 { id_217 };
          Arr<::dessser::gen::dashboard_widget::field> id_219 { p_0.fields };
          for (::dessser::gen::dashboard_widget::field &x_405 : id_219) {
            uint8_t id_220 { 0 };
            uint8_t id_221 { 0 };
            Pointer id_222 { dst_ref_403[id_221] };
            Pointer id_223 { field_to_row_binary(x_405, id_222) };
            Void id_224 { ((void)(dst_ref_403[id_220] = id_223), ::dessser::Void()) };
            (void)id_224;
            uint8_t id_225 { 0 };
            int32_t id_226 { 1L };
            uint8_t id_227 { 0 };
            int32_t id_228 { n_ref_404[id_227] };
            int32_t id_229 { int32_t(id_226 + id_228) };
            Void id_230 { ((void)(n_ref_404[id_225] = id_229), ::dessser::Void()) };
            (void)id_230;
            (void)id_230;
          }
          (void)::dessser::Void();
          uint8_t id_231 { 0 };
          Pointer id_232 { dst_ref_403[id_231] };
          let_res_218 = id_232;
        }
        let_res_215 = let_res_218;
      }
      let_res_176 = let_res_215;
    }
    return let_res_176;
  }
   };
  return fun168;
}
std::function<Pointer(::dessser::gen::dashboard_widget::source &,Pointer &)> source_to_row_binary(source_to_row_binary_init());

/* 
    (fun ("[Linear Void | Logarithmic Void]" "Ptr")
      (let "ssum_dst_380" (write-u16 little-endian (param 1) (label-of (param 0))) (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_380") (seq (assert (eq (label-of (param 0)) (u16 1))) (identifier "ssum_dst_380")))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::scale const &,Pointer &)> scale_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::scale const &,Pointer &)> fun233 { [&](::dessser::gen::dashboard_widget::scale p_0, Pointer p_1) {
    uint16_t id_234 { uint16_t(p_0) };
    Pointer id_235 { p_1.writeU16Le(id_234) };
    Pointer let_res_236;
    {
      Pointer ssum_dst_380 { id_235 };
      uint16_t id_237 { 0 };
      uint16_t id_238 { uint16_t(p_0) };
      bool id_239 { bool(id_237 == id_238) };
      Pointer choose_res_240;
      if (id_239) {
        choose_res_240 = ssum_dst_380;
      } else {
        uint16_t id_241 { uint16_t(p_0) };
        uint16_t id_242 { 1 };
        bool id_243 { bool(id_241 == id_242) };
        Void id_244 { ((void)(assert(id_243)), ::dessser::Void()) };
        (void)id_244;
        choose_res_240 = ssum_dst_380;
      }
      let_res_236 = choose_res_240;
    }
    return let_res_236;
  }
   };
  return fun233;
}
std::function<Pointer(::dessser::gen::dashboard_widget::scale const &,Pointer &)> scale_to_row_binary(scale_to_row_binary_init());

/* 
    (fun ("{left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])}" "Ptr")
      (let "srec_dst_382" (let "srec_dst_381" (write-u8 (param 1) (u8-of-bool (get-field "left" (param 0)))) (write-u8 (identifier "srec_dst_381") (u8-of-bool (get-field "force_zero" (param 0)))))
        (apply (identifier "scale-to-row-binary") (get-field "scale" (param 0)) (identifier "srec_dst_382"))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::axis const &,Pointer &)> axis_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::axis const &,Pointer &)> fun245 { [&](::dessser::gen::dashboard_widget::axis p_0, Pointer p_1) {
    bool id_246 { p_0.left };
    uint8_t id_247 { uint8_t(id_246) };
    Pointer id_248 { p_1.writeU8(id_247) };
    Pointer let_res_249;
    {
      Pointer srec_dst_381 { id_248 };
      bool id_250 { p_0.force_zero };
      uint8_t id_251 { uint8_t(id_250) };
      Pointer id_252 { srec_dst_381.writeU8(id_251) };
      let_res_249 = id_252;
    }
    Pointer let_res_253;
    {
      Pointer srec_dst_382 { let_res_249 };
      ::dessser::gen::dashboard_widget::scale id_254 { p_0.scale };
      Pointer id_255 { scale_to_row_binary(id_254, srec_dst_382) };
      let_res_253 = id_255;
    }
    return let_res_253;
  }
   };
  return fun245;
}
std::function<Pointer(::dessser::gen::dashboard_widget::axis const &,Pointer &)> axis_to_row_binary(axis_to_row_binary_init());

/* 
    (fun ("[Plot Void]" "Ptr") (let "ssum_dst_378" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (identifier "ssum_dst_378"))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::type const &,Pointer &)> type_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::type const &,Pointer &)> fun256 { [&](::dessser::gen::dashboard_widget::type p_0, Pointer p_1) {
    uint16_t id_257 { uint16_t(p_0) };
    Pointer id_258 { p_1.writeU16Le(id_257) };
    Pointer let_res_259;
    {
      Pointer ssum_dst_378 { id_258 };
      uint16_t id_260 { uint16_t(p_0) };
      uint16_t id_261 { 0 };
      bool id_262 { bool(id_260 == id_261) };
      Void id_263 { ((void)(assert(id_262)), ::dessser::Void()) };
      (void)id_263;
      let_res_259 = ssum_dst_378;
    }
    return let_res_259;
  }
   };
  return fun256;
}
std::function<Pointer(::dessser::gen::dashboard_widget::type const &,Pointer &)> type_to_row_binary(type_to_row_binary_init());

/* 
    (fun ("{title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]}" "Ptr")
      (let "srec_dst_415"
        (let "srec_dst_409"
          (let "srec_dst_408"
            (write-bytes
              (let "leb128_sz_406" (make-vec (string-length (get-field "title" (param 0))))
                (let "leb128_ptr_407" (make-vec (param 1))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_407")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_407"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_406"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_406"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_406"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_406") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_406")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_406")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_407"))))) 
              (bytes-of-string (get-field "title" (param 0)))) (apply (identifier "type-to-row-binary") (get-field "type" (param 0)) (identifier "srec_dst_408")))
          (let "dst_ref_412"
            (make-vec
              (let "leb128_sz_410" (make-vec (cardinality (get-field "axes" (param 0))))
                (let "leb128_ptr_411" (make-vec (identifier "srec_dst_409"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_411")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_411"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_410"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_410"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_410"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_410") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_410")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_410")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_411"))))))
            (let "n_ref_413" (make-vec (i32 0))
              (seq
                (for-each "x_414" (get-field "axes" (param 0))
                  (seq (set-vec (u8 0) (identifier "dst_ref_412") (apply (identifier "axis-to-row-binary") (identifier "x_414") (unsafe-nth (u8 0) (identifier "dst_ref_412"))))
                    (set-vec (u8 0) (identifier "n_ref_413") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_413")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_412"))))))
        (let "dst_ref_418"
          (make-vec
            (let "leb128_sz_416" (make-vec (cardinality (get-field "sources" (param 0))))
              (let "leb128_ptr_417" (make-vec (identifier "srec_dst_415"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_417")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_417"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_416"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_416"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_416"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_416") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_416")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_416")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_417"))))))
          (let "n_ref_419" (make-vec (i32 0))
            (seq
              (for-each "x_420" (get-field "sources" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_418") (apply (identifier "source-to-row-binary") (identifier "x_420") (unsafe-nth (u8 0) (identifier "dst_ref_418"))))
                  (set-vec (u8 0) (identifier "n_ref_419") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_419")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_418")))))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::chart &,Pointer &)> chart_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::chart &,Pointer &)> fun264 { [&](::dessser::gen::dashboard_widget::chart p_0, Pointer p_1) {
    std::string id_265 { p_0.title };
    uint32_t id_266 { (uint32_t)id_265.size() };
    Vec<1, uint32_t> id_267 {  id_266  };
    Pointer let_res_268;
    {
      Vec<1, uint32_t> leb128_sz_406 { id_267 };
      Vec<1, Pointer> id_269 {  p_1  };
      Pointer let_res_270;
      {
        Vec<1, Pointer> leb128_ptr_407 { id_269 };
        bool while_flag_271 { true };
        do {
          uint8_t id_272 { 0 };
          uint8_t id_273 { 0 };
          Pointer id_274 { leb128_ptr_407[id_273] };
          uint32_t id_275 { 128U };
          uint8_t id_276 { 0 };
          uint32_t id_277 { leb128_sz_406[id_276] };
          bool id_278 { bool(id_275 > id_277) };
          uint8_t choose_res_279;
          if (id_278) {
            uint8_t id_280 { 0 };
            uint32_t id_281 { leb128_sz_406[id_280] };
            uint8_t id_282 { uint8_t(id_281) };
            choose_res_279 = id_282;
          } else {
            uint8_t id_283 { 0 };
            uint32_t id_284 { leb128_sz_406[id_283] };
            uint8_t id_285 { uint8_t(id_284) };
            uint8_t id_286 { 128 };
            uint8_t id_287 { uint8_t(id_285 | id_286) };
            choose_res_279 = id_287;
          }
          Pointer id_288 { id_274.writeU8(choose_res_279) };
          Void id_289 { ((void)(leb128_ptr_407[id_272] = id_288), ::dessser::Void()) };
          (void)id_289;
          uint8_t id_290 { 0 };
          uint8_t id_291 { 0 };
          uint32_t id_292 { leb128_sz_406[id_291] };
          uint8_t id_293 { 7 };
          uint32_t id_294 { uint32_t(id_292 >> id_293) };
          Void id_295 { ((void)(leb128_sz_406[id_290] = id_294), ::dessser::Void()) };
          (void)id_295;
          uint8_t id_296 { 0 };
          uint32_t id_297 { leb128_sz_406[id_296] };
          uint32_t id_298 { 0U };
          bool id_299 { bool(id_297 > id_298) };
          while_flag_271 = id_299;
          if (while_flag_271) {
            (void)::dessser::Void();
          }
        } while (while_flag_271);
        (void)::dessser::Void();
        uint8_t id_300 { 0 };
        Pointer id_301 { leb128_ptr_407[id_300] };
        let_res_270 = id_301;
      }
      let_res_268 = let_res_270;
    }
    std::string id_302 { p_0.title };
    Bytes id_303 { id_302 };
    Pointer id_304 { let_res_268.writeBytes(id_303) };
    Pointer let_res_305;
    {
      Pointer srec_dst_408 { id_304 };
      ::dessser::gen::dashboard_widget::type id_306 { p_0.type };
      Pointer id_307 { type_to_row_binary(id_306, srec_dst_408) };
      let_res_305 = id_307;
    }
    Pointer let_res_308;
    {
      Pointer srec_dst_409 { let_res_305 };
      Arr<::dessser::gen::dashboard_widget::axis> id_309 { p_0.axes };
      uint32_t id_310 { id_309.size() };
      Vec<1, uint32_t> id_311 {  id_310  };
      Pointer let_res_312;
      {
        Vec<1, uint32_t> leb128_sz_410 { id_311 };
        Vec<1, Pointer> id_313 {  srec_dst_409  };
        Pointer let_res_314;
        {
          Vec<1, Pointer> leb128_ptr_411 { id_313 };
          bool while_flag_315 { true };
          do {
            uint8_t id_316 { 0 };
            uint8_t id_317 { 0 };
            Pointer id_318 { leb128_ptr_411[id_317] };
            uint32_t id_319 { 128U };
            uint8_t id_320 { 0 };
            uint32_t id_321 { leb128_sz_410[id_320] };
            bool id_322 { bool(id_319 > id_321) };
            uint8_t choose_res_323;
            if (id_322) {
              uint8_t id_324 { 0 };
              uint32_t id_325 { leb128_sz_410[id_324] };
              uint8_t id_326 { uint8_t(id_325) };
              choose_res_323 = id_326;
            } else {
              uint8_t id_327 { 0 };
              uint32_t id_328 { leb128_sz_410[id_327] };
              uint8_t id_329 { uint8_t(id_328) };
              uint8_t id_330 { 128 };
              uint8_t id_331 { uint8_t(id_329 | id_330) };
              choose_res_323 = id_331;
            }
            Pointer id_332 { id_318.writeU8(choose_res_323) };
            Void id_333 { ((void)(leb128_ptr_411[id_316] = id_332), ::dessser::Void()) };
            (void)id_333;
            uint8_t id_334 { 0 };
            uint8_t id_335 { 0 };
            uint32_t id_336 { leb128_sz_410[id_335] };
            uint8_t id_337 { 7 };
            uint32_t id_338 { uint32_t(id_336 >> id_337) };
            Void id_339 { ((void)(leb128_sz_410[id_334] = id_338), ::dessser::Void()) };
            (void)id_339;
            uint8_t id_340 { 0 };
            uint32_t id_341 { leb128_sz_410[id_340] };
            uint32_t id_342 { 0U };
            bool id_343 { bool(id_341 > id_342) };
            while_flag_315 = id_343;
            if (while_flag_315) {
              (void)::dessser::Void();
            }
          } while (while_flag_315);
          (void)::dessser::Void();
          uint8_t id_344 { 0 };
          Pointer id_345 { leb128_ptr_411[id_344] };
          let_res_314 = id_345;
        }
        let_res_312 = let_res_314;
      }
      Vec<1, Pointer> id_346 {  let_res_312  };
      Pointer let_res_347;
      {
        Vec<1, Pointer> dst_ref_412 { id_346 };
        int32_t id_348 { 0L };
        Vec<1, int32_t> id_349 {  id_348  };
        Pointer let_res_350;
        {
          Vec<1, int32_t> n_ref_413 { id_349 };
          Arr<::dessser::gen::dashboard_widget::axis> id_351 { p_0.axes };
          for (::dessser::gen::dashboard_widget::axis const &x_414 : id_351) {
            uint8_t id_352 { 0 };
            uint8_t id_353 { 0 };
            Pointer id_354 { dst_ref_412[id_353] };
            Pointer id_355 { axis_to_row_binary(x_414, id_354) };
            Void id_356 { ((void)(dst_ref_412[id_352] = id_355), ::dessser::Void()) };
            (void)id_356;
            uint8_t id_357 { 0 };
            int32_t id_358 { 1L };
            uint8_t id_359 { 0 };
            int32_t id_360 { n_ref_413[id_359] };
            int32_t id_361 { int32_t(id_358 + id_360) };
            Void id_362 { ((void)(n_ref_413[id_357] = id_361), ::dessser::Void()) };
            (void)id_362;
            (void)id_362;
          }
          (void)::dessser::Void();
          uint8_t id_363 { 0 };
          Pointer id_364 { dst_ref_412[id_363] };
          let_res_350 = id_364;
        }
        let_res_347 = let_res_350;
      }
      let_res_308 = let_res_347;
    }
    Pointer let_res_365;
    {
      Pointer srec_dst_415 { let_res_308 };
      Arr<::dessser::gen::dashboard_widget::source> id_366 { p_0.sources };
      uint32_t id_367 { id_366.size() };
      Vec<1, uint32_t> id_368 {  id_367  };
      Pointer let_res_369;
      {
        Vec<1, uint32_t> leb128_sz_416 { id_368 };
        Vec<1, Pointer> id_370 {  srec_dst_415  };
        Pointer let_res_371;
        {
          Vec<1, Pointer> leb128_ptr_417 { id_370 };
          bool while_flag_372 { true };
          do {
            uint8_t id_373 { 0 };
            uint8_t id_374 { 0 };
            Pointer id_375 { leb128_ptr_417[id_374] };
            uint32_t id_376 { 128U };
            uint8_t id_377 { 0 };
            uint32_t id_378 { leb128_sz_416[id_377] };
            bool id_379 { bool(id_376 > id_378) };
            uint8_t choose_res_380;
            if (id_379) {
              uint8_t id_381 { 0 };
              uint32_t id_382 { leb128_sz_416[id_381] };
              uint8_t id_383 { uint8_t(id_382) };
              choose_res_380 = id_383;
            } else {
              uint8_t id_384 { 0 };
              uint32_t id_385 { leb128_sz_416[id_384] };
              uint8_t id_386 { uint8_t(id_385) };
              uint8_t id_387 { 128 };
              uint8_t id_388 { uint8_t(id_386 | id_387) };
              choose_res_380 = id_388;
            }
            Pointer id_389 { id_375.writeU8(choose_res_380) };
            Void id_390 { ((void)(leb128_ptr_417[id_373] = id_389), ::dessser::Void()) };
            (void)id_390;
            uint8_t id_391 { 0 };
            uint8_t id_392 { 0 };
            uint32_t id_393 { leb128_sz_416[id_392] };
            uint8_t id_394 { 7 };
            uint32_t id_395 { uint32_t(id_393 >> id_394) };
            Void id_396 { ((void)(leb128_sz_416[id_391] = id_395), ::dessser::Void()) };
            (void)id_396;
            uint8_t id_397 { 0 };
            uint32_t id_398 { leb128_sz_416[id_397] };
            uint32_t id_399 { 0U };
            bool id_400 { bool(id_398 > id_399) };
            while_flag_372 = id_400;
            if (while_flag_372) {
              (void)::dessser::Void();
            }
          } while (while_flag_372);
          (void)::dessser::Void();
          uint8_t id_401 { 0 };
          Pointer id_402 { leb128_ptr_417[id_401] };
          let_res_371 = id_402;
        }
        let_res_369 = let_res_371;
      }
      Vec<1, Pointer> id_403 {  let_res_369  };
      Pointer let_res_404;
      {
        Vec<1, Pointer> dst_ref_418 { id_403 };
        int32_t id_405 { 0L };
        Vec<1, int32_t> id_406 {  id_405  };
        Pointer let_res_407;
        {
          Vec<1, int32_t> n_ref_419 { id_406 };
          Arr<::dessser::gen::dashboard_widget::source> id_408 { p_0.sources };
          for (::dessser::gen::dashboard_widget::source &x_420 : id_408) {
            uint8_t id_409 { 0 };
            uint8_t id_410 { 0 };
            Pointer id_411 { dst_ref_418[id_410] };
            Pointer id_412 { source_to_row_binary(x_420, id_411) };
            Void id_413 { ((void)(dst_ref_418[id_409] = id_412), ::dessser::Void()) };
            (void)id_413;
            uint8_t id_414 { 0 };
            int32_t id_415 { 1L };
            uint8_t id_416 { 0 };
            int32_t id_417 { n_ref_419[id_416] };
            int32_t id_418 { int32_t(id_415 + id_417) };
            Void id_419 { ((void)(n_ref_419[id_414] = id_418), ::dessser::Void()) };
            (void)id_419;
            (void)id_419;
          }
          (void)::dessser::Void();
          uint8_t id_420 { 0 };
          Pointer id_421 { dst_ref_418[id_420] };
          let_res_407 = id_421;
        }
        let_res_404 = let_res_407;
      }
      let_res_365 = let_res_404;
    }
    return let_res_365;
  }
   };
  return fun264;
}
std::function<Pointer(::dessser::gen::dashboard_widget::chart &,Pointer &)> chart_to_row_binary(chart_to_row_binary_init());

/* 
    (fun ("[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]" "Ptr")
      (let "ssum_dst_422" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_423" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "leb128_ptr_424" (make-vec (identifier "ssum_dst_422"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_424")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_424"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_423"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_423"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_423"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_423") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_423")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_423")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_424"))))) 
            (bytes-of-string (get-alt "Text" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "chart-to-row-binary") (get-alt "Chart" (param 0)) (identifier "ssum_dst_422"))))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> fun422 { [&](::dessser::gen::dashboard_widget::t p_0, Pointer p_1) {
    uint16_t id_423 { uint16_t(p_0.index()) };
    Pointer id_424 { p_1.writeU16Le(id_423) };
    Pointer let_res_425;
    {
      Pointer ssum_dst_422 { id_424 };
      uint16_t id_426 { 0 };
      uint16_t id_427 { uint16_t(p_0.index()) };
      bool id_428 { bool(id_426 == id_427) };
      Pointer choose_res_429;
      if (id_428) {
        std::string id_430 { std::get<0 /* Text */>(p_0) };
        uint32_t id_431 { (uint32_t)id_430.size() };
        Vec<1, uint32_t> id_432 {  id_431  };
        Pointer let_res_433;
        {
          Vec<1, uint32_t> leb128_sz_423 { id_432 };
          Vec<1, Pointer> id_434 {  ssum_dst_422  };
          Pointer let_res_435;
          {
            Vec<1, Pointer> leb128_ptr_424 { id_434 };
            bool while_flag_436 { true };
            do {
              uint8_t id_437 { 0 };
              uint8_t id_438 { 0 };
              Pointer id_439 { leb128_ptr_424[id_438] };
              uint32_t id_440 { 128U };
              uint8_t id_441 { 0 };
              uint32_t id_442 { leb128_sz_423[id_441] };
              bool id_443 { bool(id_440 > id_442) };
              uint8_t choose_res_444;
              if (id_443) {
                uint8_t id_445 { 0 };
                uint32_t id_446 { leb128_sz_423[id_445] };
                uint8_t id_447 { uint8_t(id_446) };
                choose_res_444 = id_447;
              } else {
                uint8_t id_448 { 0 };
                uint32_t id_449 { leb128_sz_423[id_448] };
                uint8_t id_450 { uint8_t(id_449) };
                uint8_t id_451 { 128 };
                uint8_t id_452 { uint8_t(id_450 | id_451) };
                choose_res_444 = id_452;
              }
              Pointer id_453 { id_439.writeU8(choose_res_444) };
              Void id_454 { ((void)(leb128_ptr_424[id_437] = id_453), ::dessser::Void()) };
              (void)id_454;
              uint8_t id_455 { 0 };
              uint8_t id_456 { 0 };
              uint32_t id_457 { leb128_sz_423[id_456] };
              uint8_t id_458 { 7 };
              uint32_t id_459 { uint32_t(id_457 >> id_458) };
              Void id_460 { ((void)(leb128_sz_423[id_455] = id_459), ::dessser::Void()) };
              (void)id_460;
              uint8_t id_461 { 0 };
              uint32_t id_462 { leb128_sz_423[id_461] };
              uint32_t id_463 { 0U };
              bool id_464 { bool(id_462 > id_463) };
              while_flag_436 = id_464;
              if (while_flag_436) {
                (void)::dessser::Void();
              }
            } while (while_flag_436);
            (void)::dessser::Void();
            uint8_t id_465 { 0 };
            Pointer id_466 { leb128_ptr_424[id_465] };
            let_res_435 = id_466;
          }
          let_res_433 = let_res_435;
        }
        std::string id_467 { std::get<0 /* Text */>(p_0) };
        Bytes id_468 { id_467 };
        Pointer id_469 { let_res_433.writeBytes(id_468) };
        choose_res_429 = id_469;
      } else {
        uint16_t id_470 { uint16_t(p_0.index()) };
        uint16_t id_471 { 1 };
        bool id_472 { bool(id_470 == id_471) };
        Void id_473 { ((void)(assert(id_472)), ::dessser::Void()) };
        (void)id_473;
        ::dessser::gen::dashboard_widget::chart id_474 { std::get<1 /* Chart */>(p_0) };
        Pointer id_475 { chart_to_row_binary(id_474, ssum_dst_422) };
        choose_res_429 = id_475;
      }
      let_res_425 = choose_res_429;
    }
    return let_res_425;
  }
   };
  return fun422;
}
std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Unused Void | Independent Void | Stacked Void | StackCentered Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2) (if (eq (u16 1) (label-of (param 0))) (size 2) (if (eq (u16 2) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 3))) (size 2))))))
 */
static std::function<Size(::dessser::gen::dashboard_widget::representation const &)> representation_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::representation const &)> fun476 { [&](::dessser::gen::dashboard_widget::representation p_0) {
    uint16_t id_477 { 0 };
    uint16_t id_478 { uint16_t(p_0) };
    bool id_479 { bool(id_477 == id_478) };
    Size choose_res_480;
    if (id_479) {
      Size id_481 { 2UL };
      choose_res_480 = id_481;
    } else {
      uint16_t id_482 { 1 };
      uint16_t id_483 { uint16_t(p_0) };
      bool id_484 { bool(id_482 == id_483) };
      Size choose_res_485;
      if (id_484) {
        Size id_486 { 2UL };
        choose_res_485 = id_486;
      } else {
        uint16_t id_487 { 2 };
        uint16_t id_488 { uint16_t(p_0) };
        bool id_489 { bool(id_487 == id_488) };
        Size choose_res_490;
        if (id_489) {
          Size id_491 { 2UL };
          choose_res_490 = id_491;
        } else {
          uint16_t id_492 { uint16_t(p_0) };
          uint16_t id_493 { 3 };
          bool id_494 { bool(id_492 == id_493) };
          Void id_495 { ((void)(assert(id_494)), ::dessser::Void()) };
          (void)id_495;
          Size id_496 { 2UL };
          choose_res_490 = id_496;
        }
        choose_res_485 = choose_res_490;
      }
      choose_res_480 = choose_res_485;
    }
    return choose_res_480;
  }
   };
  return fun476;
}
std::function<Size(::dessser::gen::dashboard_widget::representation const &)> representation_sersize_of_row_binary(representation_sersize_of_row_binary_init());

/* 
    (fun ("{opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8}")
      (add
        (let "sz_342"
          (let "sz_338" (add (size 12) (apply (identifier "representation-sersize-of-row-binary") (get-field "representation" (param 0))))
            (add (identifier "sz_338")
              (add
                (let "n_ref_340" (make-vec (string-length (get-field "column" (param 0))))
                  (let "lebsz_ref_341" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_340")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_341") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_341")))))) 
                (size-of-u32 (string-length (get-field "column" (param 0)))))))
          (let "sz_ref_345"
            (make-vec
              (add (identifier "sz_342")
                (let "n_ref_343" (make-vec (cardinality (get-field "factors" (param 0))))
                  (let "lebsz_ref_344" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_343")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_344")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_344") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_344")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_344"))))))))
            (seq
              (let "repeat_n_346" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "factors" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_346")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_345")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_345"))
                        (let "wlen_347" (string-length (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_346")) (get-field "factors" (param 0))))
                          (add
                            (let "n_ref_348" (make-vec (identifier "wlen_347"))
                              (let "lebsz_ref_349" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_348")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_349")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_349") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_349")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_349")))))) 
                            (size-of-u32 (identifier "wlen_347")))))) 
                    (set-vec (u8 0) (identifier "repeat_n_346") (add (unsafe-nth (u8 0) (identifier "repeat_n_346")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_345"))))) (size 1)))
 */
static std::function<Size(::dessser::gen::dashboard_widget::field &)> field_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::field &)> fun497 { [&](::dessser::gen::dashboard_widget::field p_0) {
    Size id_498 { 12UL };
    ::dessser::gen::dashboard_widget::representation id_499 { p_0.representation };
    Size id_500 { representation_sersize_of_row_binary(id_499) };
    Size id_501 { Size(id_498 + id_500) };
    Size let_res_502;
    {
      Size sz_338 { id_501 };
      std::string id_503 { p_0.column };
      uint32_t id_504 { (uint32_t)id_503.size() };
      Vec<1, uint32_t> id_505 {  id_504  };
      Size let_res_506;
      {
        Vec<1, uint32_t> n_ref_340 { id_505 };
        uint32_t id_507 { 1U };
        Vec<1, uint32_t> id_508 {  id_507  };
        Size let_res_509;
        {
          Vec<1, uint32_t> lebsz_ref_341 { id_508 };
          bool while_flag_510 { true };
          do {
            uint8_t id_511 { 0 };
            uint32_t id_512 { n_ref_340[id_511] };
            uint8_t id_513 { 0 };
            uint32_t id_514 { lebsz_ref_341[id_513] };
            uint8_t id_515 { 7 };
            uint32_t id_516 { uint32_t(id_514 << id_515) };
            bool id_517 { bool(id_512 >= id_516) };
            while_flag_510 = id_517;
            if (while_flag_510) {
              uint8_t id_518 { 0 };
              uint8_t id_519 { 0 };
              uint32_t id_520 { lebsz_ref_341[id_519] };
              uint32_t id_521 { 1U };
              uint32_t id_522 { uint32_t(id_520 + id_521) };
              Void id_523 { ((void)(lebsz_ref_341[id_518] = id_522), ::dessser::Void()) };
              (void)id_523;
            }
          } while (while_flag_510);
          (void)::dessser::Void();
          uint8_t id_524 { 0 };
          uint32_t id_525 { lebsz_ref_341[id_524] };
          Size id_526 { Size(id_525) };
          let_res_509 = id_526;
        }
        let_res_506 = let_res_509;
      }
      std::string id_527 { p_0.column };
      uint32_t id_528 { (uint32_t)id_527.size() };
      Size id_529 { Size(id_528) };
      Size id_530 { Size(let_res_506 + id_529) };
      Size id_531 { Size(sz_338 + id_530) };
      let_res_502 = id_531;
    }
    Size let_res_532;
    {
      Size sz_342 { let_res_502 };
      Arr<std::string> id_533 { p_0.factors };
      uint32_t id_534 { id_533.size() };
      Vec<1, uint32_t> id_535 {  id_534  };
      Size let_res_536;
      {
        Vec<1, uint32_t> n_ref_343 { id_535 };
        uint32_t id_537 { 1U };
        Vec<1, uint32_t> id_538 {  id_537  };
        Size let_res_539;
        {
          Vec<1, uint32_t> lebsz_ref_344 { id_538 };
          bool while_flag_540 { true };
          do {
            uint8_t id_541 { 0 };
            uint32_t id_542 { n_ref_343[id_541] };
            uint8_t id_543 { 0 };
            uint32_t id_544 { lebsz_ref_344[id_543] };
            uint8_t id_545 { 7 };
            uint32_t id_546 { uint32_t(id_544 << id_545) };
            bool id_547 { bool(id_542 >= id_546) };
            while_flag_540 = id_547;
            if (while_flag_540) {
              uint8_t id_548 { 0 };
              uint8_t id_549 { 0 };
              uint32_t id_550 { lebsz_ref_344[id_549] };
              uint32_t id_551 { 1U };
              uint32_t id_552 { uint32_t(id_550 + id_551) };
              Void id_553 { ((void)(lebsz_ref_344[id_548] = id_552), ::dessser::Void()) };
              (void)id_553;
            }
          } while (while_flag_540);
          (void)::dessser::Void();
          uint8_t id_554 { 0 };
          uint32_t id_555 { lebsz_ref_344[id_554] };
          Size id_556 { Size(id_555) };
          let_res_539 = id_556;
        }
        let_res_536 = let_res_539;
      }
      Size id_557 { Size(sz_342 + let_res_536) };
      Vec<1, Size> id_558 {  id_557  };
      Size let_res_559;
      {
        Vec<1, Size> sz_ref_345 { id_558 };
        int32_t id_560 { 0L };
        Vec<1, int32_t> id_561 {  id_560  };
        {
          Vec<1, int32_t> repeat_n_346 { id_561 };
          bool while_flag_562 { true };
          do {
            Arr<std::string> id_563 { p_0.factors };
            uint32_t id_564 { id_563.size() };
            int32_t id_565 { int32_t(id_564) };
            uint8_t id_566 { 0 };
            int32_t id_567 { repeat_n_346[id_566] };
            bool id_568 { bool(id_565 > id_567) };
            while_flag_562 = id_568;
            if (while_flag_562) {
              uint8_t id_569 { 0 };
              uint8_t id_570 { 0 };
              Size id_571 { sz_ref_345[id_570] };
              uint8_t id_572 { 0 };
              int32_t id_573 { repeat_n_346[id_572] };
              Arr<std::string> id_574 { p_0.factors };
              std::string id_575 { id_574[id_573] };
              uint32_t id_576 { (uint32_t)id_575.size() };
              Size let_res_577;
              {
                uint32_t wlen_347 { id_576 };
                Vec<1, uint32_t> id_578 {  wlen_347  };
                Size let_res_579;
                {
                  Vec<1, uint32_t> n_ref_348 { id_578 };
                  uint32_t id_580 { 1U };
                  Vec<1, uint32_t> id_581 {  id_580  };
                  Size let_res_582;
                  {
                    Vec<1, uint32_t> lebsz_ref_349 { id_581 };
                    bool while_flag_583 { true };
                    do {
                      uint8_t id_584 { 0 };
                      uint32_t id_585 { n_ref_348[id_584] };
                      uint8_t id_586 { 0 };
                      uint32_t id_587 { lebsz_ref_349[id_586] };
                      uint8_t id_588 { 7 };
                      uint32_t id_589 { uint32_t(id_587 << id_588) };
                      bool id_590 { bool(id_585 >= id_589) };
                      while_flag_583 = id_590;
                      if (while_flag_583) {
                        uint8_t id_591 { 0 };
                        uint8_t id_592 { 0 };
                        uint32_t id_593 { lebsz_ref_349[id_592] };
                        uint32_t id_594 { 1U };
                        uint32_t id_595 { uint32_t(id_593 + id_594) };
                        Void id_596 { ((void)(lebsz_ref_349[id_591] = id_595), ::dessser::Void()) };
                        (void)id_596;
                      }
                    } while (while_flag_583);
                    (void)::dessser::Void();
                    uint8_t id_597 { 0 };
                    uint32_t id_598 { lebsz_ref_349[id_597] };
                    Size id_599 { Size(id_598) };
                    let_res_582 = id_599;
                  }
                  let_res_579 = let_res_582;
                }
                Size id_600 { Size(wlen_347) };
                Size id_601 { Size(let_res_579 + id_600) };
                let_res_577 = id_601;
              }
              Size id_602 { Size(id_571 + let_res_577) };
              Void id_603 { ((void)(sz_ref_345[id_569] = id_602), ::dessser::Void()) };
              (void)id_603;
              uint8_t id_604 { 0 };
              uint8_t id_605 { 0 };
              int32_t id_606 { repeat_n_346[id_605] };
              int32_t id_607 { 1L };
              int32_t id_608 { int32_t(id_606 + id_607) };
              Void id_609 { ((void)(repeat_n_346[id_604] = id_608), ::dessser::Void()) };
              (void)id_609;
              (void)id_609;
            }
          } while (while_flag_562);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_610 { 0 };
        Size id_611 { sz_ref_345[id_610] };
        let_res_559 = id_611;
      }
      let_res_532 = let_res_559;
    }
    Size id_612 { 1UL };
    Size id_613 { Size(let_res_532 + id_612) };
    return id_613;
  }
   };
  return fun497;
}
std::function<Size(::dessser::gen::dashboard_widget::field &)> field_sersize_of_row_binary(field_sersize_of_row_binary_init());

/* 
    (fun ("{name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]}")
      (let "sz_353" (add (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "name" (param 0))) (size 1))
        (let "sz_ref_356"
          (make-vec
            (add (identifier "sz_353")
              (let "n_ref_354" (make-vec (cardinality (get-field "fields" (param 0))))
                (let "lebsz_ref_355" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_354")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_355")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_355") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_355")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_355"))))))))
          (seq
            (let "repeat_n_357" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "fields" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_357")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_356")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_356")) (apply (identifier "field-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_357")) (get-field "fields" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_357") (add (unsafe-nth (u8 0) (identifier "repeat_n_357")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_356"))))))
 */
static std::function<Size(::dessser::gen::dashboard_widget::source &)> source_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::source &)> fun614 { [&](::dessser::gen::dashboard_widget::source p_0) {
    auto fun615 { dessser::gen::fq_function_name::sersize_of_row_binary };
    dessser::gen::fq_function_name::t_ext id_616 { p_0.name };
    Size id_617 { fun615(id_616) };
    Size id_618 { 1UL };
    Size id_619 { Size(id_617 + id_618) };
    Size let_res_620;
    {
      Size sz_353 { id_619 };
      Arr<::dessser::gen::dashboard_widget::field> id_621 { p_0.fields };
      uint32_t id_622 { id_621.size() };
      Vec<1, uint32_t> id_623 {  id_622  };
      Size let_res_624;
      {
        Vec<1, uint32_t> n_ref_354 { id_623 };
        uint32_t id_625 { 1U };
        Vec<1, uint32_t> id_626 {  id_625  };
        Size let_res_627;
        {
          Vec<1, uint32_t> lebsz_ref_355 { id_626 };
          bool while_flag_628 { true };
          do {
            uint8_t id_629 { 0 };
            uint32_t id_630 { n_ref_354[id_629] };
            uint8_t id_631 { 0 };
            uint32_t id_632 { lebsz_ref_355[id_631] };
            uint8_t id_633 { 7 };
            uint32_t id_634 { uint32_t(id_632 << id_633) };
            bool id_635 { bool(id_630 >= id_634) };
            while_flag_628 = id_635;
            if (while_flag_628) {
              uint8_t id_636 { 0 };
              uint8_t id_637 { 0 };
              uint32_t id_638 { lebsz_ref_355[id_637] };
              uint32_t id_639 { 1U };
              uint32_t id_640 { uint32_t(id_638 + id_639) };
              Void id_641 { ((void)(lebsz_ref_355[id_636] = id_640), ::dessser::Void()) };
              (void)id_641;
            }
          } while (while_flag_628);
          (void)::dessser::Void();
          uint8_t id_642 { 0 };
          uint32_t id_643 { lebsz_ref_355[id_642] };
          Size id_644 { Size(id_643) };
          let_res_627 = id_644;
        }
        let_res_624 = let_res_627;
      }
      Size id_645 { Size(sz_353 + let_res_624) };
      Vec<1, Size> id_646 {  id_645  };
      Size let_res_647;
      {
        Vec<1, Size> sz_ref_356 { id_646 };
        int32_t id_648 { 0L };
        Vec<1, int32_t> id_649 {  id_648  };
        {
          Vec<1, int32_t> repeat_n_357 { id_649 };
          bool while_flag_650 { true };
          do {
            Arr<::dessser::gen::dashboard_widget::field> id_651 { p_0.fields };
            uint32_t id_652 { id_651.size() };
            int32_t id_653 { int32_t(id_652) };
            uint8_t id_654 { 0 };
            int32_t id_655 { repeat_n_357[id_654] };
            bool id_656 { bool(id_653 > id_655) };
            while_flag_650 = id_656;
            if (while_flag_650) {
              uint8_t id_657 { 0 };
              uint8_t id_658 { 0 };
              Size id_659 { sz_ref_356[id_658] };
              uint8_t id_660 { 0 };
              int32_t id_661 { repeat_n_357[id_660] };
              Arr<::dessser::gen::dashboard_widget::field> id_662 { p_0.fields };
              ::dessser::gen::dashboard_widget::field id_663 { id_662[id_661] };
              Size id_664 { field_sersize_of_row_binary(id_663) };
              Size id_665 { Size(id_659 + id_664) };
              Void id_666 { ((void)(sz_ref_356[id_657] = id_665), ::dessser::Void()) };
              (void)id_666;
              uint8_t id_667 { 0 };
              uint8_t id_668 { 0 };
              int32_t id_669 { repeat_n_357[id_668] };
              int32_t id_670 { 1L };
              int32_t id_671 { int32_t(id_669 + id_670) };
              Void id_672 { ((void)(repeat_n_357[id_667] = id_671), ::dessser::Void()) };
              (void)id_672;
              (void)id_672;
            }
          } while (while_flag_650);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_673 { 0 };
        Size id_674 { sz_ref_356[id_673] };
        let_res_647 = id_674;
      }
      let_res_620 = let_res_647;
    }
    return let_res_620;
  }
   };
  return fun614;
}
std::function<Size(::dessser::gen::dashboard_widget::source &)> source_sersize_of_row_binary(source_sersize_of_row_binary_init());

/* 
    (fun ("[Linear Void | Logarithmic Void]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 2))))
 */
static std::function<Size(::dessser::gen::dashboard_widget::scale const &)> scale_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::scale const &)> fun675 { [&](::dessser::gen::dashboard_widget::scale p_0) {
    uint16_t id_676 { 0 };
    uint16_t id_677 { uint16_t(p_0) };
    bool id_678 { bool(id_676 == id_677) };
    Size choose_res_679;
    if (id_678) {
      Size id_680 { 2UL };
      choose_res_679 = id_680;
    } else {
      uint16_t id_681 { uint16_t(p_0) };
      uint16_t id_682 { 1 };
      bool id_683 { bool(id_681 == id_682) };
      Void id_684 { ((void)(assert(id_683)), ::dessser::Void()) };
      (void)id_684;
      Size id_685 { 2UL };
      choose_res_679 = id_685;
    }
    return choose_res_679;
  }
   };
  return fun675;
}
std::function<Size(::dessser::gen::dashboard_widget::scale const &)> scale_sersize_of_row_binary(scale_sersize_of_row_binary_init());

/* 
    (fun ("{left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])}") (add (size 2) (apply (identifier "scale-sersize-of-row-binary") (get-field "scale" (param 0)))))
 */
static std::function<Size(::dessser::gen::dashboard_widget::axis const &)> axis_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::axis const &)> fun686 { [&](::dessser::gen::dashboard_widget::axis p_0) {
    Size id_687 { 2UL };
    ::dessser::gen::dashboard_widget::scale id_688 { p_0.scale };
    Size id_689 { scale_sersize_of_row_binary(id_688) };
    Size id_690 { Size(id_687 + id_689) };
    return id_690;
  }
   };
  return fun686;
}
std::function<Size(::dessser::gen::dashboard_widget::axis const &)> axis_sersize_of_row_binary(axis_sersize_of_row_binary_init());

/* 
    (fun ("[Plot Void]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 2)))
 */
static std::function<Size(::dessser::gen::dashboard_widget::type const &)> type_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::type const &)> fun691 { [&](::dessser::gen::dashboard_widget::type p_0) {
    uint16_t id_692 { uint16_t(p_0) };
    uint16_t id_693 { 0 };
    bool id_694 { bool(id_692 == id_693) };
    Void id_695 { ((void)(assert(id_694)), ::dessser::Void()) };
    (void)id_695;
    Size id_696 { 2UL };
    return id_696;
  }
   };
  return fun691;
}
std::function<Size(::dessser::gen::dashboard_widget::type const &)> type_sersize_of_row_binary(type_sersize_of_row_binary_init());

/* 
    (fun ("{title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]}")
      (let "sz_368"
        (let "sz_363"
          (let "sz_362"
            (add
              (let "n_ref_360" (make-vec (string-length (get-field "title" (param 0))))
                (let "lebsz_ref_361" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_360")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_361")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_361") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_361")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_361")))))) 
              (size-of-u32 (string-length (get-field "title" (param 0))))) 
            (add (identifier "sz_362") (apply (identifier "type-sersize-of-row-binary") (get-field "type" (param 0)))))
          (let "sz_ref_366"
            (make-vec
              (add (identifier "sz_363")
                (let "n_ref_364" (make-vec (cardinality (get-field "axes" (param 0))))
                  (let "lebsz_ref_365" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_364")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_365") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_365"))))))))
            (seq
              (let "repeat_n_367" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "axes" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_367")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_366")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_366")) (apply (identifier "axis-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_367")) (get-field "axes" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_367") (add (unsafe-nth (u8 0) (identifier "repeat_n_367")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_366")))))
        (let "sz_ref_371"
          (make-vec
            (add (identifier "sz_368")
              (let "n_ref_369" (make-vec (cardinality (get-field "sources" (param 0))))
                (let "lebsz_ref_370" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_369")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_370")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_370") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_370")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_370"))))))))
          (seq
            (let "repeat_n_372" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "sources" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_372")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_371")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_371")) (apply (identifier "source-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_372")) (get-field "sources" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_372") (add (unsafe-nth (u8 0) (identifier "repeat_n_372")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_371"))))))
 */
static std::function<Size(::dessser::gen::dashboard_widget::chart &)> chart_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::chart &)> fun697 { [&](::dessser::gen::dashboard_widget::chart p_0) {
    std::string id_698 { p_0.title };
    uint32_t id_699 { (uint32_t)id_698.size() };
    Vec<1, uint32_t> id_700 {  id_699  };
    Size let_res_701;
    {
      Vec<1, uint32_t> n_ref_360 { id_700 };
      uint32_t id_702 { 1U };
      Vec<1, uint32_t> id_703 {  id_702  };
      Size let_res_704;
      {
        Vec<1, uint32_t> lebsz_ref_361 { id_703 };
        bool while_flag_705 { true };
        do {
          uint8_t id_706 { 0 };
          uint32_t id_707 { n_ref_360[id_706] };
          uint8_t id_708 { 0 };
          uint32_t id_709 { lebsz_ref_361[id_708] };
          uint8_t id_710 { 7 };
          uint32_t id_711 { uint32_t(id_709 << id_710) };
          bool id_712 { bool(id_707 >= id_711) };
          while_flag_705 = id_712;
          if (while_flag_705) {
            uint8_t id_713 { 0 };
            uint8_t id_714 { 0 };
            uint32_t id_715 { lebsz_ref_361[id_714] };
            uint32_t id_716 { 1U };
            uint32_t id_717 { uint32_t(id_715 + id_716) };
            Void id_718 { ((void)(lebsz_ref_361[id_713] = id_717), ::dessser::Void()) };
            (void)id_718;
          }
        } while (while_flag_705);
        (void)::dessser::Void();
        uint8_t id_719 { 0 };
        uint32_t id_720 { lebsz_ref_361[id_719] };
        Size id_721 { Size(id_720) };
        let_res_704 = id_721;
      }
      let_res_701 = let_res_704;
    }
    std::string id_722 { p_0.title };
    uint32_t id_723 { (uint32_t)id_722.size() };
    Size id_724 { Size(id_723) };
    Size id_725 { Size(let_res_701 + id_724) };
    Size let_res_726;
    {
      Size sz_362 { id_725 };
      ::dessser::gen::dashboard_widget::type id_727 { p_0.type };
      Size id_728 { type_sersize_of_row_binary(id_727) };
      Size id_729 { Size(sz_362 + id_728) };
      let_res_726 = id_729;
    }
    Size let_res_730;
    {
      Size sz_363 { let_res_726 };
      Arr<::dessser::gen::dashboard_widget::axis> id_731 { p_0.axes };
      uint32_t id_732 { id_731.size() };
      Vec<1, uint32_t> id_733 {  id_732  };
      Size let_res_734;
      {
        Vec<1, uint32_t> n_ref_364 { id_733 };
        uint32_t id_735 { 1U };
        Vec<1, uint32_t> id_736 {  id_735  };
        Size let_res_737;
        {
          Vec<1, uint32_t> lebsz_ref_365 { id_736 };
          bool while_flag_738 { true };
          do {
            uint8_t id_739 { 0 };
            uint32_t id_740 { n_ref_364[id_739] };
            uint8_t id_741 { 0 };
            uint32_t id_742 { lebsz_ref_365[id_741] };
            uint8_t id_743 { 7 };
            uint32_t id_744 { uint32_t(id_742 << id_743) };
            bool id_745 { bool(id_740 >= id_744) };
            while_flag_738 = id_745;
            if (while_flag_738) {
              uint8_t id_746 { 0 };
              uint8_t id_747 { 0 };
              uint32_t id_748 { lebsz_ref_365[id_747] };
              uint32_t id_749 { 1U };
              uint32_t id_750 { uint32_t(id_748 + id_749) };
              Void id_751 { ((void)(lebsz_ref_365[id_746] = id_750), ::dessser::Void()) };
              (void)id_751;
            }
          } while (while_flag_738);
          (void)::dessser::Void();
          uint8_t id_752 { 0 };
          uint32_t id_753 { lebsz_ref_365[id_752] };
          Size id_754 { Size(id_753) };
          let_res_737 = id_754;
        }
        let_res_734 = let_res_737;
      }
      Size id_755 { Size(sz_363 + let_res_734) };
      Vec<1, Size> id_756 {  id_755  };
      Size let_res_757;
      {
        Vec<1, Size> sz_ref_366 { id_756 };
        int32_t id_758 { 0L };
        Vec<1, int32_t> id_759 {  id_758  };
        {
          Vec<1, int32_t> repeat_n_367 { id_759 };
          bool while_flag_760 { true };
          do {
            Arr<::dessser::gen::dashboard_widget::axis> id_761 { p_0.axes };
            uint32_t id_762 { id_761.size() };
            int32_t id_763 { int32_t(id_762) };
            uint8_t id_764 { 0 };
            int32_t id_765 { repeat_n_367[id_764] };
            bool id_766 { bool(id_763 > id_765) };
            while_flag_760 = id_766;
            if (while_flag_760) {
              uint8_t id_767 { 0 };
              uint8_t id_768 { 0 };
              Size id_769 { sz_ref_366[id_768] };
              uint8_t id_770 { 0 };
              int32_t id_771 { repeat_n_367[id_770] };
              Arr<::dessser::gen::dashboard_widget::axis> id_772 { p_0.axes };
              ::dessser::gen::dashboard_widget::axis id_773 { id_772[id_771] };
              Size id_774 { axis_sersize_of_row_binary(id_773) };
              Size id_775 { Size(id_769 + id_774) };
              Void id_776 { ((void)(sz_ref_366[id_767] = id_775), ::dessser::Void()) };
              (void)id_776;
              uint8_t id_777 { 0 };
              uint8_t id_778 { 0 };
              int32_t id_779 { repeat_n_367[id_778] };
              int32_t id_780 { 1L };
              int32_t id_781 { int32_t(id_779 + id_780) };
              Void id_782 { ((void)(repeat_n_367[id_777] = id_781), ::dessser::Void()) };
              (void)id_782;
              (void)id_782;
            }
          } while (while_flag_760);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_783 { 0 };
        Size id_784 { sz_ref_366[id_783] };
        let_res_757 = id_784;
      }
      let_res_730 = let_res_757;
    }
    Size let_res_785;
    {
      Size sz_368 { let_res_730 };
      Arr<::dessser::gen::dashboard_widget::source> id_786 { p_0.sources };
      uint32_t id_787 { id_786.size() };
      Vec<1, uint32_t> id_788 {  id_787  };
      Size let_res_789;
      {
        Vec<1, uint32_t> n_ref_369 { id_788 };
        uint32_t id_790 { 1U };
        Vec<1, uint32_t> id_791 {  id_790  };
        Size let_res_792;
        {
          Vec<1, uint32_t> lebsz_ref_370 { id_791 };
          bool while_flag_793 { true };
          do {
            uint8_t id_794 { 0 };
            uint32_t id_795 { n_ref_369[id_794] };
            uint8_t id_796 { 0 };
            uint32_t id_797 { lebsz_ref_370[id_796] };
            uint8_t id_798 { 7 };
            uint32_t id_799 { uint32_t(id_797 << id_798) };
            bool id_800 { bool(id_795 >= id_799) };
            while_flag_793 = id_800;
            if (while_flag_793) {
              uint8_t id_801 { 0 };
              uint8_t id_802 { 0 };
              uint32_t id_803 { lebsz_ref_370[id_802] };
              uint32_t id_804 { 1U };
              uint32_t id_805 { uint32_t(id_803 + id_804) };
              Void id_806 { ((void)(lebsz_ref_370[id_801] = id_805), ::dessser::Void()) };
              (void)id_806;
            }
          } while (while_flag_793);
          (void)::dessser::Void();
          uint8_t id_807 { 0 };
          uint32_t id_808 { lebsz_ref_370[id_807] };
          Size id_809 { Size(id_808) };
          let_res_792 = id_809;
        }
        let_res_789 = let_res_792;
      }
      Size id_810 { Size(sz_368 + let_res_789) };
      Vec<1, Size> id_811 {  id_810  };
      Size let_res_812;
      {
        Vec<1, Size> sz_ref_371 { id_811 };
        int32_t id_813 { 0L };
        Vec<1, int32_t> id_814 {  id_813  };
        {
          Vec<1, int32_t> repeat_n_372 { id_814 };
          bool while_flag_815 { true };
          do {
            Arr<::dessser::gen::dashboard_widget::source> id_816 { p_0.sources };
            uint32_t id_817 { id_816.size() };
            int32_t id_818 { int32_t(id_817) };
            uint8_t id_819 { 0 };
            int32_t id_820 { repeat_n_372[id_819] };
            bool id_821 { bool(id_818 > id_820) };
            while_flag_815 = id_821;
            if (while_flag_815) {
              uint8_t id_822 { 0 };
              uint8_t id_823 { 0 };
              Size id_824 { sz_ref_371[id_823] };
              uint8_t id_825 { 0 };
              int32_t id_826 { repeat_n_372[id_825] };
              Arr<::dessser::gen::dashboard_widget::source> id_827 { p_0.sources };
              ::dessser::gen::dashboard_widget::source id_828 { id_827[id_826] };
              Size id_829 { source_sersize_of_row_binary(id_828) };
              Size id_830 { Size(id_824 + id_829) };
              Void id_831 { ((void)(sz_ref_371[id_822] = id_830), ::dessser::Void()) };
              (void)id_831;
              uint8_t id_832 { 0 };
              uint8_t id_833 { 0 };
              int32_t id_834 { repeat_n_372[id_833] };
              int32_t id_835 { 1L };
              int32_t id_836 { int32_t(id_834 + id_835) };
              Void id_837 { ((void)(repeat_n_372[id_832] = id_836), ::dessser::Void()) };
              (void)id_837;
              (void)id_837;
            }
          } while (while_flag_815);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_838 { 0 };
        Size id_839 { sz_ref_371[id_838] };
        let_res_812 = id_839;
      }
      let_res_785 = let_res_812;
    }
    return let_res_785;
  }
   };
  return fun697;
}
std::function<Size(::dessser::gen::dashboard_widget::chart &)> chart_sersize_of_row_binary(chart_sersize_of_row_binary_init());

/* 
    (fun ("[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_375" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "lebsz_ref_376" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_375")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_376")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_376") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_376")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_376")))))) 
            (size-of-u32 (string-length (get-alt "Text" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "chart-sersize-of-row-binary") (get-alt "Chart" (param 0)))))))
 */
static std::function<Size(::dessser::gen::dashboard_widget::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::t &)> fun840 { [&](::dessser::gen::dashboard_widget::t p_0) {
    uint16_t id_841 { 0 };
    uint16_t id_842 { uint16_t(p_0.index()) };
    bool id_843 { bool(id_841 == id_842) };
    Size choose_res_844;
    if (id_843) {
      Size id_845 { 2UL };
      std::string id_846 { std::get<0 /* Text */>(p_0) };
      uint32_t id_847 { (uint32_t)id_846.size() };
      Vec<1, uint32_t> id_848 {  id_847  };
      Size let_res_849;
      {
        Vec<1, uint32_t> n_ref_375 { id_848 };
        uint32_t id_850 { 1U };
        Vec<1, uint32_t> id_851 {  id_850  };
        Size let_res_852;
        {
          Vec<1, uint32_t> lebsz_ref_376 { id_851 };
          bool while_flag_853 { true };
          do {
            uint8_t id_854 { 0 };
            uint32_t id_855 { n_ref_375[id_854] };
            uint8_t id_856 { 0 };
            uint32_t id_857 { lebsz_ref_376[id_856] };
            uint8_t id_858 { 7 };
            uint32_t id_859 { uint32_t(id_857 << id_858) };
            bool id_860 { bool(id_855 >= id_859) };
            while_flag_853 = id_860;
            if (while_flag_853) {
              uint8_t id_861 { 0 };
              uint8_t id_862 { 0 };
              uint32_t id_863 { lebsz_ref_376[id_862] };
              uint32_t id_864 { 1U };
              uint32_t id_865 { uint32_t(id_863 + id_864) };
              Void id_866 { ((void)(lebsz_ref_376[id_861] = id_865), ::dessser::Void()) };
              (void)id_866;
            }
          } while (while_flag_853);
          (void)::dessser::Void();
          uint8_t id_867 { 0 };
          uint32_t id_868 { lebsz_ref_376[id_867] };
          Size id_869 { Size(id_868) };
          let_res_852 = id_869;
        }
        let_res_849 = let_res_852;
      }
      std::string id_870 { std::get<0 /* Text */>(p_0) };
      uint32_t id_871 { (uint32_t)id_870.size() };
      Size id_872 { Size(id_871) };
      Size id_873 { Size(let_res_849 + id_872) };
      Size id_874 { Size(id_845 + id_873) };
      choose_res_844 = id_874;
    } else {
      uint16_t id_875 { uint16_t(p_0.index()) };
      uint16_t id_876 { 1 };
      bool id_877 { bool(id_875 == id_876) };
      Void id_878 { ((void)(assert(id_877)), ::dessser::Void()) };
      (void)id_878;
      Size id_879 { 2UL };
      ::dessser::gen::dashboard_widget::chart id_880 { std::get<1 /* Chart */>(p_0) };
      Size id_881 { chart_sersize_of_row_binary(id_880) };
      Size id_882 { Size(id_879 + id_881) };
      choose_res_844 = id_882;
    }
    return choose_res_844;
  }
   };
  return fun840;
}
std::function<Size(::dessser::gen::dashboard_widget::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_105" (let-pair "du16_fst_100" "du16_snd_101" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_100") (identifier "du16_snd_101")))
        (let-pair "dsum1_fst_106" "dsum1_snd_107" (identifier "dsum1_105")
          (if (eq (u16 0) (identifier "dsum1_fst_106")) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 0 (nop)) (identifier "dsum1_snd_107"))
            (if (eq (u16 1) (identifier "dsum1_fst_106")) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 1 (nop)) (identifier "dsum1_snd_107"))
              (if (eq (u16 2) (identifier "dsum1_fst_106")) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 2 (nop)) (identifier "dsum1_snd_107"))
                (seq (assert (eq (identifier "dsum1_fst_106") (u16 3))) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 3 (nop)) (identifier "dsum1_snd_107")))))))))
 */
static std::function<::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3(Pointer &)> representation_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3(Pointer &)> fun883 { [&](Pointer p_0) {
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_884 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 letpair_res_885;
    {
      auto du16_fst_100 { std::get<0>(id_884) };
      auto du16_snd_101 { std::get<1>(id_884) };
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_886 { du16_fst_100, du16_snd_101 };
      letpair_res_885 = id_886;
    }
    ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 let_res_887;
    {
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 dsum1_105 { letpair_res_885 };
      ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 letpair_res_888;
      {
        auto dsum1_fst_106 { std::get<0>(dsum1_105) };
        auto dsum1_snd_107 { std::get<1>(dsum1_105) };
        uint16_t id_889 { 0 };
        bool id_890 { bool(id_889 == dsum1_fst_106) };
        ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 choose_res_891;
        if (id_890) {
          (void)::dessser::Void();
          ::dessser::gen::dashboard_widget::representation id_892 { Unused };
          ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 id_893 { id_892, dsum1_snd_107 };
          choose_res_891 = id_893;
        } else {
          uint16_t id_894 { 1 };
          bool id_895 { bool(id_894 == dsum1_fst_106) };
          ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 choose_res_896;
          if (id_895) {
            (void)::dessser::Void();
            ::dessser::gen::dashboard_widget::representation id_897 { Independent };
            ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 id_898 { id_897, dsum1_snd_107 };
            choose_res_896 = id_898;
          } else {
            uint16_t id_899 { 2 };
            bool id_900 { bool(id_899 == dsum1_fst_106) };
            ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 choose_res_901;
            if (id_900) {
              (void)::dessser::Void();
              ::dessser::gen::dashboard_widget::representation id_902 { Stacked };
              ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 id_903 { id_902, dsum1_snd_107 };
              choose_res_901 = id_903;
            } else {
              uint16_t id_904 { 3 };
              bool id_905 { bool(dsum1_fst_106 == id_904) };
              Void id_906 { ((void)(assert(id_905)), ::dessser::Void()) };
              (void)id_906;
              (void)::dessser::Void();
              ::dessser::gen::dashboard_widget::representation id_907 { StackCentered };
              ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 id_908 { id_907, dsum1_snd_107 };
              choose_res_901 = id_908;
            }
            choose_res_896 = choose_res_901;
          }
          choose_res_891 = choose_res_896;
        }
        letpair_res_888 = choose_res_891;
      }
      let_res_887 = letpair_res_888;
    }
    return let_res_887;
  }
   };
  return fun883;
}
std::function<::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3(Pointer &)> representation_of_row_binary(representation_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_123" (let-pair "dfloat_fst_121" "dfloat_snd_122" (read-u64 little-endian (param 0)) (make-tup (float-of-u64 (identifier "dfloat_fst_121")) (identifier "dfloat_snd_122")))
        (let-pair "drec_fst_124" "drec_snd_125" (identifier "drec_123")
          (let "drec_129" (let-pair "du32_fst_127" "du32_snd_128" (read-u32 little-endian (identifier "drec_snd_125")) (make-tup (identifier "du32_fst_127") (identifier "du32_snd_128")))
            (let-pair "drec_fst_130" "drec_snd_131" (identifier "drec_129")
              (let "drec_132" (apply (identifier "representation-of-row-binary") (identifier "drec_snd_131"))
                (let-pair "drec_fst_133" "drec_snd_134" (identifier "drec_132")
                  (let "drec_147"
                    (let "dstring1_141"
                      (let "leb_ref_135" (make-vec (u32 0))
                        (let "shft_ref_136" (make-vec (u8 0))
                          (let "p_ref_137" (make-vec (identifier "drec_snd_134"))
                            (seq
                              (while
                                (let "leb128_138" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_137")))
                                  (let-pair "leb128_fst_139" "leb128_snd_140" 
                                    (identifier "leb128_138")
                                    (seq (set-vec (u8 0) (identifier "p_ref_137") (identifier "leb128_snd_140"))
                                      (set-vec (u8 0) (identifier "leb_ref_135")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_139") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_136"))) (unsafe-nth (u8 0) (identifier "leb_ref_135"))))
                                      (set-vec (u8 0) (identifier "shft_ref_136") (add (unsafe-nth (u8 0) (identifier "shft_ref_136")) (u8 7))) 
                                      (ge (identifier "leb128_fst_139") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_135"))) (unsafe-nth (u8 0) (identifier "p_ref_137")))))))
                      (let-pair "dstring1_fst_142" "dstring1_snd_143" 
                        (identifier "dstring1_141")
                        (let-pair "dstring2_fst_145" "dstring2_snd_146" 
                          (read-bytes (identifier "dstring1_snd_143") (identifier "dstring1_fst_142")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_145")) (identifier "dstring2_snd_146")))))
                    (let-pair "drec_fst_148" "drec_snd_149" (identifier "drec_147")
                      (let "drec_185"
                        (let-pair "dlist4_fst_183" "dlist4_snd_184"
                          (let "dlist1_159"
                            (let "leb_ref_150" (make-vec (u32 0))
                              (let "shft_ref_151" (make-vec (u8 0))
                                (let "p_ref_152" (make-vec (identifier "drec_snd_149"))
                                  (seq
                                    (while
                                      (let "leb128_153" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_152")))
                                        (let-pair "leb128_fst_154" "leb128_snd_155" 
                                          (identifier "leb128_153")
                                          (seq (set-vec (u8 0) (identifier "p_ref_152") (identifier "leb128_snd_155"))
                                            (set-vec (u8 0) (identifier "leb_ref_150")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_154") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_151"))) (unsafe-nth (u8 0) (identifier "leb_ref_150"))))
                                            (set-vec (u8 0) (identifier "shft_ref_151") (add (unsafe-nth (u8 0) (identifier "shft_ref_151")) (u8 7))) 
                                            (ge (identifier "leb128_fst_154") (u8 128))))) 
                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_150")) (unsafe-nth (u8 0) (identifier "p_ref_152")))))))
                            (let-pair "dlist1_fst_160" "dlist1_snd_161" 
                              (identifier "dlist1_159")
                              (let "inits_src_ref_162" (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_161")))
                                (seq
                                  (let "repeat_n_163" (make-vec (i32 0))
                                    (while (gt (to-i32 (identifier "dlist1_fst_160")) (unsafe-nth (u8 0) (identifier "repeat_n_163")))
                                      (seq
                                        (let "dlist2_164" (unsafe-nth (u8 0) (identifier "inits_src_ref_162"))
                                          (let-pair "dlist2_fst_165" "dlist2_snd_166" 
                                            (identifier "dlist2_164")
                                            (set-vec (u8 0) (identifier "inits_src_ref_162")
                                              (let "dstring1_173"
                                                (let "leb_ref_167" (make-vec (u32 0))
                                                  (let "shft_ref_168" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_169" 
                                                      (make-vec (identifier "dlist2_snd_166"))
                                                      (seq
                                                        (while
                                                          (let "leb128_170" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_169")))
                                                            (let-pair "leb128_fst_171" "leb128_snd_172" 
                                                              (identifier "leb128_170")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_169") (identifier "leb128_snd_172"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_167")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_171") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_168")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_167")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_168") (add (unsafe-nth (u8 0) (identifier "shft_ref_168")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_171") (u8 128))))) 
                                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_167"))) (unsafe-nth (u8 0) (identifier "p_ref_169")))))))
                                                (let-pair "dstring1_fst_174" "dstring1_snd_175" 
                                                  (identifier "dstring1_173")
                                                  (let-pair "dstring2_fst_177" "dstring2_snd_178" 
                                                    (read-bytes (identifier "dstring1_snd_175") (identifier "dstring1_fst_174"))
                                                    (make-tup (cons (string-of-bytes (identifier "dstring2_fst_177")) (identifier "dlist2_fst_165")) (identifier "dstring2_snd_178"))))))))
                                        (set-vec (u8 0) (identifier "repeat_n_163") (add (unsafe-nth (u8 0) (identifier "repeat_n_163")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_162")))))) 
                          (make-tup (arr-of-lst-rev (identifier "dlist4_fst_183")) (identifier "dlist4_snd_184")))
                        (let-pair "drec_fst_186" "drec_snd_187" (identifier "drec_185")
                          (let-pair "du8_fst_189" "du8_snd_190" (read-u8 (identifier "drec_snd_187"))
                            (make-tup
                              (make-rec (string "axis") (identifier "du8_fst_189") 
                                (string "factors") (identifier "drec_fst_186") 
                                (string "column") (identifier "drec_fst_148") 
                                (string "representation") (identifier "drec_fst_133") 
                                (string "color") (identifier "drec_fst_130") 
                                (string "opacity") (identifier "drec_fst_124")) 
                              (identifier "du8_snd_190"))))))))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8(Pointer &)> field_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8(Pointer &)> fun909 { [&](Pointer p_0) {
    ::dessser::gen::dashboard_widget::td2cd337bb3c8bc04d5603393d084985b id_910 { p_0.readU64Le() };
    ::dessser::gen::dashboard_widget::t9a758baeff17224a77e1a522010b4168 letpair_res_911;
    {
      auto dfloat_fst_121 { std::get<0>(id_910) };
      auto dfloat_snd_122 { std::get<1>(id_910) };
      double id_912 { float_of_qword(dfloat_fst_121) };
      ::dessser::gen::dashboard_widget::t9a758baeff17224a77e1a522010b4168 id_913 { id_912, dfloat_snd_122 };
      letpair_res_911 = id_913;
    }
    ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 let_res_914;
    {
      ::dessser::gen::dashboard_widget::t9a758baeff17224a77e1a522010b4168 drec_123 { letpair_res_911 };
      ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 letpair_res_915;
      {
        auto drec_fst_124 { std::get<0>(drec_123) };
        auto drec_snd_125 { std::get<1>(drec_123) };
        ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 id_916 { drec_snd_125.readU32Le() };
        ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 letpair_res_917;
        {
          auto du32_fst_127 { std::get<0>(id_916) };
          auto du32_snd_128 { std::get<1>(id_916) };
          ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 id_918 { du32_fst_127, du32_snd_128 };
          letpair_res_917 = id_918;
        }
        ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 let_res_919;
        {
          ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 drec_129 { letpair_res_917 };
          ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 letpair_res_920;
          {
            auto drec_fst_130 { std::get<0>(drec_129) };
            auto drec_snd_131 { std::get<1>(drec_129) };
            ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 id_921 { representation_of_row_binary(drec_snd_131) };
            ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 let_res_922;
            {
              ::dessser::gen::dashboard_widget::tc1bf32b9478802aec66a4e35731c20e3 drec_132 { id_921 };
              ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 letpair_res_923;
              {
                auto drec_fst_133 { std::get<0>(drec_132) };
                auto drec_snd_134 { std::get<1>(drec_132) };
                uint32_t id_924 { 0U };
                Vec<1, uint32_t> id_925 {  id_924  };
                ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_926;
                {
                  Vec<1, uint32_t> leb_ref_135 { id_925 };
                  uint8_t id_927 { 0 };
                  Vec<1, uint8_t> id_928 {  id_927  };
                  ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_929;
                  {
                    Vec<1, uint8_t> shft_ref_136 { id_928 };
                    Vec<1, Pointer> id_930 {  drec_snd_134  };
                    ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_931;
                    {
                      Vec<1, Pointer> p_ref_137 { id_930 };
                      bool while_flag_932 { true };
                      do {
                        uint8_t id_933 { 0 };
                        Pointer id_934 { p_ref_137[id_933] };
                        ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_935 { id_934.readU8() };
                        bool let_res_936;
                        {
                          ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_138 { id_935 };
                          bool letpair_res_937;
                          {
                            auto leb128_fst_139 { std::get<0>(leb128_138) };
                            auto leb128_snd_140 { std::get<1>(leb128_138) };
                            uint8_t id_938 { 0 };
                            Void id_939 { ((void)(p_ref_137[id_938] = leb128_snd_140), ::dessser::Void()) };
                            (void)id_939;
                            uint8_t id_940 { 0 };
                            uint8_t id_941 { 127 };
                            uint8_t id_942 { uint8_t(leb128_fst_139 & id_941) };
                            uint32_t id_943 { uint32_t(id_942) };
                            uint8_t id_944 { 0 };
                            uint8_t id_945 { shft_ref_136[id_944] };
                            uint32_t id_946 { uint32_t(id_943 << id_945) };
                            uint8_t id_947 { 0 };
                            uint32_t id_948 { leb_ref_135[id_947] };
                            uint32_t id_949 { uint32_t(id_946 | id_948) };
                            Void id_950 { ((void)(leb_ref_135[id_940] = id_949), ::dessser::Void()) };
                            (void)id_950;
                            uint8_t id_951 { 0 };
                            uint8_t id_952 { 0 };
                            uint8_t id_953 { shft_ref_136[id_952] };
                            uint8_t id_954 { 7 };
                            uint8_t id_955 { uint8_t(id_953 + id_954) };
                            Void id_956 { ((void)(shft_ref_136[id_951] = id_955), ::dessser::Void()) };
                            (void)id_956;
                            uint8_t id_957 { 128 };
                            bool id_958 { bool(leb128_fst_139 >= id_957) };
                            letpair_res_937 = id_958;
                          }
                          let_res_936 = letpair_res_937;
                        }
                        while_flag_932 = let_res_936;
                        if (while_flag_932) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_932);
                      (void)::dessser::Void();
                      uint8_t id_959 { 0 };
                      uint32_t id_960 { leb_ref_135[id_959] };
                      Size id_961 { Size(id_960) };
                      uint8_t id_962 { 0 };
                      Pointer id_963 { p_ref_137[id_962] };
                      ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa id_964 { id_961, id_963 };
                      let_res_931 = id_964;
                    }
                    let_res_929 = let_res_931;
                  }
                  let_res_926 = let_res_929;
                }
                ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 let_res_965;
                {
                  ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa dstring1_141 { let_res_926 };
                  ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 letpair_res_966;
                  {
                    auto dstring1_fst_142 { std::get<0>(dstring1_141) };
                    auto dstring1_snd_143 { std::get<1>(dstring1_141) };
                    ::dessser::gen::dashboard_widget::t9ef6882174ae71a34a3c5ef6b29242fb id_967 { dstring1_snd_143.readBytes(dstring1_fst_142) };
                    ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 letpair_res_968;
                    {
                      auto dstring2_fst_145 { std::get<0>(id_967) };
                      auto dstring2_snd_146 { std::get<1>(id_967) };
                      std::string id_969 { dstring2_fst_145.toString() };
                      ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 id_970 { id_969, dstring2_snd_146 };
                      letpair_res_968 = id_970;
                    }
                    letpair_res_966 = letpair_res_968;
                  }
                  let_res_965 = letpair_res_966;
                }
                ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 let_res_971;
                {
                  ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 drec_147 { let_res_965 };
                  ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 letpair_res_972;
                  {
                    auto drec_fst_148 { std::get<0>(drec_147) };
                    auto drec_snd_149 { std::get<1>(drec_147) };
                    uint32_t id_973 { 0U };
                    Vec<1, uint32_t> id_974 {  id_973  };
                    ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_975;
                    {
                      Vec<1, uint32_t> leb_ref_150 { id_974 };
                      uint8_t id_976 { 0 };
                      Vec<1, uint8_t> id_977 {  id_976  };
                      ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_978;
                      {
                        Vec<1, uint8_t> shft_ref_151 { id_977 };
                        Vec<1, Pointer> id_979 {  drec_snd_149  };
                        ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_980;
                        {
                          Vec<1, Pointer> p_ref_152 { id_979 };
                          bool while_flag_981 { true };
                          do {
                            uint8_t id_982 { 0 };
                            Pointer id_983 { p_ref_152[id_982] };
                            ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_984 { id_983.readU8() };
                            bool let_res_985;
                            {
                              ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_153 { id_984 };
                              bool letpair_res_986;
                              {
                                auto leb128_fst_154 { std::get<0>(leb128_153) };
                                auto leb128_snd_155 { std::get<1>(leb128_153) };
                                uint8_t id_987 { 0 };
                                Void id_988 { ((void)(p_ref_152[id_987] = leb128_snd_155), ::dessser::Void()) };
                                (void)id_988;
                                uint8_t id_989 { 0 };
                                uint8_t id_990 { 127 };
                                uint8_t id_991 { uint8_t(leb128_fst_154 & id_990) };
                                uint32_t id_992 { uint32_t(id_991) };
                                uint8_t id_993 { 0 };
                                uint8_t id_994 { shft_ref_151[id_993] };
                                uint32_t id_995 { uint32_t(id_992 << id_994) };
                                uint8_t id_996 { 0 };
                                uint32_t id_997 { leb_ref_150[id_996] };
                                uint32_t id_998 { uint32_t(id_995 | id_997) };
                                Void id_999 { ((void)(leb_ref_150[id_989] = id_998), ::dessser::Void()) };
                                (void)id_999;
                                uint8_t id_1000 { 0 };
                                uint8_t id_1001 { 0 };
                                uint8_t id_1002 { shft_ref_151[id_1001] };
                                uint8_t id_1003 { 7 };
                                uint8_t id_1004 { uint8_t(id_1002 + id_1003) };
                                Void id_1005 { ((void)(shft_ref_151[id_1000] = id_1004), ::dessser::Void()) };
                                (void)id_1005;
                                uint8_t id_1006 { 128 };
                                bool id_1007 { bool(leb128_fst_154 >= id_1006) };
                                letpair_res_986 = id_1007;
                              }
                              let_res_985 = letpair_res_986;
                            }
                            while_flag_981 = let_res_985;
                            if (while_flag_981) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_981);
                          (void)::dessser::Void();
                          uint8_t id_1008 { 0 };
                          uint32_t id_1009 { leb_ref_150[id_1008] };
                          uint8_t id_1010 { 0 };
                          Pointer id_1011 { p_ref_152[id_1010] };
                          ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 id_1012 { id_1009, id_1011 };
                          let_res_980 = id_1012;
                        }
                        let_res_978 = let_res_980;
                      }
                      let_res_975 = let_res_978;
                    }
                    ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc let_res_1013;
                    {
                      ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 dlist1_159 { let_res_975 };
                      ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc letpair_res_1014;
                      {
                        auto dlist1_fst_160 { std::get<0>(dlist1_159) };
                        auto dlist1_snd_161 { std::get<1>(dlist1_159) };
                        Lst<std::string> endoflist_1015;
                        ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc id_1016 { endoflist_1015, dlist1_snd_161 };
                        Vec<1, ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc> id_1017 {  id_1016  };
                        ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc let_res_1018;
                        {
                          Vec<1, ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc> inits_src_ref_162 { id_1017 };
                          int32_t id_1019 { 0L };
                          Vec<1, int32_t> id_1020 {  id_1019  };
                          {
                            Vec<1, int32_t> repeat_n_163 { id_1020 };
                            bool while_flag_1021 { true };
                            do {
                              int32_t id_1022 { int32_t(dlist1_fst_160) };
                              uint8_t id_1023 { 0 };
                              int32_t id_1024 { repeat_n_163[id_1023] };
                              bool id_1025 { bool(id_1022 > id_1024) };
                              while_flag_1021 = id_1025;
                              if (while_flag_1021) {
                                uint8_t id_1026 { 0 };
                                ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc id_1027 { inits_src_ref_162[id_1026] };
                                {
                                  ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc dlist2_164 { id_1027 };
                                  {
                                    auto dlist2_fst_165 { std::get<0>(dlist2_164) };
                                    auto dlist2_snd_166 { std::get<1>(dlist2_164) };
                                    uint8_t id_1028 { 0 };
                                    uint32_t id_1029 { 0U };
                                    Vec<1, uint32_t> id_1030 {  id_1029  };
                                    ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1031;
                                    {
                                      Vec<1, uint32_t> leb_ref_167 { id_1030 };
                                      uint8_t id_1032 { 0 };
                                      Vec<1, uint8_t> id_1033 {  id_1032  };
                                      ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1034;
                                      {
                                        Vec<1, uint8_t> shft_ref_168 { id_1033 };
                                        Vec<1, Pointer> id_1035 {  dlist2_snd_166  };
                                        ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1036;
                                        {
                                          Vec<1, Pointer> p_ref_169 { id_1035 };
                                          bool while_flag_1037 { true };
                                          do {
                                            uint8_t id_1038 { 0 };
                                            Pointer id_1039 { p_ref_169[id_1038] };
                                            ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1040 { id_1039.readU8() };
                                            bool let_res_1041;
                                            {
                                              ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_170 { id_1040 };
                                              bool letpair_res_1042;
                                              {
                                                auto leb128_fst_171 { std::get<0>(leb128_170) };
                                                auto leb128_snd_172 { std::get<1>(leb128_170) };
                                                uint8_t id_1043 { 0 };
                                                Void id_1044 { ((void)(p_ref_169[id_1043] = leb128_snd_172), ::dessser::Void()) };
                                                (void)id_1044;
                                                uint8_t id_1045 { 0 };
                                                uint8_t id_1046 { 127 };
                                                uint8_t id_1047 { uint8_t(leb128_fst_171 & id_1046) };
                                                uint32_t id_1048 { uint32_t(id_1047) };
                                                uint8_t id_1049 { 0 };
                                                uint8_t id_1050 { shft_ref_168[id_1049] };
                                                uint32_t id_1051 { uint32_t(id_1048 << id_1050) };
                                                uint8_t id_1052 { 0 };
                                                uint32_t id_1053 { leb_ref_167[id_1052] };
                                                uint32_t id_1054 { uint32_t(id_1051 | id_1053) };
                                                Void id_1055 { ((void)(leb_ref_167[id_1045] = id_1054), ::dessser::Void()) };
                                                (void)id_1055;
                                                uint8_t id_1056 { 0 };
                                                uint8_t id_1057 { 0 };
                                                uint8_t id_1058 { shft_ref_168[id_1057] };
                                                uint8_t id_1059 { 7 };
                                                uint8_t id_1060 { uint8_t(id_1058 + id_1059) };
                                                Void id_1061 { ((void)(shft_ref_168[id_1056] = id_1060), ::dessser::Void()) };
                                                (void)id_1061;
                                                uint8_t id_1062 { 128 };
                                                bool id_1063 { bool(leb128_fst_171 >= id_1062) };
                                                letpair_res_1042 = id_1063;
                                              }
                                              let_res_1041 = letpair_res_1042;
                                            }
                                            while_flag_1037 = let_res_1041;
                                            if (while_flag_1037) {
                                              (void)::dessser::Void();
                                            }
                                          } while (while_flag_1037);
                                          (void)::dessser::Void();
                                          uint8_t id_1064 { 0 };
                                          uint32_t id_1065 { leb_ref_167[id_1064] };
                                          Size id_1066 { Size(id_1065) };
                                          uint8_t id_1067 { 0 };
                                          Pointer id_1068 { p_ref_169[id_1067] };
                                          ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa id_1069 { id_1066, id_1068 };
                                          let_res_1036 = id_1069;
                                        }
                                        let_res_1034 = let_res_1036;
                                      }
                                      let_res_1031 = let_res_1034;
                                    }
                                    ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc let_res_1070;
                                    {
                                      ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa dstring1_173 { let_res_1031 };
                                      ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc letpair_res_1071;
                                      {
                                        auto dstring1_fst_174 { std::get<0>(dstring1_173) };
                                        auto dstring1_snd_175 { std::get<1>(dstring1_173) };
                                        ::dessser::gen::dashboard_widget::t9ef6882174ae71a34a3c5ef6b29242fb id_1072 { dstring1_snd_175.readBytes(dstring1_fst_174) };
                                        ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc letpair_res_1073;
                                        {
                                          auto dstring2_fst_177 { std::get<0>(id_1072) };
                                          auto dstring2_snd_178 { std::get<1>(id_1072) };
                                          std::string id_1074 { dstring2_fst_177.toString() };
                                          Lst<std::string> id_1075 { id_1074, dlist2_fst_165 };
                                          ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc id_1076 { id_1075, dstring2_snd_178 };
                                          letpair_res_1073 = id_1076;
                                        }
                                        letpair_res_1071 = letpair_res_1073;
                                      }
                                      let_res_1070 = letpair_res_1071;
                                    }
                                    Void id_1077 { ((void)(inits_src_ref_162[id_1028] = let_res_1070), ::dessser::Void()) };
                                    (void)id_1077;
                                  }
                                  (void)::dessser::Void();
                                }
                                (void)::dessser::Void();
                                uint8_t id_1078 { 0 };
                                uint8_t id_1079 { 0 };
                                int32_t id_1080 { repeat_n_163[id_1079] };
                                int32_t id_1081 { 1L };
                                int32_t id_1082 { int32_t(id_1080 + id_1081) };
                                Void id_1083 { ((void)(repeat_n_163[id_1078] = id_1082), ::dessser::Void()) };
                                (void)id_1083;
                                (void)id_1083;
                              }
                            } while (while_flag_1021);
                            (void)::dessser::Void();
                          }
                          (void)::dessser::Void();
                          uint8_t id_1084 { 0 };
                          ::dessser::gen::dashboard_widget::t941fe844f492c6f2281f99ea362423fc id_1085 { inits_src_ref_162[id_1084] };
                          let_res_1018 = id_1085;
                        }
                        letpair_res_1014 = let_res_1018;
                      }
                      let_res_1013 = letpair_res_1014;
                    }
                    ::dessser::gen::dashboard_widget::t8293f5c3f24638d91c1ca307ed4a5278 letpair_res_1086;
                    {
                      auto dlist4_fst_183 { std::get<0>(let_res_1013) };
                      auto dlist4_snd_184 { std::get<1>(let_res_1013) };
                      Arr<std::string> id_1087 { dlist4_fst_183.toArrRev() };
                      ::dessser::gen::dashboard_widget::t8293f5c3f24638d91c1ca307ed4a5278 id_1088 { id_1087, dlist4_snd_184 };
                      letpair_res_1086 = id_1088;
                    }
                    ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 let_res_1089;
                    {
                      ::dessser::gen::dashboard_widget::t8293f5c3f24638d91c1ca307ed4a5278 drec_185 { letpair_res_1086 };
                      ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 letpair_res_1090;
                      {
                        auto drec_fst_186 { std::get<0>(drec_185) };
                        auto drec_snd_187 { std::get<1>(drec_185) };
                        ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1091 { drec_snd_187.readU8() };
                        ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 letpair_res_1092;
                        {
                          auto du8_fst_189 { std::get<0>(id_1091) };
                          auto du8_snd_190 { std::get<1>(id_1091) };
                          ::dessser::gen::dashboard_widget::field id_1093 { drec_fst_124, drec_fst_130, drec_fst_133, drec_fst_148, drec_fst_186, du8_fst_189 };
                          ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 id_1094 { id_1093, du8_snd_190 };
                          letpair_res_1092 = id_1094;
                        }
                        letpair_res_1090 = letpair_res_1092;
                      }
                      let_res_1089 = letpair_res_1090;
                    }
                    letpair_res_972 = let_res_1089;
                  }
                  let_res_971 = letpair_res_972;
                }
                letpair_res_923 = let_res_971;
              }
              let_res_922 = letpair_res_923;
            }
            letpair_res_920 = let_res_922;
          }
          let_res_919 = letpair_res_920;
        }
        letpair_res_915 = let_res_919;
      }
      let_res_914 = letpair_res_915;
    }
    return let_res_914;
  }
   };
  return fun909;
}
std::function<::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8(Pointer &)> field_of_row_binary(field_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_194" (apply (ext-identifier fq_function_name of-row-binary) (param 0))
        (let-pair "drec_fst_195" "drec_snd_196" (identifier "drec_194")
          (let "drec_200" (let-pair "dbool_fst_198" "dbool_snd_199" (read-u8 (identifier "drec_snd_196")) (make-tup (not (eq (identifier "dbool_fst_198") (u8 0))) (identifier "dbool_snd_199")))
            (let-pair "drec_fst_201" "drec_snd_202" (identifier "drec_200")
              (let-pair "dlist4_fst_224" "dlist4_snd_225"
                (let "dlist1_212"
                  (let "leb_ref_203" (make-vec (u32 0))
                    (let "shft_ref_204" (make-vec (u8 0))
                      (let "p_ref_205" (make-vec (identifier "drec_snd_202"))
                        (seq
                          (while
                            (let "leb128_206" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_205")))
                              (let-pair "leb128_fst_207" "leb128_snd_208" 
                                (identifier "leb128_206")
                                (seq (set-vec (u8 0) (identifier "p_ref_205") (identifier "leb128_snd_208"))
                                  (set-vec (u8 0) (identifier "leb_ref_203")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_207") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_204"))) (unsafe-nth (u8 0) (identifier "leb_ref_203"))))
                                  (set-vec (u8 0) (identifier "shft_ref_204") (add (unsafe-nth (u8 0) (identifier "shft_ref_204")) (u8 7))) 
                                  (ge (identifier "leb128_fst_207") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_203")) (unsafe-nth (u8 0) (identifier "p_ref_205")))))))
                  (let-pair "dlist1_fst_213" "dlist1_snd_214" (identifier "dlist1_212")
                    (let "inits_src_ref_215"
                      (make-vec
                        (make-tup
                          (end-of-list "(field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})")
                          (identifier "dlist1_snd_214")))
                      (seq
                        (let "repeat_n_216" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_213")) (unsafe-nth (u8 0) (identifier "repeat_n_216")))
                            (seq
                              (let "dlist2_217" (unsafe-nth (u8 0) (identifier "inits_src_ref_215"))
                                (let-pair "dlist2_fst_218" "dlist2_snd_219" 
                                  (identifier "dlist2_217")
                                  (set-vec (u8 0) (identifier "inits_src_ref_215")
                                    (let-pair "dlist3_fst_221" "dlist3_snd_222" 
                                      (apply (identifier "field-of-row-binary") (identifier "dlist2_snd_219")) 
                                      (make-tup (cons (identifier "dlist3_fst_221") (identifier "dlist2_fst_218")) (identifier "dlist3_snd_222"))))))
                              (set-vec (u8 0) (identifier "repeat_n_216") (add (unsafe-nth (u8 0) (identifier "repeat_n_216")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_215"))))))
                (make-tup (make-rec (string "fields") (arr-of-lst-rev (identifier "dlist4_fst_224")) (string "visible") (identifier "drec_fst_201") (string "name") (identifier "drec_fst_195")) (identifier "dlist4_snd_225"))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238(Pointer &)> source_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238(Pointer &)> fun1095 { [&](Pointer p_0) {
    auto fun1096 { dessser::gen::fq_function_name::of_row_binary };
    ::dessser::gen::dashboard_widget::tafdf48d85e3efdf5b24e3fa2741562be id_1097 { fun1096(p_0) };
    ::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238 let_res_1098;
    {
      ::dessser::gen::dashboard_widget::tafdf48d85e3efdf5b24e3fa2741562be drec_194 { id_1097 };
      ::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238 letpair_res_1099;
      {
        auto drec_fst_195 { std::get<0>(drec_194) };
        auto drec_snd_196 { std::get<1>(drec_194) };
        ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1100 { drec_snd_196.readU8() };
        ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1101;
        {
          auto dbool_fst_198 { std::get<0>(id_1100) };
          auto dbool_snd_199 { std::get<1>(id_1100) };
          uint8_t id_1102 { 0 };
          bool id_1103 { bool(dbool_fst_198 == id_1102) };
          bool id_1104 { ! id_1103 };
          ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 id_1105 { id_1104, dbool_snd_199 };
          letpair_res_1101 = id_1105;
        }
        ::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238 let_res_1106;
        {
          ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 drec_200 { letpair_res_1101 };
          ::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238 letpair_res_1107;
          {
            auto drec_fst_201 { std::get<0>(drec_200) };
            auto drec_snd_202 { std::get<1>(drec_200) };
            uint32_t id_1108 { 0U };
            Vec<1, uint32_t> id_1109 {  id_1108  };
            ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1110;
            {
              Vec<1, uint32_t> leb_ref_203 { id_1109 };
              uint8_t id_1111 { 0 };
              Vec<1, uint8_t> id_1112 {  id_1111  };
              ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1113;
              {
                Vec<1, uint8_t> shft_ref_204 { id_1112 };
                Vec<1, Pointer> id_1114 {  drec_snd_202  };
                ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1115;
                {
                  Vec<1, Pointer> p_ref_205 { id_1114 };
                  bool while_flag_1116 { true };
                  do {
                    uint8_t id_1117 { 0 };
                    Pointer id_1118 { p_ref_205[id_1117] };
                    ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1119 { id_1118.readU8() };
                    bool let_res_1120;
                    {
                      ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_206 { id_1119 };
                      bool letpair_res_1121;
                      {
                        auto leb128_fst_207 { std::get<0>(leb128_206) };
                        auto leb128_snd_208 { std::get<1>(leb128_206) };
                        uint8_t id_1122 { 0 };
                        Void id_1123 { ((void)(p_ref_205[id_1122] = leb128_snd_208), ::dessser::Void()) };
                        (void)id_1123;
                        uint8_t id_1124 { 0 };
                        uint8_t id_1125 { 127 };
                        uint8_t id_1126 { uint8_t(leb128_fst_207 & id_1125) };
                        uint32_t id_1127 { uint32_t(id_1126) };
                        uint8_t id_1128 { 0 };
                        uint8_t id_1129 { shft_ref_204[id_1128] };
                        uint32_t id_1130 { uint32_t(id_1127 << id_1129) };
                        uint8_t id_1131 { 0 };
                        uint32_t id_1132 { leb_ref_203[id_1131] };
                        uint32_t id_1133 { uint32_t(id_1130 | id_1132) };
                        Void id_1134 { ((void)(leb_ref_203[id_1124] = id_1133), ::dessser::Void()) };
                        (void)id_1134;
                        uint8_t id_1135 { 0 };
                        uint8_t id_1136 { 0 };
                        uint8_t id_1137 { shft_ref_204[id_1136] };
                        uint8_t id_1138 { 7 };
                        uint8_t id_1139 { uint8_t(id_1137 + id_1138) };
                        Void id_1140 { ((void)(shft_ref_204[id_1135] = id_1139), ::dessser::Void()) };
                        (void)id_1140;
                        uint8_t id_1141 { 128 };
                        bool id_1142 { bool(leb128_fst_207 >= id_1141) };
                        letpair_res_1121 = id_1142;
                      }
                      let_res_1120 = letpair_res_1121;
                    }
                    while_flag_1116 = let_res_1120;
                    if (while_flag_1116) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_1116);
                  (void)::dessser::Void();
                  uint8_t id_1143 { 0 };
                  uint32_t id_1144 { leb_ref_203[id_1143] };
                  uint8_t id_1145 { 0 };
                  Pointer id_1146 { p_ref_205[id_1145] };
                  ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 id_1147 { id_1144, id_1146 };
                  let_res_1115 = id_1147;
                }
                let_res_1113 = let_res_1115;
              }
              let_res_1110 = let_res_1113;
            }
            ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 let_res_1148;
            {
              ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 dlist1_212 { let_res_1110 };
              ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 letpair_res_1149;
              {
                auto dlist1_fst_213 { std::get<0>(dlist1_212) };
                auto dlist1_snd_214 { std::get<1>(dlist1_212) };
                Lst<::dessser::gen::dashboard_widget::field> endoflist_1150;
                ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 id_1151 { endoflist_1150, dlist1_snd_214 };
                Vec<1, ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6> id_1152 {  id_1151  };
                ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 let_res_1153;
                {
                  Vec<1, ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6> inits_src_ref_215 { id_1152 };
                  int32_t id_1154 { 0L };
                  Vec<1, int32_t> id_1155 {  id_1154  };
                  {
                    Vec<1, int32_t> repeat_n_216 { id_1155 };
                    bool while_flag_1156 { true };
                    do {
                      int32_t id_1157 { int32_t(dlist1_fst_213) };
                      uint8_t id_1158 { 0 };
                      int32_t id_1159 { repeat_n_216[id_1158] };
                      bool id_1160 { bool(id_1157 > id_1159) };
                      while_flag_1156 = id_1160;
                      if (while_flag_1156) {
                        uint8_t id_1161 { 0 };
                        ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 id_1162 { inits_src_ref_215[id_1161] };
                        {
                          ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 dlist2_217 { id_1162 };
                          {
                            auto dlist2_fst_218 { std::get<0>(dlist2_217) };
                            auto dlist2_snd_219 { std::get<1>(dlist2_217) };
                            uint8_t id_1163 { 0 };
                            ::dessser::gen::dashboard_widget::t749cc30fe799f5ca72ede312d96197a8 id_1164 { field_of_row_binary(dlist2_snd_219) };
                            ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 letpair_res_1165;
                            {
                              auto dlist3_fst_221 { std::get<0>(id_1164) };
                              auto dlist3_snd_222 { std::get<1>(id_1164) };
                              Lst<::dessser::gen::dashboard_widget::field> id_1166 { dlist3_fst_221, dlist2_fst_218 };
                              ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 id_1167 { id_1166, dlist3_snd_222 };
                              letpair_res_1165 = id_1167;
                            }
                            Void id_1168 { ((void)(inits_src_ref_215[id_1163] = letpair_res_1165), ::dessser::Void()) };
                            (void)id_1168;
                          }
                          (void)::dessser::Void();
                        }
                        (void)::dessser::Void();
                        uint8_t id_1169 { 0 };
                        uint8_t id_1170 { 0 };
                        int32_t id_1171 { repeat_n_216[id_1170] };
                        int32_t id_1172 { 1L };
                        int32_t id_1173 { int32_t(id_1171 + id_1172) };
                        Void id_1174 { ((void)(repeat_n_216[id_1169] = id_1173), ::dessser::Void()) };
                        (void)id_1174;
                        (void)id_1174;
                      }
                    } while (while_flag_1156);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_1175 { 0 };
                  ::dessser::gen::dashboard_widget::tcb7b01c316b4ea76130319ada34983b6 id_1176 { inits_src_ref_215[id_1175] };
                  let_res_1153 = id_1176;
                }
                letpair_res_1149 = let_res_1153;
              }
              let_res_1148 = letpair_res_1149;
            }
            ::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238 letpair_res_1177;
            {
              auto dlist4_fst_224 { std::get<0>(let_res_1148) };
              auto dlist4_snd_225 { std::get<1>(let_res_1148) };
              Arr<::dessser::gen::dashboard_widget::field> id_1178 { dlist4_fst_224.toArrRev() };
              ::dessser::gen::dashboard_widget::source id_1179 { drec_fst_195, drec_fst_201, id_1178 };
              ::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238 id_1180 { id_1179, dlist4_snd_225 };
              letpair_res_1177 = id_1180;
            }
            letpair_res_1107 = letpair_res_1177;
          }
          let_res_1106 = letpair_res_1107;
        }
        letpair_res_1099 = let_res_1106;
      }
      let_res_1098 = letpair_res_1099;
    }
    return let_res_1098;
  }
   };
  return fun1095;
}
std::function<::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238(Pointer &)> source_of_row_binary(source_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_75" (let-pair "du16_fst_70" "du16_snd_71" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_70") (identifier "du16_snd_71")))
        (let-pair "dsum1_fst_76" "dsum1_snd_77" (identifier "dsum1_75")
          (if (eq (u16 0) (identifier "dsum1_fst_76")) (make-tup (construct "[Linear Void | Logarithmic Void]" 0 (nop)) (identifier "dsum1_snd_77"))
            (seq (assert (eq (identifier "dsum1_fst_76") (u16 1))) (make-tup (construct "[Linear Void | Logarithmic Void]" 1 (nop)) (identifier "dsum1_snd_77")))))))
 */
static std::function<::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974(Pointer &)> scale_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974(Pointer &)> fun1181 { [&](Pointer p_0) {
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_1182 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1183;
    {
      auto du16_fst_70 { std::get<0>(id_1182) };
      auto du16_snd_71 { std::get<1>(id_1182) };
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_1184 { du16_fst_70, du16_snd_71 };
      letpair_res_1183 = id_1184;
    }
    ::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974 let_res_1185;
    {
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 dsum1_75 { letpair_res_1183 };
      ::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974 letpair_res_1186;
      {
        auto dsum1_fst_76 { std::get<0>(dsum1_75) };
        auto dsum1_snd_77 { std::get<1>(dsum1_75) };
        uint16_t id_1187 { 0 };
        bool id_1188 { bool(id_1187 == dsum1_fst_76) };
        ::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974 choose_res_1189;
        if (id_1188) {
          (void)::dessser::Void();
          ::dessser::gen::dashboard_widget::scale id_1190 { Linear };
          ::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974 id_1191 { id_1190, dsum1_snd_77 };
          choose_res_1189 = id_1191;
        } else {
          uint16_t id_1192 { 1 };
          bool id_1193 { bool(dsum1_fst_76 == id_1192) };
          Void id_1194 { ((void)(assert(id_1193)), ::dessser::Void()) };
          (void)id_1194;
          (void)::dessser::Void();
          ::dessser::gen::dashboard_widget::scale id_1195 { Logarithmic };
          ::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974 id_1196 { id_1195, dsum1_snd_77 };
          choose_res_1189 = id_1196;
        }
        letpair_res_1186 = choose_res_1189;
      }
      let_res_1185 = letpair_res_1186;
    }
    return let_res_1185;
  }
   };
  return fun1181;
}
std::function<::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974(Pointer &)> scale_of_row_binary(scale_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_87" (let-pair "dbool_fst_85" "dbool_snd_86" (read-u8 (param 0)) (make-tup (not (eq (identifier "dbool_fst_85") (u8 0))) (identifier "dbool_snd_86")))
        (let-pair "drec_fst_88" "drec_snd_89" (identifier "drec_87")
          (let "drec_93" (let-pair "dbool_fst_91" "dbool_snd_92" (read-u8 (identifier "drec_snd_89")) (make-tup (not (eq (identifier "dbool_fst_91") (u8 0))) (identifier "dbool_snd_92")))
            (let-pair "drec_fst_94" "drec_snd_95" (identifier "drec_93")
              (let-pair "drec_fst_97" "drec_snd_98" (apply (identifier "scale-of-row-binary") (identifier "drec_snd_95"))
                (make-tup (make-rec (string "scale") (identifier "drec_fst_97") (string "force_zero") (identifier "drec_fst_94") (string "left") (identifier "drec_fst_88")) (identifier "drec_snd_98"))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4(Pointer &)> axis_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4(Pointer &)> fun1197 { [&](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1198 { p_0.readU8() };
    ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1199;
    {
      auto dbool_fst_85 { std::get<0>(id_1198) };
      auto dbool_snd_86 { std::get<1>(id_1198) };
      uint8_t id_1200 { 0 };
      bool id_1201 { bool(dbool_fst_85 == id_1200) };
      bool id_1202 { ! id_1201 };
      ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 id_1203 { id_1202, dbool_snd_86 };
      letpair_res_1199 = id_1203;
    }
    ::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4 let_res_1204;
    {
      ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 drec_87 { letpair_res_1199 };
      ::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4 letpair_res_1205;
      {
        auto drec_fst_88 { std::get<0>(drec_87) };
        auto drec_snd_89 { std::get<1>(drec_87) };
        ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1206 { drec_snd_89.readU8() };
        ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1207;
        {
          auto dbool_fst_91 { std::get<0>(id_1206) };
          auto dbool_snd_92 { std::get<1>(id_1206) };
          uint8_t id_1208 { 0 };
          bool id_1209 { bool(dbool_fst_91 == id_1208) };
          bool id_1210 { ! id_1209 };
          ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 id_1211 { id_1210, dbool_snd_92 };
          letpair_res_1207 = id_1211;
        }
        ::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4 let_res_1212;
        {
          ::dessser::gen::dashboard_widget::tf9a0a3fefc87c9e10a93d3a172850c26 drec_93 { letpair_res_1207 };
          ::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4 letpair_res_1213;
          {
            auto drec_fst_94 { std::get<0>(drec_93) };
            auto drec_snd_95 { std::get<1>(drec_93) };
            ::dessser::gen::dashboard_widget::te827b27d5f16cf2c14d368442731b974 id_1214 { scale_of_row_binary(drec_snd_95) };
            ::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4 letpair_res_1215;
            {
              auto drec_fst_97 { std::get<0>(id_1214) };
              auto drec_snd_98 { std::get<1>(id_1214) };
              ::dessser::gen::dashboard_widget::axis id_1216 { drec_fst_88, drec_fst_94, drec_fst_97 };
              ::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4 id_1217 { id_1216, drec_snd_98 };
              letpair_res_1215 = id_1217;
            }
            letpair_res_1213 = letpair_res_1215;
          }
          let_res_1212 = letpair_res_1213;
        }
        letpair_res_1205 = let_res_1212;
      }
      let_res_1204 = letpair_res_1205;
    }
    return let_res_1204;
  }
   };
  return fun1197;
}
std::function<::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4(Pointer &)> axis_of_row_binary(axis_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63") (seq (assert (eq (identifier "dsum1_fst_64") (u16 0))) (make-tup (construct "[Plot Void]" 0 (nop)) (identifier "dsum1_snd_65"))))))
 */
static std::function<::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6(Pointer &)> type_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6(Pointer &)> fun1218 { [&](Pointer p_0) {
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_1219 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1220;
    {
      auto du16_fst_58 { std::get<0>(id_1219) };
      auto du16_snd_59 { std::get<1>(id_1219) };
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_1221 { du16_fst_58, du16_snd_59 };
      letpair_res_1220 = id_1221;
    }
    ::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6 let_res_1222;
    {
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_1220 };
      ::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6 letpair_res_1223;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_1224 { 0 };
        bool id_1225 { bool(dsum1_fst_64 == id_1224) };
        Void id_1226 { ((void)(assert(id_1225)), ::dessser::Void()) };
        (void)id_1226;
        (void)::dessser::Void();
        ::dessser::gen::dashboard_widget::type id_1227 { Plot };
        ::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6 id_1228 { id_1227, dsum1_snd_65 };
        letpair_res_1223 = id_1228;
      }
      let_res_1222 = letpair_res_1223;
    }
    return let_res_1222;
  }
   };
  return fun1218;
}
std::function<::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6(Pointer &)> type_of_row_binary(type_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_241"
        (let "dstring1_235"
          (let "leb_ref_229" (make-vec (u32 0))
            (let "shft_ref_230" (make-vec (u8 0))
              (let "p_ref_231" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_232" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_231")))
                      (let-pair "leb128_fst_233" "leb128_snd_234" (identifier "leb128_232")
                        (seq (set-vec (u8 0) (identifier "p_ref_231") (identifier "leb128_snd_234"))
                          (set-vec (u8 0) (identifier "leb_ref_229")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_233") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_230"))) (unsafe-nth (u8 0) (identifier "leb_ref_229"))))
                          (set-vec (u8 0) (identifier "shft_ref_230") (add (unsafe-nth (u8 0) (identifier "shft_ref_230")) (u8 7))) 
                          (ge (identifier "leb128_fst_233") (u8 128))))) 
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_229"))) (unsafe-nth (u8 0) (identifier "p_ref_231")))))))
          (let-pair "dstring1_fst_236" "dstring1_snd_237" (identifier "dstring1_235")
            (let-pair "dstring2_fst_239" "dstring2_snd_240" (read-bytes (identifier "dstring1_snd_237") (identifier "dstring1_fst_236"))
              (make-tup (string-of-bytes (identifier "dstring2_fst_239")) (identifier "dstring2_snd_240")))))
        (let-pair "drec_fst_242" "drec_snd_243" (identifier "drec_241")
          (let "drec_244" (apply (identifier "type-of-row-binary") (identifier "drec_snd_243"))
            (let-pair "drec_fst_245" "drec_snd_246" (identifier "drec_244")
              (let "drec_270"
                (let-pair "dlist4_fst_268" "dlist4_snd_269"
                  (let "dlist1_256"
                    (let "leb_ref_247" (make-vec (u32 0))
                      (let "shft_ref_248" (make-vec (u8 0))
                        (let "p_ref_249" (make-vec (identifier "drec_snd_246"))
                          (seq
                            (while
                              (let "leb128_250" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_249")))
                                (let-pair "leb128_fst_251" "leb128_snd_252" 
                                  (identifier "leb128_250")
                                  (seq (set-vec (u8 0) (identifier "p_ref_249") (identifier "leb128_snd_252"))
                                    (set-vec (u8 0) (identifier "leb_ref_247")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_251") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_248"))) (unsafe-nth (u8 0) (identifier "leb_ref_247"))))
                                    (set-vec (u8 0) (identifier "shft_ref_248") (add (unsafe-nth (u8 0) (identifier "shft_ref_248")) (u8 7))) 
                                    (ge (identifier "leb128_fst_251") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_247")) (unsafe-nth (u8 0) (identifier "p_ref_249")))))))
                    (let-pair "dlist1_fst_257" "dlist1_snd_258" (identifier "dlist1_256")
                      (let "inits_src_ref_259" (make-vec (make-tup (end-of-list "(axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})") (identifier "dlist1_snd_258")))
                        (seq
                          (let "repeat_n_260" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_257")) (unsafe-nth (u8 0) (identifier "repeat_n_260")))
                              (seq
                                (let "dlist2_261" (unsafe-nth (u8 0) (identifier "inits_src_ref_259"))
                                  (let-pair "dlist2_fst_262" "dlist2_snd_263" 
                                    (identifier "dlist2_261")
                                    (set-vec (u8 0) (identifier "inits_src_ref_259")
                                      (let-pair "dlist3_fst_265" "dlist3_snd_266" 
                                        (apply (identifier "axis-of-row-binary") (identifier "dlist2_snd_263")) 
                                        (make-tup (cons (identifier "dlist3_fst_265") (identifier "dlist2_fst_262")) (identifier "dlist3_snd_266"))))))
                                (set-vec (u8 0) (identifier "repeat_n_260") (add (unsafe-nth (u8 0) (identifier "repeat_n_260")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_259")))))) 
                  (make-tup (arr-of-lst-rev (identifier "dlist4_fst_268")) (identifier "dlist4_snd_269")))
                (let-pair "drec_fst_271" "drec_snd_272" (identifier "drec_270")
                  (let-pair "dlist4_fst_294" "dlist4_snd_295"
                    (let "dlist1_282"
                      (let "leb_ref_273" (make-vec (u32 0))
                        (let "shft_ref_274" (make-vec (u8 0))
                          (let "p_ref_275" (make-vec (identifier "drec_snd_272"))
                            (seq
                              (while
                                (let "leb128_276" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_275")))
                                  (let-pair "leb128_fst_277" "leb128_snd_278" 
                                    (identifier "leb128_276")
                                    (seq (set-vec (u8 0) (identifier "p_ref_275") (identifier "leb128_snd_278"))
                                      (set-vec (u8 0) (identifier "leb_ref_273")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_277") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_274"))) (unsafe-nth (u8 0) (identifier "leb_ref_273"))))
                                      (set-vec (u8 0) (identifier "shft_ref_274") (add (unsafe-nth (u8 0) (identifier "shft_ref_274")) (u8 7))) 
                                      (ge (identifier "leb128_fst_277") (u8 128))))) 
                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_273")) (unsafe-nth (u8 0) (identifier "p_ref_275")))))))
                      (let-pair "dlist1_fst_283" "dlist1_snd_284" (identifier "dlist1_282")
                        (let "inits_src_ref_285"
                          (make-vec
                            (make-tup
                              (end-of-list "(source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})")
                              (identifier "dlist1_snd_284")))
                          (seq
                            (let "repeat_n_286" (make-vec (i32 0))
                              (while (gt (to-i32 (identifier "dlist1_fst_283")) (unsafe-nth (u8 0) (identifier "repeat_n_286")))
                                (seq
                                  (let "dlist2_287" (unsafe-nth (u8 0) (identifier "inits_src_ref_285"))
                                    (let-pair "dlist2_fst_288" "dlist2_snd_289" 
                                      (identifier "dlist2_287")
                                      (set-vec (u8 0) (identifier "inits_src_ref_285")
                                        (let-pair "dlist3_fst_291" "dlist3_snd_292" 
                                          (apply (identifier "source-of-row-binary") (identifier "dlist2_snd_289")) 
                                          (make-tup (cons (identifier "dlist3_fst_291") (identifier "dlist2_fst_288")) (identifier "dlist3_snd_292"))))))
                                  (set-vec (u8 0) (identifier "repeat_n_286") (add (unsafe-nth (u8 0) (identifier "repeat_n_286")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "inits_src_ref_285"))))))
                    (make-tup
                      (make-rec (string "sources") (arr-of-lst-rev (identifier "dlist4_fst_294")) 
                        (string "axes") (identifier "drec_fst_271") (string "type") 
                        (identifier "drec_fst_245") (string "title") 
                        (identifier "drec_fst_242")) (identifier "dlist4_snd_295"))))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f(Pointer &)> chart_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f(Pointer &)> fun1229 { [&](Pointer p_0) {
    uint32_t id_1230 { 0U };
    Vec<1, uint32_t> id_1231 {  id_1230  };
    ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1232;
    {
      Vec<1, uint32_t> leb_ref_229 { id_1231 };
      uint8_t id_1233 { 0 };
      Vec<1, uint8_t> id_1234 {  id_1233  };
      ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1235;
      {
        Vec<1, uint8_t> shft_ref_230 { id_1234 };
        Vec<1, Pointer> id_1236 {  p_0  };
        ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1237;
        {
          Vec<1, Pointer> p_ref_231 { id_1236 };
          bool while_flag_1238 { true };
          do {
            uint8_t id_1239 { 0 };
            Pointer id_1240 { p_ref_231[id_1239] };
            ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1241 { id_1240.readU8() };
            bool let_res_1242;
            {
              ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_232 { id_1241 };
              bool letpair_res_1243;
              {
                auto leb128_fst_233 { std::get<0>(leb128_232) };
                auto leb128_snd_234 { std::get<1>(leb128_232) };
                uint8_t id_1244 { 0 };
                Void id_1245 { ((void)(p_ref_231[id_1244] = leb128_snd_234), ::dessser::Void()) };
                (void)id_1245;
                uint8_t id_1246 { 0 };
                uint8_t id_1247 { 127 };
                uint8_t id_1248 { uint8_t(leb128_fst_233 & id_1247) };
                uint32_t id_1249 { uint32_t(id_1248) };
                uint8_t id_1250 { 0 };
                uint8_t id_1251 { shft_ref_230[id_1250] };
                uint32_t id_1252 { uint32_t(id_1249 << id_1251) };
                uint8_t id_1253 { 0 };
                uint32_t id_1254 { leb_ref_229[id_1253] };
                uint32_t id_1255 { uint32_t(id_1252 | id_1254) };
                Void id_1256 { ((void)(leb_ref_229[id_1246] = id_1255), ::dessser::Void()) };
                (void)id_1256;
                uint8_t id_1257 { 0 };
                uint8_t id_1258 { 0 };
                uint8_t id_1259 { shft_ref_230[id_1258] };
                uint8_t id_1260 { 7 };
                uint8_t id_1261 { uint8_t(id_1259 + id_1260) };
                Void id_1262 { ((void)(shft_ref_230[id_1257] = id_1261), ::dessser::Void()) };
                (void)id_1262;
                uint8_t id_1263 { 128 };
                bool id_1264 { bool(leb128_fst_233 >= id_1263) };
                letpair_res_1243 = id_1264;
              }
              let_res_1242 = letpair_res_1243;
            }
            while_flag_1238 = let_res_1242;
            if (while_flag_1238) {
              (void)::dessser::Void();
            }
          } while (while_flag_1238);
          (void)::dessser::Void();
          uint8_t id_1265 { 0 };
          uint32_t id_1266 { leb_ref_229[id_1265] };
          Size id_1267 { Size(id_1266) };
          uint8_t id_1268 { 0 };
          Pointer id_1269 { p_ref_231[id_1268] };
          ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa id_1270 { id_1267, id_1269 };
          let_res_1237 = id_1270;
        }
        let_res_1235 = let_res_1237;
      }
      let_res_1232 = let_res_1235;
    }
    ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 let_res_1271;
    {
      ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa dstring1_235 { let_res_1232 };
      ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 letpair_res_1272;
      {
        auto dstring1_fst_236 { std::get<0>(dstring1_235) };
        auto dstring1_snd_237 { std::get<1>(dstring1_235) };
        ::dessser::gen::dashboard_widget::t9ef6882174ae71a34a3c5ef6b29242fb id_1273 { dstring1_snd_237.readBytes(dstring1_fst_236) };
        ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 letpair_res_1274;
        {
          auto dstring2_fst_239 { std::get<0>(id_1273) };
          auto dstring2_snd_240 { std::get<1>(id_1273) };
          std::string id_1275 { dstring2_fst_239.toString() };
          ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 id_1276 { id_1275, dstring2_snd_240 };
          letpair_res_1274 = id_1276;
        }
        letpair_res_1272 = letpair_res_1274;
      }
      let_res_1271 = letpair_res_1272;
    }
    ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f let_res_1277;
    {
      ::dessser::gen::dashboard_widget::t13a07ee37ab40962540da8534858dc07 drec_241 { let_res_1271 };
      ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f letpair_res_1278;
      {
        auto drec_fst_242 { std::get<0>(drec_241) };
        auto drec_snd_243 { std::get<1>(drec_241) };
        ::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6 id_1279 { type_of_row_binary(drec_snd_243) };
        ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f let_res_1280;
        {
          ::dessser::gen::dashboard_widget::td081d579116db2384d0a1d4e0dd44fc6 drec_244 { id_1279 };
          ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f letpair_res_1281;
          {
            auto drec_fst_245 { std::get<0>(drec_244) };
            auto drec_snd_246 { std::get<1>(drec_244) };
            uint32_t id_1282 { 0U };
            Vec<1, uint32_t> id_1283 {  id_1282  };
            ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1284;
            {
              Vec<1, uint32_t> leb_ref_247 { id_1283 };
              uint8_t id_1285 { 0 };
              Vec<1, uint8_t> id_1286 {  id_1285  };
              ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1287;
              {
                Vec<1, uint8_t> shft_ref_248 { id_1286 };
                Vec<1, Pointer> id_1288 {  drec_snd_246  };
                ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1289;
                {
                  Vec<1, Pointer> p_ref_249 { id_1288 };
                  bool while_flag_1290 { true };
                  do {
                    uint8_t id_1291 { 0 };
                    Pointer id_1292 { p_ref_249[id_1291] };
                    ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1293 { id_1292.readU8() };
                    bool let_res_1294;
                    {
                      ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_250 { id_1293 };
                      bool letpair_res_1295;
                      {
                        auto leb128_fst_251 { std::get<0>(leb128_250) };
                        auto leb128_snd_252 { std::get<1>(leb128_250) };
                        uint8_t id_1296 { 0 };
                        Void id_1297 { ((void)(p_ref_249[id_1296] = leb128_snd_252), ::dessser::Void()) };
                        (void)id_1297;
                        uint8_t id_1298 { 0 };
                        uint8_t id_1299 { 127 };
                        uint8_t id_1300 { uint8_t(leb128_fst_251 & id_1299) };
                        uint32_t id_1301 { uint32_t(id_1300) };
                        uint8_t id_1302 { 0 };
                        uint8_t id_1303 { shft_ref_248[id_1302] };
                        uint32_t id_1304 { uint32_t(id_1301 << id_1303) };
                        uint8_t id_1305 { 0 };
                        uint32_t id_1306 { leb_ref_247[id_1305] };
                        uint32_t id_1307 { uint32_t(id_1304 | id_1306) };
                        Void id_1308 { ((void)(leb_ref_247[id_1298] = id_1307), ::dessser::Void()) };
                        (void)id_1308;
                        uint8_t id_1309 { 0 };
                        uint8_t id_1310 { 0 };
                        uint8_t id_1311 { shft_ref_248[id_1310] };
                        uint8_t id_1312 { 7 };
                        uint8_t id_1313 { uint8_t(id_1311 + id_1312) };
                        Void id_1314 { ((void)(shft_ref_248[id_1309] = id_1313), ::dessser::Void()) };
                        (void)id_1314;
                        uint8_t id_1315 { 128 };
                        bool id_1316 { bool(leb128_fst_251 >= id_1315) };
                        letpair_res_1295 = id_1316;
                      }
                      let_res_1294 = letpair_res_1295;
                    }
                    while_flag_1290 = let_res_1294;
                    if (while_flag_1290) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_1290);
                  (void)::dessser::Void();
                  uint8_t id_1317 { 0 };
                  uint32_t id_1318 { leb_ref_247[id_1317] };
                  uint8_t id_1319 { 0 };
                  Pointer id_1320 { p_ref_249[id_1319] };
                  ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 id_1321 { id_1318, id_1320 };
                  let_res_1289 = id_1321;
                }
                let_res_1287 = let_res_1289;
              }
              let_res_1284 = let_res_1287;
            }
            ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 let_res_1322;
            {
              ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 dlist1_256 { let_res_1284 };
              ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 letpair_res_1323;
              {
                auto dlist1_fst_257 { std::get<0>(dlist1_256) };
                auto dlist1_snd_258 { std::get<1>(dlist1_256) };
                Lst<::dessser::gen::dashboard_widget::axis> endoflist_1324;
                ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 id_1325 { endoflist_1324, dlist1_snd_258 };
                Vec<1, ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8> id_1326 {  id_1325  };
                ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 let_res_1327;
                {
                  Vec<1, ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8> inits_src_ref_259 { id_1326 };
                  int32_t id_1328 { 0L };
                  Vec<1, int32_t> id_1329 {  id_1328  };
                  {
                    Vec<1, int32_t> repeat_n_260 { id_1329 };
                    bool while_flag_1330 { true };
                    do {
                      int32_t id_1331 { int32_t(dlist1_fst_257) };
                      uint8_t id_1332 { 0 };
                      int32_t id_1333 { repeat_n_260[id_1332] };
                      bool id_1334 { bool(id_1331 > id_1333) };
                      while_flag_1330 = id_1334;
                      if (while_flag_1330) {
                        uint8_t id_1335 { 0 };
                        ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 id_1336 { inits_src_ref_259[id_1335] };
                        {
                          ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 dlist2_261 { id_1336 };
                          {
                            auto dlist2_fst_262 { std::get<0>(dlist2_261) };
                            auto dlist2_snd_263 { std::get<1>(dlist2_261) };
                            uint8_t id_1337 { 0 };
                            ::dessser::gen::dashboard_widget::t9a8d4d78c988f5d0b49fc7d7daee92e4 id_1338 { axis_of_row_binary(dlist2_snd_263) };
                            ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 letpair_res_1339;
                            {
                              auto dlist3_fst_265 { std::get<0>(id_1338) };
                              auto dlist3_snd_266 { std::get<1>(id_1338) };
                              Lst<::dessser::gen::dashboard_widget::axis> id_1340 { dlist3_fst_265, dlist2_fst_262 };
                              ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 id_1341 { id_1340, dlist3_snd_266 };
                              letpair_res_1339 = id_1341;
                            }
                            Void id_1342 { ((void)(inits_src_ref_259[id_1337] = letpair_res_1339), ::dessser::Void()) };
                            (void)id_1342;
                          }
                          (void)::dessser::Void();
                        }
                        (void)::dessser::Void();
                        uint8_t id_1343 { 0 };
                        uint8_t id_1344 { 0 };
                        int32_t id_1345 { repeat_n_260[id_1344] };
                        int32_t id_1346 { 1L };
                        int32_t id_1347 { int32_t(id_1345 + id_1346) };
                        Void id_1348 { ((void)(repeat_n_260[id_1343] = id_1347), ::dessser::Void()) };
                        (void)id_1348;
                        (void)id_1348;
                      }
                    } while (while_flag_1330);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_1349 { 0 };
                  ::dessser::gen::dashboard_widget::t4c3e9d1a56152b42310744919f17b6d8 id_1350 { inits_src_ref_259[id_1349] };
                  let_res_1327 = id_1350;
                }
                letpair_res_1323 = let_res_1327;
              }
              let_res_1322 = letpair_res_1323;
            }
            ::dessser::gen::dashboard_widget::t747bb378febaae5fd0b66480643426e2 letpair_res_1351;
            {
              auto dlist4_fst_268 { std::get<0>(let_res_1322) };
              auto dlist4_snd_269 { std::get<1>(let_res_1322) };
              Arr<::dessser::gen::dashboard_widget::axis> id_1352 { dlist4_fst_268.toArrRev() };
              ::dessser::gen::dashboard_widget::t747bb378febaae5fd0b66480643426e2 id_1353 { id_1352, dlist4_snd_269 };
              letpair_res_1351 = id_1353;
            }
            ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f let_res_1354;
            {
              ::dessser::gen::dashboard_widget::t747bb378febaae5fd0b66480643426e2 drec_270 { letpair_res_1351 };
              ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f letpair_res_1355;
              {
                auto drec_fst_271 { std::get<0>(drec_270) };
                auto drec_snd_272 { std::get<1>(drec_270) };
                uint32_t id_1356 { 0U };
                Vec<1, uint32_t> id_1357 {  id_1356  };
                ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1358;
                {
                  Vec<1, uint32_t> leb_ref_273 { id_1357 };
                  uint8_t id_1359 { 0 };
                  Vec<1, uint8_t> id_1360 {  id_1359  };
                  ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1361;
                  {
                    Vec<1, uint8_t> shft_ref_274 { id_1360 };
                    Vec<1, Pointer> id_1362 {  drec_snd_272  };
                    ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 let_res_1363;
                    {
                      Vec<1, Pointer> p_ref_275 { id_1362 };
                      bool while_flag_1364 { true };
                      do {
                        uint8_t id_1365 { 0 };
                        Pointer id_1366 { p_ref_275[id_1365] };
                        ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1367 { id_1366.readU8() };
                        bool let_res_1368;
                        {
                          ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_276 { id_1367 };
                          bool letpair_res_1369;
                          {
                            auto leb128_fst_277 { std::get<0>(leb128_276) };
                            auto leb128_snd_278 { std::get<1>(leb128_276) };
                            uint8_t id_1370 { 0 };
                            Void id_1371 { ((void)(p_ref_275[id_1370] = leb128_snd_278), ::dessser::Void()) };
                            (void)id_1371;
                            uint8_t id_1372 { 0 };
                            uint8_t id_1373 { 127 };
                            uint8_t id_1374 { uint8_t(leb128_fst_277 & id_1373) };
                            uint32_t id_1375 { uint32_t(id_1374) };
                            uint8_t id_1376 { 0 };
                            uint8_t id_1377 { shft_ref_274[id_1376] };
                            uint32_t id_1378 { uint32_t(id_1375 << id_1377) };
                            uint8_t id_1379 { 0 };
                            uint32_t id_1380 { leb_ref_273[id_1379] };
                            uint32_t id_1381 { uint32_t(id_1378 | id_1380) };
                            Void id_1382 { ((void)(leb_ref_273[id_1372] = id_1381), ::dessser::Void()) };
                            (void)id_1382;
                            uint8_t id_1383 { 0 };
                            uint8_t id_1384 { 0 };
                            uint8_t id_1385 { shft_ref_274[id_1384] };
                            uint8_t id_1386 { 7 };
                            uint8_t id_1387 { uint8_t(id_1385 + id_1386) };
                            Void id_1388 { ((void)(shft_ref_274[id_1383] = id_1387), ::dessser::Void()) };
                            (void)id_1388;
                            uint8_t id_1389 { 128 };
                            bool id_1390 { bool(leb128_fst_277 >= id_1389) };
                            letpair_res_1369 = id_1390;
                          }
                          let_res_1368 = letpair_res_1369;
                        }
                        while_flag_1364 = let_res_1368;
                        if (while_flag_1364) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_1364);
                      (void)::dessser::Void();
                      uint8_t id_1391 { 0 };
                      uint32_t id_1392 { leb_ref_273[id_1391] };
                      uint8_t id_1393 { 0 };
                      Pointer id_1394 { p_ref_275[id_1393] };
                      ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 id_1395 { id_1392, id_1394 };
                      let_res_1363 = id_1395;
                    }
                    let_res_1361 = let_res_1363;
                  }
                  let_res_1358 = let_res_1361;
                }
                ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 let_res_1396;
                {
                  ::dessser::gen::dashboard_widget::t491c44439106a32f896827242e8e76a1 dlist1_282 { let_res_1358 };
                  ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 letpair_res_1397;
                  {
                    auto dlist1_fst_283 { std::get<0>(dlist1_282) };
                    auto dlist1_snd_284 { std::get<1>(dlist1_282) };
                    Lst<::dessser::gen::dashboard_widget::source> endoflist_1398;
                    ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 id_1399 { endoflist_1398, dlist1_snd_284 };
                    Vec<1, ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0> id_1400 {  id_1399  };
                    ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 let_res_1401;
                    {
                      Vec<1, ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0> inits_src_ref_285 { id_1400 };
                      int32_t id_1402 { 0L };
                      Vec<1, int32_t> id_1403 {  id_1402  };
                      {
                        Vec<1, int32_t> repeat_n_286 { id_1403 };
                        bool while_flag_1404 { true };
                        do {
                          int32_t id_1405 { int32_t(dlist1_fst_283) };
                          uint8_t id_1406 { 0 };
                          int32_t id_1407 { repeat_n_286[id_1406] };
                          bool id_1408 { bool(id_1405 > id_1407) };
                          while_flag_1404 = id_1408;
                          if (while_flag_1404) {
                            uint8_t id_1409 { 0 };
                            ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 id_1410 { inits_src_ref_285[id_1409] };
                            {
                              ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 dlist2_287 { id_1410 };
                              {
                                auto dlist2_fst_288 { std::get<0>(dlist2_287) };
                                auto dlist2_snd_289 { std::get<1>(dlist2_287) };
                                uint8_t id_1411 { 0 };
                                ::dessser::gen::dashboard_widget::t98c1df55b587e112639e677d8810f238 id_1412 { source_of_row_binary(dlist2_snd_289) };
                                ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 letpair_res_1413;
                                {
                                  auto dlist3_fst_291 { std::get<0>(id_1412) };
                                  auto dlist3_snd_292 { std::get<1>(id_1412) };
                                  Lst<::dessser::gen::dashboard_widget::source> id_1414 { dlist3_fst_291, dlist2_fst_288 };
                                  ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 id_1415 { id_1414, dlist3_snd_292 };
                                  letpair_res_1413 = id_1415;
                                }
                                Void id_1416 { ((void)(inits_src_ref_285[id_1411] = letpair_res_1413), ::dessser::Void()) };
                                (void)id_1416;
                              }
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_1417 { 0 };
                            uint8_t id_1418 { 0 };
                            int32_t id_1419 { repeat_n_286[id_1418] };
                            int32_t id_1420 { 1L };
                            int32_t id_1421 { int32_t(id_1419 + id_1420) };
                            Void id_1422 { ((void)(repeat_n_286[id_1417] = id_1421), ::dessser::Void()) };
                            (void)id_1422;
                            (void)id_1422;
                          }
                        } while (while_flag_1404);
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_1423 { 0 };
                      ::dessser::gen::dashboard_widget::tddb6f2327241eb998908208af4a5b9a0 id_1424 { inits_src_ref_285[id_1423] };
                      let_res_1401 = id_1424;
                    }
                    letpair_res_1397 = let_res_1401;
                  }
                  let_res_1396 = letpair_res_1397;
                }
                ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f letpair_res_1425;
                {
                  auto dlist4_fst_294 { std::get<0>(let_res_1396) };
                  auto dlist4_snd_295 { std::get<1>(let_res_1396) };
                  Arr<::dessser::gen::dashboard_widget::source> id_1426 { dlist4_fst_294.toArrRev() };
                  ::dessser::gen::dashboard_widget::chart id_1427 { drec_fst_242, drec_fst_245, drec_fst_271, id_1426 };
                  ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f id_1428 { id_1427, dlist4_snd_295 };
                  letpair_res_1425 = id_1428;
                }
                letpair_res_1355 = letpair_res_1425;
              }
              let_res_1354 = letpair_res_1355;
            }
            letpair_res_1281 = let_res_1354;
          }
          let_res_1280 = letpair_res_1281;
        }
        letpair_res_1278 = let_res_1280;
      }
      let_res_1277 = letpair_res_1278;
    }
    return let_res_1277;
  }
   };
  return fun1229;
}
std::function<::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f(Pointer &)> chart_of_row_binary(chart_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_305" (let-pair "du16_fst_300" "du16_snd_301" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_300") (identifier "du16_snd_301")))
        (let-pair "dsum1_fst_306" "dsum1_snd_307" (identifier "dsum1_305")
          (if (eq (u16 0) (identifier "dsum1_fst_306"))
            (let "dstring1_317"
              (let "leb_ref_311" (make-vec (u32 0))
                (let "shft_ref_312" (make-vec (u8 0))
                  (let "p_ref_313" (make-vec (identifier "dsum1_snd_307"))
                    (seq
                      (while
                        (let "leb128_314" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_313")))
                          (let-pair "leb128_fst_315" "leb128_snd_316" 
                            (identifier "leb128_314")
                            (seq (set-vec (u8 0) (identifier "p_ref_313") (identifier "leb128_snd_316"))
                              (set-vec (u8 0) (identifier "leb_ref_311")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_315") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_312"))) (unsafe-nth (u8 0) (identifier "leb_ref_311"))))
                              (set-vec (u8 0) (identifier "shft_ref_312") (add (unsafe-nth (u8 0) (identifier "shft_ref_312")) (u8 7))) 
                              (ge (identifier "leb128_fst_315") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_311"))) (unsafe-nth (u8 0) (identifier "p_ref_313")))))))
              (let-pair "dstring1_fst_318" "dstring1_snd_319" (identifier "dstring1_317")
                (let-pair "dstring2_fst_321" "dstring2_snd_322" (read-bytes (identifier "dstring1_snd_319") (identifier "dstring1_fst_318"))
                  (make-tup
                    (construct "[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]" 0
                      (string-of-bytes (identifier "dstring2_fst_321"))) 
                    (identifier "dstring2_snd_322")))))
            (seq (assert (eq (identifier "dsum1_fst_306") (u16 1)))
              (let-pair "dsum2_fst_309" "dsum2_snd_310" (apply (identifier "chart-of-row-binary") (identifier "dsum1_snd_307"))
                (make-tup
                  (construct "[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]" 1
                    (identifier "dsum2_fst_309")) (identifier "dsum2_snd_310"))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> fun1429 { [&](Pointer p_0) {
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_1430 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1431;
    {
      auto du16_fst_300 { std::get<0>(id_1430) };
      auto du16_snd_301 { std::get<1>(id_1430) };
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 id_1432 { du16_fst_300, du16_snd_301 };
      letpair_res_1431 = id_1432;
    }
    ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 let_res_1433;
    {
      ::dessser::gen::dashboard_widget::ta97bb48ed75bbda6173555873826c8c6 dsum1_305 { letpair_res_1431 };
      ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 letpair_res_1434;
      {
        auto dsum1_fst_306 { std::get<0>(dsum1_305) };
        auto dsum1_snd_307 { std::get<1>(dsum1_305) };
        uint16_t id_1435 { 0 };
        bool id_1436 { bool(id_1435 == dsum1_fst_306) };
        ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 choose_res_1437;
        if (id_1436) {
          uint32_t id_1438 { 0U };
          Vec<1, uint32_t> id_1439 {  id_1438  };
          ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1440;
          {
            Vec<1, uint32_t> leb_ref_311 { id_1439 };
            uint8_t id_1441 { 0 };
            Vec<1, uint8_t> id_1442 {  id_1441  };
            ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1443;
            {
              Vec<1, uint8_t> shft_ref_312 { id_1442 };
              Vec<1, Pointer> id_1444 {  dsum1_snd_307  };
              ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa let_res_1445;
              {
                Vec<1, Pointer> p_ref_313 { id_1444 };
                bool while_flag_1446 { true };
                do {
                  uint8_t id_1447 { 0 };
                  Pointer id_1448 { p_ref_313[id_1447] };
                  ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 id_1449 { id_1448.readU8() };
                  bool let_res_1450;
                  {
                    ::dessser::gen::dashboard_widget::t1a5d74abf838df33f185a72a8912f5c9 leb128_314 { id_1449 };
                    bool letpair_res_1451;
                    {
                      auto leb128_fst_315 { std::get<0>(leb128_314) };
                      auto leb128_snd_316 { std::get<1>(leb128_314) };
                      uint8_t id_1452 { 0 };
                      Void id_1453 { ((void)(p_ref_313[id_1452] = leb128_snd_316), ::dessser::Void()) };
                      (void)id_1453;
                      uint8_t id_1454 { 0 };
                      uint8_t id_1455 { 127 };
                      uint8_t id_1456 { uint8_t(leb128_fst_315 & id_1455) };
                      uint32_t id_1457 { uint32_t(id_1456) };
                      uint8_t id_1458 { 0 };
                      uint8_t id_1459 { shft_ref_312[id_1458] };
                      uint32_t id_1460 { uint32_t(id_1457 << id_1459) };
                      uint8_t id_1461 { 0 };
                      uint32_t id_1462 { leb_ref_311[id_1461] };
                      uint32_t id_1463 { uint32_t(id_1460 | id_1462) };
                      Void id_1464 { ((void)(leb_ref_311[id_1454] = id_1463), ::dessser::Void()) };
                      (void)id_1464;
                      uint8_t id_1465 { 0 };
                      uint8_t id_1466 { 0 };
                      uint8_t id_1467 { shft_ref_312[id_1466] };
                      uint8_t id_1468 { 7 };
                      uint8_t id_1469 { uint8_t(id_1467 + id_1468) };
                      Void id_1470 { ((void)(shft_ref_312[id_1465] = id_1469), ::dessser::Void()) };
                      (void)id_1470;
                      uint8_t id_1471 { 128 };
                      bool id_1472 { bool(leb128_fst_315 >= id_1471) };
                      letpair_res_1451 = id_1472;
                    }
                    let_res_1450 = letpair_res_1451;
                  }
                  while_flag_1446 = let_res_1450;
                  if (while_flag_1446) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_1446);
                (void)::dessser::Void();
                uint8_t id_1473 { 0 };
                uint32_t id_1474 { leb_ref_311[id_1473] };
                Size id_1475 { Size(id_1474) };
                uint8_t id_1476 { 0 };
                Pointer id_1477 { p_ref_313[id_1476] };
                ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa id_1478 { id_1475, id_1477 };
                let_res_1445 = id_1478;
              }
              let_res_1443 = let_res_1445;
            }
            let_res_1440 = let_res_1443;
          }
          ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 let_res_1479;
          {
            ::dessser::gen::dashboard_widget::t12fb9c475959b52bf7b17b155a955ffa dstring1_317 { let_res_1440 };
            ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 letpair_res_1480;
            {
              auto dstring1_fst_318 { std::get<0>(dstring1_317) };
              auto dstring1_snd_319 { std::get<1>(dstring1_317) };
              ::dessser::gen::dashboard_widget::t9ef6882174ae71a34a3c5ef6b29242fb id_1481 { dstring1_snd_319.readBytes(dstring1_fst_318) };
              ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 letpair_res_1482;
              {
                auto dstring2_fst_321 { std::get<0>(id_1481) };
                auto dstring2_snd_322 { std::get<1>(id_1481) };
                std::string id_1483 { dstring2_fst_321.toString() };
                ::dessser::gen::dashboard_widget::t id_1484 { std::in_place_index<0>, id_1483 };
                ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 id_1485 { id_1484, dstring2_snd_322 };
                letpair_res_1482 = id_1485;
              }
              letpair_res_1480 = letpair_res_1482;
            }
            let_res_1479 = letpair_res_1480;
          }
          choose_res_1437 = let_res_1479;
        } else {
          uint16_t id_1486 { 1 };
          bool id_1487 { bool(dsum1_fst_306 == id_1486) };
          Void id_1488 { ((void)(assert(id_1487)), ::dessser::Void()) };
          (void)id_1488;
          ::dessser::gen::dashboard_widget::t62f7c15233495a7fd1923d1cb45a742f id_1489 { chart_of_row_binary(dsum1_snd_307) };
          ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 letpair_res_1490;
          {
            auto dsum2_fst_309 { std::get<0>(id_1489) };
            auto dsum2_snd_310 { std::get<1>(id_1489) };
            ::dessser::gen::dashboard_widget::t id_1491 { std::in_place_index<1>, dsum2_fst_309 };
            ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 id_1492 { id_1491, dsum2_snd_310 };
            letpair_res_1490 = id_1492;
          }
          choose_res_1437 = letpair_res_1490;
        }
        letpair_res_1434 = choose_res_1437;
      }
      let_res_1433 = letpair_res_1434;
    }
    return let_res_1433;
  }
   };
  return fun1429;
}
std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_327" "make_snd_328" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_327") (identifier "make_snd_328"))))
 */
static std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> fun1493 { [&](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 id_1494 { of_row_binary(p_0) };
    ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 letpair_res_1495;
    {
      auto make_fst_327 { std::get<0>(id_1494) };
      auto make_snd_328 { std::get<1>(id_1494) };
      ::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308 id_1496 { make_fst_327, make_snd_328 };
      letpair_res_1495 = id_1496;
    }
    return letpair_res_1495;
  }
   };
  return fun1493;
}
std::function<::dessser::gen::dashboard_widget::t02960804d32fdda6972311266df50308(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> fun1497 { [&](::dessser::gen::dashboard_widget::t p_0, Pointer p_1) {
    Pointer id_1498 { to_row_binary(p_0, p_1) };
    return id_1498;
  }
   };
  return fun1497;
}
std::function<Pointer(::dessser::gen::dashboard_widget::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
