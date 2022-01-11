// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "Menu.h"

#include <QAction>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QKeySequence>
#include <QMainWindow>
#include <QMenuBar>
#include <map>

#include "AboutDialog.h"
#include "ConfClient.h"
#include "LoggerView.h"
#include "LoggerWin.h"
#include "LoginWin.h"
#include "NamesTreeWin.h"
#include "SavedWindow.h"
#include "ServerInfoWin.h"
#include "alerting/AlertingWin.h"
#include "dashboard/DashboardWindow.h"
#include "dashboard/NewDashboardDialog.h"
#include "dashboard/tools.h"
#include "misc.h"
#include "processes/ProcessesWin.h"
#include "raw/RawConfWin.h"
#include "source/NewSourceDialog.h"
#include "source/SourcesWin.h"
#include "storage/StorageWin.h"
#include "stream/OperationsWin.h"
#include "target_config/NewTargetConfigEntryDialog.h"
#include "target_config/TargetConfigEditorWin.h"

static bool const verbose{false};

AboutDialog *Menu::aboutDialog;
SourcesWin *Menu::sourcesWin;
RawConfWin *Menu::rawConfWin;
NewSourceDialog *Menu::newSourceDialog;
NewTargetConfigEntryDialog *Menu::newTargetConfigEntryDialog;
NewDashboardDialog *Menu::newDashboardDialog;
ProcessesWin *Menu::processesWin;
TargetConfigEditorWin *Menu::targetConfigEditorWin;
NamesTreeWin *Menu::namesTreeWin;
StorageWin *Menu::storageWin;
ServerInfoWin *Menu::serverInfoWin;
OperationsWin *Menu::operationsWin;
LoginWin *Menu::loginWin;
LoggerWin *Menu::loggerWin;
AlertingWin *Menu::alertingWin;

QString const Menu::commandKey{
/* Assuming compilation time OS == runtime OS: */
#ifdef __APPLE__
    "⌘"
#else
    "Ctrl"
#endif
};

void Menu::initLoginWin(QString const &configDir) {
  if (verbose) qDebug() << "Create LoginWin...";
  if (!loginWin) loginWin = new LoginWin(configDir);
}

void Menu::initDialogs(QString const &srvUrl) {
  if (verbose) qDebug() << "Create SourceEditor...";
  if (!sourcesWin) sourcesWin = new SourcesWin;
  if (verbose) qDebug() << "Create RawConfWin...";
  if (!rawConfWin) rawConfWin = new RawConfWin;
  if (verbose) qDebug() << "Create NewSourceDialog...";
  if (!newSourceDialog) newSourceDialog = new NewSourceDialog;
  if (verbose) qDebug() << "Create NewTargetConfigEntryDialog...";
  if (!newTargetConfigEntryDialog)
    newTargetConfigEntryDialog = new NewTargetConfigEntryDialog;
  if (verbose) qDebug() << "Create NewDashboardDialog...";
  if (!newDashboardDialog) newDashboardDialog = new NewDashboardDialog;
  if (verbose) qDebug() << "Create ProcessesWin...";
  if (!processesWin) processesWin = new ProcessesWin;
  if (verbose) qDebug() << "Create TargetConfigEditorWin...";
  if (!targetConfigEditorWin) targetConfigEditorWin = new TargetConfigEditorWin;
  if (verbose) qDebug() << "Create NamesTreeWin...";
  if (!namesTreeWin) namesTreeWin = new NamesTreeWin;
  if (verbose) qDebug() << "Create StorageWin...";
  if (!storageWin) storageWin = new StorageWin;
  if (verbose) qDebug() << "Create ServerInfoWin...";
  if (!serverInfoWin) serverInfoWin = new ServerInfoWin(srvUrl);
  if (verbose) qDebug() << "Create OperationsWin...";
  if (!operationsWin) operationsWin = new OperationsWin;
  if (verbose) qDebug() << "Create AlertingWin ...";
  if (!alertingWin) alertingWin = new AlertingWin;
  // login is supposed to be initialized first
  Q_ASSERT(loginWin);
}

void Menu::showSomething() {
  bool someOpened = false;
  someOpened |= sourcesWin->isVisible();
  someOpened |= rawConfWin->isVisible();
  someOpened |= processesWin->isVisible();
  someOpened |= targetConfigEditorWin->isVisible();
  someOpened |= storageWin->isVisible();

  if (!someOpened) sourcesWin->show();
}

void Menu::deleteDialogs() {
  danceOfDelLater<LoginWin>(&loginWin);

  danceOfDelLater<AboutDialog>(&aboutDialog);
  danceOfDelLater<SourcesWin>(&sourcesWin);
  danceOfDelLater<RawConfWin>(&rawConfWin);
  danceOfDelLater<NewSourceDialog>(&newSourceDialog);
  danceOfDelLater<NewTargetConfigEntryDialog>(&newTargetConfigEntryDialog);
  danceOfDelLater<NewDashboardDialog>(&newDashboardDialog);
  danceOfDelLater<ProcessesWin>(&processesWin);
  danceOfDelLater<TargetConfigEditorWin>(&targetConfigEditorWin);
  danceOfDelLater<NamesTreeWin>(&namesTreeWin);
  danceOfDelLater<StorageWin>(&storageWin);
  danceOfDelLater<ServerInfoWin>(&serverInfoWin);
  danceOfDelLater<OperationsWin>(&operationsWin);
  danceOfDelLater<AlertingWin>(&alertingWin);
  // delLater is never when we quit the app:
  if (loggerWin) loggerWin->loggerView->flush();
  danceOfDelLater<LoggerWin>(&loggerWin);
}

/* This function can be called either once (with basic and extended) or twice
 * (first with basic, and then with extended): */
void Menu::populateMenu(bool basic, bool extended) {
  if (basic) {
    /* Where we can create sources, programs, edit the running config,
     * setup storage... Everything that's editing the configuration
     * in a user friendly way. */
    fileMenu =
        menuBar->addMenu(QCoreApplication::translate("QMenuBar", "&File"));
  }

  if (extended) {
    Q_ASSERT(fileMenu);  // user is supposed to populate basic first
    fileMenu->addAction(QCoreApplication::translate("QMenuBar", "New Source…"),
                        this, &Menu::openNewSourceDialog, QKeySequence::New);
    fileMenu->addAction(QCoreApplication::translate("QMenuBar", "Run…"), this,
                        &Menu::openNewTargetConfigEntryDialog,
                        Qt::CTRL | Qt::Key_R);  // _R_un

    fileMenu->addSeparator();
  }

  if (basic) {
    fileMenu->addAction(QCoreApplication::translate("QMenuBar", "Quit"), this,
                        &Menu::prepareQuit,
                        Qt::CTRL | Qt::Key_Q);  // _Q_uit

    /* Where we can manage the windows and ask for specialized views
     * such as the raw editor, the graph view or other such tools: */
    windowMenu =
        menuBar->addMenu(QCoreApplication::translate("QMenuBar", "&Window"));

    /* The login window */
    windowMenu->addAction(QCoreApplication::translate("QMenuBar", "Login…"),
                          this, &Menu::openLoginWin);
  }

  if (extended) {
    /* The code editor (also the initial window) */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Source Editor…"), this,
        &Menu::openSourceEditor);

    /* The graph of operations window: */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Graph of Operations…"), this,
        &Menu::openOperationsWin);

    /* The list of all running processes, as a qtree, equivalent to the
     * `ramen ps` command, but nicer and with stats push all the way: */
    windowMenu->addAction(QCoreApplication::translate("QMenuBar", "Processes…"),
                          this, &Menu::openProcesses);

    /* The TargetConfig editor: */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Target Configuration…"), this,
        &Menu::openTargetConfigEditor);

    /* The Storage configuration window: */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Storage Configuration…"), this,
        &Menu::openStorageWin);

    /* The alerting window: */
    windowMenu->addAction(QCoreApplication::translate("QMenuBar", "Alerting…"),
                          this, &Menu::openAlertingWin);

    /* The Server Information window: */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Server Information…"), this,
        &Menu::openServerInfoWin);

    /* As a last resort, a raw edition window: */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Raw Configuration…"), this,
        &Menu::openRawConfWin);
  }

  if (basic) {
    /* The Logger window */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Log messages…"), this,
        &Menu::openLoggerWin);

    /* An "About" entry added in any menu (but not directly in the top
     * menubar) will be moved into the automatic application menu in MacOs:
     */
    windowMenu->addAction(QCoreApplication::translate("QMenuBar", "About"),
                          this, &Menu::openAboutDialog);
  }

  if (extended) {
    dashboardMenu =
        menuBar->addMenu(QCoreApplication::translate("QMenuBar", "&Dashboard"));

    /* Number of static entries in the dashboardMenu before the list of
     * defined dashboards (separator does count as an action): */
#define NUM_STATIC_DASHBOARD_ACTIONS 2

    dashboardMenu->addAction(
        QCoreApplication::translate("QMenuBar", "New Dashboard…"), this,
        &Menu::openNewDashboardDialog, Qt::CTRL | Qt::Key_D);

    dashboardMenu->addSeparator();

    /* Dynamically add new dashboards.
     * FIXME: do not connect those for every Menu we have! Instead, use the
     * global dashboard tree, with an additional column in the model for the
     * acxtual key (column 0 saying the user facing hierarchical name) */
    connect(kvs.get(), &KVStore::keyChanged, this, &Menu::onChange);

    /* Also populate from what we already have: */
    iterDashboards(
        [this](std::string const &dash_name) { addDashboard(dash_name); });
  }

  if (extended && WITH_BETA_FEATURES) {
    alertMenu =
        menuBar->addMenu(QCoreApplication::translate("QMenuBar", "&Alert"));
    (void)alertMenu;

    /* DEBUG: the list of all names, to test autocompletion: */
    windowMenu->addAction(
        QCoreApplication::translate("QMenuBar", "Completable Names…"), this,
        &Menu::openNamesTreeWin);
  }
}

Menu::Menu(bool fullMenu_, QMainWindow *mainWindow)
    : QObject(nullptr), fullMenu(fullMenu_) {
  // A single menubar for all windows:
  menuBar = mainWindow->menuBar();

  populateMenu(true, fullMenu);
}

void Menu::upgradeToFull() {
  if (fullMenu) return;
  populateMenu(false, true);
  showSomething();
}

static void showRaised(QWidget *w) {
  if (!w) return;
  w->show();
  w->raise();
}

void Menu::openNewSourceDialog() {
  newSourceDialog->clear();
  showRaised(newSourceDialog);
}

void Menu::openNewTargetConfigEntryDialog() {
  showRaised(newTargetConfigEntryDialog);
}

void Menu::openNewDashboardDialog() {
  newDashboardDialog->clear();
  showRaised(newDashboardDialog);
}

void Menu::openSourceEditor() { showRaised(sourcesWin); }

void Menu::openProcesses() {
  // If opened too early that window will actually be deleted on close:
  if (!processesWin) processesWin = new ProcessesWin;
  showRaised(processesWin);
}

void Menu::openTargetConfigEditor() { showRaised(targetConfigEditorWin); }

void Menu::openRawConfWin() { showRaised(rawConfWin); }

void Menu::openAboutDialog() {
  if (!aboutDialog) aboutDialog = new AboutDialog;
  showRaised(aboutDialog);
}

void Menu::openNamesTreeWin() {
  // If opened too early that window will actually be deleted on close:
  if (!namesTreeWin) namesTreeWin = new NamesTreeWin;
  showRaised(namesTreeWin);
}

void Menu::openStorageWin() {
  // If opened too early that window will actually be deleted on close:
  if (!storageWin) storageWin = new StorageWin;
  showRaised(storageWin);
}

void Menu::openServerInfoWin() { showRaised(serverInfoWin); }

void Menu::openOperationsWin() { showRaised(operationsWin); }

void Menu::openAlertingWin() { showRaised(alertingWin); }

void Menu::openLoginWin() {
  showRaised(loginWin);
  loginWin->focusSubmit();
}

void Menu::openLoggerWin() {
  if (!loggerWin) loggerWin = new LoggerWin;
  showRaised(loggerWin);
}

void Menu::prepareQuit() {
  saveWindowVisibility = true;
  qApp->closeAllWindows();
}

QString const Menu::nameOfDashboard(std::string const &dash_name) {
  return isScratchpad(dash_name) ? QString("--scratchpad--")
                                 : QString::fromStdString(dash_name);
}

void Menu::addDashboard(std::string const &dash_name) {
  // Locate where to insert this new menu entry:
  QString const menu_name{nameOfDashboard(dash_name)};
  QList<QAction *> const actions{dashboardMenu->actions()};
  QAction *before{nullptr};
  for (int i = NUM_STATIC_DASHBOARD_ACTIONS; i < actions.length(); i++) {
    QString const entryName{removeAmp(actions[i]->text())};
    int const c{entryName.compare(menu_name)};
    if (c < 0) continue;
    if (c == 0) return;
    before = actions[i];
    break;
  }

  if (verbose) qDebug() << "Menu: Adding dashboard" << menu_name;

  QAction *openDashboardAction{new QAction(menu_name, this)};
  connect(openDashboardAction, &QAction::triggered,
          /* Note to self: those captured copies are actual copies of the
           * underlying data not of the reference */
          /* Note: we do not specify a receiver here on purpose, as
           * openDashboard is a static member. */
          [dash_name](bool) { openDashboard(dash_name); });
  dashboardMenu->insertAction(before, openDashboardAction);
}

void Menu::addValue(dessser::gen::sync_key::t const &key, KValue const &) {
  if (isDashboardKey(key)) {
    std::string const dash_name{dashboardNameOfKey(key)};
    addDashboard(dash_name);
  }
  // Other dynamic menus can be completed here
}

void Menu::delValue(dessser::gen::sync_key::t const &key, KValue const &) {
  if (isDashboardKey(key)) {
    std::string const &dash_name{dashboardNameOfKey(key)};

    if (isScratchpad(dash_name)) return;

    if (dashboardNumWidgets(dash_name) > 0) {
      if (verbose)
        qDebug() << "Menu: Dashboard" << QString::fromStdString(dash_name)
                 << "still has widgets";
      return;
    }

    QString const name{nameOfDashboard(dash_name)};
    QList<QAction *> const actions{dashboardMenu->actions()};
    for (int i = NUM_STATIC_DASHBOARD_ACTIONS; i < actions.length();) {
      int const c{actions[i]->text().compare(name)};
      if (c > 0) {
        qWarning() << "Menu: Deleted dashboard" << name << "not found!?";
        break;
      } else if (c == 0) {
        if (verbose) qDebug() << "Menu: Removing dashboard" << name;
        dashboardMenu->removeAction(actions[i]);
        break;
      } else
        i++;
    }
  }
  // Other dynamic menus can be updated here
}

void Menu::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
        addValue(*change.key, change.kv);
        break;
      case KeyDeleted:
        delValue(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void Menu::openDashboard(std::string const &dash_name) {
  /* Open dashboards only once: */
  static std::mutex lock;
  static std::map<std::string, DashboardWindow *> windows;

  lock.lock();

  auto const it{windows.find(dash_name)};
  if (it != windows.end()) {
    if (verbose)
      qDebug() << "Reopen dashboard window" << QString::fromStdString(dash_name)
               << it->second;
    showRaised(it->second);
  } else {
    DashboardWindow *w{new DashboardWindow(dash_name)};
    if (verbose)
      qDebug() << "No dashboard window for" << QString::fromStdString(dash_name)
               << ", creating it as" << w;
    windows.insert({dash_name, w});
    showRaised(w);
  }

  lock.unlock();
}

ConfClient *Menu::getClient() { return loginWin->client; }
