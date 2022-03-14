// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREEOUTPUT_H_220313
#define OMNITREEOUTPUT_H_220313
/* Class for OmniTreeItem representing */
#include <QVariant>

#include "omni/OmniTreeItem.h"

class OmniTreeOutput : public OmniTreeItem {
 public:
  OmniTreeOutput(QString name, OmniTreeItem *parent);

  int columnCount() const;
  QVariant data(int role) const;
};

#endif
