#include "cell.h"

t_d_cell* createCell(int value, int levels) {
    t_d_cell* new_cell = (t_d_cell*)malloc(sizeof(t_d_cell));
    new_cell->value = value;
    new_cell->levels  = levels;
    new_cell->next = (t_d_cell**)malloc(levels*sizeof(t_d_cell*));
    for(int i = 0; i<new_cell->levels; i++) {
        new_cell->next[i] = NULL;
    }
    return new_cell;
}


