#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "delay.h"
#include "print.h"
#include "selection.h"
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
        printf("Didn't catch that!\n");
        delayOneSecond();
        printf("Please try again...\n");
        delayOneSecond();
        return readString(size, havePrompt, isRequired);
    }
    
    // to ignore newline at the end
    input[strlen(input) - 1] = '\0';
    return input;
}

int readNextId()
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

    free(lastContact);
    fclose(file);
    return 1;
}

ContactArray *readContacts()
{
    ContactArray *contactArray = newContactArray();
 
    FILE *file = fopen("database/contacts.dat", "rb");
    if (file == NULL)
    {
        deleteContactArray(contactArray);
        return NULL;
    }

    Contact *temp = malloc(sizeof(Contact));
    while ((fread(temp, sizeof(Contact), 1, file)) != 0)
    {
        addContact(contactArray, temp);
    }
    fclose(file);
    free(temp);

    return contactArray;
}

Contact *readContactById(int id)
{
    FILE *file = fopen("database/contacts.dat", "rb");
    if (file == NULL)
    {
        return NULL;
    }

    Contact *contact = malloc(sizeof(Contact));
    while ((fread(contact, sizeof(Contact), 1, file)) != 0)
    {
        if (contact->id == id)
        {
            fclose(file);
            return contact;
        }
        else if (contact->id > id)
        {
            free(contact);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    free(contact);
    return NULL;
}

ContactArray *searchForContacts(char *input, int field)
{
    ContactArray *foundContacts = newContactArray();
    ContactArray *allContacts = readContacts();

    char *found = NULL;
    Contact *contact = NULL;
    for (int i = 0; i < allContacts->length; i++)
    {
        contact = malloc(sizeof(Contact));
        copyContact(contact, &allContacts->elements[i]);
        switch (field)
        {
        case FIRST_NAME:
            found = strstr(contact->firstName, input);
            break;
        case LAST_NAME:
            found = strstr(contact->lastName, input);
            break;
        case EMAIL:
            found = strstr(contact->email, input);
            break;
        case ADDRESS:
            found = strstr(contact->address, input);
            break;
        case PHONE_NUMBER:
            found = strstr(contact->phoneNumber, input);
            break;
        case HOME_NUMBER:
            found = strstr(contact->homeNumber, input);
            break;
        
        default:
            found = NULL;
            break;
        }

        if (found)
        {
            addContact(foundContacts, contact);
        }
        else
        {
            free(contact);
        }
    }

    deleteContactArray(allContacts);
    if (foundContacts->length == 0)
    {
        deleteContactArray(foundContacts);
        return NULL;
    }

    return foundContacts;
}