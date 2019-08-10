#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
extern "C" {
# include <caml/mlvalues.h>
# include <caml/memory.h>
# include <caml/alloc.h>
# include <caml/custom.h>
# include <caml/startup.h>
# include <caml/callback.h>
# include <caml/threads.h>
}
#include <QApplication>
#include <QtWidgets>
#include <QMetaType>
#include <QDesktopWidget>
#include <QFile>
#include <QCommandLineParser>
#include "RmAdminWin.h"
#include "SyncStatus.h"
#include "Menu.h"
#include "UserIdentity.h"
#include "conf.h"
#include "RamenValue.h" // for ocamlThreadId
#include "GraphModel.h"
#include "GraphViewSettings.h"
extern "C" {
# include "../src/config.h"
}

static RmAdminWin *w = nullptr;

/* Relay signals from OCaml to C++ */

extern "C" {
  value signal_conn(value url_, value status_)
  {
    CAMLparam2(url_, status_);
    std::string url(String_val(url_));
    SyncStatus status(status_);
    if (w) w->connProgress(status);
    CAMLreturn(Val_unit);
  }

  value signal_auth(value status_)
  {
    CAMLparam1(status_);
    SyncStatus status(status_);
    if (w) w->authProgress(status);
    CAMLreturn(Val_unit);
  }

  value signal_sync(value status_)
  {
    CAMLparam1(status_);
    SyncStatus status(status_);
    if (w) w->syncProgress(status);
    CAMLreturn(Val_unit);
  }

  static bool quit = false;
  value should_quit()
  {
    CAMLparam0();
    CAMLreturn(Val_int(quit ? 1:0));
  }

  value set_my_errors(value key_)
  {
    CAMLparam1(key_);
    conf::Key k(String_val(key_));
    my_errors = k;
    QMetaObject::invokeMethod(w, "setErrorKey", Qt::QueuedConnection, Q_ARG(conf::Key, k));
    CAMLreturn(Val_unit);
  }
}

static void call_for_new_frame(QString const srvUrl, UserIdentity const *id, bool insecure)
{
  CAMLparam0();
  CAMLlocal5(srv_url_, username_,
             srv_pub_key_, clt_pub_key_, clt_priv_key_);
  srv_url_ = caml_copy_string(srvUrl.toStdString().c_str());
  username_ = caml_copy_string(my_uid->toStdString().c_str());
# define GET(val, var) \
    val = caml_copy_string(insecure ? "" : id->var.toStdString().c_str());
  GET(srv_pub_key_, srv_pub_key);
  GET(clt_pub_key_, clt_pub_key);
  GET(clt_priv_key_, clt_priv_key);
  value args[5] { srv_url_, username_, srv_pub_key_, clt_pub_key_, clt_priv_key_ };
  value *start_sync = caml_named_value("start_sync");
  caml_callbackN(*start_sync, 5, args);
  CAMLreturn0;
}

// The only thread that will ever call OCaml runtime:
static void do_sync_thread(QString const srvUrl, UserIdentity const *id, bool insecure, char *argv[])
{
  ocamlThreadId = std::this_thread::get_id();
  caml_startup(argv);
  call_for_new_frame(srvUrl, id, insecure);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QCoreApplication::setApplicationName("RamenAdmin");
  QCoreApplication::setApplicationVersion(PACKAGE_VERSION);

  QCommandLineParser parser;
  parser.setApplicationDescription("Test helper");
  parser.addHelpOption();
  parser.addVersionOption();

  /* The URL to connect to the server: */
  parser.addPositionalArgument("address", QCoreApplication::translate("main",
    "Address of the configuration server, as a host name or an IP, "
    "optionally followed by a colon and a port number."));

  /* Where is the config file storing out identity? */
  QCommandLineOption identityFileOption(
    QStringList() << "i" << "identity",
    QCoreApplication::translate("main", "Location of the file storing user's identity"),
    QCoreApplication::translate("main", "file"));
  parser.addOption(identityFileOption);

  /* Or should RmAdmin connect there insecurely? We still can make use of the
   * identity file to get the username from, though. */
  QCommandLineOption insecureOption(
    QString("insecure"),
    QCoreApplication::translate("main", "Connect without encryption"));
  parser.addOption(insecureOption);

  parser.process(app);

  QString srvUrl(
    parser.positionalArguments().isEmpty() ?
      "localhost:29340" :
      parser.positionalArguments()[0]);
  if (srvUrl.length() == 0) srvUrl = QString("localhost");

  bool insecure = parser.isSet(insecureOption);

  QString defaultIdentityFileName =
    getenv("HOME") ?
      QString(getenv("HOME")) + QString("/.config/rmadmin/identity") :
      QString("/etc/rmadmin/identity");
  QFile identityFile =
    parser.isSet(identityFileOption) ?
      parser.value(identityFileOption) :
      QFile(defaultIdentityFileName);
  if (! identityFile.exists() && ! insecure) {
    std::cout
      << "File " << identityFile.fileName().toStdString()
      << " does not exist.\n"
         "Ask Ramen administrator to create a user and then to (securely) send you the "
         "identity file.\n"
         "This should be a short JSON file." << std::endl;
    exit(1);
  }
  UserIdentity *userIdentity = new UserIdentity(identityFile);
  if (! userIdentity->isValid && ! insecure) exit(1);

  my_uid = QString(getenv("USER") ? getenv("USER") : "Waldo");
  if (userIdentity->isValid) my_uid = userIdentity->username;

  qRegisterMetaType<conf::Key>();
  qRegisterMetaType<std::shared_ptr<conf::Value const>>();
  qRegisterMetaType<conf::Error>();
  qRegisterMetaType<conf::Worker>();
  qRegisterMetaType<conf::TimeRange>();
  qRegisterMetaType<conf::Retention>();
  qRegisterMetaType<QVector<int>>();

  bool with_beta_features = getenv("RMADMIN_BETA");
  /* A GraphModel satisfies both the TreeView and the GraphView
   * requirements: */
  GraphViewSettings *settings = new GraphViewSettings;
  GraphModel *graphModel = new GraphModel(settings);

  globalMenu = new Menu(graphModel, with_beta_features);
  w = new RmAdminWin(graphModel, with_beta_features);
  w->resize(QDesktopWidget().availableGeometry(w).size() * 0.7);

  std::thread sync_thread(do_sync_thread, srvUrl, userIdentity, insecure, argv);

  w->show();

  int ret = app.exec();
  quit = true;

  delete w;
  w = nullptr;
  delete graphModel;
  graphModel = nullptr;
  delete settings;
  settings = nullptr;

  std::cout << "Joining with start_sync thread..." << std::endl;
  sync_thread.join();

  return ret;
}
