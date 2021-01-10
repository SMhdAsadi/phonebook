#include "../utils/print.h"
#include "../utils/read.h"
#include "../utils/selection.h"

void menuManager()
{
    int choice;

    printLoading(1);
    printMenu("database/mainMenu.txt");
    choice = readIntInRange(1, 5);

    // switch (choice)
    // {
    //     case ADD:
    //         addMenu();
    //         break;
    //     case DELETE:
    //         deleteMenu();
    //         break;
    //     case EDIT:
    //         editMenu();
    //         break;
    //     case SEARCH:
    //         searchMenu();
    //         break;
    //     case SHOW:
    //         showMenu();
    //         break;
    // }
}