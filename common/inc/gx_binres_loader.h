/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** GUIX Component                                                        */
/**                                                                       */
/**   Binres Loader Management (Binres Loader)                            */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/**************************************************************************/
/*                                                                        */
/*  COMPONENT DEFINITION                                   RELEASE        */
/*                                                                        */
/*    gx_binres_loader.h                                  PORTABLE C      */
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file defines the GUIX binres loader component,                 */
/*    including all data types and external references.  It is assumed    */
/*    that gx_api.h and gx_port.h have already been included.             */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Kenneth Maxwell          Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/

#ifndef GX_BINRES_LOADER_H
#define GX_BINRES_LOADER_H

#define GX_BINRES_VERSION_ADD_STRING_LENGTH 50600

#ifdef GX_BINARY_RESOURCE_SUPPORT
typedef struct GX_BINRES_DATA_INFO_STRUCT
{
    GX_UBYTE *gx_binres_root_address;
    UINT      gx_binres_read_offset;
    GX_UBYTE *gx_binres_buffer;
    UINT      gx_binres_buffer_size;
    UINT      gx_binres_buffer_index;
} GX_BINRES_DATA_INFO;

/* Define utility component function prototypes.  */

UINT _gx_binres_language_count_get(GX_UBYTE *root_address, GX_VALUE *put_count);
UINT _gx_binres_language_info_load(GX_UBYTE *root_address, GX_LANGUAGE_HEADER *put_info);
#if defined(GX_ENABLE_DEPRECATED_STRING_API)
UINT _gx_binres_language_table_load(GX_UBYTE *root_address, GX_UBYTE ****returned_language_table);
#endif
UINT _gx_binres_language_table_load_ext(GX_UBYTE *root_address, GX_STRING ***returned_language_table);
UINT _gx_binres_theme_load(GX_UBYTE *root_address, INT theme_id, GX_THEME **returned_theme);
UINT _gx_binres_resource_header_load(GX_BINRES_DATA_INFO *info, GX_RESOURCE_HEADER *header);

UINT _gx_binres_string_header_load(GX_BINRES_DATA_INFO *info, GX_STRING_HEADER *header);
UINT _gx_binres_language_header_load(GX_BINRES_DATA_INFO *info, GX_LANGUAGE_HEADER *header);

/* Define error checking shells for API services.  These are only referenced by the
   application.  */

UINT _gxe_binres_language_count_get(GX_UBYTE *root_address, GX_VALUE *put_count);
UINT _gxe_binres_language_info_load(GX_UBYTE *root_address, GX_LANGUAGE_HEADER *put_info);
#if defined(GX_ENABLE_DEPRECATED_STRING_API)
UINT _gxe_binres_language_table_load(GX_UBYTE *root_address, GX_UBYTE ****returned_language_table);
#endif
UINT _gxe_binres_language_table_load_ext(GX_UBYTE *root_address, GX_STRING ***returned_language_table);
UINT _gxe_binres_theme_load(GX_UBYTE *root_address, INT theme_id, GX_THEME **returned_theme);

#endif

#endif

