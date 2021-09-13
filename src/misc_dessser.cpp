#include <cstring>
#include <sstream>
extern "C" {
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
}
#include <QCoreApplication>


#include "desssergen/raql_type.h"
#include "desssergen/sync_server_msg.h"
#include "desssergen/sync_client_msg.h"
#include "desssergen/sync_msg.h"
#include "misc.h"

#include "misc_dessser.h"

bool isScalar(dessser::gen::raql_type::t const &t)
{
  switch (t.type.index()) {
    case dessser::gen::raql_type::Vec:
    case dessser::gen::raql_type::Arr:
    case dessser::gen::raql_type::Tup:
    case dessser::gen::raql_type::Rec:
    case dessser::gen::raql_type::Sum:
      return false;
    default:
      return true;
  }
}

bool isNumeric(dessser::gen::raql_type::t const &t)
{
  switch (t.type.index()) {
    case dessser::gen::raql_type::Bool:
    case dessser::gen::raql_type::Float:
    case dessser::gen::raql_type::U8:
    case dessser::gen::raql_type::U16:
    case dessser::gen::raql_type::U24:
    case dessser::gen::raql_type::U32:
    case dessser::gen::raql_type::U40:
    case dessser::gen::raql_type::U48:
    case dessser::gen::raql_type::U56:
    case dessser::gen::raql_type::U64:
    case dessser::gen::raql_type::U128:
    case dessser::gen::raql_type::I8:
    case dessser::gen::raql_type::I16:
    case dessser::gen::raql_type::I24:
    case dessser::gen::raql_type::I32:
    case dessser::gen::raql_type::I40:
    case dessser::gen::raql_type::I48:
    case dessser::gen::raql_type::I56:
    case dessser::gen::raql_type::I64:
    case dessser::gen::raql_type::I128:
      return true;
    default:
      return false;
  }
}

bool isAWorker(dessser::gen::sync_key::t const &key)
{
  if (key.index() != dessser::gen::sync_key::PerSite) return false;
  auto const &per_site { std::get<dessser::gen::sync_key::PerSite>(key) };
  auto const &key_ { std::get<1>(per_site) };
  if (key_.index() != dessser::gen::sync_key::PerWorker) return false;
  auto const &per_worker { std::get<dessser::gen::sync_key::PerWorker>(key_) };
  auto const &key__ { std::get<1>(per_worker) };
  return key__.index() == dessser::gen::sync_key::Worker;
}

int numColumns(dessser::gen::raql_type::t const &t)
{
  switch (t.type.index()) {
    case dessser::gen::raql_type::Tup:
      {
        auto const &tup { std::get<dessser::gen::raql_type::Tup>(t.type) };
        return tup.size();
      }
    case dessser::gen::raql_type::Vec:
      {
        auto const &vec { std::get<dessser::gen::raql_type::Vec>(t.type) };
        return std::get<0>(vec);
      }
    case dessser::gen::raql_type::Rec:
      {
        auto const &rec { std::get<dessser::gen::raql_type::Rec>(t.type) };
        return rec.size();
      }
    default:
      return 1;
  }
}

QString const columnName(dessser::gen::raql_type::t const &t, size_t i)
{
  switch (t.type.index()) {
    case dessser::gen::raql_type::Tup:
    case dessser::gen::raql_type::Vec:
      return QString("#") + QString::number(i);
    case dessser::gen::raql_type::Rec:
      {
        auto const &rec { std::get<dessser::gen::raql_type::Rec>(t.type) };
        return QString::fromStdString(std::get<0>(rec[i]));
      }
    default:
      return QString();
  }
}

dessser::gen::raql_type::t const *columnType(dessser::gen::raql_type::t const &t, size_t i)
{
  switch (t.type.index()) {
    case dessser::gen::raql_type::Tup:
      {
        auto const &arr { std::get<dessser::gen::raql_type::Tup>(t.type) };
        if (i >= arr.size()) return nullptr;
        return arr[i];
      }
    case dessser::gen::raql_type::Vec:
      {
        auto const &vec { std::get<dessser::gen::raql_type::Vec>(t.type) };
        uint32_t const len { std::get<0>(vec) };
        if (i >= len) return nullptr;
        return std::get<1>(vec);
      }
    case dessser::gen::raql_type::Rec:
      {
        auto const &arr { std::get<dessser::gen::raql_type::Rec>(t.type) };
        if (i >= arr.size()) return nullptr;
        return std::get<1>(arr[i]);
      }
    default:
      return nullptr;
  }
}

dessser::gen::raql_value::t const *columnValue(dessser::gen::raql_value::t const &v, size_t i)
{
  dessser::Arr<dessser::gen::raql_value::t *> const *arr;
  switch (v.index()) {
    case dessser::gen::raql_value::VTup:
      arr = &(std::get<dessser::gen::raql_value::VTup>(v));
      Q_ASSERT(i < arr->size());
      return (*arr)[i];
    case dessser::gen::raql_value::VVec:
      arr = &(std::get<dessser::gen::raql_value::VVec>(v));
      Q_ASSERT(i < arr->size());
      return (*arr)[i];
    case dessser::gen::raql_value::VLst:
      arr = &(std::get<dessser::gen::raql_value::VLst>(v));
      Q_ASSERT(i < arr->size());
      return (*arr)[i];
    case dessser::gen::raql_value::VRec:
      {
        auto const *rec { &std::get<dessser::gen::raql_value::VRec>(v) };
        Q_ASSERT(i < rec->size());
        return std::get<1>((*rec)[i]);
      }
    default:
      return nullptr;
  }
}

std::optional<double> toDouble(dessser::gen::raql_value::t const &v)
{
  switch (v.index()) {
    case dessser::gen::raql_value::VBool:
      return (double)std::get<dessser::gen::raql_value::VBool>(v);
    case dessser::gen::raql_value::VChar:
      return (double)std::get<dessser::gen::raql_value::VChar>(v);
    case dessser::gen::raql_value::VFloat:
      return (double)std::get<dessser::gen::raql_value::VFloat>(v);
    case dessser::gen::raql_value::VU8:
      return (double)std::get<dessser::gen::raql_value::VU8>(v);
    case dessser::gen::raql_value::VU16:
      return (double)std::get<dessser::gen::raql_value::VU16>(v);
    case dessser::gen::raql_value::VU24:
      return (double)std::get<dessser::gen::raql_value::VU24>(v);
    case dessser::gen::raql_value::VU32:
      return (double)std::get<dessser::gen::raql_value::VU32>(v);
    case dessser::gen::raql_value::VU40:
      return (double)std::get<dessser::gen::raql_value::VU40>(v);
    case dessser::gen::raql_value::VU48:
      return (double)std::get<dessser::gen::raql_value::VU48>(v);
    case dessser::gen::raql_value::VU56:
      return (double)std::get<dessser::gen::raql_value::VU56>(v);
    case dessser::gen::raql_value::VU64:
      return (double)std::get<dessser::gen::raql_value::VU64>(v);
    case dessser::gen::raql_value::VU128:
      return (double)std::get<dessser::gen::raql_value::VU128>(v);
    case dessser::gen::raql_value::VI8:
      return (double)std::get<dessser::gen::raql_value::VI8>(v);
    case dessser::gen::raql_value::VI16:
      return (double)std::get<dessser::gen::raql_value::VI16>(v);
    case dessser::gen::raql_value::VI24:
      return (double)std::get<dessser::gen::raql_value::VI24>(v);
    case dessser::gen::raql_value::VI32:
      return (double)std::get<dessser::gen::raql_value::VI32>(v);
    case dessser::gen::raql_value::VI40:
      return (double)std::get<dessser::gen::raql_value::VI40>(v);
    case dessser::gen::raql_value::VI48:
      return (double)std::get<dessser::gen::raql_value::VI48>(v);
    case dessser::gen::raql_value::VI56:
      return (double)std::get<dessser::gen::raql_value::VI56>(v);
    case dessser::gen::raql_value::VI64:
      return (double)std::get<dessser::gen::raql_value::VI64>(v);
    case dessser::gen::raql_value::VI128:
      return (double)std::get<dessser::gen::raql_value::VI128>(v);
    default:
      return std::optional<double>();
  }
}

static QString arrToQString(dessser::Arr<dessser::gen::raql_value::t *> const &arr)
{
  QString s;
  for (dessser::gen::raql_value::t *v : arr) {
    if (s.length() > 0) s += ", ";
    s += raqlToQString(*v);
  }
  return s;
}

static QString qstringOfIpv4(uint32_t const v)
{
  return QString(inet_ntoa((struct in_addr){ .s_addr = htonl(v) }));
}

static QString qstringOfIpv6(uint128_t const v)
{
  char buf[ 8*(4+1) ];
  struct in6_addr ip;

# if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  memcpy(ip.s6_addr, &v, sizeof(ip.s6_addr));
# else
  uint8_t const *p { reinterpret_cast<uint8_t const *>(&v) };
  for (size_t i = 0; i < 16; ++i) ip.s6_addr[i] = p[15-i];
# endif

  return QString(inet_ntop(AF_INET6, &ip, buf, sizeof buf));
}

// Handle the cases where we do have a specialization for that key:
static QString toQStringSpecKey(dessser::gen::raql_value::t const &v, dessser::gen::sync_key::t const &k)
{
  // Try some special formats first:
  switch (v.index()) {
    case dessser::gen::raql_value::VFloat:
      { // Many float are actually dates:
        double const f { std::get<dessser::gen::raql_value::VFloat>(v) };
        switch (k.index()) {
          case dessser::gen::sync_key::Time:
            return stringOfDate(f);
          case dessser::gen::sync_key::PerSite:
            {
              auto const &per_site { std::get<dessser::gen::sync_key::PerSite>(k) };
              auto const &per_site_key { std::get<1>(per_site) };
              switch (per_site_key.index()) {
                case dessser::gen::sync_key::PerWorker:
                  {
                    auto const &per_work { std::get<dessser::gen::sync_key::PerWorker>(per_site_key) };
                    auto const &per_work_key { std::get<1>(per_work) };
                    switch (per_work_key.index()) {
                      case dessser::gen::sync_key::PerInstance:
                        {
                          auto const &per_inst { std::get<dessser::gen::sync_key::PerInstance>(per_work_key) };
                          auto const &per_inst_key { std::get<1>(per_inst) };
                          switch (per_inst_key.index()) {
                            case dessser::gen::sync_key::LastKilled:
                            case dessser::gen::sync_key::LastExit:
                            case dessser::gen::sync_key::QuarantineUntil:
                              return stringOfDate(f);
                            default:
                              break;
                          }
                          break;
                        }
                      default:
                        break;
                    }
                    break;
                  }
                default:
                  break;
              }
              break;
            }
          case dessser::gen::sync_key::Incidents:
            {
              auto const &per_inc { std::get<dessser::gen::sync_key::Incidents>(k) };
              auto const &per_inc_key { std::get<1>(per_inc) };
              switch (per_inc_key.index()) {
                case dessser::gen::sync_key::Dialogs:
                  {
                    auto const &per_diag { std::get<dessser::gen::sync_key::Dialogs>(per_inc_key) };
                    auto const &per_diag_key { std::get<1>(per_diag) };
                    switch (per_diag_key.index()) {
                      case dessser::gen::sync_key::FirstDeliveryAttempt:
                      case dessser::gen::sync_key::LastDeliveryAttempt:
                      case dessser::gen::sync_key::NextScheduled:
                      case dessser::gen::sync_key::NextSend:
                        return stringOfDate(f);
                      default:
                        break;
                    }
                    break;
                  }
                  break;
                default:
                  break;
              }
              break;
            }
          default:
              break;
        }
        break;
      }
    default:
      break;
  }

  return QString();
}

QString raqlToQString(dessser::gen::raql_value::t const &v)
{
  // Special format according to type:
  switch (v.index()) {
    case dessser::gen::raql_value::VBool:
      if (std::get<dessser::gen::raql_value::VBool>(v))
        return QCoreApplication::translate("QMainWindow", "true");
      else
        return QCoreApplication::translate("QMainWindow", "false");
    case dessser::gen::raql_value::VChar:
      {
        QString res;
        QTextStream(&res) << "#\\" << std::get<dessser::gen::raql_value::VChar>(v);
        return res;
      }
    case dessser::gen::raql_value::VIpv4:
      return qstringOfIpv4(std::get<dessser::gen::raql_value::VIpv4>(v));
    case dessser::gen::raql_value::VIpv6:
      return qstringOfIpv6(std::get<dessser::gen::raql_value::VIpv6>(v));
    case dessser::gen::raql_value::VIp:
      {
        auto const &ip { std::get<dessser::gen::raql_value::VIp>(v) };
        switch (ip.index()) {
          case dessser::gen::raql_value::v4:
            return qstringOfIpv4(std::get<dessser::gen::raql_value::v4>(ip));
          case dessser::gen::raql_value::v6:
            return qstringOfIpv6(std::get<dessser::gen::raql_value::v6>(ip));
        }
        break;
      }
    case dessser::gen::raql_value::VCidrv4:
      {
        auto const &cidr { std::get<dessser::gen::raql_value::VCidrv4>(v) };
        return qstringOfIpv4(cidr.Cidr4_ip) + QString('/') + QString::number(cidr.Cidr4_mask);
      }
    case dessser::gen::raql_value::VCidrv6:
      {
        auto const &cidr { std::get<dessser::gen::raql_value::VCidrv6>(v) };
        return qstringOfIpv6(cidr.ip) + QString('/') + QString::number(cidr.mask);
      }
    case dessser::gen::raql_value::VCidr:
      {
        auto const &cidr_ { std::get<dessser::gen::raql_value::VCidr>(v) };
        switch (cidr_.index()) {
          case dessser::gen::raql_value::v4:
            {
              auto const &cidr { std::get<dessser::gen::raql_value::v4>(cidr_) };
              return qstringOfIpv4(cidr.Cidr4_ip) + QString('/') + QString::number(cidr.Cidr4_mask);
            }
          case dessser::gen::raql_value::v6:
            {
              auto const &cidr { std::get<dessser::gen::raql_value::v6>(cidr_) };
              return qstringOfIpv6(cidr.ip) + QString('/') + QString::number(cidr.mask);
            }
        }
        break;
      }
    // TODO: VEth
    case dessser::gen::raql_value::VTup:
      return QString("(") +
             arrToQString(std::get<dessser::gen::raql_value::VTup>(v)) +
             QString(")");
    case dessser::gen::raql_value::VVec:
      return QString("[") +
             arrToQString(std::get<dessser::gen::raql_value::VVec>(v)) +
             QString("]");
    case dessser::gen::raql_value::VLst:
      return QString("[") +
             arrToQString(std::get<dessser::gen::raql_value::VLst>(v)) +
             QString("]");
    case dessser::gen::raql_value::VRec:
      {
        auto const &arr { std::get<dessser::gen::raql_value::VRec>(v) };
        QString s;
        for (auto const &v : arr) {
          if (s.length() > 0) s += ", ";
          s += QString::fromStdString(std::get<0>(v)) +
               QString(":") +
               raqlToQString(*std::get<1>(v));
        }
        return QString("{") + s + QString("}");
      }
    default:
      break;
  }

  // Fallback to default:
  std::ostringstream s;
  s << v;
  return QString::fromStdString(s.str());
}

QString raqlToQString(dessser::gen::raql_value::t const &v, dessser::gen::sync_key::t const &k)
{
  QString spec { toQStringSpecKey(v, k) };
  if (! spec.isEmpty()) return spec;

  return raqlToQString(v);
}

QString valToQString(dessser::gen::sync_value::t const &v)
{
  if (v.index() == dessser::gen::sync_value::RamenValue) {
    dessser::gen::raql_value::t const *rv { std::get<dessser::gen::sync_value::RamenValue>(v) };
    return raqlToQString(*rv);
  }

  // Fallback to default:
  std::ostringstream s;
  s << v;
  return QString::fromStdString(s.str());
}

QString valToQString(dessser::gen::sync_value::t const &v, dessser::gen::sync_key::t const &k)
{
  if (v.index() == dessser::gen::sync_value::RamenValue) {
    dessser::gen::raql_value::t const *rv { std::get<dessser::gen::sync_value::RamenValue>(v) };
    return raqlToQString(*rv, k);
  }

  return valToQString(v);
}

QString keyToQString(dessser::gen::sync_key::t const &k)
{
  std::ostringstream s;
  s << k;
  return QString::fromStdString(s.str());
}

/* Generic qDebug printer using stringstream: */
template<typename T>
QDebug printerOfStream(QDebug debug, T const &t)
{
  QDebugStateSaver saver(debug);
  std::ostringstream s;
  s << t;
  debug << QString::fromStdString(s.str());
  return debug;
}

QDebug operator<<(QDebug debug, dessser::gen::sync_client_cmd::t const &cmd)
{
  return printerOfStream<dessser::gen::sync_client_cmd::t>(debug, cmd);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_client_msg::t const &msg)
{
  return printerOfStream<dessser::gen::sync_client_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_server_msg::t const &msg)
{
  return printerOfStream<dessser::gen::sync_server_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_msg::t const &msg)
{
  return printerOfStream<dessser::gen::sync_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_socket::t const &msg)
{
  return printerOfStream<dessser::gen::sync_socket::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_key::t const &msg)
{
  return printerOfStream<dessser::gen::sync_key::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_value::t const &msg)
{
  return printerOfStream<dessser::gen::sync_value::t>(debug, msg);
}
