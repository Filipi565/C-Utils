#ifndef _COLOR_H
#define _COLOR_H

char* __color(int);

#define RESET __color(0)
#define RED __color(1)
#define GREEN __color(2)
#define YELLOW __color(3)
#define BLUE __color(4)
#define CYAN __color(5)

void setcolor(const char*);

#endif