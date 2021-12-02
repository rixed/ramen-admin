#include <cassert>
#include <string>
#include <QDebug>

#include "ConfClient.h"
#include "dashboard/tools.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc.h"

#include "dashboard/DashboardTreeModel.h"

static bool const verbose(false);

DashboardTreeModel *DashboardTreeModel::globalDashboardTree;

DashboardTreeModel::DashboardTreeModel(QObject *parent)
  : ConfTreeModel(parent),
    addedScratchpad(false)
{
  addScratchpad();

  connect(kvs.get(), &KVStore::keyChanged,
          this, &DashboardTreeModel::onChange);
}

void DashboardTreeModel::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyCreated:
      case KeyChanged:
        updateNames(change.key, change.kv);
        break;
      case KeyDeleted:
        deleteNames(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void DashboardTreeModel::updateNames(
  std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &)
{
  addScratchpad();

  std::string const dash_name { dashboardNameOfKey(*key) };

  if (isScratchpad(dash_name)) return;

  if (verbose)
    qDebug() << "DashboardTreeModel: found" << QString::fromStdString(dash_name);

  QStringList names { QString::fromStdString(dash_name).split('/') };

  (void)findOrCreate(root, names, QString::fromStdString(dash_name));
}

void DashboardTreeModel::deleteNames(
  std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &)
{
  addScratchpad();

  std::string const dash_name { dashboardNameOfKey(*key) };
  if (isScratchpad(dash_name)) return;

  // TODO: actually delete? Or keep the names around for a bit?
}

void DashboardTreeModel::addScratchpad()
{
  std::shared_ptr<dessser::gen::sync_socket::t const> my_socket {
    Menu::getClient()->syncSocket };
  if (addedScratchpad || !my_socket) return;

  /* We start with no scratchpad widgets, but we'd like a scratchpad entry
   * nonetheless so add it manually: */
  QStringList names({ "scratchpad" });
  (void)findOrCreate(root, names, QString());
  addedScratchpad = true;
}
