// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "target_config/TargetConfigEditor.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QtGlobal>

#include "Menu.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"
#include "target_config/TargetConfigEntryEditor.h"

static constexpr bool verbose{false};

TargetConfigEditor::TargetConfigEditor(QWidget *parent)
    : AtomicWidget(parent), currentIndex(-1) {
  entries.reserve(10);

  entrySelector = new QComboBox;
  entryEditor = new TargetConfigEntryEditor(true);
  noSelectionText = new QLabel(tr("No programs are running.\n"
                                  "Press %1+R to run a program.")
                                   .arg(Menu::commandKey));
  stackedLayout = new QStackedLayout;
  entryEditorIdx = stackedLayout->addWidget(entryEditor);
  noSelectionIdx = stackedLayout->addWidget(noSelectionText);
  stackedLayout->setCurrentIndex(noSelectionIdx);

  QWidget *w{new QWidget};
  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(entrySelector);
  layout->addLayout(stackedLayout);
  w->setLayout(layout);
  relayoutWidget(w);

  connect(entryEditor, &TargetConfigEntryEditor::inputChanged, this,
          &TargetConfigEditor::inputChanged);

  connect(entrySelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &TargetConfigEditor::changeEntry);
}

std::shared_ptr<dessser::gen::sync_value::t const>
TargetConfigEditor::getValue() const {
  /* Build a new config copying the current one but for the currently edited
   * entry: */
  dessser::Arr<dessser::gen::rc_entry::t_ext> target_config;
  if (verbose)
    qDebug() << "TargetConfigEditor:getValue:" << entries.size()
             << "entries, currently selected:" << currentIndex;
  for (int i = 0; i < (int)entries.size(); i++) {
    if (verbose)
      qDebug() << "TargetConfigEditor::getValue: entry" << i << ":"
               << *entries[i] << "@" << intptr_t(entries[i].get());
    target_config.push_back(i == currentIndex ? entryEditor->getValue()
                                              : entries[i]);
  }

  return std::make_shared<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::TargetConfig>,
      target_config);
}

void TargetConfigEditor::setEnabled(bool enabled) {
  if (verbose) qDebug() << "TargetConfigEditor::setEnabled(" << enabled << ")";

  /* Keep the entrySelector enabled so we can still switch between entries when
   * edition is disabled. */
  entryEditor->setEnabled(enabled);
}

bool TargetConfigEditor::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  if (verbose) qDebug() << "TargetConfigEditor::setValue" << *v;
  if (v->index() != dessser::gen::sync_value::TargetConfig) {
    qCritical() << "Target config not of TargetConfig type!?";
    return false;
  }

  dessser::Arr<dessser::gen::rc_entry::t_ext> target_config{
      std::get<dessser::gen::sync_value::TargetConfig>(*v)};

  /* Since we have a single value and it is locked whenever we want to edit
   * it, the current widget cannot have any modification when a new value is
   * received. Therefore there is no use for preserving current values.
   * Signals must be blocked during the change or the changeEntry slot will
   * be called when the first item is added and cause mayhem. */
  entrySelector->blockSignals(true);
  int const saved_current_idx{currentIndex};
  entries.clear();
  while (entrySelector->count() > 0) entrySelector->removeItem(0);

  // Copy the entries:
  for (std::shared_ptr<dessser::gen::rc_entry::t> const &entry :
       target_config) {
    if (verbose)
      qDebug() << "TargetConfigEditor::setValue entry" << entries.size()
               << "is now" << *entry << "@" << intptr_t(entry.get());
    entries.push_back(entry);
    entrySelector->addItem(QString::fromStdString(entry->program));
  }
  Q_ASSERT(entrySelector->count() == (int)entries.size());
  entrySelector->blockSignals(false);

  /* Select the same entry again */
  if (entries.size() > 0) {
    stackedLayout->setCurrentIndex(entryEditorIdx);
    int const new_idx{saved_current_idx >= 0 &&
                              saved_current_idx < (int)entries.size()
                          ? saved_current_idx
                          : 0};
    if (verbose)
      qDebug() << "TargetConfigEditor::setValue: selecting entry" << new_idx
               << "=" << *entries[new_idx];
    entryEditor->setValue(*entries[new_idx]);
    entrySelector->setCurrentIndex(new_idx);
    /* In case we moved from 0 to 1 entry, the addItem had already moved the
     * current index to 0 so the above setCurrentIndex won't trigger a new
     * currentTextChanged signal, so let's update currentIndex ourselves: */
    currentIndex = new_idx;
  } else {
    stackedLayout->setCurrentIndex(noSelectionIdx);
    entrySelector->setCurrentIndex(-1);
    currentIndex = -1;
  }

  emit valueChanged(v);

  return true;
}

void TargetConfigEditor::removeCurrentEntry() {
  int const idx{entrySelector->currentIndex()};
  Q_ASSERT(idx == currentIndex);

  if (stackedLayout->currentIndex() != entryEditorIdx || idx < 0 ||
      idx >= (int)entries.size())
    return;

  entries.erase(entries.begin() + idx);
  entrySelector->removeItem(idx);
  // In case the last entry was deleted:
  currentIndex = entrySelector->currentIndex();
}

void TargetConfigEditor::preselect(QString const &programName) {
  int const idx{entrySelector->findText(programName)};
  if (idx < 0) {
    qCritical() << "Could not preselect program" << programName;
    return;
  }

  if (idx != entrySelector->currentIndex()) {
    entrySelector->setCurrentIndex(idx);
  }
}

void TargetConfigEditor::changeEntry(int idx) {
  if (currentIndex >= 0) {
    /* Save the value from the editor: */
    if (currentIndex < (int)entries.size()) {
      if (verbose)
        qDebug()
            << "TargetConfigEditor::changeEntry: saving the current value for"
            << currentIndex << "from the editor";
      entries[currentIndex] = entryEditor->getValue();
    } else {
      /* Can happen that currentIndex is right past the end if we deleted
       * the last entry: */
      Q_ASSERT(currentIndex == (int)entries.size());
    }
  }

  currentIndex = idx;

  if (idx >= 0) {
    entryEditor->setValue(*entries[idx]);
  }
}
