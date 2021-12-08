#include <cassert>
#include <limits>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QVBoxLayout>

#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

#include "KNullableEditor.h"

KNullableEditor::KNullableEditor(
    AtomicWidget *editor_,
    QWidget *parent) :
  AtomicWidget(parent),
  editor(editor_)
{
  QVBoxLayout *layout { new QVBoxLayout };
  nullButton = new QRadioButton(tr("null"));
  layout->addWidget(nullButton);
  notNullButton = new QRadioButton(tr("not null"));
  QHBoxLayout *l { new QHBoxLayout };
  l->addWidget(notNullButton);
  l->addWidget(editor);
  layout->addLayout(l);

  QWidget *w { new QWidget };
  w->setLayout(layout);
  relayoutWidget(w);

  connect(nullButton, &QRadioButton::released,
          this, &KNullableEditor::setNull);
  connect(notNullButton, &QRadioButton::released,
          this, &KNullableEditor::setNotNull);
  connect(editor, &AtomicWidget::valueChanged,
          this, &KNullableEditor::valueChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KNullableEditor::getValue() const
{
  if (nullButton->isChecked()) {
    return nullVal;
  } else {
    return editor->getValue();
  }
}

void KNullableEditor::setEnabled(bool enabled)
{
  nullButton->setEnabled(enabled);
  notNullButton->setEnabled(enabled);
  editor->setEnabled(enabled && notNullButton->isChecked());
}

bool KNullableEditor::setValue(
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*v) };

  if (rv->index() == dessser::gen::raql_value::VNull) {
    if (nullButton->isChecked()) return false;
    // Will trigget setNull, which will emit valueChanged
    nullButton->setChecked(true);
    return true;
  } else {
    bool ret { editor->setValue(v) };
    if (!notNullButton->isChecked()) {
      notNullButton->setChecked(true);
      ret = true;
    }
    return ret;
  }
}

void KNullableEditor::setNull()
{
  emit valueChanged(nullVal);
  editor->setEnabled(false);
}

void KNullableEditor::setNotNull()
{
  editor->setEnabled(isEnabled());
  emit valueChanged(editor->getValue());
}
