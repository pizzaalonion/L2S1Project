#include "searchcontact.h"

t_contact* classicSearchContact(t_contact* contact, char* name, int level) {

    t_contact* prec = contact;
    int flag = 0;
    while ((flag == 0) && (contact->next[level] != NULL) &&  (contact->string_name <= name)) {

        if (contact->string_name == name) {
            flag = 1;
        }
        else {
            prec = contact;
            contact = contact->next[level];
        }
    }

    if (contact->string_name <= name) {
        return contact;
    }else {
        return prec;
    }
}



int dicoSearchContact(t_d_listContact * list, char* name) {
    if (list->heads_list[0] == NULL) {
        return 0;
    }
    int i = list->levels-1;
    t_contact * temp = list->heads_list[i];

    while (i >= 0) {
        printf("inwhile");

        temp = classicSearchContact(temp,name,i);

        if (strcmp(temp->string_name, name) == 0) {
            return 1;
        }


        i -= 1;
        if (strcmp(temp->string_name, name) == -1) {
            temp = list->heads_list[i];
        }
    }

    return 0;


}



