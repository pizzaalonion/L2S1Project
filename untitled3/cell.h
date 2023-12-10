#ifndef UNTITLED3_CELL_H
#define UNTITLED3_CELL_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_d_cell
{
    int value;
    struct s_d_cell** next;
    int levels;
} t_d_cell;

t_d_cell* createCell(int value, int levels);
void printCell(t_d_cell* cell);

#endif //UNTITLED3_CELL_H
