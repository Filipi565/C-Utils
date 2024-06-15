#include <path.h>
#include <bool.h>

#ifdef __cplusplus
extern "C" {
#endif
char* __path_getcwd();
int __path_chdir(const char*);
int __path_rmdir(const char*);
int __path_mkdir(const char*);
bool __path_exists(const char*);
char* __path_dirname(const char*);
char* __path_join(const int, char*, ...);
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
    p.dirname = __path_dirname;

    #ifdef _WIN32
    p.sep = "\\";
    p.altsep = "/";
    #else
    p.sep = "/";
    p.altsep = "\\";
    #endif

    return p;
}