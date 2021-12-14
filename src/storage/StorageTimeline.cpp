#include <string>
#include <QCompleter>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

#include "timeline/TimeLineView.h"
#include "ConfClient.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/replay.h"
#include "desssergen/replay_request.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "FunctionItem.h"
#include "FunctionSelector.h"
#include "GraphModel.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc_dessser.h"
#include "ReplayRequest.h"
#include "Resources.h"
#include "TimeRange.h"
#include "TimeRangeEdit.h"

#include "storage/StorageTimeline.h"

static bool const verbose { false };

StorageTimeline::StorageTimeline(
  GraphModel *graphModel,
  QWidget *parent)
  : QWidget(parent),
    respKey(nullptr)
{
  QVBoxLayout *layout { new QVBoxLayout };

  /*
   * The TimeLineView in a QScrollArea:
   */

  QScrollArea *scrollArea { new QScrollArea };
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  scrollArea->setWidgetResizable(true);

  // Required for the scrollarea to behave properly, for some reason:
  QWidget *widget { new QWidget };
  QVBoxLayout *l1 { new QVBoxLayout };
  widget->setLayout(l1);

  timeLineView = new TimeLineView(graphModel);
  l1->addWidget(timeLineView);
  l1->setSizeConstraint(QLayout::SetMinimumSize);

  scrollArea->setWidget(widget);  // Must be added last for some reason

  layout->addWidget(scrollArea);

  /*
   * Explain: a "combo" to select the target, a time picker and a button
   */

  explainTarget = new FunctionSelector(graphModel);
  explainTarget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
  explainTimeRange = new TimeRangeEdit;
  explainButton = new QPushButton(tr("&Explain"));
  // Disable that button until a function is selected:
  explainButton->setEnabled(false);
  explainReset = new QPushButton;
  QIcon closeIcon { resources->get()->closePixmap };
  explainReset->setIcon(closeIcon);
  explainReset->setEnabled(false);

  QHBoxLayout *l2 { new QHBoxLayout };
  l2->addWidget(explainTarget);
  l2->addWidget(explainTimeRange);
  l2->addWidget(explainButton);
  l2->addWidget(explainReset);

  layout->addLayout(l2);

  setLayout(layout);

  /*
   * Connections
   */

  /* Changing the selected function enable/disable the explainButton: */
  connect(explainTarget, &FunctionSelector::selectionChanged,
          this, &StorageTimeline::enableExplainButton);

  /* explainButton triggers the query: */
  connect(explainButton, &QPushButton::clicked,
          this, &StorageTimeline::requestQueryPlan);

  /* explainReset removes the highlights: */
  connect(explainReset, &QPushButton::clicked,
          this, &StorageTimeline::resetQueryPlan);

  /* Get the query answer: */
  connect(kvs.get(), &KVStore::keyChanged,
          this, &StorageTimeline::onChange);
}

void StorageTimeline::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyCreated:
      case KeyChanged:
        receiveExplain(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void StorageTimeline::enableExplainButton(FunctionItem *functionItem)
{
  explainButton->setEnabled(functionItem != nullptr);
}

void StorageTimeline::requestQueryPlan()
{
  ConfClient *client { Menu::getClient() };

  if (! respKey) {
    if (! client->syncSocket) {
      qCritical() << "Cannot request a query plan before socket is known!";
      return;
    }

    respKey =
      std::make_shared<dessser::gen::sync_key::t const>(
        std::in_place_index<dessser::gen::sync_key::PerClient>,
        std::const_pointer_cast<dessser::gen::sync_socket::t>(client->syncSocket),
        std::make_shared<dessser::gen::sync_key::per_client>(
          std::in_place_index<dessser::gen::sync_key::Response>,
          respKeyPrefix + "explain"));
  }

  FunctionItem *functionItem { explainTarget->getCurrent() };
  if (! functionItem) return;

  std::shared_ptr<Function> function {
    std::static_pointer_cast<Function>(functionItem->shared) };

  std::string functionName(function->name.toStdString());
  std::string programName(function->programName);
  std::string siteName(function->siteName);

  double since, until;
  explainTimeRange->range.absRange(&since, &until);

  std::shared_ptr<dessser::gen::sync_key::t const> key {
    std::make_shared<dessser::gen::sync_key::t const>(
      std::in_place_index<dessser::gen::sync_key::ReplayRequests>,
      dessser::VOID) };

  std::shared_ptr<dessser::gen::sync_value::t const> req {
    makeReplayRequest(siteName, programName, functionName, since, until, respKey, true) };

  if (verbose)
    qDebug() << "StorageTimeline: request QueryPlan for target"
             << functionItem->fqName() << "and response key" << *respKey;

  client->sendSet(key, req);
}

void StorageTimeline::resetQueryPlan()
{
  timeLineView->resetHighlights();
  explainReset->setEnabled(false);
}

void StorageTimeline::receiveExplain(
  std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &kv)
{
  if (*key != *respKey) return;

  if (kv.val->index() != dessser::gen::sync_value::Replay) {
    qCritical() << "StorageTimeline: explain answer is not a Replay?!";
    return;
  }

  std::shared_ptr<dessser::gen::replay::t const> replay {
    std::get<dessser::gen::sync_value::Replay>(*kv.val) };

  if (verbose)
    qDebug() << "StorageTimeline: received a query plan:" << *replay;

  timeLineView->resetHighlights();

  QPair<qreal, qreal> range { replay->since, replay->until };

  for (std::shared_ptr<dessser::gen::fq_function_name::t> const &source : replay->sources) {
    QString const label {
      QString::fromStdString(source->site + ":" + source->program + "/" + source->function) };
    timeLineView->highlightRange(label, range);
  }

  explainReset->setEnabled(true);
}
