// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREESOURCE_H_220313
#define OMNITREESOURCE_H_220313
/* Class for OmniTreeItem representing a source file */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreeSource : public OmniTreeItem {
 public:
  OmniTreeSource(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
