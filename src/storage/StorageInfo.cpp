#include "storage/StorageInfo.h"

#include <QLabel>
#include <QSizePolicy>

#include "storage/StorageForm.h"
#include "storage/StorageInfoBox.h"

StorageInfo::StorageInfo(GraphModel *graphModel, QWidget *parent)
    : QSplitter(parent) {
  StorageForm *form{new StorageForm};
  addWidget(form);

  StorageInfoBox *infos{new StorageInfoBox(graphModel)};
  addWidget(infos);

  // Make the edit form as narrow as possible:
  setStretchFactor(0, 0);
  setStretchFactor(1, 1);
}
