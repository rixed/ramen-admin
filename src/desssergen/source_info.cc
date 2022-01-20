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
  std::string doc;
  dessser::gen::raql_operation::t_ext operation;
  dessser::gen::raql_type::t_ext out_record;
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string signature;
  std::string in_signature;
  compiled_func(dessser::gen::function_name::t_ext name_, std::optional<dessser::gen::retention::t_ext> retention_, bool is_lazy_, std::string doc_, dessser::gen::raql_operation::t_ext operation_, dessser::gen::raql_type::t_ext out_record_, Lst<dessser::gen::field_name::t_ext> factors_, std::string signature_, std::string in_signature_) : name(name_), retention(retention_), is_lazy(is_lazy_), doc(doc_), operation(operation_), out_record(out_record_), factors(factors_), signature(signature_), in_signature(in_signature_) {}
  compiled_func() = default;
};
inline bool operator==(compiled_func const &a, compiled_func const &b) {
  return ::dessser::gen::function_name::Deref(a.name) == ::dessser::gen::function_name::Deref(b.name) && ((a.retention && b.retention && ::dessser::gen::retention::Deref(a.retention.value()) == ::dessser::gen::retention::Deref(b.retention.value())) || (!a.retention && !b.retention)) && a.is_lazy == b.is_lazy && a.doc == b.doc && ::dessser::gen::raql_operation::Deref(a.operation) == ::dessser::gen::raql_operation::Deref(b.operation) && ::dessser::gen::raql_type::Deref(a.out_record) == ::dessser::gen::raql_type::Deref(b.out_record) && a.factors == b.factors && a.signature == b.signature && a.in_signature == b.in_signature;
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
    (fun ("{name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}" "Ptr")
      (let "srec_dst_441"
        (let "srec_dst_438"
          (let "srec_dst_432"
            (let "srec_dst_431"
              (let "srec_dst_430"
                (let "srec_dst_427"
                  (let "srec_dst_426"
                    (let "srec_dst_425" (apply (ext-identifier function_name to-row-binary) (get-field "name" (param 0)) (param 1))
                      (if (is-null (get-field "retention" (param 0))) 
                        (write-u8 (identifier "srec_dst_425") (u8 1)) 
                        (apply (ext-identifier retention to-row-binary) (force (get-field "retention" (param 0))) (write-u8 (identifier "srec_dst_425") (u8 0)))))
                    (write-u8 (identifier "srec_dst_426") (u8-of-bool (get-field "is_lazy" (param 0)))))
                  (write-bytes
                    (let "leb128_sz_428" (make-vec (string-length (get-field "doc" (param 0))))
                      (let "leb128_ptr_429" (make-vec (identifier "srec_dst_427"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_429")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_429"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_428"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_428"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_428"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_428") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_428")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_428")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_429"))))) 
                    (bytes-of-string (get-field "doc" (param 0))))) (apply (ext-identifier raql_operation to-row-binary) (get-field "operation" (param 0)) (identifier "srec_dst_430")))
              (apply (ext-identifier raql_type to-row-binary) (get-field "out_record" (param 0)) (identifier "srec_dst_431")))
            (let "dst_ref_435"
              (make-vec
                (let "leb128_sz_433" (make-vec (cardinality (get-field "factors" (param 0))))
                  (let "leb128_ptr_434" (make-vec (identifier "srec_dst_432"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_434")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_434"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_433"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_433"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_433"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_433") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_433")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_433")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_434"))))))
              (let "n_ref_436" (make-vec (i32 0))
                (seq
                  (for-each "x_437" (get-field "factors" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_435") (apply (ext-identifier field_name to-row-binary) (identifier "x_437") (unsafe-nth (u8 0) (identifier "dst_ref_435"))))
                      (set-vec (u8 0) (identifier "n_ref_436") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_436")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_435"))))))
          (write-bytes
            (let "leb128_sz_439" (make-vec (string-length (get-field "signature" (param 0))))
              (let "leb128_ptr_440" (make-vec (identifier "srec_dst_438"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_440")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_440"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_439"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_439"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_439"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_439") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_439")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_439")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_440"))))) 
            (bytes-of-string (get-field "signature" (param 0)))))
        (write-bytes
          (let "leb128_sz_442" (make-vec (string-length (get-field "in_signature" (param 0))))
            (let "leb128_ptr_443" (make-vec (identifier "srec_dst_441"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_443")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_443"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_442"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_442"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_442"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_442") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_442")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_442")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_443"))))) 
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
      Pointer srec_dst_425 { id_3 };
      std::optional<dessser::gen::retention::t_ext> id_5 { (*p_0).retention };
      bool id_6 { !(id_5.has_value ()) };
      Pointer choose_res_7;
      if (id_6) {
        uint8_t id_8 { 1 };
        Pointer id_9 { srec_dst_425.writeU8(id_8) };
        choose_res_7 = id_9;
      } else {
        auto fun10 { dessser::gen::retention::to_row_binary };
        std::optional<dessser::gen::retention::t_ext> id_11 { (*p_0).retention };
        dessser::gen::retention::t_ext id_12 { id_11.value() };
        uint8_t id_13 { 0 };
        Pointer id_14 { srec_dst_425.writeU8(id_13) };
        Pointer id_15 { fun10(id_12, id_14) };
        choose_res_7 = id_15;
      }
      let_res_4 = choose_res_7;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_426 { let_res_4 };
      bool id_17 { (*p_0).is_lazy };
      uint8_t id_18 { uint8_t(id_17) };
      Pointer id_19 { srec_dst_426.writeU8(id_18) };
      let_res_16 = id_19;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_427 { let_res_16 };
      std::string id_21 { (*p_0).doc };
      uint32_t id_22 { (uint32_t)id_21.size() };
      Vec<1, uint32_t> id_23 {  id_22  };
      Pointer let_res_24;
      {
        Vec<1, uint32_t> leb128_sz_428 { id_23 };
        Vec<1, Pointer> id_25 {  srec_dst_427  };
        Pointer let_res_26;
        {
          Vec<1, Pointer> leb128_ptr_429 { id_25 };
          bool while_flag_27 { true };
          do {
            uint8_t id_28 { 0 };
            uint8_t id_29 { 0 };
            Pointer id_30 { leb128_ptr_429[id_29] };
            uint32_t id_31 { 128U };
            uint8_t id_32 { 0 };
            uint32_t id_33 { leb128_sz_428[id_32] };
            bool id_34 { bool(id_31 > id_33) };
            uint8_t choose_res_35;
            if (id_34) {
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_428[id_36] };
              uint8_t id_38 { uint8_t(id_37) };
              choose_res_35 = id_38;
            } else {
              uint8_t id_39 { 0 };
              uint32_t id_40 { leb128_sz_428[id_39] };
              uint8_t id_41 { uint8_t(id_40) };
              uint8_t id_42 { 128 };
              uint8_t id_43 { uint8_t(id_41 | id_42) };
              choose_res_35 = id_43;
            }
            Pointer id_44 { id_30.writeU8(choose_res_35) };
            Void id_45 { ((void)(leb128_ptr_429[id_28] = id_44), ::dessser::Void()) };
            (void)id_45;
            uint8_t id_46 { 0 };
            uint8_t id_47 { 0 };
            uint32_t id_48 { leb128_sz_428[id_47] };
            uint8_t id_49 { 7 };
            uint32_t id_50 { uint32_t(id_48 >> id_49) };
            Void id_51 { ((void)(leb128_sz_428[id_46] = id_50), ::dessser::Void()) };
            (void)id_51;
            uint8_t id_52 { 0 };
            uint32_t id_53 { leb128_sz_428[id_52] };
            uint32_t id_54 { 0U };
            bool id_55 { bool(id_53 > id_54) };
            while_flag_27 = id_55;
            if (while_flag_27) {
              (void)::dessser::Void();
            }
          } while (while_flag_27);
          (void)::dessser::Void();
          uint8_t id_56 { 0 };
          Pointer id_57 { leb128_ptr_429[id_56] };
          let_res_26 = id_57;
        }
        let_res_24 = let_res_26;
      }
      std::string id_58 { (*p_0).doc };
      Bytes id_59 { id_58 };
      Pointer id_60 { let_res_24.writeBytes(id_59) };
      let_res_20 = id_60;
    }
    Pointer let_res_61;
    {
      Pointer srec_dst_430 { let_res_20 };
      auto fun62 { dessser::gen::raql_operation::to_row_binary };
      dessser::gen::raql_operation::t_ext id_63 { (*p_0).operation };
      Pointer id_64 { fun62(id_63, srec_dst_430) };
      let_res_61 = id_64;
    }
    Pointer let_res_65;
    {
      Pointer srec_dst_431 { let_res_61 };
      auto fun66 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t_ext id_67 { (*p_0).out_record };
      Pointer id_68 { fun66(id_67, srec_dst_431) };
      let_res_65 = id_68;
    }
    Pointer let_res_69;
    {
      Pointer srec_dst_432 { let_res_65 };
      Lst<dessser::gen::field_name::t_ext> id_70 { (*p_0).factors };
      uint32_t id_71 { id_70.size() };
      Vec<1, uint32_t> id_72 {  id_71  };
      Pointer let_res_73;
      {
        Vec<1, uint32_t> leb128_sz_433 { id_72 };
        Vec<1, Pointer> id_74 {  srec_dst_432  };
        Pointer let_res_75;
        {
          Vec<1, Pointer> leb128_ptr_434 { id_74 };
          bool while_flag_76 { true };
          do {
            uint8_t id_77 { 0 };
            uint8_t id_78 { 0 };
            Pointer id_79 { leb128_ptr_434[id_78] };
            uint32_t id_80 { 128U };
            uint8_t id_81 { 0 };
            uint32_t id_82 { leb128_sz_433[id_81] };
            bool id_83 { bool(id_80 > id_82) };
            uint8_t choose_res_84;
            if (id_83) {
              uint8_t id_85 { 0 };
              uint32_t id_86 { leb128_sz_433[id_85] };
              uint8_t id_87 { uint8_t(id_86) };
              choose_res_84 = id_87;
            } else {
              uint8_t id_88 { 0 };
              uint32_t id_89 { leb128_sz_433[id_88] };
              uint8_t id_90 { uint8_t(id_89) };
              uint8_t id_91 { 128 };
              uint8_t id_92 { uint8_t(id_90 | id_91) };
              choose_res_84 = id_92;
            }
            Pointer id_93 { id_79.writeU8(choose_res_84) };
            Void id_94 { ((void)(leb128_ptr_434[id_77] = id_93), ::dessser::Void()) };
            (void)id_94;
            uint8_t id_95 { 0 };
            uint8_t id_96 { 0 };
            uint32_t id_97 { leb128_sz_433[id_96] };
            uint8_t id_98 { 7 };
            uint32_t id_99 { uint32_t(id_97 >> id_98) };
            Void id_100 { ((void)(leb128_sz_433[id_95] = id_99), ::dessser::Void()) };
            (void)id_100;
            uint8_t id_101 { 0 };
            uint32_t id_102 { leb128_sz_433[id_101] };
            uint32_t id_103 { 0U };
            bool id_104 { bool(id_102 > id_103) };
            while_flag_76 = id_104;
            if (while_flag_76) {
              (void)::dessser::Void();
            }
          } while (while_flag_76);
          (void)::dessser::Void();
          uint8_t id_105 { 0 };
          Pointer id_106 { leb128_ptr_434[id_105] };
          let_res_75 = id_106;
        }
        let_res_73 = let_res_75;
      }
      Vec<1, Pointer> id_107 {  let_res_73  };
      Pointer let_res_108;
      {
        Vec<1, Pointer> dst_ref_435 { id_107 };
        int32_t id_109 { 0L };
        Vec<1, int32_t> id_110 {  id_109  };
        Pointer let_res_111;
        {
          Vec<1, int32_t> n_ref_436 { id_110 };
          Lst<dessser::gen::field_name::t_ext> id_112 { (*p_0).factors };
          for (dessser::gen::field_name::t_ext &x_437 : id_112) {
            uint8_t id_113 { 0 };
            auto fun114 { dessser::gen::field_name::to_row_binary };
            uint8_t id_115 { 0 };
            Pointer id_116 { dst_ref_435[id_115] };
            Pointer id_117 { fun114(x_437, id_116) };
            Void id_118 { ((void)(dst_ref_435[id_113] = id_117), ::dessser::Void()) };
            (void)id_118;
            uint8_t id_119 { 0 };
            int32_t id_120 { 1L };
            uint8_t id_121 { 0 };
            int32_t id_122 { n_ref_436[id_121] };
            int32_t id_123 { int32_t(id_120 + id_122) };
            Void id_124 { ((void)(n_ref_436[id_119] = id_123), ::dessser::Void()) };
            (void)id_124;
            (void)id_124;
          }
          (void)::dessser::Void();
          uint8_t id_125 { 0 };
          Pointer id_126 { dst_ref_435[id_125] };
          let_res_111 = id_126;
        }
        let_res_108 = let_res_111;
      }
      let_res_69 = let_res_108;
    }
    Pointer let_res_127;
    {
      Pointer srec_dst_438 { let_res_69 };
      std::string id_128 { (*p_0).signature };
      uint32_t id_129 { (uint32_t)id_128.size() };
      Vec<1, uint32_t> id_130 {  id_129  };
      Pointer let_res_131;
      {
        Vec<1, uint32_t> leb128_sz_439 { id_130 };
        Vec<1, Pointer> id_132 {  srec_dst_438  };
        Pointer let_res_133;
        {
          Vec<1, Pointer> leb128_ptr_440 { id_132 };
          bool while_flag_134 { true };
          do {
            uint8_t id_135 { 0 };
            uint8_t id_136 { 0 };
            Pointer id_137 { leb128_ptr_440[id_136] };
            uint32_t id_138 { 128U };
            uint8_t id_139 { 0 };
            uint32_t id_140 { leb128_sz_439[id_139] };
            bool id_141 { bool(id_138 > id_140) };
            uint8_t choose_res_142;
            if (id_141) {
              uint8_t id_143 { 0 };
              uint32_t id_144 { leb128_sz_439[id_143] };
              uint8_t id_145 { uint8_t(id_144) };
              choose_res_142 = id_145;
            } else {
              uint8_t id_146 { 0 };
              uint32_t id_147 { leb128_sz_439[id_146] };
              uint8_t id_148 { uint8_t(id_147) };
              uint8_t id_149 { 128 };
              uint8_t id_150 { uint8_t(id_148 | id_149) };
              choose_res_142 = id_150;
            }
            Pointer id_151 { id_137.writeU8(choose_res_142) };
            Void id_152 { ((void)(leb128_ptr_440[id_135] = id_151), ::dessser::Void()) };
            (void)id_152;
            uint8_t id_153 { 0 };
            uint8_t id_154 { 0 };
            uint32_t id_155 { leb128_sz_439[id_154] };
            uint8_t id_156 { 7 };
            uint32_t id_157 { uint32_t(id_155 >> id_156) };
            Void id_158 { ((void)(leb128_sz_439[id_153] = id_157), ::dessser::Void()) };
            (void)id_158;
            uint8_t id_159 { 0 };
            uint32_t id_160 { leb128_sz_439[id_159] };
            uint32_t id_161 { 0U };
            bool id_162 { bool(id_160 > id_161) };
            while_flag_134 = id_162;
            if (while_flag_134) {
              (void)::dessser::Void();
            }
          } while (while_flag_134);
          (void)::dessser::Void();
          uint8_t id_163 { 0 };
          Pointer id_164 { leb128_ptr_440[id_163] };
          let_res_133 = id_164;
        }
        let_res_131 = let_res_133;
      }
      std::string id_165 { (*p_0).signature };
      Bytes id_166 { id_165 };
      Pointer id_167 { let_res_131.writeBytes(id_166) };
      let_res_127 = id_167;
    }
    Pointer let_res_168;
    {
      Pointer srec_dst_441 { let_res_127 };
      std::string id_169 { (*p_0).in_signature };
      uint32_t id_170 { (uint32_t)id_169.size() };
      Vec<1, uint32_t> id_171 {  id_170  };
      Pointer let_res_172;
      {
        Vec<1, uint32_t> leb128_sz_442 { id_171 };
        Vec<1, Pointer> id_173 {  srec_dst_441  };
        Pointer let_res_174;
        {
          Vec<1, Pointer> leb128_ptr_443 { id_173 };
          bool while_flag_175 { true };
          do {
            uint8_t id_176 { 0 };
            uint8_t id_177 { 0 };
            Pointer id_178 { leb128_ptr_443[id_177] };
            uint32_t id_179 { 128U };
            uint8_t id_180 { 0 };
            uint32_t id_181 { leb128_sz_442[id_180] };
            bool id_182 { bool(id_179 > id_181) };
            uint8_t choose_res_183;
            if (id_182) {
              uint8_t id_184 { 0 };
              uint32_t id_185 { leb128_sz_442[id_184] };
              uint8_t id_186 { uint8_t(id_185) };
              choose_res_183 = id_186;
            } else {
              uint8_t id_187 { 0 };
              uint32_t id_188 { leb128_sz_442[id_187] };
              uint8_t id_189 { uint8_t(id_188) };
              uint8_t id_190 { 128 };
              uint8_t id_191 { uint8_t(id_189 | id_190) };
              choose_res_183 = id_191;
            }
            Pointer id_192 { id_178.writeU8(choose_res_183) };
            Void id_193 { ((void)(leb128_ptr_443[id_176] = id_192), ::dessser::Void()) };
            (void)id_193;
            uint8_t id_194 { 0 };
            uint8_t id_195 { 0 };
            uint32_t id_196 { leb128_sz_442[id_195] };
            uint8_t id_197 { 7 };
            uint32_t id_198 { uint32_t(id_196 >> id_197) };
            Void id_199 { ((void)(leb128_sz_442[id_194] = id_198), ::dessser::Void()) };
            (void)id_199;
            uint8_t id_200 { 0 };
            uint32_t id_201 { leb128_sz_442[id_200] };
            uint32_t id_202 { 0U };
            bool id_203 { bool(id_201 > id_202) };
            while_flag_175 = id_203;
            if (while_flag_175) {
              (void)::dessser::Void();
            }
          } while (while_flag_175);
          (void)::dessser::Void();
          uint8_t id_204 { 0 };
          Pointer id_205 { leb128_ptr_443[id_204] };
          let_res_174 = id_205;
        }
        let_res_172 = let_res_174;
      }
      std::string id_206 { (*p_0).in_signature };
      Bytes id_207 { id_206 };
      Pointer id_208 { let_res_172.writeBytes(id_207) };
      let_res_168 = id_208;
    }
    return let_res_168;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_func> ,Pointer)> compiled_func_to_row_binary(compiled_func_to_row_binary_init());

/* 
    (fun ("{default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}" "Ptr")
      (let "srec_dst_462"
        (let "srec_dst_456"
          (let "srec_dst_450"
            (let "srec_dst_449"
              (let "dst_ref_446"
                (make-vec
                  (let "leb128_sz_444" (make-vec (cardinality (get-field "default_params" (param 0))))
                    (let "leb128_ptr_445" (make-vec (param 1))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_445")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_445"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_444"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_444"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_444"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_444") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_444")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_444")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_445"))))))
                (let "n_ref_447" (make-vec (i32 0))
                  (seq
                    (for-each "x_448" (get-field "default_params" (param 0))
                      (seq (set-vec (u8 0) (identifier "dst_ref_446") (apply (ext-identifier program_parameter to-row-binary) (identifier "x_448") (unsafe-nth (u8 0) (identifier "dst_ref_446"))))
                        (set-vec (u8 0) (identifier "n_ref_447") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_447")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_446"))))) 
              (apply (ext-identifier raql_expr to-row-binary) (get-field "condition" (param 0)) (identifier "srec_dst_449")))
            (let "dst_ref_453"
              (make-vec
                (let "leb128_sz_451" (make-vec (cardinality (get-field "globals" (param 0))))
                  (let "leb128_ptr_452" (make-vec (identifier "srec_dst_450"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_452")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_452"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_451"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_451"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_451"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_451") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_451")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_451")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_452"))))))
              (let "n_ref_454" (make-vec (i32 0))
                (seq
                  (for-each "x_455" (get-field "globals" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_453") (apply (ext-identifier global_variable to-row-binary) (identifier "x_455") (unsafe-nth (u8 0) (identifier "dst_ref_453"))))
                      (set-vec (u8 0) (identifier "n_ref_454") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_454")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_453"))))))
          (let "dst_ref_459"
            (make-vec
              (let "leb128_sz_457" (make-vec (cardinality (get-field "funcs" (param 0))))
                (let "leb128_ptr_458" (make-vec (identifier "srec_dst_456"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_458")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_458"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_457"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_457"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_457"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_457") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_457")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_457")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_458"))))))
            (let "n_ref_460" (make-vec (i32 0))
              (seq
                (for-each "x_461" (get-field "funcs" (param 0))
                  (seq (set-vec (u8 0) (identifier "dst_ref_459") (apply (identifier "compiled_func-to-row-binary") (identifier "x_461") (unsafe-nth (u8 0) (identifier "dst_ref_459"))))
                    (set-vec (u8 0) (identifier "n_ref_460") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_460")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_459"))))))
        (let "dst_ref_465"
          (make-vec
            (let "leb128_sz_463" (make-vec (cardinality (get-field "warnings" (param 0))))
              (let "leb128_ptr_464" (make-vec (identifier "srec_dst_462"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_464")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_464"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_463"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_463"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_463"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_463") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_463")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_463")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_464"))))))
          (let "n_ref_466" (make-vec (i32 0))
            (seq
              (for-each "x_467" (get-field "warnings" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_465") (apply (ext-identifier raql_warning to-row-binary) (identifier "x_467") (unsafe-nth (u8 0) (identifier "dst_ref_465"))))
                  (set-vec (u8 0) (identifier "n_ref_466") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_466")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_465")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> fun209 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_program>  p_0, Pointer p_1) {
    Lst<dessser::gen::program_parameter::t_ext> id_210 { (*p_0).default_params };
    uint32_t id_211 { id_210.size() };
    Vec<1, uint32_t> id_212 {  id_211  };
    Pointer let_res_213;
    {
      Vec<1, uint32_t> leb128_sz_444 { id_212 };
      Vec<1, Pointer> id_214 {  p_1  };
      Pointer let_res_215;
      {
        Vec<1, Pointer> leb128_ptr_445 { id_214 };
        bool while_flag_216 { true };
        do {
          uint8_t id_217 { 0 };
          uint8_t id_218 { 0 };
          Pointer id_219 { leb128_ptr_445[id_218] };
          uint32_t id_220 { 128U };
          uint8_t id_221 { 0 };
          uint32_t id_222 { leb128_sz_444[id_221] };
          bool id_223 { bool(id_220 > id_222) };
          uint8_t choose_res_224;
          if (id_223) {
            uint8_t id_225 { 0 };
            uint32_t id_226 { leb128_sz_444[id_225] };
            uint8_t id_227 { uint8_t(id_226) };
            choose_res_224 = id_227;
          } else {
            uint8_t id_228 { 0 };
            uint32_t id_229 { leb128_sz_444[id_228] };
            uint8_t id_230 { uint8_t(id_229) };
            uint8_t id_231 { 128 };
            uint8_t id_232 { uint8_t(id_230 | id_231) };
            choose_res_224 = id_232;
          }
          Pointer id_233 { id_219.writeU8(choose_res_224) };
          Void id_234 { ((void)(leb128_ptr_445[id_217] = id_233), ::dessser::Void()) };
          (void)id_234;
          uint8_t id_235 { 0 };
          uint8_t id_236 { 0 };
          uint32_t id_237 { leb128_sz_444[id_236] };
          uint8_t id_238 { 7 };
          uint32_t id_239 { uint32_t(id_237 >> id_238) };
          Void id_240 { ((void)(leb128_sz_444[id_235] = id_239), ::dessser::Void()) };
          (void)id_240;
          uint8_t id_241 { 0 };
          uint32_t id_242 { leb128_sz_444[id_241] };
          uint32_t id_243 { 0U };
          bool id_244 { bool(id_242 > id_243) };
          while_flag_216 = id_244;
          if (while_flag_216) {
            (void)::dessser::Void();
          }
        } while (while_flag_216);
        (void)::dessser::Void();
        uint8_t id_245 { 0 };
        Pointer id_246 { leb128_ptr_445[id_245] };
        let_res_215 = id_246;
      }
      let_res_213 = let_res_215;
    }
    Vec<1, Pointer> id_247 {  let_res_213  };
    Pointer let_res_248;
    {
      Vec<1, Pointer> dst_ref_446 { id_247 };
      int32_t id_249 { 0L };
      Vec<1, int32_t> id_250 {  id_249  };
      Pointer let_res_251;
      {
        Vec<1, int32_t> n_ref_447 { id_250 };
        Lst<dessser::gen::program_parameter::t_ext> id_252 { (*p_0).default_params };
        for (dessser::gen::program_parameter::t_ext &x_448 : id_252) {
          uint8_t id_253 { 0 };
          auto fun254 { dessser::gen::program_parameter::to_row_binary };
          uint8_t id_255 { 0 };
          Pointer id_256 { dst_ref_446[id_255] };
          Pointer id_257 { fun254(x_448, id_256) };
          Void id_258 { ((void)(dst_ref_446[id_253] = id_257), ::dessser::Void()) };
          (void)id_258;
          uint8_t id_259 { 0 };
          int32_t id_260 { 1L };
          uint8_t id_261 { 0 };
          int32_t id_262 { n_ref_447[id_261] };
          int32_t id_263 { int32_t(id_260 + id_262) };
          Void id_264 { ((void)(n_ref_447[id_259] = id_263), ::dessser::Void()) };
          (void)id_264;
          (void)id_264;
        }
        (void)::dessser::Void();
        uint8_t id_265 { 0 };
        Pointer id_266 { dst_ref_446[id_265] };
        let_res_251 = id_266;
      }
      let_res_248 = let_res_251;
    }
    Pointer let_res_267;
    {
      Pointer srec_dst_449 { let_res_248 };
      auto fun268 { dessser::gen::raql_expr::to_row_binary };
      dessser::gen::raql_expr::t_ext id_269 { (*p_0).condition };
      Pointer id_270 { fun268(id_269, srec_dst_449) };
      let_res_267 = id_270;
    }
    Pointer let_res_271;
    {
      Pointer srec_dst_450 { let_res_267 };
      Lst<dessser::gen::global_variable::t_ext> id_272 { (*p_0).globals };
      uint32_t id_273 { id_272.size() };
      Vec<1, uint32_t> id_274 {  id_273  };
      Pointer let_res_275;
      {
        Vec<1, uint32_t> leb128_sz_451 { id_274 };
        Vec<1, Pointer> id_276 {  srec_dst_450  };
        Pointer let_res_277;
        {
          Vec<1, Pointer> leb128_ptr_452 { id_276 };
          bool while_flag_278 { true };
          do {
            uint8_t id_279 { 0 };
            uint8_t id_280 { 0 };
            Pointer id_281 { leb128_ptr_452[id_280] };
            uint32_t id_282 { 128U };
            uint8_t id_283 { 0 };
            uint32_t id_284 { leb128_sz_451[id_283] };
            bool id_285 { bool(id_282 > id_284) };
            uint8_t choose_res_286;
            if (id_285) {
              uint8_t id_287 { 0 };
              uint32_t id_288 { leb128_sz_451[id_287] };
              uint8_t id_289 { uint8_t(id_288) };
              choose_res_286 = id_289;
            } else {
              uint8_t id_290 { 0 };
              uint32_t id_291 { leb128_sz_451[id_290] };
              uint8_t id_292 { uint8_t(id_291) };
              uint8_t id_293 { 128 };
              uint8_t id_294 { uint8_t(id_292 | id_293) };
              choose_res_286 = id_294;
            }
            Pointer id_295 { id_281.writeU8(choose_res_286) };
            Void id_296 { ((void)(leb128_ptr_452[id_279] = id_295), ::dessser::Void()) };
            (void)id_296;
            uint8_t id_297 { 0 };
            uint8_t id_298 { 0 };
            uint32_t id_299 { leb128_sz_451[id_298] };
            uint8_t id_300 { 7 };
            uint32_t id_301 { uint32_t(id_299 >> id_300) };
            Void id_302 { ((void)(leb128_sz_451[id_297] = id_301), ::dessser::Void()) };
            (void)id_302;
            uint8_t id_303 { 0 };
            uint32_t id_304 { leb128_sz_451[id_303] };
            uint32_t id_305 { 0U };
            bool id_306 { bool(id_304 > id_305) };
            while_flag_278 = id_306;
            if (while_flag_278) {
              (void)::dessser::Void();
            }
          } while (while_flag_278);
          (void)::dessser::Void();
          uint8_t id_307 { 0 };
          Pointer id_308 { leb128_ptr_452[id_307] };
          let_res_277 = id_308;
        }
        let_res_275 = let_res_277;
      }
      Vec<1, Pointer> id_309 {  let_res_275  };
      Pointer let_res_310;
      {
        Vec<1, Pointer> dst_ref_453 { id_309 };
        int32_t id_311 { 0L };
        Vec<1, int32_t> id_312 {  id_311  };
        Pointer let_res_313;
        {
          Vec<1, int32_t> n_ref_454 { id_312 };
          Lst<dessser::gen::global_variable::t_ext> id_314 { (*p_0).globals };
          for (dessser::gen::global_variable::t_ext &x_455 : id_314) {
            uint8_t id_315 { 0 };
            auto fun316 { dessser::gen::global_variable::to_row_binary };
            uint8_t id_317 { 0 };
            Pointer id_318 { dst_ref_453[id_317] };
            Pointer id_319 { fun316(x_455, id_318) };
            Void id_320 { ((void)(dst_ref_453[id_315] = id_319), ::dessser::Void()) };
            (void)id_320;
            uint8_t id_321 { 0 };
            int32_t id_322 { 1L };
            uint8_t id_323 { 0 };
            int32_t id_324 { n_ref_454[id_323] };
            int32_t id_325 { int32_t(id_322 + id_324) };
            Void id_326 { ((void)(n_ref_454[id_321] = id_325), ::dessser::Void()) };
            (void)id_326;
            (void)id_326;
          }
          (void)::dessser::Void();
          uint8_t id_327 { 0 };
          Pointer id_328 { dst_ref_453[id_327] };
          let_res_313 = id_328;
        }
        let_res_310 = let_res_313;
      }
      let_res_271 = let_res_310;
    }
    Pointer let_res_329;
    {
      Pointer srec_dst_456 { let_res_271 };
      Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_330 { (*p_0).funcs };
      uint32_t id_331 { id_330.size() };
      Vec<1, uint32_t> id_332 {  id_331  };
      Pointer let_res_333;
      {
        Vec<1, uint32_t> leb128_sz_457 { id_332 };
        Vec<1, Pointer> id_334 {  srec_dst_456  };
        Pointer let_res_335;
        {
          Vec<1, Pointer> leb128_ptr_458 { id_334 };
          bool while_flag_336 { true };
          do {
            uint8_t id_337 { 0 };
            uint8_t id_338 { 0 };
            Pointer id_339 { leb128_ptr_458[id_338] };
            uint32_t id_340 { 128U };
            uint8_t id_341 { 0 };
            uint32_t id_342 { leb128_sz_457[id_341] };
            bool id_343 { bool(id_340 > id_342) };
            uint8_t choose_res_344;
            if (id_343) {
              uint8_t id_345 { 0 };
              uint32_t id_346 { leb128_sz_457[id_345] };
              uint8_t id_347 { uint8_t(id_346) };
              choose_res_344 = id_347;
            } else {
              uint8_t id_348 { 0 };
              uint32_t id_349 { leb128_sz_457[id_348] };
              uint8_t id_350 { uint8_t(id_349) };
              uint8_t id_351 { 128 };
              uint8_t id_352 { uint8_t(id_350 | id_351) };
              choose_res_344 = id_352;
            }
            Pointer id_353 { id_339.writeU8(choose_res_344) };
            Void id_354 { ((void)(leb128_ptr_458[id_337] = id_353), ::dessser::Void()) };
            (void)id_354;
            uint8_t id_355 { 0 };
            uint8_t id_356 { 0 };
            uint32_t id_357 { leb128_sz_457[id_356] };
            uint8_t id_358 { 7 };
            uint32_t id_359 { uint32_t(id_357 >> id_358) };
            Void id_360 { ((void)(leb128_sz_457[id_355] = id_359), ::dessser::Void()) };
            (void)id_360;
            uint8_t id_361 { 0 };
            uint32_t id_362 { leb128_sz_457[id_361] };
            uint32_t id_363 { 0U };
            bool id_364 { bool(id_362 > id_363) };
            while_flag_336 = id_364;
            if (while_flag_336) {
              (void)::dessser::Void();
            }
          } while (while_flag_336);
          (void)::dessser::Void();
          uint8_t id_365 { 0 };
          Pointer id_366 { leb128_ptr_458[id_365] };
          let_res_335 = id_366;
        }
        let_res_333 = let_res_335;
      }
      Vec<1, Pointer> id_367 {  let_res_333  };
      Pointer let_res_368;
      {
        Vec<1, Pointer> dst_ref_459 { id_367 };
        int32_t id_369 { 0L };
        Vec<1, int32_t> id_370 {  id_369  };
        Pointer let_res_371;
        {
          Vec<1, int32_t> n_ref_460 { id_370 };
          Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_372 { (*p_0).funcs };
          for (std::shared_ptr<::dessser::gen::source_info::compiled_func>  &x_461 : id_372) {
            uint8_t id_373 { 0 };
            uint8_t id_374 { 0 };
            Pointer id_375 { dst_ref_459[id_374] };
            Pointer id_376 { compiled_func_to_row_binary(x_461, id_375) };
            Void id_377 { ((void)(dst_ref_459[id_373] = id_376), ::dessser::Void()) };
            (void)id_377;
            uint8_t id_378 { 0 };
            int32_t id_379 { 1L };
            uint8_t id_380 { 0 };
            int32_t id_381 { n_ref_460[id_380] };
            int32_t id_382 { int32_t(id_379 + id_381) };
            Void id_383 { ((void)(n_ref_460[id_378] = id_382), ::dessser::Void()) };
            (void)id_383;
            (void)id_383;
          }
          (void)::dessser::Void();
          uint8_t id_384 { 0 };
          Pointer id_385 { dst_ref_459[id_384] };
          let_res_371 = id_385;
        }
        let_res_368 = let_res_371;
      }
      let_res_329 = let_res_368;
    }
    Pointer let_res_386;
    {
      Pointer srec_dst_462 { let_res_329 };
      Lst<dessser::gen::raql_warning::t_ext> id_387 { (*p_0).warnings };
      uint32_t id_388 { id_387.size() };
      Vec<1, uint32_t> id_389 {  id_388  };
      Pointer let_res_390;
      {
        Vec<1, uint32_t> leb128_sz_463 { id_389 };
        Vec<1, Pointer> id_391 {  srec_dst_462  };
        Pointer let_res_392;
        {
          Vec<1, Pointer> leb128_ptr_464 { id_391 };
          bool while_flag_393 { true };
          do {
            uint8_t id_394 { 0 };
            uint8_t id_395 { 0 };
            Pointer id_396 { leb128_ptr_464[id_395] };
            uint32_t id_397 { 128U };
            uint8_t id_398 { 0 };
            uint32_t id_399 { leb128_sz_463[id_398] };
            bool id_400 { bool(id_397 > id_399) };
            uint8_t choose_res_401;
            if (id_400) {
              uint8_t id_402 { 0 };
              uint32_t id_403 { leb128_sz_463[id_402] };
              uint8_t id_404 { uint8_t(id_403) };
              choose_res_401 = id_404;
            } else {
              uint8_t id_405 { 0 };
              uint32_t id_406 { leb128_sz_463[id_405] };
              uint8_t id_407 { uint8_t(id_406) };
              uint8_t id_408 { 128 };
              uint8_t id_409 { uint8_t(id_407 | id_408) };
              choose_res_401 = id_409;
            }
            Pointer id_410 { id_396.writeU8(choose_res_401) };
            Void id_411 { ((void)(leb128_ptr_464[id_394] = id_410), ::dessser::Void()) };
            (void)id_411;
            uint8_t id_412 { 0 };
            uint8_t id_413 { 0 };
            uint32_t id_414 { leb128_sz_463[id_413] };
            uint8_t id_415 { 7 };
            uint32_t id_416 { uint32_t(id_414 >> id_415) };
            Void id_417 { ((void)(leb128_sz_463[id_412] = id_416), ::dessser::Void()) };
            (void)id_417;
            uint8_t id_418 { 0 };
            uint32_t id_419 { leb128_sz_463[id_418] };
            uint32_t id_420 { 0U };
            bool id_421 { bool(id_419 > id_420) };
            while_flag_393 = id_421;
            if (while_flag_393) {
              (void)::dessser::Void();
            }
          } while (while_flag_393);
          (void)::dessser::Void();
          uint8_t id_422 { 0 };
          Pointer id_423 { leb128_ptr_464[id_422] };
          let_res_392 = id_423;
        }
        let_res_390 = let_res_392;
      }
      Vec<1, Pointer> id_424 {  let_res_390  };
      Pointer let_res_425;
      {
        Vec<1, Pointer> dst_ref_465 { id_424 };
        int32_t id_426 { 0L };
        Vec<1, int32_t> id_427 {  id_426  };
        Pointer let_res_428;
        {
          Vec<1, int32_t> n_ref_466 { id_427 };
          Lst<dessser::gen::raql_warning::t_ext> id_429 { (*p_0).warnings };
          for (dessser::gen::raql_warning::t_ext &x_467 : id_429) {
            uint8_t id_430 { 0 };
            auto fun431 { dessser::gen::raql_warning::to_row_binary };
            uint8_t id_432 { 0 };
            Pointer id_433 { dst_ref_465[id_432] };
            Pointer id_434 { fun431(x_467, id_433) };
            Void id_435 { ((void)(dst_ref_465[id_430] = id_434), ::dessser::Void()) };
            (void)id_435;
            uint8_t id_436 { 0 };
            int32_t id_437 { 1L };
            uint8_t id_438 { 0 };
            int32_t id_439 { n_ref_466[id_438] };
            int32_t id_440 { int32_t(id_437 + id_439) };
            Void id_441 { ((void)(n_ref_466[id_436] = id_440), ::dessser::Void()) };
            (void)id_441;
            (void)id_441;
          }
          (void)::dessser::Void();
          uint8_t id_442 { 0 };
          Pointer id_443 { dst_ref_465[id_442] };
          let_res_428 = id_443;
        }
        let_res_425 = let_res_428;
      }
      let_res_386 = let_res_425;
    }
    return let_res_386;
  }
   };
  return fun209;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary(compiled_program_to_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]}" "Ptr")
      (let "srec_dst_478"
        (let "srec_dst_470"
          (write-bytes
            (let "leb128_sz_468" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "leb128_ptr_469" (make-vec (param 1))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_469")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_469"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_468"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_468"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_468"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_468") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_468")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_468")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_469"))))) 
            (bytes-of-string (get-field "src_ext" (param 0))))
          (let "dst_ref_473"
            (make-vec
              (let "leb128_sz_471" (make-vec (cardinality (get-field "md5s" (param 0))))
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
                (for-each "x_475" (get-field "md5s" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_473")
                      (write-bytes
                        (let "leb128_sz_476" (make-vec (string-length (identifier "x_475")))
                          (let "leb128_ptr_477" (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_473")))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_477")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_477"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_476"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_476"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_476"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_476") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_476")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_476")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_477"))))) 
                        (bytes-of-string (identifier "x_475")))) (set-vec (u8 0) (identifier "n_ref_474") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_474")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_473"))))))
        (let "ssum_dst_480" (write-u16 little-endian (identifier "srec_dst_478") (label-of (get-field "detail" (param 0))))
          (if (eq (u16 0) (label-of (get-field "detail" (param 0)))) 
            (apply (identifier "compiled_program-to-row-binary") (get-alt "Compiled" (get-field "detail" (param 0))) (identifier "ssum_dst_480"))
            (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
              (let "srec_dst_486"
                (let "dst_ref_483"
                  (make-vec
                    (let "leb128_sz_481" (make-vec (cardinality (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))))
                      (let "leb128_ptr_482" (make-vec (identifier "ssum_dst_480"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_482")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_482"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_481"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_481"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_481"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_481") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_481")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_481")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_482"))))))
                  (let "n_ref_484" (make-vec (i32 0))
                    (seq
                      (for-each "x_485" (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))
                        (seq (set-vec (u8 0) (identifier "dst_ref_483") (apply (ext-identifier raql_error to-row-binary) (identifier "x_485") (unsafe-nth (u8 0) (identifier "dst_ref_483"))))
                          (set-vec (u8 0) (identifier "n_ref_484") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_484")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_483")))))
                (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                  (write-u8 (identifier "srec_dst_486") (u8 1))
                  (apply (ext-identifier src_path to-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) (write-u8 (identifier "srec_dst_486") (u8 0))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> fun444 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0, Pointer p_1) {
    std::string id_445 { (*p_0).src_ext };
    uint32_t id_446 { (uint32_t)id_445.size() };
    Vec<1, uint32_t> id_447 {  id_446  };
    Pointer let_res_448;
    {
      Vec<1, uint32_t> leb128_sz_468 { id_447 };
      Vec<1, Pointer> id_449 {  p_1  };
      Pointer let_res_450;
      {
        Vec<1, Pointer> leb128_ptr_469 { id_449 };
        bool while_flag_451 { true };
        do {
          uint8_t id_452 { 0 };
          uint8_t id_453 { 0 };
          Pointer id_454 { leb128_ptr_469[id_453] };
          uint32_t id_455 { 128U };
          uint8_t id_456 { 0 };
          uint32_t id_457 { leb128_sz_468[id_456] };
          bool id_458 { bool(id_455 > id_457) };
          uint8_t choose_res_459;
          if (id_458) {
            uint8_t id_460 { 0 };
            uint32_t id_461 { leb128_sz_468[id_460] };
            uint8_t id_462 { uint8_t(id_461) };
            choose_res_459 = id_462;
          } else {
            uint8_t id_463 { 0 };
            uint32_t id_464 { leb128_sz_468[id_463] };
            uint8_t id_465 { uint8_t(id_464) };
            uint8_t id_466 { 128 };
            uint8_t id_467 { uint8_t(id_465 | id_466) };
            choose_res_459 = id_467;
          }
          Pointer id_468 { id_454.writeU8(choose_res_459) };
          Void id_469 { ((void)(leb128_ptr_469[id_452] = id_468), ::dessser::Void()) };
          (void)id_469;
          uint8_t id_470 { 0 };
          uint8_t id_471 { 0 };
          uint32_t id_472 { leb128_sz_468[id_471] };
          uint8_t id_473 { 7 };
          uint32_t id_474 { uint32_t(id_472 >> id_473) };
          Void id_475 { ((void)(leb128_sz_468[id_470] = id_474), ::dessser::Void()) };
          (void)id_475;
          uint8_t id_476 { 0 };
          uint32_t id_477 { leb128_sz_468[id_476] };
          uint32_t id_478 { 0U };
          bool id_479 { bool(id_477 > id_478) };
          while_flag_451 = id_479;
          if (while_flag_451) {
            (void)::dessser::Void();
          }
        } while (while_flag_451);
        (void)::dessser::Void();
        uint8_t id_480 { 0 };
        Pointer id_481 { leb128_ptr_469[id_480] };
        let_res_450 = id_481;
      }
      let_res_448 = let_res_450;
    }
    std::string id_482 { (*p_0).src_ext };
    Bytes id_483 { id_482 };
    Pointer id_484 { let_res_448.writeBytes(id_483) };
    Pointer let_res_485;
    {
      Pointer srec_dst_470 { id_484 };
      Lst<std::string> id_486 { (*p_0).md5s };
      uint32_t id_487 { id_486.size() };
      Vec<1, uint32_t> id_488 {  id_487  };
      Pointer let_res_489;
      {
        Vec<1, uint32_t> leb128_sz_471 { id_488 };
        Vec<1, Pointer> id_490 {  srec_dst_470  };
        Pointer let_res_491;
        {
          Vec<1, Pointer> leb128_ptr_472 { id_490 };
          bool while_flag_492 { true };
          do {
            uint8_t id_493 { 0 };
            uint8_t id_494 { 0 };
            Pointer id_495 { leb128_ptr_472[id_494] };
            uint32_t id_496 { 128U };
            uint8_t id_497 { 0 };
            uint32_t id_498 { leb128_sz_471[id_497] };
            bool id_499 { bool(id_496 > id_498) };
            uint8_t choose_res_500;
            if (id_499) {
              uint8_t id_501 { 0 };
              uint32_t id_502 { leb128_sz_471[id_501] };
              uint8_t id_503 { uint8_t(id_502) };
              choose_res_500 = id_503;
            } else {
              uint8_t id_504 { 0 };
              uint32_t id_505 { leb128_sz_471[id_504] };
              uint8_t id_506 { uint8_t(id_505) };
              uint8_t id_507 { 128 };
              uint8_t id_508 { uint8_t(id_506 | id_507) };
              choose_res_500 = id_508;
            }
            Pointer id_509 { id_495.writeU8(choose_res_500) };
            Void id_510 { ((void)(leb128_ptr_472[id_493] = id_509), ::dessser::Void()) };
            (void)id_510;
            uint8_t id_511 { 0 };
            uint8_t id_512 { 0 };
            uint32_t id_513 { leb128_sz_471[id_512] };
            uint8_t id_514 { 7 };
            uint32_t id_515 { uint32_t(id_513 >> id_514) };
            Void id_516 { ((void)(leb128_sz_471[id_511] = id_515), ::dessser::Void()) };
            (void)id_516;
            uint8_t id_517 { 0 };
            uint32_t id_518 { leb128_sz_471[id_517] };
            uint32_t id_519 { 0U };
            bool id_520 { bool(id_518 > id_519) };
            while_flag_492 = id_520;
            if (while_flag_492) {
              (void)::dessser::Void();
            }
          } while (while_flag_492);
          (void)::dessser::Void();
          uint8_t id_521 { 0 };
          Pointer id_522 { leb128_ptr_472[id_521] };
          let_res_491 = id_522;
        }
        let_res_489 = let_res_491;
      }
      Vec<1, Pointer> id_523 {  let_res_489  };
      Pointer let_res_524;
      {
        Vec<1, Pointer> dst_ref_473 { id_523 };
        int32_t id_525 { 0L };
        Vec<1, int32_t> id_526 {  id_525  };
        Pointer let_res_527;
        {
          Vec<1, int32_t> n_ref_474 { id_526 };
          Lst<std::string> id_528 { (*p_0).md5s };
          for (std::string const &x_475 : id_528) {
            uint8_t id_529 { 0 };
            uint32_t id_530 { (uint32_t)x_475.size() };
            Vec<1, uint32_t> id_531 {  id_530  };
            Pointer let_res_532;
            {
              Vec<1, uint32_t> leb128_sz_476 { id_531 };
              uint8_t id_533 { 0 };
              Pointer id_534 { dst_ref_473[id_533] };
              Vec<1, Pointer> id_535 {  id_534  };
              Pointer let_res_536;
              {
                Vec<1, Pointer> leb128_ptr_477 { id_535 };
                bool while_flag_537 { true };
                do {
                  uint8_t id_538 { 0 };
                  uint8_t id_539 { 0 };
                  Pointer id_540 { leb128_ptr_477[id_539] };
                  uint32_t id_541 { 128U };
                  uint8_t id_542 { 0 };
                  uint32_t id_543 { leb128_sz_476[id_542] };
                  bool id_544 { bool(id_541 > id_543) };
                  uint8_t choose_res_545;
                  if (id_544) {
                    uint8_t id_546 { 0 };
                    uint32_t id_547 { leb128_sz_476[id_546] };
                    uint8_t id_548 { uint8_t(id_547) };
                    choose_res_545 = id_548;
                  } else {
                    uint8_t id_549 { 0 };
                    uint32_t id_550 { leb128_sz_476[id_549] };
                    uint8_t id_551 { uint8_t(id_550) };
                    uint8_t id_552 { 128 };
                    uint8_t id_553 { uint8_t(id_551 | id_552) };
                    choose_res_545 = id_553;
                  }
                  Pointer id_554 { id_540.writeU8(choose_res_545) };
                  Void id_555 { ((void)(leb128_ptr_477[id_538] = id_554), ::dessser::Void()) };
                  (void)id_555;
                  uint8_t id_556 { 0 };
                  uint8_t id_557 { 0 };
                  uint32_t id_558 { leb128_sz_476[id_557] };
                  uint8_t id_559 { 7 };
                  uint32_t id_560 { uint32_t(id_558 >> id_559) };
                  Void id_561 { ((void)(leb128_sz_476[id_556] = id_560), ::dessser::Void()) };
                  (void)id_561;
                  uint8_t id_562 { 0 };
                  uint32_t id_563 { leb128_sz_476[id_562] };
                  uint32_t id_564 { 0U };
                  bool id_565 { bool(id_563 > id_564) };
                  while_flag_537 = id_565;
                  if (while_flag_537) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_537);
                (void)::dessser::Void();
                uint8_t id_566 { 0 };
                Pointer id_567 { leb128_ptr_477[id_566] };
                let_res_536 = id_567;
              }
              let_res_532 = let_res_536;
            }
            Bytes id_568 { x_475 };
            Pointer id_569 { let_res_532.writeBytes(id_568) };
            Void id_570 { ((void)(dst_ref_473[id_529] = id_569), ::dessser::Void()) };
            (void)id_570;
            uint8_t id_571 { 0 };
            int32_t id_572 { 1L };
            uint8_t id_573 { 0 };
            int32_t id_574 { n_ref_474[id_573] };
            int32_t id_575 { int32_t(id_572 + id_574) };
            Void id_576 { ((void)(n_ref_474[id_571] = id_575), ::dessser::Void()) };
            (void)id_576;
            (void)id_576;
          }
          (void)::dessser::Void();
          uint8_t id_577 { 0 };
          Pointer id_578 { dst_ref_473[id_577] };
          let_res_527 = id_578;
        }
        let_res_524 = let_res_527;
      }
      let_res_485 = let_res_524;
    }
    Pointer let_res_579;
    {
      Pointer srec_dst_478 { let_res_485 };
      ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_580 { (*p_0).detail };
      uint16_t id_581 { uint16_t(id_580.index()) };
      Pointer id_582 { srec_dst_478.writeU16Le(id_581) };
      Pointer let_res_583;
      {
        Pointer ssum_dst_480 { id_582 };
        uint16_t id_584 { 0 };
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_585 { (*p_0).detail };
        uint16_t id_586 { uint16_t(id_585.index()) };
        bool id_587 { bool(id_584 == id_586) };
        Pointer choose_res_588;
        if (id_587) {
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_589 { (*p_0).detail };
          std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_590 { std::get<0 /* Compiled */>(id_589) };
          Pointer id_591 { compiled_program_to_row_binary(id_590, ssum_dst_480) };
          choose_res_588 = id_591;
        } else {
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_592 { (*p_0).detail };
          uint16_t id_593 { uint16_t(id_592.index()) };
          uint16_t id_594 { 1 };
          bool id_595 { bool(id_593 == id_594) };
          Void id_596 { ((void)(assert(id_595)), ::dessser::Void()) };
          (void)id_596;
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_597 { (*p_0).detail };
          ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_598 { std::get<1 /* Failed */>(id_597) };
          Lst<dessser::gen::raql_error::t_ext> id_599 { id_598.errors };
          uint32_t id_600 { id_599.size() };
          Vec<1, uint32_t> id_601 {  id_600  };
          Pointer let_res_602;
          {
            Vec<1, uint32_t> leb128_sz_481 { id_601 };
            Vec<1, Pointer> id_603 {  ssum_dst_480  };
            Pointer let_res_604;
            {
              Vec<1, Pointer> leb128_ptr_482 { id_603 };
              bool while_flag_605 { true };
              do {
                uint8_t id_606 { 0 };
                uint8_t id_607 { 0 };
                Pointer id_608 { leb128_ptr_482[id_607] };
                uint32_t id_609 { 128U };
                uint8_t id_610 { 0 };
                uint32_t id_611 { leb128_sz_481[id_610] };
                bool id_612 { bool(id_609 > id_611) };
                uint8_t choose_res_613;
                if (id_612) {
                  uint8_t id_614 { 0 };
                  uint32_t id_615 { leb128_sz_481[id_614] };
                  uint8_t id_616 { uint8_t(id_615) };
                  choose_res_613 = id_616;
                } else {
                  uint8_t id_617 { 0 };
                  uint32_t id_618 { leb128_sz_481[id_617] };
                  uint8_t id_619 { uint8_t(id_618) };
                  uint8_t id_620 { 128 };
                  uint8_t id_621 { uint8_t(id_619 | id_620) };
                  choose_res_613 = id_621;
                }
                Pointer id_622 { id_608.writeU8(choose_res_613) };
                Void id_623 { ((void)(leb128_ptr_482[id_606] = id_622), ::dessser::Void()) };
                (void)id_623;
                uint8_t id_624 { 0 };
                uint8_t id_625 { 0 };
                uint32_t id_626 { leb128_sz_481[id_625] };
                uint8_t id_627 { 7 };
                uint32_t id_628 { uint32_t(id_626 >> id_627) };
                Void id_629 { ((void)(leb128_sz_481[id_624] = id_628), ::dessser::Void()) };
                (void)id_629;
                uint8_t id_630 { 0 };
                uint32_t id_631 { leb128_sz_481[id_630] };
                uint32_t id_632 { 0U };
                bool id_633 { bool(id_631 > id_632) };
                while_flag_605 = id_633;
                if (while_flag_605) {
                  (void)::dessser::Void();
                }
              } while (while_flag_605);
              (void)::dessser::Void();
              uint8_t id_634 { 0 };
              Pointer id_635 { leb128_ptr_482[id_634] };
              let_res_604 = id_635;
            }
            let_res_602 = let_res_604;
          }
          Vec<1, Pointer> id_636 {  let_res_602  };
          Pointer let_res_637;
          {
            Vec<1, Pointer> dst_ref_483 { id_636 };
            int32_t id_638 { 0L };
            Vec<1, int32_t> id_639 {  id_638  };
            Pointer let_res_640;
            {
              Vec<1, int32_t> n_ref_484 { id_639 };
              ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_641 { (*p_0).detail };
              ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_642 { std::get<1 /* Failed */>(id_641) };
              Lst<dessser::gen::raql_error::t_ext> id_643 { id_642.errors };
              for (dessser::gen::raql_error::t_ext &x_485 : id_643) {
                uint8_t id_644 { 0 };
                auto fun645 { dessser::gen::raql_error::to_row_binary };
                uint8_t id_646 { 0 };
                Pointer id_647 { dst_ref_483[id_646] };
                Pointer id_648 { fun645(x_485, id_647) };
                Void id_649 { ((void)(dst_ref_483[id_644] = id_648), ::dessser::Void()) };
                (void)id_649;
                uint8_t id_650 { 0 };
                int32_t id_651 { 1L };
                uint8_t id_652 { 0 };
                int32_t id_653 { n_ref_484[id_652] };
                int32_t id_654 { int32_t(id_651 + id_653) };
                Void id_655 { ((void)(n_ref_484[id_650] = id_654), ::dessser::Void()) };
                (void)id_655;
                (void)id_655;
              }
              (void)::dessser::Void();
              uint8_t id_656 { 0 };
              Pointer id_657 { dst_ref_483[id_656] };
              let_res_640 = id_657;
            }
            let_res_637 = let_res_640;
          }
          Pointer let_res_658;
          {
            Pointer srec_dst_486 { let_res_637 };
            ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_659 { (*p_0).detail };
            ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_660 { std::get<1 /* Failed */>(id_659) };
            std::optional<dessser::gen::src_path::t_ext> id_661 { id_660.depends_on };
            bool id_662 { !(id_661.has_value ()) };
            Pointer choose_res_663;
            if (id_662) {
              uint8_t id_664 { 1 };
              Pointer id_665 { srec_dst_486.writeU8(id_664) };
              choose_res_663 = id_665;
            } else {
              auto fun666 { dessser::gen::src_path::to_row_binary };
              ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_667 { (*p_0).detail };
              ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_668 { std::get<1 /* Failed */>(id_667) };
              std::optional<dessser::gen::src_path::t_ext> id_669 { id_668.depends_on };
              dessser::gen::src_path::t_ext id_670 { id_669.value() };
              uint8_t id_671 { 0 };
              Pointer id_672 { srec_dst_486.writeU8(id_671) };
              Pointer id_673 { fun666(id_670, id_672) };
              choose_res_663 = id_673;
            }
            let_res_658 = choose_res_663;
          }
          choose_res_588 = let_res_658;
        }
        let_res_583 = choose_res_588;
      }
      let_res_579 = let_res_583;
    }
    return let_res_579;
  }
   };
  return fun444;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}")
      (let "sz_380"
        (let "sz_376"
          (let "sz_371"
            (let "sz_370"
              (let "sz_369"
                (let "sz_365"
                  (add
                    (let "sz_363" (apply (ext-identifier function_name sersize-of-row-binary) (get-field "name" (param 0)))
                      (if (is-null (get-field "retention" (param 0))) 
                        (add (identifier "sz_363") (size 1)) (add (add (identifier "sz_363") (apply (ext-identifier retention sersize-of-row-binary) (force (get-field "retention" (param 0))))) (size 1)))) 
                    (size 1))
                  (add (identifier "sz_365")
                    (add
                      (let "n_ref_367" (make-vec (string-length (get-field "doc" (param 0))))
                        (let "lebsz_ref_368" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_367")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_368")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_368") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_368")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_368")))))) 
                      (size-of-u32 (string-length (get-field "doc" (param 0))))))) 
                (add (identifier "sz_369") (apply (ext-identifier raql_operation sersize-of-row-binary) (get-field "operation" (param 0)))))
              (add (identifier "sz_370") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "out_record" (param 0)))))
            (let "sz_ref_374"
              (make-vec
                (add (identifier "sz_371")
                  (let "n_ref_372" (make-vec (cardinality (get-field "factors" (param 0))))
                    (let "lebsz_ref_373" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_372")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_373")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_373") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_373")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_373"))))))))
              (seq
                (let "repeat_n_375" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "factors" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_375")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_374")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_374")) (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_375")) (get-field "factors" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_375") (add (unsafe-nth (u8 0) (identifier "repeat_n_375")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_374")))))
          (add (identifier "sz_376")
            (add
              (let "n_ref_378" (make-vec (string-length (get-field "signature" (param 0))))
                (let "lebsz_ref_379" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_378")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_379")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_379") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_379")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_379")))))) 
              (size-of-u32 (string-length (get-field "signature" (param 0)))))))
        (add (identifier "sz_380")
          (add
            (let "n_ref_382" (make-vec (string-length (get-field "in_signature" (param 0))))
              (let "lebsz_ref_383" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_382")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_383")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_383") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_383")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_383")))))) 
            (size-of-u32 (string-length (get-field "in_signature" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> fun674 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_func>  p_0) {
    auto fun675 { dessser::gen::function_name::sersize_of_row_binary };
    dessser::gen::function_name::t_ext id_676 { (*p_0).name };
    Size id_677 { fun675(id_676) };
    Size let_res_678;
    {
      Size sz_363 { id_677 };
      std::optional<dessser::gen::retention::t_ext> id_679 { (*p_0).retention };
      bool id_680 { !(id_679.has_value ()) };
      Size choose_res_681;
      if (id_680) {
        Size id_682 { 1UL };
        Size id_683 { Size(sz_363 + id_682) };
        choose_res_681 = id_683;
      } else {
        auto fun684 { dessser::gen::retention::sersize_of_row_binary };
        std::optional<dessser::gen::retention::t_ext> id_685 { (*p_0).retention };
        dessser::gen::retention::t_ext id_686 { id_685.value() };
        Size id_687 { fun684(id_686) };
        Size id_688 { Size(sz_363 + id_687) };
        Size id_689 { 1UL };
        Size id_690 { Size(id_688 + id_689) };
        choose_res_681 = id_690;
      }
      let_res_678 = choose_res_681;
    }
    Size id_691 { 1UL };
    Size id_692 { Size(let_res_678 + id_691) };
    Size let_res_693;
    {
      Size sz_365 { id_692 };
      std::string id_694 { (*p_0).doc };
      uint32_t id_695 { (uint32_t)id_694.size() };
      Vec<1, uint32_t> id_696 {  id_695  };
      Size let_res_697;
      {
        Vec<1, uint32_t> n_ref_367 { id_696 };
        uint32_t id_698 { 1U };
        Vec<1, uint32_t> id_699 {  id_698  };
        Size let_res_700;
        {
          Vec<1, uint32_t> lebsz_ref_368 { id_699 };
          bool while_flag_701 { true };
          do {
            uint8_t id_702 { 0 };
            uint32_t id_703 { n_ref_367[id_702] };
            uint8_t id_704 { 0 };
            uint32_t id_705 { lebsz_ref_368[id_704] };
            uint8_t id_706 { 7 };
            uint32_t id_707 { uint32_t(id_705 << id_706) };
            bool id_708 { bool(id_703 >= id_707) };
            while_flag_701 = id_708;
            if (while_flag_701) {
              uint8_t id_709 { 0 };
              uint8_t id_710 { 0 };
              uint32_t id_711 { lebsz_ref_368[id_710] };
              uint32_t id_712 { 1U };
              uint32_t id_713 { uint32_t(id_711 + id_712) };
              Void id_714 { ((void)(lebsz_ref_368[id_709] = id_713), ::dessser::Void()) };
              (void)id_714;
            }
          } while (while_flag_701);
          (void)::dessser::Void();
          uint8_t id_715 { 0 };
          uint32_t id_716 { lebsz_ref_368[id_715] };
          Size id_717 { Size(id_716) };
          let_res_700 = id_717;
        }
        let_res_697 = let_res_700;
      }
      std::string id_718 { (*p_0).doc };
      uint32_t id_719 { (uint32_t)id_718.size() };
      Size id_720 { Size(id_719) };
      Size id_721 { Size(let_res_697 + id_720) };
      Size id_722 { Size(sz_365 + id_721) };
      let_res_693 = id_722;
    }
    Size let_res_723;
    {
      Size sz_369 { let_res_693 };
      auto fun724 { dessser::gen::raql_operation::sersize_of_row_binary };
      dessser::gen::raql_operation::t_ext id_725 { (*p_0).operation };
      Size id_726 { fun724(id_725) };
      Size id_727 { Size(sz_369 + id_726) };
      let_res_723 = id_727;
    }
    Size let_res_728;
    {
      Size sz_370 { let_res_723 };
      auto fun729 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t_ext id_730 { (*p_0).out_record };
      Size id_731 { fun729(id_730) };
      Size id_732 { Size(sz_370 + id_731) };
      let_res_728 = id_732;
    }
    Size let_res_733;
    {
      Size sz_371 { let_res_728 };
      Lst<dessser::gen::field_name::t_ext> id_734 { (*p_0).factors };
      uint32_t id_735 { id_734.size() };
      Vec<1, uint32_t> id_736 {  id_735  };
      Size let_res_737;
      {
        Vec<1, uint32_t> n_ref_372 { id_736 };
        uint32_t id_738 { 1U };
        Vec<1, uint32_t> id_739 {  id_738  };
        Size let_res_740;
        {
          Vec<1, uint32_t> lebsz_ref_373 { id_739 };
          bool while_flag_741 { true };
          do {
            uint8_t id_742 { 0 };
            uint32_t id_743 { n_ref_372[id_742] };
            uint8_t id_744 { 0 };
            uint32_t id_745 { lebsz_ref_373[id_744] };
            uint8_t id_746 { 7 };
            uint32_t id_747 { uint32_t(id_745 << id_746) };
            bool id_748 { bool(id_743 >= id_747) };
            while_flag_741 = id_748;
            if (while_flag_741) {
              uint8_t id_749 { 0 };
              uint8_t id_750 { 0 };
              uint32_t id_751 { lebsz_ref_373[id_750] };
              uint32_t id_752 { 1U };
              uint32_t id_753 { uint32_t(id_751 + id_752) };
              Void id_754 { ((void)(lebsz_ref_373[id_749] = id_753), ::dessser::Void()) };
              (void)id_754;
            }
          } while (while_flag_741);
          (void)::dessser::Void();
          uint8_t id_755 { 0 };
          uint32_t id_756 { lebsz_ref_373[id_755] };
          Size id_757 { Size(id_756) };
          let_res_740 = id_757;
        }
        let_res_737 = let_res_740;
      }
      Size id_758 { Size(sz_371 + let_res_737) };
      Vec<1, Size> id_759 {  id_758  };
      Size let_res_760;
      {
        Vec<1, Size> sz_ref_374 { id_759 };
        int32_t id_761 { 0L };
        Vec<1, int32_t> id_762 {  id_761  };
        {
          Vec<1, int32_t> repeat_n_375 { id_762 };
          bool while_flag_763 { true };
          do {
            Lst<dessser::gen::field_name::t_ext> id_764 { (*p_0).factors };
            uint32_t id_765 { id_764.size() };
            int32_t id_766 { int32_t(id_765) };
            uint8_t id_767 { 0 };
            int32_t id_768 { repeat_n_375[id_767] };
            bool id_769 { bool(id_766 > id_768) };
            while_flag_763 = id_769;
            if (while_flag_763) {
              uint8_t id_770 { 0 };
              uint8_t id_771 { 0 };
              Size id_772 { sz_ref_374[id_771] };
              auto fun773 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_774 { 0 };
              int32_t id_775 { repeat_n_375[id_774] };
              Lst<dessser::gen::field_name::t_ext> id_776 { (*p_0).factors };
              dessser::gen::field_name::t_ext id_777 { id_776[id_775] };
              Size id_778 { fun773(id_777) };
              Size id_779 { Size(id_772 + id_778) };
              Void id_780 { ((void)(sz_ref_374[id_770] = id_779), ::dessser::Void()) };
              (void)id_780;
              uint8_t id_781 { 0 };
              uint8_t id_782 { 0 };
              int32_t id_783 { repeat_n_375[id_782] };
              int32_t id_784 { 1L };
              int32_t id_785 { int32_t(id_783 + id_784) };
              Void id_786 { ((void)(repeat_n_375[id_781] = id_785), ::dessser::Void()) };
              (void)id_786;
              (void)id_786;
            }
          } while (while_flag_763);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_787 { 0 };
        Size id_788 { sz_ref_374[id_787] };
        let_res_760 = id_788;
      }
      let_res_733 = let_res_760;
    }
    Size let_res_789;
    {
      Size sz_376 { let_res_733 };
      std::string id_790 { (*p_0).signature };
      uint32_t id_791 { (uint32_t)id_790.size() };
      Vec<1, uint32_t> id_792 {  id_791  };
      Size let_res_793;
      {
        Vec<1, uint32_t> n_ref_378 { id_792 };
        uint32_t id_794 { 1U };
        Vec<1, uint32_t> id_795 {  id_794  };
        Size let_res_796;
        {
          Vec<1, uint32_t> lebsz_ref_379 { id_795 };
          bool while_flag_797 { true };
          do {
            uint8_t id_798 { 0 };
            uint32_t id_799 { n_ref_378[id_798] };
            uint8_t id_800 { 0 };
            uint32_t id_801 { lebsz_ref_379[id_800] };
            uint8_t id_802 { 7 };
            uint32_t id_803 { uint32_t(id_801 << id_802) };
            bool id_804 { bool(id_799 >= id_803) };
            while_flag_797 = id_804;
            if (while_flag_797) {
              uint8_t id_805 { 0 };
              uint8_t id_806 { 0 };
              uint32_t id_807 { lebsz_ref_379[id_806] };
              uint32_t id_808 { 1U };
              uint32_t id_809 { uint32_t(id_807 + id_808) };
              Void id_810 { ((void)(lebsz_ref_379[id_805] = id_809), ::dessser::Void()) };
              (void)id_810;
            }
          } while (while_flag_797);
          (void)::dessser::Void();
          uint8_t id_811 { 0 };
          uint32_t id_812 { lebsz_ref_379[id_811] };
          Size id_813 { Size(id_812) };
          let_res_796 = id_813;
        }
        let_res_793 = let_res_796;
      }
      std::string id_814 { (*p_0).signature };
      uint32_t id_815 { (uint32_t)id_814.size() };
      Size id_816 { Size(id_815) };
      Size id_817 { Size(let_res_793 + id_816) };
      Size id_818 { Size(sz_376 + id_817) };
      let_res_789 = id_818;
    }
    Size let_res_819;
    {
      Size sz_380 { let_res_789 };
      std::string id_820 { (*p_0).in_signature };
      uint32_t id_821 { (uint32_t)id_820.size() };
      Vec<1, uint32_t> id_822 {  id_821  };
      Size let_res_823;
      {
        Vec<1, uint32_t> n_ref_382 { id_822 };
        uint32_t id_824 { 1U };
        Vec<1, uint32_t> id_825 {  id_824  };
        Size let_res_826;
        {
          Vec<1, uint32_t> lebsz_ref_383 { id_825 };
          bool while_flag_827 { true };
          do {
            uint8_t id_828 { 0 };
            uint32_t id_829 { n_ref_382[id_828] };
            uint8_t id_830 { 0 };
            uint32_t id_831 { lebsz_ref_383[id_830] };
            uint8_t id_832 { 7 };
            uint32_t id_833 { uint32_t(id_831 << id_832) };
            bool id_834 { bool(id_829 >= id_833) };
            while_flag_827 = id_834;
            if (while_flag_827) {
              uint8_t id_835 { 0 };
              uint8_t id_836 { 0 };
              uint32_t id_837 { lebsz_ref_383[id_836] };
              uint32_t id_838 { 1U };
              uint32_t id_839 { uint32_t(id_837 + id_838) };
              Void id_840 { ((void)(lebsz_ref_383[id_835] = id_839), ::dessser::Void()) };
              (void)id_840;
            }
          } while (while_flag_827);
          (void)::dessser::Void();
          uint8_t id_841 { 0 };
          uint32_t id_842 { lebsz_ref_383[id_841] };
          Size id_843 { Size(id_842) };
          let_res_826 = id_843;
        }
        let_res_823 = let_res_826;
      }
      std::string id_844 { (*p_0).in_signature };
      uint32_t id_845 { (uint32_t)id_844.size() };
      Size id_846 { Size(id_845) };
      Size id_847 { Size(let_res_823 + id_846) };
      Size id_848 { Size(sz_380 + id_847) };
      let_res_819 = id_848;
    }
    return let_res_819;
  }
   };
  return fun674;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary(compiled_func_sersize_of_row_binary_init());

/* 
    (fun ("{default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}")
      (let "sz_400"
        (let "sz_395"
          (let "sz_390"
            (let "sz_389"
              (let "sz_ref_387"
                (make-vec
                  (let "n_ref_385" (make-vec (cardinality (get-field "default_params" (param 0))))
                    (let "lebsz_ref_386" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_385")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_386")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_386") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_386")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_386")))))))
                (seq
                  (let "repeat_n_388" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "default_params" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_388")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_387")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_387"))
                            (apply (ext-identifier program_parameter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_388")) (get-field "default_params" (param 0))))))
                        (set-vec (u8 0) (identifier "repeat_n_388") (add (unsafe-nth (u8 0) (identifier "repeat_n_388")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_387")))) (add (identifier "sz_389") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "condition" (param 0)))))
            (let "sz_ref_393"
              (make-vec
                (add (identifier "sz_390")
                  (let "n_ref_391" (make-vec (cardinality (get-field "globals" (param 0))))
                    (let "lebsz_ref_392" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_391")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_392")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_392") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_392")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_392"))))))))
              (seq
                (let "repeat_n_394" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "globals" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_394")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_393")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_393"))
                          (apply (ext-identifier global_variable sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_394")) (get-field "globals" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_394") (add (unsafe-nth (u8 0) (identifier "repeat_n_394")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_393")))))
          (let "sz_ref_398"
            (make-vec
              (add (identifier "sz_395")
                (let "n_ref_396" (make-vec (cardinality (get-field "funcs" (param 0))))
                  (let "lebsz_ref_397" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_396")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_397")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_397") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_397")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_397"))))))))
            (seq
              (let "repeat_n_399" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "funcs" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_399")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_398")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_398")) (apply (identifier "compiled_func-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_399")) (get-field "funcs" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_399") (add (unsafe-nth (u8 0) (identifier "repeat_n_399")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_398")))))
        (let "sz_ref_403"
          (make-vec
            (add (identifier "sz_400")
              (let "n_ref_401" (make-vec (cardinality (get-field "warnings" (param 0))))
                (let "lebsz_ref_402" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_401")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_402")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_402") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_402")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_402"))))))))
          (seq
            (let "repeat_n_404" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "warnings" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_404")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_403")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_403")) (apply (ext-identifier raql_warning sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_404")) (get-field "warnings" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_404") (add (unsafe-nth (u8 0) (identifier "repeat_n_404")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_403"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> fun849 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_program>  p_0) {
    Lst<dessser::gen::program_parameter::t_ext> id_850 { (*p_0).default_params };
    uint32_t id_851 { id_850.size() };
    Vec<1, uint32_t> id_852 {  id_851  };
    Size let_res_853;
    {
      Vec<1, uint32_t> n_ref_385 { id_852 };
      uint32_t id_854 { 1U };
      Vec<1, uint32_t> id_855 {  id_854  };
      Size let_res_856;
      {
        Vec<1, uint32_t> lebsz_ref_386 { id_855 };
        bool while_flag_857 { true };
        do {
          uint8_t id_858 { 0 };
          uint32_t id_859 { n_ref_385[id_858] };
          uint8_t id_860 { 0 };
          uint32_t id_861 { lebsz_ref_386[id_860] };
          uint8_t id_862 { 7 };
          uint32_t id_863 { uint32_t(id_861 << id_862) };
          bool id_864 { bool(id_859 >= id_863) };
          while_flag_857 = id_864;
          if (while_flag_857) {
            uint8_t id_865 { 0 };
            uint8_t id_866 { 0 };
            uint32_t id_867 { lebsz_ref_386[id_866] };
            uint32_t id_868 { 1U };
            uint32_t id_869 { uint32_t(id_867 + id_868) };
            Void id_870 { ((void)(lebsz_ref_386[id_865] = id_869), ::dessser::Void()) };
            (void)id_870;
          }
        } while (while_flag_857);
        (void)::dessser::Void();
        uint8_t id_871 { 0 };
        uint32_t id_872 { lebsz_ref_386[id_871] };
        Size id_873 { Size(id_872) };
        let_res_856 = id_873;
      }
      let_res_853 = let_res_856;
    }
    Vec<1, Size> id_874 {  let_res_853  };
    Size let_res_875;
    {
      Vec<1, Size> sz_ref_387 { id_874 };
      int32_t id_876 { 0L };
      Vec<1, int32_t> id_877 {  id_876  };
      {
        Vec<1, int32_t> repeat_n_388 { id_877 };
        bool while_flag_878 { true };
        do {
          Lst<dessser::gen::program_parameter::t_ext> id_879 { (*p_0).default_params };
          uint32_t id_880 { id_879.size() };
          int32_t id_881 { int32_t(id_880) };
          uint8_t id_882 { 0 };
          int32_t id_883 { repeat_n_388[id_882] };
          bool id_884 { bool(id_881 > id_883) };
          while_flag_878 = id_884;
          if (while_flag_878) {
            uint8_t id_885 { 0 };
            uint8_t id_886 { 0 };
            Size id_887 { sz_ref_387[id_886] };
            auto fun888 { dessser::gen::program_parameter::sersize_of_row_binary };
            uint8_t id_889 { 0 };
            int32_t id_890 { repeat_n_388[id_889] };
            Lst<dessser::gen::program_parameter::t_ext> id_891 { (*p_0).default_params };
            dessser::gen::program_parameter::t_ext id_892 { id_891[id_890] };
            Size id_893 { fun888(id_892) };
            Size id_894 { Size(id_887 + id_893) };
            Void id_895 { ((void)(sz_ref_387[id_885] = id_894), ::dessser::Void()) };
            (void)id_895;
            uint8_t id_896 { 0 };
            uint8_t id_897 { 0 };
            int32_t id_898 { repeat_n_388[id_897] };
            int32_t id_899 { 1L };
            int32_t id_900 { int32_t(id_898 + id_899) };
            Void id_901 { ((void)(repeat_n_388[id_896] = id_900), ::dessser::Void()) };
            (void)id_901;
            (void)id_901;
          }
        } while (while_flag_878);
        (void)::dessser::Void();
      }
      (void)::dessser::Void();
      uint8_t id_902 { 0 };
      Size id_903 { sz_ref_387[id_902] };
      let_res_875 = id_903;
    }
    Size let_res_904;
    {
      Size sz_389 { let_res_875 };
      auto fun905 { dessser::gen::raql_expr::sersize_of_row_binary };
      dessser::gen::raql_expr::t_ext id_906 { (*p_0).condition };
      Size id_907 { fun905(id_906) };
      Size id_908 { Size(sz_389 + id_907) };
      let_res_904 = id_908;
    }
    Size let_res_909;
    {
      Size sz_390 { let_res_904 };
      Lst<dessser::gen::global_variable::t_ext> id_910 { (*p_0).globals };
      uint32_t id_911 { id_910.size() };
      Vec<1, uint32_t> id_912 {  id_911  };
      Size let_res_913;
      {
        Vec<1, uint32_t> n_ref_391 { id_912 };
        uint32_t id_914 { 1U };
        Vec<1, uint32_t> id_915 {  id_914  };
        Size let_res_916;
        {
          Vec<1, uint32_t> lebsz_ref_392 { id_915 };
          bool while_flag_917 { true };
          do {
            uint8_t id_918 { 0 };
            uint32_t id_919 { n_ref_391[id_918] };
            uint8_t id_920 { 0 };
            uint32_t id_921 { lebsz_ref_392[id_920] };
            uint8_t id_922 { 7 };
            uint32_t id_923 { uint32_t(id_921 << id_922) };
            bool id_924 { bool(id_919 >= id_923) };
            while_flag_917 = id_924;
            if (while_flag_917) {
              uint8_t id_925 { 0 };
              uint8_t id_926 { 0 };
              uint32_t id_927 { lebsz_ref_392[id_926] };
              uint32_t id_928 { 1U };
              uint32_t id_929 { uint32_t(id_927 + id_928) };
              Void id_930 { ((void)(lebsz_ref_392[id_925] = id_929), ::dessser::Void()) };
              (void)id_930;
            }
          } while (while_flag_917);
          (void)::dessser::Void();
          uint8_t id_931 { 0 };
          uint32_t id_932 { lebsz_ref_392[id_931] };
          Size id_933 { Size(id_932) };
          let_res_916 = id_933;
        }
        let_res_913 = let_res_916;
      }
      Size id_934 { Size(sz_390 + let_res_913) };
      Vec<1, Size> id_935 {  id_934  };
      Size let_res_936;
      {
        Vec<1, Size> sz_ref_393 { id_935 };
        int32_t id_937 { 0L };
        Vec<1, int32_t> id_938 {  id_937  };
        {
          Vec<1, int32_t> repeat_n_394 { id_938 };
          bool while_flag_939 { true };
          do {
            Lst<dessser::gen::global_variable::t_ext> id_940 { (*p_0).globals };
            uint32_t id_941 { id_940.size() };
            int32_t id_942 { int32_t(id_941) };
            uint8_t id_943 { 0 };
            int32_t id_944 { repeat_n_394[id_943] };
            bool id_945 { bool(id_942 > id_944) };
            while_flag_939 = id_945;
            if (while_flag_939) {
              uint8_t id_946 { 0 };
              uint8_t id_947 { 0 };
              Size id_948 { sz_ref_393[id_947] };
              auto fun949 { dessser::gen::global_variable::sersize_of_row_binary };
              uint8_t id_950 { 0 };
              int32_t id_951 { repeat_n_394[id_950] };
              Lst<dessser::gen::global_variable::t_ext> id_952 { (*p_0).globals };
              dessser::gen::global_variable::t_ext id_953 { id_952[id_951] };
              Size id_954 { fun949(id_953) };
              Size id_955 { Size(id_948 + id_954) };
              Void id_956 { ((void)(sz_ref_393[id_946] = id_955), ::dessser::Void()) };
              (void)id_956;
              uint8_t id_957 { 0 };
              uint8_t id_958 { 0 };
              int32_t id_959 { repeat_n_394[id_958] };
              int32_t id_960 { 1L };
              int32_t id_961 { int32_t(id_959 + id_960) };
              Void id_962 { ((void)(repeat_n_394[id_957] = id_961), ::dessser::Void()) };
              (void)id_962;
              (void)id_962;
            }
          } while (while_flag_939);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_963 { 0 };
        Size id_964 { sz_ref_393[id_963] };
        let_res_936 = id_964;
      }
      let_res_909 = let_res_936;
    }
    Size let_res_965;
    {
      Size sz_395 { let_res_909 };
      Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_966 { (*p_0).funcs };
      uint32_t id_967 { id_966.size() };
      Vec<1, uint32_t> id_968 {  id_967  };
      Size let_res_969;
      {
        Vec<1, uint32_t> n_ref_396 { id_968 };
        uint32_t id_970 { 1U };
        Vec<1, uint32_t> id_971 {  id_970  };
        Size let_res_972;
        {
          Vec<1, uint32_t> lebsz_ref_397 { id_971 };
          bool while_flag_973 { true };
          do {
            uint8_t id_974 { 0 };
            uint32_t id_975 { n_ref_396[id_974] };
            uint8_t id_976 { 0 };
            uint32_t id_977 { lebsz_ref_397[id_976] };
            uint8_t id_978 { 7 };
            uint32_t id_979 { uint32_t(id_977 << id_978) };
            bool id_980 { bool(id_975 >= id_979) };
            while_flag_973 = id_980;
            if (while_flag_973) {
              uint8_t id_981 { 0 };
              uint8_t id_982 { 0 };
              uint32_t id_983 { lebsz_ref_397[id_982] };
              uint32_t id_984 { 1U };
              uint32_t id_985 { uint32_t(id_983 + id_984) };
              Void id_986 { ((void)(lebsz_ref_397[id_981] = id_985), ::dessser::Void()) };
              (void)id_986;
            }
          } while (while_flag_973);
          (void)::dessser::Void();
          uint8_t id_987 { 0 };
          uint32_t id_988 { lebsz_ref_397[id_987] };
          Size id_989 { Size(id_988) };
          let_res_972 = id_989;
        }
        let_res_969 = let_res_972;
      }
      Size id_990 { Size(sz_395 + let_res_969) };
      Vec<1, Size> id_991 {  id_990  };
      Size let_res_992;
      {
        Vec<1, Size> sz_ref_398 { id_991 };
        int32_t id_993 { 0L };
        Vec<1, int32_t> id_994 {  id_993  };
        {
          Vec<1, int32_t> repeat_n_399 { id_994 };
          bool while_flag_995 { true };
          do {
            Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_996 { (*p_0).funcs };
            uint32_t id_997 { id_996.size() };
            int32_t id_998 { int32_t(id_997) };
            uint8_t id_999 { 0 };
            int32_t id_1000 { repeat_n_399[id_999] };
            bool id_1001 { bool(id_998 > id_1000) };
            while_flag_995 = id_1001;
            if (while_flag_995) {
              uint8_t id_1002 { 0 };
              uint8_t id_1003 { 0 };
              Size id_1004 { sz_ref_398[id_1003] };
              uint8_t id_1005 { 0 };
              int32_t id_1006 { repeat_n_399[id_1005] };
              Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_1007 { (*p_0).funcs };
              std::shared_ptr<::dessser::gen::source_info::compiled_func>  id_1008 { id_1007[id_1006] };
              Size id_1009 { compiled_func_sersize_of_row_binary(id_1008) };
              Size id_1010 { Size(id_1004 + id_1009) };
              Void id_1011 { ((void)(sz_ref_398[id_1002] = id_1010), ::dessser::Void()) };
              (void)id_1011;
              uint8_t id_1012 { 0 };
              uint8_t id_1013 { 0 };
              int32_t id_1014 { repeat_n_399[id_1013] };
              int32_t id_1015 { 1L };
              int32_t id_1016 { int32_t(id_1014 + id_1015) };
              Void id_1017 { ((void)(repeat_n_399[id_1012] = id_1016), ::dessser::Void()) };
              (void)id_1017;
              (void)id_1017;
            }
          } while (while_flag_995);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1018 { 0 };
        Size id_1019 { sz_ref_398[id_1018] };
        let_res_992 = id_1019;
      }
      let_res_965 = let_res_992;
    }
    Size let_res_1020;
    {
      Size sz_400 { let_res_965 };
      Lst<dessser::gen::raql_warning::t_ext> id_1021 { (*p_0).warnings };
      uint32_t id_1022 { id_1021.size() };
      Vec<1, uint32_t> id_1023 {  id_1022  };
      Size let_res_1024;
      {
        Vec<1, uint32_t> n_ref_401 { id_1023 };
        uint32_t id_1025 { 1U };
        Vec<1, uint32_t> id_1026 {  id_1025  };
        Size let_res_1027;
        {
          Vec<1, uint32_t> lebsz_ref_402 { id_1026 };
          bool while_flag_1028 { true };
          do {
            uint8_t id_1029 { 0 };
            uint32_t id_1030 { n_ref_401[id_1029] };
            uint8_t id_1031 { 0 };
            uint32_t id_1032 { lebsz_ref_402[id_1031] };
            uint8_t id_1033 { 7 };
            uint32_t id_1034 { uint32_t(id_1032 << id_1033) };
            bool id_1035 { bool(id_1030 >= id_1034) };
            while_flag_1028 = id_1035;
            if (while_flag_1028) {
              uint8_t id_1036 { 0 };
              uint8_t id_1037 { 0 };
              uint32_t id_1038 { lebsz_ref_402[id_1037] };
              uint32_t id_1039 { 1U };
              uint32_t id_1040 { uint32_t(id_1038 + id_1039) };
              Void id_1041 { ((void)(lebsz_ref_402[id_1036] = id_1040), ::dessser::Void()) };
              (void)id_1041;
            }
          } while (while_flag_1028);
          (void)::dessser::Void();
          uint8_t id_1042 { 0 };
          uint32_t id_1043 { lebsz_ref_402[id_1042] };
          Size id_1044 { Size(id_1043) };
          let_res_1027 = id_1044;
        }
        let_res_1024 = let_res_1027;
      }
      Size id_1045 { Size(sz_400 + let_res_1024) };
      Vec<1, Size> id_1046 {  id_1045  };
      Size let_res_1047;
      {
        Vec<1, Size> sz_ref_403 { id_1046 };
        int32_t id_1048 { 0L };
        Vec<1, int32_t> id_1049 {  id_1048  };
        {
          Vec<1, int32_t> repeat_n_404 { id_1049 };
          bool while_flag_1050 { true };
          do {
            Lst<dessser::gen::raql_warning::t_ext> id_1051 { (*p_0).warnings };
            uint32_t id_1052 { id_1051.size() };
            int32_t id_1053 { int32_t(id_1052) };
            uint8_t id_1054 { 0 };
            int32_t id_1055 { repeat_n_404[id_1054] };
            bool id_1056 { bool(id_1053 > id_1055) };
            while_flag_1050 = id_1056;
            if (while_flag_1050) {
              uint8_t id_1057 { 0 };
              uint8_t id_1058 { 0 };
              Size id_1059 { sz_ref_403[id_1058] };
              auto fun1060 { dessser::gen::raql_warning::sersize_of_row_binary };
              uint8_t id_1061 { 0 };
              int32_t id_1062 { repeat_n_404[id_1061] };
              Lst<dessser::gen::raql_warning::t_ext> id_1063 { (*p_0).warnings };
              dessser::gen::raql_warning::t_ext id_1064 { id_1063[id_1062] };
              Size id_1065 { fun1060(id_1064) };
              Size id_1066 { Size(id_1059 + id_1065) };
              Void id_1067 { ((void)(sz_ref_403[id_1057] = id_1066), ::dessser::Void()) };
              (void)id_1067;
              uint8_t id_1068 { 0 };
              uint8_t id_1069 { 0 };
              int32_t id_1070 { repeat_n_404[id_1069] };
              int32_t id_1071 { 1L };
              int32_t id_1072 { int32_t(id_1070 + id_1071) };
              Void id_1073 { ((void)(repeat_n_404[id_1068] = id_1072), ::dessser::Void()) };
              (void)id_1073;
              (void)id_1073;
            }
          } while (while_flag_1050);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1074 { 0 };
        Size id_1075 { sz_ref_403[id_1074] };
        let_res_1047 = id_1075;
      }
      let_res_1020 = let_res_1047;
    }
    return let_res_1020;
  }
   };
  return fun849;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary(compiled_program_sersize_of_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]}")
      (let "sz_417"
        (let "sz_409"
          (add
            (let "n_ref_407" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "lebsz_ref_408" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_407")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_408")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_408") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_408")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_408")))))) 
            (size-of-u32 (string-length (get-field "src_ext" (param 0)))))
          (let "sz_ref_412"
            (make-vec
              (add (identifier "sz_409")
                (let "n_ref_410" (make-vec (cardinality (get-field "md5s" (param 0))))
                  (let "lebsz_ref_411" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_410")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_411")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_411") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_411")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_411"))))))))
            (seq
              (let "repeat_n_413" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "md5s" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_413")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_412")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_412"))
                        (let "wlen_414" (string-length (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_413")) (get-field "md5s" (param 0))))
                          (add
                            (let "n_ref_415" (make-vec (identifier "wlen_414"))
                              (let "lebsz_ref_416" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_415")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_416")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_416") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_416")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_416")))))) 
                            (size-of-u32 (identifier "wlen_414")))))) 
                    (set-vec (u8 0) (identifier "repeat_n_413") (add (unsafe-nth (u8 0) (identifier "repeat_n_413")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_412")))))
        (if (eq (u16 0) (label-of (get-field "detail" (param 0)))) (add (add (identifier "sz_417") (size 2)) (apply (identifier "compiled_program-sersize-of-row-binary") (get-alt "Compiled" (get-field "detail" (param 0)))))
          (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
            (let "sz_424"
              (let "sz_ref_422"
                (make-vec
                  (add (add (identifier "sz_417") (size 2))
                    (let "n_ref_420" (make-vec (cardinality (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))))
                      (let "lebsz_ref_421" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_420")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_421")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_421") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_421")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_421"))))))))
                (seq
                  (let "repeat_n_423" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_423")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_422")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_422"))
                            (apply (ext-identifier raql_error sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_423")) (get-field "errors" (get-alt "Failed" (get-field "detail" (param 0))))))))
                        (set-vec (u8 0) (identifier "repeat_n_423") (add (unsafe-nth (u8 0) (identifier "repeat_n_423")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_422"))))
              (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                (add (identifier "sz_424") (size 1))
                (add (add (identifier "sz_424") (apply (ext-identifier src_path sersize-of-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))))) (size 1))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> fun1076 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0) {
    std::string id_1077 { (*p_0).src_ext };
    uint32_t id_1078 { (uint32_t)id_1077.size() };
    Vec<1, uint32_t> id_1079 {  id_1078  };
    Size let_res_1080;
    {
      Vec<1, uint32_t> n_ref_407 { id_1079 };
      uint32_t id_1081 { 1U };
      Vec<1, uint32_t> id_1082 {  id_1081  };
      Size let_res_1083;
      {
        Vec<1, uint32_t> lebsz_ref_408 { id_1082 };
        bool while_flag_1084 { true };
        do {
          uint8_t id_1085 { 0 };
          uint32_t id_1086 { n_ref_407[id_1085] };
          uint8_t id_1087 { 0 };
          uint32_t id_1088 { lebsz_ref_408[id_1087] };
          uint8_t id_1089 { 7 };
          uint32_t id_1090 { uint32_t(id_1088 << id_1089) };
          bool id_1091 { bool(id_1086 >= id_1090) };
          while_flag_1084 = id_1091;
          if (while_flag_1084) {
            uint8_t id_1092 { 0 };
            uint8_t id_1093 { 0 };
            uint32_t id_1094 { lebsz_ref_408[id_1093] };
            uint32_t id_1095 { 1U };
            uint32_t id_1096 { uint32_t(id_1094 + id_1095) };
            Void id_1097 { ((void)(lebsz_ref_408[id_1092] = id_1096), ::dessser::Void()) };
            (void)id_1097;
          }
        } while (while_flag_1084);
        (void)::dessser::Void();
        uint8_t id_1098 { 0 };
        uint32_t id_1099 { lebsz_ref_408[id_1098] };
        Size id_1100 { Size(id_1099) };
        let_res_1083 = id_1100;
      }
      let_res_1080 = let_res_1083;
    }
    std::string id_1101 { (*p_0).src_ext };
    uint32_t id_1102 { (uint32_t)id_1101.size() };
    Size id_1103 { Size(id_1102) };
    Size id_1104 { Size(let_res_1080 + id_1103) };
    Size let_res_1105;
    {
      Size sz_409 { id_1104 };
      Lst<std::string> id_1106 { (*p_0).md5s };
      uint32_t id_1107 { id_1106.size() };
      Vec<1, uint32_t> id_1108 {  id_1107  };
      Size let_res_1109;
      {
        Vec<1, uint32_t> n_ref_410 { id_1108 };
        uint32_t id_1110 { 1U };
        Vec<1, uint32_t> id_1111 {  id_1110  };
        Size let_res_1112;
        {
          Vec<1, uint32_t> lebsz_ref_411 { id_1111 };
          bool while_flag_1113 { true };
          do {
            uint8_t id_1114 { 0 };
            uint32_t id_1115 { n_ref_410[id_1114] };
            uint8_t id_1116 { 0 };
            uint32_t id_1117 { lebsz_ref_411[id_1116] };
            uint8_t id_1118 { 7 };
            uint32_t id_1119 { uint32_t(id_1117 << id_1118) };
            bool id_1120 { bool(id_1115 >= id_1119) };
            while_flag_1113 = id_1120;
            if (while_flag_1113) {
              uint8_t id_1121 { 0 };
              uint8_t id_1122 { 0 };
              uint32_t id_1123 { lebsz_ref_411[id_1122] };
              uint32_t id_1124 { 1U };
              uint32_t id_1125 { uint32_t(id_1123 + id_1124) };
              Void id_1126 { ((void)(lebsz_ref_411[id_1121] = id_1125), ::dessser::Void()) };
              (void)id_1126;
            }
          } while (while_flag_1113);
          (void)::dessser::Void();
          uint8_t id_1127 { 0 };
          uint32_t id_1128 { lebsz_ref_411[id_1127] };
          Size id_1129 { Size(id_1128) };
          let_res_1112 = id_1129;
        }
        let_res_1109 = let_res_1112;
      }
      Size id_1130 { Size(sz_409 + let_res_1109) };
      Vec<1, Size> id_1131 {  id_1130  };
      Size let_res_1132;
      {
        Vec<1, Size> sz_ref_412 { id_1131 };
        int32_t id_1133 { 0L };
        Vec<1, int32_t> id_1134 {  id_1133  };
        {
          Vec<1, int32_t> repeat_n_413 { id_1134 };
          bool while_flag_1135 { true };
          do {
            Lst<std::string> id_1136 { (*p_0).md5s };
            uint32_t id_1137 { id_1136.size() };
            int32_t id_1138 { int32_t(id_1137) };
            uint8_t id_1139 { 0 };
            int32_t id_1140 { repeat_n_413[id_1139] };
            bool id_1141 { bool(id_1138 > id_1140) };
            while_flag_1135 = id_1141;
            if (while_flag_1135) {
              uint8_t id_1142 { 0 };
              uint8_t id_1143 { 0 };
              Size id_1144 { sz_ref_412[id_1143] };
              uint8_t id_1145 { 0 };
              int32_t id_1146 { repeat_n_413[id_1145] };
              Lst<std::string> id_1147 { (*p_0).md5s };
              std::string id_1148 { id_1147[id_1146] };
              uint32_t id_1149 { (uint32_t)id_1148.size() };
              Size let_res_1150;
              {
                uint32_t wlen_414 { id_1149 };
                Vec<1, uint32_t> id_1151 {  wlen_414  };
                Size let_res_1152;
                {
                  Vec<1, uint32_t> n_ref_415 { id_1151 };
                  uint32_t id_1153 { 1U };
                  Vec<1, uint32_t> id_1154 {  id_1153  };
                  Size let_res_1155;
                  {
                    Vec<1, uint32_t> lebsz_ref_416 { id_1154 };
                    bool while_flag_1156 { true };
                    do {
                      uint8_t id_1157 { 0 };
                      uint32_t id_1158 { n_ref_415[id_1157] };
                      uint8_t id_1159 { 0 };
                      uint32_t id_1160 { lebsz_ref_416[id_1159] };
                      uint8_t id_1161 { 7 };
                      uint32_t id_1162 { uint32_t(id_1160 << id_1161) };
                      bool id_1163 { bool(id_1158 >= id_1162) };
                      while_flag_1156 = id_1163;
                      if (while_flag_1156) {
                        uint8_t id_1164 { 0 };
                        uint8_t id_1165 { 0 };
                        uint32_t id_1166 { lebsz_ref_416[id_1165] };
                        uint32_t id_1167 { 1U };
                        uint32_t id_1168 { uint32_t(id_1166 + id_1167) };
                        Void id_1169 { ((void)(lebsz_ref_416[id_1164] = id_1168), ::dessser::Void()) };
                        (void)id_1169;
                      }
                    } while (while_flag_1156);
                    (void)::dessser::Void();
                    uint8_t id_1170 { 0 };
                    uint32_t id_1171 { lebsz_ref_416[id_1170] };
                    Size id_1172 { Size(id_1171) };
                    let_res_1155 = id_1172;
                  }
                  let_res_1152 = let_res_1155;
                }
                Size id_1173 { Size(wlen_414) };
                Size id_1174 { Size(let_res_1152 + id_1173) };
                let_res_1150 = id_1174;
              }
              Size id_1175 { Size(id_1144 + let_res_1150) };
              Void id_1176 { ((void)(sz_ref_412[id_1142] = id_1175), ::dessser::Void()) };
              (void)id_1176;
              uint8_t id_1177 { 0 };
              uint8_t id_1178 { 0 };
              int32_t id_1179 { repeat_n_413[id_1178] };
              int32_t id_1180 { 1L };
              int32_t id_1181 { int32_t(id_1179 + id_1180) };
              Void id_1182 { ((void)(repeat_n_413[id_1177] = id_1181), ::dessser::Void()) };
              (void)id_1182;
              (void)id_1182;
            }
          } while (while_flag_1135);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_1183 { 0 };
        Size id_1184 { sz_ref_412[id_1183] };
        let_res_1132 = id_1184;
      }
      let_res_1105 = let_res_1132;
    }
    Size let_res_1185;
    {
      Size sz_417 { let_res_1105 };
      uint16_t id_1186 { 0 };
      ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1187 { (*p_0).detail };
      uint16_t id_1188 { uint16_t(id_1187.index()) };
      bool id_1189 { bool(id_1186 == id_1188) };
      Size choose_res_1190;
      if (id_1189) {
        Size id_1191 { 2UL };
        Size id_1192 { Size(sz_417 + id_1191) };
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1193 { (*p_0).detail };
        std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_1194 { std::get<0 /* Compiled */>(id_1193) };
        Size id_1195 { compiled_program_sersize_of_row_binary(id_1194) };
        Size id_1196 { Size(id_1192 + id_1195) };
        choose_res_1190 = id_1196;
      } else {
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1197 { (*p_0).detail };
        uint16_t id_1198 { uint16_t(id_1197.index()) };
        uint16_t id_1199 { 1 };
        bool id_1200 { bool(id_1198 == id_1199) };
        Void id_1201 { ((void)(assert(id_1200)), ::dessser::Void()) };
        (void)id_1201;
        Size id_1202 { 2UL };
        Size id_1203 { Size(sz_417 + id_1202) };
        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1204 { (*p_0).detail };
        ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1205 { std::get<1 /* Failed */>(id_1204) };
        Lst<dessser::gen::raql_error::t_ext> id_1206 { id_1205.errors };
        uint32_t id_1207 { id_1206.size() };
        Vec<1, uint32_t> id_1208 {  id_1207  };
        Size let_res_1209;
        {
          Vec<1, uint32_t> n_ref_420 { id_1208 };
          uint32_t id_1210 { 1U };
          Vec<1, uint32_t> id_1211 {  id_1210  };
          Size let_res_1212;
          {
            Vec<1, uint32_t> lebsz_ref_421 { id_1211 };
            bool while_flag_1213 { true };
            do {
              uint8_t id_1214 { 0 };
              uint32_t id_1215 { n_ref_420[id_1214] };
              uint8_t id_1216 { 0 };
              uint32_t id_1217 { lebsz_ref_421[id_1216] };
              uint8_t id_1218 { 7 };
              uint32_t id_1219 { uint32_t(id_1217 << id_1218) };
              bool id_1220 { bool(id_1215 >= id_1219) };
              while_flag_1213 = id_1220;
              if (while_flag_1213) {
                uint8_t id_1221 { 0 };
                uint8_t id_1222 { 0 };
                uint32_t id_1223 { lebsz_ref_421[id_1222] };
                uint32_t id_1224 { 1U };
                uint32_t id_1225 { uint32_t(id_1223 + id_1224) };
                Void id_1226 { ((void)(lebsz_ref_421[id_1221] = id_1225), ::dessser::Void()) };
                (void)id_1226;
              }
            } while (while_flag_1213);
            (void)::dessser::Void();
            uint8_t id_1227 { 0 };
            uint32_t id_1228 { lebsz_ref_421[id_1227] };
            Size id_1229 { Size(id_1228) };
            let_res_1212 = id_1229;
          }
          let_res_1209 = let_res_1212;
        }
        Size id_1230 { Size(id_1203 + let_res_1209) };
        Vec<1, Size> id_1231 {  id_1230  };
        Size let_res_1232;
        {
          Vec<1, Size> sz_ref_422 { id_1231 };
          int32_t id_1233 { 0L };
          Vec<1, int32_t> id_1234 {  id_1233  };
          {
            Vec<1, int32_t> repeat_n_423 { id_1234 };
            bool while_flag_1235 { true };
            do {
              ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1236 { (*p_0).detail };
              ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1237 { std::get<1 /* Failed */>(id_1236) };
              Lst<dessser::gen::raql_error::t_ext> id_1238 { id_1237.errors };
              uint32_t id_1239 { id_1238.size() };
              int32_t id_1240 { int32_t(id_1239) };
              uint8_t id_1241 { 0 };
              int32_t id_1242 { repeat_n_423[id_1241] };
              bool id_1243 { bool(id_1240 > id_1242) };
              while_flag_1235 = id_1243;
              if (while_flag_1235) {
                uint8_t id_1244 { 0 };
                uint8_t id_1245 { 0 };
                Size id_1246 { sz_ref_422[id_1245] };
                auto fun1247 { dessser::gen::raql_error::sersize_of_row_binary };
                uint8_t id_1248 { 0 };
                int32_t id_1249 { repeat_n_423[id_1248] };
                ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1250 { (*p_0).detail };
                ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1251 { std::get<1 /* Failed */>(id_1250) };
                Lst<dessser::gen::raql_error::t_ext> id_1252 { id_1251.errors };
                dessser::gen::raql_error::t_ext id_1253 { id_1252[id_1249] };
                Size id_1254 { fun1247(id_1253) };
                Size id_1255 { Size(id_1246 + id_1254) };
                Void id_1256 { ((void)(sz_ref_422[id_1244] = id_1255), ::dessser::Void()) };
                (void)id_1256;
                uint8_t id_1257 { 0 };
                uint8_t id_1258 { 0 };
                int32_t id_1259 { repeat_n_423[id_1258] };
                int32_t id_1260 { 1L };
                int32_t id_1261 { int32_t(id_1259 + id_1260) };
                Void id_1262 { ((void)(repeat_n_423[id_1257] = id_1261), ::dessser::Void()) };
                (void)id_1262;
                (void)id_1262;
              }
            } while (while_flag_1235);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_1263 { 0 };
          Size id_1264 { sz_ref_422[id_1263] };
          let_res_1232 = id_1264;
        }
        Size let_res_1265;
        {
          Size sz_424 { let_res_1232 };
          ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1266 { (*p_0).detail };
          ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1267 { std::get<1 /* Failed */>(id_1266) };
          std::optional<dessser::gen::src_path::t_ext> id_1268 { id_1267.depends_on };
          bool id_1269 { !(id_1268.has_value ()) };
          Size choose_res_1270;
          if (id_1269) {
            Size id_1271 { 1UL };
            Size id_1272 { Size(sz_424 + id_1271) };
            choose_res_1270 = id_1272;
          } else {
            auto fun1273 { dessser::gen::src_path::sersize_of_row_binary };
            ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_1274 { (*p_0).detail };
            ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_1275 { std::get<1 /* Failed */>(id_1274) };
            std::optional<dessser::gen::src_path::t_ext> id_1276 { id_1275.depends_on };
            dessser::gen::src_path::t_ext id_1277 { id_1276.value() };
            Size id_1278 { fun1273(id_1277) };
            Size id_1279 { Size(sz_424 + id_1278) };
            Size id_1280 { 1UL };
            Size id_1281 { Size(id_1279 + id_1280) };
            choose_res_1270 = id_1281;
          }
          let_res_1265 = choose_res_1270;
        }
        choose_res_1190 = let_res_1265;
      }
      let_res_1185 = choose_res_1190;
    }
    return let_res_1185;
  }
   };
  return fun1076;
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
                  (let "drec_84"
                    (let "dstring1_78"
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
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_72"))) (unsafe-nth (u8 0) (identifier "p_ref_74")))))))
                      (let-pair "dstring1_fst_79" "dstring1_snd_80" (identifier "dstring1_78")
                        (let-pair "dstring2_fst_82" "dstring2_snd_83" 
                          (read-bytes (identifier "dstring1_snd_80") (identifier "dstring1_fst_79")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_82")) (identifier "dstring2_snd_83")))))
                    (let-pair "drec_fst_85" "drec_snd_86" (identifier "drec_84")
                      (let "drec_87" (apply (ext-identifier raql_operation of-row-binary) (identifier "drec_snd_86"))
                        (let-pair "drec_fst_88" "drec_snd_89" (identifier "drec_87")
                          (let "drec_90" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_89"))
                            (let-pair "drec_fst_91" "drec_snd_92" (identifier "drec_90")
                              (let "drec_116"
                                (let-pair "dlist4_fst_114" "dlist4_snd_115"
                                  (let "dlist1_102"
                                    (let "leb_ref_93" (make-vec (u32 0))
                                      (let "shft_ref_94" (make-vec (u8 0))
                                        (let "p_ref_95" (make-vec (identifier "drec_snd_92"))
                                          (seq
                                            (while
                                              (let "leb128_96" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_95")))
                                                (let-pair "leb128_fst_97" "leb128_snd_98" 
                                                  (identifier "leb128_96")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_95") (identifier "leb128_snd_98"))
                                                    (set-vec (u8 0) (identifier "leb_ref_93")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_97") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_94"))) (unsafe-nth (u8 0) (identifier "leb_ref_93"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_94") (add (unsafe-nth (u8 0) (identifier "shft_ref_94")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_97") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_93")) (unsafe-nth (u8 0) (identifier "p_ref_95")))))))
                                    (let-pair "dlist1_fst_103" "dlist1_snd_104" 
                                      (identifier "dlist1_102")
                                      (let "inits_src_ref_105" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_104")))
                                        (seq
                                          (let "repeat_n_106" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_103")) (unsafe-nth (u8 0) (identifier "repeat_n_106")))
                                              (seq
                                                (let "dlist2_107" (unsafe-nth (u8 0) (identifier "inits_src_ref_105"))
                                                  (let-pair "dlist2_fst_108" "dlist2_snd_109" 
                                                    (identifier "dlist2_107")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_105")
                                                      (let-pair "dlist3_fst_111" "dlist3_snd_112" 
                                                        (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_109"))
                                                        (make-tup (cons (identifier "dlist3_fst_111") (identifier "dlist2_fst_108")) (identifier "dlist3_snd_112"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_106") (add (unsafe-nth (u8 0) (identifier "repeat_n_106")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_105")))))) 
                                  (make-tup (identity (identifier "dlist4_fst_114")) (identifier "dlist4_snd_115")))
                                (let-pair "drec_fst_117" "drec_snd_118" 
                                  (identifier "drec_116")
                                  (let "drec_131"
                                    (let "dstring1_125"
                                      (let "leb_ref_119" (make-vec (u32 0))
                                        (let "shft_ref_120" (make-vec (u8 0))
                                          (let "p_ref_121" (make-vec (identifier "drec_snd_118"))
                                            (seq
                                              (while
                                                (let "leb128_122" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_121")))
                                                  (let-pair "leb128_fst_123" "leb128_snd_124" 
                                                    (identifier "leb128_122")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_121") (identifier "leb128_snd_124"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_119")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_123") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_120")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_119")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_120") (add (unsafe-nth (u8 0) (identifier "shft_ref_120")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_123") (u8 128))))) 
                                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_119"))) (unsafe-nth (u8 0) (identifier "p_ref_121")))))))
                                      (let-pair "dstring1_fst_126" "dstring1_snd_127" 
                                        (identifier "dstring1_125")
                                        (let-pair "dstring2_fst_129" "dstring2_snd_130" 
                                          (read-bytes (identifier "dstring1_snd_127") (identifier "dstring1_fst_126")) 
                                          (make-tup (string-of-bytes (identifier "dstring2_fst_129")) (identifier "dstring2_snd_130")))))
                                    (let-pair "drec_fst_132" "drec_snd_133" 
                                      (identifier "drec_131")
                                      (let "dstring1_140"
                                        (let "leb_ref_134" (make-vec (u32 0))
                                          (let "shft_ref_135" (make-vec (u8 0))
                                            (let "p_ref_136" (make-vec (identifier "drec_snd_133"))
                                              (seq
                                                (while
                                                  (let "leb128_137" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_136")))
                                                    (let-pair "leb128_fst_138" "leb128_snd_139" 
                                                      (identifier "leb128_137")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_136") (identifier "leb128_snd_139"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_134")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_138") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_135")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_134")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_135") (add (unsafe-nth (u8 0) (identifier "shft_ref_135")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_138") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_134"))) (unsafe-nth (u8 0) (identifier "p_ref_136")))))))
                                        (let-pair "dstring1_fst_141" "dstring1_snd_142" 
                                          (identifier "dstring1_140")
                                          (let-pair "dstring2_fst_144" "dstring2_snd_145" 
                                            (read-bytes (identifier "dstring1_snd_142") (identifier "dstring1_fst_141"))
                                            (make-tup
                                              (make-rec (string "in_signature") 
                                                (string-of-bytes (identifier "dstring2_fst_144")) 
                                                (string "signature") 
                                                (identifier "drec_fst_132") 
                                                (string "factors") (identifier "drec_fst_117") 
                                                (string "out_record") 
                                                (identifier "drec_fst_91") 
                                                (string "operation") 
                                                (identifier "drec_fst_88") 
                                                (string "doc") (identifier "drec_fst_85") 
                                                (string "is_lazy") (identifier "drec_fst_70") 
                                                (string "retention") 
                                                (identifier "drec_fst_64") 
                                                (string "name") (identifier "drec_fst_58")) 
                                              (identifier "dstring2_snd_145"))))))))))))))))))))))
 */
static std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> compiled_func_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> fun1282 { [&](Pointer p_0) {
    auto fun1283 { dessser::gen::function_name::of_row_binary };
    ::dessser::gen::source_info::t7ced0f6935c1265b26e1abfcc364f52e id_1284 { fun1283(p_0) };
    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1285;
    {
      ::dessser::gen::source_info::t7ced0f6935c1265b26e1abfcc364f52e drec_57 { id_1284 };
      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1286;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        Size id_1287 { 0UL };
        uint8_t id_1288 { drec_snd_59.peekU8(id_1287) };
        uint8_t id_1289 { 1 };
        bool id_1290 { bool(id_1288 == id_1289) };
        ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 choose_res_1291;
        if (id_1290) {
          std::optional<dessser::gen::retention::t_ext> id_1292 { std::nullopt };
          Size id_1293 { 1UL };
          Pointer id_1294 { drec_snd_59.skip(id_1293) };
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 id_1295 { id_1292, id_1294 };
          choose_res_1291 = id_1295;
        } else {
          auto fun1296 { dessser::gen::retention::of_row_binary };
          Size id_1297 { 1UL };
          Pointer id_1298 { drec_snd_59.skip(id_1297) };
          ::dessser::gen::source_info::tde821e6d031c399b029ea4a78810ecf6 id_1299 { fun1296(id_1298) };
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 letpair_res_1300;
          {
            auto make1_1_fst_61 { std::get<0>(id_1299) };
            auto make1_1_snd_62 { std::get<1>(id_1299) };
            std::optional<dessser::gen::retention::t_ext> id_1301 { make1_1_fst_61 };
            ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 id_1302 { id_1301, make1_1_snd_62 };
            letpair_res_1300 = id_1302;
          }
          choose_res_1291 = letpair_res_1300;
        }
        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1303;
        {
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 drec_63 { choose_res_1291 };
          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1304;
          {
            auto drec_fst_64 { std::get<0>(drec_63) };
            auto drec_snd_65 { std::get<1>(drec_63) };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1305 { drec_snd_65.readU8() };
            ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1306;
            {
              auto dbool_fst_67 { std::get<0>(id_1305) };
              auto dbool_snd_68 { std::get<1>(id_1305) };
              uint8_t id_1307 { 0 };
              bool id_1308 { bool(dbool_fst_67 == id_1307) };
              bool id_1309 { ! id_1308 };
              ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 id_1310 { id_1309, dbool_snd_68 };
              letpair_res_1306 = id_1310;
            }
            ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1311;
            {
              ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 drec_69 { letpair_res_1306 };
              ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1312;
              {
                auto drec_fst_70 { std::get<0>(drec_69) };
                auto drec_snd_71 { std::get<1>(drec_69) };
                uint32_t id_1313 { 0U };
                Vec<1, uint32_t> id_1314 {  id_1313  };
                ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1315;
                {
                  Vec<1, uint32_t> leb_ref_72 { id_1314 };
                  uint8_t id_1316 { 0 };
                  Vec<1, uint8_t> id_1317 {  id_1316  };
                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1318;
                  {
                    Vec<1, uint8_t> shft_ref_73 { id_1317 };
                    Vec<1, Pointer> id_1319 {  drec_snd_71  };
                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1320;
                    {
                      Vec<1, Pointer> p_ref_74 { id_1319 };
                      bool while_flag_1321 { true };
                      do {
                        uint8_t id_1322 { 0 };
                        Pointer id_1323 { p_ref_74[id_1322] };
                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1324 { id_1323.readU8() };
                        bool let_res_1325;
                        {
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_75 { id_1324 };
                          bool letpair_res_1326;
                          {
                            auto leb128_fst_76 { std::get<0>(leb128_75) };
                            auto leb128_snd_77 { std::get<1>(leb128_75) };
                            uint8_t id_1327 { 0 };
                            Void id_1328 { ((void)(p_ref_74[id_1327] = leb128_snd_77), ::dessser::Void()) };
                            (void)id_1328;
                            uint8_t id_1329 { 0 };
                            uint8_t id_1330 { 127 };
                            uint8_t id_1331 { uint8_t(leb128_fst_76 & id_1330) };
                            uint32_t id_1332 { uint32_t(id_1331) };
                            uint8_t id_1333 { 0 };
                            uint8_t id_1334 { shft_ref_73[id_1333] };
                            uint32_t id_1335 { uint32_t(id_1332 << id_1334) };
                            uint8_t id_1336 { 0 };
                            uint32_t id_1337 { leb_ref_72[id_1336] };
                            uint32_t id_1338 { uint32_t(id_1335 | id_1337) };
                            Void id_1339 { ((void)(leb_ref_72[id_1329] = id_1338), ::dessser::Void()) };
                            (void)id_1339;
                            uint8_t id_1340 { 0 };
                            uint8_t id_1341 { 0 };
                            uint8_t id_1342 { shft_ref_73[id_1341] };
                            uint8_t id_1343 { 7 };
                            uint8_t id_1344 { uint8_t(id_1342 + id_1343) };
                            Void id_1345 { ((void)(shft_ref_73[id_1340] = id_1344), ::dessser::Void()) };
                            (void)id_1345;
                            uint8_t id_1346 { 128 };
                            bool id_1347 { bool(leb128_fst_76 >= id_1346) };
                            letpair_res_1326 = id_1347;
                          }
                          let_res_1325 = letpair_res_1326;
                        }
                        while_flag_1321 = let_res_1325;
                        if (while_flag_1321) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_1321);
                      (void)::dessser::Void();
                      uint8_t id_1348 { 0 };
                      uint32_t id_1349 { leb_ref_72[id_1348] };
                      Size id_1350 { Size(id_1349) };
                      uint8_t id_1351 { 0 };
                      Pointer id_1352 { p_ref_74[id_1351] };
                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1353 { id_1350, id_1352 };
                      let_res_1320 = id_1353;
                    }
                    let_res_1318 = let_res_1320;
                  }
                  let_res_1315 = let_res_1318;
                }
                ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1354;
                {
                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_78 { let_res_1315 };
                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1355;
                  {
                    auto dstring1_fst_79 { std::get<0>(dstring1_78) };
                    auto dstring1_snd_80 { std::get<1>(dstring1_78) };
                    ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1356 { dstring1_snd_80.readBytes(dstring1_fst_79) };
                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1357;
                    {
                      auto dstring2_fst_82 { std::get<0>(id_1356) };
                      auto dstring2_snd_83 { std::get<1>(id_1356) };
                      std::string id_1358 { dstring2_fst_82.toString() };
                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1359 { id_1358, dstring2_snd_83 };
                      letpair_res_1357 = id_1359;
                    }
                    letpair_res_1355 = letpair_res_1357;
                  }
                  let_res_1354 = letpair_res_1355;
                }
                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1360;
                {
                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_84 { let_res_1354 };
                  ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1361;
                  {
                    auto drec_fst_85 { std::get<0>(drec_84) };
                    auto drec_snd_86 { std::get<1>(drec_84) };
                    auto fun1362 { dessser::gen::raql_operation::of_row_binary };
                    ::dessser::gen::source_info::t9539d836e50d2481333b4e3eeeadf0ff id_1363 { fun1362(drec_snd_86) };
                    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1364;
                    {
                      ::dessser::gen::source_info::t9539d836e50d2481333b4e3eeeadf0ff drec_87 { id_1363 };
                      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1365;
                      {
                        auto drec_fst_88 { std::get<0>(drec_87) };
                        auto drec_snd_89 { std::get<1>(drec_87) };
                        auto fun1366 { dessser::gen::raql_type::of_row_binary };
                        ::dessser::gen::source_info::t101502ffd7fb38beafe4b49259f92ba1 id_1367 { fun1366(drec_snd_89) };
                        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1368;
                        {
                          ::dessser::gen::source_info::t101502ffd7fb38beafe4b49259f92ba1 drec_90 { id_1367 };
                          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1369;
                          {
                            auto drec_fst_91 { std::get<0>(drec_90) };
                            auto drec_snd_92 { std::get<1>(drec_90) };
                            uint32_t id_1370 { 0U };
                            Vec<1, uint32_t> id_1371 {  id_1370  };
                            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1372;
                            {
                              Vec<1, uint32_t> leb_ref_93 { id_1371 };
                              uint8_t id_1373 { 0 };
                              Vec<1, uint8_t> id_1374 {  id_1373  };
                              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1375;
                              {
                                Vec<1, uint8_t> shft_ref_94 { id_1374 };
                                Vec<1, Pointer> id_1376 {  drec_snd_92  };
                                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1377;
                                {
                                  Vec<1, Pointer> p_ref_95 { id_1376 };
                                  bool while_flag_1378 { true };
                                  do {
                                    uint8_t id_1379 { 0 };
                                    Pointer id_1380 { p_ref_95[id_1379] };
                                    ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1381 { id_1380.readU8() };
                                    bool let_res_1382;
                                    {
                                      ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_96 { id_1381 };
                                      bool letpair_res_1383;
                                      {
                                        auto leb128_fst_97 { std::get<0>(leb128_96) };
                                        auto leb128_snd_98 { std::get<1>(leb128_96) };
                                        uint8_t id_1384 { 0 };
                                        Void id_1385 { ((void)(p_ref_95[id_1384] = leb128_snd_98), ::dessser::Void()) };
                                        (void)id_1385;
                                        uint8_t id_1386 { 0 };
                                        uint8_t id_1387 { 127 };
                                        uint8_t id_1388 { uint8_t(leb128_fst_97 & id_1387) };
                                        uint32_t id_1389 { uint32_t(id_1388) };
                                        uint8_t id_1390 { 0 };
                                        uint8_t id_1391 { shft_ref_94[id_1390] };
                                        uint32_t id_1392 { uint32_t(id_1389 << id_1391) };
                                        uint8_t id_1393 { 0 };
                                        uint32_t id_1394 { leb_ref_93[id_1393] };
                                        uint32_t id_1395 { uint32_t(id_1392 | id_1394) };
                                        Void id_1396 { ((void)(leb_ref_93[id_1386] = id_1395), ::dessser::Void()) };
                                        (void)id_1396;
                                        uint8_t id_1397 { 0 };
                                        uint8_t id_1398 { 0 };
                                        uint8_t id_1399 { shft_ref_94[id_1398] };
                                        uint8_t id_1400 { 7 };
                                        uint8_t id_1401 { uint8_t(id_1399 + id_1400) };
                                        Void id_1402 { ((void)(shft_ref_94[id_1397] = id_1401), ::dessser::Void()) };
                                        (void)id_1402;
                                        uint8_t id_1403 { 128 };
                                        bool id_1404 { bool(leb128_fst_97 >= id_1403) };
                                        letpair_res_1383 = id_1404;
                                      }
                                      let_res_1382 = letpair_res_1383;
                                    }
                                    while_flag_1378 = let_res_1382;
                                    if (while_flag_1378) {
                                      (void)::dessser::Void();
                                    }
                                  } while (while_flag_1378);
                                  (void)::dessser::Void();
                                  uint8_t id_1405 { 0 };
                                  uint32_t id_1406 { leb_ref_93[id_1405] };
                                  uint8_t id_1407 { 0 };
                                  Pointer id_1408 { p_ref_95[id_1407] };
                                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1409 { id_1406, id_1408 };
                                  let_res_1377 = id_1409;
                                }
                                let_res_1375 = let_res_1377;
                              }
                              let_res_1372 = let_res_1375;
                            }
                            ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1410;
                            {
                              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_102 { let_res_1372 };
                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1411;
                              {
                                auto dlist1_fst_103 { std::get<0>(dlist1_102) };
                                auto dlist1_snd_104 { std::get<1>(dlist1_102) };
                                Lst<dessser::gen::field_name::t_ext> endoflist_1412;
                                ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1413 { endoflist_1412, dlist1_snd_104 };
                                Vec<1, ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1414 {  id_1413  };
                                ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1415;
                                {
                                  Vec<1, ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_105 { id_1414 };
                                  int32_t id_1416 { 0L };
                                  Vec<1, int32_t> id_1417 {  id_1416  };
                                  {
                                    Vec<1, int32_t> repeat_n_106 { id_1417 };
                                    bool while_flag_1418 { true };
                                    do {
                                      int32_t id_1419 { int32_t(dlist1_fst_103) };
                                      uint8_t id_1420 { 0 };
                                      int32_t id_1421 { repeat_n_106[id_1420] };
                                      bool id_1422 { bool(id_1419 > id_1421) };
                                      while_flag_1418 = id_1422;
                                      if (while_flag_1418) {
                                        uint8_t id_1423 { 0 };
                                        ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1424 { inits_src_ref_105[id_1423] };
                                        {
                                          ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_107 { id_1424 };
                                          {
                                            auto dlist2_fst_108 { std::get<0>(dlist2_107) };
                                            auto dlist2_snd_109 { std::get<1>(dlist2_107) };
                                            uint8_t id_1425 { 0 };
                                            auto fun1426 { dessser::gen::field_name::of_row_binary };
                                            ::dessser::gen::source_info::t18cecf882d7ac80cef37dfe6b22279d4 id_1427 { fun1426(dlist2_snd_109) };
                                            ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1428;
                                            {
                                              auto dlist3_fst_111 { std::get<0>(id_1427) };
                                              auto dlist3_snd_112 { std::get<1>(id_1427) };
                                              Lst<dessser::gen::field_name::t_ext> id_1429 { dlist3_fst_111, dlist2_fst_108 };
                                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1430 { id_1429, dlist3_snd_112 };
                                              letpair_res_1428 = id_1430;
                                            }
                                            Void id_1431 { ((void)(inits_src_ref_105[id_1425] = letpair_res_1428), ::dessser::Void()) };
                                            (void)id_1431;
                                          }
                                          (void)::dessser::Void();
                                        }
                                        (void)::dessser::Void();
                                        uint8_t id_1432 { 0 };
                                        uint8_t id_1433 { 0 };
                                        int32_t id_1434 { repeat_n_106[id_1433] };
                                        int32_t id_1435 { 1L };
                                        int32_t id_1436 { int32_t(id_1434 + id_1435) };
                                        Void id_1437 { ((void)(repeat_n_106[id_1432] = id_1436), ::dessser::Void()) };
                                        (void)id_1437;
                                        (void)id_1437;
                                      }
                                    } while (while_flag_1418);
                                    (void)::dessser::Void();
                                  }
                                  (void)::dessser::Void();
                                  uint8_t id_1438 { 0 };
                                  ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1439 { inits_src_ref_105[id_1438] };
                                  let_res_1415 = id_1439;
                                }
                                letpair_res_1411 = let_res_1415;
                              }
                              let_res_1410 = letpair_res_1411;
                            }
                            ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1440;
                            {
                              auto dlist4_fst_114 { std::get<0>(let_res_1410) };
                              auto dlist4_snd_115 { std::get<1>(let_res_1410) };
                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1441 { dlist4_fst_114, dlist4_snd_115 };
                              letpair_res_1440 = id_1441;
                            }
                            ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1442;
                            {
                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 drec_116 { letpair_res_1440 };
                              ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1443;
                              {
                                auto drec_fst_117 { std::get<0>(drec_116) };
                                auto drec_snd_118 { std::get<1>(drec_116) };
                                uint32_t id_1444 { 0U };
                                Vec<1, uint32_t> id_1445 {  id_1444  };
                                ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1446;
                                {
                                  Vec<1, uint32_t> leb_ref_119 { id_1445 };
                                  uint8_t id_1447 { 0 };
                                  Vec<1, uint8_t> id_1448 {  id_1447  };
                                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1449;
                                  {
                                    Vec<1, uint8_t> shft_ref_120 { id_1448 };
                                    Vec<1, Pointer> id_1450 {  drec_snd_118  };
                                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1451;
                                    {
                                      Vec<1, Pointer> p_ref_121 { id_1450 };
                                      bool while_flag_1452 { true };
                                      do {
                                        uint8_t id_1453 { 0 };
                                        Pointer id_1454 { p_ref_121[id_1453] };
                                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1455 { id_1454.readU8() };
                                        bool let_res_1456;
                                        {
                                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_122 { id_1455 };
                                          bool letpair_res_1457;
                                          {
                                            auto leb128_fst_123 { std::get<0>(leb128_122) };
                                            auto leb128_snd_124 { std::get<1>(leb128_122) };
                                            uint8_t id_1458 { 0 };
                                            Void id_1459 { ((void)(p_ref_121[id_1458] = leb128_snd_124), ::dessser::Void()) };
                                            (void)id_1459;
                                            uint8_t id_1460 { 0 };
                                            uint8_t id_1461 { 127 };
                                            uint8_t id_1462 { uint8_t(leb128_fst_123 & id_1461) };
                                            uint32_t id_1463 { uint32_t(id_1462) };
                                            uint8_t id_1464 { 0 };
                                            uint8_t id_1465 { shft_ref_120[id_1464] };
                                            uint32_t id_1466 { uint32_t(id_1463 << id_1465) };
                                            uint8_t id_1467 { 0 };
                                            uint32_t id_1468 { leb_ref_119[id_1467] };
                                            uint32_t id_1469 { uint32_t(id_1466 | id_1468) };
                                            Void id_1470 { ((void)(leb_ref_119[id_1460] = id_1469), ::dessser::Void()) };
                                            (void)id_1470;
                                            uint8_t id_1471 { 0 };
                                            uint8_t id_1472 { 0 };
                                            uint8_t id_1473 { shft_ref_120[id_1472] };
                                            uint8_t id_1474 { 7 };
                                            uint8_t id_1475 { uint8_t(id_1473 + id_1474) };
                                            Void id_1476 { ((void)(shft_ref_120[id_1471] = id_1475), ::dessser::Void()) };
                                            (void)id_1476;
                                            uint8_t id_1477 { 128 };
                                            bool id_1478 { bool(leb128_fst_123 >= id_1477) };
                                            letpair_res_1457 = id_1478;
                                          }
                                          let_res_1456 = letpair_res_1457;
                                        }
                                        while_flag_1452 = let_res_1456;
                                        if (while_flag_1452) {
                                          (void)::dessser::Void();
                                        }
                                      } while (while_flag_1452);
                                      (void)::dessser::Void();
                                      uint8_t id_1479 { 0 };
                                      uint32_t id_1480 { leb_ref_119[id_1479] };
                                      Size id_1481 { Size(id_1480) };
                                      uint8_t id_1482 { 0 };
                                      Pointer id_1483 { p_ref_121[id_1482] };
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1484 { id_1481, id_1483 };
                                      let_res_1451 = id_1484;
                                    }
                                    let_res_1449 = let_res_1451;
                                  }
                                  let_res_1446 = let_res_1449;
                                }
                                ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1485;
                                {
                                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_125 { let_res_1446 };
                                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1486;
                                  {
                                    auto dstring1_fst_126 { std::get<0>(dstring1_125) };
                                    auto dstring1_snd_127 { std::get<1>(dstring1_125) };
                                    ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1487 { dstring1_snd_127.readBytes(dstring1_fst_126) };
                                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1488;
                                    {
                                      auto dstring2_fst_129 { std::get<0>(id_1487) };
                                      auto dstring2_snd_130 { std::get<1>(id_1487) };
                                      std::string id_1489 { dstring2_fst_129.toString() };
                                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1490 { id_1489, dstring2_snd_130 };
                                      letpair_res_1488 = id_1490;
                                    }
                                    letpair_res_1486 = letpair_res_1488;
                                  }
                                  let_res_1485 = letpair_res_1486;
                                }
                                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1491;
                                {
                                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_131 { let_res_1485 };
                                  ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1492;
                                  {
                                    auto drec_fst_132 { std::get<0>(drec_131) };
                                    auto drec_snd_133 { std::get<1>(drec_131) };
                                    uint32_t id_1493 { 0U };
                                    Vec<1, uint32_t> id_1494 {  id_1493  };
                                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1495;
                                    {
                                      Vec<1, uint32_t> leb_ref_134 { id_1494 };
                                      uint8_t id_1496 { 0 };
                                      Vec<1, uint8_t> id_1497 {  id_1496  };
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1498;
                                      {
                                        Vec<1, uint8_t> shft_ref_135 { id_1497 };
                                        Vec<1, Pointer> id_1499 {  drec_snd_133  };
                                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1500;
                                        {
                                          Vec<1, Pointer> p_ref_136 { id_1499 };
                                          bool while_flag_1501 { true };
                                          do {
                                            uint8_t id_1502 { 0 };
                                            Pointer id_1503 { p_ref_136[id_1502] };
                                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1504 { id_1503.readU8() };
                                            bool let_res_1505;
                                            {
                                              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_137 { id_1504 };
                                              bool letpair_res_1506;
                                              {
                                                auto leb128_fst_138 { std::get<0>(leb128_137) };
                                                auto leb128_snd_139 { std::get<1>(leb128_137) };
                                                uint8_t id_1507 { 0 };
                                                Void id_1508 { ((void)(p_ref_136[id_1507] = leb128_snd_139), ::dessser::Void()) };
                                                (void)id_1508;
                                                uint8_t id_1509 { 0 };
                                                uint8_t id_1510 { 127 };
                                                uint8_t id_1511 { uint8_t(leb128_fst_138 & id_1510) };
                                                uint32_t id_1512 { uint32_t(id_1511) };
                                                uint8_t id_1513 { 0 };
                                                uint8_t id_1514 { shft_ref_135[id_1513] };
                                                uint32_t id_1515 { uint32_t(id_1512 << id_1514) };
                                                uint8_t id_1516 { 0 };
                                                uint32_t id_1517 { leb_ref_134[id_1516] };
                                                uint32_t id_1518 { uint32_t(id_1515 | id_1517) };
                                                Void id_1519 { ((void)(leb_ref_134[id_1509] = id_1518), ::dessser::Void()) };
                                                (void)id_1519;
                                                uint8_t id_1520 { 0 };
                                                uint8_t id_1521 { 0 };
                                                uint8_t id_1522 { shft_ref_135[id_1521] };
                                                uint8_t id_1523 { 7 };
                                                uint8_t id_1524 { uint8_t(id_1522 + id_1523) };
                                                Void id_1525 { ((void)(shft_ref_135[id_1520] = id_1524), ::dessser::Void()) };
                                                (void)id_1525;
                                                uint8_t id_1526 { 128 };
                                                bool id_1527 { bool(leb128_fst_138 >= id_1526) };
                                                letpair_res_1506 = id_1527;
                                              }
                                              let_res_1505 = letpair_res_1506;
                                            }
                                            while_flag_1501 = let_res_1505;
                                            if (while_flag_1501) {
                                              (void)::dessser::Void();
                                            }
                                          } while (while_flag_1501);
                                          (void)::dessser::Void();
                                          uint8_t id_1528 { 0 };
                                          uint32_t id_1529 { leb_ref_134[id_1528] };
                                          Size id_1530 { Size(id_1529) };
                                          uint8_t id_1531 { 0 };
                                          Pointer id_1532 { p_ref_136[id_1531] };
                                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1533 { id_1530, id_1532 };
                                          let_res_1500 = id_1533;
                                        }
                                        let_res_1498 = let_res_1500;
                                      }
                                      let_res_1495 = let_res_1498;
                                    }
                                    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1534;
                                    {
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_140 { let_res_1495 };
                                      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1535;
                                      {
                                        auto dstring1_fst_141 { std::get<0>(dstring1_140) };
                                        auto dstring1_snd_142 { std::get<1>(dstring1_140) };
                                        ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1536 { dstring1_snd_142.readBytes(dstring1_fst_141) };
                                        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1537;
                                        {
                                          auto dstring2_fst_144 { std::get<0>(id_1536) };
                                          auto dstring2_snd_145 { std::get<1>(id_1536) };
                                          std::string id_1538 { dstring2_fst_144.toString() };
                                          std::shared_ptr<::dessser::gen::source_info::compiled_func>  id_1539 { std::make_shared<::dessser::gen::source_info::compiled_func>(drec_fst_58, drec_fst_64, drec_fst_70, drec_fst_85, drec_fst_88, drec_fst_91, drec_fst_117, drec_fst_132, id_1538) };
                                          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be id_1540 { id_1539, dstring2_snd_145 };
                                          letpair_res_1537 = id_1540;
                                        }
                                        letpair_res_1535 = letpair_res_1537;
                                      }
                                      let_res_1534 = letpair_res_1535;
                                    }
                                    letpair_res_1492 = let_res_1534;
                                  }
                                  let_res_1491 = letpair_res_1492;
                                }
                                letpair_res_1443 = let_res_1491;
                              }
                              let_res_1442 = letpair_res_1443;
                            }
                            letpair_res_1369 = let_res_1442;
                          }
                          let_res_1368 = letpair_res_1369;
                        }
                        letpair_res_1365 = let_res_1368;
                      }
                      let_res_1364 = letpair_res_1365;
                    }
                    letpair_res_1361 = let_res_1364;
                  }
                  let_res_1360 = letpair_res_1361;
                }
                letpair_res_1312 = let_res_1360;
              }
              let_res_1311 = letpair_res_1312;
            }
            letpair_res_1304 = let_res_1311;
          }
          let_res_1303 = letpair_res_1304;
        }
        letpair_res_1286 = let_res_1303;
      }
      let_res_1285 = letpair_res_1286;
    }
    return let_res_1285;
  }
   };
  return fun1282;
}
std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> compiled_func_of_row_binary(compiled_func_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_172"
        (let-pair "dlist4_fst_170" "dlist4_snd_171"
          (let "dlist1_158"
            (let "leb_ref_149" (make-vec (u32 0))
              (let "shft_ref_150" (make-vec (u8 0))
                (let "p_ref_151" (make-vec (param 0))
                  (seq
                    (while
                      (let "leb128_152" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_151")))
                        (let-pair "leb128_fst_153" "leb128_snd_154" (identifier "leb128_152")
                          (seq (set-vec (u8 0) (identifier "p_ref_151") (identifier "leb128_snd_154"))
                            (set-vec (u8 0) (identifier "leb_ref_149")
                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_153") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_150"))) (unsafe-nth (u8 0) (identifier "leb_ref_149"))))
                            (set-vec (u8 0) (identifier "shft_ref_150") (add (unsafe-nth (u8 0) (identifier "shft_ref_150")) (u8 7))) 
                            (ge (identifier "leb128_fst_153") (u8 128))))) 
                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_149")) (unsafe-nth (u8 0) (identifier "p_ref_151")))))))
            (let-pair "dlist1_fst_159" "dlist1_snd_160" (identifier "dlist1_158")
              (let "inits_src_ref_161" (make-vec (make-tup (end-of-list "$program_parameter") (identifier "dlist1_snd_160")))
                (seq
                  (let "repeat_n_162" (make-vec (i32 0))
                    (while (gt (to-i32 (identifier "dlist1_fst_159")) (unsafe-nth (u8 0) (identifier "repeat_n_162")))
                      (seq
                        (let "dlist2_163" (unsafe-nth (u8 0) (identifier "inits_src_ref_161"))
                          (let-pair "dlist2_fst_164" "dlist2_snd_165" 
                            (identifier "dlist2_163")
                            (set-vec (u8 0) (identifier "inits_src_ref_161")
                              (let-pair "dlist3_fst_167" "dlist3_snd_168" 
                                (apply (ext-identifier program_parameter of-row-binary) (identifier "dlist2_snd_165")) 
                                (make-tup (cons (identifier "dlist3_fst_167") (identifier "dlist2_fst_164")) (identifier "dlist3_snd_168"))))))
                        (set-vec (u8 0) (identifier "repeat_n_162") (add (unsafe-nth (u8 0) (identifier "repeat_n_162")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "inits_src_ref_161")))))) 
          (make-tup (identity (identifier "dlist4_fst_170")) (identifier "dlist4_snd_171")))
        (let-pair "drec_fst_173" "drec_snd_174" (identifier "drec_172")
          (let "drec_175" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_174"))
            (let-pair "drec_fst_176" "drec_snd_177" (identifier "drec_175")
              (let "drec_201"
                (let-pair "dlist4_fst_199" "dlist4_snd_200"
                  (let "dlist1_187"
                    (let "leb_ref_178" (make-vec (u32 0))
                      (let "shft_ref_179" (make-vec (u8 0))
                        (let "p_ref_180" (make-vec (identifier "drec_snd_177"))
                          (seq
                            (while
                              (let "leb128_181" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_180")))
                                (let-pair "leb128_fst_182" "leb128_snd_183" 
                                  (identifier "leb128_181")
                                  (seq (set-vec (u8 0) (identifier "p_ref_180") (identifier "leb128_snd_183"))
                                    (set-vec (u8 0) (identifier "leb_ref_178")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_182") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_179"))) (unsafe-nth (u8 0) (identifier "leb_ref_178"))))
                                    (set-vec (u8 0) (identifier "shft_ref_179") (add (unsafe-nth (u8 0) (identifier "shft_ref_179")) (u8 7))) 
                                    (ge (identifier "leb128_fst_182") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_178")) (unsafe-nth (u8 0) (identifier "p_ref_180")))))))
                    (let-pair "dlist1_fst_188" "dlist1_snd_189" (identifier "dlist1_187")
                      (let "inits_src_ref_190" (make-vec (make-tup (end-of-list "$global_variable") (identifier "dlist1_snd_189")))
                        (seq
                          (let "repeat_n_191" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_188")) (unsafe-nth (u8 0) (identifier "repeat_n_191")))
                              (seq
                                (let "dlist2_192" (unsafe-nth (u8 0) (identifier "inits_src_ref_190"))
                                  (let-pair "dlist2_fst_193" "dlist2_snd_194" 
                                    (identifier "dlist2_192")
                                    (set-vec (u8 0) (identifier "inits_src_ref_190")
                                      (let-pair "dlist3_fst_196" "dlist3_snd_197" 
                                        (apply (ext-identifier global_variable of-row-binary) (identifier "dlist2_snd_194"))
                                        (make-tup (cons (identifier "dlist3_fst_196") (identifier "dlist2_fst_193")) (identifier "dlist3_snd_197"))))))
                                (set-vec (u8 0) (identifier "repeat_n_191") (add (unsafe-nth (u8 0) (identifier "repeat_n_191")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_190")))))) 
                  (make-tup (identity (identifier "dlist4_fst_199")) (identifier "dlist4_snd_200")))
                (let-pair "drec_fst_202" "drec_snd_203" (identifier "drec_201")
                  (let "drec_227"
                    (let-pair "dlist4_fst_225" "dlist4_snd_226"
                      (let "dlist1_213"
                        (let "leb_ref_204" (make-vec (u32 0))
                          (let "shft_ref_205" (make-vec (u8 0))
                            (let "p_ref_206" (make-vec (identifier "drec_snd_203"))
                              (seq
                                (while
                                  (let "leb128_207" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_206")))
                                    (let-pair "leb128_fst_208" "leb128_snd_209" 
                                      (identifier "leb128_207")
                                      (seq (set-vec (u8 0) (identifier "p_ref_206") (identifier "leb128_snd_209"))
                                        (set-vec (u8 0) (identifier "leb_ref_204")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_208") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_205"))) (unsafe-nth (u8 0) (identifier "leb_ref_204"))))
                                        (set-vec (u8 0) (identifier "shft_ref_205") (add (unsafe-nth (u8 0) (identifier "shft_ref_205")) (u8 7))) 
                                        (ge (identifier "leb128_fst_208") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_204")) (unsafe-nth (u8 0) (identifier "p_ref_206")))))))
                        (let-pair "dlist1_fst_214" "dlist1_snd_215" (identifier "dlist1_213")
                          (let "inits_src_ref_216"
                            (make-vec
                              (make-tup
                                (end-of-list "(compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})")
                                (identifier "dlist1_snd_215")))
                            (seq
                              (let "repeat_n_217" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_214")) (unsafe-nth (u8 0) (identifier "repeat_n_217")))
                                  (seq
                                    (let "dlist2_218" (unsafe-nth (u8 0) (identifier "inits_src_ref_216"))
                                      (let-pair "dlist2_fst_219" "dlist2_snd_220" 
                                        (identifier "dlist2_218")
                                        (set-vec (u8 0) (identifier "inits_src_ref_216")
                                          (let-pair "dlist3_fst_222" "dlist3_snd_223" 
                                            (apply (identifier "compiled_func-of-row-binary") (identifier "dlist2_snd_220"))
                                            (make-tup (cons (identifier "dlist3_fst_222") (identifier "dlist2_fst_219")) (identifier "dlist3_snd_223"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_217") (add (unsafe-nth (u8 0) (identifier "repeat_n_217")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_216")))))) 
                      (make-tup (identity (identifier "dlist4_fst_225")) (identifier "dlist4_snd_226")))
                    (let-pair "drec_fst_228" "drec_snd_229" (identifier "drec_227")
                      (let-pair "dlist4_fst_251" "dlist4_snd_252"
                        (let "dlist1_239"
                          (let "leb_ref_230" (make-vec (u32 0))
                            (let "shft_ref_231" (make-vec (u8 0))
                              (let "p_ref_232" (make-vec (identifier "drec_snd_229"))
                                (seq
                                  (while
                                    (let "leb128_233" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_232")))
                                      (let-pair "leb128_fst_234" "leb128_snd_235" 
                                        (identifier "leb128_233")
                                        (seq (set-vec (u8 0) (identifier "p_ref_232") (identifier "leb128_snd_235"))
                                          (set-vec (u8 0) (identifier "leb_ref_230")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_234") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_231"))) (unsafe-nth (u8 0) (identifier "leb_ref_230"))))
                                          (set-vec (u8 0) (identifier "shft_ref_231") (add (unsafe-nth (u8 0) (identifier "shft_ref_231")) (u8 7))) 
                                          (ge (identifier "leb128_fst_234") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_230")) (unsafe-nth (u8 0) (identifier "p_ref_232")))))))
                          (let-pair "dlist1_fst_240" "dlist1_snd_241" 
                            (identifier "dlist1_239")
                            (let "inits_src_ref_242" (make-vec (make-tup (end-of-list "$raql_warning") (identifier "dlist1_snd_241")))
                              (seq
                                (let "repeat_n_243" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_240")) (unsafe-nth (u8 0) (identifier "repeat_n_243")))
                                    (seq
                                      (let "dlist2_244" (unsafe-nth (u8 0) (identifier "inits_src_ref_242"))
                                        (let-pair "dlist2_fst_245" "dlist2_snd_246" 
                                          (identifier "dlist2_244")
                                          (set-vec (u8 0) (identifier "inits_src_ref_242")
                                            (let-pair "dlist3_fst_248" "dlist3_snd_249" 
                                              (apply (ext-identifier raql_warning of-row-binary) (identifier "dlist2_snd_246"))
                                              (make-tup (cons (identifier "dlist3_fst_248") (identifier "dlist2_fst_245")) (identifier "dlist3_snd_249"))))))
                                      (set-vec (u8 0) (identifier "repeat_n_243") (add (unsafe-nth (u8 0) (identifier "repeat_n_243")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_242"))))))
                        (make-tup
                          (make-rec (string "warnings") (identity (identifier "dlist4_fst_251")) 
                            (string "funcs") (identifier "drec_fst_228") 
                            (string "globals") (identifier "drec_fst_202") 
                            (string "condition") (identifier "drec_fst_176") 
                            (string "default_params") (identifier "drec_fst_173")) 
                          (identifier "dlist4_snd_252"))))))))))))
 */
static std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> compiled_program_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> fun1541 { [&](Pointer p_0) {
    uint32_t id_1542 { 0U };
    Vec<1, uint32_t> id_1543 {  id_1542  };
    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1544;
    {
      Vec<1, uint32_t> leb_ref_149 { id_1543 };
      uint8_t id_1545 { 0 };
      Vec<1, uint8_t> id_1546 {  id_1545  };
      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1547;
      {
        Vec<1, uint8_t> shft_ref_150 { id_1546 };
        Vec<1, Pointer> id_1548 {  p_0  };
        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1549;
        {
          Vec<1, Pointer> p_ref_151 { id_1548 };
          bool while_flag_1550 { true };
          do {
            uint8_t id_1551 { 0 };
            Pointer id_1552 { p_ref_151[id_1551] };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1553 { id_1552.readU8() };
            bool let_res_1554;
            {
              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_152 { id_1553 };
              bool letpair_res_1555;
              {
                auto leb128_fst_153 { std::get<0>(leb128_152) };
                auto leb128_snd_154 { std::get<1>(leb128_152) };
                uint8_t id_1556 { 0 };
                Void id_1557 { ((void)(p_ref_151[id_1556] = leb128_snd_154), ::dessser::Void()) };
                (void)id_1557;
                uint8_t id_1558 { 0 };
                uint8_t id_1559 { 127 };
                uint8_t id_1560 { uint8_t(leb128_fst_153 & id_1559) };
                uint32_t id_1561 { uint32_t(id_1560) };
                uint8_t id_1562 { 0 };
                uint8_t id_1563 { shft_ref_150[id_1562] };
                uint32_t id_1564 { uint32_t(id_1561 << id_1563) };
                uint8_t id_1565 { 0 };
                uint32_t id_1566 { leb_ref_149[id_1565] };
                uint32_t id_1567 { uint32_t(id_1564 | id_1566) };
                Void id_1568 { ((void)(leb_ref_149[id_1558] = id_1567), ::dessser::Void()) };
                (void)id_1568;
                uint8_t id_1569 { 0 };
                uint8_t id_1570 { 0 };
                uint8_t id_1571 { shft_ref_150[id_1570] };
                uint8_t id_1572 { 7 };
                uint8_t id_1573 { uint8_t(id_1571 + id_1572) };
                Void id_1574 { ((void)(shft_ref_150[id_1569] = id_1573), ::dessser::Void()) };
                (void)id_1574;
                uint8_t id_1575 { 128 };
                bool id_1576 { bool(leb128_fst_153 >= id_1575) };
                letpair_res_1555 = id_1576;
              }
              let_res_1554 = letpair_res_1555;
            }
            while_flag_1550 = let_res_1554;
            if (while_flag_1550) {
              (void)::dessser::Void();
            }
          } while (while_flag_1550);
          (void)::dessser::Void();
          uint8_t id_1577 { 0 };
          uint32_t id_1578 { leb_ref_149[id_1577] };
          uint8_t id_1579 { 0 };
          Pointer id_1580 { p_ref_151[id_1579] };
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1581 { id_1578, id_1580 };
          let_res_1549 = id_1581;
        }
        let_res_1547 = let_res_1549;
      }
      let_res_1544 = let_res_1547;
    }
    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 let_res_1582;
    {
      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_158 { let_res_1544 };
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1583;
      {
        auto dlist1_fst_159 { std::get<0>(dlist1_158) };
        auto dlist1_snd_160 { std::get<1>(dlist1_158) };
        Lst<dessser::gen::program_parameter::t_ext> endoflist_1584;
        ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1585 { endoflist_1584, dlist1_snd_160 };
        Vec<1, ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800> id_1586 {  id_1585  };
        ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 let_res_1587;
        {
          Vec<1, ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800> inits_src_ref_161 { id_1586 };
          int32_t id_1588 { 0L };
          Vec<1, int32_t> id_1589 {  id_1588  };
          {
            Vec<1, int32_t> repeat_n_162 { id_1589 };
            bool while_flag_1590 { true };
            do {
              int32_t id_1591 { int32_t(dlist1_fst_159) };
              uint8_t id_1592 { 0 };
              int32_t id_1593 { repeat_n_162[id_1592] };
              bool id_1594 { bool(id_1591 > id_1593) };
              while_flag_1590 = id_1594;
              if (while_flag_1590) {
                uint8_t id_1595 { 0 };
                ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1596 { inits_src_ref_161[id_1595] };
                {
                  ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 dlist2_163 { id_1596 };
                  {
                    auto dlist2_fst_164 { std::get<0>(dlist2_163) };
                    auto dlist2_snd_165 { std::get<1>(dlist2_163) };
                    uint8_t id_1597 { 0 };
                    auto fun1598 { dessser::gen::program_parameter::of_row_binary };
                    ::dessser::gen::source_info::tbbb6e77f92131ca39155edc6f36a3063 id_1599 { fun1598(dlist2_snd_165) };
                    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1600;
                    {
                      auto dlist3_fst_167 { std::get<0>(id_1599) };
                      auto dlist3_snd_168 { std::get<1>(id_1599) };
                      Lst<dessser::gen::program_parameter::t_ext> id_1601 { dlist3_fst_167, dlist2_fst_164 };
                      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1602 { id_1601, dlist3_snd_168 };
                      letpair_res_1600 = id_1602;
                    }
                    Void id_1603 { ((void)(inits_src_ref_161[id_1597] = letpair_res_1600), ::dessser::Void()) };
                    (void)id_1603;
                  }
                  (void)::dessser::Void();
                }
                (void)::dessser::Void();
                uint8_t id_1604 { 0 };
                uint8_t id_1605 { 0 };
                int32_t id_1606 { repeat_n_162[id_1605] };
                int32_t id_1607 { 1L };
                int32_t id_1608 { int32_t(id_1606 + id_1607) };
                Void id_1609 { ((void)(repeat_n_162[id_1604] = id_1608), ::dessser::Void()) };
                (void)id_1609;
                (void)id_1609;
              }
            } while (while_flag_1590);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_1610 { 0 };
          ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1611 { inits_src_ref_161[id_1610] };
          let_res_1587 = id_1611;
        }
        letpair_res_1583 = let_res_1587;
      }
      let_res_1582 = letpair_res_1583;
    }
    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1612;
    {
      auto dlist4_fst_170 { std::get<0>(let_res_1582) };
      auto dlist4_snd_171 { std::get<1>(let_res_1582) };
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1613 { dlist4_fst_170, dlist4_snd_171 };
      letpair_res_1612 = id_1613;
    }
    ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1614;
    {
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 drec_172 { letpair_res_1612 };
      ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1615;
      {
        auto drec_fst_173 { std::get<0>(drec_172) };
        auto drec_snd_174 { std::get<1>(drec_172) };
        auto fun1616 { dessser::gen::raql_expr::of_row_binary };
        ::dessser::gen::source_info::tc473a3a3b5068e57b15e934d0afcc038 id_1617 { fun1616(drec_snd_174) };
        ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1618;
        {
          ::dessser::gen::source_info::tc473a3a3b5068e57b15e934d0afcc038 drec_175 { id_1617 };
          ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1619;
          {
            auto drec_fst_176 { std::get<0>(drec_175) };
            auto drec_snd_177 { std::get<1>(drec_175) };
            uint32_t id_1620 { 0U };
            Vec<1, uint32_t> id_1621 {  id_1620  };
            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1622;
            {
              Vec<1, uint32_t> leb_ref_178 { id_1621 };
              uint8_t id_1623 { 0 };
              Vec<1, uint8_t> id_1624 {  id_1623  };
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1625;
              {
                Vec<1, uint8_t> shft_ref_179 { id_1624 };
                Vec<1, Pointer> id_1626 {  drec_snd_177  };
                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1627;
                {
                  Vec<1, Pointer> p_ref_180 { id_1626 };
                  bool while_flag_1628 { true };
                  do {
                    uint8_t id_1629 { 0 };
                    Pointer id_1630 { p_ref_180[id_1629] };
                    ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1631 { id_1630.readU8() };
                    bool let_res_1632;
                    {
                      ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_181 { id_1631 };
                      bool letpair_res_1633;
                      {
                        auto leb128_fst_182 { std::get<0>(leb128_181) };
                        auto leb128_snd_183 { std::get<1>(leb128_181) };
                        uint8_t id_1634 { 0 };
                        Void id_1635 { ((void)(p_ref_180[id_1634] = leb128_snd_183), ::dessser::Void()) };
                        (void)id_1635;
                        uint8_t id_1636 { 0 };
                        uint8_t id_1637 { 127 };
                        uint8_t id_1638 { uint8_t(leb128_fst_182 & id_1637) };
                        uint32_t id_1639 { uint32_t(id_1638) };
                        uint8_t id_1640 { 0 };
                        uint8_t id_1641 { shft_ref_179[id_1640] };
                        uint32_t id_1642 { uint32_t(id_1639 << id_1641) };
                        uint8_t id_1643 { 0 };
                        uint32_t id_1644 { leb_ref_178[id_1643] };
                        uint32_t id_1645 { uint32_t(id_1642 | id_1644) };
                        Void id_1646 { ((void)(leb_ref_178[id_1636] = id_1645), ::dessser::Void()) };
                        (void)id_1646;
                        uint8_t id_1647 { 0 };
                        uint8_t id_1648 { 0 };
                        uint8_t id_1649 { shft_ref_179[id_1648] };
                        uint8_t id_1650 { 7 };
                        uint8_t id_1651 { uint8_t(id_1649 + id_1650) };
                        Void id_1652 { ((void)(shft_ref_179[id_1647] = id_1651), ::dessser::Void()) };
                        (void)id_1652;
                        uint8_t id_1653 { 128 };
                        bool id_1654 { bool(leb128_fst_182 >= id_1653) };
                        letpair_res_1633 = id_1654;
                      }
                      let_res_1632 = letpair_res_1633;
                    }
                    while_flag_1628 = let_res_1632;
                    if (while_flag_1628) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_1628);
                  (void)::dessser::Void();
                  uint8_t id_1655 { 0 };
                  uint32_t id_1656 { leb_ref_178[id_1655] };
                  uint8_t id_1657 { 0 };
                  Pointer id_1658 { p_ref_180[id_1657] };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1659 { id_1656, id_1658 };
                  let_res_1627 = id_1659;
                }
                let_res_1625 = let_res_1627;
              }
              let_res_1622 = let_res_1625;
            }
            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 let_res_1660;
            {
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_187 { let_res_1622 };
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1661;
              {
                auto dlist1_fst_188 { std::get<0>(dlist1_187) };
                auto dlist1_snd_189 { std::get<1>(dlist1_187) };
                Lst<dessser::gen::global_variable::t_ext> endoflist_1662;
                ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1663 { endoflist_1662, dlist1_snd_189 };
                Vec<1, ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7> id_1664 {  id_1663  };
                ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 let_res_1665;
                {
                  Vec<1, ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7> inits_src_ref_190 { id_1664 };
                  int32_t id_1666 { 0L };
                  Vec<1, int32_t> id_1667 {  id_1666  };
                  {
                    Vec<1, int32_t> repeat_n_191 { id_1667 };
                    bool while_flag_1668 { true };
                    do {
                      int32_t id_1669 { int32_t(dlist1_fst_188) };
                      uint8_t id_1670 { 0 };
                      int32_t id_1671 { repeat_n_191[id_1670] };
                      bool id_1672 { bool(id_1669 > id_1671) };
                      while_flag_1668 = id_1672;
                      if (while_flag_1668) {
                        uint8_t id_1673 { 0 };
                        ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1674 { inits_src_ref_190[id_1673] };
                        {
                          ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 dlist2_192 { id_1674 };
                          {
                            auto dlist2_fst_193 { std::get<0>(dlist2_192) };
                            auto dlist2_snd_194 { std::get<1>(dlist2_192) };
                            uint8_t id_1675 { 0 };
                            auto fun1676 { dessser::gen::global_variable::of_row_binary };
                            ::dessser::gen::source_info::t40a6bf0f8e6a7b21bd5b768113e20619 id_1677 { fun1676(dlist2_snd_194) };
                            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1678;
                            {
                              auto dlist3_fst_196 { std::get<0>(id_1677) };
                              auto dlist3_snd_197 { std::get<1>(id_1677) };
                              Lst<dessser::gen::global_variable::t_ext> id_1679 { dlist3_fst_196, dlist2_fst_193 };
                              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1680 { id_1679, dlist3_snd_197 };
                              letpair_res_1678 = id_1680;
                            }
                            Void id_1681 { ((void)(inits_src_ref_190[id_1675] = letpair_res_1678), ::dessser::Void()) };
                            (void)id_1681;
                          }
                          (void)::dessser::Void();
                        }
                        (void)::dessser::Void();
                        uint8_t id_1682 { 0 };
                        uint8_t id_1683 { 0 };
                        int32_t id_1684 { repeat_n_191[id_1683] };
                        int32_t id_1685 { 1L };
                        int32_t id_1686 { int32_t(id_1684 + id_1685) };
                        Void id_1687 { ((void)(repeat_n_191[id_1682] = id_1686), ::dessser::Void()) };
                        (void)id_1687;
                        (void)id_1687;
                      }
                    } while (while_flag_1668);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_1688 { 0 };
                  ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1689 { inits_src_ref_190[id_1688] };
                  let_res_1665 = id_1689;
                }
                letpair_res_1661 = let_res_1665;
              }
              let_res_1660 = letpair_res_1661;
            }
            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1690;
            {
              auto dlist4_fst_199 { std::get<0>(let_res_1660) };
              auto dlist4_snd_200 { std::get<1>(let_res_1660) };
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1691 { dlist4_fst_199, dlist4_snd_200 };
              letpair_res_1690 = id_1691;
            }
            ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1692;
            {
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 drec_201 { letpair_res_1690 };
              ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1693;
              {
                auto drec_fst_202 { std::get<0>(drec_201) };
                auto drec_snd_203 { std::get<1>(drec_201) };
                uint32_t id_1694 { 0U };
                Vec<1, uint32_t> id_1695 {  id_1694  };
                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1696;
                {
                  Vec<1, uint32_t> leb_ref_204 { id_1695 };
                  uint8_t id_1697 { 0 };
                  Vec<1, uint8_t> id_1698 {  id_1697  };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1699;
                  {
                    Vec<1, uint8_t> shft_ref_205 { id_1698 };
                    Vec<1, Pointer> id_1700 {  drec_snd_203  };
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1701;
                    {
                      Vec<1, Pointer> p_ref_206 { id_1700 };
                      bool while_flag_1702 { true };
                      do {
                        uint8_t id_1703 { 0 };
                        Pointer id_1704 { p_ref_206[id_1703] };
                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1705 { id_1704.readU8() };
                        bool let_res_1706;
                        {
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_207 { id_1705 };
                          bool letpair_res_1707;
                          {
                            auto leb128_fst_208 { std::get<0>(leb128_207) };
                            auto leb128_snd_209 { std::get<1>(leb128_207) };
                            uint8_t id_1708 { 0 };
                            Void id_1709 { ((void)(p_ref_206[id_1708] = leb128_snd_209), ::dessser::Void()) };
                            (void)id_1709;
                            uint8_t id_1710 { 0 };
                            uint8_t id_1711 { 127 };
                            uint8_t id_1712 { uint8_t(leb128_fst_208 & id_1711) };
                            uint32_t id_1713 { uint32_t(id_1712) };
                            uint8_t id_1714 { 0 };
                            uint8_t id_1715 { shft_ref_205[id_1714] };
                            uint32_t id_1716 { uint32_t(id_1713 << id_1715) };
                            uint8_t id_1717 { 0 };
                            uint32_t id_1718 { leb_ref_204[id_1717] };
                            uint32_t id_1719 { uint32_t(id_1716 | id_1718) };
                            Void id_1720 { ((void)(leb_ref_204[id_1710] = id_1719), ::dessser::Void()) };
                            (void)id_1720;
                            uint8_t id_1721 { 0 };
                            uint8_t id_1722 { 0 };
                            uint8_t id_1723 { shft_ref_205[id_1722] };
                            uint8_t id_1724 { 7 };
                            uint8_t id_1725 { uint8_t(id_1723 + id_1724) };
                            Void id_1726 { ((void)(shft_ref_205[id_1721] = id_1725), ::dessser::Void()) };
                            (void)id_1726;
                            uint8_t id_1727 { 128 };
                            bool id_1728 { bool(leb128_fst_208 >= id_1727) };
                            letpair_res_1707 = id_1728;
                          }
                          let_res_1706 = letpair_res_1707;
                        }
                        while_flag_1702 = let_res_1706;
                        if (while_flag_1702) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_1702);
                      (void)::dessser::Void();
                      uint8_t id_1729 { 0 };
                      uint32_t id_1730 { leb_ref_204[id_1729] };
                      uint8_t id_1731 { 0 };
                      Pointer id_1732 { p_ref_206[id_1731] };
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1733 { id_1730, id_1732 };
                      let_res_1701 = id_1733;
                    }
                    let_res_1699 = let_res_1701;
                  }
                  let_res_1696 = let_res_1699;
                }
                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 let_res_1734;
                {
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_213 { let_res_1696 };
                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1735;
                  {
                    auto dlist1_fst_214 { std::get<0>(dlist1_213) };
                    auto dlist1_snd_215 { std::get<1>(dlist1_213) };
                    Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > endoflist_1736;
                    ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1737 { endoflist_1736, dlist1_snd_215 };
                    Vec<1, ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47> id_1738 {  id_1737  };
                    ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 let_res_1739;
                    {
                      Vec<1, ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47> inits_src_ref_216 { id_1738 };
                      int32_t id_1740 { 0L };
                      Vec<1, int32_t> id_1741 {  id_1740  };
                      {
                        Vec<1, int32_t> repeat_n_217 { id_1741 };
                        bool while_flag_1742 { true };
                        do {
                          int32_t id_1743 { int32_t(dlist1_fst_214) };
                          uint8_t id_1744 { 0 };
                          int32_t id_1745 { repeat_n_217[id_1744] };
                          bool id_1746 { bool(id_1743 > id_1745) };
                          while_flag_1742 = id_1746;
                          if (while_flag_1742) {
                            uint8_t id_1747 { 0 };
                            ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1748 { inits_src_ref_216[id_1747] };
                            {
                              ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 dlist2_218 { id_1748 };
                              {
                                auto dlist2_fst_219 { std::get<0>(dlist2_218) };
                                auto dlist2_snd_220 { std::get<1>(dlist2_218) };
                                uint8_t id_1749 { 0 };
                                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be id_1750 { compiled_func_of_row_binary(dlist2_snd_220) };
                                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1751;
                                {
                                  auto dlist3_fst_222 { std::get<0>(id_1750) };
                                  auto dlist3_snd_223 { std::get<1>(id_1750) };
                                  Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_1752 { dlist3_fst_222, dlist2_fst_219 };
                                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1753 { id_1752, dlist3_snd_223 };
                                  letpair_res_1751 = id_1753;
                                }
                                Void id_1754 { ((void)(inits_src_ref_216[id_1749] = letpair_res_1751), ::dessser::Void()) };
                                (void)id_1754;
                              }
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_1755 { 0 };
                            uint8_t id_1756 { 0 };
                            int32_t id_1757 { repeat_n_217[id_1756] };
                            int32_t id_1758 { 1L };
                            int32_t id_1759 { int32_t(id_1757 + id_1758) };
                            Void id_1760 { ((void)(repeat_n_217[id_1755] = id_1759), ::dessser::Void()) };
                            (void)id_1760;
                            (void)id_1760;
                          }
                        } while (while_flag_1742);
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_1761 { 0 };
                      ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1762 { inits_src_ref_216[id_1761] };
                      let_res_1739 = id_1762;
                    }
                    letpair_res_1735 = let_res_1739;
                  }
                  let_res_1734 = letpair_res_1735;
                }
                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1763;
                {
                  auto dlist4_fst_225 { std::get<0>(let_res_1734) };
                  auto dlist4_snd_226 { std::get<1>(let_res_1734) };
                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1764 { dlist4_fst_225, dlist4_snd_226 };
                  letpair_res_1763 = id_1764;
                }
                ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1765;
                {
                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 drec_227 { letpair_res_1763 };
                  ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1766;
                  {
                    auto drec_fst_228 { std::get<0>(drec_227) };
                    auto drec_snd_229 { std::get<1>(drec_227) };
                    uint32_t id_1767 { 0U };
                    Vec<1, uint32_t> id_1768 {  id_1767  };
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1769;
                    {
                      Vec<1, uint32_t> leb_ref_230 { id_1768 };
                      uint8_t id_1770 { 0 };
                      Vec<1, uint8_t> id_1771 {  id_1770  };
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1772;
                      {
                        Vec<1, uint8_t> shft_ref_231 { id_1771 };
                        Vec<1, Pointer> id_1773 {  drec_snd_229  };
                        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1774;
                        {
                          Vec<1, Pointer> p_ref_232 { id_1773 };
                          bool while_flag_1775 { true };
                          do {
                            uint8_t id_1776 { 0 };
                            Pointer id_1777 { p_ref_232[id_1776] };
                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1778 { id_1777.readU8() };
                            bool let_res_1779;
                            {
                              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_233 { id_1778 };
                              bool letpair_res_1780;
                              {
                                auto leb128_fst_234 { std::get<0>(leb128_233) };
                                auto leb128_snd_235 { std::get<1>(leb128_233) };
                                uint8_t id_1781 { 0 };
                                Void id_1782 { ((void)(p_ref_232[id_1781] = leb128_snd_235), ::dessser::Void()) };
                                (void)id_1782;
                                uint8_t id_1783 { 0 };
                                uint8_t id_1784 { 127 };
                                uint8_t id_1785 { uint8_t(leb128_fst_234 & id_1784) };
                                uint32_t id_1786 { uint32_t(id_1785) };
                                uint8_t id_1787 { 0 };
                                uint8_t id_1788 { shft_ref_231[id_1787] };
                                uint32_t id_1789 { uint32_t(id_1786 << id_1788) };
                                uint8_t id_1790 { 0 };
                                uint32_t id_1791 { leb_ref_230[id_1790] };
                                uint32_t id_1792 { uint32_t(id_1789 | id_1791) };
                                Void id_1793 { ((void)(leb_ref_230[id_1783] = id_1792), ::dessser::Void()) };
                                (void)id_1793;
                                uint8_t id_1794 { 0 };
                                uint8_t id_1795 { 0 };
                                uint8_t id_1796 { shft_ref_231[id_1795] };
                                uint8_t id_1797 { 7 };
                                uint8_t id_1798 { uint8_t(id_1796 + id_1797) };
                                Void id_1799 { ((void)(shft_ref_231[id_1794] = id_1798), ::dessser::Void()) };
                                (void)id_1799;
                                uint8_t id_1800 { 128 };
                                bool id_1801 { bool(leb128_fst_234 >= id_1800) };
                                letpair_res_1780 = id_1801;
                              }
                              let_res_1779 = letpair_res_1780;
                            }
                            while_flag_1775 = let_res_1779;
                            if (while_flag_1775) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_1775);
                          (void)::dessser::Void();
                          uint8_t id_1802 { 0 };
                          uint32_t id_1803 { leb_ref_230[id_1802] };
                          uint8_t id_1804 { 0 };
                          Pointer id_1805 { p_ref_232[id_1804] };
                          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1806 { id_1803, id_1805 };
                          let_res_1774 = id_1806;
                        }
                        let_res_1772 = let_res_1774;
                      }
                      let_res_1769 = let_res_1772;
                    }
                    ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c let_res_1807;
                    {
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_239 { let_res_1769 };
                      ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c letpair_res_1808;
                      {
                        auto dlist1_fst_240 { std::get<0>(dlist1_239) };
                        auto dlist1_snd_241 { std::get<1>(dlist1_239) };
                        Lst<dessser::gen::raql_warning::t_ext> endoflist_1809;
                        ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1810 { endoflist_1809, dlist1_snd_241 };
                        Vec<1, ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c> id_1811 {  id_1810  };
                        ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c let_res_1812;
                        {
                          Vec<1, ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c> inits_src_ref_242 { id_1811 };
                          int32_t id_1813 { 0L };
                          Vec<1, int32_t> id_1814 {  id_1813  };
                          {
                            Vec<1, int32_t> repeat_n_243 { id_1814 };
                            bool while_flag_1815 { true };
                            do {
                              int32_t id_1816 { int32_t(dlist1_fst_240) };
                              uint8_t id_1817 { 0 };
                              int32_t id_1818 { repeat_n_243[id_1817] };
                              bool id_1819 { bool(id_1816 > id_1818) };
                              while_flag_1815 = id_1819;
                              if (while_flag_1815) {
                                uint8_t id_1820 { 0 };
                                ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1821 { inits_src_ref_242[id_1820] };
                                {
                                  ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c dlist2_244 { id_1821 };
                                  {
                                    auto dlist2_fst_245 { std::get<0>(dlist2_244) };
                                    auto dlist2_snd_246 { std::get<1>(dlist2_244) };
                                    uint8_t id_1822 { 0 };
                                    auto fun1823 { dessser::gen::raql_warning::of_row_binary };
                                    ::dessser::gen::source_info::tf20c5d088795d1f84266f4ee74fe3594 id_1824 { fun1823(dlist2_snd_246) };
                                    ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c letpair_res_1825;
                                    {
                                      auto dlist3_fst_248 { std::get<0>(id_1824) };
                                      auto dlist3_snd_249 { std::get<1>(id_1824) };
                                      Lst<dessser::gen::raql_warning::t_ext> id_1826 { dlist3_fst_248, dlist2_fst_245 };
                                      ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1827 { id_1826, dlist3_snd_249 };
                                      letpair_res_1825 = id_1827;
                                    }
                                    Void id_1828 { ((void)(inits_src_ref_242[id_1822] = letpair_res_1825), ::dessser::Void()) };
                                    (void)id_1828;
                                  }
                                  (void)::dessser::Void();
                                }
                                (void)::dessser::Void();
                                uint8_t id_1829 { 0 };
                                uint8_t id_1830 { 0 };
                                int32_t id_1831 { repeat_n_243[id_1830] };
                                int32_t id_1832 { 1L };
                                int32_t id_1833 { int32_t(id_1831 + id_1832) };
                                Void id_1834 { ((void)(repeat_n_243[id_1829] = id_1833), ::dessser::Void()) };
                                (void)id_1834;
                                (void)id_1834;
                              }
                            } while (while_flag_1815);
                            (void)::dessser::Void();
                          }
                          (void)::dessser::Void();
                          uint8_t id_1835 { 0 };
                          ::dessser::gen::source_info::tb1f955478ba8f504d91dbdb67381088c id_1836 { inits_src_ref_242[id_1835] };
                          let_res_1812 = id_1836;
                        }
                        letpair_res_1808 = let_res_1812;
                      }
                      let_res_1807 = letpair_res_1808;
                    }
                    ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1837;
                    {
                      auto dlist4_fst_251 { std::get<0>(let_res_1807) };
                      auto dlist4_snd_252 { std::get<1>(let_res_1807) };
                      std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_1838 { std::make_shared<::dessser::gen::source_info::compiled_program>(drec_fst_173, drec_fst_176, drec_fst_202, drec_fst_228, dlist4_fst_251) };
                      ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 id_1839 { id_1838, dlist4_snd_252 };
                      letpair_res_1837 = id_1839;
                    }
                    letpair_res_1766 = letpair_res_1837;
                  }
                  let_res_1765 = letpair_res_1766;
                }
                letpair_res_1693 = let_res_1765;
              }
              let_res_1692 = letpair_res_1693;
            }
            letpair_res_1619 = let_res_1692;
          }
          let_res_1618 = letpair_res_1619;
        }
        letpair_res_1615 = let_res_1618;
      }
      let_res_1614 = letpair_res_1615;
    }
    return let_res_1614;
  }
   };
  return fun1541;
}
std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> compiled_program_of_row_binary(compiled_program_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_268"
        (let "dstring1_262"
          (let "leb_ref_256" (make-vec (u32 0))
            (let "shft_ref_257" (make-vec (u8 0))
              (let "p_ref_258" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_259" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_258")))
                      (let-pair "leb128_fst_260" "leb128_snd_261" (identifier "leb128_259")
                        (seq (set-vec (u8 0) (identifier "p_ref_258") (identifier "leb128_snd_261"))
                          (set-vec (u8 0) (identifier "leb_ref_256")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_260") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_257"))) (unsafe-nth (u8 0) (identifier "leb_ref_256"))))
                          (set-vec (u8 0) (identifier "shft_ref_257") (add (unsafe-nth (u8 0) (identifier "shft_ref_257")) (u8 7))) 
                          (ge (identifier "leb128_fst_260") (u8 128))))) 
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_256"))) (unsafe-nth (u8 0) (identifier "p_ref_258")))))))
          (let-pair "dstring1_fst_263" "dstring1_snd_264" (identifier "dstring1_262")
            (let-pair "dstring2_fst_266" "dstring2_snd_267" (read-bytes (identifier "dstring1_snd_264") (identifier "dstring1_fst_263"))
              (make-tup (string-of-bytes (identifier "dstring2_fst_266")) (identifier "dstring2_snd_267")))))
        (let-pair "drec_fst_269" "drec_snd_270" (identifier "drec_268")
          (let "drec_306"
            (let-pair "dlist4_fst_304" "dlist4_snd_305"
              (let "dlist1_280"
                (let "leb_ref_271" (make-vec (u32 0))
                  (let "shft_ref_272" (make-vec (u8 0))
                    (let "p_ref_273" (make-vec (identifier "drec_snd_270"))
                      (seq
                        (while
                          (let "leb128_274" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_273")))
                            (let-pair "leb128_fst_275" "leb128_snd_276" 
                              (identifier "leb128_274")
                              (seq (set-vec (u8 0) (identifier "p_ref_273") (identifier "leb128_snd_276"))
                                (set-vec (u8 0) (identifier "leb_ref_271")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_275") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_272"))) (unsafe-nth (u8 0) (identifier "leb_ref_271"))))
                                (set-vec (u8 0) (identifier "shft_ref_272") (add (unsafe-nth (u8 0) (identifier "shft_ref_272")) (u8 7))) 
                                (ge (identifier "leb128_fst_275") (u8 128))))) 
                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_271")) (unsafe-nth (u8 0) (identifier "p_ref_273")))))))
                (let-pair "dlist1_fst_281" "dlist1_snd_282" (identifier "dlist1_280")
                  (let "inits_src_ref_283" (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_282")))
                    (seq
                      (let "repeat_n_284" (make-vec (i32 0))
                        (while (gt (to-i32 (identifier "dlist1_fst_281")) (unsafe-nth (u8 0) (identifier "repeat_n_284")))
                          (seq
                            (let "dlist2_285" (unsafe-nth (u8 0) (identifier "inits_src_ref_283"))
                              (let-pair "dlist2_fst_286" "dlist2_snd_287" 
                                (identifier "dlist2_285")
                                (set-vec (u8 0) (identifier "inits_src_ref_283")
                                  (let "dstring1_294"
                                    (let "leb_ref_288" (make-vec (u32 0))
                                      (let "shft_ref_289" (make-vec (u8 0))
                                        (let "p_ref_290" (make-vec (identifier "dlist2_snd_287"))
                                          (seq
                                            (while
                                              (let "leb128_291" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_290")))
                                                (let-pair "leb128_fst_292" "leb128_snd_293" 
                                                  (identifier "leb128_291")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_290") (identifier "leb128_snd_293"))
                                                    (set-vec (u8 0) (identifier "leb_ref_288")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_292") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_289"))) (unsafe-nth (u8 0) (identifier "leb_ref_288"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_289") (add (unsafe-nth (u8 0) (identifier "shft_ref_289")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_292") (u8 128))))) 
                                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_288"))) (unsafe-nth (u8 0) (identifier "p_ref_290")))))))
                                    (let-pair "dstring1_fst_295" "dstring1_snd_296" 
                                      (identifier "dstring1_294")
                                      (let-pair "dstring2_fst_298" "dstring2_snd_299" 
                                        (read-bytes (identifier "dstring1_snd_296") (identifier "dstring1_fst_295"))
                                        (make-tup (cons (string-of-bytes (identifier "dstring2_fst_298")) (identifier "dlist2_fst_286")) (identifier "dstring2_snd_299"))))))))
                            (set-vec (u8 0) (identifier "repeat_n_284") (add (unsafe-nth (u8 0) (identifier "repeat_n_284")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "inits_src_ref_283")))))) 
              (make-tup (identity (identifier "dlist4_fst_304")) (identifier "dlist4_snd_305")))
            (let-pair "drec_fst_307" "drec_snd_308" (identifier "drec_306")
              (let-pair "drec_fst_357" "drec_snd_358"
                (let "dsum1_315" (let-pair "du16_fst_310" "du16_snd_311" (read-u16 little-endian (identifier "drec_snd_308")) (make-tup (identifier "du16_fst_310") (identifier "du16_snd_311")))
                  (let-pair "dsum1_fst_316" "dsum1_snd_317" (identifier "dsum1_315")
                    (if (eq (u16 0) (identifier "dsum1_fst_316"))
                      (let-pair "dsum2_fst_354" "dsum2_snd_355" (apply (identifier "compiled_program-of-row-binary") (identifier "dsum1_snd_317"))
                        (make-tup
                          (construct "[Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]" 0
                            (identifier "dsum2_fst_354")) (identifier "dsum2_snd_355")))
                      (seq (assert (eq (identifier "dsum1_fst_316") (u16 1)))
                        (let "drec_341"
                          (let-pair "dlist4_fst_339" "dlist4_snd_340"
                            (let "dlist1_327"
                              (let "leb_ref_318" (make-vec (u32 0))
                                (let "shft_ref_319" (make-vec (u8 0))
                                  (let "p_ref_320" (make-vec (identifier "dsum1_snd_317"))
                                    (seq
                                      (while
                                        (let "leb128_321" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_320")))
                                          (let-pair "leb128_fst_322" "leb128_snd_323" 
                                            (identifier "leb128_321")
                                            (seq (set-vec (u8 0) (identifier "p_ref_320") (identifier "leb128_snd_323"))
                                              (set-vec (u8 0) (identifier "leb_ref_318")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_322") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_319"))) (unsafe-nth (u8 0) (identifier "leb_ref_318"))))
                                              (set-vec (u8 0) (identifier "shft_ref_319") (add (unsafe-nth (u8 0) (identifier "shft_ref_319")) (u8 7))) 
                                              (ge (identifier "leb128_fst_322") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_318")) (unsafe-nth (u8 0) (identifier "p_ref_320")))))))
                              (let-pair "dlist1_fst_328" "dlist1_snd_329" 
                                (identifier "dlist1_327")
                                (let "inits_src_ref_330" (make-vec (make-tup (end-of-list "$raql_error") (identifier "dlist1_snd_329")))
                                  (seq
                                    (let "repeat_n_331" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_328")) (unsafe-nth (u8 0) (identifier "repeat_n_331")))
                                        (seq
                                          (let "dlist2_332" (unsafe-nth (u8 0) (identifier "inits_src_ref_330"))
                                            (let-pair "dlist2_fst_333" "dlist2_snd_334" 
                                              (identifier "dlist2_332")
                                              (set-vec (u8 0) (identifier "inits_src_ref_330")
                                                (let-pair "dlist3_fst_336" "dlist3_snd_337" 
                                                  (apply (ext-identifier raql_error of-row-binary) (identifier "dlist2_snd_334"))
                                                  (make-tup (cons (identifier "dlist3_fst_336") (identifier "dlist2_fst_333")) (identifier "dlist3_snd_337"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_331") (add (unsafe-nth (u8 0) (identifier "repeat_n_331")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_330")))))) 
                            (make-tup (identity (identifier "dlist4_fst_339")) (identifier "dlist4_snd_340")))
                          (let-pair "drec_fst_342" "drec_snd_343" (identifier "drec_341")
                            (let-pair "drec_fst_348" "drec_snd_349"
                              (if (eq (peek-u8 (identifier "drec_snd_343") (size 0)) (u8 1)) 
                                (make-tup (null "$src_path") (ptr-add (identifier "drec_snd_343") (size 1)))
                                (let-pair "make1_1_fst_345" "make1_1_snd_346" 
                                  (apply (ext-identifier src_path of-row-binary) (ptr-add (identifier "drec_snd_343") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_345")) (identifier "make1_1_snd_346"))))
                              (make-tup
                                (construct "[Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]" 1
                                  (make-rec (string "depends_on") (identifier "drec_fst_348") (string "errors") (identifier "drec_fst_342"))) 
                                (identifier "drec_snd_349")))))))))
                (make-tup (make-rec (string "detail") (identifier "drec_fst_357") (string "md5s") (identifier "drec_fst_307") (string "src_ext") (identifier "drec_fst_269")) (identifier "drec_snd_358"))))))))
 */
static std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> fun1840 { [&](Pointer p_0) {
    uint32_t id_1841 { 0U };
    Vec<1, uint32_t> id_1842 {  id_1841  };
    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1843;
    {
      Vec<1, uint32_t> leb_ref_256 { id_1842 };
      uint8_t id_1844 { 0 };
      Vec<1, uint8_t> id_1845 {  id_1844  };
      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1846;
      {
        Vec<1, uint8_t> shft_ref_257 { id_1845 };
        Vec<1, Pointer> id_1847 {  p_0  };
        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1848;
        {
          Vec<1, Pointer> p_ref_258 { id_1847 };
          bool while_flag_1849 { true };
          do {
            uint8_t id_1850 { 0 };
            Pointer id_1851 { p_ref_258[id_1850] };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1852 { id_1851.readU8() };
            bool let_res_1853;
            {
              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_259 { id_1852 };
              bool letpair_res_1854;
              {
                auto leb128_fst_260 { std::get<0>(leb128_259) };
                auto leb128_snd_261 { std::get<1>(leb128_259) };
                uint8_t id_1855 { 0 };
                Void id_1856 { ((void)(p_ref_258[id_1855] = leb128_snd_261), ::dessser::Void()) };
                (void)id_1856;
                uint8_t id_1857 { 0 };
                uint8_t id_1858 { 127 };
                uint8_t id_1859 { uint8_t(leb128_fst_260 & id_1858) };
                uint32_t id_1860 { uint32_t(id_1859) };
                uint8_t id_1861 { 0 };
                uint8_t id_1862 { shft_ref_257[id_1861] };
                uint32_t id_1863 { uint32_t(id_1860 << id_1862) };
                uint8_t id_1864 { 0 };
                uint32_t id_1865 { leb_ref_256[id_1864] };
                uint32_t id_1866 { uint32_t(id_1863 | id_1865) };
                Void id_1867 { ((void)(leb_ref_256[id_1857] = id_1866), ::dessser::Void()) };
                (void)id_1867;
                uint8_t id_1868 { 0 };
                uint8_t id_1869 { 0 };
                uint8_t id_1870 { shft_ref_257[id_1869] };
                uint8_t id_1871 { 7 };
                uint8_t id_1872 { uint8_t(id_1870 + id_1871) };
                Void id_1873 { ((void)(shft_ref_257[id_1868] = id_1872), ::dessser::Void()) };
                (void)id_1873;
                uint8_t id_1874 { 128 };
                bool id_1875 { bool(leb128_fst_260 >= id_1874) };
                letpair_res_1854 = id_1875;
              }
              let_res_1853 = letpair_res_1854;
            }
            while_flag_1849 = let_res_1853;
            if (while_flag_1849) {
              (void)::dessser::Void();
            }
          } while (while_flag_1849);
          (void)::dessser::Void();
          uint8_t id_1876 { 0 };
          uint32_t id_1877 { leb_ref_256[id_1876] };
          Size id_1878 { Size(id_1877) };
          uint8_t id_1879 { 0 };
          Pointer id_1880 { p_ref_258[id_1879] };
          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1881 { id_1878, id_1880 };
          let_res_1848 = id_1881;
        }
        let_res_1846 = let_res_1848;
      }
      let_res_1843 = let_res_1846;
    }
    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1882;
    {
      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_262 { let_res_1843 };
      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1883;
      {
        auto dstring1_fst_263 { std::get<0>(dstring1_262) };
        auto dstring1_snd_264 { std::get<1>(dstring1_262) };
        ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1884 { dstring1_snd_264.readBytes(dstring1_fst_263) };
        ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1885;
        {
          auto dstring2_fst_266 { std::get<0>(id_1884) };
          auto dstring2_snd_267 { std::get<1>(id_1884) };
          std::string id_1886 { dstring2_fst_266.toString() };
          ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1887 { id_1886, dstring2_snd_267 };
          letpair_res_1885 = id_1887;
        }
        letpair_res_1883 = letpair_res_1885;
      }
      let_res_1882 = letpair_res_1883;
    }
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 let_res_1888;
    {
      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_268 { let_res_1882 };
      ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_1889;
      {
        auto drec_fst_269 { std::get<0>(drec_268) };
        auto drec_snd_270 { std::get<1>(drec_268) };
        uint32_t id_1890 { 0U };
        Vec<1, uint32_t> id_1891 {  id_1890  };
        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1892;
        {
          Vec<1, uint32_t> leb_ref_271 { id_1891 };
          uint8_t id_1893 { 0 };
          Vec<1, uint8_t> id_1894 {  id_1893  };
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1895;
          {
            Vec<1, uint8_t> shft_ref_272 { id_1894 };
            Vec<1, Pointer> id_1896 {  drec_snd_270  };
            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1897;
            {
              Vec<1, Pointer> p_ref_273 { id_1896 };
              bool while_flag_1898 { true };
              do {
                uint8_t id_1899 { 0 };
                Pointer id_1900 { p_ref_273[id_1899] };
                ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1901 { id_1900.readU8() };
                bool let_res_1902;
                {
                  ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_274 { id_1901 };
                  bool letpair_res_1903;
                  {
                    auto leb128_fst_275 { std::get<0>(leb128_274) };
                    auto leb128_snd_276 { std::get<1>(leb128_274) };
                    uint8_t id_1904 { 0 };
                    Void id_1905 { ((void)(p_ref_273[id_1904] = leb128_snd_276), ::dessser::Void()) };
                    (void)id_1905;
                    uint8_t id_1906 { 0 };
                    uint8_t id_1907 { 127 };
                    uint8_t id_1908 { uint8_t(leb128_fst_275 & id_1907) };
                    uint32_t id_1909 { uint32_t(id_1908) };
                    uint8_t id_1910 { 0 };
                    uint8_t id_1911 { shft_ref_272[id_1910] };
                    uint32_t id_1912 { uint32_t(id_1909 << id_1911) };
                    uint8_t id_1913 { 0 };
                    uint32_t id_1914 { leb_ref_271[id_1913] };
                    uint32_t id_1915 { uint32_t(id_1912 | id_1914) };
                    Void id_1916 { ((void)(leb_ref_271[id_1906] = id_1915), ::dessser::Void()) };
                    (void)id_1916;
                    uint8_t id_1917 { 0 };
                    uint8_t id_1918 { 0 };
                    uint8_t id_1919 { shft_ref_272[id_1918] };
                    uint8_t id_1920 { 7 };
                    uint8_t id_1921 { uint8_t(id_1919 + id_1920) };
                    Void id_1922 { ((void)(shft_ref_272[id_1917] = id_1921), ::dessser::Void()) };
                    (void)id_1922;
                    uint8_t id_1923 { 128 };
                    bool id_1924 { bool(leb128_fst_275 >= id_1923) };
                    letpair_res_1903 = id_1924;
                  }
                  let_res_1902 = letpair_res_1903;
                }
                while_flag_1898 = let_res_1902;
                if (while_flag_1898) {
                  (void)::dessser::Void();
                }
              } while (while_flag_1898);
              (void)::dessser::Void();
              uint8_t id_1925 { 0 };
              uint32_t id_1926 { leb_ref_271[id_1925] };
              uint8_t id_1927 { 0 };
              Pointer id_1928 { p_ref_273[id_1927] };
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1929 { id_1926, id_1928 };
              let_res_1897 = id_1929;
            }
            let_res_1895 = let_res_1897;
          }
          let_res_1892 = let_res_1895;
        }
        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1930;
        {
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_280 { let_res_1892 };
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1931;
          {
            auto dlist1_fst_281 { std::get<0>(dlist1_280) };
            auto dlist1_snd_282 { std::get<1>(dlist1_280) };
            Lst<std::string> endoflist_1932;
            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1933 { endoflist_1932, dlist1_snd_282 };
            Vec<1, ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc> id_1934 {  id_1933  };
            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1935;
            {
              Vec<1, ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc> inits_src_ref_283 { id_1934 };
              int32_t id_1936 { 0L };
              Vec<1, int32_t> id_1937 {  id_1936  };
              {
                Vec<1, int32_t> repeat_n_284 { id_1937 };
                bool while_flag_1938 { true };
                do {
                  int32_t id_1939 { int32_t(dlist1_fst_281) };
                  uint8_t id_1940 { 0 };
                  int32_t id_1941 { repeat_n_284[id_1940] };
                  bool id_1942 { bool(id_1939 > id_1941) };
                  while_flag_1938 = id_1942;
                  if (while_flag_1938) {
                    uint8_t id_1943 { 0 };
                    ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1944 { inits_src_ref_283[id_1943] };
                    {
                      ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc dlist2_285 { id_1944 };
                      {
                        auto dlist2_fst_286 { std::get<0>(dlist2_285) };
                        auto dlist2_snd_287 { std::get<1>(dlist2_285) };
                        uint8_t id_1945 { 0 };
                        uint32_t id_1946 { 0U };
                        Vec<1, uint32_t> id_1947 {  id_1946  };
                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1948;
                        {
                          Vec<1, uint32_t> leb_ref_288 { id_1947 };
                          uint8_t id_1949 { 0 };
                          Vec<1, uint8_t> id_1950 {  id_1949  };
                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1951;
                          {
                            Vec<1, uint8_t> shft_ref_289 { id_1950 };
                            Vec<1, Pointer> id_1952 {  dlist2_snd_287  };
                            ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1953;
                            {
                              Vec<1, Pointer> p_ref_290 { id_1952 };
                              bool while_flag_1954 { true };
                              do {
                                uint8_t id_1955 { 0 };
                                Pointer id_1956 { p_ref_290[id_1955] };
                                ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1957 { id_1956.readU8() };
                                bool let_res_1958;
                                {
                                  ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_291 { id_1957 };
                                  bool letpair_res_1959;
                                  {
                                    auto leb128_fst_292 { std::get<0>(leb128_291) };
                                    auto leb128_snd_293 { std::get<1>(leb128_291) };
                                    uint8_t id_1960 { 0 };
                                    Void id_1961 { ((void)(p_ref_290[id_1960] = leb128_snd_293), ::dessser::Void()) };
                                    (void)id_1961;
                                    uint8_t id_1962 { 0 };
                                    uint8_t id_1963 { 127 };
                                    uint8_t id_1964 { uint8_t(leb128_fst_292 & id_1963) };
                                    uint32_t id_1965 { uint32_t(id_1964) };
                                    uint8_t id_1966 { 0 };
                                    uint8_t id_1967 { shft_ref_289[id_1966] };
                                    uint32_t id_1968 { uint32_t(id_1965 << id_1967) };
                                    uint8_t id_1969 { 0 };
                                    uint32_t id_1970 { leb_ref_288[id_1969] };
                                    uint32_t id_1971 { uint32_t(id_1968 | id_1970) };
                                    Void id_1972 { ((void)(leb_ref_288[id_1962] = id_1971), ::dessser::Void()) };
                                    (void)id_1972;
                                    uint8_t id_1973 { 0 };
                                    uint8_t id_1974 { 0 };
                                    uint8_t id_1975 { shft_ref_289[id_1974] };
                                    uint8_t id_1976 { 7 };
                                    uint8_t id_1977 { uint8_t(id_1975 + id_1976) };
                                    Void id_1978 { ((void)(shft_ref_289[id_1973] = id_1977), ::dessser::Void()) };
                                    (void)id_1978;
                                    uint8_t id_1979 { 128 };
                                    bool id_1980 { bool(leb128_fst_292 >= id_1979) };
                                    letpair_res_1959 = id_1980;
                                  }
                                  let_res_1958 = letpair_res_1959;
                                }
                                while_flag_1954 = let_res_1958;
                                if (while_flag_1954) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_1954);
                              (void)::dessser::Void();
                              uint8_t id_1981 { 0 };
                              uint32_t id_1982 { leb_ref_288[id_1981] };
                              Size id_1983 { Size(id_1982) };
                              uint8_t id_1984 { 0 };
                              Pointer id_1985 { p_ref_290[id_1984] };
                              ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1986 { id_1983, id_1985 };
                              let_res_1953 = id_1986;
                            }
                            let_res_1951 = let_res_1953;
                          }
                          let_res_1948 = let_res_1951;
                        }
                        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1987;
                        {
                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_294 { let_res_1948 };
                          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1988;
                          {
                            auto dstring1_fst_295 { std::get<0>(dstring1_294) };
                            auto dstring1_snd_296 { std::get<1>(dstring1_294) };
                            ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1989 { dstring1_snd_296.readBytes(dstring1_fst_295) };
                            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1990;
                            {
                              auto dstring2_fst_298 { std::get<0>(id_1989) };
                              auto dstring2_snd_299 { std::get<1>(id_1989) };
                              std::string id_1991 { dstring2_fst_298.toString() };
                              Lst<std::string> id_1992 { id_1991, dlist2_fst_286 };
                              ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1993 { id_1992, dstring2_snd_299 };
                              letpair_res_1990 = id_1993;
                            }
                            letpair_res_1988 = letpair_res_1990;
                          }
                          let_res_1987 = letpair_res_1988;
                        }
                        Void id_1994 { ((void)(inits_src_ref_283[id_1945] = let_res_1987), ::dessser::Void()) };
                        (void)id_1994;
                      }
                      (void)::dessser::Void();
                    }
                    (void)::dessser::Void();
                    uint8_t id_1995 { 0 };
                    uint8_t id_1996 { 0 };
                    int32_t id_1997 { repeat_n_284[id_1996] };
                    int32_t id_1998 { 1L };
                    int32_t id_1999 { int32_t(id_1997 + id_1998) };
                    Void id_2000 { ((void)(repeat_n_284[id_1995] = id_1999), ::dessser::Void()) };
                    (void)id_2000;
                    (void)id_2000;
                  }
                } while (while_flag_1938);
                (void)::dessser::Void();
              }
              (void)::dessser::Void();
              uint8_t id_2001 { 0 };
              ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_2002 { inits_src_ref_283[id_2001] };
              let_res_1935 = id_2002;
            }
            letpair_res_1931 = let_res_1935;
          }
          let_res_1930 = letpair_res_1931;
        }
        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_2003;
        {
          auto dlist4_fst_304 { std::get<0>(let_res_1930) };
          auto dlist4_snd_305 { std::get<1>(let_res_1930) };
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_2004 { dlist4_fst_304, dlist4_snd_305 };
          letpair_res_2003 = id_2004;
        }
        ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 let_res_2005;
        {
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc drec_306 { letpair_res_2003 };
          ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_2006;
          {
            auto drec_fst_307 { std::get<0>(drec_306) };
            auto drec_snd_308 { std::get<1>(drec_306) };
            ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 id_2007 { drec_snd_308.readU16Le() };
            ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2008;
            {
              auto du16_fst_310 { std::get<0>(id_2007) };
              auto du16_snd_311 { std::get<1>(id_2007) };
              ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 id_2009 { du16_fst_310, du16_snd_311 };
              letpair_res_2008 = id_2009;
            }
            ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 let_res_2010;
            {
              ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 dsum1_315 { letpair_res_2008 };
              ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2011;
              {
                auto dsum1_fst_316 { std::get<0>(dsum1_315) };
                auto dsum1_snd_317 { std::get<1>(dsum1_315) };
                uint16_t id_2012 { 0 };
                bool id_2013 { bool(id_2012 == dsum1_fst_316) };
                ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 choose_res_2014;
                if (id_2013) {
                  ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 id_2015 { compiled_program_of_row_binary(dsum1_snd_317) };
                  ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2016;
                  {
                    auto dsum2_fst_354 { std::get<0>(id_2015) };
                    auto dsum2_snd_355 { std::get<1>(id_2015) };
                    ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_2017 { std::in_place_index<0>, dsum2_fst_354 };
                    ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 id_2018 { id_2017, dsum2_snd_355 };
                    letpair_res_2016 = id_2018;
                  }
                  choose_res_2014 = letpair_res_2016;
                } else {
                  uint16_t id_2019 { 1 };
                  bool id_2020 { bool(dsum1_fst_316 == id_2019) };
                  Void id_2021 { ((void)(assert(id_2020)), ::dessser::Void()) };
                  (void)id_2021;
                  uint32_t id_2022 { 0U };
                  Vec<1, uint32_t> id_2023 {  id_2022  };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_2024;
                  {
                    Vec<1, uint32_t> leb_ref_318 { id_2023 };
                    uint8_t id_2025 { 0 };
                    Vec<1, uint8_t> id_2026 {  id_2025  };
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_2027;
                    {
                      Vec<1, uint8_t> shft_ref_319 { id_2026 };
                      Vec<1, Pointer> id_2028 {  dsum1_snd_317  };
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_2029;
                      {
                        Vec<1, Pointer> p_ref_320 { id_2028 };
                        bool while_flag_2030 { true };
                        do {
                          uint8_t id_2031 { 0 };
                          Pointer id_2032 { p_ref_320[id_2031] };
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_2033 { id_2032.readU8() };
                          bool let_res_2034;
                          {
                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_321 { id_2033 };
                            bool letpair_res_2035;
                            {
                              auto leb128_fst_322 { std::get<0>(leb128_321) };
                              auto leb128_snd_323 { std::get<1>(leb128_321) };
                              uint8_t id_2036 { 0 };
                              Void id_2037 { ((void)(p_ref_320[id_2036] = leb128_snd_323), ::dessser::Void()) };
                              (void)id_2037;
                              uint8_t id_2038 { 0 };
                              uint8_t id_2039 { 127 };
                              uint8_t id_2040 { uint8_t(leb128_fst_322 & id_2039) };
                              uint32_t id_2041 { uint32_t(id_2040) };
                              uint8_t id_2042 { 0 };
                              uint8_t id_2043 { shft_ref_319[id_2042] };
                              uint32_t id_2044 { uint32_t(id_2041 << id_2043) };
                              uint8_t id_2045 { 0 };
                              uint32_t id_2046 { leb_ref_318[id_2045] };
                              uint32_t id_2047 { uint32_t(id_2044 | id_2046) };
                              Void id_2048 { ((void)(leb_ref_318[id_2038] = id_2047), ::dessser::Void()) };
                              (void)id_2048;
                              uint8_t id_2049 { 0 };
                              uint8_t id_2050 { 0 };
                              uint8_t id_2051 { shft_ref_319[id_2050] };
                              uint8_t id_2052 { 7 };
                              uint8_t id_2053 { uint8_t(id_2051 + id_2052) };
                              Void id_2054 { ((void)(shft_ref_319[id_2049] = id_2053), ::dessser::Void()) };
                              (void)id_2054;
                              uint8_t id_2055 { 128 };
                              bool id_2056 { bool(leb128_fst_322 >= id_2055) };
                              letpair_res_2035 = id_2056;
                            }
                            let_res_2034 = letpair_res_2035;
                          }
                          while_flag_2030 = let_res_2034;
                          if (while_flag_2030) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_2030);
                        (void)::dessser::Void();
                        uint8_t id_2057 { 0 };
                        uint32_t id_2058 { leb_ref_318[id_2057] };
                        uint8_t id_2059 { 0 };
                        Pointer id_2060 { p_ref_320[id_2059] };
                        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_2061 { id_2058, id_2060 };
                        let_res_2029 = id_2061;
                      }
                      let_res_2027 = let_res_2029;
                    }
                    let_res_2024 = let_res_2027;
                  }
                  ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 let_res_2062;
                  {
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_327 { let_res_2024 };
                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 letpair_res_2063;
                    {
                      auto dlist1_fst_328 { std::get<0>(dlist1_327) };
                      auto dlist1_snd_329 { std::get<1>(dlist1_327) };
                      Lst<dessser::gen::raql_error::t_ext> endoflist_2064;
                      ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2065 { endoflist_2064, dlist1_snd_329 };
                      Vec<1, ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8> id_2066 {  id_2065  };
                      ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 let_res_2067;
                      {
                        Vec<1, ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8> inits_src_ref_330 { id_2066 };
                        int32_t id_2068 { 0L };
                        Vec<1, int32_t> id_2069 {  id_2068  };
                        {
                          Vec<1, int32_t> repeat_n_331 { id_2069 };
                          bool while_flag_2070 { true };
                          do {
                            int32_t id_2071 { int32_t(dlist1_fst_328) };
                            uint8_t id_2072 { 0 };
                            int32_t id_2073 { repeat_n_331[id_2072] };
                            bool id_2074 { bool(id_2071 > id_2073) };
                            while_flag_2070 = id_2074;
                            if (while_flag_2070) {
                              uint8_t id_2075 { 0 };
                              ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2076 { inits_src_ref_330[id_2075] };
                              {
                                ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 dlist2_332 { id_2076 };
                                {
                                  auto dlist2_fst_333 { std::get<0>(dlist2_332) };
                                  auto dlist2_snd_334 { std::get<1>(dlist2_332) };
                                  uint8_t id_2077 { 0 };
                                  auto fun2078 { dessser::gen::raql_error::of_row_binary };
                                  ::dessser::gen::source_info::teea7fc62226f20557c62e7bf6ca50e88 id_2079 { fun2078(dlist2_snd_334) };
                                  ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 letpair_res_2080;
                                  {
                                    auto dlist3_fst_336 { std::get<0>(id_2079) };
                                    auto dlist3_snd_337 { std::get<1>(id_2079) };
                                    Lst<dessser::gen::raql_error::t_ext> id_2081 { dlist3_fst_336, dlist2_fst_333 };
                                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2082 { id_2081, dlist3_snd_337 };
                                    letpair_res_2080 = id_2082;
                                  }
                                  Void id_2083 { ((void)(inits_src_ref_330[id_2077] = letpair_res_2080), ::dessser::Void()) };
                                  (void)id_2083;
                                }
                                (void)::dessser::Void();
                              }
                              (void)::dessser::Void();
                              uint8_t id_2084 { 0 };
                              uint8_t id_2085 { 0 };
                              int32_t id_2086 { repeat_n_331[id_2085] };
                              int32_t id_2087 { 1L };
                              int32_t id_2088 { int32_t(id_2086 + id_2087) };
                              Void id_2089 { ((void)(repeat_n_331[id_2084] = id_2088), ::dessser::Void()) };
                              (void)id_2089;
                              (void)id_2089;
                            }
                          } while (while_flag_2070);
                          (void)::dessser::Void();
                        }
                        (void)::dessser::Void();
                        uint8_t id_2090 { 0 };
                        ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2091 { inits_src_ref_330[id_2090] };
                        let_res_2067 = id_2091;
                      }
                      letpair_res_2063 = let_res_2067;
                    }
                    let_res_2062 = letpair_res_2063;
                  }
                  ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 letpair_res_2092;
                  {
                    auto dlist4_fst_339 { std::get<0>(let_res_2062) };
                    auto dlist4_snd_340 { std::get<1>(let_res_2062) };
                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 id_2093 { dlist4_fst_339, dlist4_snd_340 };
                    letpair_res_2092 = id_2093;
                  }
                  ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 let_res_2094;
                  {
                    ::dessser::gen::source_info::t50e7b7e05d9b475b8059a2fda20d15e8 drec_341 { letpair_res_2092 };
                    ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2095;
                    {
                      auto drec_fst_342 { std::get<0>(drec_341) };
                      auto drec_snd_343 { std::get<1>(drec_341) };
                      Size id_2096 { 0UL };
                      uint8_t id_2097 { drec_snd_343.peekU8(id_2096) };
                      uint8_t id_2098 { 1 };
                      bool id_2099 { bool(id_2097 == id_2098) };
                      ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 choose_res_2100;
                      if (id_2099) {
                        std::optional<dessser::gen::src_path::t_ext> id_2101 { std::nullopt };
                        Size id_2102 { 1UL };
                        Pointer id_2103 { drec_snd_343.skip(id_2102) };
                        ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 id_2104 { id_2101, id_2103 };
                        choose_res_2100 = id_2104;
                      } else {
                        auto fun2105 { dessser::gen::src_path::of_row_binary };
                        Size id_2106 { 1UL };
                        Pointer id_2107 { drec_snd_343.skip(id_2106) };
                        ::dessser::gen::source_info::t6915129216bc7fcac0c82f38ea6cfec8 id_2108 { fun2105(id_2107) };
                        ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 letpair_res_2109;
                        {
                          auto make1_1_fst_345 { std::get<0>(id_2108) };
                          auto make1_1_snd_346 { std::get<1>(id_2108) };
                          std::optional<dessser::gen::src_path::t_ext> id_2110 { make1_1_fst_345 };
                          ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 id_2111 { id_2110, make1_1_snd_346 };
                          letpair_res_2109 = id_2111;
                        }
                        choose_res_2100 = letpair_res_2109;
                      }
                      ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 letpair_res_2112;
                      {
                        auto drec_fst_348 { std::get<0>(choose_res_2100) };
                        auto drec_snd_349 { std::get<1>(choose_res_2100) };
                        ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b id_2113 { drec_fst_342, drec_fst_348 };
                        ::dessser::gen::source_info::t39aa42e5bfed35fd9fe6b7649dfa4b04 id_2114 { std::in_place_index<1>, id_2113 };
                        ::dessser::gen::source_info::ta6d5b2ed2831b82e0aa9d2a37c294bd6 id_2115 { id_2114, drec_snd_349 };
                        letpair_res_2112 = id_2115;
                      }
                      letpair_res_2095 = letpair_res_2112;
                    }
                    let_res_2094 = letpair_res_2095;
                  }
                  choose_res_2014 = let_res_2094;
                }
                letpair_res_2011 = choose_res_2014;
              }
              let_res_2010 = letpair_res_2011;
            }
            ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_2116;
            {
              auto drec_fst_357 { std::get<0>(let_res_2010) };
              auto drec_snd_358 { std::get<1>(let_res_2010) };
              std::shared_ptr<::dessser::gen::source_info::t>  id_2117 { std::make_shared<::dessser::gen::source_info::t>(drec_fst_269, drec_fst_307, drec_fst_357) };
              ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_2118 { id_2117, drec_snd_358 };
              letpair_res_2116 = id_2118;
            }
            letpair_res_2006 = letpair_res_2116;
          }
          let_res_2005 = letpair_res_2006;
        }
        letpair_res_1889 = let_res_2005;
      }
      let_res_1888 = letpair_res_1889;
    }
    return let_res_1888;
  }
   };
  return fun1840;
}
std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_360" "make_snd_361" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_360") (identifier "make_snd_361"))))
 */
static std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> fun2119 { [&](Pointer p_0) {
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_2120 { of_row_binary(p_0) };
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_2121;
    {
      auto make_fst_360 { std::get<0>(id_2120) };
      auto make_snd_361 { std::get<1>(id_2120) };
      ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_2122 { make_fst_360, make_snd_361 };
      letpair_res_2121 = id_2122;
    }
    return letpair_res_2121;
  }
   };
  return fun2119;
}
std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]; warnings: $raql_warning[[]]}) | Failed {errors: $raql_error[[]]; depends_on: $src_path?}]}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> fun2123 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0, Pointer p_1) {
    Pointer id_2124 { to_row_binary(p_0, p_1) };
    return id_2124;
  }
   };
  return fun2123;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
