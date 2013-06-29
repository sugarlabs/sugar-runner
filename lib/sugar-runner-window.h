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
