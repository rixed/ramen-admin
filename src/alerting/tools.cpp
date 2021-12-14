#include <set>
#include <utility>
#include <QDebug>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/raql_value.h"
#include "desssergen/alerting_notification.h"
#include "KVStore.h"
#include "misc_dessser.h"

#include "alerting/tools.h"

static bool const verbose { false };

std::shared_ptr<dessser::gen::sync_key::t const> incidentKey(
  std::string const &incident_id,
  std::shared_ptr<dessser::gen::sync_key::incident_key const> k)
{
  return std::make_shared<dessser::gen::sync_key::t>(
    std::in_place_index<dessser::gen::sync_key::Incidents>,
    std::make_tuple(incident_id,
                    std::const_pointer_cast<dessser::gen::sync_key::incident_key>(k)));
}

std::shared_ptr<dessser::gen::sync_value::t const> getIncident(
  std::string const &incident_id,
  std::shared_ptr<dessser::gen::sync_key::incident_key const> k)
{
  return kvs->get(incidentKey(incident_id, k));
}

std::shared_ptr<dessser::gen::alerting_notification::t const> getIncidentNotif(
  std::string const &incident_id,
  std::shared_ptr<dessser::gen::sync_key::incident_key const> k)
{
  std::shared_ptr<dessser::gen::sync_value::t const> v {
    getIncident(incident_id, k) };
  if (!v || v->index() != dessser::gen::sync_value::Notification)
    return nullptr;
  return std::get<dessser::gen::sync_value::Notification>(*v);
}

std::shared_ptr<std::string const> getAssignedTeam(std::string const &incident_id)
{
  std::shared_ptr<dessser::gen::sync_value::t const> v {
    getIncident(
      incident_id,
      std::make_shared<dessser::gen::sync_key::incident_key>(
        std::in_place_index<dessser::gen::sync_key::Team>, dessser::VOID)) };
  if (!v || v->index() != dessser::gen::sync_value::RamenValue)
    return nullptr;
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*v) };
  if (rv->index() != dessser::gen::raql_value::VString)
    return nullptr;
  return std::shared_ptr<std::string const>(
    &std::get<dessser::gen::raql_value::VString>(*rv),
    /* No del */[](std::string const *){});
}

void iterTeams(
  std::function<void(std::string const &)> f)
{
  kvs->lock.lock_shared();
  std::set<std::string> names;
  for (std::pair<std::shared_ptr<dessser::gen::sync_key::t const>, KValue> const p : kvs->map) {
    std::shared_ptr<dessser::gen::sync_key::t const> key { p.first };
    if (key->index() != dessser::gen::sync_key::Teams) continue;
    std::string const &name {
      std::get<0>(std::get<dessser::gen::sync_key::Teams>(*key)) };
    auto it_new { names.insert(name) };
    if (it_new.second) {
      if (verbose)
        qDebug() << "New teamName:" << QString::fromStdString(name);
      f(name);
    }
  }
  kvs->lock.unlock_shared();
}

void iterIncidents(
  std::function<void(std::string const &)> f)
{
  kvs->lock.lock_shared();
  std::set<std::string> ids;
  for (std::pair<std::shared_ptr<dessser::gen::sync_key::t const>, KValue> const p : kvs->map) {
    std::shared_ptr<dessser::gen::sync_key::t const> key { p.first };
    if (key->index() != dessser::gen::sync_key::Incidents) continue;
    std::string const &incident_id {
      std::get<0>(std::get<dessser::gen::sync_key::Incidents>(*key)) };
    auto it_new { ids.insert(incident_id) };
    if (it_new.second) {
      if (verbose)
        qDebug() << "New incident_id:" << QString::fromStdString(incident_id);
      f(incident_id);
    }
  }
  kvs->lock.unlock_shared();
}

void iterDialogs(
  std::string const &incident_id,
  std::function<void(std::string const &)> f)
{
  kvs->lock.lock_shared();
  std::set<std::string> ids;
  for (std::pair<std::shared_ptr<dessser::gen::sync_key::t const>, KValue> const p : kvs->map) {
    std::shared_ptr<dessser::gen::sync_key::t const> key { p.first };
    if (key->index() != dessser::gen::sync_key::Incidents) continue;
    std::string const &this_incident_id {
      std::get<0>(std::get<dessser::gen::sync_key::Incidents>(*key)) };
    if (this_incident_id != incident_id) continue;
    std::shared_ptr<::dessser::gen::sync_key::incident_key> ikey {
      std::get<1>(std::get<dessser::gen::sync_key::Incidents>(*key)) };
    if (ikey->index() != dessser::gen::sync_key::Dialogs) continue;
    std::string const &dialog_id {
      std::get<0>(std::get<dessser::gen::sync_key::Dialogs>(*ikey)) };
    auto it_new { ids.insert(dialog_id) };
    if (it_new.second) {
      if (verbose)
        qDebug() << "New dialog_id:" << QString::fromStdString(dialog_id);
      f(dialog_id);
    }
  }
  kvs->lock.unlock_shared();
}

void iterLogs(
  std::string const &incident_id,
  std::function<void(double, std::shared_ptr<dessser::gen::alerting_log::t const>)> f)
{
  kvs->lock.lock_shared();
  for (std::pair<std::shared_ptr<dessser::gen::sync_key::t const>, KValue> const p : kvs->map) {
    std::shared_ptr<dessser::gen::sync_key::t const> key { p.first };
    if (key->index() != dessser::gen::sync_key::Incidents) continue;
    std::string const &this_incident_id {
      std::get<0>(std::get<dessser::gen::sync_key::Incidents>(*key)) };
    if (this_incident_id != incident_id) continue;
    std::shared_ptr<::dessser::gen::sync_key::incident_key> ikey {
      std::get<1>(std::get<dessser::gen::sync_key::Incidents>(*key)) };
    if (ikey->index() != dessser::gen::sync_key::Journal) continue;
    double const &time {
      std::get<0>(std::get<dessser::gen::sync_key::Journal>(*ikey)) };
    std::shared_ptr<dessser::gen::sync_value::t const> val { p.second.val };
    if (val->index() != dessser::gen::sync_value::IncidentLog) {
      qCritical() << "iterLogs: Value for key" << *key
                  << "not an IncidentLog (but" << *val << ")";
      continue;
    }
    std::shared_ptr<dessser::gen::alerting_log::t const> log {
      std::get<dessser::gen::sync_value::IncidentLog>(*val) };

    if (verbose)
      qDebug() << "New log for time:" << time << ":" << *log;

    f(time, log);
  }
  kvs->lock.unlock_shared();
}

bool parseLogKey(
  dessser::gen::sync_key::t const &key,
  std::string *incident_id,
  double *time)
{
  if (key.index() != dessser::gen::sync_key::Incidents)
    return false;
  if (incident_id) {
    *incident_id = std::get<0>(std::get<dessser::gen::sync_key::Incidents>(key));
    if (verbose)
      qDebug() << "parseLogKey: Found incident_id"
               << QString::fromStdString(*incident_id);
  }

  std::shared_ptr<dessser::gen::sync_key::incident_key const> ikey {
    std::get<1>(std::get<dessser::gen::sync_key::Incidents>(key)) };
  if (ikey->index() != dessser::gen::sync_key::Journal)
    return false;
  if (time) {
    *time = std::get<0>(std::get<dessser::gen::sync_key::Journal>(*ikey));
    if (verbose)
      qDebug() << "parseLogKey: Found time" << *time;
  }

  return true;
}

std::shared_ptr<dessser::gen::sync_key::t const> dialogKey(
  std::string const &incident_id,
  std::string const &dialog_id,
  std::shared_ptr<dessser::gen::sync_key::dialog_key const> k)
{
  std::shared_ptr<dessser::gen::sync_key::incident_key> incident_key {
    std::make_shared<dessser::gen::sync_key::incident_key>(
      std::in_place_index<dessser::gen::sync_key::Dialogs>,
      std::make_tuple(dialog_id,
                      std::const_pointer_cast<dessser::gen::sync_key::dialog_key>(k))) };
  return incidentKey(incident_id, incident_key);
}

std::shared_ptr<dessser::gen::sync_value::t const> getDialog(
  std::string const &incident_id,
  std::string const &dialog_id,
  std::shared_ptr<dessser::gen::sync_key::dialog_key const> k)
{
  return kvs->get(dialogKey(incident_id, dialog_id, k));
}

std::optional<double> getDialogDate(
  std::string const &incident_id,
  std::string const &dialog_id,
  std::shared_ptr<dessser::gen::sync_key::dialog_key const> k)
{
  std::shared_ptr<dessser::gen::sync_value::t const> val {
    getDialog(incident_id, dialog_id, k) };
  if (! val || val->index() != dessser::gen::sync_value::RamenValue)
    return std::nullopt;
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*val) };
  if (rv->index() != dessser::gen::raql_value::VFloat) {
    qCritical() << "getDialogDate: value for dialog" << *k
                << "is not a float but" << *rv;
    return std::nullopt;
  }
  return std::get<dessser::gen::raql_value::VFloat>(*rv);
}
