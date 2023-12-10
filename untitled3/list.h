

#ifndef UNTITLED3_LIST_H
#define UNTITLED3_LIST_H
#include "cell.h"
#include "contact.h"
typedef struct s_d_list
{
    t_d_cell** heads_list;
    int levels;
} t_d_list;

t_d_list* createList(int levels);
void addHeadCell(t_d_list* list,t_d_cell* cell);
void printLevel(t_d_list* list, int level);
void printAll(t_d_list* list);
void printAllClear(t_d_list* list);
void addCell(t_d_list* list,t_d_cell* cell);

#endif //UNTITLED3_LIST_H
