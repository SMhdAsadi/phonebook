#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/ansi_escapes.h"
#include "../utils/write.h"
#include "../utils/delay.h"
#include "menuCommon.h"
#include "menuManager.h"

#include <malloc.h>
#include <string.h>


void addMenu()
{
    Contact *newContact = malloc(sizeof(Contact));

    printMenu("database/addMenu.txt");
    getContact(newContact);
    newContact->id = readNextId();


    int isSuccess;
    char *message;
    isSuccess = appendContact(newContact);
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
    mainMenu();
}