#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "delay.h"
#include "print.h"
#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif

int isWhiteSpace(char *string)
{
    int allAreWhiteSpace = 1, isLetterWhiteSpace;
    char whiteSpaces[] = {' ', '\n', '\t', '\r'};
    
    for (int i = 0; i < strlen(string); i++)
    {
        isLetterWhiteSpace = 0;
        for (int j = 0; j < sizeof(whiteSpaces); j++)
        {
            if (string[i] == whiteSpaces[j])
            {
                isLetterWhiteSpace = 1;
                break;
            }
        }
        if (!isLetterWhiteSpace)
        {
            return 0;
        }
    }
    return 1;
}

int readInt()
{
    printPrompt();

    char input[20];
    fgets(input, 20, stdin);

    char *giberish;
    long inputNumber = strtol(input, &giberish, 10);
    if (inputNumber == 0)
    {
        printf("Didn't catch that!\n");
        delayOneSecond();
        printf("Please try again...\n");
        delayOneSecond();
        return readInt();
    }
    
    return inputNumber;
}

int readIntInRange(int from, int to)
{
    int input = readInt();
    while (input < from || input > to)
    {
        printf("Please enter valid number.\n");
        delayOneSecond();
        return readIntInRange(from, to);
    }

    return input;
}

char *readString(int size, int havePrompt, int isRequired)
{
    if (havePrompt)
    {
        printPrompt();
    }
    char *input = malloc(size + 1);

    fgets(input, size + 1, stdin);
    if (isRequired && isWhiteSpace(input))
    {
        return NULL;
    }
    
    // to ignore newline at the end
    input[strlen(input) - 1] = '\0';
    return input;
}

int getId()
{
    Contact *lastContact = malloc(sizeof(Contact));

    FILE *file = fopen("database/contacts.dat", "rb");
    if (file == NULL)
    {
        free(lastContact);
        return -1;
    }

    fseek(file, -1 * sizeof(Contact), SEEK_END);
    if ((fread(lastContact, sizeof(Contact), 1, file) ) != 0)
    {
        int id = lastContact->id;
        free(lastContact);
        fclose(file);
        return id + 1;
    }

    return 0;
}

Contacts *getContacts()
{
    Contacts *contacts = newContacts();

    FILE *file = fopen("database/contacts.dat", "rb");
    if (file == NULL)
    {
        deleteContacts(contacts);
        return NULL;
    }

    Contact *temp = malloc(sizeof(Contact));

    while ((fread(temp, sizeof(Contact), 1, file)) != 0)
    {
        addContact(contacts, temp);
    }
    fclose(file);

    return contacts;
}