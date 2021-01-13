#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu/menuManager.h"

void initializeDatabase();

int main()
{
    initializeDatabase();
    menuManager();

    return 0;
}

void initializeDatabase()
{
    char *fileNames[] = {"mainMenu.txt", "addMenu.txt", "searchMenu.txt", 
                         "showMenu.txt", "deleteMenu.txt", "editMenu.txt"};
    char dirName[] = "database/";
    char fileName[30];

    FILE *file;

    for (int i = 0; i < sizeof(fileNames) / sizeof(fileNames[0]); i++)
    {
        strcpy(fileName, dirName);
        strcat(fileName, fileNames[i]);

        file = fopen(fileName, "r");
        if (file == NULL)
        {
            printf("Please be sure that all database files are ready\n");
            exit(1);
        }
        fclose(file);
    }

    file = fopen("database/contacts.dat", "rb");
    if (file == NULL)
    {
        file = fopen("database/contacts.dat", "wb");
        if (file != NULL)
        {
            fclose(file);
            return;
        }
    }
    fclose(file);
}