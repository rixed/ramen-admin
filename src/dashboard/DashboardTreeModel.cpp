// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "dashboard/DashboardTreeModel.h"

#include <QDebug>
#include <string>

#include "ConfClient.h"
#include "ConfSubTree.h"
#include "KVStore.h"
#include "Menu.h"
#include "dashboard/tools.h"
#include "misc.h"

static bool const verbose{false};

DashboardTreeModel *DashboardTreeModel::globalDashboardTree;

DashboardTreeModel::DashboardTreeModel(QObject *parent)
    : ConfTreeModel(parent) {
  /* We start with no scratchpad widgets, but we'd like a scratchpad entry
   * nonetheless so add it manually: */
  QStringList names{SCRATCHPAD};
  (void)findOrCreate(root, names, QString(SCRATCHPAD));
}

void DashboardTreeModel::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    if (!isDashboardKey(*change.key)) continue;
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
    std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &) {
  std::string const dash_name{dashboardNameOfKey(*key)};

  if (isScratchpad(dash_name)) return;

  QStringList names{QString::fromStdString(dash_name).split('/')};

  if (verbose)
    qDebug() << "DashboardTreeModel::updateNames: from name"
             << QString::fromStdString(dash_name) << "to path:" << names;

  (void)findOrCreate(root, names, QString::fromStdString(dash_name));
}

void DashboardTreeModel::deleteNames(
    std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &) {
  std::string const dash_name{dashboardNameOfKey(*key)};
  if (isScratchpad(dash_name)) return;

  // TODO: actually delete? Or keep the names around for a bit?
}

Qt::ItemFlags DashboardTreeModel::flags(QModelIndex const &index) const {
  Q_ASSERT(index.isValid());
  Qt::ItemFlags f{ConfTreeModel::flags(index)};

  ConfSubTree *tree{static_cast<ConfSubTree *>(index.internalPointer())};
  if (tree->isTerm())
    return f;
  else
    return f & (~Qt::ItemIsSelectable);
}
