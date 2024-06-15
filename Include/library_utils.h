#ifndef _LIBRARY_UTILS_H
#define _LIBRARY_UTILS_H

#ifdef _WIN32
 #include <windows.h>
 typedef HINSTANCE Library;
 
 FARPROC get_function(Library, char []);
 
 #else
 typedef void* Library;
 
 void* get_function(Library, char [])
 
#endif // _WIN32

Library load_library(char []);
int unload_library(Library);

#endif // _LIBRARY_UTILS_H