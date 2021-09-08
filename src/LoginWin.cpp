#include <memory>
#include <QDebug>
#include <QFile>
#include <QMetaObject>
#include "ConfClient.h"
#include "LoginWidget.h"
#include "LoginWin.h"
#include "Menu.h"
#include "UserIdentity.h"

LoginWin::LoginWin(
  QString configDir,
  QWidget *parent)
  : SavedWindow("LoginWindow", "User Authentication", false, parent),
    client(nullptr)
{
  loginWidget = new LoginWidget(configDir);
  setCentralWidget(loginWidget);
  connect(loginWidget, &LoginWidget::submitted,
          this, &LoginWin::startApp);
  connect(loginWidget, &LoginWidget::cancelled,
          this, &LoginWin::exitApp);

  /* As a status bar we will have the connection status and total number
   * of exchanged messages. */
  errorMessage = new KErrorMsg(this);
  statusBar()->addPermanentWidget(errorMessage);

  /* Must not wait that the connProgress slot create the statusBar, as
   * it will be called from another thread: */
  statusBar()->showMessage(tr("Starting-up..."));

  connect(this, &LoginWin::authenticated,
          menu, &Menu::upgradeToFull);
}

LoginWin::~LoginWin()
{
  // Since the process is about to exit there is no need to close the client etc.
}

void LoginWin::focusSubmit()
{
  loginWidget->focusSubmit();
}

void LoginWin::startApp(
  QString const server, QString const username, QString const idFile)
{
  loginWidget->setSubmitStatus("");

  std::shared_ptr<UserIdentity const> id;
  if (! idFile.isEmpty()) {
    QFile file(idFile);
    id = std::make_shared<UserIdentity>(file);
    if (! id->isValid) {
      qCritical() << "Identity file" << idFile << "is not valid";
      id.reset();
      QCoreApplication::exit(1);
      return;
    }
  }

  /* Create the windows that will connect to the kvs->map keys *before*
   * the connection is attempted: */
  Menu::initDialogs(server);

  client = new ConfClient(server, username, id, kvs);
  connect(client, &ConfClient::knownErrKey,
          errorMessage, &KErrorMsg::setKey);
  connect(client, &ConfClient::connectionProgressed,
          this, &LoginWin::syncProgress);
  connect(client, &ConfClient::connectionFatalError,
          this, &LoginWin::syncFailed);
}

void LoginWin::exitApp()
{
  QCoreApplication::quit();
}

void LoginWin::setStatusMsg()
{
  QStatusBar *sb = statusBar(); // create it if it doesn't exist yet

  if (! errMsg.isEmpty()) {
    sb->setStyleSheet("background-color: pink;");
  }
  sb->showMessage(errMsg);

  loginWidget->setSubmitStatus(syncStatus.message());
}

void LoginWin::syncProgress(SyncStatus status)
{
  syncStatus = status;
  setStatusMsg();
  // Start the actual interface as soon as synchronization starts:
  if (status.status == SyncStatus::Status::Synchronizing) {
    emit authenticated();
    //hide();
  }
}

void LoginWin::syncFailed(SyncStatus lastStatus, QString const &msg)
{
  syncStatus = lastStatus;
  errMsg = msg;
  setStatusMsg();
}
