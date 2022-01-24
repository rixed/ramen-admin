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
#include "desssergen/src_path.h"
#include "desssergen/raql_error.h"
#include "desssergen/raql_warning.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_operation.h"
#include "desssergen/raql_expr.h"
#include "desssergen/retention.h"
#include "desssergen/function_name.h"
#include "desssergen/global_variable.h"
#include "desssergen/raql_expr.h"
#include "desssergen/program_parameter.h"

namespace dessser::gen::source_info {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct compiled_func {
  dessser::gen::function_name::t_ext name;
  std::optional<dessser::gen::retention::t_ext> retention;
  bool is_lazy;
  std::optional<dessser::gen::raql_expr::t_ext> best_after;
  std::string doc;
  dessser::gen::raql_operation::t_ext operation;
  dessser::gen::raql_type::t_ext out_record;
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string signature;
  std::string in_signature;
  compiled_func(dessser::gen::function_name::t_ext name_, std::optional<dessser::gen::retention::t_ext> retention_, bool is_lazy_, std::optional<dessser::gen::raql_expr::t_ext> best_after_, std::string doc_, dessser::gen::raql_operation::t_ext operation_, dessser::gen::raql_type::t_ext out_record_, Lst<dessser::gen::field_name::t_ext> factors_, std::string signature_, std::string in_signature_) : name(name_), retention(retention_), is_lazy(is_lazy_), best_after(best_after_), doc(doc_), operation(operation_), out_record(out_record_), factors(factors_), signature(signature_), in_signature(in_signature_) {}
  compiled_func() = default;
};
inline bool operator==(compiled_func const &a, compiled_func const &b) {
  return ::dessser::gen::function_name::Deref(a.name) == ::dessser::gen::function_name::Deref(b.name) && ((a.retention && b.retention && ::dessser::gen::retention::Deref(a.retention.value()) == ::dessser::gen::retention::Deref(b.retention.value())) || (!a.retention && !b.retention)) && a.is_lazy == b.is_lazy && ((a.best_after && b.best_after && ::dessser::gen::raql_expr::Deref(a.best_after.value()) == ::dessser::gen::raql_expr::Deref(b.best_after.value())) || (!a.best_after && !b.best_after)) && a.doc == b.doc && ::dessser::gen::raql_operation::Deref(a.operation) == ::dessser::gen::raql_operation::Deref(b.operation) && ::dessser::gen::raql_type::Deref(a.out_record) == ::dessser::gen::raql_type::Deref(b.out_record) && a.factors == b.factors && a.signature == b.signature && a.in_signature == b.in_signature;
}

inline bool operator!=(compiled_func const &a, compiled_func const &b) {
  return !operator==(a, b);
}
struct compiled_program {
  Lst<dessser::gen::program_parameter::t_ext> default_params;
  dessser::gen::raql_expr::t_ext condition;
  Lst<dessser::gen::global_variable::t_ext> globals;
  Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > funcs;
  Lst<dessser::gen::raql_warning::t_ext> warnings;
  compiled_program(Lst<dessser::gen::program_parameter::t_ext> default_params_, dessser::gen::raql_expr::t_ext condition_, Lst<dessser::gen::global_variable::t_ext> globals_, Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > funcs_, Lst<dessser::gen::raql_warning::t_ext> warnings_) : default_params(default_params_), condition(condition_), globals(globals_), funcs(funcs_), warnings(warnings_) {}
  compiled_program() = default;
};
inline bool operator==(compiled_program const &a, compiled_program const &b) {
  return a.default_params == b.default_params && ::dessser::gen::raql_expr::Deref(a.condition) == ::dessser::gen::raql_expr::Deref(b.condition) && a.globals == b.globals && a.funcs == b.funcs && a.warnings == b.warnings;
}

inline bool operator!=(compiled_program const &a, compiled_program const &b) {
  return !operator==(a, b);
}
struct td7297575b32536089f1cb63910c9de8b {
  Lst<dessser::gen::raql_error::t_ext> errors;
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  td7297575b32536089f1cb63910c9de8b(Lst<dessser::gen::raql_error::t_ext> errors_, std::optional<dessser::gen::src_path::t_ext> depends_on_) : errors(errors_), depends_on(depends_on_) {}
  td7297575b32536089f1cb63910c9de8b() = default;
};
inline bool operator==(td7297575b32536089f1cb63910c9de8b const &a, td7297575b32536089f1cb63910c9de8b const &b) {
  return a.errors == b.errors && ((a.depends_on && b.depends_on && ::dessser::gen::src_path::Deref(a.depends_on.value()) == ::dessser::gen::src_path::Deref(b.depends_on.value())) || (!a.depends_on && !b.depends_on));
}

inline bool operator!=(td7297575b32536089f1cb63910c9de8b const &a, td7297575b32536089f1cb63910c9de8b const &b) {
  return !operator==(a, b);
}
struct t39aa42e5bfed35fd9fe6b7649dfa4b04 : public std::variant<
  std::shared_ptr<::dessser::gen::source_info::compiled_program> , // Compiled
  ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b // Failed
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t39aa42e5bfed35fd9fe6b7649dfa4b04 const &a, t39aa42e5bfed35fd9fe6b7649dfa4b04 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return (*std::get<0>(a)) == (*std::get<0>(b)); // Compiled
    case 1: return std::get<1>(a) == std::get<1>(b); // Failed
  };
  return false;
}
inline bool operator!=(t39aa42e5bfed35fd9fe6b7649dfa4b04 const &a, t39aa42e5bfed35fd9fe6b7649dfa4b04 const &b) {
  return !operator==(a, b);
}
struct t {
  std::string src_ext;
  Lst<std::string> md5s;
  ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 detail;
  t(std::string src_ext_, Lst<std::string> md5s_, ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 detail_) : src_ext(src_ext_), md5s(md5s_), detail(detail_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.src_ext == b.src_ext && a.md5s == b.md5s && a.detail == b.detail;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t24b44b6db30fb2060e8aaa3137f095be : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::compiled_func> ,
  Pointer
> {
  using tuple::tuple;
  t24b44b6db30fb2060e8aaa3137f095be(std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_func> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_func> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t24b44b6db30fb2060e8aaa3137f095be const &a, t24b44b6db30fb2060e8aaa3137f095be const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t24b44b6db30fb2060e8aaa3137f095be const &a, t24b44b6db30fb2060e8aaa3137f095be const &b) {
  return !operator==(a, b);
}
struct t7ced0f6935c1265b26e1abfcc364f52e : public std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t7ced0f6935c1265b26e1abfcc364f52e(std::tuple<dessser::gen::function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7ced0f6935c1265b26e1abfcc364f52e const &a, t7ced0f6935c1265b26e1abfcc364f52e const &b) {
  return ::dessser::gen::function_name::Deref(std::get<0>(a)) == ::dessser::gen::function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7ced0f6935c1265b26e1abfcc364f52e const &a, t7ced0f6935c1265b26e1abfcc364f52e const &b) {
  return !operator==(a, b);
}
struct tc72cc770fa220718dd8ff2db4757ae10 : public std::tuple<
  std::optional<dessser::gen::retention::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tc72cc770fa220718dd8ff2db4757ae10(std::tuple<std::optional<dessser::gen::retention::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::retention::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc72cc770fa220718dd8ff2db4757ae10 const &a, tc72cc770fa220718dd8ff2db4757ae10 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::retention::Deref(std::get<0>(a).value()) == ::dessser::gen::retention::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc72cc770fa220718dd8ff2db4757ae10 const &a, tc72cc770fa220718dd8ff2db4757ae10 const &b) {
  return !operator==(a, b);
}
struct tde821e6d031c399b029ea4a78810ecf6 : public std::tuple<
  dessser::gen::retention::t_ext,
  Pointer
> {
  using tuple::tuple;
  tde821e6d031c399b029ea4a78810ecf6(std::tuple<dessser::gen::retention::t_ext, Pointer> p)
    : std::tuple<dessser::gen::retention::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tde821e6d031c399b029ea4a78810ecf6 const &a, tde821e6d031c399b029ea4a78810ecf6 const &b) {
  return ::dessser::gen::retention::Deref(std::get<0>(a)) == ::dessser::gen::retention::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tde821e6d031c399b029ea4a78810ecf6 const &a, tde821e6d031c399b029ea4a78810ecf6 const &b) {
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
struct tffcb9977d856d30366202f1b8eb57823 : public std::tuple<
  std::optional<dessser::gen::raql_expr::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tffcb9977d856d30366202f1b8eb57823(std::tuple<std::optional<dessser::gen::raql_expr::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::raql_expr::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tffcb9977d856d30366202f1b8eb57823 const &a, tffcb9977d856d30366202f1b8eb57823 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::raql_expr::Deref(std::get<0>(a).value()) == ::dessser::gen::raql_expr::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tffcb9977d856d30366202f1b8eb57823 const &a, tffcb9977d856d30366202f1b8eb57823 const &b) {
  return !operator==(a, b);
}
struct tc473a3a3b5068e57b15e934d0afcc038 : public std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc473a3a3b5068e57b15e934d0afcc038(std::tuple<dessser::gen::raql_expr::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_expr::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
  return ::dessser::gen::raql_expr::Deref(std::get<0>(a)) == ::dessser::gen::raql_expr::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
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
struct t9539d836e50d2481333b4e3eeeadf0ff : public std::tuple<
  dessser::gen::raql_operation::t_ext,
  Pointer
> {
  using tuple::tuple;
  t9539d836e50d2481333b4e3eeeadf0ff(std::tuple<dessser::gen::raql_operation::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_operation::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9539d836e50d2481333b4e3eeeadf0ff const &a, t9539d836e50d2481333b4e3eeeadf0ff const &b) {
  return ::dessser::gen::raql_operation::Deref(std::get<0>(a)) == ::dessser::gen::raql_operation::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9539d836e50d2481333b4e3eeeadf0ff const &a, t9539d836e50d2481333b4e3eeeadf0ff const &b) {
  return !operator==(a, b);
}
struct t101502ffd7fb38beafe4b49259f92ba1 : public std::tuple<
  dessser::gen::raql_type::t_ext,
  Pointer
> {
  using tuple::tuple;
  t101502ffd7fb38beafe4b49259f92ba1(std::tuple<dessser::gen::raql_type::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_type::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t101502ffd7fb38beafe4b49259f92ba1 const &a, t101502ffd7fb38beafe4b49259f92ba1 const &b) {
  return ::dessser::gen::raql_type::Deref(std::get<0>(a)) == ::dessser::gen::raql_type::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t101502ffd7fb38beafe4b49259f92ba1 const &a, t101502ffd7fb38beafe4b49259f92ba1 const &b) {
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
struct t70259d935c5af76ccd7093d0aa01c0a0 : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::compiled_program> ,
  Pointer
> {
  using tuple::tuple;
  t70259d935c5af76ccd7093d0aa01c0a0(std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_program> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_program> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t70259d935c5af76ccd7093d0aa01c0a0 const &a, t70259d935c5af76ccd7093d0aa01c0a0 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t70259d935c5af76ccd7093d0aa01c0a0 const &a, t70259d935c5af76ccd7093d0aa01c0a0 const &b) {
  return !operator==(a, b);
}
struct t1882123c3b77d3ab876e6d0dd467e800 : public std::tuple<
  Lst<dessser::gen::program_parameter::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t1882123c3b77d3ab876e6d0dd467e800(std::tuple<Lst<dessser::gen::program_parameter::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::program_parameter::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1882123c3b77d3ab876e6d0dd467e800 const &a, t1882123c3b77d3ab876e6d0dd467e800 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1882123c3b77d3ab876e6d0dd467e800 const &a, t1882123c3b77d3ab876e6d0dd467e800 const &b) {
  return !operator==(a, b);
}
struct tbbb6e77f92131ca39155edc6f36a3063 : public std::tuple<
  dessser::gen::program_parameter::t_ext,
  Pointer
> {
  using tuple::tuple;
  tbbb6e77f92131ca39155edc6f36a3063(std::tuple<dessser::gen::program_parameter::t_ext, Pointer> p)
    : std::tuple<dessser::gen::program_parameter::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tbbb6e77f92131ca39155edc6f36a3063 const &a, tbbb6e77f92131ca39155edc6f36a3063 const &b) {
  return ::dessser::gen::program_parameter::Deref(std::get<0>(a)) == ::dessser::gen::program_parameter::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tbbb6e77f92131ca39155edc6f36a3063 const &a, tbbb6e77f92131ca39155edc6f36a3063 const &b) {
  return !operator==(a, b);
}
struct tb460ebd1a257a89e5c8d619ba39de2a7 : public std::tuple<
  Lst<dessser::gen::global_variable::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tb460ebd1a257a89e5c8d619ba39de2a7(std::tuple<Lst<dessser::gen::global_variable::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::global_variable::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb460ebd1a257a89e5c8d619ba39de2a7 const &a, tb460ebd1a257a89e5c8d619ba39de2a7 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb460ebd1a257a89e5c8d619ba39de2a7 const &a, tb460ebd1a257a89e5c8d619ba39de2a7 const &b) {
  return !operator==(a, b);
}
struct t40a6bf0f8e6a7b21bd5b768113e20619 : public std::tuple<
  dessser::gen::global_variable::t_ext,
  Pointer
> {
  using tuple::tuple;
  t40a6bf0f8e6a7b21bd5b768113e20619(std::tuple<dessser::gen::global_variable::t_ext, Pointer> p)
    : std::tuple<dessser::gen::global_variable::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t40a6bf0f8e6a7b21bd5b768113e20619 const &a, t40a6bf0f8e6a7b21bd5b768113e20619 const &b) {
  return ::dessser::gen::global_variable::Deref(std::get<0>(a)) == ::dessser::gen::global_variable::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t40a6bf0f8e6a7b21bd5b768113e20619 const &a, t40a6bf0f8e6a7b21bd5b768113e20619 const &b) {
  return !operator==(a, b);
}
struct t1c57319406adeaa4ba598b4a352fcb47 : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> >,
  Pointer
> {
  using tuple::tuple;
  t1c57319406adeaa4ba598b4a352fcb47(std::tuple<Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1c57319406adeaa4ba598b4a352fcb47 const &a, t1c57319406adeaa4ba598b4a352fcb47 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1c57319406adeaa4ba598b4a352fcb47 const &a, t1c57319406adeaa4ba598b4a352fcb47 const &b) {
  return !operator==(a, b);
}
struct tb1f955478ba8f504d91dbdb67381088c : public std::tuple<
  Lst<dessser::gen::raql_warning::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tb1f955478ba8f504d91dbdb67381088c(std::tuple<Lst<dessser::gen::raql_warning::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::raql_warning::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb1f955478ba8f504d91dbdb67381088c const &a, tb1f955478ba8f504d91dbdb67381088c const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb1f955478ba8f504d91dbdb67381088c const &a, tb1f955478ba8f504d91dbdb67381088c const &b) {
  return !operator==(a, b);
}
struct tf20c5d088795d1f84266f4ee74fe3594 : public std::tuple<
  dessser::gen::raql_warning::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf20c5d088795d1f84266f4ee74fe3594(std::tuple<dessser::gen::raql_warning::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_warning::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf20c5d088795d1f84266f4ee74fe3594 const &a, tf20c5d088795d1f84266f4ee74fe3594 const &b) {
  return ::dessser::gen::raql_warning::Deref(std::get<0>(a)) == ::dessser::gen::raql_warning::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf20c5d088795d1f84266f4ee74fe3594 const &a, tf20c5d088795d1f84266f4ee74fe3594 const &b) {
  return !operator==(a, b);
}
struct t52b663ff57b1b0023c18934f992f38e8 : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::t> ,
  Pointer
> {
  using tuple::tuple;
  t52b663ff57b1b0023c18934f992f38e8(std::tuple<std::shared_ptr<::dessser::gen::source_info::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t52b663ff57b1b0023c18934f992f38e8 const &a, t52b663ff57b1b0023c18934f992f38e8 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t52b663ff57b1b0023c18934f992f38e8 const &a, t52b663ff57b1b0023c18934f992f38e8 const &b) {
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
struct ta6d5b2ed2831b82e0aa9d2a37c294bd6 : public std::tuple<
  ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04,
  Pointer
> {
  using tuple::tuple;
  ta6d5b2ed2831b82e0aa9d2a37c294bd6(std::tuple<::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04, Pointer> p)
    : std::tuple<::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta6d5b2ed2831b82e0aa9d2a37c294bd6 const &a, ta6d5b2ed2831b82e0aa9d2a37c294bd6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta6d5b2ed2831b82e0aa9d2a37c294bd6 const &a, ta6d5b2ed2831b82e0aa9d2a37c294bd6 const &b) {
  return !operator==(a, b);
}
struct t50e7b7e05d9b475b8059a2fda20d15e8 : public std::tuple<
  Lst<dessser::gen::raql_error::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t50e7b7e05d9b475b8059a2fda20d15e8(std::tuple<Lst<dessser::gen::raql_error::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::raql_error::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t50e7b7e05d9b475b8059a2fda20d15e8 const &a, t50e7b7e05d9b475b8059a2fda20d15e8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t50e7b7e05d9b475b8059a2fda20d15e8 const &a, t50e7b7e05d9b475b8059a2fda20d15e8 const &b) {
  return !operator==(a, b);
}
struct teea7fc62226f20557c62e7bf6ca50e88 : public std::tuple<
  dessser::gen::raql_error::t_ext,
  Pointer
> {
  using tuple::tuple;
  teea7fc62226f20557c62e7bf6ca50e88(std::tuple<dessser::gen::raql_error::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_error::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(teea7fc62226f20557c62e7bf6ca50e88 const &a, teea7fc62226f20557c62e7bf6ca50e88 const &b) {
  return ::dessser::gen::raql_error::Deref(std::get<0>(a)) == ::dessser::gen::raql_error::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(teea7fc62226f20557c62e7bf6ca50e88 const &a, teea7fc62226f20557c62e7bf6ca50e88 const &b) {
  return !operator==(a, b);
}
struct t0d3a9bddef6e1883c4a75ebbb2e9dee7 : public std::tuple<
  std::optional<dessser::gen::src_path::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t0d3a9bddef6e1883c4a75ebbb2e9dee7(std::tuple<std::optional<dessser::gen::src_path::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::src_path::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0d3a9bddef6e1883c4a75ebbb2e9dee7 const &a, t0d3a9bddef6e1883c4a75ebbb2e9dee7 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::src_path::Deref(std::get<0>(a).value()) == ::dessser::gen::src_path::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0d3a9bddef6e1883c4a75ebbb2e9dee7 const &a, t0d3a9bddef6e1883c4a75ebbb2e9dee7 const &b) {
  return !operator==(a, b);
}
struct t6915129216bc7fcac0c82f38ea6cfec8 : public std::tuple<
  dessser::gen::src_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  t6915129216bc7fcac0c82f38ea6cfec8(std::tuple<dessser::gen::src_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::src_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6915129216bc7fcac0c82f38ea6cfec8 const &a, t6915129216bc7fcac0c82f38ea6cfec8 const &b) {
  return ::dessser::gen::src_path::Deref(std::get<0>(a)) == ::dessser::gen::src_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6915129216bc7fcac0c82f38ea6cfec8 const &a, t6915129216bc7fcac0c82f38ea6cfec8 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}" "Ptr")
      (let "srec_dst_449"
        (let "srec_dst_446"
          (let "srec_dst_440"
            (let "srec_dst_439"
              (let "srec_dst_438"
                (let "srec_dst_435"
                  (let "srec_dst_434"
                    (let "srec_dst_433"
                      (let "srec_dst_432" (apply (ext-identifier function_name to-row-binary) (get-field "name" (param 0)) (param 1))
                        (if (is-null (get-field "retention" (param 0))) 
                          (write-u8 (identifier "srec_dst_432") (u8 1)) 
                          (apply (ext-identifier retention to-row-binary) (force (get-field "retention" (param 0))) (write-u8 (identifier "srec_dst_432") (u8 0)))))
                      (write-u8 (identifier "srec_dst_433") (u8-of-bool (get-field "is_lazy" (param 0)))))
                    (if (is-null (get-field "best_after" (param 0))) 
                      (write-u8 (identifier "srec_dst_434") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "best_after" (param 0))) (write-u8 (identifier "srec_dst_434") (u8 0)))))
                  (write-bytes
                    (let "leb128_sz_436" (make-vec (string-length (get-field "doc" (param 0))))
                      (let "leb128_ptr_437" (make-vec (identifier "srec_dst_435"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_437")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_437"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_436"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_436"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_436"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_436") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_436")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_436")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_437"))))) 
                    (bytes-of-string (get-field "doc" (param 0))))) (apply (ext-identifier raql_operation to-row-binary) (get-field "operation" (param 0)) (identifier "srec_dst_438")))
              (apply (ext-identifier raql_type to-row-binary) (get-field "out_record" (param 0)) (identifier "srec_dst_439")))
            (let "dst_ref_443"
              (make-vec
                (let "leb128_sz_441" (make-vec (cardinality (get-field "factors" (param 0))))
                  (let "leb128_ptr_442" (make-vec (identifier "srec_dst_440"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_442")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_442"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_441"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_441"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_441"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_441") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_441")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_441")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_442"))))))
              (let "n_ref_444" (make-vec (i32 0))
                (seq
                  (for-each "x_445" (get-field "factors" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_443") (apply (ext-identifier field_name to-row-binary) (identifier "x_445") (unsafe-nth (u8 0) (identifier "dst_ref_443"))))
                      (set-vec (u8 0) (identifier "n_ref_444") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_444")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_443"))))))
          (write-bytes
            (let "leb128_sz_447" (make-vec (string-length (get-field "signature" (param 0))))
              (let "leb128_ptr_448" (make-vec (identifier "srec_dst_446"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_448")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_448"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_447"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_447"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_447"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_447") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_447")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_447")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_448"))))) 
            (bytes-of-string (get-field "signature" (param 0)))))
        (write-bytes
          (let "leb128_sz_450" (make-vec (string-length (get-field "in_signature" (param 0))))
            (let "leb128_ptr_451" (make-vec (identifier "srec_dst_449"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_451")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_451"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_450"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_450"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_450"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_450") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_450")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_450")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_451"))))) 
          (bytes-of-string (get-field "in_signature" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_func> ,Pointer)> compiled_func_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_func> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_func>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::function_name::to_row_binary };
    dessser::gen::function_name::t_ext id_2 { (*p_0).name };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_432 { id_3 };
      std::optional<dessser::gen::retention::t_ext> id_5 { (*p_0).retention };
      bool id_6 { !(id_5.has_value ()) };
      Pointer choose_res_7;
      if (id_6) {
        uint8_t id_8 { 1 };
        Pointer id_9 { srec_dst_432.writeU8(id_8) };
        choose_res_7 = id_9;
      } else {
        auto fun10 { dessser::gen::retention::to_row_binary };
        std::optional<dessser::gen::retention::t_ext> id_11 { (*p_0).retention };
        dessser::gen::retention::t_ext id_12 { id_11.value() };
        uint8_t id_13 { 0 };
        Pointer id_14 { srec_dst_432.writeU8(id_13) };
        Pointer id_15 { fun10(id_12, id_14) };
        choose_res_7 = id_15;
      }
      let_res_4 = choose_res_7;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_433 { let_res_4 };
      bool id_17 { (*p_0).is_lazy };
      uint8_t id_18 { uint8_t(id_17) };
      Pointer id_19 { srec_dst_433.writeU8(id_18) };
      let_res_16 = id_19;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_434 { let_res_16 };
      std::optional<dessser::gen::raql_expr::t_ext> id_21 { (*p_0).best_after };
      bool id_22 { !(id_21.has_value ()) };
      Pointer choose_res_23;
      if (id_22) {
        uint8_t id_24 { 1 };
        Pointer id_25 { srec_dst_434.writeU8(id_24) };
        choose_res_23 = id_25;
      } else {
        auto fun26 { dessser::gen::raql_expr::to_row_binary };
        std::optional<dessser::gen::raql_expr::t_ext> id_27 { (*p_0).best_after };
        dessser::gen::raql_expr::t_ext id_28 { id_27.value() };
        uint8_t id_29 { 0 };
        Pointer id_30 { srec_dst_434.writeU8(id_29) };
        Pointer id_31 { fun26(id_28, id_30) };
        choose_res_23 = id_31;
      }
      let_res_20 = choose_res_23;
    }
    Pointer let_res_32;
    {
      Pointer srec_dst_435 { let_res_20 };
      std::string id_33 { (*p_0).doc };
      uint32_t id_34 { (uint32_t)id_33.size() };
      Vec<1, uint32_t> id_35 {  id_34  };
      Pointer let_res_36;
      {
        Vec<1, uint32_t> leb128_sz_436 { id_35 };
        Vec<1, Pointer> id_37 {  srec_dst_435  };
        Pointer let_res_38;
        {
          Vec<1, Pointer> leb128_ptr_437 { id_37 };
          bool while_flag_39 { true };
          do {
            uint8_t id_40 { 0 };
            uint8_t id_41 { 0 };
            Pointer id_42 { leb128_ptr_437[id_41] };
            uint32_t id_43 { 128U };
            uint8_t id_44 { 0 };
            uint32_t id_45 { leb128_sz_436[id_44] };
            bool id_46 { bool(id_43 > id_45) };
            uint8_t choose_res_47;
            if (id_46) {
              uint8_t id_48 { 0 };
              uint32_t id_49 { leb128_sz_436[id_48] };
              uint8_t id_50 { uint8_t(id_49) };
              choose_res_47 = id_50;
            } else {
              uint8_t id_51 { 0 };
              uint32_t id_52 { leb128_sz_436[id_51] };
              uint8_t id_53 { uint8_t(id_52) };
              uint8_t id_54 { 128 };
              uint8_t id_55 { uint8_t(id_53 | id_54) };
              choose_res_47 = id_55;
            }
            Pointer id_56 { id_42.writeU8(choose_res_47) };
            Void id_57 { ((void)(leb128_ptr_437[id_40] = id_56), ::dessser::Void()) };
            (void)id_57;
            uint8_t id_58 { 0 };
            uint8_t id_59 { 0 };
            uint32_t id_60 { leb128_sz_436[id_59] };
            uint8_t id_61 { 7 };
            uint32_t id_62 { uint32_t(id_60 >> id_61) };
            Void id_63 { ((void)(leb128_sz_436[id_58] = id_62), ::dessser::Void()) };
            (void)id_63;
            uint8_t id_64 { 0 };
            uint32_t id_65 { leb128_sz_436[id_64] };
            uint32_t id_66 { 0U };
            bool id_67 { bool(id_65 > id_66) };
            while_flag_39 = id_67;
            if (while_flag_39) {
              (void)::dessser::Void();
            }
          } while (while_flag_39);
          (void)::dessser::Void();
          uint8_t id_68 { 0 };
          Pointer id_69 { leb128_ptr_437[id_68] };
          let_res_38 = id_69;
        }
        let_res_36 = let_res_38;
      }
      std::string id_70 { (*p_0).doc };
      Bytes id_71 { id_70 };
      Pointer id_72 { let_res_36.writeBytes(id_71) };
      let_res_32 = id_72;
    }
    Pointer let_res_73;
    {
      Pointer srec_dst_438 { let_res_32 };
      auto fun74 { dessser::gen::raql_operation::to_row_binary };
      dessser::gen::raql_operation::t_ext id_75 { (*p_0).operation };
      Pointer id_76 { fun74(id_75, srec_dst_438) };
      let_res_73 = id_76;
    }
    Pointer let_res_77;
    {
      Pointer srec_dst_439 { let_res_73 };
      auto fun78 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t_ext id_79 { (*p_0).out_record };
      Pointer id_80 { fun78(id_79, srec_dst_439) };
      let_res_77 = id_80;
    }
    Pointer let_res_81;
    {
      Pointer srec_dst_440 { let_res_77 };
      Lst<dessser::gen::field_name::t_ext> id_82 { (*p_0).factors };
      uint32_t id_83 { id_82.size() };
      Vec<1, uint32_t> id_84 {  id_83  };
      Pointer let_res_85;
      {
        Vec<1, uint32_t> leb128_sz_441 { id_84 };
        Vec<1, Pointer> id_86 {  srec_dst_440  };
        Pointer let_res_87;
        {
          Vec<1, Pointer> leb128_ptr_442 { id_86 };
          bool while_flag_88 { true };
          do {
            uint8_t id_89 { 0 };
            uint8_t id_90 { 0 };
            Pointer id_91 { leb128_ptr_442[id_90] };
            uint32_t id_92 { 128U };
            uint8_t id_93 { 0 };
            uint32_t id_94 { leb128_sz_441[id_93] };
            bool id_95 { bool(id_92 > id_94) };
            uint8_t choose_res_96;
            if (id_95) {
              uint8_t id_97 { 0 };
              uint32_t id_98 { leb128_sz_441[id_97] };
              uint8_t id_99 { uint8_t(id_98) };
              choose_res_96 = id_99;
            } else {
              uint8_t id_100 { 0 };
              uint32_t id_101 { leb128_sz_441[id_100] };
              uint8_t id_102 { uint8_t(id_101) };
              uint8_t id_103 { 128 };
              uint8_t id_104 { uint8_t(id_102 | id_103) };
              choose_res_96 = id_104;
            }
            Pointer id_105 { id_91.writeU8(choose_res_96) };
            Void id_106 { ((void)(leb128_ptr_442[id_89] = id_105), ::dessser::Void()) };
            (void)id_106;
            uint8_t id_107 { 0 };
            uint8_t id_108 { 0 };
            uint32_t id_109 { leb128_sz_441[id_108] };
            uint8_t id_110 { 7 };
            uint32_t id_111 { uint32_t(id_109 >> id_110) };
            Void id_112 { ((void)(leb128_sz_441[id_107] = id_111), ::dessser::Void()) };
            (void)id_112;
            uint8_t id_113 { 0 };
            uint32_t id_114 { leb128_sz_441[id_113] };
            uint32_t id_115 { 0U };
            bool id_116 { bool(id_114 > id_115) };
            while_flag_88 = id_116;
            if (while_flag_88) {
              (void)::dessser::Void();
            }
          } while (while_flag_88);
          (void)::dessser::Void();
          uint8_t id_117 { 0 };
          Pointer id_118 { leb128_ptr_442[id_117] };
          let_res_87 = id_118;
        }
        let_res_85 = let_res_87;
      }
      Vec<1, Pointer> id_119 {  let_res_85  };
      Pointer let_res_120;
      {
        Vec<1, Pointer> dst_ref_443 { id_119 };
        int32_t id_121 { 0L };
        Vec<1, int32_t> id_122 {  id_121  };
        Pointer let_res_123;
        {
          Vec<1, int32_t> n_ref_444 { id_122 };
          Lst<dessser::gen::field_name::t_ext> id_124 { (*p_0).factors };
          for (dessser::gen::field_name::t_ext &x_445 : id_124) {
            uint8_t id_125 { 0 };
            auto fun126 { dessser::gen::field_name::to_row_binary };
            uint8_t id_127 { 0 };
            Pointer id_128 { dst_ref_443[id_127] };
            Pointer id_129 { fun126(x_445, id_128) };
            Void id_130 { ((void)(dst_ref_443[id_125] = id_129), ::dessser::Void()) };
            (void)id_130;
            uint8_t id_131 { 0 };
            int32_t id_132 { 1L };
            uint8_t id_133 { 0 };
            int32_t id_134 { n_ref_444[id_133] };
            int32_t id_135 { int32_t(id_132 + id_134) };
            Void id_136 { ((void)(n_ref_444[id_131] = id_135), ::dessser::Void()) };
            (void)id_136;
            (void)id_136;
          }
          (void)::dessser::Void();
          uint8_t id_137 { 0 };
          Pointer id_138 { dst_ref_443[id_137] };
          let_res_123 = id_138;
        }
        let_res_120 = let_res_123;
      }
      let_res_81 = let_res_120;
    }
    Pointer let_res_139;
    {
      Pointer srec_dst_446 { let_res_81 };
      std::string id_140 { (*p_0).signature };
      uint32_t id_141 { (uint32_t)id_140.size() };
      Vec<1, uint32_t> id_142 {  id_141  };
      Pointer let_res_143;
      {
        Vec<1, uint32_t> leb128_sz_447 { id_142 };
        Vec<1, Pointer> id_144 {  srec_dst_446  };
        Pointer let_res_145;
        {
          Vec<1, Pointer> leb128_ptr_448 { id_144 };
          bool while_flag_146 { true };
          do {
            uint8_t id_147 { 0 };
            uint8_t id_148 { 0 };
            Pointer id_149 { leb128_ptr_448[id_148] };
            uint32_t id_150 { 128U };
            uint8_t id_151 { 0 };
            uint32_t id_152 { leb128_sz_447[id_151] };
            bool id_153 { bool(id_150 > id_152) };
            uint8_t choose_res_154;
            if (id_153) {
              uint8_t id_155 { 0 };
              uint32_t id_156 { leb128_sz_447[id_155] };
              uint8_t id_157 { uint8_t(id_156) };
              choose_res_154 = id_157;
            } else {
              uint8_t id_158 { 0 };
              uint32_t id_159 { leb128_sz_447[id_158] };
              uint8_t id_160 { uint8_t(id_159) };
              uint8_t id_161 { 128 };
              uint8_t id_162 { uint8_t(id_160 | id_161) };
              choose_res_154 = id_162;
            }
            Pointer id_163 { id_149.writeU8(choose_res_154) };
            Void id_164 { ((void)(leb128_ptr_448[id_147] = id_163), ::dessser::Void()) };
            (void)id_164;
            uint8_t id_165 { 0 };
            uint8_t id_166 { 0 };
            uint32_t id_167 { leb128_sz_447[id_166] };
            uint8_t id_168 { 7 };
            uint32_t id_169 { uint32_t(id_167 >> id_168) };
            Void id_170 { ((void)(leb128_sz_447[id_165] = id_169), ::dessser::Void()) };
            (void)id_170;
            uint8_t id_171 { 0 };
            uint32_t id_172 { leb128_sz_447[id_171] };
            uint32_t id_173 { 0U };
            bool id_174 { bool(id_172 > id_173) };
            while_flag_146 = id_174;
            if (while_flag_146) {
              (void)::dessser::Void();
            }
          } while (while_flag_146);
          (void)::dessser::Void();
          uint8_t id_175 { 0 };
          Pointer id_176 { leb128_ptr_448[id_175] };
          let_res_145 = id_176;
        }
        let_res_143 = let_res_145;
      }
      std::string id_177 { (*p_0).signature };
      Bytes id_178 { id_177 };
      Pointer id_179 { let_res_143.writeBytes(id_178) };
      let_res_139 = id_179;
    }
    Pointer let_res_180;
    {
      Pointer srec_dst_449 { let_res_139 };
      std::string id_181 { (*p_0).in_signature };
      uint32_t id_182 { (uint32_t)id_181.size() };
      Vec<1, uint32_t> id_183 {  id_182  };
      Pointer let_res_184;
      {
        Vec<1, uint32_t> leb128_sz_450 { id_183 };
        Vec<1, Pointer> id_185 {  srec_dst_449  };
        Pointer let_res_186;
        {
          Vec<1, Pointer> leb128_ptr_451 { id_185 };
          bool while_flag_187 { true };
          do {
            uint8_t id_188 { 0 };
            uint8_t id_189 { 0 };
            Pointer id_190 { leb128_ptr_451[id_189] };
            uint32_t id_191 { 128U };
            uint8_t id_192 { 0 };
            uint32_t id_193 { leb128_sz_450[id_192] };
            bool id_194 { bool(id_191 > id_193) };
            uint8_t choose_res_195;
            if (id_194) {
              uint8_t id_196 { 0 };
              uint32_t id_197 { leb128_sz_450[id_196] };
              uint8_t id_198 { uint8_t(id_197) };
              choose_res_195 = id_198;
            } else {
              uint8_t id_199 { 0 };
              uint32_t id_200 { leb128_sz_450[id_199] };
              uint8_t id_201 { uint8_t(id_200) };
              uint8_t id_202 { 128 };
              uint8_t id_203 { uint8_t(id_201 | id_202) };
              choose_res_195 = id_203;
            }
            Pointer id_204 { id_190.writeU8(choose_res_195) };
            Void id_205 { ((void)(leb128_ptr_451[id_188] = id_204), ::dessser::Void()) };
            (void)id_205;
            uint8_t id_206 { 0 };
            uint8_t id_207 { 0 };
            uint32_t id_208 { leb128_sz_450[id_207] };
            uint8_t id_209 { 7 };
            uint32_t id_210 { uint32_t(id_208 >> id_209) };
            Void id_211 { ((void)(leb128_sz_450[id_206] = id_210), ::dessser::Void()) };
            (void)id_211;
            uint8_t id_212 { 0 };
            uint32_t id_213 { leb128_sz_450[id_212] };
            uint32_t id_214 { 0U };
            bool id_215 { bool(id_213 > id_214) };
            while_flag_187 = id_215;
            if (while_flag_187) {
              (void)::dessser::Void();
            }
          } while (while_flag_187);
          (void)::dessser::Void();
          uint8_t id_216 { 0 };
          Pointer id_217 { leb128_ptr_451[id_216] };
          let_res_186 = id_217;
        }
        let_res_184 = let_res_186;
      }
      std::string id_218 { (*p_0).in_signature };
      Bytes id_219 { id_218 };
      Pointer id_220 { let_res_184.writeBytes(id_219) };
      let_res_180 = id_220;
    }
    return let_res_180;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_func> ,Pointer)> compiled_func_to_row_binary(compiled_func_to_row_binary_init());

/* 
    (fun ("{default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}" "Ptr")
      (let "srec_dst_470"
        (let "srec_dst_464"
          (let "srec_dst_458"
            (let "srec_dst_457"
              (let "dst_ref_454"
                (make-vec
                  (let "leb128_sz_452" (make-vec (cardinality (get-field "default_params" (param 0))))
                    (let "leb128_ptr_453" (make-vec (param 1))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_453")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_453"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_452"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_452"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_452"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_452") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_452")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_452")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_453"))))))
                (let "n_ref_455" (make-vec (i32 0))
                  (seq
                    (for-each "x_456" (get-field "default_params" (param 0))
                      (seq (set-vec (u8 0) (identifier "dst_ref_454") (apply (ext-identifier program_parameter to-row-binary) (identifier "x_456") (unsafe-nth (u8 0) (identifier "dst_ref_454"))))
                        (set-vec (u8 0) (identifier "n_ref_455") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_455")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_454"))))) 
              (apply (ext-identifier raql_expr to-row-binary) (get-field "condition" (param 0)) (identifier "srec_dst_457")))
            (let "dst_ref_461"
              (make-vec
                (let "leb128_sz_459" (make-vec (cardinality (get-field "globals" (param 0))))
                  (let "leb128_ptr_460" (make-vec (identifier "srec_dst_458"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_460")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_460"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_459"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_459"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_459"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_459") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_459")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_459")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_460"))))))
              (let "n_ref_462" (make-vec (i32 0))
                (seq
                  (for-each "x_463" (get-field "globals" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_461") (apply (ext-identifier global_variable to-row-binary) (identifier "x_463") (unsafe-nth (u8 0) (identifier "dst_ref_461"))))
                      (set-vec (u8 0) (identifier "n_ref_462") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_462")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_461"))))))
          (let "dst_ref_467"
            (make-vec
              (let "leb128_sz_465" (make-vec (cardinality (get-field "funcs" (param 0))))
                (let "leb128_ptr_466" (make-vec (identifier "srec_dst_464"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_466")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_466"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_465"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_465"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_465"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_465") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_465")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_465")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_466"))))))
            (let "n_ref_468" (make-vec (i32 0))
              (seq
                (for-each "x_469" (get-field "funcs" (param 0))
                  (seq (set-vec (u8 0) (identifier "dst_ref_467") (apply (identifier "compiled_func-to-row-binary") (identifier "x_469") (unsafe-nth (u8 0) (identifier "dst_ref_467"))))
                    (set-vec (u8 0) (identifier "n_ref_468") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_468")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_467"))))))
        (let "dst_ref_473"
          (make-vec
            (let "leb128_sz_471" (make-vec (cardinality (get-field "warnings" (param 0))))
              (let "leb128_ptr_472" (make-vec (identifier "srec_dst_470"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_472")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_472"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_471"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_471"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_471"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_471") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_471")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_471")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_472"))))))
          (let "n_ref_474" (make-vec (i32 0))
            (seq
              (for-each "x_475" (get-field "warnings" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_473") (apply (ext-identifier raql_warning to-row-binary) (identifier "x_475") (unsafe-nth (u8 0) (identifier "dst_ref_473"))))
                  (set-vec (u8 0) (identifier "n_ref_474") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_474")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_473")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> fun221 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_program>  p_0, Pointer p_1) {
    Lst<dessser::gen::program_parameter::t_ext> id_222 { (*p_0).default_params };
    uint32_t id_223 { id_222.size() };
    Vec<1, uint32_t> id_224 {  id_223  };
    Pointer let_res_225;
    {
      Vec<1, uint32_t> leb128_sz_452 { id_224 };
      Vec<1, Pointer> id_226 {  p_1  };
      Pointer let_res_227;
      {
        Vec<1, Pointer> leb128_ptr_453 { id_226 };
        bool while_flag_228 { true };
        do {
          uint8_t id_229 { 0 };
          uint8_t id_230 { 0 };
          Pointer id_231 { leb128_ptr_453[id_230] };
          uint32_t id_232 { 128U };
          uint8_t id_233 { 0 };
          uint32_t id_234 { leb128_sz_452[id_233] };
          bool id_235 { bool(id_232 > id_234) };
          uint8_t choose_res_236;
          if (id_235) {
            uint8_t id_237 { 0 };
            uint32_t id_238 { leb128_sz_452[id_237] };
            uint8_t id_239 { uint8_t(id_238) };
            choose_res_236 = id_239;
          } else {
            uint8_t id_240 { 0 };
            uint32_t id_241 { leb128_sz_452[id_240] };
            uint8_t id_242 { uint8_t(id_241) };
            uint8_t id_243 { 128 };
            uint8_t id_244 { uint8_t(id_242 | id_243) };
            choose_res_236 = id_244;
          }
          Pointer id_245 { id_231.writeU8(choose_res_236) };
          Void id_246 { ((void)(leb128_ptr_453[id_229] = id_245), ::dessser::Void()) };
          (void)id_246;
          uint8_t id_247 { 0 };
          uint8_t id_248 { 0 };
          uint32_t id_249 { leb128_sz_452[id_248] };
          uint8_t id_250 { 7 };
          uint32_t id_251 { uint32_t(id_249 >> id_250) };
          Void id_252 { ((void)(leb128_sz_452[id_247] = id_251), ::dessser::Void()) };
          (void)id_252;
          uint8_t id_253 { 0 };
          uint32_t id_254 { leb128_sz_452[id_253] };
          uint32_t id_255 { 0U };
          bool id_256 { bool(id_254 > id_255) };
          while_flag_228 = id_256;
          if (while_flag_228) {
            (void)::dessser::Void();
          }
        } while (while_flag_228);
        (void)::dessser::Void();
        uint8_t id_257 { 0 };
        Pointer id_258 { leb128_ptr_453[id_257] };
        let_res_227 = id_258;
      }
      let_res_225 = let_res_227;
    }
    Vec<1, Pointer> id_259 {  let_res_225  };
    Pointer let_res_260;
    {
      Vec<1, Pointer> dst_ref_454 { id_259 };
      int32_t id_261 { 0L };
      Vec<1, int32_t> id_262 {  id_261  };
      Pointer let_res_263;
      {
        Vec<1, int32_t> n_ref_455 { id_262 };
        Lst<dessser::gen::program_parameter::t_ext> id_264 { (*p_0).default_params };
        for (dessser::gen::program_parameter::t_ext &x_456 : id_264) {
          uint8_t id_265 { 0 };
          auto fun266 { dessser::gen::program_parameter::to_row_binary };
          uint8_t id_267 { 0 };
          Pointer id_268 { dst_ref_454[id_267] };
          Pointer id_269 { fun266(x_456, id_268) };
          Void id_270 { ((void)(dst_ref_454[id_265] = id_269), ::dessser::Void()) };
          (void)id_270;
          uint8_t id_271 { 0 };
          int32_t id_272 { 1L };
          uint8_t id_273 { 0 };
          int32_t id_274 { n_ref_455[id_273] };
          int32_t id_275 { int32_t(id_272 + id_274) };
          Void id_276 { ((void)(n_ref_455[id_271] = id_275), ::dessser::Void()) };
          (void)id_276;
          (void)id_276;
        }
        (void)::dessser::Void();
        uint8_t id_277 { 0 };
        Pointer id_278 { dst_ref_454[id_277] };
        let_res_263 = id_278;
      }
      let_res_260 = let_res_263;
    }
    Pointer let_res_279;
    {
      Pointer srec_dst_457 { let_res_260 };
      auto fun280 { dessser::gen::raql_expr::to_row_binary };
      dessser::gen::raql_expr::t_ext id_281 { (*p_0).condition };
      Pointer id_282 { fun280(id_281, srec_dst_457) };
      let_res_279 = id_282;
    }
    Pointer let_res_283;
    {
      Pointer srec_dst_458 { let_res_279 };
      Lst<dessser::gen::global_variable::t_ext> id_284 { (*p_0).globals };
      uint32_t id_285 { id_284.size() };
      Vec<1, uint32_t> id_286 {  id_285  };
      Pointer let_res_287;
      {
        Vec<1, uint32_t> leb128_sz_459 { id_286 };
        Vec<1, Pointer> id_288 {  srec_dst_458  };
        Pointer let_res_289;
        {
          Vec<1, Pointer> leb128_ptr_460 { id_288 };
          bool while_flag_290 { true };
          do {
            uint8_t id_291 { 0 };
            uint8_t id_292 { 0 };
            Pointer id_293 { leb128_ptr_460[id_292] };
            uint32_t id_294 { 128U };
            uint8_t id_295 { 0 };
            uint32_t id_296 { leb128_sz_459[id_295] };
            bool id_297 { bool(id_294 > id_296) };
            uint8_t choose_res_298;
            if (id_297) {
              uint8_t id_299 { 0 };
              uint32_t id_300 { leb128_sz_459[id_299] };
              uint8_t id_301 { uint8_t(id_300) };
              choose_res_298 = id_301;
            } else {
              uint8_t id_302 { 0 };
              uint32_t id_303 { leb128_sz_459[id_302] };
              uint8_t id_304 { uint8_t(id_303) };
              uint8_t id_305 { 128 };
              uint8_t id_306 { uint8_t(id_304 | id_305) };
              choose_res_298 = id_306;
            }
            Pointer id_307 { id_293.writeU8(choose_res_298) };
            Void id_308 { ((void)(leb128_ptr_460[id_291] = id_307), ::dessser::Void()) };
            (void)id_308;
            uint8_t id_309 { 0 };
            uint8_t id_310 { 0 };
            uint32_t id_311 { leb128_sz_459[id_310] };
            uint8_t id_312 { 7 };
            uint32_t id_313 { uint32_t(id_311 >> id_312) };
            Void id_314 { ((void)(leb128_sz_459[id_309] = id_313), ::dessser::Void()) };
            (void)id_314;
            uint8_t id_315 { 0 };
            uint32_t id_316 { leb128_sz_459[id_315] };
            uint32_t id_317 { 0U };
            bool id_318 { bool(id_316 > id_317) };
            while_flag_290 = id_318;
            if (while_flag_290) {
              (void)::dessser::Void();
            }
          } while (while_flag_290);
          (void)::dessser::Void();
          uint8_t id_319 { 0 };
          Pointer id_320 { leb128_ptr_460[id_319] };
          let_res_289 = id_320;
        }
        let_res_287 = let_res_289;
      }
      Vec<1, Pointer> id_321 {  let_res_287  };
      Pointer let_res_322;
      {
        Vec<1, Pointer> dst_ref_461 { id_321 };
        int32_t id_323 { 0L };
        Vec<1, int32_t> id_324 {  id_323  };
        Pointer let_res_325;
        {
          Vec<1, int32_t> n_ref_462 { id_324 };
          Lst<dessser::gen::global_variable::t_ext> id_326 { (*p_0).globals };
          for (dessser::gen::global_variable::t_ext &x_463 : id_326) {
            uint8_t id_327 { 0 };
            auto fun328 { dessser::gen::global_variable::to_row_binary };
            uint8_t id_329 { 0 };
            Pointer id_330 { dst_ref_461[id_329] };
            Pointer id_331 { fun328(x_463, id_330) };
            Void id_332 { ((void)(dst_ref_461[id_327] = id_331), ::dessser::Void()) };
            (void)id_332;
            uint8_t id_333 { 0 };
            int32_t id_334 { 1L };
            uint8_t id_335 { 0 };
            int32_t id_336 { n_ref_462[id_335] };
            int32_t id_337 { int32_t(id_334 + id_336) };
            Void id_338 { ((void)(n_ref_462[id_333] = id_337), ::dessser::Void()) };
            (void)id_338;
            (void)id_338;
          }
          (void)::dessser::Void();
          uint8_t id_339 { 0 };
          Pointer id_340 { dst_ref_461[id_339] };
          let_res_325 = id_340;
        }
        let_res_322 = let_res_325;
      }
      let_res_283 = let_res_322;
    }
    Pointer let_res_341;
    {
      Pointer srec_dst_464 { let_res_283 };
      Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_342 { (*p_0).funcs };
      uint32_t id_343 { id_342.size() };
      Vec<1, uint32_t> id_344 {  id_343  };
      Pointer let_res_345;
      {
        Vec<1, uint32_t> leb128_sz_465 { id_344 };
        Vec<1, Pointer> id_346 {  srec_dst_464  };
        Pointer let_res_347;
        {
          Vec<1, Pointer> leb128_ptr_466 { id_346 };
          bool while_flag_348 { true };
          do {
            uint8_t id_349 { 0 };
            uint8_t id_350 { 0 };
            Pointer id_351 { leb128_ptr_466[id_350] };
            uint32_t id_352 { 128U };
            uint8_t id_353 { 0 };
            uint32_t id_354 { leb128_sz_465[id_353] };
            bool id_355 { bool(id_352 > id_354) };
            uint8_t choose_res_356;
            if (id_355) {
              uint8_t id_357 { 0 };
              uint32_t id_358 { leb128_sz_465[id_357] };
              uint8_t id_359 { uint8_t(id_358) };
              choose_res_356 = id_359;
            } else {
              uint8_t id_360 { 0 };
              uint32_t id_361 { leb128_sz_465[id_360] };
              uint8_t id_362 { uint8_t(id_361) };
              uint8_t id_363 { 128 };
              uint8_t id_364 { uint8_t(id_362 | id_363) };
              choose_res_356 = id_364;
            }
            Pointer id_365 { id_351.writeU8(choose_res_356) };
            Void id_366 { ((void)(leb128_ptr_466[id_349] = id_365), ::dessser::Void()) };
            (void)id_366;
            uint8_t id_367 { 0 };
            uint8_t id_368 { 0 };
            uint32_t id_369 { leb128_sz_465[id_368] };
            uint8_t id_370 { 7 };
            uint32_t id_371 { uint32_t(id_369 >> id_370) };
            Void id_372 { ((void)(leb128_sz_465[id_367] = id_371), ::dessser::Void()) };
            (void)id_372;
            uint8_t id_373 { 0 };
            uint32_t id_374 { leb128_sz_465[id_373] };
            uint32_t id_375 { 0U };
            bool id_376 { bool(id_374 > id_375) };
            while_flag_348 = id_376;
            if (while_flag_348) {
              (void)::dessser::Void();
            }
          } while (while_flag_348);
          (void)::dessser::Void();
          uint8_t id_377 { 0 };
          Pointer id_378 { leb128_ptr_466[id_377] };
          let_res_347 = id_378;
        }
        let_res_345 = let_res_347;
      }
      Vec<1, Pointer> id_379 {  let_res_345  };
      Pointer let_res_380;
      {
        Vec<1, Pointer> dst_ref_467 { id_379 };
        int32_t id_381 { 0L };
        Vec<1, int32_t> id_382 {  id_381  };
        Pointer let_res_383;
        {
          Vec<1, int32_t> n_ref_468 { id_382 };
          Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_384 { (*p_0).funcs };
          for (std::shared_ptr<::dessser::gen::source_info::compiled_func>  &x_469 : id_384) {
            uint8_t id_385 { 0 };
            uint8_t id_386 { 0 };
            Pointer id_387 { dst_ref_467[id_386] };
            Pointer id_388 { compiled_func_to_row_binary(x_469, id_387) };
            Void id_389 { ((void)(dst_ref_467[id_385] = id_388), ::dessser::Void()) };
            (void)id_389;
            uint8_t id_390 { 0 };
            int32_t id_391 { 1L };
            uint8_t id_392 { 0 };
            int32_t id_393 { n_ref_468[id_392] };
            int32_t id_394 { int32_t(id_391 + id_393) };
            Void id_395 { ((void)(n_ref_468[id_390] = id_394), ::dessser::Void()) };
            (void)id_395;
            (void)id_395;
          }
          (void)::dessser::Void();
          uint8_t id_396 { 0 };
          Pointer id_397 { dst_ref_467[id_396] };
          let_res_383 = id_397;
        }
        let_res_380 = let_res_383;
      }
      let_res_341 = let_res_380;
    }
    Pointer let_res_398;
    {
      Pointer srec_dst_470 { let_res_341 };
      Lst<dessser::gen::raql_warning::t_ext> id_399 { (*p_0).warnings };
      uint32_t id_400 { id_399.size() };
      Vec<1, uint32_t> id_401 {  id_400  };
      Pointer let_res_402;
      {
        Vec<1, uint32_t> leb128_sz_471 { id_401 };
        Vec<1, Pointer> id_403 {  srec_dst_470  };
        Pointer let_res_404;
        {
          Vec<1, Pointer> leb128_ptr_472 { id_403 };
          bool while_flag_405 { true };
          do {
            uint8_t id_406 { 0 };
            uint8_t id_407 { 0 };
            Pointer id_408 { leb128_ptr_472[id_407] };
            uint32_t id_409 { 128U };
            uint8_t id_410 { 0 };
            uint32_t id_411 { leb128_sz_471[id_410] };
            bool id_412 { bool(id_409 > id_411) };
            uint8_t choose_res_413;
            if (id_412) {
              uint8_t id_414 { 0 };
              uint32_t id_415 { leb128_sz_471[id_414] };
              uint8_t id_416 { uint8_t(id_415) };
              choose_res_413 = id_416;
            } else {
              uint8_t id_417 { 0 };
              uint32_t id_418 { leb128_sz_471[id_417] };
              uint8_t id_419 { uint8_t(id_418) };
              uint8_t id_420 { 128 };
              uint8_t id_421 { uint8_t(id_419 | id_420) };
              choose_res_413 = id_421;
            }
            Pointer id_422 { id_408.writeU8(choose_res_413) };
            Void id_423 { ((void)(leb128_ptr_472[id_406] = id_422), ::dessser::Void()) };
            (void)id_423;
            uint8_t id_424 { 0 };
            uint8_t id_425 { 0 };
            uint32_t id_426 { leb128_sz_471[id_425] };
            uint8_t id_427 { 7 };
            uint32_t id_428 { uint32_t(id_426 >> id_427) };
            Void id_429 { ((void)(leb128_sz_471[id_424] = id_428), ::dessser::Void()) };
            (void)id_429;
            uint8_t id_430 { 0 };
            uint32_t id_431 { leb128_sz_471[id_430] };
            uint32_t id_432 { 0U };
            bool id_433 { bool(id_431 > id_432) };
            while_flag_405 = id_433;
            if (while_flag_405) {
              (void)::dessser::Void();
            }
          } while (while_flag_405);
          (void)::dessser::Void();
          uint8_t id_434 { 0 };
          Pointer id_435 { leb128_ptr_472[id_434] };
          let_res_404 = id_435;
        }
        let_res_402 = let_res_404;
      }
      Vec<1, Pointer> id_436 {  let_res_402  };
      Pointer let_res_437;
      {
        Vec<1, Pointer> dst_ref_473 { id_436 };
        int32_t id_438 { 0L };
        Vec<1, int32_t> id_439 {  id_438  };
        Pointer let_res_440;
        {
          Vec<1, int32_t> n_ref_474 { id_439 };
          Lst<dessser::gen::raql_warning::t_ext> id_441 { (*p_0).warnings };
          for (dessser::gen::raql_warning::t_ext &x_475 : id_441) {
            uint8_t id_442 { 0 };
            auto fun443 { dessser::gen::raql_warning::to_row_binary };
            uint8_t id_444 { 0 };
            Pointer id_445 { dst_ref_473[id_444] };
            Pointer id_446 { fun443(x_475, id_445) };
            Void id_447 { ((void)(dst_ref_473[id_442] = id_446), ::dessser::Void()) };
            (void)id_447;
            uint8_t id_448 { 0 };
            int32_t id_449 { 1L };
            uint8_t id_450 { 0 };
            int32_t id_451 { n_ref_474[id_450] };
            int32_t id_452 { int32_t(id_449 + id_451) };
            Void id_453 { ((void)(n_ref_474[id_448] = id_452), ::dessser::Void()) };
            (void)id_453;
            (void)id_453;
          }
          (void)::dessser::Void();
          uint8_t id_454 { 0 };
          Pointer id_455 { dst_ref_473[id_454] };
          let_res_440 = id_455;
        }
        let_res_437 = let_res_440;
      }
      let_res_398 = let_res_437;
    }
    return let_res_398;
  }
   };
  return fun221;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary(compiled_program_to_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]}" "Ptr")
      (let "srec_dst_486"
        (let "srec_dst_478"
          (write-bytes
            (let "leb128_sz_476" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "leb128_ptr_477" (make-vec (param 1))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_477")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_477"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_476"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_476"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_476"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_476") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_476")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_476")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_477"))))) 
            (bytes-of-string (get-field "src_ext" (param 0))))
          (let "dst_ref_481"
            (make-vec
              (let "leb128_sz_479" (make-vec (cardinality (get-field "md5s" (param 0))))
                (let "leb128_ptr_480" (make-vec (identifier "srec_dst_478"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_480")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_480"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_479"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_479"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_479"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_479") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_479")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_479")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_480"))))))
            (let "n_ref_482" (make-vec (i32 0))
              (seq
                (for-each "x_483" (get-field "md5s" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_481")
                      (write-bytes
                        (let "leb128_sz_484" (make-vec (string-length (identifier "x_483")))
                          (let "leb128_ptr_485" (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_481")))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_485")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_485"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_484"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_484"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_484"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_484") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_484")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_484")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_485"))))) 
                        (bytes-of-string (identifier "x_483")))) (set-vec (u8 0) (identifier "n_ref_482") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_482")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_481"))))))
        (let "ssum_dst_488" (write-u16 little-endian (identifier "srec_dst_486") (label-of (get-field "detail" (param 0))))
          (if (eq (u16 0) (label-of (get-field "detail" (param 0)))) 
            (apply (identifier "compiled_program-to-row-binary") (get-alt "Compiled" (get-field "detail" (param 0))) (identifier "ssum_dst_488"))
            (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
              (let "srec_dst_494"
                (let "dst_ref_491"
                  (make-vec
                    (let "leb128_sz_489" (make-vec (cardinality (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))))
                      (let "leb128_ptr_490" (make-vec (identifier "ssum_dst_488"))
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
                      (for-each "x_493" (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))
                        (seq (set-vec (u8 0) (identifier "dst_ref_491") (apply (ext-identifier raql_error to-row-binary) (identifier "x_493") (unsafe-nth (u8 0) (identifier "dst_ref_491"))))
                          (set-vec (u8 0) (identifier "n_ref_492") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_492")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_491")))))
                (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                  (write-u8 (identifier "srec_dst_494") (u8 1))
                  (apply (ext-identifier src_path to-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) (write-u8 (identifier "srec_dst_494") (u8 0))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> fun456 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0, Pointer p_1) {
    std::string id_457 { (*p_0).src_ext };
    uint32_t id_458 { (uint32_t)id_457.size() };
    Vec<1, uint32_t> id_459 {  id_458  };
    Pointer let_res_460;
    {
      Vec<1, uint32_t> leb128_sz_476 { id_459 };
      Vec<1, Pointer> id_461 {  p_1  };
      Pointer let_res_462;
      {
        Vec<1, Pointer> leb128_ptr_477 { id_461 };
        bool while_flag_463 { true };
        do {
          uint8_t id_464 { 0 };
          uint8_t id_465 { 0 };
          Pointer id_466 { leb128_ptr_477[id_465] };
          uint32_t id_467 { 128U };
          uint8_t id_468 { 0 };
          uint32_t id_469 { leb128_sz_476[id_468] };
          bool id_470 { bool(id_467 > id_469) };
          uint8_t choose_res_471;
          if (id_470) {
            uint8_t id_472 { 0 };
            uint32_t id_473 { leb128_sz_476[id_472] };
            uint8_t id_474 { uint8_t(id_473) };
            choose_res_471 = id_474;
          } else {
            uint8_t id_475 { 0 };
            uint32_t id_476 { leb128_sz_476[id_475] };
            uint8_t id_477 { uint8_t(id_476) };
            uint8_t id_478 { 128 };
            uint8_t id_479 { uint8_t(id_477 | id_478) };
            choose_res_471 = id_479;
          }
          Pointer id_480 { id_466.writeU8(choose_res_471) };
          Void id_481 { ((void)(leb128_ptr_477[id_464] = id_480), ::dessser::Void()) };
          (void)id_481;
          uint8_t id_482 { 0 };
          uint8_t id_483 { 0 };
          uint32_t id_484 { leb128_sz_476[id_483] };
          uint8_t id_485 { 7 };
          uint32_t id_486 { uint32_t(id_484 >> id_485) };
          Void id_487 { ((void)(leb128_sz_476[id_482] = id_486), ::dessser::Void()) };
          (void)id_487;
          uint8_t id_488 { 0 };
          uint32_t id_489 { leb128_sz_476[id_488] };
          uint32_t id_490 { 0U };
          bool id_491 { bool(id_489 > id_490) };
          while_flag_463 = id_491;
          if (while_flag_463) {
            (void)::dessser::Void();
          }
        } while (while_flag_463);
        (void)::dessser::Void();
        uint8_t id_492 { 0 };
        Pointer id_493 { leb128_ptr_477[id_492] };
        let_res_462 = id_493;
      }
      let_res_460 = let_res_462;
    }
    std::string id_494 { (*p_0).src_ext };
    Bytes id_495 { id_494 };
    Pointer id_496 { let_res_460.writeBytes(id_495) };
    Pointer let_res_497;
    {
      Pointer srec_dst_478 { id_496 };
      Lst<std::string> id_498 { (*p_0).md5s };
      uint32_t id_499 { id_498.size() };
      Vec<1, uint32_t> id_500 {  id_499  };
      Pointer let_res_501;
      {
        Vec<1, uint32_t> leb128_sz_479 { id_500 };
        Vec<1, Pointer> id_502 {  srec_dst_478  };
        Pointer let_res_503;
        {
          Vec<1, Pointer> leb128_ptr_480 { id_502 };
          bool while_flag_504 { true };
          do {
            uint8_t id_505 { 0 };
            uint8_t id_506 { 0 };
            Pointer id_507 { leb128_ptr_480[id_506] };
            uint32_t id_508 { 128U };
            uint8_t id_509 { 0 };
            uint32_t id_510 { leb128_sz_479[id_509] };
            bool id_511 { bool(id_508 > id_510) };
            uint8_t choose_res_512;
            if (id_511) {
              uint8_t id_513 { 0 };
              uint32_t id_514 { leb128_sz_479[id_513] };
              uint8_t id_515 { uint8_t(id_514) };
              choose_res_512 = id_515;
            } else {
              uint8_t id_516 { 0 };
              uint32_t id_517 { leb128_sz_479[id_516] };
              uint8_t id_518 { uint8_t(id_517) };
              uint8_t id_519 { 128 };
              uint8_t id_520 { uint8_t(id_518 | id_519) };
              choose_res_512 = id_520;
            }
            Pointer id_521 { id_507.writeU8(choose_res_512) };
            Void id_522 { ((void)(leb128_ptr_480[id_505] = id_521), ::dessser::Void()) };
            (void)id_522;
            uint8_t id_523 { 0 };
            uint8_t id_524 { 0 };
            uint32_t id_525 { leb128_sz_479[id_524] };
            uint8_t id_526 { 7 };
            uint32_t id_527 { uint32_t(id_525 >> id_526) };
            Void id_528 { ((void)(leb128_sz_479[id_523] = id_527), ::dessser::Void()) };
            (void)id_528;
            uint8_t id_529 { 0 };
            uint32_t id_530 { leb128_sz_479[id_529] };
            uint32_t id_531 { 0U };
            bool id_532 { bool(id_530 > id_531) };
            while_flag_504 = id_532;
            if (while_flag_504) {
              (void)::dessser::Void();
            }
          } while (while_flag_504);
          (void)::dessser::Void();
          uint8_t id_533 { 0 };
          Pointer id_534 { leb128_ptr_480[id_533] };
          let_res_503 = id_534;
        }
        let_res_501 = let_res_503;
      }
      Vec<1, Pointer> id_535 {  let_res_501  };
      Pointer let_res_536;
      {
        Vec<1, Pointer> dst_ref_481 { id_535 };
        int32_t id_537 { 0L };
        Vec<1, int32_t> id_538 {  id_537  };
        Pointer let_res_539;
        {
          Vec<1, int32_t> n_ref_482 { id_538 };
          Lst<std::string> id_540 { (*p_0).md5s };
          for (std::string const &x_483 : id_540) {
            uint8_t id_541 { 0 };
            uint32_t id_542 { (uint32_t)x_483.size() };
            Vec<1, uint32_t> id_543 {  id_542  };
            Pointer let_res_544;
            {
              Vec<1, uint32_t> leb128_sz_484 { id_543 };
              uint8_t id_545 { 0 };
              Pointer id_546 { dst_ref_481[id_545] };
              Vec<1, Pointer> id_547 {  id_546  };
              Pointer let_res_548;
              {
                Vec<1, Pointer> leb128_ptr_485 { id_547 };
                bool while_flag_549 { true };
                do {
                  uint8_t id_550 { 0 };
                  uint8_t id_551 { 0 };
                  Pointer id_552 { leb128_ptr_485[id_551] };
                  uint32_t id_553 { 128U };
                  uint8_t id_554 { 0 };
                  uint32_t id_555 { leb128_sz_484[id_554] };
                  bool id_556 { bool(id_553 > id_555) };
                  uint8_t choose_res_557;
                  if (id_556) {
                    uint8_t id_558 { 0 };
                    uint32_t id_559 { leb128_sz_484[id_558] };
                    uint8_t id_560 { uint8_t(id_559) };
                    choose_res_557 = id_560;
                  } else {
                    uint8_t id_561 { 0 };
                    uint32_t id_562 { leb128_sz_484[id_561] };
                    uint8_t id_563 { uint8_t(id_562) };
                    uint8_t id_564 { 128 };
                    uint8_t id_565 { uint8_t(id_563 | id_564) };
                    choose_res_557 = id_565;
                  }
                  Pointer id_566 { id_552.writeU8(choose_res_557) };
                  Void id_567 { ((void)(leb128_ptr_485[id_550] = id_566), ::dessser::Void()) };
                  (void)id_567;
                  uint8_t id_568 { 0 };
                  uint8_t id_569 { 0 };
                  uint32_t id_570 { leb128_sz_484[id_569] };
                  uint8_t id_571 { 7 };
                  uint32_t id_572 { uint32_t(id_570 >> id_571) };
                  Void id_573 { ((void)(leb128_sz_484[id_568] = id_572), ::dessser::Void()) };
                  (void)id_573;
                  uint8_t id_574 { 0 };
                  uint32_t id_575 { leb128_sz_484[id_574] };
                  uint32_t id_576 { 0U };
                  bool id_577 { bool(id_575 > id_576) };
                  while_flag_549 = id_577;
                  if (while_flag_549) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_549);
                (void)::dessser::Void();
                uint8_t id_578 { 0 };
                Pointer id_579 { leb128_ptr_485[id_578] };
                let_res_548 = id_579;
              }
              let_res_544 = let_res_548;
            }
            Bytes id_580 { x_483 };
            Pointer id_581 { let_res_544.writeBytes(id_580) };
            Void id_582 { ((void)(dst_ref_481[id_541] = id_581), ::dessser::Void()) };
            (void)id_582;
            uint8_t id_583 { 0 };
            int32_t id_584 { 1L };
            uint8_t id_585 { 0 };
            int32_t id_586 { n_ref_482[id_585] };
            int32_t id_587 { int32_t(id_584 + id_586) };
            Void id_588 { ((void)(n_ref_482[id_583] = id_587), ::dessser::Void()) };
            (void)id_588;
            (void)id_588;
          }
          (void)::dessser::Void();
          uint8_t id_589 { 0 };
          Pointer id_590 { dst_ref_481[id_589] };
          let_res_539 = id_590;
        }
        let_res_536 = let_res_539;
      }
      let_res_497 = let_res_536;
    }
    Pointer let_res_591;
    {
      Pointer srec_dst_486 { let_res_497 };
      ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_592 { (*p_0).detail };
      uint16_t id_593 { uint16_t(id_592.index()) };
      Pointer id_594 { srec_dst_486.writeU16Le(id_593) };
      Pointer let_res_595;
      {
        Pointer ssum_dst_488 { id_594 };
        uint16_t id_596 { 0 };
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_597 { (*p_0).detail };
        uint16_t id_598 { uint16_t(id_597.index()) };
        bool id_599 { bool(id_596 == id_598) };
        Pointer choose_res_600;
        if (id_599) {
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_601 { (*p_0).detail };
          std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_602 { std::get<0 /* Compiled */>(id_601) };
          Pointer id_603 { compiled_program_to_row_binary(id_602, ssum_dst_488) };
          choose_res_600 = id_603;
        } else {
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_604 { (*p_0).detail };
          uint16_t id_605 { uint16_t(id_604.index()) };
          uint16_t id_606 { 1 };
          bool id_607 { bool(id_605 == id_606) };
          Void id_608 { ((void)(assert(id_607)), ::dessser::Void()) };
          (void)id_608;
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_609 { (*p_0).detail };
          ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_610 { std::get<1 /* Failed */>(id_609) };
          Lst<dessser::gen::raql_error::t_ext> id_611 { id_610.errors };
          uint32_t id_612 { id_611.size() };
          Vec<1, uint32_t> id_613 {  id_612  };
          Pointer let_res_614;
          {
            Vec<1, uint32_t> leb128_sz_489 { id_613 };
            Vec<1, Pointer> id_615 {  ssum_dst_488  };
            Pointer let_res_616;
            {
              Vec<1, Pointer> leb128_ptr_490 { id_615 };
              bool while_flag_617 { true };
              do {
                uint8_t id_618 { 0 };
                uint8_t id_619 { 0 };
                Pointer id_620 { leb128_ptr_490[id_619] };
                uint32_t id_621 { 128U };
                uint8_t id_622 { 0 };
                uint32_t id_623 { leb128_sz_489[id_622] };
                bool id_624 { bool(id_621 > id_623) };
                uint8_t choose_res_625;
                if (id_624) {
                  uint8_t id_626 { 0 };
                  uint32_t id_627 { leb128_sz_489[id_626] };
                  uint8_t id_628 { uint8_t(id_627) };
                  choose_res_625 = id_628;
                } else {
                  uint8_t id_629 { 0 };
                  uint32_t id_630 { leb128_sz_489[id_629] };
                  uint8_t id_631 { uint8_t(id_630) };
                  uint8_t id_632 { 128 };
                  uint8_t id_633 { uint8_t(id_631 | id_632) };
                  choose_res_625 = id_633;
                }
                Pointer id_634 { id_620.writeU8(choose_res_625) };
                Void id_635 { ((void)(leb128_ptr_490[id_618] = id_634), ::dessser::Void()) };
                (void)id_635;
                uint8_t id_636 { 0 };
                uint8_t id_637 { 0 };
                uint32_t id_638 { leb128_sz_489[id_637] };
                uint8_t id_639 { 7 };
                uint32_t id_640 { uint32_t(id_638 >> id_639) };
                Void id_641 { ((void)(leb128_sz_489[id_636] = id_640), ::dessser::Void()) };
                (void)id_641;
                uint8_t id_642 { 0 };
                uint32_t id_643 { leb128_sz_489[id_642] };
                uint32_t id_644 { 0U };
                bool id_645 { bool(id_643 > id_644) };
                while_flag_617 = id_645;
                if (while_flag_617) {
                  (void)::dessser::Void();
                }
              } while (while_flag_617);
              (void)::dessser::Void();
              uint8_t id_646 { 0 };
              Pointer id_647 { leb128_ptr_490[id_646] };
              let_res_616 = id_647;
            }
            let_res_614 = let_res_616;
          }
          Vec<1, Pointer> id_648 {  let_res_614  };
          Pointer let_res_649;
          {
            Vec<1, Pointer> dst_ref_491 { id_648 };
            int32_t id_650 { 0L };
            Vec<1, int32_t> id_651 {  id_650  };
            Pointer let_res_652;
            {
              Vec<1, int32_t> n_ref_492 { id_651 };
              ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_653 { (*p_0).detail };
              ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_654 { std::get<1 /* Failed */>(id_653) };
              Lst<dessser::gen::raql_error::t_ext> id_655 { id_654.errors };
              for (dessser::gen::raql_error::t_ext &x_493 : id_655) {
                uint8_t id_656 { 0 };
                auto fun657 { dessser::gen::raql_error::to_row_binary };
                uint8_t id_658 { 0 };
                Pointer id_659 { dst_ref_491[id_658] };
                Pointer id_660 { fun657(x_493, id_659) };
                Void id_661 { ((void)(dst_ref_491[id_656] = id_660), ::dessser::Void()) };
                (void)id_661;
                uint8_t id_662 { 0 };
                int32_t id_663 { 1L };
                uint8_t id_664 { 0 };
                int32_t id_665 { n_ref_492[id_664] };
                int32_t id_666 { int32_t(id_663 + id_665) };
                Void id_667 { ((void)(n_ref_492[id_662] = id_666), ::dessser::Void()) };
                (void)id_667;
                (void)id_667;
              }
              (void)::dessser::Void();
              uint8_t id_668 { 0 };
              Pointer id_669 { dst_ref_491[id_668] };
              let_res_652 = id_669;
            }
            let_res_649 = let_res_652;
          }
          Pointer let_res_670;
          {
            Pointer srec_dst_494 { let_res_649 };
            ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_671 { (*p_0).detail };
            ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_672 { std::get<1 /* Failed */>(id_671) };
            std::optional<dessser::gen::src_path::t_ext> id_673 { id_672.depends_on };
            bool id_674 { !(id_673.has_value ()) };
            Pointer choose_res_675;
            if (id_674) {
              uint8_t id_676 { 1 };
              Pointer id_677 { srec_dst_494.writeU8(id_676) };
              choose_res_675 = id_677;
            } else {
              auto fun678 { dessser::gen::src_path::to_row_binary };
              ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_679 { (*p_0).detail };
              ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_680 { std::get<1 /* Failed */>(id_679) };
              std::optional<dessser::gen::src_path::t_ext> id_681 { id_680.depends_on };
              dessser::gen::src_path::t_ext id_682 { id_681.value() };
              uint8_t id_683 { 0 };
              Pointer id_684 { srec_dst_494.writeU8(id_683) };
              Pointer id_685 { fun678(id_682, id_684) };
              choose_res_675 = id_685;
            }
            let_res_670 = choose_res_675;
          }
          choose_res_600 = let_res_670;
        }
        let_res_595 = choose_res_600;
      }
      let_res_591 = let_res_595;
    }
    return let_res_591;
  }
   };
  return fun456;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}")
      (let "sz_387"
        (let "sz_383"
          (let "sz_378"
            (let "sz_377"
              (let "sz_376"
                (let "sz_372"
                  (let "sz_371"
                    (add
                      (let "sz_369" (apply (ext-identifier function_name sersize-of-row-binary) (get-field "name" (param 0)))
                        (if (is-null (get-field "retention" (param 0))) 
                          (add (identifier "sz_369") (size 1)) (add (add (identifier "sz_369") (apply (ext-identifier retention sersize-of-row-binary) (force (get-field "retention" (param 0))))) (size 1)))) 
                      (size 1))
                    (if (is-null (get-field "best_after" (param 0))) 
                      (add (identifier "sz_371") (size 1)) (add (add (identifier "sz_371") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "best_after" (param 0))))) (size 1))))
                  (add (identifier "sz_372")
                    (add
                      (let "n_ref_374" (make-vec (string-length (get-field "doc" (param 0))))
                        (let "lebsz_ref_375" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_374")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_375") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_375")))))) 
                      (size-of-u32 (string-length (get-field "doc" (param 0))))))) 
                (add (identifier "sz_376") (apply (ext-identifier raql_operation sersize-of-row-binary) (get-field "operation" (param 0)))))
              (add (identifier "sz_377") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "out_record" (param 0)))))
            (let "sz_ref_381"
              (make-vec
                (add (identifier "sz_378")
                  (let "n_ref_379" (make-vec (cardinality (get-field "factors" (param 0))))
                    (let "lebsz_ref_380" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_379")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_380")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_380") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_380")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_380"))))))))
              (seq
                (let "repeat_n_382" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "factors" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_382")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_381")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_381")) (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_382")) (get-field "factors" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_382") (add (unsafe-nth (u8 0) (identifier "repeat_n_382")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_381")))))
          (add (identifier "sz_383")
            (add
              (let "n_ref_385" (make-vec (string-length (get-field "signature" (param 0))))
                (let "lebsz_ref_386" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_385")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_386")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_386") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_386")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_386")))))) 
              (size-of-u32 (string-length (get-field "signature" (param 0)))))))
        (add (identifier "sz_387")
          (add
            (let "n_ref_389" (make-vec (string-length (get-field "in_signature" (param 0))))
              (let "lebsz_ref_390" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_389")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_390")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_390") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_390")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_390")))))) 
            (size-of-u32 (string-length (get-field "in_signature" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> fun686 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_func>  p_0) {
    auto fun687 { dessser::gen::function_name::sersize_of_row_binary };
    dessser::gen::function_name::t_ext id_688 { (*p_0).name };
    Size id_689 { fun687(id_688) };
    Size let_res_690;
    {
      Size sz_369 { id_689 };
      std::optional<dessser::gen::retention::t_ext> id_691 { (*p_0).retention };
      bool id_692 { !(id_691.has_value ()) };
      Size choose_res_693;
      if (id_692) {
        Size id_694 { 1UL };
        Size id_695 { Size(sz_369 + id_694) };
        choose_res_693 = id_695;
      } else {
        auto fun696 { dessser::gen::retention::sersize_of_row_binary };
        std::optional<dessser::gen::retention::t_ext> id_697 { (*p_0).retention };
        dessser::gen::retention::t_ext id_698 { id_697.value() };
        Size id_699 { fun696(id_698) };
        Size id_700 { Size(sz_369 + id_699) };
        Size id_701 { 1UL };
        Size id_702 { Size(id_700 + id_701) };
        choose_res_693 = id_702;
      }
      let_res_690 = choose_res_693;
    }
    Size id_703 { 1UL };
    Size id_704 { Size(let_res_690 + id_703) };
    Size let_res_705;
    {
      Size sz_371 { id_704 };
      std::optional<dessser::gen::raql_expr::t_ext> id_706 { (*p_0).best_after };
      bool id_707 { !(id_706.has_value ()) };
      Size choose_res_708;
      if (id_707) {
        Size id_709 { 1UL };
        Size id_710 { Size(sz_371 + id_709) };
        choose_res_708 = id_710;
      } else {
        auto fun711 { dessser::gen::raql_expr::sersize_of_row_binary };
        std::optional<dessser::gen::raql_expr::t_ext> id_712 { (*p_0).best_after };
        dessser::gen::raql_expr::t_ext id_713 { id_712.value() };
        Size id_714 { fun711(id_713) };
        Size id_715 { Size(sz_371 + id_714) };
        Size id_716 { 1UL };
        Size id_717 { Size(id_715 + id_716) };
        choose_res_708 = id_717;
      }
      let_res_705 = choose_res_708;
    }
    Size let_res_718;
    {
      Size sz_372 { let_res_705 };
      std::string id_719 { (*p_0).doc };
      uint32_t id_720 { (uint32_t)id_719.size() };
      Vec<1, uint32_t> id_721 {  id_720  };
      Size let_res_722;
      {
        Vec<1, uint32_t> n_ref_374 { id_721 };
        uint32_t id_723 { 1U };
        Vec<1, uint32_t> id_724 {  id_723  };
        Size let_res_725;
        {
          Vec<1, uint32_t> lebsz_ref_375 { id_724 };
          bool while_flag_726 { true };
          do {
            uint8_t id_727 { 0 };
            uint32_t id_728 { n_ref_374[id_727] };
            uint8_t id_729 { 0 };
            uint32_t id_730 { lebsz_ref_375[id_729] };
            uint8_t id_731 { 7 };
            uint32_t id_732 { uint32_t(id_730 << id_731) };
            bool id_733 { bool(id_728 >= id_732) };
            while_flag_726 = id_733;
            if (while_flag_726) {
              uint8_t id_734 { 0 };
              uint8_t id_735 { 0 };
              uint32_t id_736 { lebsz_ref_375[id_735] };
              uint32_t id_737 { 1U };
              uint32_t id_738 { uint32_t(id_736 + id_737) };
              Void id_739 { ((void)(lebsz_ref_375[id_734] = id_738), ::dessser::Void()) };
              (void)id_739;
            }
          } while (while_flag_726);
          (void)::dessser::Void();
          uint8_t id_740 { 0 };
          uint32_t id_741 { lebsz_ref_375[id_740] };
          Size id_742 { Size(id_741) };
          let_res_725 = id_742;
        }
        let_res_722 = let_res_725;
      }
      std::string id_743 { (*p_0).doc };
      uint32_t id_744 { (uint32_t)id_743.size() };
      Size id_745 { Size(id_744) };
      Size id_746 { Size(let_res_722 + id_745) };
      Size id_747 { Size(sz_372 + id_746) };
      let_res_718 = id_747;
    }
    Size let_res_748;
    {
      Size sz_376 { let_res_718 };
      auto fun749 { dessser::gen::raql_operation::sersize_of_row_binary };
      dessser::gen::raql_operation::t_ext id_750 { (*p_0).operation };
      Size id_751 { fun749(id_750) };
      Size id_752 { Size(sz_376 + id_751) };
      let_res_748 = id_752;
    }
    Size let_res_753;
    {
      Size sz_377 { let_res_748 };
      auto fun754 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t_ext id_755 { (*p_0).out_record };
      Size id_756 { fun754(id_755) };
      Size id_757 { Size(sz_377 + id_756) };
      let_res_753 = id_757;
    }
    Size let_res_758;
    {
      Size sz_378 { let_res_753 };
      Lst<dessser::gen::field_name::t_ext> id_759 { (*p_0).factors };
      uint32_t id_760 { id_759.size() };
      Vec<1, uint32_t> id_761 {  id_760  };
      Size let_res_762;
      {
        Vec<1, uint32_t> n_ref_379 { id_761 };
        uint32_t id_763 { 1U };
        Vec<1, uint32_t> id_764 {  id_763  };
        Size let_res_765;
        {
          Vec<1, uint32_t> lebsz_ref_380 { id_764 };
          bool while_flag_766 { true };
          do {
            uint8_t id_767 { 0 };
            uint32_t id_768 { n_ref_379[id_767] };
            uint8_t id_769 { 0 };
            uint32_t id_770 { lebsz_ref_380[id_769] };
            uint8_t id_771 { 7 };
            uint32_t id_772 { uint32_t(id_770 << id_771) };
            bool id_773 { bool(id_768 >= id_772) };
            while_flag_766 = id_773;
            if (while_flag_766) {
              uint8_t id_774 { 0 };
              uint8_t id_775 { 0 };
              uint32_t id_776 { lebsz_ref_380[id_775] };
              uint32_t id_777 { 1U };
              uint32_t id_778 { uint32_t(id_776 + id_777) };
              Void id_779 { ((void)(lebsz_ref_380[id_774] = id_778), ::dessser::Void()) };
              (void)id_779;
            }
          } while (while_flag_766);
          (void)::dessser::Void();
          uint8_t id_780 { 0 };
          uint32_t id_781 { lebsz_ref_380[id_780] };
          Size id_782 { Size(id_781) };
          let_res_765 = id_782;
        }
        let_res_762 = let_res_765;
      }
      Size id_783 { Size(sz_378 + let_res_762) };
      Vec<1, Size> id_784 {  id_783  };
      Size let_res_785;
      {
        Vec<1, Size> sz_ref_381 { id_784 };
        int32_t id_786 { 0L };
        Vec<1, int32_t> id_787 {  id_786  };
        {
          Vec<1, int32_t> repeat_n_382 { id_787 };
          bool while_flag_788 { true };
          do {
            Lst<dessser::gen::field_name::t_ext> id_789 { (*p_0).factors };
            uint32_t id_790 { id_789.size() };
            int32_t id_791 { int32_t(id_790) };
            uint8_t id_792 { 0 };
            int32_t id_793 { repeat_n_382[id_792] };
            bool id_794 { bool(id_791 > id_793) };
            while_flag_788 = id_794;
            if (while_flag_788) {
              uint8_t id_795 { 0 };
              uint8_t id_796 { 0 };
              Size id_797 { sz_ref_381[id_796] };
              auto fun798 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_799 { 0 };
              int32_t id_800 { repeat_n_382[id_799] };
              Lst<dessser::gen::field_name::t_ext> id_801 { (*p_0).factors };
              dessser::gen::field_name::t_ext id_802 { id_801[id_800] };
              Size id_803 { fun798(id_802) };
              Size id_804 { Size(id_797 + id_803) };
              Void id_805 { ((void)(sz_ref_381[id_795] = id_804), ::dessser::Void()) };
              (void)id_805;
              uint8_t id_806 { 0 };
              uint8_t id_807 { 0 };
              int32_t id_808 { repeat_n_382[id_807] };
              int32_t id_809 { 1L };
              int32_t id_810 { int32_t(id_808 + id_809) };
              Void id_811 { ((void)(repeat_n_382[id_806] = id_810), ::dessser::Void()) };
              (void)id_811;
              (void)id_811;
            }
          } while (while_flag_788);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_812 { 0 };
        Size id_813 { sz_ref_381[id_812] };
        let_res_785 = id_813;
      }
      let_res_758 = let_res_785;
    }
    Size let_res_814;
    {
      Size sz_383 { let_res_758 };
      std::string id_815 { (*p_0).signature };
      uint32_t id_816 { (uint32_t)id_815.size() };
      Vec<1, uint32_t> id_817 {  id_816  };
      Size let_res_818;
      {
        Vec<1, uint32_t> n_ref_385 { id_817 };
        uint32_t id_819 { 1U };
        Vec<1, uint32_t> id_820 {  id_819  };
        Size let_res_821;
        {
          Vec<1, uint32_t> lebsz_ref_386 { id_820 };
          bool while_flag_822 { true };
          do {
            uint8_t id_823 { 0 };
            uint32_t id_824 { n_ref_385[id_823] };
            uint8_t id_825 { 0 };
            uint32_t id_826 { lebsz_ref_386[id_825] };
            uint8_t id_827 { 7 };
            uint32_t id_828 { uint32_t(id_826 << id_827) };
            bool id_829 { bool(id_824 >= id_828) };
            while_flag_822 = id_829;
            if (while_flag_822) {
              uint8_t id_830 { 0 };
              uint8_t id_831 { 0 };
              uint32_t id_832 { lebsz_ref_386[id_831] };
              uint32_t id_833 { 1U };
              uint32_t id_834 { uint32_t(id_832 + id_833) };
              Void id_835 { ((void)(lebsz_ref_386[id_830] = id_834), ::dessser::Void()) };
              (void)id_835;
            }
          } while (while_flag_822);
          (void)::dessser::Void();
          uint8_t id_836 { 0 };
          uint32_t id_837 { lebsz_ref_386[id_836] };
          Size id_838 { Size(id_837) };
          let_res_821 = id_838;
        }
        let_res_818 = let_res_821;
      }
      std::string id_839 { (*p_0).signature };
      uint32_t id_840 { (uint32_t)id_839.size() };
      Size id_841 { Size(id_840) };
      Size id_842 { Size(let_res_818 + id_841) };
      Size id_843 { Size(sz_383 + id_842) };
      let_res_814 = id_843;
    }
    Size let_res_844;
    {
      Size sz_387 { let_res_814 };
      std::string id_845 { (*p_0).in_signature };
      uint32_t id_846 { (uint32_t)id_845.size() };
      Vec<1, uint32_t> id_847 {  id_846  };
      Size let_res_848;
      {
        Vec<1, uint32_t> n_ref_389 { id_847 };
        uint32_t id_849 { 1U };
        Vec<1, uint32_t> id_850 {  id_849  };
        Size let_res_851;
        {
          Vec<1, uint32_t> lebsz_ref_390 { id_850 };
          bool while_flag_852 { true };
          do {
            uint8_t id_853 { 0 };
            uint32_t id_854 { n_ref_389[id_853] };
            uint8_t id_855 { 0 };
            uint32_t id_856 { lebsz_ref_390[id_855] };
            uint8_t id_857 { 7 };
            uint32_t id_858 { uint32_t(id_856 << id_857) };
            bool id_859 { bool(id_854 >= id_858) };
            while_flag_852 = id_859;
            if (while_flag_852) {
              uint8_t id_860 { 0 };
              uint8_t id_861 { 0 };
              uint32_t id_862 { lebsz_ref_390[id_861] };
              uint32_t id_863 { 1U };
              uint32_t id_864 { uint32_t(id_862 + id_863) };
              Void id_865 { ((void)(lebsz_ref_390[id_860] = id_864), ::dessser::Void()) };
              (void)id_865;
            }
          } while (while_flag_852);
          (void)::dessser::Void();
          uint8_t id_866 { 0 };
          uint32_t id_867 { lebsz_ref_390[id_866] };
          Size id_868 { Size(id_867) };
          let_res_851 = id_868;
        }
        let_res_848 = let_res_851;
      }
      std::string id_869 { (*p_0).in_signature };
      uint32_t id_870 { (uint32_t)id_869.size() };
      Size id_871 { Size(id_870) };
      Size id_872 { Size(let_res_848 + id_871) };
      Size id_873 { Size(sz_387 + id_872) };
      let_res_844 = id_873;
    }
    return let_res_844;
  }
   };
  return fun686;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary(compiled_func_sersize_of_row_binary_init());

/* 
    (fun ("{default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}")
      (let "sz_407"
        (let "sz_402"
          (let "sz_397"
            (let "sz_396"
              (let "sz_ref_394"
                (make-vec
                  (let "n_ref_392" (make-vec (cardinality (get-field "default_params" (param 0))))
                    (let "lebsz_ref_393" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_392")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_393")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_393") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_393")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_393")))))))
                (seq
                  (let "repeat_n_395" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "default_params" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_395")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_394")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_394"))
                            (apply (ext-identifier program_parameter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_395")) (get-field "default_params" (param 0))))))
                        (set-vec (u8 0) (identifier "repeat_n_395") (add (unsafe-nth (u8 0) (identifier "repeat_n_395")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_394")))) (add (identifier "sz_396") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "condition" (param 0)))))
            (let "sz_ref_400"
              (make-vec
                (add (identifier "sz_397")
                  (let "n_ref_398" (make-vec (cardinality (get-field "globals" (param 0))))
                    (let "lebsz_ref_399" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_398")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_399")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_399") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_399")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_399"))))))))
              (seq
                (let "repeat_n_401" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "globals" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_401")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_400")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_400"))
                          (apply (ext-identifier global_variable sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_401")) (get-field "globals" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_401") (add (unsafe-nth (u8 0) (identifier "repeat_n_401")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_400")))))
          (let "sz_ref_405"
            (make-vec
              (add (identifier "sz_402")
                (let "n_ref_403" (make-vec (cardinality (get-field "funcs" (param 0))))
                  (let "lebsz_ref_404" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_403")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_404")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_404") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_404")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_404"))))))))
            (seq
              (let "repeat_n_406" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "funcs" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_406")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_405")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_405")) (apply (identifier "compiled_func-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_406")) (get-field "funcs" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_406") (add (unsafe-nth (u8 0) (identifier "repeat_n_406")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_405")))))
        (let "sz_ref_410"
          (make-vec
            (add (identifier "sz_407")
              (let "n_ref_408" (make-vec (cardinality (get-field "warnings" (param 0))))
                (let "lebsz_ref_409" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_408")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_409")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_409") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_409")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_409"))))))))
          (seq
            (let "repeat_n_411" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "warnings" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_411")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_410")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_410")) (apply (ext-identifier raql_warning sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_411")) (get-field "warnings" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_411") (add (unsafe-nth (u8 0) (identifier "repeat_n_411")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_410"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> fun874 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_program>  p_0) {
    Lst<dessser::gen::program_parameter::t_ext> id_875 { (*p_0).default_params };
    uint32_t id_876 { id_875.size() };
    Vec<1, uint32_t> id_877 {  id_876  };
    Size let_res_878;
    {
      Vec<1, uint32_t> n_ref_392 { id_877 };
      uint32_t id_879 { 1U };
      Vec<1, uint32_t> id_880 {  id_879  };
      Size let_res_881;
      {
        Vec<1, uint32_t> lebsz_ref_393 { id_880 };
        bool while_flag_882 { true };
        do {
          uint8_t id_883 { 0 };
          uint32_t id_884 { n_ref_392[id_883] };
          uint8_t id_885 { 0 };
          uint32_t id_886 { lebsz_ref_393[id_885] };
          uint8_t id_887 { 7 };
          uint32_t id_888 { uint32_t(id_886 << id_887) };
          bool id_889 { bool(id_884 >= id_888) };
          while_flag_882 = id_889;
          if (while_flag_882) {
            uint8_t id_890 { 0 };
            uint8_t id_891 { 0 };
            uint32_t id_892 { lebsz_ref_393[id_891] };
            uint32_t id_893 { 1U };
            uint32_t id_894 { uint32_t(id_892 + id_893) };
            Void id_895 { ((void)(lebsz_ref_393[id_890] = id_894), ::dessser::Void()) };
            (void)id_895;
          }
        } while (while_flag_882);
        (void)::dessser::Void();
        uint8_t id_896 { 0 };
        uint32_t id_897 { lebsz_ref_393[id_896] };
        Size id_898 { Size(id_897) };
        let_res_881 = id_898;
      }
      let_res_878 = let_res_881;
    }
    Vec<1, Size> id_899 {  let_res_878  };
    Size let_res_900;
    {
      Vec<1, Size> sz_ref_394 { id_899 };
      int32_t id_901 { 0L };
      Vec<1, int32_t> id_902 {  id_901  };
      {
        Vec<1, int32_t> repeat_n_395 { id_902 };
        bool while_flag_903 { true };
        do {
          Lst<dessser::gen::program_parameter::t_ext> id_904 { (*p_0).default_params };
          uint32_t id_905 { id_904.size() };
          int32_t id_906 { int32_t(id_905) };
          uint8_t id_907 { 0 };
          int32_t id_908 { repeat_n_395[id_907] };
          bool id_909 { bool(id_906 > id_908) };
          while_flag_903 = id_909;
          if (while_flag_903) {
            uint8_t id_910 { 0 };
            uint8_t id_911 { 0 };
            Size id_912 { sz_ref_394[id_911] };
            auto fun913 { dessser::gen::program_parameter::sersize_of_row_binary };
            uint8_t id_914 { 0 };
            int32_t id_915 { repeat_n_395[id_914] };
            Lst<dessser::gen::program_parameter::t_ext> id_916 { (*p_0).default_params };
            dessser::gen::program_parameter::t_ext id_917 { id_916[id_915] };
            Size id_918 { fun913(id_917) };
            Size id_919 { Size(id_912 + id_918) };
            Void id_920 { ((void)(sz_ref_394[id_910] = id_919), ::dessser::Void()) };
            (void)id_920;
            uint8_t id_921 { 0 };
            uint8_t id_922 { 0 };
            int32_t id_923 { repeat_n_395[id_922] };
            int32_t id_924 { 1L };
            int32_t id_925 { int32_t(id_923 + id_924) };
            Void id_926 { ((void)(repeat_n_395[id_921] = id_925), ::dessser::Void()) };
            (void)id_926;
            (void)id_926;
          }
        } while (while_flag_903);
        (void)::dessser::Void();
      }
      (void)::dessser::Void();
      uint8_t id_927 { 0 };
      Size id_928 { sz_ref_394[id_927] };
      let_res_900 = id_928;
    }
    Size let_res_929;
    {
      Size sz_396 { let_res_900 };
      auto fun930 { dessser::gen::raql_expr::sersize_of_row_binary };
      dessser::gen::raql_expr::t_ext id_931 { (*p_0).condition };
      Size id_932 { fun930(id_931) };
      Size id_933 { Size(sz_396 + id_932) };
      let_res_929 = id_933;
    }
    Size let_res_934;
    {
      Size sz_397 { let_res_929 };
      Lst<dessser::gen::global_variable::t_ext> id_935 { (*p_0).globals };
      uint32_t id_936 { id_935.size() };
      Vec<1, uint32_t> id_937 {  id_936  };
      Size let_res_938;
      {
        Vec<1, uint32_t> n_ref_398 { id_937 };
        uint32_t id_939 { 1U };
        Vec<1, uint32_t> id_940 {  id_939  };
        Size let_res_941;
        {
          Vec<1, uint32_t> lebsz_ref_399 { id_940 };
          bool while_flag_942 { true };
          do {
            uint8_t id_943 { 0 };
            uint32_t id_944 { n_ref_398[id_943] };
            uint8_t id_945 { 0 };
            uint32_t id_946 { lebsz_ref_399[id_945] };
            uint8_t id_947 { 7 };
            uint32_t id_948 { uint32_t(id_946 << id_947) };
            bool id_949 { bool(id_944 >= id_948) };
            while_flag_942 = id_949;
            if (while_flag_942) {
              uint8_t id_950 { 0 };
              uint8_t id_951 { 0 };
              uint32_t id_952 { lebsz_ref_399[id_951] };
              uint32_t id_953 { 1U };
              uint32_t id_954 { uint32_t(id_952 + id_953) };
              Void id_955 { ((void)(lebsz_ref_399[id_950] = id_954), ::dessser::Void()) };
              (void)id_955;
            }
          } while (while_flag_942);
          (void)::dessser::Void();
          uint8_t id_956 { 0 };
          uint32_t id_957 { lebsz_ref_399[id_956] };
          Size id_958 { Size(id_957) };
          let_res_941 = id_958;
        }
        let_res_938 = let_res_941;
      }
      Size id_959 { Size(sz_397 + let_res_938) };
      Vec<1, Size> id_960 {  id_959  };
      Size let_res_961;
      {
        Vec<1, Size> sz_ref_400 { id_960 };
        int32_t id_962 { 0L };
        Vec<1, int32_t> id_963 {  id_962  };
        {
          Vec<1, int32_t> repeat_n_401 { id_963 };
          bool while_flag_964 { true };
          do {
            Lst<dessser::gen::global_variable::t_ext> id_965 { (*p_0).globals };
            uint32_t id_966 { id_965.size() };
            int32_t id_967 { int32_t(id_966) };
            uint8_t id_968 { 0 };
            int32_t id_969 { repeat_n_401[id_968] };
            bool id_970 { bool(id_967 > id_969) };
            while_flag_964 = id_970;
            if (while_flag_964) {
              uint8_t id_971 { 0 };
              uint8_t id_972 { 0 };
              Size id_973 { sz_ref_400[id_972] };
              auto fun974 { dessser::gen::global_variable::sersize_of_row_binary };
              uint8_t id_975 { 0 };
              int32_t id_976 { repeat_n_401[id_975] };
              Lst<dessser::gen::global_variable::t_ext> id_977 { (*p_0).globals };
              dessser::gen::global_variable::t_ext id_978 { id_977[id_976] };
              Size id_979 { fun974(id_978) };
              Size id_980 { Size(id_973 + id_979) };
              Void id_981 { ((void)(sz_ref_400[id_971] = id_980), ::dessser::Void()) };
              (void)id_981;
              uint8_t id_982 { 0 };
              uint8_t id_983 { 0 };
              int32_t id_984 { repeat_n_401[id_983] };
              int32_t id_985 { 1L };
              int32_t id_986 { int32_t(id_984 + id_985) };
              Void id_987 { ((void)(repeat_n_401[id_982] = id_986), ::dessser::Void()) };
              (void)id_987;
              (void)id_987;
            }
          } while (while_flag_964);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_988 { 0 };
        Size id_989 { sz_ref_400[id_988] };
        let_res_961 = id_989;
      }
      let_res_934 = let_res_961;
    }
    Size let_res_990;
    {
      Size sz_402 { let_res_934 };
      Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_991 { (*p_0).funcs };
      uint32_t id_992 { id_991.size() };
      Vec<1, uint32_t> id_993 {  id_992  };
      Size let_res_994;
      {
        Vec<1, uint32_t> n_ref_403 { id_993 };
        uint32_t id_995 { 1U };
        Vec<1, uint32_t> id_996 {  id_995  };
        Size let_res_997;
        {
          Vec<1, uint32_t> lebsz_ref_404 { id_996 };
          bool while_flag_998 { true };
          do {
            uint8_t id_999 { 0 };
            uint32_t id_1000 { n_ref_403[id_999] };
            uint8_t id_1001 { 0 };
            uint32_t id_1002 { lebsz_ref_404[id_1001] };
            uint8_t id_1003 { 7 };
            uint32_t id_1004 { uint32_t(id_1002 << id_1003) };
            bool id_1005 { bool(id_1000 >= id_1004) };
            while_flag_998 = id_1005;
            if (while_flag_998) {
              uint8_t id_1006 { 0 };
              uint8_t id_1007 { 0 };
              uint32_t id_1008 { lebsz_ref_404[id_1007] };
              uint32_t id_1009 { 1U };
              uint32_t id_1010 { uint32_t(id_1008 + id_1009) };
              Void id_1011 { ((void)(lebsz_ref_404[id_1006] = id_1010), ::dessser::Void()) };
              (void)id_1011;
            }
          } while (while_flag_998);
          (void)::dessser::Void();
          uint8_t id_1012 { 0 };
          uint32_t id_1013 { lebsz_ref_404[id_1012] };
          Size id_1014 { Size(id_1013) };
          let_res_997 = id_1014;
        }
        let_res_994 = let_res_997;
      }
      Size id_1015 { Size(sz_402 + let_res_994) };
      Vec<1, Size> id_1016 {  id_1015  };
      Size let_res_1017;
      {
        Vec<1, Size> sz_ref_405 { id_1016 };
        int32_t id_1018 { 0L };
        Vec<1, int32_t> id_1019 {  id_1018  };
        {
          Vec<1, int32_t> repeat_n_406 { id_1019 };
          bool while_flag_1020 { true };
          do {
            Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_1021 { (*p_0).funcs };
            uint32_t id_1022 { id_1021.size() };
            int32_t id_1023 { int32_t(id_1022) };
            uint8_t id_1024 { 0 };
            int32_t id_1025 { repeat_n_406[id_1024] };
            bool id_1026 { bool(id_1023 > id_1025) };
            while_flag_1020 = id_1026;
            if (while_flag_1020) {
              uint8_t id_1027 { 0 };
              uint8_t id_1028 { 0 };
              Size id_1029 { sz_ref_405[id_1028] };
              uint8_t id_1030 { 0 };
              int32_t id_1031 { repeat_n_406[id_1030] };
              Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_1032 { (*p_0).funcs };
              std::shared_ptr<::dessser::gen::source_info::compiled_func>  id_1033 { id_1032[id_1031] };
              Size id_1034 { compiled_func_sersize_of_row_binary(id_1033) };
              Size id_1035 { Size(id_1029 + id_1034) };
              Void id_1036 { ((void)(sz_ref_405[id_1027] = id_1035), ::dessser::Void()) };
              (void)id_1036;
              uint8_t id_1037 { 0 };
              uint8_t id_1038 { 0 };
              int32_t id_1039 { repeat_n_406[id_1038] };
              int32_t id_1040 { 1L };
              int32_t id_1041 { int32_t(id_1039 + id_1040) };
              Void id_1042 { ((void)(repeat_n_406[id_1037] = id_1041), ::dessser::Void()) };
              (void)id_1042;
              (void)id_1042;
            }
          } while (while_flag_1020);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1043 { 0 };
        Size id_1044 { sz_ref_405[id_1043] };
        let_res_1017 = id_1044;
      }
      let_res_990 = let_res_1017;
    }
    Size let_res_1045;
    {
      Size sz_407 { let_res_990 };
      Lst<dessser::gen::raql_warning::t_ext> id_1046 { (*p_0).warnings };
      uint32_t id_1047 { id_1046.size() };
      Vec<1, uint32_t> id_1048 {  id_1047  };
      Size let_res_1049;
      {
        Vec<1, uint32_t> n_ref_408 { id_1048 };
        uint32_t id_1050 { 1U };
        Vec<1, uint32_t> id_1051 {  id_1050  };
        Size let_res_1052;
        {
          Vec<1, uint32_t> lebsz_ref_409 { id_1051 };
          bool while_flag_1053 { true };
          do {
            uint8_t id_1054 { 0 };
            uint32_t id_1055 { n_ref_408[id_1054] };
            uint8_t id_1056 { 0 };
            uint32_t id_1057 { lebsz_ref_409[id_1056] };
            uint8_t id_1058 { 7 };
            uint32_t id_1059 { uint32_t(id_1057 << id_1058) };
            bool id_1060 { bool(id_1055 >= id_1059) };
            while_flag_1053 = id_1060;
            if (while_flag_1053) {
              uint8_t id_1061 { 0 };
              uint8_t id_1062 { 0 };
              uint32_t id_1063 { lebsz_ref_409[id_1062] };
              uint32_t id_1064 { 1U };
              uint32_t id_1065 { uint32_t(id_1063 + id_1064) };
              Void id_1066 { ((void)(lebsz_ref_409[id_1061] = id_1065), ::dessser::Void()) };
              (void)id_1066;
            }
          } while (while_flag_1053);
          (void)::dessser::Void();
          uint8_t id_1067 { 0 };
          uint32_t id_1068 { lebsz_ref_409[id_1067] };
          Size id_1069 { Size(id_1068) };
          let_res_1052 = id_1069;
        }
        let_res_1049 = let_res_1052;
      }
      Size id_1070 { Size(sz_407 + let_res_1049) };
      Vec<1, Size> id_1071 {  id_1070  };
      Size let_res_1072;
      {
        Vec<1, Size> sz_ref_410 { id_1071 };
        int32_t id_1073 { 0L };
        Vec<1, int32_t> id_1074 {  id_1073  };
        {
          Vec<1, int32_t> repeat_n_411 { id_1074 };
          bool while_flag_1075 { true };
          do {
            Lst<dessser::gen::raql_warning::t_ext> id_1076 { (*p_0).warnings };
            uint32_t id_1077 { id_1076.size() };
            int32_t id_1078 { int32_t(id_1077) };
            uint8_t id_1079 { 0 };
            int32_t id_1080 { repeat_n_411[id_1079] };
            bool id_1081 { bool(id_1078 > id_1080) };
            while_flag_1075 = id_1081;
            if (while_flag_1075) {
              uint8_t id_1082 { 0 };
              uint8_t id_1083 { 0 };
              Size id_1084 { sz_ref_410[id_1083] };
              auto fun1085 { dessser::gen::raql_warning::sersize_of_row_binary };
              uint8_t id_1086 { 0 };
              int32_t id_1087 { repeat_n_411[id_1086] };
              Lst<dessser::gen::raql_warning::t_ext> id_1088 { (*p_0).warnings };
              dessser::gen::raql_warning::t_ext id_1089 { id_1088[id_1087] };
              Size id_1090 { fun1085(id_1089) };
              Size id_1091 { Size(id_1084 + id_1090) };
              Void id_1092 { ((void)(sz_ref_410[id_1082] = id_1091), ::dessser::Void()) };
              (void)id_1092;
              uint8_t id_1093 { 0 };
              uint8_t id_1094 { 0 };
              int32_t id_1095 { repeat_n_411[id_1094] };
              int32_t id_1096 { 1L };
              int32_t id_1097 { int32_t(id_1095 + id_1096) };
              Void id_1098 { ((void)(repeat_n_411[id_1093] = id_1097), ::dessser::Void()) };
              (void)id_1098;
              (void)id_1098;
            }
          } while (while_flag_1075);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1099 { 0 };
        Size id_1100 { sz_ref_410[id_1099] };
        let_res_1072 = id_1100;
      }
      let_res_1045 = let_res_1072;
    }
    return let_res_1045;
  }
   };
  return fun874;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary(compiled_program_sersize_of_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]}")
      (let "sz_424"
        (let "sz_416"
          (add
            (let "n_ref_414" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "lebsz_ref_415" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_414")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_415")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_415") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_415")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_415")))))) 
            (size-of-u32 (string-length (get-field "src_ext" (param 0)))))
          (let "sz_ref_419"
            (make-vec
              (add (identifier "sz_416")
                (let "n_ref_417" (make-vec (cardinality (get-field "md5s" (param 0))))
                  (let "lebsz_ref_418" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_417")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_418")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_418") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_418")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_418"))))))))
            (seq
              (let "repeat_n_420" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "md5s" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_420")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_419")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_419"))
                        (let "wlen_421" (string-length (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_420")) (get-field "md5s" (param 0))))
                          (add
                            (let "n_ref_422" (make-vec (identifier "wlen_421"))
                              (let "lebsz_ref_423" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_422")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_423")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_423") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_423")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_423")))))) 
                            (size-of-u32 (identifier "wlen_421")))))) 
                    (set-vec (u8 0) (identifier "repeat_n_420") (add (unsafe-nth (u8 0) (identifier "repeat_n_420")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_419")))))
        (if (eq (u16 0) (label-of (get-field "detail" (param 0)))) (add (add (identifier "sz_424") (size 2)) (apply (identifier "compiled_program-sersize-of-row-binary") (get-alt "Compiled" (get-field "detail" (param 0)))))
          (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
            (let "sz_431"
              (let "sz_ref_429"
                (make-vec
                  (add (add (identifier "sz_424") (size 2))
                    (let "n_ref_427" (make-vec (cardinality (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))))
                      (let "lebsz_ref_428" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_427")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_428")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_428") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_428")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_428"))))))))
                (seq
                  (let "repeat_n_430" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_430")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_429")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_429"))
                            (apply (ext-identifier raql_error sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_430")) (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))))))
                        (set-vec (u8 0) (identifier "repeat_n_430") (add (unsafe-nth (u8 0) (identifier "repeat_n_430")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_429"))))
              (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                (add (identifier "sz_431") (size 1))
                (add (add (identifier "sz_431") (apply (ext-identifier src_path sersize-of-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))))) (size 1))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> fun1101 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0) {
    std::string id_1102 { (*p_0).src_ext };
    uint32_t id_1103 { (uint32_t)id_1102.size() };
    Vec<1, uint32_t> id_1104 {  id_1103  };
    Size let_res_1105;
    {
      Vec<1, uint32_t> n_ref_414 { id_1104 };
      uint32_t id_1106 { 1U };
      Vec<1, uint32_t> id_1107 {  id_1106  };
      Size let_res_1108;
      {
        Vec<1, uint32_t> lebsz_ref_415 { id_1107 };
        bool while_flag_1109 { true };
        do {
          uint8_t id_1110 { 0 };
          uint32_t id_1111 { n_ref_414[id_1110] };
          uint8_t id_1112 { 0 };
          uint32_t id_1113 { lebsz_ref_415[id_1112] };
          uint8_t id_1114 { 7 };
          uint32_t id_1115 { uint32_t(id_1113 << id_1114) };
          bool id_1116 { bool(id_1111 >= id_1115) };
          while_flag_1109 = id_1116;
          if (while_flag_1109) {
            uint8_t id_1117 { 0 };
            uint8_t id_1118 { 0 };
            uint32_t id_1119 { lebsz_ref_415[id_1118] };
            uint32_t id_1120 { 1U };
            uint32_t id_1121 { uint32_t(id_1119 + id_1120) };
            Void id_1122 { ((void)(lebsz_ref_415[id_1117] = id_1121), ::dessser::Void()) };
            (void)id_1122;
          }
        } while (while_flag_1109);
        (void)::dessser::Void();
        uint8_t id_1123 { 0 };
        uint32_t id_1124 { lebsz_ref_415[id_1123] };
        Size id_1125 { Size(id_1124) };
        let_res_1108 = id_1125;
      }
      let_res_1105 = let_res_1108;
    }
    std::string id_1126 { (*p_0).src_ext };
    uint32_t id_1127 { (uint32_t)id_1126.size() };
    Size id_1128 { Size(id_1127) };
    Size id_1129 { Size(let_res_1105 + id_1128) };
    Size let_res_1130;
    {
      Size sz_416 { id_1129 };
      Lst<std::string> id_1131 { (*p_0).md5s };
      uint32_t id_1132 { id_1131.size() };
      Vec<1, uint32_t> id_1133 {  id_1132  };
      Size let_res_1134;
      {
        Vec<1, uint32_t> n_ref_417 { id_1133 };
        uint32_t id_1135 { 1U };
        Vec<1, uint32_t> id_1136 {  id_1135  };
        Size let_res_1137;
        {
          Vec<1, uint32_t> lebsz_ref_418 { id_1136 };
          bool while_flag_1138 { true };
          do {
            uint8_t id_1139 { 0 };
            uint32_t id_1140 { n_ref_417[id_1139] };
            uint8_t id_1141 { 0 };
            uint32_t id_1142 { lebsz_ref_418[id_1141] };
            uint8_t id_1143 { 7 };
            uint32_t id_1144 { uint32_t(id_1142 << id_1143) };
            bool id_1145 { bool(id_1140 >= id_1144) };
            while_flag_1138 = id_1145;
            if (while_flag_1138) {
              uint8_t id_1146 { 0 };
              uint8_t id_1147 { 0 };
              uint32_t id_1148 { lebsz_ref_418[id_1147] };
              uint32_t id_1149 { 1U };
              uint32_t id_1150 { uint32_t(id_1148 + id_1149) };
              Void id_1151 { ((void)(lebsz_ref_418[id_1146] = id_1150), ::dessser::Void()) };
              (void)id_1151;
            }
          } while (while_flag_1138);
          (void)::dessser::Void();
          uint8_t id_1152 { 0 };
          uint32_t id_1153 { lebsz_ref_418[id_1152] };
          Size id_1154 { Size(id_1153) };
          let_res_1137 = id_1154;
        }
        let_res_1134 = let_res_1137;
      }
      Size id_1155 { Size(sz_416 + let_res_1134) };
      Vec<1, Size> id_1156 {  id_1155  };
      Size let_res_1157;
      {
        Vec<1, Size> sz_ref_419 { id_1156 };
        int32_t id_1158 { 0L };
        Vec<1, int32_t> id_1159 {  id_1158  };
        {
          Vec<1, int32_t> repeat_n_420 { id_1159 };
          bool while_flag_1160 { true };
          do {
            Lst<std::string> id_1161 { (*p_0).md5s };
            uint32_t id_1162 { id_1161.size() };
            int32_t id_1163 { int32_t(id_1162) };
            uint8_t id_1164 { 0 };
            int32_t id_1165 { repeat_n_420[id_1164] };
            bool id_1166 { bool(id_1163 > id_1165) };
            while_flag_1160 = id_1166;
            if (while_flag_1160) {
              uint8_t id_1167 { 0 };
              uint8_t id_1168 { 0 };
              Size id_1169 { sz_ref_419[id_1168] };
              uint8_t id_1170 { 0 };
              int32_t id_1171 { repeat_n_420[id_1170] };
              Lst<std::string> id_1172 { (*p_0).md5s };
              std::string id_1173 { id_1172[id_1171] };
              uint32_t id_1174 { (uint32_t)id_1173.size() };
              Size let_res_1175;
              {
                uint32_t wlen_421 { id_1174 };
                Vec<1, uint32_t> id_1176 {  wlen_421  };
                Size let_res_1177;
                {
                  Vec<1, uint32_t> n_ref_422 { id_1176 };
                  uint32_t id_1178 { 1U };
                  Vec<1, uint32_t> id_1179 {  id_1178  };
                  Size let_res_1180;
                  {
                    Vec<1, uint32_t> lebsz_ref_423 { id_1179 };
                    bool while_flag_1181 { true };
                    do {
                      uint8_t id_1182 { 0 };
                      uint32_t id_1183 { n_ref_422[id_1182] };
                      uint8_t id_1184 { 0 };
                      uint32_t id_1185 { lebsz_ref_423[id_1184] };
                      uint8_t id_1186 { 7 };
                      uint32_t id_1187 { uint32_t(id_1185 << id_1186) };
                      bool id_1188 { bool(id_1183 >= id_1187) };
                      while_flag_1181 = id_1188;
                      if (while_flag_1181) {
                        uint8_t id_1189 { 0 };
                        uint8_t id_1190 { 0 };
                        uint32_t id_1191 { lebsz_ref_423[id_1190] };
                        uint32_t id_1192 { 1U };
                        uint32_t id_1193 { uint32_t(id_1191 + id_1192) };
                        Void id_1194 { ((void)(lebsz_ref_423[id_1189] = id_1193), ::dessser::Void()) };
                        (void)id_1194;
                      }
                    } while (while_flag_1181);
                    (void)::dessser::Void();
                    uint8_t id_1195 { 0 };
                    uint32_t id_1196 { lebsz_ref_423[id_1195] };
                    Size id_1197 { Size(id_1196) };
                    let_res_1180 = id_1197;
                  }
                  let_res_1177 = let_res_1180;
                }
                Size id_1198 { Size(wlen_421) };
                Size id_1199 { Size(let_res_1177 + id_1198) };
                let_res_1175 = id_1199;
              }
              Size id_1200 { Size(id_1169 + let_res_1175) };
              Void id_1201 { ((void)(sz_ref_419[id_1167] = id_1200), ::dessser::Void()) };
              (void)id_1201;
              uint8_t id_1202 { 0 };
              uint8_t id_1203 { 0 };
              int32_t id_1204 { repeat_n_420[id_1203] };
              int32_t id_1205 { 1L };
              int32_t id_1206 { int32_t(id_1204 + id_1205) };
              Void id_1207 { ((void)(repeat_n_420[id_1202] = id_1206), ::dessser::Void()) };
              (void)id_1207;
              (void)id_1207;
            }
          } while (while_flag_1160);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1208 { 0 };
        Size id_1209 { sz_ref_419[id_1208] };
        let_res_1157 = id_1209;
      }
      let_res_1130 = let_res_1157;
    }
    Size let_res_1210;
    {
      Size sz_424 { let_res_1130 };
      uint16_t id_1211 { 0 };
      ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1212 { (*p_0).detail };
      uint16_t id_1213 { uint16_t(id_1212.index()) };
      bool id_1214 { bool(id_1211 == id_1213) };
      Size choose_res_1215;
      if (id_1214) {
        Size id_1216 { 2UL };
        Size id_1217 { Size(sz_424 + id_1216) };
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1218 { (*p_0).detail };
        std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_1219 { std::get<0 /* Compiled */>(id_1218) };
        Size id_1220 { compiled_program_sersize_of_row_binary(id_1219) };
        Size id_1221 { Size(id_1217 + id_1220) };
        choose_res_1215 = id_1221;
      } else {
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1222 { (*p_0).detail };
        uint16_t id_1223 { uint16_t(id_1222.index()) };
        uint16_t id_1224 { 1 };
        bool id_1225 { bool(id_1223 == id_1224) };
        Void id_1226 { ((void)(assert(id_1225)), ::dessser::Void()) };
        (void)id_1226;
        Size id_1227 { 2UL };
        Size id_1228 { Size(sz_424 + id_1227) };
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1229 { (*p_0).detail };
        ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1230 { std::get<1 /* Failed */>(id_1229) };
        Lst<dessser::gen::raql_error::t_ext> id_1231 { id_1230.errors };
        uint32_t id_1232 { id_1231.size() };
        Vec<1, uint32_t> id_1233 {  id_1232  };
        Size let_res_1234;
        {
          Vec<1, uint32_t> n_ref_427 { id_1233 };
          uint32_t id_1235 { 1U };
          Vec<1, uint32_t> id_1236 {  id_1235  };
          Size let_res_1237;
          {
            Vec<1, uint32_t> lebsz_ref_428 { id_1236 };
            bool while_flag_1238 { true };
            do {
              uint8_t id_1239 { 0 };
              uint32_t id_1240 { n_ref_427[id_1239] };
              uint8_t id_1241 { 0 };
              uint32_t id_1242 { lebsz_ref_428[id_1241] };
              uint8_t id_1243 { 7 };
              uint32_t id_1244 { uint32_t(id_1242 << id_1243) };
              bool id_1245 { bool(id_1240 >= id_1244) };
              while_flag_1238 = id_1245;
              if (while_flag_1238) {
                uint8_t id_1246 { 0 };
                uint8_t id_1247 { 0 };
                uint32_t id_1248 { lebsz_ref_428[id_1247] };
                uint32_t id_1249 { 1U };
                uint32_t id_1250 { uint32_t(id_1248 + id_1249) };
                Void id_1251 { ((void)(lebsz_ref_428[id_1246] = id_1250), ::dessser::Void()) };
                (void)id_1251;
              }
            } while (while_flag_1238);
            (void)::dessser::Void();
            uint8_t id_1252 { 0 };
            uint32_t id_1253 { lebsz_ref_428[id_1252] };
            Size id_1254 { Size(id_1253) };
            let_res_1237 = id_1254;
          }
          let_res_1234 = let_res_1237;
        }
        Size id_1255 { Size(id_1228 + let_res_1234) };
        Vec<1, Size> id_1256 {  id_1255  };
        Size let_res_1257;
        {
          Vec<1, Size> sz_ref_429 { id_1256 };
          int32_t id_1258 { 0L };
          Vec<1, int32_t> id_1259 {  id_1258  };
          {
            Vec<1, int32_t> repeat_n_430 { id_1259 };
            bool while_flag_1260 { true };
            do {
              ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1261 { (*p_0).detail };
              ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1262 { std::get<1 /* Failed */>(id_1261) };
              Lst<dessser::gen::raql_error::t_ext> id_1263 { id_1262.errors };
              uint32_t id_1264 { id_1263.size() };
              int32_t id_1265 { int32_t(id_1264) };
              uint8_t id_1266 { 0 };
              int32_t id_1267 { repeat_n_430[id_1266] };
              bool id_1268 { bool(id_1265 > id_1267) };
              while_flag_1260 = id_1268;
              if (while_flag_1260) {
                uint8_t id_1269 { 0 };
                uint8_t id_1270 { 0 };
                Size id_1271 { sz_ref_429[id_1270] };
                auto fun1272 { dessser::gen::raql_error::sersize_of_row_binary };
                uint8_t id_1273 { 0 };
                int32_t id_1274 { repeat_n_430[id_1273] };
                ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1275 { (*p_0).detail };
                ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1276 { std::get<1 /* Failed */>(id_1275) };
                Lst<dessser::gen::raql_error::t_ext> id_1277 { id_1276.errors };
                dessser::gen::raql_error::t_ext id_1278 { id_1277[id_1274] };
                Size id_1279 { fun1272(id_1278) };
                Size id_1280 { Size(id_1271 + id_1279) };
                Void id_1281 { ((void)(sz_ref_429[id_1269] = id_1280), ::dessser::Void()) };
                (void)id_1281;
                uint8_t id_1282 { 0 };
                uint8_t id_1283 { 0 };
                int32_t id_1284 { repeat_n_430[id_1283] };
                int32_t id_1285 { 1L };
                int32_t id_1286 { int32_t(id_1284 + id_1285) };
                Void id_1287 { ((void)(repeat_n_430[id_1282] = id_1286), ::dessser::Void()) };
                (void)id_1287;
                (void)id_1287;
              }
            } while (while_flag_1260);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_1288 { 0 };
          Size id_1289 { sz_ref_429[id_1288] };
          let_res_1257 = id_1289;
        }
        Size let_res_1290;
        {
          Size sz_431 { let_res_1257 };
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1291 { (*p_0).detail };
          ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1292 { std::get<1 /* Failed */>(id_1291) };
          std::optional<dessser::gen::src_path::t_ext> id_1293 { id_1292.depends_on };
          bool id_1294 { !(id_1293.has_value ()) };
          Size choose_res_1295;
          if (id_1294) {
            Size id_1296 { 1UL };
            Size id_1297 { Size(sz_431 + id_1296) };
            choose_res_1295 = id_1297;
          } else {
            auto fun1298 { dessser::gen::src_path::sersize_of_row_binary };
            ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1299 { (*p_0).detail };
            ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1300 { std::get<1 /* Failed */>(id_1299) };
            std::optional<dessser::gen::src_path::t_ext> id_1301 { id_1300.depends_on };
            dessser::gen::src_path::t_ext id_1302 { id_1301.value() };
            Size id_1303 { fun1298(id_1302) };
            Size id_1304 { Size(sz_431 + id_1303) };
            Size id_1305 { 1UL };
            Size id_1306 { Size(id_1304 + id_1305) };
            choose_res_1295 = id_1306;
          }
          let_res_1290 = choose_res_1295;
        }
        choose_res_1215 = let_res_1290;
      }
      let_res_1210 = choose_res_1215;
    }
    return let_res_1210;
  }
   };
  return fun1101;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_57" (apply (ext-identifier function_name of-row-binary) (param 0))
        (let-pair "drec_fst_58" "drec_snd_59" (identifier "drec_57")
          (let "drec_63"
            (if (eq (peek-u8 (identifier "drec_snd_59") (size 0)) (u8 1)) 
              (make-tup (null "$retention") (ptr-add (identifier "drec_snd_59") (size 1)))
              (let-pair "make1_1_fst_61" "make1_1_snd_62" (apply (ext-identifier retention of-row-binary) (ptr-add (identifier "drec_snd_59") (size 1)))
                (make-tup (not-null (identifier "make1_1_fst_61")) (identifier "make1_1_snd_62"))))
            (let-pair "drec_fst_64" "drec_snd_65" (identifier "drec_63")
              (let "drec_69" (let-pair "dbool_fst_67" "dbool_snd_68" (read-u8 (identifier "drec_snd_65")) (make-tup (not (eq (identifier "dbool_fst_67") (u8 0))) (identifier "dbool_snd_68")))
                (let-pair "drec_fst_70" "drec_snd_71" (identifier "drec_69")
                  (let "drec_75"
                    (if (eq (peek-u8 (identifier "drec_snd_71") (size 0)) (u8 1)) 
                      (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_71") (size 1)))
                      (let-pair "make1_1_fst_73" "make1_1_snd_74" (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_71") (size 1)))
                        (make-tup (not-null (identifier "make1_1_fst_73")) (identifier "make1_1_snd_74"))))
                    (let-pair "drec_fst_76" "drec_snd_77" (identifier "drec_75")
                      (let "drec_90"
                        (let "dstring1_84"
                          (let "leb_ref_78" (make-vec (u32 0))
                            (let "shft_ref_79" (make-vec (u8 0))
                              (let "p_ref_80" (make-vec (identifier "drec_snd_77"))
                                (seq
                                  (while
                                    (let "leb128_81" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_80")))
                                      (let-pair "leb128_fst_82" "leb128_snd_83" 
                                        (identifier "leb128_81")
                                        (seq (set-vec (u8 0) (identifier "p_ref_80") (identifier "leb128_snd_83"))
                                          (set-vec (u8 0) (identifier "leb_ref_78")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_82") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_79"))) (unsafe-nth (u8 0) (identifier "leb_ref_78"))))
                                          (set-vec (u8 0) (identifier "shft_ref_79") (add (unsafe-nth (u8 0) (identifier "shft_ref_79")) (u8 7))) 
                                          (ge (identifier "leb128_fst_82") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_78"))) (unsafe-nth (u8 0) (identifier "p_ref_80")))))))
                          (let-pair "dstring1_fst_85" "dstring1_snd_86" 
                            (identifier "dstring1_84")
                            (let-pair "dstring2_fst_88" "dstring2_snd_89" 
                              (read-bytes (identifier "dstring1_snd_86") (identifier "dstring1_fst_85")) 
                              (make-tup (string-of-bytes (identifier "dstring2_fst_88")) (identifier "dstring2_snd_89")))))
                        (let-pair "drec_fst_91" "drec_snd_92" (identifier "drec_90")
                          (let "drec_93" (apply (ext-identifier raql_operation of-row-binary) (identifier "drec_snd_92"))
                            (let-pair "drec_fst_94" "drec_snd_95" (identifier "drec_93")
                              (let "drec_96" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_95"))
                                (let-pair "drec_fst_97" "drec_snd_98" 
                                  (identifier "drec_96")
                                  (let "drec_122"
                                    (let-pair "dlist4_fst_120" "dlist4_snd_121"
                                      (let "dlist1_108"
                                        (let "leb_ref_99" (make-vec (u32 0))
                                          (let "shft_ref_100" (make-vec (u8 0))
                                            (let "p_ref_101" (make-vec (identifier "drec_snd_98"))
                                              (seq
                                                (while
                                                  (let "leb128_102" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_101")))
                                                    (let-pair "leb128_fst_103" "leb128_snd_104" 
                                                      (identifier "leb128_102")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_101") (identifier "leb128_snd_104"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_99")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_103") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_100")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_99")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_100") (add (unsafe-nth (u8 0) (identifier "shft_ref_100")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_103") (u8 128))))) 
                                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_99")) (unsafe-nth (u8 0) (identifier "p_ref_101")))))))
                                        (let-pair "dlist1_fst_109" "dlist1_snd_110" 
                                          (identifier "dlist1_108")
                                          (let "inits_src_ref_111" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_110")))
                                            (seq
                                              (let "repeat_n_112" (make-vec (i32 0))
                                                (while (gt (to-i32 (identifier "dlist1_fst_109")) (unsafe-nth (u8 0) (identifier "repeat_n_112")))
                                                  (seq
                                                    (let "dlist2_113" 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_111"))
                                                      (let-pair "dlist2_fst_114" "dlist2_snd_115" 
                                                        (identifier "dlist2_113")
                                                        (set-vec (u8 0) 
                                                          (identifier "inits_src_ref_111")
                                                          (let-pair "dlist3_fst_117" "dlist3_snd_118" 
                                                            (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_115"))
                                                            (make-tup (cons (identifier "dlist3_fst_117") (identifier "dlist2_fst_114")) (identifier "dlist3_snd_118"))))))
                                                    (set-vec (u8 0) (identifier "repeat_n_112") (add (unsafe-nth (u8 0) (identifier "repeat_n_112")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_111")))))) 
                                      (make-tup (identity (identifier "dlist4_fst_120")) (identifier "dlist4_snd_121")))
                                    (let-pair "drec_fst_123" "drec_snd_124" 
                                      (identifier "drec_122")
                                      (let "drec_137"
                                        (let "dstring1_131"
                                          (let "leb_ref_125" (make-vec (u32 0))
                                            (let "shft_ref_126" (make-vec (u8 0))
                                              (let "p_ref_127" (make-vec (identifier "drec_snd_124"))
                                                (seq
                                                  (while
                                                    (let "leb128_128" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_127")))
                                                      (let-pair "leb128_fst_129" "leb128_snd_130" 
                                                        (identifier "leb128_128")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_127") (identifier "leb128_snd_130"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_125")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_129") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_126")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_125")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_126") (add (unsafe-nth (u8 0) (identifier "shft_ref_126")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_129") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_125"))) (unsafe-nth (u8 0) (identifier "p_ref_127")))))))
                                          (let-pair "dstring1_fst_132" "dstring1_snd_133" 
                                            (identifier "dstring1_131")
                                            (let-pair "dstring2_fst_135" "dstring2_snd_136" 
                                              (read-bytes (identifier "dstring1_snd_133") (identifier "dstring1_fst_132")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_135")) (identifier "dstring2_snd_136")))))
                                        (let-pair "drec_fst_138" "drec_snd_139" 
                                          (identifier "drec_137")
                                          (let "dstring1_146"
                                            (let "leb_ref_140" (make-vec (u32 0))
                                              (let "shft_ref_141" (make-vec (u8 0))
                                                (let "p_ref_142" (make-vec (identifier "drec_snd_139"))
                                                  (seq
                                                    (while
                                                      (let "leb128_143" 
                                                        (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_142")))
                                                        (let-pair "leb128_fst_144" "leb128_snd_145" 
                                                          (identifier "leb128_143")
                                                          (seq (set-vec (u8 0) (identifier "p_ref_142") (identifier "leb128_snd_145"))
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb_ref_140")
                                                              (bit-or 
                                                                (left-shift (to-u32 (bit-and (identifier "leb128_fst_144") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_141")))
                                                                (unsafe-nth (u8 0) (identifier "leb_ref_140")))) 
                                                            (set-vec (u8 0) (identifier "shft_ref_141") (add (unsafe-nth (u8 0) (identifier "shft_ref_141")) (u8 7))) 
                                                            (ge (identifier "leb128_fst_144") (u8 128))))) 
                                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_140"))) (unsafe-nth (u8 0) (identifier "p_ref_142")))))))
                                            (let-pair "dstring1_fst_147" "dstring1_snd_148" 
                                              (identifier "dstring1_146")
                                              (let-pair "dstring2_fst_150" "dstring2_snd_151" 
                                                (read-bytes (identifier "dstring1_snd_148") (identifier "dstring1_fst_147"))
                                                (make-tup
                                                  (make-rec (string "in_signature") 
                                                    (string-of-bytes (identifier "dstring2_fst_150")) 
                                                    (string "signature") 
                                                    (identifier "drec_fst_138") 
                                                    (string "factors") 
                                                    (identifier "drec_fst_123") 
                                                    (string "out_record") 
                                                    (identifier "drec_fst_97") 
                                                    (string "operation") 
                                                    (identifier "drec_fst_94") 
                                                    (string "doc") (identifier "drec_fst_91") 
                                                    (string "best_after") 
                                                    (identifier "drec_fst_76") 
                                                    (string "is_lazy") 
                                                    (identifier "drec_fst_70") 
                                                    (string "retention") 
                                                    (identifier "drec_fst_64") 
                                                    (string "name") (identifier "drec_fst_58")) 
                                                  (identifier "dstring2_snd_151"))))))))))))))))))))))))
 */
static std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> compiled_func_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> fun1307 { [&](Pointer p_0) {
    auto fun1308 { dessser::gen::function_name::of_row_binary };
    ::dessser::gen::source_info::t7ced0f6935c1265b26e1abfcc364f52e id_1309 { fun1308(p_0) };
    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1310;
    {
      ::dessser::gen::source_info::t7ced0f6935c1265b26e1abfcc364f52e drec_57 { id_1309 };
      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1311;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        Size id_1312 { 0UL };
        uint8_t id_1313 { drec_snd_59.peekU8(id_1312) };
        uint8_t id_1314 { 1 };
        bool id_1315 { bool(id_1313 == id_1314) };
        ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 choose_res_1316;
        if (id_1315) {
          std::optional<dessser::gen::retention::t_ext> id_1317 { std::nullopt };
          Size id_1318 { 1UL };
          Pointer id_1319 { drec_snd_59.skip(id_1318) };
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 id_1320 { id_1317, id_1319 };
          choose_res_1316 = id_1320;
        } else {
          auto fun1321 { dessser::gen::retention::of_row_binary };
          Size id_1322 { 1UL };
          Pointer id_1323 { drec_snd_59.skip(id_1322) };
          ::dessser::gen::source_info::tde821e6d031c399b029ea4a78810ecf6 id_1324 { fun1321(id_1323) };
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 letpair_res_1325;
          {
            auto make1_1_fst_61 { std::get<0>(id_1324) };
            auto make1_1_snd_62 { std::get<1>(id_1324) };
            std::optional<dessser::gen::retention::t_ext> id_1326 { make1_1_fst_61 };
            ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 id_1327 { id_1326, make1_1_snd_62 };
            letpair_res_1325 = id_1327;
          }
          choose_res_1316 = letpair_res_1325;
        }
        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1328;
        {
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 drec_63 { choose_res_1316 };
          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1329;
          {
            auto drec_fst_64 { std::get<0>(drec_63) };
            auto drec_snd_65 { std::get<1>(drec_63) };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1330 { drec_snd_65.readU8() };
            ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1331;
            {
              auto dbool_fst_67 { std::get<0>(id_1330) };
              auto dbool_snd_68 { std::get<1>(id_1330) };
              uint8_t id_1332 { 0 };
              bool id_1333 { bool(dbool_fst_67 == id_1332) };
              bool id_1334 { ! id_1333 };
              ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 id_1335 { id_1334, dbool_snd_68 };
              letpair_res_1331 = id_1335;
            }
            ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1336;
            {
              ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 drec_69 { letpair_res_1331 };
              ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1337;
              {
                auto drec_fst_70 { std::get<0>(drec_69) };
                auto drec_snd_71 { std::get<1>(drec_69) };
                Size id_1338 { 0UL };
                uint8_t id_1339 { drec_snd_71.peekU8(id_1338) };
                uint8_t id_1340 { 1 };
                bool id_1341 { bool(id_1339 == id_1340) };
                ::dessser::gen::source_info::tffcb9977d856d30366202f1b8eb57823 choose_res_1342;
                if (id_1341) {
                  std::optional<dessser::gen::raql_expr::t_ext> id_1343 { std::nullopt };
                  Size id_1344 { 1UL };
                  Pointer id_1345 { drec_snd_71.skip(id_1344) };
                  ::dessser::gen::source_info::tffcb9977d856d30366202f1b8eb57823 id_1346 { id_1343, id_1345 };
                  choose_res_1342 = id_1346;
                } else {
                  auto fun1347 { dessser::gen::raql_expr::of_row_binary };
                  Size id_1348 { 1UL };
                  Pointer id_1349 { drec_snd_71.skip(id_1348) };
                  ::dessser::gen::source_info::tc473a3a3b5068e57b15e934d0afcc038 id_1350 { fun1347(id_1349) };
                  ::dessser::gen::source_info::tffcb9977d856d30366202f1b8eb57823 letpair_res_1351;
                  {
                    auto make1_1_fst_73 { std::get<0>(id_1350) };
                    auto make1_1_snd_74 { std::get<1>(id_1350) };
                    std::optional<dessser::gen::raql_expr::t_ext> id_1352 { make1_1_fst_73 };
                    ::dessser::gen::source_info::tffcb9977d856d30366202f1b8eb57823 id_1353 { id_1352, make1_1_snd_74 };
                    letpair_res_1351 = id_1353;
                  }
                  choose_res_1342 = letpair_res_1351;
                }
                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1354;
                {
                  ::dessser::gen::source_info::tffcb9977d856d30366202f1b8eb57823 drec_75 { choose_res_1342 };
                  ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1355;
                  {
                    auto drec_fst_76 { std::get<0>(drec_75) };
                    auto drec_snd_77 { std::get<1>(drec_75) };
                    uint32_t id_1356 { 0U };
                    Vec<1, uint32_t> id_1357 {  id_1356  };
                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1358;
                    {
                      Vec<1, uint32_t> leb_ref_78 { id_1357 };
                      uint8_t id_1359 { 0 };
                      Vec<1, uint8_t> id_1360 {  id_1359  };
                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1361;
                      {
                        Vec<1, uint8_t> shft_ref_79 { id_1360 };
                        Vec<1, Pointer> id_1362 {  drec_snd_77  };
                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1363;
                        {
                          Vec<1, Pointer> p_ref_80 { id_1362 };
                          bool while_flag_1364 { true };
                          do {
                            uint8_t id_1365 { 0 };
                            Pointer id_1366 { p_ref_80[id_1365] };
                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1367 { id_1366.readU8() };
                            bool let_res_1368;
                            {
                              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_81 { id_1367 };
                              bool letpair_res_1369;
                              {
                                auto leb128_fst_82 { std::get<0>(leb128_81) };
                                auto leb128_snd_83 { std::get<1>(leb128_81) };
                                uint8_t id_1370 { 0 };
                                Void id_1371 { ((void)(p_ref_80[id_1370] = leb128_snd_83), ::dessser::Void()) };
                                (void)id_1371;
                                uint8_t id_1372 { 0 };
                                uint8_t id_1373 { 127 };
                                uint8_t id_1374 { uint8_t(leb128_fst_82 & id_1373) };
                                uint32_t id_1375 { uint32_t(id_1374) };
                                uint8_t id_1376 { 0 };
                                uint8_t id_1377 { shft_ref_79[id_1376] };
                                uint32_t id_1378 { uint32_t(id_1375 << id_1377) };
                                uint8_t id_1379 { 0 };
                                uint32_t id_1380 { leb_ref_78[id_1379] };
                                uint32_t id_1381 { uint32_t(id_1378 | id_1380) };
                                Void id_1382 { ((void)(leb_ref_78[id_1372] = id_1381), ::dessser::Void()) };
                                (void)id_1382;
                                uint8_t id_1383 { 0 };
                                uint8_t id_1384 { 0 };
                                uint8_t id_1385 { shft_ref_79[id_1384] };
                                uint8_t id_1386 { 7 };
                                uint8_t id_1387 { uint8_t(id_1385 + id_1386) };
                                Void id_1388 { ((void)(shft_ref_79[id_1383] = id_1387), ::dessser::Void()) };
                                (void)id_1388;
                                uint8_t id_1389 { 128 };
                                bool id_1390 { bool(leb128_fst_82 >= id_1389) };
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
                          uint32_t id_1392 { leb_ref_78[id_1391] };
                          Size id_1393 { Size(id_1392) };
                          uint8_t id_1394 { 0 };
                          Pointer id_1395 { p_ref_80[id_1394] };
                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1396 { id_1393, id_1395 };
                          let_res_1363 = id_1396;
                        }
                        let_res_1361 = let_res_1363;
                      }
                      let_res_1358 = let_res_1361;
                    }
                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1397;
                    {
                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_84 { let_res_1358 };
                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1398;
                      {
                        auto dstring1_fst_85 { std::get<0>(dstring1_84) };
                        auto dstring1_snd_86 { std::get<1>(dstring1_84) };
                        ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1399 { dstring1_snd_86.readBytes(dstring1_fst_85) };
                        ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1400;
                        {
                          auto dstring2_fst_88 { std::get<0>(id_1399) };
                          auto dstring2_snd_89 { std::get<1>(id_1399) };
                          std::string id_1401 { dstring2_fst_88.toString() };
                          ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1402 { id_1401, dstring2_snd_89 };
                          letpair_res_1400 = id_1402;
                        }
                        letpair_res_1398 = letpair_res_1400;
                      }
                      let_res_1397 = letpair_res_1398;
                    }
                    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1403;
                    {
                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_90 { let_res_1397 };
                      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1404;
                      {
                        auto drec_fst_91 { std::get<0>(drec_90) };
                        auto drec_snd_92 { std::get<1>(drec_90) };
                        auto fun1405 { dessser::gen::raql_operation::of_row_binary };
                        ::dessser::gen::source_info::t9539d836e50d2481333b4e3eeeadf0ff id_1406 { fun1405(drec_snd_92) };
                        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1407;
                        {
                          ::dessser::gen::source_info::t9539d836e50d2481333b4e3eeeadf0ff drec_93 { id_1406 };
                          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1408;
                          {
                            auto drec_fst_94 { std::get<0>(drec_93) };
                            auto drec_snd_95 { std::get<1>(drec_93) };
                            auto fun1409 { dessser::gen::raql_type::of_row_binary };
                            ::dessser::gen::source_info::t101502ffd7fb38beafe4b49259f92ba1 id_1410 { fun1409(drec_snd_95) };
                            ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1411;
                            {
                              ::dessser::gen::source_info::t101502ffd7fb38beafe4b49259f92ba1 drec_96 { id_1410 };
                              ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1412;
                              {
                                auto drec_fst_97 { std::get<0>(drec_96) };
                                auto drec_snd_98 { std::get<1>(drec_96) };
                                uint32_t id_1413 { 0U };
                                Vec<1, uint32_t> id_1414 {  id_1413  };
                                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1415;
                                {
                                  Vec<1, uint32_t> leb_ref_99 { id_1414 };
                                  uint8_t id_1416 { 0 };
                                  Vec<1, uint8_t> id_1417 {  id_1416  };
                                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1418;
                                  {
                                    Vec<1, uint8_t> shft_ref_100 { id_1417 };
                                    Vec<1, Pointer> id_1419 {  drec_snd_98  };
                                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1420;
                                    {
                                      Vec<1, Pointer> p_ref_101 { id_1419 };
                                      bool while_flag_1421 { true };
                                      do {
                                        uint8_t id_1422 { 0 };
                                        Pointer id_1423 { p_ref_101[id_1422] };
                                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1424 { id_1423.readU8() };
                                        bool let_res_1425;
                                        {
                                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_102 { id_1424 };
                                          bool letpair_res_1426;
                                          {
                                            auto leb128_fst_103 { std::get<0>(leb128_102) };
                                            auto leb128_snd_104 { std::get<1>(leb128_102) };
                                            uint8_t id_1427 { 0 };
                                            Void id_1428 { ((void)(p_ref_101[id_1427] = leb128_snd_104), ::dessser::Void()) };
                                            (void)id_1428;
                                            uint8_t id_1429 { 0 };
                                            uint8_t id_1430 { 127 };
                                            uint8_t id_1431 { uint8_t(leb128_fst_103 & id_1430) };
                                            uint32_t id_1432 { uint32_t(id_1431) };
                                            uint8_t id_1433 { 0 };
                                            uint8_t id_1434 { shft_ref_100[id_1433] };
                                            uint32_t id_1435 { uint32_t(id_1432 << id_1434) };
                                            uint8_t id_1436 { 0 };
                                            uint32_t id_1437 { leb_ref_99[id_1436] };
                                            uint32_t id_1438 { uint32_t(id_1435 | id_1437) };
                                            Void id_1439 { ((void)(leb_ref_99[id_1429] = id_1438), ::dessser::Void()) };
                                            (void)id_1439;
                                            uint8_t id_1440 { 0 };
                                            uint8_t id_1441 { 0 };
                                            uint8_t id_1442 { shft_ref_100[id_1441] };
                                            uint8_t id_1443 { 7 };
                                            uint8_t id_1444 { uint8_t(id_1442 + id_1443) };
                                            Void id_1445 { ((void)(shft_ref_100[id_1440] = id_1444), ::dessser::Void()) };
                                            (void)id_1445;
                                            uint8_t id_1446 { 128 };
                                            bool id_1447 { bool(leb128_fst_103 >= id_1446) };
                                            letpair_res_1426 = id_1447;
                                          }
                                          let_res_1425 = letpair_res_1426;
                                        }
                                        while_flag_1421 = let_res_1425;
                                        if (while_flag_1421) {
                                          (void)::dessser::Void();
                                        }
                                      } while (while_flag_1421);
                                      (void)::dessser::Void();
                                      uint8_t id_1448 { 0 };
                                      uint32_t id_1449 { leb_ref_99[id_1448] };
                                      uint8_t id_1450 { 0 };
                                      Pointer id_1451 { p_ref_101[id_1450] };
                                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1452 { id_1449, id_1451 };
                                      let_res_1420 = id_1452;
                                    }
                                    let_res_1418 = let_res_1420;
                                  }
                                  let_res_1415 = let_res_1418;
                                }
                                ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1453;
                                {
                                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_108 { let_res_1415 };
                                  ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1454;
                                  {
                                    auto dlist1_fst_109 { std::get<0>(dlist1_108) };
                                    auto dlist1_snd_110 { std::get<1>(dlist1_108) };
                                    Lst<dessser::gen::field_name::t_ext> endoflist_1455;
                                    ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1456 { endoflist_1455, dlist1_snd_110 };
                                    Vec<1, ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1457 {  id_1456  };
                                    ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1458;
                                    {
                                      Vec<1, ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_111 { id_1457 };
                                      int32_t id_1459 { 0L };
                                      Vec<1, int32_t> id_1460 {  id_1459  };
                                      {
                                        Vec<1, int32_t> repeat_n_112 { id_1460 };
                                        bool while_flag_1461 { true };
                                        do {
                                          int32_t id_1462 { int32_t(dlist1_fst_109) };
                                          uint8_t id_1463 { 0 };
                                          int32_t id_1464 { repeat_n_112[id_1463] };
                                          bool id_1465 { bool(id_1462 > id_1464) };
                                          while_flag_1461 = id_1465;
                                          if (while_flag_1461) {
                                            uint8_t id_1466 { 0 };
                                            ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1467 { inits_src_ref_111[id_1466] };
                                            {
                                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_113 { id_1467 };
                                              {
                                                auto dlist2_fst_114 { std::get<0>(dlist2_113) };
                                                auto dlist2_snd_115 { std::get<1>(dlist2_113) };
                                                uint8_t id_1468 { 0 };
                                                auto fun1469 { dessser::gen::field_name::of_row_binary };
                                                ::dessser::gen::source_info::t18cecf882d7ac80cef37dfe6b22279d4 id_1470 { fun1469(dlist2_snd_115) };
                                                ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1471;
                                                {
                                                  auto dlist3_fst_117 { std::get<0>(id_1470) };
                                                  auto dlist3_snd_118 { std::get<1>(id_1470) };
                                                  Lst<dessser::gen::field_name::t_ext> id_1472 { dlist3_fst_117, dlist2_fst_114 };
                                                  ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1473 { id_1472, dlist3_snd_118 };
                                                  letpair_res_1471 = id_1473;
                                                }
                                                Void id_1474 { ((void)(inits_src_ref_111[id_1468] = letpair_res_1471), ::dessser::Void()) };
                                                (void)id_1474;
                                              }
                                              (void)::dessser::Void();
                                            }
                                            (void)::dessser::Void();
                                            uint8_t id_1475 { 0 };
                                            uint8_t id_1476 { 0 };
                                            int32_t id_1477 { repeat_n_112[id_1476] };
                                            int32_t id_1478 { 1L };
                                            int32_t id_1479 { int32_t(id_1477 + id_1478) };
                                            Void id_1480 { ((void)(repeat_n_112[id_1475] = id_1479), ::dessser::Void()) };
                                            (void)id_1480;
                                            (void)id_1480;
                                          }
                                        } while (while_flag_1461);
                                        (void)::dessser::Void();
                                      }
                                      (void)::dessser::Void();
                                      uint8_t id_1481 { 0 };
                                      ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1482 { inits_src_ref_111[id_1481] };
                                      let_res_1458 = id_1482;
                                    }
                                    letpair_res_1454 = let_res_1458;
                                  }
                                  let_res_1453 = letpair_res_1454;
                                }
                                ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1483;
                                {
                                  auto dlist4_fst_120 { std::get<0>(let_res_1453) };
                                  auto dlist4_snd_121 { std::get<1>(let_res_1453) };
                                  ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1484 { dlist4_fst_120, dlist4_snd_121 };
                                  letpair_res_1483 = id_1484;
                                }
                                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1485;
                                {
                                  ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 drec_122 { letpair_res_1483 };
                                  ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1486;
                                  {
                                    auto drec_fst_123 { std::get<0>(drec_122) };
                                    auto drec_snd_124 { std::get<1>(drec_122) };
                                    uint32_t id_1487 { 0U };
                                    Vec<1, uint32_t> id_1488 {  id_1487  };
                                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1489;
                                    {
                                      Vec<1, uint32_t> leb_ref_125 { id_1488 };
                                      uint8_t id_1490 { 0 };
                                      Vec<1, uint8_t> id_1491 {  id_1490  };
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1492;
                                      {
                                        Vec<1, uint8_t> shft_ref_126 { id_1491 };
                                        Vec<1, Pointer> id_1493 {  drec_snd_124  };
                                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1494;
                                        {
                                          Vec<1, Pointer> p_ref_127 { id_1493 };
                                          bool while_flag_1495 { true };
                                          do {
                                            uint8_t id_1496 { 0 };
                                            Pointer id_1497 { p_ref_127[id_1496] };
                                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1498 { id_1497.readU8() };
                                            bool let_res_1499;
                                            {
                                              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_128 { id_1498 };
                                              bool letpair_res_1500;
                                              {
                                                auto leb128_fst_129 { std::get<0>(leb128_128) };
                                                auto leb128_snd_130 { std::get<1>(leb128_128) };
                                                uint8_t id_1501 { 0 };
                                                Void id_1502 { ((void)(p_ref_127[id_1501] = leb128_snd_130), ::dessser::Void()) };
                                                (void)id_1502;
                                                uint8_t id_1503 { 0 };
                                                uint8_t id_1504 { 127 };
                                                uint8_t id_1505 { uint8_t(leb128_fst_129 & id_1504) };
                                                uint32_t id_1506 { uint32_t(id_1505) };
                                                uint8_t id_1507 { 0 };
                                                uint8_t id_1508 { shft_ref_126[id_1507] };
                                                uint32_t id_1509 { uint32_t(id_1506 << id_1508) };
                                                uint8_t id_1510 { 0 };
                                                uint32_t id_1511 { leb_ref_125[id_1510] };
                                                uint32_t id_1512 { uint32_t(id_1509 | id_1511) };
                                                Void id_1513 { ((void)(leb_ref_125[id_1503] = id_1512), ::dessser::Void()) };
                                                (void)id_1513;
                                                uint8_t id_1514 { 0 };
                                                uint8_t id_1515 { 0 };
                                                uint8_t id_1516 { shft_ref_126[id_1515] };
                                                uint8_t id_1517 { 7 };
                                                uint8_t id_1518 { uint8_t(id_1516 + id_1517) };
                                                Void id_1519 { ((void)(shft_ref_126[id_1514] = id_1518), ::dessser::Void()) };
                                                (void)id_1519;
                                                uint8_t id_1520 { 128 };
                                                bool id_1521 { bool(leb128_fst_129 >= id_1520) };
                                                letpair_res_1500 = id_1521;
                                              }
                                              let_res_1499 = letpair_res_1500;
                                            }
                                            while_flag_1495 = let_res_1499;
                                            if (while_flag_1495) {
                                              (void)::dessser::Void();
                                            }
                                          } while (while_flag_1495);
                                          (void)::dessser::Void();
                                          uint8_t id_1522 { 0 };
                                          uint32_t id_1523 { leb_ref_125[id_1522] };
                                          Size id_1524 { Size(id_1523) };
                                          uint8_t id_1525 { 0 };
                                          Pointer id_1526 { p_ref_127[id_1525] };
                                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1527 { id_1524, id_1526 };
                                          let_res_1494 = id_1527;
                                        }
                                        let_res_1492 = let_res_1494;
                                      }
                                      let_res_1489 = let_res_1492;
                                    }
                                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1528;
                                    {
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_131 { let_res_1489 };
                                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1529;
                                      {
                                        auto dstring1_fst_132 { std::get<0>(dstring1_131) };
                                        auto dstring1_snd_133 { std::get<1>(dstring1_131) };
                                        ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1530 { dstring1_snd_133.readBytes(dstring1_fst_132) };
                                        ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1531;
                                        {
                                          auto dstring2_fst_135 { std::get<0>(id_1530) };
                                          auto dstring2_snd_136 { std::get<1>(id_1530) };
                                          std::string id_1532 { dstring2_fst_135.toString() };
                                          ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1533 { id_1532, dstring2_snd_136 };
                                          letpair_res_1531 = id_1533;
                                        }
                                        letpair_res_1529 = letpair_res_1531;
                                      }
                                      let_res_1528 = letpair_res_1529;
                                    }
                                    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1534;
                                    {
                                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_137 { let_res_1528 };
                                      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1535;
                                      {
                                        auto drec_fst_138 { std::get<0>(drec_137) };
                                        auto drec_snd_139 { std::get<1>(drec_137) };
                                        uint32_t id_1536 { 0U };
                                        Vec<1, uint32_t> id_1537 {  id_1536  };
                                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1538;
                                        {
                                          Vec<1, uint32_t> leb_ref_140 { id_1537 };
                                          uint8_t id_1539 { 0 };
                                          Vec<1, uint8_t> id_1540 {  id_1539  };
                                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1541;
                                          {
                                            Vec<1, uint8_t> shft_ref_141 { id_1540 };
                                            Vec<1, Pointer> id_1542 {  drec_snd_139  };
                                            ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1543;
                                            {
                                              Vec<1, Pointer> p_ref_142 { id_1542 };
                                              bool while_flag_1544 { true };
                                              do {
                                                uint8_t id_1545 { 0 };
                                                Pointer id_1546 { p_ref_142[id_1545] };
                                                ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1547 { id_1546.readU8() };
                                                bool let_res_1548;
                                                {
                                                  ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_143 { id_1547 };
                                                  bool letpair_res_1549;
                                                  {
                                                    auto leb128_fst_144 { std::get<0>(leb128_143) };
                                                    auto leb128_snd_145 { std::get<1>(leb128_143) };
                                                    uint8_t id_1550 { 0 };
                                                    Void id_1551 { ((void)(p_ref_142[id_1550] = leb128_snd_145), ::dessser::Void()) };
                                                    (void)id_1551;
                                                    uint8_t id_1552 { 0 };
                                                    uint8_t id_1553 { 127 };
                                                    uint8_t id_1554 { uint8_t(leb128_fst_144 & id_1553) };
                                                    uint32_t id_1555 { uint32_t(id_1554) };
                                                    uint8_t id_1556 { 0 };
                                                    uint8_t id_1557 { shft_ref_141[id_1556] };
                                                    uint32_t id_1558 { uint32_t(id_1555 << id_1557) };
                                                    uint8_t id_1559 { 0 };
                                                    uint32_t id_1560 { leb_ref_140[id_1559] };
                                                    uint32_t id_1561 { uint32_t(id_1558 | id_1560) };
                                                    Void id_1562 { ((void)(leb_ref_140[id_1552] = id_1561), ::dessser::Void()) };
                                                    (void)id_1562;
                                                    uint8_t id_1563 { 0 };
                                                    uint8_t id_1564 { 0 };
                                                    uint8_t id_1565 { shft_ref_141[id_1564] };
                                                    uint8_t id_1566 { 7 };
                                                    uint8_t id_1567 { uint8_t(id_1565 + id_1566) };
                                                    Void id_1568 { ((void)(shft_ref_141[id_1563] = id_1567), ::dessser::Void()) };
                                                    (void)id_1568;
                                                    uint8_t id_1569 { 128 };
                                                    bool id_1570 { bool(leb128_fst_144 >= id_1569) };
                                                    letpair_res_1549 = id_1570;
                                                  }
                                                  let_res_1548 = letpair_res_1549;
                                                }
                                                while_flag_1544 = let_res_1548;
                                                if (while_flag_1544) {
                                                  (void)::dessser::Void();
                                                }
                                              } while (while_flag_1544);
                                              (void)::dessser::Void();
                                              uint8_t id_1571 { 0 };
                                              uint32_t id_1572 { leb_ref_140[id_1571] };
                                              Size id_1573 { Size(id_1572) };
                                              uint8_t id_1574 { 0 };
                                              Pointer id_1575 { p_ref_142[id_1574] };
                                              ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1576 { id_1573, id_1575 };
                                              let_res_1543 = id_1576;
                                            }
                                            let_res_1541 = let_res_1543;
                                          }
                                          let_res_1538 = let_res_1541;
                                        }
                                        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1577;
                                        {
                                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_146 { let_res_1538 };
                                          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1578;
                                          {
                                            auto dstring1_fst_147 { std::get<0>(dstring1_146) };
                                            auto dstring1_snd_148 { std::get<1>(dstring1_146) };
                                            ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1579 { dstring1_snd_148.readBytes(dstring1_fst_147) };
                                            ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1580;
                                            {
                                              auto dstring2_fst_150 { std::get<0>(id_1579) };
                                              auto dstring2_snd_151 { std::get<1>(id_1579) };
                                              std::string id_1581 { dstring2_fst_150.toString() };
                                              std::shared_ptr<::dessser::gen::source_info::compiled_func>  id_1582 { std::make_shared<::dessser::gen::source_info::compiled_func>(drec_fst_58, drec_fst_64, drec_fst_70, drec_fst_76, drec_fst_91, drec_fst_94, drec_fst_97, drec_fst_123, drec_fst_138, id_1581) };
                                              ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be id_1583 { id_1582, dstring2_snd_151 };
                                              letpair_res_1580 = id_1583;
                                            }
                                            letpair_res_1578 = letpair_res_1580;
                                          }
                                          let_res_1577 = letpair_res_1578;
                                        }
                                        letpair_res_1535 = let_res_1577;
                                      }
                                      let_res_1534 = letpair_res_1535;
                                    }
                                    letpair_res_1486 = let_res_1534;
                                  }
                                  let_res_1485 = letpair_res_1486;
                                }
                                letpair_res_1412 = let_res_1485;
                              }
                              let_res_1411 = letpair_res_1412;
                            }
                            letpair_res_1408 = let_res_1411;
                          }
                          let_res_1407 = letpair_res_1408;
                        }
                        letpair_res_1404 = let_res_1407;
                      }
                      let_res_1403 = letpair_res_1404;
                    }
                    letpair_res_1355 = let_res_1403;
                  }
                  let_res_1354 = letpair_res_1355;
                }
                letpair_res_1337 = let_res_1354;
              }
              let_res_1336 = letpair_res_1337;
            }
            letpair_res_1329 = let_res_1336;
          }
          let_res_1328 = letpair_res_1329;
        }
        letpair_res_1311 = let_res_1328;
      }
      let_res_1310 = letpair_res_1311;
    }
    return let_res_1310;
  }
   };
  return fun1307;
}
std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> compiled_func_of_row_binary(compiled_func_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_178"
        (let-pair "dlist4_fst_176" "dlist4_snd_177"
          (let "dlist1_164"
            (let "leb_ref_155" (make-vec (u32 0))
              (let "shft_ref_156" (make-vec (u8 0))
                (let "p_ref_157" (make-vec (param 0))
                  (seq
                    (while
                      (let "leb128_158" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_157")))
                        (let-pair "leb128_fst_159" "leb128_snd_160" (identifier "leb128_158")
                          (seq (set-vec (u8 0) (identifier "p_ref_157") (identifier "leb128_snd_160"))
                            (set-vec (u8 0) (identifier "leb_ref_155")
                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_159") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_156"))) (unsafe-nth (u8 0) (identifier "leb_ref_155"))))
                            (set-vec (u8 0) (identifier "shft_ref_156") (add (unsafe-nth (u8 0) (identifier "shft_ref_156")) (u8 7))) 
                            (ge (identifier "leb128_fst_159") (u8 128))))) 
                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_155")) (unsafe-nth (u8 0) (identifier "p_ref_157")))))))
            (let-pair "dlist1_fst_165" "dlist1_snd_166" (identifier "dlist1_164")
              (let "inits_src_ref_167" (make-vec (make-tup (end-of-list "$program_parameter") (identifier "dlist1_snd_166")))
                (seq
                  (let "repeat_n_168" (make-vec (i32 0))
                    (while (gt (to-i32 (identifier "dlist1_fst_165")) (unsafe-nth (u8 0) (identifier "repeat_n_168")))
                      (seq
                        (let "dlist2_169" (unsafe-nth (u8 0) (identifier "inits_src_ref_167"))
                          (let-pair "dlist2_fst_170" "dlist2_snd_171" 
                            (identifier "dlist2_169")
                            (set-vec (u8 0) (identifier "inits_src_ref_167")
                              (let-pair "dlist3_fst_173" "dlist3_snd_174" 
                                (apply (ext-identifier program_parameter of-row-binary) (identifier "dlist2_snd_171")) 
                                (make-tup (cons (identifier "dlist3_fst_173") (identifier "dlist2_fst_170")) (identifier "dlist3_snd_174"))))))
                        (set-vec (u8 0) (identifier "repeat_n_168") (add (unsafe-nth (u8 0) (identifier "repeat_n_168")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "inits_src_ref_167")))))) 
          (make-tup (identity (identifier "dlist4_fst_176")) (identifier "dlist4_snd_177")))
        (let-pair "drec_fst_179" "drec_snd_180" (identifier "drec_178")
          (let "drec_181" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_180"))
            (let-pair "drec_fst_182" "drec_snd_183" (identifier "drec_181")
              (let "drec_207"
                (let-pair "dlist4_fst_205" "dlist4_snd_206"
                  (let "dlist1_193"
                    (let "leb_ref_184" (make-vec (u32 0))
                      (let "shft_ref_185" (make-vec (u8 0))
                        (let "p_ref_186" (make-vec (identifier "drec_snd_183"))
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
                    (let-pair "dlist1_fst_194" "dlist1_snd_195" (identifier "dlist1_193")
                      (let "inits_src_ref_196" (make-vec (make-tup (end-of-list "$global_variable") (identifier "dlist1_snd_195")))
                        (seq
                          (let "repeat_n_197" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_194")) (unsafe-nth (u8 0) (identifier "repeat_n_197")))
                              (seq
                                (let "dlist2_198" (unsafe-nth (u8 0) (identifier "inits_src_ref_196"))
                                  (let-pair "dlist2_fst_199" "dlist2_snd_200" 
                                    (identifier "dlist2_198")
                                    (set-vec (u8 0) (identifier "inits_src_ref_196")
                                      (let-pair "dlist3_fst_202" "dlist3_snd_203" 
                                        (apply (ext-identifier global_variable of-row-binary) (identifier "dlist2_snd_200"))
                                        (make-tup (cons (identifier "dlist3_fst_202") (identifier "dlist2_fst_199")) (identifier "dlist3_snd_203"))))))
                                (set-vec (u8 0) (identifier "repeat_n_197") (add (unsafe-nth (u8 0) (identifier "repeat_n_197")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_196")))))) 
                  (make-tup (identity (identifier "dlist4_fst_205")) (identifier "dlist4_snd_206")))
                (let-pair "drec_fst_208" "drec_snd_209" (identifier "drec_207")
                  (let "drec_233"
                    (let-pair "dlist4_fst_231" "dlist4_snd_232"
                      (let "dlist1_219"
                        (let "leb_ref_210" (make-vec (u32 0))
                          (let "shft_ref_211" (make-vec (u8 0))
                            (let "p_ref_212" (make-vec (identifier "drec_snd_209"))
                              (seq
                                (while
                                  (let "leb128_213" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_212")))
                                    (let-pair "leb128_fst_214" "leb128_snd_215" 
                                      (identifier "leb128_213")
                                      (seq (set-vec (u8 0) (identifier "p_ref_212") (identifier "leb128_snd_215"))
                                        (set-vec (u8 0) (identifier "leb_ref_210")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_214") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_211"))) (unsafe-nth (u8 0) (identifier "leb_ref_210"))))
                                        (set-vec (u8 0) (identifier "shft_ref_211") (add (unsafe-nth (u8 0) (identifier "shft_ref_211")) (u8 7))) 
                                        (ge (identifier "leb128_fst_214") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_210")) (unsafe-nth (u8 0) (identifier "p_ref_212")))))))
                        (let-pair "dlist1_fst_220" "dlist1_snd_221" (identifier "dlist1_219")
                          (let "inits_src_ref_222"
                            (make-vec
                              (make-tup
                                (end-of-list "(compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})")
                                (identifier "dlist1_snd_221")))
                            (seq
                              (let "repeat_n_223" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_220")) (unsafe-nth (u8 0) (identifier "repeat_n_223")))
                                  (seq
                                    (let "dlist2_224" (unsafe-nth (u8 0) (identifier "inits_src_ref_222"))
                                      (let-pair "dlist2_fst_225" "dlist2_snd_226" 
                                        (identifier "dlist2_224")
                                        (set-vec (u8 0) (identifier "inits_src_ref_222")
                                          (let-pair "dlist3_fst_228" "dlist3_snd_229" 
                                            (apply (identifier "compiled_func-of-row-binary") (identifier "dlist2_snd_226"))
                                            (make-tup (cons (identifier "dlist3_fst_228") (identifier "dlist2_fst_225")) (identifier "dlist3_snd_229"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_223") (add (unsafe-nth (u8 0) (identifier "repeat_n_223")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_222")))))) 
                      (make-tup (identity (identifier "dlist4_fst_231")) (identifier "dlist4_snd_232")))
                    (let-pair "drec_fst_234" "drec_snd_235" (identifier "drec_233")
                      (let-pair "dlist4_fst_257" "dlist4_snd_258"
                        (let "dlist1_245"
                          (let "leb_ref_236" (make-vec (u32 0))
                            (let "shft_ref_237" (make-vec (u8 0))
                              (let "p_ref_238" (make-vec (identifier "drec_snd_235"))
                                (seq
                                  (while
                                    (let "leb128_239" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_238")))
                                      (let-pair "leb128_fst_240" "leb128_snd_241" 
                                        (identifier "leb128_239")
                                        (seq (set-vec (u8 0) (identifier "p_ref_238") (identifier "leb128_snd_241"))
                                          (set-vec (u8 0) (identifier "leb_ref_236")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_240") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_237"))) (unsafe-nth (u8 0) (identifier "leb_ref_236"))))
                                          (set-vec (u8 0) (identifier "shft_ref_237") (add (unsafe-nth (u8 0) (identifier "shft_ref_237")) (u8 7))) 
                                          (ge (identifier "leb128_fst_240") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_236")) (unsafe-nth (u8 0) (identifier "p_ref_238")))))))
                          (let-pair "dlist1_fst_246" "dlist1_snd_247" 
                            (identifier "dlist1_245")
                            (let "inits_src_ref_248" (make-vec (make-tup (end-of-list "$raql_warning") (identifier "dlist1_snd_247")))
                              (seq
                                (let "repeat_n_249" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_246")) (unsafe-nth (u8 0) (identifier "repeat_n_249")))
                                    (seq
                                      (let "dlist2_250" (unsafe-nth (u8 0) (identifier "inits_src_ref_248"))
                                        (let-pair "dlist2_fst_251" "dlist2_snd_252" 
                                          (identifier "dlist2_250")
                                          (set-vec (u8 0) (identifier "inits_src_ref_248")
                                            (let-pair "dlist3_fst_254" "dlist3_snd_255" 
                                              (apply (ext-identifier raql_warning of-row-binary) (identifier "dlist2_snd_252"))
                                              (make-tup (cons (identifier "dlist3_fst_254") (identifier "dlist2_fst_251")) (identifier "dlist3_snd_255"))))))
                                      (set-vec (u8 0) (identifier "repeat_n_249") (add (unsafe-nth (u8 0) (identifier "repeat_n_249")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_248"))))))
                        (make-tup
                          (make-rec (string "warnings") (identity (identifier "dlist4_fst_257")) 
                            (string "funcs") (identifier "drec_fst_234") 
                            (string "globals") (identifier "drec_fst_208") 
                            (string "condition") (identifier "drec_fst_182") 
                            (string "default_params") (identifier "drec_fst_179")) 
                          (identifier "dlist4_snd_258"))))))))))))
 */
static std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> compiled_program_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> fun1584 { [&](Pointer p_0) {
    uint32_t id_1585 { 0U };
    Vec<1, uint32_t> id_1586 {  id_1585  };
    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1587;
    {
      Vec<1, uint32_t> leb_ref_155 { id_1586 };
      uint8_t id_1588 { 0 };
      Vec<1, uint8_t> id_1589 {  id_1588  };
      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1590;
      {
        Vec<1, uint8_t> shft_ref_156 { id_1589 };
        Vec<1, Pointer> id_1591 {  p_0  };
        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1592;
        {
          Vec<1, Pointer> p_ref_157 { id_1591 };
          bool while_flag_1593 { true };
          do {
            uint8_t id_1594 { 0 };
            Pointer id_1595 { p_ref_157[id_1594] };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1596 { id_1595.readU8() };
            bool let_res_1597;
            {
              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_158 { id_1596 };
              bool letpair_res_1598;
              {
                auto leb128_fst_159 { std::get<0>(leb128_158) };
                auto leb128_snd_160 { std::get<1>(leb128_158) };
                uint8_t id_1599 { 0 };
                Void id_1600 { ((void)(p_ref_157[id_1599] = leb128_snd_160), ::dessser::Void()) };
                (void)id_1600;
                uint8_t id_1601 { 0 };
                uint8_t id_1602 { 127 };
                uint8_t id_1603 { uint8_t(leb128_fst_159 & id_1602) };
                uint32_t id_1604 { uint32_t(id_1603) };
                uint8_t id_1605 { 0 };
                uint8_t id_1606 { shft_ref_156[id_1605] };
                uint32_t id_1607 { uint32_t(id_1604 << id_1606) };
                uint8_t id_1608 { 0 };
                uint32_t id_1609 { leb_ref_155[id_1608] };
                uint32_t id_1610 { uint32_t(id_1607 | id_1609) };
                Void id_1611 { ((void)(leb_ref_155[id_1601] = id_1610), ::dessser::Void()) };
                (void)id_1611;
                uint8_t id_1612 { 0 };
                uint8_t id_1613 { 0 };
                uint8_t id_1614 { shft_ref_156[id_1613] };
                uint8_t id_1615 { 7 };
                uint8_t id_1616 { uint8_t(id_1614 + id_1615) };
                Void id_1617 { ((void)(shft_ref_156[id_1612] = id_1616), ::dessser::Void()) };
                (void)id_1617;
                uint8_t id_1618 { 128 };
                bool id_1619 { bool(leb128_fst_159 >= id_1618) };
                letpair_res_1598 = id_1619;
              }
              let_res_1597 = letpair_res_1598;
            }
            while_flag_1593 = let_res_1597;
            if (while_flag_1593) {
              (void)::dessser::Void();
            }
          } while (while_flag_1593);
          (void)::dessser::Void();
          uint8_t id_1620 { 0 };
          uint32_t id_1621 { leb_ref_155[id_1620] };
          uint8_t id_1622 { 0 };
          Pointer id_1623 { p_ref_157[id_1622] };
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1624 { id_1621, id_1623 };
          let_res_1592 = id_1624;
        }
        let_res_1590 = let_res_1592;
      }
      let_res_1587 = let_res_1590;
    }
    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 let_res_1625;
    {
      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_164 { let_res_1587 };
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1626;
      {
        auto dlist1_fst_165 { std::get<0>(dlist1_164) };
        auto dlist1_snd_166 { std::get<1>(dlist1_164) };
        Lst<dessser::gen::program_parameter::t_ext> endoflist_1627;
        ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1628 { endoflist_1627, dlist1_snd_166 };
        Vec<1, ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800> id_1629 {  id_1628  };
        ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 let_res_1630;
        {
          Vec<1, ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800> inits_src_ref_167 { id_1629 };
          int32_t id_1631 { 0L };
          Vec<1, int32_t> id_1632 {  id_1631  };
          {
            Vec<1, int32_t> repeat_n_168 { id_1632 };
            bool while_flag_1633 { true };
            do {
              int32_t id_1634 { int32_t(dlist1_fst_165) };
              uint8_t id_1635 { 0 };
              int32_t id_1636 { repeat_n_168[id_1635] };
              bool id_1637 { bool(id_1634 > id_1636) };
              while_flag_1633 = id_1637;
              if (while_flag_1633) {
                uint8_t id_1638 { 0 };
                ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1639 { inits_src_ref_167[id_1638] };
                {
                  ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 dlist2_169 { id_1639 };
                  {
                    auto dlist2_fst_170 { std::get<0>(dlist2_169) };
                    auto dlist2_snd_171 { std::get<1>(dlist2_169) };
                    uint8_t id_1640 { 0 };
                    auto fun1641 { dessser::gen::program_parameter::of_row_binary };
                    ::dessser::gen::source_info::tbbb6e77f92131ca39155edc6f36a3063 id_1642 { fun1641(dlist2_snd_171) };
                    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1643;
                    {
                      auto dlist3_fst_173 { std::get<0>(id_1642) };
                      auto dlist3_snd_174 { std::get<1>(id_1642) };
                      Lst<dessser::gen::program_parameter::t_ext> id_1644 { dlist3_fst_173, dlist2_fst_170 };
                      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1645 { id_1644, dlist3_snd_174 };
                      letpair_res_1643 = id_1645;
                    }
                    Void id_1646 { ((void)(inits_src_ref_167[id_1640] = letpair_res_1643), ::dessser::Void()) };
                    (void)id_1646;
                  }
                  (void)::dessser::Void();
                }
                (void)::dessser::Void();
                uint8_t id_1647 { 0 };
                uint8_t id_1648 { 0 };
                int32_t id_1649 { repeat_n_168[id_1648] };
                int32_t id_1650 { 1L };
                int32_t id_1651 { int32_t(id_1649 + id_1650) };
                Void id_1652 { ((void)(repeat_n_168[id_1647] = id_1651), ::dessser::Void()) };
                (void)id_1652;
                (void)id_1652;
              }
            } while (while_flag_1633);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_1653 { 0 };
          ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1654 { inits_src_ref_167[id_1653] };
          let_res_1630 = id_1654;
        }
        letpair_res_1626 = let_res_1630;
      }
      let_res_1625 = letpair_res_1626;
    }
    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1655;
    {
      auto dlist4_fst_176 { std::get<0>(let_res_1625) };
      auto dlist4_snd_177 { std::get<1>(let_res_1625) };
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1656 { dlist4_fst_176, dlist4_snd_177 };
      letpair_res_1655 = id_1656;
    }
    ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1657;
    {
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 drec_178 { letpair_res_1655 };
      ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1658;
      {
        auto drec_fst_179 { std::get<0>(drec_178) };
        auto drec_snd_180 { std::get<1>(drec_178) };
        auto fun1659 { dessser::gen::raql_expr::of_row_binary };
        ::dessser::gen::source_info::tc473a3a3b5068e57b15e934d0afcc038 id_1660 { fun1659(drec_snd_180) };
        ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1661;
        {
          ::dessser::gen::source_info::tc473a3a3b5068e57b15e934d0afcc038 drec_181 { id_1660 };
          ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1662;
          {
            auto drec_fst_182 { std::get<0>(drec_181) };
            auto drec_snd_183 { std::get<1>(drec_181) };
            uint32_t id_1663 { 0U };
            Vec<1, uint32_t> id_1664 {  id_1663  };
            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1665;
            {
              Vec<1, uint32_t> leb_ref_184 { id_1664 };
              uint8_t id_1666 { 0 };
              Vec<1, uint8_t> id_1667 {  id_1666  };
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1668;
              {
                Vec<1, uint8_t> shft_ref_185 { id_1667 };
                Vec<1, Pointer> id_1669 {  drec_snd_183  };
                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1670;
                {
                  Vec<1, Pointer> p_ref_186 { id_1669 };
                  bool while_flag_1671 { true };
                  do {
                    uint8_t id_1672 { 0 };
                    Pointer id_1673 { p_ref_186[id_1672] };
                    ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1674 { id_1673.readU8() };
                    bool let_res_1675;
                    {
                      ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_187 { id_1674 };
                      bool letpair_res_1676;
                      {
                        auto leb128_fst_188 { std::get<0>(leb128_187) };
                        auto leb128_snd_189 { std::get<1>(leb128_187) };
                        uint8_t id_1677 { 0 };
                        Void id_1678 { ((void)(p_ref_186[id_1677] = leb128_snd_189), ::dessser::Void()) };
                        (void)id_1678;
                        uint8_t id_1679 { 0 };
                        uint8_t id_1680 { 127 };
                        uint8_t id_1681 { uint8_t(leb128_fst_188 & id_1680) };
                        uint32_t id_1682 { uint32_t(id_1681) };
                        uint8_t id_1683 { 0 };
                        uint8_t id_1684 { shft_ref_185[id_1683] };
                        uint32_t id_1685 { uint32_t(id_1682 << id_1684) };
                        uint8_t id_1686 { 0 };
                        uint32_t id_1687 { leb_ref_184[id_1686] };
                        uint32_t id_1688 { uint32_t(id_1685 | id_1687) };
                        Void id_1689 { ((void)(leb_ref_184[id_1679] = id_1688), ::dessser::Void()) };
                        (void)id_1689;
                        uint8_t id_1690 { 0 };
                        uint8_t id_1691 { 0 };
                        uint8_t id_1692 { shft_ref_185[id_1691] };
                        uint8_t id_1693 { 7 };
                        uint8_t id_1694 { uint8_t(id_1692 + id_1693) };
                        Void id_1695 { ((void)(shft_ref_185[id_1690] = id_1694), ::dessser::Void()) };
                        (void)id_1695;
                        uint8_t id_1696 { 128 };
                        bool id_1697 { bool(leb128_fst_188 >= id_1696) };
                        letpair_res_1676 = id_1697;
                      }
                      let_res_1675 = letpair_res_1676;
                    }
                    while_flag_1671 = let_res_1675;
                    if (while_flag_1671) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_1671);
                  (void)::dessser::Void();
                  uint8_t id_1698 { 0 };
                  uint32_t id_1699 { leb_ref_184[id_1698] };
                  uint8_t id_1700 { 0 };
                  Pointer id_1701 { p_ref_186[id_1700] };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1702 { id_1699, id_1701 };
                  let_res_1670 = id_1702;
                }
                let_res_1668 = let_res_1670;
              }
              let_res_1665 = let_res_1668;
            }
            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 let_res_1703;
            {
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_193 { let_res_1665 };
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1704;
              {
                auto dlist1_fst_194 { std::get<0>(dlist1_193) };
                auto dlist1_snd_195 { std::get<1>(dlist1_193) };
                Lst<dessser::gen::global_variable::t_ext> endoflist_1705;
                ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1706 { endoflist_1705, dlist1_snd_195 };
                Vec<1, ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7> id_1707 {  id_1706  };
                ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 let_res_1708;
                {
                  Vec<1, ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7> inits_src_ref_196 { id_1707 };
                  int32_t id_1709 { 0L };
                  Vec<1, int32_t> id_1710 {  id_1709  };
                  {
                    Vec<1, int32_t> repeat_n_197 { id_1710 };
                    bool while_flag_1711 { true };
                    do {
                      int32_t id_1712 { int32_t(dlist1_fst_194) };
                      uint8_t id_1713 { 0 };
                      int32_t id_1714 { repeat_n_197[id_1713] };
                      bool id_1715 { bool(id_1712 > id_1714) };
                      while_flag_1711 = id_1715;
                      if (while_flag_1711) {
                        uint8_t id_1716 { 0 };
                        ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1717 { inits_src_ref_196[id_1716] };
                        {
                          ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 dlist2_198 { id_1717 };
                          {
                            auto dlist2_fst_199 { std::get<0>(dlist2_198) };
                            auto dlist2_snd_200 { std::get<1>(dlist2_198) };
                            uint8_t id_1718 { 0 };
                            auto fun1719 { dessser::gen::global_variable::of_row_binary };
                            ::dessser::gen::source_info::t40a6bf0f8e6a7b21bd5b768113e20619 id_1720 { fun1719(dlist2_snd_200) };
                            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1721;
                            {
                              auto dlist3_fst_202 { std::get<0>(id_1720) };
                              auto dlist3_snd_203 { std::get<1>(id_1720) };
                              Lst<dessser::gen::global_variable::t_ext> id_1722 { dlist3_fst_202, dlist2_fst_199 };
                              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1723 { id_1722, dlist3_snd_203 };
                              letpair_res_1721 = id_1723;
                            }
                            Void id_1724 { ((void)(inits_src_ref_196[id_1718] = letpair_res_1721), ::dessser::Void()) };
                            (void)id_1724;
                          }
                          (void)::dessser::Void();
                        }
                        (void)::dessser::Void();
                        uint8_t id_1725 { 0 };
                        uint8_t id_1726 { 0 };
                        int32_t id_1727 { repeat_n_197[id_1726] };
                        int32_t id_1728 { 1L };
                        int32_t id_1729 { int32_t(id_1727 + id_1728) };
                        Void id_1730 { ((void)(repeat_n_197[id_1725] = id_1729), ::dessser::Void()) };
                        (void)id_1730;
                        (void)id_1730;
                      }
                    } while (while_flag_1711);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_1731 { 0 };
                  ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1732 { inits_src_ref_196[id_1731] };
                  let_res_1708 = id_1732;
                }
                letpair_res_1704 = let_res_1708;
              }
              let_res_1703 = letpair_res_1704;
            }
            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1733;
            {
              auto dlist4_fst_205 { std::get<0>(let_res_1703) };
              auto dlist4_snd_206 { std::get<1>(let_res_1703) };
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1734 { dlist4_fst_205, dlist4_snd_206 };
              letpair_res_1733 = id_1734;
            }
            ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1735;
            {
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 drec_207 { letpair_res_1733 };
              ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1736;
              {
                auto drec_fst_208 { std::get<0>(drec_207) };
                auto drec_snd_209 { std::get<1>(drec_207) };
                uint32_t id_1737 { 0U };
                Vec<1, uint32_t> id_1738 {  id_1737  };
                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1739;
                {
                  Vec<1, uint32_t> leb_ref_210 { id_1738 };
                  uint8_t id_1740 { 0 };
                  Vec<1, uint8_t> id_1741 {  id_1740  };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1742;
                  {
                    Vec<1, uint8_t> shft_ref_211 { id_1741 };
                    Vec<1, Pointer> id_1743 {  drec_snd_209  };
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1744;
                    {
                      Vec<1, Pointer> p_ref_212 { id_1743 };
                      bool while_flag_1745 { true };
                      do {
                        uint8_t id_1746 { 0 };
                        Pointer id_1747 { p_ref_212[id_1746] };
                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1748 { id_1747.readU8() };
                        bool let_res_1749;
                        {
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_213 { id_1748 };
                          bool letpair_res_1750;
                          {
                            auto leb128_fst_214 { std::get<0>(leb128_213) };
                            auto leb128_snd_215 { std::get<1>(leb128_213) };
                            uint8_t id_1751 { 0 };
                            Void id_1752 { ((void)(p_ref_212[id_1751] = leb128_snd_215), ::dessser::Void()) };
                            (void)id_1752;
                            uint8_t id_1753 { 0 };
                            uint8_t id_1754 { 127 };
                            uint8_t id_1755 { uint8_t(leb128_fst_214 & id_1754) };
                            uint32_t id_1756 { uint32_t(id_1755) };
                            uint8_t id_1757 { 0 };
                            uint8_t id_1758 { shft_ref_211[id_1757] };
                            uint32_t id_1759 { uint32_t(id_1756 << id_1758) };
                            uint8_t id_1760 { 0 };
                            uint32_t id_1761 { leb_ref_210[id_1760] };
                            uint32_t id_1762 { uint32_t(id_1759 | id_1761) };
                            Void id_1763 { ((void)(leb_ref_210[id_1753] = id_1762), ::dessser::Void()) };
                            (void)id_1763;
                            uint8_t id_1764 { 0 };
                            uint8_t id_1765 { 0 };
                            uint8_t id_1766 { shft_ref_211[id_1765] };
                            uint8_t id_1767 { 7 };
                            uint8_t id_1768 { uint8_t(id_1766 + id_1767) };
                            Void id_1769 { ((void)(shft_ref_211[id_1764] = id_1768), ::dessser::Void()) };
                            (void)id_1769;
                            uint8_t id_1770 { 128 };
                            bool id_1771 { bool(leb128_fst_214 >= id_1770) };
                            letpair_res_1750 = id_1771;
                          }
                          let_res_1749 = letpair_res_1750;
                        }
                        while_flag_1745 = let_res_1749;
                        if (while_flag_1745) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_1745);
                      (void)::dessser::Void();
                      uint8_t id_1772 { 0 };
                      uint32_t id_1773 { leb_ref_210[id_1772] };
                      uint8_t id_1774 { 0 };
                      Pointer id_1775 { p_ref_212[id_1774] };
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1776 { id_1773, id_1775 };
                      let_res_1744 = id_1776;
                    }
                    let_res_1742 = let_res_1744;
                  }
                  let_res_1739 = let_res_1742;
                }
                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 let_res_1777;
                {
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_219 { let_res_1739 };
                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1778;
                  {
                    auto dlist1_fst_220 { std::get<0>(dlist1_219) };
                    auto dlist1_snd_221 { std::get<1>(dlist1_219) };
                    Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > endoflist_1779;
                    ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1780 { endoflist_1779, dlist1_snd_221 };
                    Vec<1, ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47> id_1781 {  id_1780  };
                    ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 let_res_1782;
                    {
                      Vec<1, ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47> inits_src_ref_222 { id_1781 };
                      int32_t id_1783 { 0L };
                      Vec<1, int32_t> id_1784 {  id_1783  };
                      {
                        Vec<1, int32_t> repeat_n_223 { id_1784 };
                        bool while_flag_1785 { true };
                        do {
                          int32_t id_1786 { int32_t(dlist1_fst_220) };
                          uint8_t id_1787 { 0 };
                          int32_t id_1788 { repeat_n_223[id_1787] };
                          bool id_1789 { bool(id_1786 > id_1788) };
                          while_flag_1785 = id_1789;
                          if (while_flag_1785) {
                            uint8_t id_1790 { 0 };
                            ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1791 { inits_src_ref_222[id_1790] };
                            {
                              ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 dlist2_224 { id_1791 };
                              {
                                auto dlist2_fst_225 { std::get<0>(dlist2_224) };
                                auto dlist2_snd_226 { std::get<1>(dlist2_224) };
                                uint8_t id_1792 { 0 };
                                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be id_1793 { compiled_func_of_row_binary(dlist2_snd_226) };
                                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1794;
                                {
                                  auto dlist3_fst_228 { std::get<0>(id_1793) };
                                  auto dlist3_snd_229 { std::get<1>(id_1793) };
                                  Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_1795 { dlist3_fst_228, dlist2_fst_225 };
                                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1796 { id_1795, dlist3_snd_229 };
                                  letpair_res_1794 = id_1796;
                                }
                                Void id_1797 { ((void)(inits_src_ref_222[id_1792] = letpair_res_1794), ::dessser::Void()) };
                                (void)id_1797;
                              }
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_1798 { 0 };
                            uint8_t id_1799 { 0 };
                            int32_t id_1800 { repeat_n_223[id_1799] };
                            int32_t id_1801 { 1L };
                            int32_t id_1802 { int32_t(id_1800 + id_1801) };
                            Void id_1803 { ((void)(repeat_n_223[id_1798] = id_1802), ::dessser::Void()) };
                            (void)id_1803;
                            (void)id_1803;
                          }
                        } while (while_flag_1785);
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_1804 { 0 };
                      ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1805 { inits_src_ref_222[id_1804] };
                      let_res_1782 = id_1805;
                    }
                    letpair_res_1778 = let_res_1782;
                  }
                  let_res_1777 = letpair_res_1778;
                }
                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1806;
                {
                  auto dlist4_fst_231 { std::get<0>(let_res_1777) };
                  auto dlist4_snd_232 { std::get<1>(let_res_1777) };
                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1807 { dlist4_fst_231, dlist4_snd_232 };
                  letpair_res_1806 = id_1807;
                }
                ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1808;
                {
                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 drec_233 { letpair_res_1806 };
                  ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1809;
                  {
                    auto drec_fst_234 { std::get<0>(drec_233) };
                    auto drec_snd_235 { std::get<1>(drec_233) };
                    uint32_t id_1810 { 0U };
                    Vec<1, uint32_t> id_1811 {  id_1810  };
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1812;
                    {
                      Vec<1, uint32_t> leb_ref_236 { id_1811 };
                      uint8_t id_1813 { 0 };
                      Vec<1, uint8_t> id_1814 {  id_1813  };
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1815;
                      {
                        Vec<1, uint8_t> shft_ref_237 { id_1814 };
                        Vec<1, Pointer> id_1816 {  drec_snd_235  };
                        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1817;
                        {
                          Vec<1, Pointer> p_ref_238 { id_1816 };
                          bool while_flag_1818 { true };
                          do {
                            uint8_t id_1819 { 0 };
                            Pointer id_1820 { p_ref_238[id_1819] };
                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1821 { id_1820.readU8() };
                            bool let_res_1822;
                            {
                              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_239 { id_1821 };
                              bool letpair_res_1823;
                              {
                                auto leb128_fst_240 { std::get<0>(leb128_239) };
                                auto leb128_snd_241 { std::get<1>(leb128_239) };
                                uint8_t id_1824 { 0 };
                                Void id_1825 { ((void)(p_ref_238[id_1824] = leb128_snd_241), ::dessser::Void()) };
                                (void)id_1825;
                                uint8_t id_1826 { 0 };
                                uint8_t id_1827 { 127 };
                                uint8_t id_1828 { uint8_t(leb128_fst_240 & id_1827) };
                                uint32_t id_1829 { uint32_t(id_1828) };
                                uint8_t id_1830 { 0 };
                                uint8_t id_1831 { shft_ref_237[id_1830] };
                                uint32_t id_1832 { uint32_t(id_1829 << id_1831) };
                                uint8_t id_1833 { 0 };
                                uint32_t id_1834 { leb_ref_236[id_1833] };
                                uint32_t id_1835 { uint32_t(id_1832 | id_1834) };
                                Void id_1836 { ((void)(leb_ref_236[id_1826] = id_1835), ::dessser::Void()) };
                                (void)id_1836;
                                uint8_t id_1837 { 0 };
                                uint8_t id_1838 { 0 };
                                uint8_t id_1839 { shft_ref_237[id_1838] };
                                uint8_t id_1840 { 7 };
                                uint8_t id_1841 { uint8_t(id_1839 + id_1840) };
                                Void id_1842 { ((void)(shft_ref_237[id_1837] = id_1841), ::dessser::Void()) };
                                (void)id_1842;
                                uint8_t id_1843 { 128 };
                                bool id_1844 { bool(leb128_fst_240 >= id_1843) };
                                letpair_res_1823 = id_1844;
                              }
                              let_res_1822 = letpair_res_1823;
                            }
                            while_flag_1818 = let_res_1822;
                            if (while_flag_1818) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_1818);
                          (void)::dessser::Void();
                          uint8_t id_1845 { 0 };
                          uint32_t id_1846 { leb_ref_236[id_1845] };
                          uint8_t id_1847 { 0 };
                          Pointer id_1848 { p_ref_238[id_1847] };
                          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1849 { id_1846, id_1848 };
                          let_res_1817 = id_1849;
                        }
                        let_res_1815 = let_res_1817;
                      }
                      let_res_1812 = let_res_1815;
                    }
                    ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c let_res_1850;
                    {
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_245 { let_res_1812 };
                      ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c letpair_res_1851;
                      {
                        auto dlist1_fst_246 { std::get<0>(dlist1_245) };
                        auto dlist1_snd_247 { std::get<1>(dlist1_245) };
                        Lst<dessser::gen::raql_warning::t_ext> endoflist_1852;
                        ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1853 { endoflist_1852, dlist1_snd_247 };
                        Vec<1, ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c> id_1854 {  id_1853  };
                        ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c let_res_1855;
                        {
                          Vec<1, ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c> inits_src_ref_248 { id_1854 };
                          int32_t id_1856 { 0L };
                          Vec<1, int32_t> id_1857 {  id_1856  };
                          {
                            Vec<1, int32_t> repeat_n_249 { id_1857 };
                            bool while_flag_1858 { true };
                            do {
                              int32_t id_1859 { int32_t(dlist1_fst_246) };
                              uint8_t id_1860 { 0 };
                              int32_t id_1861 { repeat_n_249[id_1860] };
                              bool id_1862 { bool(id_1859 > id_1861) };
                              while_flag_1858 = id_1862;
                              if (while_flag_1858) {
                                uint8_t id_1863 { 0 };
                                ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1864 { inits_src_ref_248[id_1863] };
                                {
                                  ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c dlist2_250 { id_1864 };
                                  {
                                    auto dlist2_fst_251 { std::get<0>(dlist2_250) };
                                    auto dlist2_snd_252 { std::get<1>(dlist2_250) };
                                    uint8_t id_1865 { 0 };
                                    auto fun1866 { dessser::gen::raql_warning::of_row_binary };
                                    ::dessser::gen::source_info::tf20c5d088795d1f84266f4ee74fe3594 id_1867 { fun1866(dlist2_snd_252) };
                                    ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c letpair_res_1868;
                                    {
                                      auto dlist3_fst_254 { std::get<0>(id_1867) };
                                      auto dlist3_snd_255 { std::get<1>(id_1867) };
                                      Lst<dessser::gen::raql_warning::t_ext> id_1869 { dlist3_fst_254, dlist2_fst_251 };
                                      ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1870 { id_1869, dlist3_snd_255 };
                                      letpair_res_1868 = id_1870;
                                    }
                                    Void id_1871 { ((void)(inits_src_ref_248[id_1865] = letpair_res_1868), ::dessser::Void()) };
                                    (void)id_1871;
                                  }
                                  (void)::dessser::Void();
                                }
                                (void)::dessser::Void();
                                uint8_t id_1872 { 0 };
                                uint8_t id_1873 { 0 };
                                int32_t id_1874 { repeat_n_249[id_1873] };
                                int32_t id_1875 { 1L };
                                int32_t id_1876 { int32_t(id_1874 + id_1875) };
                                Void id_1877 { ((void)(repeat_n_249[id_1872] = id_1876), ::dessser::Void()) };
                                (void)id_1877;
                                (void)id_1877;
                              }
                            } while (while_flag_1858);
                            (void)::dessser::Void();
                          }
                          (void)::dessser::Void();
                          uint8_t id_1878 { 0 };
                          ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1879 { inits_src_ref_248[id_1878] };
                          let_res_1855 = id_1879;
                        }
                        letpair_res_1851 = let_res_1855;
                      }
                      let_res_1850 = letpair_res_1851;
                    }
                    ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1880;
                    {
                      auto dlist4_fst_257 { std::get<0>(let_res_1850) };
                      auto dlist4_snd_258 { std::get<1>(let_res_1850) };
                      std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_1881 { std::make_shared<::dessser::gen::source_info::compiled_program>(drec_fst_179, drec_fst_182, drec_fst_208, drec_fst_234, dlist4_fst_257) };
                      ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 id_1882 { id_1881, dlist4_snd_258 };
                      letpair_res_1880 = id_1882;
                    }
                    letpair_res_1809 = letpair_res_1880;
                  }
                  let_res_1808 = letpair_res_1809;
                }
                letpair_res_1736 = let_res_1808;
              }
              let_res_1735 = letpair_res_1736;
            }
            letpair_res_1662 = let_res_1735;
          }
          let_res_1661 = letpair_res_1662;
        }
        letpair_res_1658 = let_res_1661;
      }
      let_res_1657 = letpair_res_1658;
    }
    return let_res_1657;
  }
   };
  return fun1584;
}
std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> compiled_program_of_row_binary(compiled_program_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_274"
        (let "dstring1_268"
          (let "leb_ref_262" (make-vec (u32 0))
            (let "shft_ref_263" (make-vec (u8 0))
              (let "p_ref_264" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_265" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_264")))
                      (let-pair "leb128_fst_266" "leb128_snd_267" (identifier "leb128_265")
                        (seq (set-vec (u8 0) (identifier "p_ref_264") (identifier "leb128_snd_267"))
                          (set-vec (u8 0) (identifier "leb_ref_262")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_266") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_263"))) (unsafe-nth (u8 0) (identifier "leb_ref_262"))))
                          (set-vec (u8 0) (identifier "shft_ref_263") (add (unsafe-nth (u8 0) (identifier "shft_ref_263")) (u8 7))) 
                          (ge (identifier "leb128_fst_266") (u8 128))))) 
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_262"))) (unsafe-nth (u8 0) (identifier "p_ref_264")))))))
          (let-pair "dstring1_fst_269" "dstring1_snd_270" (identifier "dstring1_268")
            (let-pair "dstring2_fst_272" "dstring2_snd_273" (read-bytes (identifier "dstring1_snd_270") (identifier "dstring1_fst_269"))
              (make-tup (string-of-bytes (identifier "dstring2_fst_272")) (identifier "dstring2_snd_273")))))
        (let-pair "drec_fst_275" "drec_snd_276" (identifier "drec_274")
          (let "drec_312"
            (let-pair "dlist4_fst_310" "dlist4_snd_311"
              (let "dlist1_286"
                (let "leb_ref_277" (make-vec (u32 0))
                  (let "shft_ref_278" (make-vec (u8 0))
                    (let "p_ref_279" (make-vec (identifier "drec_snd_276"))
                      (seq
                        (while
                          (let "leb128_280" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_279")))
                            (let-pair "leb128_fst_281" "leb128_snd_282" 
                              (identifier "leb128_280")
                              (seq (set-vec (u8 0) (identifier "p_ref_279") (identifier "leb128_snd_282"))
                                (set-vec (u8 0) (identifier "leb_ref_277")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_281") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_278"))) (unsafe-nth (u8 0) (identifier "leb_ref_277"))))
                                (set-vec (u8 0) (identifier "shft_ref_278") (add (unsafe-nth (u8 0) (identifier "shft_ref_278")) (u8 7))) 
                                (ge (identifier "leb128_fst_281") (u8 128))))) 
                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_277")) (unsafe-nth (u8 0) (identifier "p_ref_279")))))))
                (let-pair "dlist1_fst_287" "dlist1_snd_288" (identifier "dlist1_286")
                  (let "inits_src_ref_289" (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_288")))
                    (seq
                      (let "repeat_n_290" (make-vec (i32 0))
                        (while (gt (to-i32 (identifier "dlist1_fst_287")) (unsafe-nth (u8 0) (identifier "repeat_n_290")))
                          (seq
                            (let "dlist2_291" (unsafe-nth (u8 0) (identifier "inits_src_ref_289"))
                              (let-pair "dlist2_fst_292" "dlist2_snd_293" 
                                (identifier "dlist2_291")
                                (set-vec (u8 0) (identifier "inits_src_ref_289")
                                  (let "dstring1_300"
                                    (let "leb_ref_294" (make-vec (u32 0))
                                      (let "shft_ref_295" (make-vec (u8 0))
                                        (let "p_ref_296" (make-vec (identifier "dlist2_snd_293"))
                                          (seq
                                            (while
                                              (let "leb128_297" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_296")))
                                                (let-pair "leb128_fst_298" "leb128_snd_299" 
                                                  (identifier "leb128_297")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_296") (identifier "leb128_snd_299"))
                                                    (set-vec (u8 0) (identifier "leb_ref_294")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_298") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_295"))) (unsafe-nth (u8 0) (identifier "leb_ref_294"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_295") (add (unsafe-nth (u8 0) (identifier "shft_ref_295")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_298") (u8 128))))) 
                                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_294"))) (unsafe-nth (u8 0) (identifier "p_ref_296")))))))
                                    (let-pair "dstring1_fst_301" "dstring1_snd_302" 
                                      (identifier "dstring1_300")
                                      (let-pair "dstring2_fst_304" "dstring2_snd_305" 
                                        (read-bytes (identifier "dstring1_snd_302") (identifier "dstring1_fst_301"))
                                        (make-tup (cons (string-of-bytes (identifier "dstring2_fst_304")) (identifier "dlist2_fst_292")) (identifier "dstring2_snd_305"))))))))
                            (set-vec (u8 0) (identifier "repeat_n_290") (add (unsafe-nth (u8 0) (identifier "repeat_n_290")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "inits_src_ref_289")))))) 
              (make-tup (identity (identifier "dlist4_fst_310")) (identifier "dlist4_snd_311")))
            (let-pair "drec_fst_313" "drec_snd_314" (identifier "drec_312")
              (let-pair "drec_fst_363" "drec_snd_364"
                (let "dsum1_321" (let-pair "du16_fst_316" "du16_snd_317" (read-u16 little-endian (identifier "drec_snd_314")) (make-tup (identifier "du16_fst_316") (identifier "du16_snd_317")))
                  (let-pair "dsum1_fst_322" "dsum1_snd_323" (identifier "dsum1_321")
                    (if (eq (u16 0) (identifier "dsum1_fst_322"))
                      (let-pair "dsum2_fst_360" "dsum2_snd_361" (apply (identifier "compiled_program-of-row-binary") (identifier "dsum1_snd_323"))
                        (make-tup
                          (construct "[Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]" 0
                            (identifier "dsum2_fst_360")) (identifier "dsum2_snd_361")))
                      (seq (assert (eq (identifier "dsum1_fst_322") (u16 1)))
                        (let "drec_347"
                          (let-pair "dlist4_fst_345" "dlist4_snd_346"
                            (let "dlist1_333"
                              (let "leb_ref_324" (make-vec (u32 0))
                                (let "shft_ref_325" (make-vec (u8 0))
                                  (let "p_ref_326" (make-vec (identifier "dsum1_snd_323"))
                                    (seq
                                      (while
                                        (let "leb128_327" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_326")))
                                          (let-pair "leb128_fst_328" "leb128_snd_329" 
                                            (identifier "leb128_327")
                                            (seq (set-vec (u8 0) (identifier "p_ref_326") (identifier "leb128_snd_329"))
                                              (set-vec (u8 0) (identifier "leb_ref_324")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_328") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_325"))) (unsafe-nth (u8 0) (identifier "leb_ref_324"))))
                                              (set-vec (u8 0) (identifier "shft_ref_325") (add (unsafe-nth (u8 0) (identifier "shft_ref_325")) (u8 7))) 
                                              (ge (identifier "leb128_fst_328") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_324")) (unsafe-nth (u8 0) (identifier "p_ref_326")))))))
                              (let-pair "dlist1_fst_334" "dlist1_snd_335" 
                                (identifier "dlist1_333")
                                (let "inits_src_ref_336" (make-vec (make-tup (end-of-list "$raql_error") (identifier "dlist1_snd_335")))
                                  (seq
                                    (let "repeat_n_337" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_334")) (unsafe-nth (u8 0) (identifier "repeat_n_337")))
                                        (seq
                                          (let "dlist2_338" (unsafe-nth (u8 0) (identifier "inits_src_ref_336"))
                                            (let-pair "dlist2_fst_339" "dlist2_snd_340" 
                                              (identifier "dlist2_338")
                                              (set-vec (u8 0) (identifier "inits_src_ref_336")
                                                (let-pair "dlist3_fst_342" "dlist3_snd_343" 
                                                  (apply (ext-identifier raql_error of-row-binary) (identifier "dlist2_snd_340"))
                                                  (make-tup (cons (identifier "dlist3_fst_342") (identifier "dlist2_fst_339")) (identifier "dlist3_snd_343"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_337") (add (unsafe-nth (u8 0) (identifier "repeat_n_337")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_336")))))) 
                            (make-tup (identity (identifier "dlist4_fst_345")) (identifier "dlist4_snd_346")))
                          (let-pair "drec_fst_348" "drec_snd_349" (identifier "drec_347")
                            (let-pair "drec_fst_354" "drec_snd_355"
                              (if (eq (peek-u8 (identifier "drec_snd_349") (size 0)) (u8 1)) 
                                (make-tup (null "$src_path") (ptr-add (identifier "drec_snd_349") (size 1)))
                                (let-pair "make1_1_fst_351" "make1_1_snd_352" 
                                  (apply (ext-identifier src_path of-row-binary) (ptr-add (identifier "drec_snd_349") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_351")) (identifier "make1_1_snd_352"))))
                              (make-tup
                                (construct "[Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]" 1
                                  (make-rec (string "depends_on") (identifier "drec_fst_354") (string "errors") (identifier "drec_fst_348"))) 
                                (identifier "drec_snd_355")))))))))
                (make-tup (make-rec (string "detail") (identifier "drec_fst_363") (string "md5s") (identifier "drec_fst_313") (string "src_ext") (identifier "drec_fst_275")) (identifier "drec_snd_364"))))))))
 */
static std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> fun1883 { [&](Pointer p_0) {
    uint32_t id_1884 { 0U };
    Vec<1, uint32_t> id_1885 {  id_1884  };
    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1886;
    {
      Vec<1, uint32_t> leb_ref_262 { id_1885 };
      uint8_t id_1887 { 0 };
      Vec<1, uint8_t> id_1888 {  id_1887  };
      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1889;
      {
        Vec<1, uint8_t> shft_ref_263 { id_1888 };
        Vec<1, Pointer> id_1890 {  p_0  };
        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1891;
        {
          Vec<1, Pointer> p_ref_264 { id_1890 };
          bool while_flag_1892 { true };
          do {
            uint8_t id_1893 { 0 };
            Pointer id_1894 { p_ref_264[id_1893] };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1895 { id_1894.readU8() };
            bool let_res_1896;
            {
              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_265 { id_1895 };
              bool letpair_res_1897;
              {
                auto leb128_fst_266 { std::get<0>(leb128_265) };
                auto leb128_snd_267 { std::get<1>(leb128_265) };
                uint8_t id_1898 { 0 };
                Void id_1899 { ((void)(p_ref_264[id_1898] = leb128_snd_267), ::dessser::Void()) };
                (void)id_1899;
                uint8_t id_1900 { 0 };
                uint8_t id_1901 { 127 };
                uint8_t id_1902 { uint8_t(leb128_fst_266 & id_1901) };
                uint32_t id_1903 { uint32_t(id_1902) };
                uint8_t id_1904 { 0 };
                uint8_t id_1905 { shft_ref_263[id_1904] };
                uint32_t id_1906 { uint32_t(id_1903 << id_1905) };
                uint8_t id_1907 { 0 };
                uint32_t id_1908 { leb_ref_262[id_1907] };
                uint32_t id_1909 { uint32_t(id_1906 | id_1908) };
                Void id_1910 { ((void)(leb_ref_262[id_1900] = id_1909), ::dessser::Void()) };
                (void)id_1910;
                uint8_t id_1911 { 0 };
                uint8_t id_1912 { 0 };
                uint8_t id_1913 { shft_ref_263[id_1912] };
                uint8_t id_1914 { 7 };
                uint8_t id_1915 { uint8_t(id_1913 + id_1914) };
                Void id_1916 { ((void)(shft_ref_263[id_1911] = id_1915), ::dessser::Void()) };
                (void)id_1916;
                uint8_t id_1917 { 128 };
                bool id_1918 { bool(leb128_fst_266 >= id_1917) };
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
          uint32_t id_1920 { leb_ref_262[id_1919] };
          Size id_1921 { Size(id_1920) };
          uint8_t id_1922 { 0 };
          Pointer id_1923 { p_ref_264[id_1922] };
          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1924 { id_1921, id_1923 };
          let_res_1891 = id_1924;
        }
        let_res_1889 = let_res_1891;
      }
      let_res_1886 = let_res_1889;
    }
    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1925;
    {
      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_268 { let_res_1886 };
      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1926;
      {
        auto dstring1_fst_269 { std::get<0>(dstring1_268) };
        auto dstring1_snd_270 { std::get<1>(dstring1_268) };
        ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1927 { dstring1_snd_270.readBytes(dstring1_fst_269) };
        ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1928;
        {
          auto dstring2_fst_272 { std::get<0>(id_1927) };
          auto dstring2_snd_273 { std::get<1>(id_1927) };
          std::string id_1929 { dstring2_fst_272.toString() };
          ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1930 { id_1929, dstring2_snd_273 };
          letpair_res_1928 = id_1930;
        }
        letpair_res_1926 = letpair_res_1928;
      }
      let_res_1925 = letpair_res_1926;
    }
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 let_res_1931;
    {
      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_274 { let_res_1925 };
      ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_1932;
      {
        auto drec_fst_275 { std::get<0>(drec_274) };
        auto drec_snd_276 { std::get<1>(drec_274) };
        uint32_t id_1933 { 0U };
        Vec<1, uint32_t> id_1934 {  id_1933  };
        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1935;
        {
          Vec<1, uint32_t> leb_ref_277 { id_1934 };
          uint8_t id_1936 { 0 };
          Vec<1, uint8_t> id_1937 {  id_1936  };
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1938;
          {
            Vec<1, uint8_t> shft_ref_278 { id_1937 };
            Vec<1, Pointer> id_1939 {  drec_snd_276  };
            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1940;
            {
              Vec<1, Pointer> p_ref_279 { id_1939 };
              bool while_flag_1941 { true };
              do {
                uint8_t id_1942 { 0 };
                Pointer id_1943 { p_ref_279[id_1942] };
                ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1944 { id_1943.readU8() };
                bool let_res_1945;
                {
                  ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_280 { id_1944 };
                  bool letpair_res_1946;
                  {
                    auto leb128_fst_281 { std::get<0>(leb128_280) };
                    auto leb128_snd_282 { std::get<1>(leb128_280) };
                    uint8_t id_1947 { 0 };
                    Void id_1948 { ((void)(p_ref_279[id_1947] = leb128_snd_282), ::dessser::Void()) };
                    (void)id_1948;
                    uint8_t id_1949 { 0 };
                    uint8_t id_1950 { 127 };
                    uint8_t id_1951 { uint8_t(leb128_fst_281 & id_1950) };
                    uint32_t id_1952 { uint32_t(id_1951) };
                    uint8_t id_1953 { 0 };
                    uint8_t id_1954 { shft_ref_278[id_1953] };
                    uint32_t id_1955 { uint32_t(id_1952 << id_1954) };
                    uint8_t id_1956 { 0 };
                    uint32_t id_1957 { leb_ref_277[id_1956] };
                    uint32_t id_1958 { uint32_t(id_1955 | id_1957) };
                    Void id_1959 { ((void)(leb_ref_277[id_1949] = id_1958), ::dessser::Void()) };
                    (void)id_1959;
                    uint8_t id_1960 { 0 };
                    uint8_t id_1961 { 0 };
                    uint8_t id_1962 { shft_ref_278[id_1961] };
                    uint8_t id_1963 { 7 };
                    uint8_t id_1964 { uint8_t(id_1962 + id_1963) };
                    Void id_1965 { ((void)(shft_ref_278[id_1960] = id_1964), ::dessser::Void()) };
                    (void)id_1965;
                    uint8_t id_1966 { 128 };
                    bool id_1967 { bool(leb128_fst_281 >= id_1966) };
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
              uint32_t id_1969 { leb_ref_277[id_1968] };
              uint8_t id_1970 { 0 };
              Pointer id_1971 { p_ref_279[id_1970] };
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1972 { id_1969, id_1971 };
              let_res_1940 = id_1972;
            }
            let_res_1938 = let_res_1940;
          }
          let_res_1935 = let_res_1938;
        }
        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1973;
        {
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_286 { let_res_1935 };
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1974;
          {
            auto dlist1_fst_287 { std::get<0>(dlist1_286) };
            auto dlist1_snd_288 { std::get<1>(dlist1_286) };
            Lst<std::string> endoflist_1975;
            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1976 { endoflist_1975, dlist1_snd_288 };
            Vec<1, ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc> id_1977 {  id_1976  };
            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1978;
            {
              Vec<1, ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc> inits_src_ref_289 { id_1977 };
              int32_t id_1979 { 0L };
              Vec<1, int32_t> id_1980 {  id_1979  };
              {
                Vec<1, int32_t> repeat_n_290 { id_1980 };
                bool while_flag_1981 { true };
                do {
                  int32_t id_1982 { int32_t(dlist1_fst_287) };
                  uint8_t id_1983 { 0 };
                  int32_t id_1984 { repeat_n_290[id_1983] };
                  bool id_1985 { bool(id_1982 > id_1984) };
                  while_flag_1981 = id_1985;
                  if (while_flag_1981) {
                    uint8_t id_1986 { 0 };
                    ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1987 { inits_src_ref_289[id_1986] };
                    {
                      ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc dlist2_291 { id_1987 };
                      {
                        auto dlist2_fst_292 { std::get<0>(dlist2_291) };
                        auto dlist2_snd_293 { std::get<1>(dlist2_291) };
                        uint8_t id_1988 { 0 };
                        uint32_t id_1989 { 0U };
                        Vec<1, uint32_t> id_1990 {  id_1989  };
                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1991;
                        {
                          Vec<1, uint32_t> leb_ref_294 { id_1990 };
                          uint8_t id_1992 { 0 };
                          Vec<1, uint8_t> id_1993 {  id_1992  };
                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1994;
                          {
                            Vec<1, uint8_t> shft_ref_295 { id_1993 };
                            Vec<1, Pointer> id_1995 {  dlist2_snd_293  };
                            ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1996;
                            {
                              Vec<1, Pointer> p_ref_296 { id_1995 };
                              bool while_flag_1997 { true };
                              do {
                                uint8_t id_1998 { 0 };
                                Pointer id_1999 { p_ref_296[id_1998] };
                                ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_2000 { id_1999.readU8() };
                                bool let_res_2001;
                                {
                                  ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_297 { id_2000 };
                                  bool letpair_res_2002;
                                  {
                                    auto leb128_fst_298 { std::get<0>(leb128_297) };
                                    auto leb128_snd_299 { std::get<1>(leb128_297) };
                                    uint8_t id_2003 { 0 };
                                    Void id_2004 { ((void)(p_ref_296[id_2003] = leb128_snd_299), ::dessser::Void()) };
                                    (void)id_2004;
                                    uint8_t id_2005 { 0 };
                                    uint8_t id_2006 { 127 };
                                    uint8_t id_2007 { uint8_t(leb128_fst_298 & id_2006) };
                                    uint32_t id_2008 { uint32_t(id_2007) };
                                    uint8_t id_2009 { 0 };
                                    uint8_t id_2010 { shft_ref_295[id_2009] };
                                    uint32_t id_2011 { uint32_t(id_2008 << id_2010) };
                                    uint8_t id_2012 { 0 };
                                    uint32_t id_2013 { leb_ref_294[id_2012] };
                                    uint32_t id_2014 { uint32_t(id_2011 | id_2013) };
                                    Void id_2015 { ((void)(leb_ref_294[id_2005] = id_2014), ::dessser::Void()) };
                                    (void)id_2015;
                                    uint8_t id_2016 { 0 };
                                    uint8_t id_2017 { 0 };
                                    uint8_t id_2018 { shft_ref_295[id_2017] };
                                    uint8_t id_2019 { 7 };
                                    uint8_t id_2020 { uint8_t(id_2018 + id_2019) };
                                    Void id_2021 { ((void)(shft_ref_295[id_2016] = id_2020), ::dessser::Void()) };
                                    (void)id_2021;
                                    uint8_t id_2022 { 128 };
                                    bool id_2023 { bool(leb128_fst_298 >= id_2022) };
                                    letpair_res_2002 = id_2023;
                                  }
                                  let_res_2001 = letpair_res_2002;
                                }
                                while_flag_1997 = let_res_2001;
                                if (while_flag_1997) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_1997);
                              (void)::dessser::Void();
                              uint8_t id_2024 { 0 };
                              uint32_t id_2025 { leb_ref_294[id_2024] };
                              Size id_2026 { Size(id_2025) };
                              uint8_t id_2027 { 0 };
                              Pointer id_2028 { p_ref_296[id_2027] };
                              ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_2029 { id_2026, id_2028 };
                              let_res_1996 = id_2029;
                            }
                            let_res_1994 = let_res_1996;
                          }
                          let_res_1991 = let_res_1994;
                        }
                        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_2030;
                        {
                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_300 { let_res_1991 };
                          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_2031;
                          {
                            auto dstring1_fst_301 { std::get<0>(dstring1_300) };
                            auto dstring1_snd_302 { std::get<1>(dstring1_300) };
                            ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_2032 { dstring1_snd_302.readBytes(dstring1_fst_301) };
                            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_2033;
                            {
                              auto dstring2_fst_304 { std::get<0>(id_2032) };
                              auto dstring2_snd_305 { std::get<1>(id_2032) };
                              std::string id_2034 { dstring2_fst_304.toString() };
                              Lst<std::string> id_2035 { id_2034, dlist2_fst_292 };
                              ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_2036 { id_2035, dstring2_snd_305 };
                              letpair_res_2033 = id_2036;
                            }
                            letpair_res_2031 = letpair_res_2033;
                          }
                          let_res_2030 = letpair_res_2031;
                        }
                        Void id_2037 { ((void)(inits_src_ref_289[id_1988] = let_res_2030), ::dessser::Void()) };
                        (void)id_2037;
                      }
                      (void)::dessser::Void();
                    }
                    (void)::dessser::Void();
                    uint8_t id_2038 { 0 };
                    uint8_t id_2039 { 0 };
                    int32_t id_2040 { repeat_n_290[id_2039] };
                    int32_t id_2041 { 1L };
                    int32_t id_2042 { int32_t(id_2040 + id_2041) };
                    Void id_2043 { ((void)(repeat_n_290[id_2038] = id_2042), ::dessser::Void()) };
                    (void)id_2043;
                    (void)id_2043;
                  }
                } while (while_flag_1981);
                (void)::dessser::Void();
              }
              (void)::dessser::Void();
              uint8_t id_2044 { 0 };
              ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_2045 { inits_src_ref_289[id_2044] };
              let_res_1978 = id_2045;
            }
            letpair_res_1974 = let_res_1978;
          }
          let_res_1973 = letpair_res_1974;
        }
        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_2046;
        {
          auto dlist4_fst_310 { std::get<0>(let_res_1973) };
          auto dlist4_snd_311 { std::get<1>(let_res_1973) };
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_2047 { dlist4_fst_310, dlist4_snd_311 };
          letpair_res_2046 = id_2047;
        }
        ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 let_res_2048;
        {
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc drec_312 { letpair_res_2046 };
          ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_2049;
          {
            auto drec_fst_313 { std::get<0>(drec_312) };
            auto drec_snd_314 { std::get<1>(drec_312) };
            ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 id_2050 { drec_snd_314.readU16Le() };
            ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2051;
            {
              auto du16_fst_316 { std::get<0>(id_2050) };
              auto du16_snd_317 { std::get<1>(id_2050) };
              ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 id_2052 { du16_fst_316, du16_snd_317 };
              letpair_res_2051 = id_2052;
            }
            ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 let_res_2053;
            {
              ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 dsum1_321 { letpair_res_2051 };
              ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2054;
              {
                auto dsum1_fst_322 { std::get<0>(dsum1_321) };
                auto dsum1_snd_323 { std::get<1>(dsum1_321) };
                uint16_t id_2055 { 0 };
                bool id_2056 { bool(id_2055 == dsum1_fst_322) };
                ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 choose_res_2057;
                if (id_2056) {
                  ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 id_2058 { compiled_program_of_row_binary(dsum1_snd_323) };
                  ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2059;
                  {
                    auto dsum2_fst_360 { std::get<0>(id_2058) };
                    auto dsum2_snd_361 { std::get<1>(id_2058) };
                    ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_2060 { std::in_place_index<0>, dsum2_fst_360 };
                    ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 id_2061 { id_2060, dsum2_snd_361 };
                    letpair_res_2059 = id_2061;
                  }
                  choose_res_2057 = letpair_res_2059;
                } else {
                  uint16_t id_2062 { 1 };
                  bool id_2063 { bool(dsum1_fst_322 == id_2062) };
                  Void id_2064 { ((void)(assert(id_2063)), ::dessser::Void()) };
                  (void)id_2064;
                  uint32_t id_2065 { 0U };
                  Vec<1, uint32_t> id_2066 {  id_2065  };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_2067;
                  {
                    Vec<1, uint32_t> leb_ref_324 { id_2066 };
                    uint8_t id_2068 { 0 };
                    Vec<1, uint8_t> id_2069 {  id_2068  };
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_2070;
                    {
                      Vec<1, uint8_t> shft_ref_325 { id_2069 };
                      Vec<1, Pointer> id_2071 {  dsum1_snd_323  };
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_2072;
                      {
                        Vec<1, Pointer> p_ref_326 { id_2071 };
                        bool while_flag_2073 { true };
                        do {
                          uint8_t id_2074 { 0 };
                          Pointer id_2075 { p_ref_326[id_2074] };
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_2076 { id_2075.readU8() };
                          bool let_res_2077;
                          {
                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_327 { id_2076 };
                            bool letpair_res_2078;
                            {
                              auto leb128_fst_328 { std::get<0>(leb128_327) };
                              auto leb128_snd_329 { std::get<1>(leb128_327) };
                              uint8_t id_2079 { 0 };
                              Void id_2080 { ((void)(p_ref_326[id_2079] = leb128_snd_329), ::dessser::Void()) };
                              (void)id_2080;
                              uint8_t id_2081 { 0 };
                              uint8_t id_2082 { 127 };
                              uint8_t id_2083 { uint8_t(leb128_fst_328 & id_2082) };
                              uint32_t id_2084 { uint32_t(id_2083) };
                              uint8_t id_2085 { 0 };
                              uint8_t id_2086 { shft_ref_325[id_2085] };
                              uint32_t id_2087 { uint32_t(id_2084 << id_2086) };
                              uint8_t id_2088 { 0 };
                              uint32_t id_2089 { leb_ref_324[id_2088] };
                              uint32_t id_2090 { uint32_t(id_2087 | id_2089) };
                              Void id_2091 { ((void)(leb_ref_324[id_2081] = id_2090), ::dessser::Void()) };
                              (void)id_2091;
                              uint8_t id_2092 { 0 };
                              uint8_t id_2093 { 0 };
                              uint8_t id_2094 { shft_ref_325[id_2093] };
                              uint8_t id_2095 { 7 };
                              uint8_t id_2096 { uint8_t(id_2094 + id_2095) };
                              Void id_2097 { ((void)(shft_ref_325[id_2092] = id_2096), ::dessser::Void()) };
                              (void)id_2097;
                              uint8_t id_2098 { 128 };
                              bool id_2099 { bool(leb128_fst_328 >= id_2098) };
                              letpair_res_2078 = id_2099;
                            }
                            let_res_2077 = letpair_res_2078;
                          }
                          while_flag_2073 = let_res_2077;
                          if (while_flag_2073) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_2073);
                        (void)::dessser::Void();
                        uint8_t id_2100 { 0 };
                        uint32_t id_2101 { leb_ref_324[id_2100] };
                        uint8_t id_2102 { 0 };
                        Pointer id_2103 { p_ref_326[id_2102] };
                        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_2104 { id_2101, id_2103 };
                        let_res_2072 = id_2104;
                      }
                      let_res_2070 = let_res_2072;
                    }
                    let_res_2067 = let_res_2070;
                  }
                  ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 let_res_2105;
                  {
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_333 { let_res_2067 };
                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 letpair_res_2106;
                    {
                      auto dlist1_fst_334 { std::get<0>(dlist1_333) };
                      auto dlist1_snd_335 { std::get<1>(dlist1_333) };
                      Lst<dessser::gen::raql_error::t_ext> endoflist_2107;
                      ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2108 { endoflist_2107, dlist1_snd_335 };
                      Vec<1, ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8> id_2109 {  id_2108  };
                      ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 let_res_2110;
                      {
                        Vec<1, ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8> inits_src_ref_336 { id_2109 };
                        int32_t id_2111 { 0L };
                        Vec<1, int32_t> id_2112 {  id_2111  };
                        {
                          Vec<1, int32_t> repeat_n_337 { id_2112 };
                          bool while_flag_2113 { true };
                          do {
                            int32_t id_2114 { int32_t(dlist1_fst_334) };
                            uint8_t id_2115 { 0 };
                            int32_t id_2116 { repeat_n_337[id_2115] };
                            bool id_2117 { bool(id_2114 > id_2116) };
                            while_flag_2113 = id_2117;
                            if (while_flag_2113) {
                              uint8_t id_2118 { 0 };
                              ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2119 { inits_src_ref_336[id_2118] };
                              {
                                ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 dlist2_338 { id_2119 };
                                {
                                  auto dlist2_fst_339 { std::get<0>(dlist2_338) };
                                  auto dlist2_snd_340 { std::get<1>(dlist2_338) };
                                  uint8_t id_2120 { 0 };
                                  auto fun2121 { dessser::gen::raql_error::of_row_binary };
                                  ::dessser::gen::source_info::teea7fc62226f20557c62e7bf6ca50e88 id_2122 { fun2121(dlist2_snd_340) };
                                  ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 letpair_res_2123;
                                  {
                                    auto dlist3_fst_342 { std::get<0>(id_2122) };
                                    auto dlist3_snd_343 { std::get<1>(id_2122) };
                                    Lst<dessser::gen::raql_error::t_ext> id_2124 { dlist3_fst_342, dlist2_fst_339 };
                                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2125 { id_2124, dlist3_snd_343 };
                                    letpair_res_2123 = id_2125;
                                  }
                                  Void id_2126 { ((void)(inits_src_ref_336[id_2120] = letpair_res_2123), ::dessser::Void()) };
                                  (void)id_2126;
                                }
                                (void)::dessser::Void();
                              }
                              (void)::dessser::Void();
                              uint8_t id_2127 { 0 };
                              uint8_t id_2128 { 0 };
                              int32_t id_2129 { repeat_n_337[id_2128] };
                              int32_t id_2130 { 1L };
                              int32_t id_2131 { int32_t(id_2129 + id_2130) };
                              Void id_2132 { ((void)(repeat_n_337[id_2127] = id_2131), ::dessser::Void()) };
                              (void)id_2132;
                              (void)id_2132;
                            }
                          } while (while_flag_2113);
                          (void)::dessser::Void();
                        }
                        (void)::dessser::Void();
                        uint8_t id_2133 { 0 };
                        ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2134 { inits_src_ref_336[id_2133] };
                        let_res_2110 = id_2134;
                      }
                      letpair_res_2106 = let_res_2110;
                    }
                    let_res_2105 = letpair_res_2106;
                  }
                  ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 letpair_res_2135;
                  {
                    auto dlist4_fst_345 { std::get<0>(let_res_2105) };
                    auto dlist4_snd_346 { std::get<1>(let_res_2105) };
                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2136 { dlist4_fst_345, dlist4_snd_346 };
                    letpair_res_2135 = id_2136;
                  }
                  ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 let_res_2137;
                  {
                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 drec_347 { letpair_res_2135 };
                    ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2138;
                    {
                      auto drec_fst_348 { std::get<0>(drec_347) };
                      auto drec_snd_349 { std::get<1>(drec_347) };
                      Size id_2139 { 0UL };
                      uint8_t id_2140 { drec_snd_349.peekU8(id_2139) };
                      uint8_t id_2141 { 1 };
                      bool id_2142 { bool(id_2140 == id_2141) };
                      ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 choose_res_2143;
                      if (id_2142) {
                        std::optional<dessser::gen::src_path::t_ext> id_2144 { std::nullopt };
                        Size id_2145 { 1UL };
                        Pointer id_2146 { drec_snd_349.skip(id_2145) };
                        ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 id_2147 { id_2144, id_2146 };
                        choose_res_2143 = id_2147;
                      } else {
                        auto fun2148 { dessser::gen::src_path::of_row_binary };
                        Size id_2149 { 1UL };
                        Pointer id_2150 { drec_snd_349.skip(id_2149) };
                        ::dessser::gen::source_info::t6915129216bc7fcac0c82f38ea6cfec8 id_2151 { fun2148(id_2150) };
                        ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 letpair_res_2152;
                        {
                          auto make1_1_fst_351 { std::get<0>(id_2151) };
                          auto make1_1_snd_352 { std::get<1>(id_2151) };
                          std::optional<dessser::gen::src_path::t_ext> id_2153 { make1_1_fst_351 };
                          ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 id_2154 { id_2153, make1_1_snd_352 };
                          letpair_res_2152 = id_2154;
                        }
                        choose_res_2143 = letpair_res_2152;
                      }
                      ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2155;
                      {
                        auto drec_fst_354 { std::get<0>(choose_res_2143) };
                        auto drec_snd_355 { std::get<1>(choose_res_2143) };
                        ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_2156 { drec_fst_348, drec_fst_354 };
                        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_2157 { std::in_place_index<1>, id_2156 };
                        ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 id_2158 { id_2157, drec_snd_355 };
                        letpair_res_2155 = id_2158;
                      }
                      letpair_res_2138 = letpair_res_2155;
                    }
                    let_res_2137 = letpair_res_2138;
                  }
                  choose_res_2057 = let_res_2137;
                }
                letpair_res_2054 = choose_res_2057;
              }
              let_res_2053 = letpair_res_2054;
            }
            ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_2159;
            {
              auto drec_fst_363 { std::get<0>(let_res_2053) };
              auto drec_snd_364 { std::get<1>(let_res_2053) };
              std::shared_ptr<::dessser::gen::source_info::t>  id_2160 { std::make_shared<::dessser::gen::source_info::t>(drec_fst_275, drec_fst_313, drec_fst_363) };
              ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_2161 { id_2160, drec_snd_364 };
              letpair_res_2159 = id_2161;
            }
            letpair_res_2049 = letpair_res_2159;
          }
          let_res_2048 = letpair_res_2049;
        }
        letpair_res_1932 = let_res_2048;
      }
      let_res_1931 = letpair_res_1932;
    }
    return let_res_1931;
  }
   };
  return fun1883;
}
std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_366" "make_snd_367" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_366") (identifier "make_snd_367"))))
 */
static std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> fun2162 { [&](Pointer p_0) {
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_2163 { of_row_binary(p_0) };
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_2164;
    {
      auto make_fst_366 { std::get<0>(id_2163) };
      auto make_snd_367 { std::get<1>(id_2163) };
      ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_2165 { make_fst_366, make_snd_367 };
      letpair_res_2164 = id_2165;
    }
    return letpair_res_2164;
  }
   };
  return fun2162;
}
std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; best_after: $raql_expr?; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> fun2166 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0, Pointer p_1) {
    Pointer id_2167 { to_row_binary(p_0, p_1) };
    return id_2167;
  }
   };
  return fun2166;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
