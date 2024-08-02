#include "pch.h"

#ifdef __cplusplus
extern "C" {
#endif
int __path_chdir(const char*);
int __path_rmdir(const char*);
int __path_mkdir(const char*);
bool __path_exists(const char*);
int __path_getcwd(char*, size_t);
int __path_join(char*, size_t, ...);
#ifdef __cplusplus
}
#endif

__path __new_path()
{
    __path p;
    p.chdir = __path_chdir;
    p.getcwd = __path_getcwd;
    p.mkdir = __path_mkdir;
    p.rmdir = __path_rmdir;
    p.exists = __path_exists;
    p.join = __path_join;

    #ifdef _WIN32
    p.sep = "\\";
    p.altsep = "/";
    #else
    p.sep = "/";
    p.altsep = "/";
    #endif

    return p;
}