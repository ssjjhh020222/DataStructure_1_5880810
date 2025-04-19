#ifndef LINEARLIST_H
#define LINEARLIST_H

#define MAX_LIST_SIZE 100

typedef struct {
    char name[100];
    char phone[15];
} Contact;

typedef struct {
    Contact contacts[MAX_LIST_SIZE];
    int size;
} ListType;

void initList(ListType* list);
void addContact(ListType* list, const char* name, const char* phone);
int searchContact(ListType* list, const char* name);
int deleteContact(ListType* list, const char* name);
void printAllContacts(ListType* list);
 
#endif
