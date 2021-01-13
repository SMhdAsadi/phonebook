#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif

/*
    prints a string on the stdout with delay
    used to make printing feel like someone is typing
*/
void printWithDelay(char *string, int length);

/*
    prints a string on the stdout with delay and color
    color can be:
        black, blue, red, green, 
        magenta, yellow, white, cyan
*/
void printColorful(char *string, int length, char *color);

/*
    prints a >>> sign for demonstrating promp
*/
void printPrompt();

/*
    prints an colorful and animated loading for specified rounds
*/
void printLoading(int round);

/*
    takes a txt file address, decodes and prints it
*/
void printMenu(char *menuTextAddress);

/*
    prints a single contact with full details on the screen
*/
void printContact(Contact *contact);

/*
    prints important fields of Contacts in a neat table
*/
void printContacts(ContactArray *ContactArray);