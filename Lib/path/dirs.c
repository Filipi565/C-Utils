#ifndef _WIN32
 #include <sys/types.h>
 #include <unistd.h>
#else
 #include <direct.h>
#endif

#include <sys/stat.h>

int __path_mkdir(const char* __path)
{
    int status;
    #ifndef _WIN32
        status = mkdir(__path, 0700);
    #else
        status = _mkdir(__path);
    #endif

    return status;
}

int __path_rmdir(const char* __path)
{
    int status;

    #ifndef _WIN32
        status = rmdir(__path);
    #else
        status = _rmdir(__path);
    #endif
    
    return status;
}