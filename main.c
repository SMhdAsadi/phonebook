#include <stdio.h>
#include <string.h>

#include "utils/print.h"
#include "utils/showMenu.h"

void menu();

int main()
{
    menu();

    return 0;
}

void menu()
{
    printLoading(1);
    show("database/mainMenu.txt");
    getc(stdin);
}