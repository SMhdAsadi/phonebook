#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif

/*
    takes a string and determines if it is whitespace
*/
int isWhiteSpace(char *string);

/*
    prints a prompt and reads a int
    if something other than int entered, it repeats itself
*/
int readInt();

/*
    reads an int in range of [from, to] from user
*/
int readIntInRange(int from, int to);

/*
    reads a string from the user
    if isRequired is true, it doesn't return whitespace
*/
char *readString(int size, int havePrompt, int isRequired);

/*
    returns the lowest id possible to choose for contact
*/
int readNextId();

/*
    reads all of contacts from the database and returns them
    returns NULL if file cannot be opened
*/
ContactArray *readContacts();

/*
    returns the contact with specified id
    if no contact found with that id, returns NULL
*/
Contact *readContactById(int id);

/*
    searches for contacts in any field
    field can be:
    1: first name
    2: last name
    3: email
    4: address
    5: phone number
    6: home number
*/
ContactArray *searchForContacts(char *input, int field);