#ifndef L2S1PROJECT_LISTS_H
#define L2S1PROJECT_LISTS_H
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list {
    int max_level;
    t_cell** heads = NULL;
}t_list;

t_list* create_list(int max_levels);

void insert_head(t_cell* cell, t_list* list);

#endif //L2S1PROJECT_LISTS_H
