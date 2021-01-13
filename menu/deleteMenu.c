#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/delay.h"
#include "../utils/write.h"
#include "menuManager.h"

#include <string.h>
#include <stdlib.h>

void delete();

void deleteMenu()
{
    printMenu("database/deleteMenu.txt");
    
    delete();
}

void delete()
{
    int choosedId = 0, deleteSucceed = 0;
    char *message = NULL;
    ContactArray *contacts = NULL;

    while (1)
    {
        contacts = readContacts();
        if (contacts == NULL)
        {
            message = "\nCannot open database!\n";
            printColorful(message, strlen(message), "red");
            delay(2000);
            exit(1);
        }
        printContacts(contacts);
        deleteContactArray(contacts);

        choosedId = readInt();

        if (choosedId == -1)
        {
            mainMenu();
            return;
        }

        deleteSucceed = deleteContactById(choosedId);
        if (deleteSucceed)
        {
            message = "\nDeleted contact!\n\n";
            printColorful(message, strlen(message), "cyan");
        }
        else
        {
            message = "\nCannot Delete: no contact found with that id\n\n";
            printColorful(message, strlen(message), "red");
        }
    }
}