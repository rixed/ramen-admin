// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include <cstring>
#include <memory>
#include <sstream>
extern "C" {
// For getpid():
#include <sys/types.h>
#include <unistd.h>
}
#include <QCoreApplication>
#include <QHostAddress>

#include "desssergen/dashboard_widget.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/raql_type.h"
#include "desssergen/replay.h"
#include "desssergen/replay_request.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_client_msg.h"
#include "desssergen/sync_msg.h"
#include "desssergen/sync_server_msg.h"
#include "misc.h"
#include "misc_dessser.h"

std::string const respKeyPrefix{std::to_string(getpid()) + "_" +
                                std::to_string(std::rand()) + "_"};

std::shared_ptr<dessser::gen::raql_value::t const> const vnull{
    std::make_shared<dessser::gen::raql_value::t>(
        std::in_place_index<dessser::gen::raql_value::VNull>, dessser::Void())};

std::shared_ptr<dessser::gen::sync_value::t const> const nullVal{
    std::make_shared<dessser::gen::sync_value::t const>(
        std::in_place_index<dessser::gen::sync_value::RamenValue>,
        std::const_pointer_cast<dessser::gen::raql_value::t>(
            std::static_pointer_cast<dessser::gen::raql_value::t const>(
                vnull)))};

std::shared_ptr<dessser::gen::sync_key::t const> const targetConfig{
    std::make_shared<dessser::gen::sync_key::t>(
        std::in_place_index<dessser::gen::sync_key::TargetConfig>,
        dessser::Void())};

std::shared_ptr<dessser::gen::dashboard_widget::type const> const chartPlotType{
    std::make_shared<dessser::gen::dashboard_widget::type>(
        std::in_place_index<dessser::gen::dashboard_widget::Plot>,
        dessser::Void())};

bool isScalar(dessser::gen::raql_type::t const &t) {
  switch (t.type->index()) {
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

bool isNumeric(dessser::gen::raql_type::t const &t) {
  switch (t.type->index()) {
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

bool isAWorker(dessser::gen::sync_key::t const &key) {
  if (key.index() != dessser::gen::sync_key::PerSite) return false;
  std::shared_ptr<dessser::gen::sync_key::per_site const> per_site{
      std::get<dessser::gen::sync_key::PerSite>(key)};
  std::shared_ptr<dessser::gen::sync_key::per_site_data const> per_site_data{
      std::get<1>(*per_site)};
  if (per_site_data->index() != dessser::gen::sync_key::PerWorker) return false;
  std::shared_ptr<dessser::gen::sync_key::per_worker const> per_worker{
      std::get<dessser::gen::sync_key::PerWorker>(*per_site_data)};
  std::shared_ptr<dessser::gen::sync_key::per_worker_data const>
      per_worker_data{std::get<1>(*per_worker)};
  return per_worker_data->index() == dessser::gen::sync_key::Worker;
}

bool isNull(dessser::gen::sync_value::t const &v) {
  if (v.index() != dessser::gen::sync_value::RamenValue) return false;
  return std::get<dessser::gen::sync_value::RamenValue>(v)->index() ==
         dessser::gen::raql_value::VNull;
}

std::shared_ptr<dessser::gen::sync_value::t> newDashboardChart(
    std::string const &site_name, std::string const &program_name,
    std::string const &function_name) {
  std::shared_ptr<dessser::gen::dashboard_widget::axis> axis{
      std::make_shared<dessser::gen::dashboard_widget::axis>(
          true, false,
          std::make_shared<dessser::gen::dashboard_widget::scale>(
              std::in_place_index<dessser::gen::dashboard_widget::Linear>,
              dessser::Void()))};

  dessser::Arr<std::shared_ptr< ::dessser::gen::dashboard_widget::axis> > axes{
      axis};

  std::shared_ptr<dessser::gen::dashboard_widget::source> source{
      std::make_shared<dessser::gen::dashboard_widget::source>(
          std::make_shared<dessser::gen::fq_function_name::t>(
              site_name, program_name, function_name),
          true,
          dessser::Arr<
              std::shared_ptr<dessser::gen::dashboard_widget::field> >())};

  dessser::Arr<std::shared_ptr< ::dessser::gen::dashboard_widget::source> >
      sources{source};

  std::shared_ptr<dessser::gen::sync_value::t> chart{
      std::make_shared<dessser::gen::sync_value::t>(
          std::in_place_index<dessser::gen::sync_value::DashboardWidget>,
          std::make_shared<dessser::gen::dashboard_widget::t>(
              std::in_place_index<dessser::gen::dashboard_widget::Chart>,
              std::make_shared<dessser::gen::dashboard_widget::chart>(
                  // Title
                  site_name + ':' + program_name + '/' + function_name,
                  // Type: plot
                  std::const_pointer_cast<dessser::gen::dashboard_widget::type>(
                      chartPlotType),
                  // Single axis: left=true, forceZero=false, scale=Linear
                  axes,
                  // Single source: visible: true
                  sources)))};

  return chart;
}

unsigned numColumns(dessser::gen::raql_type::t const &t) {
  switch (t.type->index()) {
    case dessser::gen::raql_type::Tup: {
      auto const &tup{std::get<dessser::gen::raql_type::Tup>(*t.type)};
      return tup.size();
    }
    case dessser::gen::raql_type::Vec: {
      auto const &vec{std::get<dessser::gen::raql_type::Vec>(*t.type)};
      return std::get<0>(vec);
    }
    case dessser::gen::raql_type::Rec: {
      auto const &rec{std::get<dessser::gen::raql_type::Rec>(*t.type)};
      return rec.size();
    }
    default:
      return 1;
  }
}

std::string const columnName(dessser::gen::raql_type::t const &t, unsigned i) {
  switch (t.type->index()) {
    case dessser::gen::raql_type::Tup:
    case dessser::gen::raql_type::Vec:
      return std::string("#") + std::to_string(i);
    case dessser::gen::raql_type::Rec: {
      auto const &rec{std::get<dessser::gen::raql_type::Rec>(*t.type)};
      return std::get<0>(*rec[i]);
    }
    default:
      return std::string();
  }
}

std::shared_ptr<dessser::gen::raql_type::t const> columnType(
    dessser::gen::raql_type::t const &t, unsigned i) {
  switch (t.type->index()) {
    case dessser::gen::raql_type::Tup: {
      auto const &arr{std::get<dessser::gen::raql_type::Tup>(*t.type)};
      if (i >= arr.size()) return nullptr;
      return arr[i];
    }
    case dessser::gen::raql_type::Vec: {
      auto const &vec{std::get<dessser::gen::raql_type::Vec>(*t.type)};
      uint32_t const len{std::get<0>(vec)};
      if (i >= len) return nullptr;
      return std::get<1>(vec);
    }
    case dessser::gen::raql_type::Rec: {
      auto const &arr{std::get<dessser::gen::raql_type::Rec>(*t.type)};
      if (i >= arr.size()) return nullptr;
      return std::get<1>(*arr[i]);
    }
    default:
      return nullptr;
  }
}

std::shared_ptr<dessser::gen::raql_value::t const> columnValue(
    dessser::gen::raql_value::t const &v, unsigned i) {
  dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t> > const *arr;
  switch (v.index()) {
    case dessser::gen::raql_value::VTup:
      arr = &(std::get<dessser::gen::raql_value::VTup>(v));
      Q_ASSERT(i < arr->size());
      return (*arr)[i];
    case dessser::gen::raql_value::VVec:
      arr = &(std::get<dessser::gen::raql_value::VVec>(v));
      Q_ASSERT(i < arr->size());
      return (*arr)[i];
    case dessser::gen::raql_value::VArr:
      arr = &(std::get<dessser::gen::raql_value::VArr>(v));
      Q_ASSERT(i < arr->size());
      return (*arr)[i];
    case dessser::gen::raql_value::VRec: {
      dessser::Arr<
          std::shared_ptr<dessser::gen::raql_value::named_value> > const &rec{
          std::get<dessser::gen::raql_value::VRec>(v)};
      Q_ASSERT(i < rec.size());
      return std::get<1>(*rec[i]);
    }
    default:
      return nullptr;
  }
}

std::optional<double> toDouble(dessser::gen::raql_value::t const &v) {
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

std::shared_ptr<dessser::gen::source_info::compiled_program const>
getCompiledProgram(dessser::gen::sync_value::t const &v) {
  if (v.index() != dessser::gen::sync_value::SourceInfo) return nullptr;
  std::shared_ptr<dessser::gen::source_info::t const> source_info{
      std::get<dessser::gen::sync_value::SourceInfo>(v)};
  if (source_info->detail.index() != dessser::gen::source_info::Compiled)
    return nullptr;
  return std::get<dessser::gen::source_info::Compiled>(source_info->detail);
}

std::optional<std::pair<std::string const, std::string const> > srcPathOfKey(
    dessser::gen::sync_key::t const &k) {
  if (k.index() != dessser::gen::sync_key::Sources) return std::nullopt;
  auto const &src{std::get<dessser::gen::sync_key::Sources>(k)};
  return std::make_pair(std::get<0>(src), std::get<1>(src));
}

std::shared_ptr<dessser::gen::sync_key::t> keyOfSrcPath(
    std::string const &path, std::string const &ext) {
  return std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::Sources>, path, ext);
}

/* The name used by a chart source in the list of functions (also to order
 * them)
 */
std::string const siteFqName(dessser::gen::fq_function_name::t const &s) {
  return s.site + ':' + s.program + '/' + s.function;
}

std::shared_ptr<dessser::gen::sync_value::t> makeReplayRequest(
    std::string const &site, std::string const &program,
    std::string const &function, double since, double until,
    std::shared_ptr<dessser::gen::sync_key::t const> respKey, bool explain) {
  std::shared_ptr<dessser::gen::fq_function_name::t> fq_target{
      std::make_shared<dessser::gen::fq_function_name::t>(site, program,
                                                          function)};

  std::shared_ptr<dessser::gen::replay_request::t> req{
      std::make_shared<dessser::gen::replay_request::t>(
          std::const_pointer_cast<dessser::gen::fq_function_name::t>(fq_target),
          since, until, explain,
          std::const_pointer_cast<dessser::gen::sync_key::t>(respKey))};

  return std::make_shared<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::ReplayRequest>,
      std::const_pointer_cast<dessser::gen::replay_request::t>(req));
}

// Returns the TargetConfig value, or nullptr:
dessser::Arr<dessser::gen::rc_entry::t_ext> const *getTargetConfig(
    dessser::gen::sync_value::t const &v) {
  if (v.index() != dessser::gen::sync_value::TargetConfig) return nullptr;
  return &std::get<dessser::gen::sync_value::TargetConfig>(v);
}

static QString arrToQString(
    dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t> > const &arr) {
  QString s;
  for (std::shared_ptr<dessser::gen::raql_value::t> const &v : arr) {
    if (s.length() > 0) s += ", ";
    s += raqlValToQString(*v);
  }
  return s;
}

static QString qstringOfIpv4(uint32_t const v) {
  QHostAddress const addr{quint32(v)};
  return addr.toString();
}

static QString qstringOfIpv6(uint128_t const v) {
  Q_IPV6ADDR v_;

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  memcpy(&v_, &v, 16);
#else
  uint8_t const *p{reinterpret_cast<uint8_t const *>(&v)};
  for (size_t i = 0; i < 16; ++i) v_[i] = p[15 - i];
#endif

  QHostAddress const addr{v_};
  return addr.toString();
}

// Handle the cases where we do have a specialization for that key:
static QString toQStringSpecKey(dessser::gen::raql_value::t const &v,
                                dessser::gen::sync_key::t const &k) {
  // Try some special formats first:
  switch (v.index()) {
    case dessser::gen::raql_value::VFloat: {  // Many float are actually dates:
      double const f{std::get<dessser::gen::raql_value::VFloat>(v)};
      switch (k.index()) {
        case dessser::gen::sync_key::Time:
          return stringOfDate(f);
        case dessser::gen::sync_key::PerSite: {
          std::shared_ptr<dessser::gen::sync_key::per_site const> per_site{
              std::get<dessser::gen::sync_key::PerSite>(k)};
          std::shared_ptr<dessser::gen::sync_key::per_site_data const>
              per_site_data{std::get<1>(*per_site)};
          switch (per_site_data->index()) {
            case dessser::gen::sync_key::PerWorker: {
              std::shared_ptr<dessser::gen::sync_key::per_worker const>
                  per_worker{std::get<dessser::gen::sync_key::PerWorker>(
                      *per_site_data)};
              std::shared_ptr<dessser::gen::sync_key::per_worker_data const>
                  per_work_data{std::get<1>(*per_worker)};
              switch (per_work_data->index()) {
                case dessser::gen::sync_key::PerInstance: {
                  auto const &per_inst{
                      std::get<dessser::gen::sync_key::PerInstance>(
                          *per_work_data)};
                  auto const &per_inst_key{std::get<1>(per_inst)};
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
        case dessser::gen::sync_key::Incidents: {
          auto const &per_inc{std::get<dessser::gen::sync_key::Incidents>(k)};
          std::shared_ptr<dessser::gen::sync_key::incident_key const>
              per_inc_key{std::get<1>(per_inc)};
          switch (per_inc_key->index()) {
            case dessser::gen::sync_key::Dialogs: {
              auto const &per_diag{
                  std::get<dessser::gen::sync_key::Dialogs>(*per_inc_key)};
              std::shared_ptr<dessser::gen::sync_key::dialog_key const>
                  per_diag_key{std::get<1>(per_diag)};
              switch (per_diag_key->index()) {
                case dessser::gen::sync_key::FirstDeliveryAttempt:
                case dessser::gen::sync_key::LastDeliveryAttempt:
                case dessser::gen::sync_key::NextScheduled:
                case dessser::gen::sync_key::NextSend:
                  return stringOfDate(f);
                default:
                  break;
              }
              break;
            } break;
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

QString raqlValToQString(dessser::gen::raql_value::t const &v,
                         std::shared_ptr<dessser::gen::sync_key::t const> k) {
  if (k) {
    QString spec{toQStringSpecKey(v, *k)};
    if (!spec.isEmpty()) return spec;
  }

  // Special format according to type:
  switch (v.index()) {
    case dessser::gen::raql_value::VNull:
      return QCoreApplication::translate("QMainWindow", "null");
    case dessser::gen::raql_value::VFloat:
      return QString::number(std::get<dessser::gen::raql_value::VFloat>(v));
    case dessser::gen::raql_value::VString:
      return QString::fromStdString(
          std::get<dessser::gen::raql_value::VString>(v));
    case dessser::gen::raql_value::VBool:
      if (std::get<dessser::gen::raql_value::VBool>(v))
        return QCoreApplication::translate("QMainWindow", "true");
      else
        return QCoreApplication::translate("QMainWindow", "false");
    case dessser::gen::raql_value::VChar: {
      QString res;
      QTextStream(&res) << "#\\"
                        << std::get<dessser::gen::raql_value::VChar>(v);
      return res;
    }
    case dessser::gen::raql_value::VU8:
      return QString::number(std::get<dessser::gen::raql_value::VU8>(v));
    case dessser::gen::raql_value::VU16:
      return QString::number(std::get<dessser::gen::raql_value::VU16>(v));
    case dessser::gen::raql_value::VU24:
      return QString::number(std::get<dessser::gen::raql_value::VU24>(v));
    case dessser::gen::raql_value::VU32:
      return QString::number(std::get<dessser::gen::raql_value::VU32>(v));
    case dessser::gen::raql_value::VU40:
      return QString::number(std::get<dessser::gen::raql_value::VU40>(v));
    case dessser::gen::raql_value::VU48:
      return QString::number(std::get<dessser::gen::raql_value::VU48>(v));
    case dessser::gen::raql_value::VU56:
      return QString::number(std::get<dessser::gen::raql_value::VU56>(v));
    case dessser::gen::raql_value::VU64:
      return QString::number(std::get<dessser::gen::raql_value::VU64>(v));
    case dessser::gen::raql_value::VU128:
      return stringOfU128(std::get<dessser::gen::raql_value::VU128>(v));
    case dessser::gen::raql_value::VI8:
      return QString::number(std::get<dessser::gen::raql_value::VI8>(v));
    case dessser::gen::raql_value::VI16:
      return QString::number(std::get<dessser::gen::raql_value::VI16>(v));
    case dessser::gen::raql_value::VI24:
      return QString::number(std::get<dessser::gen::raql_value::VI24>(v));
    case dessser::gen::raql_value::VI32:
      return QString::number(std::get<dessser::gen::raql_value::VI32>(v));
    case dessser::gen::raql_value::VI40:
      return QString::number(std::get<dessser::gen::raql_value::VI40>(v));
    case dessser::gen::raql_value::VI48:
      return QString::number(std::get<dessser::gen::raql_value::VI48>(v));
    case dessser::gen::raql_value::VI56:
      return QString::number(std::get<dessser::gen::raql_value::VI56>(v));
    case dessser::gen::raql_value::VI64:
      return QString::number(std::get<dessser::gen::raql_value::VI64>(v));
    case dessser::gen::raql_value::VI128:
      return stringOfI128(std::get<dessser::gen::raql_value::VU128>(v));
    case dessser::gen::raql_value::VIpv4:
      return qstringOfIpv4(std::get<dessser::gen::raql_value::VIpv4>(v));
    case dessser::gen::raql_value::VIpv6:
      return qstringOfIpv6(std::get<dessser::gen::raql_value::VIpv6>(v));
    case dessser::gen::raql_value::VIp: {
      auto const &ip{std::get<dessser::gen::raql_value::VIp>(v)};
      switch (ip.index()) {
        case dessser::gen::raql_value::v4:
          return qstringOfIpv4(std::get<dessser::gen::raql_value::v4>(ip));
        case dessser::gen::raql_value::v6:
          return qstringOfIpv6(std::get<dessser::gen::raql_value::v6>(ip));
      }
      break;
    }
    case dessser::gen::raql_value::VCidrv4: {
      auto const &cidr{std::get<dessser::gen::raql_value::VCidrv4>(v)};
      return qstringOfIpv4(cidr.Cidr4_ip) + QString('/') +
             QString::number(cidr.Cidr4_mask);
    }
    case dessser::gen::raql_value::VCidrv6: {
      auto const &cidr{std::get<dessser::gen::raql_value::VCidrv6>(v)};
      return qstringOfIpv6(cidr.ip) + QString('/') + QString::number(cidr.mask);
    }
    case dessser::gen::raql_value::VCidr: {
      auto const &cidr_{std::get<dessser::gen::raql_value::VCidr>(v)};
      switch (cidr_.index()) {
        case dessser::gen::raql_value::v4: {
          auto const &cidr{std::get<dessser::gen::raql_value::v4>(cidr_)};
          return qstringOfIpv4(cidr.Cidr4_ip) + QString('/') +
                 QString::number(cidr.Cidr4_mask);
        }
        case dessser::gen::raql_value::v6: {
          auto const &cidr{std::get<dessser::gen::raql_value::v6>(cidr_)};
          return qstringOfIpv6(cidr.ip) + QString('/') +
                 QString::number(cidr.mask);
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
    case dessser::gen::raql_value::VArr:
      return QString("[") +
             arrToQString(std::get<dessser::gen::raql_value::VArr>(v)) +
             QString("]");
    case dessser::gen::raql_value::VRec: {
      dessser::Arr<
          std::shared_ptr<dessser::gen::raql_value::named_value> > const &arr{
          std::get<dessser::gen::raql_value::VRec>(v)};
      QString s;
      for (std::shared_ptr<dessser::gen::raql_value::named_value> const &v :
           arr) {
        if (s.length() > 0) s += ", ";
        s += QString::fromStdString(std::get<0>(*v)) + QString(":") +
             raqlValToQString(*std::get<1>(*v));
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

static QString raqlBaseType2QString(dessser::gen::raql_type::base const &b) {
  using namespace dessser::gen::raql_type;
  switch (b.index()) {
    case Tup: {
      dessser::Arr<std::shared_ptr<t> > ts{std::get<Tup>(b)};
      QString s;
      bool first = true;
      for (std::shared_ptr<t> const &t : ts) {
        QString sep{QString(first ? "(" : "; ")};
        first = false;
        s += sep + raqlTypeToQString(*t);
      }
      return s + ")";
    }
    case Vec: {
      auto const d_t{std::get<Vec>(b)};
      return raqlTypeToQString(*std::get<1>(d_t)) + "[" +
             QString::number(std::get<0>(d_t)) + "]";
    }
    case Arr: {
      std::shared_ptr<t> t{std::get<Arr>(b)};
      return raqlTypeToQString(*t) + "[]";
    }
    case Rec: {
      auto const ts{std::get<Rec>(b)};
      QString s;
      bool first = true;
      for (std::shared_ptr<dessser::gen::raql_type::named_type> const &n_t :
           ts) {
        QString sep{QString(first ? "{" : "; ")};
        first = false;
        s += sep + QString::fromStdString(std::get<0>(*n_t)) + ": " +
             raqlTypeToQString(*std::get<1>(*n_t));
      }
      return s + "}";
    }
    case Sum: {
      auto const ts{std::get<Sum>(b)};
      QString s;
      bool first = true;
      for (std::shared_ptr<dessser::gen::raql_type::named_type> const &n_t :
           ts) {
        QString sep{QString(first ? "[" : " | ")};
        first = false;
        s += sep + QString::fromStdString(std::get<0>(*n_t)) + " " +
             raqlTypeToQString(*std::get<1>(*n_t));
      }
      return s + "]";
    }
    case Map: {
      auto const k_v{std::get<Map>(b)};
      return raqlTypeToQString(*std::get<0>(k_v)) + "[" +
             raqlTypeToQString(*std::get<1>(k_v)) + "]";
    }
    default: {
      std::ostringstream s;
      s << b;
      return QString::fromStdString(s.str());
    }
  }
}

QString raqlTypeToQString(dessser::gen::raql_type::t const &t) {
  QString b{raqlBaseType2QString(*t.type)};
  if (t.nullable) b += '?';
  return b;
}

QString raqlExprToQString(dessser::gen::raql_expr::t const &e) {
  std::ostringstream s;
  s << e;
  return QString::fromStdString(s.str());
}

QString syncValToQString(dessser::gen::sync_value::t const &v,
                         std::shared_ptr<dessser::gen::sync_key::t const> k) {
  if (v.index() == dessser::gen::sync_value::RamenValue) {
    std::shared_ptr<dessser::gen::raql_value::t const> rv{
        std::get<dessser::gen::sync_value::RamenValue>(v)};
    return raqlValToQString(*rv, k);
  }

  // Fallback to default:
  std::ostringstream s;
  s << v;
  return QString::fromStdString(s.str());
}

QString syncKeyToQString(dessser::gen::sync_key::t const &k) {
  std::ostringstream s;
  s << k;
  return QString::fromStdString(s.str());
}

/* Generic qDebug printer using stringstream: */
template <typename T>
QDebug printerOfStream(QDebug debug, T const &t) {
  QDebugStateSaver saver{debug};
  std::ostringstream s;
  s << t;
  debug << QString::fromStdString(s.str());
  return debug;
}

QDebug operator<<(QDebug debug, dessser::gen::sync_client_cmd::t const &cmd) {
  return printerOfStream<dessser::gen::sync_client_cmd::t>(debug, cmd);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_client_msg::t const &msg) {
  return printerOfStream<dessser::gen::sync_client_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_server_msg::t const &msg) {
  return printerOfStream<dessser::gen::sync_server_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_msg::t const &msg) {
  return printerOfStream<dessser::gen::sync_msg::t>(debug, msg);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_socket::t const &s) {
  return printerOfStream<dessser::gen::sync_socket::t>(debug, s);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_key::t const &k) {
  return printerOfStream<dessser::gen::sync_key::t>(debug, k);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_key::dialog_key const &k) {
  return printerOfStream<dessser::gen::sync_key::dialog_key>(debug, k);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_key::incident_key const &k) {
  return printerOfStream<dessser::gen::sync_key::incident_key>(debug, k);
}

QDebug operator<<(QDebug debug, dessser::gen::sync_value::t const &v) {
  return printerOfStream<dessser::gen::sync_value::t>(debug, v);
}

QDebug operator<<(QDebug debug, dessser::gen::raql_value::t const &v) {
  return printerOfStream<dessser::gen::raql_value::t>(debug, v);
}

QDebug operator<<(QDebug debug, dessser::gen::raql_type::t const &t) {
  return printerOfStream<dessser::gen::raql_type::t>(debug, t);
}

QDebug operator<<(QDebug debug, dessser::gen::raql_type::base const &b) {
  return printerOfStream<dessser::gen::raql_type::base>(debug, b);
}

QDebug operator<<(QDebug debug,
                  dessser::gen::dashboard_widget::chart const &c) {
  return printerOfStream<dessser::gen::dashboard_widget::chart>(debug, c);
}

QDebug operator<<(QDebug debug, dessser::gen::fq_function_name::t const &n) {
  return printerOfStream<dessser::gen::fq_function_name::t>(debug, n);
}

QDebug operator<<(QDebug debug, dessser::gen::rc_entry::t const &e) {
  return printerOfStream<dessser::gen::rc_entry::t>(debug, e);
}

QDebug operator<<(QDebug debug, dessser::gen::replay::t const &r) {
  return printerOfStream<dessser::gen::replay::t>(debug, r);
}

QDebug operator<<(QDebug debug, dessser::gen::alerting_log::t const &l) {
  return printerOfStream<dessser::gen::alerting_log::t>(debug, l);
}

QDebug operator<<(QDebug debug, std::string const &s) {
  QDebugStateSaver saver{debug};
  debug << QString::fromStdString(s);
  return debug;
}
