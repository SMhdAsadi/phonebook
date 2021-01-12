#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif

void setupScreen();
void restoreScreen();
void printWithDelay(char *string, int length);
void printColorful(char *string, int length, char *color);
void printPrompt();
void printLoading(int round);
void printMenu(char *menuTextAddress);
void printContact(Contact *contact);
void printContacts(Contacts *contacts);