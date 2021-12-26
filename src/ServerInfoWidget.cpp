// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ServerInfoWidget.h"

#include <QDebug>
#include <QFormLayout>
#include <QLabel>
#include <QtGlobal>

#include "KVStore.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"

static bool const verbose(false);

ServerInfoWidget::ServerInfoWidget(QString const &srvUrl, QWidget *parent)
    : QWidget(parent) {
  layout = new QFormLayout;

  layout->addRow(new QLabel(tr("Configuration Server:")), new QLabel(srvUrl));

  setLayout(layout);

  connect(kvs.get(), &KVStore::keyChanged, this, &ServerInfoWidget::onChange);
}

void ServerInfoWidget::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
        setKey(*change.key, change.kv);
        break;
      case KeyChanged:
        setKey(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void ServerInfoWidget::setKey(dessser::gen::sync_key::t const &key,
                              KValue const &kv) {
  if (key.index() == dessser::gen::sync_key::Time) {
    setLabel(QString("Time"), kv.val);
  } else if (key.index() == dessser::gen::sync_key::Versions) {
    std::string const what{std::get<dessser::gen::sync_key::Versions>(key)};
    setLabel(QString::fromStdString(what), kv.val);
  }
}

void ServerInfoWidget::setLabel(
    QString const &label,
    std::shared_ptr<dessser::gen::sync_value::t const> value) {
  if (value->index() != dessser::gen::sync_value::RamenValue) {
  err:
    qCritical() << "ServerInfoWidget::setLabel: value is not a string?!";
    return;
  }
  std::shared_ptr<dessser::gen::raql_value::t const> val{
      std::get<dessser::gen::sync_value::RamenValue>(*value)};

  QString str;

  switch (val->index()) {
    case dessser::gen::raql_value::VString:
      str = QString::fromStdString(
          std::get<dessser::gen::raql_value::VString>(*val));
      break;
    case dessser::gen::raql_value::VFloat:
      str = stringOfDate(std::get<dessser::gen::raql_value::VFloat>(*val));
      break;
    default:
      goto err;
  }

  for (int row = 0; row < layout->rowCount(); row++) {
    QLabel const *l = dynamic_cast<QLabel const *>(
        layout->itemAt(row, QFormLayout::LabelRole)->widget());
    if (l) {
      if (l->text() != label) continue;

      QLabel *v = dynamic_cast<QLabel *>(
          layout->itemAt(row, QFormLayout::FieldRole)->widget());
      if (v) {
        v->setText(str);
      } else {
        qCritical() << "ServerInfoWidget has a value that's not a label!?";
      }
      return;
    } else {
      qCritical() << "ServerInfoWidget has a label that's not a label!?";
    }
  }

  // Create a new label:
  if (verbose)
    qDebug() << "ServerInfoWidget:: Creating new server info label for"
             << label;

  layout->addRow(new QLabel(label), new QLabel(str));
}
