// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ConfTreeWidget.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QStackedLayout>

#include "ConfClient.h"
#include "KFloatEditor.h"
#include "KShortLabel.h"
#include "Menu.h"
#include "Resources.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"
#include "raw/ConfTreeItem.h"
#include "raw/RawConfEditorDialog.h"

static constexpr bool verbose{false};

/* In order to display the conftree as an actual tree we need the keys to be
 * split in a meaningful way. Unfortunately, using dessser automatic conversion
 * to string won't produce anything useful so we do it mostly by hand here.
 * Ideally, we'd need some introspection for that task.
 * Cf. https://github.com/rixed/dessser/issues/39
 * For now just do it by hand, trying to ensure the compiler will notice if
 * the type definitions become incompatible. */

static QStringList treeNamesOfSourcePath(std::string const &src_path) {
  return QString::fromStdString(src_path).split('/', Qt::SkipEmptyParts);
}

static QStringList treeNamesOfSourcesKey(dessser::gen::sync_key::t const &k) {
  auto const &source{std::get<dessser::gen::sync_key::Sources>(k)};
  return QStringList("Sources") << treeNamesOfSourcePath(std::get<0>(source))
                                << QString::fromStdString(std::get<1>(source));
}

static QStringList treeNamesOfPerSiteKey(dessser::gen::sync_key::t const &k) {
  using namespace dessser::gen::sync_key;
  per_site const &per_site{std::get<PerSite>(k)};
  std::string const &site_name{std::get<0>(per_site)};
  per_site_data const &data{std::get<1>(per_site)};
  QStringList ret{"PerSite", QString::fromStdString(site_name)};

  switch (data.index()) {
    case IsMaster:
      return ret << "IsMaster";
    case PerService: {
      auto const &service{std::get<PerService>(data)};
      std::string const &service_name{std::get<0>(service)};
      auto const &service_data{std::get<1>(service)};
      ret = ret << "PerService" << QString::fromStdString(service_name);
      switch (service_data) {
        case Host:
          return ret << "Host";
        case Port:
          return ret << "Port";
        default:
          qFatal("Invalid service_data");
          return ret << "INVALID";
      }
    }
    case PerWorker: {
      per_worker const &per_worker{std::get<PerWorker>(data)};
      std::string const &worker_name{std::get<0>(per_worker)};
      per_worker_data const &worker_data{std::get<1>(per_worker)};
      ret =
          ret
          << "PerWorker"
          << QString::fromStdString(worker_name).split('/', Qt::SkipEmptyParts);
      switch (worker_data.index()) {
        case RuntimeStats:
          return ret << "RuntimeStats";
        case ArchivedTimes:
          return ret << "ArchivedTimes";
        case NumArcFiles:
          return ret << "NumArcFiles";
        case NumArcBytes:
          return ret << "NumArcBytes";
        case AllocedArcBytes:
          return ret << "AllocedArcBytes";
        case Worker:
          return ret << "Worker";
        case PerInstance: {
          auto const &instance{std::get<PerInstance>(worker_data)};
          std::string const &instance_name{std::get<0>(instance)};
          auto const &instance_data{std::get<1>(instance)};
          ret = ret << "PerInstance" << QString::fromStdString(instance_name);
          switch (instance_data) {
            case StateFile:
              return ret << "StateFile";
            case InputRingFile:
              return ret << "InputRingFile";
            case Pid:
              return ret << "Pid";
            case LastKilled:
              return ret << "LastKilled";
            case LastExit:
              return ret << "LastExit";
            case LastExitStatus:
              return ret << "LastExitStatus";
            case SuccessiveFailures:
              return ret << "SuccessiveFailures";
            case QuarantineUntil:
              return ret << "QuarantineUntil";
            default:
              qFatal("Invalid instance_data");
              return ret << "INVALID";
          }
        }
        case PerReplayer:
          return ret << "PerReplayer"
                     << QString::number(std::get<PerReplayer>(worker_data));
        case OutputSpecs:
          return ret << "OutputSpecs";
        default:
          qFatal("Invalid worker_data");
          return ret << "INVALID";
      }
    }
    case PerProgram: {
      auto const &program{std::get<PerProgram>(data)};
      std::string const &program_name{std::get<0>(program)};
      auto const &program_data{std::get<1>(program)};
      ret = ret << "PerProgram"
                << QString::fromStdString(program_name)
                       .split('/', Qt::SkipEmptyParts);
      switch (program_data) {
        case Executable:
          return ret << "Executable";
        default:
          qFatal("Invalid program_data");
          return ret << "INVALID";
      }
    }
    default:
      qFatal("Invalid data.index");
      return ret << "INVALID";
  }
}

static QStringList treeNamesOfStorageKey(dessser::gen::sync_key::t const &k) {
  using namespace dessser::gen::sync_key;
  auto const &storage{std::get<Storage>(k)};
  QStringList ret{"Storage"};
  switch (storage.index()) {
    case TotalSize:
      return ret << "TotalSize";
    case RecallCost:
      return ret << "RecallCost";
    case RetentionsOverride:
      return ret << "RetentionsOverride"
                 << QString::fromStdString(
                        std::get<RetentionsOverride>(storage));
    default:
      qFatal("Invalid storage");
  }
}

static QStringList treeNamesOfTailsKey(dessser::gen::sync_key::t const &k) {
  using namespace dessser::gen::sync_key;
  auto const &tails{std::get<Tails>(k)};
  std::string const &site_name{std::get<0>(tails)};
  std::string const &fq_name{std::get<1>(tails)};
  std::string const &instance{std::get<2>(tails)};
  per_tail const &subscriber_data{std::get<3>(tails)};
  QStringList ret{QStringList("Tails") << QString::fromStdString(site_name)
                                       << QString::fromStdString(fq_name).split(
                                              '/', Qt::SkipEmptyParts)
                                       << QString::fromStdString(instance)};
  switch (subscriber_data.index()) {
    case Subscriber:
      return ret << "Subscriber"
                 << QString::fromStdString(
                        std::get<Subscriber>(subscriber_data));
    case LastTuple:
      return ret << "LastTuple"
                 << QString::number(std::get<LastTuple>(subscriber_data));
    default:
      qFatal("Invalid subscriber_data");
  }
}

static QStringList treeNamesOfSyncSocket(
    dessser::gen::sync_socket::t const &sock) {
  using namespace dessser::gen::sync_socket;
  QString const port{QString::number(sock.port)};
  switch (sock.ip.index()) {
    case v4:
      return QStringList(stringOfIp4(std::get<v4>(sock.ip))) << port;
    case v6:
      return QStringList(stringOfIp6(std::get<v6>(sock.ip))) << port;
    default:
      qFatal("Invalid sock.ip");
  }
}

static QStringList treeNamesOfDashKey(
    dessser::gen::sync_key::per_dash_key const &dash_key) {
  using namespace dessser::gen::sync_key;
  switch (dash_key.index()) {
    case Widgets:
      return QStringList("Widgets")
             << QString::number(std::get<Widgets>(dash_key));
    default:
      qFatal("Invalid per_dash");
  }
}

static QStringList treeNamesOfPerClientKey(dessser::gen::sync_key::t const &k) {
  using namespace dessser::gen::sync_key;
  auto const &per_client{std::get<PerClient>(k)};
  dessser::gen::sync_socket::t const &sock{std::get<0>(per_client)};
  dessser::gen::sync_key::per_client const &per_client_data{
      std::get<1>(per_client)};
  QStringList ret{QStringList("PerClient") << treeNamesOfSyncSocket(sock)};
  switch (per_client_data.index()) {
    case Response:
      return ret << "Response"
                 << QString::fromStdString(std::get<Response>(per_client_data));
    case Scratchpad:
      return ret << "Scratchpad"
                 << treeNamesOfDashKey(*std::get<Scratchpad>(per_client_data));
    default:
      qFatal("Invalid per_client_data");
  }
}

static QStringList treeNamesOfTeamsKey(dessser::gen::sync_key::t const &k) {
  using namespace dessser::gen::sync_key;
  auto const &team{std::get<Teams>(k)};
  QStringList ret{QStringList("Teams")
                  << QString::fromStdString(team.name).split(
                         '/', Qt::SkipEmptyParts)};
  switch (team.info.index()) {
    case Contacts:
      return ret << "Contacts"
                 << QString::fromStdString(std::get<Contacts>(team.info));
    case Inhibition:
      return ret << "Inhibition"
                 << QString::fromStdString(std::get<Inhibition>(team.info));
    default:
      qFatal("Invalid team.info");
  }
}

static QStringList treeNamesOfIncidentsKey(dessser::gen::sync_key::t const &k) {
  using namespace dessser::gen::sync_key;
  auto const &incidents{std::get<Incidents>(k)};
  std::string const &incident_id{std::get<0>(incidents)};
  dessser::gen::sync_key::incident_key const &incident_data{
      std::get<1>(incidents)};
  QStringList ret{QStringList("Incidents")
                  << QString::fromStdString(incident_id)};
  switch (incident_data.index()) {
    case FirstStartNotif:
      return ret << "FirstStartNotif";
    case LastStartNotif:
      return ret << "LastStartNotif";
    case LastStopNotif:
      return ret << "LastStopNotif";
    case LastStateChangeNotif:
      return ret << "LastStateChangeNotif";
    case Team:
      return ret << "Team";
    case Dialogs: {
      auto const &dialogs{std::get<Dialogs>(incident_data)};
      ret = ret << "Dialogs"
                << QString::fromStdString(std::get<0>(dialogs))
                       .split('/', Qt::SkipEmptyParts);
      dessser::gen::sync_key::dialog_key const &dialog_data{
          std::get<1>(dialogs)};
      switch (dialog_data) {
        case NumDeliveryAttempts:
          return ret << "NumDeliveryAttempts";
        case FirstDeliveryAttempt:
          return ret << "FirstDeliveryAttempt";
        case LastDeliveryAttempt:
          return ret << "LastDeliveryAttempt";
        case NextScheduled:
          return ret << "NextScheduled";
        case NextSend:
          return ret << "NextSend";
        case DeliveryStatus:
          return ret << "DeliveryStatus";
        case Ack:
          return ret << "Ack";
        default:
          qFatal("Invalid dialog_data");
          return ret << "INVALID";
      }
    }
    case Journal: {
      auto const &journal{std::get<Journal>(incident_data)};
      return ret << "Journal" << stringOfDate(std::get<0>(journal))
                 << QString::number(std::get<1>(journal));
    }
    default:
      qFatal("Invalid incident_data");
  }
}

static QStringList treeNamesOfSyncKey(dessser::gen::sync_key::t const &k) {
  using namespace dessser::gen::sync_key;
  switch (k.index()) {
    case DevNull:
      return QStringList("DevNull");
    case Time:
      return QStringList("Time");
    case Versions:
      return QStringList("Versions")
             << QString::fromStdString(std::get<Versions>(k));
    case Sources:
      return treeNamesOfSourcesKey(k);
    case TargetConfig:
      return QStringList("TargetConfig");
    case PerSite:
      return treeNamesOfPerSiteKey(k);
    case Storage:
      return treeNamesOfStorageKey(k);
    case Tails:
      return treeNamesOfTailsKey(k);
    case Replays:
      return QStringList("Replays") << QString::number(std::get<Replays>(k));
    case Error: {
      std::optional<dessser::gen::sync_socket::t_ext> const &error{
          std::get<Error>(k)};
      if (error) {
        return QStringList("Error") << treeNamesOfSyncSocket(*error);
      } else {
        return QStringList("Error") << "None";
      }
    }
    case ReplayRequests:
      return QStringList("ReplayRequests");
    case PerClient:
      return treeNamesOfPerClientKey(k);
    case Dashboards: {
      auto const &dash{std::get<Dashboards>(k)};
      return QStringList("Dashboards")
             << QString::fromStdString(std::get<0>(dash))
             << treeNamesOfDashKey(*std::get<1>(dash));
    }
    case Notifications:
      return QStringList("Notifications");
    case Teams:
      return treeNamesOfTeamsKey(k);
    case Incidents:
      return treeNamesOfIncidentsKey(k);
    default:
      qWarning() << "Unimplemented treeNamesOfSyncKey for" << k;
      return QStringList(syncKeyToQString(k));
  }
}

ConfTreeItem *ConfTreeWidget::findItem(QString const &name,
                                       ConfTreeItem *parent) const {
  if (parent) {
    // TODO: once sorted, early exit (which also tells where to insert the
    // new one)
    for (int c = 0; c < parent->childCount(); c++) {
      ConfTreeItem *item{dynamic_cast<ConfTreeItem *>(parent->child(c))};
      if (item->name == name) return item;
    }
  } else {
    for (int c = 0; c < topLevelItemCount(); c++) {
      ConfTreeItem *item{dynamic_cast<ConfTreeItem *>(topLevelItem(c))};
      if (item->name == name) return item;
    }
  }

  return nullptr;
}

static bool isASubscriber(dessser::gen::sync_key::t const &key) {
  if (key.index() != dessser::gen::sync_key::Tails) return false;
  auto const &tail{std::get<dessser::gen::sync_key::Tails>(key)};
  dessser::gen::sync_key::per_tail const &per_tail{std::get<3>(tail)};
  return per_tail.index() == dessser::gen::sync_key::Subscriber;
}

static bool betterSkipKey(dessser::gen::sync_key::t const &key) {
  return (key.index() == dessser::gen::sync_key::Tails &&
          !isASubscriber(key)) ||
         // Too many of them:
         key.index() == dessser::gen::sync_key::Incidents ||
         key.index() == dessser::gen::sync_key::Notifications;
}

// Slot to propagates editor valueChanged into the item emitDatachanged
void ConfTreeWidget::editedValueChangedFromStore(
    std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &kv) {
  if (betterSkipKey(*key)) return;

  editedValueChanged(key, kv.val);
}

void ConfTreeWidget::editedValueChanged(
    std::shared_ptr<dessser::gen::sync_key::t const> key,
    std::shared_ptr<dessser::gen::sync_value::t const>) {
  Q_ASSERT(key);
  ConfTreeItem *item{itemOfKey(key)};
  if (item) {
    item->emitDataChanged();
    /* The view will then ask for its data again, and those will be fetched
     * from the store. */
    resizeColumnToContents(2);
  }
}

void ConfTreeWidget::deleteItem(
    std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &) {
  if (betterSkipKey(*key)) return;

  QStringList names{treeNamesOfSyncKey(*key)};
  if (verbose)
    qDebug() << "ConfTreeWidget::deleteItem: deleting names" << names;

  Q_ASSERT(names.length() >= 1);

  /* Delete leaf item as well as all intermediary items that are now empty: */
  do {
    ConfTreeItem *item{findItemByNames(names)};
    Q_ASSERT(item);
    if (verbose)
      qDebug() << "ConfTreeWidget::deleteItem:" << item->name << "has"
               << item->childCount() << "children";
    if (item->childCount() > 0) break;
    /* Note: No need to emitDataChanged on the parent
     * Note2: QTreeWidgetItem objects are not QObject so delete for real: */
    delete item;
    names.removeLast();
  } while (names.length() > 0);
}

void ConfTreeWidget::deleteClicked(
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  Q_ASSERT(key);
  QMessageBox msg;
  msg.setText(tr("Are you sure?"));
  msg.setInformativeText(tr("Key %1 will be lost forever, there is no undo")
                             .arg(syncKeyToQString(*key)));
  msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msg.setDefaultButton(QMessageBox::Cancel);
  msg.setIcon(QMessageBox::Warning);
  if (QMessageBox::Ok == msg.exec()) Menu::getClient()->sendDel(*key);
}

void ConfTreeWidget::openViewWindow(
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  QDialog *editor{new RawConfEditorDialog(key, false)};
  editor->show();
}

void ConfTreeWidget::openEditorWindow(
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  QDialog *editor{new RawConfEditorDialog(key, true)};
  editor->show();
}

QWidget *ConfTreeWidget::actionWidget(
    std::shared_ptr<dessser::gen::sync_key::t const> key, bool canWrite,
    bool canDel) {
  // The widget for the "Actions" column:
  QWidget *widget{new QWidget};
  QHBoxLayout *layout{new QHBoxLayout};
  layout->setContentsMargins(0, 0, 0, 0);
  widget->setLayout(layout);

  QPushButton *viewButton{new QPushButton(tr("View"))};
  layout->addWidget(viewButton);
  connect(viewButton, &QPushButton::clicked, this,
          [this, key](bool) { openViewWindow(key); });

  if (canWrite) {
    QPushButton *editButton{new QPushButton(tr("Edit"))};
    layout->addWidget(editButton);
    connect(editButton, &QPushButton::clicked, this,
            [this, key](bool) { openEditorWindow(key); });
  }

  if (canDel) {
    QPushButton *delButton{new QPushButton(tr("Delete"))};
    layout->addWidget(delButton);
    connect(delButton, &QPushButton::clicked, this,
            [this, key](bool) { deleteClicked(key); });
  }

  return widget;
}

/* Same height as the actionWidget, but invisible: */
QWidget *ConfTreeWidget::fillerWidget() {
  QWidget *widget{new QWidget};
  QHBoxLayout *layout{new QHBoxLayout};
  layout->setContentsMargins(0, 0, 0, 0);
  QPushButton *nopButton{new QPushButton};
  nopButton->setFlat(true);
  nopButton->setEnabled(false);
  layout->addWidget(nopButton);
  widget->setLayout(layout);
  return widget;
}

/* Add a key by adding the ConfTreeItems recursively (or reuse preexisting
 * one), and return the leaf one. Will not create it if kv is null. */
void ConfTreeWidget::createItemByNames(
    // Takes a copy of [names] because it's going to be mnodified
    QStringList names, std::shared_ptr<dessser::gen::sync_key::t const> key,
    KValue const &kv, ConfTreeItem *parent, bool topLevel) {
  qsizetype const len{names.count()};
  Q_ASSERT(len >= 1);
  QString const name{names.takeFirst()};

  ConfTreeItem *item{findItem(name, parent)};
  if (item) {
    if (len > 1) createItemByNames(names, key, kv, item);
    return;
  }

  // Create it:

  item = 1 == len ? new ConfTreeItem(key, name, parent, nullptr)
                  :                                             // TODO: sort
             new ConfTreeItem(nullptr, name, parent, nullptr);  // TODO: sort

  if (!item) return;

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
    KShortLabel *shortLabel{new KShortLabel};
    shortLabel->setKey(key);
    shortLabel->setValueFromStore();
    shortLabel->setContentsMargins(8, 8, 8, 8);
    // Redraw/resize whenever the value is changed:
    connect(
        shortLabel, &AtomicWidget::valueChanged, this,
        [this, key](std::shared_ptr<dessser::gen::sync_value::t const> val) {
          editedValueChanged(key, val);
        });
    setItemWidget(item, 1, shortLabel);
    setItemWidget(item, 3, actionWidget(key, kv.can_write, kv.can_del));
  }
}

void ConfTreeWidget::createItem(
    std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &kv) {
  if (betterSkipKey(*key)) return;

  if (verbose) qDebug() << "ConfTreeWidget: createItem for key" << *key;

  /* We have a new key.
   * Add it to the tree and connect any value change for that value to a
   * slot that will retrieve the item and call it's emitDataChanged function
   * (which will itself call the underlying model to signal a change).
   */
  QStringList names{treeNamesOfSyncKey(*key)};
  createItemByNames(names, key, kv, nullptr, true);
}

void ConfTreeWidget::activateItem(QTreeWidgetItem *item_, int) {
  ConfTreeItem *item{dynamic_cast<ConfTreeItem *>(item_)};
  if (!item) {
    qDebug() << "Activated an item that's not a ConfTreeItem!?";
    return;
  }

  if (item->key) {
    openEditorWindow(item->key);
  } else {
    item->setExpanded(!item->isExpanded());
  }
}

ConfTreeItem *ConfTreeWidget::itemOfKey(
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  QStringList names{treeNamesOfSyncKey(*key)};
  return findItemByNames(names);
}

ConfTreeItem *ConfTreeWidget::findItemByNames(
    // Takes a copy of [names] because it's going to be modified
    QStringList names, ConfTreeItem *parent) {
  qsizetype const len{names.count()};
  Q_ASSERT(len >= 1);
  QString const name{names.takeFirst()};

  ConfTreeItem *item{findItem(name, parent)};
  if (item) {
    if (1 == len) return item;
    return findItemByNames(names, item);
  }

  return nullptr;
}

ConfTreeWidget::ConfTreeWidget(QWidget *parent) : QTreeWidget(parent) {
  setUniformRowHeights(true);
  setColumnCount(CONFTREE_WIDGET_NUM_COLUMNS);
  setAlternatingRowColors(true);
  ;
  static QStringList labels{"Name", "Value", "Lock", "Actions"};
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
  connect(this, &QTreeWidget::itemActivated, this,
          &ConfTreeWidget::activateItem);

  /* Register to every change in the kvs: */
  connect(kvs.get(), &KVStore::keyChanged, this, &ConfTreeWidget::onChange);
}

void ConfTreeWidget::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
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

void ConfTreeWidget::keyPressEvent(QKeyEvent *event) {
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

QSize ConfTreeWidget::minimumSizeHint() const { return QSize(350, 140); }
