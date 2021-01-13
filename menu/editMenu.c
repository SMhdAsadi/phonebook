#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/delay.h"
#include "../utils/write.h"
#include "../utils/ansi_escapes.h"
#include "menuCommon.h"
#include "menuManager.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void edit();

void editMenu()
{
    printMenu("database/editMenu.txt");
    
    edit();
}

void edit()
{
    int choosedId = 0, editSucceed = 0;
    char *message = NULL;

    Contacts *contacts = NULL;
    Contact *contact = NULL;

    while (1)
    {
        contacts = getContacts();
        if (contacts == NULL)
        {
            message = "\nCannot open database!\n";
            printColorful(message, strlen(message), "red");
            delay(2000);
            exit(1);
        }
        printContacts(contacts);
        deleteContacts(contacts);

        choosedId = readInt();

        if (choosedId == -1)
        {
            mainMenu();
            return;
        }

        contact = readContact(choosedId);
        if (contact == NULL)
        {
            message = "\nCannot Edit: no contact found with that id\n\n";
            printColorful(message, strlen(message), "red");
        }
        else
        {
            printContact(contact);

            Contact *newContact = malloc(sizeof(Contact));
            char *message = "\nfirst name*  :\nlast name*   :\naddress      :\nemail*       :\nphone number*:\nhome number  :\n";
            printColorful(message, strlen(message), "red");
            getContact(newContact);
            newContact->id = choosedId;

            editSucceed = updateContact(newContact);
            free(newContact);
            if (editSucceed)
            {
                message = "\nSuccessfully edited\n\n";
                printColorful(message, strlen(message), "cyan");
            }
            else
            {
                message = "\nCannot Edit: no contact found with that id\n\n";
                printColorful(message, strlen(message), "red");
            }
        }
    }
}