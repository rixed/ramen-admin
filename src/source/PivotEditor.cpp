// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "PivotEditor.h"

#include <QLabel>
#include <QVBoxLayout>

static constexpr bool verbose{false};

PivotEditor::PivotEditor(QWidget *parent) : AtomicWidget(parent) {
  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(new QLabel("TODO"));
  setLayout(layout);
}
