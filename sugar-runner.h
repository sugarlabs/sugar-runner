#ifndef __SUGAR_RUNNER_H__
#define __SUGAR_RUNNER_H__

#include <glib.h>

G_BEGIN_DECLS

char           *sugar_runner_find_free_display (void);
char          **sugar_runner_list_outputs      (void);

G_END_DECLS

#endif /* __SUGAR_WINDOW_H__ */
