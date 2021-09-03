#ifndef DESSSER_GEN_units
#define DESSSER_GEN_units
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::units {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  double,
  bool
> tea0eebdc0b2e9b51f69e77168901ab2f;

typedef std::tuple<
  std::string,
  ::dessser::gen::units::tea0eebdc0b2e9b51f69e77168901ab2f
> t7a10547ef8ab8f1e1017ccef19d73726;

typedef Arr<::dessser::gen::units::t7a10547ef8ab8f1e1017ccef19d73726> t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::units::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
