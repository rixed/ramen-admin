#ifndef MISC_DESSSER_H_210910
#define MISC_DESSSER_H_210910
#include <memory>
#include <optional>
#include <string>
#include <QDebug>
#include <QString>

namespace dessser {
  namespace gen {
    namespace raql_expr { struct t; }
    namespace raql_type {
      struct t;
      struct base;
    }
    namespace raql_value { struct t; }
    namespace sync_client_cmd { struct t; }
    namespace sync_client_msg { struct t; }
    namespace sync_server_msg { struct t; }
    namespace sync_msg { struct t; }
    namespace sync_socket { struct t; }
    namespace sync_key { struct t; }
    namespace sync_value { struct t; }
  }
}

// All but vectors, lists, tuples, records, sum types
bool isScalar(dessser::gen::raql_type::t const &);

// All integers, floats and bool.
bool isNumeric(dessser::gen::raql_type::t const &);

bool isAWorker(dessser::gen::sync_key::t const &);

unsigned numColumns(dessser::gen::raql_type::t const &);

std::string const columnName(dessser::gen::raql_type::t const &, size_t);

// Returns a pointer into the passed type (or nullptr):
std::shared_ptr<dessser::gen::raql_type::t const> columnType(
  dessser::gen::raql_type::t const &, size_t);

// Returns a pointer into the passed value (or nullptr):
std::shared_ptr<dessser::gen::raql_value::t const> columnValue(
  dessser::gen::raql_value::t const &, size_t);

// Returns the float representation of that value
std::optional<double> toDouble(dessser::gen::raql_value::t const &);

/* Returns the string representation of that value (the optional key gives a hint about
 * the type of conversion desired) */
QString raqlValToQString(
  dessser::gen::raql_value::t const &,
  std::shared_ptr<dessser::gen::sync_key::t const> = nullptr);

QString raqlTypeToQString(dessser::gen::raql_type::t const &);

QString raqlExprToQString(dessser::gen::raql_expr::t const &);

QString syncValToQString(
  dessser::gen::sync_value::t const &,
  std::shared_ptr<dessser::gen::sync_key::t const> = nullptr);

QString syncKeyToQString(dessser::gen::sync_key::t const &);

/* Debug printer for some dessser generated types: */

QDebug operator<<(QDebug, dessser::gen::sync_client_cmd::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_client_msg::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_server_msg::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_msg::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_socket::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_key::t const &);
QDebug operator<<(QDebug, dessser::gen::sync_value::t const &);
QDebug operator<<(QDebug, dessser::gen::raql_value::t const &);
QDebug operator<<(QDebug, dessser::gen::raql_type::t const &);
QDebug operator<<(QDebug, dessser::gen::raql_type::base const &);

#endif
