#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/selection.h"
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
    ContactArray *foundContacts = NULL;

    while (1)
    {
        choice = readIntInRange(1, 7);

        switch (choice)
        {
            case FIRST_NAME:
                message = "\nPlease enter first name to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NAME_SIZE, 1, 1);
                foundContacts = searchForContacts(input, 1);
                break;
            case LAST_NAME:
                message = "\nPlease enter last name to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NAME_SIZE, 1, 1);
                foundContacts = searchForContacts(input, 2);
                break;
            case EMAIL:
                message = "\nPlease enter email to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(EMAIL_SIZE, 1, 1);
                foundContacts = searchForContacts(input, 3);
                break;
            case ADDRESS:
                message = "\nPlease enter address to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(ADDRESS_SIZE, 1, 1);
                foundContacts = searchForContacts(input, 4);
                break;
            case PHONE_NUMBER:
                message = "\nPlease enter phone number to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NUMBER_SIZE, 1, 1);
                foundContacts = searchForContacts(input, 5);
                break;
            case HOME_NUMBER:
                message = "\nPlease enter home number to search:\n";
                printColorful(message, strlen(message), "yellow");
                input = readString(NUMBER_SIZE, 1, 1);
                foundContacts = searchForContacts(input, 6);
                break;
            case MAIN_MENU:
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
            deleteContactArray(foundContacts);
        }
    }
}