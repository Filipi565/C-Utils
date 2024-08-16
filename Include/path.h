#ifndef _PATH_H_
#define _PATH_H_

#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stddef.h>
#include "bool.h"

typedef struct path
{
	const char* sep;
	const char* altsep;

    int (*chdir) (const char*);
    int (*mkdir) (const char*);
    int (*rmdir) (const char*);
    bool (*exists) (const char*);
    int (*getcwd) (char* _Buffer, size_t _SizeInBytes);
    int (*join) (char* _Buffer, size_t _SizeInBytes, ...);
} __path;

__path __new_path();

#ifdef __cplusplus
}
#endif

#define path __new_path()

#endif
