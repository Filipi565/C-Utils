#include "pch.h"

int __path_getcwd(char* _Buffer, size_t _SizeInBytes)
{
    #ifdef _WIN32
        _getcwd(_Buffer, _SizeInBytes);
    #else
        getcwd(_Buffer, _SizeInBytes);
    #endif

    return 0;
}

int __path_chdir(const char* __path)
{
    int status;
    #ifdef _WIN32
        status = _chdir(__path);
    #else
        status = chdir(__path);
    #endif

    return status;
}