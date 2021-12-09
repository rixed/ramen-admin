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

// Returns true if this key is that of a dashboard
bool isDashboardKey(dessser::gen::sync_key::t const &);

// Returns the dashboard name (SCRATCHPAD for the scratchpad)
std::string const dashboardNameOfKey(dessser::gen::sync_key::t const &);

/* For each defined dashboard, call that function with its name */
void iterDashboards(std::function<void(std::string const &)>);

/* Returns the number of widgets defined in the dashboard which name is given */
int dashboardNumWidgets(std::string const &dash_name);

std::optional<uint32_t> widgetIndexOfKey(dessser::gen::sync_key::t const &);

// Iter over widget indexes in ascending order
void iterDashboardWidgets(
  std::string const &dash_name,  // SCRATCHPAD for scratchpad
  // Called back with the widget key and its value:
  std::function<void(std::shared_ptr<dessser::gen::sync_key::t const>, KValue const &)>);

/* Returns the next available widget key in the dashboard identified by
 * that name: */
std::shared_ptr<dessser::gen::sync_key::t> dashboardNextWidget(std::string const &dash_name);

#define SCRATCHPAD "scratchpad"
inline bool isScratchpad(std::string const &dash_name) {
  return dash_name == SCRATCHPAD;
}

#endif
