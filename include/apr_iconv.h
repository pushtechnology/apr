/* ====================================================================
 * Copyright (c) 1999 The Apache Group.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 *
 * 4. The names "Apache Server" and "Apache Group" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache"
 *    nor may "Apache" appear in their names without prior written
 *    permission of the Apache Group.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 *
 * THIS SOFTWARE IS PROVIDED BY THE APACHE GROUP ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE APACHE GROUP OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Group.
 * For more information on the Apache Group and the Apache HTTP server
 * project, please see <http://www.apache.org/>.
 *
 */

#ifndef APR_ICONV_H
#define APR_ICONV_H

#include "apr_general.h"
#include "apr_time.h"
#include "apr_errno.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if !defined(ICONV_IMPLEMENT)

typedef void                         ap_iconv_t;

/* For platforms where we don't bother with translating between codepages
 */

#define ap_codepage_open(convset, topage, frompage, context) 
#define ap_translate_codepage(convset, inbuf, inbytes_left, outbuf, \
                              outbytes_left) outbuf=inbuf;
/* The purpose of ap_translate char is to translate one character
 * at a time.  This needs to be written carefully so that it works
 * with double-byte character sets. 
 */
#define ap_translate_char(convset, inchar, outchar) outchar = inchar
#define ap_codepage_close(convset)

#else

typedef struct ap_iconv_t            ap_iconv_t;

void ap_codepage_open(ap_iconv_t **convset, const char *topage, 
                         const char *frompage, ap_context_t *context); 
void ap_translate_codepage(ap_iconv_t *convset, const char *inbuf, 
                              ap_size_t inbytes_left, const char *outbuf,
                              ap_size_t outbytes_left);
/* The purpose of ap_translate char is to translate one character
 * at a time.  This needs to be written carefully so that it works
 * with double-byte character sets. 
 */
void ap_translate_char(ap_iconv_t *convset, char inchar, char outchar);
void ap_codepage_close(ap_iconv_t *convset)
#endif

#ifdef __cplusplus
}
#endif

#endif  /* ! APR_ICONV_H */


