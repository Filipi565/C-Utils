#ifndef _PATH_H
#define _PATH_H

#include <bool.h>

typedef struct __path
{
    const char* sep;
    const char* altsep;

    char* (*getcwd) ();
    int (*chdir) (const char*);
    int (*mkdir) (const char*);
    int (*rmdir) (const char*);
    bool (*exists) (const char*);
    char* (*dirname) (const char*);
    char* (*join) (const int, char*, ...);
} __path;

#ifdef __cplusplus
extern "C" {
#endif

__path __new_path();

#ifdef __cplusplus
}
#endif

#define path __new_path()

#endif