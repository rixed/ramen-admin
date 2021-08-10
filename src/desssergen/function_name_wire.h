#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  std::string,
  Pointer
> v_46a5e81c2410b000ff0adea6dc198147;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(std::string,Pointer)> to_row_binary;
std::function<Size(std::string)> sersize_of_row_binary;
std::function<v_46a5e81c2410b000ff0adea6dc198147(Pointer)> of_row_binary;

}
