// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef MAKESYNCVALUE_H_210914
#define MAKESYNCVALUE_H_210914
/*
 * Converter from QString (editor widget content) to actual sync_value:
 */
#include <memory>

#include "misc.h"

class QString;
namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
namespace raql_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

std::unique_ptr<dessser::gen::sync_value::t> makeRamenValue(
    std::shared_ptr<dessser::gen::raql_value::t>);

std::unique_ptr<dessser::gen::sync_value::t> ofBool(bool);
std::unique_ptr<dessser::gen::sync_value::t> ofChar(char);
std::unique_ptr<dessser::gen::sync_value::t> ofDouble(double);
std::unique_ptr<dessser::gen::sync_value::t> ofString(std::string const &);
std::unique_ptr<dessser::gen::sync_value::t> ofU8(uint8_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU16(uint16_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU24(uint32_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU32(uint32_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU40(uint64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU48(uint64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU56(uint64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU64(uint64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofU128(uint128_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI8(int8_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI16(int16_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI24(int32_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI32(int32_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI40(int64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI48(int64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI56(int64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI64(int64_t);
std::unique_ptr<dessser::gen::sync_value::t> ofI128(int128_t);
std::unique_ptr<dessser::gen::sync_value::t> ofIpv4(uint32_t);
std::unique_ptr<dessser::gen::sync_value::t> ofIpv6(uint128_t);
std::unique_ptr<dessser::gen::sync_value::t> ofCidrv4(uint32_t, uint8_t);
std::unique_ptr<dessser::gen::sync_value::t> ofCidrv6(uint128_t, uint8_t);

std::unique_ptr<dessser::gen::sync_value::t> boolOfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> charOfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> floatOfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> stringOfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u8OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u16OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u24OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u32OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u40OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u48OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u56OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u64OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> u128OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i8OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i16OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i24OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i32OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i40OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i48OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i56OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i64OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> i128OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> ipv4OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> ipv6OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> ipOfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> cidrv4OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> cidrv6OfQString(QString const &);
std::unique_ptr<dessser::gen::sync_value::t> cidrOfQString(QString const &);

#endif
