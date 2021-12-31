// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ProgramPartItem.h"

#include <QDebug>
#include <QMarginsF>

#include "FunctionItem.h"
#include "GraphModel.h"
#include "ProgramItem.h"
#include "Resources.h"
#include "stream/GraphView.h"

static bool const verbose{false};

ProgramPartItem::ProgramPartItem(GraphItem *treeParent,
                                 std::unique_ptr<ProgramPart> program,
                                 ProgramItem *actualProgram_)
    : GraphItem(treeParent, std::move(program), nullptr),
      actualProgram(actualProgram_) {
  Q_ASSERT(treeParent);
  if (verbose)
    qDebug() << "Create a new ProgramPartItem at" << intptr_t(this)
             << "treeParent=" << (intptr_t)treeParent << "actualProgram"
             << (intptr_t)actualProgram;
}

QRectF ProgramPartItem::operationRect() const {
  if (actualProgram) {
    return actualProgram->operationRect();
  } else {
    QRectF bbox;
    for (auto const &sub_part : subParts) {
      QRectF b{sub_part->operationRect()};
      b.translate(sub_part->pos());
      bbox |= b;
    }
    return bbox;
  }
}

// All their running functions are top-halves
bool ProgramPartItem::isTopHalf() const {
  if (!actualProgram) return false;
  return actualProgram->isTopHalf();
}

bool ProgramPartItem::isUsed() const {
  if (!actualProgram) return false;
  return actualProgram->isUsed();
}

bool ProgramPartItem::isRunning() const {
  if (!actualProgram) return false;
  return actualProgram->isRunning();
}

bool ProgramPartItem::isWorking() const {
  if (!actualProgram) return false;
  return actualProgram->isWorking();
}

ProgramPartItem::operator QString() const {
  QString s{" ProgramPart[" + QString(row) + QString("]:") + shared->name};
  return s;
}

void ProgramPartItem::reorder(GraphModel *) {
  int numFunctions{actualProgram ? (int)actualProgram->functions.size() : 0};
  for (int i = 0; (size_t)i < subParts.size(); i++) {
    if (subParts[i]->row != numFunctions + i) {
      subParts[i]->row = numFunctions + i;
    }
  }
}
