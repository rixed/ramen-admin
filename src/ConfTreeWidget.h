#ifndef CONFTREEWIDGET_H_190715
#define CONFTREEWIDGET_H_190715
#include <QStringList>
#include <QTreeWidget>

#include "ConfChange.h"

class AtomicWidget;
class ConfTreeItem;
struct KValue;

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
    namespace sync_value { struct t; }
  }
}

#define CONFTREE_WIDGET_NUM_COLUMNS 4

class ConfTreeWidget : public QTreeWidget
{
  Q_OBJECT

  void createItemByNames(
    QStringList &, dessser::gen::sync_key::t const &, KValue const &, ConfTreeItem * = nullptr, bool = false);
  ConfTreeItem *findItemByNames(QStringList &names, ConfTreeItem * = nullptr);

  ConfTreeItem *itemOfKey(dessser::gen::sync_key::t const &);
  ConfTreeItem *findItem(QString const &name, ConfTreeItem *parent) const;

  QWidget *actionWidget(dessser::gen::sync_key::t const &, bool, bool);
  QWidget *fillerWidget();

  void createItem(dessser::gen::sync_key::t const &, KValue const &);
  void deleteItem(dessser::gen::sync_key::t const &, KValue const &);
  void editedValueChangedFromStore(dessser::gen::sync_key::t const &, KValue const &kvp);

public:
  ConfTreeWidget(QWidget *parent = nullptr);
  QSize minimumSizeHint() const override;

protected:
  void keyPressEvent(QKeyEvent *) override;

protected slots:
  void onChange(QList<ConfChange> const &);
  void editedValueChanged(dessser::gen::sync_key::t const &, std::shared_ptr<dessser::gen::sync_value::t const>);
  void deleteClicked(dessser::gen::sync_key::t const &);
  void activateItem(QTreeWidgetItem *item, int column);
  void openEditorWindow(dessser::gen::sync_key::t const &);
};

#endif
