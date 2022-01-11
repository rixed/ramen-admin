// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "storage/StorageInfoBox.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

#include "FunctionItem.h"
#include "GraphModel.h"
#include "ProgramItem.h"
#include "SiteItem.h"
#include "misc.h"

StorageInfoBox::StorageInfoBox(GraphModel *graphModel_, QWidget *parent)
    : QWidget(parent),
      graphModel(graphModel_),
      knowAllArcWorkers(false),
      knowAllArcFiles(false),
      knowAllArcBytes(false) {
  QGridLayout *layout{new QGridLayout()};

  numArcWorkersWdg = new QLabel(this);
  numArcFilesWdg = new QLabel(this);
  numArcBytesWdg = new QLabel(this);
  lastAllocatorRunWdg = new QLabel(this);

  layout->addWidget(new QLabel("Number of archiving workers:", this), 0, 0,
                    Qt::AlignRight);
  layout->addWidget(numArcWorkersWdg, 0, 1, Qt::AlignLeft);

  layout->addWidget(new QLabel("Number of archive files:", this), 1, 0,
                    Qt::AlignRight);
  layout->addWidget(numArcFilesWdg, 1, 1, Qt::AlignLeft);

  layout->addWidget(new QLabel("Archive total size:", this), 2, 0,
                    Qt::AlignRight);
  layout->addWidget(numArcBytesWdg, 2, 1, Qt::AlignLeft);

  layout->addWidget(new QLabel("Last allocator run:", this), 3, 0,
                    Qt::AlignRight);
  layout->addWidget(lastAllocatorRunWdg, 3, 1, Qt::AlignLeft);

  setLayout(layout);

  recomputeTimer = new QTimer(this);
  recomputeTimer->setSingleShot(true);
  connect(graphModel, &GraphModel::storagePropertyChanged, this,
          &StorageInfoBox::rearmRecomputeTimer);
  connect(recomputeTimer, &QTimer::timeout, this,
          &StorageInfoBox::recomputeStats);
}

static QString orMore(QString const s, bool knowAll) {
  if (knowAll) return s;
  return s + "+";
}

void StorageInfoBox::recomputeStats() {
  unsigned countWorkers{0};
  unsigned countFiles{0};
  size_t countBytes{0};
  bool all_workers{true};
  bool all_files{true};
  bool all_bytes{true};
  // TODO: lastAllocatorRun (must export it first)

  for (auto &siteItem : graphModel->sites) {
    for (auto &programItem : siteItem->programs) {
      for (auto &functionItem : programItem->functions) {
        std::shared_ptr<Function const> function{
            std::static_pointer_cast<Function const>(functionItem->shared)};
        if (function->allocArcBytes) {
          if (*function->allocArcBytes > 0) countWorkers++;
        } else
          all_workers = false;
        if (function->numArcFiles)
          countFiles += *function->numArcFiles;
        else
          all_files = false;
        if (function->numArcBytes)
          countBytes += *function->numArcBytes;
        else
          all_bytes = false;
      }
    }
  }

  if (!numArcWorkers || *numArcWorkers != countWorkers ||
      knowAllArcWorkers != all_workers) {
    *numArcWorkers = countWorkers;
    knowAllArcWorkers = all_workers;
    numArcWorkersWdg->setText(
        orMore(QString::number(countWorkers), all_workers));
  }
  if (!numArcFiles || *numArcFiles != countFiles ||
      knowAllArcFiles != all_files) {
    *numArcFiles = countFiles;
    knowAllArcFiles = all_files;
    numArcFilesWdg->setText(orMore(QString::number(countFiles), all_files));
  }
  if (!numArcBytes || *numArcBytes != countBytes ||
      knowAllArcBytes != all_bytes) {
    *numArcBytes = countBytes;
    knowAllArcBytes = all_bytes;
    numArcBytesWdg->setText(orMore(stringOfBytes(countBytes), all_bytes));
  }
}

void StorageInfoBox::rearmRecomputeTimer(FunctionItem const *) {
  static int const recomputeTimeout{1000};
  recomputeTimer->start(recomputeTimeout);
}
