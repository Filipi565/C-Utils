/*
some systems does not come with stdbool.h,
so this file is necessary
*/

#ifndef _BOOL_H
#define _BOOL_H

#ifndef __cplusplus

#ifndef bool
typedef unsigned char bool;
#define bool bool
#endif

#ifndef false
const char false = '\0';
#define false false
#endif

#ifndef true
const char true = !false;
#define true true
#endif

#ifndef _STDBOOL_H
#define _STDBOOL_H
#endif

/* Signal that all the definitions are present.  */
#ifndef __bool_true_false_are_defined
#define __bool_true_false_are_defined 1
#endif

#endif /* __cplusplus */

#endif /*_BOOL_H*/
