/*
some systems does not come with stdbool.h,
so this file is necessary
*/

#ifndef _BOOL_H
#define _BOOL_H

#ifndef __cplusplus
#ifndef bool
typedef int bool;
#define bool bool
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef _STDBOOL_H
#define _STDBOOL_H
#endif

/* Signal that all the definitions are present.  */
#ifndef __bool_true_false_are_defined
#define __bool_true_false_are_defined 1
#endif
#endif /*__cplusplus*/

#endif /*_BOOL_H*/