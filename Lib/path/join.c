#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <path.h>

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

char* __path_join_remove_seps(char* _Source)
{
    if (_string_startswith(_Source, path.sep) || _string_startswith(_Source, path.altsep)){
        char n[strlen(_Source)+1];
        char* n_r = _string_reverse(_Source);
        strcpy(n, n_r);
        free(n_r);

        n[strlen(_Source)-1] = '\0';

        char* r = (char*)malloc(strlen(n)+1);
        char* r_r = _string_reverse(n);
        strcpy(r, r_r);
        free(r_r);
        return r;
    } else {
        char* __new = (char*)malloc(strlen(_Source)+1);
        strcpy(__new, _Source);
        return __new;
    }
}



char* __path_join_verify_path(char* _Path)
{
    if (!_string_endswith(_Path, path.sep) || !_string_endswith(_Path, path.altsep)){
        char* __new = (char*)malloc(strlen(_Path)+2);
        strcpy(__new, _Path);
        strcat(__new, path.sep);
        return __new;
    } else {
        char* __new = (char*)malloc(strlen(_Path)+1);
        strcpy(__new, _Path);
        return __new;
    }
}

char* __path_join(const int _N_of_args, char* _Fist, ...)
{
    va_list args;
    va_start(args, _Fist);

    char* _Path = __path_join_verify_path(_Fist);

    for (int i = 0; i < _N_of_args-1; i++){
        char* n = __path_join_remove_seps(va_arg(args, char*));
        char* _n_path = (char*)malloc(strlen(_Path)+strlen(n)+1);
        strcpy(_n_path, _Path);
        strcat(_n_path, n);

        free(_Path);
        _Path = (char*)malloc(strlen(_n_path)+2);
        strcpy(_Path, _n_path);
        strcat(_Path, path.sep);
        free(_n_path);
        free(n);
    }

    va_end(args);

    _Path[strlen(_Path)-1] = '\0';

    return _Path;
}
