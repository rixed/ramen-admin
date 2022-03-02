AC_INIT(rmadmin, 7.0.0)

AC_PROG_CXX
AC_CONFIG_HEADERS([src/config.h])

AC_PATH_PROG(QMAKE, qmake)
AS_IF([test -z "$QMAKE"], [AC_MSG_ERROR([Cannot find qmake.])])

AC_PATH_PROG(CONVERT, convert)
AS_IF([test -z "$CONVERT"], [AC_MSG_ERROR([Cannot find convert.])])

AC_LANG([C++])
CXXFLAGS="$CFLAGS -std=c++17"

AC_ARG_WITH([ramen],
  AC_HELP_STRING([--with-ramen], [Where to find ramen source *.type files]),
  [],
  [with_ramen=../ramen])
AC_SUBST(RAMEN_SRC, [$with_ramen])

AC_ARG_WITH([dessser],
  AC_HELP_STRING([--with-dessser], [Where to find dessser include files]),
  [],
  [with_dessser=../dessser/src])
AC_SUBST(DESSSER_INC, [$(realpath $with_dessser)])

default_dessserc=../dessser/src/dessserc
if ocamlfind query dessser >/dev/null 2>&1 ; then
  default_dessserc=$(ocamlfind query dessser)/dessserc
fi

AC_ARG_WITH([dessserc],
  AC_HELP_STRING([--with-dessserc], [Where to find the dessserc code generator]),
  [],
  [with_dessserc=$default_dessserc])
AC_SUBST(DESSSERC, [$with_dessserc])

AC_CONFIG_FILES([
  Makefile
  src/rmadmin.pro
  src/rmadmin.nsi
  tests/tests.pro
])
AC_OUTPUT
