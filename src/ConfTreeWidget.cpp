#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QKeyEvent>
#include <QStackedLayout>

#include "ConfClient.h"
#include "ConfTreeEditorDialog.h"
#include "ConfTreeItem.h"
#include "desssergen/sync_value.h"
#include "KFloatEditor.h"
#include "KShortLabel.h"
#include "Menu.h"
#include "misc_dessser.h"
#include "Resources.h"

#include "ConfTreeWidget.h"

static bool const verbose { false };

ConfTreeItem *ConfTreeWidget::findItem(QString const &name, ConfTreeItem *parent) const
{
  if (parent) {
    // TODO: once sorted, early exit (which also tells where to insert the new one)
    for (int c = 0; c < parent->childCount(); c ++) {
      ConfTreeItem *item = dynamic_cast<ConfTreeItem *>(parent->child(c));
      if (item->name == name) return item;
    }
  } else {
    for (int c = 0; c < topLevelItemCount(); c ++) {
      ConfTreeItem *item = dynamic_cast<ConfTreeItem *>(topLevelItem(c));
      if (item->name == name) return item;
    }
  }

  return nullptr;
}

static bool isASubscriber(dessser::gen::sync_key::t const &key)
{
  if (key.index() != dessser::gen::sync_key::Tails) return false;
  auto const &tail { std::get<dessser::gen::sync_key::Tails>(key) };
  auto const *per_tail { std::get<3>(tail) };
  return per_tail->index() == dessser::gen::sync_key::Subscriber;
}

static bool betterSkipKey(dessser::gen::sync_key::t const &key)
{
  return key.index() == dessser::gen::sync_key::Tails && !isASubscriber(key);
}

// Slot to propagates editor valueChanged into the item emitDatachanged
void ConfTreeWidget::editedValueChangedFromStore(dessser::gen::sync_key::t const &key, KValue const &kv)
{
  if (betterSkipKey(key)) return;

  editedValueChanged(key, kv.val);
}

void ConfTreeWidget::editedValueChanged(
  dessser::gen::sync_key::t const &key, std::shared_ptr<dessser::gen::sync_value::t const>)
{
  ConfTreeItem *item = itemOfKey(key);
  if (item) {
    item->emitDataChanged();
    /* The view will then ask for its data again, and those will be fetched
     * from the store. */
    resizeColumnToContents(2);
  }
}

void ConfTreeWidget::deleteItem(dessser::gen::sync_key::t const &key, KValue const &)
{
  if (betterSkipKey(key)) return;

  /* Note: No need to emitDataChanged on the parent
   * Note2: QTreeWidgetItem objects are not QObject so delete for real: */
  delete itemOfKey(key);
}

void ConfTreeWidget::deleteClicked(dessser::gen::sync_key::t const &key)
{
  QMessageBox msg;
  msg.setText(tr("Are you sure?"));
  msg.setInformativeText(
    tr("Key %1 will be lost forever, there is no undo")
      .arg(syncKeyToQString(key)));
  msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msg.setDefaultButton(QMessageBox::Cancel);
  msg.setIcon(QMessageBox::Warning);
  if (QMessageBox::Ok == msg.exec()) Menu::getClient()->sendDel(&key);
}

void ConfTreeWidget::openEditorWindow(dessser::gen::sync_key::t const &key)
{
  QDialog *editor = new ConfTreeEditorDialog(key);
  editor->show();
}

QWidget *ConfTreeWidget::actionWidget(dessser::gen::sync_key::t const &key, bool canWrite, bool canDel)
{
  // The widget for the "Actions" column:
  QWidget *widget = new QWidget;
  QHBoxLayout *layout = new QHBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  widget->setLayout(layout);

  QPushButton *editButton =
    new QPushButton(canWrite ? tr("Edit"):tr("View"));
  layout->addWidget(editButton);
  connect(editButton, &QPushButton::clicked,
          this, [this, key](bool) {
    openEditorWindow(key);
  });

  if (canDel) {
    QPushButton *delButton = new QPushButton(tr("Delete"));
    layout->addWidget(delButton);
    connect(delButton, &QPushButton::clicked,
            this, [this, key](bool) {
      deleteClicked(key);
    });
  }

  return widget;
}

/* Same height as the actionWidget, but invisible: */
QWidget *ConfTreeWidget::fillerWidget()
{
  QWidget *widget = new QWidget;
  QHBoxLayout *layout = new QHBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  QPushButton *nopButton = new QPushButton;
  nopButton->setFlat(true);
  nopButton->setEnabled(false);
  layout->addWidget(nopButton);
  widget->setLayout(layout);
  return widget;
}

/* Add a key by adding the ConfTreeItems recursively (or reuse preexisting one),
 * and return the leaf one.
 * Will not create it if kv is null. */
void ConfTreeWidget::createItemByNames(
  QStringList &names, dessser::gen::sync_key::t const &key, KValue const &kv, ConfTreeItem *parent, bool topLevel)
{
  int const len = names.count();
  assert(len >= 1);
  QString const name = names.takeFirst();

  ConfTreeItem *item = findItem(name, parent);
  if (item) {
    if (len > 1)
      createItemByNames(names, key, kv, item);
    return;
  }

  // Create it:

  item =
    1 == len ?
      new ConfTreeItem(key, name, parent, nullptr) : // TODO: sort
      new ConfTreeItem(std::nullopt, name, parent, nullptr); // TODO: sort

  if (! item) return;

  if (parent)
    parent->addChild(item);
  else
    addTopLevelItem(item);

  if (len > 1) {
    /* If that's a top-level item, add a "filler" in the action column in
     * order for the first line of the QTreeWidget (the one used to compute
     * the uniform height) has the same size as the taller ones. */
    if (topLevel) setItemWidget(item, 3, fillerWidget());
    createItemByNames(names, key, kv, item);
  } else {
    // "The tree takes ownership of the widget"
    KShortLabel *shortLabel = new KShortLabel;
    shortLabel->setKey(key);
    shortLabel->setContentsMargins(8, 8, 8, 8);
    // Redraw/resize whenever the value is changed:
    connect(shortLabel, &AtomicWidget::valueChanged,
            this, &ConfTreeWidget::editedValueChanged);
    setItemWidget(item, 1, shortLabel);
    setItemWidget(item, 3, actionWidget(key, kv.can_write, kv.can_del));
  }
}

void ConfTreeWidget::createItem(dessser::gen::sync_key::t const &key, KValue const &kv)
{
  if (betterSkipKey(key)) return;

  if (verbose)
    qDebug() << "ConfTreeWidget: createItem for key" << key;

  /* We have a new key.
   * Add it to the tree and connect any value change for that value to a
   * slot that will retrieve the item and call it's emitDataChanged function
   * (which will itself call the underlying model to signal a change).
   */
  QString const keyName { syncKeyToQString(key) };
  QStringList names { keyName.split("/", Qt::SkipEmptyParts) };
  createItemByNames(names, key, kv, nullptr, true);
}

void ConfTreeWidget::activateItem(QTreeWidgetItem *item_, int)
{
  ConfTreeItem *item = dynamic_cast<ConfTreeItem *>(item_);
  if (! item) {
    qDebug() << "Activated an item that's not a ConfTreeItem!?";
    return;
  }

  if (item->key) {
    openEditorWindow(*item->key);
  } else {
    item->setExpanded(! item->isExpanded());
  }
}

ConfTreeItem *ConfTreeWidget::itemOfKey(dessser::gen::sync_key::t const &key)
{
  QString const keyName { syncKeyToQString(key) };
  QStringList names { keyName.split("/", Qt::SkipEmptyParts) };
  return findItemByNames(names);
}

ConfTreeItem *ConfTreeWidget::findItemByNames(
  QStringList &names, ConfTreeItem *parent)
{
  int const len = names.count();
  assert(len >= 1);
  QString const name = names.takeFirst();

  ConfTreeItem *item = findItem(name, parent);
  if (item) {
    if (1 == len) return item;
    return findItemByNames(names, item);
  }

  return nullptr;
}

ConfTreeWidget::ConfTreeWidget(QWidget *parent) :
  QTreeWidget(parent)
{
  setUniformRowHeights(true);
  setColumnCount(CONFTREE_WIDGET_NUM_COLUMNS);
  setAlternatingRowColors(true);;
  static QStringList labels { "Name", "Value", "Lock", "Actions" };
  setHeaderLabels(labels);
  header()->setStretchLastSection(false);
  header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  header()->setSectionResizeMode(1, QHeaderView::Stretch);
  header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
  header()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

/*  if (verbose)
    qDebug() << "ConfTreeWidget: Created in thread "
             << std::this_thread::get_id();*/

  /* Get the activation signal to either collapse/expand or edit: */
  connect(this, &QTreeWidget::itemActivated,
          this, &ConfTreeWidget::activateItem);

  /* Register to every change in the kvs: */
  connect(kvs.get(), &KVStore::keyChanged,
          this, &ConfTreeWidget::onChange);
}

void ConfTreeWidget::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyCreated:
        createItem(change.key, change.kv);
        break;
      case KeyLocked:
      case KeyUnlocked:
        editedValueChangedFromStore(change.key, change.kv);
        break;
      case KeyDeleted:
        deleteItem(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void ConfTreeWidget::keyPressEvent(QKeyEvent *event)
{
  QTreeWidget::keyPressEvent(event);

  switch (event->key()) {
    case Qt::Key_Space:
    case Qt::Key_Select:
    case Qt::Key_Enter:
    case Qt::Key_Return:
      if (currentItem()) {
        emit QTreeWidget::itemActivated(currentItem(), 0);
      }
  }
}

QSize ConfTreeWidget::minimumSizeHint() const
{
  return QSize(350, 140);
}
