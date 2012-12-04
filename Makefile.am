bin_in_files = sugar-runner.in
bin_SCRIPTS = $(bin_in_files:.in=)

dist_helpersdir = $(libexecdir)/$(PACKAGE)
dist_helpers_SCRIPTS = tweak-xwrapper \
                       xephyr-window

helpersdir = $(libexecdir)/$(PACKAGE)

helpers_scripts_in_files = xinitrc.in
helpers_SCRIPTS = $(helpers_scripts_in_files:.in=)

sugar-runner: sugar-runner.in
	@sed -e "s|\@helpersdir\@|$(helpersdir)|" $< > $@

xinitrc: xinitrc.in
	@sed -e "s|\@helpersdir\@|$(helpersdir)|" $< > $@

CLEANFILES = $(bin_SCRIPTS) $(helpers_SCRIPTS)
EXTRA_DIST = $(bin_in_files) $(helpers_scripts_in_files)

lib_LTLIBRARIES = libsugarrunner.la

libsugarrunner_la_CFLAGS = $(SUGAR_RUNNER_CFLAGS)
libsugarrunner_la_LIBADD = $(SUGAR_RUNNER_LIBS)

libsugarrunner_la_SOURCES = \
    sugar-runner.c \
    sugar-runner.h \
    sugar-runner-window.c \
    sugar-runner-window.h

-include $(INTROSPECTION_MAKEFILE)

INTROSPECTION_GIRS = SugarRunner-1.0.gir
INTROSPECTION_SCANNER_ARGS = \
    --identifier-prefix=SugarRunner \
    --symbol-prefix=sugar_runner

SugarRunner_1_0_gir_LIBS = libsugarrunner.la
SugarRunner_1_0_gir_FILES = $(libsugarrunner_la_SOURCES)
SugarRunner_1_0_gir_PACKAGES = glib-2.0
SugarRunner_1_0_gir_EXPORT_PACKAGES = SugaRunner-1.0

girdir = $(datadir)/gir-1.0
gir_DATA = SugarRunner-1.0.gir

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = SugarRunner-1.0.typelib

CLEANFILES += $(gir_DATA) $(typelib_DATA)
