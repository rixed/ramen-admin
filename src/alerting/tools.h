// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TOOLS_H_200525
#define TOOLS_H_200525
#include <functional>
#include <memory>
#include <mutex>
#include <optional>
#include <string>

#include "desssergen/sync_key.h"

namespace dessser {
namespace gen {
namespace alerting_log {
struct t;
}
namespace alerting_notification {
struct t;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

void iterTeams(std::function<void(std::string const &)>);

void iterIncidents(std::function<void(std::string const &)>);

void iterDialogs(std::string const &incident_id,
                 std::function<void(std::string const &)>);

// In no particular order:
void iterLogs(
    std::string const &incident_id,
    std::function<void(double,
                       std::shared_ptr<dessser::gen::alerting_log::t const>)>);

bool parseLogKey(dessser::gen::sync_key::t const &, std::string *incident_id,
                 double *time);

std::shared_ptr<dessser::gen::alerting_notification::t const> getIncidentNotif(
    std::string const &incident_id,
    std::shared_ptr<dessser::gen::sync_key::incident_key const>);

std::shared_ptr<std::string const> getAssignedTeam(
    std::string const &incident_id);

std::shared_ptr<dessser::gen::sync_key::t const> dialogKey(
    std::string const &incident_id, std::string const &dialog_id,
    std::shared_ptr<dessser::gen::sync_key::dialog_key const>);

std::shared_ptr<dessser::gen::sync_value::t const> getDialog(
    std::string const &incident_id, std::string const &dialog_id,
    std::shared_ptr<dessser::gen::sync_key::dialog_key const>);

/* Same as above but returns a float directly: */
std::optional<double> getDialogDate(
    std::string const &incident_id, std::string const &dialog_id,
    std::shared_ptr<dessser::gen::sync_key::dialog_key const>);

#endif
