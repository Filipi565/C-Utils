#ifndef _STRINGS_UTILS_H_
#define _STRINGS_UTILS_H_

#include <string.h>
#include <bool.h>

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
Reverses the String:
Ex.:

char string[9] = "MyString";
char reversed[9];
string_reverse(reversed, sizeof(reversed));
printf("%s\n", reversed);

output: gnirtSyM
*/
int string_reverse(char* _Buffer, size_t _SizeInBytes, const char* _Source);

/*
See if the string starts with an other string
Ex.: 

char string[] = "MyString";
bool result1 = string_startswith(string, "My"); // true
bool result2 = string_startswith(string, "foo"); // false
*/
bool string_startswith(const char*, const char*);

/*
See if the string starts with an other string
Ex.: 

char string[] = "MyString";
bool result1 = string_endswith(string, "ing"); // true
bool result2 = string_endswith(string, "foo"); // false
*/
bool string_endswith(const char*, const char*);

#ifdef __cplusplus
}
#endif

#endif