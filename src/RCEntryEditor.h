// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef RCENTRYEDITOR_H_190607
#define RCENTRYEDITOR_H_190607
#include <QCheckBox>
#include <QMap>
#include <QWidget>
#include <memory>
#include <string>

#include "ConfChange.h"

/* An editor for a single entry of the target configuration.
 * The actual TargetConfigEditor, bound to the TargetConfig entry in the
 * config tree, will use many of those in a QToolBox. */

struct KValue;
class QFormLayout;
class QLabel;
class QComboBox;
class QLineEdit;

namespace dessser {
namespace gen {
namespace program_parameter {
struct t;
}
namespace raql_value {
struct t;
}
namespace rc_entry {
struct t;
}
namespace source_info {
struct t;
}
namespace sync_key {
struct t;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class RCEntryEditor : public QWidget {
  Q_OBJECT

  friend class TargetConfigEditor;

 protected:
  QLineEdit *suffixEdit;
  QComboBox *sourceBox;
  QLabel *deletedSourceWarning;
  QLabel *notCompiledSourceWarning;
  bool sourceDoesExist;
  bool sourceIsCompiled;
  QCheckBox *enabledBox, *debugBox, *automaticBox;
  QLineEdit *sitesEdit;
  QLineEdit *reportEdit;
  QLineEdit *cwdEdit;

  /* The SourceInfo defines the possible parameters, with a name, a doc and a
   * default value. On top of that, the rc-entry comes with a (possibly
   * smaller) set of parameters overwriting the defaults.  The form must offer
   * to edit every defined params for that source.  When the sourceBox is
   * changed, the set of defined parameters change and an unset parameters but
   * appear again with the default value. In case the edition is cancelled then
   * AtomicWidget will reset the value it witnessed initially. */
  // Returned value still owned by the callee
  std::shared_ptr<dessser::gen::raql_value::t const> paramValue(
      std::shared_ptr<dessser::gen::program_parameter::t const>) const;

  // Bag of previously set parameter values:
  static QMap<std::string, std::shared_ptr<dessser::gen::raql_value::t const> >
      setParamValues;

  /* Keep the layout so it can be reset and also the widget and param
   * names can be retrieved: */
  QFormLayout *paramsForm;

  /* Whether the edition of this RC entry is currently enabled or not: */
  bool enabled;

  void addSourceFromStore(dessser::gen::sync_key::t const &, KValue const &);
  void updateSourceFromStore(dessser::gen::sync_key::t const &, KValue const &);
  void removeSourceFromStore(dessser::gen::sync_key::t const &, KValue const &);

 public:
  bool sourceEditable;

  RCEntryEditor(bool sourceEditable = true, QWidget *parent = nullptr);

  // Select that one, even if it does not exist:
  void setProgramName(std::string const &);

  /* An RCEntryEditor can be used to edit an existing entry when editing the
   * TargetConfig, or to create a new entry when asking to run a new program.
   * In the former case, the editor must be enabled/disabled according to
   * the TargetConfig lock state in the confserver, using this setEnabled
   * function. In the later case, the RCEntryEditor must be enabled once
   * after creation, as its initially constructed disabled: */
  void setEnabled(bool);

  /* Both addSource and findOrAddSourceName return the position in the select
   * box where the name has been inserted/found (so it can be programmatically
   * selected), or -1 if it has not been inserted. */
  int addSource(dessser::gen::sync_key::t const &);
  int findOrAddSourceName(QString const &);

  void updateSourceWarnings();

  void saveParams();
  void clearParams();

  bool isValid() const;

  /* Build a new RCEntry according to current content.
   * Caller takes ownership */
  std::shared_ptr<dessser::gen::rc_entry::t> getValue() const;

  bool programIsEnabled() const {
    return enabledBox && enabledBox->isChecked();
  }

 signals:
  void inputChanged();

 private slots:
  void onChange(QList<ConfChange> const &);

 private:
  /* Refresh the params each time another source is selected.
   * Used to reset the parameter table */
  void resetParams();
  // Set the form values according to this RCEntry:
  void setValue(dessser::gen::rc_entry::t const &);
};

#endif
