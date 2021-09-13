#include <QRadioButton>
#include <QVBoxLayout>

#include "MakeSyncValue.h"

#include "KBool.h"

KBool::KBool(QString const &yesLabel, QString const &noLabel, QWidget *parent) :
  KChoice(
    {
      { yesLabel, ofBool(true) },
      { noLabel, ofBool(false) }
    },
    parent
  ) {}

KBool::KBool(QWidget *parent) :
  KBool(tr("yes"), tr("no"), parent) {}
