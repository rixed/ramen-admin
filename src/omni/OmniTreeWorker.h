// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREEWORKER_H_220313
#define OMNITREEWORKER_H_220313
/* Class for OmniTreeItem representing a worker */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreeWorker : public OmniTreeItem {
 public:
  OmniTreeWorker(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
