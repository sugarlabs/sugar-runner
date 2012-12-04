#include <X11/extensions/Xrandr.h>

#include "sugar-runner.h"

char *
sugar_runner_find_free_display(void)
{
    int port;

    for (port = 99; port < 1000; port++) {
        char *display_name = g_strdup_printf(":%d", port);

        Display *dpy = XOpenDisplay(display_name);

        if (!dpy) {
            return display_name;
        } else {
            g_free(display_name);
            XCloseDisplay(dpy);
        }
    }

    return NULL;
}

/**
 * sugar_runner_list_outputs:
 *
 * Return value: (array zero-terminated=1) (transfer full):
 **/
char **
sugar_runner_list_outputs(void)
{
    char **outputs;
    GSList *outputs_list = NULL, *l = NULL;
    Display *dpy = XOpenDisplay(NULL);
    XRRScreenResources *rr;
    XRROutputInfo *output;
    int i;

    XSynchronize(dpy, 1);

    rr = XRRGetScreenResources(dpy, DefaultRootWindow(dpy));

    if (rr != NULL) {
        for (i = 0; i < rr->noutput; i++) {
            output = XRRGetOutputInfo(dpy, rr, rr->outputs[i]);

            if (output->connection == RR_Connected) {
                outputs_list = g_slist_append(outputs_list, output->name);
            }

            XRRFreeOutputInfo(output);
        }
    }

    XRRFreeScreenResources(rr);

    XSync(dpy, 1);
    XCloseDisplay(dpy);

    outputs = g_new0(gchar *, g_slist_length(outputs_list) + 1);
    for (l = outputs_list, i = 0; l != NULL; l = l->next) {
        outputs[i++] = g_strdup(l->data);
    }
    outputs[i] = NULL;

    return outputs;
}
