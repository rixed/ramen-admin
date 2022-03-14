// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREEPATH_H_220313
#define OMNITREEPATH_H_220313
/* Class for OmniTreeItem representing a source Path */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreePath : public OmniTreeItem {
 public:
  OmniTreePath(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
