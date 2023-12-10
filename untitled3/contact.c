#include "contact.h"
#include <string.h>



t_d_listContact* createListContact() {

    //dynamic allocation of the memory for the list
    t_d_listContact *list_heads = (t_d_listContact*)malloc(sizeof(t_d_listContact));
    //allocation of the memory for the "heads_list" field , which is an array of SLL
    list_heads->levels = 4;
    list_heads->heads_list = (t_contact**)malloc(list_heads->levels*sizeof(t_contact*));

    // filling the so said array with NULL values, to avoid segmentation fault.
    for (int i = 0; i < list_heads->levels; i++ ) {
        list_heads->heads_list[i] = NULL;
    }
    return list_heads;
}



void fillList(t_d_listContact* list_contacts) {
    FILE *lastnames = fopen("C:\\Users\\benma\\CLionProjects\\untitled3\\noms2008nat_txt.txt", "r");
    FILE *firstnames = fopen("C:\\Users\\benma\\CLionProjects\\untitled3\\nat2021.csv", "r");
    char line[30];
    char **list_firstname = (char **) malloc(sizeof(line));
    char **list_name = (char **) malloc(sizeof(line));
    int i = 0;
    while (fgets(line, sizeof(line), firstnames) != NULL) {


        i++;
        if (i % 100 == 0) {
            char **temp = (char **) realloc(list_firstname, i * sizeof(line));
            list_firstname = temp;
            list_firstname[i / 100 + 1] = fgets(line, sizeof(line), firstnames);
        }
    }

    i = 0;
    while (fgets(line, sizeof(line), lastnames) != NULL) {
        i++;
        if (i % 1000 == 0) {
            char **temp = (char **) realloc(list_name, i * sizeof(line));
            list_name = temp;
        }
    }
    /*
    int j = 0;
    while(list_firstname[j] != NULL && list_name[j] != NULL) {
        createContact(getName(list_firstname[j],list_name[j]));
        j++;
        */
    for (int j = 0; j < 3; j++) {
        t_contact* contact_test = createContact(scanString());

        addContact( contact_test,list_contacts);


    }

}





int getHeight(t_contact* contact, t_d_listContact* list) {
    if (list->heads_list[0] == NULL) {
        return 4;
    }
    t_contact *temp = list->heads_list[0];
    t_contact *prec = list->heads_list[0];

    while (temp->next[0] != NULL && strcmp(contact->string_name, temp->string_name) > 0) {
        prec = temp;
        temp = temp->next[0];

    }

    if (strcmp(contact->string_name, temp->string_name) > 0) {
        return 4-charCount(contact->string_name,temp->string_name);

    }
    else {

        if (temp == list->heads_list[0]) {
            return 4;
        }
        else {
            return 4- charCount(prec->string_name,contact->string_name);
        }
    }

}

void addContact( t_contact* contact, t_d_listContact* list_contacts) {
    if (list_contacts->heads_list[0] == NULL) {

        addHeadContact(list_contacts, contact);
        return;
    }
    int levels = getHeight(contact,list_contacts);
    t_contact *temp;
    t_contact *prec;

    for (int line = 0; line < levels; line++) {
        // define temp and prec
        temp = list_contacts->heads_list[line];
        prec = list_contacts->heads_list[line];
        contact->next[line] = NULL;

        // while temp->next[i] exists and contact->string > temp->string;
        //printf("%s", temp->string_name);
        while (temp->next[line] != NULL && strcmp(contact->string_name, temp->string_name) > 0) {

            prec = temp;
            temp = temp->next[line];

        }

        //
        if (strcmp(contact->string_name, temp->string_name) >= 0) {
            contact->next[line] = temp->next[line];
            temp->next[line] = contact;
            //same
        } else {

            if (temp == list_contacts->heads_list[line]) {
                list_contacts->heads_list[line] = contact;

                if (line < 4-charCount(temp->string_name, contact->string_name)) {
                    contact->next[line] = temp;

                }else {

                    contact->next[line] = temp->next[line];

                }

            } else {
                prec->next[line] = contact;
                if (line < 4- charCount(contact->string_name, temp->string_name)) {
                    contact->next[line] = temp;
                }else {
                    contact->next[line] = temp->next[line];
                }
            }
        }
        contact->level = getHeight(contact, list_contacts)-1;
        if (contact->next[line] != NULL) {
            contact->next[line]->level = getHeight(contact->next[line], list_contacts)-1;
        }

    }


}

void addHeadContact(t_d_listContact *contactList, t_contact *contact){
    for (int i = 0; i < 4; i++) {
        contact->next[i] = NULL;
        contactList->heads_list[i] = contact;

    }
    contactList->heads_list[0]->level = 4;
}



t_contact* createContact(char* string) {
    t_contact* contact = (t_contact*)malloc(sizeof(t_contact));
    contact->string_name = string;

    contact->nb_rdv = 0;
    contact->list_rdv = (t_rdv**)malloc(sizeof(t_rdv*));
    contact->level = 4;
    contact->next = (t_contact**)malloc(4*sizeof(t_contact *));


    for (int i = 0; i<=3; i++) {

        contact->next[i] = NULL;

    }

    return contact;
}



char* getName(char* firstname, char* lastname) {

    char* string = (char*)malloc(60*sizeof(char));
    string = strcat(lastname,"_");
    string = strcat(string,firstname);
    char* temp = string;
    while (*string ) {

        if (*string >= 'A' && *string <= 'Z') {
            // Convert uppercase letter to lowercase by adding 32
            *string = *string + 32;
        }
        string++;
    }
    string = temp;

    return string;

}



char* scanString() {
    printf("Enter the complete name of the patient:");
    char* firstname = (char*)malloc(30*sizeof(char));
    scanf("%s", firstname);

    char* lastname = (char*)malloc(30*sizeof(char));
    scanf("%s",lastname);
    char* string = (char*)malloc(60*sizeof(char));
    string = strcat(lastname,"_");
    string = strcat(string,firstname);
    char* temp = string;
    while (*string ) {

        if (*string >= 'A' && *string <= 'Z') {
            // Convert uppercase letter to lowercase by adding 32
            *string = *string + 32;
        }
        string++;
    }
    string = temp;
    return string;

}







void createRdv(t_contact* contact) {
    t_rdv* rendezvous = (t_rdv*)malloc(sizeof(t_rdv));
    rendezvous->date = createDate();
    rendezvous->time = createTime();
    rendezvous->duration = createDuration();

    t_rdv** temp  = (t_rdv**)realloc(contact->list_rdv, contact->nb_rdv*sizeof(t_rdv*));
    temp[contact->nb_rdv] = NULL;
    contact->list_rdv = temp;
    printf("coucou\n");
    contact->list_rdv[contact->nb_rdv] = rendezvous;
    printf("apres");

    contact->nb_rdv += 1;



}


t_date* createDate() {
    t_date* date = (t_date*)malloc(sizeof(t_date));


    do {
        printf("day of the month");
        scanf("%d", &date->day);
    }
    while (0 >= date->day || date->day > 31 );
    do {
        fflush(stdin);
        printf("month of the year");

        scanf("%d", &date->month);
    }
    while ( 0 >= date->month || date->month > 12 );
    do {
        fflush(stdin);
    printf("year of the appointment");

    scanf("%d", &date->year);
    }
    while (2022 > date->year);
    return date;
}


t_time* createTime() {
    t_time* time = (t_time*)malloc(sizeof(t_time));
    do {
        printf("hour of the appointment (hours)");
        scanf("%d", &time->hour);
    }
    while (0 > time->hour || time->hour > 23);
    do {
        printf("hour of the appointment (minutes)");
        scanf("%d", &time->minute);
    }
    while (0 > time->minute || time->minute > 59);

    return time;
}


t_time* createDuration() {
    t_time* time = (t_time*)malloc(sizeof(t_time));
    do {
        printf("duration (hours)");
        scanf("%d", &time->hour);
    }
    while (0 > time->hour || time->hour > 23);
    do {
        printf("duration (minutes)");
        scanf("%d", &time->minute);
    }
    while (0 > time->minute || time->minute > 59);

    return time;
}




void printAllContact(t_d_listContact * list){

    for(int i=0;i<4;i++){

        printf("{head : %d}",i);

        if (list->heads_list[0] != NULL){

            t_contact* temp  = list->heads_list[0];

            while(temp != NULL){
                if(i <= temp->level) {

                    printf("--->[%s|@-]",temp->string_name);
                }

                temp = temp->next[0];
            }
        }
        printf("--> NULL\n");

    }
}




