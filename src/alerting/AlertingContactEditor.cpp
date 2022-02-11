// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "alerting/AlertingContactEditor.h"

#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedLayout>

#include "RangeDoubleValidator.h"
#include "alerting/AlertingContactExecuteEditor.h"
#include "alerting/AlertingContactIgnoreEditor.h"
#include "alerting/AlertingContactKafkaEditor.h"
#include "alerting/AlertingContactSqliteEditor.h"
#include "alerting/AlertingContactSyslogEditor.h"
#include "desssergen/alerting_contact.h"
#include "desssergen/sync_value.h"

static constexpr bool verbose{false};

static QStringList alternatives{"Ignore", "Execute", "Syslog", "Sqlite",
                                "Kafka"};

AlertingContactEditor::AlertingContactEditor(QWidget *parent)
    : AtomicWidget(parent) {
  QWidget *widget{new QWidget};
  QFormLayout *layout{new QFormLayout};

  typeEdit = new QComboBox;
  typeEdit->insertItems(0, alternatives);

  editors.reserve(alternatives.length());
  editors.emplace_back(new AlertingContactIgnoreEditor);
  editors.emplace_back(new AlertingContactExecuteEditor);
  editors.emplace_back(new AlertingContactSyslogEditor);
  editors.emplace_back(new AlertingContactSqliteEditor);
  editors.emplace_back(new AlertingContactKafkaEditor);
  stackedLayout = new QStackedLayout;
  for (AlertingContactViaEditor *w : editors) stackedLayout->addWidget(w);

  timeoutEditor = new QLineEdit;
  timeoutEditor->setValidator(RangeDoubleValidator::forRange(0, 9999));
  timeoutEditor->setPlaceholderText(tr("seconds"));
  QLabel *doc{
      new QLabel(tr("If timeout is set to a positive number of seconds then "
                    "alerts will be delivered again unless acknowledged."))};
  doc->setStyleSheet("font-style: italic");
  doc->setWordWrap(true);

  layout->addRow(tr("Select the desired type:"), typeEdit);
  layout->addRow(stackedLayout);
  layout->addRow(tr("How long before escalating:"), timeoutEditor);
  layout->addRow(doc);

  widget->setLayout(layout);
  relayoutWidget(widget);

  connect(typeEdit, QOverload<int>::of(&QComboBox::currentIndexChanged),
          [this](int index) { stackedLayout->setCurrentIndex(index); });
}

std::shared_ptr<dessser::gen::sync_value::t const>
AlertingContactEditor::getValue() const {
  double const timeout{timeoutEditor->text().toDouble()};
  int const editor_index{stackedLayout->currentIndex()};
  Q_ASSERT(editor_index < (ssize_t)editors.size());
  return std::make_shared<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::AlertingContact>,
      dessser::gen::alerting_contact::t{*editors[editor_index]->getValue(),
                                        timeout});
}

void AlertingContactEditor::setEnabled(bool enabled) {
  typeEdit->setEnabled(enabled);
  for (AlertingContactViaEditor *w : editors) w->setEnabled(enabled);
  timeoutEditor->setEnabled(enabled);
}

bool AlertingContactEditor::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  if (v->index() != dessser::gen::sync_value::AlertingContact) return false;

  dessser::gen::alerting_contact::t const &contact{
      std::get<dessser::gen::sync_value::AlertingContact>(*v)};
  size_t const index{contact.via.index()};
  if (index > editors.size()) {
    qFatal("AlertingContactEditor::setValue: Invalid via->index");
    return false;
  }
  if (!editors[index]->setValue(contact.via)) return false;
  // stackedLayout->setCurrentIndex(index);
  typeEdit->setCurrentIndex(index);  // Will set stackedLayout
  timeoutEditor->setText(QString::number(contact.timeout));
  return true;
}

void AlertingContactEditor::clear() {
  typeEdit->setCurrentIndex(0);
  for (AlertingContactViaEditor *e : editors) e->clear();
  timeoutEditor->clear();
}
