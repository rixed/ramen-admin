// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef CONFAUTOMATON_H_200325
#define CONFAUTOMATON_H_200325
/* Some commands are made of multiple configuration changes and must wait for
 * one step to succeed before proceeding to the next one. In essence, they are
 * small, short lived state machines reacting to configuration changes.
 * They could also, optionally, log everything on a dedicated status window
 * (but ordinary logger window would do too).
 *
 * Technically, a new automaton is created for every new instances of such
 * multi-step commands, and will listen to every key change during its
 * lifetime, matching them against the current set of outgoing transitions,
 * until it reaches a final state and then destroys itself.
 */
#include <QObject>
#include <memory>
#include <string>
#include <vector>

#include "ConfChange.h"

struct KValue;
class KVStore;

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

class Automaton : public QObject {
  Q_OBJECT

 public:
  /* Note: we cannot distinguish between new and updated keys since we ignore
   * VNull values: */
  enum KeyOperation { OnSet = 1, OnLock = 2, OnUnlock = 4, OnDelete = 8 };

  /* Works only with the global kvs so no KVStore parameter.
   * Initial state will be the first one. */
  Automaton(QString const, size_t numStates, QObject *parent = nullptr);

  void addTransition(size_t fromState, size_t toState, unsigned ops = 0,
                     std::shared_ptr<dessser::gen::sync_key::t const> = nullptr,
                     double timeout = 0.);

  /* To be called once all transitions have been added to start the process. */
  void start();

  /* Some transitions might be manual, for instance to react to some other
   * signal than a key change. */
  void moveTo(size_t toState);

 signals:
  // val is null for forced transitions:
  void transitionTo(Automaton *, size_t state,
                    std::shared_ptr<dessser::gen::sync_value::t const>);

 private:
  struct Transition {
    size_t toState;
    unsigned keyOperations;
    std::shared_ptr<dessser::gen::sync_key::t const> key;
    double timeoutDate;
  };

  struct State {
    std::vector<Transition> transitions;
  };

  void tryTransition(std::shared_ptr<dessser::gen::sync_key::t const>,
                     KValue const &, KeyOperation);

  void tryDirectTransition();

 protected:
  QString const name;
  std::vector<State> states;
  size_t currentState{0};

 private slots:
  void onChange(QList<ConfChange> const &);
};

#endif
