#ifndef MENU_H_190731
#define MENU_H_190731
#include <string>
#include <QObject>
#include "KVStore.h"

class AboutDialog;
class ConfClient;
class ConfTreeDialog;
struct KValue;
class LoggerWin;
class LoginWin;
class NamesTreeWin;
#ifdef WITH_DASHBOARDS
class NewDashboardDialog;
#endif
#ifdef WITH_PROGRAMS
class NewProgramDialog;
#endif
#ifdef WITH_SOURCES
class NewSourceDialog;
#endif
#ifdef WITH_OPERATIONS
class OperationsWin;
#endif
#ifdef WITH_PROCESSES
class ProcessesDialog;
#endif
class QMainWindow;
class QMenuBar;
class RCEditorDialog;
class ServerInfoWin;
#ifdef WITH_SOURCES
class SourcesWin;
#endif
#ifdef WITH_STORAGE
class StorageWin;
#endif
#ifdef WITH_ALERTING
class AlertingWin;
#endif

/* We need some slots to open the windows from various places, therefore
 * we need a Q_OBJECT.
 * Of course we only ever want a single instance of it: */

class QMenu;

namespace dessser {
  namespace gen {
    namespace sync_key {
      struct t;
    }
  }
}

class Menu : public QObject
{
  Q_OBJECT

  QMenu *fileMenu, *windowMenu, *dashboardMenu, *alertMenu;

  void populateMenu(bool, bool);
  void showSomething();

  // Add a dashboard in the dashboard menu:
# ifdef WITH_DASHBOARDS
  void addDashboard(QString const &, std::string const &key_prefix);
# endif
  void addValue(dessser::gen::sync_key::t const &, KValue const &);
  void delValue(dessser::gen::sync_key::t const &, KValue const &);

public:
  QMenuBar *menuBar;
  bool fullMenu;

  static AboutDialog *aboutDialog;
# ifdef WITH_SOURCES
  static SourcesWin *sourcesWin;
# endif
  static ConfTreeDialog *confTreeDialog;
# ifdef WITH_SOURCES
  static NewSourceDialog *newSourceDialog;
# endif
# ifdef WITH_PROGRAMS
  static NewProgramDialog *newProgramDialog;
# endif
# ifdef WITH_DASHBOARDS
  static NewDashboardDialog *newDashboardDialog;
# endif
# ifdef WITH_PROCESSES
  static ProcessesDialog *processesDialog;
# endif
  static RCEditorDialog *rcEditorDialog;
  static NamesTreeWin *namesTreeWin;
# ifdef WITH_STORAGE
  static StorageWin *storageWin;
# endif
  static ServerInfoWin *serverInfoWin;
# ifdef WITH_OPERATIONS
  static OperationsWin *operationsWin;
# endif
  static LoginWin *loginWin;
  static LoggerWin *loggerWin;
# ifdef WITH_ALERTING
  static AlertingWin *alertingWin;
# endif

  static void initDialogs(QString const &srvUrl);
  static void initLoginWin(QString const &configDir);
  static void deleteDialogs();

  Menu(bool fullMenu, QMainWindow *);

public slots:
  void upgradeToFull();  // and show something
# ifdef WITH_SOURCES
  static void openNewSourceDialog();
# endif
# ifdef WITH_PROGRAMS
  static void openNewProgramDialog();
# endif
# ifdef WITH_DASHBOARDS
  static void openNewDashboardDialog();
# endif
# ifdef WITH_SOURCES
  static void openSourceEditor();
# endif
# ifdef WITH_PROCESSES
  static void openProcesses();
# endif
  static void openRCEditor();
  static void openConfTreeDialog();
  static void openAboutDialog();
  static void openNamesTreeWin();
# ifdef WITH_STORAGE
  static void openStorageWin();
# endif
# ifdef WITH_ALERTING
  static void openAlertingWin();
# endif
  static void openServerInfoWin();
# ifdef WITH_OPERATIONS
  static void openOperationsWin();
# endif
  static void openLoginWin();
  static void openLoggerWin();
  static void prepareQuit();
# ifdef WITH_DASHBOARDS
  static void openDashboard(QString const &, std::string const &);
# endif
  static ConfClient *getClient();

protected slots:
  void onChange(QList<ConfChange> const &);
};

#endif
