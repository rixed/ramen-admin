#include "KErrorMsg.h"

#include <QDebug>
#include <QtGlobal>

#include "KVStore.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static bool const verbose{false};

KErrorMsg::KErrorMsg(QWidget *parent) : QLabel(parent) {
  connect(kvs.get(), &KVStore::keyChanged, this, &KErrorMsg::onChange);
}

void KErrorMsg::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
      case KeyChanged:
        setError(*change.key, change.kv);
        break;
      case KeyDeleted:
        // Our error key is deleted as part of server timeouting us:
        warnTimeout(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

/* Beware:
 * First, this setKey is not the one from an AtomicWidget.
 * Second, and more importantly, this can (and will) be called before the key
 * is present in kvs (as the string here is taken from the answer to the
 * Auth message)! */
void KErrorMsg::setKey(std::shared_ptr<dessser::gen::sync_key::t const> k) {
  Q_ASSERT(!key);
  if (verbose) qDebug() << "KErrorMsg: setting key to" << *k;
  key = k;
}

void KErrorMsg::displayError(QString const &str) {
  QLabel::setStyleSheet(
      str.length() == 0 ? QString() : QStringLiteral("background-color: pink"));
  QLabel::setText(str);
}

void KErrorMsg::setError(dessser::gen::sync_key::t const &k, KValue const &kv) {
  if (!key || *key != k) return;

  if (kv.val->index() != dessser::gen::sync_value::Error) {
    qCritical() << "Error value is not an error!?";
    return;
  }

  auto const err{std::get<dessser::gen::sync_value::Error>(*kv.val)};
  displayError(QString::fromStdString(std::get<2>(err)));
}

void KErrorMsg::warnTimeout(dessser::gen::sync_key::t const &k,
                            KValue const &) {
  if (!key || *key != k) return;

  displayError(tr("Server timed us out!"));
}
