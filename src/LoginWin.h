#ifndef LOGINWIN_H_191107
#define LOGINWIN_H_191107
/* This is the root window that handle user identity and connection to a
 * given server. Once the user is authenticated with the server this window
 * gives way to the actual RmAdmin windows but until then that's the only
 * possible window (with the logs window).
 *
 * It has the menu (with only exit) and the main status bar.
 * It is also a SavedWindow.
 * It can be hidden but not closed, or the whole app will exit.
 * It is not possible to change server once connected.
 * The menu is properly populated once authentication is successful.
 * The only widget in there is the LoginWidget.
 * Statistics are displayed in the window status bar. */
#include <QString>
#include "KErrorMsg.h"
#include "SavedWindow.h"
#include "SyncStatus.h"

class QLabel;
class QTimer;
class ConfClient;
struct UserIdentity;
class LoginWidget;

class LoginWin : public SavedWindow
{
  Q_OBJECT

  LoginWidget *loginWidget;

  QString errMsg;

  void setStatusMsg(SyncStatus const);
  KErrorMsg *errorMessage;
  QLabel *stats;

  // Once set by the loginWidget:
  QString const server;

  // Timer used to refresh connection stats
  QTimer *statsTimer;

protected:
  friend class Menu;
  /* That's the only ConfClient that's ever instantiated.
   * It's the one returned by Menu::getClient() */
  ConfClient *client;

public:
  LoginWin(QString const configDir, QWidget *parent = nullptr);
  ~LoginWin();
  void focusSubmit();

protected slots:
  // If idFile is null then it is assumed insecure, and the other way around.
  void startConnect(
    QString const server, QString const username, QString const idFile);

  void exitApp();

  void refreshStats();

public slots:
  void syncProgress(SyncStatus const);
  void syncFailed(SyncStatus const, QString const &);

signals:
  void authenticated();
};

#endif
