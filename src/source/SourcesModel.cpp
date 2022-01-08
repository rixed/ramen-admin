// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "SourcesModel.h"

#include <QAbstractItemModel>
#include <QApplication>
#include <QDebug>
#include <QStyle>
#include <QtGlobal>

#include "KVStore.h"
#include "KValue.h"
#include "Resources.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"

static bool const verbose{false};

SourcesModel::SourcesModel(QObject *parent) : QAbstractItemModel(parent) {
  root = new DirItem("");

  connect(kvs.get(), &KVStore::keyChanged, this, &SourcesModel::onChange);
}

void SourcesModel::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
        addSource(*change.key, change.kv);
        break;
      case KeyDeleted:
        delSource(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

QModelIndex SourcesModel::index(int row, int column,
                                QModelIndex const &parent) const {
  if (row < 0 || column < 0 || column >= NumColumns) return QModelIndex();

  DirItem const *parentDir =
      parent.isValid() ? static_cast<DirItem const *>(parent.internalPointer())
                       : root;
  if (!parentDir) return QModelIndex();

  if (row >= parentDir->numRows()) return QModelIndex();
  return createIndex(row, column, parentDir->children[row]);
}

QModelIndex SourcesModel::parent(QModelIndex const &index) const {
  if (!index.isValid()) return QModelIndex();
  TreeItem const *item = static_cast<TreeItem const *>(index.internalPointer());
  if (!item->parent) return QModelIndex();
  return indexOfItem(item->parent);
}

int SourcesModel::rowCount(QModelIndex const &parent) const {
  TreeItem const *item =
      parent.isValid() ? static_cast<TreeItem const *>(parent.internalPointer())
                       : root;
  return item->numRows();
}

int SourcesModel::columnCount(QModelIndex const &) const { return NumColumns; }

QVariant SourcesModel::data(QModelIndex const &index, int role) const {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 11, 0))
  Q_ASSERT(
      checkIndex(index, QAbstractItemModel::CheckIndexOption::IndexIsValid));
#endif
  if (!index.isValid()) return QVariant();

  TreeItem const *item = static_cast<TreeItem const *>(index.internalPointer());

  switch (role) {
    case Qt::DisplayRole:
      switch (index.column()) {
        case SrcPath:
          return QVariant(item->name);
        case Action1: {
          // Button to show the compilation result:
          if (item->isDir()) return QVariant();
          std::shared_ptr<dessser::gen::source_info::t const> info{
              sourceInfoOfItem(item)};
          if (!info) {
            return QVariant();
          } else if (info->detail.index() ==
                     dessser::gen::source_info::Compiled) {
            return Resources::get()->infoPixmap;
          } else {
            Q_ASSERT(info->detail.index() == dessser::gen::source_info::Failed);
            return Resources::get()->errorPixmap;
          }
        }
        case Action2: {
          // Button to run the program
          if (item->isDir()) return QVariant();
          std::shared_ptr<dessser::gen::source_info::t const> info{
              sourceInfoOfItem(item)};
          if (!info) {
            return Resources::get()->waitPixmap;
          } else if (info->detail.index() ==
                     dessser::gen::source_info::Compiled) {
            return Resources::get()->playPixmap;
          } else {
            Q_ASSERT(info->detail.index() == dessser::gen::source_info::Failed);
            return QVariant();
          }
        }
        default:
          return QVariant();
      }
      break;
    default:
      return QVariant();
  }
}

// Returns the source name (without extension):
QString const baseNameOfKey(dessser::gen::sync_key::t const &k) {
  if (k.index() != dessser::gen::sync_key::Sources) {
    qDebug() << "Key" << k << "is invalid for a source";
    return QString();
  } else {
    auto const &sources{std::get<dessser::gen::sync_key::Sources>(k)};
    return QString::fromStdString(std::get<0>(sources));
  }
}

// Returns the file name (source path + extension):
QString const sourceNameOfKey(dessser::gen::sync_key::t const &k) {
  if (k.index() != dessser::gen::sync_key::Sources) {
    qDebug() << "Key" << k << "is invalid for a source";
    return QString();
  } else {
    auto const &sources{std::get<dessser::gen::sync_key::Sources>(k)};
    return QString::fromStdString(std::get<0>(sources) + "." +
                                  std::get<1>(sources));
  }
}

std::shared_ptr<dessser::gen::sync_key::t> keyOfSourceName(
    QString const &sourceName, char const *extension) {
  std::string const f{sourceName.toStdString()};
  size_t i{f.rfind('.')};

  /* Any source name is supposed to have an extension from which to tell the
   * language it's written in. */
  Q_ASSERT(extension || i != std::string::npos);

  std::string ext{extension ? extension : f.substr(i + 1, f.length() - i - 1)};
  std::string src_path{i != std::string::npos ? f.substr(0, i) : f};
  return std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::Sources>, src_path, ext);
}

bool SourcesModel::isMyKey(dessser::gen::sync_key::t const &k) const {
  if (k.index() != dessser::gen::sync_key::Sources) return false;
  auto const &sources{std::get<dessser::gen::sync_key::Sources>(k)};
  std::string const &ext{std::get<1>(sources)};
  return ext == "ramen" || ext == "alert";
}

void SourcesModel::addSource(dessser::gen::sync_key::t const &key,
                             KValue const &) {
  if (!isMyKey(key)) return;

  Q_ASSERT(key.index() == dessser::gen::sync_key::Sources);  // because isMyKey
  auto const &sources{std::get<dessser::gen::sync_key::Sources>(key)};
  std::string const src_path{std::get<0>(sources)};

  QStringList names{
      QString::fromStdString(src_path).split('/', Qt::SkipEmptyParts)};
  QString const extension{QString::fromStdString(std::get<1>(sources))};
  createAll(src_path, names, extension, root);
}

QModelIndex SourcesModel::indexOfItem(TreeItem const *item) const {
  if (!item->parent) return QModelIndex();
  DirItem const *parentDir = dynamic_cast<DirItem const *>(item->parent);
  Q_ASSERT(parentDir);

  // FIXME: seriously?
  int row = 0;
  for (auto it = parentDir->children.constBegin();
       it != parentDir->children.constEnd(); it++) {
    if (*it == item) break;
    row++;
  }

  if (row >= parentDir->numRows()) return QModelIndex();
  return createIndex(row, 0, (void *)item);
}

SourcesModel::FileItem *SourcesModel::createAll(std::string const &src_path,
                                                QStringList &names,
                                                QString const &extension,
                                                DirItem *root) {
  FileItem *ret = nullptr;
  do {
    QString const &nextName{names.takeFirst()};
    bool const lastName{names.isEmpty()};
    // Look for either a dir by that name or where to add it:
    int row{0};
    bool needNewItem{true};
    for (auto it = root->children.constBegin(); it != root->children.constEnd();
         it++) {
      if ((*it)->name == nextName) {
        if (!lastName && (*it)->isDir()) {
          if (verbose) qDebug() << "createAll: Same directory name";
          DirItem *sub{dynamic_cast<DirItem *>(*it)};
          Q_ASSERT(sub);  // because isDir()
          root = sub;
          needNewItem = false;
          break;
        } else if (lastName && !(*it)->isDir()) {
          if (verbose) qDebug() << "createAll: Same file";
          ret = dynamic_cast<FileItem *>(*it);
          Q_ASSERT(ret);  // because !isDir()
          ret->addExtension(extension);
          needNewItem = false;
          break;
        } else {
          /* Same name while not same type: Create a new dir with same
           * name, this is not UNIX. */
          if (verbose) qDebug() << "createAll: file and dir with same name!";
          break;
        }
      } else if ((*it)->name > nextName) {
        if (verbose)
          qDebug() << "createAll: reached past" << lastName << "(" << nextName
                   << ")";
        break;
      }
      row++;
    }
    if (needNewItem) {
      if (verbose) qDebug() << "createAll: create new" << nextName;
      beginInsertRows(indexOfItem(root), row /* first row */, row /* last */);
      if (lastName) {
        // Create the final file
        ret = new FileItem(nextName, src_path, root);
        ret->addExtension(extension);
        root->addItem(ret, row);
      } else {
        // Add a subdirectory and "recurse"
        DirItem *sub{new DirItem(nextName, root)};
        root->addItem(sub, row);
        root = sub;
      }
      endInsertRows();
    }
  } while (!ret);

  return ret;
}

std::string const SourcesModel::SrcPathOfItem(
    SourcesModel::TreeItem const *item) const {
  // Retrieve the key for the info:
  if (item->isDir()) return std::string();

  SourcesModel::FileItem const *file{
      dynamic_cast<SourcesModel::FileItem const *>(item)};
  Q_ASSERT(file);
  return file->srcPath;
}

std::string const SourcesModel::SrcPathOfIndex(QModelIndex const &index) const {
  // Retrieve the key for the info:
  SourcesModel::TreeItem const *item{
      static_cast<SourcesModel::TreeItem const *>(index.internalPointer())};
  return SrcPathOfItem(item);
}

QModelIndex const SourcesModel::indexOfSrcPath(std::string const &prefix) {
  TreeItem *item{itemOfSrcPath(prefix)};
  if (!item) return QModelIndex();
  return indexOfItem(item);
}

SourcesModel::TreeItem *SourcesModel::itemOfSrcPath(std::string const &prefix) {
  QStringList names{
      QString::fromStdString(prefix).split('/', Qt::SkipEmptyParts)};

  TreeItem *item{root};
  do {
    if (names.isEmpty()) return item;
    QString const &nextName{names.takeFirst()};
    /* Because we have at least one name left after item.
     * Crash here? Check you've sent a key _prefix_ not a full key. */
    Q_ASSERT(item->isDir());
    DirItem *dir{static_cast<DirItem *>(item)};

    for (auto it = dir->children.begin(); it != dir->children.end(); it++) {
      if ((*it)->name == nextName) {
        item = *it;
        goto found;
      }
    }
    qCritical() << "Cannot find key prefix" << QString::fromStdString(prefix);
    return nullptr;
  found:;
  } while (true);
}

std::shared_ptr<dessser::gen::source_info::t const>
SourcesModel::sourceInfoOfItem(TreeItem const *item) const {
  if (item->isDir()) return nullptr;

  SourcesModel::FileItem const *file{
      dynamic_cast<SourcesModel::FileItem const *>(item)};
  Q_ASSERT(file);

  std::shared_ptr<dessser::gen::sync_key::t> const infoKey{
      keyOfSrcPath(file->srcPath, "info")};

  std::shared_ptr<dessser::gen::sync_value::t const> v;
  kvs->lock.lock_shared();
  auto it{kvs->map.find(infoKey)};
  if (it != kvs->map.end()) v = it->second.val;
  kvs->lock.unlock_shared();

  if (!v) return nullptr;
  if (v->index() != dessser::gen::sync_value::SourceInfo) {
    if (verbose)
      qDebug() << "SourcesModel::sourceInfoOfItem: Key" << *infoKey
               << "is not a SourceInfo but" << *v;
    return nullptr;
  }
  return std::shared_ptr<dessser::gen::source_info::t const>(
      std::get<dessser::gen::sync_value::SourceInfo>(*v));
}

void SourcesModel::delSource(dessser::gen::sync_key::t const &key,
                             KValue const &) {
  if (!isMyKey(key)) return;

  Q_ASSERT(key.index() == dessser::gen::sync_key::Sources);  // because isMyKey
  auto const &sources{std::get<dessser::gen::sync_key::Sources>(key)};
  std::string const &src_path{std::get<0>(sources)};

  QStringList names{
      QString::fromStdString(src_path).split('/', Qt::SkipEmptyParts)};
  QString const extension{QString::fromStdString(std::get<1>(sources))};

  deleteAll(names, extension, root);
}

void SourcesModel::deleteAll(QStringList &names, QString const &extension,
                             DirItem *root) {
  Q_ASSERT(!names.isEmpty());

  /* Locate this name in root children: */
  int row;
  for (row = 0; row < root->children.count(); row++) {
    if (root->children[row]->name == names.first()) {
      goto found;
    }
  }
  qCritical() << "Cannot find" << names.first() << "in children";
  return;
found:

  names.removeFirst();

  if (names.count() == 0) {
    if (verbose)
      qDebug() << "SourcesModel: Deleting extension"
               << root->children[row]->name << "/" << extension;

    FileItem *file{dynamic_cast<FileItem *>(root->children[row])};
    Q_ASSERT(file);  // Because we only delete full path to files

    file->delExtension(extension);
    if (file->extensions.isEmpty()) {
      beginRemoveRows(indexOfItem(root), row, row);
      delete file;
      endRemoveRows();
    }
  } else {
    DirItem *dir{dynamic_cast<DirItem *>(root->children[row])};
    Q_ASSERT(dir);  // Because we only delete full path to files
    deleteAll(names, extension, dir);
    if (dir->children.count() > 0) return;
    // delete that empty dir
    beginRemoveRows(indexOfItem(root), row, row);
    delete dir;
    endRemoveRows();
  }
}
