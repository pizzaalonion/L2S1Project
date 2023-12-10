#ifndef UNTITLED3_SEARCHCONTACT_H
#define UNTITLED3_SEARCHCONTACT_H
#import "contact.h"
#import <stdlib.h>
#include <stdio.h>
#include <string.h>

t_contact* classicSearchContact(t_contact* contact, char* name, int level);


int dicoSearchContact(t_d_listContact * list, char* name);

#endif //UNTITLED3_SEARCHCONTACT_H
