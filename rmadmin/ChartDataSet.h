#ifndef CHARTDATASET_H_190526
#define CHARTDATASET_H_190526
#include <QObject>

class FunctionItem;
struct RamenType;
struct RamenValue;

class ChartDataSet : public QObject
{
  Q_OBJECT

  FunctionItem const *functionItem;
  std::shared_ptr<RamenType const> type;
  QString name_;

  unsigned column;
  bool isFactor;

public:
  ChartDataSet(FunctionItem const *, unsigned column, QObject *parent = nullptr);
  bool isNumeric() const;
  unsigned numRows() const;
  RamenValue const *value(unsigned row) const;
  QString name() const;

signals:
  void valueAdded() const;
};

#endif
