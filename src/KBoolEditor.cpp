#include <QRadioButton>
#include <QVBoxLayout>

#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"

#include "KBoolEditor.h"

KBoolEditor::KBoolEditor(QWidget *parent, QString const &yesLabel, QString const &noLabel) :
  KChoice(
    {
      { yesLabel, ofBool(true) },
      { noLabel, ofBool(false) }
    },
    parent
  ) {}
