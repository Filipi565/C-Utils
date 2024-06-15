#include <library_utils.h>
#include <stdlib.h>
#include <stdio.h>
#include <color.h>
#include <bool.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifdef _WIN32
Library load_library(char _dll_path[])
{
    Library obj = LoadLibrary(_dll_path);

    if (obj == NULL) {
        setcolor(RED);
        fprintf(stderr, "Could no Load the Library: \"%s\"\n", _dll_path);
        setcolor(RESET);
        exit(1);
    }

    return obj;
}

FARPROC get_function(Library _obj, char _name[])
{
    FARPROC f = GetProcAddress(_obj, _name);

    if (f == NULL){
        setcolor(RED);
        fprintf(stderr, "Error on finding function: \"%s\"\n", _name);
        setcolor(RESET);
    }

    return f;
}

bool unload_library(Library _obj)
{
    return FreeLibrary(_obj);
}

#else

Library load_library(char _library_path[])
{
    Library obj = dlopen(_library_path, RTLD_LAZY);

    if (!obj){
        setcolor(RED);
        fprintf(stderr, "%s\n", dlerror());
        setcolor(RESET);
        exit(1);
    }

    dlerror();

    return obj;
}

void* get_function(Library _obj, char _name[])
{
    void* f = dlsym(_obj, _name);

    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        setcolor(RED);
        fprintf(stderr, "Error on finding function: %s\n", dlsym_error);
        setcolor(RESET);
        dlclose(_obj);
        exit(1);
    }

    return f;
}

bool unload_library(Library _obj)
{
    dlclose(_obj);
}

#endif
