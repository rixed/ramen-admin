#include <algorithm>
#include <optional>
#include <QDebug>

#include "ConfClient.h"
#include "desssergen/sync_key.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc.h"

#include "dashboard/tools.h"

bool isDashboardKey(dessser::gen::sync_key::t const &key)
{
  if (key.index() == dessser::gen::sync_key::Dashboards) {
    return true;
  } else if (key.index() == dessser::gen::sync_key::PerClient) {
    auto const &per_client {
      std::get<dessser::gen::sync_key::PerClient>(key) };
    if (*Menu::getClient()->syncSocket == *std::get<0>(per_client) &&
        std::get<1>(per_client)->index() == dessser::gen::sync_key::Scratchpad)
      return true;
  }

  return false;
}

std::string const dashboardNameOfKey(dessser::gen::sync_key::t const &key)
{
  if (key.index() == dessser::gen::sync_key::Dashboards) {
    auto const &dashboards {
      std::get<dessser::gen::sync_key::Dashboards>(key) };
    return std::get<0>(dashboards);
  } else if (key.index() == dessser::gen::sync_key::PerClient) {
    auto const &per_client {
      std::get<dessser::gen::sync_key::PerClient>(key) };
    if (*Menu::getClient()->syncSocket == *std::get<0>(per_client) &&
        std::get<1>(per_client)->index() == dessser::gen::sync_key::Scratchpad)
      return "";
  }

  Q_ASSERT(false);
}

void iterDashboards(std::function<void(std::string const &)> f)
{
  // Remember dashboard already visited to call [f] only once per dashboard:
  std::unordered_set<std::string> visited;

  kvs->lock.lock_shared();
  for (std::pair<std::shared_ptr<dessser::gen::sync_key::t const>, KValue> const p : kvs->map) {
    std::shared_ptr<dessser::gen::sync_key::t const> key { p.first };
    std::shared_ptr<dessser::gen::sync_key::t const> to_visit;

    switch (key->index()) {
      case dessser::gen::sync_key::PerClient:
        {
          auto const &per_client { std::get<dessser::gen::sync_key::PerClient>(*key) };
          std::shared_ptr<dessser::gen::sync_socket::t const> sock {
            std::get<0>(per_client) };
          if (*sock != *Menu::getClient()->syncSocket) break;
          std::shared_ptr<dessser::gen::sync_key::per_client const> per_client_data {
            std::get<1>(per_client) };
          if (per_client_data->index() != dessser::gen::sync_key::Scratchpad) break;
          to_visit = key;
        }
        break;
      case dessser::gen::sync_key::Dashboards:
        to_visit = key;
        break;
      default:
        break;
    }

    if (to_visit) {
      std::string const dash_name { dashboardNameOfKey(*to_visit) };
      if (visited.find(dash_name) == visited.end()) {
        visited.insert(dash_name);
        f(dash_name);
      }
    }
  }

  kvs->lock.unlock_shared();
}

int dashboardNumWidgets(std::string const &dash_name)
{
  int num { 0 };

  iterDashboardWidgets(dash_name,
    [&num](std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &) { num++; });

  return num;
}

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
  /* Reminder: kvs->map is not sorted. Therefore to map must be scanned first, and
   * the list of keys ordered by indices before calling [f]. */
  std::map<uint32_t,
           std::pair<std::shared_ptr<dessser::gen::sync_key::t const>,
                     KValue const &>> widgets;
  kvs->lock.lock_shared();
  for (std::pair<std::shared_ptr<dessser::gen::sync_key::t const>, KValue> const &p : kvs->map) {
    std::shared_ptr<dessser::gen::sync_key::t const> key { p.first };
    std::shared_ptr<dessser::gen::sync_key::per_dash_key> per_dash_key;
    if (isScratchpad(dash_name)) {  // Skip all keys but widgets from the scratchpad:
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
    std::optional<uint32_t> const idx { widgetIndexOfKey(*key) };
    Q_ASSERT(idx);
    widgets.emplace(*idx, std::make_pair(key, value));
  }

  /* Still holding the KVS->map lock so that the callback can assume those dashboard
   * widgets do exist, call [f]: */
  for (auto const &k_v : widgets) {
    std::shared_ptr<dessser::gen::sync_key::t const> const &key { k_v.second.first };
    KValue const &value { k_v.second.second };
    f(key, value);
  }
  kvs->lock.unlock_shared();
}

std::shared_ptr<dessser::gen::sync_key::t> dashboardNextWidget(std::string const &dash_name)
{
  std::optional<uint32_t> num;

  iterDashboardWidgets(dash_name,
    [&num](std::shared_ptr<dessser::gen::sync_key::t const> k, KValue const &) {
      std::optional<uint32_t> n { widgetIndexOfKey(*k) };
      Q_ASSERT(n.has_value());
      num = num ? std::max(*num, *n) : *n;
  });

  uint32_t const idx { num ? *num + 1 : 0 };

  std::shared_ptr<dessser::gen::sync_key::per_dash_key> per_dash_key {
    std::make_shared<dessser::gen::sync_key::per_dash_key>(
      std::in_place_index<dessser::gen::sync_key::Widgets>, idx) };

  if (isScratchpad(dash_name)) {
    return
      std::make_shared<dessser::gen::sync_key::t>(
        std::in_place_index<dessser::gen::sync_key::PerClient>,
        std::const_pointer_cast<dessser::gen::sync_socket::t>(Menu::getClient()->syncSocket),
        std::make_shared<dessser::gen::sync_key::per_client>(
          std::in_place_index<dessser::gen::sync_key::Scratchpad>,
          per_dash_key));
  } else {
    return
      std::make_shared<dessser::gen::sync_key::t>(
        std::in_place_index<dessser::gen::sync_key::Dashboards>,
        dash_name,
        per_dash_key);
  }
}
