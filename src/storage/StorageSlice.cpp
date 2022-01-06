// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "storage/StorageSlice.h"

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
using namespace QtCharts;
#endif

static QString labelOfKey(Key const &k) {
  QString label;
  for (unsigned r = 0; r < 3; r++) {
    if (k.name[r].length() == 0) continue;
    if (label.length()) label.append(r == 1 ? ":" : "/");
    label.append(k.name[r]);
  }
  return label;
}

StorageSlice::StorageSlice(QColor color_, bool labelVisible_, Key key_,
                           Values val_, DataMode dataMode, QObject *parent)
    : QPieSlice(labelOfKey(key_), val_.forMode(dataMode), parent),
      color(color_),
      labelNormallyVisible(labelVisible_),
      key(key_),
      val(val_) {
  longLabel = label();
  for (unsigned r = 0; r < 3; r++) {
    if (key.name[r].length()) shortLabel = key.name[r];
  }

  setColor(color);
  highColor = color.lighter();

  setLabelVisible(labelNormallyVisible);

  setExplodeDistanceFactor(0.04);
}

void StorageSlice::addChild(StorageSlice *slice) { children.push_back(slice); }

void StorageSlice::setSelected(bool s) {
  setColor(s ? highColor : color);
  setLabelVisible(s || labelNormallyVisible);
  setLabel(s ? shortLabel : longLabel);
  setExploded(s);
  for (auto slice : children) {
    slice->setExploded(s);
    slice->setLabelVisible(!s && slice->labelNormallyVisible);
  }
}
