#include <QPushButton>
#include <QSizePolicy>
#include <QTextDocument>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "dashboard/DashboardWidgetForm.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/sync_value.h"
#include "GrowingTextEdit.h"

#include "dashboard/DashboardWidgetText.h"

DashboardWidgetText::DashboardWidgetText(
  DashboardWidgetForm *widgetForm,
  QWidget *parent)
  : AtomicWidget(parent)
{
  text = new GrowingTextEdit;
  text->setPlaceholderText(tr("Enter a text here"));

  QHBoxLayout *buttonsLayout { new QHBoxLayout };
  if (widgetForm) {
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(widgetForm->cancelButton);
    buttonsLayout->addWidget(widgetForm->submitButton);
    buttonsLayout->addWidget(widgetForm->deleteButton);
  }
  /* We want to hide/show those three buttons simultaneously, and independently
   * of the AtomicForm that may also call hide/show on the buttons individually.
   * Therefore we pack them in a widget and will hide/show that widget instead: */
  QWidget *buttonBox { new QWidget };
  buttonBox->setLayout(buttonsLayout);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(text);
  layout->addWidget(buttonBox);
  QWidget *widget = new QWidget(this);
  widget->setLayout(layout);

  if (widgetForm) {
    widgetForm->setExpand(false);
    buttonBox->setVisible(false);
    /* Open/close the editor when the AtomicForm is enabled/disabled: */
    connect(widgetForm, &DashboardWidgetForm::changeEnabled,
            this, [buttonBox](bool enabled)
      {
        buttonBox->setVisible(enabled);
      });
  };

  QSizePolicy p { sizePolicy() };
  p.setVerticalPolicy(QSizePolicy::Fixed);
  p.setVerticalStretch(0);
  setSizePolicy(p);

  relayoutWidget(widget);
}

void DashboardWidgetText::setEnabled(bool enabled)
{
  text->setEnabled(enabled);
}

bool DashboardWidgetText::setValue(
  std::shared_ptr<dessser::gen::sync_key::t const>,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  if (v->index() != dessser::gen::sync_value::DashboardWidget) {
not_a_dash:
    qWarning("DashboardWidgetText::setValue: not a conf::DashWidgetText?");
    return false;
  }

  std::shared_ptr<dessser::gen::dashboard_widget::t> w {
    std::get<dessser::gen::sync_value::DashboardWidget>(*v) };

  if (w->index() != dessser::gen::dashboard_widget::Text) goto not_a_dash;

  text->setHtml(
    QString::fromStdString(std::get<dessser::gen::dashboard_widget::Text>(*w)));

  return true;
}

std::shared_ptr<dessser::gen::sync_value::t const> DashboardWidgetText::getValue() const
{
  std::shared_ptr<dessser::gen::dashboard_widget::t> w {
    std::make_shared<dessser::gen::dashboard_widget::t>(
      std::in_place_index<dessser::gen::dashboard_widget::Text>,
      text->document()->toHtml().toStdString()) };

  return std::make_shared<dessser::gen::sync_value::t>(
    std::in_place_index<dessser::gen::sync_value::DashboardWidget>,
    w);
}
