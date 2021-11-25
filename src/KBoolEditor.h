#ifndef KBOOLEDITOR_H_190516
#define KBOOLEDITOR_H_190516
/* AtomicWidget to configure a boolean. */
#include "KChoice.h"

class KBoolEditor : public KChoice
{
  Q_OBJECT

public:
  KBoolEditor(
    QWidget *parent = nullptr,
    QString const &yesLabel = tr("true"),
    QString const &noLabel = tr("false"));
};

#endif
