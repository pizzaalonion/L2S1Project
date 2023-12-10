#include "cell.h"

t_d_cell* createCell(int value, int levels) {
    /**
     * @brief creates a cell
     * @param value : value of the cell
     * @param level : number of levels of the cell
     * @return new cell of type pointer to cell
     */
    //dynamic allocation of the memory
    t_d_cell *new_cell = (t_d_cell*)malloc(sizeof(t_d_cell));

    //attribution of the value and levels argument to the cell
    new_cell->value = value;
    new_cell->levels = levels;

    // allocation of an array of pointer to cells to the attribute "next"
    new_cell->next = (t_d_cell**)malloc(levels*sizeof(t_d_cell*));

    // filling the so said array with NULL values, to avoid segmentation fault.
    for (int i = 0; i<=levels; i++) {
        new_cell->next[i] = NULL;
    }
    return new_cell;
}


