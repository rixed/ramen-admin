// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ATOMICFORM_H_190504
#define ATOMICFORM_H_190504
#include <QString>
#include <QWidget>
#include <list>
#include <optional>
#include <set>

#include "ConfChange.h"
#include "KVStore.h"

/* We want to be able to edit a group of values atomically.
 * For this, we need this group of widget to be associated with 3 buttons:
 * "edit", "cancel" and "commit".
 *
 * We are passed a list of KWidgets (Keyed-Widget), which must have a
 * setEnabled(bool) slot (all QWidgets have this one),
 * and they must have a method to get the sync_value out of it, that we call
 * when we commit the form and when we click "edit" to save the initial
 * values.
 *
 * Then this class will lock all the keys (then wait for them to be actually
 * locked before making the widget editable (thanks to the notifications)
 * and the cancel/submit buttons clickable), display errors, etc.
 *
 * Regarding the layout, this class does not mess with the layout of the
 * passed widgets (assuming they are laid out already).
 * The simpler would be to build it like the MainApplication window is build:
 * ie we have an empty widget where the user add one by one the widgets that
 * he want, some of them being atomic widgets and some of them being normal
 * widgets. And then atomic form adds ots buttons below.
 * We therefore just offer an "add" method, and use introspection to know
 * it the user adds an atomic widget to register it in the atomic group.
 */

class AtomicWidget;
struct KValue;
class QHBoxLayout;
class QMessageBox;
class QPushButton;
class QVBoxLayout;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class AtomicForm : public QWidget {
  Q_OBJECT

  struct FormWidget {
    AtomicWidget *widget;
    /* Changes are detected by comparing the value stored in the widget at the
     * time it is enabled with the value stored in the widget when the used
     * submits or cancels it.
     * Null if no value could be saved (because we started in edition mode). */
    std::shared_ptr<dessser::gen::sync_value::t const> initValue;

    FormWidget(AtomicWidget *widget_) : widget(widget_), initValue(nullptr) {}
  };

  std::list<FormWidget> widgets;
  std::set<AtomicWidget *> deletables;

  bool cancelStaysEnabled;

  QVBoxLayout *groupLayout;
  QWidget *errorArea;
  QMessageBox *confirmCancelDialog, *confirmDeleteDialog;

  // The set of all keys currently locked by this user:
  std::unordered_set<std::shared_ptr<dessser::gen::sync_key::t const>, HashKey,
                     EqualKey>
      locked;

  void doCancel();
  void doSubmit();
  bool someEdited();

  // Similar to lockValue, once we already know the key is our:
  void setOwner(std::shared_ptr<dessser::gen::sync_key::t const>,
                std::optional<QString> const &);

  bool allLocked() const;

  void lockValue(std::shared_ptr<dessser::gen::sync_key::t const>,
                 KValue const &);

  void unlockValue(std::shared_ptr<dessser::gen::sync_key::t const>,
                   KValue const &);

 public:
  QPushButton *editButton, *cancelButton, *deleteButton, *submitButton;

  QWidget *centralWidget;

  /* Note: When the form is displayed on a dialog we might want to keep the
   * cancel button enabled at all times to close the dialog. */
  AtomicForm(bool visibleButtons = true, bool cancelStaysEnabled = false,
             QWidget *parent = nullptr);

  ~AtomicForm();

  /* Set this widget in the center of the layout:
   * Note that this does not imply an addWidget (indeed, the central
   * widget need not be an Atomicwidget at all. */
  void setCentralWidget(QWidget *);
  // and take ownership of those QWidgets:
  void addWidget(AtomicWidget *, bool deletable = false);

  // In case one want to add buttons in there:
  QHBoxLayout *buttonsLayout;

  bool isEnabled() const;

 protected:
  bool isMyKey(std::shared_ptr<dessser::gen::sync_key::t const>) const;

 protected slots:
  void removeWidget(QObject *);
  void checkValidity();

 public slots:
  void onChange(QList<ConfChange> const &);
  void wantEdit();
  void wantCancel();
  void wantDelete();
  void wantSubmit();
  void setEnabled(bool);
  void changeKey(std::shared_ptr<dessser::gen::sync_key::t const> oldKey,
                 std::shared_ptr<dessser::gen::sync_key::t const> newKey);

 signals:
  void changeEnabled(bool);
};

#endif
