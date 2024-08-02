#ifndef _PCH_H_
#define _PCH_H_

#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <path.h>

#ifndef _WIN32
#include <sys/types.h>
#include <unistd.h>
#else
#include <direct.h>
#endif

#endif // _PCH_H_