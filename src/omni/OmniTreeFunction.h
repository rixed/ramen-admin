// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREEFUNCTION_H_220313
#define OMNITREEFUNCTION_H_220313
/* Class for OmniTreeItem representing a function */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreeFunction : public OmniTreeItem {
 public:
  OmniTreeFunction(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
