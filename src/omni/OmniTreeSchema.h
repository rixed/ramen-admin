// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREESCHEMA_H_220313
#define OMNITREESCHEMA_H_220313
/* Class for OmniTreeItem representing an info file (aka that program's schema)
 */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreeSchema : public OmniTreeItem {
 public:
  OmniTreeSchema(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
