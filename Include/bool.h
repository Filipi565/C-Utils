#if (defined(__STDC__) && __STDC_VERSION__ >= 199901L) || (defined(_MSC_VER) && _MSC_VER >= 1800)
#include <stdbool.h>
#elif !defined(__cplusplus) && !defined(bool)

typedef unsigned char bool;
#define bool bool

const bool false = '\0';
#define false false

const bool true = !false;
#define true true

#endif
