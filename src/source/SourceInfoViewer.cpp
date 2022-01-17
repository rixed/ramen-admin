// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "source/SourceInfoViewer.h"

#include <QDebug>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QStackedLayout>
#include <QTabWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QtGlobal>

#include "MakeSyncValue.h"
#include "desssergen/raql_type.h"
#include "desssergen/retention.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"

SourceInfoViewer::SourceInfoViewer(QWidget *parent) : AtomicWidget(parent) {
  stackedLayout = new QStackedLayout;

  QWidget *readOnlyWidget{new QWidget};
  readOnlyWidget->setObjectName("infoViewerContents");
  readOnlyLayout = new QVBoxLayout;
  readOnlyWidget->setLayout(readOnlyLayout);
  readOnlyWidget->setMinimumHeight(400);
  readOnlyIndex = stackedLayout->addWidget(readOnlyWidget);

  QLabel *readWriteError{
      new QLabel(tr("Object informations can not be edited"))};
  readWriteError->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  readWriteIndex = stackedLayout->addWidget(readWriteError);

  QWidget *contents{new QWidget};
  contents->setLayout(stackedLayout);
  relayoutWidget(contents);
}

void SourceInfoViewer::setEnabled(bool enabled) {
  stackedLayout->setCurrentIndex(enabled ? readWriteIndex : readOnlyIndex);
}

static QString const QStringOfRetention(dessser::gen::retention::t const &r) {
  return QString("for ") + raqlExprToQString(*r.duration) +
         QString(", every ") + stringOfDuration(r.period);
}

bool SourceInfoViewer::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  /* Empty the previous params/parents layouts: */
  /* FIXME: rather instanciate the widgets only once and hide those unused */
  emptyLayout(readOnlyLayout);

  if (v->index() == dessser::gen::sync_value::SourceInfo) {
    std::shared_ptr<dessser::gen::source_info::t> info{
        std::get<dessser::gen::sync_value::SourceInfo>(*v)};

    if (info->detail.index() == dessser::gen::source_info::Failed) {
      auto const &failed{
          std::get<dessser::gen::source_info::Failed>(info->detail)};
      QLabel *l{new QLabel(QString::fromStdString(failed.err_msg))};
      l->setWordWrap(true);
      l->setAlignment(Qt::AlignCenter);
      readOnlyLayout->addWidget(l);
    } else {
      Q_ASSERT(info->detail.index() == dessser::gen::source_info::Compiled);
      std::shared_ptr<dessser::gen::source_info::compiled_program> compiled{
          std::get<dessser::gen::source_info::Compiled>(info->detail)};

      readOnlyLayout->addWidget(new QLabel("<b>" + tr("Parameters") + "</b>"));

      if (compiled->default_params.size() == 0) {
        QLabel *none{new QLabel("<i>" + tr("none") + "</i>")};
        none->setAlignment(Qt::AlignCenter);
        readOnlyLayout->addWidget(none);
      } else {
        QFormLayout *paramsLayout{new QFormLayout};
        for (std::shared_ptr<dessser::gen::program_parameter::t> const &p :
             compiled->default_params) {
          QLabel *l{new QLabel(raqlValToQString(*p->value))};
          l->setWordWrap(true);
          paramsLayout->addRow(QString::fromStdString(p->name) + ":", l);
          if (p->doc.size() > 0) {
            QLabel *doc{new QLabel(QString::fromStdString(p->doc))};
            doc->setWordWrap(true);
            paramsLayout->addRow(doc);
          }
        }
        readOnlyLayout->addLayout(paramsLayout);
      }

      QTabWidget *functions{new QTabWidget};
      for (std::shared_ptr<dessser::gen::source_info::compiled_func> const
               &func : compiled->funcs) {
        QVBoxLayout *l{new QVBoxLayout};
        QWidget *w{new QWidget};
        w->setLayout(l);
        QString title{QString(QString::fromStdString(func->name) +
                              (func->is_lazy ? " (lazy)" : ""))};
        functions->addTab(w, title);
        if (func->doc.length() > 0) {
          QLabel *doc{new QLabel(QString::fromStdString(func->doc))};
          doc->setWordWrap(true);
          l->addWidget(doc);
        }
        QLabel *retention{new QLabel(
            tr("Retention: %1")
                .arg(func->retention ? QStringOfRetention(**func->retention)
                                     : "<i>" + tr("none") + "</i>"))};
        retention->setWordWrap(true);
        l->addWidget(retention);

        l->addWidget(new QLabel(tr("Output Type:")));
        // One line per "column" of the outType:
        QTableWidget *columns{new QTableWidget};
        l->addWidget(columns);
        columns->setColumnCount(3);
        columns->setHorizontalHeaderLabels({"Name", "Type", "Low Card."});
        columns->setEditTriggers(QAbstractItemView::NoEditTriggers);
        columns->verticalHeader()->setVisible(false);
        unsigned num_cols{numColumns(*func->out_record)};
        columns->setRowCount(num_cols);

        for (unsigned c = 0; c < num_cols; c++) {
          std::string const name{columnName(*func->out_record, c)};
          bool isFactor{false};
          for (std::string const &factor : func->factors) {
            if (factor == name) {
              isFactor = true;
              break;
            }
          }

          std::shared_ptr<dessser::gen::raql_type::t const> subtype{
              columnType(*func->out_record, c)};
          columns->setItem(c, 0,
                           new QTableWidgetItem(QString::fromStdString(name)));
          columns->setItem(c, 1,
                           new QTableWidgetItem(
                               subtype ? raqlTypeToQString(*subtype)
                                       : raqlTypeToQString(*func->out_record)));
          columns->setItem(c, 2, new QTableWidgetItem(isFactor ? "✓" : ""));
        }
        columns->resizeColumnsToContents();

        QLabel *sign{new QLabel(
            tr("Signature: %1").arg(QString::fromStdString(func->signature)))};
        sign->setWordWrap(true);
        l->addWidget(sign);
      }
      readOnlyLayout->addWidget(new QLabel("<b>" + tr("Functions") + "</b>"));
      readOnlyLayout->addWidget(functions);
    }
    readOnlyLayout->addSpacing(10);
    QStringList md5s;
    for (auto const &s : info->md5s) md5s.append(QString::fromStdString(s));
    QString md5s_label{
        QString(tr(md5s.length() > 1 ? "For sources which MD5s are: %1"
                                     : "For source which MD5 is: %1")
                    .arg(md5s.join(", ")))};
    QLabel *md5{new QLabel(md5s_label)};
    md5->setWordWrap(true);
    readOnlyLayout->addWidget(md5);
    // TODO: emit valueChanged?
    return true;
  } else {
    qCritical() << "Not a SourceInfo value?!";
    return false;
  }
}
