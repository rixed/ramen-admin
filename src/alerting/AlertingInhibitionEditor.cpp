// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingInhibitionEditor.h"

#include <QDateTimeEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>

#include "ConfClient.h"
#include "desssergen/alerting_inhibition.h"
#include "desssergen/sync_value.h"

static constexpr bool verbose{false};

AlertingInhibitionEditor::AlertingInhibitionEditor(QWidget *parent)
    : AtomicWidget(parent) {
  whatEditor = new QLineEdit;
  whatEditor->setPlaceholderText(tr("Enter a name or glob pattern"));
  startEditor = new QDateTimeEdit;
  startEditor->setCalendarPopup(true);
  stopEditor = new QDateTimeEdit;
  stopEditor->setCalendarPopup(true);
  whyEditor = new QPlainTextEdit;
  whyEditor->setPlaceholderText(tr("Explain the reason for this inhibition"));
  whoLabel = new QLabel;

  QWidget *widget{new QWidget};
  QFormLayout *layout{new QFormLayout};
  layout->addRow(tr("Alerts matching"), whatEditor);
  layout->addRow(tr("From"), startEditor);
  layout->addRow(tr("To"), stopEditor);
  layout->addRow(new QLabel(tr("Reason for silencing those alerts")));
  layout->addRow(whyEditor);
  layout->addRow(tr("Creator"), whoLabel);

  widget->setLayout(layout);
  relayoutWidget(widget);
}

std::shared_ptr<dessser::gen::sync_value::t const>
AlertingInhibitionEditor::getValue() const {
  return std::make_shared<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::Inhibition>,
      dessser::gen::alerting_inhibition::t{
          whatEditor->text().toStdString(),
          double(startEditor->dateTime().toSecsSinceEpoch()),
          double(stopEditor->dateTime().toSecsSinceEpoch()), who,
          whyEditor->toPlainText().toStdString()});
}

void AlertingInhibitionEditor::setEnabled(bool enabled) {
  whatEditor->setEnabled(enabled);
  startEditor->setEnabled(enabled);
  stopEditor->setEnabled(enabled);
  whyEditor->setEnabled(enabled);
}

bool AlertingInhibitionEditor::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  if (v->index() != dessser::gen::sync_value::Inhibition) return false;

  dessser::gen::alerting_inhibition::t const &inhibition{
      std::get<dessser::gen::sync_value::Inhibition>(*v)};
  whatEditor->setText(QString::fromStdString(inhibition.what));
  startEditor->setDateTime(
      QDateTime::fromSecsSinceEpoch(inhibition.start_date));
  stopEditor->setDateTime(QDateTime::fromSecsSinceEpoch(inhibition.stop_date));
  whyEditor->setPlainText(QString::fromStdString(inhibition.why));
  who = inhibition.who;
  whoLabel->setText(QString::fromStdString(who));

  return true;
}

void AlertingInhibitionEditor::clear() {
  whatEditor->clear();
  QDateTime const now{QDateTime::currentDateTime()};
  startEditor->setDateTime(now);
  stopEditor->setDateTime(now.addSecs(3600));
  whyEditor->clear();
  whoLabel->clear();
}
