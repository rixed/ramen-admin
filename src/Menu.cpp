#include <cassert>
#include <map>
#include <QAction>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QMainWindow>
#include <QMenuBar>
#include <QKeySequence>
#include "AboutDialog.h"
#include "ConfClient.h"
#include "ConfTreeDialog.h"
#include "dashboard/DashboardWindow.h"
#include "dashboard/NewDashboardDialog.h"
#include "dashboard/tools.h"
#include "LoggerView.h"
#include "LoggerWin.h"
#include "LoginWin.h"
#include "misc.h"
#include "NamesTreeWin.h"
#ifdef WITH_SOURCES
#include "NewSourceDialog.h"
#endif
#ifdef WITH_PROGRAMS
#include "NewProgramDialog.h"
#endif
#ifdef WITH_OPERATIONS
#include "OperationsWin.h"
#endif
#include "ProcessesDialog.h"
#include "RCEditorDialog.h"
#include "SavedWindow.h"
#include "ServerInfoWin.h"
#ifdef WITH_SOURCES
#include "SourcesWin.h"
#endif
#ifdef WITH_STORAGE
#include "StorageWin.h"
#endif
#ifdef WITH_ALERTING
#include "alerting/AlertingWin.h"
#endif

#include "Menu.h"

static bool const verbose(false);

AboutDialog *Menu::aboutDialog;
#ifdef WITH_SOURCES
SourcesWin *Menu::sourcesWin;
#endif
ConfTreeDialog *Menu::confTreeDialog;
#ifdef WITH_SOURCES
NewSourceDialog *Menu::newSourceDialog;
#endif
#ifdef WITH_PROGRAMS
NewProgramDialog *Menu::newProgramDialog;
# endif
NewDashboardDialog *Menu::newDashboardDialog;
ProcessesDialog *Menu::processesDialog;
RCEditorDialog *Menu::rcEditorDialog;
NamesTreeWin *Menu::namesTreeWin;
#ifdef WITH_STORAGE
StorageWin *Menu::storageWin;
#endif
ServerInfoWin *Menu::serverInfoWin;
#ifdef WITH_OPERATIONS
OperationsWin *Menu::operationsWin;
# endif
LoginWin *Menu::loginWin;
LoggerWin *Menu::loggerWin;
#ifdef WITH_ALERTING
AlertingWin *Menu::alertingWin;
#endif

void Menu::initLoginWin(QString const &configDir)
{
  if (verbose) qDebug() << "Create LoginWin...";
  if (! loginWin) loginWin = new LoginWin(configDir);
}

void Menu::initDialogs(QString const &srvUrl)
{
# ifdef WITH_SOURCES
  if (verbose) qDebug() << "Create SourceEditor...";
  if (! sourcesWin) sourcesWin = new SourcesWin;
# endif
  if (verbose) qDebug() << "Create ConfTreeDialog...";
  if (!confTreeDialog) confTreeDialog = new ConfTreeDialog;
# ifdef WITH_SOURCES
  if (verbose) qDebug() << "Create NewSourceDialog...";
  if (! newSourceDialog) newSourceDialog = new NewSourceDialog;
# endif
# ifdef WITH_PROGRAMS
  if (verbose) qDebug() << "Create NewProgramDialog...";
  if (! newProgramDialog) newProgramDialog = new NewProgramDialog;
# endif
  if (verbose) qDebug() << "Create NewDashboardDialog...";
  if (! newDashboardDialog) newDashboardDialog = new NewDashboardDialog;
  if (verbose) qDebug() << "Create ProcessesDialog...";
  if (! processesDialog) processesDialog = new ProcessesDialog;
  if (verbose) qDebug() << "Create RCEditorDialog...";
  if (! rcEditorDialog) rcEditorDialog = new RCEditorDialog;
  if (verbose) qDebug() << "Create NamesTreeWin...";
  if (! namesTreeWin) namesTreeWin = new NamesTreeWin;
# ifdef WITH_STORAGE
  if (verbose) qDebug() << "Create StorageWin...";
  if (! storageWin) storageWin = new StorageWin;
# endif
  if (verbose) qDebug() << "Create ServerInfoWin...";
  if (! serverInfoWin) serverInfoWin = new ServerInfoWin(srvUrl);
# ifdef WITH_OPERATIONS
  if (verbose) qDebug() << "Create OperationsWin...";
  if (! operationsWin) operationsWin = new OperationsWin;
# endif
# ifdef WITH_ALERTING
  if (verbose) qDebug() << "Create AlertingWin ...";
  if (! alertingWin) alertingWin = new AlertingWin;
# endif
  // login is supposed to be initialized first
  assert(loginWin);
}

void Menu::showSomething()
{
  bool someOpened = false;
# ifdef WITH_SOURCES
  someOpened |= sourcesWin->isVisible();
# endif
  someOpened |= confTreeDialog->isVisible();
  someOpened |= processesDialog->isVisible();
  someOpened |= rcEditorDialog->isVisible();
# ifdef WITH_STORAGE
  someOpened |= storageWin->isVisible();
# endif

# ifdef WITH_SOURCES
  if (! someOpened) sourcesWin->show();
# endif
}

void Menu::deleteDialogs()
{
  danceOfDelLater<LoginWin>(&loginWin);

  danceOfDelLater<AboutDialog>(&aboutDialog);
# ifdef WITH_SOURCES
  danceOfDelLater<SourcesWin>(&sourcesWin);
# endif
  danceOfDelLater<ConfTreeDialog>(&confTreeDialog);
# ifdef WITH_SOURCES
  danceOfDelLater<NewSourceDialog>(&newSourceDialog);
# endif
# ifdef WITH_PROGRAMS
  danceOfDelLater<NewProgramDialog>(&newProgramDialog);
# endif
  danceOfDelLater<NewDashboardDialog>(&newDashboardDialog);
  danceOfDelLater<ProcessesDialog>(&processesDialog);
  danceOfDelLater<RCEditorDialog>(&rcEditorDialog);
  danceOfDelLater<NamesTreeWin>(&namesTreeWin);
# ifdef WITH_STORAGE
  danceOfDelLater<StorageWin>(&storageWin);
# endif
  danceOfDelLater<ServerInfoWin>(&serverInfoWin);
# ifdef WITH_OPERATIONS
  danceOfDelLater<OperationsWin>(&operationsWin);
# endif
# ifdef WITH_ALERTING
  danceOfDelLater<AlertingWin>(&alertingWin);
# endif
  // delLater is never when we quit the app:
  if (loggerWin) loggerWin->loggerView->flush();
  danceOfDelLater<LoggerWin>(&loggerWin);
}

/* This function can be called either once (with basic and extended) or twice
 * (first with basic, and then with extended): */
void Menu::populateMenu(bool basic, bool extended)
{
  if (basic) {
    /* Where we can create sources, programs, edit the running config,
     * setup storage... Everything that's editing the configuration
     * in a user friendly way. */
    fileMenu = menuBar->addMenu(
      QCoreApplication::translate("QMenuBar", "&File"));
  }

  if (extended) {
    assert(fileMenu);  // user is supposed to populate basic first
#   ifdef WITH_SOURCES
    fileMenu->addAction(
      QCoreApplication::translate("QMenuBar", "New Source…"),
      this, &Menu::openNewSourceDialog,
      QKeySequence::New);
#   endif
#   ifdef WITH_PROGRAMS
    fileMenu->addAction(
      QCoreApplication::translate("QMenuBar", "New Program…"),
      this, &Menu::openNewProgramDialog,
      Qt::CTRL|Qt::Key_R); // _R_un
#   endif

    fileMenu->addSeparator();
  }

  if (basic) {
    fileMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Quit"),
      this, &Menu::prepareQuit,
      Qt::CTRL|Qt::Key_Q); // _Q_uit

    /* Where we can manage the windows and ask for specialized views
     * such as the raw editor, the graph view or other such tools: */
    windowMenu = menuBar->addMenu(
      QCoreApplication::translate("QMenuBar", "&Window"));

    /* The login window */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Login…"),
      this, &Menu::openLoginWin);
  }

  if (extended) {
#   ifdef WITH_SOURCES
    /* The code editor (also the initial window) */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Source Editor…"),
      this, &Menu::openSourceEditor);
#   endif

#   ifdef WITH_OPERATIONS
    /* The graph of operations window: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Graph of Operations…"),
      this, &Menu::openOperationsWin);
#   endif

    /* The list of all running processes, as a qtree, equivalent to the
     * `ramen ps` command, but nicer and with stats push all the way: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Processes…"),
      this, &Menu::openProcesses);

    /* The TargetConfig editor: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Running Configuration…"),
      this, &Menu::openRCEditor);

#   ifdef WITH_STORAGE
    /* The Storage configuration window: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Storage Configuration…"),
      this, &Menu::openStorageWin);
#   endif

#   ifdef WITH_ALERTING
    /* The alerting window: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Alerting…"),
      this, &Menu::openAlertingWin);
#   endif

    /* The Server Information window: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Server Information…"),
      this, &Menu::openServerInfoWin);

    /* As a last resort, a raw edition window: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Raw Configuration…"),
      this, &Menu::openConfTreeDialog);
  }

  if (basic) {
    /* The Logger window */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Log messages…"),
      this, &Menu::openLoggerWin);

    /* An "About" entry added in any menu (but not directly in the top menubar)
     * will be moved into the automatic application menu in MacOs: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "About"),
      this, &Menu::openAboutDialog);
  }

  if (extended) {
    dashboardMenu = menuBar->addMenu(
      QCoreApplication::translate("QMenuBar", "&Dashboard"));

    /* Number of static entries in the dashboardMenu before the list of
     * defined dashboards (separator does count as an action): */
#   define NUM_STATIC_DASHBOARD_ACTIONS 2

    dashboardMenu->addAction(
      QCoreApplication::translate("QMenuBar", "New Dashboard…"),
      this, &Menu::openNewDashboardDialog,
      Qt::CTRL|Qt::Key_D);

    dashboardMenu->addSeparator();

    /* Dynamically add new dashboards.
     * FIXME: do not connect those for every Menu we have! Instead, use the
     * global dashboard tree, with an additional column in the model for the
     * acxtual key (column 0 saying the user facing hierarchical name) */
    connect(kvs.get(), &KVStore::keyChanged,
            this, &Menu::onChange);

    /* Also populate from what we already have: */
    iterDashboards([this](std::string const &dash_name) { addDashboard(dash_name); });
  }

  if (extended && WITH_BETA_FEATURES) {
#   ifdef WITH_ALERTING
    alertMenu = menuBar->addMenu(
      QCoreApplication::translate("QMenuBar", "&Alert"));
    (void)alertMenu;
#   endif

    /* DEBUG: the list of all names, to test autocompletion: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Completable Names…"),
      this, &Menu::openNamesTreeWin);
  }
}

Menu::Menu(bool fullMenu_, QMainWindow *mainWindow) :
  QObject(nullptr),
  fullMenu(fullMenu_)
{
  // A single menubar for all windows:
  menuBar = mainWindow->menuBar();

  populateMenu(true, fullMenu);
}

void Menu::upgradeToFull()
{
  if (fullMenu) return;
  populateMenu(false, true);
  showSomething();
}

static void showRaised(QWidget *w)
{
  if (! w) return;
  w->show();
  w->raise();
}

#ifdef WITH_SOURCES
void Menu::openNewSourceDialog()
{
  newSourceDialog->clear();
  showRaised(newSourceDialog);
}
#endif

#ifdef WITH_PROGRAMS
void Menu::openNewProgramDialog()
{
  showRaised(newProgramDialog);
}
#endif

void Menu::openNewDashboardDialog()
{
  newDashboardDialog->clear();
  showRaised(newDashboardDialog);
}

#ifdef WITH_SOURCES
void Menu::openSourceEditor()
{
  showRaised(sourcesWin);
}
#endif

void Menu::openProcesses()
{
  // If opened too early that window will actually be deleted on close:
  if (! processesDialog) processesDialog = new ProcessesDialog;
  showRaised(processesDialog);
}

void Menu::openRCEditor()
{
  showRaised(rcEditorDialog);
}

void Menu::openConfTreeDialog()
{
  showRaised(confTreeDialog);
}

void Menu::openAboutDialog()
{
  if (! aboutDialog) aboutDialog = new AboutDialog;
  showRaised(aboutDialog);
}

void Menu::openNamesTreeWin()
{
  // If opened too early that window will actually be deleted on close:
  if (! namesTreeWin) namesTreeWin = new NamesTreeWin;
  showRaised(namesTreeWin);
}

#ifdef WITH_STORAGE
void Menu::openStorageWin()
{
  // If opened too early that window will actually be deleted on close:
  if (! storageWin) storageWin = new StorageWin;
  showRaised(storageWin);
}
#endif

void Menu::openServerInfoWin()
{
  showRaised(serverInfoWin);
}

#ifdef WITH_OPERATIONS
void Menu::openOperationsWin()
{
  showRaised(operationsWin);
}
#endif

#ifdef WITH_ALERTING
void Menu::openAlertingWin()
{
  showRaised(alertingWin);
}
#endif

void Menu::openLoginWin()
{
  showRaised(loginWin);
  loginWin->focusSubmit();
}

void Menu::openLoggerWin()
{
  if (! loggerWin) loggerWin = new LoggerWin;
  showRaised(loggerWin);
}

void Menu::prepareQuit()
{
  saveWindowVisibility = true;
  qApp->closeAllWindows();
}

QString const Menu::nameOfDashboard(std::string const &dash_name)
{
  return
    dash_name.empty() ? QString("--scratchpad--")
                      : QString::fromStdString(dash_name);
}

void Menu::addDashboard(std::string const &dash_name)
{
  // Locate where to insert this new menu entry:
  QString const menu_name { nameOfDashboard(dash_name) };
  QList<QAction *> const actions = dashboardMenu->actions();
  QAction *before = nullptr;
  for (int i = NUM_STATIC_DASHBOARD_ACTIONS; i < actions.length(); i++) {
    QString const entryName(removeAmp(actions[i]->text()));
    int const c = entryName.compare(menu_name);
    if (c < 0) continue;
    if (c == 0) return;
    before = actions[i];
    break;
  }

  if (verbose)
    qDebug() << "Menu: Adding dashboard" << menu_name;

  QAction *openDashboardAction(new QAction(menu_name, this));
  connect(openDashboardAction, &QAction::triggered,
    /* Note to self: those captured copies are actual copies of the underlying
     * data not of the reference */
    /* Note: we do not specify a receiver here on purpose, as openDashboard is
     * a static member. */
    [dash_name] (bool) { openDashboard(dash_name); });
  dashboardMenu->insertAction(before, openDashboardAction);
}

void Menu::addValue(dessser::gen::sync_key::t const &key, KValue const &)
{
  if (isDashboardKey(key)) {
    std::string const dash_name { dashboardNameOfKey(key) };
    addDashboard(dash_name);
  }
  // Other dynamic menus can be completed here
}

void Menu::delValue(dessser::gen::sync_key::t const &key, KValue const &)
{
  if (isDashboardKey(key)) {
    std::string const &dash_name { dashboardNameOfKey(key) };

    if (isScratchpad(dash_name)) return;

    if (dashboardNumWidgets(dash_name) > 0) {
      if (verbose)
        qDebug()
          << "Menu: Dashboard" << QString::fromStdString(dash_name) << "still has widgets";
      return;
    }

    QString const name { nameOfDashboard(dash_name) };
    QList<QAction *> const actions = dashboardMenu->actions();
    for (int i = NUM_STATIC_DASHBOARD_ACTIONS; i < actions.length(); ) {
      int const c = actions[i]->text().compare(name);
      if (c > 0) {
        qWarning() << "Menu: Deleted dashboard" << name << "not found!?";
        break;
      } else if (c == 0) {
        if (verbose)
          qDebug() << "Menu: Removing dashboard" << name;
        dashboardMenu->removeAction(actions[i]);
        break;
      } else i++;
    }
  }
  // Other dynamic menus can be updated here
}

void Menu::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
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

void Menu::openDashboard(std::string const &dash_name)
{
  /* Open dashboards only once: */
  static std::mutex lock;
  static std::map<std::string, DashboardWindow *> windows;

  lock.lock();

  auto const it { windows.find(dash_name) };
  if (it != windows.end()) {
    if (verbose)
      qDebug()
        << "Reopen dashboard window" << QString::fromStdString(dash_name) << it->second;
    showRaised(it->second);
  } else {
    DashboardWindow *w { new DashboardWindow(dash_name) };
    if (verbose)
      qDebug()
        << "No dashboard window for" << QString::fromStdString(dash_name)
        << ", creating it as" << w;
    windows.insert({ dash_name, w });
    showRaised(w);
  }

  lock.unlock();
}

ConfClient *Menu::getClient()
{
  return loginWin->client;
}
