#ifndef DASHBOARD_TOOLS_H_200304
#define DASHBOARD_TOOLS_H_200304
#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <QString>

#include "KValue.h"

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
  }
}

#ifdef WITH_DASHBOARDS
std::pair<QString const, std::string const> dashboardNameAndPrefOfKey(
  dessser::gen::sync_key::t const &);

QString const dashboardNameOfKey(dessser::gen::sync_key::t const &);

std::string const dashboardPrefixOfKey(dessser::gen::sync_key::t const &);

void iterDashboards(
  std::function<void(std::string const &key, KValue const &,
                     QString const &, std::string const &key_prefix)>);

/* Returns the number of widgets defined in the dashboard which key prefix is
 * given. Prefix ends with the name of the dashboard (without trailing slash) */
int dashboardNumWidgets(std::string const &key_prefix);
#endif

std::optional<uint32_t> widgetIndexOfKey(dessser::gen::sync_key::t const &);

void iterDashboardWidgets(
  std::string const &dash_name,  // or empty for scratchpad
  // Called back with the widget key and its value:
  std::function<void(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &)>);

/* Returns the next available widget number in the dashboard identified by
 * that name (or the scratchpad if name is empty): */
uint32_t dashboardNextWidget(std::string const &dash_name);

#define SCRATCHPAD ""

#endif
