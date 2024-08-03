#include "pch.h"

#ifdef _WIN32
#define strcpy1(dst, size, src) (strcpy_s(dst, size, src))
#else
#define strcpy1(dst, size, src) (strncpy(dst, src, size))
#endif

int string_reverse(char* _Buffer, size_t _SizeInBytes, const char* _Source)
{
    int string_length = strlen(_Source);

    char* result = (char*)malloc((string_length+1)*sizeof(char));

    if (result == NULL){
        return 1;
    }

    int i1 = 0;
    int i2 = string_length-1;

    while (i2 >= 0){
        result[i1] = _Source[i2];
        i1++;
        i2--;
    }
    result[string_length] = '\0'; // the end of the string

    strcpy1(_Buffer, _SizeInBytes, result);

    free(result);

    return 0;
}
