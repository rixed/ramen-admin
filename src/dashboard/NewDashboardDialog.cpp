#include <QDebug>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>

#include "ConfClient.h"
#include "dashboard/tools.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "Menu.h"
#include "PathNameValidator.h"

#include "dashboard/NewDashboardDialog.h"

static bool const verbose { false };

NewDashboardDialog::NewDashboardDialog(QWidget *parent)
  : QDialog(parent)
{
  nameEdit = new QLineEdit;
  nameEdit->setPlaceholderText("Unique name");
  nameEdit->setValidator(new PathNameValidator(this));
  // TODO: Validate that the name is unique and distinct from "scratchpad"

  QDialogButtonBox *buttonBox {
    new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel) };

  connect(buttonBox, &QDialogButtonBox::accepted,
          this, &NewDashboardDialog::createDashboard);
  connect(buttonBox, &QDialogButtonBox::rejected,
          this, &QDialog::reject);

  QFormLayout *formLayout { new QFormLayout };
  formLayout->addRow(tr("Dashboard name"), nameEdit);
  QVBoxLayout *layout { new QVBoxLayout };
  layout->addLayout(formLayout);
  layout->addWidget(buttonBox);
  setLayout(layout);

  setWindowTitle(tr("Create New Dashboard"));
  setModal(true);
}

void NewDashboardDialog::createDashboard()
{
  if (verbose)
    qDebug() << "NewDashboardDialog: creating new dashboard...";

  /* Originally the dashboard is created with a single text widget with
   * the name, as a placeholder, since empty dashboards are invalid (not
   * stored in the configuration). */
  std::string const dash_name { nameEdit->text().toStdString() };
  Q_ASSERT(dash_name != SCRATCHPAD); // FIXME

  std::string const placeholder {
    tr("Sample text widget where you could enter a description for this widget.")
      .toStdString() };

  std::shared_ptr<dessser::gen::sync_value::t const> val {
    std::make_shared<dessser::gen::sync_value::t const>(
      std::in_place_index<dessser::gen::sync_value::DashboardWidget>,
      std::make_shared<dessser::gen::dashboard_widget::t>(
        std::in_place_index<dessser::gen::dashboard_widget::Text>,
        placeholder)) };

  std::shared_ptr<dessser::gen::sync_key::t> key {
    dashboardNextWidget(dash_name) };

  Menu::getClient()->sendNew(key, val);

  clear();
  QDialog::accept();

  if (verbose)
    qDebug() << "NewDashboardDialog: opening new dashboard...";

  Menu::openDashboard(dash_name);
}

void NewDashboardDialog::clear()
{
  nameEdit->clear();
}
