// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "EventTime.h"

#include <QDebug>
#include <QString>

#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "misc_dessser.h"

static constexpr bool verbose{false};

EventTime::EventTime(dessser::gen::raql_type::t const &type)
    : startColumn(-1), stopColumn(-1) {
  if (!isScalar(type)) {
    unsigned const num_cols{numColumns(type)};
    for (unsigned column = 0; column < num_cols; column++) {
      std::shared_ptr<dessser::gen::raql_type::t const> subType{
          columnType(type, column)};
      if (subType && isScalar(*subType)) {
        std::string const name{columnName(type, column)};
        if (name == "start") {
          startColumn = column;
          if (verbose)
            qDebug() << "EventTime::EventTime(): Found start field to be "
                     << startColumn;
        } else if (name == "stop") {
          stopColumn = column;
          if (verbose)
            qDebug() << "EventTime::EventTime(): Found stop field to be "
                     << stopColumn;
        }
      }
    }
  }
}

bool EventTime::isValid() const { return startColumn >= 0; }

std::optional<double> EventTime::startOfTuple(
    dessser::gen::raql_value::t const &tuple) const {
  if (startColumn < 0) return std::nullopt;
  std::shared_ptr<dessser::gen::raql_value::t const> startVal{
      columnValue(tuple, startColumn)};
  if (!startVal) return std::nullopt;
  return toDouble(*startVal);
}

std::optional<double> EventTime::stopOfTuple(
    dessser::gen::raql_value::t const &tuple) const {
  if (stopColumn < 0) return std::nullopt;
  std::shared_ptr<dessser::gen::raql_value::t const> stopVal{
      columnValue(tuple, stopColumn)};
  if (!stopVal) return std::nullopt;
  return toDouble(*stopVal);
}

QDebug operator<<(QDebug debug, EventTime const &v) {
  QDebugStateSaver saver(debug);
  debug.nospace() << "Start column:" << v.startColumn
                  << ", Stop column:" << v.stopColumn;

  return debug;
}
