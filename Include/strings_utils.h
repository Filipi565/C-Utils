#ifndef _STRINGS_UTILS_H
#define _STRINGS_UTILS_H

#include <string.h>
#include <bool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool string_startswith(const char*, const char*);
bool string_endswith(const char*, const char*);
char* string_reverse(const char*);

#ifdef __cplusplus
}
#endif

#endif