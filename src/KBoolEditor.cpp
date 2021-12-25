#include "KBoolEditor.h"

#include <QRadioButton>
#include <QVBoxLayout>

#include "MakeSyncValue.h"
#include "desssergen/sync_value.h"

KBoolEditor::KBoolEditor(QWidget *parent, QString const &yesLabel,
                         QString const &noLabel)
    : KChoice({{yesLabel, ofBool(true)}, {noLabel, ofBool(false)}}, parent) {}
