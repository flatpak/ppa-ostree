/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2015 Colin Walters <walters@verbum.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the licence or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#pragma once

#include "ostree-deployment.h"

G_BEGIN_DECLS

struct _OstreeDeployment
{
  GObject       parent_instance;

  int index;  /* Global offset */
  char *osname;  /* osname */
  char *csum;  /* OSTree checksum of tree */
  int deployserial;  /* How many times this particular csum appears in deployment list */
  char *bootcsum;  /* Checksum of kernel+initramfs */
  int bootserial; /* An integer assigned to this tree per its ${bootcsum} */
  OstreeBootconfigParser *bootconfig; /* Bootloader configuration */
  GKeyFile *origin; /* How to construct an upgraded version of this tree */
  OstreeDeploymentUnlockedState unlocked;  /* The unlocked state */
};

void _ostree_deployment_set_bootcsum (OstreeDeployment *self, const char *bootcsum);

G_END_DECLS
