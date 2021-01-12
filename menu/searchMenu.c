#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "../utils/print.h"
#include "../utils/read.h"
#include "menuManager.h"

void search();

void searchMenu()
{
    printMenu("database/searchMenu.txt");

    search();
}

void search()
{
    int choice;
    char *message = NULL, *input = NULL;
    Contacts *foundContacts = NULL;

    while (1)
    {
        choice = readIntInRange(1, 7);

        switch (choice)
        {
            case 1:
                // first name
                message = "\nPlease enter first name to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NAME_SIZE, 1, 1);
                foundContacts = searchContact(input, 1);
                break;
            case 2:
                // last name
                message = "\nPlease enter last name to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NAME_SIZE, 1, 1);
                foundContacts = searchContact(input, 2);
                break;
            case 3:
                // email
                message = "\nPlease enter email to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(EMAIL_SIZE, 1, 1);
                foundContacts = searchContact(input, 3);
                break;
            case 4:
                // address
                message = "\nPlease enter address to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(ADDRESS_SIZE, 1, 1);
                foundContacts = searchContact(input, 4);
                break;
            case 5:
                // phone number
                message = "\nPlease enter phone number to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NUMBER_SIZE, 1, 1);
                foundContacts = searchContact(input, 5);
                break;
            case 6:
                // home number
                message = "\nPlease enter home number to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NUMBER_SIZE, 1, 1);
                foundContacts = searchContact(input, 6);
                break;
            case 7:
                mainMenu();
                return;
                break;
        }
        free(input);

        if (!foundContacts)
        {
            message = "\nNo Contacts Found!\n";
            printColorful(message, strlen(message), "red");
        }
        else
        {
            message = "\nFound some contacts!\n\n";
            printColorful(message, strlen(message), "cyan");
            printContacts(foundContacts);
            deleteContacts(foundContacts);
        }
    }
}