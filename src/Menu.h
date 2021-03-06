// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef MENU_H_190731
#define MENU_H_190731
/* There exist one instance of a Menu per SavedWindow, but most of what they do
 * is the same and on the same global state, thus the many static functions and
 * variables. */
#include <QObject>
#include <string>

#include "ConfChange.h"
#include "KVStore.h"

class AboutDialog;
class ConfClient;
class RawConfWin;
struct KValue;
class LoggerWin;
class LoginWin;
class NamesTreeWin;
class NewDashboardDialog;
class NewTargetConfigEntryDialog;
class NewSourceDialog;
class OperationsWin;
class ProcessesWin;
class QMainWindow;
class QMenuBar;
class TargetConfigEditorWin;
class ServerInfoWin;
class SourcesWin;
class StorageWin;
class AlertingWin;
class HelpWin;

/* We need some slots to open the windows from various places, therefore
 * we need a Q_OBJECT.
 * Of course we only ever want a single instance of it: */

class QMenu;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
}  // namespace gen
}  // namespace dessser

class Menu : public QObject {
  Q_OBJECT

  QMenu *fileMenu, *windowMenu, *dashboardMenu, *alertMenu, *helpMenu;

  void populateMenu(bool, bool);
  void showSomething();

  // Add a dashboard in the dashboard menu:
  void addDashboard(std::string const &);
  void addValue(dessser::gen::sync_key::t const &, KValue const &);
  void delValue(dessser::gen::sync_key::t const &, KValue const &);

 public:
  QMenuBar *menuBar;
  bool fullMenu;

  static AboutDialog *aboutDialog;
  static SourcesWin *sourcesWin;
  static RawConfWin *rawConfWin;
  static NewSourceDialog *newSourceDialog;
  static NewTargetConfigEntryDialog *newTargetConfigEntryDialog;
  static NewDashboardDialog *newDashboardDialog;
  static ProcessesWin *processesWin;
  static TargetConfigEditorWin *targetConfigEditorWin;
  static NamesTreeWin *namesTreeWin;
  static StorageWin *storageWin;
  static ServerInfoWin *serverInfoWin;
  static OperationsWin *operationsWin;
  static LoginWin *loginWin;
  static LoggerWin *loggerWin;
  static AlertingWin *alertingWin;
  static HelpWin *helpWin;

  static void initDialogs(QString const &srvUrl);
  static void initLoginWin(QString const &configDir);
  static void deleteDialogs();
  static QString const nameOfDashboard(std::string const &dash_name);

  Menu(bool fullMenu, QMainWindow *);

  static void openNewSourceDialog();
  static void openNewTargetConfigEntryDialog();
  static void openNewDashboardDialog();
  static void openSourceEditor();
  static void openProcesses();
  static void openTargetConfigEditor();
  static void openRawConfWin();
  static void openAboutDialog();
  static void openNamesTreeWin();
  static void openStorageWin();
  static void openAlertingWin();
  static void openServerInfoWin();
  static void openOperationsWin();
  static void openLoginWin();
  static void openLoggerWin();
  static void openHelpWin();
  static void prepareQuit();
  static void openDashboard(std::string const &);
  static ConfClient *getClient();

  /* Which key acts as the command key for shot-cuts: */
  static QString const commandKey;

 public slots:
  void upgradeToFull();  // and show something

 protected slots:
  void onChange(QList<ConfChange> const &);
};

#endif
