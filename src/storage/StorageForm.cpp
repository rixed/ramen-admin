#include <memory>
#include <QFormLayout>
#include <QWidget>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "PosIntValidator.h"
#include "PosDoubleValidator.h"
#include "KFloatEditor.h"
#include "KIntEditor.h"

#include "storage/StorageForm.h"

StorageForm::StorageForm(QWidget *parent) :
  AtomicForm(parent)
{
  QWidget *cw { new QWidget(this) };

  /* Define 2 input lines, for total size and recall cost: */

  static std::shared_ptr<dessser::gen::sync_key::t const> totalSizeKey {
    std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::Storage>,
      std::in_place_index<dessser::gen::sync_key::TotalSize>,
      dessser::VOID) };
  KIntEditor *totalSizeEdit { new KIntEditor(u64OfQString, cw) };
  totalSizeEdit->setKey(totalSizeKey);
  totalSizeEdit->setPlaceholderText(tr("Size in bytes"));

  static std::shared_ptr<dessser::gen::sync_key::t const> recallCostKey {
    std::make_shared<dessser::gen::sync_key::t>(
      std::in_place_index<dessser::gen::sync_key::Storage>,
      std::in_place_index<dessser::gen::sync_key::RecallCost>,
      dessser::VOID) };
  KFloatEditor *recallCostEdit { new KFloatEditor(cw, 0., 1.) };
  recallCostEdit->setKey(recallCostKey);
  recallCostEdit->setPlaceholderText(tr("Cost of reading vs. computing"));

  QFormLayout *formLayout { new QFormLayout };
  formLayout->addRow(tr("&Total Size:"), totalSizeEdit);
  formLayout->addRow(tr("&Recall Cost:"), recallCostEdit);
  cw->setLayout(formLayout);

  setCentralWidget(cw);
  addWidget(totalSizeEdit);
  addWidget(recallCostEdit);
}
