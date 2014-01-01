/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/*
 * hwp-hwpml-file.h
 *
 * Copyright (C) 2013 Hodong Kim <hodong@cogno.org>
 * 
 * This library is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __HWP_HWPML_FILE_H__
#define __HWP_HWPML_FILE_H__

#include <glib-object.h>

#include "hwp-file.h"
#include "hwp-models.h"

G_BEGIN_DECLS

#define HWP_TYPE_HWPML_FILE             (hwp_hwpml_file_get_type ())
#define HWP_HWPML_FILE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), HWP_TYPE_HWPML_FILE, HWPHWPMLFile))
#define HWP_HWPML_FILE_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), HWP_TYPE_HWPML_FILE, HWPHWPMLFileClass))
#define HWP_IS_HWPML_FILE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HWP_TYPE_HWPML_FILE))
#define HWP_IS_HWPML_FILE_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), HWP_TYPE_HWPML_FILE))
#define HWP_HWPML_FILE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), HWP_TYPE_HWPML_FILE, HWPHWPMLFileClass))

typedef struct _HWPHWPMLFile        HWPHWPMLFile;
typedef struct _HWPHWPMLFileClass   HWPHWPMLFileClass;
typedef struct _HWPHWPMLFilePrivate HWPHWPMLFilePrivate;

struct _HWPHWPMLFileClass {
  HWPFileClass parent_class;
};

struct _HWPHWPMLFile {
  HWPFile              parent_instance;
  HWPHWPMLFilePrivate *priv;

  HWPDocument         *document;
  HWPPage             *page;
};

struct _HWPHWPMLFilePrivate {
  gchar *uri;
};

GType         hwp_hwpml_file_get_type               (void) G_GNUC_CONST;
HWPHWPMLFile *hwp_hwpml_file_new_for_path           (const gchar *path,
                                                     GError     **error);
gchar        *hwp_hwpml_file_get_hwp_version_string (HWPFile     *file);
void          hwp_hwpml_file_get_hwp_version        (HWPFile     *file,
                                                     guint8      *major_version,
                                                     guint8      *minor_version,
                                                     guint8      *micro_version,
                                                     guint8      *extra_version);
HWPDocument  *hwp_hwpml_file_get_document           (HWPFile     *file,
                                                     GError     **error);

G_END_DECLS

#endif /* __HWP_HWPML_FILE_H__ */