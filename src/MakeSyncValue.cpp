// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "MakeSyncValue.h"

#include <QString>

#include "desssergen/sync_value.h"

std::unique_ptr<dessser::gen::sync_value::t> makeRamenValue(
    std::shared_ptr<dessser::gen::raql_value::t> rv) {
  return std::make_unique<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::RamenValue>, rv);
}

std::unique_ptr<dessser::gen::sync_value::t> ofBool(bool b) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VBool>, b));
}

std::unique_ptr<dessser::gen::sync_value::t> boolOfQString(QString const &s) {
  if (s.isEmpty()) return std::unique_ptr<dessser::gen::sync_value::t>();
  char const c{s[0].toLatin1()};
  return ofBool(c == '1' || c == 'y' || c == 't' || s == QString("on"));
}

std::unique_ptr<dessser::gen::sync_value::t> ofChar(char c) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VChar>, c));
}

std::unique_ptr<dessser::gen::sync_value::t> charOfQString(QString const &s) {
  if (s.isEmpty()) return nullptr;
  return ofChar(s[0].toLatin1());
}

std::unique_ptr<dessser::gen::sync_value::t> ofDouble(double d) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VFloat>, d));
}

std::unique_ptr<dessser::gen::sync_value::t> floatOfQString(QString const &s) {
  if (s.isEmpty()) return nullptr;
  return ofDouble(s.toDouble());
}

std::unique_ptr<dessser::gen::sync_value::t> ofString(std::string const &s) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VString>, s));
}

std::unique_ptr<dessser::gen::sync_value::t> stringOfQString(QString const &s) {
  if (s.isEmpty()) return nullptr;
  return ofString(s.toStdString());
}

#define DO_UINT(W, CW, conv)                                             \
  std::unique_ptr<dessser::gen::sync_value::t> ofU##W(uint##CW##_t n) {  \
    return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>( \
        std::in_place_index<dessser::gen::raql_value::VU##W>, n));       \
  }                                                                      \
                                                                         \
  std::unique_ptr<dessser::gen::sync_value::t> u##W##OfQString(          \
      QString const &s) {                                                \
    if (s.isEmpty()) return nullptr;                                     \
    return ofU##W(s.conv());                                             \
  }

DO_UINT(8, 8, toInt)
DO_UINT(16, 16, toInt)
DO_UINT(24, 32, toInt)
DO_UINT(32, 32, toLongLong)
DO_UINT(40, 64, toLongLong)
DO_UINT(48, 64, toLongLong)
DO_UINT(56, 64, toLongLong)
DO_UINT(64, 64, toLongLong)
// FIXME:
DO_UINT(128, 128, toLongLong)

#define DO_INT(W, CW, conv)                                              \
  std::unique_ptr<dessser::gen::sync_value::t> ofI##W(int##CW##_t n) {   \
    return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>( \
        std::in_place_index<dessser::gen::raql_value::VI##W>, n));       \
  }                                                                      \
                                                                         \
  std::unique_ptr<dessser::gen::sync_value::t> i##W##OfQString(          \
      QString const &s) {                                                \
    if (s.isEmpty()) return nullptr;                                     \
    return ofI##W(s.conv());                                             \
  }

DO_INT(8, 8, toInt)
DO_INT(16, 16, toInt)
DO_INT(24, 32, toInt)
DO_INT(32, 32, toLongLong)
DO_INT(40, 64, toLongLong)
DO_INT(48, 64, toLongLong)
DO_INT(56, 64, toLongLong)
DO_INT(64, 64, toLongLong)
// FIXME:
DO_INT(128, 128, toLongLong)

std::unique_ptr<dessser::gen::sync_value::t> ofIpv4(uint32_t ip) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VIpv4>, ip));
}

std::unique_ptr<dessser::gen::sync_value::t> ipv4OfQString(QString const &s) {
  uint32_t ip;
  if (!parseIpv4(&ip, s)) return nullptr;
  return ofIpv4(ip);
}

std::unique_ptr<dessser::gen::sync_value::t> ofIpv6(uint128_t ip) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VIpv6>, ip));
}

std::unique_ptr<dessser::gen::sync_value::t> ipv6OfQString(QString const &s) {
  uint128_t ip;
  if (!parseIpv6(&ip, s)) return nullptr;
  return ofIpv6(ip);
}

std::unique_ptr<dessser::gen::sync_value::t> ipOfQString(QString const &s) {
  uint32_t ip4;
  uint128_t ip6;
  if (parseIpv4(&ip4, s)) {
    return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
        std::in_place_index<dessser::gen::raql_value::VIp>,
        std::in_place_index<dessser::gen::raql_value::v4>, ip4));
  } else if (parseIpv6(&ip6, s)) {
    return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
        std::in_place_index<dessser::gen::raql_value::VIp>,
        std::in_place_index<dessser::gen::raql_value::v6>, ip6));
  } else {
    return nullptr;
  }
}

std::unique_ptr<dessser::gen::sync_value::t> ofCidrv4(uint32_t ip,
                                                      uint8_t mask) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VCidrv4>, ip, mask));
}

std::unique_ptr<dessser::gen::sync_value::t> cidrv4OfQString(QString const &s) {
  QStringList l{s.split('/', Qt::KeepEmptyParts)};
  uint32_t ip;
  if (l.count() != 2 || !parseIpv4(&ip, s)) return nullptr;
  return ofCidrv4(ip, l[1].toInt());
}

std::unique_ptr<dessser::gen::sync_value::t> ofCidrv6(uint128_t ip,
                                                      uint8_t mask) {
  return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VCidrv6>, ip, mask));
}

std::unique_ptr<dessser::gen::sync_value::t> cidrv6OfQString(QString const &s) {
  QStringList l{s.split('/', Qt::KeepEmptyParts)};
  uint128_t ip;
  if (l.count() != 2 || !parseIpv6(&ip, s)) return nullptr;
  return ofCidrv6(ip, l[1].toInt());
}
