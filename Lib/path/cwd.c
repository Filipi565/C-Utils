#ifndef _WIN32
 #include <sys/types.h>
 #include <unistd.h>
#else
 #include <direct.h>
#endif

#include <stdlib.h>
#include <string.h>

char* __path_getcwd()
{
    char* temp_buffer = (char*)malloc(4096);
    #ifdef _WIN32
        _getcwd(temp_buffer, 4096);
    #else
        getcwd(temp_buffer, 4096);
    #endif

    char* buffer = (char*)malloc(strlen(temp_buffer)+1);

    strcpy(buffer, temp_buffer);
    free(temp_buffer);

    return buffer;
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