AC_INIT([sugar-runner], [0.2], [dwnarvaez@gmail.com])
AM_INIT_AUTOMAKE([foreign dist-xz no-dist-gzip])
AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
AC_PROG_LIBTOOL

PKG_CHECK_MODULES(SUGAR_RUNNER, x11 xrandr glib-2.0)

GOBJECT_INTROSPECTION_REQUIRE([1.34.0])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
