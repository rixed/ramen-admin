// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef SOURCEEDIT_H_190516
#define SOURCEEDIT_H_190516
#include <QWidget>
#include <memory>
#include <string>

#include "ConfChange.h"

class AlertEditor;
class PivotEditor;
class AtomicWidget;
class KTextEdit;
struct KValue;
class ProgramItem;
class QComboBox;
class QLabel;
class QStackedLayout;
class SourceInfoViewer;

namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class SourceEdit : public QWidget {
  Q_OBJECT

  AtomicWidget const *currentWidget() const;

  void setError(std::shared_ptr<dessser::gen::sync_key::t const>,
                KValue const &);

  /* Associate the given key to that editor for that language index
   * if the key is null then no key will be associated. */
  void setLanguageKey(int, AtomicWidget *,
                      std::shared_ptr<dessser::gen::sync_key::t const>);

 public:
  std::string srcPath;

  /* When several source extensions are defined, an additional combo box is
   * visible: */
  QComboBox *extensionsCombo;
  QWidget *extensionSwitcher;

  /* The editor for alert sources: */
  AlertEditor *alertEditor;

  /* The editor for pivot sources: */
  PivotEditor *pivotEditor;

  /* The editor for ramen language sources: */
  KTextEdit *textEditor;

  /* We do not really edit the info but that's nice to see it here, and it is
   * more natural that the form lock/unlock/delete the info key alongside
   * the other editable sources. Especially, the deletion of the info file is
   * what triggers the worker to be stopped. */
  SourceInfoViewer *infoEditor;

  /* The stackedLayout to display either of the above, and their indices: */
  QStackedLayout *stackedLayout;

  int textEditorIndex;
  int alertEditorIndex;
  int pivotEditorIndex;
  int infoEditorIndex;

  QWidget *errorsBox;         // Hide or show depending on presence of errors
  QLabel *compilationErrors;  // Text of errors
  QWidget *warningsBox;
  QLabel *compilationWarnings;

  SourceEdit(QWidget *parent = nullptr);

  // Returns the value of the value of the currently selected editor:
  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;

  void enableLanguage(int index, bool enabled);

  bool hasValidInput() const;

 protected:
  void resetError(KValue const *);
  void doResetError(KValue const &);

 public slots:
  void setSrcPath(std::string const &);

  /* Display the editor corresponding to the given language index (either
   * textEditorIndex, alertEditorIndex, pivotEditorIndex...): */
  void setLanguage(int index);

  void disableLanguageSwitch(bool);

 protected slots:
  void onChange(QList<ConfChange> const &);

 signals:
  void inputChanged();
};

#endif
