// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ProgramPartItem.h"

#include <QDebug>
#include <QMarginsF>

#include "FunctionItem.h"
#include "GraphModel.h"
#include "ProgramItem.h"
#include "Resources.h"
#include "stream/GraphView.h"

static constexpr bool verbose{false};

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
  QString s{" ProgramPart[" + QString::number(row) + QString("]:") +
            shared->name};
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

/* Collapse or expand any actual descendent subprogram, while keeping the
 * ProgramPartItem collapse flag flag as they are, ie representative of the
 * state in the treeview, as required for further handling of those events. */
void ProgramPartItem::propagateSetCollapse(bool c) {
  /* If we are collapsing, collapse actual programs. If we are expanding,
   * restore their original state (ie. that of the parent ProgramPart): */
  if (actualProgram) actualProgram->setCollapsed(c || isCollapsed());
  for (ProgramPartItem *subPart : subParts) {
    if (subPart->isCollapsed()) continue;
    subPart->propagateSetCollapse(c);
  }
}

void ProgramPartItem::setCollapsed(bool c) {
  GraphItem::setCollapsed(c);
  if (actualProgram)
    actualProgram->setCollapsed(c);
  else {
    /* Bummer! Below actual programs won't be hidden/shown as they are not our
     * subItems but sites'.  So walk the subtree (as long as it's expanded)
     * and manually collapse/expand them. */
    propagateSetCollapse(c);
  }
}
