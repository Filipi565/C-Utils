#include <strings_utils.h>
#include <stdlib.h>

bool string_endswith(const char* __string, const char* __value)
{
    char* r1 = string_reverse(__string);
    char* r2 = string_reverse(__value);
    bool result = string_startswith(r1, r2);
    
    free(r1);
    free(r2);
    return result;
}