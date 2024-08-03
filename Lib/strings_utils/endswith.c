#include "pch.h"

bool string_endswith(const char* __string, const char* __value)
{
    size_t lenght1, lenght2;
    char* r1;
    char* r2;
    bool result;

    lenght1 = strlen(__string)+1;
    lenght2 = strlen(__value)+1;

    r1 = (char*)malloc(lenght1*sizeof(char));
    r2 = (char*)malloc(lenght2*sizeof(char));

    if (r1 == NULL || r2 == NULL){
        return -1;
    }

    string_reverse(r1, lenght1, __string);
    string_reverse(r2, lenght2, __value);

    result = string_startswith(r1, r2);

    free(r1);
    free(r2);

    return result;
}
