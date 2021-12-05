#include <QDebug>
#include <QModelIndex>
#include <QVariant>

#include "colorOfString.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/raql_type.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "GraphModel.h"
#include "KVStore.h"
#include "misc.h"
#include "misc_dessser.h"
#include "Resources.h"

#include "chart/TimeChartFunctionFieldsModel.h"

static bool const verbose { false };

TimeChartFunctionFieldsModel::TimeChartFunctionFieldsModel(
  std::string const &site,
  std::string const &program,
  std::string const &function,
  QObject *parent)
  : QAbstractTableModel(parent),
    source(
      {},
      std::make_shared<dessser::gen::fq_function_name::t>(function, program, site),
      true)
{
  connect(GraphModel::globalGraphModel, &GraphModel::workerChanged,
          this, &TimeChartFunctionFieldsModel::checkSource);
}

int TimeChartFunctionFieldsModel::rowCount(QModelIndex const &) const
{
  return numericFields.count();
}

int TimeChartFunctionFieldsModel::columnCount(QModelIndex const &) const
{
  return NumColumns;
}

std::shared_ptr<dessser::gen::dashboard_widget::field const>
  TimeChartFunctionFieldsModel::findFieldConfiguration(std::string const &name) const
{
  for (std::shared_ptr<dessser::gen::dashboard_widget::field const> field : source.fields) {
    if (field->column == name) return field;
  }

  return nullptr;
}

static std::shared_ptr<dessser::gen::dashboard_widget::field> makeField(
  std::string const &program, std::string const &function, std::string const &field)
{
  std::shared_ptr<dessser::gen::dashboard_widget::representation> representation {
    std::make_shared<dessser::gen::dashboard_widget::representation>(
      std::in_place_index<dessser::gen::dashboard_widget::Unused>, dessser::VOID) };

  QString const full_name {
    QString::fromStdString(program) + "/" +
    QString::fromStdString(function) + "/" +
    QString::fromStdString(field) };

  QColor c { colorOfString(full_name) };

  dessser::Arr<std::string> factors;

  return
    std::make_shared<dessser::gen::dashboard_widget::field>(
      (uint8_t)0,  // axis number
      (uint32_t)(c.rgb() & 0xffffffU),
      field,
      factors,
      (double)c.alphaF(), // opacity
      representation);
}

dessser::gen::dashboard_widget::field
  TimeChartFunctionFieldsModel::findFieldConfiguration(int row) const
{
  std::string const name {
    headerData(row, Qt::Vertical).toString().toStdString() };

  std::shared_ptr<dessser::gen::dashboard_widget::field> field {
    std::const_pointer_cast<dessser::gen::dashboard_widget::field>(
      findFieldConfiguration(name)) };

  if (! field) {
    field = makeField(source.name->program, source.name->function, name);
  }
  return *field;
}

std::shared_ptr<dessser::gen::dashboard_widget::field>
  TimeChartFunctionFieldsModel::findFieldConfiguration(int row)
{
  std::string const name {
    headerData(row, Qt::Vertical).toString().toStdString() };

  std::shared_ptr<dessser::gen::dashboard_widget::field> field {
    std::const_pointer_cast<dessser::gen::dashboard_widget::field>(
      findFieldConfiguration(name)) };

  if (! field) {
    field = makeField(source.name->program, source.name->function, name);
    if (verbose) qDebug() << "model: adding a field";
    source.fields.push_back(field);
  }
  return field;
}

QVariant TimeChartFunctionFieldsModel::data(
  QModelIndex const &index, int role) const
{
  if (role != Qt::EditRole && role != Qt::DisplayRole) return QVariant();

  int const row { index.row() };
  if (row < 0 || row >= numericFields.count()) return QVariant();

  int const col { index.column() };
  if (col < 0 || col >= NumColumns) return QVariant();

  dessser::gen::dashboard_widget::field const field {
    findFieldConfiguration(row) };

  switch (static_cast<Columns>(col)) {
    case ColRepresentation:
      return (uint)field.representation->index();

    case ColFactors:
      if (role == Qt::DisplayRole) {
        if (field.factors.empty())
          return Resources::get()->emptyIcon;
        else
          return Resources::get()->factorsIcon;
    } else if (role == Qt::EditRole) {
      QStringList lst;
      for (std::string const &f : field.factors) {
        lst += QString::fromStdString(f);
      }
      return lst;
    }
    break;

    case ColAxis:
      return field.axis;

    case ColColor:
      {
        QColor c { (QRgb)(field.color) }; // This constructor sets alpha to solid
        c.setAlphaF(field.opacity);
        return c;
      }

    case NumColumns:  // not a real column number
      Q_ASSERT(false);
  }

  return QVariant();
}

QVariant TimeChartFunctionFieldsModel::headerData(
  int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::EditRole && role != Qt::DisplayRole) return QVariant();

  if (orientation == Qt::Vertical) {
    if (section < 0 || section >= numericFields.count()) return QVariant();
    return numericFields[section];
  } else if (orientation == Qt::Horizontal) {
    if (section < 0 || section >= NumColumns) return QVariant();
    switch (static_cast<Columns>(section)) {
      case ColRepresentation:
        return QString(tr("draw"));
      case ColFactors:
        return QString(tr("factors"));
      case ColAxis:
        return QString(tr("axis"));
      case ColColor:
        return QString(tr("color"));
      case NumColumns:
        Q_ASSERT(false);
    }
  }

  return QVariant();
}

bool TimeChartFunctionFieldsModel::setData(
  QModelIndex const &index, QVariant const &value, int role)
{
  if (role != Qt::EditRole) return false;

  int const row { index.row() };
  if (row < 0 || row >= numericFields.count()) return false;

  int const col { index.column() };
  if (col < 0 || col >= NumColumns) return false;

  std::shared_ptr<dessser::gen::dashboard_widget::field> field {
    findFieldConfiguration(row) };

  // Required to assign variants:
  static dessser::gen::dashboard_widget::representation const reprUnused {
    std::in_place_index<dessser::gen::dashboard_widget::Unused>, dessser::VOID };
  static dessser::gen::dashboard_widget::representation const reprIndependent {
    std::in_place_index<dessser::gen::dashboard_widget::Independent>, dessser::VOID };
  static dessser::gen::dashboard_widget::representation const reprStacked {
    std::in_place_index<dessser::gen::dashboard_widget::Stacked>, dessser::VOID };
  static dessser::gen::dashboard_widget::representation const reprStackCentered  {
    std::in_place_index<dessser::gen::dashboard_widget::StackCentered>, dessser::VOID };

  switch (static_cast<Columns>(col)) {
    case ColRepresentation:
      switch (value.toInt()) {
        case 0:
          *field->representation = reprUnused;
          break;
        case 1:
          *field->representation = reprIndependent;
          break;
        case 2:
          *field->representation = reprStacked;
          break;
        case 3:
          *field->representation = reprStackCentered;
          break;
        default:
          Q_ASSERT(false);
      }
      break;

    case ColFactors:
      field->factors.clear();
      for (QString const &s : value.toStringList()) {
        field->factors.push_back(s.toStdString());
      }
      break;

    case ColAxis:
      {
        int const v { value.toInt() };
        Q_ASSERT(v >= 0 && v < 256);
        field->axis = v;
      }
      break;

    case ColColor:
      field->color = value.value<QColor>().rgb() & 0xffffffU;
      break;

    case NumColumns:
      Q_ASSERT(false);
  }

  static const QVector<int> editedRoles { Qt::EditRole, Qt::DisplayRole };
  emit dataChanged(index, index, editedRoles);
  return true;
}

Qt::ItemFlags TimeChartFunctionFieldsModel::flags(QModelIndex const &) const
{
  return Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool TimeChartFunctionFieldsModel::setValue(
  dessser::gen::dashboard_widget::source const &source_)
{
  if (verbose)
    qDebug() << "model: setValue with " << source_.fields.size() << "fields";

  /* The structure of the model can change entirely from the previous one.
   * Start by getting a list of all numeric fields (similar to NamesTree): */
  std::shared_ptr<dessser::gen::sync_key::t const> infoKey {
    std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::Sources>,
      srcPathFromProgramName(source_.name->program),
      "info") };

  std::shared_ptr<dessser::gen::source_info::t const> sourceInfo;
  {
    kvs->lock.lock_shared();
    auto it = kvs->map.find(infoKey);
    if (it != kvs->map.end()) {
      std::shared_ptr<dessser::gen::sync_value::t const> v { it->second.val };
      if (v->index() == dessser::gen::sync_value::SourceInfo) {
        sourceInfo = std::get<dessser::gen::sync_value::SourceInfo>(*v);
      } else {
        if (! sourceInfo)
          qCritical() << "TimeChartFunctionFieldsModel: Not a SourceInfo!?";
      }
    }
    kvs->lock.unlock_shared();
  }

  if (! sourceInfo) {
    qWarning() << "TimeChartFunctionFieldsModel: Cannot get field of" << *infoKey;
    return false;
  }

  if (sourceInfo->detail.index() != dessser::gen::source_info::Compiled) {
    qWarning() << "TimeChartFunctionFieldsModel:"
               << *infoKey << "is not compiled yet";
    return false;
  }

  std::shared_ptr<dessser::gen::source_info::compiled_program> prog {
    std::get<dessser::gen::source_info::Compiled>(sourceInfo->detail) };

  beginResetModel();
  numericFields.clear();
  factors.clear();

  for (std::shared_ptr<dessser::gen::source_info::compiled_func const> func : prog->funcs) {
    if (func->name != source_.name->function) continue;
    std::shared_ptr<dessser::gen::raql_type::t const> typ { func->out_record };
    for (unsigned c = 0; c < numColumns(*typ); c++) {
      std::string const name { columnName(*typ, c) };
      std::shared_ptr<dessser::gen::raql_type::t const> t { columnType(*typ, c) };
      QString name_ { QString::fromStdString(name) };
      if (isNumeric(*t)) numericFields += name_;
      if (func->factors.contains(name)) factors += name_;
    }
    break;
  }

  if (verbose)
    qDebug() << "TimeChartFunctionFieldsModel: found these numeric fields:"
             << numericFields;

  source = source_;

  /* Filter out fields that are not numeric (or does not exist any longer) */
  {
    auto it { source.fields.begin() };
    auto end { source.fields.end() };
    while (it != end) {
      QString const name { QString::fromStdString((*it)->column) };
      if (!numericFields.contains(name)) {
        qWarning() << "configured field" << name
                   << "does not exist or is not numeric";
        source.fields.erase(it++);
      } else {
        ++it;
      }
    }
  }

  endResetModel();
  return true;
}

/* Called whenever a worker has changed */
void TimeChartFunctionFieldsModel::checkSource(
  QString const &oldSign, QString const &newSign)
{
  if (oldSign == newSign) return;

  setValue(source);
}

bool TimeChartFunctionFieldsModel::hasSelection() const
{
  for (std::shared_ptr<dessser::gen::dashboard_widget::field const> field : source.fields) {
    if (field->representation->index() != dessser::gen::dashboard_widget::Unused)
      return true;
  }

  return false;
}
