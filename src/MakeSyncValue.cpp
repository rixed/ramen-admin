#include <QString>

#include "desssergen/sync_value.h"

#include "MakeSyncValue.h"

static std::unique_ptr<dessser::gen::sync_value::t> makeRaql(
  dessser::gen::raql_value::t *rv)
{
  return std::make_unique<dessser::gen::sync_value::t>(
    std::in_place_index<dessser::gen::sync_value::RamenValue>,
    rv);
}

std::unique_ptr<dessser::gen::sync_value::t> ofBool(bool b)
{
  return makeRaql(new dessser::gen::raql_value::t(
    std::in_place_index<dessser::gen::raql_value::VBool>, b));
}

std::unique_ptr<dessser::gen::sync_value::t> ofChar(char c)
{
  return makeRaql(new dessser::gen::raql_value::t(
    std::in_place_index<dessser::gen::raql_value::VChar>, c));
}

std::unique_ptr<dessser::gen::sync_value::t> ofDouble(double d)
{
  return makeRaql(new dessser::gen::raql_value::t(
    std::in_place_index<dessser::gen::raql_value::VFloat>, d));
}

std::unique_ptr<dessser::gen::sync_value::t> ofString(std::string const &s)
{
  return makeRaql(new dessser::gen::raql_value::t(
    std::in_place_index<dessser::gen::raql_value::VString>, s));
}

#define DO_UINT(W, CW, conv) \
std::unique_ptr<dessser::gen::sync_value::t> ofU##W(uint##CW##_t n) \
{ \
  return makeRaql(new dessser::gen::raql_value::t( \
    std::in_place_index<dessser::gen::raql_value::VU##W>, n)); \
} \
 \
std::unique_ptr<dessser::gen::sync_value::t> u##W##OfQString(QString const &s) \
{ \
  if (s.isEmpty()) return std::unique_ptr<dessser::gen::sync_value::t>(); \
  return ofU##W(s.conv()); \
} \

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

#define DO_INT(W, CW, conv) \
std::unique_ptr<dessser::gen::sync_value::t> ofI##W(int##CW##_t n) \
{ \
  return makeRaql(new dessser::gen::raql_value::t( \
    std::in_place_index<dessser::gen::raql_value::VI##W>, n)); \
} \
 \
std::unique_ptr<dessser::gen::sync_value::t> i##W##OfQString(QString const &s) \
{ \
  if (s.isEmpty()) return std::unique_ptr<dessser::gen::sync_value::t>(); \
  return ofI##W(s.conv()); \
} \

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

std::unique_ptr<dessser::gen::sync_value::t> boolOfQString(QString const &s)
{
  if (s.isEmpty()) return std::unique_ptr<dessser::gen::sync_value::t>();
  char const c { s[0].toLatin1() };
  return ofBool(c == '1' || c == 'y' || c == 't' || s == QString("on"));
}

std::unique_ptr<dessser::gen::sync_value::t> charOfQString(QString const &s)
{
  if (s.isEmpty()) return std::unique_ptr<dessser::gen::sync_value::t>();
  return ofChar(s[0].toLatin1());
}

std::unique_ptr<dessser::gen::sync_value::t> floatOfQString(QString const &s)
{
  if (s.isEmpty()) return std::unique_ptr<dessser::gen::sync_value::t>();
  return ofDouble(s.toDouble());
}

std::unique_ptr<dessser::gen::sync_value::t> stringOfQString(QString const &s)
{
  if (s.isEmpty()) return std::unique_ptr<dessser::gen::sync_value::t>();
  return ofString(s.toStdString());
}
