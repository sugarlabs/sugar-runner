/*
 * Copyright (C) 2013, Daniel Narvaez
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with the Control Center; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __SUGAR_RUNNER_H__
#define __SUGAR_RUNNER_H__

#include <glib.h>

G_BEGIN_DECLS

char           *sugar_runner_find_free_display (void);
char          **sugar_runner_list_outputs      (void);

G_END_DECLS

#endif /* __SUGAR_WINDOW_H__ */
