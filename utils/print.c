#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "ansi_escapes.h"
#include "delay.h"
#ifndef CONTACT_INCLUDED
#include "contact.h"
#define CONTACT_INCLUDED
#endif

#define ID_WIDTH 3
#define FIRST_NAME_WIDTH 15
#define LAST_NAME_WIDTH 15
#define EMAIL_WIDTH 30
#define PHONE_WIDTH 13

void setupScreen()
{
    setupConsole();
    clearScreen();
    moveTo(1, 1);
}

void restoreScreen()
{
    restoreConsole();
}

void printWithDelay(char *string, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", string[i]);
        fflush(stdout);
        delay(PRINT_DELAY);
    }
}

void printColorful(char *string, int length, char *color)
{
    setupConsole();
    Color newColor;
    if (strcasecmp(color, "red") == 0)
        newColor = RED_TXT;
    else if (strcasecmp(color, "blue") == 0)
        newColor = BLUE_TXT;
    else if (strcasecmp(color, "green") == 0)
        newColor = GREEN_TXT;
    else if (strcasecmp(color, "yellow") == 0)
        newColor = YELLOW_TXT;
    else if (strcasecmp(color, "cyan") == 0)
        newColor = CYAN_TXT;
    else if (strcasecmp(color, "white") == 0)
        newColor = WHITE_TXT;
    else if (strcasecmp(color, "magenta") == 0)
        newColor = MAGENTA_TXT;
    else if (strcasecmp(color, "black") == 0)
        newColor = BLACK_TXT;
    else
        newColor = RESET_COLOR;

    setTextColorBright(newColor);
    printWithDelay(string, length);
    setTextColorBright(RESET_COLOR);
    restoreConsole();
}

void printCenteralized(char *s, int length)
{
    printf("---%*s%*s---\n",length + (int)strlen(s) / 2, s, length - (int)strlen(s) / 2, "");
}

void printPrompt()
{
    setupConsole();
    setTextColorBright(GREEN_TXT);

    printf("\n>>> ");
    restoreConsole();
}

void printLoading(int round)
{
    srand(time(NULL));
    setupConsole();
    setTextColorBright(CYAN_TXT);
    
    printCenteralized("Loading", 20);

    for (int i = 0; i < round; i++)
    {
        for (int j = 0; j < 46; j++)
        {
            printf("%c", 219);
            fflush(stdout);
            delay(rand() % (LOADING_DELAY * 5));
        }

        for (int j = 0; j < 46; j++)
        {
            moveLeft(1);
            clearLineToRight();
            fflush(stdout);
            delay(rand() % (LOADING_DELAY * 5));
        }
    }

    moveUp(1);
    clearScreenToBottom();
    printCenteralized("Load completed!", 20);
    delay(1000);
    restoreConsole();
}

void printMenu(char *menuTextAddress)
{
    setupScreen();

    FILE *file = fopen(menuTextAddress, "r");
    if (file == NULL)
    {
        char *message = "Database Error!\n";
        restoreConsole();
        printColorful(message, strlen(message), "red");
        exit(1);
    }
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
        strncpy(color, buff, sizeof(color));

        if ((c = fgets(buff, 200, file)) == NULL)
        {
            break;
        }

        restoreConsole();
        printColorful(buff, strlen(buff), color);
    }

    fclose(file);
}

void printContact(Contact *contact)
{
    printf("Contact [\n");
    printf("    id: %d\n", contact->id);
    printf("    first name: %s\n", contact->firstName);
    printf("    last name: %s\n", contact->lastName);
    printf("    address: %s\n", contact->address);
    printf("    email: %s\n", contact->email);
    printf("    phone: %s\n", contact->phoneNumber);
    printf("    home: %s\n", contact->homeNumber);
    printf("]\n");
}

void printHorizontalRow(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("\u2501");
    }
}

void printTopBar()
{
    setupConsole();
    setTextColorBright(YELLOW_TXT);
    printf("%-*s%-*s%-*s%-*s%-*s\n", 
        ID_WIDTH + 2, "ID", 
        FIRST_NAME_WIDTH + 1, "FirstName",
        LAST_NAME_WIDTH + 1, "LastName", 
        EMAIL_WIDTH + 1, "Email", 
        PHONE_WIDTH + 1, "PhoneNumber"
    );
    restoreConsole();

    for (int i = 0; i < 80; i++)
    {
        printf("#");
    }

    // printf("\u250F");

    // int widths[] = {ID_WIDTH, FIRST_NAME_WIDTH, LAST_NAME_WIDTH, EMAIL_WIDTH};

    // for (int i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
    // {
    //     printHorizontalRow(widths[i]);
    //     printf("\u2533");
    // }

    // // phone number
    // printHorizontalRow(PHONE_WIDTH);
    // printf("\u2513");

    printf("\n");
}

void printMiddleBar(Contact contact)
{
    printf(" ");

    printf("%-*i", ID_WIDTH, contact.id);
    printf(" ");

    printf("%-*.*s", FIRST_NAME_WIDTH, FIRST_NAME_WIDTH, contact.firstName);
    printf(" ");

    printf("%-*.*s", LAST_NAME_WIDTH, LAST_NAME_WIDTH, contact.lastName);
    printf(" ");

    printf("%-*.*s", EMAIL_WIDTH, EMAIL_WIDTH, contact.email);
    printf(" ");

    printf("%-*.*s", PHONE_WIDTH, PHONE_WIDTH, contact.phoneNumber);
    printf(" ");

    printf("\n");
}

void printBottomBar()
{
    for (int i = 0; i < 80; i++)
    {
        printf("#");
    }
    // printf("\u2517");

    // int widths[] = {ID_WIDTH, FIRST_NAME_WIDTH, LAST_NAME_WIDTH, EMAIL_WIDTH};

    // for (int i = 0; i < sizeof(widths) / sizeof(widths[0]); i++)
    // {
    //     printHorizontalRow(widths[i]);
    //     printf("\u253B");
    // }

    // // phone number
    // printHorizontalRow(PHONE_WIDTH);
    // printf("\u251B");

    printf("\n");
}

void printContacts(ContactArray *contactArray)
{
    printTopBar();

    for (int i = 0; i < contactArray->length; i++)
    {
        printMiddleBar(contactArray->elements[i]);
    }

    printBottomBar();
}