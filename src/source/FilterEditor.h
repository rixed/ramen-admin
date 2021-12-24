#ifndef FILTEREDITOR_H_191210
#define FILTEREDITOR_H_191210
#include <memory>
#include <QString>
#include <QWidget>

class QComboBox;
class QCompleter;
class QLineEdit;
class QModelIndex;
class NamesSubtree;
struct SimpleFilter;

namespace dessser {
  namespace gen {
    namespace alert { struct t; }
    namespace simple_filter { struct t; }
  }
}

class FilterEditor : public QWidget {
  Q_OBJECT

public:
  QLineEdit *lhsEdit;
  QComboBox *opEdit;
  QLineEdit *rhsEdit;

  QCompleter *completer = nullptr;  // used for lhsEdit;

  FilterEditor(QWidget *parent = nullptr);

  void setEnabled(bool);

  bool isEmpty() const;

  bool hasValidInput() const;

  QString const description(
    QString const &prefix = QString(), QString const &suffix = QString());

  bool setValue(dessser::gen::simple_filter::t const &);

  void clear();

  std::shared_ptr<dessser::gen::simple_filter::t> getValue() const;

public slots:
  void setFunction(QModelIndex const &);

signals:
  /* Signaled when the filter has been changed in any way: */
  void inputChanged();
};

#endif
