// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef OMNITREEMODEL_H_220313
#define OMNITREEMODEL_H_220313

/* This model represents a hierarchy of sources/programs/processes:
 * +
 * +-path/to/src1
 * |  +- RaQL
 * |  +- Schema (aka info)
 * |    +- Function1 (actual name of that function)
 * |    +- Function2
 * |        \- Worker
 * |            +- Stats
 * |            +- Process1
 * |            \- Output
 * \-path/to/src2
 *    +- etc...
 *
 * Each type of entry is prefixed with a specific icon like file explorers do.
 * At the right of the name a series of buttons allow to run actions depending
 * on the entry type, most of them just sending navigation event to the main
 * panel:
 *
 * type: action
 * any:
 *   If locked by user a dark lock symbol which display the lock information
 *   with a button to release the lock
 *   If locked by another user, a light lock which opens lock detail without any
 *   option to delete it.
 * source path:
 *   Open preferred language in code editor
 *   Delete icon to delete that source (after confirmation).
 *   This deletes all defined languages and schema.
 * specific language:
 *   Open that language in the code editor
 *   An icon to delete specifically that language (after confirmation)
 * schema:
 *   Open the (read only) info
 *   Has a button to delete (after confirmation) the precompiled info
 *   A button to run that source (opens the target-config-entry editor)
 * function:
 *   Open type info for that function
 * worker:
 *   Opens the target editor for that entry that displays parameters.
 *   A button to disable the worker
 *   A button to stop that worker
 * stats
 *   Open this worker stats (ie a page displaying all stats)
 * process:
 *   open the top, focused to that process
 *   A button to kill that process
 * Output:
 *   Open the tail-table
 */
#include <QAbstractItemModel>
#include <memory>

#include "ConfChange.h"

class OmniTreeItem;

class OmniTreeModel : public QAbstractItemModel {
  Q_OBJECT

  OmniTreeItem *root;

  OmniTreeItem *getItem(QModelIndex const &index) const;

 public:
  OmniTreeModel(QObject *parent = nullptr);

  /* Implementation of the QAbstractItemModel.
   * Will use the corresponding functions of OmniTreeItem : */

  QModelIndex index(int row, int column, QModelIndex const &parent) const;

  QModelIndex parent(QModelIndex const &index) const;

  int rowCount(QModelIndex const &parent) const;

  int columnCount(QModelIndex const &parent) const;

  QVariant data(QModelIndex const &index, int role) const;
};

#endif
