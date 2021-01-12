#include "../utils/contact.h"
#define CONTACT_INCLUDED

#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/ansi_escapes.h"
#include "../utils/write.h"
#include "../utils/delay.h"
#include "menuManager.h"

#include <malloc.h>
#include <string.h>

#define FIELD_NAME_WIDTH 15
#define FIELD_HEIGHT 6

void moveCaret(int up, int right);
char *getRequiredString(int size);
void getContact(Contact *contact);

void addMenu()
{
    Contact *newContact = malloc(sizeof(Contact));

    printMenu("database/addMenu.txt");
    getContact(newContact);

    int isSuccess;
    char *message;
    isSuccess = writeContact(newContact);
    if (isSuccess)
    {
        message = "\nContact has been added to phoneBook!\n";
        printColorful(message, strlen(message), "cyan");
        delay(2000);
    }
    else
    {
        message = "\nOh there is a problem in the database\n";
        printColorful(message, strlen(message), "red");
        delayOneSecond();
    }
    
    free(newContact);
    menuManager();
}

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
    moveCaret(FIELD_HEIGHT, FIELD_NAME_WIDTH);
    strcpy(contact->firstName, getRequiredString(NAME_SIZE));

    moveCaret(0, FIELD_NAME_WIDTH);
    strcpy(contact->lastName, getRequiredString(NAME_SIZE));

    moveCaret(0, FIELD_NAME_WIDTH);
    strcpy(contact->address, readString(ADDRESS_SIZE, 0, 0));

    moveCaret(0, FIELD_NAME_WIDTH);
    strcpy(contact->email, getRequiredString(EMAIL_SIZE));

    moveCaret(0, FIELD_NAME_WIDTH);
    strcpy(contact->phoneNumber, getRequiredString(NUMBER_SIZE));
    
    moveCaret(0, FIELD_NAME_WIDTH);
    strcpy(contact->homeNumber, readString(NUMBER_SIZE, 0, 0));

    contact->id = getId();
}