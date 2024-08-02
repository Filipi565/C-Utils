#ifndef _COLOR_H_
#define _COLOR_H_

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

char* __color(int);

void setcolor(const char*);

#ifdef __cplusplus
}
#endif

#define RESET __color(0)
#define RED __color(1)
#define GREEN __color(2)
#define YELLOW __color(3)
#define BLUE __color(4)
#define CYAN __color(5)

#endif
