// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "KBoolEditor.h"

#include <QRadioButton>
#include <QVBoxLayout>

#include "MakeSyncValue.h"
#include "desssergen/sync_value.h"

KBoolEditor::KBoolEditor(QWidget *parent, QString const &yesLabel,
                         QString const &noLabel)
    : KChoice({{yesLabel, ofBool(true)}, {noLabel, ofBool(false)}}, parent) {}
