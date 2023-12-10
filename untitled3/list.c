#include "list.h"

t_d_list* createList(int levels) {
    /**
     * @brief creates a new list
     * @param levels : the maximum nb of levels we want
     * @return a pointer to the list
     */
     //dynamic allocation of the memory for the list
    t_d_list *list_heads = (t_d_list*)malloc(sizeof(t_d_list));
    //allocation of the memory for the "heads_list" field , which is an array of SLL
    list_heads->heads_list = (t_d_cell**)malloc(levels*sizeof(t_d_cell*));
    list_heads->levels = levels;
    // filling the so said array with NULL values, to avoid segmentation fault.
    for (int i = 0; i < levels; i++ ) {
        list_heads->heads_list[i] = NULL;
    }
    return list_heads;
}

void addHeadCell(t_d_list* list,t_d_cell* cell) {
    /**
     * @brief adds a cell at the head of a level
     * @param list : the so said list; cell : the so said cell
     * @return none
     */

    //necessary conditions for the correct initiation of the loop
    if (cell->levels <= list->levels && cell != NULL && list != NULL) {
        //looping through all the levels indicated by the cell
        for(int i = 0; i<cell->levels   ;i++) {
            //in case the list is empty
            if (list->heads_list[i] == NULL) {
                list->heads_list[i] = cell;
            }
            // in case the list is not : push the new cell in
            else {
            cell->next[i] = list->heads_list[i];
            list->heads_list[i] = cell;
            }
        }
    }
}

void printLevel(t_d_list* list, int level) {
    /**
     * @brief prints a level from a list
     * @param list : the so said list; level : the so said level
     * @return none
     */
    // verification of the existance of the level
    if (level <= list->levels) {
        //print the header
        printf("{head : %d}", level - 1);
        // verifying that the level is not empty (level-1 for the index of the level)
        if (list->heads_list[level - 1] != NULL) {
            // initialisation of our iteration cell
            t_d_cell *temp = list->heads_list[level - 1];
            // setting the while loop
            while (temp != NULL) {
                // print command
                printf("-->[%d|@]--->", temp->value);
                //iteration of the variable
                temp = temp->next[level - 1];
            }
            // EOL print
            printf("NULL");
        }
    }
    else {

    }
}


void printAll(t_d_list* list) {
    for(int i = 1; i<=list->levels;i++) {
        printf("{head : %d}", i-1);
        if (list->heads_list[i - 1] != NULL) {
            t_d_cell *temp = list->heads_list[i - 1];
            while (temp != NULL) {

                    printf("-->[%d|@]---", temp->value);
                    temp = temp->next[i - 1];

            }

            printf("---NULL");
        }

        printf("\n");
    }
}

void addCell(t_d_list* list,t_d_cell* cell) {
    if (cell->levels <= list->levels && cell != NULL && list != NULL) {


            if (list->heads_list[0] == NULL) {
                for (int j = 0; j <= cell->levels - 1; j++) {
                    list->heads_list[j] = cell;
                }
            } else {
                t_d_cell *temp = list->heads_list[0];
                t_d_cell* prec = list->heads_list[0];


                while ( (temp->next[0]!= NULL) &&(temp->value >= cell->value) ) {
                    prec = temp;
                    temp = temp->next[0];
                }

                for (int i = 0; i <= cell->levels - 1; i++) {

                        if (temp->value < cell->value) {
                            if(temp==list->heads_list[i]) {
                                list->heads_list[i] = cell;
                                cell->next[i] = temp;
                            }else {
                                cell->next[i] = prec->next[i];
                                prec->next[i] = cell;
                            }
                        }else {
                            cell->next[i] = temp->next[i];
                            temp->next[i] = cell;
                        }
                    }

                }

            }

    }

void printAllClear(t_d_list* list){

    for(int i=1;i<list->levels+1;i++){

        printf("{head : %d}",i);

        if (list->heads_list[0] != NULL){

            t_d_cell* temp  = list->heads_list[0];

            while(temp != NULL){
                if(i <= temp->levels) {

                    printf("--->[%d|@-]",temp->value);
                }
                else {

                    if (temp->value <= 9) {
                    printf("----------");
                }else if (temp->value <= 99){
                        printf("-----------");
                    } else {
                        printf("-------------");

                    }
                }
                temp = temp->next[0];
            }
        }
        printf("--> NULL\n");

    }
}

