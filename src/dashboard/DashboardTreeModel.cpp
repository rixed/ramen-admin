#include <string>
#include <QDebug>

#include "ConfClient.h"
#include "dashboard/tools.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc.h"

#include "dashboard/DashboardTreeModel.h"

static bool const verbose { false };

DashboardTreeModel *DashboardTreeModel::globalDashboardTree;

DashboardTreeModel::DashboardTreeModel(QObject *parent)
  : ConfTreeModel(parent)
{
  /* We start with no scratchpad widgets, but we'd like a scratchpad entry
   * nonetheless so add it manually: */
  QStringList names { SCRATCHPAD };
  (void)findOrCreate(root, names, QString());

  connect(kvs.get(), &KVStore::keyChanged,
          this, &DashboardTreeModel::onChange);
}

void DashboardTreeModel::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    if (! isDashboardKey(*change.key)) continue;
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
  std::string const dash_name { dashboardNameOfKey(*key) };

  if (isScratchpad(dash_name)) return;

  QStringList names { QString::fromStdString(dash_name).split('/') };

  if (verbose)
    qDebug()
      << "DashboardTreeModel::updateNames: from name" << QString::fromStdString(dash_name)
      << "to path:" << names;

  (void)findOrCreate(root, names, QString::fromStdString(dash_name));
}

void DashboardTreeModel::deleteNames(
  std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &)
{
  std::string const dash_name { dashboardNameOfKey(*key) };
  if (isScratchpad(dash_name)) return;

  // TODO: actually delete? Or keep the names around for a bit?
}
