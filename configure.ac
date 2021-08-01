AC_INIT(rmadmin, 7.0.0)

AC_PROG_CXX
AC_CONFIG_HEADERS([src/config.h])

AC_CHECK_LIB(zmq, zmq_bind)

AC_PATH_PROG(QMAKE, qmake)
AS_IF([test -z "$QMAKE"], [AC_MSG_ERROR([Cannot find qmake.])])

AC_PATH_PROG(CONVERT, convert)
AS_IF([test -z "$CONVERT"], [AC_MSG_ERROR([Cannot find convert.])])

AC_LANG([C++])
CXXFLAGS="$CFLAGS -std=c++17"

AC_CONFIG_FILES([
  Makefile
  src/rmadmin.pro
])
AC_OUTPUT
