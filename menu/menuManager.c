#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/selection.h"
#include "../utils/delay.h"
#include "addMenu.h"
#include "showMenu.h"

#include <string.h>
#include <stdlib.h>

void menuManager()
{
    int choice;

    printLoading(1);
    printMenu("database/mainMenu.txt");
    choice = readIntInRange(1, 6);

    char *message = "\nThank you for using our app :)\n";
    switch (choice)
    {
        case ADD:
            addMenu();
            break;
    //     case DELETE:
    //         deleteMenu();
    //         break;
    //     case EDIT:
    //         editMenu();
    //         break;
    //     case SEARCH:
    //         searchMenu();
    //         break;
        case SHOW:
            showMenu();
            break;
        case EXIT:
            printColorful(message, strlen(message), "cyan");
            delay(2000);
            exit(0);
            break;
    }
}