// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "TimeChartAxisEditor.h"

#include <QButtonGroup>
#include <QCheckBox>
#include <QDebug>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QRadioButton>

#include "desssergen/dashboard_widget.h"

TimeChartAxisEditor::TimeChartAxisEditor(QWidget *parent) : QWidget(parent) {
  left = new QRadioButton(tr("Left"));
  right = new QRadioButton(tr("Right"));
  QButtonGroup *side = new QButtonGroup;
  side->addButton(left);
  side->addButton(right);
  left->setChecked(true);

  forceZero = new QCheckBox("Force Zero");

  linear = new QRadioButton(tr("Linear"));
  logarithmic = new QRadioButton(tr("Logarithmic"));
  QButtonGroup *linLog{new QButtonGroup};
  linLog->addButton(linear);
  linLog->addButton(logarithmic);
  linear->setChecked(true);

  connect(side, QOverload<int>::of(&QButtonGroup::idClicked), this,
          [this](int) { emit valueChanged(); });
  connect(forceZero, &QCheckBox::stateChanged, this,
          &TimeChartAxisEditor::valueChanged);
  connect(linLog, QOverload<int>::of(&QButtonGroup::idClicked), this,
          [this](int) { emit valueChanged(); });

  QHBoxLayout *sideLayout = new QHBoxLayout;
  sideLayout->addWidget(left);
  sideLayout->addWidget(right);

  QHBoxLayout *scaleLayout = new QHBoxLayout;
  scaleLayout->addWidget(linear);
  scaleLayout->addWidget(logarithmic);

  QFormLayout *form = new QFormLayout;
  form->addRow(tr("Side"), sideLayout);
  form->addRow(tr("Force Zero"), forceZero);
  form->addRow(tr("Scale"), scaleLayout);

  setLayout(form);
}

bool TimeChartAxisEditor::setValue(
    dessser::gen::dashboard_widget::axis const &a) {
  if (a.left != left->isChecked()) {
    (a.left ? left : right)->click();
  }

  if (a.force_zero != forceZero->isChecked()) {
    forceZero->setChecked(a.force_zero);
  }

  switch (a.scale->index()) {
    case dessser::gen::dashboard_widget::Linear:
      if (!linear->isChecked()) {
        linear->click();
      }
      break;

    case dessser::gen::dashboard_widget::Logarithmic:
      if (!logarithmic->isChecked()) {
        logarithmic->click();
      }
      break;
  }

  return true;
}

std::shared_ptr<dessser::gen::dashboard_widget::axis>
TimeChartAxisEditor::getValue() const {
  std::shared_ptr<dessser::gen::dashboard_widget::scale> scale{
      linear->isChecked()
          ? std::make_shared<dessser::gen::dashboard_widget::scale>(
                std::in_place_index<dessser::gen::dashboard_widget::Linear>,
                dessser::Void())
          : std::make_shared<dessser::gen::dashboard_widget::scale>(
                std::in_place_index<
                    dessser::gen::dashboard_widget::Logarithmic>,
                dessser::Void())};

  return std::make_shared<dessser::gen::dashboard_widget::axis>(
      forceZero->isChecked(), left->isChecked(), scale);
}
