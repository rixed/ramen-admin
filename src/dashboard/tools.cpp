#include <algorithm>
#include <optional>
#include <QDebug>

#include "ConfClient.h"
#include "desssergen/sync_key.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc.h"

#include "dashboard/tools.h"

#ifdef WITH_DASHBOARDS
// FIXME: returns the name of the dashboard and a function to return the widget key
std::pair<QString const, uint32_t const> dashboardNameAndPrefOfKey(
  dessser::gen::sync_key::t const &key)
{
  assert(client && client->syncSocket);

  if (key.index() == dessser::gen::sync_key::Dashboards) {
    auto const &dashboards {
      std::get<dessser::gen::sync_key::Dashboards>(key) };
    Q_ASSERT(dashboards.index() == dessser::gen::sync_key::Widgets);
    auto const &widgets {
      std::get<dessser::gen::sync_key::Widgets>(dashboards) };
    return std::make_pair(QString::fromStdString(std::get<0>(dashboards)),
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

QString const dashboardNameOfKey(dessser::gen::sync_key::t const &key)
{
  return dashboardNameAndPrefOfKey(key).first;
}

std::string const dashboardPrefixOfKey(dessser::gen::sync_key::t const &key)
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
    dessser::gen::sync_key::t const &key = it->first;
    KValue const &value = it->second;
    std::pair<QString const, std::string const> name_pref =
      dashboardNameAndPrefOfKey(key);
    if (! name_pref.first.isEmpty())
      f(key, value, name_pref.first, name_pref.second);
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
#endif

std::optional<uint32_t> widgetIndexOfKey(dessser::gen::sync_key::t const &key)
{
  std::shared_ptr<dessser::gen::sync_key::per_dash_key> per_dash_key;

  switch (key.index()) {
    case dessser::gen::sync_key::PerClient:
      {
        auto const &per_client { std::get<dessser::gen::sync_key::PerClient>(key) };
        std::shared_ptr<dessser::gen::sync_key::per_client const> per_client_data {
          std::get<1>(per_client) };
        if (per_client_data->index() != dessser::gen::sync_key::Scratchpad) break;
        per_dash_key = std::get<dessser::gen::sync_key::Scratchpad>(*per_client_data);
      }
      break;
    case dessser::gen::sync_key::Dashboards:
      {
        auto const &per_dash { std::get<dessser::gen::sync_key::Dashboards>(key) };
        per_dash_key = std::get<1>(per_dash);
      }
      break;
    default:
      break;
  }

  if (per_dash_key)
    return std::get<dessser::gen::sync_key::Widgets>(*per_dash_key);
  else
    return std::nullopt;
}

void iterDashboardWidgets(
  std::string const &dash_name,
  std::function<void(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &)> f)
{
  /* We need to scan the whole map: */
  kvs->lock.lock_shared();
  for (std::pair<std::shared_ptr<dessser::gen::sync_key::t const>, KValue> const p : kvs->map) {
    std::shared_ptr<dessser::gen::sync_key::t const> key { p.first };
    std::shared_ptr<dessser::gen::sync_key::per_dash_key> per_dash_key;
    if (dash_name.size() == 0) {  // Skip all keys but widgets from the scratchpad:
      if (key->index() != dessser::gen::sync_key::PerClient) continue;
      auto const &per_client { std::get<dessser::gen::sync_key::PerClient>(*key) };
      std::shared_ptr<dessser::gen::sync_socket::t const> sock {
        std::get<0>(per_client) };
      if (*sock != *Menu::getClient()->syncSocket) continue;
      std::shared_ptr<dessser::gen::sync_key::per_client const> per_client_data {
        std::get<1>(per_client) };
      if (per_client_data->index() != dessser::gen::sync_key::Scratchpad) continue;
      per_dash_key = std::get<dessser::gen::sync_key::Scratchpad>(*per_client_data);
    } else {  // Skip all keys but that dashboard widgets:
      if (key->index() != dessser::gen::sync_key::Dashboards) continue;
      auto const &per_dash { std::get<dessser::gen::sync_key::Dashboards>(*key) };
      if (std::get<0>(per_dash) != dash_name) continue;
      per_dash_key = std::get<1>(per_dash);
    }
    KValue const &value { p.second };
    if (per_dash_key->index() != dessser::gen::sync_key::Widgets) continue;
    f(key, value);
  }
  kvs->lock.unlock_shared();
}

uint32_t dashboardNextWidget(std::string const &dash_name)
{
  std::optional<uint32_t> num;

  iterDashboardWidgets(dash_name,
    [&num](std::shared_ptr<dessser::gen::sync_key::t const> k, KValue const &) {
      std::optional<uint32_t> n { widgetIndexOfKey(*k) };
      Q_ASSERT(n.has_value());
      num = num ? std::max(*num, *n) : *n;
  });

  return num ? *num + 1 : 0;
}
