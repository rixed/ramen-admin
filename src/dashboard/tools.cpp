#include <algorithm>
#include <optional>
#include <QDebug>
#include "conf.h"
#include "misc.h"

#include "dashboard/tools.h"

// FIXME: returns the name of the dashboard and a function to return the widget key
std::pair<std::string const, uint32_t const> dashboardNameAndPrefOfKey(
  dessser::gen::sync_key::t const &key)
{
  assert(client && client->syncSocket);

  if (key.index() == dessser::gen::sync_key::Dashboards) {
    auto const &dashboards {
      std::get<dessser::gen::sync_key::Dashboards>(key) };
    Q_ASSERT(dashboards.index() == dessser::gen::sync_key::Widgets);
    auto const &widgets {
      std::get<dessser::gen::sync_key::Widgets>(dashboards) };
    return std::make_pair(std::get<0>(dashboards),
                          std::get<0>(widgets));
  } else if (key.index() == dessser::gen::sync_key::PerClient) {
    auto const &per_client {
      std::get<dessser::gen::sync_key::PerClient>(key) };
    if (*client->syncSocket == *std::get<0>(per_client) &&
        std::get<1>(per_client).index() == dessser::gen::sync_key::Scratchpad) {
      return std::make_pair(QString("scratchpad"),
                            client_scratchpad);
  }
err:
  return std::make_pair(QString(), std::string());
}

QString const dashboardNameOfKey(std::string const &key)
{
  return dashboardNameAndPrefOfKey(key).first;
}

std::string const dashboardPrefixOfKey(std::string const &key)
{
  return dashboardNameAndPrefOfKey(key).second;
}

void iterDashboards(
  std::function<void(std::string const &, KValue const &,
                     QString const &, std::string const &)> f)
{
  kvs->lock.lock_shared();
  std::map<std::string const, KValue>::const_iterator const end =
    kvs->map.upper_bound("e");
  for (std::map<std::string const, KValue>::const_iterator it =
         kvs->map.lower_bound("dashboards/");
       it != end ; it++)
  {
    std::string const &key = it->first;
    KValue const &value = it->second;
    std::pair<QString const, std::string const> name_pref =
      dashboardNameAndPrefOfKey(key);
    if (! name_pref.first.isEmpty())
      f(key, value, name_pref.first, name_pref.second);
  }
  // TODO: Also the users/.../scratchpad keys!
  kvs->lock.unlock_shared();
}

std::optional<int> widgetIndexOfKey(std::string const &key)
{
  std::string const key_prefix = dashboardPrefixOfKey(key);
  if (key_prefix.empty()) return std::nullopt;

  size_t end;
  int const n =
    std::stoi(key.substr(key_prefix.length() + strlen("/widgets/")), &end);
  if (end == 0) return std::nullopt;
  return n;
}

void iterDashboardWidgets(
  std::string const &key_prefix,
  std::function<void(std::string const &, KValue const &, int)> f)
{
  kvs->lock.lock_shared();
  std::map<std::string const, KValue>::const_iterator const end =
    kvs->map.upper_bound(key_prefix + "/x");
  std::string const tot_prefix(key_prefix + "/widgets/");
  for (std::map<std::string const, KValue>::const_iterator it =
          kvs->map.lower_bound(tot_prefix);
       it != end ; it++)
  {
    std::string const &key = it->first;
    KValue const &value = it->second;
    if (! startsWith(key, tot_prefix)) continue;
    std::optional<int> const idx = widgetIndexOfKey(key);
    if (idx) f(key, value, *idx);
  }
  // TODO: Also the users/.../scratchpad keys!
  kvs->lock.unlock_shared();
}

int dashboardNumWidgets(std::string const &key_prefix)
{
  int num(0);

  iterDashboardWidgets(key_prefix,
    [&num](std::string const &, KValue const &, int) {
      num++;
  });

  return num;
}

int dashboardNextWidget(std::string const &key_prefix)
{
  int num(-1);

  iterDashboardWidgets(key_prefix,
    [&num](std::string const &, KValue const &, int n) {
      num = std::max(num, n);
  });

  return num + 1;
}
