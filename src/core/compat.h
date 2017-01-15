/**
 * Copyright (C) 2017 Quenza Inc.
 * All Rights Reserved
 *
 * This file is part of the Ayahesa core.
 *
 * Content can not be copied and/or distributed without the express
 * permission of the author.
 */

#ifndef _AYAHESA_COMPAT_H_
#define _AYAHESA_COMPAT_H_

#include <string.h>

#ifdef NEED_STRDUP

char *ayahesa_strdup(const char *src);

#endif // NEED_STRDUP

char *strncpy0(char* dest, const char* src, size_t size);
char *strtolower(char *str);
char *rstrip(char* s);
char *lskip(char *s);

#endif // _AYAHESA_COMPAT_H_
