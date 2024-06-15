#ifndef _STRINGS_UTILS_H
#define _STRINGS_UTILS_H

#include <string.h>
#include <bool.h>

bool string_startswith(const char*, const char*);
bool string_endswith(const char*, const char*);
char* string_reverse(const char*);

#endif