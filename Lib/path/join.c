#include "pch.h"

#include <stdio.h>

#ifdef _WIN32
#define strcpy1(dst, size, src) (strcpy_s(dst, size, src))
#define strcat1(dst, size, src) (strcat_s(dst, size, src))
#else
#define strcpy1(dst, size, src) (strncpy(dst, src, size))
#define strcat1(dst, size, src) (strncat(dst, src, size))
#endif

bool _string_startswith(const char* __string, const char* __value)
{
    int value_length = strlen(__value);
    int string_length = strlen(__string);
    if (value_length == 0){ // the __value is ""
        return true;
    }

    if (string_length < value_length){
        return false;
    }

    for (int i = 0; i < value_length; i++){
        if (__string[i] != __value[i]){
            return false;
        }
    }

    return true;
}

char* _string_reverse(const char* __string)
{
    int string_length = strlen(__string);
    char* result = (char*)malloc(string_length+1);

    int i1 = 0;
    int i2 = string_length-1;

    while (i2 >= 0){
        result[i1] = __string[i2];
        i1++;
        i2--;
    }
    result[string_length] = '\0'; // the end of the string

    return result;
}

bool _string_endswith(const char* __string, const char* __value)
{
    char* r1 = _string_reverse(__string);
    char* r2 = _string_reverse(__value);

    bool result = _string_startswith(r1, r2);
    
    free(r1);
    free(r2);
    return result;
}

char* __path_join_verify_path(const char* _Path)
{
    if (!(_string_endswith(_Path, path.sep) || _string_endswith(_Path, path.altsep))){
        size_t lenght = strlen(_Path)+2; // +2 to the path.sep and the null char
        
        char* _New = (char*)malloc(lenght);
        strcpy1(_New, lenght, _Path);
        strcat1(_New, lenght, path.sep);
        return _New;
    } else {
        char* _New = (char*)malloc(strlen(_Path)+1);
        strcpy1(_New, strlen(_Path)+1, _Path);
        return _New;
    }
}

char* __path_join_real_arg(const char* _Arg)
{
    char* _New = (char*)malloc(strlen(_Arg)+1);
    strcpy1(_New, strlen(_Arg)+1, _Arg);
    if (_string_endswith(_Arg, path.sep) || _string_endswith(_Arg, path.altsep)){
        _New[strlen(_Arg)] = '\0';
    }

    return _New;
}

int __path_join(char* _Buffer, size_t _SizeInBytes, ...)
{
    va_list args;
    va_start(args, _SizeInBytes);

    char* _First;
    char* _Path;
    char* arg;
    size_t lenght;

    _First = va_arg(args, char*);

    if (_First == NULL){
        return 1;
    }

    _First = __path_join_verify_path(_First);

    lenght = strlen(_First)+1;

    while (true){
        arg = va_arg(args, char*);
        if (arg == NULL){
            break;
        }

        lenght += strlen(arg);
    }

    va_end(args);

    _Path = (char*)malloc(lenght);
    strcpy1(_Path, lenght, _First);
    free(_First);

    va_start(args, _SizeInBytes);

    va_arg(args, char*); // remove the fist element that we already have

    while (true){
        arg = va_arg(args, char*);
        if (arg == NULL){
            break;
        }

        arg = __path_join_real_arg(arg);

        strcat1(_Path, lenght, arg);
        strcat1(_Path, lenght, path.sep);

        free(arg);
    }

    va_end(args);

    _Path[lenght] = '\0'; // remove the path.sep char

    strcpy1(_Buffer, _SizeInBytes, _Path);

    free(_Path);

    return 0;
}