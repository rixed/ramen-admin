#include <cassert>
#include <cmath>
#include <string>
#include <memory>
#include <QDebug>
#include <QtGlobal>

#include "ConfChange.h"
#include "ConfClient.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_value.h"
#include "EventTime.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc_dessser.h"

#include "TailModel.h"

TailModel::TailModel(
  std::string const &siteName_, std::string const &fqName_, std::string const &workerSign_,
  std::shared_ptr<dessser::gen::raql_type::t const> type_,
  std::shared_ptr<EventTime const> eventTime_,
  QObject *parent)
  : QAbstractTableModel(parent),
    eventTime(eventTime_),
    siteName(siteName_),
    fqName(fqName_),
    workerSign(workerSign_),
    type(type_)
{
  tuples.reserve(500);

  connect(kvs.get(), &KVStore::keyChanged,
          this, &TailModel::onChange);

  // Subscribe
  std::shared_ptr<dessser::gen::sync_key::t const> k { subscriberKey() };
  static std::shared_ptr<dessser::gen::raql_value::t> const dummy {
    std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VNull>,
      dessser::VOID) };
  static std::shared_ptr<dessser::gen::sync_value::t> const v {
    std::make_shared<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::RamenValue>,
      std::static_pointer_cast<dessser::gen::raql_value::t>(dummy)) };
  Menu::getClient()->sendSet(
    k, std::static_pointer_cast<dessser::gen::sync_value::t>(v));
}

TailModel::~TailModel()
{
  // Unsubscribe
  std::shared_ptr<dessser::gen::sync_key::t const> k { subscriberKey() };
  Menu::getClient()->sendDel(k);
}

std::shared_ptr<dessser::gen::sync_key::t> TailModel::subscriberKey() const
{
  std::shared_ptr<dessser::gen::sync_key::per_tail> sub {
    std::make_shared<dessser::gen::sync_key::per_tail>(
      std::in_place_index<dessser::gen::sync_key::Subscriber>,
      my_uid->toStdString()) };

  return std::make_shared<dessser::gen::sync_key::t>(
    std::in_place_index<dessser::gen::sync_key::Tails>,
    siteName, fqName, workerSign, sub);
}

void TailModel::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyCreated:
        addTuple(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void TailModel::addTuple(dessser::gen::sync_key::t const &key, KValue const &kv)
{
  if (key.index() != dessser::gen::sync_key::Tails) return;

  auto const &tails { std::get<dessser::gen::sync_key::Tails>(key) };
  if (std::get<0>(tails) != siteName ||
      std::get<1>(tails) != fqName ||
      std::get<2>(tails) != workerSign) return;

  std::shared_ptr<dessser::gen::sync_key::per_tail const> per_tail {
    std::get<3>(tails) };
  if (per_tail->index() != dessser::gen::sync_key::LastTuple) return;

  if (kv.val->index() != dessser::gen::sync_value::Tuples) {
    qCritical() << "TailModel::addTuple: Received a Tail that is not tuples:" << *kv.val;
    return;
  }

  dessser::Arr<std::shared_ptr<dessser::gen::sync_value::tuple>> const &batch {
    std::get<dessser::gen::sync_value::Tuples>(*kv.val) };

  size_t const numTuples { batch.size() };
  if (0 == numTuples) return;

  beginInsertRows(QModelIndex(), tuples.size(), tuples.size() + numTuples - 1);

  for (std::shared_ptr<dessser::gen::sync_value::tuple> const tuple : batch) {
    /* If a function has no event time info, all tuples will have time 0.
     * Past data is disabled in that case anyway. */
    double start { eventTime ?
      eventTime->startOfTuple(*tuple->values).value_or(0.) : 0. };

    minEventTime_ =
      std::isnan(minEventTime_) ? start : std::min(minEventTime_, start);
    maxEventTime_ =
      std::isnan(maxEventTime_) ? start : std::max(maxEventTime_, start);

    order.insert(std::make_pair(start, tuples.size()));
    tuples.emplace_back(start, tuple->values);
  }
  endInsertRows();
}

int TailModel::rowCount(QModelIndex const &parent) const
{
  if (parent.isValid()) return 0;
  return tuples.size();
}

int TailModel::columnCount(QModelIndex const &parent) const
{
  if (parent.isValid()) return 0;
  return numColumns(*type);
}

QVariant TailModel::data(QModelIndex const &index, int role) const
{
  if (! index.isValid()) return QVariant();

  int const row { index.row() };
  int const column { index.column() };

  if (row < 0 || row >= rowCount() ||
      column < 0 || column >= columnCount())
    return QVariant();

  switch (role) {
    case Qt::DisplayRole:
      {
        std::shared_ptr<dessser::gen::raql_value::t const> v {
          columnValue(*tuples[row].second, column) };
        return v ? QVariant(raqlValToQString(*v)) : QVariant();
      }
      break;
    case Qt::ToolTipRole:
      // TODO
      return QVariant(QString("Column #") + QString::number(column));
    default:
      return QVariant();
  }
}

QVariant TailModel::headerData(int section, Qt::Orientation orient, int role) const
{
  if (role != Qt::DisplayRole)
    return QAbstractTableModel::headerData(section, orient, role);

  switch (orient) {
    case Qt::Horizontal:
      if (section < 0 || section >= columnCount()) return QVariant();
      return QVariant(QString::fromStdString(columnName(*type, section)));
    case Qt::Vertical:
      if (section < 0 || section >= rowCount()) return QVariant();
      return QVariant(QString::number(section));
  }
  return QVariant();
}

bool TailModel::isNumeric(int column) const
{
  std::shared_ptr<dessser::gen::raql_type::t const> t { columnType(*type, column) };
  return t ? ::isNumeric(*t) : false;
}
