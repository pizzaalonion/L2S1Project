#include "sorting.h"
#include <time.h>

t_d_list*  create2nList(int n) {
    t_d_list* list = createList(n);
    int* list_int = (int*)malloc((pow(2,n)-1)*sizeof(int));
    int* list_levels = (int*)malloc((pow(2,n)-1)*sizeof(int));
    for (int i = 1; i < pow(2,n); i++) {
        list_int[i] = i;
        list_levels[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i % (int)(pow(2,j) + 0.2) == 0) {
                list_levels[i] += 1;
            }
        }

        t_d_cell* cell = createCell(list_int[i], list_levels[i]);

        addHeadCell(list, cell);
    }
    return list;

}

t_d_cell* classicSearch(t_d_cell* node, int value, int level) {


    t_d_cell* prec = node;
    int flag = 0;


    while ((flag == 0) && (node->next[level] != NULL) &&  (node->value >= value)) {

        if (node->value == value) {
            flag = 1;
        }
        else {
            prec = node;
            node = node->next[level];
        }
    }

    if (node->value >= value) {
        return node;
    }else {
        return prec;
    }
}


int dicoSearch(t_d_list* list, int value) {
    int i = list->levels-1;
    t_d_cell* temp = list->heads_list[i];
    while (i >= 0) {
        temp = classicSearch(temp,value,i);
        if (temp->value == value) {
            return 1;
        }


        i -= 1;
        if (temp->value < value ) {
            temp = list->heads_list[i];
        }
    }

    return 0;


}

