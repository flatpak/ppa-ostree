/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2011 Colin Walters <walters@verbum.org>
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
 *
 * Author: Colin Walters <walters@verbum.org>
 */

#ifndef _OSTREE_DIFF
#define _OSTREE_DIFF

#include "ostree-core.h"
#include "ostree-types.h"

G_BEGIN_DECLS

typedef struct _OstreeDiffItem OstreeDiffItem;
struct _OstreeDiffItem
{
  volatile gint refcount;

  GFile *src;
  GFile *target;

  GFileInfo *src_info;
  GFileInfo *target_info;

  char *src_checksum;
  char *target_checksum;
};

OstreeDiffItem *ostree_diff_item_ref (OstreeDiffItem *diffitem);
void ostree_diff_item_unref (OstreeDiffItem *diffitem);

gboolean ostree_diff_dirs (GFile          *a,
                           GFile          *b,
                           GPtrArray      *modified,
                           GPtrArray      *removed,
                           GPtrArray      *added,
                           GCancellable   *cancellable,
                           GError        **error);

void ostree_diff_print (GFile          *base,
                        GPtrArray      *modified,
                        GPtrArray      *removed,
                        GPtrArray      *added);

G_END_DECLS

#endif /* _OSTREE_REPO */