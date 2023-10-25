#include "lists.h"


t_list* create_list(int max_levels) {
    t_list* list;
    list->max_level = max_levels;
    list->heads = (t_cell**)malloc(list->max_level*sizeof(t_cell*));
}

void insert_head(t_cell* cell, t_list* list) {
    for (int i = 0; i< cell->nb_levels; i++) {
        list->heads[i] = cell;

    }
}
