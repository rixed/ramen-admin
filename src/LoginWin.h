#ifndef LOGINWIN_H_191107
#define LOGINWIN_H_191107
/* This is the root window that handle user identity and connection to a
 * given server. Once the user is authenticated with the server this window
 * gives way to the actual RmAdmin windows but until then that's the only
 * possible window.
 *
 * It has the menu (with only exit) and the main status bar.
 * It is also a SavedWindow.
 * It can be hidden but not closed, or the whole app will exit.
 * It is not possible to change server once connected.
 * OCaml connection thread is started from here when the login form is
 * submitted, and the menu is properly populated when authentication is
 * successful.
 * The only widget for now in there is the LoginWidget. */
#include <QString>
#include "KErrorMsg.h"
#include "SavedWindow.h"
#include "SyncStatus.h"

class ConfClient;
struct UserIdentity;
class LoginWidget;

class LoginWin : public SavedWindow
{
  Q_OBJECT

  LoginWidget *loginWidget;

  ConfClient *client;

  // FIXME: those two are now redundant with client
  SyncStatus syncStatus;
  QString errMsg;

  void setStatusMsg();
  KErrorMsg *errorMessage;

  // Once set by the loginWidget:
  QString const server;

public:
  LoginWin(QString const configDir, QWidget *parent = nullptr);
  ~LoginWin();
  void focusSubmit();

protected slots:
  // If idfile is null then it is assumed insecure, and the other way around.
  void startApp(
    QString const server, QString const username, QString const idFile);

  void exitApp();

public slots:
  void syncProgress(SyncStatus);
  void syncFailed(SyncStatus, QString const &);

signals:
  void authenticated();
};

#endif
