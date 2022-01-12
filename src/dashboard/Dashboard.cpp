// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "dashboard/Dashboard.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QMargins>
#include <QScrollArea>
#include <QSplitter>
#include <QVBoxLayout>
#include <memory>

#include "ConfClient.h"
#include "FunctionItem.h"
#include "FunctionSelector.h"
#include "GraphModel.h"
#include "Menu.h"
#include "TimeRange.h"
#include "TimeRangeEdit.h"
#include "dashboard/DashboardWidgetForm.h"
#include "dashboard/tools.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"
#include "timeline/TimeLineGroup.h"

static bool const verbose{false};

Dashboard::Dashboard(std::string const &dash_name, QWidget *parent)
    : QWidget(parent), name(dash_name) {
  timeLineGroup = new TimeLineGroup(this);

  // TODO: globalGraphModelWithoutTopHalves, cf chart/TimeChartFunctionsEditor
  GraphModel *graph{GraphModel::globalGraphModel};
  functionSelector = new FunctionSelector(graph);
  QPushButton *addButton{new QPushButton(tr("Add"))};
  connect(addButton, &QPushButton::clicked, this,
          &Dashboard::addCurrentFunction);

  timeRangeEdit = new TimeRangeEdit;

  placeHolder = new QLabel(tr("This dashboard is empty"));
  placeHolder->setObjectName("placeHolder");
  splitter = new QSplitter(Qt::Vertical);

  QScrollArea *scrollArea{new QScrollArea(this)};
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scrollArea->setWidgetResizable(true);
  scrollArea->setWidget(splitter);

  QHBoxLayout *bottomBar{new QHBoxLayout};
  bottomBar->setObjectName("bottomBar");
  bottomBar->addWidget(functionSelector);
  bottomBar->addWidget(addButton);
  bottomBar->addStretch();
  bottomBar->addWidget(timeRangeEdit);

  QVBoxLayout *vboxLayout{new QVBoxLayout};
  vboxLayout->setContentsMargins(0, 0, 0, 0);
  vboxLayout->setContentsMargins(QMargins());
  vboxLayout->addWidget(placeHolder);
  vboxLayout->addWidget(scrollArea);
  vboxLayout->addLayout(bottomBar);

  setLayout(vboxLayout);

  connect(kvs.get(), &KVStore::keyChanged, this, &Dashboard::onChange);

  iterDashboardWidgets(
      name, [this](std::shared_ptr<dessser::gen::sync_key::t const> key,
                   KValue const &) { addWidget(key); });
}

void Dashboard::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
        addValue(change.key, change.kv);
        break;
      case KeyDeleted:
        delValue(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void Dashboard::addWidget(
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  std::optional<uint32_t> idx{widgetIndexOfKey(*key)};
  if (!idx) {
    qCritical() << "Invalid key, not a widget:" << *key;
    return;
  }

  if (verbose) qDebug() << "Dashboard: addWidget" << *key << "at index" << *idx;

  DashboardWidgetForm *widgetForm{new DashboardWidgetForm(key, this, this)};

  /* Add the new widget at the proper position in the layout: */
  int splitterIdx{0};
  for (std::list<WidgetRef>::iterator it = widgets.begin(); it != widgets.end();
       it++, splitterIdx++) {
    if (it->idx == *idx) {
      if (verbose) qDebug() << "Dashboard: replacing widget" << *idx;
      it->widget->deleteLater();  // also removes from the splitter
      it->widget = widgetForm;
      goto added;
    } else if (it->idx > *idx) {
      widgets.emplace(it, *idx, widgetForm);
      goto added;
    }
  }
  // fallback: add it at the end
  widgets.emplace_back(*idx, widgetForm);
added:
  splitter->insertWidget(splitterIdx, widgetForm);

  placeHolder->setVisible(widgets.empty());
}

void Dashboard::resetArrows() {
  // Reset up/down arrows in menus:
  size_t const numWidgets(widgets.size());
  size_t i(0);
  for (std::list<WidgetRef>::iterator it = widgets.begin(); it != widgets.end();
       i++, it++)
    it->widget->enableArrowsForPosition(i, numWidgets);
}

bool Dashboard::isMyKey(dessser::gen::sync_key::t const &key) {
  return isDashboardKey(key) && name == dashboardNameOfKey(key);
}

void Dashboard::addValue(std::shared_ptr<dessser::gen::sync_key::t const> key,
                         KValue const &) {
  if (!isMyKey(*key)) return;

  if (verbose) qDebug() << "Dashboard::addValue for key" << *key;

  std::optional<uint32_t> idx{widgetIndexOfKey(*key)};
  if (!idx) return;
  addWidget(key);
  resetArrows();
}

void Dashboard::delWidget(uint32_t idx) {
  for (std::list<WidgetRef>::iterator it = widgets.begin(); it != widgets.end();
       it++) {
    if (it->idx == idx) {
      if (verbose) qDebug() << "Dashboard: Removing widget" << idx;
      it->widget->deleteLater();
      widgets.erase(it);
      break;
    } else if (it->idx > idx) {
      qWarning() << "Unknown deleted widget index" << idx;
      break;
    }
  }

  resetArrows();
  placeHolder->setVisible(widgets.empty());
}

void Dashboard::delValue(std::shared_ptr<dessser::gen::sync_key::t const> key,
                         KValue const &) {
  if (!isMyKey(*key)) return;

  if (verbose) qDebug() << "Dashboard: removing widget" << *key;

  std::optional<uint32_t> idx{widgetIndexOfKey(*key)};
  if (!idx) {
    qCritical() << "Dashboard::delValue: Cannot find index of widget" << *key;
    return;
  }

  delWidget(*idx);
}

void Dashboard::addCurrentFunction() {
  FunctionItem *f{functionSelector->getCurrent()};
  if (!f) {
    qDebug() << "Must select a function";
    return;
  }

  std::shared_ptr<Function> function{
      std::dynamic_pointer_cast<Function>(f->shared)};
  if (!function) {
    qWarning() << "No such function";
    return;
  }

  std::shared_ptr<dessser::gen::sync_value::t> chart{newDashboardChart(
      function->siteName, function->programName, function->name.toStdString())};

  std::shared_ptr<dessser::gen::sync_key::t> const key{
      dashboardNextWidget(name)};

  Menu::getClient()->sendNew(key, chart, DEFAULT_LOCK_TIMEOUT);
}
