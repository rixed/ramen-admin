#include <cassert>
#include <QAbstractItemModel>
#include <QDebug>
#include <QtGlobal>
#include <QVariant>

#include "ConfSubTree.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/worker.h"
#include "KVStore.h"
#include "misc.h"
#include "misc_dessser.h"

#include "NamesTree.h"

static bool const verbose(false);

NamesTree *NamesTree::globalNamesTree;
NamesTree *NamesTree::globalNamesTreeAnySites;

/*
 * The NamesTree itself:
 *
 * Also a model.
 * We then have a proxy than select only a subtree.
 */

NamesTree::NamesTree(bool withSites_, QObject *parent)
  : ConfTreeModel(parent), withSites(withSites_)
{
  connect(kvs.get(), &KVStore::keyChanged,
          this, &NamesTree::onChange);
}

void NamesTree::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyCreated:
      case KeyChanged:
        updateNames(*change.key, change.kv);
        break;
      case KeyDeleted:
        deleteNames(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

std::pair<std::string, std::string> NamesTree::pathOfIndex(
  QModelIndex const &index) const
{
  std::pair<std::string, std::string> ret; // { std::string(), std::string() };

  if (! index.isValid()) return ret;

  ConfSubTree *s = static_cast<ConfSubTree *>(index.internalPointer());

  if (!s->isTerm() && verbose)
    qWarning() << s->name << "is not a terminal yet is on term position";

  while (s != root) {
    std::string *n = s->isTerm() ? &ret.second : &ret.first;
    if (! n->empty()) n->insert(0, "/");
    n->insert(0, s->name.toStdString());
    s = s->parent;
  }

  return ret;
}

void NamesTree::updateNames(dessser::gen::sync_key::t const &key, KValue const &kv)
{
  if (key.index() != dessser::gen::sync_key::PerSite) return;
  std::shared_ptr<dessser::gen::sync_key::per_site const> per_site {
    std::get<dessser::gen::sync_key::PerSite>(key) };
  std::string const &site_name { std::get<0>(*per_site) };
  std::shared_ptr<dessser::gen::sync_key::per_site_data const> per_site_data {
    std::get<1>(*per_site) };
  if (per_site_data->index() != dessser::gen::sync_key::PerWorker) return;
  std::shared_ptr<dessser::gen::sync_key::per_worker const> per_worker {
    std::get<dessser::gen::sync_key::PerWorker>(*per_site_data) };
  std::string const &fq_name { std::get<0>(*per_worker) };
  std::shared_ptr<dessser::gen::sync_key::per_worker_data const> per_worker_data {
    std::get<1>(*per_worker) };
  if (per_worker_data->index() != dessser::gen::sync_key::Worker) return;

  if (kv.val->index() != dessser::gen::sync_value::Worker) [[unlikely]] {
    qCritical() << "Not a worker!?";
    return;
  }
  std::shared_ptr<dessser::gen::worker::t const> worker {
    std::get<dessser::gen::sync_value::Worker>(*kv.val) };

  if (worker->role.index() != dessser::gen::worker::Whole) return;

  /* Get the site name, program name list and function name: */

  QString const site { QString::fromStdString(site_name) };

  // Locate the function name at the end:
  size_t const j { fq_name.rfind('/') };
  if (j == std::string::npos || j == 0 || j >= fq_name.size() - 1) {
    qCritical() << "Invalid fq_name:" << QString::fromStdString(fq_name);
    return;
  }

  // Everything in between in the program name:
  std::string const prog_name { fq_name.substr(0, j) };
  std::string const src_path { srcPathFromProgramName(prog_name) };
  QString const programs { QString::fromStdString(prog_name) };
  QStringList const program { programs.split('/', Qt::SkipEmptyParts) };
  std::string const function_name { fq_name.substr(j + 1) };
  QString const function { QString::fromStdString(function_name) };

  if (verbose)
    qDebug() << "NamesTree: found" << site << "/ "
              << programs << "/" << function;

  QStringList names(QStringList(site) << program << function);
  if (! withSites) names.removeFirst();

  ConfSubTree *func { findOrCreate(root, names, QString()) };

  /* Now get the field names */

  /* In theory keys are synced in the same order as created so we should
   * received the source info before any worker using it during a sync: */
  dessser::gen::sync_key::t const infoKey {
    std::in_place_index<dessser::gen::sync_key::Sources>,
    src_path,
    "info" };

  std::shared_ptr<dessser::gen::source_info::t const> sourceInfos;

  kvs->lock.lock_shared();
  auto it =
    kvs->map.find(std::shared_ptr<dessser::gen::sync_key::t const>(
      &infoKey, /* No del */[](dessser::gen::sync_key::t const *){}));
  if (it != kvs->map.end()) {
    std::shared_ptr<dessser::gen::sync_value::t const> v { it->second.val };
    if (v->index() == dessser::gen::sync_value::SourceInfo) [[likely]] {
      sourceInfos = std::shared_ptr<dessser::gen::source_info::t const>(
                      std::get<dessser::gen::sync_value::SourceInfo>(*v));
    } else {
      qCritical() << "Not a SourceInfo!?";
    }
  }
  kvs->lock.unlock_shared();

  if (! sourceInfos) {
    if (verbose)
      qDebug() << "NamesTree: No source info yet for" << infoKey;
    return;
  }

  if (sourceInfos->detail.index() != dessser::gen::source_info::Compiled) {
    if (verbose)
      qDebug() << "NamesTree:" << infoKey << "not compiled yet";
    return;
  }

  std::shared_ptr<dessser::gen::source_info::compiled_program> compiled {
    std::get<dessser::gen::source_info::Compiled>(sourceInfos->detail) };

  /* In the sourceInfos all functions of that program could be found, but for
   * simplicity let's add only the one we came for: */
  for (std::shared_ptr<dessser::gen::source_info::compiled_func const> info : compiled->funcs) {
    if (info->name != function_name) continue;

    unsigned const num_cols { numColumns(*info->out_record) };
    /* FIXME: Each column could have subcolumns and all should be inserted
     * hierarchically. */
    /* Some type info for the field (stored in the model as UserType+... would
     * come handy, for instance to determine if a field is numeric, or a
     * factor, etc */
    for (unsigned i = 0; i < num_cols; i++) {
      QString const col { QString::fromStdString(columnName(*info->out_record, i)) };
      QStringList names(col);
      (void)findOrCreate(func, names, names.last());
    }
    break;
  }

/*  if (verbose) {
    qDebug() << "NamesTree: Current names-tree:";
    dump();
  }*/
}

void NamesTree::deleteNames(dessser::gen::sync_key::t const &key, KValue const &)
{
  if (! isAWorker(key)) return;

  // TODO: actually delete? Or keep the names around for a bit?
}

/*
 * If we are already in the subtree, then to ensure we do not leave it the only
 * function that require adapting is parent() (so we do not leave the subtree
 * up the root). index() also need to be adapted to enumeration starts from the
 * subtree.
 */

NamesSubtree::NamesSubtree(NamesTree const &namesTree, QModelIndex const &newRoot_)
  : NamesTree(namesTree.withSites),
    newRoot(newRoot_)
{
  /* This new NamesTree will update itself from conftree signals, but let's
   * copy the passed namesTree to not start from empty: */
  delete root;
  root = new ConfSubTree(*(namesTree.root), nullptr);
}

QModelIndex NamesSubtree::index(int row, int column, QModelIndex const &parent) const
{
  if (! parent.isValid()) {
    return NamesTree::index(row, column, newRoot);
  }
  return NamesTree::index(row, column, parent);
}

QModelIndex NamesSubtree::parent(QModelIndex const &index) const
{
  if (index == newRoot) return QModelIndex();

  return NamesTree::parent(index);
}

int NamesSubtree::rowCount(QModelIndex const &index) const
{
  return NamesTree::rowCount(index.isValid() ? index : QModelIndex(newRoot));
}

int NamesSubtree::columnCount(QModelIndex const &index) const
{
  return NamesTree::columnCount(index.isValid() ? index : QModelIndex(newRoot));
}

QVariant NamesSubtree::data(QModelIndex const &index, int role) const
{
  return NamesTree::data(index.isValid() ? index : QModelIndex(newRoot), role);
}

/*
 * Just teach QCompleter how to convert a string to/from a path:
 */

NamesCompleter::NamesCompleter(
  NamesTree *model, QObject *parent, QModelIndex const &newRoot_)
  : QCompleter(model, parent),
    newRoot(newRoot_)
{
  if (verbose)
    qDebug() << "NamesCompleter: root label:"
             << (newRoot.isValid() ? model->data(newRoot, Qt::DisplayRole) : "");

  setCompletionRole(Qt::DisplayRole);
  setModelSorting(QCompleter::CaseSensitivelySortedModel);
}

QStringList NamesCompleter::splitPath(QString const &path_) const
{
  QString path(path_);
  QAbstractItemModel const *mod = model();

  for (QModelIndex i = newRoot; i.isValid(); i = mod->parent(i)) {
    if (! path.isEmpty()) path.prepend('/');
    path.prepend(mod->data(i, Qt::DisplayRole).toString());
  }

  /* Would be nice to SkipEmptyParts, but the last one must not be skipped, or
   * the completer would not jump to the next level of the tree. */
  return path.split('/');
}

QString NamesCompleter::pathFromIndex(QModelIndex const &index) const
{
  if (!index.isValid()) {
    // possible when newRoot is the root
    assert(!newRoot.isValid());
    return QString(); // Path from model root
  }

  ConfSubTree *tree = static_cast<ConfSubTree *>(index.internalPointer());

  QString ret(tree->name);

  ConfSubTree *root =
    newRoot.isValid() ?
      static_cast<ConfSubTree *>(QModelIndex(newRoot).internalPointer()) : nullptr;
  if (verbose)
    qDebug() << "NamesCompleter: root@" << root << ":" << root->name;

  while (tree->parent && tree->parent->parent && tree->parent != root) {
    tree = tree->parent;
    if (verbose)
      qDebug() << "NamesCompleter: tree@" << tree;
    ret.prepend('/');
    ret.prepend(tree->name);
  }

  return ret;
}
