//
// Created by benma on 24/10/2023.
//

#ifndef L2S1PROJECT_CELL_H
#define L2S1PROJECT_CELL_H

typedef struct s_cell {
    int value;
    int nb_levels;
    s_cell* list;
} t_cell;

t_cell* create_cell(int value, int levels);


#endif //L2S1PROJECT_CELL_H
