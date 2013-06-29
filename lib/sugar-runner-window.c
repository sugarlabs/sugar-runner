/*
 * Copyright (C) 2013, Daniel Narvaez
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <X11/Xlib.h>
#include <X11/Xatom.h>

#include "sugar-runner-window.h"

static Display *display = NULL;
static Window window = 0;
static Atom wm_delete_window;
static gboolean is_fullscreen = FALSE;

void
sugar_runner_window_create(int width, int height, gboolean fullscreen)
{
    Window root_window;
    const char *title = "Sugar Runner";

    if (display == NULL) {
        display = XOpenDisplay(NULL);
    }

    root_window = RootWindow(display, 0);

    window = XCreateSimpleWindow(display, root_window, 0, 0,
                                 width, height, 0, 0, 0);

    XSelectInput (display, window, StructureNotifyMask);

    if (fullscreen) {
        Atom atom;

        atom = XInternAtom(display, "_NET_WM_STATE_FULLSCREEN", True);
        XChangeProperty(display, window,
                        XInternAtom(display, "_NET_WM_STATE", True),
                        XA_ATOM, 32, PropModeReplace,
                        (unsigned char *)&atom, 1);
    }

    XChangeProperty (display, window,
		     XInternAtom(display, "_NET_WM_NAME", True),
		     XInternAtom(display, "UTF8_STRING", True), 8,
		     PropModeReplace, (unsigned char *)title, strlen(title));

    XMapWindow(display, window);

    wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wm_delete_window, 1);
}

gboolean
sugar_runner_window_wait(void)
{
    XEvent event;

    XNextEvent(display, &event);

    if (event.type == ConfigureNotify) {
        XConfigureEvent configure_event = event.xconfigure;
        is_fullscreen = (DisplayWidth(display, 0) == configure_event.width &&
                         DisplayHeight(display, 0) == configure_event.height);
    }

    return TRUE;
}

gboolean
sugar_runner_window_is_fullscreen(void)
{
    return is_fullscreen;
}

unsigned long
sugar_runner_window_get_xid(void)
{
    return window;
}
