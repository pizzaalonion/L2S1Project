#include <stdio.h>
#include "list.h"
#include "sorting.h"
#include "timer.h"
#import "contact.h"
#include "searchcontact.h"
int main() {
    int tag = 1;
    t_d_listContact* list = createListContact();

    while (tag) {
        //printf menu principal
        //scanf de l'input
        //switch input
        printf("======================================YOUR DIARY==================================\n");
        printf("1 : Create a new contact\n");
        printf("2 : Create a new appointment\n");
        printf("3 : View appointments for a contact\n");
        printf("4 : Display the list of contacts\n");
        printf("5 : Delete an appointment\n");
        printf("6 : Save the appointment file\n");
        printf("7 : Get the efficiency of contact insertion\n");
        printf("0 : Close\n");
        int option;
        do {
            printf("Enter your action as an integer :\n");
            scanf("%d", &option);

        }while (0>option ||option > 7);
        t_contact* contact;
        char* contact_name;
        switch (option) {
            case 0 :


                    break;

            case 1 :
                printf("\n");
                contact = createContact(scanString());
                addContact(contact,list);
                    break;

            case 2 :
                printf("\n");
                contact_name = scanString();
                contact = classicSearchContact(list->heads_list[0], contact_name,0);
                createRdv(contact);
                break;

            case 3 :
                printf("\n");
                contact_name = scanString();
                contact = classicSearchContact(list->heads_list[0], contact_name,0);
                printf("the contact %s has %d appointments: \n ",contact->string_name, contact->nb_rdv);
                printf("%d", contact->list_rdv[0]->time->minute);
                for (int i = 0; i < contact->nb_rdv;i++) {
                    printf("The %d/%d/%d", contact->list_rdv[i]->date->day,contact->list_rdv[i]->date->month,contact->list_rdv[i]->date->year);
                    printf(" at %dh-%dm",contact->list_rdv[i]->time->hour,contact->list_rdv[i]->time->minute);
                    printf(" for a duration of  %dh-%dm",contact->list_rdv[i]->duration->hour,contact->list_rdv[i]->duration->minute);
                }
                break;

            case 4 :printAllContact(list);
            case 5 :
            case 6 :
            case 7 :

        }
    }










    /*
    printf("Hello World !\n");
    // creation of a list of n levels adn ordered 2^n elements
    int n =16;
    t_d_list* liste1 = create2nList(n);
    printAllClear(liste1);


    //display of the list

    //printf("%d", dicoSearch(liste1,9));



    FILE *log_file = fopen("C:\\Users\\benma\\CLionProjects\\untitled3\\log.txt", "a");
    char format[] = "%d\t%s\t%s\n" ;
    int level = n;
    char *time_lvl0;
    char *time_all_levels;

    startTimer();
    for(int i = 0; i < 10000; i++) {

        int randomvar = rand() % (int)(pow(2,n)-1 + 0.2);
        // call the function of the classic search at level 0

        // special dicotomic search of 13
        classicSearch(liste1->heads_list[0], randomvar, 0);

    }
    stopTimer();
    time_lvl0 = getTimeAsString(); // timer module function

    printf("classical search time : ");
    displayTime();

    startTimer();
    for (int j = 0; j < 10000; j++) {
        int randomvar = rand() % (int)(pow(2,n)-1 + 0.2);
        dicoSearch(liste1,randomvar);
    }
    stopTimer();
    printf("dichotomic search time : ");

    time_all_levels = getTimeAsString();
    displayTime();

    fprintf(log_file,format,level,time_lvl0, time_all_levels);
    fclose(log_file);
*/
    return 0;
}