#ifndef TIMECHARTFUNCTIONFIELDSMODEL_H_200309
#define TIMECHARTFUNCTIONFIELDSMODEL_H_200309
#include <QAbstractTableModel>
#include <QStringList>
#include <memory>
#include <string>

#include "desssergen/dashboard_widget.h"

struct KValue;

/* This model is not listening to configuration changes but is rather
 * configured entirely with setValue (from the FunctionEditor, which
 * receives it from the FunctionsEditor, which receives it from the
 * TimeChartEditWidget, which is an AtomicWidget connected to that key. */

class TimeChartFunctionFieldsModel : public QAbstractTableModel {
  Q_OBJECT

  /* Returns a R-O pointer to the known configuration for that field, or
   * null: */
  std::shared_ptr<dessser::gen::dashboard_widget::field const>
  findFieldConfiguration(std::string const &field_name) const;

  /* Returns a copy of the stored Column in source or a fresh default value
   * if there is no stored configuration for that field yet. */
  dessser::gen::dashboard_widget::field findFieldConfiguration(int) const;

  /* Same as above, but returns the value from the configuration (and add it if
   * needed) */
  std::shared_ptr<dessser::gen::dashboard_widget::field> findFieldConfiguration(
      int);

 public:
  /* Used to answer data(), can be changed at any time.
   * Will be extended with new field config as new fields are edited.
   * WARNING: Therefore, is not a copy of the dashboard_widget::t,
   *          as fields can be in different order/number. */
  dessser::gen::dashboard_widget::source source;

  // Names of the numeric fields:
  QStringList numericFields;

  // Names of possible factors:
  QStringList factors;

  enum Columns { ColRepresentation, ColFactors, ColAxis, ColColor, NumColumns };

  TimeChartFunctionFieldsModel(std::string const &site,
                               std::string const &program,
                               std::string const &function,
                               QObject *parent = nullptr);

  int rowCount(QModelIndex const &parent = QModelIndex()) const override;

  int columnCount(QModelIndex const &parent = QModelIndex()) const override;

  QVariant data(QModelIndex const &index,
                int role = Qt::DisplayRole) const override;

  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;

  // Maybe useless:
  bool setData(const QModelIndex &index, const QVariant &value,
               int role = Qt::EditRole) override;

  Qt::ItemFlags flags(const QModelIndex &index) const override;

  bool hasSelection() const;

 protected slots:
  void checkSource(QString const &, QString const &);

 public slots:
  /* Faster and simpler than individual setData:
   * Returns false if value could not be set.
   * Emits modelReset. */
  bool setValue(dessser::gen::dashboard_widget::source const &);
};

#endif
