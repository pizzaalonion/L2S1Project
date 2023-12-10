#ifndef UNTITLED3_CONTACT_H
#define UNTITLED3_CONTACT_H
#include "list.h"
#include "utilitary.h"


typedef struct s_time
{
    int hour;
    int minute;
} t_time;


typedef struct s_date{
    int day;
    int month;
    int year;
} t_date;


typedef struct s_rdv{

    t_time* duration;
    t_time* time;
    t_date* date;
} t_rdv;


typedef struct s_contact {

    char* string_name;
    t_rdv** list_rdv;
    int nb_rdv;
    struct s_contact** next;
    int level;


} t_contact;

typedef struct s_d_listContact
{
    t_contact ** heads_list;
    int levels;
} t_d_listContact;


t_d_listContact * createListContact();
void fillList(t_d_listContact* list_contacts);
void addContact( t_contact* contact, t_d_listContact* list_contacts);
void addHeadContact(t_d_listContact *list_contacts, t_contact *contact);

t_contact* createContact(char* string);
t_date* createDate();
t_time* createTime();
t_time* createDuration();
void createRdv(t_contact* contact);
char* getName(char* firstname, char* lastname);
int getHeight(t_contact* contact, t_d_listContact* list);
char* scanString();
void printAllContact(t_d_listContact * list);




#endif //UNTITLED3_CONTACT_H

