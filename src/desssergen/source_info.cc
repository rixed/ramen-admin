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
#include "desssergen/src_path.h"
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
  compiled_program(Lst<dessser::gen::program_parameter::t_ext> default_params_, dessser::gen::raql_expr::t_ext condition_, Lst<dessser::gen::global_variable::t_ext> globals_, Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > funcs_) : default_params(default_params_), condition(condition_), globals(globals_), funcs(funcs_) {}
  compiled_program() = default;
};
inline bool operator==(compiled_program const &a, compiled_program const &b) {
  return a.default_params == b.default_params && ::dessser::gen::raql_expr::Deref(a.condition) == ::dessser::gen::raql_expr::Deref(b.condition) && a.globals == b.globals && a.funcs == b.funcs;
}

inline bool operator!=(compiled_program const &a, compiled_program const &b) {
  return !operator==(a, b);
}
struct t7904aca1b7c7094ac41533a38083131a {
  std::string err_msg;
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  t7904aca1b7c7094ac41533a38083131a(std::string err_msg_, std::optional<dessser::gen::src_path::t_ext> depends_on_) : err_msg(err_msg_), depends_on(depends_on_) {}
  t7904aca1b7c7094ac41533a38083131a() = default;
};
inline bool operator==(t7904aca1b7c7094ac41533a38083131a const &a, t7904aca1b7c7094ac41533a38083131a const &b) {
  return a.err_msg == b.err_msg && ((a.depends_on && b.depends_on && ::dessser::gen::src_path::Deref(a.depends_on.value()) == ::dessser::gen::src_path::Deref(b.depends_on.value())) || (!a.depends_on && !b.depends_on));
}

inline bool operator!=(t7904aca1b7c7094ac41533a38083131a const &a, t7904aca1b7c7094ac41533a38083131a const &b) {
  return !operator==(a, b);
}
struct t01907297530734eeb2fea6f30cc7354a : public std::variant<
  std::shared_ptr<::dessser::gen::source_info::compiled_program> , // Compiled
  ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a // Failed
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t01907297530734eeb2fea6f30cc7354a const &a, t01907297530734eeb2fea6f30cc7354a const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return (*std::get<0>(a)) == (*std::get<0>(b)); // Compiled
    case 1: return std::get<1>(a) == std::get<1>(b); // Failed
  };
  return false;
}
inline bool operator!=(t01907297530734eeb2fea6f30cc7354a const &a, t01907297530734eeb2fea6f30cc7354a const &b) {
  return !operator==(a, b);
}
struct t {
  std::string src_ext;
  Lst<std::string> md5s;
  ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a detail;
  t(std::string src_ext_, Lst<std::string> md5s_, ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a detail_) : src_ext(src_ext_), md5s(md5s_), detail(detail_) {}
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
struct t1dbe46d793a5e2554e3a17c25d03e7d4 : public std::tuple<
  ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a,
  Pointer
> {
  using tuple::tuple;
  t1dbe46d793a5e2554e3a17c25d03e7d4(std::tuple<::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a, Pointer> p)
    : std::tuple<::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1dbe46d793a5e2554e3a17c25d03e7d4 const &a, t1dbe46d793a5e2554e3a17c25d03e7d4 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1dbe46d793a5e2554e3a17c25d03e7d4 const &a, t1dbe46d793a5e2554e3a17c25d03e7d4 const &b) {
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
      (let "srec_dst_397"
        (let "srec_dst_394"
          (let "srec_dst_388"
            (let "srec_dst_387"
              (let "srec_dst_386"
                (let "srec_dst_383"
                  (let "srec_dst_382"
                    (let "srec_dst_381" (apply (ext-identifier function_name to-row-binary) (get-field "name" (param 0)) (param 1))
                      (if (is-null (get-field "retention" (param 0))) 
                        (write-u8 (identifier "srec_dst_381") (u8 1)) 
                        (apply (ext-identifier retention to-row-binary) (force (get-field "retention" (param 0))) (write-u8 (identifier "srec_dst_381") (u8 0)))))
                    (write-u8 (identifier "srec_dst_382") (u8-of-bool (get-field "is_lazy" (param 0)))))
                  (write-bytes
                    (let "leb128_sz_384" (make-vec (string-length (get-field "doc" (param 0))))
                      (let "leb128_ptr_385" (make-vec (identifier "srec_dst_383"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_385")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_385"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_384") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_384")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_384")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_385"))))) 
                    (bytes-of-string (get-field "doc" (param 0))))) (apply (ext-identifier raql_operation to-row-binary) (get-field "operation" (param 0)) (identifier "srec_dst_386")))
              (apply (ext-identifier raql_type to-row-binary) (get-field "out_record" (param 0)) (identifier "srec_dst_387")))
            (let "dst_ref_391"
              (make-vec
                (let "leb128_sz_389" (make-vec (cardinality (get-field "factors" (param 0))))
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
                  (for-each "x_393" (get-field "factors" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_391") (apply (ext-identifier field_name to-row-binary) (identifier "x_393") (unsafe-nth (u8 0) (identifier "dst_ref_391"))))
                      (set-vec (u8 0) (identifier "n_ref_392") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_392")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_391"))))))
          (write-bytes
            (let "leb128_sz_395" (make-vec (string-length (get-field "signature" (param 0))))
              (let "leb128_ptr_396" (make-vec (identifier "srec_dst_394"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_396")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_396"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_395") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_395")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_395")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_396"))))) 
            (bytes-of-string (get-field "signature" (param 0)))))
        (write-bytes
          (let "leb128_sz_398" (make-vec (string-length (get-field "in_signature" (param 0))))
            (let "leb128_ptr_399" (make-vec (identifier "srec_dst_397"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_399")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_399"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_398"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_398"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_398"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_398") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_398")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_398")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_399"))))) 
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
      Pointer srec_dst_381 { id_3 };
      std::optional<dessser::gen::retention::t_ext> id_5 { (*p_0).retention };
      bool id_6 { !(id_5.has_value ()) };
      Pointer choose_res_7;
      if (id_6) {
        uint8_t id_8 { 1 };
        Pointer id_9 { srec_dst_381.writeU8(id_8) };
        choose_res_7 = id_9;
      } else {
        auto fun10 { dessser::gen::retention::to_row_binary };
        std::optional<dessser::gen::retention::t_ext> id_11 { (*p_0).retention };
        dessser::gen::retention::t_ext id_12 { id_11.value() };
        uint8_t id_13 { 0 };
        Pointer id_14 { srec_dst_381.writeU8(id_13) };
        Pointer id_15 { fun10(id_12, id_14) };
        choose_res_7 = id_15;
      }
      let_res_4 = choose_res_7;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_382 { let_res_4 };
      bool id_17 { (*p_0).is_lazy };
      uint8_t id_18 { uint8_t(id_17) };
      Pointer id_19 { srec_dst_382.writeU8(id_18) };
      let_res_16 = id_19;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_383 { let_res_16 };
      std::string id_21 { (*p_0).doc };
      uint32_t id_22 { (uint32_t)id_21.size() };
      Vec<1, uint32_t> id_23 {  id_22  };
      Pointer let_res_24;
      {
        Vec<1, uint32_t> leb128_sz_384 { id_23 };
        Vec<1, Pointer> id_25 {  srec_dst_383  };
        Pointer let_res_26;
        {
          Vec<1, Pointer> leb128_ptr_385 { id_25 };
          bool while_flag_27 { true };
          do {
            uint8_t id_28 { 0 };
            uint8_t id_29 { 0 };
            Pointer id_30 { leb128_ptr_385[id_29] };
            uint32_t id_31 { 128U };
            uint8_t id_32 { 0 };
            uint32_t id_33 { leb128_sz_384[id_32] };
            bool id_34 { bool(id_31 > id_33) };
            uint8_t choose_res_35;
            if (id_34) {
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_384[id_36] };
              uint8_t id_38 { uint8_t(id_37) };
              choose_res_35 = id_38;
            } else {
              uint8_t id_39 { 0 };
              uint32_t id_40 { leb128_sz_384[id_39] };
              uint8_t id_41 { uint8_t(id_40) };
              uint8_t id_42 { 128 };
              uint8_t id_43 { uint8_t(id_41 | id_42) };
              choose_res_35 = id_43;
            }
            Pointer id_44 { id_30.writeU8(choose_res_35) };
            Void id_45 { ((void)(leb128_ptr_385[id_28] = id_44), ::dessser::VOID) };
            (void)id_45;
            uint8_t id_46 { 0 };
            uint8_t id_47 { 0 };
            uint32_t id_48 { leb128_sz_384[id_47] };
            uint8_t id_49 { 7 };
            uint32_t id_50 { uint32_t(id_48 >> id_49) };
            Void id_51 { ((void)(leb128_sz_384[id_46] = id_50), ::dessser::VOID) };
            (void)id_51;
            uint8_t id_52 { 0 };
            uint32_t id_53 { leb128_sz_384[id_52] };
            uint32_t id_54 { 0U };
            bool id_55 { bool(id_53 > id_54) };
            while_flag_27 = id_55;
            if (while_flag_27) {
              (void)::dessser::VOID;
            }
          } while (while_flag_27);
          (void)::dessser::VOID;
          uint8_t id_56 { 0 };
          Pointer id_57 { leb128_ptr_385[id_56] };
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
      Pointer srec_dst_386 { let_res_20 };
      auto fun62 { dessser::gen::raql_operation::to_row_binary };
      dessser::gen::raql_operation::t_ext id_63 { (*p_0).operation };
      Pointer id_64 { fun62(id_63, srec_dst_386) };
      let_res_61 = id_64;
    }
    Pointer let_res_65;
    {
      Pointer srec_dst_387 { let_res_61 };
      auto fun66 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t_ext id_67 { (*p_0).out_record };
      Pointer id_68 { fun66(id_67, srec_dst_387) };
      let_res_65 = id_68;
    }
    Pointer let_res_69;
    {
      Pointer srec_dst_388 { let_res_65 };
      Lst<dessser::gen::field_name::t_ext> id_70 { (*p_0).factors };
      uint32_t id_71 { id_70.size() };
      Vec<1, uint32_t> id_72 {  id_71  };
      Pointer let_res_73;
      {
        Vec<1, uint32_t> leb128_sz_389 { id_72 };
        Vec<1, Pointer> id_74 {  srec_dst_388  };
        Pointer let_res_75;
        {
          Vec<1, Pointer> leb128_ptr_390 { id_74 };
          bool while_flag_76 { true };
          do {
            uint8_t id_77 { 0 };
            uint8_t id_78 { 0 };
            Pointer id_79 { leb128_ptr_390[id_78] };
            uint32_t id_80 { 128U };
            uint8_t id_81 { 0 };
            uint32_t id_82 { leb128_sz_389[id_81] };
            bool id_83 { bool(id_80 > id_82) };
            uint8_t choose_res_84;
            if (id_83) {
              uint8_t id_85 { 0 };
              uint32_t id_86 { leb128_sz_389[id_85] };
              uint8_t id_87 { uint8_t(id_86) };
              choose_res_84 = id_87;
            } else {
              uint8_t id_88 { 0 };
              uint32_t id_89 { leb128_sz_389[id_88] };
              uint8_t id_90 { uint8_t(id_89) };
              uint8_t id_91 { 128 };
              uint8_t id_92 { uint8_t(id_90 | id_91) };
              choose_res_84 = id_92;
            }
            Pointer id_93 { id_79.writeU8(choose_res_84) };
            Void id_94 { ((void)(leb128_ptr_390[id_77] = id_93), ::dessser::VOID) };
            (void)id_94;
            uint8_t id_95 { 0 };
            uint8_t id_96 { 0 };
            uint32_t id_97 { leb128_sz_389[id_96] };
            uint8_t id_98 { 7 };
            uint32_t id_99 { uint32_t(id_97 >> id_98) };
            Void id_100 { ((void)(leb128_sz_389[id_95] = id_99), ::dessser::VOID) };
            (void)id_100;
            uint8_t id_101 { 0 };
            uint32_t id_102 { leb128_sz_389[id_101] };
            uint32_t id_103 { 0U };
            bool id_104 { bool(id_102 > id_103) };
            while_flag_76 = id_104;
            if (while_flag_76) {
              (void)::dessser::VOID;
            }
          } while (while_flag_76);
          (void)::dessser::VOID;
          uint8_t id_105 { 0 };
          Pointer id_106 { leb128_ptr_390[id_105] };
          let_res_75 = id_106;
        }
        let_res_73 = let_res_75;
      }
      Vec<1, Pointer> id_107 {  let_res_73  };
      Pointer let_res_108;
      {
        Vec<1, Pointer> dst_ref_391 { id_107 };
        int32_t id_109 { 0L };
        Vec<1, int32_t> id_110 {  id_109  };
        Pointer let_res_111;
        {
          Vec<1, int32_t> n_ref_392 { id_110 };
          Lst<dessser::gen::field_name::t_ext> id_112 { (*p_0).factors };
          for (dessser::gen::field_name::t_ext &x_393 : id_112) {
            uint8_t id_113 { 0 };
            auto fun114 { dessser::gen::field_name::to_row_binary };
            uint8_t id_115 { 0 };
            Pointer id_116 { dst_ref_391[id_115] };
            Pointer id_117 { fun114(x_393, id_116) };
            Void id_118 { ((void)(dst_ref_391[id_113] = id_117), ::dessser::VOID) };
            (void)id_118;
            uint8_t id_119 { 0 };
            int32_t id_120 { 1L };
            uint8_t id_121 { 0 };
            int32_t id_122 { n_ref_392[id_121] };
            int32_t id_123 { int32_t(id_120 + id_122) };
            Void id_124 { ((void)(n_ref_392[id_119] = id_123), ::dessser::VOID) };
            (void)id_124;
            (void)id_124;
          }
          (void)::dessser::VOID;
          uint8_t id_125 { 0 };
          Pointer id_126 { dst_ref_391[id_125] };
          let_res_111 = id_126;
        }
        let_res_108 = let_res_111;
      }
      let_res_69 = let_res_108;
    }
    Pointer let_res_127;
    {
      Pointer srec_dst_394 { let_res_69 };
      std::string id_128 { (*p_0).signature };
      uint32_t id_129 { (uint32_t)id_128.size() };
      Vec<1, uint32_t> id_130 {  id_129  };
      Pointer let_res_131;
      {
        Vec<1, uint32_t> leb128_sz_395 { id_130 };
        Vec<1, Pointer> id_132 {  srec_dst_394  };
        Pointer let_res_133;
        {
          Vec<1, Pointer> leb128_ptr_396 { id_132 };
          bool while_flag_134 { true };
          do {
            uint8_t id_135 { 0 };
            uint8_t id_136 { 0 };
            Pointer id_137 { leb128_ptr_396[id_136] };
            uint32_t id_138 { 128U };
            uint8_t id_139 { 0 };
            uint32_t id_140 { leb128_sz_395[id_139] };
            bool id_141 { bool(id_138 > id_140) };
            uint8_t choose_res_142;
            if (id_141) {
              uint8_t id_143 { 0 };
              uint32_t id_144 { leb128_sz_395[id_143] };
              uint8_t id_145 { uint8_t(id_144) };
              choose_res_142 = id_145;
            } else {
              uint8_t id_146 { 0 };
              uint32_t id_147 { leb128_sz_395[id_146] };
              uint8_t id_148 { uint8_t(id_147) };
              uint8_t id_149 { 128 };
              uint8_t id_150 { uint8_t(id_148 | id_149) };
              choose_res_142 = id_150;
            }
            Pointer id_151 { id_137.writeU8(choose_res_142) };
            Void id_152 { ((void)(leb128_ptr_396[id_135] = id_151), ::dessser::VOID) };
            (void)id_152;
            uint8_t id_153 { 0 };
            uint8_t id_154 { 0 };
            uint32_t id_155 { leb128_sz_395[id_154] };
            uint8_t id_156 { 7 };
            uint32_t id_157 { uint32_t(id_155 >> id_156) };
            Void id_158 { ((void)(leb128_sz_395[id_153] = id_157), ::dessser::VOID) };
            (void)id_158;
            uint8_t id_159 { 0 };
            uint32_t id_160 { leb128_sz_395[id_159] };
            uint32_t id_161 { 0U };
            bool id_162 { bool(id_160 > id_161) };
            while_flag_134 = id_162;
            if (while_flag_134) {
              (void)::dessser::VOID;
            }
          } while (while_flag_134);
          (void)::dessser::VOID;
          uint8_t id_163 { 0 };
          Pointer id_164 { leb128_ptr_396[id_163] };
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
      Pointer srec_dst_397 { let_res_127 };
      std::string id_169 { (*p_0).in_signature };
      uint32_t id_170 { (uint32_t)id_169.size() };
      Vec<1, uint32_t> id_171 {  id_170  };
      Pointer let_res_172;
      {
        Vec<1, uint32_t> leb128_sz_398 { id_171 };
        Vec<1, Pointer> id_173 {  srec_dst_397  };
        Pointer let_res_174;
        {
          Vec<1, Pointer> leb128_ptr_399 { id_173 };
          bool while_flag_175 { true };
          do {
            uint8_t id_176 { 0 };
            uint8_t id_177 { 0 };
            Pointer id_178 { leb128_ptr_399[id_177] };
            uint32_t id_179 { 128U };
            uint8_t id_180 { 0 };
            uint32_t id_181 { leb128_sz_398[id_180] };
            bool id_182 { bool(id_179 > id_181) };
            uint8_t choose_res_183;
            if (id_182) {
              uint8_t id_184 { 0 };
              uint32_t id_185 { leb128_sz_398[id_184] };
              uint8_t id_186 { uint8_t(id_185) };
              choose_res_183 = id_186;
            } else {
              uint8_t id_187 { 0 };
              uint32_t id_188 { leb128_sz_398[id_187] };
              uint8_t id_189 { uint8_t(id_188) };
              uint8_t id_190 { 128 };
              uint8_t id_191 { uint8_t(id_189 | id_190) };
              choose_res_183 = id_191;
            }
            Pointer id_192 { id_178.writeU8(choose_res_183) };
            Void id_193 { ((void)(leb128_ptr_399[id_176] = id_192), ::dessser::VOID) };
            (void)id_193;
            uint8_t id_194 { 0 };
            uint8_t id_195 { 0 };
            uint32_t id_196 { leb128_sz_398[id_195] };
            uint8_t id_197 { 7 };
            uint32_t id_198 { uint32_t(id_196 >> id_197) };
            Void id_199 { ((void)(leb128_sz_398[id_194] = id_198), ::dessser::VOID) };
            (void)id_199;
            uint8_t id_200 { 0 };
            uint32_t id_201 { leb128_sz_398[id_200] };
            uint32_t id_202 { 0U };
            bool id_203 { bool(id_201 > id_202) };
            while_flag_175 = id_203;
            if (while_flag_175) {
              (void)::dessser::VOID;
            }
          } while (while_flag_175);
          (void)::dessser::VOID;
          uint8_t id_204 { 0 };
          Pointer id_205 { leb128_ptr_399[id_204] };
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
    (fun ("{default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]}" "Ptr")
      (let "srec_dst_412"
        (let "srec_dst_406"
          (let "srec_dst_405"
            (let "dst_ref_402"
              (make-vec
                (let "leb128_sz_400" (make-vec (cardinality (get-field "default_params" (param 0))))
                  (let "leb128_ptr_401" (make-vec (param 1))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_401")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_401"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_400"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_400"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_400"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_400") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_400")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_400")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_401"))))))
              (let "n_ref_403" (make-vec (i32 0))
                (seq
                  (for-each "x_404" (get-field "default_params" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_402") (apply (ext-identifier program_parameter to-row-binary) (identifier "x_404") (unsafe-nth (u8 0) (identifier "dst_ref_402"))))
                      (set-vec (u8 0) (identifier "n_ref_403") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_403")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_402"))))) (apply (ext-identifier raql_expr to-row-binary) (get-field "condition" (param 0)) (identifier "srec_dst_405")))
          (let "dst_ref_409"
            (make-vec
              (let "leb128_sz_407" (make-vec (cardinality (get-field "globals" (param 0))))
                (let "leb128_ptr_408" (make-vec (identifier "srec_dst_406"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_408")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_408"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_407"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_407"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_407"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_407") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_407")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_407")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_408"))))))
            (let "n_ref_410" (make-vec (i32 0))
              (seq
                (for-each "x_411" (get-field "globals" (param 0))
                  (seq (set-vec (u8 0) (identifier "dst_ref_409") (apply (ext-identifier global_variable to-row-binary) (identifier "x_411") (unsafe-nth (u8 0) (identifier "dst_ref_409"))))
                    (set-vec (u8 0) (identifier "n_ref_410") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_410")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_409"))))))
        (let "dst_ref_415"
          (make-vec
            (let "leb128_sz_413" (make-vec (cardinality (get-field "funcs" (param 0))))
              (let "leb128_ptr_414" (make-vec (identifier "srec_dst_412"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_414")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_414"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_413"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_413"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_413"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_413") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_413")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_413")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_414"))))))
          (let "n_ref_416" (make-vec (i32 0))
            (seq
              (for-each "x_417" (get-field "funcs" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_415") (apply (identifier "compiled_func-to-row-binary") (identifier "x_417") (unsafe-nth (u8 0) (identifier "dst_ref_415"))))
                  (set-vec (u8 0) (identifier "n_ref_416") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_416")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_415")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> fun209 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_program>  p_0, Pointer p_1) {
    Lst<dessser::gen::program_parameter::t_ext> id_210 { (*p_0).default_params };
    uint32_t id_211 { id_210.size() };
    Vec<1, uint32_t> id_212 {  id_211  };
    Pointer let_res_213;
    {
      Vec<1, uint32_t> leb128_sz_400 { id_212 };
      Vec<1, Pointer> id_214 {  p_1  };
      Pointer let_res_215;
      {
        Vec<1, Pointer> leb128_ptr_401 { id_214 };
        bool while_flag_216 { true };
        do {
          uint8_t id_217 { 0 };
          uint8_t id_218 { 0 };
          Pointer id_219 { leb128_ptr_401[id_218] };
          uint32_t id_220 { 128U };
          uint8_t id_221 { 0 };
          uint32_t id_222 { leb128_sz_400[id_221] };
          bool id_223 { bool(id_220 > id_222) };
          uint8_t choose_res_224;
          if (id_223) {
            uint8_t id_225 { 0 };
            uint32_t id_226 { leb128_sz_400[id_225] };
            uint8_t id_227 { uint8_t(id_226) };
            choose_res_224 = id_227;
          } else {
            uint8_t id_228 { 0 };
            uint32_t id_229 { leb128_sz_400[id_228] };
            uint8_t id_230 { uint8_t(id_229) };
            uint8_t id_231 { 128 };
            uint8_t id_232 { uint8_t(id_230 | id_231) };
            choose_res_224 = id_232;
          }
          Pointer id_233 { id_219.writeU8(choose_res_224) };
          Void id_234 { ((void)(leb128_ptr_401[id_217] = id_233), ::dessser::VOID) };
          (void)id_234;
          uint8_t id_235 { 0 };
          uint8_t id_236 { 0 };
          uint32_t id_237 { leb128_sz_400[id_236] };
          uint8_t id_238 { 7 };
          uint32_t id_239 { uint32_t(id_237 >> id_238) };
          Void id_240 { ((void)(leb128_sz_400[id_235] = id_239), ::dessser::VOID) };
          (void)id_240;
          uint8_t id_241 { 0 };
          uint32_t id_242 { leb128_sz_400[id_241] };
          uint32_t id_243 { 0U };
          bool id_244 { bool(id_242 > id_243) };
          while_flag_216 = id_244;
          if (while_flag_216) {
            (void)::dessser::VOID;
          }
        } while (while_flag_216);
        (void)::dessser::VOID;
        uint8_t id_245 { 0 };
        Pointer id_246 { leb128_ptr_401[id_245] };
        let_res_215 = id_246;
      }
      let_res_213 = let_res_215;
    }
    Vec<1, Pointer> id_247 {  let_res_213  };
    Pointer let_res_248;
    {
      Vec<1, Pointer> dst_ref_402 { id_247 };
      int32_t id_249 { 0L };
      Vec<1, int32_t> id_250 {  id_249  };
      Pointer let_res_251;
      {
        Vec<1, int32_t> n_ref_403 { id_250 };
        Lst<dessser::gen::program_parameter::t_ext> id_252 { (*p_0).default_params };
        for (dessser::gen::program_parameter::t_ext &x_404 : id_252) {
          uint8_t id_253 { 0 };
          auto fun254 { dessser::gen::program_parameter::to_row_binary };
          uint8_t id_255 { 0 };
          Pointer id_256 { dst_ref_402[id_255] };
          Pointer id_257 { fun254(x_404, id_256) };
          Void id_258 { ((void)(dst_ref_402[id_253] = id_257), ::dessser::VOID) };
          (void)id_258;
          uint8_t id_259 { 0 };
          int32_t id_260 { 1L };
          uint8_t id_261 { 0 };
          int32_t id_262 { n_ref_403[id_261] };
          int32_t id_263 { int32_t(id_260 + id_262) };
          Void id_264 { ((void)(n_ref_403[id_259] = id_263), ::dessser::VOID) };
          (void)id_264;
          (void)id_264;
        }
        (void)::dessser::VOID;
        uint8_t id_265 { 0 };
        Pointer id_266 { dst_ref_402[id_265] };
        let_res_251 = id_266;
      }
      let_res_248 = let_res_251;
    }
    Pointer let_res_267;
    {
      Pointer srec_dst_405 { let_res_248 };
      auto fun268 { dessser::gen::raql_expr::to_row_binary };
      dessser::gen::raql_expr::t_ext id_269 { (*p_0).condition };
      Pointer id_270 { fun268(id_269, srec_dst_405) };
      let_res_267 = id_270;
    }
    Pointer let_res_271;
    {
      Pointer srec_dst_406 { let_res_267 };
      Lst<dessser::gen::global_variable::t_ext> id_272 { (*p_0).globals };
      uint32_t id_273 { id_272.size() };
      Vec<1, uint32_t> id_274 {  id_273  };
      Pointer let_res_275;
      {
        Vec<1, uint32_t> leb128_sz_407 { id_274 };
        Vec<1, Pointer> id_276 {  srec_dst_406  };
        Pointer let_res_277;
        {
          Vec<1, Pointer> leb128_ptr_408 { id_276 };
          bool while_flag_278 { true };
          do {
            uint8_t id_279 { 0 };
            uint8_t id_280 { 0 };
            Pointer id_281 { leb128_ptr_408[id_280] };
            uint32_t id_282 { 128U };
            uint8_t id_283 { 0 };
            uint32_t id_284 { leb128_sz_407[id_283] };
            bool id_285 { bool(id_282 > id_284) };
            uint8_t choose_res_286;
            if (id_285) {
              uint8_t id_287 { 0 };
              uint32_t id_288 { leb128_sz_407[id_287] };
              uint8_t id_289 { uint8_t(id_288) };
              choose_res_286 = id_289;
            } else {
              uint8_t id_290 { 0 };
              uint32_t id_291 { leb128_sz_407[id_290] };
              uint8_t id_292 { uint8_t(id_291) };
              uint8_t id_293 { 128 };
              uint8_t id_294 { uint8_t(id_292 | id_293) };
              choose_res_286 = id_294;
            }
            Pointer id_295 { id_281.writeU8(choose_res_286) };
            Void id_296 { ((void)(leb128_ptr_408[id_279] = id_295), ::dessser::VOID) };
            (void)id_296;
            uint8_t id_297 { 0 };
            uint8_t id_298 { 0 };
            uint32_t id_299 { leb128_sz_407[id_298] };
            uint8_t id_300 { 7 };
            uint32_t id_301 { uint32_t(id_299 >> id_300) };
            Void id_302 { ((void)(leb128_sz_407[id_297] = id_301), ::dessser::VOID) };
            (void)id_302;
            uint8_t id_303 { 0 };
            uint32_t id_304 { leb128_sz_407[id_303] };
            uint32_t id_305 { 0U };
            bool id_306 { bool(id_304 > id_305) };
            while_flag_278 = id_306;
            if (while_flag_278) {
              (void)::dessser::VOID;
            }
          } while (while_flag_278);
          (void)::dessser::VOID;
          uint8_t id_307 { 0 };
          Pointer id_308 { leb128_ptr_408[id_307] };
          let_res_277 = id_308;
        }
        let_res_275 = let_res_277;
      }
      Vec<1, Pointer> id_309 {  let_res_275  };
      Pointer let_res_310;
      {
        Vec<1, Pointer> dst_ref_409 { id_309 };
        int32_t id_311 { 0L };
        Vec<1, int32_t> id_312 {  id_311  };
        Pointer let_res_313;
        {
          Vec<1, int32_t> n_ref_410 { id_312 };
          Lst<dessser::gen::global_variable::t_ext> id_314 { (*p_0).globals };
          for (dessser::gen::global_variable::t_ext &x_411 : id_314) {
            uint8_t id_315 { 0 };
            auto fun316 { dessser::gen::global_variable::to_row_binary };
            uint8_t id_317 { 0 };
            Pointer id_318 { dst_ref_409[id_317] };
            Pointer id_319 { fun316(x_411, id_318) };
            Void id_320 { ((void)(dst_ref_409[id_315] = id_319), ::dessser::VOID) };
            (void)id_320;
            uint8_t id_321 { 0 };
            int32_t id_322 { 1L };
            uint8_t id_323 { 0 };
            int32_t id_324 { n_ref_410[id_323] };
            int32_t id_325 { int32_t(id_322 + id_324) };
            Void id_326 { ((void)(n_ref_410[id_321] = id_325), ::dessser::VOID) };
            (void)id_326;
            (void)id_326;
          }
          (void)::dessser::VOID;
          uint8_t id_327 { 0 };
          Pointer id_328 { dst_ref_409[id_327] };
          let_res_313 = id_328;
        }
        let_res_310 = let_res_313;
      }
      let_res_271 = let_res_310;
    }
    Pointer let_res_329;
    {
      Pointer srec_dst_412 { let_res_271 };
      Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_330 { (*p_0).funcs };
      uint32_t id_331 { id_330.size() };
      Vec<1, uint32_t> id_332 {  id_331  };
      Pointer let_res_333;
      {
        Vec<1, uint32_t> leb128_sz_413 { id_332 };
        Vec<1, Pointer> id_334 {  srec_dst_412  };
        Pointer let_res_335;
        {
          Vec<1, Pointer> leb128_ptr_414 { id_334 };
          bool while_flag_336 { true };
          do {
            uint8_t id_337 { 0 };
            uint8_t id_338 { 0 };
            Pointer id_339 { leb128_ptr_414[id_338] };
            uint32_t id_340 { 128U };
            uint8_t id_341 { 0 };
            uint32_t id_342 { leb128_sz_413[id_341] };
            bool id_343 { bool(id_340 > id_342) };
            uint8_t choose_res_344;
            if (id_343) {
              uint8_t id_345 { 0 };
              uint32_t id_346 { leb128_sz_413[id_345] };
              uint8_t id_347 { uint8_t(id_346) };
              choose_res_344 = id_347;
            } else {
              uint8_t id_348 { 0 };
              uint32_t id_349 { leb128_sz_413[id_348] };
              uint8_t id_350 { uint8_t(id_349) };
              uint8_t id_351 { 128 };
              uint8_t id_352 { uint8_t(id_350 | id_351) };
              choose_res_344 = id_352;
            }
            Pointer id_353 { id_339.writeU8(choose_res_344) };
            Void id_354 { ((void)(leb128_ptr_414[id_337] = id_353), ::dessser::VOID) };
            (void)id_354;
            uint8_t id_355 { 0 };
            uint8_t id_356 { 0 };
            uint32_t id_357 { leb128_sz_413[id_356] };
            uint8_t id_358 { 7 };
            uint32_t id_359 { uint32_t(id_357 >> id_358) };
            Void id_360 { ((void)(leb128_sz_413[id_355] = id_359), ::dessser::VOID) };
            (void)id_360;
            uint8_t id_361 { 0 };
            uint32_t id_362 { leb128_sz_413[id_361] };
            uint32_t id_363 { 0U };
            bool id_364 { bool(id_362 > id_363) };
            while_flag_336 = id_364;
            if (while_flag_336) {
              (void)::dessser::VOID;
            }
          } while (while_flag_336);
          (void)::dessser::VOID;
          uint8_t id_365 { 0 };
          Pointer id_366 { leb128_ptr_414[id_365] };
          let_res_335 = id_366;
        }
        let_res_333 = let_res_335;
      }
      Vec<1, Pointer> id_367 {  let_res_333  };
      Pointer let_res_368;
      {
        Vec<1, Pointer> dst_ref_415 { id_367 };
        int32_t id_369 { 0L };
        Vec<1, int32_t> id_370 {  id_369  };
        Pointer let_res_371;
        {
          Vec<1, int32_t> n_ref_416 { id_370 };
          Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_372 { (*p_0).funcs };
          for (std::shared_ptr<::dessser::gen::source_info::compiled_func>  &x_417 : id_372) {
            uint8_t id_373 { 0 };
            uint8_t id_374 { 0 };
            Pointer id_375 { dst_ref_415[id_374] };
            Pointer id_376 { compiled_func_to_row_binary(x_417, id_375) };
            Void id_377 { ((void)(dst_ref_415[id_373] = id_376), ::dessser::VOID) };
            (void)id_377;
            uint8_t id_378 { 0 };
            int32_t id_379 { 1L };
            uint8_t id_380 { 0 };
            int32_t id_381 { n_ref_416[id_380] };
            int32_t id_382 { int32_t(id_379 + id_381) };
            Void id_383 { ((void)(n_ref_416[id_378] = id_382), ::dessser::VOID) };
            (void)id_383;
            (void)id_383;
          }
          (void)::dessser::VOID;
          uint8_t id_384 { 0 };
          Pointer id_385 { dst_ref_415[id_384] };
          let_res_371 = id_385;
        }
        let_res_368 = let_res_371;
      }
      let_res_329 = let_res_368;
    }
    return let_res_329;
  }
   };
  return fun209;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary(compiled_program_to_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]}) | Failed {err_msg: STRING; depends_on: $src_path?}]}" "Ptr")
      (let "srec_dst_428"
        (let "srec_dst_420"
          (write-bytes
            (let "leb128_sz_418" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "leb128_ptr_419" (make-vec (param 1))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_419")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_419"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_418"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_418"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_418"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_418") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_418")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_418")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_419"))))) 
            (bytes-of-string (get-field "src_ext" (param 0))))
          (let "dst_ref_423"
            (make-vec
              (let "leb128_sz_421" (make-vec (cardinality (get-field "md5s" (param 0))))
                (let "leb128_ptr_422" (make-vec (identifier "srec_dst_420"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_422")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_422"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_421") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_421")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_421")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_422"))))))
            (let "n_ref_424" (make-vec (i32 0))
              (seq
                (for-each "x_425" (get-field "md5s" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_423")
                      (write-bytes
                        (let "leb128_sz_426" (make-vec (string-length (identifier "x_425")))
                          (let "leb128_ptr_427" (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_423")))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_427")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_427"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_426"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_426"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_426"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_426") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_426")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_426")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_427"))))) 
                        (bytes-of-string (identifier "x_425")))) (set-vec (u8 0) (identifier "n_ref_424") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_424")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_423"))))))
        (let "ssum_dst_430" (write-u16 little-endian (identifier "srec_dst_428") (label-of (get-field "detail" (param 0))))
          (if (eq (u16 0) (label-of (get-field "detail" (param 0)))) 
            (apply (identifier "compiled_program-to-row-binary") (get-alt "Compiled" (get-field "detail" (param 0))) (identifier "ssum_dst_430"))
            (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
              (let "srec_dst_433"
                (write-bytes
                  (let "leb128_sz_431" (make-vec (string-length (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))
                    (let "leb128_ptr_432" (make-vec (identifier "ssum_dst_430"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_432")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_432"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_431"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_431"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_431"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_431") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_431")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_431")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_432"))))) 
                  (bytes-of-string (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))
                (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                  (write-u8 (identifier "srec_dst_433") (u8 1))
                  (apply (ext-identifier src_path to-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) (write-u8 (identifier "srec_dst_433") (u8 0))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> fun386 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0, Pointer p_1) {
    std::string id_387 { (*p_0).src_ext };
    uint32_t id_388 { (uint32_t)id_387.size() };
    Vec<1, uint32_t> id_389 {  id_388  };
    Pointer let_res_390;
    {
      Vec<1, uint32_t> leb128_sz_418 { id_389 };
      Vec<1, Pointer> id_391 {  p_1  };
      Pointer let_res_392;
      {
        Vec<1, Pointer> leb128_ptr_419 { id_391 };
        bool while_flag_393 { true };
        do {
          uint8_t id_394 { 0 };
          uint8_t id_395 { 0 };
          Pointer id_396 { leb128_ptr_419[id_395] };
          uint32_t id_397 { 128U };
          uint8_t id_398 { 0 };
          uint32_t id_399 { leb128_sz_418[id_398] };
          bool id_400 { bool(id_397 > id_399) };
          uint8_t choose_res_401;
          if (id_400) {
            uint8_t id_402 { 0 };
            uint32_t id_403 { leb128_sz_418[id_402] };
            uint8_t id_404 { uint8_t(id_403) };
            choose_res_401 = id_404;
          } else {
            uint8_t id_405 { 0 };
            uint32_t id_406 { leb128_sz_418[id_405] };
            uint8_t id_407 { uint8_t(id_406) };
            uint8_t id_408 { 128 };
            uint8_t id_409 { uint8_t(id_407 | id_408) };
            choose_res_401 = id_409;
          }
          Pointer id_410 { id_396.writeU8(choose_res_401) };
          Void id_411 { ((void)(leb128_ptr_419[id_394] = id_410), ::dessser::VOID) };
          (void)id_411;
          uint8_t id_412 { 0 };
          uint8_t id_413 { 0 };
          uint32_t id_414 { leb128_sz_418[id_413] };
          uint8_t id_415 { 7 };
          uint32_t id_416 { uint32_t(id_414 >> id_415) };
          Void id_417 { ((void)(leb128_sz_418[id_412] = id_416), ::dessser::VOID) };
          (void)id_417;
          uint8_t id_418 { 0 };
          uint32_t id_419 { leb128_sz_418[id_418] };
          uint32_t id_420 { 0U };
          bool id_421 { bool(id_419 > id_420) };
          while_flag_393 = id_421;
          if (while_flag_393) {
            (void)::dessser::VOID;
          }
        } while (while_flag_393);
        (void)::dessser::VOID;
        uint8_t id_422 { 0 };
        Pointer id_423 { leb128_ptr_419[id_422] };
        let_res_392 = id_423;
      }
      let_res_390 = let_res_392;
    }
    std::string id_424 { (*p_0).src_ext };
    Bytes id_425 { id_424 };
    Pointer id_426 { let_res_390.writeBytes(id_425) };
    Pointer let_res_427;
    {
      Pointer srec_dst_420 { id_426 };
      Lst<std::string> id_428 { (*p_0).md5s };
      uint32_t id_429 { id_428.size() };
      Vec<1, uint32_t> id_430 {  id_429  };
      Pointer let_res_431;
      {
        Vec<1, uint32_t> leb128_sz_421 { id_430 };
        Vec<1, Pointer> id_432 {  srec_dst_420  };
        Pointer let_res_433;
        {
          Vec<1, Pointer> leb128_ptr_422 { id_432 };
          bool while_flag_434 { true };
          do {
            uint8_t id_435 { 0 };
            uint8_t id_436 { 0 };
            Pointer id_437 { leb128_ptr_422[id_436] };
            uint32_t id_438 { 128U };
            uint8_t id_439 { 0 };
            uint32_t id_440 { leb128_sz_421[id_439] };
            bool id_441 { bool(id_438 > id_440) };
            uint8_t choose_res_442;
            if (id_441) {
              uint8_t id_443 { 0 };
              uint32_t id_444 { leb128_sz_421[id_443] };
              uint8_t id_445 { uint8_t(id_444) };
              choose_res_442 = id_445;
            } else {
              uint8_t id_446 { 0 };
              uint32_t id_447 { leb128_sz_421[id_446] };
              uint8_t id_448 { uint8_t(id_447) };
              uint8_t id_449 { 128 };
              uint8_t id_450 { uint8_t(id_448 | id_449) };
              choose_res_442 = id_450;
            }
            Pointer id_451 { id_437.writeU8(choose_res_442) };
            Void id_452 { ((void)(leb128_ptr_422[id_435] = id_451), ::dessser::VOID) };
            (void)id_452;
            uint8_t id_453 { 0 };
            uint8_t id_454 { 0 };
            uint32_t id_455 { leb128_sz_421[id_454] };
            uint8_t id_456 { 7 };
            uint32_t id_457 { uint32_t(id_455 >> id_456) };
            Void id_458 { ((void)(leb128_sz_421[id_453] = id_457), ::dessser::VOID) };
            (void)id_458;
            uint8_t id_459 { 0 };
            uint32_t id_460 { leb128_sz_421[id_459] };
            uint32_t id_461 { 0U };
            bool id_462 { bool(id_460 > id_461) };
            while_flag_434 = id_462;
            if (while_flag_434) {
              (void)::dessser::VOID;
            }
          } while (while_flag_434);
          (void)::dessser::VOID;
          uint8_t id_463 { 0 };
          Pointer id_464 { leb128_ptr_422[id_463] };
          let_res_433 = id_464;
        }
        let_res_431 = let_res_433;
      }
      Vec<1, Pointer> id_465 {  let_res_431  };
      Pointer let_res_466;
      {
        Vec<1, Pointer> dst_ref_423 { id_465 };
        int32_t id_467 { 0L };
        Vec<1, int32_t> id_468 {  id_467  };
        Pointer let_res_469;
        {
          Vec<1, int32_t> n_ref_424 { id_468 };
          Lst<std::string> id_470 { (*p_0).md5s };
          for (std::string const &x_425 : id_470) {
            uint8_t id_471 { 0 };
            uint32_t id_472 { (uint32_t)x_425.size() };
            Vec<1, uint32_t> id_473 {  id_472  };
            Pointer let_res_474;
            {
              Vec<1, uint32_t> leb128_sz_426 { id_473 };
              uint8_t id_475 { 0 };
              Pointer id_476 { dst_ref_423[id_475] };
              Vec<1, Pointer> id_477 {  id_476  };
              Pointer let_res_478;
              {
                Vec<1, Pointer> leb128_ptr_427 { id_477 };
                bool while_flag_479 { true };
                do {
                  uint8_t id_480 { 0 };
                  uint8_t id_481 { 0 };
                  Pointer id_482 { leb128_ptr_427[id_481] };
                  uint32_t id_483 { 128U };
                  uint8_t id_484 { 0 };
                  uint32_t id_485 { leb128_sz_426[id_484] };
                  bool id_486 { bool(id_483 > id_485) };
                  uint8_t choose_res_487;
                  if (id_486) {
                    uint8_t id_488 { 0 };
                    uint32_t id_489 { leb128_sz_426[id_488] };
                    uint8_t id_490 { uint8_t(id_489) };
                    choose_res_487 = id_490;
                  } else {
                    uint8_t id_491 { 0 };
                    uint32_t id_492 { leb128_sz_426[id_491] };
                    uint8_t id_493 { uint8_t(id_492) };
                    uint8_t id_494 { 128 };
                    uint8_t id_495 { uint8_t(id_493 | id_494) };
                    choose_res_487 = id_495;
                  }
                  Pointer id_496 { id_482.writeU8(choose_res_487) };
                  Void id_497 { ((void)(leb128_ptr_427[id_480] = id_496), ::dessser::VOID) };
                  (void)id_497;
                  uint8_t id_498 { 0 };
                  uint8_t id_499 { 0 };
                  uint32_t id_500 { leb128_sz_426[id_499] };
                  uint8_t id_501 { 7 };
                  uint32_t id_502 { uint32_t(id_500 >> id_501) };
                  Void id_503 { ((void)(leb128_sz_426[id_498] = id_502), ::dessser::VOID) };
                  (void)id_503;
                  uint8_t id_504 { 0 };
                  uint32_t id_505 { leb128_sz_426[id_504] };
                  uint32_t id_506 { 0U };
                  bool id_507 { bool(id_505 > id_506) };
                  while_flag_479 = id_507;
                  if (while_flag_479) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_479);
                (void)::dessser::VOID;
                uint8_t id_508 { 0 };
                Pointer id_509 { leb128_ptr_427[id_508] };
                let_res_478 = id_509;
              }
              let_res_474 = let_res_478;
            }
            Bytes id_510 { x_425 };
            Pointer id_511 { let_res_474.writeBytes(id_510) };
            Void id_512 { ((void)(dst_ref_423[id_471] = id_511), ::dessser::VOID) };
            (void)id_512;
            uint8_t id_513 { 0 };
            int32_t id_514 { 1L };
            uint8_t id_515 { 0 };
            int32_t id_516 { n_ref_424[id_515] };
            int32_t id_517 { int32_t(id_514 + id_516) };
            Void id_518 { ((void)(n_ref_424[id_513] = id_517), ::dessser::VOID) };
            (void)id_518;
            (void)id_518;
          }
          (void)::dessser::VOID;
          uint8_t id_519 { 0 };
          Pointer id_520 { dst_ref_423[id_519] };
          let_res_469 = id_520;
        }
        let_res_466 = let_res_469;
      }
      let_res_427 = let_res_466;
    }
    Pointer let_res_521;
    {
      Pointer srec_dst_428 { let_res_427 };
      ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_522 { (*p_0).detail };
      uint16_t id_523 { uint16_t(id_522.index()) };
      Pointer id_524 { srec_dst_428.writeU16Le(id_523) };
      Pointer let_res_525;
      {
        Pointer ssum_dst_430 { id_524 };
        uint16_t id_526 { 0 };
        ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_527 { (*p_0).detail };
        uint16_t id_528 { uint16_t(id_527.index()) };
        bool id_529 { bool(id_526 == id_528) };
        Pointer choose_res_530;
        if (id_529) {
          ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_531 { (*p_0).detail };
          std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_532 { std::get<0 /* Compiled */>(id_531) };
          Pointer id_533 { compiled_program_to_row_binary(id_532, ssum_dst_430) };
          choose_res_530 = id_533;
        } else {
          ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_534 { (*p_0).detail };
          uint16_t id_535 { uint16_t(id_534.index()) };
          uint16_t id_536 { 1 };
          bool id_537 { bool(id_535 == id_536) };
          Void id_538 { ((void)(assert(id_537)), ::dessser::VOID) };
          (void)id_538;
          ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_539 { (*p_0).detail };
          ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_540 { std::get<1 /* Failed */>(id_539) };
          std::string id_541 { id_540.err_msg };
          uint32_t id_542 { (uint32_t)id_541.size() };
          Vec<1, uint32_t> id_543 {  id_542  };
          Pointer let_res_544;
          {
            Vec<1, uint32_t> leb128_sz_431 { id_543 };
            Vec<1, Pointer> id_545 {  ssum_dst_430  };
            Pointer let_res_546;
            {
              Vec<1, Pointer> leb128_ptr_432 { id_545 };
              bool while_flag_547 { true };
              do {
                uint8_t id_548 { 0 };
                uint8_t id_549 { 0 };
                Pointer id_550 { leb128_ptr_432[id_549] };
                uint32_t id_551 { 128U };
                uint8_t id_552 { 0 };
                uint32_t id_553 { leb128_sz_431[id_552] };
                bool id_554 { bool(id_551 > id_553) };
                uint8_t choose_res_555;
                if (id_554) {
                  uint8_t id_556 { 0 };
                  uint32_t id_557 { leb128_sz_431[id_556] };
                  uint8_t id_558 { uint8_t(id_557) };
                  choose_res_555 = id_558;
                } else {
                  uint8_t id_559 { 0 };
                  uint32_t id_560 { leb128_sz_431[id_559] };
                  uint8_t id_561 { uint8_t(id_560) };
                  uint8_t id_562 { 128 };
                  uint8_t id_563 { uint8_t(id_561 | id_562) };
                  choose_res_555 = id_563;
                }
                Pointer id_564 { id_550.writeU8(choose_res_555) };
                Void id_565 { ((void)(leb128_ptr_432[id_548] = id_564), ::dessser::VOID) };
                (void)id_565;
                uint8_t id_566 { 0 };
                uint8_t id_567 { 0 };
                uint32_t id_568 { leb128_sz_431[id_567] };
                uint8_t id_569 { 7 };
                uint32_t id_570 { uint32_t(id_568 >> id_569) };
                Void id_571 { ((void)(leb128_sz_431[id_566] = id_570), ::dessser::VOID) };
                (void)id_571;
                uint8_t id_572 { 0 };
                uint32_t id_573 { leb128_sz_431[id_572] };
                uint32_t id_574 { 0U };
                bool id_575 { bool(id_573 > id_574) };
                while_flag_547 = id_575;
                if (while_flag_547) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_547);
              (void)::dessser::VOID;
              uint8_t id_576 { 0 };
              Pointer id_577 { leb128_ptr_432[id_576] };
              let_res_546 = id_577;
            }
            let_res_544 = let_res_546;
          }
          ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_578 { (*p_0).detail };
          ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_579 { std::get<1 /* Failed */>(id_578) };
          std::string id_580 { id_579.err_msg };
          Bytes id_581 { id_580 };
          Pointer id_582 { let_res_544.writeBytes(id_581) };
          Pointer let_res_583;
          {
            Pointer srec_dst_433 { id_582 };
            ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_584 { (*p_0).detail };
            ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_585 { std::get<1 /* Failed */>(id_584) };
            std::optional<dessser::gen::src_path::t_ext> id_586 { id_585.depends_on };
            bool id_587 { !(id_586.has_value ()) };
            Pointer choose_res_588;
            if (id_587) {
              uint8_t id_589 { 1 };
              Pointer id_590 { srec_dst_433.writeU8(id_589) };
              choose_res_588 = id_590;
            } else {
              auto fun591 { dessser::gen::src_path::to_row_binary };
              ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_592 { (*p_0).detail };
              ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_593 { std::get<1 /* Failed */>(id_592) };
              std::optional<dessser::gen::src_path::t_ext> id_594 { id_593.depends_on };
              dessser::gen::src_path::t_ext id_595 { id_594.value() };
              uint8_t id_596 { 0 };
              Pointer id_597 { srec_dst_433.writeU8(id_596) };
              Pointer id_598 { fun591(id_595, id_597) };
              choose_res_588 = id_598;
            }
            let_res_583 = choose_res_588;
          }
          choose_res_530 = let_res_583;
        }
        let_res_525 = choose_res_530;
      }
      let_res_521 = let_res_525;
    }
    return let_res_521;
  }
   };
  return fun386;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}")
      (let "sz_342"
        (let "sz_338"
          (let "sz_333"
            (let "sz_332"
              (let "sz_331"
                (let "sz_327"
                  (add
                    (let "sz_325" (apply (ext-identifier function_name sersize-of-row-binary) (get-field "name" (param 0)))
                      (if (is-null (get-field "retention" (param 0))) 
                        (add (identifier "sz_325") (size 1)) (add (add (identifier "sz_325") (apply (ext-identifier retention sersize-of-row-binary) (force (get-field "retention" (param 0))))) (size 1)))) 
                    (size 1))
                  (add (identifier "sz_327")
                    (add
                      (let "n_ref_329" (make-vec (string-length (get-field "doc" (param 0))))
                        (let "lebsz_ref_330" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_329")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_330")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_330") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_330")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_330")))))) 
                      (size-of-u32 (string-length (get-field "doc" (param 0))))))) 
                (add (identifier "sz_331") (apply (ext-identifier raql_operation sersize-of-row-binary) (get-field "operation" (param 0)))))
              (add (identifier "sz_332") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "out_record" (param 0)))))
            (let "sz_ref_336"
              (make-vec
                (add (identifier "sz_333")
                  (let "n_ref_334" (make-vec (cardinality (get-field "factors" (param 0))))
                    (let "lebsz_ref_335" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_334")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_335")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_335") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_335")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_335"))))))))
              (seq
                (let "repeat_n_337" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "factors" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_337")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_336")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_336")) (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_337")) (get-field "factors" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_337") (add (unsafe-nth (u8 0) (identifier "repeat_n_337")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_336")))))
          (add (identifier "sz_338")
            (add
              (let "n_ref_340" (make-vec (string-length (get-field "signature" (param 0))))
                (let "lebsz_ref_341" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_340")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_341") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_341")))))) 
              (size-of-u32 (string-length (get-field "signature" (param 0)))))))
        (add (identifier "sz_342")
          (add
            (let "n_ref_344" (make-vec (string-length (get-field "in_signature" (param 0))))
              (let "lebsz_ref_345" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_344")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_345")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_345") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_345")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_345")))))) 
            (size-of-u32 (string-length (get-field "in_signature" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> fun599 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_func>  p_0) {
    auto fun600 { dessser::gen::function_name::sersize_of_row_binary };
    dessser::gen::function_name::t_ext id_601 { (*p_0).name };
    Size id_602 { fun600(id_601) };
    Size let_res_603;
    {
      Size sz_325 { id_602 };
      std::optional<dessser::gen::retention::t_ext> id_604 { (*p_0).retention };
      bool id_605 { !(id_604.has_value ()) };
      Size choose_res_606;
      if (id_605) {
        Size id_607 { 1UL };
        Size id_608 { Size(sz_325 + id_607) };
        choose_res_606 = id_608;
      } else {
        auto fun609 { dessser::gen::retention::sersize_of_row_binary };
        std::optional<dessser::gen::retention::t_ext> id_610 { (*p_0).retention };
        dessser::gen::retention::t_ext id_611 { id_610.value() };
        Size id_612 { fun609(id_611) };
        Size id_613 { Size(sz_325 + id_612) };
        Size id_614 { 1UL };
        Size id_615 { Size(id_613 + id_614) };
        choose_res_606 = id_615;
      }
      let_res_603 = choose_res_606;
    }
    Size id_616 { 1UL };
    Size id_617 { Size(let_res_603 + id_616) };
    Size let_res_618;
    {
      Size sz_327 { id_617 };
      std::string id_619 { (*p_0).doc };
      uint32_t id_620 { (uint32_t)id_619.size() };
      Vec<1, uint32_t> id_621 {  id_620  };
      Size let_res_622;
      {
        Vec<1, uint32_t> n_ref_329 { id_621 };
        uint32_t id_623 { 1U };
        Vec<1, uint32_t> id_624 {  id_623  };
        Size let_res_625;
        {
          Vec<1, uint32_t> lebsz_ref_330 { id_624 };
          bool while_flag_626 { true };
          do {
            uint8_t id_627 { 0 };
            uint32_t id_628 { n_ref_329[id_627] };
            uint8_t id_629 { 0 };
            uint32_t id_630 { lebsz_ref_330[id_629] };
            uint8_t id_631 { 7 };
            uint32_t id_632 { uint32_t(id_630 << id_631) };
            bool id_633 { bool(id_628 >= id_632) };
            while_flag_626 = id_633;
            if (while_flag_626) {
              uint8_t id_634 { 0 };
              uint8_t id_635 { 0 };
              uint32_t id_636 { lebsz_ref_330[id_635] };
              uint32_t id_637 { 1U };
              uint32_t id_638 { uint32_t(id_636 + id_637) };
              Void id_639 { ((void)(lebsz_ref_330[id_634] = id_638), ::dessser::VOID) };
              (void)id_639;
            }
          } while (while_flag_626);
          (void)::dessser::VOID;
          uint8_t id_640 { 0 };
          uint32_t id_641 { lebsz_ref_330[id_640] };
          Size id_642 { Size(id_641) };
          let_res_625 = id_642;
        }
        let_res_622 = let_res_625;
      }
      std::string id_643 { (*p_0).doc };
      uint32_t id_644 { (uint32_t)id_643.size() };
      Size id_645 { Size(id_644) };
      Size id_646 { Size(let_res_622 + id_645) };
      Size id_647 { Size(sz_327 + id_646) };
      let_res_618 = id_647;
    }
    Size let_res_648;
    {
      Size sz_331 { let_res_618 };
      auto fun649 { dessser::gen::raql_operation::sersize_of_row_binary };
      dessser::gen::raql_operation::t_ext id_650 { (*p_0).operation };
      Size id_651 { fun649(id_650) };
      Size id_652 { Size(sz_331 + id_651) };
      let_res_648 = id_652;
    }
    Size let_res_653;
    {
      Size sz_332 { let_res_648 };
      auto fun654 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t_ext id_655 { (*p_0).out_record };
      Size id_656 { fun654(id_655) };
      Size id_657 { Size(sz_332 + id_656) };
      let_res_653 = id_657;
    }
    Size let_res_658;
    {
      Size sz_333 { let_res_653 };
      Lst<dessser::gen::field_name::t_ext> id_659 { (*p_0).factors };
      uint32_t id_660 { id_659.size() };
      Vec<1, uint32_t> id_661 {  id_660  };
      Size let_res_662;
      {
        Vec<1, uint32_t> n_ref_334 { id_661 };
        uint32_t id_663 { 1U };
        Vec<1, uint32_t> id_664 {  id_663  };
        Size let_res_665;
        {
          Vec<1, uint32_t> lebsz_ref_335 { id_664 };
          bool while_flag_666 { true };
          do {
            uint8_t id_667 { 0 };
            uint32_t id_668 { n_ref_334[id_667] };
            uint8_t id_669 { 0 };
            uint32_t id_670 { lebsz_ref_335[id_669] };
            uint8_t id_671 { 7 };
            uint32_t id_672 { uint32_t(id_670 << id_671) };
            bool id_673 { bool(id_668 >= id_672) };
            while_flag_666 = id_673;
            if (while_flag_666) {
              uint8_t id_674 { 0 };
              uint8_t id_675 { 0 };
              uint32_t id_676 { lebsz_ref_335[id_675] };
              uint32_t id_677 { 1U };
              uint32_t id_678 { uint32_t(id_676 + id_677) };
              Void id_679 { ((void)(lebsz_ref_335[id_674] = id_678), ::dessser::VOID) };
              (void)id_679;
            }
          } while (while_flag_666);
          (void)::dessser::VOID;
          uint8_t id_680 { 0 };
          uint32_t id_681 { lebsz_ref_335[id_680] };
          Size id_682 { Size(id_681) };
          let_res_665 = id_682;
        }
        let_res_662 = let_res_665;
      }
      Size id_683 { Size(sz_333 + let_res_662) };
      Vec<1, Size> id_684 {  id_683  };
      Size let_res_685;
      {
        Vec<1, Size> sz_ref_336 { id_684 };
        int32_t id_686 { 0L };
        Vec<1, int32_t> id_687 {  id_686  };
        {
          Vec<1, int32_t> repeat_n_337 { id_687 };
          bool while_flag_688 { true };
          do {
            Lst<dessser::gen::field_name::t_ext> id_689 { (*p_0).factors };
            uint32_t id_690 { id_689.size() };
            int32_t id_691 { int32_t(id_690) };
            uint8_t id_692 { 0 };
            int32_t id_693 { repeat_n_337[id_692] };
            bool id_694 { bool(id_691 > id_693) };
            while_flag_688 = id_694;
            if (while_flag_688) {
              uint8_t id_695 { 0 };
              uint8_t id_696 { 0 };
              Size id_697 { sz_ref_336[id_696] };
              auto fun698 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_699 { 0 };
              int32_t id_700 { repeat_n_337[id_699] };
              Lst<dessser::gen::field_name::t_ext> id_701 { (*p_0).factors };
              dessser::gen::field_name::t_ext id_702 { id_701[id_700] };
              Size id_703 { fun698(id_702) };
              Size id_704 { Size(id_697 + id_703) };
              Void id_705 { ((void)(sz_ref_336[id_695] = id_704), ::dessser::VOID) };
              (void)id_705;
              uint8_t id_706 { 0 };
              uint8_t id_707 { 0 };
              int32_t id_708 { repeat_n_337[id_707] };
              int32_t id_709 { 1L };
              int32_t id_710 { int32_t(id_708 + id_709) };
              Void id_711 { ((void)(repeat_n_337[id_706] = id_710), ::dessser::VOID) };
              (void)id_711;
              (void)id_711;
            }
          } while (while_flag_688);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_712 { 0 };
        Size id_713 { sz_ref_336[id_712] };
        let_res_685 = id_713;
      }
      let_res_658 = let_res_685;
    }
    Size let_res_714;
    {
      Size sz_338 { let_res_658 };
      std::string id_715 { (*p_0).signature };
      uint32_t id_716 { (uint32_t)id_715.size() };
      Vec<1, uint32_t> id_717 {  id_716  };
      Size let_res_718;
      {
        Vec<1, uint32_t> n_ref_340 { id_717 };
        uint32_t id_719 { 1U };
        Vec<1, uint32_t> id_720 {  id_719  };
        Size let_res_721;
        {
          Vec<1, uint32_t> lebsz_ref_341 { id_720 };
          bool while_flag_722 { true };
          do {
            uint8_t id_723 { 0 };
            uint32_t id_724 { n_ref_340[id_723] };
            uint8_t id_725 { 0 };
            uint32_t id_726 { lebsz_ref_341[id_725] };
            uint8_t id_727 { 7 };
            uint32_t id_728 { uint32_t(id_726 << id_727) };
            bool id_729 { bool(id_724 >= id_728) };
            while_flag_722 = id_729;
            if (while_flag_722) {
              uint8_t id_730 { 0 };
              uint8_t id_731 { 0 };
              uint32_t id_732 { lebsz_ref_341[id_731] };
              uint32_t id_733 { 1U };
              uint32_t id_734 { uint32_t(id_732 + id_733) };
              Void id_735 { ((void)(lebsz_ref_341[id_730] = id_734), ::dessser::VOID) };
              (void)id_735;
            }
          } while (while_flag_722);
          (void)::dessser::VOID;
          uint8_t id_736 { 0 };
          uint32_t id_737 { lebsz_ref_341[id_736] };
          Size id_738 { Size(id_737) };
          let_res_721 = id_738;
        }
        let_res_718 = let_res_721;
      }
      std::string id_739 { (*p_0).signature };
      uint32_t id_740 { (uint32_t)id_739.size() };
      Size id_741 { Size(id_740) };
      Size id_742 { Size(let_res_718 + id_741) };
      Size id_743 { Size(sz_338 + id_742) };
      let_res_714 = id_743;
    }
    Size let_res_744;
    {
      Size sz_342 { let_res_714 };
      std::string id_745 { (*p_0).in_signature };
      uint32_t id_746 { (uint32_t)id_745.size() };
      Vec<1, uint32_t> id_747 {  id_746  };
      Size let_res_748;
      {
        Vec<1, uint32_t> n_ref_344 { id_747 };
        uint32_t id_749 { 1U };
        Vec<1, uint32_t> id_750 {  id_749  };
        Size let_res_751;
        {
          Vec<1, uint32_t> lebsz_ref_345 { id_750 };
          bool while_flag_752 { true };
          do {
            uint8_t id_753 { 0 };
            uint32_t id_754 { n_ref_344[id_753] };
            uint8_t id_755 { 0 };
            uint32_t id_756 { lebsz_ref_345[id_755] };
            uint8_t id_757 { 7 };
            uint32_t id_758 { uint32_t(id_756 << id_757) };
            bool id_759 { bool(id_754 >= id_758) };
            while_flag_752 = id_759;
            if (while_flag_752) {
              uint8_t id_760 { 0 };
              uint8_t id_761 { 0 };
              uint32_t id_762 { lebsz_ref_345[id_761] };
              uint32_t id_763 { 1U };
              uint32_t id_764 { uint32_t(id_762 + id_763) };
              Void id_765 { ((void)(lebsz_ref_345[id_760] = id_764), ::dessser::VOID) };
              (void)id_765;
            }
          } while (while_flag_752);
          (void)::dessser::VOID;
          uint8_t id_766 { 0 };
          uint32_t id_767 { lebsz_ref_345[id_766] };
          Size id_768 { Size(id_767) };
          let_res_751 = id_768;
        }
        let_res_748 = let_res_751;
      }
      std::string id_769 { (*p_0).in_signature };
      uint32_t id_770 { (uint32_t)id_769.size() };
      Size id_771 { Size(id_770) };
      Size id_772 { Size(let_res_748 + id_771) };
      Size id_773 { Size(sz_342 + id_772) };
      let_res_744 = id_773;
    }
    return let_res_744;
  }
   };
  return fun599;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary(compiled_func_sersize_of_row_binary_init());

/* 
    (fun ("{default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]}")
      (let "sz_357"
        (let "sz_352"
          (let "sz_351"
            (let "sz_ref_349"
              (make-vec
                (let "n_ref_347" (make-vec (cardinality (get-field "default_params" (param 0))))
                  (let "lebsz_ref_348" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_347")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_348")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_348") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_348")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_348")))))))
              (seq
                (let "repeat_n_350" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "default_params" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_350")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_349")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_349"))
                          (apply (ext-identifier program_parameter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_350")) (get-field "default_params" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_350") (add (unsafe-nth (u8 0) (identifier "repeat_n_350")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_349")))) (add (identifier "sz_351") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "condition" (param 0)))))
          (let "sz_ref_355"
            (make-vec
              (add (identifier "sz_352")
                (let "n_ref_353" (make-vec (cardinality (get-field "globals" (param 0))))
                  (let "lebsz_ref_354" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_353")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_354")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_354") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_354")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_354"))))))))
            (seq
              (let "repeat_n_356" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "globals" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_356")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_355")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_355")) (apply (ext-identifier global_variable sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_356")) (get-field "globals" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_356") (add (unsafe-nth (u8 0) (identifier "repeat_n_356")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_355")))))
        (let "sz_ref_360"
          (make-vec
            (add (identifier "sz_357")
              (let "n_ref_358" (make-vec (cardinality (get-field "funcs" (param 0))))
                (let "lebsz_ref_359" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_358")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_359")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_359") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_359")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_359"))))))))
          (seq
            (let "repeat_n_361" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "funcs" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_361")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_360")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_360")) (apply (identifier "compiled_func-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_361")) (get-field "funcs" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_361") (add (unsafe-nth (u8 0) (identifier "repeat_n_361")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_360"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> fun774 { [&](std::shared_ptr<::dessser::gen::source_info::compiled_program>  p_0) {
    Lst<dessser::gen::program_parameter::t_ext> id_775 { (*p_0).default_params };
    uint32_t id_776 { id_775.size() };
    Vec<1, uint32_t> id_777 {  id_776  };
    Size let_res_778;
    {
      Vec<1, uint32_t> n_ref_347 { id_777 };
      uint32_t id_779 { 1U };
      Vec<1, uint32_t> id_780 {  id_779  };
      Size let_res_781;
      {
        Vec<1, uint32_t> lebsz_ref_348 { id_780 };
        bool while_flag_782 { true };
        do {
          uint8_t id_783 { 0 };
          uint32_t id_784 { n_ref_347[id_783] };
          uint8_t id_785 { 0 };
          uint32_t id_786 { lebsz_ref_348[id_785] };
          uint8_t id_787 { 7 };
          uint32_t id_788 { uint32_t(id_786 << id_787) };
          bool id_789 { bool(id_784 >= id_788) };
          while_flag_782 = id_789;
          if (while_flag_782) {
            uint8_t id_790 { 0 };
            uint8_t id_791 { 0 };
            uint32_t id_792 { lebsz_ref_348[id_791] };
            uint32_t id_793 { 1U };
            uint32_t id_794 { uint32_t(id_792 + id_793) };
            Void id_795 { ((void)(lebsz_ref_348[id_790] = id_794), ::dessser::VOID) };
            (void)id_795;
          }
        } while (while_flag_782);
        (void)::dessser::VOID;
        uint8_t id_796 { 0 };
        uint32_t id_797 { lebsz_ref_348[id_796] };
        Size id_798 { Size(id_797) };
        let_res_781 = id_798;
      }
      let_res_778 = let_res_781;
    }
    Vec<1, Size> id_799 {  let_res_778  };
    Size let_res_800;
    {
      Vec<1, Size> sz_ref_349 { id_799 };
      int32_t id_801 { 0L };
      Vec<1, int32_t> id_802 {  id_801  };
      {
        Vec<1, int32_t> repeat_n_350 { id_802 };
        bool while_flag_803 { true };
        do {
          Lst<dessser::gen::program_parameter::t_ext> id_804 { (*p_0).default_params };
          uint32_t id_805 { id_804.size() };
          int32_t id_806 { int32_t(id_805) };
          uint8_t id_807 { 0 };
          int32_t id_808 { repeat_n_350[id_807] };
          bool id_809 { bool(id_806 > id_808) };
          while_flag_803 = id_809;
          if (while_flag_803) {
            uint8_t id_810 { 0 };
            uint8_t id_811 { 0 };
            Size id_812 { sz_ref_349[id_811] };
            auto fun813 { dessser::gen::program_parameter::sersize_of_row_binary };
            uint8_t id_814 { 0 };
            int32_t id_815 { repeat_n_350[id_814] };
            Lst<dessser::gen::program_parameter::t_ext> id_816 { (*p_0).default_params };
            dessser::gen::program_parameter::t_ext id_817 { id_816[id_815] };
            Size id_818 { fun813(id_817) };
            Size id_819 { Size(id_812 + id_818) };
            Void id_820 { ((void)(sz_ref_349[id_810] = id_819), ::dessser::VOID) };
            (void)id_820;
            uint8_t id_821 { 0 };
            uint8_t id_822 { 0 };
            int32_t id_823 { repeat_n_350[id_822] };
            int32_t id_824 { 1L };
            int32_t id_825 { int32_t(id_823 + id_824) };
            Void id_826 { ((void)(repeat_n_350[id_821] = id_825), ::dessser::VOID) };
            (void)id_826;
            (void)id_826;
          }
        } while (while_flag_803);
        (void)::dessser::VOID;
      }
      (void)::dessser::VOID;
      uint8_t id_827 { 0 };
      Size id_828 { sz_ref_349[id_827] };
      let_res_800 = id_828;
    }
    Size let_res_829;
    {
      Size sz_351 { let_res_800 };
      auto fun830 { dessser::gen::raql_expr::sersize_of_row_binary };
      dessser::gen::raql_expr::t_ext id_831 { (*p_0).condition };
      Size id_832 { fun830(id_831) };
      Size id_833 { Size(sz_351 + id_832) };
      let_res_829 = id_833;
    }
    Size let_res_834;
    {
      Size sz_352 { let_res_829 };
      Lst<dessser::gen::global_variable::t_ext> id_835 { (*p_0).globals };
      uint32_t id_836 { id_835.size() };
      Vec<1, uint32_t> id_837 {  id_836  };
      Size let_res_838;
      {
        Vec<1, uint32_t> n_ref_353 { id_837 };
        uint32_t id_839 { 1U };
        Vec<1, uint32_t> id_840 {  id_839  };
        Size let_res_841;
        {
          Vec<1, uint32_t> lebsz_ref_354 { id_840 };
          bool while_flag_842 { true };
          do {
            uint8_t id_843 { 0 };
            uint32_t id_844 { n_ref_353[id_843] };
            uint8_t id_845 { 0 };
            uint32_t id_846 { lebsz_ref_354[id_845] };
            uint8_t id_847 { 7 };
            uint32_t id_848 { uint32_t(id_846 << id_847) };
            bool id_849 { bool(id_844 >= id_848) };
            while_flag_842 = id_849;
            if (while_flag_842) {
              uint8_t id_850 { 0 };
              uint8_t id_851 { 0 };
              uint32_t id_852 { lebsz_ref_354[id_851] };
              uint32_t id_853 { 1U };
              uint32_t id_854 { uint32_t(id_852 + id_853) };
              Void id_855 { ((void)(lebsz_ref_354[id_850] = id_854), ::dessser::VOID) };
              (void)id_855;
            }
          } while (while_flag_842);
          (void)::dessser::VOID;
          uint8_t id_856 { 0 };
          uint32_t id_857 { lebsz_ref_354[id_856] };
          Size id_858 { Size(id_857) };
          let_res_841 = id_858;
        }
        let_res_838 = let_res_841;
      }
      Size id_859 { Size(sz_352 + let_res_838) };
      Vec<1, Size> id_860 {  id_859  };
      Size let_res_861;
      {
        Vec<1, Size> sz_ref_355 { id_860 };
        int32_t id_862 { 0L };
        Vec<1, int32_t> id_863 {  id_862  };
        {
          Vec<1, int32_t> repeat_n_356 { id_863 };
          bool while_flag_864 { true };
          do {
            Lst<dessser::gen::global_variable::t_ext> id_865 { (*p_0).globals };
            uint32_t id_866 { id_865.size() };
            int32_t id_867 { int32_t(id_866) };
            uint8_t id_868 { 0 };
            int32_t id_869 { repeat_n_356[id_868] };
            bool id_870 { bool(id_867 > id_869) };
            while_flag_864 = id_870;
            if (while_flag_864) {
              uint8_t id_871 { 0 };
              uint8_t id_872 { 0 };
              Size id_873 { sz_ref_355[id_872] };
              auto fun874 { dessser::gen::global_variable::sersize_of_row_binary };
              uint8_t id_875 { 0 };
              int32_t id_876 { repeat_n_356[id_875] };
              Lst<dessser::gen::global_variable::t_ext> id_877 { (*p_0).globals };
              dessser::gen::global_variable::t_ext id_878 { id_877[id_876] };
              Size id_879 { fun874(id_878) };
              Size id_880 { Size(id_873 + id_879) };
              Void id_881 { ((void)(sz_ref_355[id_871] = id_880), ::dessser::VOID) };
              (void)id_881;
              uint8_t id_882 { 0 };
              uint8_t id_883 { 0 };
              int32_t id_884 { repeat_n_356[id_883] };
              int32_t id_885 { 1L };
              int32_t id_886 { int32_t(id_884 + id_885) };
              Void id_887 { ((void)(repeat_n_356[id_882] = id_886), ::dessser::VOID) };
              (void)id_887;
              (void)id_887;
            }
          } while (while_flag_864);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_888 { 0 };
        Size id_889 { sz_ref_355[id_888] };
        let_res_861 = id_889;
      }
      let_res_834 = let_res_861;
    }
    Size let_res_890;
    {
      Size sz_357 { let_res_834 };
      Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_891 { (*p_0).funcs };
      uint32_t id_892 { id_891.size() };
      Vec<1, uint32_t> id_893 {  id_892  };
      Size let_res_894;
      {
        Vec<1, uint32_t> n_ref_358 { id_893 };
        uint32_t id_895 { 1U };
        Vec<1, uint32_t> id_896 {  id_895  };
        Size let_res_897;
        {
          Vec<1, uint32_t> lebsz_ref_359 { id_896 };
          bool while_flag_898 { true };
          do {
            uint8_t id_899 { 0 };
            uint32_t id_900 { n_ref_358[id_899] };
            uint8_t id_901 { 0 };
            uint32_t id_902 { lebsz_ref_359[id_901] };
            uint8_t id_903 { 7 };
            uint32_t id_904 { uint32_t(id_902 << id_903) };
            bool id_905 { bool(id_900 >= id_904) };
            while_flag_898 = id_905;
            if (while_flag_898) {
              uint8_t id_906 { 0 };
              uint8_t id_907 { 0 };
              uint32_t id_908 { lebsz_ref_359[id_907] };
              uint32_t id_909 { 1U };
              uint32_t id_910 { uint32_t(id_908 + id_909) };
              Void id_911 { ((void)(lebsz_ref_359[id_906] = id_910), ::dessser::VOID) };
              (void)id_911;
            }
          } while (while_flag_898);
          (void)::dessser::VOID;
          uint8_t id_912 { 0 };
          uint32_t id_913 { lebsz_ref_359[id_912] };
          Size id_914 { Size(id_913) };
          let_res_897 = id_914;
        }
        let_res_894 = let_res_897;
      }
      Size id_915 { Size(sz_357 + let_res_894) };
      Vec<1, Size> id_916 {  id_915  };
      Size let_res_917;
      {
        Vec<1, Size> sz_ref_360 { id_916 };
        int32_t id_918 { 0L };
        Vec<1, int32_t> id_919 {  id_918  };
        {
          Vec<1, int32_t> repeat_n_361 { id_919 };
          bool while_flag_920 { true };
          do {
            Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_921 { (*p_0).funcs };
            uint32_t id_922 { id_921.size() };
            int32_t id_923 { int32_t(id_922) };
            uint8_t id_924 { 0 };
            int32_t id_925 { repeat_n_361[id_924] };
            bool id_926 { bool(id_923 > id_925) };
            while_flag_920 = id_926;
            if (while_flag_920) {
              uint8_t id_927 { 0 };
              uint8_t id_928 { 0 };
              Size id_929 { sz_ref_360[id_928] };
              uint8_t id_930 { 0 };
              int32_t id_931 { repeat_n_361[id_930] };
              Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_932 { (*p_0).funcs };
              std::shared_ptr<::dessser::gen::source_info::compiled_func>  id_933 { id_932[id_931] };
              Size id_934 { compiled_func_sersize_of_row_binary(id_933) };
              Size id_935 { Size(id_929 + id_934) };
              Void id_936 { ((void)(sz_ref_360[id_927] = id_935), ::dessser::VOID) };
              (void)id_936;
              uint8_t id_937 { 0 };
              uint8_t id_938 { 0 };
              int32_t id_939 { repeat_n_361[id_938] };
              int32_t id_940 { 1L };
              int32_t id_941 { int32_t(id_939 + id_940) };
              Void id_942 { ((void)(repeat_n_361[id_937] = id_941), ::dessser::VOID) };
              (void)id_942;
              (void)id_942;
            }
          } while (while_flag_920);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_943 { 0 };
        Size id_944 { sz_ref_360[id_943] };
        let_res_917 = id_944;
      }
      let_res_890 = let_res_917;
    }
    return let_res_890;
  }
   };
  return fun774;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary(compiled_program_sersize_of_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]}) | Failed {err_msg: STRING; depends_on: $src_path?}]}")
      (let "sz_374"
        (let "sz_366"
          (add
            (let "n_ref_364" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "lebsz_ref_365" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_364")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_365") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_365")))))) 
            (size-of-u32 (string-length (get-field "src_ext" (param 0)))))
          (let "sz_ref_369"
            (make-vec
              (add (identifier "sz_366")
                (let "n_ref_367" (make-vec (cardinality (get-field "md5s" (param 0))))
                  (let "lebsz_ref_368" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_367")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_368")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_368") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_368")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_368"))))))))
            (seq
              (let "repeat_n_370" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "md5s" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_370")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_369")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_369"))
                        (let "wlen_371" (string-length (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_370")) (get-field "md5s" (param 0))))
                          (add
                            (let "n_ref_372" (make-vec (identifier "wlen_371"))
                              (let "lebsz_ref_373" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_372")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_373")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_373") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_373")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_373")))))) 
                            (size-of-u32 (identifier "wlen_371")))))) 
                    (set-vec (u8 0) (identifier "repeat_n_370") (add (unsafe-nth (u8 0) (identifier "repeat_n_370")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_369")))))
        (if (eq (u16 0) (label-of (get-field "detail" (param 0)))) (add (add (identifier "sz_374") (size 2)) (apply (identifier "compiled_program-sersize-of-row-binary") (get-alt "Compiled" (get-field "detail" (param 0)))))
          (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
            (let "sz_380"
              (add (add (identifier "sz_374") (size 2))
                (add
                  (let "n_ref_378" (make-vec (string-length (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))
                    (let "lebsz_ref_379" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_378")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_379")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_379") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_379")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_379")))))) 
                  (size-of-u32 (string-length (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))))
              (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                (add (identifier "sz_380") (size 1))
                (add (add (identifier "sz_380") (apply (ext-identifier src_path sersize-of-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))))) (size 1))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> fun945 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0) {
    std::string id_946 { (*p_0).src_ext };
    uint32_t id_947 { (uint32_t)id_946.size() };
    Vec<1, uint32_t> id_948 {  id_947  };
    Size let_res_949;
    {
      Vec<1, uint32_t> n_ref_364 { id_948 };
      uint32_t id_950 { 1U };
      Vec<1, uint32_t> id_951 {  id_950  };
      Size let_res_952;
      {
        Vec<1, uint32_t> lebsz_ref_365 { id_951 };
        bool while_flag_953 { true };
        do {
          uint8_t id_954 { 0 };
          uint32_t id_955 { n_ref_364[id_954] };
          uint8_t id_956 { 0 };
          uint32_t id_957 { lebsz_ref_365[id_956] };
          uint8_t id_958 { 7 };
          uint32_t id_959 { uint32_t(id_957 << id_958) };
          bool id_960 { bool(id_955 >= id_959) };
          while_flag_953 = id_960;
          if (while_flag_953) {
            uint8_t id_961 { 0 };
            uint8_t id_962 { 0 };
            uint32_t id_963 { lebsz_ref_365[id_962] };
            uint32_t id_964 { 1U };
            uint32_t id_965 { uint32_t(id_963 + id_964) };
            Void id_966 { ((void)(lebsz_ref_365[id_961] = id_965), ::dessser::VOID) };
            (void)id_966;
          }
        } while (while_flag_953);
        (void)::dessser::VOID;
        uint8_t id_967 { 0 };
        uint32_t id_968 { lebsz_ref_365[id_967] };
        Size id_969 { Size(id_968) };
        let_res_952 = id_969;
      }
      let_res_949 = let_res_952;
    }
    std::string id_970 { (*p_0).src_ext };
    uint32_t id_971 { (uint32_t)id_970.size() };
    Size id_972 { Size(id_971) };
    Size id_973 { Size(let_res_949 + id_972) };
    Size let_res_974;
    {
      Size sz_366 { id_973 };
      Lst<std::string> id_975 { (*p_0).md5s };
      uint32_t id_976 { id_975.size() };
      Vec<1, uint32_t> id_977 {  id_976  };
      Size let_res_978;
      {
        Vec<1, uint32_t> n_ref_367 { id_977 };
        uint32_t id_979 { 1U };
        Vec<1, uint32_t> id_980 {  id_979  };
        Size let_res_981;
        {
          Vec<1, uint32_t> lebsz_ref_368 { id_980 };
          bool while_flag_982 { true };
          do {
            uint8_t id_983 { 0 };
            uint32_t id_984 { n_ref_367[id_983] };
            uint8_t id_985 { 0 };
            uint32_t id_986 { lebsz_ref_368[id_985] };
            uint8_t id_987 { 7 };
            uint32_t id_988 { uint32_t(id_986 << id_987) };
            bool id_989 { bool(id_984 >= id_988) };
            while_flag_982 = id_989;
            if (while_flag_982) {
              uint8_t id_990 { 0 };
              uint8_t id_991 { 0 };
              uint32_t id_992 { lebsz_ref_368[id_991] };
              uint32_t id_993 { 1U };
              uint32_t id_994 { uint32_t(id_992 + id_993) };
              Void id_995 { ((void)(lebsz_ref_368[id_990] = id_994), ::dessser::VOID) };
              (void)id_995;
            }
          } while (while_flag_982);
          (void)::dessser::VOID;
          uint8_t id_996 { 0 };
          uint32_t id_997 { lebsz_ref_368[id_996] };
          Size id_998 { Size(id_997) };
          let_res_981 = id_998;
        }
        let_res_978 = let_res_981;
      }
      Size id_999 { Size(sz_366 + let_res_978) };
      Vec<1, Size> id_1000 {  id_999  };
      Size let_res_1001;
      {
        Vec<1, Size> sz_ref_369 { id_1000 };
        int32_t id_1002 { 0L };
        Vec<1, int32_t> id_1003 {  id_1002  };
        {
          Vec<1, int32_t> repeat_n_370 { id_1003 };
          bool while_flag_1004 { true };
          do {
            Lst<std::string> id_1005 { (*p_0).md5s };
            uint32_t id_1006 { id_1005.size() };
            int32_t id_1007 { int32_t(id_1006) };
            uint8_t id_1008 { 0 };
            int32_t id_1009 { repeat_n_370[id_1008] };
            bool id_1010 { bool(id_1007 > id_1009) };
            while_flag_1004 = id_1010;
            if (while_flag_1004) {
              uint8_t id_1011 { 0 };
              uint8_t id_1012 { 0 };
              Size id_1013 { sz_ref_369[id_1012] };
              uint8_t id_1014 { 0 };
              int32_t id_1015 { repeat_n_370[id_1014] };
              Lst<std::string> id_1016 { (*p_0).md5s };
              std::string id_1017 { id_1016[id_1015] };
              uint32_t id_1018 { (uint32_t)id_1017.size() };
              Size let_res_1019;
              {
                uint32_t wlen_371 { id_1018 };
                Vec<1, uint32_t> id_1020 {  wlen_371  };
                Size let_res_1021;
                {
                  Vec<1, uint32_t> n_ref_372 { id_1020 };
                  uint32_t id_1022 { 1U };
                  Vec<1, uint32_t> id_1023 {  id_1022  };
                  Size let_res_1024;
                  {
                    Vec<1, uint32_t> lebsz_ref_373 { id_1023 };
                    bool while_flag_1025 { true };
                    do {
                      uint8_t id_1026 { 0 };
                      uint32_t id_1027 { n_ref_372[id_1026] };
                      uint8_t id_1028 { 0 };
                      uint32_t id_1029 { lebsz_ref_373[id_1028] };
                      uint8_t id_1030 { 7 };
                      uint32_t id_1031 { uint32_t(id_1029 << id_1030) };
                      bool id_1032 { bool(id_1027 >= id_1031) };
                      while_flag_1025 = id_1032;
                      if (while_flag_1025) {
                        uint8_t id_1033 { 0 };
                        uint8_t id_1034 { 0 };
                        uint32_t id_1035 { lebsz_ref_373[id_1034] };
                        uint32_t id_1036 { 1U };
                        uint32_t id_1037 { uint32_t(id_1035 + id_1036) };
                        Void id_1038 { ((void)(lebsz_ref_373[id_1033] = id_1037), ::dessser::VOID) };
                        (void)id_1038;
                      }
                    } while (while_flag_1025);
                    (void)::dessser::VOID;
                    uint8_t id_1039 { 0 };
                    uint32_t id_1040 { lebsz_ref_373[id_1039] };
                    Size id_1041 { Size(id_1040) };
                    let_res_1024 = id_1041;
                  }
                  let_res_1021 = let_res_1024;
                }
                Size id_1042 { Size(wlen_371) };
                Size id_1043 { Size(let_res_1021 + id_1042) };
                let_res_1019 = id_1043;
              }
              Size id_1044 { Size(id_1013 + let_res_1019) };
              Void id_1045 { ((void)(sz_ref_369[id_1011] = id_1044), ::dessser::VOID) };
              (void)id_1045;
              uint8_t id_1046 { 0 };
              uint8_t id_1047 { 0 };
              int32_t id_1048 { repeat_n_370[id_1047] };
              int32_t id_1049 { 1L };
              int32_t id_1050 { int32_t(id_1048 + id_1049) };
              Void id_1051 { ((void)(repeat_n_370[id_1046] = id_1050), ::dessser::VOID) };
              (void)id_1051;
              (void)id_1051;
            }
          } while (while_flag_1004);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_1052 { 0 };
        Size id_1053 { sz_ref_369[id_1052] };
        let_res_1001 = id_1053;
      }
      let_res_974 = let_res_1001;
    }
    Size let_res_1054;
    {
      Size sz_374 { let_res_974 };
      uint16_t id_1055 { 0 };
      ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1056 { (*p_0).detail };
      uint16_t id_1057 { uint16_t(id_1056.index()) };
      bool id_1058 { bool(id_1055 == id_1057) };
      Size choose_res_1059;
      if (id_1058) {
        Size id_1060 { 2UL };
        Size id_1061 { Size(sz_374 + id_1060) };
        ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1062 { (*p_0).detail };
        std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_1063 { std::get<0 /* Compiled */>(id_1062) };
        Size id_1064 { compiled_program_sersize_of_row_binary(id_1063) };
        Size id_1065 { Size(id_1061 + id_1064) };
        choose_res_1059 = id_1065;
      } else {
        ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1066 { (*p_0).detail };
        uint16_t id_1067 { uint16_t(id_1066.index()) };
        uint16_t id_1068 { 1 };
        bool id_1069 { bool(id_1067 == id_1068) };
        Void id_1070 { ((void)(assert(id_1069)), ::dessser::VOID) };
        (void)id_1070;
        Size id_1071 { 2UL };
        Size id_1072 { Size(sz_374 + id_1071) };
        ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1073 { (*p_0).detail };
        ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_1074 { std::get<1 /* Failed */>(id_1073) };
        std::string id_1075 { id_1074.err_msg };
        uint32_t id_1076 { (uint32_t)id_1075.size() };
        Vec<1, uint32_t> id_1077 {  id_1076  };
        Size let_res_1078;
        {
          Vec<1, uint32_t> n_ref_378 { id_1077 };
          uint32_t id_1079 { 1U };
          Vec<1, uint32_t> id_1080 {  id_1079  };
          Size let_res_1081;
          {
            Vec<1, uint32_t> lebsz_ref_379 { id_1080 };
            bool while_flag_1082 { true };
            do {
              uint8_t id_1083 { 0 };
              uint32_t id_1084 { n_ref_378[id_1083] };
              uint8_t id_1085 { 0 };
              uint32_t id_1086 { lebsz_ref_379[id_1085] };
              uint8_t id_1087 { 7 };
              uint32_t id_1088 { uint32_t(id_1086 << id_1087) };
              bool id_1089 { bool(id_1084 >= id_1088) };
              while_flag_1082 = id_1089;
              if (while_flag_1082) {
                uint8_t id_1090 { 0 };
                uint8_t id_1091 { 0 };
                uint32_t id_1092 { lebsz_ref_379[id_1091] };
                uint32_t id_1093 { 1U };
                uint32_t id_1094 { uint32_t(id_1092 + id_1093) };
                Void id_1095 { ((void)(lebsz_ref_379[id_1090] = id_1094), ::dessser::VOID) };
                (void)id_1095;
              }
            } while (while_flag_1082);
            (void)::dessser::VOID;
            uint8_t id_1096 { 0 };
            uint32_t id_1097 { lebsz_ref_379[id_1096] };
            Size id_1098 { Size(id_1097) };
            let_res_1081 = id_1098;
          }
          let_res_1078 = let_res_1081;
        }
        ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1099 { (*p_0).detail };
        ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_1100 { std::get<1 /* Failed */>(id_1099) };
        std::string id_1101 { id_1100.err_msg };
        uint32_t id_1102 { (uint32_t)id_1101.size() };
        Size id_1103 { Size(id_1102) };
        Size id_1104 { Size(let_res_1078 + id_1103) };
        Size id_1105 { Size(id_1072 + id_1104) };
        Size let_res_1106;
        {
          Size sz_380 { id_1105 };
          ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1107 { (*p_0).detail };
          ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_1108 { std::get<1 /* Failed */>(id_1107) };
          std::optional<dessser::gen::src_path::t_ext> id_1109 { id_1108.depends_on };
          bool id_1110 { !(id_1109.has_value ()) };
          Size choose_res_1111;
          if (id_1110) {
            Size id_1112 { 1UL };
            Size id_1113 { Size(sz_380 + id_1112) };
            choose_res_1111 = id_1113;
          } else {
            auto fun1114 { dessser::gen::src_path::sersize_of_row_binary };
            ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1115 { (*p_0).detail };
            ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_1116 { std::get<1 /* Failed */>(id_1115) };
            std::optional<dessser::gen::src_path::t_ext> id_1117 { id_1116.depends_on };
            dessser::gen::src_path::t_ext id_1118 { id_1117.value() };
            Size id_1119 { fun1114(id_1118) };
            Size id_1120 { Size(sz_380 + id_1119) };
            Size id_1121 { 1UL };
            Size id_1122 { Size(id_1120 + id_1121) };
            choose_res_1111 = id_1122;
          }
          let_res_1106 = choose_res_1111;
        }
        choose_res_1059 = let_res_1106;
      }
      let_res_1054 = choose_res_1059;
    }
    return let_res_1054;
  }
   };
  return fun945;
}
std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier function_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_62"
            (if (eq (peek-u8 (identifier "drec_snd_58") (size 0)) (u8 1)) 
              (make-tup (null "$retention") (ptr-add (identifier "drec_snd_58") (size 1)))
              (let-pair "make1_1_fst_60" "make1_1_snd_61" (apply (ext-identifier retention of-row-binary) (ptr-add (identifier "drec_snd_58") (size 1)))
                (make-tup (not-null (identifier "make1_1_fst_60")) (identifier "make1_1_snd_61"))))
            (let-pair "drec_fst_63" "drec_snd_64" (identifier "drec_62")
              (let "drec_68" (let-pair "dbool_fst_66" "dbool_snd_67" (read-u8 (identifier "drec_snd_64")) (make-tup (not (eq (identifier "dbool_fst_66") (u8 0))) (identifier "dbool_snd_67")))
                (let-pair "drec_fst_69" "drec_snd_70" (identifier "drec_68")
                  (let "drec_83"
                    (let "dstring1_77"
                      (let "leb_ref_71" (make-vec (u32 0))
                        (let "shft_ref_72" (make-vec (u8 0))
                          (let "p_ref_73" (make-vec (identifier "drec_snd_70"))
                            (seq
                              (while
                                (let "leb128_74" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_73")))
                                  (let-pair "leb128_fst_75" "leb128_snd_76" 
                                    (identifier "leb128_74")
                                    (seq (set-vec (u8 0) (identifier "p_ref_73") (identifier "leb128_snd_76"))
                                      (set-vec (u8 0) (identifier "leb_ref_71")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_75") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_72"))) (unsafe-nth (u8 0) (identifier "leb_ref_71"))))
                                      (set-vec (u8 0) (identifier "shft_ref_72") (add (unsafe-nth (u8 0) (identifier "shft_ref_72")) (u8 7))) 
                                      (ge (identifier "leb128_fst_75") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_71"))) (unsafe-nth (u8 0) (identifier "p_ref_73")))))))
                      (let-pair "dstring1_fst_78" "dstring1_snd_79" (identifier "dstring1_77")
                        (let-pair "dstring2_fst_81" "dstring2_snd_82" 
                          (read-bytes (identifier "dstring1_snd_79") (identifier "dstring1_fst_78")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_81")) (identifier "dstring2_snd_82")))))
                    (let-pair "drec_fst_84" "drec_snd_85" (identifier "drec_83")
                      (let "drec_86" (apply (ext-identifier raql_operation of-row-binary) (identifier "drec_snd_85"))
                        (let-pair "drec_fst_87" "drec_snd_88" (identifier "drec_86")
                          (let "drec_89" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_88"))
                            (let-pair "drec_fst_90" "drec_snd_91" (identifier "drec_89")
                              (let "drec_115"
                                (let-pair "dlist4_fst_113" "dlist4_snd_114"
                                  (let "dlist1_101"
                                    (let "leb_ref_92" (make-vec (u32 0))
                                      (let "shft_ref_93" (make-vec (u8 0))
                                        (let "p_ref_94" (make-vec (identifier "drec_snd_91"))
                                          (seq
                                            (while
                                              (let "leb128_95" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_94")))
                                                (let-pair "leb128_fst_96" "leb128_snd_97" 
                                                  (identifier "leb128_95")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_94") (identifier "leb128_snd_97"))
                                                    (set-vec (u8 0) (identifier "leb_ref_92")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_96") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_93"))) (unsafe-nth (u8 0) (identifier "leb_ref_92"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_93") (add (unsafe-nth (u8 0) (identifier "shft_ref_93")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_96") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_92")) (unsafe-nth (u8 0) (identifier "p_ref_94")))))))
                                    (let-pair "dlist1_fst_102" "dlist1_snd_103" 
                                      (identifier "dlist1_101")
                                      (let "inits_src_ref_104" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_103")))
                                        (seq
                                          (let "repeat_n_105" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_102")) (unsafe-nth (u8 0) (identifier "repeat_n_105")))
                                              (seq
                                                (let "dlist2_106" (unsafe-nth (u8 0) (identifier "inits_src_ref_104"))
                                                  (let-pair "dlist2_fst_107" "dlist2_snd_108" 
                                                    (identifier "dlist2_106")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_104")
                                                      (let-pair "dlist3_fst_110" "dlist3_snd_111" 
                                                        (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_108"))
                                                        (make-tup (cons (identifier "dlist3_fst_110") (identifier "dlist2_fst_107")) (identifier "dlist3_snd_111"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_105") (add (unsafe-nth (u8 0) (identifier "repeat_n_105")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_104")))))) 
                                  (make-tup (identity (identifier "dlist4_fst_113")) (identifier "dlist4_snd_114")))
                                (let-pair "drec_fst_116" "drec_snd_117" 
                                  (identifier "drec_115")
                                  (let "drec_130"
                                    (let "dstring1_124"
                                      (let "leb_ref_118" (make-vec (u32 0))
                                        (let "shft_ref_119" (make-vec (u8 0))
                                          (let "p_ref_120" (make-vec (identifier "drec_snd_117"))
                                            (seq
                                              (while
                                                (let "leb128_121" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_120")))
                                                  (let-pair "leb128_fst_122" "leb128_snd_123" 
                                                    (identifier "leb128_121")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_120") (identifier "leb128_snd_123"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_118")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_122") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_119")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_118")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_119") (add (unsafe-nth (u8 0) (identifier "shft_ref_119")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_122") (u8 128))))) 
                                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_118"))) (unsafe-nth (u8 0) (identifier "p_ref_120")))))))
                                      (let-pair "dstring1_fst_125" "dstring1_snd_126" 
                                        (identifier "dstring1_124")
                                        (let-pair "dstring2_fst_128" "dstring2_snd_129" 
                                          (read-bytes (identifier "dstring1_snd_126") (identifier "dstring1_fst_125")) 
                                          (make-tup (string-of-bytes (identifier "dstring2_fst_128")) (identifier "dstring2_snd_129")))))
                                    (let-pair "drec_fst_131" "drec_snd_132" 
                                      (identifier "drec_130")
                                      (let "dstring1_139"
                                        (let "leb_ref_133" (make-vec (u32 0))
                                          (let "shft_ref_134" (make-vec (u8 0))
                                            (let "p_ref_135" (make-vec (identifier "drec_snd_132"))
                                              (seq
                                                (while
                                                  (let "leb128_136" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_135")))
                                                    (let-pair "leb128_fst_137" "leb128_snd_138" 
                                                      (identifier "leb128_136")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_135") (identifier "leb128_snd_138"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_133")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_137") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_134")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_133")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_134") (add (unsafe-nth (u8 0) (identifier "shft_ref_134")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_137") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_133"))) (unsafe-nth (u8 0) (identifier "p_ref_135")))))))
                                        (let-pair "dstring1_fst_140" "dstring1_snd_141" 
                                          (identifier "dstring1_139")
                                          (let-pair "dstring2_fst_143" "dstring2_snd_144" 
                                            (read-bytes (identifier "dstring1_snd_141") (identifier "dstring1_fst_140"))
                                            (make-tup
                                              (make-rec (string "in_signature") 
                                                (string-of-bytes (identifier "dstring2_fst_143")) 
                                                (string "signature") 
                                                (identifier "drec_fst_131") 
                                                (string "factors") (identifier "drec_fst_116") 
                                                (string "out_record") 
                                                (identifier "drec_fst_90") 
                                                (string "operation") 
                                                (identifier "drec_fst_87") 
                                                (string "doc") (identifier "drec_fst_84") 
                                                (string "is_lazy") (identifier "drec_fst_69") 
                                                (string "retention") 
                                                (identifier "drec_fst_63") 
                                                (string "name") (identifier "drec_fst_57")) 
                                              (identifier "dstring2_snd_144"))))))))))))))))))))))
 */
static std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> compiled_func_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> fun1123 { [&](Pointer p_0) {
    auto fun1124 { dessser::gen::function_name::of_row_binary };
    ::dessser::gen::source_info::t7ced0f6935c1265b26e1abfcc364f52e id_1125 { fun1124(p_0) };
    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1126;
    {
      ::dessser::gen::source_info::t7ced0f6935c1265b26e1abfcc364f52e drec_56 { id_1125 };
      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1127;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        Size id_1128 { 0UL };
        uint8_t id_1129 { drec_snd_58.peekU8(id_1128) };
        uint8_t id_1130 { 1 };
        bool id_1131 { bool(id_1129 == id_1130) };
        ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 choose_res_1132;
        if (id_1131) {
          std::optional<dessser::gen::retention::t_ext> id_1133 { std::nullopt };
          Size id_1134 { 1UL };
          Pointer id_1135 { drec_snd_58.skip(id_1134) };
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 id_1136 { id_1133, id_1135 };
          choose_res_1132 = id_1136;
        } else {
          auto fun1137 { dessser::gen::retention::of_row_binary };
          Size id_1138 { 1UL };
          Pointer id_1139 { drec_snd_58.skip(id_1138) };
          ::dessser::gen::source_info::tde821e6d031c399b029ea4a78810ecf6 id_1140 { fun1137(id_1139) };
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 letpair_res_1141;
          {
            auto make1_1_fst_60 { std::get<0>(id_1140) };
            auto make1_1_snd_61 { std::get<1>(id_1140) };
            std::optional<dessser::gen::retention::t_ext> id_1142 { make1_1_fst_60 };
            ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 id_1143 { id_1142, make1_1_snd_61 };
            letpair_res_1141 = id_1143;
          }
          choose_res_1132 = letpair_res_1141;
        }
        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1144;
        {
          ::dessser::gen::source_info::tc72cc770fa220718dd8ff2db4757ae10 drec_62 { choose_res_1132 };
          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1145;
          {
            auto drec_fst_63 { std::get<0>(drec_62) };
            auto drec_snd_64 { std::get<1>(drec_62) };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1146 { drec_snd_64.readU8() };
            ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1147;
            {
              auto dbool_fst_66 { std::get<0>(id_1146) };
              auto dbool_snd_67 { std::get<1>(id_1146) };
              uint8_t id_1148 { 0 };
              bool id_1149 { bool(dbool_fst_66 == id_1148) };
              bool id_1150 { ! id_1149 };
              ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 id_1151 { id_1150, dbool_snd_67 };
              letpair_res_1147 = id_1151;
            }
            ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1152;
            {
              ::dessser::gen::source_info::tf9a0a3fefc87c9e10a93d3a172850c26 drec_68 { letpair_res_1147 };
              ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1153;
              {
                auto drec_fst_69 { std::get<0>(drec_68) };
                auto drec_snd_70 { std::get<1>(drec_68) };
                uint32_t id_1154 { 0U };
                Vec<1, uint32_t> id_1155 {  id_1154  };
                ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1156;
                {
                  Vec<1, uint32_t> leb_ref_71 { id_1155 };
                  uint8_t id_1157 { 0 };
                  Vec<1, uint8_t> id_1158 {  id_1157  };
                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1159;
                  {
                    Vec<1, uint8_t> shft_ref_72 { id_1158 };
                    Vec<1, Pointer> id_1160 {  drec_snd_70  };
                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1161;
                    {
                      Vec<1, Pointer> p_ref_73 { id_1160 };
                      bool while_flag_1162 { true };
                      do {
                        uint8_t id_1163 { 0 };
                        Pointer id_1164 { p_ref_73[id_1163] };
                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1165 { id_1164.readU8() };
                        bool let_res_1166;
                        {
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_74 { id_1165 };
                          bool letpair_res_1167;
                          {
                            auto leb128_fst_75 { std::get<0>(leb128_74) };
                            auto leb128_snd_76 { std::get<1>(leb128_74) };
                            uint8_t id_1168 { 0 };
                            Void id_1169 { ((void)(p_ref_73[id_1168] = leb128_snd_76), ::dessser::VOID) };
                            (void)id_1169;
                            uint8_t id_1170 { 0 };
                            uint8_t id_1171 { 127 };
                            uint8_t id_1172 { uint8_t(leb128_fst_75 & id_1171) };
                            uint32_t id_1173 { uint32_t(id_1172) };
                            uint8_t id_1174 { 0 };
                            uint8_t id_1175 { shft_ref_72[id_1174] };
                            uint32_t id_1176 { uint32_t(id_1173 << id_1175) };
                            uint8_t id_1177 { 0 };
                            uint32_t id_1178 { leb_ref_71[id_1177] };
                            uint32_t id_1179 { uint32_t(id_1176 | id_1178) };
                            Void id_1180 { ((void)(leb_ref_71[id_1170] = id_1179), ::dessser::VOID) };
                            (void)id_1180;
                            uint8_t id_1181 { 0 };
                            uint8_t id_1182 { 0 };
                            uint8_t id_1183 { shft_ref_72[id_1182] };
                            uint8_t id_1184 { 7 };
                            uint8_t id_1185 { uint8_t(id_1183 + id_1184) };
                            Void id_1186 { ((void)(shft_ref_72[id_1181] = id_1185), ::dessser::VOID) };
                            (void)id_1186;
                            uint8_t id_1187 { 128 };
                            bool id_1188 { bool(leb128_fst_75 >= id_1187) };
                            letpair_res_1167 = id_1188;
                          }
                          let_res_1166 = letpair_res_1167;
                        }
                        while_flag_1162 = let_res_1166;
                        if (while_flag_1162) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_1162);
                      (void)::dessser::VOID;
                      uint8_t id_1189 { 0 };
                      uint32_t id_1190 { leb_ref_71[id_1189] };
                      Size id_1191 { Size(id_1190) };
                      uint8_t id_1192 { 0 };
                      Pointer id_1193 { p_ref_73[id_1192] };
                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1194 { id_1191, id_1193 };
                      let_res_1161 = id_1194;
                    }
                    let_res_1159 = let_res_1161;
                  }
                  let_res_1156 = let_res_1159;
                }
                ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1195;
                {
                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_77 { let_res_1156 };
                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1196;
                  {
                    auto dstring1_fst_78 { std::get<0>(dstring1_77) };
                    auto dstring1_snd_79 { std::get<1>(dstring1_77) };
                    ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1197 { dstring1_snd_79.readBytes(dstring1_fst_78) };
                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1198;
                    {
                      auto dstring2_fst_81 { std::get<0>(id_1197) };
                      auto dstring2_snd_82 { std::get<1>(id_1197) };
                      std::string id_1199 { dstring2_fst_81.toString() };
                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1200 { id_1199, dstring2_snd_82 };
                      letpair_res_1198 = id_1200;
                    }
                    letpair_res_1196 = letpair_res_1198;
                  }
                  let_res_1195 = letpair_res_1196;
                }
                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1201;
                {
                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_83 { let_res_1195 };
                  ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1202;
                  {
                    auto drec_fst_84 { std::get<0>(drec_83) };
                    auto drec_snd_85 { std::get<1>(drec_83) };
                    auto fun1203 { dessser::gen::raql_operation::of_row_binary };
                    ::dessser::gen::source_info::t9539d836e50d2481333b4e3eeeadf0ff id_1204 { fun1203(drec_snd_85) };
                    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1205;
                    {
                      ::dessser::gen::source_info::t9539d836e50d2481333b4e3eeeadf0ff drec_86 { id_1204 };
                      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1206;
                      {
                        auto drec_fst_87 { std::get<0>(drec_86) };
                        auto drec_snd_88 { std::get<1>(drec_86) };
                        auto fun1207 { dessser::gen::raql_type::of_row_binary };
                        ::dessser::gen::source_info::t101502ffd7fb38beafe4b49259f92ba1 id_1208 { fun1207(drec_snd_88) };
                        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1209;
                        {
                          ::dessser::gen::source_info::t101502ffd7fb38beafe4b49259f92ba1 drec_89 { id_1208 };
                          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1210;
                          {
                            auto drec_fst_90 { std::get<0>(drec_89) };
                            auto drec_snd_91 { std::get<1>(drec_89) };
                            uint32_t id_1211 { 0U };
                            Vec<1, uint32_t> id_1212 {  id_1211  };
                            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1213;
                            {
                              Vec<1, uint32_t> leb_ref_92 { id_1212 };
                              uint8_t id_1214 { 0 };
                              Vec<1, uint8_t> id_1215 {  id_1214  };
                              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1216;
                              {
                                Vec<1, uint8_t> shft_ref_93 { id_1215 };
                                Vec<1, Pointer> id_1217 {  drec_snd_91  };
                                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1218;
                                {
                                  Vec<1, Pointer> p_ref_94 { id_1217 };
                                  bool while_flag_1219 { true };
                                  do {
                                    uint8_t id_1220 { 0 };
                                    Pointer id_1221 { p_ref_94[id_1220] };
                                    ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1222 { id_1221.readU8() };
                                    bool let_res_1223;
                                    {
                                      ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_95 { id_1222 };
                                      bool letpair_res_1224;
                                      {
                                        auto leb128_fst_96 { std::get<0>(leb128_95) };
                                        auto leb128_snd_97 { std::get<1>(leb128_95) };
                                        uint8_t id_1225 { 0 };
                                        Void id_1226 { ((void)(p_ref_94[id_1225] = leb128_snd_97), ::dessser::VOID) };
                                        (void)id_1226;
                                        uint8_t id_1227 { 0 };
                                        uint8_t id_1228 { 127 };
                                        uint8_t id_1229 { uint8_t(leb128_fst_96 & id_1228) };
                                        uint32_t id_1230 { uint32_t(id_1229) };
                                        uint8_t id_1231 { 0 };
                                        uint8_t id_1232 { shft_ref_93[id_1231] };
                                        uint32_t id_1233 { uint32_t(id_1230 << id_1232) };
                                        uint8_t id_1234 { 0 };
                                        uint32_t id_1235 { leb_ref_92[id_1234] };
                                        uint32_t id_1236 { uint32_t(id_1233 | id_1235) };
                                        Void id_1237 { ((void)(leb_ref_92[id_1227] = id_1236), ::dessser::VOID) };
                                        (void)id_1237;
                                        uint8_t id_1238 { 0 };
                                        uint8_t id_1239 { 0 };
                                        uint8_t id_1240 { shft_ref_93[id_1239] };
                                        uint8_t id_1241 { 7 };
                                        uint8_t id_1242 { uint8_t(id_1240 + id_1241) };
                                        Void id_1243 { ((void)(shft_ref_93[id_1238] = id_1242), ::dessser::VOID) };
                                        (void)id_1243;
                                        uint8_t id_1244 { 128 };
                                        bool id_1245 { bool(leb128_fst_96 >= id_1244) };
                                        letpair_res_1224 = id_1245;
                                      }
                                      let_res_1223 = letpair_res_1224;
                                    }
                                    while_flag_1219 = let_res_1223;
                                    if (while_flag_1219) {
                                      (void)::dessser::VOID;
                                    }
                                  } while (while_flag_1219);
                                  (void)::dessser::VOID;
                                  uint8_t id_1246 { 0 };
                                  uint32_t id_1247 { leb_ref_92[id_1246] };
                                  uint8_t id_1248 { 0 };
                                  Pointer id_1249 { p_ref_94[id_1248] };
                                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1250 { id_1247, id_1249 };
                                  let_res_1218 = id_1250;
                                }
                                let_res_1216 = let_res_1218;
                              }
                              let_res_1213 = let_res_1216;
                            }
                            ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1251;
                            {
                              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_101 { let_res_1213 };
                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1252;
                              {
                                auto dlist1_fst_102 { std::get<0>(dlist1_101) };
                                auto dlist1_snd_103 { std::get<1>(dlist1_101) };
                                Lst<dessser::gen::field_name::t_ext> endoflist_1253;
                                ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1254 { endoflist_1253, dlist1_snd_103 };
                                Vec<1, ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_1255 {  id_1254  };
                                ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_1256;
                                {
                                  Vec<1, ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_104 { id_1255 };
                                  int32_t id_1257 { 0L };
                                  Vec<1, int32_t> id_1258 {  id_1257  };
                                  {
                                    Vec<1, int32_t> repeat_n_105 { id_1258 };
                                    bool while_flag_1259 { true };
                                    do {
                                      int32_t id_1260 { int32_t(dlist1_fst_102) };
                                      uint8_t id_1261 { 0 };
                                      int32_t id_1262 { repeat_n_105[id_1261] };
                                      bool id_1263 { bool(id_1260 > id_1262) };
                                      while_flag_1259 = id_1263;
                                      if (while_flag_1259) {
                                        uint8_t id_1264 { 0 };
                                        ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1265 { inits_src_ref_104[id_1264] };
                                        {
                                          ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_106 { id_1265 };
                                          {
                                            auto dlist2_fst_107 { std::get<0>(dlist2_106) };
                                            auto dlist2_snd_108 { std::get<1>(dlist2_106) };
                                            uint8_t id_1266 { 0 };
                                            auto fun1267 { dessser::gen::field_name::of_row_binary };
                                            ::dessser::gen::source_info::t18cecf882d7ac80cef37dfe6b22279d4 id_1268 { fun1267(dlist2_snd_108) };
                                            ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1269;
                                            {
                                              auto dlist3_fst_110 { std::get<0>(id_1268) };
                                              auto dlist3_snd_111 { std::get<1>(id_1268) };
                                              Lst<dessser::gen::field_name::t_ext> id_1270 { dlist3_fst_110, dlist2_fst_107 };
                                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1271 { id_1270, dlist3_snd_111 };
                                              letpair_res_1269 = id_1271;
                                            }
                                            Void id_1272 { ((void)(inits_src_ref_104[id_1266] = letpair_res_1269), ::dessser::VOID) };
                                            (void)id_1272;
                                          }
                                          (void)::dessser::VOID;
                                        }
                                        (void)::dessser::VOID;
                                        uint8_t id_1273 { 0 };
                                        uint8_t id_1274 { 0 };
                                        int32_t id_1275 { repeat_n_105[id_1274] };
                                        int32_t id_1276 { 1L };
                                        int32_t id_1277 { int32_t(id_1275 + id_1276) };
                                        Void id_1278 { ((void)(repeat_n_105[id_1273] = id_1277), ::dessser::VOID) };
                                        (void)id_1278;
                                        (void)id_1278;
                                      }
                                    } while (while_flag_1259);
                                    (void)::dessser::VOID;
                                  }
                                  (void)::dessser::VOID;
                                  uint8_t id_1279 { 0 };
                                  ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1280 { inits_src_ref_104[id_1279] };
                                  let_res_1256 = id_1280;
                                }
                                letpair_res_1252 = let_res_1256;
                              }
                              let_res_1251 = letpair_res_1252;
                            }
                            ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_1281;
                            {
                              auto dlist4_fst_113 { std::get<0>(let_res_1251) };
                              auto dlist4_snd_114 { std::get<1>(let_res_1251) };
                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_1282 { dlist4_fst_113, dlist4_snd_114 };
                              letpair_res_1281 = id_1282;
                            }
                            ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1283;
                            {
                              ::dessser::gen::source_info::tae4ac4fd187cdebd0a4f6d30f229fbc5 drec_115 { letpair_res_1281 };
                              ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1284;
                              {
                                auto drec_fst_116 { std::get<0>(drec_115) };
                                auto drec_snd_117 { std::get<1>(drec_115) };
                                uint32_t id_1285 { 0U };
                                Vec<1, uint32_t> id_1286 {  id_1285  };
                                ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1287;
                                {
                                  Vec<1, uint32_t> leb_ref_118 { id_1286 };
                                  uint8_t id_1288 { 0 };
                                  Vec<1, uint8_t> id_1289 {  id_1288  };
                                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1290;
                                  {
                                    Vec<1, uint8_t> shft_ref_119 { id_1289 };
                                    Vec<1, Pointer> id_1291 {  drec_snd_117  };
                                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1292;
                                    {
                                      Vec<1, Pointer> p_ref_120 { id_1291 };
                                      bool while_flag_1293 { true };
                                      do {
                                        uint8_t id_1294 { 0 };
                                        Pointer id_1295 { p_ref_120[id_1294] };
                                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1296 { id_1295.readU8() };
                                        bool let_res_1297;
                                        {
                                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_121 { id_1296 };
                                          bool letpair_res_1298;
                                          {
                                            auto leb128_fst_122 { std::get<0>(leb128_121) };
                                            auto leb128_snd_123 { std::get<1>(leb128_121) };
                                            uint8_t id_1299 { 0 };
                                            Void id_1300 { ((void)(p_ref_120[id_1299] = leb128_snd_123), ::dessser::VOID) };
                                            (void)id_1300;
                                            uint8_t id_1301 { 0 };
                                            uint8_t id_1302 { 127 };
                                            uint8_t id_1303 { uint8_t(leb128_fst_122 & id_1302) };
                                            uint32_t id_1304 { uint32_t(id_1303) };
                                            uint8_t id_1305 { 0 };
                                            uint8_t id_1306 { shft_ref_119[id_1305] };
                                            uint32_t id_1307 { uint32_t(id_1304 << id_1306) };
                                            uint8_t id_1308 { 0 };
                                            uint32_t id_1309 { leb_ref_118[id_1308] };
                                            uint32_t id_1310 { uint32_t(id_1307 | id_1309) };
                                            Void id_1311 { ((void)(leb_ref_118[id_1301] = id_1310), ::dessser::VOID) };
                                            (void)id_1311;
                                            uint8_t id_1312 { 0 };
                                            uint8_t id_1313 { 0 };
                                            uint8_t id_1314 { shft_ref_119[id_1313] };
                                            uint8_t id_1315 { 7 };
                                            uint8_t id_1316 { uint8_t(id_1314 + id_1315) };
                                            Void id_1317 { ((void)(shft_ref_119[id_1312] = id_1316), ::dessser::VOID) };
                                            (void)id_1317;
                                            uint8_t id_1318 { 128 };
                                            bool id_1319 { bool(leb128_fst_122 >= id_1318) };
                                            letpair_res_1298 = id_1319;
                                          }
                                          let_res_1297 = letpair_res_1298;
                                        }
                                        while_flag_1293 = let_res_1297;
                                        if (while_flag_1293) {
                                          (void)::dessser::VOID;
                                        }
                                      } while (while_flag_1293);
                                      (void)::dessser::VOID;
                                      uint8_t id_1320 { 0 };
                                      uint32_t id_1321 { leb_ref_118[id_1320] };
                                      Size id_1322 { Size(id_1321) };
                                      uint8_t id_1323 { 0 };
                                      Pointer id_1324 { p_ref_120[id_1323] };
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1325 { id_1322, id_1324 };
                                      let_res_1292 = id_1325;
                                    }
                                    let_res_1290 = let_res_1292;
                                  }
                                  let_res_1287 = let_res_1290;
                                }
                                ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1326;
                                {
                                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_124 { let_res_1287 };
                                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1327;
                                  {
                                    auto dstring1_fst_125 { std::get<0>(dstring1_124) };
                                    auto dstring1_snd_126 { std::get<1>(dstring1_124) };
                                    ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1328 { dstring1_snd_126.readBytes(dstring1_fst_125) };
                                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1329;
                                    {
                                      auto dstring2_fst_128 { std::get<0>(id_1328) };
                                      auto dstring2_snd_129 { std::get<1>(id_1328) };
                                      std::string id_1330 { dstring2_fst_128.toString() };
                                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1331 { id_1330, dstring2_snd_129 };
                                      letpair_res_1329 = id_1331;
                                    }
                                    letpair_res_1327 = letpair_res_1329;
                                  }
                                  let_res_1326 = letpair_res_1327;
                                }
                                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1332;
                                {
                                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_130 { let_res_1326 };
                                  ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1333;
                                  {
                                    auto drec_fst_131 { std::get<0>(drec_130) };
                                    auto drec_snd_132 { std::get<1>(drec_130) };
                                    uint32_t id_1334 { 0U };
                                    Vec<1, uint32_t> id_1335 {  id_1334  };
                                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1336;
                                    {
                                      Vec<1, uint32_t> leb_ref_133 { id_1335 };
                                      uint8_t id_1337 { 0 };
                                      Vec<1, uint8_t> id_1338 {  id_1337  };
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1339;
                                      {
                                        Vec<1, uint8_t> shft_ref_134 { id_1338 };
                                        Vec<1, Pointer> id_1340 {  drec_snd_132  };
                                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1341;
                                        {
                                          Vec<1, Pointer> p_ref_135 { id_1340 };
                                          bool while_flag_1342 { true };
                                          do {
                                            uint8_t id_1343 { 0 };
                                            Pointer id_1344 { p_ref_135[id_1343] };
                                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1345 { id_1344.readU8() };
                                            bool let_res_1346;
                                            {
                                              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_136 { id_1345 };
                                              bool letpair_res_1347;
                                              {
                                                auto leb128_fst_137 { std::get<0>(leb128_136) };
                                                auto leb128_snd_138 { std::get<1>(leb128_136) };
                                                uint8_t id_1348 { 0 };
                                                Void id_1349 { ((void)(p_ref_135[id_1348] = leb128_snd_138), ::dessser::VOID) };
                                                (void)id_1349;
                                                uint8_t id_1350 { 0 };
                                                uint8_t id_1351 { 127 };
                                                uint8_t id_1352 { uint8_t(leb128_fst_137 & id_1351) };
                                                uint32_t id_1353 { uint32_t(id_1352) };
                                                uint8_t id_1354 { 0 };
                                                uint8_t id_1355 { shft_ref_134[id_1354] };
                                                uint32_t id_1356 { uint32_t(id_1353 << id_1355) };
                                                uint8_t id_1357 { 0 };
                                                uint32_t id_1358 { leb_ref_133[id_1357] };
                                                uint32_t id_1359 { uint32_t(id_1356 | id_1358) };
                                                Void id_1360 { ((void)(leb_ref_133[id_1350] = id_1359), ::dessser::VOID) };
                                                (void)id_1360;
                                                uint8_t id_1361 { 0 };
                                                uint8_t id_1362 { 0 };
                                                uint8_t id_1363 { shft_ref_134[id_1362] };
                                                uint8_t id_1364 { 7 };
                                                uint8_t id_1365 { uint8_t(id_1363 + id_1364) };
                                                Void id_1366 { ((void)(shft_ref_134[id_1361] = id_1365), ::dessser::VOID) };
                                                (void)id_1366;
                                                uint8_t id_1367 { 128 };
                                                bool id_1368 { bool(leb128_fst_137 >= id_1367) };
                                                letpair_res_1347 = id_1368;
                                              }
                                              let_res_1346 = letpair_res_1347;
                                            }
                                            while_flag_1342 = let_res_1346;
                                            if (while_flag_1342) {
                                              (void)::dessser::VOID;
                                            }
                                          } while (while_flag_1342);
                                          (void)::dessser::VOID;
                                          uint8_t id_1369 { 0 };
                                          uint32_t id_1370 { leb_ref_133[id_1369] };
                                          Size id_1371 { Size(id_1370) };
                                          uint8_t id_1372 { 0 };
                                          Pointer id_1373 { p_ref_135[id_1372] };
                                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1374 { id_1371, id_1373 };
                                          let_res_1341 = id_1374;
                                        }
                                        let_res_1339 = let_res_1341;
                                      }
                                      let_res_1336 = let_res_1339;
                                    }
                                    ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be let_res_1375;
                                    {
                                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_139 { let_res_1336 };
                                      ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1376;
                                      {
                                        auto dstring1_fst_140 { std::get<0>(dstring1_139) };
                                        auto dstring1_snd_141 { std::get<1>(dstring1_139) };
                                        ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1377 { dstring1_snd_141.readBytes(dstring1_fst_140) };
                                        ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be letpair_res_1378;
                                        {
                                          auto dstring2_fst_143 { std::get<0>(id_1377) };
                                          auto dstring2_snd_144 { std::get<1>(id_1377) };
                                          std::string id_1379 { dstring2_fst_143.toString() };
                                          std::shared_ptr<::dessser::gen::source_info::compiled_func>  id_1380 { std::make_shared<::dessser::gen::source_info::compiled_func>(drec_fst_57, drec_fst_63, drec_fst_69, drec_fst_84, drec_fst_87, drec_fst_90, drec_fst_116, drec_fst_131, id_1379) };
                                          ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be id_1381 { id_1380, dstring2_snd_144 };
                                          letpair_res_1378 = id_1381;
                                        }
                                        letpair_res_1376 = letpair_res_1378;
                                      }
                                      let_res_1375 = letpair_res_1376;
                                    }
                                    letpair_res_1333 = let_res_1375;
                                  }
                                  let_res_1332 = letpair_res_1333;
                                }
                                letpair_res_1284 = let_res_1332;
                              }
                              let_res_1283 = letpair_res_1284;
                            }
                            letpair_res_1210 = let_res_1283;
                          }
                          let_res_1209 = letpair_res_1210;
                        }
                        letpair_res_1206 = let_res_1209;
                      }
                      let_res_1205 = letpair_res_1206;
                    }
                    letpair_res_1202 = let_res_1205;
                  }
                  let_res_1201 = letpair_res_1202;
                }
                letpair_res_1153 = let_res_1201;
              }
              let_res_1152 = letpair_res_1153;
            }
            letpair_res_1145 = let_res_1152;
          }
          let_res_1144 = letpair_res_1145;
        }
        letpair_res_1127 = let_res_1144;
      }
      let_res_1126 = letpair_res_1127;
    }
    return let_res_1126;
  }
   };
  return fun1123;
}
std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> compiled_func_of_row_binary(compiled_func_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_171"
        (let-pair "dlist4_fst_169" "dlist4_snd_170"
          (let "dlist1_157"
            (let "leb_ref_148" (make-vec (u32 0))
              (let "shft_ref_149" (make-vec (u8 0))
                (let "p_ref_150" (make-vec (param 0))
                  (seq
                    (while
                      (let "leb128_151" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_150")))
                        (let-pair "leb128_fst_152" "leb128_snd_153" (identifier "leb128_151")
                          (seq (set-vec (u8 0) (identifier "p_ref_150") (identifier "leb128_snd_153"))
                            (set-vec (u8 0) (identifier "leb_ref_148")
                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_152") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_149"))) (unsafe-nth (u8 0) (identifier "leb_ref_148"))))
                            (set-vec (u8 0) (identifier "shft_ref_149") (add (unsafe-nth (u8 0) (identifier "shft_ref_149")) (u8 7))) 
                            (ge (identifier "leb128_fst_152") (u8 128))))) 
                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_148")) (unsafe-nth (u8 0) (identifier "p_ref_150")))))))
            (let-pair "dlist1_fst_158" "dlist1_snd_159" (identifier "dlist1_157")
              (let "inits_src_ref_160" (make-vec (make-tup (end-of-list "$program_parameter") (identifier "dlist1_snd_159")))
                (seq
                  (let "repeat_n_161" (make-vec (i32 0))
                    (while (gt (to-i32 (identifier "dlist1_fst_158")) (unsafe-nth (u8 0) (identifier "repeat_n_161")))
                      (seq
                        (let "dlist2_162" (unsafe-nth (u8 0) (identifier "inits_src_ref_160"))
                          (let-pair "dlist2_fst_163" "dlist2_snd_164" 
                            (identifier "dlist2_162")
                            (set-vec (u8 0) (identifier "inits_src_ref_160")
                              (let-pair "dlist3_fst_166" "dlist3_snd_167" 
                                (apply (ext-identifier program_parameter of-row-binary) (identifier "dlist2_snd_164")) 
                                (make-tup (cons (identifier "dlist3_fst_166") (identifier "dlist2_fst_163")) (identifier "dlist3_snd_167"))))))
                        (set-vec (u8 0) (identifier "repeat_n_161") (add (unsafe-nth (u8 0) (identifier "repeat_n_161")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "inits_src_ref_160")))))) 
          (make-tup (identity (identifier "dlist4_fst_169")) (identifier "dlist4_snd_170")))
        (let-pair "drec_fst_172" "drec_snd_173" (identifier "drec_171")
          (let "drec_174" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_173"))
            (let-pair "drec_fst_175" "drec_snd_176" (identifier "drec_174")
              (let "drec_200"
                (let-pair "dlist4_fst_198" "dlist4_snd_199"
                  (let "dlist1_186"
                    (let "leb_ref_177" (make-vec (u32 0))
                      (let "shft_ref_178" (make-vec (u8 0))
                        (let "p_ref_179" (make-vec (identifier "drec_snd_176"))
                          (seq
                            (while
                              (let "leb128_180" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_179")))
                                (let-pair "leb128_fst_181" "leb128_snd_182" 
                                  (identifier "leb128_180")
                                  (seq (set-vec (u8 0) (identifier "p_ref_179") (identifier "leb128_snd_182"))
                                    (set-vec (u8 0) (identifier "leb_ref_177")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_181") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_178"))) (unsafe-nth (u8 0) (identifier "leb_ref_177"))))
                                    (set-vec (u8 0) (identifier "shft_ref_178") (add (unsafe-nth (u8 0) (identifier "shft_ref_178")) (u8 7))) 
                                    (ge (identifier "leb128_fst_181") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_177")) (unsafe-nth (u8 0) (identifier "p_ref_179")))))))
                    (let-pair "dlist1_fst_187" "dlist1_snd_188" (identifier "dlist1_186")
                      (let "inits_src_ref_189" (make-vec (make-tup (end-of-list "$global_variable") (identifier "dlist1_snd_188")))
                        (seq
                          (let "repeat_n_190" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_187")) (unsafe-nth (u8 0) (identifier "repeat_n_190")))
                              (seq
                                (let "dlist2_191" (unsafe-nth (u8 0) (identifier "inits_src_ref_189"))
                                  (let-pair "dlist2_fst_192" "dlist2_snd_193" 
                                    (identifier "dlist2_191")
                                    (set-vec (u8 0) (identifier "inits_src_ref_189")
                                      (let-pair "dlist3_fst_195" "dlist3_snd_196" 
                                        (apply (ext-identifier global_variable of-row-binary) (identifier "dlist2_snd_193"))
                                        (make-tup (cons (identifier "dlist3_fst_195") (identifier "dlist2_fst_192")) (identifier "dlist3_snd_196"))))))
                                (set-vec (u8 0) (identifier "repeat_n_190") (add (unsafe-nth (u8 0) (identifier "repeat_n_190")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_189")))))) 
                  (make-tup (identity (identifier "dlist4_fst_198")) (identifier "dlist4_snd_199")))
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
                              (end-of-list "(compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})")
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
                                          (apply (identifier "compiled_func-of-row-binary") (identifier "dlist2_snd_219"))
                                          (make-tup (cons (identifier "dlist3_fst_221") (identifier "dlist2_fst_218")) (identifier "dlist3_snd_222"))))))
                                  (set-vec (u8 0) (identifier "repeat_n_216") (add (unsafe-nth (u8 0) (identifier "repeat_n_216")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "inits_src_ref_215"))))))
                    (make-tup
                      (make-rec (string "funcs") (identity (identifier "dlist4_fst_224")) 
                        (string "globals") (identifier "drec_fst_201") 
                        (string "condition") (identifier "drec_fst_175") 
                        (string "default_params") (identifier "drec_fst_172")) 
                      (identifier "dlist4_snd_225"))))))))))
 */
static std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> compiled_program_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> fun1382 { [&](Pointer p_0) {
    uint32_t id_1383 { 0U };
    Vec<1, uint32_t> id_1384 {  id_1383  };
    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1385;
    {
      Vec<1, uint32_t> leb_ref_148 { id_1384 };
      uint8_t id_1386 { 0 };
      Vec<1, uint8_t> id_1387 {  id_1386  };
      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1388;
      {
        Vec<1, uint8_t> shft_ref_149 { id_1387 };
        Vec<1, Pointer> id_1389 {  p_0  };
        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1390;
        {
          Vec<1, Pointer> p_ref_150 { id_1389 };
          bool while_flag_1391 { true };
          do {
            uint8_t id_1392 { 0 };
            Pointer id_1393 { p_ref_150[id_1392] };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1394 { id_1393.readU8() };
            bool let_res_1395;
            {
              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_151 { id_1394 };
              bool letpair_res_1396;
              {
                auto leb128_fst_152 { std::get<0>(leb128_151) };
                auto leb128_snd_153 { std::get<1>(leb128_151) };
                uint8_t id_1397 { 0 };
                Void id_1398 { ((void)(p_ref_150[id_1397] = leb128_snd_153), ::dessser::VOID) };
                (void)id_1398;
                uint8_t id_1399 { 0 };
                uint8_t id_1400 { 127 };
                uint8_t id_1401 { uint8_t(leb128_fst_152 & id_1400) };
                uint32_t id_1402 { uint32_t(id_1401) };
                uint8_t id_1403 { 0 };
                uint8_t id_1404 { shft_ref_149[id_1403] };
                uint32_t id_1405 { uint32_t(id_1402 << id_1404) };
                uint8_t id_1406 { 0 };
                uint32_t id_1407 { leb_ref_148[id_1406] };
                uint32_t id_1408 { uint32_t(id_1405 | id_1407) };
                Void id_1409 { ((void)(leb_ref_148[id_1399] = id_1408), ::dessser::VOID) };
                (void)id_1409;
                uint8_t id_1410 { 0 };
                uint8_t id_1411 { 0 };
                uint8_t id_1412 { shft_ref_149[id_1411] };
                uint8_t id_1413 { 7 };
                uint8_t id_1414 { uint8_t(id_1412 + id_1413) };
                Void id_1415 { ((void)(shft_ref_149[id_1410] = id_1414), ::dessser::VOID) };
                (void)id_1415;
                uint8_t id_1416 { 128 };
                bool id_1417 { bool(leb128_fst_152 >= id_1416) };
                letpair_res_1396 = id_1417;
              }
              let_res_1395 = letpair_res_1396;
            }
            while_flag_1391 = let_res_1395;
            if (while_flag_1391) {
              (void)::dessser::VOID;
            }
          } while (while_flag_1391);
          (void)::dessser::VOID;
          uint8_t id_1418 { 0 };
          uint32_t id_1419 { leb_ref_148[id_1418] };
          uint8_t id_1420 { 0 };
          Pointer id_1421 { p_ref_150[id_1420] };
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1422 { id_1419, id_1421 };
          let_res_1390 = id_1422;
        }
        let_res_1388 = let_res_1390;
      }
      let_res_1385 = let_res_1388;
    }
    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 let_res_1423;
    {
      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_157 { let_res_1385 };
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1424;
      {
        auto dlist1_fst_158 { std::get<0>(dlist1_157) };
        auto dlist1_snd_159 { std::get<1>(dlist1_157) };
        Lst<dessser::gen::program_parameter::t_ext> endoflist_1425;
        ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1426 { endoflist_1425, dlist1_snd_159 };
        Vec<1, ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800> id_1427 {  id_1426  };
        ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 let_res_1428;
        {
          Vec<1, ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800> inits_src_ref_160 { id_1427 };
          int32_t id_1429 { 0L };
          Vec<1, int32_t> id_1430 {  id_1429  };
          {
            Vec<1, int32_t> repeat_n_161 { id_1430 };
            bool while_flag_1431 { true };
            do {
              int32_t id_1432 { int32_t(dlist1_fst_158) };
              uint8_t id_1433 { 0 };
              int32_t id_1434 { repeat_n_161[id_1433] };
              bool id_1435 { bool(id_1432 > id_1434) };
              while_flag_1431 = id_1435;
              if (while_flag_1431) {
                uint8_t id_1436 { 0 };
                ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1437 { inits_src_ref_160[id_1436] };
                {
                  ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 dlist2_162 { id_1437 };
                  {
                    auto dlist2_fst_163 { std::get<0>(dlist2_162) };
                    auto dlist2_snd_164 { std::get<1>(dlist2_162) };
                    uint8_t id_1438 { 0 };
                    auto fun1439 { dessser::gen::program_parameter::of_row_binary };
                    ::dessser::gen::source_info::tbbb6e77f92131ca39155edc6f36a3063 id_1440 { fun1439(dlist2_snd_164) };
                    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1441;
                    {
                      auto dlist3_fst_166 { std::get<0>(id_1440) };
                      auto dlist3_snd_167 { std::get<1>(id_1440) };
                      Lst<dessser::gen::program_parameter::t_ext> id_1442 { dlist3_fst_166, dlist2_fst_163 };
                      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1443 { id_1442, dlist3_snd_167 };
                      letpair_res_1441 = id_1443;
                    }
                    Void id_1444 { ((void)(inits_src_ref_160[id_1438] = letpair_res_1441), ::dessser::VOID) };
                    (void)id_1444;
                  }
                  (void)::dessser::VOID;
                }
                (void)::dessser::VOID;
                uint8_t id_1445 { 0 };
                uint8_t id_1446 { 0 };
                int32_t id_1447 { repeat_n_161[id_1446] };
                int32_t id_1448 { 1L };
                int32_t id_1449 { int32_t(id_1447 + id_1448) };
                Void id_1450 { ((void)(repeat_n_161[id_1445] = id_1449), ::dessser::VOID) };
                (void)id_1450;
                (void)id_1450;
              }
            } while (while_flag_1431);
            (void)::dessser::VOID;
          }
          (void)::dessser::VOID;
          uint8_t id_1451 { 0 };
          ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1452 { inits_src_ref_160[id_1451] };
          let_res_1428 = id_1452;
        }
        letpair_res_1424 = let_res_1428;
      }
      let_res_1423 = letpair_res_1424;
    }
    ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 letpair_res_1453;
    {
      auto dlist4_fst_169 { std::get<0>(let_res_1423) };
      auto dlist4_snd_170 { std::get<1>(let_res_1423) };
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 id_1454 { dlist4_fst_169, dlist4_snd_170 };
      letpair_res_1453 = id_1454;
    }
    ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1455;
    {
      ::dessser::gen::source_info::t1882123c3b77d3ab876e6d0dd467e800 drec_171 { letpair_res_1453 };
      ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1456;
      {
        auto drec_fst_172 { std::get<0>(drec_171) };
        auto drec_snd_173 { std::get<1>(drec_171) };
        auto fun1457 { dessser::gen::raql_expr::of_row_binary };
        ::dessser::gen::source_info::tc473a3a3b5068e57b15e934d0afcc038 id_1458 { fun1457(drec_snd_173) };
        ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1459;
        {
          ::dessser::gen::source_info::tc473a3a3b5068e57b15e934d0afcc038 drec_174 { id_1458 };
          ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1460;
          {
            auto drec_fst_175 { std::get<0>(drec_174) };
            auto drec_snd_176 { std::get<1>(drec_174) };
            uint32_t id_1461 { 0U };
            Vec<1, uint32_t> id_1462 {  id_1461  };
            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1463;
            {
              Vec<1, uint32_t> leb_ref_177 { id_1462 };
              uint8_t id_1464 { 0 };
              Vec<1, uint8_t> id_1465 {  id_1464  };
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1466;
              {
                Vec<1, uint8_t> shft_ref_178 { id_1465 };
                Vec<1, Pointer> id_1467 {  drec_snd_176  };
                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1468;
                {
                  Vec<1, Pointer> p_ref_179 { id_1467 };
                  bool while_flag_1469 { true };
                  do {
                    uint8_t id_1470 { 0 };
                    Pointer id_1471 { p_ref_179[id_1470] };
                    ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1472 { id_1471.readU8() };
                    bool let_res_1473;
                    {
                      ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_180 { id_1472 };
                      bool letpair_res_1474;
                      {
                        auto leb128_fst_181 { std::get<0>(leb128_180) };
                        auto leb128_snd_182 { std::get<1>(leb128_180) };
                        uint8_t id_1475 { 0 };
                        Void id_1476 { ((void)(p_ref_179[id_1475] = leb128_snd_182), ::dessser::VOID) };
                        (void)id_1476;
                        uint8_t id_1477 { 0 };
                        uint8_t id_1478 { 127 };
                        uint8_t id_1479 { uint8_t(leb128_fst_181 & id_1478) };
                        uint32_t id_1480 { uint32_t(id_1479) };
                        uint8_t id_1481 { 0 };
                        uint8_t id_1482 { shft_ref_178[id_1481] };
                        uint32_t id_1483 { uint32_t(id_1480 << id_1482) };
                        uint8_t id_1484 { 0 };
                        uint32_t id_1485 { leb_ref_177[id_1484] };
                        uint32_t id_1486 { uint32_t(id_1483 | id_1485) };
                        Void id_1487 { ((void)(leb_ref_177[id_1477] = id_1486), ::dessser::VOID) };
                        (void)id_1487;
                        uint8_t id_1488 { 0 };
                        uint8_t id_1489 { 0 };
                        uint8_t id_1490 { shft_ref_178[id_1489] };
                        uint8_t id_1491 { 7 };
                        uint8_t id_1492 { uint8_t(id_1490 + id_1491) };
                        Void id_1493 { ((void)(shft_ref_178[id_1488] = id_1492), ::dessser::VOID) };
                        (void)id_1493;
                        uint8_t id_1494 { 128 };
                        bool id_1495 { bool(leb128_fst_181 >= id_1494) };
                        letpair_res_1474 = id_1495;
                      }
                      let_res_1473 = letpair_res_1474;
                    }
                    while_flag_1469 = let_res_1473;
                    if (while_flag_1469) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_1469);
                  (void)::dessser::VOID;
                  uint8_t id_1496 { 0 };
                  uint32_t id_1497 { leb_ref_177[id_1496] };
                  uint8_t id_1498 { 0 };
                  Pointer id_1499 { p_ref_179[id_1498] };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1500 { id_1497, id_1499 };
                  let_res_1468 = id_1500;
                }
                let_res_1466 = let_res_1468;
              }
              let_res_1463 = let_res_1466;
            }
            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 let_res_1501;
            {
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_186 { let_res_1463 };
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1502;
              {
                auto dlist1_fst_187 { std::get<0>(dlist1_186) };
                auto dlist1_snd_188 { std::get<1>(dlist1_186) };
                Lst<dessser::gen::global_variable::t_ext> endoflist_1503;
                ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1504 { endoflist_1503, dlist1_snd_188 };
                Vec<1, ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7> id_1505 {  id_1504  };
                ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 let_res_1506;
                {
                  Vec<1, ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7> inits_src_ref_189 { id_1505 };
                  int32_t id_1507 { 0L };
                  Vec<1, int32_t> id_1508 {  id_1507  };
                  {
                    Vec<1, int32_t> repeat_n_190 { id_1508 };
                    bool while_flag_1509 { true };
                    do {
                      int32_t id_1510 { int32_t(dlist1_fst_187) };
                      uint8_t id_1511 { 0 };
                      int32_t id_1512 { repeat_n_190[id_1511] };
                      bool id_1513 { bool(id_1510 > id_1512) };
                      while_flag_1509 = id_1513;
                      if (while_flag_1509) {
                        uint8_t id_1514 { 0 };
                        ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1515 { inits_src_ref_189[id_1514] };
                        {
                          ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 dlist2_191 { id_1515 };
                          {
                            auto dlist2_fst_192 { std::get<0>(dlist2_191) };
                            auto dlist2_snd_193 { std::get<1>(dlist2_191) };
                            uint8_t id_1516 { 0 };
                            auto fun1517 { dessser::gen::global_variable::of_row_binary };
                            ::dessser::gen::source_info::t40a6bf0f8e6a7b21bd5b768113e20619 id_1518 { fun1517(dlist2_snd_193) };
                            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1519;
                            {
                              auto dlist3_fst_195 { std::get<0>(id_1518) };
                              auto dlist3_snd_196 { std::get<1>(id_1518) };
                              Lst<dessser::gen::global_variable::t_ext> id_1520 { dlist3_fst_195, dlist2_fst_192 };
                              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1521 { id_1520, dlist3_snd_196 };
                              letpair_res_1519 = id_1521;
                            }
                            Void id_1522 { ((void)(inits_src_ref_189[id_1516] = letpair_res_1519), ::dessser::VOID) };
                            (void)id_1522;
                          }
                          (void)::dessser::VOID;
                        }
                        (void)::dessser::VOID;
                        uint8_t id_1523 { 0 };
                        uint8_t id_1524 { 0 };
                        int32_t id_1525 { repeat_n_190[id_1524] };
                        int32_t id_1526 { 1L };
                        int32_t id_1527 { int32_t(id_1525 + id_1526) };
                        Void id_1528 { ((void)(repeat_n_190[id_1523] = id_1527), ::dessser::VOID) };
                        (void)id_1528;
                        (void)id_1528;
                      }
                    } while (while_flag_1509);
                    (void)::dessser::VOID;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_1529 { 0 };
                  ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1530 { inits_src_ref_189[id_1529] };
                  let_res_1506 = id_1530;
                }
                letpair_res_1502 = let_res_1506;
              }
              let_res_1501 = letpair_res_1502;
            }
            ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 letpair_res_1531;
            {
              auto dlist4_fst_198 { std::get<0>(let_res_1501) };
              auto dlist4_snd_199 { std::get<1>(let_res_1501) };
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 id_1532 { dlist4_fst_198, dlist4_snd_199 };
              letpair_res_1531 = id_1532;
            }
            ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 let_res_1533;
            {
              ::dessser::gen::source_info::tb460ebd1a257a89e5c8d619ba39de2a7 drec_200 { letpair_res_1531 };
              ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1534;
              {
                auto drec_fst_201 { std::get<0>(drec_200) };
                auto drec_snd_202 { std::get<1>(drec_200) };
                uint32_t id_1535 { 0U };
                Vec<1, uint32_t> id_1536 {  id_1535  };
                ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1537;
                {
                  Vec<1, uint32_t> leb_ref_203 { id_1536 };
                  uint8_t id_1538 { 0 };
                  Vec<1, uint8_t> id_1539 {  id_1538  };
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1540;
                  {
                    Vec<1, uint8_t> shft_ref_204 { id_1539 };
                    Vec<1, Pointer> id_1541 {  drec_snd_202  };
                    ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1542;
                    {
                      Vec<1, Pointer> p_ref_205 { id_1541 };
                      bool while_flag_1543 { true };
                      do {
                        uint8_t id_1544 { 0 };
                        Pointer id_1545 { p_ref_205[id_1544] };
                        ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1546 { id_1545.readU8() };
                        bool let_res_1547;
                        {
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_206 { id_1546 };
                          bool letpair_res_1548;
                          {
                            auto leb128_fst_207 { std::get<0>(leb128_206) };
                            auto leb128_snd_208 { std::get<1>(leb128_206) };
                            uint8_t id_1549 { 0 };
                            Void id_1550 { ((void)(p_ref_205[id_1549] = leb128_snd_208), ::dessser::VOID) };
                            (void)id_1550;
                            uint8_t id_1551 { 0 };
                            uint8_t id_1552 { 127 };
                            uint8_t id_1553 { uint8_t(leb128_fst_207 & id_1552) };
                            uint32_t id_1554 { uint32_t(id_1553) };
                            uint8_t id_1555 { 0 };
                            uint8_t id_1556 { shft_ref_204[id_1555] };
                            uint32_t id_1557 { uint32_t(id_1554 << id_1556) };
                            uint8_t id_1558 { 0 };
                            uint32_t id_1559 { leb_ref_203[id_1558] };
                            uint32_t id_1560 { uint32_t(id_1557 | id_1559) };
                            Void id_1561 { ((void)(leb_ref_203[id_1551] = id_1560), ::dessser::VOID) };
                            (void)id_1561;
                            uint8_t id_1562 { 0 };
                            uint8_t id_1563 { 0 };
                            uint8_t id_1564 { shft_ref_204[id_1563] };
                            uint8_t id_1565 { 7 };
                            uint8_t id_1566 { uint8_t(id_1564 + id_1565) };
                            Void id_1567 { ((void)(shft_ref_204[id_1562] = id_1566), ::dessser::VOID) };
                            (void)id_1567;
                            uint8_t id_1568 { 128 };
                            bool id_1569 { bool(leb128_fst_207 >= id_1568) };
                            letpair_res_1548 = id_1569;
                          }
                          let_res_1547 = letpair_res_1548;
                        }
                        while_flag_1543 = let_res_1547;
                        if (while_flag_1543) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_1543);
                      (void)::dessser::VOID;
                      uint8_t id_1570 { 0 };
                      uint32_t id_1571 { leb_ref_203[id_1570] };
                      uint8_t id_1572 { 0 };
                      Pointer id_1573 { p_ref_205[id_1572] };
                      ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1574 { id_1571, id_1573 };
                      let_res_1542 = id_1574;
                    }
                    let_res_1540 = let_res_1542;
                  }
                  let_res_1537 = let_res_1540;
                }
                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 let_res_1575;
                {
                  ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_212 { let_res_1537 };
                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1576;
                  {
                    auto dlist1_fst_213 { std::get<0>(dlist1_212) };
                    auto dlist1_snd_214 { std::get<1>(dlist1_212) };
                    Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > endoflist_1577;
                    ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1578 { endoflist_1577, dlist1_snd_214 };
                    Vec<1, ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47> id_1579 {  id_1578  };
                    ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 let_res_1580;
                    {
                      Vec<1, ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47> inits_src_ref_215 { id_1579 };
                      int32_t id_1581 { 0L };
                      Vec<1, int32_t> id_1582 {  id_1581  };
                      {
                        Vec<1, int32_t> repeat_n_216 { id_1582 };
                        bool while_flag_1583 { true };
                        do {
                          int32_t id_1584 { int32_t(dlist1_fst_213) };
                          uint8_t id_1585 { 0 };
                          int32_t id_1586 { repeat_n_216[id_1585] };
                          bool id_1587 { bool(id_1584 > id_1586) };
                          while_flag_1583 = id_1587;
                          if (while_flag_1583) {
                            uint8_t id_1588 { 0 };
                            ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1589 { inits_src_ref_215[id_1588] };
                            {
                              ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 dlist2_217 { id_1589 };
                              {
                                auto dlist2_fst_218 { std::get<0>(dlist2_217) };
                                auto dlist2_snd_219 { std::get<1>(dlist2_217) };
                                uint8_t id_1590 { 0 };
                                ::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be id_1591 { compiled_func_of_row_binary(dlist2_snd_219) };
                                ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 letpair_res_1592;
                                {
                                  auto dlist3_fst_221 { std::get<0>(id_1591) };
                                  auto dlist3_snd_222 { std::get<1>(id_1591) };
                                  Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > id_1593 { dlist3_fst_221, dlist2_fst_218 };
                                  ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1594 { id_1593, dlist3_snd_222 };
                                  letpair_res_1592 = id_1594;
                                }
                                Void id_1595 { ((void)(inits_src_ref_215[id_1590] = letpair_res_1592), ::dessser::VOID) };
                                (void)id_1595;
                              }
                              (void)::dessser::VOID;
                            }
                            (void)::dessser::VOID;
                            uint8_t id_1596 { 0 };
                            uint8_t id_1597 { 0 };
                            int32_t id_1598 { repeat_n_216[id_1597] };
                            int32_t id_1599 { 1L };
                            int32_t id_1600 { int32_t(id_1598 + id_1599) };
                            Void id_1601 { ((void)(repeat_n_216[id_1596] = id_1600), ::dessser::VOID) };
                            (void)id_1601;
                            (void)id_1601;
                          }
                        } while (while_flag_1583);
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_1602 { 0 };
                      ::dessser::gen::source_info::t1c57319406adeaa4ba598b4a352fcb47 id_1603 { inits_src_ref_215[id_1602] };
                      let_res_1580 = id_1603;
                    }
                    letpair_res_1576 = let_res_1580;
                  }
                  let_res_1575 = letpair_res_1576;
                }
                ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 letpair_res_1604;
                {
                  auto dlist4_fst_224 { std::get<0>(let_res_1575) };
                  auto dlist4_snd_225 { std::get<1>(let_res_1575) };
                  std::shared_ptr<::dessser::gen::source_info::compiled_program>  id_1605 { std::make_shared<::dessser::gen::source_info::compiled_program>(drec_fst_172, drec_fst_175, drec_fst_201, dlist4_fst_224) };
                  ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 id_1606 { id_1605, dlist4_snd_225 };
                  letpair_res_1604 = id_1606;
                }
                letpair_res_1534 = letpair_res_1604;
              }
              let_res_1533 = letpair_res_1534;
            }
            letpair_res_1460 = let_res_1533;
          }
          let_res_1459 = letpair_res_1460;
        }
        letpair_res_1456 = let_res_1459;
      }
      let_res_1455 = letpair_res_1456;
    }
    return let_res_1455;
  }
   };
  return fun1382;
}
std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> compiled_program_of_row_binary(compiled_program_of_row_binary_init());

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
          (let "drec_279"
            (let-pair "dlist4_fst_277" "dlist4_snd_278"
              (let "dlist1_253"
                (let "leb_ref_244" (make-vec (u32 0))
                  (let "shft_ref_245" (make-vec (u8 0))
                    (let "p_ref_246" (make-vec (identifier "drec_snd_243"))
                      (seq
                        (while
                          (let "leb128_247" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_246")))
                            (let-pair "leb128_fst_248" "leb128_snd_249" 
                              (identifier "leb128_247")
                              (seq (set-vec (u8 0) (identifier "p_ref_246") (identifier "leb128_snd_249"))
                                (set-vec (u8 0) (identifier "leb_ref_244")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_248") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_245"))) (unsafe-nth (u8 0) (identifier "leb_ref_244"))))
                                (set-vec (u8 0) (identifier "shft_ref_245") (add (unsafe-nth (u8 0) (identifier "shft_ref_245")) (u8 7))) 
                                (ge (identifier "leb128_fst_248") (u8 128))))) 
                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_244")) (unsafe-nth (u8 0) (identifier "p_ref_246")))))))
                (let-pair "dlist1_fst_254" "dlist1_snd_255" (identifier "dlist1_253")
                  (let "inits_src_ref_256" (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_255")))
                    (seq
                      (let "repeat_n_257" (make-vec (i32 0))
                        (while (gt (to-i32 (identifier "dlist1_fst_254")) (unsafe-nth (u8 0) (identifier "repeat_n_257")))
                          (seq
                            (let "dlist2_258" (unsafe-nth (u8 0) (identifier "inits_src_ref_256"))
                              (let-pair "dlist2_fst_259" "dlist2_snd_260" 
                                (identifier "dlist2_258")
                                (set-vec (u8 0) (identifier "inits_src_ref_256")
                                  (let "dstring1_267"
                                    (let "leb_ref_261" (make-vec (u32 0))
                                      (let "shft_ref_262" (make-vec (u8 0))
                                        (let "p_ref_263" (make-vec (identifier "dlist2_snd_260"))
                                          (seq
                                            (while
                                              (let "leb128_264" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_263")))
                                                (let-pair "leb128_fst_265" "leb128_snd_266" 
                                                  (identifier "leb128_264")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_263") (identifier "leb128_snd_266"))
                                                    (set-vec (u8 0) (identifier "leb_ref_261")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_265") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_262"))) (unsafe-nth (u8 0) (identifier "leb_ref_261"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_262") (add (unsafe-nth (u8 0) (identifier "shft_ref_262")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_265") (u8 128))))) 
                                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_261"))) (unsafe-nth (u8 0) (identifier "p_ref_263")))))))
                                    (let-pair "dstring1_fst_268" "dstring1_snd_269" 
                                      (identifier "dstring1_267")
                                      (let-pair "dstring2_fst_271" "dstring2_snd_272" 
                                        (read-bytes (identifier "dstring1_snd_269") (identifier "dstring1_fst_268"))
                                        (make-tup (cons (string-of-bytes (identifier "dstring2_fst_271")) (identifier "dlist2_fst_259")) (identifier "dstring2_snd_272"))))))))
                            (set-vec (u8 0) (identifier "repeat_n_257") (add (unsafe-nth (u8 0) (identifier "repeat_n_257")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "inits_src_ref_256")))))) 
              (make-tup (identity (identifier "dlist4_fst_277")) (identifier "dlist4_snd_278")))
            (let-pair "drec_fst_280" "drec_snd_281" (identifier "drec_279")
              (let-pair "drec_fst_319" "drec_snd_320"
                (let "dsum1_288" (let-pair "du16_fst_283" "du16_snd_284" (read-u16 little-endian (identifier "drec_snd_281")) (make-tup (identifier "du16_fst_283") (identifier "du16_snd_284")))
                  (let-pair "dsum1_fst_289" "dsum1_snd_290" (identifier "dsum1_288")
                    (if (eq (u16 0) (identifier "dsum1_fst_289"))
                      (let-pair "dsum2_fst_316" "dsum2_snd_317" (apply (identifier "compiled_program-of-row-binary") (identifier "dsum1_snd_290"))
                        (make-tup
                          (construct "[Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]}) | Failed {err_msg: STRING; depends_on: $src_path?}]" 0
                            (identifier "dsum2_fst_316")) (identifier "dsum2_snd_317")))
                      (seq (assert (eq (identifier "dsum1_fst_289") (u16 1)))
                        (let "drec_303"
                          (let "dstring1_297"
                            (let "leb_ref_291" (make-vec (u32 0))
                              (let "shft_ref_292" (make-vec (u8 0))
                                (let "p_ref_293" (make-vec (identifier "dsum1_snd_290"))
                                  (seq
                                    (while
                                      (let "leb128_294" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_293")))
                                        (let-pair "leb128_fst_295" "leb128_snd_296" 
                                          (identifier "leb128_294")
                                          (seq (set-vec (u8 0) (identifier "p_ref_293") (identifier "leb128_snd_296"))
                                            (set-vec (u8 0) (identifier "leb_ref_291")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_295") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_292"))) (unsafe-nth (u8 0) (identifier "leb_ref_291"))))
                                            (set-vec (u8 0) (identifier "shft_ref_292") (add (unsafe-nth (u8 0) (identifier "shft_ref_292")) (u8 7))) 
                                            (ge (identifier "leb128_fst_295") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_291"))) (unsafe-nth (u8 0) (identifier "p_ref_293")))))))
                            (let-pair "dstring1_fst_298" "dstring1_snd_299" 
                              (identifier "dstring1_297")
                              (let-pair "dstring2_fst_301" "dstring2_snd_302" 
                                (read-bytes (identifier "dstring1_snd_299") (identifier "dstring1_fst_298")) 
                                (make-tup (string-of-bytes (identifier "dstring2_fst_301")) (identifier "dstring2_snd_302")))))
                          (let-pair "drec_fst_304" "drec_snd_305" (identifier "drec_303")
                            (let-pair "drec_fst_310" "drec_snd_311"
                              (if (eq (peek-u8 (identifier "drec_snd_305") (size 0)) (u8 1)) 
                                (make-tup (null "$src_path") (ptr-add (identifier "drec_snd_305") (size 1)))
                                (let-pair "make1_1_fst_307" "make1_1_snd_308" 
                                  (apply (ext-identifier src_path of-row-binary) (ptr-add (identifier "drec_snd_305") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_307")) (identifier "make1_1_snd_308"))))
                              (make-tup
                                (construct "[Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]}) | Failed {err_msg: STRING; depends_on: $src_path?}]" 1
                                  (make-rec (string "depends_on") (identifier "drec_fst_310") (string "err_msg") (identifier "drec_fst_304"))) 
                                (identifier "drec_snd_311")))))))))
                (make-tup (make-rec (string "detail") (identifier "drec_fst_319") (string "md5s") (identifier "drec_fst_280") (string "src_ext") (identifier "drec_fst_242")) (identifier "drec_snd_320"))))))))
 */
static std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> fun1607 { [&](Pointer p_0) {
    uint32_t id_1608 { 0U };
    Vec<1, uint32_t> id_1609 {  id_1608  };
    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1610;
    {
      Vec<1, uint32_t> leb_ref_229 { id_1609 };
      uint8_t id_1611 { 0 };
      Vec<1, uint8_t> id_1612 {  id_1611  };
      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1613;
      {
        Vec<1, uint8_t> shft_ref_230 { id_1612 };
        Vec<1, Pointer> id_1614 {  p_0  };
        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1615;
        {
          Vec<1, Pointer> p_ref_231 { id_1614 };
          bool while_flag_1616 { true };
          do {
            uint8_t id_1617 { 0 };
            Pointer id_1618 { p_ref_231[id_1617] };
            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1619 { id_1618.readU8() };
            bool let_res_1620;
            {
              ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_232 { id_1619 };
              bool letpair_res_1621;
              {
                auto leb128_fst_233 { std::get<0>(leb128_232) };
                auto leb128_snd_234 { std::get<1>(leb128_232) };
                uint8_t id_1622 { 0 };
                Void id_1623 { ((void)(p_ref_231[id_1622] = leb128_snd_234), ::dessser::VOID) };
                (void)id_1623;
                uint8_t id_1624 { 0 };
                uint8_t id_1625 { 127 };
                uint8_t id_1626 { uint8_t(leb128_fst_233 & id_1625) };
                uint32_t id_1627 { uint32_t(id_1626) };
                uint8_t id_1628 { 0 };
                uint8_t id_1629 { shft_ref_230[id_1628] };
                uint32_t id_1630 { uint32_t(id_1627 << id_1629) };
                uint8_t id_1631 { 0 };
                uint32_t id_1632 { leb_ref_229[id_1631] };
                uint32_t id_1633 { uint32_t(id_1630 | id_1632) };
                Void id_1634 { ((void)(leb_ref_229[id_1624] = id_1633), ::dessser::VOID) };
                (void)id_1634;
                uint8_t id_1635 { 0 };
                uint8_t id_1636 { 0 };
                uint8_t id_1637 { shft_ref_230[id_1636] };
                uint8_t id_1638 { 7 };
                uint8_t id_1639 { uint8_t(id_1637 + id_1638) };
                Void id_1640 { ((void)(shft_ref_230[id_1635] = id_1639), ::dessser::VOID) };
                (void)id_1640;
                uint8_t id_1641 { 128 };
                bool id_1642 { bool(leb128_fst_233 >= id_1641) };
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
          uint32_t id_1644 { leb_ref_229[id_1643] };
          Size id_1645 { Size(id_1644) };
          uint8_t id_1646 { 0 };
          Pointer id_1647 { p_ref_231[id_1646] };
          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1648 { id_1645, id_1647 };
          let_res_1615 = id_1648;
        }
        let_res_1613 = let_res_1615;
      }
      let_res_1610 = let_res_1613;
    }
    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1649;
    {
      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_235 { let_res_1610 };
      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1650;
      {
        auto dstring1_fst_236 { std::get<0>(dstring1_235) };
        auto dstring1_snd_237 { std::get<1>(dstring1_235) };
        ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1651 { dstring1_snd_237.readBytes(dstring1_fst_236) };
        ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1652;
        {
          auto dstring2_fst_239 { std::get<0>(id_1651) };
          auto dstring2_snd_240 { std::get<1>(id_1651) };
          std::string id_1653 { dstring2_fst_239.toString() };
          ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1654 { id_1653, dstring2_snd_240 };
          letpair_res_1652 = id_1654;
        }
        letpair_res_1650 = letpair_res_1652;
      }
      let_res_1649 = letpair_res_1650;
    }
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 let_res_1655;
    {
      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_241 { let_res_1649 };
      ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_1656;
      {
        auto drec_fst_242 { std::get<0>(drec_241) };
        auto drec_snd_243 { std::get<1>(drec_241) };
        uint32_t id_1657 { 0U };
        Vec<1, uint32_t> id_1658 {  id_1657  };
        ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1659;
        {
          Vec<1, uint32_t> leb_ref_244 { id_1658 };
          uint8_t id_1660 { 0 };
          Vec<1, uint8_t> id_1661 {  id_1660  };
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1662;
          {
            Vec<1, uint8_t> shft_ref_245 { id_1661 };
            Vec<1, Pointer> id_1663 {  drec_snd_243  };
            ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 let_res_1664;
            {
              Vec<1, Pointer> p_ref_246 { id_1663 };
              bool while_flag_1665 { true };
              do {
                uint8_t id_1666 { 0 };
                Pointer id_1667 { p_ref_246[id_1666] };
                ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1668 { id_1667.readU8() };
                bool let_res_1669;
                {
                  ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_247 { id_1668 };
                  bool letpair_res_1670;
                  {
                    auto leb128_fst_248 { std::get<0>(leb128_247) };
                    auto leb128_snd_249 { std::get<1>(leb128_247) };
                    uint8_t id_1671 { 0 };
                    Void id_1672 { ((void)(p_ref_246[id_1671] = leb128_snd_249), ::dessser::VOID) };
                    (void)id_1672;
                    uint8_t id_1673 { 0 };
                    uint8_t id_1674 { 127 };
                    uint8_t id_1675 { uint8_t(leb128_fst_248 & id_1674) };
                    uint32_t id_1676 { uint32_t(id_1675) };
                    uint8_t id_1677 { 0 };
                    uint8_t id_1678 { shft_ref_245[id_1677] };
                    uint32_t id_1679 { uint32_t(id_1676 << id_1678) };
                    uint8_t id_1680 { 0 };
                    uint32_t id_1681 { leb_ref_244[id_1680] };
                    uint32_t id_1682 { uint32_t(id_1679 | id_1681) };
                    Void id_1683 { ((void)(leb_ref_244[id_1673] = id_1682), ::dessser::VOID) };
                    (void)id_1683;
                    uint8_t id_1684 { 0 };
                    uint8_t id_1685 { 0 };
                    uint8_t id_1686 { shft_ref_245[id_1685] };
                    uint8_t id_1687 { 7 };
                    uint8_t id_1688 { uint8_t(id_1686 + id_1687) };
                    Void id_1689 { ((void)(shft_ref_245[id_1684] = id_1688), ::dessser::VOID) };
                    (void)id_1689;
                    uint8_t id_1690 { 128 };
                    bool id_1691 { bool(leb128_fst_248 >= id_1690) };
                    letpair_res_1670 = id_1691;
                  }
                  let_res_1669 = letpair_res_1670;
                }
                while_flag_1665 = let_res_1669;
                if (while_flag_1665) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_1665);
              (void)::dessser::VOID;
              uint8_t id_1692 { 0 };
              uint32_t id_1693 { leb_ref_244[id_1692] };
              uint8_t id_1694 { 0 };
              Pointer id_1695 { p_ref_246[id_1694] };
              ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 id_1696 { id_1693, id_1695 };
              let_res_1664 = id_1696;
            }
            let_res_1662 = let_res_1664;
          }
          let_res_1659 = let_res_1662;
        }
        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1697;
        {
          ::dessser::gen::source_info::t491c44439106a32f896827242e8e76a1 dlist1_253 { let_res_1659 };
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1698;
          {
            auto dlist1_fst_254 { std::get<0>(dlist1_253) };
            auto dlist1_snd_255 { std::get<1>(dlist1_253) };
            Lst<std::string> endoflist_1699;
            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1700 { endoflist_1699, dlist1_snd_255 };
            Vec<1, ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc> id_1701 {  id_1700  };
            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1702;
            {
              Vec<1, ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc> inits_src_ref_256 { id_1701 };
              int32_t id_1703 { 0L };
              Vec<1, int32_t> id_1704 {  id_1703  };
              {
                Vec<1, int32_t> repeat_n_257 { id_1704 };
                bool while_flag_1705 { true };
                do {
                  int32_t id_1706 { int32_t(dlist1_fst_254) };
                  uint8_t id_1707 { 0 };
                  int32_t id_1708 { repeat_n_257[id_1707] };
                  bool id_1709 { bool(id_1706 > id_1708) };
                  while_flag_1705 = id_1709;
                  if (while_flag_1705) {
                    uint8_t id_1710 { 0 };
                    ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1711 { inits_src_ref_256[id_1710] };
                    {
                      ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc dlist2_258 { id_1711 };
                      {
                        auto dlist2_fst_259 { std::get<0>(dlist2_258) };
                        auto dlist2_snd_260 { std::get<1>(dlist2_258) };
                        uint8_t id_1712 { 0 };
                        uint32_t id_1713 { 0U };
                        Vec<1, uint32_t> id_1714 {  id_1713  };
                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1715;
                        {
                          Vec<1, uint32_t> leb_ref_261 { id_1714 };
                          uint8_t id_1716 { 0 };
                          Vec<1, uint8_t> id_1717 {  id_1716  };
                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1718;
                          {
                            Vec<1, uint8_t> shft_ref_262 { id_1717 };
                            Vec<1, Pointer> id_1719 {  dlist2_snd_260  };
                            ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1720;
                            {
                              Vec<1, Pointer> p_ref_263 { id_1719 };
                              bool while_flag_1721 { true };
                              do {
                                uint8_t id_1722 { 0 };
                                Pointer id_1723 { p_ref_263[id_1722] };
                                ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1724 { id_1723.readU8() };
                                bool let_res_1725;
                                {
                                  ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_264 { id_1724 };
                                  bool letpair_res_1726;
                                  {
                                    auto leb128_fst_265 { std::get<0>(leb128_264) };
                                    auto leb128_snd_266 { std::get<1>(leb128_264) };
                                    uint8_t id_1727 { 0 };
                                    Void id_1728 { ((void)(p_ref_263[id_1727] = leb128_snd_266), ::dessser::VOID) };
                                    (void)id_1728;
                                    uint8_t id_1729 { 0 };
                                    uint8_t id_1730 { 127 };
                                    uint8_t id_1731 { uint8_t(leb128_fst_265 & id_1730) };
                                    uint32_t id_1732 { uint32_t(id_1731) };
                                    uint8_t id_1733 { 0 };
                                    uint8_t id_1734 { shft_ref_262[id_1733] };
                                    uint32_t id_1735 { uint32_t(id_1732 << id_1734) };
                                    uint8_t id_1736 { 0 };
                                    uint32_t id_1737 { leb_ref_261[id_1736] };
                                    uint32_t id_1738 { uint32_t(id_1735 | id_1737) };
                                    Void id_1739 { ((void)(leb_ref_261[id_1729] = id_1738), ::dessser::VOID) };
                                    (void)id_1739;
                                    uint8_t id_1740 { 0 };
                                    uint8_t id_1741 { 0 };
                                    uint8_t id_1742 { shft_ref_262[id_1741] };
                                    uint8_t id_1743 { 7 };
                                    uint8_t id_1744 { uint8_t(id_1742 + id_1743) };
                                    Void id_1745 { ((void)(shft_ref_262[id_1740] = id_1744), ::dessser::VOID) };
                                    (void)id_1745;
                                    uint8_t id_1746 { 128 };
                                    bool id_1747 { bool(leb128_fst_265 >= id_1746) };
                                    letpair_res_1726 = id_1747;
                                  }
                                  let_res_1725 = letpair_res_1726;
                                }
                                while_flag_1721 = let_res_1725;
                                if (while_flag_1721) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_1721);
                              (void)::dessser::VOID;
                              uint8_t id_1748 { 0 };
                              uint32_t id_1749 { leb_ref_261[id_1748] };
                              Size id_1750 { Size(id_1749) };
                              uint8_t id_1751 { 0 };
                              Pointer id_1752 { p_ref_263[id_1751] };
                              ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1753 { id_1750, id_1752 };
                              let_res_1720 = id_1753;
                            }
                            let_res_1718 = let_res_1720;
                          }
                          let_res_1715 = let_res_1718;
                        }
                        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc let_res_1754;
                        {
                          ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_267 { let_res_1715 };
                          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1755;
                          {
                            auto dstring1_fst_268 { std::get<0>(dstring1_267) };
                            auto dstring1_snd_269 { std::get<1>(dstring1_267) };
                            ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1756 { dstring1_snd_269.readBytes(dstring1_fst_268) };
                            ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1757;
                            {
                              auto dstring2_fst_271 { std::get<0>(id_1756) };
                              auto dstring2_snd_272 { std::get<1>(id_1756) };
                              std::string id_1758 { dstring2_fst_271.toString() };
                              Lst<std::string> id_1759 { id_1758, dlist2_fst_259 };
                              ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1760 { id_1759, dstring2_snd_272 };
                              letpair_res_1757 = id_1760;
                            }
                            letpair_res_1755 = letpair_res_1757;
                          }
                          let_res_1754 = letpair_res_1755;
                        }
                        Void id_1761 { ((void)(inits_src_ref_256[id_1712] = let_res_1754), ::dessser::VOID) };
                        (void)id_1761;
                      }
                      (void)::dessser::VOID;
                    }
                    (void)::dessser::VOID;
                    uint8_t id_1762 { 0 };
                    uint8_t id_1763 { 0 };
                    int32_t id_1764 { repeat_n_257[id_1763] };
                    int32_t id_1765 { 1L };
                    int32_t id_1766 { int32_t(id_1764 + id_1765) };
                    Void id_1767 { ((void)(repeat_n_257[id_1762] = id_1766), ::dessser::VOID) };
                    (void)id_1767;
                    (void)id_1767;
                  }
                } while (while_flag_1705);
                (void)::dessser::VOID;
              }
              (void)::dessser::VOID;
              uint8_t id_1768 { 0 };
              ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1769 { inits_src_ref_256[id_1768] };
              let_res_1702 = id_1769;
            }
            letpair_res_1698 = let_res_1702;
          }
          let_res_1697 = letpair_res_1698;
        }
        ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc letpair_res_1770;
        {
          auto dlist4_fst_277 { std::get<0>(let_res_1697) };
          auto dlist4_snd_278 { std::get<1>(let_res_1697) };
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc id_1771 { dlist4_fst_277, dlist4_snd_278 };
          letpair_res_1770 = id_1771;
        }
        ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 let_res_1772;
        {
          ::dessser::gen::source_info::t941fe844f492c6f2281f99ea362423fc drec_279 { letpair_res_1770 };
          ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_1773;
          {
            auto drec_fst_280 { std::get<0>(drec_279) };
            auto drec_snd_281 { std::get<1>(drec_279) };
            ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 id_1774 { drec_snd_281.readU16Le() };
            ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1775;
            {
              auto du16_fst_283 { std::get<0>(id_1774) };
              auto du16_snd_284 { std::get<1>(id_1774) };
              ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 id_1776 { du16_fst_283, du16_snd_284 };
              letpair_res_1775 = id_1776;
            }
            ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 let_res_1777;
            {
              ::dessser::gen::source_info::ta97bb48ed75bbda6173555873826c8c6 dsum1_288 { letpair_res_1775 };
              ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 letpair_res_1778;
              {
                auto dsum1_fst_289 { std::get<0>(dsum1_288) };
                auto dsum1_snd_290 { std::get<1>(dsum1_288) };
                uint16_t id_1779 { 0 };
                bool id_1780 { bool(id_1779 == dsum1_fst_289) };
                ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 choose_res_1781;
                if (id_1780) {
                  ::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0 id_1782 { compiled_program_of_row_binary(dsum1_snd_290) };
                  ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 letpair_res_1783;
                  {
                    auto dsum2_fst_316 { std::get<0>(id_1782) };
                    auto dsum2_snd_317 { std::get<1>(id_1782) };
                    ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1784 { std::in_place_index<0>, dsum2_fst_316 };
                    ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 id_1785 { id_1784, dsum2_snd_317 };
                    letpair_res_1783 = id_1785;
                  }
                  choose_res_1781 = letpair_res_1783;
                } else {
                  uint16_t id_1786 { 1 };
                  bool id_1787 { bool(dsum1_fst_289 == id_1786) };
                  Void id_1788 { ((void)(assert(id_1787)), ::dessser::VOID) };
                  (void)id_1788;
                  uint32_t id_1789 { 0U };
                  Vec<1, uint32_t> id_1790 {  id_1789  };
                  ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1791;
                  {
                    Vec<1, uint32_t> leb_ref_291 { id_1790 };
                    uint8_t id_1792 { 0 };
                    Vec<1, uint8_t> id_1793 {  id_1792  };
                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1794;
                    {
                      Vec<1, uint8_t> shft_ref_292 { id_1793 };
                      Vec<1, Pointer> id_1795 {  dsum1_snd_290  };
                      ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa let_res_1796;
                      {
                        Vec<1, Pointer> p_ref_293 { id_1795 };
                        bool while_flag_1797 { true };
                        do {
                          uint8_t id_1798 { 0 };
                          Pointer id_1799 { p_ref_293[id_1798] };
                          ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 id_1800 { id_1799.readU8() };
                          bool let_res_1801;
                          {
                            ::dessser::gen::source_info::t1a5d74abf838df33f185a72a8912f5c9 leb128_294 { id_1800 };
                            bool letpair_res_1802;
                            {
                              auto leb128_fst_295 { std::get<0>(leb128_294) };
                              auto leb128_snd_296 { std::get<1>(leb128_294) };
                              uint8_t id_1803 { 0 };
                              Void id_1804 { ((void)(p_ref_293[id_1803] = leb128_snd_296), ::dessser::VOID) };
                              (void)id_1804;
                              uint8_t id_1805 { 0 };
                              uint8_t id_1806 { 127 };
                              uint8_t id_1807 { uint8_t(leb128_fst_295 & id_1806) };
                              uint32_t id_1808 { uint32_t(id_1807) };
                              uint8_t id_1809 { 0 };
                              uint8_t id_1810 { shft_ref_292[id_1809] };
                              uint32_t id_1811 { uint32_t(id_1808 << id_1810) };
                              uint8_t id_1812 { 0 };
                              uint32_t id_1813 { leb_ref_291[id_1812] };
                              uint32_t id_1814 { uint32_t(id_1811 | id_1813) };
                              Void id_1815 { ((void)(leb_ref_291[id_1805] = id_1814), ::dessser::VOID) };
                              (void)id_1815;
                              uint8_t id_1816 { 0 };
                              uint8_t id_1817 { 0 };
                              uint8_t id_1818 { shft_ref_292[id_1817] };
                              uint8_t id_1819 { 7 };
                              uint8_t id_1820 { uint8_t(id_1818 + id_1819) };
                              Void id_1821 { ((void)(shft_ref_292[id_1816] = id_1820), ::dessser::VOID) };
                              (void)id_1821;
                              uint8_t id_1822 { 128 };
                              bool id_1823 { bool(leb128_fst_295 >= id_1822) };
                              letpair_res_1802 = id_1823;
                            }
                            let_res_1801 = letpair_res_1802;
                          }
                          while_flag_1797 = let_res_1801;
                          if (while_flag_1797) {
                            (void)::dessser::VOID;
                          }
                        } while (while_flag_1797);
                        (void)::dessser::VOID;
                        uint8_t id_1824 { 0 };
                        uint32_t id_1825 { leb_ref_291[id_1824] };
                        Size id_1826 { Size(id_1825) };
                        uint8_t id_1827 { 0 };
                        Pointer id_1828 { p_ref_293[id_1827] };
                        ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa id_1829 { id_1826, id_1828 };
                        let_res_1796 = id_1829;
                      }
                      let_res_1794 = let_res_1796;
                    }
                    let_res_1791 = let_res_1794;
                  }
                  ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 let_res_1830;
                  {
                    ::dessser::gen::source_info::t12fb9c475959b52bf7b17b155a955ffa dstring1_297 { let_res_1791 };
                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1831;
                    {
                      auto dstring1_fst_298 { std::get<0>(dstring1_297) };
                      auto dstring1_snd_299 { std::get<1>(dstring1_297) };
                      ::dessser::gen::source_info::t9ef6882174ae71a34a3c5ef6b29242fb id_1832 { dstring1_snd_299.readBytes(dstring1_fst_298) };
                      ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 letpair_res_1833;
                      {
                        auto dstring2_fst_301 { std::get<0>(id_1832) };
                        auto dstring2_snd_302 { std::get<1>(id_1832) };
                        std::string id_1834 { dstring2_fst_301.toString() };
                        ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 id_1835 { id_1834, dstring2_snd_302 };
                        letpair_res_1833 = id_1835;
                      }
                      letpair_res_1831 = letpair_res_1833;
                    }
                    let_res_1830 = letpair_res_1831;
                  }
                  ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 let_res_1836;
                  {
                    ::dessser::gen::source_info::t13a07ee37ab40962540da8534858dc07 drec_303 { let_res_1830 };
                    ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 letpair_res_1837;
                    {
                      auto drec_fst_304 { std::get<0>(drec_303) };
                      auto drec_snd_305 { std::get<1>(drec_303) };
                      Size id_1838 { 0UL };
                      uint8_t id_1839 { drec_snd_305.peekU8(id_1838) };
                      uint8_t id_1840 { 1 };
                      bool id_1841 { bool(id_1839 == id_1840) };
                      ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 choose_res_1842;
                      if (id_1841) {
                        std::optional<dessser::gen::src_path::t_ext> id_1843 { std::nullopt };
                        Size id_1844 { 1UL };
                        Pointer id_1845 { drec_snd_305.skip(id_1844) };
                        ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 id_1846 { id_1843, id_1845 };
                        choose_res_1842 = id_1846;
                      } else {
                        auto fun1847 { dessser::gen::src_path::of_row_binary };
                        Size id_1848 { 1UL };
                        Pointer id_1849 { drec_snd_305.skip(id_1848) };
                        ::dessser::gen::source_info::t6915129216bc7fcac0c82f38ea6cfec8 id_1850 { fun1847(id_1849) };
                        ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 letpair_res_1851;
                        {
                          auto make1_1_fst_307 { std::get<0>(id_1850) };
                          auto make1_1_snd_308 { std::get<1>(id_1850) };
                          std::optional<dessser::gen::src_path::t_ext> id_1852 { make1_1_fst_307 };
                          ::dessser::gen::source_info::t0d3a9bddef6e1883c4a75ebbb2e9dee7 id_1853 { id_1852, make1_1_snd_308 };
                          letpair_res_1851 = id_1853;
                        }
                        choose_res_1842 = letpair_res_1851;
                      }
                      ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 letpair_res_1854;
                      {
                        auto drec_fst_310 { std::get<0>(choose_res_1842) };
                        auto drec_snd_311 { std::get<1>(choose_res_1842) };
                        ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a id_1855 { drec_fst_304, drec_fst_310 };
                        ::dessser::gen::source_info::t01907297530734eeb2fea6f30cc7354a id_1856 { std::in_place_index<1>, id_1855 };
                        ::dessser::gen::source_info::t1dbe46d793a5e2554e3a17c25d03e7d4 id_1857 { id_1856, drec_snd_311 };
                        letpair_res_1854 = id_1857;
                      }
                      letpair_res_1837 = letpair_res_1854;
                    }
                    let_res_1836 = letpair_res_1837;
                  }
                  choose_res_1781 = let_res_1836;
                }
                letpair_res_1778 = choose_res_1781;
              }
              let_res_1777 = letpair_res_1778;
            }
            ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_1858;
            {
              auto drec_fst_319 { std::get<0>(let_res_1777) };
              auto drec_snd_320 { std::get<1>(let_res_1777) };
              std::shared_ptr<::dessser::gen::source_info::t>  id_1859 { std::make_shared<::dessser::gen::source_info::t>(drec_fst_242, drec_fst_280, drec_fst_319) };
              ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_1860 { id_1859, drec_snd_320 };
              letpair_res_1858 = id_1860;
            }
            letpair_res_1773 = letpair_res_1858;
          }
          let_res_1772 = letpair_res_1773;
        }
        letpair_res_1656 = let_res_1772;
      }
      let_res_1655 = letpair_res_1656;
    }
    return let_res_1655;
  }
   };
  return fun1607;
}
std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_322" "make_snd_323" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_322") (identifier "make_snd_323"))))
 */
static std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> fun1861 { [&](Pointer p_0) {
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_1862 { of_row_binary(p_0) };
    ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 letpair_res_1863;
    {
      auto make_fst_322 { std::get<0>(id_1862) };
      auto make_snd_323 { std::get<1>(id_1862) };
      ::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8 id_1864 { make_fst_322, make_snd_323 };
      letpair_res_1863 = id_1864;
    }
    return letpair_res_1863;
  }
   };
  return fun1861;
}
std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled (compiled_program AS {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: (compiled_func AS {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING})[[]]}) | Failed {err_msg: STRING; depends_on: $src_path?}]}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> fun1865 { [&](std::shared_ptr<::dessser::gen::source_info::t>  p_0, Pointer p_1) {
    Pointer id_1866 { to_row_binary(p_0, p_1) };
    return id_1866;
  }
   };
  return fun1865;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
