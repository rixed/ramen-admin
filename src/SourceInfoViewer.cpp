#include <QtGlobal>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QTabWidget>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/raql_type.h"
#include "desssergen/retention.h"
#include "MakeSyncValue.h"
#include "misc.h"
#include "misc_dessser.h"

#include "SourceInfoViewer.h"

SourceInfoViewer::SourceInfoViewer(QWidget *parent) :
  AtomicWidget(parent)
{
  layout = new QVBoxLayout;
  QWidget *contents = new QWidget;
  contents->setObjectName("infoViewerContents");
  contents->setLayout(layout);
  contents->setMinimumHeight(400);
  relayoutWidget(contents);
}

static QString const QStringOfRetention(dessser::gen::retention::t const &r)
{
  return
    QString("for ") +
    raqlExprToQString(*r.duration) +
    QString(", every ") +
    stringOfDuration(r.period);
}

bool SourceInfoViewer::setValue(
  std::optional<dessser::gen::sync_key::t const> const &,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  /* Empty the previous params/parents layouts: */
  /* FIXME: rather instanciate the widgets only once and hide those unused */
  emptyLayout(layout);

  if (v->index() == dessser::gen::sync_value::SourceInfo) {
    dessser::gen::source_info::t *info {
      std::get<dessser::gen::sync_value::SourceInfo>(*v) };

    if (info->detail.index() == dessser::gen::source_info::Failed) {
      auto const &failed {
        std::get<dessser::gen::source_info::Failed>(info->detail) };
      QLabel *l { new QLabel(QString::fromStdString(failed.err_msg)) };
      l->setWordWrap(true);
      l->setAlignment(Qt::AlignCenter);
      layout->addWidget(l);
    } else {
      Q_ASSERT(info->detail.index() == dessser::gen::source_info::Compiled);
      dessser::gen::source_info::compiled_program *compiled {
        std::get<dessser::gen::source_info::Compiled>(info->detail) };

      layout->addWidget(new QLabel("<b>" + tr("Parameters") + "</b>"));

      if (compiled->default_params.size() == 0) {
        QLabel *none { new QLabel("<i>" + tr("none") + "</i>") };
        none->setAlignment(Qt::AlignCenter);
        layout->addWidget(none);
      } else {
        QFormLayout *paramsLayout = new QFormLayout;
        for (auto p : compiled->default_params) {
          QLabel *l { new QLabel(raqlValToQString(*p->value)) };
          l->setWordWrap(true);
          paramsLayout->addRow(QString::fromStdString(p->ptyp->name) + ":", l);
          if (p->ptyp->doc.size() > 0) {
            QLabel *doc { new QLabel(QString::fromStdString(p->ptyp->doc)) };
            doc->setWordWrap(true);
            paramsLayout->addRow(doc);
          }
        }
        layout->addLayout(paramsLayout);
      }

      QTabWidget *functions { new QTabWidget };
      for (dessser::gen::source_info::compiled_func *func : compiled->funcs) {
        QVBoxLayout *l { new QVBoxLayout };
        QWidget *w { new QWidget };
        w->setLayout(l);
        QString title {
          QString(QString::fromStdString(func->name) +
                  (func->is_lazy ? " (lazy)" : "")) };
        functions->addTab(w, title);
        if (func->doc.length() > 0) {
          QLabel *doc = new QLabel(QString::fromStdString(func->doc));
          doc->setWordWrap(true);
          l->addWidget(doc);
        }
        QLabel *retention { new QLabel(
          tr("Retention: ") +
          (func->retention ?
            QStringOfRetention(**func->retention) :
            "<i>" + tr("none") + "</i>")) };
        l->addWidget(retention);

        l->addWidget(new QLabel(tr("Output Type:")));
        // One line per "column" of the outType:
        QTableWidget *columns { new QTableWidget };
        l->addWidget(columns);
        columns->setColumnCount(3);
        columns->setHorizontalHeaderLabels({ "Name", "Type", "Low Card." });
        columns->setEditTriggers(QAbstractItemView::NoEditTriggers);
        columns->verticalHeader()->setVisible(false);
        unsigned num_cols { numColumns(*func->out_record) };
        columns->setRowCount(num_cols);

        for (unsigned c = 0; c < num_cols; c ++) {
          std::string const name { columnName(*func->out_record, c) };
          bool isFactor { false };
          for (std::string const &factor : func->factors) {
            if (factor == name) {
              isFactor = true;
              break;
            }
          }

          dessser::gen::raql_type::t const *subtype {
            columnType(*func->out_record, c) };
          columns->setItem(c, 0, new QTableWidgetItem(QString::fromStdString(name)));
          columns->setItem(c, 1, new QTableWidgetItem(
            subtype ?
              raqlTypeToQString(*subtype) :
              raqlTypeToQString(*func->out_record)));
          columns->setItem(c, 2, new QTableWidgetItem(isFactor ? "✓":""));
        }
        columns->resizeColumnsToContents();

        QLabel *sign {
          new QLabel(
            tr("Signature: %1").arg(QString::fromStdString(func->signature))) };
        l->addWidget(sign);
      }
      layout->addWidget(new QLabel("<b>" + tr("Functions") + "</b>"));
      layout->addWidget(functions);
    }
    layout->addSpacing(10);
    QString md5s { QString("For sources which MD5 are ") };
    for (auto s : info->md5s) md5s += ", " + QString::fromStdString(s);
    QLabel *md5 { new QLabel(md5s) };
    md5->setWordWrap(true);
    layout->addWidget(md5);
    return true;
  } else {
    qCritical() << "Not a SourceInfo value?!";
    return false;
  }
}
