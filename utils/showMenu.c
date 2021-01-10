#include <stdio.h>
#include <string.h>

#include "print.h"


void show(char *menuTextAddress)
{
    setupScreen();

    FILE *file = fopen(menuTextAddress, "r");

    char buff[200], color[10], *c;

    while (1)
    {
        if (fscanf(file, "%s ", buff) == 0)
        {
            break;
        }
        while (strcmp(buff, "\\n") == 0)
        {
            printf("\n");
            if (fscanf(file, "%s ", buff) == 0)
            {
                break;
            }
        }
        strcpy(color, buff);

        if ((c = fgets(buff, 200, file)) == NULL)
        {
            break;
        }

        printColorful(buff, strlen(buff), color);
    }

    fclose(file);
    restoreScreen();
}
