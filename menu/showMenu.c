#include <stdio.h>

#ifndef CONTACT_INCLUDED
#include "../utils/contact.h"
#define CONTACT_INCLUDED
#endif
#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/delay.h"

void showMenu()
{
    printMenu("database/showMenu.txt");
    Contacts *contacts = getContacts();    

    printContacts(contacts);
    readInt();
    deleteContacts(contacts);
}