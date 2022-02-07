// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingWin.h"

#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "ConfChange.h"
#include "ConfClient.h"
#include "KVStore.h"
#include "Menu.h"
#include "Resources.h"
#include "alerting/AlertingJournal.h"
#include "alerting/AlertingLogsModel.h"
#include "alerting/AlertingStats.h"
#include "alerting/AlertingTimeLine.h"
#include "alerting/EditContactDialog.h"
#include "alerting/EditInhibitionDialog.h"
#include "alerting/NewContactDialog.h"
#include "alerting/NewInhibitionDialog.h"
#include "alerting/NewTeamDialog.h"
#include "desssergen/alerting_contact.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static constexpr bool verbose{false};

AlertingWin::AlertingWin(QWidget *parent)
    : SavedWindow("Alerting", tr("Alerting"), true, parent) {
  QWidget *widget = new QWidget;

  QVBoxLayout *layout = new QVBoxLayout;

  stats = new AlertingStats;
  layout->addWidget(stats);

  /* Copied from StorageTimeLine which alludes to some issue if not wrapping
   * into another widget: */
  QScrollArea *scrollArea{new QScrollArea};
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  scrollArea->setWidgetResizable(true);
  QWidget *w{new QWidget};
  QVBoxLayout *l1{new QVBoxLayout};
  w->setLayout(l1);
  timeLine = new AlertingTimeLine;
  l1->addWidget(timeLine);
  l1->setSizeConstraint(QLayout::SetMinimumSize);
  scrollArea->setWidget(w);
  layout->addWidget(scrollArea);

  journal = new AlertingJournal(AlertingLogsModel::globalLogsModel);
  layout->addWidget(journal);

  widget->setLayout(layout);

  setCentralWidget(widget);

  /* Have a menu to list/edit/add contacts */
  teamsMenu = this->menuBar()->addMenu(tr("&Teams"));

  Resources *r{Resources::get()};
  newTeamDialog = new NewTeamDialog(this);
  teamsMenu->addAction(r->addPixmap, tr("Add…"), [this]() {
    newTeamDialog->clear();
    newTeamDialog->open();
  });
  connect(newTeamDialog, &NewTeamDialog::finished, this, &AlertingWin::newTeam);

  newContactDialog = new NewContactDialog(this);
  connect(newContactDialog, &NewContactDialog::finished, this,
          &AlertingWin::newContact);

  editContactDialog = new EditContactDialog(this);
  editInhibitionDialog = new EditInhibitionDialog(this);

  newInhibitionDialog = new NewInhibitionDialog(this);
  connect(newInhibitionDialog, &NewInhibitionDialog::finished, this,
          &AlertingWin::newInhibition);

  // Also listen to contact creations/deletions to update this menu
  connect(kvs.get(), &KVStore::keyChanged, this, &AlertingWin::onChange);
}

void AlertingWin::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
        addTeamEntry(*change.key);
        break;
      case KeyDeleted:
        delTeamEntry(*change.key);
        break;
      default:
        break;
    }
  }
}

QAction *AlertingWin::findOrCreateSectionEntry(
    QMenu *menu, int skip_sections, QString const &name,
    std::function<QAction *(QString const &)> create) {
  // Look for the designated section
  QList<QAction *> actions{menu->actions()};
  QAction *a{nullptr};
  int i;
  for (i = 0; skip_sections > 0 && i < actions.length(); i++) {
    a = actions[i];
    if (a->isSeparator()) skip_sections--;
  }

  if (skip_sections > 0) {
    qFatal("AlertingWin::findOrCreateSectionEntry: Invalid section index");
    return nullptr;
  }

  if (verbose) qDebug() << "found section where to add" << name;
  // Now look for that name in that section:
  for (; i < actions.length(); i++) {
    a = actions[i];
    // Stop before next section separator or "Add" button:
    if (a->isSeparator() || !a->icon().isNull()) break;
    if (a->text() == name) return a;
    if (a->text() > name) break;
  }
  // Insert a new entry before a:
  if (verbose)
    qDebug() << "Insert" << name << "before" << (a ? a->text() : "null");
  QAction *n{create(name)};
  menu->insertAction(a, n);
  return n;
}

QAction *AlertingWin::findOrCreateMenuEntry(
    QString const &name, std::function<QAction *(QString const &)> create) {
  return findOrCreateSectionEntry(teamsMenu, 0, name, create);
}

QAction *AlertingWin::findOrCreateTeamMenuEntry(QString const &team_name) {
  return findOrCreateMenuEntry(
      team_name,
      /* function called to create the QAction to be added if needed: */
      [this](QString const &team_name) {
        if (verbose) qDebug() << "Creating a new submenu for" << team_name;
        QMenu *team_menu{new QMenu(team_name)};
        Resources *r{Resources::get()};
        team_menu->addSection(tr("Contacts"));
        team_menu->addAction(r->addPixmap, tr("Add…"), [this, team_name]() {
          newContactDialog->reset(team_name);
          newContactDialog->open();
        });
        team_menu->addSection(tr("Inhibitions"));
        team_menu->addAction(r->addPixmap, tr("Add…"), [this, team_name]() {
          newInhibitionDialog->reset(team_name);
          newInhibitionDialog->open();
        });
        return team_menu->menuAction();
      });
}

QAction *AlertingWin::findOrCreateContactMenuEntry(QMenu *team_menu,
                                                   QString const &team_name,
                                                   QString const &name) {
  return findOrCreateSectionEntry(
      team_menu, 1, name, [this, team_name](QString const &name) {
        if (verbose) qDebug() << "Creating a new entry for contact" << name;
        QAction *a{new QAction(name)};
        connect(a, &QAction::triggered, [this, team_name, name](bool) {
          editContactDialog->reset(team_name, name);
          editContactDialog->open();
        });
        return a;
      });
}

QAction *AlertingWin::findOrCreateInhibitionMenuEntry(QMenu *team_menu,
                                                      QString const &team_name,
                                                      QString const &name) {
  return findOrCreateSectionEntry(
      team_menu, 2, name, [this, team_name](QString const &name) {
        QAction *a{new QAction(name)};
        connect(a, &QAction::triggered, [this, team_name, name](bool) {
          editInhibitionDialog->reset(team_name, name);
          editInhibitionDialog->open();
        });
        return a;
      });
}

void AlertingWin::addTeamEntry(dessser::gen::sync_key::t const &k) {
  if (k.index() != dessser::gen::sync_key::Teams) return;

  auto const &team{std::get<dessser::gen::sync_key::Teams>(k)};
  /* Make sure this team is in the menu */
  QMenu *team_menu{
      findOrCreateTeamMenuEntry(QString::fromStdString(team.name))->menu()};

  switch (team.info->index()) {
    case dessser::gen::sync_key::Contacts: {
      std::string const &contact_name{
          std::get<dessser::gen::sync_key::Contacts>(*team.info)};
      /* Make sure this contact name is in the team submenu */
      findOrCreateContactMenuEntry(team_menu, QString::fromStdString(team.name),
                                   QString::fromStdString(contact_name));
      break;
    }
    case dessser::gen::sync_key::Inhibition: {
      std::string const &inhibition_name{
          std::get<dessser::gen::sync_key::Inhibition>(*team.info)};
      /* Make sure this inhibition name is in the team submenu */
      findOrCreateInhibitionMenuEntry(team_menu,
                                      QString::fromStdString(team.name),
                                      QString::fromStdString(inhibition_name));
      break;
    }
    default:
      qFatal("Invalid teams subkey index");
      break;
  }
}

void AlertingWin::delTeamEntry(dessser::gen::sync_key::t const &) {
  // TODO
}

void AlertingWin::newTeam(int result) {
  if (0 == result) return;

  QString const name{newTeamDialog->getValue()};

  if (verbose) qDebug() << "newTeam" << name;

  std::shared_ptr<dessser::gen::sync_key::t const> k{
      keyOfTeamContact(name.toStdString(), std::string("default"))};

  std::shared_ptr<dessser::gen::sync_value::t const> v{
      std::make_shared<dessser::gen::sync_value::t>(
          std::in_place_index<dessser::gen::sync_value::AlertingContact>,
          std::make_shared<dessser::gen::alerting_contact::t>(
              std::make_shared<dessser::gen::alerting_contact::via>(
                  std::in_place_index<dessser::gen::alerting_contact::Ignore>,
                  dessser::Void()),
              0.))};

  Menu::getClient()->sendNew(k, v);
}

void AlertingWin::newContact(int result) {
  if (0 == result) return;

  if (verbose) qDebug() << "newContact";

  QString const team_name{newContactDialog->getTeamName()};
  QString const contact_name{newContactDialog->getContactName()};

  std::shared_ptr<dessser::gen::sync_key::t const> k{
      keyOfTeamContact(team_name.toStdString(), contact_name.toStdString())};

  std::shared_ptr<dessser::gen::sync_value::t const> v{
      newContactDialog->getValue()};

  Menu::getClient()->sendNew(k, v);
}

void AlertingWin::newInhibition(int result) {
  if (0 == result) return;

  if (verbose) qDebug() << "newInhibition";

  QString const team_name{newInhibitionDialog->getTeamName()};
  QString const inhibition_name{newInhibitionDialog->getInhibitionName()};

  std::shared_ptr<dessser::gen::sync_key::t const> k{
      keyOfInhibition(team_name.toStdString(), inhibition_name.toStdString())};

  std::shared_ptr<dessser::gen::sync_value::t const> v{
      newInhibitionDialog->getValue()};

  Menu::getClient()->sendNew(k, v);
}
