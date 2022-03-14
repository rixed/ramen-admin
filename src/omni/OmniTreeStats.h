// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREESTATS_H_220313
#define OMNITREESTATS_H_220313
/* Class for OmniTreeItem representing */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreeStats : public OmniTreeItem {
 public:
  OmniTreeStats(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
