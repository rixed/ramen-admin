// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ATOMICWIDGET_H_190506
#define ATOMICWIDGET_H_190506
/* What an AtomicForm remembers about its widgets */
#include <QWidget>
#include <memory>

#include "ConfChange.h"

struct KValue;
class QStackedLayout;

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

/* We choose to have AtomicWidget a QObject, meaning the derived
 * implementations of an AtomicWidgets cannot also inherit a QObject (ie any
 * QWidget). Instead they will have to include this QWidget they wish they
 * inherited from as a member and redirect calls to the few interesting QWidget
 * functions to that member. To help with this (esp. sizing) pass your widget
 * to relayoutWidget. This allows us to use an AtomicWidget to indiscriminately
 * manipulate any value editor. */
class AtomicWidget : public QWidget {
  Q_OBJECT

  QStackedLayout *layout;

  // For the default implementation of setKey()/key()
  std::shared_ptr<dessser::gen::sync_key::t const> _key;

  void lockValue(dessser::gen::sync_key::t const &, KValue const &);

  void unlockValue(dessser::gen::sync_key::t const &, KValue const &);

  void forgetValue(dessser::gen::sync_key::t const &, KValue const &);

 public:
  AtomicWidget(QWidget *parent = nullptr);

  /* As much as we'd like to build the widget and set its key in one go, we
* cannot because virtual function setValues cannot be resolved at
* construction time:
AtomicWidget(std::string const &k, QWidget *parent) :
AtomicWidget(parent) {
setKey(k);
} */

  virtual std::shared_ptr<dessser::gen::sync_key::t const> key() const {
    return _key;
  }

  QString dbgId() const;

  bool sameKey(dessser::gen::sync_key::t const &k) const {
    std::shared_ptr<dessser::gen::sync_key::t const> current{key()};
    return current && k == *current;
  }

  bool sameKey(std::shared_ptr<dessser::gen::sync_key::t const> k) const {
    std::shared_ptr<dessser::gen::sync_key::t const> current{key()};
    if (!k) return !current;
    return current && *k == *current;
  }

  // Called by setKey to actually save (a copy of) that new key:
  virtual void saveKey(
      std::shared_ptr<dessser::gen::sync_key::t const> newKey) {
    _key = newKey;
  }

  virtual void setEnabled(bool) = 0;

  // By default do not set any value (read-only):
  virtual std::shared_ptr<dessser::gen::sync_value::t const> getValue() const {
    return nullptr;
  }

  /* Return false if the editor can not display this value because of
   * incompatible types.
   * Note: need to share that value because AtomicWidget might keep a
   * copy. */
  // TODO: replace the widget with an error message then.
  virtual bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>) = 0;

  virtual bool hasValidInput() const { return true; }

  /* We want the AtomicWidget to survive the removal of the key from the
   * kvs so we merely take and store the key name and will lookup the kvs
   * each time we need the actual value (which is almost never - the widget
   * produces the value).
   * If nullptr, the value is not supposed to be found in the configuration,
   * and edition is disabled. */
  virtual void setKey(std::shared_ptr<dessser::gen::sync_key::t const>);

  /* Get the value from the store and call setValue. Does nothing if the
   * key is unset.
   * Returns the result of setValue, or true if the key is unset. */
  bool setValueFromStore();

 protected:
  void relayoutWidget(QWidget *w);

 public slots:
  void onChange(QList<ConfChange> const &);

 signals:
  // Triggered when the key is changed:
  void keyChanged(std::shared_ptr<dessser::gen::sync_key::t const> old,
                  std::shared_ptr<dessser::gen::sync_key::t const> new_);

  // Triggered when the underlying value is changed
  void valueChanged(std::shared_ptr<dessser::gen::sync_value::t const>);

  // Triggered when the edited value is changed
  void inputChanged();
};

#endif
