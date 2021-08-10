#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_key {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct v_808252496816a9c094ed1ddb199861d1 : public std::variant<
  uint32_t
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_808252496816a9c094ed1ddb199861d1 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  v_808252496816a9c094ed1ddb199861d1,
  Pointer
> bb7a1af56c56ee3850e41d7e7bbfd8d3;

typedef std::tuple<
  dessser::gen::src_path::t,
  std::string
> c404d7e7dfb3057f4a4f6b6766eeb900;

struct v_1e81caa74ae611e9cb191b8ee50bee25 : public std::variant<
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_1e81caa74ae611e9cb191b8ee50bee25 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_1e81caa74ae611e9cb191b8ee50bee25
> c8d851022c838ee90bc952d525c2d3aa;

struct v_8e097ae30bed5641a60541fcf38314dd : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_8e097ae30bed5641a60541fcf38314dd const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_8e097ae30bed5641a60541fcf38314dd
> a9a5fa86cfaa17c85b3606d1a4582bcd;

struct v_8c6c9edc5b1d709b5094571801c00912 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  a9a5fa86cfaa17c85b3606d1a4582bcd,
  uint32_t,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_8c6c9edc5b1d709b5094571801c00912 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::fq_name::t,
  v_8c6c9edc5b1d709b5094571801c00912
> v_0fab8a04cd41fd489e58d011ef6f08ad;

struct v_5c73eec19356406029ebc971f8fc93ef : public std::variant<
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_5c73eec19356406029ebc971f8fc93ef const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_5c73eec19356406029ebc971f8fc93ef
> v_9a47b091ef9a7a446e50646760330664;

struct v_320dee9bcc93c7ed0c75cc7db8b85d9b : public std::variant<
  Void,
  c8d851022c838ee90bc952d525c2d3aa,
  v_0fab8a04cd41fd489e58d011ef6f08ad,
  v_9a47b091ef9a7a446e50646760330664
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_320dee9bcc93c7ed0c75cc7db8b85d9b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::site_name::t,
  v_320dee9bcc93c7ed0c75cc7db8b85d9b
> v_26540a608fe059393cc3cd282be43df3;

struct v_60ff76b761c62e00eb6df04e7d00fbc8 : public std::variant<
  Void,
  Void,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_60ff76b761c62e00eb6df04e7d00fbc8 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct v_6c1c7418355e363a303990cad40945dd : public std::variant<
  std::string,
  uint32_t
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_6c1c7418355e363a303990cad40945dd const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct v_3a6e990115d17bf3eefa1b91b13ca80b : public std::tuple<
  dessser::gen::site_name::t,
  dessser::gen::fq_name::t,
  std::string,
  v_6c1c7418355e363a303990cad40945dd
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_3a6e990115d17bf3eefa1b91b13ca80b const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct v_90e4213e12fd850ebf8d15b08342b17e : public std::variant<
  std::string,
  v_808252496816a9c094ed1ddb199861d1
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_90e4213e12fd850ebf8d15b08342b17e const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::sync_socket::t,
  v_90e4213e12fd850ebf8d15b08342b17e
> v_287d43b770d826e060b1e65a4d07e0b0;

struct per_dash_key;
typedef std::tuple<
  std::string,
  v_808252496816a9c094ed1ddb199861d1*
> ea82132cbdaf05c9cc56869f7b4529c3;

struct v_04c2264c7cb6c602ff22f97c6ae3e620 : public std::variant<
  std::string,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_04c2264c7cb6c602ff22f97c6ae3e620 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_04c2264c7cb6c602ff22f97c6ae3e620
> v_3891539b8b788ad5d369dde272200753;

struct f27b577e1bb6a9c447e7eec975daa7e7 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, f27b577e1bb6a9c447e7eec975daa7e7 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  f27b577e1bb6a9c447e7eec975daa7e7
> v_22ca22dbe40628ddd4edb314b5205ff3;

typedef std::tuple<
  double,
  uint32_t
> a87b3e8210a10a34a7c2070f37f91a0a;

struct e6f820d94c0e3bb8eb0c04383ff72e06 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  v_22ca22dbe40628ddd4edb314b5205ff3,
  a87b3e8210a10a34a7c2070f37f91a0a
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, e6f820d94c0e3bb8eb0c04383ff72e06 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  e6f820d94c0e3bb8eb0c04383ff72e06
> ec4a56989018adc62b22d5f6798b0bc1;

struct t : public std::variant<
  Void,
  Void,
  std::string,
  c404d7e7dfb3057f4a4f6b6766eeb900,
  Void,
  v_26540a608fe059393cc3cd282be43df3,
  v_60ff76b761c62e00eb6df04e7d00fbc8,
  v_3a6e990115d17bf3eefa1b91b13ca80b,
  uint16_t,
  std::optional<dessser::gen::sync_socket::t>,
  Void,
  v_287d43b770d826e060b1e65a4d07e0b0,
  ea82132cbdaf05c9cc56869f7b4529c3,
  Void,
  v_3891539b8b788ad5d369dde272200753,
  ec4a56989018adc62b22d5f6798b0bc1
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
    case 9: os << std::get<9>(v); break;
    case 10: os << std::get<10>(v); break;
    case 11: os << std::get<11>(v); break;
    case 12: os << std::get<12>(v); break;
    case 13: os << std::get<13>(v); break;
    case 14: os << std::get<14>(v); break;
    case 15: os << std::get<15>(v); break;
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(v_808252496816a9c094ed1ddb199861d1,Pointer)> per_dash_key_to_row_binary;
std::function<Size(v_808252496816a9c094ed1ddb199861d1)> per_dash_key_sersize_of_row_binary;
std::function<bb7a1af56c56ee3850e41d7e7bbfd8d3(Pointer)> per_dash_key_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<Pointer(t,Pointer)> to_row_binary;

}
