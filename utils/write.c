#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif
#include "read.h"
#include "print.h"
#include "delay.h"

int writeContact(Contact *contact)
{
    FILE *file = fopen("database/contacts.dat", "ab");
    if (file == NULL)
    {
        return -1;
    }
    fwrite(contact, sizeof(Contact), 1, file);
    fclose(file);

    return 1;
}

int deleteContact(int id)
{
    char *message = NULL;

    FILE *contacts = fopen("database/contacts.dat", "rb");
    if (contacts == NULL)
    {
        message = "\nCannot open database!\n";
        printColorful(message, strlen(message), "red");
        delay(2000);
        exit(1); 
    }

    FILE *temp = fopen("database/temp.dat", "wb");
    if (temp == NULL)
    {
        message = "\nCannot open database!\n";
        printColorful(message, strlen(message), "red");
        delay(2000);
        exit(1);   
    }

    int found = 0;
    Contact *contact = calloc(1, sizeof(Contact));
    while ((fread(contact, sizeof(Contact), 1, contacts)) != 0)
    {
        if (contact->id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(contact, sizeof(Contact), 1, temp);
        }
    }
    free(contact);
    fclose(temp);
    fclose(contacts);
    remove("database/contacts.dat");
    rename("database/temp.dat", "database/contacts.dat");

    return found;   
}

int updateContact(Contact *contact)
{
    char *message = NULL;

    FILE *contactsFile = fopen("database/contacts.dat", "rb");
    if (contactsFile == NULL)
    {
        message = "\nCannot open database!\n";
        printColorful(message, strlen(message), "red");
        delay(2000);
        exit(1); 
    }

    FILE *tempFile = fopen("database/temp.dat", "wb");
    if (tempFile == NULL)
    {
        message = "\nCannot open database!\n";
        printColorful(message, strlen(message), "red");
        delay(2000);
        exit(1);   
    }

    int found = 0;
    Contact *tempContact = calloc(1, sizeof(Contact));
    while ((fread(tempContact, sizeof(Contact), 1, contactsFile)) != 0)
    {
        if (tempContact->id == contact->id)
        {
            found = 1;
            fwrite(contact, sizeof(Contact), 1, tempFile);
        }
        else
        {
            fwrite(tempContact, sizeof(Contact), 1, tempFile);
        }
    }

    free(tempContact);
    fclose(tempFile);
    fclose(contactsFile);

    remove("database/contacts.dat");
    rename("database/temp.dat", "database/contacts.dat");

    return found;
}