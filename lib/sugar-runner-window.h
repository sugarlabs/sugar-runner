#ifndef __SUGAR_RUNNER_WINDOW_H__
#define __SUGAR_RUNNER_WINDOW_H__

#include <glib.h>

G_BEGIN_DECLS

void            sugar_runner_window_create        (int width,
                                                   int height,
                                                   gboolean fullscreen);
gboolean        sugar_runner_window_wait          (void);
gboolean        sugar_runner_window_is_fullscreen (void);
unsigned long   sugar_runner_window_get_xid       (void);

G_END_DECLS

#endif /* __SUGAR_RUNNER_WINDOW_H__ */
