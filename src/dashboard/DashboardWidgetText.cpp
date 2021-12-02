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

  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  if (widgetForm) {
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(widgetForm->cancelButton);
    buttonsLayout->addWidget(widgetForm->submitButton);
  }

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(text);
  layout->addLayout(buttonsLayout);
  QWidget *widget = new QWidget(this);
  widget->setLayout(layout);

  if (widgetForm) {
    widgetForm->setExpand(false);
    widgetForm->cancelButton->setVisible(false);
    widgetForm->submitButton->setVisible(false);
    /* Open/close the editor when the AtomicForm is enabled/disabled: */
    connect(widgetForm, &DashboardWidgetForm::changeEnabled,
            this, [widgetForm](bool enabled) {
      widgetForm->cancelButton->setVisible(enabled);
      widgetForm->submitButton->setVisible(enabled);
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
