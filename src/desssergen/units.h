#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::units {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  double,
  bool
> v_1a724825aad0221aa9e0a09417bb3c5f;

typedef std::tuple<
  std::string,
  v_1a724825aad0221aa9e0a09417bb3c5f
> e845b33138a56d15c346dc169018381f;

typedef Arr<e845b33138a56d15c346dc169018381f> t;
typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t&,Pointer)> to_row_binary;
std::function<Size(t&)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
