// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREEProcess_H_220313
#define OMNITREEProcess_H_220313
/* Class for OmniTreeItem representing the Unix process of a worker */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreeProcess : public OmniTreeItem {
 public:
  OmniTreeProcess(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
