#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QSizePolicy>
#include <QVBoxLayout>

#include "AtomicWidget.h"
#include "dashboard/DashboardCopyDialog.h"
#include "dashboard/DashboardSelector.h"
#include "dashboard/DashboardWidget.h"
#include "dashboard/tools.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "ConfClient.h"
#include "Menu.h"
#include "misc_dessser.h"
#include "Resources.h"

#include "dashboard/DashboardWidgetForm.h"

static bool const verbose { false };

DashboardWidgetForm::DashboardWidgetForm(
  std::shared_ptr<dessser::gen::sync_key::t const> widgetKey_,
  Dashboard *dashboard_,
  QWidget *parent)
  : AtomicForm(false, parent),
    widgetKey(widgetKey_),
    dashboard(dashboard_)
{
  /* Beware that `new DashboardWidget()` will call back setExpand, so
   * create the menuFrame sooner: */
  menuFrame = new QWidget(this);
  menuFrame->setObjectName("menuFrame");

  widget = new DashboardWidget(dashboard, this, this);
  widget->setObjectName("GenericDashboardWidget");

  QMenuBar *menuBar { new QMenuBar };
  menuBar->addAction(tr("export"));
  QMenu *moveMenu { menuBar->addMenu(tr("move")) };
  moveMenu->addSection(tr("Within this dashboard"));

  Resources const *r { Resources::get() };

  upAction = moveMenu->addAction(r->upPixmap, tr("Up"),
                                 this, &DashboardWidgetForm::moveUp);
  downAction = moveMenu->addAction(r->downPixmap, tr("Down"),
                                   this, &DashboardWidgetForm::moveDown);
  moveMenu->addSection(tr("To another dashboard"));
  moveMenu->addAction(r->copyPixmap, tr("Copy to…"),
                      this, &DashboardWidgetForm::performCopy);
  moveMenu->addAction(tr("Move to…"),
                      this, &DashboardWidgetForm::performMove);

  title = new QLabel;
  title->setObjectName("title");

  QHBoxLayout *titleBar { new QHBoxLayout };
  titleBar->setObjectName("titleBar");
  titleBar->addWidget(menuBar);
  titleBar->addStretch();
  titleBar->addWidget(title);
  titleBar->addStretch();
  titleBar->addWidget(editButton);

  connect(widget, &DashboardWidget::titleChanged,
          this, &DashboardWidgetForm::setTitle);
  /* Now that everything is connected, set the key (which will set the
   * value) */
  widget->setKey(widgetKey);
  widget->setValueFromStore();
  /* And add it to the form that will then get the initial value: */
  addWidget(widget, true);

  /* Or the top-left corner button will float away if the menubar expands
   * vertically, for some unfathomable reason: */
  menuBar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);

  layout = new QVBoxLayout;
  layout->setSpacing(0);
  layout->setContentsMargins(QMargins());
  layout->addLayout(titleBar, 0);
  layout->addWidget(widget, 1);
  menuFrame->setLayout(layout);
  setCentralWidget(menuFrame);

  // Prepare the copy destination window:
  /* FIXME: as this is an application-modal dialog we could have only one for
   * the whole app. */
  copyDialog = new DashboardCopyDialog(this);
}

DashboardWidgetForm::~DashboardWidgetForm()
{
  if (verbose)
    qDebug() << "DashboardWidgetForm: destructing" << this
             << "while parent of widget" << widget;
  /* Due to what looks like a Qt bug, the destruct signal would be sent to
   * this AtomicForm when widget, its only child, is going to be deleted,
   * crashing the app. So let's cautiously defuse that bomb here: */
  // TODO: a minimal app exhibiting that behavior
  widget->disconnect(this);
}

void DashboardWidgetForm::enableArrowsForPosition(size_t idx, size_t count)
{
  upAction->setEnabled(idx > 0);
  downAction->setEnabled(idx < count - 1);
}

void DashboardWidgetForm::setExpand(bool expand)
{
  QSizePolicy p {
    QSizePolicy::Preferred,
    (expand ? QSizePolicy::Expanding : QSizePolicy::Maximum) };
  p.setVerticalStretch(expand ? 1 : 0);
  setSizePolicy(p);
  menuFrame->setSizePolicy(p);
}

void DashboardWidgetForm::doCopy(bool andDelete)
{
  if (QDialog::Accepted == copyDialog->copy(!andDelete)) {
    std::string const dash_name { copyDialog->dashSelector->getCurrent() };
    std::shared_ptr<dessser::gen::sync_key::t> dest_key {
      dashboardNextWidget(dash_name) };

    if (verbose)
      qDebug() << "DashboardWidgetForm: Will copy to" << *dest_key;

    std::shared_ptr<dessser::gen::sync_value::t const> v { widget->getValue() };

    /* FIXME: wait for the new widget to be created. And to be sure that's
     * ours, lock and unlock the destination dashboard around these
     * operations, which implies to perform all this asynchronously. */
    Menu::getClient()->sendNew(dest_key, v);
    if (andDelete) Menu::getClient()->sendDel(widgetKey);
  }
}

void DashboardWidgetForm::performCopy()
{
  doCopy(false);
}

void DashboardWidgetForm::performMove()
{
  doCopy(true);
}

void DashboardWidgetForm::moveUp()
{
  /* Locate which other widget to switch position with: */
  std::optional<uint32_t> const my_idx { widgetIndexOfKey(*widgetKey) };
  if (! my_idx) {
    qCritical() << "Cannot find out widget index from" << *widgetKey;
    return;
  }

  // TODO: lock the whole dashboard first:
  std::shared_ptr<dessser::gen::sync_key::t const> destKey;
  KValue destVal;
  std::string const dash_name { dashboardNameOfKey(*widgetKey) };
  iterDashboardWidgets(dash_name,
    [my_idx, &destKey, &destVal](std::shared_ptr<dessser::gen::sync_key::t const> key,
                                KValue const &val)
    {
      std::optional<uint32_t> const that_idx { widgetIndexOfKey(*key) };
      if (that_idx && *that_idx < *my_idx) {
        destKey = key;
        destVal = val;
      }
    });

  switchPosition(destKey, destVal);
}

void DashboardWidgetForm::moveDown()
{
  /* Locate which other widget to switch position with: */
  std::optional<uint32_t> const my_idx { widgetIndexOfKey(*widgetKey) };
  if (! my_idx) {
    qCritical() << "Cannot find out widget index from" << *widgetKey;
    return;
  }

  // TODO: lock the whole dashboard first:
  std::shared_ptr<dessser::gen::sync_key::t const> destKey;
  KValue destVal;
  std::string const dash_name { dashboardNameOfKey(*widgetKey) };
  iterDashboardWidgets(dash_name,
    [my_idx, &destKey, &destVal](std::shared_ptr<dessser::gen::sync_key::t const> key,
                                 KValue const &val)
    {
      std::optional<uint32_t> const that_idx { widgetIndexOfKey(*key) };
      if (!destKey && that_idx && *that_idx > *my_idx) {
        destKey = key;
        destVal = val;
      }
    });

  switchPosition(destKey, destVal);
}

void DashboardWidgetForm::switchPosition(
  std::shared_ptr<dessser::gen::sync_key::t const> destKey, KValue const &destVal)
{
  if (! destKey) {
    qCritical() << "No widget to switch position with" << *widgetKey;
    return;
  }

  Menu::getClient()->sendSet(destKey, widget->getValue());
  Menu::getClient()->sendSet(widgetKey, destVal.val);
}

void DashboardWidgetForm::setTitle(QString const &s)
{
  if (verbose)
    qDebug() << "Setting new title:" << s;
  title->setText(s);
}
