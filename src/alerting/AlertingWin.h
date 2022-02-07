// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGWINDOW_H_200525
#define ALERTINGWINDOW_H_200525
#include <QString>
#include <functional>

#include "SavedWindow.h"

class AlertingJournal;
class AlertingStats;
class AlertingTimeLine;
class EditContactDialog;
class NewContactDialog;
class EditInhibitionDialog;
class NewInhibitionDialog;
class NewTeamDialog;
class QAction;
class QMenu;
struct ConfChange;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
}  // namespace gen
}  // namespace dessser

class AlertingWin : public SavedWindow {
  Q_OBJECT

  AlertingStats *stats;
  AlertingTimeLine *timeLine;
  AlertingJournal *journal;

  QMenu *teamsMenu;

  NewTeamDialog *newTeamDialog;
  NewContactDialog *newContactDialog;
  NewInhibitionDialog *newInhibitionDialog;

  EditContactDialog *editContactDialog;
  EditInhibitionDialog *editInhibitionDialog;

  void addTeamEntry(dessser::gen::sync_key::t const &);
  void delTeamEntry(dessser::gen::sync_key::t const &);

  void newTeam(int);
  void newContact(int);
  void newInhibition(int);

  QAction *findOrCreateMenuEntry(QString const &,
                                 std::function<QAction *(QString const &)>);
  QAction *findOrCreateTeamMenuEntry(QString const &);
  QAction *findOrCreateSectionEntry(QMenu *, int, QString const &,
                                    std::function<QAction *(QString const &)>);
  QAction *findOrCreateContactMenuEntry(QMenu *, QString const &,
                                        QString const &);
  QAction *findOrCreateInhibitionMenuEntry(QMenu *, QString const &,
                                           QString const &);

 public:
  AlertingWin(QWidget *parent = nullptr);

 public slots:
  void onChange(QList<ConfChange> const &);
};

#endif
