#include "pch.h"

bool string_startswith(const char* __string, const char* __value)
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
        char s_char = __string[i];
        char v_char = __value[i];
        if (s_char != v_char){
            return false;
        }
    }

    return true;
}