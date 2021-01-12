#include <stdio.h>

#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif

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