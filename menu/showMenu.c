#include <stdio.h>
#include <string.h>

#ifndef CONTACT_INCLUDED
#include "../utils/contact.h"
#define CONTACT_INCLUDED
#endif
#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/delay.h"
#include "menuManager.h"

void readInput()
{
    char *message = "\nEnter valid id to see a contact with details or -1 to go to main menu\n";
    printColorful(message, strlen(message), "blue");

    int choice;
    Contact *contact = NULL;
    while (1)
    {
        choice = readInt();

        if (choice == -1)
        {
            return;
        }

        contact = readContactById(choice);
        if (contact == NULL)
        {
            message = "No contact found with this id\n";
            printColorful(message, strlen(message), "red");
        }
        else
        {
            printContact(contact);
        }
    }
}


void showMenu()
{
    printMenu("database/showMenu.txt");
    
    ContactArray *contacts = readContacts();    
    printContacts(contacts);
    readInput();
    
    deleteContactArray(contacts);
    mainMenu();
}