#include <stdio.h>

#include "contact.h"

int writeContact(Contact *contact)
{
    FILE *file = fopen("../database/contacts.dat", "ab");
    if (file == NULL)
    {
        return -1;
    }
    fwrite(contact, sizeof(*contact), 1, file);
    fclose(file);

    return 1;
}