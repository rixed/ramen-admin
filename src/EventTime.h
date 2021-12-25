#ifndef EVENTTIME_H_191008
#define EVENTTIME_H_191008
/* An object to represent a RamenEventTime and also perform quick extraction
 * of a tuple's event time: */
#include <optional>

namespace dessser {
namespace gen {
namespace raql_type {
struct t;
}
namespace raql_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

struct EventTime {
  /* No support for old-style event-time (esp. since it could depend on
   * parameters which we cannot easily have access to from here). */
  EventTime(dessser::gen::raql_type::t const &);

  bool isValid() const;

  std::optional<double> startOfTuple(dessser::gen::raql_value::t const &) const;
  std::optional<double> stopOfTuple(dessser::gen::raql_value::t const &) const;

  /* Record the location of the start/stop field in the tuple, or -1 if
   * they are not present. */
  int startColumn;
  int stopColumn;
};

QDebug operator<<(QDebug debug, EventTime const &);

#endif
