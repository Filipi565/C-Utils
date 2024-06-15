#include <stdlib.h>
#include <string.h>

char* string_reverse(const char* __string)
{
    int string_length = strlen(__string);

    char* result = (char*)malloc(string_lenght+1);

    int i1 = 0;
    int i2 = string_length-1;

    while (i2 >= 0){
        temp_result[i1] = __string[i2];
        i1++;
        i2--;
    }
    result[string_length] = '\0'; // the end of the string

    return result;
}
