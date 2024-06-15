#include <sys/stat.h>
#include <bool.h>

bool __path_exists(const char* __path)
{
    #ifndef _WIN32
        struct stat info;
    #else
        struct _stat info;
    #endif

    #ifndef _WIN32
        if (stat(__path, &info) == 0){
            return true;
        } else {
            return false;
        }
    #else
        if (_stat(__path, &info) == 0){
            return true;
        } else {
            return false;
        }
    #endif
}