#ifndef CONTACT_INCLUDED
#include "../utils/contact.h"
#define CONTACT_INCLUDED
#endif

#define FIELD_NAME_WIDTH 15
#define FIELD_HEIGHT 6

void moveCaret(int up, int right);
char *getRequiredString(int size);
void getContact(Contact *contact);
