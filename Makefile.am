dist_bin_SCRIPTS = run-with-keyring

bin_in_files = sugar-runner.in
bin_SCRIPTS = $(bin_in_files:.in=)

dist_helpersdir = $(libexecdir)/$(PACKAGE)
dist_helpers_SCRIPTS = get-screen-dpi \
                       run-with-keyring

helpersdir = $(libexecdir)/$(PACKAGE)

helpers_scripts_in_files = xinitrc.in
helpers_SCRIPTS = $(helpers_scripts_in_files:.in=)

helpers_PROGRAMS = find-free-display \
                   list-outputs \
                   xephyr-window

sugar-runner: sugar-runner.in
	@sed -e "s|\@helpersdir\@|$(helpersdir)|" $< > $@

xinitrc: xinitrc.in
	@sed -e "s|\@helpersdir\@|$(helpersdir)|" $< > $@

find_free_display_SOURCE = find-free-display.c
find_free_display_LDADD = $(X11_LIBS)

list_outputs_SOURCE = list-outputs.c
list_outputs_LDADD = $(X11_LIBS) $(XRANDR_LIBS)

xephyr_window_SOURCE = xephyr-window.c
xephyr_window_LDADD = $(X11_LIBS) $(XRANDR_LIBS)

CLEANFILES = $(bin_SCRIPTS) $(helpers_SCRIPTS)
EXTRA_DIST = $(bin_in_files) $(helpers_scripts_in_files)
