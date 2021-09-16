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
#ifdef WITH_DASHBOARDS
# include "dashboard/DashboardWindow.h"
# include "dashboard/NewDashboardDialog.h"
# include "dashboard/tools.h"
#endif
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
#ifdef WITH_PROCESSES
#include "ProcessesDialog.h"
#endif
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
#ifdef WITH_DASHBOARDS
NewDashboardDialog *Menu::newDashboardDialog;
#endif
#ifdef WITH_PROCESSES
ProcessesDialog *Menu::processesDialog;
#endif
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
# ifdef WITH_DASHBOARDS
  if (verbose) qDebug() << "Create NewDashboardDialog...";
  if (! newDashboardDialog) newDashboardDialog = new NewDashboardDialog;
# endif
# ifdef WITH_PROCESSES
  if (verbose) qDebug() << "Create ProcessesDialog...";
  if (! processesDialog) processesDialog = new ProcessesDialog;
# endif
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
  if (verbose) qDebug() << "Create Logger ...";
  if (! loggerWin) loggerWin = new LoggerWin;
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
# ifdef WITH_PROCESSES
  someOpened |= processesDialog->isVisible();
# endif
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
# ifdef WITH_DASHBOARDS
  danceOfDelLater<NewDashboardDialog>(&newDashboardDialog);
# endif
# ifdef WITH_PROCESSES
  danceOfDelLater<ProcessesDialog>(&processesDialog);
# endif
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

#   ifdef WITH_PROCESSES
    /* The list of all running processes, as a qtree, equivalent to the
     * `ramen ps` command, but nicer and with stats push all the way: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Processes…"),
      this, &Menu::openProcesses);
#   endif

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

    /* The Logger window */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Log messages…"),
      this, &Menu::openLoggerWin);

    /* As a last resort, a raw edition window: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "Raw Configuration…"),
      this, &Menu::openConfTreeDialog);
  }

  if (basic) {
    /* An "About" entry added in any menu (but not directly in the top menubar)
     * will be moved into the automatic application menu in MacOs: */
    windowMenu->addAction(
      QCoreApplication::translate("QMenuBar", "About"),
      this, &Menu::openAboutDialog);
  }

  if (extended) {
# ifdef WITH_DASHBOARDS
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
# endif

    /* Dynamically add new dashboards.
     * FIXME: do not connect those for every Menu we have! Instead, use the
     * global dashboard tree, with an additional column in the model for the
     * acxtual key (column 0 saying the user facing hierarchical name) */
    connect(kvs.get(), &KVStore::keyChanged,
            this, &Menu::onChange);

# ifdef WITH_DASHBOARDS
    /* Also populate from what we already have: */
    iterDashboards([this](std::string const &, KValue const &,
                          QString const &name, std::string const &key_prefix) {
      addDashboard(name, key_prefix);
    });
# endif
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

#ifdef WITH_DASHBOARDS
void Menu::openNewDashboardDialog()
{
  newDashboardDialog->clear();
  showRaised(newDashboardDialog);
}
#endif

#ifdef WITH_SOURCES
void Menu::openSourceEditor()
{
  showRaised(sourcesWin);
}
#endif

#ifdef WITH_PROCESSES
void Menu::openProcesses()
{
  showRaised(processesDialog);
}
#endif

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
  showRaised(namesTreeWin);
}

#ifdef WITH_STORAGE
void Menu::openStorageWin()
{
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
  showRaised(loggerWin);
}

void Menu::prepareQuit()
{
  saveWindowVisibility = true;
  qApp->closeAllWindows();
}

# ifdef WITH_DASHBOARDS
void Menu::addDashboard(QString const &name, std::string const &key_prefix)
{
  // Locate where to insert this new menu entry:
  QList<QAction *> const actions = dashboardMenu->actions();
  QAction *before = nullptr;
  for (int i = NUM_STATIC_DASHBOARD_ACTIONS; i < actions.length(); i++) {
    QString const entryName(removeAmp(actions[i]->text()));
    int const c = entryName.compare(name);
    if (c < 0) continue;
    if (c == 0) return;
    before = actions[i];
    break;
  }

  if (verbose)
    qDebug() << "Menu: Adding dashboard" << name;

  QAction *openDashboardAction(new QAction(name, this));
  connect(openDashboardAction, &QAction::triggered,
    /* Note to self: those captured copies are actual copies of the underlying
     * data not of the reference */
    /* Note: we do not specify a receiver here on purpose, as openDashboard is
     * a static member. */
    [name, key_prefix] (bool) {
      openDashboard(name, key_prefix);
  });
  dashboardMenu->insertAction(before, openDashboardAction);
}
# endif

void Menu::addValue(dessser::gen::sync_key::t const &key, KValue const &)
{
# ifdef WITH_DASHBOARDS
  std::pair<QString const, std::string> name_prefix =
    dashboardNameAndPrefOfKey(key);
  if (!name_prefix.first.isEmpty())
      addDashboard(name_prefix.first, name_prefix.second);
  // Other dynamic menus can be completed here
# else
  (void)key;
# endif
}

void Menu::delValue(dessser::gen::sync_key::t const &key, KValue const &)
{
# ifdef WITH_DASHBOARDS
  std::pair<QString const, std::string> name_prefix =
    dashboardNameAndPrefOfKey(key);
  QString const &name(name_prefix.first);
  std::string const &prefix(name_prefix.second);

  if (name.isEmpty()) return;

  if (dashboardNumWidgets(prefix) > 0) {
    if (verbose)
      qDebug() << "Menu: Dashboard" << name << "still has widgets";
    return;
  }

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
# else
  (void)key;
# endif
}

void Menu::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyCreated:
        addValue(change.key, change.kv);
        break;
      case KeyDeleted:
        delValue(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

#ifdef WITH_DASHBOARDS
void Menu::openDashboard(QString const &name, std::string const &key_prefix)
{
  /* Open dashboards only once: */
  static std::mutex lock;
  static std::map<QString, DashboardWindow *> windows;

  lock.lock();

  auto const it = windows.find(name);
  if (it != windows.end()) {
    if (verbose)
      qDebug() << "Reopen dashboard window" << name << it->second;
    showRaised(it->second);
  } else {
    DashboardWindow *w = new DashboardWindow(name, key_prefix);
    if (verbose)
      qDebug() << "No dashboard window for" << name << ", creating it as" << w;
    windows.insert({ name, w });
    showRaised(w);
  }

  lock.unlock();
}
# endif

ConfClient *Menu::getClient()
{
  return loginWin->client;
}
