#include "../utils/ansi_escapes.h"
#include "../utils/read.h"
#include "../utils/delay.h"
#ifndef CONTACT_INCLUDED
#include "../utils/contact.h"
#define CONTACT_INCLUDED
#endif

#include <string.h>
#include <malloc.h>

#define FIELD_NAME_WIDTH 15
#define FIELD_HEIGHT 6

void moveCaret(int up, int right)
{
    setupConsole();
    if (up)
    {
        moveUp(up);
    }
    if (right)
    {
        moveRight(right);
    }
    restoreConsole();
}

char *getRequiredString(int size)
{
    char *input = readString(size, 0, 1);

    while (input == NULL)
    {
        moveCaret(1, FIELD_NAME_WIDTH);
        input = readString(size, 0, 1);
    }
    return input;
}

void getContact(Contact *contact)
{
    char *input = NULL;

    moveCaret(FIELD_HEIGHT, FIELD_NAME_WIDTH);
    input = getRequiredString(NAME_SIZE);
    strcpy(contact->firstName, input); 
    free(input);

    moveCaret(0, FIELD_NAME_WIDTH);
    input = getRequiredString(NAME_SIZE);
    strcpy(contact->lastName, input);
    free(input);

    moveCaret(0, FIELD_NAME_WIDTH);
    input = readString(ADDRESS_SIZE, 0, 0);
    strcpy(contact->address, input); 
    free(input);

    moveCaret(0, FIELD_NAME_WIDTH);
    input = getRequiredString(EMAIL_SIZE);
    strcpy(contact->email, input);
    free(input);

    moveCaret(0, FIELD_NAME_WIDTH);
    input = getRequiredString(NUMBER_SIZE);
    strcpy(contact->phoneNumber, input);
    free(input);
    
    moveCaret(0, FIELD_NAME_WIDTH);
    input = readString(NUMBER_SIZE, 0, 0);
    strcpy(contact->homeNumber, input);
    free(input);
}