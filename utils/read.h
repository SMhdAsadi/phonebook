#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif

int isWhiteSpace(char *string);
int readInt();
int readIntInRange(int from, int to);
char *readString(int size, int havePrompt, int isRequired);
int getId();
Contacts *getContacts();
Contact *readContact(int id);
Contacts *searchContact(char *input, int field);