// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "chart/TimeChartFunctionFieldsModel.h"

#include <QDebug>
#include <QModelIndex>
#include <QVariant>

#include "GraphModel.h"
#include "KVStore.h"
#include "Resources.h"
#include "colorOfString.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/raql_type.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"

static constexpr bool verbose{false};

TimeChartFunctionFieldsModel::TimeChartFunctionFieldsModel(
    std::string const &site, std::string const &program,
    std::string const &function, QObject *parent)
    : QAbstractTableModel(parent),
      source(dessser::gen::fq_function_name::t{site, program, function}, true,
             {}) {
  connect(GraphModel::globalGraphModel, &GraphModel::workerChanged, this,
          &TimeChartFunctionFieldsModel::checkSource);
}

int TimeChartFunctionFieldsModel::rowCount(QModelIndex const &) const {
  return numericFields.count();
}

int TimeChartFunctionFieldsModel::columnCount(QModelIndex const &) const {
  return NumColumns;
}

dessser::gen::dashboard_widget::field const *
TimeChartFunctionFieldsModel::findFieldConfiguration(
    std::string const &name) const {
  for (dessser::gen::dashboard_widget::field const &field : source.fields) {
    if (field.column == name) return &field;
  }

  return nullptr;
}

static dessser::gen::dashboard_widget::field makeField(
    std::string const &program, std::string const &function,
    std::string const &field) {
  dessser::gen::dashboard_widget::representation representation{
      dessser::gen::dashboard_widget::Unused};

  QString const full_name{QString::fromStdString(program) + "/" +
                          QString::fromStdString(function) + "/" +
                          QString::fromStdString(field)};

  QColor c{colorOfString(full_name, 0.2)};

  dessser::Arr<std::string> factors;

  return dessser::gen::dashboard_widget::field{(double)c.alphaF(),  // opacity
                                               (uint32_t)(c.rgb() & 0xffffffU),
                                               representation,
                                               field,
                                               factors,
                                               (uint8_t)0};  // axis number
}

dessser::gen::dashboard_widget::field
TimeChartFunctionFieldsModel::findFieldConfiguration(int row) const {
  std::string const name{
      headerData(row, Qt::Vertical).toString().toStdString()};

  dessser::gen::dashboard_widget::field const *field{
      findFieldConfiguration(name)};

  if (field) return *field;

  return makeField(source.name.program, source.name.function, name);
}

dessser::gen::dashboard_widget::field *
TimeChartFunctionFieldsModel::findFieldConfiguration(int row) {
  std::string const name{
      headerData(row, Qt::Vertical).toString().toStdString()};

  dessser::gen::dashboard_widget::field const *field{
      findFieldConfiguration(name)};

  if (field) return const_cast<dessser::gen::dashboard_widget::field *>(field);

  if (verbose) qDebug() << "model: adding a field";
  source.fields.push_back(
      makeField(source.name.program, source.name.function, name));
  return &source.fields[source.fields.size() - 1];
}

QVariant TimeChartFunctionFieldsModel::data(QModelIndex const &index,
                                            int role) const {
  if (role != Qt::EditRole && role != Qt::DisplayRole) return QVariant();

  int const row{index.row()};
  if (row < 0 || row >= numericFields.count()) return QVariant();

  int const col{index.column()};
  if (col < 0 || col >= NumColumns) return QVariant();

  dessser::gen::dashboard_widget::field const field{
      findFieldConfiguration(row)};

  switch (static_cast<Columns>(col)) {
    case ColRepresentation:
      return (uint)field.representation;

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

    case ColColor: {
      QColor c{(QRgb)(field.color)};  // This constructor sets alpha to solid
      c.setAlphaF(field.opacity);
      return c;
    }

    case NumColumns:  // not a real column number
      qFatal("TimeChartFunctionFieldsModel::data: invalid column");
  }

  return QVariant();
}

QVariant TimeChartFunctionFieldsModel::headerData(int section,
                                                  Qt::Orientation orientation,
                                                  int role) const {
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
        qFatal(
            "TimeChartFunctionFieldsModel::headerData: invalid column "
            "section");
    }
  }

  return QVariant();
}

bool TimeChartFunctionFieldsModel::setData(QModelIndex const &index,
                                           QVariant const &value, int role) {
  if (role != Qt::EditRole) return false;

  int const row{index.row()};
  if (row < 0 || row >= numericFields.count()) return false;

  int const col{index.column()};
  if (col < 0 || col >= NumColumns) return false;

  dessser::gen::dashboard_widget::field *field{findFieldConfiguration(row)};

  switch (static_cast<Columns>(col)) {
    case ColRepresentation:
      switch (value.toInt()) {
        case 0:
          field->representation = dessser::gen::dashboard_widget::Unused;
          break;
        case 1:
          field->representation = dessser::gen::dashboard_widget::Independent;
          break;
        case 2:
          field->representation = dessser::gen::dashboard_widget::Stacked;
          break;
        case 3:
          field->representation = dessser::gen::dashboard_widget::StackCentered;
          break;
        default:
          qFatal("TimeChartFunctionFieldsModel::setData: invalid column");
      }
      break;

    case ColFactors: {
      field->factors.clear();
      QStringList const fields{value.toStringList()};
      for (QString const &s : fields) {
        field->factors.push_back(s.toStdString());
      }
    } break;

    case ColAxis: {
      int const v{value.toInt()};
      Q_ASSERT(v >= 0 && v < 256);
      field->axis = v;
    } break;

    case ColColor:
      field->color = value.value<QColor>().rgb() & 0xffffffU;
      break;

    case NumColumns:
      qFatal("TimeChartFunctionFieldsModel::setData: cannot set NumColumns");
  }

  static const QVector<int> editedRoles{Qt::EditRole, Qt::DisplayRole};
  emit dataChanged(index, index, editedRoles);
  return true;
}

Qt::ItemFlags TimeChartFunctionFieldsModel::flags(QModelIndex const &) const {
  return Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool TimeChartFunctionFieldsModel::setValue(
    dessser::gen::dashboard_widget::source const &source_) {
  if (verbose)
    qDebug() << "model: setValue with " << source_.fields.size() << "fields";

  /* The structure of the model can change entirely from the previous one.
   * Start by getting a list of all numeric fields (similar to NamesTree): */
  std::shared_ptr<dessser::gen::sync_key::t const> infoKey{
      std::make_shared<dessser::gen::sync_key::t>(
          std::in_place_index<dessser::gen::sync_key::Sources>,
          srcPathFromProgramName(source_.name.program), "info")};

  std::optional<dessser::gen::source_info::t> sourceInfo;
  {
    kvs->lock.lock_shared();
    auto it{kvs->map.find(infoKey)};
    if (it != kvs->map.end()) {
      std::shared_ptr<dessser::gen::sync_value::t const> v{it->second.val};
      if (v->index() == dessser::gen::sync_value::SourceInfo) {
        sourceInfo = std::get<dessser::gen::sync_value::SourceInfo>(*v);
      } else {
        if (!sourceInfo)
          qCritical() << "TimeChartFunctionFieldsModel: Not a SourceInfo!?";
      }
    }
    kvs->lock.unlock_shared();
  }

  if (!sourceInfo) {
    qWarning() << "TimeChartFunctionFieldsModel: Cannot get field of"
               << *infoKey;
    return false;
  }

  if (sourceInfo->detail.index() != dessser::gen::source_info::Compiled) {
    qWarning() << "TimeChartFunctionFieldsModel:" << *infoKey
               << "is not compiled yet";
    return false;
  }

  dessser::gen::source_info::compiled_program const &prog{
      std::get<dessser::gen::source_info::Compiled>(sourceInfo->detail)};

  beginResetModel();
  numericFields.clear();
  factors.clear();

  for (dessser::gen::source_info::compiled_func const &func : prog.funcs) {
    if (func.name != source_.name.function) continue;
    std::shared_ptr<dessser::gen::raql_type::t const> typ{func.out_record};
    for (unsigned c = 0; c < numColumns(*typ); c++) {
      std::string const name{columnName(*typ, c)};
      std::shared_ptr<dessser::gen::raql_type::t const> t{columnType(*typ, c)};
      QString name_{QString::fromStdString(name)};
      if (isNumeric(*t)) numericFields += name_;
      if (func.factors.contains(name)) factors += name_;
    }
    break;
  }

  if (verbose)
    qDebug() << "TimeChartFunctionFieldsModel: found these numeric fields:"
             << numericFields;

  source = source_;

  /* Filter out fields that are not numeric (or does not exist any longer) */
  {
    auto it{source.fields.begin()};
    while (it != source.fields.end()) {
      QString const name{QString::fromStdString((*it).column)};
      if (!numericFields.contains(name)) {
        qWarning() << "configured field" << name
                   << "does not exist or is not numeric";
        it = source.fields.erase(it);
      } else {
        ++it;
      }
    }
  }

  endResetModel();
  return true;
}

/* Called whenever a worker has changed */
void TimeChartFunctionFieldsModel::checkSource(QString const &oldSign,
                                               QString const &newSign) {
  if (oldSign == newSign) return;

  setValue(source);
}

bool TimeChartFunctionFieldsModel::hasSelection() const {
  for (dessser::gen::dashboard_widget::field const &field : source.fields) {
    if (field.representation != dessser::gen::dashboard_widget::Unused)
      return true;
  }

  return false;
}
