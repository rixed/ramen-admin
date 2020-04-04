#ifndef TIMECHARTFUNCTIONFIELDSMODEL_H_200309
#define TIMECHARTFUNCTIONFIELDSMODEL_H_200309
#include <string>
#include <QAbstractTableModel>
#include <QStringList>
#include "conf.h"
#include "confValue.h"

struct KValue;

class TimeChartFunctionFieldsModel : public QAbstractTableModel
{
  Q_OBJECT

  void resetInfo(std::string const &, KValue const &);

public:
  /* Used to answer data(), can be changed at any time.
   * Will be extended with new field config as new fields are edited.
   * WARNING: Therefore, is not a copy of the conf::DashWidgetChart,
   *          as fields can be in different order/number. */
  conf::DashWidgetChart::Source source;

  std::string const infoKey;

  // Names of the numeric fields:
  QStringList numericFields;

  // Names of possible factors:
  QStringList factors;

  /* Returns a R-O pointer to the known configuration for that field, or
   * null: */
  conf::DashWidgetChart::Column const *findFieldConfiguration(
    std::string const &fieldName) const;
  /* Returns a copy of the stored Column in source or a fresh default value
   * if there is no stored configuration for that field yet) */
  conf::DashWidgetChart::Column findFieldConfiguration(int) const;
  /* Returns a R-W reference to the stored Column in source (which will be
   * extended if the field has no configuration yet) */
  conf::DashWidgetChart::Column &findFieldConfiguration(int);

  enum Columns {
    ColRepresentation, ColFactors, ColAxis, ColColor, NumColumns
  };

  TimeChartFunctionFieldsModel(
    std::string const &site,
    std::string const &program,
    std::string const &function,
    QObject *parent = nullptr);

  int rowCount(QModelIndex const &parent = QModelIndex()) const override;

  int columnCount(QModelIndex const &parent = QModelIndex()) const override;

  QVariant data(
    QModelIndex const &index, int role = Qt::DisplayRole) const override;

  QVariant headerData(
    int section, Qt::Orientation orientation, int role = Qt::DisplayRole
  ) const override;

  // Maybe useless:
  bool setData(const QModelIndex &index, const QVariant &value,
               int role = Qt::EditRole) override;

  Qt::ItemFlags flags(const QModelIndex &index) const override;

public slots:
  void onChange(QList<ConfChange> const &);

  // Faster and simpler than individual setData:
  bool setValue(conf::DashWidgetChart::Source const &);
};

#endif
