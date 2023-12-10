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


